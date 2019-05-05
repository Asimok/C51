/*
 * 单片机发送两个字符给PC机 波特率 9600Mhz SMOD=0 fosc=11.0592Mhz
 * (SMOD=1 时 PCON=0X80 要写上)
 *计算初值
 *波特率=（2^SMOD/32）*(fosc/((256-X)*12))
 *
 * */
#include "../reg52.h"
#define  uc unsigned  char
#define  ui unsigned  int
//初始化串口
void init()
{

    TMOD=0x20;//用定时器1 方式2 自动重装初值 M1=1 M0=0
    TH1=253;//计算初值  波特率9600bps时
    TL1=253;//低八位可以不设置
    TR1=1;//启动定时器T1

    SM0=0;//使用SCON方式一
    SM1=1;
    REN=1;//启动串口接收数据

    //SCON结构 SM1 SM1 SM2 REN TB8 RB8 TI RI
    //也可以 SCON=0X50

    //使用查询方式

}
void delay(ui z)
{
    ui a,b;
    for ( a=z;a>0;a--)
        for( b=110;b>0;b--);
}
void sendbyte(uc dat)
{
   //发送单个字符给PC机
   SBUF=dat;
   while (!TI);//TI=0 时一直等待
   TI=0;//手动将发送中断标志位清零
}
void sendstr(uc *s)
{
    while (*s!='\0')
    {
        sendbyte(*s);
        s++;
    }
}

void main()
{
    init();
    sendstr("第1个字符");
    delay(500);
    sendstr("第2个字符");
    while (1);
}


