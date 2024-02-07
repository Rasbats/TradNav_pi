/////////////////////////////////////////////////////////////////////////////
// Name:        doc.h
// Purpose:     Document classes for Doodle sample
// Author:      Julian Smart
// Modified by:
// Created:     2004-12-07
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __DOODLE_DOCH__
#define __DOODLE_DOCH__

#include "wx/docview.h"
#include "wx/cmdproc.h"
#include "pidc.h"
#include "tdPath.h"

class piDC;
/*
 * Defines a line from one point to the other
 */

class DoodleSegment: public tdPath
{
public:
    DoodleSegment();    
    virtual ~DoodleSegment();

    void Draw();

    /// Saves the segment
    std::ostream& SaveObject(std::ostream& stream);

    /// Loads the segment
    wxInputStream& LoadObject(wxInputStream& stream);

    /// Gets the lines
    wxList& GetLines() { return m_lines; }
    const wxList& GetLines() const { return m_lines; }
    void DrawSegment(piDC& dc, wxPoint* rp1, wxPoint* rp2,
        PlugIn_ViewPort& VP, bool bdraw_arrow);
    void RenderSegment(piDC& dc, int xa, int ya, int xb, int yb,
        PlugIn_ViewPort& VP, bool bdraw_arrow, int hilite_width);

private:
    wxList m_lines;
};

/*
 * Represents a doodle document
 */
class DoodleLine : public wxObject {
public:
    DoodleLine(wxInt32 x1 = 0, wxInt32 y1 = 0, wxInt32 x2 = 0, wxInt32 y2 = 0)
    {
        m_x1 = x1;
        m_y1 = y1;
        m_x2 = x2;
        m_y2 = y2;
    }

    wxInt32 m_x1;
    wxInt32 m_y1;
    wxInt32 m_x2;
    wxInt32 m_y2;
};


#endif
    // __DOODLE_DOCH__

