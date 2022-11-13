//
// Created by rhys on 4/12/22.
//

#include "SettingsDlgCust.h"

#include <wx/dir.h>
#include <wx/log.h>

void setCombo(wxChoice* chc, wxArrayString data){
    for(int i=0 ; i<data.Count() ; i++){
        chc->Append(data.Item(i));
    }
}

SettingsDlgCust::SettingsDlgCust(wxWindow* parent) : SettingsDlg(parent){
    settings = Settings::init();

    loadDisplay();
    loadEditor();
    loadView();
}

void SettingsDlgCust::loadEditor() {
    LineWrapCheck->SetValue(settings->doLineWrap);

    StyleCombo->Clear();
    wxArrayString styleThemes = filesInDir(settings->editorStyleDir);
    for(int i=0 ; i<styleThemes.Count() ; i++){styleThemes.Item(i).Replace(wxT(".theme"),wxT(""));}
    setCombo(StyleCombo, styleThemes);
    StyleCombo->SetSelection(styleThemes.Index(settings->editorStyle));
}

void SettingsDlgCust::loadDisplay() {
    CssCombo->Clear();
    wxArrayString cssFiles = filesInDir(settings->cssDir);
    setCombo(CssCombo, cssFiles);
    CssCombo->SetSelection(cssFiles.Index(settings->cssTheme));

    CodeThemeCombo->Clear();
    wxArrayString codeThemes = filesInDir(settings->codeBlockDir);
    setCombo(CodeThemeCombo, codeThemes);
    CodeThemeCombo->SetSelection(codeThemes.Index(settings->codeBlockStyle));

    MathsBackendCombo->SetSelection((int) settings->mathsBackend);

    MermaidCheck->SetValue(settings->useMermaid);
    CharterCheck->SetValue(settings->useCharter);
    HighlightCheck->SetValue(settings->doHighlight);
}

void SettingsDlgCust::loadView() {

}

void SettingsDlgCust::saveEditor() {
    settings->doLineWrap = LineWrapCheck->GetValue();
    settings->editorStyle = StyleCombo->GetStringSelection();
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

}

wxArrayString SettingsDlgCust::filesInDir(wxString dirs) {
    wxDir dir(dirs);

    wxArrayString out;

    if ( !dir.IsOpened() ){
        wxLogError(wxT("Cannot open directory: %s\n"), dirs.c_str());
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
