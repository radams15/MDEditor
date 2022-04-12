//
// Created by rhys on 4/11/22.
//

#ifndef MDEDITOR_SETTINGS_H
#define MDEDITOR_SETTINGS_H


#include <wx/string.h>

enum MathsBackend {
    NONE = 0,
    KATEX = 1,
    MATHJAX = 2,
};

class Settings {
protected:

    Settings();

public: //TODO encapsulate by making private (getters & setters)

    /* BEGIN EDITOR */

    bool doLineWrap;

    /* END EDITOR */


    /* BEGIN DISPLAY */
    wxString cssDir;
    wxString codeBlockDir;
    wxString scidownCssFile;

    wxString cssTheme;
    wxString codeBlockStyle;

    bool useMermaid;
    bool useCharter;
    bool doHighlight;

    MathsBackend mathsBackend;

    /* END DISPLAY */


    /* BEGIN VIEW */

    /* ENDVIEW */

public:
    static Settings* init();

    void load();
    void save();
};


#endif //MDEDITOR_SETTINGS_H
