									   /*
 * ��Ƭ������һ�����ݣ���LED��֤���յ������� ������ 4800 SMOD=1  fosc=11.0592Mhz
 *�����ֵ
 *������=��2^SMOD/32��*(fosc/((256-X)*12))
 *
 * */
#include "reg52.h"
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
    P0=SBUF;

}
}
