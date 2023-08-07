/*
 * File:   main.c
 * Author: SUSHANT H PATIL
 * 
 * Created on June 1, 2023, 3:12 PM
 */

#include <xc.h>
#include "ssd.h"
#include "digital_keypad.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)


void init_config(void) {
    
    init_digital_keypad();          
    init_ssd();                 
}
void main(void) {
    unsigned char ssd[] ={ ZERO, ZERO, ZERO, ZERO};
    unsigned char digit[] = {ZERO ,ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN ,EIGHT, NINE};    
    unsigned long int count , delay=0 ; 
    unsigned char key;
    init_config();
    
    count = eeprom_read(0x00) * 1000 ;
    count = count + (eeprom_read(0x01)*100);
    count = count + (eeprom_read(0x02)*10);
    count = count + (eeprom_read(0x03));
      
    while(1)
    {                                              
       key = read_digital_keypad(LEVEL);                                     
                        
       if(delay++ == 100)
       {
           delay=0;
                   count++;
                   if(count>9999)
                   {
                       count=0;
                   }
                   
       } 
        ssd[3] = digit[(count % 10)];                  
        ssd[2] = digit[(count % 100) / 10];                  
        ssd[1] = digit[(count % 1000) / 100];                                 
        ssd[0] = digit[(count / 1000)]; 
        
       display(ssd);
       
       if(key == SW2)
       {
           eeprom_write(0x03 , (count % 10) );
           eeprom_write(0x02 , ((count/10)%10) );
           eeprom_write(0x01 , ((count % 1000) / 100) );
           eeprom_write(0x00 , (count / 1000) );
           
           
       }
      
    }
    return;
}
     