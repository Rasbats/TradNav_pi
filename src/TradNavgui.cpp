///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TradNavgui.h"

///////////////////////////////////////////////////////////////////////////

m_Dialog::m_Dialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9111;
	bSizer9111 = new wxBoxSizer( wxVERTICAL );

	m_staticText1511 = new wxStaticText( this, wxID_ANY, wxT("DR Options"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1511->Wrap( -1 );
	m_staticText1511->SetFont( wxFont( 20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer9111->Add( m_staticText1511, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	wxBoxSizer* bSizer1311;
	bSizer1311 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14111112;
	bSizer14111112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32111112 = new wxStaticText( this, wxID_ANY, wxT("Planned         \nSpeed           "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32111112->Wrap( -1 );
	bSizer14111112->Add( m_staticText32111112, 0, wxALL, 5 );

	m_Speed_PS = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14111112->Add( m_Speed_PS, 0, wxALL, 5 );

	m_staticText33111111 = new wxStaticText( this, wxID_ANY, wxT("kts"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33111111->Wrap( -1 );
	bSizer14111112->Add( m_staticText33111111, 0, wxALL, 5 );


	bSizer1311->Add( bSizer14111112, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14111111;
	bSizer14111111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32111111 = new wxStaticText( this, wxID_ANY, wxT("Interval            "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32111111->Wrap( -1 );
	bSizer14111111->Add( m_staticText32111111, 0, wxALL, 5 );

	m_toggleRange = new wxToggleButton( this, wxID_ANY, wxT("Range"), wxDefaultPosition, wxDefaultSize, 0 );
	m_toggleRange->SetValue( true );
	bSizer14111111->Add( m_toggleRange, 0, wxALL, 5 );


	bSizer1311->Add( bSizer14111111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText72 = new wxStaticText( this, wxID_ANY, wxT("Range :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText72->Wrap( -1 );
	bSizer141->Add( m_staticText72, 0, wxALL, 5 );

	m_textCtrlRange = new wxTextCtrl( this, wxID_ANY, wxT("10.0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer141->Add( m_textCtrlRange, 0, wxALL, 5 );


	bSizer1311->Add( bSizer141, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_sliderRange = new wxSlider( this, wxID_ANY, 0, 0, 30, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer9->Add( m_sliderRange, 0, wxALL|wxEXPAND, 5 );


	bSizer1311->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Bearing :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer14->Add( m_staticText7, 0, wxALL, 5 );

	m_Bearing = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_Bearing, 0, wxALL, 5 );


	bSizer1311->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Horizontal angle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer10->Add( m_staticText10, 0, wxALL, 5 );

	m_textCtrlHorizontal = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_textCtrlHorizontal, 0, wxALL, 5 );


	bSizer1311->Add( bSizer10, 1, wxEXPAND, 5 );


	bSizer9111->Add( bSizer1311, 1, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer9111->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	m_button3111 = new wxButton( this, wxID_ANY, wxT("Draw Bearings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer71->Add( m_button3111, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );


	bSizer9111->Add( bSizer71, 0, wxEXPAND, 5 );

	m_toggleBtn2 = new wxToggleButton( this, wxID_ANY, wxT("Start Drawing Bearings"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_toggleBtn2, 0, wxALL, 5 );

	m_checkBoxBearing = new wxCheckBox( this, wxID_ANY, wxT("Add Bearing"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxBearing->SetValue(true);
	bSizer9111->Add( m_checkBoxBearing, 0, wxALL, 5 );

	m_checkBoxAdd = new wxCheckBox( this, wxID_ANY, wxT("Add Waypoint"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_checkBoxAdd, 0, wxALL, 5 );

	m_checkBoxAddEBL = new wxCheckBox( this, wxID_ANY, wxT("Add EBL"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_checkBoxAddEBL, 0, wxALL, 5 );

	m_buttonDraw = new wxButton( this, wxID_ANY, wxT("Draw Ranges"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_buttonDraw, 0, wxALL|wxEXPAND, 5 );

	m_buttonHorizontal = new wxButton( this, wxID_ANY, wxT("Draw Horizontal"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_buttonHorizontal, 0, wxALL|wxEXPAND, 5 );

	m_buttonDrawHorizontal = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_buttonDrawHorizontal, 0, wxALL, 5 );

	m_buttonDraw1 = new wxButton( this, wxID_ANY, wxT("StopTimer"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9111->Add( m_buttonDraw1, 0, wxALL|wxEXPAND, 5 );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 3, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_textCtrlLat = new wxTextCtrl( this, wxID_ANY, wxT("50.0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_textCtrlLat, 0, wxALL, 5 );

	m_textCtrlLon = new wxTextCtrl( this, wxID_ANY, wxT("-4.0"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer1->Add( m_textCtrlLon, 0, wxALL, 5 );


	bSizer9111->Add( fgSizer1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer9111 );
	this->Layout();
	myTimer.SetOwner( this, myTimer.GetId() );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( m_Dialog::OnClose ) );
	m_toggleRange->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnToggleRange ), NULL, this );
	m_textCtrlRange->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( m_Dialog::text_shortcut ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_Bearing->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	m_textCtrlHorizontal->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	m_button3111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnCursorSelect ), NULL, this );
	m_button3111->Connect( wxEVT_CHAR_HOOK, wxKeyEventHandler( m_Dialog::OnCharHook ), NULL, this );
	m_buttonDraw->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnRangeCursorSelect ), NULL, this );
	m_buttonHorizontal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnHorizontalSelect ), NULL, this );
	m_buttonDrawHorizontal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnDrawHorizontal ), NULL, this );
	m_buttonDraw1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStop ), NULL, this );
	m_textCtrlLat->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	m_textCtrlLon->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	this->Connect( myTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimer ) );
}

m_Dialog::~m_Dialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( m_Dialog::OnClose ) );
	m_toggleRange->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnToggleRange ), NULL, this );
	m_textCtrlRange->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( m_Dialog::text_shortcut ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_sliderRange->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( m_Dialog::OnScroll ), NULL, this );
	m_Bearing->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	m_textCtrlHorizontal->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	m_button3111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnCursorSelect ), NULL, this );
	m_button3111->Disconnect( wxEVT_CHAR_HOOK, wxKeyEventHandler( m_Dialog::OnCharHook ), NULL, this );
	m_buttonDraw->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnRangeCursorSelect ), NULL, this );
	m_buttonHorizontal->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnHorizontalSelect ), NULL, this );
	m_buttonDrawHorizontal->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnDrawHorizontal ), NULL, this );
	m_buttonDraw1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( m_Dialog::OnStop ), NULL, this );
	m_textCtrlLat->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	m_textCtrlLon->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( m_Dialog::key_shortcut ), NULL, this );
	this->Disconnect( myTimer.GetId(), wxEVT_TIMER, wxTimerEventHandler( m_Dialog::OnTimer ) );

}
