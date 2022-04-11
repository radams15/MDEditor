//
// Created by rhys on 4/11/22.
//

#include "MainFrameCust.h"
#include "Converter.h"


#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>

MainFrameCust::MainFrameCust() : MainFrame(NULL){

}

void MainFrameCust::RefreshText() {
    wxString text = MDEntry->GetText();

    wxString html = Converter::md2html(text);

    DisplayView->SetPage(html);
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

}
