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

#include "TradNavgui_impl.h"
#include "TradNavgui.h"
#include "TradNav_pi.h"
#include "icons.h"

#include <wx/progdlg.h>
#include <wx/wx.h>
#include "wx/dir.h"
#include <list>
#include <cmath>

class RangeFix;

#ifdef __OCPN__ANTradNavOID__
wxWindow *g_Window;
#endif

#define FAIL(X) do { error = X; goto failed; } while(0)

Dlg::Dlg(wxWindow *parent, TradNav_pi *ppi)
	: m_Dialog(parent)
{
	this->Fit();
	dbg = false; //for debug output set to true
	
	pPlugIn = ppi;
	pParent = parent;
    m_bShowBearing = false;

#ifdef __OCPN__ANTradNavOID__
    g_Window = this;
    GetHandle()->setStyleSheet( qtStyleSheet);
    Connect( wxEVT_MOTION, wxMouseEventHandler( Dlg::OnMouseEvent ) );
#endif
	
}

Dlg::~Dlg()
{
	
}

#ifdef __OCPN__ANTradNavOID__ 
wxPoint g_startPos;
wxPoint g_startMouse;
wxPoint g_mouse_pos_screen;

void Dlg::OnMouseEvent( wxMouseEvent& event )
{
    g_mouse_pos_screen = ClientToScreen( event.GetPosition() );
    
    if(event.Dragging()){
        int x = wxMax(0, g_startPos.x + (g_mouse_pos_screen.x - g_startMouse.x));
        int y = wxMax(0, g_startPos.y + (g_mouse_pos_screen.y - g_startMouse.y));
        int xmax = ::wxGetDisplaySize().x - GetSize().x;
        x = wxMin(x, xmax);
        int ymax = ::wxGetDisplaySize().y - (GetSize().y * 2);          // Some fluff at the bottom
        y = wxMin(y, ymax);
        
        g_Window->Move(x, y);
    }
}
#endif

void Dlg::Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype){
//add point
	TiXmlElement * RoutePoint = new TiXmlElement( "rtept" );
    RoutePoint->SetAttribute("lat", ptlat.mb_str());
    RoutePoint->SetAttribute("lon", ptlon.mb_str());


    TiXmlElement * Name = new TiXmlElement( "name" );
    TiXmlText * text = new TiXmlText( ptname.mb_str() );
    RoutePoint->LinkEndChild( Name );
    Name->LinkEndChild( text );

    TiXmlElement * Symbol = new TiXmlElement( "sym" );
    TiXmlText * text1 = new TiXmlText( ptsym.mb_str() );
    RoutePoint->LinkEndChild( Symbol );
    Symbol->LinkEndChild( text1 );

    TiXmlElement * Type = new TiXmlElement( "type" );
    TiXmlText * text2 = new TiXmlText( pttype.mb_str() );
    RoutePoint->LinkEndChild( Type );
    Type->LinkEndChild( text2 );
    Route->LinkEndChild( RoutePoint );
//done adding point
}

void Dlg::OnClose(wxCloseEvent& event)
{	
	pPlugIn->OnTradNavDialogClose();
}

void Dlg::OnStart(wxCommandEvent& event) { 
    
        myTimer->Stop();    
}

void Dlg::OnStop(wxCommandEvent& event) { 
    myTimer->Stop(); 
}


void Dlg::OnDraw(wxCommandEvent& event) { 
    
    myTimer->Stop();

    return;

        myRange.lat = pPlugIn->GetCursorLat();
    myRange.lon = pPlugIn->GetCursorLon();
    myRange.range = 10.0;

    wxString myLat = wxString::Format("%f", myRange.lat);
    // wxMessageBox(myRangePix);
    m_textCtrlLat->SetFocus();
    m_textCtrlLat->SetValue(myLat);

    wxString myLon = wxString::Format("%f", myRange.lon);
    m_textCtrlLon->SetValue(myLon);

    wxColour myColour = wxColour("RED");
    wxString guid
        = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));

    rangeWaypoint = new PlugIn_Waypoint_Ex(myRange.lat, myRange.lon, "circle",
        "test", guid, 8000000, true, 1, 10.5, myColour);
    rangeWaypoint->b_useScamin = false;

    AddSingleWaypointEx(rangeWaypoint, false);
    RequestRefresh(pPlugIn->m_parent_window);


}

