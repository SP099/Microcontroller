/*
 * File:   timers.c
 * Author: sushant h patil
 *
 * Created on May 28, 2023, 4:38 PM
 */


#include <xc.h>

void init_timer0(void)
{
    /* Setting the internal clock source */
    T0CS = 0;
    
    /* Assinging the prescaler to Watchdog Timer */
    PSA = 1;

    TMR0 = 6;
    
    /* The timer interrupt is enabled */
    TMR0IE = 1;
}