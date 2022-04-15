//
// Created by rhys on 4/11/22.
//

#include "MainFrameCust.h"
#include "Converter.h"
#include "Settings.h"
#include "SettingsDlgCust.h"
#include "StyledTextTheme.h"

#include <wx/filedlg.h>
#include <wx/txtstrm.h>
#include <wx/textfile.h>

extern "C" void tweak(void* window);

#ifdef USE_STYLED_CTRL
void loadStyleTheme(wxStyledTextCtrl* textCtrl){
    Settings* s = Settings::init();

    StyledTextTheme theme(s->editorStyle);

    textCtrl->SetLexer(wxSTC_LEX_MARKDOWN);

    wxColour highlightColour = {};
    for(int i=4 ; i<=10 ; i++) {
        textCtrl->StyleSetForeground(i, theme.header_colour);
        textCtrl->StyleSetBackground(i, theme.background_colour);
    }

    for(int i=10 ; i<=31 ; i++) {
        textCtrl->StyleSetForeground(i, theme.code_block_colour);
        textCtrl->StyleSetBackground(i, theme.background_colour);
    }

    textCtrl->StyleSetBackground(0, theme.background_colour); // Text bg
    textCtrl->StyleSetBackground(1, theme.background_colour); // Newline bg
    textCtrl->StyleSetBackground(wxSTC_STYLE_DEFAULT, theme.background_colour); // No-text bg
    textCtrl->StyleSetForeground(0, theme.foreground_colour);

    textCtrl->SetSelBackground( true, theme.highlight_colour );
    textCtrl->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
}
#endif

MainFrameCust::MainFrameCust() : MainFrame(NULL){
    SetThemeEnabled(true);

#ifdef USE_WEBVIEW
    webView = wxWebView::New(DisplayPanel, ID_DISPLAY);
    DisplaySizer->Add(webView, 1, wxEXPAND, 5);
#else
    htmlView = new wxHtmlWindow(DisplayPanel, ID_DISPLAY);
    DisplaySizer->Add(htmlView, 1, wxEXPAND, 5);
#endif

#ifdef USE_STYLED_CTRL
    textCtrl = new wxStyledTextCtrl( EntryPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );

    textCtrl->SetUseTabs( true );
    textCtrl->SetTabWidth( 4 );
    textCtrl->SetIndent( 4 );
    textCtrl->SetTabIndents( true );
    textCtrl->SetBackSpaceUnIndents( true );
    textCtrl->SetViewEOL( false );
    textCtrl->SetViewWhiteSpace( false );
    textCtrl->SetMarginWidth( 1, 0 );
    textCtrl->SetIndentationGuides( true );
    textCtrl->SetReadOnly( false );
    textCtrl->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
    textCtrl->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
    textCtrl->SetMarginWidth( 1, 16);
    textCtrl->SetMarginSensitive( 1, true );
    textCtrl->SetProperty( wxT("fold"), wxT("1") );
    textCtrl->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
    textCtrl->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
    textCtrl->SetMarginWidth( 0, textCtrl->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("000") ) );

    loadStyleTheme(textCtrl);

    EntrySizer->Add( textCtrl, 1, wxEXPAND | wxALL, 5 );
#else
    textCtrl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH2|wxTE_PROCESS_TAB|wxTE_PROCESS_ENTER);
    textCtrl->SetEditable(true);
    EntrySizer->Add( textCtrl, 1, wxEXPAND | wxALL, 5 );
#endif

#ifdef __APPLE__
    tweak((void*) MacGetTopLevelWindowRef());
#endif
}

void MainFrameCust::RefreshText() {
#if USE_STYLED_CTRL
    wxString text = textCtrl->GetText();
#else
    wxString text = textCtrl->GetValue();
#endif

    wxString html = Converter::md2html(text);

#ifdef USE_WEBVIEW
    webView->SetPage(html, wxT("about::blank"));
#else
    htmlView->SetPage(html);
#endif

    loadEntrySettings();
}

void MainFrameCust::OnRefreshBtn(wxCommandEvent &event) {
    RefreshText();
}

