/*
 * File:   main.c
 * Author: sushant h patil
 *
 * Created on May 28, 2023, 4:37 PM
 */


#include <xc.h>
#include "main.h"
#include "timers.h"
#include "adc.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)
     
/*global variable declaration*/   
unsigned short adc_reg_val;     
void init_config(void) {
    LED_ARRAY1 = OFF;
    LED_ARRAY1_DDR = 0x00;    
  
    init_adc();      
    init_timer0();
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void) {   
    
    init_config();   
    while (1)
    {
        adc_reg_val = read_adc();//10 bits -> 0 to 1023          
    }
    return;
}
