/*
 * File:   main.c
 * Author: sushant h patil
 *
 * Created on May 31, 2023, 1:35 PM
 */


#include <xc.h>
#include "clcd.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void) {
    
    init_clcd();
}

void main(void) {
    
    init_config();
    unsigned char temp;
    unsigned int wait;
    char message[] = "Hello_______";
     
    while (1) 
    {
        /*Right scrolling*/           
        clcd_print("Right Scrolling",LINE1(0));
        /*right scrolling logic*/                          
        temp = message[11];          
        for(int i = 12 ; i > 0 ; i--)          
        {              
            message[i] = message[i - 1];	          
        }          
        message[0] = temp; 
        /*display the message in 2nd line first position*/
        clcd_print(message, LINE2(0));          
        // non-blocking delay         
        if(wait++ == 100000)          
        {
                wait=0;           
        }      
    }
    return;
}



