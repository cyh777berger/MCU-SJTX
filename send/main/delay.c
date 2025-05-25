#include "Delay.h"

void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

void delay1(unsigned int i)
{
	while(i--){}
}

void DelayMS(unsigned int ms)
{
 	unsigned char i;
	while(ms--)
	{
	 	for(i=0;i<120;i++);
	}
}