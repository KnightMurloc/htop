#ifndef HEADER_MetersPanel
#define HEADER_MetersPanel
/*
htop - MetersPanel.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Panel.h"
#include "Settings.h"
#include "ScreenManager.h"

typedef struct MetersPanel_ MetersPanel;

struct MetersPanel_ {
   Panel super;

   Settings* settings;
   Vector* meters;
   ScreenManager* scr;
   MetersPanel* leftNeighbor;
   MetersPanel* rightNeighbor;
   bool moving;
};


// Note: In code the meters are known to have bar/text/graph "Modes", but in UI
// we call them "Styles".
// We avoid UTF-8 arrows ← → here as they might display full-width on Chinese
// terminals, breaking our aligning.
// In <http://unicode.org/reports/tr11/>, arrows (U+2019..U+2199) are
// considered "Ambiguous characters".

void MetersPanel_setMoving(MetersPanel* this, bool moving);

extern PanelClass MetersPanel_class;

MetersPanel* MetersPanel_new(Settings* settings, const char* header, Vector* meters, ScreenManager* scr);

#endif
