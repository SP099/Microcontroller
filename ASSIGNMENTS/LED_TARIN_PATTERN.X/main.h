/* 
 * File:   main.h
 * Name: Sushant Patil
 */

#ifndef MAIN_H
#define	MAIN_H

/* Board has 2 LED Arrays. We are using the 1st one @ PORTB*/
#define LED_ARRAY PORTB

/* Define LED_ARRAY_DDR as TRISB for readability
* TRISB is Data Direction Register for PORTB
*/
#define LED_ARRAY_DDR TRISB

#endif

