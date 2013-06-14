#ifndef _COMPACT_MENU_H_
#define _COMPACT_MENU_H_

#define CM_SAFE_MODE

#define PRAGMA_PATH "..\\Source\\compact_menu"

typedef struct CMSTYLE
{
	COLOR colText;
	COLOR colBack;
	COLOR colOver;
	FONT *font;
} CMSTYLE;

CMSTYLE *cmstyle_create ( FONT *font, COLOR *colText, COLOR *colBackground, COLOR *colOver );

PANEL *cmenu_create ( char *chrMember, var pos_x, var pos_y, var size_x, var layer, var flags, CMSTYLE *style );

void cmenu_modify ( PANEL *panel, var size_x, CMSTYLE *style );

void cmenu_remove ( PANEL *panel );

void cmenu_remove_all ();

void cmmember_draw_name ();

void cmmember_draw_var ( var *pointer, STRING *format );


#include "compact_menu.c"
#include "cm_submenu.c"
#include "cm_title.c"
#include "cm_line.c"
#include "cm_space.c"
#include "cm_bitmap.c"
#include "cm_button.c"
#include "cm_slider.c"
#include "cm_digit.c"

#endif