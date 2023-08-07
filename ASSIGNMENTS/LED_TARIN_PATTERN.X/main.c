/* 
 * Name        : Sushant Patil
 * Date        : 04/05/2023
 * Description : LED train pattern on ledsAssignment
 */


#include <xc.h>
#include "main.h"

#pragma config WDTE = OFF // Watch Timer Enable bit (WDT disabled)

/* Function: init_config()
 * This function is used to setup initial peripheral
 */
static void init_config(void) {
    // Set direction of LED_ARRAY to output
    LED_ARRAY_DDR = 0x00; 
    // Set initial value of LED_ARRAY to off
    LED_ARRAY = 0x00; 
}

int main(void) {
    // Call init_config function to initialize peripheral configuration
    init_config();

    // Declare variables
    int i = 0; // changed count to i for readability
    unsigned long int wait = 0;

    // Loop forever
    while (1) {
        // Increment wait variable
        wait++;

        // Wait for a certain number of cycles before updating LEDs
        if (wait == 100000) {
            wait = 0; // Reset wait variable

            // Turn on LEDs from left to right
            if (i >= 0 && i <= 7) {
                LED_ARRAY = LED_ARRAY << 1 | 1;
            }
            // Turn off LEDs from left to right
            else if (i >= 8 && i <= 15) {
                LED_ARRAY = LED_ARRAY << 1;
            }
            // Turn on LEDs from right to left
            else if (i >= 16 && i <= 23) {
                LED_ARRAY = LED_ARRAY >> 1 | 0x80;
            }
            // Turn off LEDs from right to left
            else if (i >= 24 && i <= 31) {
                LED_ARRAY = LED_ARRAY >> 1;
            }
            // Reset i variable to start again from the beginning
            else {
                i = -1; // start at 0 on next iteration
            }
            i++; // Increment i
        }
    }
    return 0;
}
