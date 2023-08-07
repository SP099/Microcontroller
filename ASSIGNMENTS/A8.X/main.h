/* 
 * File:   main.h
 * Author: SUSHANT H PATIL
 *
 * Created on May 25, 2023, 9:44 PM
 */


#ifndef MAIN_H
#define	MAIN_H

#define OFF              0x00

#define  LED_ARRAY_1      PORTD
#define  LED_ARRAY_1_DDR  TRISD
void glow_on_press(unsigned char key);

#endif	/* MAIN_H */