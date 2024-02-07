/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  TradNav Plugin
 * Author:   Mike Rossiter
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Mike Rossiter                                *
 *   $EMAIL$                                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif // precompiled headers

#include "TradNav_pi.h"
#include "TradNavgui.h"
#include "TradNavgui_impl.h"
#include "pidc.h"
#include "tdEventHandler.h"
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/object.h>
#include "tdPath.h"

wxWindow* g_current_canvas;
int g_current_canvas_index;
wxWindow* g_parent_window;
TradNav_pi* g_tradnav_pi;

tdEventHandler* g_tdEventHandler;
PlugIn_ViewPort g_VP;
piDC* g_pDC;
bool g_bOpenGL;

wxString* g_PrivateDataDir;
wxString* g_pData;
bearingList* g_pBearingList;

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void* ppimgr)
{
    return new TradNav_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p) { delete p; }

//---------------------------------------------------------------------------------------------------------
//
//    TradNav PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

TradNav_pi::TradNav_pi(void* ppimgr)
    : opencpn_plugin_117(ppimgr)
{
    // Create the PlugIn icons
    initialize_images();

    wxFileName fn;
    wxString tmp_path;

    tmp_path = GetPluginDataDir("TradNav_pi");
    fn.SetPath(tmp_path);
    fn.AppendDir(_T("data"));
    fn.SetFullName("tradnav_pi_panel.png");

    wxString shareLocn = fn.GetFullPath();
    wxImage panelIcon(shareLocn);

    if (panelIcon.IsOk())
        m_panelBitmap = wxBitmap(panelIcon);
    else
        wxLogMessage(_T("    TradNav_pi panel icon NOT loaded"));

    wxString* l_pDir = new wxString(*GetpPrivateApplicationDataLocation());
    appendOSDirSlash(l_pDir);
    l_pDir->Append(_T("plugins"));
    appendOSDirSlash(l_pDir);
    if (!wxDir::Exists(*l_pDir))
        wxMkdir(*l_pDir);
    l_pDir->Append(_T("TradNav_pi"));
    appendOSDirSlash(l_pDir);
    if (!wxDir::Exists(*l_pDir))
        wxMkdir(*l_pDir);
    g_PrivateDataDir = new wxString;
    g_PrivateDataDir->Append(*l_pDir);
    g_pData = new wxString(*l_pDir);
    g_pData->append(wxS("data"));
    appendOSDirSlash(g_pData);
    if (!wxDir::Exists(*g_pData))
        wxMkdir(*g_pData);

    m_bShowTradNav = false;
}

TradNav_pi::~TradNav_pi(void)
{
    delete _img_TradNav_pi;
    delete _img_TradNav;
}

int TradNav_pi::Init(void)
{
    AddLocaleCatalog(_T("opencpn-TradNav_pi"));

    // Set some default private member parameters
    m_route_dialog_x = 0;
    m_route_dialog_y = 0;
    ::wxDisplaySize(&m_display_width, &m_display_height);

    g_tradnav_pi = this;

    //    Get a pointer to the opencpn display canvas, to use as a parent for
    //    the POI Manager dialog
    m_parent_window = PluginGetFocusCanvas();
    g_parent_window = m_parent_window;
    clickn = 0;
    currentSegment = NULL;
    rangeCircle = NULL;
    m_pSelectedPath = NULL;
    m_bFinish = false;

    g_pBearingList = new bearingList;

    // Create an OCPN Draw event handler
    g_tdEventHandler = new tdEventHandler(g_tradnav_pi);
    g_tdEventHandler->SetWindow(m_parent_window);

    //    Get a pointer to the opencpn configuration object
    m_pconfig = GetOCPNConfigObject();

    //    And load the configuration items
    LoadConfig();

    //    This PlugIn needs a toolbar icon, so request its insertion
    if (m_bTradNavShowIcon)

#ifdef TradNav_USE_SVG
        m_leftclick_tool_id = InsertPlugInToolSVG(_T("TradNav"), _svg_tradnav,
            _svg_tradnav, _svg_tradnav_toggled, wxITEM_CHECK, _("TradNav"),
            _T(""), NULL, CALCULATOR_TOOL_POSITION, 0, this);
#else
        m_leftclick_tool_id
            = InsertPlugInTool(_T(""), _img_TradNav, _img_TradNav, wxITEM_CHECK,
                _("TradNav"), _T(""), NULL, CALCULATOR_TOOL_POSITION, 0, this);
#endif
   
    m_pDialog = NULL;

    return (WANTS_OVERLAY_CALLBACK | WANTS_CURSOR_LATLON
        | WANTS_TOOLBAR_CALLBACK | WANTS_CONFIG
        | INSTALLS_CONTEXTMENU_ITEMS | WANTS_NMEA_EVENTS | USES_AUI_MANAGER
        | WANTS_PREFERENCES | WANTS_ONPAINT_VIEWPORT | WANTS_PLUGIN_MESSAGING
        | WANTS_OPENGL_OVERLAY_CALLBACK | WANTS_LATE_INIT | WANTS_MOUSE_EVENTS
        | WANTS_KEYBOARD_EVENTS);
}

