///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/checkbox.h>
#include <wx/timer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class m_Dialog
///////////////////////////////////////////////////////////////////////////////
class m_Dialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText1511;
		wxStaticText* m_staticText32111112;
		wxStaticText* m_staticText33111111;
		wxStaticText* m_staticText32111111;
		wxStaticText* m_staticText3311111;
		wxStaticText* m_staticText72;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_textCtrlHorizontal;
		wxStaticLine* m_staticline1;
		wxButton* m_button3111;
		wxStaticText* m_staticText71;
		wxButton* m_buttonDraw;
		wxButton* m_buttonHorizontal;
		wxButton* m_buttonDraw1;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void text_shortcut( wxCommandEvent& event ) { event.Skip(); }
		virtual void key_shortcut( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnCursorSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCharHook( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnRangeCursorSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHorizontalSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:
		wxTextCtrl* m_Speed_PS;
		wxChoice* m_Nship;
		wxTextCtrl* m_textCtrlRange;
		wxTextCtrl* m_Bearing;
		wxCheckBox* m_checkBoxAdd;
		wxCheckBox* m_checkBoxAddEBL;
		wxTextCtrl* m_textCtrlLat;
		wxTextCtrl* m_textCtrlLon;
		wxTimer myTimer;

		m_Dialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("DR"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 378,536 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~m_Dialog();

};

