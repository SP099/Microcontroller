/* 
 * File:   i2c.h
 * Author: Sushant
 *
 * Created on June 18, 2023, 7:37 PM
 */


#ifndef I2C_H
#define	I2C_H

#define FOSC            20000000

void init_i2c(unsigned long baud);
void i2c_start(void);
void i2c_rep_start(void);
void i2c_stop(void);
unsigned char i2c_read(unsigned char ack);
int i2c_write(unsigned char data);


#endif	/* I2C_H */

