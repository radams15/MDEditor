//
// Created by rhys on 22/01/2022.
//

#include "MainApp.h"
#include "MainFrameCust.h"

bool MainApp::OnInit() {
    wxInitAllImageHandlers();

    MainFrame *frame = new MainFrameCust();
    frame->Show(true);

    return true;
}
