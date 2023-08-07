/*
 * File:   main.c
 * Author: SUSHANT H PATIL
 *
 * Created on 19 May, 2023, 5:18 PM
 */


#include <xc.h>
#include "main.h"
#include "timers.h"
#include "digital_keypad.h"


#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

unsigned int duty_cycle = 50, loop_counter = 0;

static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
    init_timer0();
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void) {
    unsigned char key;
    
    init_config();

    while (1)
    {
       
        
        key = read_digital_keypad(STATE);

        if (key == SW1)
        {
        	//set brightness to 100 by setting duty_cycle
             duty_cycle = 100;
             //turn on timer
             TMR0 = ON;
        }
        
    }
    return;
}
