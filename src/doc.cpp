/////////////////////////////////////////////////////////////////////////////
// Name:        doc.cpp
// Purpose:     Implements document functionality for the Doodle sample
// Author:      Julian Smart
// Modified by:
// Created:     2004-11-07
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/txtstrm.h"
#include "wx/filename.h"
#include "TradNav_pi.h"
#include "doc.h"



/*
 * DoodleSegment
 */

DoodleSegment::DoodleSegment()
    : tdPath()
{
    m_sTypeString = _T("DoodleSegment");
}

DoodleSegment::~DoodleSegment()
{
   
}



void DoodleSegment::Draw()
{
    wxList::compatibility_iterator node = GetLines().GetFirst();
   
}

void DoodleSegment::DrawSegment( piDC& dc, wxPoint *rp1, wxPoint *rp2, PlugIn_ViewPort &VP, bool bdraw_arrow )
{
    dc.SetPen(wxPen("RED", 1));
   
    RenderSegment(dc, rp1->x, rp1->y, rp2->x, rp2->y, VP, false, 4);
}

void DoodleSegment::RenderSegment(piDC& dc, int xa, int ya, int xb, int yb,
    PlugIn_ViewPort& VP, bool bdraw_arrow, int hilite_width)
{
    //    Get the dc boundary
    int sx, sy;
    sx = VP.pix_width;
    sy = VP.pix_height;

    //    Try to exit early if the segment is nowhere near the screen
    wxRect r(0, 0, sx, sy);
    wxRect s(xa, ya, 1, 1);
    wxRect t(xb, yb, 1, 1);
    s.Union(t);
    if (!r.Intersects(s))
        return;

    //    Clip the line segment to the dc boundary
    int x0 = xa;
    int y0 = ya;
    int x1 = xb;
    int y1 = yb;

    //    If hilite is desired, use a Native Graphics context to render alpha
    //    colours That is, if wxGraphicsContext is available.....


            dc.StrokeLine(x0, y0, x1, y1);
    
}


