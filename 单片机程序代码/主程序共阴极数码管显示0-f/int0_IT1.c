//下降沿触发
#include "reg52.h"
#define ui unsigned int

sbit LED = P2 ^ 2;

/*------------------------------------------------
				   共阳数码管 0-F
------------------------------------------------*/
unsigned char code table[]={    0xc0,0xf9,0xa4,0xb0,
						  		0x99,0x92,0x82,0xf8,
						 	    0x80,0x90,0x88,0x83,
						 		0xc6,0xa1,0x86,0x8e
						  }	  ;
void delay(ui z)
{
	ui a, b;
	for (a = z; a > 0; a--)
		for (b = 110; b > 0; b--);
}
void Init_INT0(void)
{
	IT0 = 1;//外部中断0下降沿触发
	EA = 1;            //总中断打开
	EX0 = 1;           //外部中断0打开
}
void main()
{
	ui i;
	
	Init_INT0();

	for (i = 0; i < 16; i++)  		
	{   
		LED = 1;//熄灭LED
		delay(500);
		P0 = table[i];
	}
}
void int0() interrupt 0
{
	LED = 0;//点亮LED
}

