//
// Created by rhys on 4/12/22.
//

#ifndef MDEDITOR_SETTINGSDLGCUST_H
#define MDEDITOR_SETTINGSDLGCUST_H


#include "MainFrame.h"
#include "Settings.h"

class SettingsDlgCust : public SettingsDlg {
private:
    Settings* settings;

    void loadEditor();
    void loadDisplay();
    void loadView();

    void saveEditor();
    void saveDisplay();
    void saveView();

    static wxArrayString filesInDir(wxString dirs);


public:
    explicit SettingsDlgCust(wxWindow* parent);

    int ShowModal();
};


#endif //MDEDITOR_SETTINGSDLGCUST_H
