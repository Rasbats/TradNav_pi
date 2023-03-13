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

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "TradNav_pi.h"
#include "TradNavgui_impl.h"
#include "TradNavgui.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new TradNav_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

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

TradNav_pi::TradNav_pi(void *ppimgr)
      :opencpn_plugin_117 (ppimgr)
{
      // Create the PlugIn icons
      initialize_images();

	  wxFileName fn;
	  wxString tmp_path;

	  tmp_path = GetPluginDataDir("TradNav_pi");
	  fn.SetPath(tmp_path);
	  fn.AppendDir(_T("data"));
	  fn.SetFullName("tradnav_pi_panel_icon.png");

	  wxString shareLocn = fn.GetFullPath();
	  wxImage panelIcon(shareLocn);
	  
	  if (panelIcon.IsOk())
		  m_panelBitmap = wxBitmap(panelIcon);
	  else
		  wxLogMessage(_T("    TradNav_pi panel icon NOT loaded"));
	  m_bShowTradNav = false;
}

TradNav_pi::~TradNav_pi(void)
{
     delete _img_TradNav_pi;
     delete _img_TradNav;
     
}

int TradNav_pi::Init(void)
{
      AddLocaleCatalog( _T("opencpn-TradNav_pi") );

      // Set some default private member parameters
      m_route_dialog_x = 0;
      m_route_dialog_y = 0;
      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
      LoadConfig();

      //    This PlugIn needs a toolbar icon, so request its insertion
	if(m_bTradNavShowIcon)

#ifdef TradNav_USE_SVG
		m_leftclick_tool_id = InsertPlugInToolSVG(_T("TradNav"), _svg_tradnav, _svg_tradnav, _svg_tradnav_toggled,
			wxITEM_CHECK, _("TradNav"), _T(""), NULL, CALCULATOR_TOOL_POSITION, 0, this);
#else
		m_leftclick_tool_id = InsertPlugInTool(_T(""), _img_TradNav, _img_TradNav, wxITEM_CHECK,
			_("TradNav"), _T(""), NULL,
			CALCULATOR_TOOL_POSITION, 0, this);
#endif
    

      m_pDialog = NULL;

return (WANTS_OVERLAY_CALLBACK | WANTS_CURSOR_LATLON
          | WANTS_TOOLBAR_CALLBACK | INSTALLS_TOOLBAR_TOOL | WANTS_CONFIG
          | INSTALLS_CONTEXTMENU_ITEMS | WANTS_NMEA_EVENTS | USES_AUI_MANAGER
          | WANTS_PREFERENCES | WANTS_ONPAINT_VIEWPORT | WANTS_PLUGIN_MESSAGING
          | WANTS_OPENGL_OVERLAY_CALLBACK | WANTS_LATE_INIT | WANTS_MOUSE_EVENTS
          | WANTS_KEYBOARD_EVENTS);
}

bool TradNav_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pDialog)
      {
            //Capture dialog position
            wxPoint p = m_pDialog->GetPosition();
            SetCalculatorDialogX(p.x);
            SetCalculatorDialogY(p.y);
            if ((m_pDialog->myTimer != NULL)
                && (m_pDialog->myTimer->IsRunning())) { // need to stop the timer or crash on
                                          // exit
                m_pDialog->myTimer->Stop();
            }

            m_pDialog->Close();
            delete m_pDialog;
            m_pDialog = NULL;

			m_bShowTradNav = false;
			SetToolbarItemState( m_leftclick_tool_id, m_bShowTradNav );

      }	
    
    SaveConfig();

    RequestRefresh(m_parent_window); // refresh main window

    return true;
}

int TradNav_pi::GetAPIVersionMajor()
{
      return atoi(API_VERSION);
}

int TradNav_pi::GetAPIVersionMinor()
{
      std::string v(API_VERSION);
    size_t dotpos = v.find('.');
    return atoi(v.substr(dotpos + 1).c_str());
}

int TradNav_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int TradNav_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *TradNav_pi::GetPlugInBitmap()
{
      return &m_panelBitmap;
}

wxString TradNav_pi::GetCommonName()
{
      return _("TradNav");
}


wxString TradNav_pi::GetShortDescription()
{
      return _("TradNav Positions using GPX files");
}

wxString TradNav_pi::GetLongDescription()
{
      return _("Creates GPX files with\n\
TradNav Positions");
}

