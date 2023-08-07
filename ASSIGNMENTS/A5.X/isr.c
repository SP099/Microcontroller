/*
 * File:   isr.c
 * Author: SUSHANT H PATIL
 *
 * Created on 25 May, 2023, 3:54 PM
 */

#include <xc.h>
#include "main.h"

unsigned long int period = 100,duty_cycle=50,loop_counter=0;
void __interrupt() isr(void)
{        
    if (TMR0IF == 1)
    {
        /*50 percentage LED Blinking*/
        if(loop_counter < duty_cycle )
        {
            LED1 = 1;
        }
        if(loop_counter >= duty_cycle && loop_counter < period)
        {
            LED1 = 0;
        }
        if(loop_counter++ == period)
        {
            loop_counter = 0;
        }
        
        TMR0IF = 0;
    }
    
}

