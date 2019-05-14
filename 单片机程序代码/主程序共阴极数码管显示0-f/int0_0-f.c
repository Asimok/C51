#include "reg52.h"
#define ui unsigned int
//�ⲿ�ж� �͵�ƽ����
sbit wela = P2 ^ 1;
sbit dula = P2 ^ 0;
sbit LED = P2 ^ 2;
/*------------------------------------------------
				   ������ʾ0-F
------------------------------------------------*/
unsigned char code table[] = { 0x3F,0x06,0x5B,0x4F,
						  0x66,0x6D,0x7d,0x07,
						  0x7f,0x6f,0x77,0x7C,
						  0x39,0x5E,0x79,0x71
};
void delay(ui z)
{
	ui a, b;
	for (a = z; a > 0; a--)
		for (b = 110; b > 0; b--);
}
void Init_INT0(void)
{
	IT0 = 0;//�͵�ƽ
	EA = 1;            //���жϴ�
	EX0 = 1;           //�ⲿ�ж�0��
}
void main()
{
	ui i;
	
	Init_INT0();
//��λ--->��λ
	wela = 1;
	P0 = 0x00;
	wela = 0;

		  while(1){
	for (i = 0; i < 16; i++)  		
	{			  	
	    LED = 1;
		delay(500);
		P0 = table[i];
	}
	}
}
void int0() interrupt 0
{
	LED = 0;
	delay(2000);
}

