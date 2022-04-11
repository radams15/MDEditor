//
// Created by rhys on 4/11/22.
//

#include "MainFrameCust.h"

#include <html.h>
#include <document.h>

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
