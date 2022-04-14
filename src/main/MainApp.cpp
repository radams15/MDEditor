//
// Created by rhys on 22/01/2022.
//

#include "MainApp.h"
#include "MainFrameCust.h"

#ifdef __WXMSW__
#include <wx/msw/registry.h>
#endif

bool MainApp::OnInit() {
    wxInitAllImageHandlers();

#ifdef __WXMSW__
    wxLogNull nolog;   // suppress error messages
    wxRegKey rk( wxT("HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer\\Main\\FeatureControl\\FEATURE_BROWSER_EMULATION") );
    rk.SetValue( wxT("MDeditor.exe"), 11001);
#endif

    MainFrame *frame = new MainFrameCust();
    frame->Show(true);

    return true;
}
