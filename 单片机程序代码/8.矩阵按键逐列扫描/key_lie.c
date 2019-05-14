/*
逐列扫描
矩阵按键的延时抖动，以及消除抖动
最后三个数码管显示1-16的平方11
平方表
1 4 9 16
25 36 49 64
81 100 121 144
169 196 225 256
x x x x
x x x x
x x x x
x x x x
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
ui shu = 0;
uc bai, shi, ge ,temp;
void delay(ui a)
{
	ui b, c;
	for (b = a; b > 0; b--)
		for (c = 110; c > 0; c--);
}
ui 	keyscan();
void display(ui ,ui  ,ui );
void separate(ui);
void main()
{
	while (1)
	{
	
		separate(keyscan());
	   	display(bai,shi,ge);
	//display(1,2,3);
	}

}

void display(ui b,ui s,ui g)
{
	
	// //分离3位数
    // bai=num/100;
    // shi=num%100/10;
    // ge=num%100%10;

	P0 = 0xfe; //第一个数码管 0111 1111 显示 百位
	wela = 1; //先送位码
	wela = 0;
	dula = 1;
	P0 = table[b];
	dula = 0;
	delay(1);


	P0 = 0xfd; //第二个数码管 1011 1111 显示 十位
	wela = 1;
	wela = 0;
	dula = 1;
	P0 = table[s];
	dula = 0;
	delay(1);


	P0 = 0xfb; 	//第三个数码管 1101 1111 显示  个位
	wela = 1;
	wela = 0; 
	dula = 1;
	P0 = table[g];
	dula = 0;
	delay(1);
}
ui keyscan()
{
	//高四位 列 ； 低四位 行
		//第一列………………第一行
		//1111 1111
	P3 = 0x7f;//选中第一列 0111 1111
	//低四位做输入要先被拉成高电平
	temp = P3;
	temp = temp & 0x0f;//判断有没有某一行按键被按下
	while (temp != 0x0f)//P3的值发生改变说明有按键被按下
	{
		delay(10);//通过延时消除抖动
		while (temp != 0x0f)//再次判断
		{
			temp = P3;
			switch(temp) {

				case 0x7e://选中（1，1）
			{
					shu=1;
					break; }
				
				case 0x7d://选中（2，1）
				
					shu=25;
					break;
				
				case 0x7b://选中（3，1）
				
					shu=81;
					break;
				
				case 0x77://选中（4，1）
				
					shu=169;
					break;
				
			}
			
while (temp != 0x0f)   //按键被按下
					{
						temp = P3;
						temp = temp & 0x0f;
						display(bai,shi,ge);

						}
						}
	}
	/////////////////////////////////////////
	P3 = 0xbf;//选中第二列 1011 1111
	temp = P3;
	temp = temp & 0x0f;//判断有没有某一列按键被按下
	while (temp != 0x0f)//P3的值发生改变说明有按键被按下
	{
		delay(10);//通过延时消除抖动
		while (temp != 0x0f)//再次判断
		{
			temp = P3;
			switch(temp) {

				case 0xbe://选中（1，2）
			
				shu=4;
					break;
				
				case 0xbd://选中（2，2）
			
				shu=36;
					break;
				
				case 0xbb://选中（3，2）
				
				shu=100;
					break;
				
				case 0xb7://选中（4，2）
				shu=196;
					break;
				
			}
			while (temp != 0x0f)
					{
						temp = P3;
						temp = temp & 0x0f;
						display(bai,shi,ge);
						}
		}
	}
	/////////////////////////////////////////
	P3 = 0xdf;//选中第三列 1101 1111
	temp = P3;
	temp = temp & 0x0f;//判断有没有某一列按键被按下
	while (temp != 0x0f)//P3的值发生改变说明有按键被按下
	{
		delay(10);//通过延时消除抖动
		while (temp != 0x0f)//再次判断
		{
			temp = P3;
			switch(temp) {

				case 0xde://选中（1，3）
				
				shu=9;
					break;
				
				case 0xdd://选中（2，3）
				
				shu=49;
					break;
				
				case 0xdb://选中（3，3）
				
				shu=121;
					break;
				
				case 0xd7://选中（4，3）
				
				shu=225;
					break;
				
			}
			while (temp != 0x0f)
					{
						temp = P3;
						temp = temp & 0x0f;
						display(bai,shi,ge);
						}
		}
	}
	   	/////////////////////////////////////////
	P3 = 0xef;//选中第四列 1110 1111
	temp = P3;
	temp = temp & 0x0f;//判断有没有某一列按键被按下
	while (temp != 0x0f)//P3的值发生改变说明有按键被按下
	{
		delay(10);//通过延时消除抖动
		while (temp != 0x0f)//再次判断
		{
			temp = P3;
			switch(temp) {

				case 0xee://选中（1,4）
				
				shu=16;
					break;
				
				case 0xed://选中（2,4）
				
				shu=64;
					break;
				
				case 0xeb://选中（3，4）
			
				shu=144;
					break;
				
				case 0xe7://选中（4，4）
				
				shu=256;
					break;
			}
				while (temp != 0x0f)
					{
						temp = P3;
						temp = temp & 0x0f;
						display(bai,shi,ge);
						}
		}
	}
   return shu;
}
void separate(ui num)
{
//分离3位数
    bai=num/100;
    shi=num%100/10;
    ge=num%100%10;
}