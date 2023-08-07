/*
 * File:   isr.c
 * Author: Sushant H Patil
 */



#include <xc.h>
#include "main.h"
#include "ssd.h"

int count1;
void __interrupt() isr(void)
{
    static unsigned int count2 = 0;
    if (TMR0IF == 1)
    {
        TMR0 = TMR0 + 6 + 2;
        if (++count2 == 15000)
        {
            if(INTF == 1)
            {
                count1 = 0;
                INTF = 0;
                TMR0IE = 1;
                
            }
            count1++;
            
            count2 = 0;
            LED1 = !LED1;  
        }
        
        TMR0IF = 0;
    }
}