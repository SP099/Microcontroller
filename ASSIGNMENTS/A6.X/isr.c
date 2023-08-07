/*
 * File:   isr.c
 * Author: sushant h patil
 *
 * Created on May 28, 2023, 4:39 PM
 */

#include <xc.h>
#include "main.h"

extern unsigned short adc_reg_val;         
void __interrupt() isr(void)
{      
    static unsigned long int period = 100, loop_counter = 0,duty_cycle; 
    duty_cycle = (adc_reg_val/10);  

    if (TMR0IF == 1)
    {
        TMR0 = TMR0 + 8;         
        //LED blinking was increasing when we are increasing  in pot meter        
        //pot meter is 0 to 1023 until slowly brightness increasing   
        if(loop_counter < duty_cycle)		                        
        {			               
            LED1 = ON;		            
        }		          
        else if(loop_counter >= duty_cycle && loop_counter < period )		                
        {						                
            LED1 = OFF;		          
        }			       
        if(loop_counter++ == period)		            
        {		                 
            loop_counter = 0;		           
        }      
        TMR0IF = 0;       
    }
}