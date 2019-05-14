/*
定时器0实现 定时500ms 使LED灯亮灭
使用12MHZ晶振
*/
#include "reg52.h"
unsigned char num=0;
sbit led=P0^0;
void inittimer0();
void main()
{
    led=0; //初始状态 led灭
    inittimer0();
    while(1)
    {
        if(num==10)
        {
            num=0; //中断10次 500ms 重新计数 Num清零
            led=~led;
        }
    }
}
void inittimer0()
{

    TMOD=0X01;
    TH0=(65536-50000)/256;  //定时50ms
    TL0=(65536-50000)%256;

    EA=1; //总中断
    ET0=1;  //T0中断
    TR0=1;  //开启TO

}
void timer0() interrupt 1
{
    TH0=(65536-50000)/256;  //定时50ms
    TL0=(65536-50000)%256;
    num++;
}