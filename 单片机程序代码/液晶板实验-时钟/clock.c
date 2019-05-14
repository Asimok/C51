/*
 * 自定义闹钟
 * 使用定时器T0
 * */

#include "reg52.h"
#define ui unsigned int
#define uc unsigned char

//学校板子
sbit rs=P2^4;
sbit rw=P2^5;
sbit en=P2^6;
//自己板子
//sbit rs=P2^6;
//sbit rw=P2^5;
//sbit en=P2^7;
sbit dula=P2^2;
sbit wela=P2^3;
uc count,hour,min,sec;
uc code table1[]="2019-05-10 FIR";
uc code table2[]="  12:13:14";
void delay(ui z)
{
    ui a,b;
    for ( a=z;a>0;a--)
        for( b=110;b>0;b--);
}
void write_com(uc com)//写指令
{
    rs=0;//指令 低电平
    rw=0;//写
    P0=com;//D0-D7发送指令
    en=1;//产生高脉冲
    delay(5);
    en=0;
}
void write_dat(uc dat)//写数据
{
    rs=1;//数据 高电平
    rw=0;//写
    P0=dat;//D0-D7发送数据
    en=1;//产生高脉冲
    delay(5);
    en=0;
}
void init()
{
    uc num;
    hour=10;
    min=10;
    sec=10;
    dula=0;
    wela=0;

    write_com(0x38);//命令6 8位数据接口 2行显示 5*7点阵
    write_com(0x0f);//命令4 开显示 有光标 闪烁
    write_com(0x06);//命令3 读或写一个字符后地址指针加一 整屏显示不移动
    write_com(0x01);//命令1 清屏

    //写入字符串 字符串长度16
    for(num=0;num<14;num++)
    {
        write_dat(table1[num]);
        delay(5);
    }
    write_com(0xc0);//换行
    //写入字符串 字符串长度12
    for(num=0;num<10;num++)
    {
        write_dat(table2[num]);
        delay(5);
    }
   
}
void init_T0()
{
    TMOD=0X01;
    TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
    EA=1;
    ET0=1;
    TR0=1;
}
void write_nowtime(uc add,uc dat)
{
    uc shi,ge;//将传来的两位数据分离
    shi=dat/10;
    ge=dat%10;
    //显示到第二行 0x80+0x40
    //add 为偏移位置
    write_com(0xc0+add);
    //0x30表示0的ASCLL码 0x30+数字(0-9)表示 该数字对应的表里的值(Ascll)
    write_dat(0x30+shi);//光标自动下移 不用手动移位
    write_dat(0x30+ge);

}

void main()
{
    init();
    init_T0();
    while(1)
    {
        if(count==20)
        {
            //1秒
            count=0;
            sec++;
            if(sec==60)
            {
                sec=0;
                min++;
                if(min==60)
                {
                    min=0;
                    hour++;
                    if(hour==24)
                    {
                        hour=0;
                        //  00:00:00
                        //0123456789  位置
                    }
                    write_nowtime(2,hour);
                }
                write_nowtime(5,min);
            }
            write_nowtime(8,sec);
        }
    }
}

void timer_t0() interrupt 1
{
TH0=(65536-50000)/256;
TL0=(65536-50000)%256;
count++;
}