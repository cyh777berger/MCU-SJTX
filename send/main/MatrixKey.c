#include "MatrixKey.h"
unsigned char MatrixKey(void)
{
	unsigned char KeyNumber=0;
	unsigned char X,Y,Z;
	P1=0x0f; 
	if(P1!=0x0f) 
	{
		if(P1!=0x0f)
		{
			X=P1; 
			P1=0xf0; 
			Y=P1;    
			Z=X|Y; 

			switch (Z) 
			{
				case 0xe7: KeyNumber=0x01; break; 
				case 0xeb: KeyNumber=0x02; break;
				case 0xed: KeyNumber=0x03; break;
				case 0xee: KeyNumber=0x04; break;
				
				case 0xd7: KeyNumber=0x05; break;
				case 0xdb: KeyNumber=0x06; break;
				case 0xdd: KeyNumber=0x07; break;
				case 0xde: KeyNumber=0x08; break;
				
				case 0xb7: KeyNumber=0x09; break;
				case 0xbb: KeyNumber=0x0a; break;
				case 0xbd: KeyNumber=0x0b; break;
				case 0xbe: KeyNumber=0x0c; break;
				
				case 0x77: KeyNumber=0x0d; break;
				case 0x7b: KeyNumber=0x0e; break;
				case 0x7d: KeyNumber=0x0f; break;
				case 0x7e: KeyNumber=0x10; break;
			}
		 }
	}
	return KeyNumber;
}
/*
unsigned char MatrixKey(void)
{
	unsigned char KeyNumber=0;
	
	P1=0xF7;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=1;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=5;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=9;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=13;}
	
	P1=0xFB;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=2;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=6;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=10;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=14;}
	
	P1=0xFD;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=3;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=7;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=11;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=15;}
	
	P1=0xFE;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=4;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=8;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=12;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=16;}
	
	return KeyNumber;
}
*/