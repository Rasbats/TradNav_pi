///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/choice.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/menu.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class TradNavUIDialogBase
///////////////////////////////////////////////////////////////////////////////
class TradNavUIDialogBase : public wxFrame
{
	private:

	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panelExtensions;
		wxTextCtrl* m_textCtrl8;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText12;
		wxButton* m_buttonAttach;
		wxButton* m_buttonAttach1;
		wxStaticText* m_staticText13;
		wxButton* m_buttonAttach21;
		wxButton* m_buttonAttach22;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText101;
		wxPanel* m_panelIdentify;
		wxTextCtrl* m_textCtrl81;
		wxStaticText* m_staticText151;
		wxStaticText* m_staticText61;
		wxStaticText* m_staticText71;
		wxButton* m_bButtonBearing11;
		wxButton* m_button81;
		wxMenu* m_mHelp;
		wxMenu* m_mRoutes;
		wxMenu* m_mExtensions;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void key_shortcut( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnBearingLine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRangeCircle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBearingLineDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRangeCircleDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEBL( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEBL_off( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInformation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNewRoute( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveRoute( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoadRoute( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImportRoute( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteRoute( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveExtensions( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:
		wxChoice* m_choiceFirstNum;
		wxChoice* m_choiceSecondNum;
		wxChoice* m_choiceThirdNum;
		wxTextCtrl* m_range;
		wxChoice* m_choiceFirstNum1;
		wxChoice* m_choiceSecondNum1;
		wxChoice* m_choiceThirdNum1;
		wxTextCtrl* m_Lat1;
		wxTextCtrl* m_Lon1;
		wxMenuBar* m_menubar3;
		wxTimer m_timer1;

		TradNavUIDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("finSAR_edit"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 377,839 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~TradNavUIDialogBase();

};

