///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrame, wxFrame )
	EVT_BUTTON( wxID_ANY, MainFrame::_wxFB_OnRefreshBtn )
	EVT_MENU( ID_SAVE, MainFrame::_wxFB_OnSave )
	EVT_MENU( ID_OPEN, MainFrame::_wxFB_OnOpen )
	EVT_MENU( ID_EXPORT, MainFrame::_wxFB_OnExport )
	EVT_MENU( ID_SETTINGS, MainFrame::_wxFB_OnOpenSettings )
END_EVENT_TABLE()

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter1OnIdle ), NULL, this );

	EntryPanel = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	EntrySizer = new wxBoxSizer( wxVERTICAL );


	EntryPanel->SetSizer( EntrySizer );
	EntryPanel->Layout();
	EntrySizer->Fit( EntryPanel );
	DisplayPanel = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	DisplaySizer = new wxBoxSizer( wxVERTICAL );


	DisplayPanel->SetSizer( DisplaySizer );
	DisplayPanel->Layout();
	DisplaySizer->Fit( DisplayPanel );
	m_splitter1->SplitVertically( EntryPanel, DisplayPanel, 0 );
	bSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_button2 = new wxButton( m_toolBar1, wxID_ANY, wxT("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	m_toolBar1->AddControl( m_button2 );
	m_toolBar1->Realize();

	StatusBar = this->CreateStatusBar( 1, 0, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	FileMenu = new wxMenu();
	wxMenuItem* SaveMenu;
	SaveMenu = new wxMenuItem( FileMenu, ID_SAVE, wxString( wxT("Save") ) + wxT('\t') + wxT("Ctrl-S"), wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( SaveMenu );

	wxMenuItem* OpenMenu;
	OpenMenu = new wxMenuItem( FileMenu, ID_OPEN, wxString( wxT("Open") ) + wxT('\t') + wxT("Ctrl-O"), wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( OpenMenu );

	wxMenuItem* ExportBtn;
	ExportBtn = new wxMenuItem( FileMenu, ID_EXPORT, wxString( wxT("Export") ) + wxT('\t') + wxT("Ctrl-E"), wxEmptyString, wxITEM_NORMAL );
	FileMenu->Append( ExportBtn );

	m_menubar1->Append( FileMenu, wxT("File") );

	EditMenu = new wxMenu();
	wxMenuItem* SettingsBtn;
	SettingsBtn = new wxMenuItem( EditMenu, ID_SETTINGS, wxString( wxT("Settings") ) , wxEmptyString, wxITEM_NORMAL );
	EditMenu->Append( SettingsBtn );

	m_menubar1->Append( EditMenu, wxT("Edit") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}

SettingsDlg::SettingsDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	bSizer4->SetMinSize( wxSize( 800,500 ) );
	SettingsNotebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	EditorPanel = new wxPanel( SettingsNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	LineWrapCheck = new wxCheckBox( EditorPanel, wxID_ANY, wxT("Line Wrapping"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( LineWrapCheck, 0, wxALL, 5 );


	bSizer17->Add( bSizer18, 1, wxEXPAND, 5 );


	EditorPanel->SetSizer( bSizer17 );
	EditorPanel->Layout();
	bSizer17->Fit( EditorPanel );
	SettingsNotebook->AddPage( EditorPanel, wxT("Editor"), false );
	DisplayPanel = new wxPanel( SettingsNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( DisplayPanel, wxID_ANY, wxT("CSS Theme"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer6->Add( m_staticText1, 0, wxALL, 5 );

	wxArrayString CssComboChoices;
	CssCombo = new wxChoice( DisplayPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, CssComboChoices, 0 );
	CssCombo->SetSelection( 0 );
	bSizer6->Add( CssCombo, 0, wxALL, 5 );


	bSizer5->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( DisplayPanel, wxID_ANY, wxT("Code Block Theme"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer61->Add( m_staticText11, 0, wxALL, 5 );

	wxArrayString CodeThemeComboChoices;
	CodeThemeCombo = new wxChoice( DisplayPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, CodeThemeComboChoices, 0 );
	CodeThemeCombo->SetSelection( 0 );
	bSizer61->Add( CodeThemeCombo, 0, wxALL, 5 );


	bSizer5->Add( bSizer61, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( DisplayPanel, wxID_ANY, wxT("Maths Interpreter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer62->Add( m_staticText12, 0, wxALL, 5 );

	wxString MathsBackendComboChoices[] = { wxT("None"), wxT("Katex"), wxT("MathJax") };
	int MathsBackendComboNChoices = sizeof( MathsBackendComboChoices ) / sizeof( wxString );
	MathsBackendCombo = new wxChoice( DisplayPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, MathsBackendComboNChoices, MathsBackendComboChoices, 0 );
	MathsBackendCombo->SetSelection( 0 );
	bSizer62->Add( MathsBackendCombo, 0, wxALL, 5 );


	bSizer5->Add( bSizer62, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	MermaidCheck = new wxCheckBox( DisplayPanel, wxID_ANY, wxT("Use Mermaid"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( MermaidCheck, 0, wxALL, 5 );


	bSizer5->Add( bSizer12, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	CharterCheck = new wxCheckBox( DisplayPanel, wxID_ANY, wxT("Use Charter"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( CharterCheck, 0, wxALL, 5 );


	bSizer5->Add( bSizer13, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	HighlightCheck = new wxCheckBox( DisplayPanel, wxID_ANY, wxT("Do Code Highlighting"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( HighlightCheck, 0, wxALL, 5 );


	bSizer5->Add( bSizer16, 1, wxEXPAND, 5 );


	DisplayPanel->SetSizer( bSizer5 );
	DisplayPanel->Layout();
	bSizer5->Fit( DisplayPanel );
	SettingsNotebook->AddPage( DisplayPanel, wxT("Display"), true );
	VewPanel = new wxPanel( SettingsNotebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	SettingsNotebook->AddPage( VewPanel, wxT("View"), false );

	bSizer4->Add( SettingsNotebook, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	this->Centre( wxBOTH );
}

SettingsDlg::~SettingsDlg()
{
}
