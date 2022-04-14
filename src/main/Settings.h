//
// Created by rhys on 4/11/22.
//

#ifndef MDEDITOR_SETTINGS_H
#define MDEDITOR_SETTINGS_H


#include <wx/string.h>

#if defined(WIN32)
#define SEP "\\"
#elif defined(__UNIX__)
#define SEP "/"
#else
#define SEP ":"
#endif

#ifndef DATA_DIR
#define DATA_DIR "../data"
#endif

#ifndef __APPLE__
#define GET_DATA(f) DATA_DIR SEP f
#else
extern "C" const char* getResourcePath(const char* file);

#define GET_DATA(f) wxString::FromUTF8(getResourcePath(f))
#endif

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
    wxString scriptDir;

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