bool TradNav_pi::DeInit(void)
{
    //    Record the dialog position
    if (NULL != m_pDialog) {
        // Capture dialog position
        wxPoint p = m_pDialog->GetPosition();
        SetCalculatorDialogX(p.x);
        SetCalculatorDialogY(p.y);
        if ((m_pDialog->myTimer != NULL)
            && (m_pDialog->myTimer
                    ->IsRunning())) { // need to stop the timer or crash on
            // exit
            m_pDialog->myTimer->Stop();
        }

        m_pDialog->Close();
        delete m_pDialog;
        m_pDialog = NULL;

        m_bShowTradNav = false;
        SetToolbarItemState(m_leftclick_tool_id, m_bShowTradNav);
    }

    SaveConfig();

    RequestRefresh(m_parent_window); // refresh main window

    return true;
}

int TradNav_pi::GetAPIVersionMajor() { return atoi(API_VERSION); }

int TradNav_pi::GetAPIVersionMinor()
{
    std::string v(API_VERSION);
    size_t dotpos = v.find('.');
    return atoi(v.substr(dotpos + 1).c_str());
}

int TradNav_pi::GetPlugInVersionMajor() { return PLUGIN_VERSION_MAJOR; }

int TradNav_pi::GetPlugInVersionMinor() { return PLUGIN_VERSION_MINOR; }

wxBitmap* TradNav_pi::GetPlugInBitmap() { return &m_panelBitmap; }

wxString TradNav_pi::GetCommonName() { return _("TradNav"); }

wxString TradNav_pi::GetShortDescription()
{
    return _("TradNav Positions using GPX files");
}

wxString TradNav_pi::GetLongDescription()
{
    return _("Creates GPX files with\n\
TradNav Positions");
}

int TradNav_pi::GetToolbarToolCount(void) { return 1; }

void TradNav_pi::SetColorScheme(PI_ColorScheme cs)
{
    if (NULL == m_pDialog)
        return;

    DimeWindow(m_pDialog);
}

void TradNav_pi::OnToolbarToolCallback(int id)
{

    if (NULL == m_pDialog) {
        m_pDialog = new Dlg(m_parent_window, this);
        m_pDialog->Move(wxPoint(m_route_dialog_x, m_route_dialog_y));
        m_pDialog->myTimer = new wxTimer(m_pDialog);
        // Create the drawing factory
    }

    m_pDialog->Fit();
    // Toggle
    m_bShowTradNav = !m_bShowTradNav;

    //    Toggle dialog?
    if (m_bShowTradNav) {
        m_pDialog->Show();
    } else
        m_pDialog->Hide();

    // Toggle is handled by the toolbar but we must keep plugin manager b_toggle
    // updated to actual status to ensure correct status upon toolbar rebuild
    SetToolbarItemState(m_leftclick_tool_id, m_bShowTradNav);

    RequestRefresh(m_parent_window); // refresh main window
}

