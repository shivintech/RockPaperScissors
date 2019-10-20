/**  @file   navswitch_controller.c
     @author Shivin Gaba, Anzac Morel
     @date   13 October 2019
     @brief  This module contains the implmentation of the navswitch methods.


*/

#include "navswitch.h"

/**
 *   This function changes the character currently displayed on the LED
 *   matrix when the navswitch is pressed upwards.
     @param displayed_character The current character displayed on the
     LED matrix.
     @return displayed_character The next character displayed in order.
*/

char navswitch_up (char character)
{
    if (character == 'P') {
        character = 'S';
    } else if (character == 'S') {
        character = 'R';
    } else {
        character = 'P';
    }
    return character;
}

/**
 *   This function changes the character currently displayed on the LED
 *   matrix when the navswitch is pressed downwards.
     @param displayed_character The current character displayed on the
     LED matrix.
     @return displayed_character The next character displayed in order.
*/

char navswitch_down (char character)
{
    if (character == 'P') {
        character = 'R';
    } else if (character == 'S') {
        character = 'P';
    } else {
        character = 'S';
    }
    return character;
}

