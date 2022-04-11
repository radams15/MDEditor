//
// Created by rhys on 4/11/22.
//

#include "MainFrameCust.h"

#include <html.h>
#include <document.h>

#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>

wxString md2html(wxString in){
    hoedown_renderer* renderer;
    hoedown_document* document;
    hoedown_buffer* buffer;
    scidown_render_flags html_mode = SCIDOWN_RENDER_MERMAID;
    localization local = {
            (char*) "Figure",
            (char*) "Listing",
            (char*) "Table"
    };

    renderer = hoedown_html_renderer_new(html_mode, 0, local);

    char * header = strdup(""); // Header inc. styling, etc.

    char * footer = strdup("");

    ext_definition def = {header, footer};


    document = hoedown_document_new(renderer,
                                    (hoedown_extensions) (HOEDOWN_EXT_BLOCK         |
                                    HOEDOWN_EXT_SPAN          |
                                    HOEDOWN_EXT_FLAGS),
                                    &def,
                                    ".",
                                    16);

    buffer = hoedown_buffer_new(500);

    const char* data = in.mb_str();
    hoedown_document_render(document, buffer, (uint8_t*) data, in.length(), 0);

    free(header);
    free(footer);

    const char* buf_cstr = hoedown_buffer_cstr(buffer);

    wxString html = wxString(buf_cstr);

    hoedown_html_renderer_free(renderer);
    hoedown_document_free(document);
    hoedown_buffer_free(buffer);

    return html;
}

MainFrameCust::MainFrameCust() : MainFrame(NULL){

}

void MainFrameCust::RefreshText() {
    wxString text = MDEntry->GetText();

    DisplayView->SetPage(md2html(text));
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
