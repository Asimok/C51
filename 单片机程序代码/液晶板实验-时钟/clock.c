/*
 * �Զ�������
 * ʹ�ö�ʱ��T0
 * */

#include "reg52.h"
#define ui unsigned int
#define uc unsigned char

//ѧУ����
sbit rs=P2^4;
sbit rw=P2^5;
sbit en=P2^6;
//�Լ�����
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
void write_com(uc com)//дָ��
{
    rs=0;//ָ�� �͵�ƽ
    rw=0;//д
    P0=com;//D0-D7����ָ��
    en=1;//����������
    delay(5);
    en=0;
}
void write_dat(uc dat)//д����
{
    rs=1;//���� �ߵ�ƽ
    rw=0;//д
    P0=dat;//D0-D7��������
    en=1;//����������
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

    write_com(0x38);//����6 8λ���ݽӿ� 2����ʾ 5*7����
    write_com(0x0f);//����4 ����ʾ �й�� ��˸
    write_com(0x06);//����3 ����дһ���ַ����ַָ���һ ������ʾ���ƶ�
    write_com(0x01);//����1 ����

    //д���ַ��� �ַ�������16
    for(num=0;num<14;num++)
    {
        write_dat(table1[num]);
        delay(5);
    }
    write_com(0xc0);//����
    //д���ַ��� �ַ�������12
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
    uc shi,ge;//����������λ���ݷ���
    shi=dat/10;
    ge=dat%10;
    //��ʾ���ڶ��� 0x80+0x40
    //add Ϊƫ��λ��
    write_com(0xc0+add);
    //0x30��ʾ0��ASCLL�� 0x30+����(0-9)��ʾ �����ֶ�Ӧ�ı����ֵ(Ascll)
    write_dat(0x30+shi);//����Զ����� �����ֶ���λ
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
            //1��
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
                        //0123456789  λ��
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