/**  @file   start_screen.c
     @author Shivin Gaba, Anzac Morel
     @date   13 October 2019
     @brief  This module contains all the methods that are used to
     display the start screen.

*/

#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "start_screen.h"
#include "ir_uart.h"

#define PACER_RATE 500

/**
 *   This function is used befor the game starts and displays paper,
 *   scissors, rock on the screen as scrolling text.
     @param void
     @return void
*/

void start_screen (void)
{
    bool ready_up_sent = false;
    bool ready_up_received = false;
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text ("ROCK, PAPER, SCISSORS");

    while (1) {
        pacer_wait ();
        tinygl_update ();
        navswitch_update ();
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            ir_uart_putc ('r');
            ready_up_sent = true;
        }
        if (ir_uart_read_ready_p ()) {
            char incoming_ready_up;
            incoming_ready_up = ir_uart_getc ();
            if (incoming_ready_up == 'r') {
                ready_up_received = true;
            }
        }
        
        if (ready_up_received == true && ready_up_sent == true) {
                break;
        }
    }
}
