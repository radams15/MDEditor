//
// Created by rhys on 4/11/22.
//

#ifndef MDEDITOR_MAINFRAMECUST_H
#define MDEDITOR_MAINFRAMECUST_H

#include "MainFrame.h"

#ifdef USE_WEBVIEW
#include <wx/webview.h>
#include <wx/textctrl.h>

#else
#include <wx/wxhtml.h>
#endif

#ifdef USE_STYLED_CTRL
#include <wx/stc/stc.h>
#endif

class MainFrameCust : public MainFrame{
private:

    enum {
        ID_DISPLAY
    };

    void RefreshText();

    wxString currentFile;

    void loadEntrySettings();

#ifdef USE_WEBVIEW
    wxWebView* webView;
#else
    wxHtmlWindow* htmlView;
#endif

#ifdef USE_STYLED_CTRL
    wxStyledTextCtrl* textCtrl;
#else
    wxTextCtrl* textCtrl;
#endif

protected:

    void OnRefreshBtn( wxCommandEvent& event );

    void OnSave( wxCommandEvent& event );
    void OnOpen( wxCommandEvent& event );
    void OnExport( wxCommandEvent& event );
    void OnOpenSettings( wxCommandEvent& event );

public:
    MainFrameCust();
};


#endif //MDEDITOR_MAINFRAMECUST_H
