/*
 * File:   main.c
 * Author: UNIS
 * 
 * Created on 22 May, 2023, 4:44 PM
 */


#include <xc.h>
#include "main.h"
#include "timers.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)

/*extern previous file variable visibility*/
extern unsigned  long int period;
extern unsigned  long int duty_cycle;
extern unsigned  long int loop_counter;
static void init_config(void)
{
	LED_ARRAY = 0x00;    
	LED_ARRAY_DDR = 0x00;
    
    init_digital_keypad(); 
    init_timer0();   
    
    /* Enable all the Global Interrupts */
    GIE = 1;

}
void main(void) {
    init_config();
    unsigned char key;
    unsigned int wait;
  
	while(1)
	{   
        /*non blocking delay*/
        if(wait-- == 0)
        {
            wait = 2500;
            /*read key from user*/
            key = read_digital_keypad(LEVEL);
            /*LED brightness increments*/
            if(key == SW1)
            {
                if(duty_cycle != period)
                {
                   duty_cycle++;     
                }
            }
            /*LED brightness increments*/
            else if(key == SW2)
            {
                if(duty_cycle != 0)
                {
                    duty_cycle--;
                }
            }
        }
        
    }
    return;
}
