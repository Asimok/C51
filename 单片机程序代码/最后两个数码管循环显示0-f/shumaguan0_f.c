/*
最后两个数码管显示0~F
*/

#include "reg52.h"
#define ui unsigned int

sbit wela =P2^1;//定义引脚
sbit dula =P2^0;

/*------------------------------------------------
                   查表表格
------------------------------------------------*/
unsigned char code table[]={    0x3F,0x06,0x5B,0x4F,
												 	 			0x66,0x6D,0x7d,0x07,
						  									0x7f,0x6f,0x77,0x7C,
						  									0x39,0x5E,0x79,0x71 }	;
																//共阴数码管0~F
						

void delay(ui z)
{
    ui a,b;
    for(a=z;a>0;a--)
    	for(b=110;b>0;b--);
} 

void main()
{
     ui i=0;
	//位选数码管0011 1111
	//0选中最后两个数码管  低电平选中数码管 从左到右最左边的为最低位 即第一个数码管为最低位
	//低位--->高位
	wela=1;//送位码
	P0=0x3f;
	wela=0;

	while(1)
	{	
	for(i=0;i<16;i++)   
	    {
	    	 delay(1000);
				 dula=1;//送段码
		     P0=table[i];
				 dula=0;
	    }
	}
}