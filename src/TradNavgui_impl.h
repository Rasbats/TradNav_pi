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

#ifndef _CALCULATORGUI_IMPL_H_
#define _CALCULATORGUI_IMPL_H_

#ifdef WX_PRECOMP
#include "wx/wx.h"
#endif


#include "TradNavgui.h"
#include "TradNav_pi.h"

#include "NavFunc.h"
#include "tinyxml.h"

#include <list>
#include <vector>

#include <math.h>
#include <cmath>
#include <wx/timer.h>
#include "ocpn_plugin.h"


#ifdef __OCPN__ANTradNavOID__
#include "qtstylesheet.h"
#endif

using namespace std;

class TradNav_pi;
class Position;
class PlugIn_ViewPort;
class RangeFix;
class piDC;

class RangeFix {
public:
    double lat, lon, range;
    wxPoint myRangePoint;
    int myRangePix;
};


class Dlg : public m_Dialog
{
public:
	Dlg(wxWindow *parent, TradNav_pi *ppi);
	~Dlg();
        
	wxWindow *pParent;
	TradNav_pi *pPlugIn;

#ifdef __OCPN__ANTradNavOID__
    void OnMouseEvent( wxMouseEvent& event );
#endif
		
		vector<Position> my_positions;
		vector<Position> my_points;
    vector<Position> my_curpoints;


        void Addpoint(TiXmlElement* Route, wxString ptlat, wxString ptlon, wxString ptname, wxString ptsym, wxString pttype);
        void OnDraw(wxCommandEvent& event);	
        void OnDrawHorizontal(wxCommandEvent& event);	

        void OnUpdate(); 
		
        void OnDrag();
        double m_dRange;
		
		double m_cursor_lon, m_cursor_lat, m_start_lat, m_start_lon;

		wxString rte_start;
	    wxString rte_end;
        bool m_bLeftUp;
        bool m_bRadius;

		void SetViewPort(PlugIn_ViewPort* vp);
        double metrePerPixel;
        int myPix;
        void AddRadius();

        void text_shortcut(wxCommandEvent& event);
        //void OnMouseDrag(wxMouseEvent& event);
        void key_shortcut(wxKeyEvent& event);
        void OnCursorSelect(wxCommandEvent& event);
        void OnCursor(wxCommandEvent& event);
        void OnCursor(double lat, double lon);

        void OnRightDown();
        void OnRightDownDragging();
        void OnLeftDownDragging();
        void OnToggleRange(wxCommandEvent& event);
        void OnScroll(wxScrollEvent& event);

        void OnCursor(void);

        void OnRangeCursorSelect(wxCommandEvent& event);
        void OnRangeCursor(wxCommandEvent& event);
        void OnRangeCursor(void);
        void OnRangeCursor(double lat, double lon);

        void OnHorizontalSelect(wxCommandEvent& event);
        void OnHorizontal(wxCommandEvent& event);
        void OnHorizontal(void);
        void OnHorizontal(double lat, double lon);

        wxString myguid;

        wxPoint p1;
        RangeFix myRange;
        RangeFix newDrawFix;
        vector<RangeFix> mySetRanges;
        vector<RangeFix> myDrawPoints;
        vector<int> mySetPix;

        PlugIn_ViewPort *m_vp, m_current_vp;
        PlugIn_ViewPort& GetCurrentViewPort() { return m_current_vp; }

        PlugIn_Waypoint_Ex* rangeWaypoint;
        PlugIn_Waypoint_Ex* editWaypoint;

        PlugIn_Waypoint_Ex* eblWaypoint, foundWaypoint;
        PlugIn_Waypoint_Ex* foundWP;
        PlugIn_Route_Ex* eblRoute, *nRoute;
        int GetRandomNumber(int range_min, int range_max);
        bool m_bShowBearing;
        wxTimer* myTimer;
        Plugin_WaypointExList* myList, *newList;
        PlugIn_Waypoint_Ex *pwaypointex, *pwaypointex1, *pwpt, *pwpt1;
        wxPlugin_WaypointExListNode* pwpnode, *pwpnode1;
        PlugIn_Route_Ex* myRoute;
        void OnTimer(wxTimerEvent& event);
        void Notify();
        void OnStart(wxCommandEvent& event);
        void OnStop(wxCommandEvent& event);

        double brg;
        wxString myBrg;
        wxString myDist;
        wxPoint textPoint;

        bool m_bToggleRange;
        bool m_bSetRange;
        wxArrayString m_arrayGUID;
        wxArrayString m_arrayRouteGUID;
        wxString GetClosestWP();
        wxString GetClosestRoute();
        double GetBestAngle(double hsa, double brg);

        wxPoint g_mouse_pos_screen;
        void OnMouseEvent(wxPoint eventP);

 private:
	    void OnClose( wxCloseEvent& event );
        PlugIn_Route* newRoute;
		void AddMyWaypoint(); 
		
		PlugIn_Waypoint* wayPointA;
        void OnLeft();

        double lat1, lon1, lat2, lon2;
        bool error_found;
        bool dbg;
        int i;

		wxString     m_gpx_path;
        
};


class Position
{
public:

    wxString lat, lon, wpt_num;
    double latD, lonD;
    Position *prev, *next; /* doubly linked circular list of positions */
    int routepoint;

};



#endif
