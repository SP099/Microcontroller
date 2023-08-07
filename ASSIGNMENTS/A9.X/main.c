/*
 * File:   main.c
 * Author: sushant h patil
 *
 * Created on 30 May, 2023, 9:36 PM
 */


#include <xc.h>
#include "main.h"
#include "adc.h"
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

void display(unsigned short adc_reg_val)
{ 
    char buff[8];
    int i;
    
  

    i = 1; 
    do
    {
        buff[i] = (adc_reg_val % 10) + '0';
        adc_reg_val = adc_reg_val / 10;
    } while (i--); 
    buff[2] = '.';
    buff[3] = '0';
    buff[4] = '0';
    buff[5] = DEGREE;
    buff[6] = 'C';
    buff[7] = '\0';

    clcd_print(buff, LINE2(8));
     
}

static void init_config(void) {
    init_clcd();
    init_adc();
    
    clcd_print("Room Temp   ", LINE1(1));
}

void main(void) {
    unsigned short int adc_reg_val,volt;
    
    init_config();

    while (1) {
        adc_reg_val = read_adc(CHANNEL2); // pot1
        
        volt=(float)(adc_reg_val * 0.488);
       
        display(volt);
    }
    return;
}