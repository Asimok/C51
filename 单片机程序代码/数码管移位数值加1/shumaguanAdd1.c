/*
�����ÿ���һ������һλ ������ֵ��һ ������ʾ0-8
*/

#include "reg52.h"
#define ui unsigned int

sbit wela =P2^1;//��������
sbit dula =P2^0;

/*------------------------------------------------
                   �����
------------------------------------------------*/
unsigned char code table[]={    0x3F,0x06,0x5B,0x4F,
												 	 			0x66,0x6D,0x7d,0x07,
						  									0x7f,0x6f,0x77,0x7C,
						  									0x39,0x5E,0x79,0x71 }	;
																//���������0~F

  //�͵�ƽѡ������� ����������ߵ�Ϊ���λ ����һ�������Ϊ���λ
	//��λ--->��λ
																//1110 1111 
unsigned char code shumaguan[]={ 0xfe,0xfd,0xfb,0xf7,
																 0xef,0xdf,0xbf,0x7f   }	;
																//�����ҵ���
						
void delay(ui z)
{
    ui a,b;
    for(a=z;a>0;a--)
    	for(b=110;b>0;b--);
} 

void main()
{
     ui i=1;

	while(1)
	{	
	for(i=1;i<9;i++)   //���� forѭ��������forѭ���������еĳ���ѭ��
                     //ִ��16�Σ������������16��Ԫ��
	    {
					wela=1;
					P0=shumaguan[i-1];
					wela=0;
					delay(1000);
					dula=1;
					P0=table[i];
					dula=0;
	    }

	
	
	}
}