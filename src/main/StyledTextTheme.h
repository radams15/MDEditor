//
// Created by rhys on 15/04/2022.
//

#ifndef MDEDITOR_STYLEDTEXTTHEME_H
#define MDEDITOR_STYLEDTEXTTHEME_H

#include <wx/string.h>
#include <wx/colour.h>

class StyledTextTheme {
private:
    wxString path;

    void load();

public:
    wxColour background_colour;
    wxColour foreground_colour;
    wxColour header_colour;
    wxColour highlight_colour;
    wxColour code_block_colour;

    StyledTextTheme(wxString name);
};


#endif //MDEDITOR_STYLEDTEXTTHEME_H
