/*
中间四个数码管显示 0-F 间隔1s 定时器0实现
1100 0011 0XC3;
使用12MHZ晶振  定时1000ms 20次
*/

#include"reg52.h"
sbit wela=P2^0;
sbit dula=P2^1;
#define ui unsigned int
ui num=0,i=0;
/*------------------------------------------------
                  共阴数码管 0-F
------------------------------------------------*/
unsigned char code table[]={    0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71
						  }	  ;
void inittimer();
void main()
{
    inittimer();
    wela=1;
    P0=0XC3;
    wela=0;
    while(1)
    {
        if(num==20)
        {
            num=0;
			i++;   
        }
		 
		dula=1;
            P0=table[i];
            dula=0;
    }

}
void inittimer()
{
    TMOD=0X01;
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    EA=1;
    ET0=1;
    TR0=1;
}
void timer0() interrupt 1
{
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    num++;
   
    if(i==16)
    {
        i=0;
    }

}