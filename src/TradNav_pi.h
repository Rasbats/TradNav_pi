/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  TradNav Plugin
 * Author:   Mike Rossiter
 *
 ***************************************************************************
 *   Copyright (C) 2013 by Mike Rossiter                                   *
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

#ifndef _CALCULATOR_PI_H_
#define _CALCULATOR_PI_H_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include <wx/glcanvas.h>
#endif // precompiled headers

#include <wx/fileconf.h>

#include "TradNavgui.h"
#include "TradNavgui_impl.h"
#include "ocpn_plugin.h" //Required for OCPN plugin functions

#include "piOverlayFactory.h"
#include "pidc.h"
#include <vector>
#include <wx/dc.h>
#include <wx/event.h>

#include "config.h"
#include "doc.h"
#include "globals.h"
#include "wx/docview.h"
#include "range.h"
#include "globals.h"

#include "bearing.h"

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define CALCULATOR_TOOL_POSITION                                               \
    -1 // Request default positioning of toolbar tool

class Dlg;
class piDC;
class Position;
class DoodleSegment;


class TradNav_pi : public opencpn_plugin_117 {
public:
    TradNav_pi(void* ppimgr);
    ~TradNav_pi(void);

    //    The required PlugIn Methods
    int Init(void);
    bool DeInit(void);

    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();
    wxBitmap* GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();

    //    The required override PlugIn Methods
    int GetToolbarToolCount(void);
    void OnToolbarToolCallback(int id);

    //    Optional plugin overrides
    void SetColorScheme(PI_ColorScheme cs);

    //    The override PlugIn Methods

    //    Other public methods
    void SetCalculatorDialogX(int x) { m_route_dialog_x = x; };
    void SetCalculatorDialogY(int x) { m_route_dialog_y = x; };
    void SetCalculatorDialogWidth(int x) { m_route_dialog_width = x; };
    void SetCalculatorDialogHeight(int x) { m_route_dialog_height = x; };
    void OnTradNavDialogClose();
    double GetCursorLon(void) { return m_cursor_lon; }
    double GetCursorLat(void) { return m_cursor_lat; }
    double SetCursorLon(double lon) { return m_cursor_lon; }
    double SetCursorLat(double lat) { return m_cursor_lat; }
    void SetCursorLatLon(double lat, double lon);

    bool RenderGLOverlay(wxGLContext* pcontext, PlugIn_ViewPort* vp);
    bool RenderGLOverlays(wxGLContext* pcontext, PlugIn_ViewPort* vp);
    bool RenderGLOverlayMultiCanvas(
        wxGLContext* pcontext, PlugIn_ViewPort* vp, int canvas_index);
    bool RenderOverlay(wxMemoryDC* pmdc, PlugIn_ViewPort* vp);
    bool RenderOverlay(wxDC& dc, PlugIn_ViewPort* vp);
    bool RenderOverlays(wxDC& dc, PlugIn_ViewPort* pivp);
    bool RenderOverlayMultiCanvas(
        wxDC& dc, PlugIn_ViewPort* vp, int canvas_index);
    void RenderPathLegs(piDC& dc);

    void RenderExtraPathLegInfo(piDC& dc, wxPoint ref_point, wxString s);
    void AlphaBlending(piDC& dc, int x, int y, int size_x,
        int size_y, float radius, wxColour color, unsigned char transparency);

    PlugIn_ViewPort g_VP;

    wxWindow* m_parent_window;
    wxWindow* g_parent_window;
    wxWindow* m_plugin_window;

    piDC m_oDC;
    Dlg* m_pDialog;
    double m_cur_lat[10];
    double m_cur_lon[10];
    int clickn;
    int m_drawing_canvas_index;
    int g_cursor_x;
    int g_cursor_y;
    wxPoint m_cursorPoint;
    wxWindow* g_current_canvas;
    int g_current_canvas_index;
    bool CreateLine(wxMouseEvent event);
    DoodleSegment* currentSegment;
    DoodleLine* newLine;

    RangeCircle* rangeCircle;



        double m_chart_scale;
    double m_view_scale;
    wxGLContext* m_pcontext;
    wxMemoryDC* pmdc;
    tdPath* m_pSelectedPath;
    void appendOSDirSlash(wxString* pString);
    void tdRequestRefresh(int canvas_index, bool bFullRefresh);
    bearing* newBearing;
    bearingPoint* newBPbegin;
    bearingPoint* newBPend;
    bool m_bFinish;

private:
    wxFileConfig* m_pconfig;

    bool LoadConfig(void);
    bool SaveConfig(void);

    bool MouseEventHook(wxMouseEvent& event);

    int m_route_dialog_x, m_route_dialog_y, m_route_dialog_width,
        m_route_dialog_height;
    int m_display_width, m_display_height;
    int m_leftclick_tool_id;
    bool m_ShowHelp, m_bCaptureCursor, m_bCaptureShip;
    double m_ship_lon, m_ship_lat, m_cursor_lon, m_cursor_lat;
    bool m_bTradNavShowIcon;
    bool m_bShowTradNav;
    wxBitmap m_panelBitmap;
    bool KeyboardEventHook(wxKeyEvent& event);
    int m_position_menu_id;
    int m_mouse_canvas_index;
    int m_current_canvas_index;
    PlugIn_ViewPort m_VP;
    wxPoint rp1;
    wxPoint rp2;
    DoodleSegment* m_pSelectedSegment;
};

#endif
