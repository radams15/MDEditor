//
// Created by rhys on 22/01/2022.
//

#ifndef YOUTUBECLI_MAINAPP_H
#define YOUTUBECLI_MAINAPP_H

#include <wx/cmdline.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainApp : public wxApp {
private:
    wxArrayString files;
public:
    virtual bool OnInit();
    virtual void OnInitCmdLine(wxCmdLineParser& parser);
    virtual bool OnCmdLineParsed(wxCmdLineParser& parser);
};

static const wxCmdLineEntryDesc g_cmdLineDesc [] = {
            { wxCMD_LINE_PARAM, "f", "file", "file to open", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL  },

            { wxCMD_LINE_NONE }
};



#endif //YOUTUBECLI_MAINAPP_H