bool TradNav_pi::LoadConfig(void)
{
    wxFileConfig* pConf = (wxFileConfig*)m_pconfig;

    if (pConf) {
        pConf->SetPath(_T( "/Settings/TradNav_pi" ));
        pConf->Read(_T( "ShowTradNavIcon" ), &m_bTradNavShowIcon, 1);

        m_route_dialog_x = pConf->Read(_T ( "DialogPosX" ), 20L);
        m_route_dialog_y = pConf->Read(_T ( "DialogPosY" ), 20L);

        if ((m_route_dialog_x < 0) || (m_route_dialog_x > m_display_width))
            m_route_dialog_x = 5;
        if ((m_route_dialog_y < 0) || (m_route_dialog_y > m_display_height))
            m_route_dialog_y = 5;
        return true;
    } else
        return false;
}

bool TradNav_pi::SaveConfig(void)
{
    wxFileConfig* pConf = (wxFileConfig*)m_pconfig;

    if (pConf) {
        pConf->SetPath(_T ( "/Settings/TradNav_pi" ));
        pConf->Write(_T ( "ShowTradNavIcon" ), m_bTradNavShowIcon);

        pConf->Write(_T ( "DialogPosX" ), m_route_dialog_x);
        pConf->Write(_T ( "DialogPosY" ), m_route_dialog_y);

        return true;
    } else
        return false;
}

void TradNav_pi::OnTradNavDialogClose()
{
    m_bShowTradNav = false;
    SetToolbarItemState(m_leftclick_tool_id, m_bShowTradNav);
    m_pDialog->Hide();
    SaveConfig();

    RequestRefresh(m_parent_window); // refresh main window
}

void TradNav_pi::SetCursorLatLon(double lat, double lon)
{
    m_cursor_lat = lat;
    m_cursor_lon = lon;

    if (g_tdEventHandler) {
        g_tdEventHandler->SetLatLon(lat, lon);
        g_tdEventHandler->SetWindow(g_parent_window);
    }
}

bool TradNav_pi::KeyboardEventHook(wxKeyEvent& event)
{
    if (!m_pDialog || !m_pDialog->IsShown()) {
        return false;
    }

    bool bret = FALSE;

    // wxMessageBox("P");

    if (event.GetKeyCode() < 128) // ascii
    {
        int key_char = event.GetKeyCode();

        if (event.ControlDown())
            key_char -= 64;

        switch (key_char) {
        case WXK_CONTROL_G: // Ctrl R
            if (event.ShiftDown()) { // Shift-Ctrl-R
                if (event.GetEventType() == wxEVT_KEY_DOWN) {
                    // wxMessageBox("R");
                    // double lat = m_cursor_lat;
                    m_pDialog->OnRangeCursor(m_cursor_lat, m_cursor_lon);
                    // wxString mylat = wxString::Format("%f", lat);
                    // wxMessageBox(mylat);
                    return true;
                }
            }
            break;

        case WXK_CONTROL_B: // Ctrl P
            if (event.ShiftDown()) { // Shift-Ctrl-P
                if (event.GetEventType() == wxEVT_KEY_DOWN) {
                    m_pDialog->OnCursor(m_cursor_lat, m_cursor_lon);
                    return true;
                }
            }
            break;

        case WXK_CONTROL_H: // Ctrl P
            if (event.ShiftDown()) { // Shift-Ctrl-P
                if (event.GetEventType() == wxEVT_KEY_DOWN) {
                    m_pDialog->OnHorizontal(m_cursor_lat, m_cursor_lon);
                    return true;
                }
            }
            break;

        case WXK_ESCAPE: // Generic Break
            if (event.GetEventType() == wxEVT_KEY_DOWN) {
                m_pDialog->myTimer->Stop();
                return false;
                break;
            }
        }

        return false;
    }
}