int TradNav_pi::GetToolbarToolCount(void)
{
      return 1;
}

void TradNav_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pDialog)
            return;

      DimeWindow(m_pDialog);
}

void TradNav_pi::OnToolbarToolCallback(int id)
{
    
	if(NULL == m_pDialog)
      {
            m_pDialog = new Dlg(m_parent_window, this);
            m_pDialog->Move(wxPoint(m_route_dialog_x, m_route_dialog_y));
            m_pDialog->myTimer = new wxTimer(m_pDialog);
            // Create the drawing factory
            m_pOverlayFactory = new piOverlayFactory(*m_pDialog);
            m_pOverlayFactory->SetParentSize(m_display_width, m_display_height);		

      }

	  m_pDialog->Fit();
	  //Toggle 
	  m_bShowTradNav = !m_bShowTradNav;	  

      //    Toggle dialog? 
      if(m_bShowTradNav) {
          m_pDialog->Show();         
      } else
          m_pDialog->Hide();
     
      // Toggle is handled by the toolbar but we must keep plugin manager b_toggle updated
      // to actual status to ensure correct status upon toolbar rebuild
      SetToolbarItemState( m_leftclick_tool_id, m_bShowTradNav );

      RequestRefresh(m_parent_window); // refresh main window
}

bool TradNav_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/TradNav_pi" ) );
			 pConf->Read ( _T( "ShowTradNavIcon" ), &m_bTradNavShowIcon, 1 );
           
            m_route_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_route_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );
         
            if((m_route_dialog_x < 0) || (m_route_dialog_x > m_display_width))
                  m_route_dialog_x = 5;
            if((m_route_dialog_y < 0) || (m_route_dialog_y > m_display_height))
                  m_route_dialog_y = 5;
            return true;
      }
      else
            return false;
}

bool TradNav_pi::SaveConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T ( "/Settings/TradNav_pi" ) );
			pConf->Write ( _T ( "ShowTradNavIcon" ), m_bTradNavShowIcon );
          
            pConf->Write ( _T ( "DialogPosX" ),   m_route_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_route_dialog_y );
            
            return true;
      }
      else
            return false;
}

void TradNav_pi::OnTradNavDialogClose()
{
    m_bShowTradNav = false;
    SetToolbarItemState( m_leftclick_tool_id, m_bShowTradNav );
    m_pDialog->Hide();
    SaveConfig();

    RequestRefresh(m_parent_window); // refresh main window

}

void TradNav_pi::SetCursorLatLon(double lat, double lon)
{
    m_cursor_lat = lat;
    m_cursor_lon = lon;

    if (m_pDialog) {

            m_pDialog->m_cursor_lat = m_cursor_lat;
            m_pDialog->m_cursor_lon = m_cursor_lon;
    }
}
/*
bool TradNav_pi::MouseEventHook(wxMouseEvent& event)
{
     bool bret = FALSE;
     bool bRefresh = FALSE;
     bool bFullRefresh = FALSE;

     return true;

     if (!m_pDialog)
            return false;     
     
     // g_current_canvas_index = canvasindex;

     if (event.LeftDown()) {
            m_pDialog->OnLeft();            
            //m_pDialog->m_bRadius = false;
     }       
     else if (event.Dragging()) {

        
         //m_pDialog->OnDrag();

        
     } else if (event.LeftUp()) {

            //m_pDialog->m_bLeftUp = true;
         //m_pDialog->m_bRadius = true;
     }      
     else
            event.Skip();
}
*/
bool TradNav_pi::RenderOverlay(wxDC& dc, PlugIn_ViewPort* vp)
{

     if (!m_pDialog || !m_pOverlayFactory)
            return false;

     piDC pidc(dc);

     //m_pDialog->SetViewPort(vp);
     //m_pDialog->AddRadius();

     m_pOverlayFactory->RenderOverlay(pidc, *vp);

     return true;
}

bool TradNav_pi::RenderGLOverlay(wxGLContext* pcontext, PlugIn_ViewPort* vp)
{
     if (!m_pDialog || !m_pOverlayFactory)
            return false;

     piDC piDC;
     m_oDC = piDC;
     glEnable(GL_BLEND);
     piDC.SetVP(vp);

     m_pDialog->SetViewPort(vp);
     m_pOverlayFactory->RenderText(piDC, *vp);
     m_pOverlayFactory->RenderOverlay(piDC, *vp);
     

     return true;
}


