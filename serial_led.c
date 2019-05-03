/*
* 单片机接收一个数据，用LED验证接收到的数据 波特率 4800 SMOD=1  fosc=11.0592Mhz
*计算初值
*波特率=（2^SMOD/32）*(fosc/((256-X)*12))
*
* */
#include "reg52.h"
//初始化串口
void init()
{
    //SMOD=1 时 PCON=0X80 要写上
    PCON=0X80;
    TMOD=0x20;//用定时器1 方式2 自动重装初值 M1=1 M0=0
    TH1=244;//计算初值  波特率4800bps时
    TL1=244;//低八位可以不设置
    TR1=1;//启动定时器T1

    SM0=0;//使用SCON方式一
    SM1=1;
    REN=1;//启动串口接收数据

    //SCON结构 SM1 SM1 SM2 REN TB8 RB8 TI RI
    //也可以 SCON=0X50

    //中断方式
    EA=1;
    ES=1;
}
void main()
{
    init();
    while(1);


}
void serial() interrupt 4
{
unsigned  char temp;
if(RI)
{
RI=0;//将接收中断标志位 手动清零
temp=SBUF;//将SBUF中的数据取出来
P0=SBUF;

}
}
