//
// Created by rhys on 4/11/22.
//

#ifndef MDEDITOR_SETTINGS_H
#define MDEDITOR_SETTINGS_H


#include <wx/string.h>

#if defined(WIN32)
#define SEP wxT("\\")
#elif defined(__UNIX__)
#define SEP wxT("/")
#else
#define SEP wxT(":")
#endif

#ifndef DATA_DIR
#define DATA_DIR "../data"
#endif

#ifndef __APPLE__
#define GET_DATA(f) wxT(DATA_DIR SEP f)
#else
extern "C" const char* getResourcePath(const char* file);

#define GET_DATA(f) wxString::FromUTF8(getResourcePath((const char*) (f)))
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
    wxString editorStyleDir;

    wxString cssTheme;
    wxString codeBlockStyle;
    wxString editorStyle;

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
