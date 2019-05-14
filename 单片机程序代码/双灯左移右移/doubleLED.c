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
	uc i;//用作循环
	uc temp;//中间变量

	while(1)
	{
		temp=0XFC; //1111 1100  第一二个灯亮
		P1=temp;
		for(i=0;i<8;i++)
		{
			//移动八位
			delay(5000);
			temp=temp<<1; //1111 1000 左移一位
			temp=temp|0x01;  //位或 1111 1001 保证每次只亮两个灯
			P1=temp;//不直接用P1 防止闪烁
		}
		//循环8次后 0000 0000
		//从左端开始右移
		//0011 1111
		temp=0x3f;
		P1=temp;

		for(i=0;i<8;i++)
		{
			//移动八位
			delay(5000);
			temp=temp>>1; //0001 1111 左移一位
			temp=temp|0x80;  //位或 1001 1111 保证每次只亮两个灯
			P1=temp;//不直接用P1 防止闪烁
		}

		 for(i=0;i<3;i++)   
            //闪烁三次        
		 {
			  P1=0xff;	//全灭
				delay(5000);
			  P1=0x00;	//全亮
			 	delay(5000);
		 }               
	}


}
