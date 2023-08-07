/*
 * File:   main.c
 * Author: SUSHANT H PATIL
 *
 * Created on May 24, 2023, 9:29 PM
 */



#include <xc.h>
#include "ssd.h"
#include "timers.h"

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

unsigned int hour = 12, min, flag;

static void init_config(void) {
    //initialize timer 0
    init_timer0();
    
    //initialize ssd
    init_ssd();
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}

void main(void) {
    init_config();
    
    unsigned char ssd[4];
    unsigned char digit[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
    
    while (1) {

        //display hour
        ssd[0] = digit[hour / 10];
        
        //for half sec display DP
        if(flag)
        {
            ssd[1] = digit[hour % 10] | DP ;
            flag = 0;
        }
        else
        {
            ssd[1] = digit[hour % 10];   
        }
        
        //display min
        ssd[2] = digit[min / 10];
        ssd[3] = digit[min % 10];
        
        //call display function
        display(ssd);
    }
    return;
}
