/*
 * File:   main.c
 * Author: SUSHANT H PATIL
 * Problem Statement : Write a Embedded C program to display the multiple patterns on the LEDs controlled by the switches.
 *                     For every switch, dedicate a LEDs glow pattern.The pattern should change on key press
 */


#include <xc.h>
#include "main.h"
#include "timers.h"
#include"digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)


static void init_config(void) {
    LED_ARRAY1 = 0x00;
    LED_ARRAY1_DDR = 0x00;
    
    init_digital_keypad();
    init_timer0();     
    init_timer1();
    init_timer2();
    
    /* Peripheral Interrupt Enable Bit (For Timer2) */
    PEIE = 1;
    
    /* Enable all the Global Interrupts */
    GIE = 1;
    
}

void main(void) {
    
    init_config();


    while (1)
    {
       ;
    }
    return;
}