void Dlg::OnUpdate() { 
                        
                
    nRoute = new PlugIn_Route_Ex();

    wxString guid = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));
    nRoute->m_GUID = guid;

    
    nRoute->m_NameString = "test";
    nRoute->m_StartString = "start";
    nRoute->m_EndString = "end";
    
    
    myList = eblRoute->pWaypointList;

               

                //PlugIn_Waypoint_Ex *pwaypointex, *pwaypointex1;

                pwpnode = myList->GetFirst();
                pwaypointex = pwpnode->GetData();
                
                nRoute->pWaypointList->Append(pwaypointex);

                pwpnode = myList->GetLast();
                pwaypointex1 = pwpnode->GetData();

                nRoute->pWaypointList->Append(pwaypointex1);

                newList = nRoute->pWaypointList;
                
                pwpnode = newList->GetFirst();
                pwpt = pwpnode->GetData();

                pwpnode = newList->GetLast();
                pwpt1 = pwpnode->GetData();


                double lat0, lon0, lat1, lon1;
                lat0 = pwpt->m_lat;

                wxString myLon = wxString::Format("%f", pwpt->m_lon);
                wxMessageBox(myLon);

                lon0 = pwpt->m_lon;
                lat1 = pwpt1->m_lat;
                lon1 = pwpt1->m_lon;
                double brg;
                double dist;

                DistanceBearingMercator(lat0, lon0, lat1, lon1, &dist, &brg);

                wxString myBrg = wxString::Format("%f", brg);

                m_Bearing->SetValue(myBrg);
                
                
        

    

}

/*
void Dlg::OnDraw(wxCommandEvent& event)
{

    PlugIn_Waypoint* wayPointA
        = new PlugIn_Waypoint(50.0, -4.0, "swp", "Test", "");
    wayPointA->m_MarkDescription = "";
    wayPointA->m_IsVisible = true;
    wayPointA->m_IconName = "circle";

    AddSingleWaypoint(wayPointA, false);

    PlugIn_Waypoint* wayPointB
        = new PlugIn_Waypoint(30.0, -40.0, "swp1", "Test1", "");
    wayPointB->m_MarkDescription = "";
    wayPointB->m_IsVisible = true;
    wayPointB->m_IconName = "circle";

    AddSingleWaypoint(wayPointB, false);

    PlugIn_Route* newRoute
        = new PlugIn_Route; // for adding a route on OpenCPN chart display

    newRoute->m_GUID = "AB";
    newRoute->m_NameString = "AB";
    newRoute->m_StartString = "A";
    newRoute->m_EndString = "B";

    newRoute->pWaypointList->Append(wayPointA);
    newRoute->pWaypointList->Append(wayPointB);

    AddPlugInRoute(newRoute, false);

    RequestRefresh(pPlugIn->m_parent_window);
}*/


void Dlg::OnLeft() {

	AddMyWaypoint();

	if (m_checkBoxAddEBL->IsChecked()) {

	PlugIn_Waypoint* wayPointB
        = new PlugIn_Waypoint(m_cursor_lat, m_cursor_lon, "swp", "", "");
    wayPointB->m_MarkDescription = "";
    wayPointB->m_IsVisible = true;
    wayPointB->m_IconName = "Symbol-X-Large-Red";

    AddSingleWaypoint(wayPointB, false);

	 newRoute
        = new PlugIn_Route; // for adding a route on OpenCPN chart display

    newRoute->m_GUID = "AB";
    newRoute->m_NameString = "AB";
    newRoute->m_StartString = "A";
    newRoute->m_EndString = "B";

    newRoute->pWaypointList->Append(wayPointA);
    newRoute->pWaypointList->Append(wayPointB);

    AddPlugInRoute(newRoute, false);

	m_bLeftUp = true;
    m_bRadius = false;

    RequestRefresh(pPlugIn->m_parent_window);

	}

}

void Dlg::OnDrag() { 

	if (m_bLeftUp) { 
		i++;
		wxString myI = wxString::Format("%i", i);
		
        
		m_textCtrlLat->SetValue(myI);

	}
}

void Dlg::OnMouseDrag(wxMouseEvent& event) { 

    m_textCtrlRange->SetFocus();

        //int x = event.GetX();

        double myR = 5.0;
        wxString myRR = wxString::Format("%f", myR);

        m_textCtrlLat->SetValue(myRR);

    

}

