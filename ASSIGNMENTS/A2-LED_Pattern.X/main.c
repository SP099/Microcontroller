/*
 to toggle direction of train using digital keypad
 * File:   main.c
 */

#include <xc.h>
#include "main.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

static void init_config(void) {
	
	/* Turn off LEDs initially */
	LED_ARRAY1 = 0x00;
	
	/* Configure as Ouput Port */
    	LED_ARRAY1_DDR  = 0X00;

	/* Initialize digital keypad */    	
	init_digital_keypad();
}

void main(void) {

    unsigned char key , pre_key ;
    long int delay = 10000 ;
    int flag = 0 ,i=0 ; 
    
    init_config();

    while (1) {
        key = read_digital_keypad(STATE);
        
        if(key != ALL_RELEASED )
        {
            pre_key = key ;
            flag = 1 ;
        }
     
        if (pre_key == SW1 && flag == 1)
            {
                LED_ARRAY1 = 0x00;
                flag =0 ;
            }
            else if (pre_key == SW2 && flag == 1)
            {
                LED_ARRAY1 = 0x00;
                flag =0 ;
            }
            else if (pre_key == SW3 && flag == 1)
            {
                LED_ARRAY1 = 0xAA;
                flag =0 ;
            }
            else if (pre_key == SW4 && flag == 1)
            {
                LED_ARRAY1 = 0x0F;
                flag =0 ;
            }
        
        
        if(delay-- == 0)
        { 
            delay = 10000;
            if (pre_key == SW1)
            {
                if(i < 8)
                {
                    LED_ARRAY1 = LED_ARRAY1 << 1 | 1 ; 
                    i++;
                }      
                else if (i < 16)
                {
                    LED_ARRAY1 = LED_ARRAY1 << 1 ;
                    i++ ;
                }   
                else if (i<24)
                {
                    LED_ARRAY1 = (LED_ARRAY1 >>1)| 0x80 ;
                    i++;
                }
                else if (i<32)
                {
                    LED_ARRAY1 = (LED_ARRAY1 >> 1) ;
                    i++;
                }  
                else
                {
                    i=0;   
                }
            }
            
            else if (pre_key == SW2)
            {
                if(i < 8)
                {
                    LED_ARRAY1 = LED_ARRAY1 << 1 | 1 ; 
                    i++;
                }
                    
                else if (i < 16)
                {
                    LED_ARRAY1 = LED_ARRAY1 << 1 ;
                    i++ ;
                }
                else
                {
                    i=0;   
                }
            }
            
            else if (pre_key == SW3)
            {
                LED_ARRAY1 = ~LED_ARRAY1 ;
            }
            
            else if (pre_key == SW4)
            {
                LED_ARRAY1 = ~LED_ARRAY1 ;
            }
        }
    }
    return;

}
