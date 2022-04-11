//
// Created by rhys on 4/11/22.
//

#ifndef MDEDITOR_SETTINGS_H
#define MDEDITOR_SETTINGS_H


#include <wx/string.h>

enum MathsBackend {
    KATEX,
    MATHJAX,
    NONE
};

class Settings {
protected:

    Settings();

public: //TODO encapsulate by making private (getters & setters)
    wxString cssDir;
    wxString highlightDir;

    wxString scidownCssFile;
    wxString cssTheme;
    wxString highlightTheme;
    wxString codeblockTheme;

    bool useMermaid;
    bool useCharter;
    bool useHighlight;

    MathsBackend mathsBackend;

public:
    static Settings* init();
};


#endif //MDEDITOR_SETTINGS_H
