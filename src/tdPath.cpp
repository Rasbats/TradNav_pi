#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif // precompiled headers

#include "TradNav_pi.h"
#include "tdPath.h"

#include <wx/listimpl.cpp>
WX_DEFINE_LIST(PathList);

tdPath::tdPath(void) { 
  
   m_sTypeString = wxS("Path"); 

}

tdPath::~tdPath(void) {


}