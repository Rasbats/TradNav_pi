#ifndef __PATH_H__
#define __PATH_H__

#include <wx/list.h>
#include <wx/object.h>
#include <list>
#include <wx/hashmap.h>

class tdPath : public wxObject {

public:
    tdPath(void);   
    ~tdPath(void);

    wxString m_sTypeString;

    private:

};

WX_DECLARE_LIST(tdPath, PathList); // establish class Path as list member

#endif
