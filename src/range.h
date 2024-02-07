/////////////////////////////////////////////////////////////////////////////
// Name:        doc.h
// Purpose:     Document classes for Range sample
// Author:      Julian Smart
// Modified by:
// Created:     2004-12-07
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __DLE_DOCH__
#define __DLE_DOCH__

#include "pidc.h"

class piDC;
/*
 * Defines a range circle
 */

class RangeCircle: public wxObject
{
public:
    RangeCircle() {};
    RangeCircle(const RangeCircle& rng);
    ~RangeCircle();

    RangeCircle(wxInt32 x1 = 0, wxInt32 y1 = 0, wxInt32 rr = 0)
    { m_x1 = x1; m_y1 = y1; m_rr; }

    wxInt32 m_x1;
    wxInt32 m_y1;
    wxInt32 m_rr;

    void DrawRange(piDC& dc, wxPoint* rp1, int rr, PlugIn_ViewPort& VP,
        bool bdraw_arrow);
    void RenderRange(piDC& dc, int xa, int ya, int rr, 
        PlugIn_ViewPort& VP, bool bdraw_arrow, int hilite_width);


};






#endif
    // __DLE_DOCH__

