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
#include <wx/html/htmlwin.h>
#include <wx/splitter.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

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


	protected:
		enum
		{
			ID_SAVE = 1000,
			ID_OPEN,
			ID_EXPORT
		};

		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel2;
		wxStyledTextCtrl* MDEntry;
		wxPanel* m_panel3;
		wxHtmlWindow* DisplayView;
		wxToolBar* m_toolBar1;
		wxButton* m_button1;
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		wxMenu* FileMenu;

		// Virtual event handlers, override them in your derived class
		virtual void OnRefreshBtn( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("MDEditor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 0 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter1OnIdle ), NULL, this );
		}

};

