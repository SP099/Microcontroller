/*
 * File:   timers.c
 * Author: SUSHANT H PATIL
 *
 * Created on 25 May, 2023, 5:52 PM
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

