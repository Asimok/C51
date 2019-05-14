/*
数码管每间隔一秒右移一位 并且数值加一 依次显示0-8
*/

#include "reg52.h"
#define ui unsigned int

sbit wela =P2^1;//定义引脚
sbit dula =P2^0;

/*------------------------------------------------
                   查表表格
------------------------------------------------*/
unsigned char code table[]={    0x3F,0x06,0x5B,0x4F,
												 	 			0x66,0x6D,0x7d,0x07,
						  									0x7f,0x6f,0x77,0x7C,
						  									0x39,0x5E,0x79,0x71 }	;
																//共阴数码管0~F

  //低电平选中数码管 从左到右最左边的为最低位 即第一个数码管为最低位
	//低位--->高位
																//1110 1111 
unsigned char code shumaguan[]={ 0xfe,0xfd,0xfb,0xf7,
																 0xef,0xdf,0xbf,0x7f   }	;
																//从左到右点亮
						
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
	for(i=1;i<9;i++)   //加入 for循环，表明for循环大括号中的程序循环
                     //执行16次，表明表格中有16个元素
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