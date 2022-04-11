//
// Created by rhys on 4/11/22.
//

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
