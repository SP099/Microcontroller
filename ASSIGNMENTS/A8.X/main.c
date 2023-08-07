/*
 * File:   main.c
 * Author: SUSHANT H PATIL
 *
 * Created on May 25, 2023, 9:45 PM
 */

#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
#define SW_WAIT     200

void init_config(void) {
    
    init_digital_keypad();          
    init_ssd();                 
}
void main(void) {
    unsigned char ssd[] ={ ZERO, ZERO, ZERO, ZERO};
    unsigned char digit[] = {ZERO ,ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN ,EIGHT, NINE};    
    static unsigned int count = 0,flag = 1, wait = 0 , sw_count = 0; 
    unsigned char key;
    init_config();
    
    while(1)
    {                                              
       key = read_digital_keypad(LEVEL);                                     
                        
            if(key == SW1)           
            {                            
                if(flag)
                {                  
                    count++;                
                    flag = 0;             
                }              
                else
                {
                    sw_count--;  
                }
            }           
            else 
            {
                flag = 1;
            }                              
            if(sw_count > 0)
            {               
                if(wait++ == 25)
                {                   
                    ssd[3] = digit[(count % 10)];                  
                    ssd[2] = digit[(count % 100) / 10];                  
                    ssd[1] = digit[(count % 1000) / 100];                 
                    ssd[0] = digit[(count / 1000)];                  
                    wait = 0;              
                }

            }          
            else
            {                
                sw_count = SW_WAIT;            
                count = 0;         
            }
            if( count >= 9999 ) 
            {
                while(1);           
            }
       
       display(ssd);  
    }
    return;
}
     