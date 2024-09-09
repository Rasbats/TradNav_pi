///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TradNavUIDialogBase.h"

///////////////////////////////////////////////////////////////////////////

TradNavUIDialogBase::TradNavUIDialogBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_notebook1->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	m_notebook1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	m_panelRangeBearing = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelRangeBearing->SetBackgroundColour( wxColour( 139, 197, 197 ) );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl8 = new wxTextCtrl( m_panelRangeBearing, wxID_ANY, _("Range and Bearing"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	m_textCtrl8->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_textCtrl8->SetBackgroundColour( wxColour( 75, 126, 211 ) );

	bSizer25->Add( m_textCtrl8, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );


	bSizer25->Add( bSizer81, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText15 = new wxStaticText( m_panelRangeBearing, wxID_ANY, _("  Mag. Bearing    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	fgSizer4->Add( m_staticText15, 0, wxALL, 5 );

	wxString m_choiceFirstNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceFirstNumNChoices = sizeof( m_choiceFirstNumChoices ) / sizeof( wxString );
	m_choiceFirstNum = new wxChoice( m_panelRangeBearing, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFirstNumNChoices, m_choiceFirstNumChoices, 0 );
	m_choiceFirstNum->SetSelection( 0 );
	fgSizer4->Add( m_choiceFirstNum, 0, wxALIGN_RIGHT|wxALL, 5 );

	wxString m_choiceSecondNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceSecondNumNChoices = sizeof( m_choiceSecondNumChoices ) / sizeof( wxString );
	m_choiceSecondNum = new wxChoice( m_panelRangeBearing, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSecondNumNChoices, m_choiceSecondNumChoices, 0 );
	m_choiceSecondNum->SetSelection( 0 );
	fgSizer4->Add( m_choiceSecondNum, 0, wxALL, 5 );

	wxString m_choiceThirdNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceThirdNumNChoices = sizeof( m_choiceThirdNumChoices ) / sizeof( wxString );
	m_choiceThirdNum = new wxChoice( m_panelRangeBearing, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceThirdNumNChoices, m_choiceThirdNumChoices, 0 );
	m_choiceThirdNum->SetSelection( 0 );
	fgSizer4->Add( m_choiceThirdNum, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer5->Add( fgSizer4, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText101 = new wxStaticText( m_panelRangeBearing, wxID_ANY, _("  Target Range   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	fgSizer5->Add( m_staticText101, 0, wxALL, 5 );

	m_range = new wxSpinCtrlDouble( m_panelRangeBearing, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_range->SetDigits( 1 );
	fgSizer5->Add( m_range, 0, wxALL, 5 );


	bSizer5->Add( fgSizer5, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText11 = new wxStaticText( m_panelRangeBearing, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer2->Add( m_staticText11, 0, wxALL, 5 );

	m_staticText41 = new wxStaticText( m_panelRangeBearing, wxID_ANY, _("Range"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	fgSizer2->Add( m_staticText41, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText4 = new wxStaticText( m_panelRangeBearing, wxID_ANY, _("Bearing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer2->Add( m_staticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText12 = new wxStaticText( m_panelRangeBearing, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	fgSizer2->Add( m_staticText12, 0, wxALL, 5 );

	m_buttonAttach1 = new wxButton( m_panelRangeBearing, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach1->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_buttonAttach = new wxButton( m_panelRangeBearing, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText13 = new wxStaticText( m_panelRangeBearing, wxID_ANY, _("               "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	fgSizer2->Add( m_staticText13, 0, wxALL, 5 );

	m_buttonAttach22 = new wxButton( m_panelRangeBearing, wxID_ANY, _("Del"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach22->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach22, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_buttonAttach21 = new wxButton( m_panelRangeBearing, wxID_ANY, _("Del"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonAttach21->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	fgSizer2->Add( m_buttonAttach21, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer5->Add( fgSizer2, 0, wxEXPAND, 5 );


	bSizer1->Add( bSizer5, 0, wxEXPAND, 5 );


	bSizer25->Add( bSizer1, 0, wxEXPAND, 5 );


	bSizer71->Add( bSizer25, 0, wxEXPAND, 5 );


	m_panelRangeBearing->SetSizer( bSizer71 );
	m_panelRangeBearing->Layout();
	bSizer71->Fit( m_panelRangeBearing );
	m_notebook1->AddPage( m_panelRangeBearing, _("     Range and Bearing  "), true );
	m_panelIdentify = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelIdentify->SetBackgroundColour( wxColour( 45, 232, 105 ) );

	wxBoxSizer* bSizer711;
	bSizer711 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl81 = new wxTextCtrl( m_panelIdentify, wxID_ANY, _("Identify"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	m_textCtrl81->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	m_textCtrl81->SetBackgroundColour( wxColour( 223, 227, 60 ) );

	bSizer251->Add( m_textCtrl81, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer811;
	bSizer811 = new wxBoxSizer( wxVERTICAL );


	bSizer251->Add( bSizer811, 1, wxEXPAND, 5 );


	bSizer711->Add( bSizer251, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer41;
	fgSizer41 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer41->SetFlexibleDirection( wxBOTH );
	fgSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText151 = new wxStaticText( m_panelIdentify, wxID_ANY, _("  Mag.  Bearing   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	fgSizer41->Add( m_staticText151, 0, wxALL, 5 );

	wxString m_choiceFirstNum1Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceFirstNum1NChoices = sizeof( m_choiceFirstNum1Choices ) / sizeof( wxString );
	m_choiceFirstNum1 = new wxChoice( m_panelIdentify, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFirstNum1NChoices, m_choiceFirstNum1Choices, 0 );
	m_choiceFirstNum1->SetSelection( 0 );
	fgSizer41->Add( m_choiceFirstNum1, 0, wxALIGN_RIGHT|wxALL, 5 );

	wxString m_choiceSecondNum1Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceSecondNum1NChoices = sizeof( m_choiceSecondNum1Choices ) / sizeof( wxString );
	m_choiceSecondNum1 = new wxChoice( m_panelIdentify, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSecondNum1NChoices, m_choiceSecondNum1Choices, 0 );
	m_choiceSecondNum1->SetSelection( 0 );
	fgSizer41->Add( m_choiceSecondNum1, 0, wxALL, 5 );

	wxString m_choiceThirdNum1Choices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceThirdNum1NChoices = sizeof( m_choiceThirdNum1Choices ) / sizeof( wxString );
	m_choiceThirdNum1 = new wxChoice( m_panelIdentify, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceThirdNum1NChoices, m_choiceThirdNum1Choices, 0 );
	m_choiceThirdNum1->SetSelection( 0 );
	fgSizer41->Add( m_choiceThirdNum1, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer51->Add( fgSizer41, 1, wxEXPAND, 5 );


	bSizer12->Add( bSizer51, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxVERTICAL );

	m_bButtonBearing11 = new wxButton( m_panelIdentify, wxID_ANY, _("Plot Mag. bearing from ship "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer111->Add( m_bButtonBearing11, 0, wxALL, 5 );

	m_button81 = new wxButton( m_panelIdentify, wxID_ANY, _("Switch off plot"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer111->Add( m_button81, 0, wxALL, 5 );


	bSizer12->Add( bSizer111, 0, wxEXPAND, 5 );


	bSizer711->Add( bSizer12, 0, wxEXPAND, 5 );


	m_panelIdentify->SetSizer( bSizer711 );
	m_panelIdentify->Layout();
	bSizer711->Fit( m_panelIdentify );
	m_notebook1->AddPage( m_panelIdentify, _("Identify"), false );
	m_panelEBL = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_bButtonBearing1 = new wxButton( m_panelEBL, wxID_ANY, _("EBL On"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_bButtonBearing1, 0, wxALL, 5 );

	m_button8 = new wxButton( m_panelEBL, wxID_ANY, _("EBL Off"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_button8, 0, wxALL, 5 );


	bSizer14->Add( bSizer11, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( m_panelEBL, wxID_ANY, _("   Bearing:    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer17->Add( m_staticText16, 0, wxALL, 5 );

	m_EBLbearing = new wxTextCtrl( m_panelEBL, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_EBLbearing, 0, wxALL, 5 );


	bSizer14->Add( bSizer17, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer311;
	fgSizer311 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer311->SetFlexibleDirection( wxBOTH );
	fgSizer311->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText611 = new wxStaticText( m_panelEBL, wxID_ANY, _("Cross hairs Latitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText611->Wrap( -1 );
	fgSizer311->Add( m_staticText611, 0, wxALL, 5 );

	m_Lat1 = new wxTextCtrl( m_panelEBL, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer311->Add( m_Lat1, 0, wxALL, 5 );

	m_staticText711 = new wxStaticText( m_panelEBL, wxID_ANY, _("Cross hairs Longitude"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText711->Wrap( -1 );
	fgSizer311->Add( m_staticText711, 0, wxALL, 5 );

	m_Lon1 = new wxTextCtrl( m_panelEBL, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer311->Add( m_Lon1, 0, wxALL, 5 );


	bSizer14->Add( fgSizer311, 0, wxEXPAND, 5 );


	m_panelEBL->SetSizer( bSizer14 );
	m_panelEBL->Layout();
	bSizer14->Fit( m_panelEBL );
	m_notebook1->AddPage( m_panelEBL, _("EBL"), false );
	m_panelRunningFix = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelRunningFix->SetBackgroundColour( wxColour( 192, 192, 192 ) );

	wxBoxSizer* bSizer712;
	bSizer712 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer252;
	bSizer252 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl82 = new wxTextCtrl( m_panelRunningFix, wxID_ANY, _("Running Fix"), wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	m_textCtrl82->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	m_textCtrl82->SetBackgroundColour( wxColour( 255, 128, 0 ) );

	bSizer252->Add( m_textCtrl82, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer812;
	bSizer812 = new wxBoxSizer( wxVERTICAL );


	bSizer252->Add( bSizer812, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer421;
	fgSizer421 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer421->SetFlexibleDirection( wxBOTH );
	fgSizer421->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1521 = new wxStaticText( m_panelRunningFix, wxID_ANY, _("  First Bearing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1521->Wrap( -1 );
	fgSizer421->Add( m_staticText1521, 0, wxALL, 5 );

	wxString m_choiceRFfirstNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceRFfirstNumNChoices = sizeof( m_choiceRFfirstNumChoices ) / sizeof( wxString );
	m_choiceRFfirstNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRFfirstNumNChoices, m_choiceRFfirstNumChoices, 0 );
	m_choiceRFfirstNum->SetSelection( 0 );
	fgSizer421->Add( m_choiceRFfirstNum, 0, wxALIGN_RIGHT|wxALL, 5 );

	wxString m_choiceRFsecondNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceRFsecondNumNChoices = sizeof( m_choiceRFsecondNumChoices ) / sizeof( wxString );
	m_choiceRFsecondNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRFsecondNumNChoices, m_choiceRFsecondNumChoices, 0 );
	m_choiceRFsecondNum->SetSelection( 0 );
	fgSizer421->Add( m_choiceRFsecondNum, 0, wxALL, 5 );

	wxString m_choiceRFthirdNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceRFthirdNumNChoices = sizeof( m_choiceRFthirdNumChoices ) / sizeof( wxString );
	m_choiceRFthirdNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceRFthirdNumNChoices, m_choiceRFthirdNumChoices, 0 );
	m_choiceRFthirdNum->SetSelection( 0 );
	fgSizer421->Add( m_choiceRFthirdNum, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer52->Add( fgSizer421, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer42;
	fgSizer42 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer42->SetFlexibleDirection( wxBOTH );
	fgSizer42->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText152 = new wxStaticText( m_panelRunningFix, wxID_ANY, _("  Course"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText152->Wrap( -1 );
	fgSizer42->Add( m_staticText152, 0, wxALL, 5 );

	wxString m_choiceCourseFirstNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceCourseFirstNumNChoices = sizeof( m_choiceCourseFirstNumChoices ) / sizeof( wxString );
	m_choiceCourseFirstNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCourseFirstNumNChoices, m_choiceCourseFirstNumChoices, 0 );
	m_choiceCourseFirstNum->SetSelection( 0 );
	fgSizer42->Add( m_choiceCourseFirstNum, 0, wxALIGN_RIGHT|wxALL, 5 );

	wxString m_choiceCourseSecondNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceCourseSecondNumNChoices = sizeof( m_choiceCourseSecondNumChoices ) / sizeof( wxString );
	m_choiceCourseSecondNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCourseSecondNumNChoices, m_choiceCourseSecondNumChoices, 0 );
	m_choiceCourseSecondNum->SetSelection( 0 );
	fgSizer42->Add( m_choiceCourseSecondNum, 0, wxALL, 5 );

	wxString m_choiceCourseThirdNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceCourseThirdNumNChoices = sizeof( m_choiceCourseThirdNumChoices ) / sizeof( wxString );
	m_choiceCourseThirdNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCourseThirdNumNChoices, m_choiceCourseThirdNumChoices, 0 );
	m_choiceCourseThirdNum->SetSelection( 0 );
	fgSizer42->Add( m_choiceCourseThirdNum, 0, wxALIGN_LEFT|wxALL, 5 );


	bSizer52->Add( fgSizer42, 0, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1011 = new wxStaticText( m_panelRunningFix, wxID_ANY, _("  Speed (Kts)   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1011->Wrap( -1 );
	fgSizer51->Add( m_staticText1011, 0, wxALL, 5 );

	m_speed = new wxSpinCtrlDouble( m_panelRunningFix, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0.000000, 1 );
	m_speed->SetDigits( 1 );
	fgSizer51->Add( m_speed, 0, wxALL, 5 );


	bSizer52->Add( fgSizer51, 1, wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1522 = new wxStaticText( m_panelRunningFix, wxID_ANY, _("  Minutes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1522->Wrap( -1 );
	fgSizer21->Add( m_staticText1522, 0, wxALL, 5 );

	wxString m_choiceMinutesFirstNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceMinutesFirstNumNChoices = sizeof( m_choiceMinutesFirstNumChoices ) / sizeof( wxString );
	m_choiceMinutesFirstNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceMinutesFirstNumNChoices, m_choiceMinutesFirstNumChoices, 0 );
	m_choiceMinutesFirstNum->SetSelection( 0 );
	fgSizer21->Add( m_choiceMinutesFirstNum, 0, wxALL, 5 );

	wxString m_choiceMinutesSecondNumChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choiceMinutesSecondNumNChoices = sizeof( m_choiceMinutesSecondNumChoices ) / sizeof( wxString );
	m_choiceMinutesSecondNum = new wxChoice( m_panelRunningFix, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceMinutesSecondNumNChoices, m_choiceMinutesSecondNumChoices, 0 );
	m_choiceMinutesSecondNum->SetSelection( 0 );
	fgSizer21->Add( m_choiceMinutesSecondNum, 0, wxALL, 5 );


	bSizer52->Add( fgSizer21, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );

	m_button27 = new wxButton( m_panelRunningFix, wxID_ANY, _("Plot transferred position line"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button27->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	bSizer28->Add( m_button27, 0, wxALL, 5 );


	bSizer52->Add( bSizer28, 0, wxEXPAND, 5 );


	bSizer13->Add( bSizer52, 0, wxEXPAND, 5 );


	bSizer252->Add( bSizer13, 0, wxEXPAND, 5 );


	bSizer712->Add( bSizer252, 0, wxEXPAND, 5 );


	m_panelRunningFix->SetSizer( bSizer712 );
	m_panelRunningFix->Layout();
	bSizer712->Fit( m_panelRunningFix );
	m_notebook1->AddPage( m_panelRunningFix, _("Running Fix"), false );

	bSizer3->Add( m_notebook1, 0, wxEXPAND | wxALL, 5 );


	fgSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( fgSizer1 );
	this->Layout();
	m_menubar3 = new wxMenuBar( 0 );
	m_mHelp = new wxMenu();
	wxMenuItem* m_mInformation;
	m_mInformation = new wxMenuItem( m_mHelp, wxID_ANY, wxString( _("Guide") ) , wxEmptyString, wxITEM_NORMAL );
	m_mHelp->Append( m_mInformation );

	wxMenuItem* m_mAbout;
	m_mAbout = new wxMenuItem( m_mHelp, wxID_ANY, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_mHelp->Append( m_mAbout );

	m_menubar3->Append( m_mHelp, _("Help") );

	this->SetMenuBar( m_menubar3 );

	m_timer1.SetOwner( this, m_timer1.GetId() );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TradNavUIDialogBase::OnClose ) );
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( TradNavUIDialogBase::OnSize ) );
	m_panelRangeBearing->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ), NULL, this );
	m_buttonAttach1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnRangeCircle ), NULL, this );
	m_buttonAttach->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnBearingLine ), NULL, this );
	m_buttonAttach22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnRangeCircleDelete ), NULL, this );
	m_buttonAttach21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnBearingLineDelete ), NULL, this );
	m_panelIdentify->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ), NULL, this );
	m_bButtonBearing11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonIdentify ), NULL, this );
	m_button81->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonIdentify_off ), NULL, this );
	m_bButtonBearing1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonEBL ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonEBL_off ), NULL, this );
	m_panelRunningFix->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ), NULL, this );
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnPlotRunningFix ), NULL, this );
	m_mHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( TradNavUIDialogBase::OnInformation ), this, m_mInformation->GetId());
	m_mHelp->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( TradNavUIDialogBase::OnAbout ), this, m_mAbout->GetId());
	this->Connect( m_timer1.GetId(), wxEVT_TIMER, wxTimerEventHandler( TradNavUIDialogBase::OnTimer ) );
}

TradNavUIDialogBase::~TradNavUIDialogBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( TradNavUIDialogBase::OnClose ) );
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( TradNavUIDialogBase::OnSize ) );
	m_panelRangeBearing->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ), NULL, this );
	m_buttonAttach1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnRangeCircle ), NULL, this );
	m_buttonAttach->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnBearingLine ), NULL, this );
	m_buttonAttach22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnRangeCircleDelete ), NULL, this );
	m_buttonAttach21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnBearingLineDelete ), NULL, this );
	m_panelIdentify->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ), NULL, this );
	m_bButtonBearing11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonIdentify ), NULL, this );
	m_button81->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonIdentify_off ), NULL, this );
	m_bButtonBearing1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonEBL ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnButtonEBL_off ), NULL, this );
	m_panelRunningFix->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( TradNavUIDialogBase::key_shortcut ), NULL, this );
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( TradNavUIDialogBase::OnPlotRunningFix ), NULL, this );
	this->Disconnect( m_timer1.GetId(), wxEVT_TIMER, wxTimerEventHandler( TradNavUIDialogBase::OnTimer ) );

}
