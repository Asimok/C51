/*
独立按键的延时抖动，以及消除抖动
最后一个数码管显示0-10
*/
#include "reg52.h"
/*------------------------------------------------
				  共阴数码管 0-F
------------------------------------------------*/
unsigned char code table[] = { 0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71
};
#define uc unsigned char 
#define ui unsigned int 
sbit dula = P2 ^ 0;
sbit wela = P2 ^ 1;
sbit key = P1 ^ 0;
uc num = 0;
void delay(ui a)
{
	ui b,c;
	for (b = a; b > 0; b--)
		for (c = 110; c > 0; c--);
}

void main()
{
	//选中最后一个数码管 1111 1110
	wela = 1;
	P0 = 0x7f;
	wela = 0;

	key = 1;
	while (1)
	{
		if (key == 0)//消除抖动
		{
			//delay(10);//通过延时消除抖动
		//	if (key == 0)//再次判断是否真的有按键被按下，如果按键被按下
			//{
				num++;
				if (num == 10)
					num = 0;
				while (!key);//如果按键没有被松开，一直循环
		//	}
		}
		dula = 1;
		P0 = table[num];
		dula = 0;


	}

}