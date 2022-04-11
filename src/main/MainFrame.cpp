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
END_EVENT_TABLE()

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter1OnIdle ), NULL, this );

	m_panel2 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	MDEntry = new wxStyledTextCtrl( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	MDEntry->SetUseTabs( true );
	MDEntry->SetTabWidth( 4 );
	MDEntry->SetIndent( 4 );
	MDEntry->SetTabIndents( true );
	MDEntry->SetBackSpaceUnIndents( true );
	MDEntry->SetViewEOL( false );
	MDEntry->SetViewWhiteSpace( false );
	MDEntry->SetMarginWidth( 2, 0 );
	MDEntry->SetIndentationGuides( true );
	MDEntry->SetReadOnly( false );
	MDEntry->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	MDEntry->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	MDEntry->SetMarginWidth( 1, 16);
	MDEntry->SetMarginSensitive( 1, true );
	MDEntry->SetProperty( wxT("fold"), wxT("1") );
	MDEntry->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	MDEntry->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	MDEntry->SetMarginWidth( 0, MDEntry->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	MDEntry->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	MDEntry->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	MDEntry->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	MDEntry->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	MDEntry->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	MDEntry->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	MDEntry->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	MDEntry->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	MDEntry->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	MDEntry->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	MDEntry->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer5->Add( MDEntry, 1, wxEXPAND | wxALL, 5 );


	m_panel2->SetSizer( bSizer5 );
	m_panel2->Layout();
	bSizer5->Fit( m_panel2 );
	m_panel3 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	DisplayView = new wxHtmlWindow( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO );
	bSizer6->Add( DisplayView, 1, wxALL|wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer6 );
	m_panel3->Layout();
	bSizer6->Fit( m_panel3 );
	m_splitter1->SplitVertically( m_panel2, m_panel3, 0 );
	bSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_button1 = new wxButton( m_toolBar1, wxID_ANY, wxT("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );

	m_button1->SetBitmap( wxNullBitmap );
	m_toolBar1->AddControl( m_button1 );
	m_toolBar1->Realize();

	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
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

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );
}

MainFrame::~MainFrame()
{
}
