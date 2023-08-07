/*
 * File:   main.c
 * Author: sushant h patil
 *
 *  Created on June 1, 2023, 9:16 AM
 */


#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"
#pragma config WDTE = OFF        /* Watchdog Timer Enable bit (WDT disabled)*/

static void init_config(void) {
    /*initialization of keypad and ssd*/
    init_ssd();
    init_digital_keypad();
}

void main(void) 
{
    /*initialization of keypad and ssd values*/
    init_config();
    unsigned char ssd[MAX_SSD_CNT];
    unsigned char cur_key = SW1, key;
    unsigned int digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, UNDERSCORE, UNDERSCORE};
    unsigned int wait = 0, count = 0;
    unsigned char flag = 1; //flag variable to indicate the running state

    while (1)
    {
        key = read_digital_keypad(STATE);
        
        if (key == SW1 || key == SW2)
        {
            //update the current key
            cur_key = key;
        }
        else if (key == SW3)
        {
            //toggle the running state
            flag = !flag;
        }
        
        if (flag)
        {
            if (wait++ == 200)
            {
                wait = 0;
                
                //changing the direction on key pressed 
                //right to left scrolling 
                if (cur_key == SW1)
                {           
                    if (count++ >= 11)
                    {
                        count = 0;
                    }
                }
                //left to right scrolling 
                else if (cur_key == SW2)
                {         
                    if (count-- <= 0)
                    {
                        count = 11;
                    }
                }
            }
        }
        
        //set the values to SSD 
        ssd[0] = digit[count];
        ssd[1] = digit[(count + 1)%12];
        ssd[2] = digit[(count + 2)%12];
        ssd[3] = digit[(count + 3)%12];

        display(ssd);
    }
    
    return;
}