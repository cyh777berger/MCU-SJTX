#include <reg52.h>
#include <intrins.h>
sbit LED_A = P1^4;  // ?????
sbit LED_B = P1^5;
sbit LED_C = P1^6;
sbit LED_D = P1^7;

unsigned char seg_code[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};  // ???????
unsigned char receive_data = 0;  // ??????
void display_num(unsigned char num);
void receive();