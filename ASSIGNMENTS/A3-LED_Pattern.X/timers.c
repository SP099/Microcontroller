/*
 * File:   timers.c
 * Author: SUSHANT H PATIL
 *
 * Created on May 23, 2023, 3:45 PM
 */


#include <xc.h>
#include "timers.h"

void init_timer0(void)
{
    /* Setting the internal clock source */
    T0CS = 0;
    
    /* Assigning the pre scaler to Watchdog Timer */
    PSA = 1;
    
    TMR0 = 6;
    /* The timer interrupt is enabled */
    TMR0IE = 1;
    
}
void init_timer1(void)
{    
    /* selecting the pre scale as 1:8 */
    T1CKPS1 = 1;
    T1CKPS0 = 1;
                    
    TMR1H = 0XFE;              
    TMR1L = 0X0C;

    /* the timer1 interrupt is enabled */
    TMR1IE = 1;

    /* selecting the internal clock source */
    TMR1CS = 0;
   
    /* switching on the timer2 */
    TMR1ON = 1;
}
void init_timer2(void)
{
    /* Selecting the scale as 1:16 */
    T2CKPS0 = 1;
    T2CKPS1 = 1;

    /* Loading the Pre Load register with 250 */
    PR2 = 250;
    /* The timer interrupt is enabled */
    TMR2IE = 1;
   
    /* Switching on the Timer2 */
    TMR2ON = 1;
}