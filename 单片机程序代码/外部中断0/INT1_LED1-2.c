#include "reg52.h"
#define ui unsigned int
//�ⲿ�ж� �͵�ƽ����
sbit LED1 = P2 ^ 2;
sbit LED2 = P2 ^ 3;
void Init_INT0(void)
{
	IT0 = 1;//�½���
	EA = 1;            //���жϴ�
	EX0 = 1;           //�ⲿ�ж�0��
}
void delay(ui z)
{
	ui a, b;
	for (a = z; a > 0; a--)
		for (b = 110; b > 0; b--);
}
void main()
{

	Init_INT0();
	delay(1000);
    LED1 = 0;
    LED2 = 1;
	
}
void int0() interrupt 0
{
	LED1 = 1;
    LED2 = 0;
}

