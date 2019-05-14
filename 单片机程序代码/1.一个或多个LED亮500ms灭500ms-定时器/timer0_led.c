/*
��ʱ��0ʵ�� ��ʱ500ms ʹLED������
ʹ��12MHZ����
*/
#include "reg52.h"
unsigned char num=0;
sbit led=P0^0;
void inittimer0();
void main()
{
    led=0; //��ʼ״̬ led��
    inittimer0();
    while(1)
    {
        if(num==10)
        {
            num=0; //�ж�10�� 500ms ���¼��� Num����
            led=~led;
        }
    }
}
void inittimer0()
{

    TMOD=0X01;
    TH0=(65536-50000)/256;  //��ʱ50ms
    TL0=(65536-50000)%256;

    EA=1; //���ж�
    ET0=1;  //T0�ж�
    TR0=1;  //����TO

}
void timer0() interrupt 1
{
    TH0=(65536-50000)/256;  //��ʱ50ms
    TL0=(65536-50000)%256;
    num++;
}