//
// Created by rhys on 4/11/22.
//

#include <wx/config.h>
#include "Settings.h"

#define DATA_DIR "../data"

Settings::Settings() {
    doLineWrap = true;

    //TODO Don't hardcode for my machine
    cssDir = DATA_DIR "/css_styles";
    codeBlockDir = DATA_DIR "/highlight_styles";
    scidownCssFile = DATA_DIR "/scidown.css";

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
