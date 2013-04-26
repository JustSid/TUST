#include <acknex.h>
#include "menu.h"

void menu_init() {

	var vFormat;
	var vPixel;
	int i;
	
	// TODO: Has to be done with generic TUST BITMAP FUNCTIONS
	// Create buttons - if not defined, generate bitmaps
	if (bmapMenuButtonOff == NULL) {
		bmapMenuButtonOff = bmap_createblack(MENU_BUTTON_SIZE_X,MENU_BUTTON_SIZE_Y,24);
		var vFormat = bmap_lock(bmapMenuButtonOff, 0);
		var vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		int i;
		// Draw Borders
		for (i=0; i<bmap_width(bmapMenuButtonOff); i++) {
			pixel_to_bmap(bmapMenuButtonOff, i, 0, vPixel);
			pixel_to_bmap(bmapMenuButtonOff, i, bmap_height(bmapMenuButtonOff)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapMenuButtonOff); i++) {
			pixel_to_bmap(bmapMenuButtonOff, 0, i, vPixel);
			pixel_to_bmap(bmapMenuButtonOff, bmap_width(bmapMenuButtonOff)-1, i, vPixel);
		}
		bmap_unlock(bmapMenuButtonOff);
	}
	if (bmapMenuButtonOn == NULL) {
		bmapMenuButtonOn = bmap_createblack(MENU_BUTTON_SIZE_X,MENU_BUTTON_SIZE_Y,24);
		bmap_fill(bmapMenuButtonOn, vector(0,0,128), 100);
		vFormat = bmap_lock(bmapMenuButtonOn, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		
		// Draw Borders
		for (i=0; i<bmap_width(bmapMenuButtonOn); i++) {
			pixel_to_bmap(bmapMenuButtonOn, i, 0, vPixel);
			pixel_to_bmap(bmapMenuButtonOn, i, bmap_height(bmapMenuButtonOn)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapMenuButtonOn); i++) {
			pixel_to_bmap(bmapMenuButtonOn, 0, i, vPixel);
			pixel_to_bmap(bmapMenuButtonOn, bmap_width(bmapMenuButtonOn)-1, i, vPixel);
		}
		bmap_unlock(bmapMenuButtonOn);
	}
	
	// TODO: Has to be done with generic TUST BITMAP FUNCTIONS
	// Create save/load slot bitmaps
	if (bmapSaveSlotOff == NULL) {
		bmapSaveSlotOff = bmap_createblack(MENU_SAVE_SLOT_SIZE_X, MENU_SAVE_SLOT_SIZE_Y, 24);
		vFormat = bmap_lock(bmapSaveSlotOff, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapSaveSlotOff); i++) {
			pixel_to_bmap(bmapSaveSlotOff, i, 0, vPixel);
			pixel_to_bmap(bmapSaveSlotOff, i, bmap_height(bmapSaveSlotOff)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapSaveSlotOff); i++) {
			pixel_to_bmap(bmapSaveSlotOff, 0, i, vPixel);
			pixel_to_bmap(bmapSaveSlotOff, bmap_width(bmapSaveSlotOff)-1, i, vPixel);
		}
		bmap_unlock(bmapSaveSlotOff);
	}
	if (bmapSaveSlotOn == NULL) {
		bmapSaveSlotOn = bmap_createblack(MENU_SAVE_SLOT_SIZE_X, MENU_SAVE_SLOT_SIZE_Y, 24);
		bmap_fill(bmapSaveSlotOn, vector(0,0,128), 100);
		vFormat = bmap_lock(bmapSaveSlotOn, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapSaveSlotOn); i++) {
			pixel_to_bmap(bmapSaveSlotOn, i, 0, vPixel);
			pixel_to_bmap(bmapSaveSlotOn, i, bmap_height(bmapSaveSlotOn)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapSaveSlotOn); i++) {
			pixel_to_bmap(bmapSaveSlotOn, 0, i, vPixel);
			pixel_to_bmap(bmapSaveSlotOn, bmap_width(bmapSaveSlotOn)-1, i, vPixel);
		}
		bmap_unlock(bmapSaveSlotOn);
	}
	
	// Create options elements
	if (bmapOptionsChoiceBg == NULL)	 {
		bmapOptionsChoiceBg = bmap_createblack(MENU_BUTTON_SIZE_X * 4 + MENU_BUTTON_GAP * 5, MENU_BUTTON_SIZE_Y + MENU_BUTTON_GAP * 2, 24);
		vFormat = bmap_lock(bmapOptionsChoiceBg, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapOptionsChoiceBg); i++) {
			pixel_to_bmap(bmapOptionsChoiceBg, i, 0, vPixel);
			pixel_to_bmap(bmapOptionsChoiceBg, i, bmap_height(bmapOptionsChoiceBg)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapOptionsChoiceBg); i++) {
			pixel_to_bmap(bmapOptionsChoiceBg, 0, i, vPixel);
			pixel_to_bmap(bmapOptionsChoiceBg, bmap_width(bmapOptionsChoiceBg)-1, i, vPixel);
		}
		bmap_unlock(bmapOptionsChoiceBg);
	}
	
	// Create the background for the options menues
	if (bmapOptionsBg == NULL) {
		// If the define is set to -1, the size of the options choice bar
		// is used to determine the width of the options window.
		if (MENU_OPTIONS_SIZE_X == -1) {
			bmapOptionsBg = bmap_createblack(bmap_width(bmapOptionsChoiceBg), MENU_OPTIONS_SIZE_Y, 24);
		} else {
			bmapOptionsBg = bmap_createblack(MENU_OPTIONS_SIZE_X, MENU_OPTIONS_SIZE_Y, 24);
		}
		vFormat = bmap_lock(bmapOptionsBg, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapOptionsBg); i++) {
			pixel_to_bmap(bmapOptionsBg, i, 0, vPixel);
			pixel_to_bmap(bmapOptionsBg, i, bmap_height(bmapOptionsBg)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapOptionsBg); i++) {
			pixel_to_bmap(bmapOptionsBg, 0, i, vPixel);
			pixel_to_bmap(bmapOptionsBg, bmap_width(bmapOptionsBg)-1, i, vPixel);
		}
		bmap_unlock(bmapOptionsBg);		
	}
	
	// Create Knob and Slider bitmaps
	if (bmapSliderKnob == NULL) {
		bmapSliderKnob = bmap_createblack(15, 15, 24);
		bmap_fill(bmapSliderKnob, vector(0,0,128), 100);
		vFormat = bmap_lock(bmapSliderKnob, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapSliderKnob); i++) {
			pixel_to_bmap(bmapSliderKnob, i, 0, vPixel);
			pixel_to_bmap(bmapSliderKnob, i, bmap_height(bmapSliderKnob)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapSliderKnob); i++) {
			pixel_to_bmap(bmapSliderKnob, 0, i, vPixel);
			pixel_to_bmap(bmapSliderKnob, bmap_width(bmapSliderKnob)-1, i, vPixel);
		}
		bmap_unlock(bmapSliderKnob);		
	}
	
	if (bmapSliderBg == NULL) {
		bmapSliderBg = bmap_createblack(200, 10, 24);
		vFormat = bmap_lock(bmapSliderBg, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapSliderBg); i++) {
			pixel_to_bmap(bmapSliderBg, i, 0, vPixel);
			pixel_to_bmap(bmapSliderBg, i, bmap_height(bmapSliderBg)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapSliderBg); i++) {
			pixel_to_bmap(bmapSliderBg, 0, i, vPixel);
			pixel_to_bmap(bmapSliderBg, bmap_width(bmapSliderBg)-1, i, vPixel);
		}
		bmap_unlock(bmapSliderBg);		
	}
	
	// Checkbox: TODO draw cross instead of other fill color
	if (bmapCheckBoxCheckedOn == NULL) {
		bmapCheckBoxCheckedOn = bmap_createblack(15, 15, 24);
		bmap_fill(bmapCheckBoxCheckedOn, vector(0,0,128), 100);
		vFormat = bmap_lock(bmapCheckBoxCheckedOn, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapCheckBoxCheckedOn); i++) {
			pixel_to_bmap(bmapCheckBoxCheckedOn, i, 0, vPixel);
			pixel_to_bmap(bmapCheckBoxCheckedOn, i, bmap_height(bmapCheckBoxCheckedOn)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapCheckBoxCheckedOn); i++) {
			pixel_to_bmap(bmapCheckBoxCheckedOn, 0, i, vPixel);
			pixel_to_bmap(bmapCheckBoxCheckedOn, bmap_width(bmapCheckBoxCheckedOn)-1, i, vPixel);
		}
		bmap_unlock(bmapCheckBoxCheckedOn);		
	}
	
	if (bmapCheckBoxCheckedOff == NULL) {
		bmapCheckBoxCheckedOff = bmap_createblack(15, 15, 24);
		bmap_fill(bmapCheckBoxCheckedOff, vector(0,0,128), 100);		
		vFormat = bmap_lock(bmapCheckBoxCheckedOff, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapCheckBoxCheckedOff); i++) {
			pixel_to_bmap(bmapCheckBoxCheckedOff, i, 0, vPixel);
			pixel_to_bmap(bmapCheckBoxCheckedOff, i, bmap_height(bmapCheckBoxCheckedOff)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapCheckBoxCheckedOff); i++) {
			pixel_to_bmap(bmapCheckBoxCheckedOff, 0, i, vPixel);
			pixel_to_bmap(bmapCheckBoxCheckedOff, bmap_width(bmapCheckBoxCheckedOff)-1, i, vPixel);
		}
		bmap_unlock(bmapCheckBoxCheckedOff);		
	}
	
	if (bmapCheckBoxUncheckedOn == NULL) {
		bmapCheckBoxUncheckedOn = bmap_createblack(15, 15, 24);
		bmap_fill(bmapCheckBoxUncheckedOn, vector(0,0,128), 100);
		vFormat = bmap_lock(bmapCheckBoxUncheckedOn, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapCheckBoxUncheckedOn); i++) {
			pixel_to_bmap(bmapCheckBoxUncheckedOn, i, 0, vPixel);
			pixel_to_bmap(bmapCheckBoxUncheckedOn, i, bmap_height(bmapCheckBoxUncheckedOn)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapCheckBoxUncheckedOn); i++) {
			pixel_to_bmap(bmapCheckBoxUncheckedOn, 0, i, vPixel);
			pixel_to_bmap(bmapCheckBoxUncheckedOn, bmap_width(bmapCheckBoxUncheckedOn)-1, i, vPixel);
		}
		bmap_unlock(bmapCheckBoxUncheckedOn);		
	}	
	
	if (bmapCheckBoxUncheckedOff == NULL) {
		bmapCheckBoxUncheckedOff = bmap_createblack(15, 15, 24);
		//bmap_fill(bmapCheckBoxUncheckedOff, vector(255,255,255), 100);
		vFormat = bmap_lock(bmapCheckBoxUncheckedOff, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapCheckBoxUncheckedOff); i++) {
			pixel_to_bmap(bmapCheckBoxUncheckedOff, i, 0, vPixel);
			pixel_to_bmap(bmapCheckBoxUncheckedOff, i, bmap_height(bmapCheckBoxUncheckedOff)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapCheckBoxUncheckedOff); i++) {
			pixel_to_bmap(bmapCheckBoxUncheckedOff, 0, i, vPixel);
			pixel_to_bmap(bmapCheckBoxUncheckedOff, bmap_width(bmapCheckBoxUncheckedOff)-1, i, vPixel);
		}
		bmap_unlock(bmapCheckBoxUncheckedOff);		
	}
	
	// Combobox
	if (bmapComboboxOn == NULL) {
		bmapComboboxOn = bmap_createblack(200, 15, 24);
		//bmap_fill(bmapCheckBoxUncheckedOff, vector(255,255,255), 100);
		vFormat = bmap_lock(bmapComboboxOn, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapComboboxOn); i++) {
			pixel_to_bmap(bmapComboboxOn, i, 0, vPixel);
			pixel_to_bmap(bmapComboboxOn, i, bmap_height(bmapComboboxOn)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapComboboxOn); i++) {
			pixel_to_bmap(bmapComboboxOn, 0, i, vPixel);
			pixel_to_bmap(bmapComboboxOn, bmap_width(bmapComboboxOn)-1, i, vPixel);
		}
		bmap_unlock(bmapComboboxOn);		
	}
	
	if (bmapComboboxOff == NULL) {
		bmapComboboxOff = bmap_createblack(200, 15, 24);
		bmap_fill(bmapComboboxOff, vector(0,0,128), 100);
		vFormat = bmap_lock(bmapComboboxOff, 0);
		vPixel = pixel_for_vec(vector(255,255,255), 100, vFormat);
		// Draw Borders
		for (i=0; i<bmap_width(bmapComboboxOff); i++) {
			pixel_to_bmap(bmapComboboxOff, i, 0, vPixel);
			pixel_to_bmap(bmapComboboxOff, i, bmap_height(bmapComboboxOff)-1, vPixel);
		}
		for (i=0; i<bmap_height(bmapComboboxOff); i++) {
			pixel_to_bmap(bmapComboboxOff, 0, i, vPixel);
			pixel_to_bmap(bmapComboboxOff, bmap_width(bmapComboboxOff)-1, i, vPixel);
		}
		bmap_unlock(bmapComboboxOff);		
	}	
		
		
	// Create panels
	// Start menu
	panStartMenu = pan_create("", 10);
	vec_set(panStartMenu.size_x, vector(MENU_BUTTON_SIZE_X + MENU_BUTTON_GAP * 2, MENU_BUTTON_SIZE_Y * 7 + MENU_BUTTON_GAP * 6, 0));
	pan_setbutton(panStartMenu, 0, 0, 0, 0, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // New game
	pan_setbutton(panStartMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 1 + MENU_BUTTON_GAP * 1, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Continue game
	pan_setbutton(panStartMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 2 + MENU_BUTTON_GAP * 2, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Load game
	pan_setbutton(panStartMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 3 + MENU_BUTTON_GAP * 3, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Options
	pan_setbutton(panStartMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 4 + MENU_BUTTON_GAP * 4, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Credits
	pan_setbutton(panStartMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 5 + MENU_BUTTON_GAP * 5, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // To windows
	
	panInGameMenu = pan_create("", 10);
	vec_set(panInGameMenu.size_x, vector(MENU_BUTTON_SIZE_X + MENU_BUTTON_GAP * 4, MENU_BUTTON_SIZE_Y * 5 + MENU_BUTTON_GAP * 4, 0));
	pan_setbutton(panInGameMenu, 0, 0, 0, 0, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Continue
	pan_setbutton(panInGameMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 1 + MENU_BUTTON_GAP * 1, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Load
	pan_setbutton(panInGameMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 2 + MENU_BUTTON_GAP * 2, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Save
	pan_setbutton(panInGameMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 3 + MENU_BUTTON_GAP * 3, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Options
	pan_setbutton(panInGameMenu, 0, 0, 0, MENU_BUTTON_SIZE_Y * 4 + MENU_BUTTON_GAP * 4, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Exit
	
	panSaveMenu = pan_create("", 10);
	vec_set(panSaveMenu.size_x, vector(MENU_SAVE_SLOT_SIZE_X*2 + MENU_BUTTON_GAP * 3, MENU_BUTTON_SIZE_Y * 1 + MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP * 3, 0));
	// 6 Save slots
	pan_setbutton(panSaveMenu, 0, 0, 0, 0, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panSaveMenu, 0, 0, MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP, 0, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panSaveMenu, 0, 0, 0, MENU_SAVE_SLOT_SIZE_Y*1 + MENU_BUTTON_GAP*1, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panSaveMenu, 0, 0, MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP, MENU_SAVE_SLOT_SIZE_Y*1 + MENU_BUTTON_GAP*1, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panSaveMenu, 0, 0, 0, MENU_SAVE_SLOT_SIZE_Y*2 + MENU_BUTTON_GAP*2, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panSaveMenu, 0, 0, MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP, MENU_SAVE_SLOT_SIZE_Y*2 + MENU_BUTTON_GAP*2, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	// Save and Back button
	pan_setbutton(panSaveMenu, 0, 0, 0, MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	pan_setbutton(panSaveMenu, 0, 0, MENU_BUTTON_SIZE_X + MENU_BUTTON_GAP, MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);

	panLoadMenu = pan_create("", 10);
	vec_set(panLoadMenu.size_x, vector(MENU_SAVE_SLOT_SIZE_X*2 + MENU_BUTTON_GAP * 3, MENU_BUTTON_SIZE_Y * 1 + MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP * 3, 0));
	// 6 Save slots
	pan_setbutton(panLoadMenu, 0, 0, 0, 0, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panLoadMenu, 0, 0, MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP, 0, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panLoadMenu, 0, 0, 0, MENU_SAVE_SLOT_SIZE_Y*1 + MENU_BUTTON_GAP*1, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panLoadMenu, 0, 0, MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP, MENU_SAVE_SLOT_SIZE_Y*1 + MENU_BUTTON_GAP*1, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panLoadMenu, 0, 0, 0, MENU_SAVE_SLOT_SIZE_Y*2 + MENU_BUTTON_GAP*2, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	pan_setbutton(panLoadMenu, 0, 0, MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP, MENU_SAVE_SLOT_SIZE_Y*2 + MENU_BUTTON_GAP*2, bmapSaveSlotOn, bmapSaveSlotOff, bmapSaveSlotOn, bmapSaveSlotOff, NULL, NULL, NULL);
	// Save and Back button
	pan_setbutton(panLoadMenu, 0, 0, 0, MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	pan_setbutton(panLoadMenu, 0, 0, MENU_BUTTON_SIZE_X + MENU_BUTTON_GAP, MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	
	
	panOptionsMenu = pan_create("", 10);
	panOptionsMenu.bmap = bmapOptionsChoiceBg;
	// TODO: Should not be necessary!
	vec_set(panOptionsMenu.size_x, vector(bmap_width(bmapOptionsChoiceBg), bmap_height(bmapOptionsChoiceBg), 0));
	pan_setbutton(panOptionsMenu, 0, 4, MENU_BUTTON_GAP, MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	pan_setbutton(panOptionsMenu, 0, 4, MENU_BUTTON_SIZE_X*1 + MENU_BUTTON_GAP * 2, MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	pan_setbutton(panOptionsMenu, 0, 4, MENU_BUTTON_SIZE_X*2 + MENU_BUTTON_GAP * 3, MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	pan_setbutton(panOptionsMenu, 0, 4, MENU_BUTTON_SIZE_X*3 + MENU_BUTTON_GAP * 4, MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL);
	
	// Game Options
	panOptionsGame = pan_create("", 10);
	panOptionsGame.bmap = bmapOptionsBg;
	// TODO: Should not be necessary!
	vec_set(panOptionsGame.size_x, vector(bmap_width(bmapOptionsBg), bmap_height(bmapOptionsBg), 0));
	pan_setbutton(panOptionsGame, 0, 0, bmap_width(bmapOptionsBg) - MENU_BUTTON_SIZE_X - MENU_BUTTON_GAP, bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y - MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Apply
	pan_setbutton(panOptionsGame, 0, 0, MENU_BUTTON_GAP, bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y - MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Back
	pan_setslider(panOptionsGame, 0, 100, MENU_BUTTON_SIZE_Y * 1, bmapSliderBg, bmapSliderKnob, 0, 2, vOptionsDifficulty); // Difficulty
	pan_setbutton(panOptionsGame, 0, 2, 100, MENU_BUTTON_SIZE_Y * 2, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL); // Violence
	pan_setbutton(panOptionsGame, 0, 2, 100, MENU_BUTTON_SIZE_Y * 3, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL); // Dialogs
	pan_setbutton(panOptionsGame, 0, 2, 100, MENU_BUTTON_SIZE_Y * 4, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL); // Hints

	// Graphic Options
	panOptionsGraphics = pan_create("", 10);
	panOptionsGraphics.bmap = bmapOptionsBg;
	// TODO: Should not be necessary!
	vec_set(panOptionsGraphics.size_x, vector(bmap_width(bmapOptionsBg), bmap_height(bmapOptionsBg), 0));
	pan_setbutton(panOptionsGraphics, 0, 0, bmap_width(bmapOptionsBg) - MENU_BUTTON_SIZE_X - MENU_BUTTON_GAP, bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y - MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Apply
	pan_setbutton(panOptionsGraphics, 0, 0, MENU_BUTTON_GAP, bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y - MENU_BUTTON_GAP, bmapMenuButtonOn, bmapMenuButtonOff, bmapMenuButtonOn, bmapMenuButtonOff, NULL, NULL, NULL); // Back

	//pan_setslider(panOptionsGraphics, 0, 100, MENU_BUTTON_SIZE_Y * 1, bmapSliderBg, bmapSliderKnob, 0, 10, vOptionsResolution); // Resolution
	
	// Resolution combobox
	pan_setbutton(panOptionsGraphics, 0, 0, 100, MENU_BUTTON_SIZE_Y * 1, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_show, NULL, NULL);
	
	{
		// Create resolution dropdown
		panOptionsGraphicsResolutionList = pan_create("", 11);
		panOptionsGraphicsResolutionList.size_x = bmap_width(bmapComboboxOn);
		panOptionsGraphicsResolutionList.size_y = bmap_height(bmapComboboxOn)*6;
		pan_setbutton(panOptionsGraphicsResolutionList, 0, 4, 0, 0, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_click, NULL, NULL); // 800x600
		pan_setbutton(panOptionsGraphicsResolutionList, 0, 4, 0, bmap_height(bmapComboboxOn) * 1, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_click, NULL, NULL); // 1024x768
		pan_setbutton(panOptionsGraphicsResolutionList, 0, 4, 0, bmap_height(bmapComboboxOn) * 2, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_click, NULL, NULL); // 1280x1024
		pan_setbutton(panOptionsGraphicsResolutionList, 0, 4, 0, bmap_height(bmapComboboxOn) * 3, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_click, NULL, NULL); // 1400x1050
		pan_setbutton(panOptionsGraphicsResolutionList, 0, 4, 0, bmap_height(bmapComboboxOn) * 4, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_click, NULL, NULL); // 1600x1200
		pan_setbutton(panOptionsGraphicsResolutionList, 0, 4, 0, bmap_height(bmapComboboxOn) * 5, bmapComboboxOff, bmapComboboxOn, bmapComboboxOff, bmapComboboxOn, menu_resolution_click, NULL, NULL); // 1920x1200
	}
	
	pan_setslider(panOptionsGraphics, 0, 100, MENU_BUTTON_SIZE_Y * 3, bmapSliderBg, bmapSliderKnob, 0, 20, vOptionsBrightness); // Brightness
	pan_setbutton(panOptionsGraphics, 0, 2, 100, MENU_BUTTON_SIZE_Y * 4, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL); // Shader
	pan_setbutton(panOptionsGraphics, 0, 2, 100, MENU_BUTTON_SIZE_Y * 5, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL); // Shadows
	
	// Details
	panOptionsGraphicsDetails = pan_create("", 11);
	panOptionsGraphicsDetails.size_x = 160;
	panOptionsGraphicsDetails.size_y = 15;
	pan_setbutton(panOptionsGraphicsDetails, 0, 4, 0, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);
	pan_setbutton(panOptionsGraphicsDetails, 0, 4, 80, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);
	pan_setbutton(panOptionsGraphicsDetails, 0, 4, 160, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);

	
	// Antialiasing
	panOptionsGraphicsAntiAliasing = pan_create("", 11);
	panOptionsGraphicsAntiAliasing.size_x = 160;
	panOptionsGraphicsAntiAliasing.size_y = 15;
	pan_setbutton(panOptionsGraphicsAntiAliasing, 0, 4, 0, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);
	pan_setbutton(panOptionsGraphicsAntiAliasing, 0, 4, 50, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);
	pan_setbutton(panOptionsGraphicsAntiAliasing, 0, 4, 100, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);
	pan_setbutton(panOptionsGraphicsAntiAliasing, 0, 4, 150, 0, bmapCheckBoxCheckedOff, bmapCheckBoxUncheckedOff, bmapCheckBoxCheckedOn, bmapCheckBoxUncheckedOn, NULL, NULL, NULL);
	
	
	
/*PANEL* panOptionsAudio			= NULL;
PANEL* panOptionsInput			= NULL;*/
		
	// Create texts
	txtMenuNewGame							= txt_create(1, 11);
	txtMenuContinueGame					= txt_create(1, 11);
	txtMenuLoadGame						= txt_create(1, 11);
	txtMenuSaveGame						= txt_create(1, 11);
	txtMenuOptions							= txt_create(1, 11);
	txtMenuOptionsGame					= txt_create(1, 11);
	txtMenuOptionsGraphics				= txt_create(1, 11);
	txtMenuOptionsAudio					= txt_create(1, 11);
	txtMenuOptionsInput					= txt_create(1, 11);
	txtMenuOptionsApply					= txt_create(1, 11);
	txtMenuDifficulty						= txt_create(1, 11);
	txtMenuViolence						= txt_create(1, 11);
	txtMenuShowDialogs					= txt_create(1, 11);
	txtMenuShowHints						= txt_create(1, 11);
	txtMenuResolutions					= txt_create(1, 11);
	txtMenuAntialias						= txt_create(1, 11);
	txtMenuBrightness						= txt_create(1, 11);
	txtMenuShader							= txt_create(1, 11);
	txtMenuShadows							= txt_create(1, 11);
	txtMenuDetails							= txt_create(1, 11);
	txtMenuCredits							= txt_create(1, 11);
	txtMenuExitGame						= txt_create(1, 11);
	txtMenuReturnToWin					= txt_create(1, 11);
	txtMenuBack								= txt_create(1, 11);
	txtOptionsGraphicsDetailsLow		= txt_create(1, 11);
	txtOptionsGraphicsDetailsMedium	= txt_create(1, 11);
	txtOptionsGraphicsDetailsHigh		= txt_create(1, 11);
	txtOptionsGraphicsAAOff				= txt_create(1, 11);
	txtOptionsGraphicsAA1x				= txt_create(1, 11);
	txtOptionsGraphicsAA4x				= txt_create(1, 11);
	txtOptionsGraphicsAA9x				= txt_create(1, 11);	
	
	txtResCurrent							= txt_create(1, 11);
	txtRes800x600							= txt_create(1, 12);	
	txtRes1024x768							= txt_create(1, 12);	
	txtRes1280x1024						= txt_create(1, 12);	
	txtRes1400x1050						= txt_create(1, 12);	
	txtRes1600x1200						= txt_create(1, 12);	
	txtRes1920x1200						= txt_create(1, 12);	
	
	txtMenuSaveGameTitles = sys_malloc(sizeof(TEXT*)*6);
	for(i=0; i<6; i++) {
		txtMenuSaveGameTitles[i] = txt_create(1, 11);
		str_cpy((txtMenuSaveGameTitles[i].pstring)[0], "Empty");
		set(txtMenuSaveGameTitles[i], CENTER_X | CENTER_Y | OUTLINE);
	}

	str_cpy((txtMenuNewGame.pstring)[0], "New game");
	str_cpy((txtMenuContinueGame.pstring)[0], "Continue");
	str_cpy((txtMenuLoadGame.pstring)[0], "Load game");
	str_cpy((txtMenuSaveGame.pstring)[0], "Save Game");
	str_cpy((txtMenuOptions.pstring)[0], "Options");
	str_cpy((txtMenuOptionsGame.pstring)[0], "Game"); // Game Options
	{
		str_cpy((txtMenuDifficulty.pstring)[0], "Difficulty:");
		str_cpy((txtMenuViolence.pstring)[0], "Show blood:");
		str_cpy((txtMenuShowDialogs.pstring)[0], "Show dialogs:");
		str_cpy((txtMenuShowHints.pstring)[0], "Show Hints:");
	}
	str_cpy((txtMenuOptionsGraphics.pstring)[0], "Graphics");
	{
		str_cpy((txtMenuResolutions.pstring)[0], "Resolution:"); // Resolution
		{
			str_cpy((txtResCurrent.pstring)[0], "Current res");
			str_cpy((txtRes800x600.pstring)[0], "800x600");
			str_cpy((txtRes1024x768.pstring)[0], "1024x768");
			str_cpy((txtRes1280x1024.pstring)[0], "1280x1024");
			str_cpy((txtRes1400x1050.pstring)[0], "1400x1050");
			str_cpy((txtRes1600x1200.pstring)[0], "1600x1200");
			str_cpy((txtRes1920x1200.pstring)[0], "1920x1200");
		}
		str_cpy((txtMenuAntialias.pstring)[0], "Anti aliasing:"); // AntiAliasing
		{
			str_cpy((txtOptionsGraphicsAAOff.pstring)[0], "Off");
			str_cpy((txtOptionsGraphicsAA1x.pstring)[0], "1x");
			str_cpy((txtOptionsGraphicsAA4x.pstring)[0], "4x");
			str_cpy((txtOptionsGraphicsAA9x.pstring)[0], "9x");
		}
		str_cpy((txtMenuBrightness.pstring)[0], "Brightness:");
		str_cpy((txtMenuShader.pstring)[0], "Shader:");
		str_cpy((txtMenuShadows.pstring)[0], "Shadows:");
		str_cpy((txtMenuDetails.pstring)[0], "Details:"); // Details
		{
			str_cpy((txtOptionsGraphicsDetailsLow.pstring)[0], "Low");
			str_cpy((txtOptionsGraphicsDetailsMedium.pstring)[0], "Medium");
			str_cpy((txtOptionsGraphicsDetailsHigh.pstring)[0], "High");
		}
	}
	str_cpy((txtMenuOptionsAudio.pstring)[0], "Audio");
	str_cpy((txtMenuOptionsInput.pstring)[0], "Keyboard & Mouse");
	str_cpy((txtMenuOptionsApply.pstring)[0], "Apply");
	str_cpy((txtMenuCredits.pstring)[0], "Credits");
	str_cpy((txtMenuExitGame.pstring)[0], "Exit game");
	str_cpy((txtMenuReturnToWin.pstring)[0], "Return to windows");
	str_cpy((txtMenuBack.pstring)[0], "Back");
	
	wait(1); // Needed so that center_x and center_y work
	
	set(txtMenuNewGame, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuContinueGame, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuLoadGame, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuSaveGame, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuOptions, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuOptionsGame, CENTER_X | CENTER_Y | OUTLINE);
	{
		set(txtMenuDifficulty, OUTLINE);
		set(txtMenuViolence, OUTLINE);
		set(txtMenuShowDialogs, OUTLINE);
		set(txtMenuShowHints, OUTLINE);
	}
	set(txtMenuOptionsGraphics, CENTER_X | CENTER_Y | OUTLINE);
	{
		set(txtMenuResolutions, OUTLINE);
		{
			set(txtResCurrent, CENTER_X | CENTER_Y | OUTLINE);
			set(txtRes800x600, CENTER_X | CENTER_Y | OUTLINE);
			set(txtRes1024x768, CENTER_X | CENTER_Y | OUTLINE);
			set(txtRes1280x1024, CENTER_X | CENTER_Y | OUTLINE);
			set(txtRes1400x1050, CENTER_X | CENTER_Y | OUTLINE);
			set(txtRes1600x1200, CENTER_X | CENTER_Y | OUTLINE);
			set(txtRes1920x1200, CENTER_X | CENTER_Y | OUTLINE);
		}
		set(txtMenuAntialias, OUTLINE);
		{
			set(txtOptionsGraphicsAAOff, OUTLINE);
			set(txtOptionsGraphicsAA1x, OUTLINE);
			set(txtOptionsGraphicsAA4x, OUTLINE);
			set(txtOptionsGraphicsAA9x, OUTLINE);
		}
		set(txtMenuBrightness, OUTLINE);
		set(txtMenuShader, OUTLINE);
		set(txtMenuShadows, OUTLINE);
		set(txtMenuDetails, OUTLINE);
		{
			set(txtOptionsGraphicsDetailsLow, OUTLINE);
			set(txtOptionsGraphicsDetailsMedium, OUTLINE);
			set(txtOptionsGraphicsDetailsHigh, OUTLINE);
		}
	}
	set(txtMenuOptionsAudio, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuOptionsInput, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuOptionsApply, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuCredits, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuExitGame, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuReturnToWin, CENTER_X | CENTER_Y | OUTLINE);
	set(txtMenuBack, CENTER_X | CENTER_Y | OUTLINE);
	
	
	menu_center();
}

void menu_show(int _menu) {
	//if (panStartMenu == NULL) return;

	int i;
	// Hide all open menus
	menu_hide();
		
	switch (_menu) {
		case MENU_START:
			nCurrentMenu = MENU_START;
			set(panStartMenu, SHOW);
			set(txtMenuNewGame, SHOW);
			// Only if there are save games!
			set(txtMenuContinueGame, SHOW);
			set(txtMenuLoadGame, SHOW);
			set(txtMenuOptions, SHOW);
			set(txtMenuCredits, SHOW);
			set(txtMenuReturnToWin, SHOW);
		break;
		case MENU_IN_GAME:
			nCurrentMenu = MENU_IN_GAME;
			set(panInGameMenu, SHOW);
			set(txtMenuContinueGame, SHOW);
			set(txtMenuLoadGame, SHOW);
			set(txtMenuSaveGame, SHOW);
			set(txtMenuOptions, SHOW);
			set(txtMenuExitGame, SHOW);
		break;
		case MENU_SAVE:
			nCurrentMenu = MENU_SAVE;
			set(panSaveMenu, SHOW);
			set(txtMenuSaveGame, SHOW);
			for(i=0; i<6; i++) {
				set(txtMenuSaveGameTitles[i], SHOW);
			}
			set(txtMenuBack, SHOW);
		break;
		case MENU_LOAD:
			nCurrentMenu = MENU_LOAD;
			set(panLoadMenu, SHOW);
			set(txtMenuLoadGame, SHOW);
			for(i=0; i<6; i++) {
				set(txtMenuSaveGameTitles[i], SHOW);
			}
			set(txtMenuBack, SHOW);
		break;
		case MENU_OPTIONS_GAME:
			nCurrentMenu = MENU_OPTIONS_GAME;
			set(panOptionsMenu, SHOW);
			set(panOptionsGame, SHOW);
			set(txtMenuOptionsGame, SHOW);
			set(txtMenuOptionsGraphics, SHOW);
			set(txtMenuOptionsAudio, SHOW);
			set(txtMenuOptionsInput, SHOW);
			set(txtMenuOptionsApply, SHOW);
			set(txtMenuBack, SHOW);
			// Set game button to be checked
			button_state(panOptionsMenu, 1, 1);
			
			set(txtMenuDifficulty, SHOW);
			set(txtMenuViolence, SHOW);
			set(txtMenuShowDialogs, SHOW);
			set(txtMenuShowHints, SHOW);
		break;
		case MENU_OPTIONS_GRAPHICS:
			nCurrentMenu = MENU_OPTIONS_GRAPHICS;
			set(panOptionsMenu, SHOW);
			set(panOptionsGraphics, SHOW);
			set(txtMenuOptionsGame, SHOW);
			set(txtMenuOptionsGraphics, SHOW);
			set(txtMenuOptionsAudio, SHOW);
			set(txtMenuOptionsInput, SHOW);
			set(txtMenuOptionsApply, SHOW);
			set(txtMenuBack, SHOW);

			// Set graphics button to be checked
			button_state(panOptionsMenu, 2, 1);			
			set(txtMenuResolutions, SHOW);
			set(txtMenuAntialias, SHOW);
			{
				set(txtOptionsGraphicsAAOff, SHOW);
				set(txtOptionsGraphicsAA1x, SHOW);
				set(txtOptionsGraphicsAA4x, SHOW);
				set(txtOptionsGraphicsAA9x, SHOW);
				switch(d3d_antialias) {
					case 0: button_state(panOptionsGraphicsAntiAliasing, 1, 1); break;
					case 1: button_state(panOptionsGraphicsAntiAliasing, 2, 1); break;
					case 4: button_state(panOptionsGraphicsAntiAliasing, 3, 1); break;
					case 9: button_state(panOptionsGraphicsAntiAliasing, 4, 1); break;
				}
			}
			set(txtMenuBrightness, SHOW);
			set(txtMenuShader, SHOW);
			set(txtMenuShadows, SHOW);
			set(txtMenuDetails, SHOW);
			{
				set(txtOptionsGraphicsDetailsLow, SHOW);
				set(txtOptionsGraphicsDetailsMedium, SHOW);
				set(txtOptionsGraphicsDetailsHigh, SHOW);
			}
			set(panOptionsGraphicsDetails, SHOW);
			set(panOptionsGraphicsAntiAliasing, SHOW);
			set(txtResCurrent, SHOW);
			switch(video_mode) {
				case 7: str_cpy((txtResCurrent.pstring)[0], "800x600"); button_state(panOptionsGraphicsResolutionList, 1,1); break;
				case 8: str_cpy((txtResCurrent.pstring)[0], "1024x768"); button_state(panOptionsGraphicsResolutionList, 2,1); break;
				case 9: str_cpy((txtResCurrent.pstring)[0], "1280x1024"); button_state(panOptionsGraphicsResolutionList, 3,1); break;
				case 10: str_cpy((txtResCurrent.pstring)[0], "1400x1050"); button_state(panOptionsGraphicsResolutionList, 4,1); break;
				case 11: str_cpy((txtResCurrent.pstring)[0], "1600x1200"); button_state(panOptionsGraphicsResolutionList, 5,1); break;
				case 12: str_cpy((txtResCurrent.pstring)[0], "1920x1200"); button_state(panOptionsGraphicsResolutionList, 6,1); break;
			}
		break;		
	}
	
	nMenuVisible = 1;
	
	menu_align(_menu);
}

void menu_hide() {
	
	nMenuVisible = 0;
	
	if (panStartMenu != NULL) reset(panStartMenu, SHOW);
	if (panInGameMenu != NULL) reset(panInGameMenu, SHOW);
	if (panSaveMenu != NULL) reset(panSaveMenu, SHOW);
	if (panOptionsMenu != NULL) reset(panOptionsMenu, SHOW);
	if (panOptionsGame != NULL) reset(panOptionsGame, SHOW);
	if (panOptionsGraphics != NULL) reset(panOptionsGraphics, SHOW);
	if (panOptionsAudio != NULL) reset(panOptionsAudio, SHOW);
	if (panOptionsInput != NULL) reset(panOptionsInput, SHOW);
	if (txtMenuOptionsGame != NULL) reset(txtMenuOptionsGame, SHOW);
	if (txtMenuDifficulty != NULL) reset(txtMenuDifficulty, SHOW);
	if (txtMenuViolence != NULL) reset(txtMenuViolence, SHOW);
	if (txtMenuShowDialogs != NULL) reset(txtMenuShowDialogs, SHOW);
	if (txtMenuShowHints != NULL) reset(txtMenuShowHints, SHOW);
	if (txtMenuOptionsGraphics != NULL) reset(txtMenuOptionsGraphics, SHOW);
	if (txtMenuDetails != NULL) reset(txtMenuDetails, SHOW);
	if (txtMenuShadows != NULL) reset(txtMenuShadows, SHOW);
	if (txtMenuShader != NULL) reset(txtMenuShader, SHOW);
	if (txtMenuBrightness != NULL) reset(txtMenuBrightness, SHOW);
	if (txtMenuAntialias != NULL) reset(txtMenuAntialias, SHOW);
	if (txtMenuResolutions != NULL) reset(txtMenuResolutions, SHOW);
	if (txtMenuOptionsAudio != NULL) reset(txtMenuOptionsAudio, SHOW);
	if (txtMenuOptionsInput != NULL) reset(txtMenuOptionsInput, SHOW);
	if (txtMenuNewGame != NULL) reset(txtMenuNewGame, SHOW);
	if (txtMenuContinueGame != NULL) reset(txtMenuContinueGame, SHOW);
	if (txtMenuLoadGame != NULL) reset(txtMenuLoadGame, SHOW);
	if (txtMenuSaveGame != NULL) reset(txtMenuSaveGame, SHOW);
	if (txtMenuOptions != NULL) reset(txtMenuOptions, SHOW);
	if (txtMenuOptionsApply != NULL) reset(txtMenuOptionsApply, SHOW);
	if (txtMenuCredits != NULL) reset(txtMenuCredits, SHOW);
	if (txtMenuExitGame != NULL) reset(txtMenuExitGame, SHOW);
	if (txtMenuReturnToWin != NULL) reset(txtMenuReturnToWin, SHOW);	
	if (txtMenuBack != NULL) reset(txtMenuBack, SHOW);
	if (panOptionsGraphicsDetails != NULL) reset(panOptionsGraphicsDetails, SHOW);
	if (panOptionsGraphicsAntiAliasing != NULL) reset(panOptionsGraphicsAntiAliasing, SHOW);
	if (txtOptionsGraphicsAAOff != NULL) reset(txtOptionsGraphicsAAOff, SHOW);
	if (txtOptionsGraphicsAA1x != NULL) reset(txtOptionsGraphicsAA1x, SHOW);
	if (txtOptionsGraphicsAA4x != NULL) reset(txtOptionsGraphicsAA4x, SHOW);
	if (txtOptionsGraphicsAA9x != NULL) reset(txtOptionsGraphicsAA9x, SHOW);
	if (txtOptionsGraphicsDetailsLow != NULL) reset(txtOptionsGraphicsDetailsLow, SHOW);
	if (txtOptionsGraphicsDetailsMedium != NULL) reset(txtOptionsGraphicsDetailsMedium, SHOW);
	if (txtOptionsGraphicsDetailsHigh != NULL) reset(txtOptionsGraphicsDetailsHigh, SHOW);
	if (panOptionsGraphicsResolutionList != NULL) reset(panOptionsGraphicsResolutionList, SHOW);
	if (txtResCurrent != NULL) reset(txtResCurrent, SHOW);
	if (txtRes800x600 != NULL) reset(txtRes800x600, SHOW);
	if (txtRes1024x768 != NULL) reset(txtRes1024x768, SHOW);
	if (txtRes1280x1024 != NULL) reset(txtRes1280x1024, SHOW);
	if (txtRes1400x1050 != NULL) reset(txtRes1400x1050, SHOW);
	if (txtRes1600x1200 != NULL) reset(txtRes1600x1200, SHOW);
	if (txtRes1920x1200 != NULL) reset(txtRes1920x1200, SHOW);

	int i;
	for(i=0; i<6; i++) {
		if (txtMenuSaveGameTitles[i] != NULL) {
			reset(txtMenuSaveGameTitles[i], SHOW);
		}
	}
}

int menu_is_visible() {
	return nMenuVisible;
}

void menu_align(int _menu) {
	if (panStartMenu == NULL) return;
	
	int i;
	
	switch(_menu) {
		case MENU_START:
			txtMenuNewGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuNewGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y / 2;
			
			// Only if there are save games!
			txtMenuContinueGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuContinueGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 1 + MENU_BUTTON_GAP * 1 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuLoadGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuLoadGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 2 + MENU_BUTTON_GAP * 2 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuOptions.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptions.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 3 + MENU_BUTTON_GAP * 3 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuCredits.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuCredits.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 4 + MENU_BUTTON_GAP * 4 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuReturnToWin.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuReturnToWin.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 5 + MENU_BUTTON_GAP * 5 + MENU_BUTTON_SIZE_Y / 2;
		break;
		case MENU_IN_GAME:
			txtMenuContinueGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuContinueGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuLoadGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuLoadGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 1 + MENU_BUTTON_GAP * 1 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuSaveGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuSaveGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 2 + MENU_BUTTON_GAP * 2 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuOptions.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptions.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 3 + MENU_BUTTON_GAP * 3 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuExitGame.pos_x = panStartMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuExitGame.pos_y = panStartMenu.pos_y + MENU_BUTTON_SIZE_Y * 4 + MENU_BUTTON_GAP * 4 + MENU_BUTTON_SIZE_Y / 2;								
		break;
		case MENU_SAVE:
			i = 0;
			for(i=0; i<3; i++) {
				txtMenuSaveGameTitles[i].pos_x = panSaveMenu.pos_x + MENU_SAVE_SLOT_SIZE_X / 2;
				txtMenuSaveGameTitles[i].pos_y = panSaveMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y * i + MENU_BUTTON_GAP * i + MENU_BUTTON_SIZE_Y / 2;
			}
			for(i=3; i<6; i++) {
				txtMenuSaveGameTitles[i].pos_x = panSaveMenu.pos_x + MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP + MENU_SAVE_SLOT_SIZE_X / 2;
				txtMenuSaveGameTitles[i].pos_y = panSaveMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y * (i-3) + MENU_BUTTON_GAP * (i-3) + MENU_BUTTON_SIZE_Y / 2;
			}
			
			txtMenuBack.pos_x = panSaveMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuBack.pos_y = panSaveMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuSaveGame.pos_x = panSaveMenu.pos_x + MENU_BUTTON_SIZE_X + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_X / 2;
			txtMenuSaveGame.pos_y = panSaveMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3 + MENU_BUTTON_SIZE_Y / 2;
		break;
		case MENU_LOAD:
			i = 0;
			for(i=0; i<3; i++) {
				txtMenuSaveGameTitles[i].pos_x = panLoadMenu.pos_x + MENU_SAVE_SLOT_SIZE_X / 2;
				txtMenuSaveGameTitles[i].pos_y = panLoadMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y * i + MENU_BUTTON_GAP * i + MENU_BUTTON_SIZE_Y / 2;
			}
			for(i=3; i<6; i++) {
				txtMenuSaveGameTitles[i].pos_x = panLoadMenu.pos_x + MENU_SAVE_SLOT_SIZE_X + MENU_BUTTON_GAP + MENU_SAVE_SLOT_SIZE_X / 2;
				txtMenuSaveGameTitles[i].pos_y = panLoadMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y * (i-3) + MENU_BUTTON_GAP * (i-3) + MENU_BUTTON_SIZE_Y / 2;
			}
			
			txtMenuBack.pos_x = panLoadMenu.pos_x + MENU_BUTTON_SIZE_X / 2;
			txtMenuBack.pos_y = panLoadMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3 + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuLoadGame.pos_x = panLoadMenu.pos_x + MENU_BUTTON_SIZE_X + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_X / 2;
			txtMenuLoadGame.pos_y = panLoadMenu.pos_y + MENU_SAVE_SLOT_SIZE_Y*3 + MENU_BUTTON_GAP*3 + MENU_BUTTON_SIZE_Y / 2;
		break;
		case MENU_OPTIONS_GAME:
			panOptionsGame.pos_x = panOptionsMenu.pos_x;
			panOptionsGame.pos_y = panOptionsMenu.pos_y + panOptionsMenu.size_y + MENU_BUTTON_GAP;
			
			txtMenuOptionsGame.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsGame.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuOptionsGraphics.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_SIZE_X*1 + MENU_BUTTON_GAP * 2 + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsGraphics.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
		
			txtMenuOptionsAudio.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_SIZE_X*2 + MENU_BUTTON_GAP * 3 + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsAudio.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
		
			txtMenuOptionsInput.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_SIZE_X*3 + MENU_BUTTON_GAP * 4 + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsInput.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuOptionsApply.pos_x = panOptionsGame.pos_x + bmap_width(bmapOptionsBg) - MENU_BUTTON_SIZE_X / 2 - MENU_BUTTON_GAP;
			txtMenuOptionsApply.pos_y = panOptionsGame.pos_y + bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y / 2 - MENU_BUTTON_GAP;
			
			txtMenuBack.pos_x = panOptionsGame.pos_x + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_X / 2;
			txtMenuBack.pos_y = panOptionsGame.pos_y + bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y / 2 - MENU_BUTTON_GAP; 
			
			txtMenuDifficulty.pos_x = panOptionsGame.pos_x + 10;
			txtMenuDifficulty.pos_y = panOptionsGame.pos_y + MENU_BUTTON_SIZE_Y * 1.1;
			
			txtMenuViolence.pos_x = panOptionsGame.pos_x + 10;
			txtMenuViolence.pos_y =panOptionsGame.pos_y + MENU_BUTTON_SIZE_Y * 2.1;
			
			txtMenuShowDialogs.pos_x = panOptionsGame.pos_x + 10;
			txtMenuShowDialogs.pos_y = panOptionsGame.pos_y + MENU_BUTTON_SIZE_Y * 3.1;
			
			txtMenuShowHints.pos_x = panOptionsGame.pos_x + 10;
			txtMenuShowHints.pos_y = panOptionsGame.pos_y + MENU_BUTTON_SIZE_Y * 4.1;
		break;
		case MENU_OPTIONS_GRAPHICS:
			panOptionsGraphics.pos_x = panOptionsMenu.pos_x;
			panOptionsGraphics.pos_y = panOptionsMenu.pos_y + panOptionsMenu.size_y + MENU_BUTTON_GAP;
			
			txtMenuOptionsGame.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsGame.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuOptionsGraphics.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_SIZE_X*1 + MENU_BUTTON_GAP * 2 + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsGraphics.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
		
			txtMenuOptionsAudio.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_SIZE_X*2 + MENU_BUTTON_GAP * 3 + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsAudio.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
		
			txtMenuOptionsInput.pos_x = panOptionsMenu.pos_x + MENU_BUTTON_SIZE_X*3 + MENU_BUTTON_GAP * 4 + MENU_BUTTON_SIZE_X / 2;
			txtMenuOptionsInput.pos_y = panOptionsMenu.pos_y + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_Y / 2;
			
			txtMenuOptionsApply.pos_x = panOptionsGraphics.pos_x + bmap_width(bmapOptionsBg) - MENU_BUTTON_SIZE_X / 2 - MENU_BUTTON_GAP;
			txtMenuOptionsApply.pos_y = panOptionsGraphics.pos_y + bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y / 2 - MENU_BUTTON_GAP;
			
			txtMenuBack.pos_x = panOptionsGraphics.pos_x + MENU_BUTTON_GAP + MENU_BUTTON_SIZE_X / 2;
			txtMenuBack.pos_y = panOptionsGraphics.pos_y + bmap_height(bmapOptionsBg) - MENU_BUTTON_SIZE_Y / 2 - MENU_BUTTON_GAP;
			
			txtMenuResolutions.pos_x = panOptionsGraphics.pos_x + 10;
			txtMenuResolutions.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 1.1;
			{
				panOptionsGraphicsResolutionList.pos_x = panOptionsGraphics.pos_x + 100;
				panOptionsGraphicsResolutionList.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 1 + bmap_height(bmapComboboxOn);
				
				txtResCurrent.pos_x = panOptionsGraphics.pos_x + 100 + bmap_width(bmapComboboxOn) / 2;
				txtResCurrent.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 1 + bmap_height(bmapComboboxOn) / 2; // TODO
				
				txtRes800x600.pos_x = panOptionsGraphicsResolutionList.pos_x + bmap_width(bmapComboboxOn) / 2;
				txtRes800x600.pos_y = panOptionsGraphicsResolutionList.pos_y + bmap_height(bmapComboboxOn) * 0.5;
				
				txtRes1024x768.pos_x = panOptionsGraphicsResolutionList.pos_x + bmap_width(bmapComboboxOn) / 2;
				txtRes1024x768.pos_y = panOptionsGraphicsResolutionList.pos_y + bmap_height(bmapComboboxOn) * 1.5;
				
				txtRes1280x1024.pos_x = panOptionsGraphicsResolutionList.pos_x + bmap_width(bmapComboboxOn) / 2;
				txtRes1280x1024.pos_y = panOptionsGraphicsResolutionList.pos_y + bmap_height(bmapComboboxOn) * 2.5;
				
				txtRes1400x1050.pos_x = panOptionsGraphicsResolutionList.pos_x + bmap_width(bmapComboboxOn) / 2;
				txtRes1400x1050.pos_y = panOptionsGraphicsResolutionList.pos_y + bmap_height(bmapComboboxOn) * 3.5;
				
				txtRes1600x1200.pos_x = panOptionsGraphicsResolutionList.pos_x + bmap_width(bmapComboboxOn) / 2;
				txtRes1600x1200.pos_y = panOptionsGraphicsResolutionList.pos_y + bmap_height(bmapComboboxOn) * 4.5;
				
				txtRes1920x1200.pos_x = panOptionsGraphicsResolutionList.pos_x + bmap_width(bmapComboboxOn) / 2;
				txtRes1920x1200.pos_y = panOptionsGraphicsResolutionList.pos_y + bmap_height(bmapComboboxOn) * 5.5;
			}
			
			txtMenuAntialias.pos_x = panOptionsGraphics.pos_x + 10;
			txtMenuAntialias.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 2.1;
			
			txtMenuBrightness.pos_x = panOptionsGraphics.pos_x + 10;
			txtMenuBrightness.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 3.1;
			
			txtMenuShader.pos_x = panOptionsGraphics.pos_x + 10;
			txtMenuShader.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 4.1;
			
			txtMenuShadows.pos_x = panOptionsGraphics.pos_x + 10;
			txtMenuShadows.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 5.1;
			
			txtMenuDetails.pos_x = panOptionsGraphics.pos_x + 10;
			txtMenuDetails.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 6.1;
			
			panOptionsGraphicsDetails.pos_x = panOptionsGraphics.pos_x + 100;
			panOptionsGraphicsDetails.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 6;
			{
				txtOptionsGraphicsDetailsLow.pos_x = panOptionsGraphicsDetails.pos_x + 20;	
				txtOptionsGraphicsDetailsLow.pos_y = panOptionsGraphicsDetails.pos_y;
				
				txtOptionsGraphicsDetailsMedium.pos_x = panOptionsGraphicsDetails.pos_x + 100;
				txtOptionsGraphicsDetailsMedium.pos_y = panOptionsGraphicsDetails.pos_y;
				
				txtOptionsGraphicsDetailsHigh.pos_x = panOptionsGraphicsDetails.pos_x + 180; 
				txtOptionsGraphicsDetailsHigh.pos_y = panOptionsGraphicsDetails.pos_y;
			}				
			
			panOptionsGraphicsAntiAliasing.pos_x = panOptionsGraphics.pos_x + 100; 
			panOptionsGraphicsAntiAliasing.pos_y = panOptionsGraphics.pos_y + MENU_BUTTON_SIZE_Y * 2;
			{
				txtOptionsGraphicsAAOff.pos_x = panOptionsGraphicsAntiAliasing.pos_x + 20;
				txtOptionsGraphicsAAOff.pos_y = panOptionsGraphicsAntiAliasing.pos_y;
				
				txtOptionsGraphicsAA1x.pos_x = panOptionsGraphicsAntiAliasing.pos_x + 70;
				txtOptionsGraphicsAA1x.pos_y = panOptionsGraphicsAntiAliasing.pos_y;
				
				txtOptionsGraphicsAA4x.pos_x = panOptionsGraphicsAntiAliasing.pos_x + 120;
				txtOptionsGraphicsAA4x.pos_y = panOptionsGraphicsAntiAliasing.pos_y;
				
				txtOptionsGraphicsAA9x.pos_x = panOptionsGraphicsAntiAliasing.pos_x + 170;
				txtOptionsGraphicsAA9x.pos_y = panOptionsGraphicsAntiAliasing.pos_y;												
			}
		break;
	}
}

void menu_center() {
	if (panStartMenu != NULL) {
		panStartMenu.pos_x = screen_size.x / 2 - panStartMenu.size_x / 2;
		panStartMenu.pos_y = screen_size.y / 2 - panStartMenu.size_y / 2;	
		panInGameMenu.pos_x = screen_size.x / 2 - panStartMenu.size_x / 2;
		panInGameMenu.pos_y = screen_size.y / 2 - panStartMenu.size_y / 2;
		panSaveMenu.pos_x = screen_size.x / 2 - panSaveMenu.size_x / 2;
		panSaveMenu.pos_y = screen_size.y / 2 - panSaveMenu.size_y / 2;
		panLoadMenu.pos_x = screen_size.x / 2 - panSaveMenu.size_x / 2;
		panLoadMenu.pos_y = screen_size.y / 2 - panSaveMenu.size_y / 2;
		panOptionsMenu.pos_x = screen_size.x / 2 - panOptionsMenu.size_x / 2;
		panOptionsMenu.pos_y = 30;	
		menu_align(nCurrentMenu);
	}
}

void menu_set_pos(int _x, int _y) {
	if (panStartMenu != NULL) {
		panStartMenu.pos_x = _x;
		panStartMenu.pos_y = _y;
		panInGameMenu.pos_x = _x;
		panInGameMenu.pos_y = _x;
		panSaveMenu.pos_x = _x;
		panSaveMenu.pos_y = _y;
		panLoadMenu.pos_x = _x;
		panLoadMenu.pos_y = _y;	
		panOptionsMenu.pos_x = _x;
		panOptionsMenu.pos_y = _y;	
		menu_align(nCurrentMenu);
	}	
}

void menu_show_message(STRING* _msg) {
	
}

void menu_show_message_fullscreen(STRING* _msg) {
	
}

int menu_show_choice_message(STRING* _msg, STRING* _button1, STRING* _button2) {
	
}

// Internal functions
void menu_resolution_show() {
	if(is(panOptionsGraphicsResolutionList, SHOW)) {
		// Hide resolution list
		reset(panOptionsGraphicsResolutionList, SHOW);
		reset(txtRes800x600, SHOW);
		reset(txtRes1024x768, SHOW);
		reset(txtRes1280x1024, SHOW);
		reset(txtRes1400x1050, SHOW);
		reset(txtRes1600x1200, SHOW);
		reset(txtRes1920x1200, SHOW);			
	} else {
		// Show resolution list
		set(panOptionsGraphicsResolutionList, SHOW);
		set(txtRes800x600, SHOW);
		set(txtRes1024x768, SHOW);
		set(txtRes1280x1024, SHOW);
		set(txtRes1400x1050, SHOW);
		set(txtRes1600x1200, SHOW);
		set(txtRes1920x1200, SHOW);	
	}
}

void menu_resolution_click(var _button_number, PANEL* _panel) {
	// Hide resolution list
	reset(panOptionsGraphicsResolutionList, SHOW);
	reset(txtRes800x600, SHOW);
	reset(txtRes1024x768, SHOW);
	reset(txtRes1280x1024, SHOW);
	reset(txtRes1400x1050, SHOW);
	reset(txtRes1600x1200, SHOW);
	reset(txtRes1920x1200, SHOW);	
}
