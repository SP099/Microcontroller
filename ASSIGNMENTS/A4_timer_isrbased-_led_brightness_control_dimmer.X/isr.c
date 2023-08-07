/*
 * File:   isr.c
 * Author: SUSHANT H PATIL
 *
 * Created on 20 May, 2023, 10:35 AM
 */

#include <xc.h>
#include "main.h"

extern unsigned int duty_cycle, loop_counter;

extern unsigned long int req_time;

void __interrupt() isr(void)
{
    static unsigned long int count = 0;
   
     // logic to generate PWM
    if (loop_counter <= duty_cycle)
    {
        LED1 = ON;
    }
    else
    {
        LED1 = OFF;
    }
    if (loop_counter == PERIOD)
    {
        loop_counter = 0;
    }
    loop_counter++;
    
    
    if (TMR0IF == 1)
    {  
        /* TMR0 Register value + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 6 + 2;
        
        if (++count == req_time) // for 5 sec delay count value is 100000
        {      
            // brightness back 10%
            duty_cycle = 10;
            
            count = 0;    
        }     
        TMR0IF = 0;
    }
}
