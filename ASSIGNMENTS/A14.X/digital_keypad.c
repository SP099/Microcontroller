/*
 * File:   digital_keypad.c
 * Author: Sushant
 *
 * Created on 9 June, 2023, 10:43 PM
 */



#include <xc.h>
#include "digital_keypad.h"
static int count=0;

void init_digital_keypad(void)
{
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad(unsigned char mode)
{
    static unsigned char once = 1;
    
    if (mode == LEVEL_DETECTION)
    {
      
        return KEYPAD_PORT & INPUT_LINES;
    }
    else
    {
        count++;
        if (((KEYPAD_PORT & INPUT_LINES) != ALL_RELEASED) && once)
        {
            once = 0;
            count =0;
            
            return KEYPAD_PORT & INPUT_LINES;
        }
        else if (((KEYPAD_PORT & INPUT_LINES) == SW1) && count > 50 )
        {
            count = 0;
            return LPSW1;
        }
        else if ((KEYPAD_PORT & INPUT_LINES) == ALL_RELEASED)
        {
            count = 0;
            once = 1;
        }
        
    }
    
    return ALL_RELEASED;
}