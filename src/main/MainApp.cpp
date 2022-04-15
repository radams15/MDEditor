//
// Created by rhys on 22/01/2022.
//

#include "MainApp.h"
#include "MainFrameCust.h"

#ifdef __WXMSW__
#include <wx/msw/registry.h>
#endif

bool MainApp::OnInit() {
    if (!wxApp::OnInit())
        return false;

    wxInitAllImageHandlers();

#ifdef __WXMSW__
    wxLogNull nolog;   // suppress error messages
    wxRegKey rk( wxT("HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer\\Main\\FeatureControl\\FEATURE_BROWSER_EMULATION") );
    rk.SetValue( wxT("MDeditor.exe"), 11001);
#endif

    MainFrameCust *frame = new MainFrameCust();
    frame->Show(true);

    frame->OpenFiles(files);

    return true;
}


void MainApp::OnInitCmdLine(wxCmdLineParser& parser) {
    parser.SetDesc (g_cmdLineDesc);

    parser.SetSwitchChars (wxT("-"));
}

bool MainApp::OnCmdLineParsed(wxCmdLineParser& parser) {
    for (int i = 0; i < parser.GetParamCount(); i++){
        wxString param = parser.GetParam(i);
        files.Add(param);
    }

    return true;
}