bool TradNav_pi::MouseEventHook(wxMouseEvent& event)
{

    if (!m_pDialog)
        return false;
    if (m_pDialog && m_pDialog->m_toggleBtn2->GetValue() == false)
        return false;
    m_drawing_canvas_index = -1;

    // m_parent_window = GetOCPNCanvasWindow();
    // m_parent_window = PluginGetFocusCanvas();

    //m_parent_window->SetFocus();
    //m_parent_window->CaptureMouse();
    m_mouse_canvas_index = GetCanvasIndexUnderMouse();
    g_tdEventHandler->SetCanvasIndex(m_mouse_canvas_index);

    if (GetCanvasCount() == 1 || m_drawing_canvas_index == -1
        || m_mouse_canvas_index == m_drawing_canvas_index) {
        g_cursor_x = event.GetX();
        g_cursor_y = event.GetY();
        m_cursorPoint.x = g_cursor_x;
        m_cursorPoint.y = g_cursor_y;
    }

    if (GetCanvasCount() > 1 && m_drawing_canvas_index != -1
        && m_mouse_canvas_index != m_drawing_canvas_index) {
        return false;
    }

    // The last position
    static int xpos = -1;
    static int ypos = -1;
    // currentSegment = NULL;

    // Take into account scrolling
    wxPoint pt = m_cursorPoint;
    double mLat1, mLon1, mLat2, mLon2;
    double m_lat1, m_lon1;
    // m_pSelectedPath = m_pSelectedSegment;
    // m_pSelectedPath->m_sTypeString = "DoodleSegment";
    //g_tdEventHandler->SetPath();

    g_tdEventHandler->SetCanvas(GetCanvasByIndex(m_mouse_canvas_index));
    //

    if (event.LeftDown()) {
        /*
        if (m_pSelectedPath)
           wxMessageBox("found");
        else
            wxMessageBox("Not found");
        */
         //g_tdEventHandler->SetPath(m_pSelectedPath);

        GetCanvasPixLL(&g_VP, &rp1, m_cursor_lat, m_cursor_lon);
        
        
        newBPbegin = new bearingPoint(m_cursor_lat, m_cursor_lon);
        m_bFinish = false;
        
    }

    if (event.LeftUp()) {
        /*

      wxList mySegs = doc->GetDoodleSegments();
        wxString sz = wxString::Format("%i", mySegs.size());
        m_pDialog->m_Bearing->SetValue(sz);
*/
        GetCanvasLLPix(&g_VP, rp2, &m_lat1, &m_lon1);
        newBPend = new bearingPoint(m_lat1, m_lon1);

        bearingLine* newBLine = new bearingLine(m_cursor_lat, m_cursor_lon, m_lat1 , m_lon1);
        newBearing = new bearing;
        newBearing->m_bearingLine = *newBLine;
        newBearing->m_bearingBegin = newBPbegin;
        newBearing->m_bearingEnd = newBPend;
        g_pBearingList->push_back(newBearing);
        //m_drawing_canvas_index = -1;
        
m_bFinish = true;

    }

    if (xpos > -1 && ypos > -1 && event.Dragging()) {

        newLine = new DoodleLine;
        newLine->m_x1 = xpos;
        newLine->m_y1 = ypos;
        newLine->m_x2 = pt.x;
        newLine->m_y2 = pt.y;
        // currentSegment->GetLines().Append(newLine);
        // m_pSelectedPath = currentSegment;
        // rp1 = wxPoint(xpos, ypos);
        rp2 = wxPoint(pt);
        
        
    }

    xpos = pt.x;
    ypos = pt.y;
    event.SetEventType(
        wxEVT_MOVING); // stop dragging canvas on event flow through
    //m_parent_window->ReleaseMouse();
    // m_parent_window->Refresh();
    // g_parent_window->Refresh();
    tdRequestRefresh(m_mouse_canvas_index, true);
    return false;
} //

bool TradNav_pi::RenderOverlay(wxMemoryDC* pmdc, PlugIn_ViewPort* pivp)
{
    g_bOpenGL = false;
    m_VP = *pivp;
    g_VP = *pivp;
    m_chart_scale = pivp->chart_scale;
    m_view_scale = pivp->view_scale_ppm;

    piDC ocpnmdc(*pmdc);

    RenderPathLegs(ocpnmdc);
    return TRUE;
}

bool TradNav_pi::RenderOverlay(wxDC& dc, PlugIn_ViewPort* pivp)
{
    g_bOpenGL = false;
    return RenderOverlays(dc, pivp);
}

bool TradNav_pi::RenderOverlays(wxDC& dc, PlugIn_ViewPort* pivp)
{
    m_VP = *pivp;
    g_VP = *pivp;
    m_chart_scale = pivp->chart_scale;
    m_view_scale = pivp->view_scale_ppm;

    g_pDC = new piDC(dc);
    // LLBBox llbb;
    // llbb.Set(pivp->lat_min, pivp->lon_min, pivp->lat_max, pivp->lon_max);

    RenderPathLegs(*g_pDC);

    delete g_pDC;
    return TRUE;
}

