///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/stc/stc.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/checkbox.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/notebook.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnRefreshBtn( wxCommandEvent& event ){ OnRefreshBtn( event ); }
		void _wxFB_OnSave( wxCommandEvent& event ){ OnSave( event ); }
		void _wxFB_OnOpen( wxCommandEvent& event ){ OnOpen( event ); }
		void _wxFB_OnExport( wxCommandEvent& event ){ OnExport( event ); }
		void _wxFB_OnOpenSettings( wxCommandEvent& event ){ OnOpenSettings( event ); }


	protected:
		enum
		{
			ID_SAVE = 1000,
			ID_OPEN,
			ID_EXPORT,
			ID_SETTINGS
		};

		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel2;
		wxStyledTextCtrl* MDEntry;
		wxPanel* DisplayPanel;
		wxBoxSizer* DisplaySizer;
		wxToolBar* m_toolBar1;
		wxButton* m_button1;
		wxStatusBar* StatusBar;
		wxMenuBar* m_menubar1;
		wxMenu* FileMenu;
		wxMenu* EditMenu;

		// Virtual event handlers, override them in your derived class
		virtual void OnRefreshBtn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpenSettings( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MDEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 0 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter1OnIdle ), NULL, this );
		}

};

///////////////////////////////////////////////////////////////////////////////
/// Class SettingsDlg
///////////////////////////////////////////////////////////////////////////////
class SettingsDlg : public wxDialog
{
	private:

	protected:
		wxNotebook* SettingsNotebook;
		wxPanel* EditorPanel;
		wxCheckBox* LineWrapCheck;
		wxPanel* DisplayPanel;
		wxStaticText* m_staticText1;
		wxChoice* CssCombo;
		wxStaticText* m_staticText11;
		wxChoice* CodeThemeCombo;
		wxStaticText* m_staticText12;
		wxChoice* MathsBackendCombo;
		wxCheckBox* MermaidCheck;
		wxCheckBox* CharterCheck;
		wxCheckBox* HighlightCheck;
		wxPanel* VewPanel;

	public:

		SettingsDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Settings"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );

		~SettingsDlg();

};

