/**  @file   update_display.c
     @author Shivin Gaba, Anzac Morel
     @date   13 October 2019
     @brief  This module contains all the methods that are used to
     display different outcomes and message for the players on the LED matrix.

*/

#include "tinygl.h"
#include "update_display.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"

#define TEN_SECONDS 5000
#define SIX_SECONDS 3000


/**
 *   This function sets the LED matrix display to the character that is passed in it.
     @param the character type value that is displayed on the LED matrix.
*/
void display_character (char character)
{
    char buffer[2];
    buffer[0] = character;
    buffer[1] = '\0';
    tinygl_text (buffer);
}

/**
 *   This function displays the result on the LED matrix based on which character
 *   is passed a parameter to this function.
     @param 'W' for win, 'L' for loss and 'D' for draw
*/
void display_result (char print_text, int wins, int losses)
{
    if (print_text == 'W') {
        tinygl_text ("YOU WON");
    } else if (print_text == 'L') {
        tinygl_text ("YOU LOST");
    } else {
        tinygl_text ("DRAW");
    }
    int timer =  0;
    change_display (timer);
    if (wins != 3 && losses != 3) {
        display_score (wins);
    }
    tinygl_clear ();
}


/**
 *   Displays the score on the LED matrix after each round of game.
     @param an int value that is used to check what score to be set on the LED matrix.

*/
void display_score (int score)
{    
    char set_score = 0;

    if (score == 0) {
        set_score = '0';
    } else if (score == 1) {
        set_score = '1';
    } else if (score == 2) {
        set_score = '2';
    } else if (score == 3) {
        set_score = '3';
    }
    
    int timer = 0;
    while (timer < SIX_SECONDS) {
        display_character (set_score);
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();
        timer++;
        if (timer == SIX_SECONDS) {
            tinygl_clear();
            tinygl_update ();
        }
    }
    timer = 0;
}

/**
 *   This function makes sure that the display on the LED matrix is just displayed for 10 seconds.
     @param an int value that keeps a track of the time and breaks the loop when the condition is met
*/
void change_display (int timer){
     while (timer < TEN_SECONDS){
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();
        timer++;
        
        if (timer == TEN_SECONDS) {
            tinygl_clear ();
            tinygl_update ();
        }
    }
    timer = 0;
}