bool TradNav_pi::RenderOverlayMultiCanvas(
    wxDC& dc, PlugIn_ViewPort* vp, int canvas_index)
{
    g_bOpenGL = false;
    m_current_canvas_index = canvas_index;
    bool bRet = RenderOverlays(dc, vp);
    return bRet;
}

bool TradNav_pi::RenderGLOverlay(wxGLContext* pcontext, PlugIn_ViewPort* pivp)
{
    g_bOpenGL = true;
    return RenderGLOverlays(pcontext, pivp);
}

bool TradNav_pi::RenderGLOverlays(wxGLContext* pcontext, PlugIn_ViewPort* pivp)
{
    m_pcontext = pcontext;
    m_VP = *pivp;
    g_VP = *pivp;
    m_chart_scale = pivp->chart_scale;
    m_view_scale = pivp->view_scale_ppm;

    g_pDC = new piDC();
    g_pDC->SetVP(pivp);

    // LLBBox llbb;
    //  llbb.Set(pivp->lat_min, pivp->lon_min, pivp->lat_max, pivp->lon_max);

    //    DrawAllODPointsInBBox( *g_pDC, llbb );
    RenderPathLegs(*g_pDC);

    delete g_pDC;
    return TRUE;
}

bool TradNav_pi::RenderGLOverlayMultiCanvas(
    wxGLContext* pcontext, PlugIn_ViewPort* vp, int canvas_index)
{
    g_bOpenGL = true;
    m_current_canvas_index = canvas_index;
    bool bRet = RenderGLOverlays(pcontext, vp);
    return bRet;
}

void TradNav_pi::RenderPathLegs(piDC& dc)
{
    if (m_mouse_canvas_index != m_current_canvas_index) {
        // wxMessageBox(" here ");
        return;
    } // wxMessageBox(" here ");
    DoodleSegment* tns = new DoodleSegment();
    wxPoint cursorpoint;
    GetCanvasPixLL(&g_VP, &cursorpoint, m_cursor_lat, m_cursor_lon);
    tns->DrawSegment(dc, &rp1, &rp2, m_VP, true);
    
    
    double lat1, lon1, lat2, lon2, brg, dist;

    GetCanvasLLPix(&g_VP, rp1, &lat1, &lon1);
    GetCanvasLLPix(&g_VP, rp2, &lat2, &lon2);
    DistanceBearingMercator_Plugin(lat2, lon2, lat1, lon1, &brg, &dist);

    wxString sBrg = wxString::Format("%f", brg);

    m_pDialog->m_Bearing->SetValue(sBrg);

    if (m_pDialog)
        RenderExtraPathLegInfo(dc, rp1, sBrg);


    if (m_bFinish) { 
      // let's iterate over the list in STL syntax
        bearingList::iterator iter;
        for (iter = g_pBearingList->begin(); iter != g_pBearingList->end();
             ++iter) {
            bearing* current = *iter;

            //double dd = current->m_bearingBegin->m_x1;
            //wxString dds = wxString::Format("%f", dd);
            
             current->RenderBearing(dc, current->m_bearingBegin->m_x1,
                current->m_bearingBegin->m_y1, current->m_bearingEnd->m_x1,
                current->m_bearingEnd->m_y1, m_VP, false, 4); 
        }
   }
    delete tns;
}

void TradNav_pi::RenderExtraPathLegInfo(piDC& dc, wxPoint ref_point, wxString s)
{
    wxFont dFont(
        12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);  
  
    dc.SetFont(dFont);

    int w, h;
    int xp, yp;
    int hilite_offset = 3;
#ifdef __WXMAC__
    wxScreenDC sdc;
    sdc.GetTextExtent(s, &w, &h, NULL, NULL, dFont);
#else
    dc.GetTextExtent(s, &w, &h);
#endif

    xp = ref_point.x - w;
    yp = ref_point.y + h;
    yp += hilite_offset;

    wxColour tColour;
    GetGlobalColor(wxS("YELO1"), &tColour);
    AlphaBlending(dc, xp, yp, w, h, 0.0, tColour, 172);

    GetGlobalColor(wxS("UBLCK"), &tColour);
    dc.SetPen(wxPen(tColour));
    dc.DrawText(s, xp, yp);
}

