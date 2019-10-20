/**  @file   update_display.h
     @author Shivin Gaba , Anzac Morel
     @date   13 October 2019
     @brief This module implements the methods used to display various
     information on the LED matrix.

*/


#ifndef UPDATE_DISPLAY_H
#define UPDATE_DISPLAY_H

#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"


void display_character (char character);

void display_result (char print_text, int wins, int losses);

void display_score(int score);

void change_display (int count);


#endif
