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
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
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
		wxPanel* m_panelRangeBearing;
		wxTextCtrl* m_textCtrl8;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText101;
		wxSpinCtrlDouble* m_range;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText12;
		wxButton* m_buttonAttach1;
		wxButton* m_buttonAttach;
		wxStaticText* m_staticText13;
		wxButton* m_buttonAttach22;
		wxButton* m_buttonAttach21;
		wxPanel* m_panelIdentify;
		wxTextCtrl* m_textCtrl81;
		wxStaticText* m_staticText151;
		wxButton* m_bButtonBearing11;
		wxButton* m_button81;
		wxPanel* m_panelEBL;
		wxButton* m_bButtonBearing1;
		wxButton* m_button8;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText611;
		wxStaticText* m_staticText711;
		wxPanel* m_panelRunningFix;
		wxTextCtrl* m_textCtrl82;
		wxStaticText* m_staticText1521;
		wxStaticText* m_staticText152;
		wxStaticText* m_staticText1011;
		wxSpinCtrlDouble* m_speed;
		wxStaticText* m_staticText1522;
		wxButton* m_button27;
		wxMenu* m_mHelp;

		// Virtual event handlers, override them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void key_shortcut( wxKeyEvent& event ) { event.Skip(); }
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnRangeCircle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBearingLine( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRangeCircleDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBearingLineDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonIdentify( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonIdentify_off( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEBL( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonEBL_off( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlotRunningFix( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInformation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:
		wxChoice* m_choiceFirstNum;
		wxChoice* m_choiceSecondNum;
		wxChoice* m_choiceThirdNum;
		wxChoice* m_choiceFirstNum1;
		wxChoice* m_choiceSecondNum1;
		wxChoice* m_choiceThirdNum1;
		wxTextCtrl* m_EBLbearing;
		wxTextCtrl* m_Lat1;
		wxTextCtrl* m_Lon1;
		wxChoice* m_choiceRFfirstNum;
		wxChoice* m_choiceRFsecondNum;
		wxChoice* m_choiceRFthirdNum;
		wxChoice* m_choiceCourseFirstNum;
		wxChoice* m_choiceCourseSecondNum;
		wxChoice* m_choiceCourseThirdNum;
		wxChoice* m_choiceMinutesFirstNum;
		wxChoice* m_choiceMinutesSecondNum;
		wxMenuBar* m_menubar3;
		wxTimer m_timer1;

		TradNavUIDialogBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("TradNav"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 377,839 ), long style = wxCAPTION|wxCLOSE_BOX|wxFRAME_FLOAT_ON_PARENT|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

		~TradNavUIDialogBase();

};

