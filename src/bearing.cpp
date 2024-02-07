#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "bearing.h"

#include "TradNav_pi.h"
#include "doc.h"
#include "wx/filename.h"
#include "wx/txtstrm.h"

#include <wx/listimpl.cpp>
WX_DEFINE_LIST(bearingList);

/*
 * bearing
 */

bearing::bearing()
    
{ 
  bearingPoint* m_bearingBegin;
 bearingPoint* m_bearingEnd;  

 }

bearing::~bearing() {


}
void bearingLine::AddPoint(bearingLine* bp) { 
  bp; 

}

void bearing::RenderBearing(piDC& dc, double lata, double lona, double latb,
    double lonb, PlugIn_ViewPort& VP, bool bdraw_arrow, int hilite_width)
{
    dc.SetPen(wxPen("RED", 10)); 
  wxPoint start, end;
  GetCanvasPixLL(&VP, &start, lata, lona);
    GetCanvasPixLL(&VP, &end, latb, lonb);

    int xa, ya, xb, yb;
    xa = start.x;
    ya = start.y;
    xb = end.x;
    yb = end.y;

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

    dc.StrokeLine(x0, y0, x1, y1);

}

