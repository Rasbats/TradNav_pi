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

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "tdEventHandler.h"
#include "TradNav_pi.h"
#include "ocpn_plugin.h"
#include "doc.h"
#include <wx/window.h>
#include <wx/clipbrd.h>
#include "tdPath.h"


tdEventHandler::tdEventHandler(TradNav_pi *parent)
{
    //ctor
    m_pSelectedPath = NULL;

    m_parent = parent;
    m_parent_window = GetOCPNCanvasWindow();
    g_current_canvas = g_parent_window;
    g_current_canvas_index = 0;
    wxLogMessage("Finished constructor");
}


void tdEventHandler::SetPath(tdPath *path )
{
    m_pDoodleSegment = NULL;
    m_pSelectedPath = NULL;

    if(path == 0)
        return;

    if (path->m_sTypeString == "DoodleSegment") {
        m_pDoodleSegment = dynamic_cast<DoodleSegment*>(path);
        m_pSelectedPath = m_pDoodleSegment;
    }

    //assert(m_pSelectedPath != 0);
}


void tdEventHandler::SetWindow( wxWindow *window )
{
    m_parent_window = window;
}

void tdEventHandler::SetCanvas( wxWindow *window )
{
    g_current_canvas = window;
}

void tdEventHandler::SetCanvasIndex( int canvasindex )
{
    g_current_canvas_index = canvasindex;
}

void tdEventHandler::SetLatLon( double lat, double lon )
{
    m_cursor_lat = lat;
    m_cursor_lon = lon;
}


tdEventHandler::~tdEventHandler()
{
    //dtor
    wxLogMessage("~tdEventHandler");
}

void tdEventHandler::tdERequestRefresh( int canvas_index, bool bFullRefresh )
{
    if(!bFullRefresh) {
        if(canvas_index != -1) RequestRefresh(GetCanvasByIndex(canvas_index));
    }
    else {
        for(int i = 0; i < GetCanvasCount(); ++i) {
            RequestRefresh(GetCanvasByIndex(i));
        }
    }
}
