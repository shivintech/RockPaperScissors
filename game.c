/**  @file   start_screen.c
     @author Shivin Gaba, Anzac Morel
     @date   13 October 2019
     @brief  This module contains the main logic for the game.

*/

#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "display.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "stdio.h"
#include "stdlib.h"
#include "led.h"
#include <stdbool.h>
#include "start_screen.h"
#include "update_display.h"

#define LOOP_RATE 500
#define PACER_RATE 500
#define MESSAGE_RATE 25

int game_counter = 0;
int win_counter = 0;
int loss_counter = 0;
int draw_counter = 0;

bool game_won (char, char);
char navswitch_up (char);
char navswitch_down (char);

/**
 *   This function takes the two character inputs from the user 1 and user 2, then accordingly decides the winner
 *   or the looser.
     @param an int value that keeps a track of the time and breaks the loop when the condition is met
*/

char check_inputs (char user_selection, char other_user_selection) 
{
    char print_text;
    if (user_selection == other_user_selection) {
        print_text = 'D';
    } else if (game_won (user_selection, other_user_selection)) {
        print_text = 'W';
        win_counter++;
    } else {
        print_text = 'L';
        loss_counter++;
    }
    return print_text;
}
    

/**
 *   This function changes the character currently displayed on the LED
 *   matrix when the navswitch is pressed downwards.
     @param user_selection The character that was sent by the user.
     @param other_user_selection The character that was received by the
     user.
     @return boolean Either true or false depending on the inputs.
*/

bool game_won (char user_selection, char other_user_selection)
{
    return ((user_selection == 'S' && other_user_selection == 'P') || (user_selection == 'R' && other_user_selection == 'S') || (user_selection == 'P' && other_user_selection == 'R'));
}

int main (void)
{
    system_init ();
    display_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    navswitch_init ();
    ir_uart_init ();
    led_init ();
    led_set (LED1, 0);
    pacer_init (LOOP_RATE);
    char character = 'P';
    char user_selection = 1;
    char other_user_selection = 2;
    int timer = 0;
    pacer_init (PACER_RATE);
    
    start_screen ();

    //This loops repeats the game until one player has won three games.
    while (win_counter < 3 && loss_counter < 3) {
        bool choice_sent = false;
        bool choice_recived = false;
        int game_state = 1;
        led_set (LED1, 0);

        //This loop prevents the game from progressing until each fun kit
        //has both sent and received a character.
        while (game_state) {
            pacer_wait ();
            navswitch_update ();
            tinygl_update ();
            display_character (character);

            //The next two if statments restrict the user from changing
            //their input after they have sent a character.
            if (navswitch_push_event_p (NAVSWITCH_NORTH) && choice_sent == false) {
                character = navswitch_up (character);
            }

            if (navswitch_push_event_p (NAVSWITCH_SOUTH) && choice_sent == false) {
                character =  navswitch_down (character);
            }

            //This if statment sends the users selection if the navswitch
            //is pressed.
            if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
                user_selection = character;
                ir_uart_putc (character);
                choice_sent = true;
            }

            //This if statment receives the other users selection and
            //turns on the led to confirm a character has been received.
            if (ir_uart_read_ready_p ()) {
                char incoming_move;
                incoming_move = ir_uart_getc ();

                if (incoming_move == 'R' || incoming_move == 'P' || incoming_move == 'S') {
                    other_user_selection = incoming_move;
                    choice_recived = true;
                    led_set (LED1, 1);
                }
            }

            //This set of statment determines the outcome of the game
            //and sends the appropriate character so the result can be
            //displayed.
            if (choice_sent == true && choice_recived == true) {
                char print_text;
                led_set (LED1, 0);
                print_text = check_inputs (user_selection, other_user_selection);
                display_result (print_text, win_counter, loss_counter);
                tinygl_clear ();
                game_state = 0;
            }
        }
    }
    tinygl_text ("THE FINAL SCORE IS");
    change_display (timer);
    display_score (win_counter);
    tinygl_clear ();
    tinygl_text ("GAME OVER");
    change_display (timer);
    tinygl_clear ();
    tinygl_update ();
}