void MainFrameCust::OnSave(wxCommandEvent &event) {
    if(!currentFile) {
        wxFileDialog saveFileDialog(this, wxT("Save Markdown File"), wxT(""), wxT(""), wxT("Markdown files (*.md)|*.md"),wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

        if (saveFileDialog.ShowModal() == wxID_CANCEL) {
            return;
        }

        currentFile = saveFileDialog.GetPath();
    }

    wxTextFile file( currentFile );
    file.Open();

    file.Clear();

#if USE_STYLED_CTRL
    int lines = textCtrl->GetLineCount();
#else
    int lines = textCtrl->GetNumberOfLines();
#endif

    for(int i=0 ; i<lines ; i++){
#if USE_STYLED_CTRL
        wxString line = textCtrl->GetLine(i);
#else
        wxString line = textCtrl->GetLineText(i);
#endif

        line = line.Strip(wxString::both);

        file.AddLine(line);
    }

    file.Write();
    file.Close();
}

void MainFrameCust::OnOpen(wxCommandEvent &event) {
    //TODO check if current document saved

    wxFileDialog openFileDialog(this, wxT("Open Markdown File"), wxT(""), wxT(""), wxT("Markdown files (*.md)|*.md"), wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    currentFile = openFileDialog.GetPath();

    OpenFile(currentFile);
}

void MainFrameCust::OnExport(wxCommandEvent &event) {
    wxFileDialog saveFileDialog(this, wxT("Export HTML File"), wxT(""), wxT(""), wxT("HTML files (*.html)|*.html"),wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxTextFile file( saveFileDialog.GetPath() );
    file.Open();

    file.Clear();

#if USE_STYLED_CTRL
    wxString text = textCtrl->GetText();
#else
    wxString text = textCtrl->GetValue();
#endif

    wxString html = Converter::md2html(text);

    file.AddLine(html);

    file.Write();
    file.Close();
}

void MainFrameCust::OnOpenSettings(wxCommandEvent &event) {
    SettingsDlgCust dlg(this);

    if (dlg.ShowModal() == wxID_CANCEL) {
        return;
    }

    Settings* s = Settings::init();

    s->save();

    s->load();

    RefreshText();
    loadEntrySettings();
}

void MainFrameCust::loadEntrySettings() {
    Settings* s = Settings::init();

#if USE_STYLED_CTRL
    if(s->doLineWrap){
        textCtrl->SetWrapMode(wxSTC_WRAP_WORD);
    }else{
        textCtrl->SetWrapMode(wxSTC_WRAP_NONE);
    }

#else
    if(s->doLineWrap) {
        textCtrl->SetExtraStyle(wxTE_WORDWRAP);
    } else {
        textCtrl->SetExtraStyle(wxTE_DONTWRAP);
    }
#endif
}

void MainFrameCust::OpenFiles(wxArrayString files) {
    if(files.Count() < 1){
        return;
    }

    wxString file = files.Item(0);

    OpenFile(file);
}

void MainFrameCust::OpenFile(wxString file) {
    SetLabel(wxString::Format(wxT("MD Editor: '%s'"), currentFile.mb_str()));

    wxString str;

    wxTextFile tfile;
    tfile.Open(file);


    str = tfile.GetFirstLine();

#if USE_STYLED_CTRL
    textCtrl->ClearAll();
    textCtrl->AddText(str);
    textCtrl->NewLine();
#else
    textCtrl->Clear();
    textCtrl->AppendText(str);
#if defined(WIN32)
    textCtrl->AppendText(wxT("\r\n"));
#elif defined(__UNIX__)
    textCtrl->AppendText(wxT("\n"));
#else
    textCtrl->AppendText(wxT("\r"));
#endif
#endif

    while(!tfile.Eof()){
        str = tfile.GetNextLine();
#if USE_STYLED_CTRL
        textCtrl->AddText(str);
        textCtrl->NewLine();
#else
        textCtrl->AppendText(str);
#if defined(WIN32)
        textCtrl->AppendText(wxT("\r\n"));
#elif defined(__UNIX__)
        textCtrl->AppendText(wxT("\n"));
#else
        textCtrl->AppendText(wxT("\r"));
#endif
#endif
    }
}
