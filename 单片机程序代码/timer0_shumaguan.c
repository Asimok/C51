/*
�м��ĸ��������ʾ 0-F ���1s ��ʱ��0ʵ��
1100 0011 0XC3;
ʹ��12MHZ����  ��ʱ1000ms 20��
*/

#include"reg52.h"
sbit wela=P2^0;
sbit dula=P2^1;
#define ui unsigned int
ui num=0,i=0;
/*------------------------------------------------
                  ��������� 0-F
------------------------------------------------*/
unsigned char code table[]={    0xc0,0xf9,0xa4,0xb0,
                                0x99,0x92,0x82,0xf8,
                                0x80,0x90,0x88,0x83,
                                0xc6,0xa1,0x86,0x8e
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
            dula=1;
            P0=table[i];
            dula=0;
        }
    }

}
void inittimer()
{
    TMOD=0X01;
    TH0=(65536-5O000)/256;
    TL0=(65536-50000)%256;
    EA=1;
    ET0=1;
    TR0=1;
}
void timer0() interrupt 1
{
    TH0=(65536-5O000)/256;
    TL0=(65536-50000)%256;
    num++;
    i++;
    if(i==16)
    {
        i=0;
    }

}