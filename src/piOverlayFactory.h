/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  Climatology Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2014 by Sean D'Epagnier                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
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
 ***************************************************************************
 */

#include <list>
#include <map>


class PlugIn_ViewPort;
class piDC;
class wxDC;

#ifdef __OCPN__ANDROID__
#include <qopengl.h>
#include "gl_private.h"
#endif

//----------------------------------------------------------------------------------------------------------
//    Climatology Overlay Specification
//----------------------------------------------------------------------------------------------------------

class piOverlay {
public:
    piOverlay( void )
    {
        m_iTexture = 0;
        m_pDCBitmap = NULL, m_pRGBA = NULL;
        m_latoff = m_lonoff = 0;
    }

    ~piOverlay( void );

    unsigned int m_iTexture; /* opengl mode */

    wxBitmap *m_pDCBitmap; /* dc mode */
    unsigned char *m_pRGBA;

    int m_width, m_height;
    double m_latoff, m_lonoff;
};

//----------------------------------------------------------------------------------------------------------
//    Climatology Overlay Factory Specification
//----------------------------------------------------------------------------------------------------------

class Dlg;
class wxGLContext;
class piOverlayFactory;

class piOverlayFactory {
public:
    piOverlayFactory( Dlg &dlg );
    ~piOverlayFactory();
	
	
	void SetParentSize( int w, int h ) { m_ParentSize.SetWidth(w) ; m_ParentSize.SetHeight(h) ;}
	bool RenderOverlay(piDC &dc, PlugIn_ViewPort &vp);

	piDC *m_dc;

	wxPoint polyPoints[4];
    
    bool RenderText(piDC& dc, PlugIn_ViewPort& vp);
 
private:
	wxSize  m_ParentSize;

	void Plot(piDC *dc, PlugIn_ViewPort *vp, wxColour color);

    void DrawMyRange(PlugIn_ViewPort* BBox);

    

    void DrawText(double x1, double y1, double x2, double y2,
        const wxColour& color, double width);

    void DrawLine( double x1, double y1, double x2, double y2,
                   const wxColour &color, double width );

    void DrawCircle( double x, double y, double r, const wxColour &color, double width );

    bool CreateGLTexture(piOverlay &O, int setting, int month, PlugIn_ViewPort &vp);
    void DrawGLTexture( piOverlay &O1, piOverlay &O2,
                        double dpos, PlugIn_ViewPort &vp, double transparency);

	void DrawNumbers(wxPoint p, double value, int settings,
		wxColour back_color);

    int piOverlayFactory::GetRangePixVP(
            PlugIn_ViewPort& vp, double r);

    Dlg &m_dlg;

    

    wxString m_sFailedMessage;
};
