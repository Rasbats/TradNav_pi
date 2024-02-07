/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  OCPN Draw Event Handler Support
 * Author:   Jon Gough
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register                               *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/

#ifndef OCPNDRAWEVENTHANDLER_H
#define OCPNDRAWEVENTHANDLER_H

#include "TradNav_pi.h"
#include <wx/event.h>
#include <wx/timer.h>


// Forward declarations
class tnLine;
class DoodleSegment;

enum {
    HEAD_DOG_TIMER = 1000,
    ODROPOPUP_TIMER,
    ROLLOVER_TIMER,
    OD_TIMER_1,
    BLINK_TIMER,
    LAST_TIMER
};

class tdEventHandler : public wxEvtHandler {
public:
    tdEventHandler(TradNav_pi* parent);
    ~tdEventHandler();

    void SetPath(tdPath* path);
    void SetWindow(wxWindow* window);
    void SetCanvas(wxWindow* window);
    void SetCanvasIndex(int canvasindex);
    void SetLatLon(double lat, double lon);

protected:
private:
    void tdERequestRefresh(int canvas_index, bool bFullRefresh = FALSE);

    TradNav_pi* m_parent;
    wxWindow* m_parent_window;
    tdPath* m_pSelectedPath;
    double m_cursor_lat;
    double m_cursor_lon;
    int m_iFoundPIL;
    DoodleSegment* m_pDoodleSegment;
};

#endif // OCPNDRAWEVENTHANDLER_H
