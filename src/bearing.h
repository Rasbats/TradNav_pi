#ifndef __E_DOCH__
#define __E_DOCH__

#include "pidc.h"
#include "wx/cmdproc.h"
#include "wx/docview.h"

class piDC;


#include <wx\object.h>

class bearingLine : public wxObject {
public:
    bearingLine(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)
    {
        m_x1 = x1;
        m_y1 = y1;
        m_x2 = x2;
        m_y2 = y2;
    }

    double m_x1;
    double m_y1;
    double m_x2;
    double m_y2;

    void AddPoint(bearingLine* bp);

};

class bearingPoint : public wxObject {
public:
    bearingPoint(double x1 = 0, double y1 = 0)
    {
        m_x1 = x1;
        m_y1 = y1;
    }
    double m_x1;
    double m_y1;
    
};

class bearing : public wxObject { 
  public:
    bearing();
    virtual ~bearing();
    bearingLine m_bearingLine;
    bearingPoint* m_bearingBegin;
    bearingPoint* m_bearingEnd;
    void RenderBearing(piDC& dc, double lata, double lona, double latb,
        double lonb, PlugIn_ViewPort& VP, bool bdraw_arrow, int hilite_width);

    unsigned int m_iDisplayTextTexture;
    int m_iDisplayTextTextureWidth, m_iDisplayTextTextureHeight;

};

WX_DECLARE_LIST(bearing, bearingList); // establish class DR list member

#endif