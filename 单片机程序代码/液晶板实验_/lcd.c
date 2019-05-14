/*
 * Һ������ʾ�����ַ���
 * */
#include "reg52.h"
#define  uc unsigned char
#define ui unsigned int
//ѧУ����
sbit rs=P2^4;
sbit rw=P2^5;
sbit en=P2^6;
//�Լ�����
//sbit rs=P2^6;
//sbit rw=P2^5;
//sbit en=P2^7;
void delay(ui z)
{
    ui a,b;
    for ( a=z;a>0;a--)
        for( b=110;b>0;b--);
}
void write_com(uc com)//дָ��
{
    rs=0;
    rw=0;
    P0=com;//D0-D7����ָ��
    en=1;//����������
    delay(5);
    en=0;
}
void write_dat(uc dat)//д����
{
    rs=1;//���� �ߵ�ƽ
    rw=0;
    P0=dat;//D0-D7��������
    en=1;//����������
    delay(5);
    en=0;
}
void init()
{
    write_com(0x38);//����6 8λ���ݽӿ� 2����ʾ 5*7����
    write_com(0x0f);//����4 ����ʾ �й�� ��˸
    write_com(0x06);//����3 ����дһ���ַ����ַָ���һ ������ʾ���ƶ�
    write_com(0x01);//����1 ����
}
void display(uc *s)
{
    int i=0;
    uc dat;
    while(*s!='\0')
    {
        dat=*s;
        delay(500);
        //write_com(0x18);  //����5 �ַ�����
        write_dat(dat);
        s++;
    }
}
void main()
{
    init();
    //��ʾ�ڵ�һ��  0x00-0x0f
    write_com(0x80+0x00);
    display("hello world!");
    //��ʾ�ڵڶ���  0x40-0x4f
    write_com(0x80+0x40);
    display("today is sunday!!!");
    while(1);
}