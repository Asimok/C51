/*
 * 液晶板显示两行字符串
 * */
#include "reg52.h"
#define  uc unsigned char
#define ui unsigned int
//学校板子
sbit rs=P2^4;
sbit rw=P2^5;
sbit en=P2^6;
//自己板子
//sbit rs=P2^6;
//sbit rw=P2^5;
//sbit en=P2^7;
void delay(ui z)
{
    ui a,b;
    for ( a=z;a>0;a--)
        for( b=110;b>0;b--);
}
void write_com(uc com)//写指令
{
    rs=0;
    rw=0;
    P0=com;//D0-D7发送指令
    en=1;//产生高脉冲
    delay(5);
    en=0;
}
void write_dat(uc dat)//写数据
{
    rs=1;//数据 高电平
    rw=0;
    P0=dat;//D0-D7发送数据
    en=1;//产生高脉冲
    delay(5);
    en=0;
}
void init()
{
    write_com(0x38);//命令6 8位数据接口 2行显示 5*7点阵
    write_com(0x0f);//命令4 开显示 有光标 闪烁
    write_com(0x06);//命令3 读或写一个字符后地址指针加一 整屏显示不移动
    write_com(0x01);//命令1 清屏
}
void display(uc *s)
{
    int i=0;
    uc dat;
    while(*s!='\0')
    {
        dat=*s;
        delay(500);
        //write_com(0x18);  //命令5 字符左移
        write_dat(dat);
        s++;
    }
}
void main()
{
    init();
    //显示在第一行  0x00-0x0f
    write_com(0x80+0x00);
    display("hello world!");
    //显示在第二行  0x40-0x4f
    write_com(0x80+0x40);
    display("today is sunday!!!");
    while(1);
}