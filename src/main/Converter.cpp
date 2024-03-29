//
// Created by rhys on 4/11/22.
//

#include "Converter.h"
#include "Settings.h"

#include <html.h>
#include <wx/textfile.h>

scidown_render_flags renderMode(Settings* s){
    scidown_render_flags out = (scidown_render_flags) 0;

    if(s->useMermaid){
        out = (scidown_render_flags) (out | (scidown_render_flags) SCIDOWN_RENDER_MERMAID);
    }

    if(s->useCharter){
        out = (scidown_render_flags) (out | (scidown_render_flags) SCIDOWN_RENDER_CHARTER);
    }

    return out;
}

wxString join(wxString a, wxString b){
    return a + SEP + b;
}

wxString getFileContent(wxString file){
    if(! wxFileExists(file)) {
        wxLogError(wxT("Cannot open file '%s'\n"), file.c_str());
        return wxT("");
    }

    wxString str;
    wxString out;

    wxTextFile tfile;
    tfile.Open(file);

    out += tfile.GetFirstLine() + wxT("\n");

    while (!tfile.Eof()) {
        out += tfile.GetNextLine() + wxT("\n");
    }

    return out;
}

wxString header(Settings* s){
    wxString buf = wxT("");

    if(s->mathsBackend == KATEX){
        buf += wxT("<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.9.0-alpha2/katex.min.css\" crossorigin=\"anonymous\">");
        buf += wxT("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.9.0-alpha2/katex.min.js\" crossorigin=\"anonymous\"></script>");
        buf += wxT("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/KaTeX/0.9.0-alpha2/contrib/auto-render.min.js\" crossorigin=\"anonymous\"></script>");
    }else if(s->mathsBackend == MATHJAX){
        buf += wxT("<script type=\"text/javascript\" src=\"https://cdn.jsdelivr.net/npm/mathjax@2.7.1/MathJax.js?config=TeX-AMS_HTML\"></script>");
    }

    if(s->doHighlight){
        wxString css = s->codeBlockStyle;
        css.Replace(wxT(".css"), wxT(""));
        buf += wxString::Format(wxT("<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/%s.min.css\">"), css.c_str());
        buf += wxT("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/highlight.min.js\"></script>");
    }

    if(s->useMermaid){
        buf += wxT("<script src=\"https://unpkg.com/mermaid@7.1.2/dist/mermaid.min.js\"></script>");
    }

    buf += wxT("<style>");
    buf += getFileContent(join(s->cssDir, s->cssTheme));
    buf += getFileContent(s->scidownCssFile);
    buf += wxT("</style>");

    return buf;
}

wxString footer(Settings* s){
    wxString buf;

    if(s->mathsBackend == KATEX){
        buf += wxT("<script>renderMathInElement(document.body);</script>");
    }

    if(s->doHighlight){
        buf += wxT("<script>hljs.initHighlightingOnLoad();</script>");
    }

    if(s->useMermaid){
        buf += wxT("<script>mermaid.initialize({startOnLoad:true});</script>");
    }

    return buf;
}

wxString Converter::md2html(wxString in){
    Settings* s = Settings::init();

    hoedown_renderer* renderer;
    hoedown_document* document;
    hoedown_buffer* buffer;

    scidown_render_flags html_mode = renderMode(s);

    localization_t local = {
            (char*) wxT("Figure"),
            (char*) wxT("Listing"),
            (char*) wxT("Table")
    };

    renderer = hoedown_html_renderer_new(html_mode, 0, local);

    ext_definition def = {
            (char*) strdup((const char*) header(s).mb_str()),
            (char*) strdup((const char*) footer(s).mb_str()),
    };

    document = hoedown_document_new(renderer,
                                    (hoedown_extensions) (HOEDOWN_EXT_BLOCK | HOEDOWN_EXT_SPAN | HOEDOWN_EXT_FLAGS),
                                    &def,
                                    ".",
                                    16);

    buffer = hoedown_buffer_new(500);

    const char* data = (const char*) strdup((const char*) in.mb_str());
    hoedown_document_render(document, buffer, (uint8_t*) data, in.length(), 0);

    const char* buf_cstr = hoedown_buffer_cstr(buffer);

    wxString html = wxString::FromUTF8(buf_cstr);
	
	//printf("HTML: %s\n", buf_cstr);

    free(def.extra_header);
    free(def.extra_closing);
    hoedown_html_renderer_free(renderer);
    hoedown_document_free(document);
    hoedown_buffer_free(buffer);

    return html;
}
