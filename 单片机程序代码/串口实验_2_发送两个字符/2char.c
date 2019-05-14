/*
 * ��Ƭ�����������ַ���PC�� ������ 9600Mhz SMOD=0 fosc=11.0592Mhz
 * (SMOD=1 ʱ PCON=0X80 Ҫд��)
 *�����ֵ
 *������=��2^SMOD/32��*(fosc/((256-X)*12))
 *
 * */
#include "reg52.h"
#define  uc unsigned  char
#define  ui unsigned  int
//��ʼ������
void init()
{

    TMOD=0x20;//�ö�ʱ��1 ��ʽ2 �Զ���װ��ֵ M1=1 M0=0
    TH1=253;//�����ֵ  ������9600bpsʱ
    TL1=253;//�Ͱ�λ���Բ�����
    TR1=1;//������ʱ��T1

    SM0=0;//ʹ��SCON��ʽһ
    SM1=1;
    REN=1;//�������ڽ�������

    //SCON�ṹ SM1 SM1 SM2 REN TB8 RB8 TI RI
    //Ҳ���� SCON=0X50

    //ʹ�ò�ѯ��ʽ

}
void delay(ui z)
{
    ui a,b;
    for ( a=z;a>0;a--)
        for( b=110;b>0;b--);
}
void sendbyte(uc dat)
{
   //���͵����ַ���PC��
   SBUF=dat;
   while (!TI);//TI=0 ʱһֱ�ȴ�
   TI=0;//�ֶ��������жϱ�־λ����
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
    sendstr("A");
    delay(500);
    sendstr("B");
    while (1);
}


