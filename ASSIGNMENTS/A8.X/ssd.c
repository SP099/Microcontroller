/*
 * File:   ssd.c
 * Author: SUSHANT H PATIL
 *
 * Created on May 25, 2023, 9:46 PM
 */


#include <xc.h>
#include "ssd.h"

void init_ssd(void)
{
    /* Seeting the SSD data line as Output */
    SSD_DATA_PORT_DDR = 0x00;
    
    /* Setting SSD Control Line as Output (RA5 - RA2) */
    SSD_CONTROL_PORT_DDR = SSD_CONTROL_PORT_DDR & 0x03;
    
    /*to turn off all the four ssd*/
    SSD_CONTROL_PORT = SSD_CONTROL_PORT & 0x03;
}

void display(unsigned char data[])
{
    unsigned char digit;
    
    for (digit = 0;  digit < MAX_SSD_CNT ; digit++)
    {
        SSD_DATA_PORT = data[digit];
        SSD_CONTROL_PORT = (SSD_CONTROL_PORT & 0x03) | (0x04 << digit);
      for (unsigned long int wait = 400; wait--;);
    }
    
}