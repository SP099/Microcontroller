/*
 * File:   isr.c
 * Author: SUSHANT H PATIL
 *
 * Created on May 24, 2023, 9:41 PM
 */

#include <xc.h>
#include "timers.h"

extern unsigned int hour, min, flag;
void __interrupt() isr(void)
{
    static unsigned long int count1 = 0, count2 = 0;
    static unsigned int count3 = 0;
    
    if (TMR0IF == 1)
    {
        /* TMR0 Register value + 6 (offset count to get 250 ticks) + 2 Inst Cycle */
        TMR0 = TMR0 + 6 + 2;
        
        //increment min after 60 sec
        if (++count1 == 1200000)
        {
            min++;            
            count1 = 0;            
        }
        //increment hour after 60 min
        if(++count2 == 72000000)
        {
            hour++;
            min = 0; // reset min to 00
            count2 = 0;
        }
        
        //half sec delay for DP
        if(++count3 == 10000)
        {
            flag = 1;
            count3 = 0;
        }
        
        TMR0IF = 0;
    }
}
