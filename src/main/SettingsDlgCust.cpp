//
// Created by rhys on 4/12/22.
//

#include "SettingsDlgCust.h"

#include <wx/dir.h>
#include <wx/log.h>

SettingsDlgCust::SettingsDlgCust(wxWindow* parent) : SettingsDlg(parent){
    settings = Settings::init();

    loadDisplay();
    loadEditor();
    loadView();
}

void SettingsDlgCust::loadEditor() {

}

void SettingsDlgCust::loadDisplay() {
    CssCombo->Clear();
    wxArrayString cssFiles = filesInDir(settings->cssDir);
    CssCombo->Set(cssFiles);
    CssCombo->SetSelection(cssFiles.Index(settings->cssTheme));

    CodeThemeCombo->Clear();
    wxArrayString codeThemes = filesInDir(settings->codeBlockDir);
    CodeThemeCombo->Set(codeThemes);
    CodeThemeCombo->SetSelection(codeThemes.Index(settings->codeBlockStyle));

    MathsBackendCombo->SetSelection((int) settings->mathsBackend);

    MermaidCheck->SetValue(settings->useMermaid);
    CharterCheck->SetValue(settings->useCharter);
    HighlightCheck->SetValue(settings->doHighlight);
}

void SettingsDlgCust::loadView() {
    LineWrapCheck->SetValue(settings->doLineWrap);
}

void SettingsDlgCust::saveEditor() {

}

void SettingsDlgCust::saveDisplay() {
    settings->cssTheme = CssCombo->GetStringSelection();
    settings->codeBlockStyle = CodeThemeCombo->GetStringSelection();

    settings->mathsBackend = (MathsBackend) MathsBackendCombo->GetSelection();

    settings->useMermaid = MermaidCheck->GetValue();
    settings->useCharter = CharterCheck->GetValue();
    settings->doHighlight = HighlightCheck->GetValue();
}

void SettingsDlgCust::saveView() {
    settings->doLineWrap = LineWrapCheck->GetValue();
}

wxArrayString SettingsDlgCust::filesInDir(wxString dirs) {
    wxDir dir(dirs);

    wxArrayString out;

    if ( !dir.IsOpened() ){
        wxLogError("Cannot open directory: %s\n", dirs);
        return out;
    }

    wxString filename;
    bool cont = dir.GetFirst(&filename);
    while ( cont ){
        out.Add(filename);

        cont = dir.GetNext(&filename);
    }


    return out;
}

int SettingsDlgCust::ShowModal() {
    SettingsDlg::ShowModal();

    saveDisplay();
    saveEditor();
    saveView();

    return wxID_OK;
}
