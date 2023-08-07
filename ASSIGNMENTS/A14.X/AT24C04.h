/* 
 * File:   AT24C04.h
 * Author: Sushant
 *
 * Created on 9 June, 2023, 10:50 PM
 */



#ifndef AT24C04_H
#define	AT24C04_H
#define SLAVE_WRITE             0b10100000 // 0xD0
#define SLAVE_READ              0b10100001 // 0xD1

#define SEC_ADDR                0x00


void init_AT24C04(void);
unsigned char read_AT24C04(unsigned char addr);
void write_AT24C04(unsigned char addr, unsigned char data);

#endif	/* AT24C04_H */