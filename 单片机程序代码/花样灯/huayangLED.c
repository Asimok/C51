#include "reg52.h"
#define uc unsigned char
#define ui unsigned int
uc code seg[]={			  0x7f,0xbf,0xdf,0xef,
						  0xf7,0xfb,0xfd,0xfe,
						  0xff,0xff,0x00,0x00,
						  0x55,0x55,0xaa,0xaa
						  }	  ;
void delay(ui z)
{
	ui a,b;
	for(a=z;a>0;a--)
		for(b=110;b>0;b--);
}
void main()
{
	ui i;
	P1=0XFE; //1111 1110
	for(i=0;i<8;i++)
	{
		delay(1000);
	//	P1=seg[i];
		P1=P1<<1;

	}
	P1=0X7F; //0111 1111
	for(i=0;i<8;i++)
	{
		delay(1000);
	//	P1=seg[i];
		P1=P1>>1;

	}
}