#include <REG52.H>

sbit LCD_RS =P2^4;
sbit LCD_RW =P2^5;
sbit LCD_E  =P2^6;
#define LCD_DataPort P0

unsigned char code CG_dat1[]={0x04,0x1F,0x15,0x1F,0x15,0x1F,0x07,0x00,0x40};
unsigned char code CG_dat2[]={0x05,0x0B,0x19,0x1F,0x09,0x1D,0x09,0x00,0x48};
unsigned char code CG_dat3[]={0x0A,0x1F,0x04,0x1F,0x1F,0x04,0x1F,0x00,0x50};
unsigned char code CG_dat4[]={0x0E,0x0E,0x15,0x0F,0x14,0x0A,0x1D,0x00,0x58};
unsigned char code CG_dat5[]={0x12,0x0A,0x0F,0x1A,0x07,0x1D,0x17,0x00,0x60};

void LCD_Delay()		
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}

void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_E=1;
	LCD_Delay();
	LCD_E=0;
	LCD_Delay();
}


void LCD_Init(void)
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}


void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Column-1)+0x40);
	}
}

int LCD_Pow(int X,int Y){
	unsigned char i;
	int Result=1;
	for(i=0;i<Y;i++){
	Result*=X;}
	return Result;
}

void LCD_ShowNum(unsigned char Line, unsigned char Column,unsigned int Number,unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor (Line, Column);
	for(i=Length;i>0;i--){
	LCD_WriteData(Number/LCD_Pow(10,i-1)%10+'0');}
}

void LCD_makechar(unsigned char CG_dat[]){
	unsigned char i;
	for(i=0;i<8;i++){
	LCD_WriteCommand(CG_dat[8]+i);
	LCD_WriteData(CG_dat[i]);
}
}
void LCD_ShowChar(unsigned char Line,unsigned char Column,unsigned char Char)
{
	LCD_SetCursor(Line,Column);
	LCD_WriteData(Char);
}

void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}

void LCD_print(unsigned char Line,unsigned char Column,unsigned char *text)
{
	//int i = 2;
	LCD_SetCursor(Line,Column);
	while(*text != 0)
	{
		LCD_WriteData(*text++);
	}
}

void name(){
	LCD_makechar(CG_dat1);
	LCD_makechar(CG_dat2);
	LCD_makechar(CG_dat3);
	LCD_makechar(CG_dat4);
	LCD_makechar(CG_dat5);
	LCD_ShowChar(1,1,0x00);
	LCD_ShowChar(1,2,0x01);
	LCD_ShowNum(1,3,2203,4);
	LCD_ShowChar(1,7,0x02);
	LCD_ShowChar(1,8,0x03);
	LCD_ShowChar(1,9,0x04);
	LCD_ShowChar(1,10,0x05);
	LCD_ShowNum(2,1,8212,4);
	LCD_ShowNum(2,5,2209,4);
	LCD_ShowNum(2,9,24,2);
}