/*
 * File:   timers.c
 * Author: SUSHANT H PATIL
 *
 * Created on May 23, 2023, 9:31 PM
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
