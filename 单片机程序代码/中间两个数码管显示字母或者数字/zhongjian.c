#include "reg52.h"
#define ui unsigned int

sbit wela =P2^1; //定义引脚
sbit dula =P2^0;

/*------------------------------------------------
                   查表表格
------------------------------------------------*/
unsigned char code table[]={    0x3F,0x06,0x5B,0x4F,
						 		0x66,0x6D,0x7d,0x07,
						  		0x7f,0x6f,0x77,0x7C,
						  		0x39,0x5E,0x79,0x71
						  }	  ;
						//依次为0~F
						//0011 1111  输出为 1 点亮数码管的一段

void delay(ui z)
{
    ui a,b;
    for(a=z;a>0;a--)
    	for(b=110;b>0;b--);
} 

void main()
{
     ui i=0;
	//位选数码管1110 0111
	//0 选中中间两个数码管	 低电平选中数码管 高电平使得数码管的一段点亮
	//低位--->高位  反着来 从左到右 第一个数码管为最低位
	wela=1;
	P0=0xe7;
	wela=0;
	while(1)
	{
	for(i=0;i<16;i++)  
	    {
	    	 delay(1000);
			 //送段码
			 dula=1;
		     P0=table[i];
			 dula=0;
	    }

	
	
	}
}