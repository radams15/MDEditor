//
// Created by rhys on 4/11/22.
//

#ifndef MDEDITOR_MAINFRAMECUST_H
#define MDEDITOR_MAINFRAMECUST_H

#include "MainFrame.h"

class MainFrameCust : public MainFrame{
private:

    void RefreshText();

protected:

    void OnRefreshBtn( wxCommandEvent& event );

public:
    MainFrameCust();
};


#endif //MDEDITOR_MAINFRAMECUST_H
