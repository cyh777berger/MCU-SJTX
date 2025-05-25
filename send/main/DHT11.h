#include <reg52.h>

#ifndef __DHT11_H__
#define __DHT11_H__

sbit Data = P2^7;

unsigned char DHT11_rec_byte(void);
void DHT11_start(void);
void DHT11_receive(void);
void DHT11_Display(void);

#endif