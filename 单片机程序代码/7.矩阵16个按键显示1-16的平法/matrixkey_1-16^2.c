/*
����ɨ��
���󰴼�����ʱ�������Լ���������
��������������ʾ1-16��ƽ��
ƽ���� 
1 4 9 16 
25 36 49 64 
81 100 121 144 
169 196 225 256
*/
#include "reg52.h"
/*------------------------------------------------
				  ��������� 0-F
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
uc temp;
ui bai,shi, ge;
ui keyscan();
void delay(ui);
void display(ui);
void main()
{

	while (1)
	{

		display(keyscan());
	}

}

void display(ui num)
{
	
	//����3λ��
    bai=num/100;
    shi=num%100/10;
    ge=num%100%10;

	P0 = 0xfe; //��һ������� 0111 1111 ��ʾ ��λ
	wela = 1; //����λ��
	wela = 0;
	dula = 1;
	P0 = table[bai];
	dula = 0;
	delay(1);


	P0 = 0xfd; //�ڶ�������� 1011 1111 ��ʾ ʮλ
	wela = 1;
	wela = 0;
	dula = 1;
	P0 = table[shi];
	dula = 0;
	delay(1);


	P0 = 0xfb; 	//����������� 1101 1111 ��ʾ  ��λ
	wela = 1;
	wela = 0; 
	dula = 1;
	P0 = table[ge];
	dula = 0;
	delay(1);
}
ui keyscan()
{
ui shu;
	//����λ �� �� ����λ ��
		//��һ�С�������������һ��
		//1111 1111
	P3 = 0xfe;//ѡ�е�һ�� 1111 1110
	//����λ������Ҫ�ȱ����ɸߵ�ƽ
	temp = P3;
	temp = temp & 0xf0;//�ж���û��ĳһ�а���������
	while (temp != 0xf0)//P3��ֵ�����ı�˵���а���������
	{
		delay(10);//ͨ����ʱ��������
		while (temp != 0xf0)//�ٴ��ж�
		{
			temp = P3;
			switch(temp) {

				case 0x7e://ѡ�У�1��1��
			
				shu=1;
					break;
				
				case 0xbe://ѡ�У�1��2��
				
				shu=4;
					break;
				
				case 0xde://ѡ�У�1��3��
				
				shu=9;
					break;
				
				case 0xee://ѡ�У�1��4��
				
				shu=16;
					break;
				
			//	default: break;
			}
				while (temp != 0xf0)
					{
						temp = P3;
						temp = temp & 0xf0;
						}
		}
	}
/////////////////////////////////////////
	P3 = 0xfd;//ѡ�еڶ��� 1111 1101
	temp = P3;
	temp = temp & 0xf0;//�ж���û��ĳһ�а���������
	while (temp != 0xf0)//P3��ֵ�����ı�˵���а���������
	{
		delay(10);//ͨ����ʱ��������
		while (temp != 0xf0)//�ٴ��ж�
		{
			temp = P3;
			switch(temp) {

				case 0x7d://ѡ�У�2��1��
				
				shu=25;
					break;
				
				case 0xbd://ѡ�У�2��2��
				
				shu=36;
					break;
				
				case 0xdd://ѡ�У�2��3��
				
				shu=49;
					break;
				
				case 0xed://ѡ�У�2��4��
				
				shu=64;
					break;
				
			//		default: break;
			}
				while (temp != 0xf0)
					{
						temp = P3;
						temp = temp & 0xf0;
						}
		}
	}
	/////////////////////////////////////////
	P3 = 0xfb;//ѡ�е����� 1111 1011
	temp = P3;
	temp = temp & 0xf0;//�ж���û��ĳһ�а���������
	while (temp != 0xf0)//P3��ֵ�����ı�˵���а���������
	{
		delay(10);//ͨ����ʱ��������
		while (temp != 0xf0)//�ٴ��ж�
		{
			temp = P3;
			switch(temp) {

				case 0x7b://ѡ�У�3��1��
				
					shu=81;
					break;
				
				case 0xbb://ѡ�У�3��2��
				
				shu=100;
					break;
				
				case 0xdb://ѡ�У�3��3��
				
				shu=121;
					break;
				
				case 0xeb://ѡ�У�3��4��
				
				shu=144;
					break;
				
			//		default: break;
			}
				while (temp != 0xf0)
					{
						temp = P3;
						temp = temp & 0xf0;
						}
		}
	}

	/////////////////////////////////////////
	P3 = 0xf7;//ѡ�е����� 1111 0111
	temp = P3;
	temp = temp & 0xf0;//�ж���û��ĳһ�а���������
	while (temp != 0xf0)//P3��ֵ�����ı�˵���а���������
	{
		delay(10);//ͨ����ʱ��������
		while (temp != 0xf0)//�ٴ��ж�
		{
			temp = P3;
			switch(temp) {

				case 0x77://ѡ�У�4��1��
				{
				shu=169;
					break;
				}
				case 0xb7://ѡ�У�4��2��
				{
								shu=196;
					break;
				}
				case 0xd7://ѡ�У�4��3��
				{
				shu=225;
					break;
				}
				case 0xe7://ѡ�У�4��4��
				{
					shu=256;
					break;
				}
			//		default: break;
			
			}
				while (temp != 0xf0)
					{
						temp = P3;
						temp = temp & 0xf0;
						}
		}
	}
	return shu;


}
void delay(ui a)
{
	ui b, c;
	for (b = a; b > 0; b--)
		for (c = 110; c > 0; c--);
}