void Dlg::text_shortcut(wxCommandEvent& event) {

    myTimer->Stop();
    
    OnRangeCursorSelect(event);
        event.Skip();
}

void Dlg::key_shortcut(wxKeyEvent& event)
{      
              
    // of course, it doesn't have to be the control key. You can use others:
    // http://docs.wxwidgets.org/stable/wx_wxkeyevent.html
        if (event.GetModifiers() == wxMOD_CONTROL) {
                switch (event.GetKeyCode()) {
                case 'B': // can return the upper ASCII value of a key
        // do whatever you like for a Ctrl+G event here!
                        myTimer->Stop();    
                        OnCursor();
                        break;
                case 'R':
                        OnRangeCursor();
                        break;
                case 'H':
                        OnHorizontal();
                        break;



                case WXK_LEFT: // we also have special keycodes for non-ascii
                               // values.
        // get a full list of special keycodes here:
        // http://docs.wxwidgets.org/stable/wx_keycodes.html
        wxMessageBox(_("CTRL+Left"));
        break;
                default: // do nothing
        break;
                }
        }
    event.Skip();
}

void Dlg::OnCursorSelect(wxCommandEvent& event)
{

    wxMessageBox(_("To copy the cursor location place the cursor on the chart "
                   "\n     ...and press <CTRL>+B"));
    m_textCtrlLat->SetFocus();
    myTimer->Stop();

    event.Skip();
}

void Dlg::OnCursor(wxCommandEvent& event) { 
        
    OnCursor(); 
}

void Dlg::OnCursor(void)
{   
    myRange.lat = pPlugIn->GetCursorLat();
    myRange.lon = pPlugIn->GetCursorLon();
    myRange.range = 10.0;

    wxString myLat = wxString::Format("%f", myRange.lat);
    m_textCtrlLat->SetFocus();
    m_textCtrlLat->SetValue(myLat);
   
    wxString myLon = wxString::Format("%f", myRange.lon);
    m_textCtrlLon->SetValue(myLon);
    
    wxColour myColour = wxColour("RED");
    wxString guid = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));

    rangeWaypoint = new PlugIn_Waypoint_Ex(myRange.lat, myRange.lon, "Symbol-X-Large-Red",
        "for bearing", guid, 8000000, true, 0, 0, myColour);
    rangeWaypoint->b_useScamin = false;

    AddSingleWaypointEx(rangeWaypoint, false); 

    RequestRefresh(pPlugIn->m_parent_window);

    guid = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));

    myRange.lat += 0.1;

    eblWaypoint = new PlugIn_Waypoint_Ex(myRange.lat, myRange.lon, "circle",
        "move for bearing", guid, 8000000, true, 0, 0, myColour);
    eblWaypoint->b_useScamin = false;

    AddSingleWaypointEx(eblWaypoint, false); 

    eblRoute = new PlugIn_Route_Ex();
    eblRoute->pWaypointList->Append(eblWaypoint);

    guid = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));
    eblRoute->m_GUID = guid;
    eblRoute->pWaypointList->Append(rangeWaypoint);
    eblRoute->m_NameString = "bearing";
    eblRoute->m_StartString = "start";
    eblRoute->m_EndString = "end";

    AddPlugInRouteEx(eblRoute, false);
    myTimer->Start(500, wxTIMER_CONTINUOUS);

    GetParent()->Refresh();
}

void Dlg::OnHorizontalSelect(wxCommandEvent& event) {

    wxMessageBox(_("To copy the cursor location place the cursor on the chart "
                   "\n     ...and press <CTRL>+H"));

    m_Bearing->SetFocus();
    myTimer->Stop();

    event.Skip();
}

void Dlg::OnHorizontal(wxCommandEvent& event) { 
    
    OnHorizontal(); 

}

