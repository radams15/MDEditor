//
// Created by rhys on 4/11/22.
//

#include <wx/config.h>
#include "Settings.h"

Settings::Settings() {
    //TODO Don't hardcode for my machine
    cssDir = "/mnt/share/scripts/MDEditor/data/css_styles";
    highlightDir = "/mnt/share/scripts/MDEditor/data/highlight_styles";

    scidownCssFile = "/mnt/share/scripts/MDEditor/data/scidown.css";

    cssTheme = "swiss.css";
    highlightTheme = "default.css";

    useMermaid = true;
    useCharter = true;
    useHighlight = true;

    mathsBackend = KATEX;
}

Settings* Settings::init() {
    static Settings instance;
    return &instance;
}

void Settings::load() {

}

void Settings::save() {
    wxConfig* conf = new wxConfig("MDEditor");

    conf->SetPath("/Editor");



    conf->SetPath("/Display");

    // These are really compile-time constants so don't save them
    /*conf->Write("cssDir", cssDir);
    conf->Write("highlightDir", highlightDir);
    conf->Write("scidownCssFile", scidownCssFile);*/

    conf->Write("cssTheme", cssTheme);
    conf->Write("highlightTheme", highlightTheme);
    conf->Write("codeblockTheme", codeblockTheme);

    conf->Write("useMermaid", useMermaid);
    conf->Write("useCharter", useCharter);
    conf->Write("useHighlight", useHighlight);
    conf->Write("mathsBackend", (int) mathsBackend);


    conf->SetPath("/View");

    wxPrintf("%s\n", wxFileConfig::GetLocalFileName("MDEditor"));

    delete conf;
}
