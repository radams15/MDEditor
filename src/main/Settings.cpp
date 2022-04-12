//
// Created by rhys on 4/11/22.
//

#include <wx/config.h>
#include "Settings.h"

Settings::Settings() {
    doLineWrap = true;

    //TODO Don't hardcode for my machine
    cssDir = "/mnt/share/scripts/MDEditor/data/css_styles";
    codeBlockDir = "/mnt/share/scripts/MDEditor/data/highlight_styles";

    scidownCssFile = "/mnt/share/scripts/MDEditor/data/scidown.css";

    cssTheme = "swiss.css";
    codeBlockStyle = "default.css";

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
    wxConfig* conf = new wxConfig("MDEditor");

    if(conf->Exists("/Editor")) {
        conf->SetPath("/Editor");
        conf->Read("doLineWrap", &doLineWrap);
    }

    if(conf->Exists("/Display")) {
        conf->SetPath("/Display");

        conf->Read("cssTheme", &cssTheme);
        conf->Read("codeBlockStyle", &codeBlockStyle);

        conf->Read("useMermaid", &useMermaid);
        conf->Read("useCharter", &useCharter);
        conf->Read("doHighlight", &doHighlight);
        conf->Read("mathsBackend", (int *) &mathsBackend);
    }

    if(conf->Exists("/View")) {
        conf->SetPath("/View");
    }

    delete conf;
}

void Settings::save() {
    wxConfig* conf = new wxConfig("MDEditor");

    conf->SetPath("/Editor");
    conf->Write("doLineWrap", doLineWrap);

    conf->SetPath("/Display");

    conf->Write("cssTheme", cssTheme);
    conf->Write("codeBlockStyle", codeBlockStyle);

    conf->Write("useMermaid", useMermaid);
    conf->Write("useCharter", useCharter);
    conf->Write("doHighlight", doHighlight);
    conf->Write("mathsBackend", (int) mathsBackend);

    conf->SetPath("/View");

    delete conf;
}