void Dlg::OnHorizontal() {
    
    myRange.lat = pPlugIn->GetCursorLat();
    myRange.lon = pPlugIn->GetCursorLon();
    myRange.range = 10.0;

    wxString myLat = wxString::Format("%f", myRange.lat);
    m_textCtrlLat->SetFocus();
    m_textCtrlLat->SetValue(myLat);

    wxString myLon = wxString::Format("%f", myRange.lon);
    m_textCtrlLon->SetValue(myLon);

    wxColour myColour = wxColour("RED");
    wxString guid
        = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));

    rangeWaypoint
        = new PlugIn_Waypoint_Ex(myRange.lat, myRange.lon, "Symbol-X-Large-Red",
            "point1", guid, 8000000, true, 0, 0, myColour);
    rangeWaypoint->b_useScamin = false;

    AddSingleWaypointEx(rangeWaypoint, false);

    RequestRefresh(pPlugIn->m_parent_window);

    guid = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));

    myRange.lat += 0.1;

    eblWaypoint = new PlugIn_Waypoint_Ex(myRange.lat, myRange.lon, "Symbol-X-Large-Red",
        "point2", guid, 8000000, true, 0, 0, myColour);
    eblWaypoint->b_useScamin = false;

    AddSingleWaypointEx(eblWaypoint, false);

    eblRoute = new PlugIn_Route_Ex();
    eblRoute->pWaypointList->Append(eblWaypoint);

    guid = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));
    eblRoute->m_GUID = guid;
    eblRoute->pWaypointList->Append(rangeWaypoint);
    eblRoute->m_NameString = "bearing";
    eblRoute->m_StartString = "start";
    eblRoute->m_EndString = "end";

    AddPlugInRouteEx(eblRoute, false);

    wxString horizontalangle = m_textCtrlHorizontal->GetValue();
    double ha;
    horizontalangle.ToDouble(&ha);
    double hsa = 90 - ha;

    double lat1, lon1, lat0, lon0, dist, brg;

    lat0 = rangeWaypoint->m_lat;
    lon0 = rangeWaypoint->m_lon;
    lat1 = eblWaypoint->m_lat;
    lon1 = eblWaypoint->m_lon;

    DistanceBearingMercator(lat1, lon1, lat0, lon0, &dist, &brg);

    myLon = wxString::Format("%f", brg);
    wxMessageBox(myLon);

    double brg1, brg2;
    brg1 = brg + hsa;
    if (brg1 > 360) {
                brg1 -= 360;
    }

    DistanceBearingMercator(lat0, lon0, lat1, lon1,  &dist, &brg);

    brg2 = brg - hsa;
    if (brg < hsa) {
                brg2 = 360 - (hsa - brg);
    }

    double r;
    double initVector;
    initVector = hsa * d2r;
    r = (dist / 2)/cos(initVector);




    GetParent()->Refresh();


}

void Dlg::OnRangeCursorSelect(wxCommandEvent& event)
{

    wxMessageBox(_("To copy the cursor location place the cursor on the chart "
                   "\n     ...and press <CTRL>+R"));

    m_Bearing->SetFocus();
    myTimer->Stop();

    event.Skip();
}

void Dlg::OnRangeCursor(wxCommandEvent& event)
{
    OnRangeCursor();
}

void Dlg::OnRangeCursor(void)
{
    if (myTimer->IsRunning())
                myTimer->Stop();

    myRange.lat = pPlugIn->GetCursorLat();
    myRange.lon = pPlugIn->GetCursorLon();

    double lat, lon;
    lat = myRange.lat;
    lon = myRange.lon;

    wxString myR = m_textCtrlRange->GetValue();
    double myRange; 
    myR.ToDouble(&myRange);
    
    wxString myLat = wxString::Format("%f", lat);
    m_textCtrlLat->SetValue(myLat);

    wxString myLon = wxString::Format("%f", lon);
    m_textCtrlLon->SetValue(myLon);

    wxColour myColour = wxColour("RED");
    wxString guid
        = wxString::Format(_T("%i"), (int)GetRandomNumber(1, 4000000));
    myguid = guid;
    rangeWaypoint = new PlugIn_Waypoint_Ex(lat, lon,
        "Symbol-X-Large-Red", "Range", guid, 8000000, true, 1, myRange, myColour);
    rangeWaypoint->b_useScamin = false;
    rangeWaypoint->IsVisible = true;


    AddSingleWaypointEx(rangeWaypoint, false);

    RequestRefresh(pPlugIn->m_parent_window);
}



void Dlg::OnTimer(wxTimerEvent& event) { Notify(); }

