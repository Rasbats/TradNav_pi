/******************************************************************************
 * $Id: TradNav_pi.h,v 1.0 2015/01/28 01:54:37 jongough Exp $
 *
 * Project:  OpenCPN
 * Purpose:  OpenCPN General Drawing Plugin
 * Author:   Jon Gough
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
 *   $EMAIL$   *
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
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */
#ifndef _OCPNDRAWGLOBALS_H_
#define _OCPNDRAWGLOBALS_H_
class TradNav_pi;
class tnLine;
class tdEventHandler;
class piDC;

class PlugIn_ViewPort;

class SelectItem;

extern TradNav_pi* g_tradnav_pi;
class PathList;
class tdPath;

extern tdEventHandler* g_tdEventHandler;

extern wxWindow* g_parent_window;
extern wxWindow* g_current_canvas;
extern int g_current_canvas_index;

extern bool g_bOpenGL;

extern wxString* g_PrivateDataDir;

extern wxString* g_pHome_Locn;
extern wxString* g_pData;

extern PlugIn_ViewPort g_VP;
extern piDC* g_pDC;



#endif
