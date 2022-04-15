//
// Created by rhys on 15/04/2022.
//

#include <wx/wfstream.h>
#include <wx/fileconf.h>

#include "StyledTextTheme.h"

#include "Settings.h"

#define READ_COLOUR(conf,key,out) buf="";conf.Read(key,&buf); if(! buf.IsEmpty()){out = toColour(buf);}else{}


bool SplitToken(const wxString& input, const wxChar& sep, wxString& rLeft, wxString& rRight){
    rLeft = input.BeforeFirst(sep);
    if (rLeft == input)
        return false;
    rRight= input.AfterFirst(sep);
    if (rRight.IsEmpty())
        return false;

    return true;
}


wxColour toColour(wxString in){
    wxString rs,gs,bs,tmp;

    wxPrintf("Colour: %s\n", in);

    long r,g,b;

    SplitToken(in, ',', rs, tmp);
    SplitToken(tmp, ',', gs, bs);

    rs.ToCLong(&r);
    gs.ToCLong(&g);
    bs.ToCLong(&b);

    return wxColour(r,g,b);
}

StyledTextTheme::StyledTextTheme(wxString file) {
    Settings* s = Settings::init();

    path = s->themeDir + SEP + file + ".theme";

    load();
}

void StyledTextTheme::load() {
    wxFileInputStream is(path);

    wxFileConfig conf(is);
    conf.SetPath(wxT("Theme"));

    wxString buf;

    READ_COLOUR(conf, "background_colour", background_colour);
    READ_COLOUR(conf, "foreground_colour", foreground_colour);
    READ_COLOUR(conf, "header_colour", header_colour);
    READ_COLOUR(conf, "highlight_colour", highlight_colour);
    READ_COLOUR(conf, "code_block_colour", code_block_colour);
}
