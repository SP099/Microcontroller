/*
 * File:   isr.c
 * Author: SUSHANT H PATIL
 *
 * Created on 22 May, 2023, 4:54 PM
 */


#include <xc.h>
#include "main.h"

void __interrupt() isr(void)
{
    static unsigned int count1 = 0 ;  
    static unsigned int count2 = 0;
    static unsigned int count3 = 0 ;

    if (TMR0IF == 1)
    {
        /* TMR0 Register value + 6 (offset count to get 250 ticks) + 2 Instant Cycle */
        TMR0 = TMR0 + 8;
        
        if (++count1 == 20000)
        {
            count1 = 0;        
            LED1 = !LED1;
        }      
        TMR0IF = 0;
    }              
    if(TMR1IF == 1)       
    {                   
        TMR1H = 0XFE;              
        TMR1L = 0X0C;            
        /* TMR1H and TMR1L is re initialize to value FE0C to get 500 ticks */           
        if (++count2 == 1240)              
        {                        
            count2 = 0;                    
            LED2 = !LED2;    
        }                      
        TMR1IF =0;                 
    }  
    if (TMR2IF == 1)
    {
        if (++count3 == 1250)
        {
            count3 = 0;
            
            LED3 = !LED3;
        }       
        TMR2IF = 0;       
    }
}