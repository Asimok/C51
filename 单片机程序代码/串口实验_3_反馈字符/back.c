/*
 * PC������һ���ַ�����Ƭ�� ��Ƭ���յ����ٷ���PC��
 *
 * */
#include "reg52.h"
#define uc unsigned char
//��ʼ������
void init()
{
    //SMOD=1 ʱ PCON=0X80 Ҫд��
    PCON=0X80;
    TMOD=0x20;//�ö�ʱ��1 ��ʽ2 �Զ���װ��ֵ M1=1 M0=0
    TH1=244;//�����ֵ  ������4800bpsʱ
    TL1=244;//�Ͱ�λ���Բ�����
    TR1=1;//������ʱ��T1

    SM0=0;//ʹ��SCON��ʽһ
    SM1=1;
    REN=1;//�������ڽ�������

    //SCON�ṹ SM1 SM1 SM2 REN TB8 RB8 TI RI
    //Ҳ���� SCON=0X50

    //�жϷ�ʽ
    EA=1;
    ES=1;
}
void sendbyte(uc date)
{
    //���͵����ַ���PC��
    SBUF=date;
    while (!TI);//TI=0 ʱһֱ�ȴ�
    TI=0;//�ֶ��������жϱ�־λ����
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
RI=0;//�������жϱ�־λ �ֶ�����
temp=SBUF;//��SBUF�е�����ȡ����
P0=temp;
sendbyte(temp);
}
if(TI)
    TI=0;//�������жϱ�־λ�ֶ�����
}