void Dlg::Notify() { 

    //OnTest();
    double lat0, lon0, lat1, lon1;
    lat0 = rangeWaypoint->m_lat;

    //wxString myLon = wxString::Format("%f", pwpt->m_lon);
    //wxMessageBox(myLon);

    lon0 = rangeWaypoint->m_lon;
    lat1 = pPlugIn->GetCursorLat();
    lon1 = pPlugIn->GetCursorLon();
    double brg;
    double dist;

    DistanceBearingMercator(lat0, lon0, lat1, lon1, &dist, &brg);
    myBrg = wxString::Format("%f", brg);
    m_Bearing->SetFocus();
    m_Bearing->SetValue(myBrg);

    myDist = wxString::Format("%f", dist);
    m_textCtrlRange->SetFocus();
    m_textCtrlRange->SetValue(myDist);

    rangeWaypoint->RangeRingSpace = dist;
    UpdateSingleWaypointEx(rangeWaypoint);
    /*
    if (editWaypoint == NULL) {
                editWaypoint = new PlugIn_Waypoint_Ex(*rangeWaypoint);
                wxString guid = wxString::Format(
                    _T("%i"), (int)GetRandomNumber(1, 4000000));

                editWaypoint->m_GUID = guid;
                editWaypoint->m_MarkName = "edit";

                lat0 = editWaypoint->m_lat;
                lon0 = editWaypoint->m_lon;
                lat1 = pPlugIn->GetCursorLat();
                lon1 = pPlugIn->GetCursorLon();

                DistanceBearingMercator(lat0, lon0, lat1, lon1, &dist, &brg);

                editWaypoint->RangeRingSpace = dist;
                AddSingleWaypointEx(editWaypoint);
    } else {
                lat0 = editWaypoint->m_lat;
                lon0 = editWaypoint->m_lon;
                lat1 = pPlugIn->GetCursorLat();
                lon1 = pPlugIn->GetCursorLon();

                DistanceBearingMercator(lat0, lon0, lat1, lon1, &dist, &brg);
                editWaypoint->RangeRingSpace = dist;
                UpdateSingleWaypointEx(editWaypoint);
    }*/
    double la, ln, rg;
    m_textCtrlLat->GetValue().ToDouble(&la);
    m_textCtrlLon->GetValue().ToDouble(&ln);
    m_textCtrlRange->GetValue().ToDouble(&rg);

    m_start_lat = la;
    m_start_lon = ln;

    myBrg = m_Bearing->GetValue();

    GetParent()->Refresh();
}

int Dlg::GetRandomNumber(int range_min, int range_max)
{
    long u = (long)wxRound(
        ((double)rand() / ((double)(RAND_MAX) + 1) * (range_max - range_min))
        + range_min);
    return (int)u;
}

void Dlg::AddRadius()
{   
    
    double la, ln, rg;   
    m_textCtrlLat->GetValue().ToDouble(&la);
    m_textCtrlLon->GetValue().ToDouble(&ln);
    m_textCtrlRange->GetValue().ToDouble(&rg);
         
         m_start_lat = la;
         m_start_lon = ln;
         m_dRange = rg;

	    GetCanvasPixLL(m_vp, &p1, m_start_lat, m_start_lon);
        newDrawFix.myRangePoint = p1; // Points for ranges

	    double latitude = m_vp->clat;
	    int h = m_vp->pix_height;
        double l =  m_vp->lat_max - m_vp->lat_min;

        double zoom = (log2(156543.03392 * cos(latitude * PI / 180) * h/(l*60*1852) ));
	
	    double num = 2;

        double boxlat = m_vp->clat;

        double mpp;
        mpp = 156543.03392 * cos(boxlat * PI / 180) / pow(num, zoom);
				
        myPix = 1852 * m_dRange / mpp;
        newDrawFix.myRangePix = myPix; // pix for the ranges

        
        //wxString myRangePix = wxString::Format("%i", myPix);
        //wxMessageBox(myRangePix);
    
}

void Dlg::AddMyWaypoint() { 

	if (m_checkBoxAdd->IsChecked()) {

		wayPointA
      = new PlugIn_Waypoint(m_cursor_lat, m_cursor_lon, "swp", "", "");
  wayPointA->m_MarkDescription = "";
  wayPointA->m_IsVisible = true;
  wayPointA->m_IconName = "Symbol-X-Large-Red";

  AddSingleWaypoint(wayPointA, false);

  m_start_lat = m_cursor_lat;
  m_start_lon = m_cursor_lon;

  RequestRefresh(pPlugIn->m_parent_window);
	
	m_checkBoxAdd->SetValue(false);

	m_bLeftUp = false;

	i = 0;

	}

}

void Dlg::SetViewPort(PlugIn_ViewPort* vp)
{
        if (m_vp == vp)
        return;

        m_vp = new PlugIn_ViewPort(*vp);
}

