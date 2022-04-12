//
// Created by rhys on 4/11/22.
//

#include "MainFrameCust.h"
#include "Converter.h"
#include "Settings.h"
#include "SettingsDlgCust.h"


#include <wx/filedlg.h>
#include <wx/txtstrm.h>
#include <wx/textfile.h>


MainFrameCust::MainFrameCust() : MainFrame(NULL){
#ifdef USE_WEBVIEW
    webView = wxWebView::New(DisplayPanel, ID_DISPLAY);
    DisplaySizer->Add(webView, 1, wxEXPAND, 15);
#else
    htmlView = new wxHtmlWindow(DisplayPanel, ID_DISPLAY);
    DisplaySizer->Add(htmlView, 1, wxEXPAND, 5);
#endif


}

void MainFrameCust::RefreshText() {
    wxString text = MDEntry->GetText();

    wxString html = Converter::md2html(text);

#ifdef USE_WEBVIEW
    webView->SetPage(html, "about::blank");
#else
    htmlView->SetPage(html);
#endif
}

void MainFrameCust::OnRefreshBtn(wxCommandEvent &event) {
    RefreshText();
}

void MainFrameCust::OnSave(wxCommandEvent &event) {
    if(!currentFile) {
        wxFileDialog saveFileDialog(this, wxT("Save Markdown File"), "", "", "Markdown files (*.md)|*.md",wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

        if (saveFileDialog.ShowModal() == wxID_CANCEL) {
            return;
        }

        currentFile = saveFileDialog.GetPath();
    }

    wxTextFile file( currentFile );
    file.Open();

    file.Clear();

    int lines = MDEntry->GetLineCount();
    for(int i=0 ; i<lines ; i++){
        wxString line = MDEntry->GetLine(i);
        line = line.Strip(wxString::both);

        file.AddLine(line);
    }

    file.Write();
    file.Close();
}

void MainFrameCust::OnOpen(wxCommandEvent &event) {
    //TODO check if current document saved

    wxFileDialog openFileDialog(this, wxT("Open Markdown File"), "", "", "Markdown files (*.md)|*.md", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    currentFile = openFileDialog.GetPath();

    SetLabel(wxString::Format("MD Editor: '%s'", currentFile));

    wxString str;

    wxTextFile tfile;
    tfile.Open(currentFile);

    MDEntry->Clear();

    str = tfile.GetFirstLine();
    MDEntry->AddText(str);
    MDEntry->NewLine();

    while(!tfile.Eof()){
        str = tfile.GetNextLine();
        MDEntry->AddText(str);
        MDEntry->NewLine();
    }
}

void MainFrameCust::OnExport(wxCommandEvent &event) {
    wxFileDialog saveFileDialog(this, wxT("Export HTML File"), "", "", "HTML files (*.html)|*.html",wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxTextFile file( saveFileDialog.GetPath() );
    file.Open();

    file.Clear();

    wxString text = MDEntry->GetText();

    wxString html = Converter::md2html(text);

    file.AddLine(html);

    file.Write();
    file.Close();
}

void MainFrameCust::OnOpenSettings(wxCommandEvent &event) {
    SettingsDlgCust dlg(this);

    if (dlg.ShowModal() == wxID_CANCEL) {
        return;
    }

    Settings* s = Settings::init();

    s->save();

    s->load();

    //TODO refresh GUI
    RefreshText();
}
