//
// Created by rhys on 4/11/22.
//

#include <wx/config.h>
#include "Settings.h"

Settings::Settings() {
    doLineWrap = true;

    cssDir = GET_DATA("css_styles");
    codeBlockDir = GET_DATA("highlight_styles");
    scidownCssFile = GET_DATA("scidown.css");
    scriptDir = GET_DATA("scripts");
    editorStyleDir = GET_DATA("themes");

    cssTheme = wxT("swiss.css");
    codeBlockStyle = wxT("default.css");
    editorStyle = wxT("cobalt");

    useMermaid = true;
    useCharter = true;
    doHighlight = true;

    mathsBackend = KATEX;

    load();
}

Settings* Settings::init() {
    static Settings instance;
    return &instance;
}

void Settings::load() {
    wxConfig* conf = new wxConfig(wxT("MDEditor"));

    if(conf->Exists(wxT("/Editor"))) {
        conf->SetPath(wxT("/Editor"));
        conf->Read(wxT("doLineWrap"), &doLineWrap);
        conf->Read(wxT("editorStyle"), &editorStyle);
    }

    if(conf->Exists(wxT("/Display"))) {
        conf->SetPath(wxT("/Display"));

        conf->Read(wxT("cssTheme"), &cssTheme);
        conf->Read(wxT("codeBlockStyle"), &codeBlockStyle);
        conf->Read(wxT("editorStyle"), &editorStyle);

        conf->Read(wxT("useMermaid"), &useMermaid);
        conf->Read(wxT("useCharter"), &useCharter);
        conf->Read(wxT("doHighlight"), &doHighlight);
        conf->Read(wxT("mathsBackend"), (int *) &mathsBackend);
    }

    if(conf->Exists(wxT("/View"))) {
        conf->SetPath(wxT("/View"));
    }

    delete conf;
}

void Settings::save() {
    wxConfig* conf = new wxConfig(wxT("MDEditor"));

    conf->SetPath(wxT("/Editor"));
    conf->Write(wxT("doLineWrap"), doLineWrap);
    conf->Write(wxT("editorStyle"), editorStyle);

    conf->SetPath(wxT("/Display"));

    conf->Write(wxT("cssTheme"), cssTheme);
    conf->Write(wxT("codeBlockStyle"), codeBlockStyle);

    conf->Write(wxT("useMermaid"), useMermaid);
    conf->Write(wxT("useCharter"), useCharter);
    conf->Write(wxT("doHighlight"), doHighlight);
    conf->Write(wxT("mathsBackend"), (int) mathsBackend);

    conf->SetPath(wxT("/View"));

    delete conf;
}
