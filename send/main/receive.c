#include <reg52.h>
#include <intrins.h>
#include <receive.h>
#include <delay.h>
void display_num(unsigned char num)
{
    P0 = seg_code[num];  // ????
    LED_A = 0; LED_B = 0; LED_C = 0; LED_D = 0;  // ?????
    delay(500);
    LED_A = 1; LED_B = 1; LED_C = 1; LED_D = 1;  // ?????
}

void receive()
{
    SCON = 0x50;
    TMOD = 0x20;
    TH1 = TL1 = 0xF4;
    TR1 = 1;

    while (1)
    {
        if (RI)  // ?????
        {
            receive_data = SBUF;
            RI = 0;
            display_num(receive_data);  // ????????
        }
    }
}