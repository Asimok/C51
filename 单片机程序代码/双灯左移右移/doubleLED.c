#include "reg52.h"
#define uc unsigned int

void delay(uc a)
{
	uc b,c;
	for(b=a;b>0;b--)
		for(c=110;c>0;c--);
}

void main()
{
	uc i;//����ѭ��
	uc temp;//�м����

	while(1)
	{
		temp=0XFC; //1111 1100  ��һ��������
		P1=temp;
		for(i=0;i<8;i++)
		{
			//�ƶ���λ
			delay(5000);
			temp=temp<<1; //1111 1000 ����һλ
			temp=temp|0x01;  //λ�� 1111 1001 ��֤ÿ��ֻ��������
			P1=temp;//��ֱ����P1 ��ֹ��˸
		}
		//ѭ��8�κ� 0000 0000
		//����˿�ʼ����
		//0011 1111
		temp=0x3f;
		P1=temp;

		for(i=0;i<8;i++)
		{
			//�ƶ���λ
			delay(5000);
			temp=temp>>1; //0001 1111 ����һλ
			temp=temp|0x80;  //λ�� 1001 1111 ��֤ÿ��ֻ��������
			P1=temp;//��ֱ����P1 ��ֹ��˸
		}

		 for(i=0;i<3;i++)   
            //��˸����        
		 {
			  P1=0xff;	//ȫ��
				delay(5000);
			  P1=0x00;	//ȫ��
			 	delay(5000);
		 }               
	}


}