/* render a rectangle at a given color and transparency */
void TradNav_pi::AlphaBlending(piDC& dc, int x, int y, int size_x, int size_y,
    float radius, wxColour color, unsigned char transparency)
{
#if 1
    wxDC* pdc = dc.GetDC();
    if (pdc) {
        //    Get wxImage of area of interest
        wxBitmap obm(size_x, size_y);
        wxMemoryDC mdc1;
        mdc1.SelectObject(obm);
        mdc1.Blit(0, 0, size_x, size_y, pdc, x, y);
        mdc1.SelectObject(wxNullBitmap);
        wxImage oim = obm.ConvertToImage();

        //    Create destination image
        wxBitmap olbm(size_x, size_y);
        wxMemoryDC oldc(olbm);
        if (!oldc.IsOk())
             return;

        oldc.SetBackground(*wxBLACK_BRUSH);
        oldc.SetBrush(*wxWHITE_BRUSH);
        oldc.Clear();

        if (radius > 0.0)
             oldc.DrawRoundedRectangle(0, 0, size_x, size_y, radius);

        wxImage dest = olbm.ConvertToImage();
        unsigned char* dest_data = (unsigned char*)malloc(
            size_x * size_y * 3 * sizeof(unsigned char));
        unsigned char* bg = oim.GetData();
        unsigned char* box = dest.GetData();
        unsigned char* d = dest_data;

        //  Sometimes, on Windows, the destination image is corrupt...
        if (NULL == box) {
             free(d);
             return;
        }

        float alpha = 1.0 - (float)transparency / 255.0;
        int sb = size_x * size_y;
        for (int i = 0; i < sb; i++) {
             float a = alpha;
             if (*box == 0 && radius > 0.0)
                a = 1.0;
             int r = ((*bg++) * a) + (1.0 - a) * color.Red();
             *d++ = r;
             box++;
             int g = ((*bg++) * a) + (1.0 - a) * color.Green();
             *d++ = g;
             box++;
             int b = ((*bg++) * a) + (1.0 - a) * color.Blue();
             *d++ = b;
             box++;
        }

        dest.SetData(dest_data);

        //    Convert destination to bitmap and draw it
        wxBitmap dbm(dest);
        dc.DrawBitmap(dbm, x, y, false);

        // on MSW, the dc Bounding box is not updated on DrawBitmap() method.
        // Do it explicitely here for all platforms.
        dc.CalcBoundingBox(x, y);
        dc.CalcBoundingBox(x + size_x, y + size_y);
    } else {
#ifdef ocpnUSE_GL
        /* opengl version */
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        if (radius > 1.0f) {
             wxColour c(color.Red(), color.Green(), color.Blue(), transparency);
             dc.SetBrush(wxBrush(c));
             dc.DrawRoundedRectangle(x, y, size_x, size_y, radius);
        } else {
#ifndef USE_ANDROID_GLES2
             glColor4ub(color.Red(), color.Green(), color.Blue(), transparency);
             glBegin(GL_QUADS);
             glVertex2i(x, y);
             glVertex2i(x + size_x, y);
             glVertex2i(x + size_x, y + size_y);
             glVertex2i(x, y + size_y);
             glEnd();
#endif
        }
        glDisable(GL_BLEND);
#else
        wxLogMessage(_(
            "Alpha blending not drawn as OpenGL not available in this build"));
#endif
    }
#endif
}


void TradNav_pi::appendOSDirSlash(wxString* pString)
{
    wxChar sep = wxFileName::GetPathSeparator();

    if (pString->Last() != sep)
        pString->Append(sep);
}

void TradNav_pi::tdRequestRefresh(int canvas_index, bool bFullRefresh)
{
    if (!bFullRefresh) {
        if (canvas_index != -1)
            RequestRefresh(GetCanvasByIndex(canvas_index));
    } else {
        for (int i = 0; i < GetCanvasCount(); ++i) {
            RequestRefresh(GetCanvasByIndex(i));
        }
    }
}
