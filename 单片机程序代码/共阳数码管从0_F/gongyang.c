/*
�����������ʾ0~F ���һ��
ע�⽫���߽ӵ���������� 
*/

#include "reg52.h"
#define ui unsigned int
/*------------------------------------------------
                   ��������ܱ��
------------------------------------------------*/
unsigned char code table[]={    0xc0,0xf9,0xa4,0xb0,
						  								    	0x99,0x92,0x82,0xf8,
						 										0x80,0x90,0x88,0x83,
						 										0xc6,0xa1,0x86,0x8e
						  }	  ;
						

void delay(ui z)
{
    ui a,b;
    for(a=z;a>0;a--)
    	for(b=110;b>0;b--);
} 

void main()
{
  ui i;
	while(1)
	{

	for(i=0;i<16;i++)   
	    {
	    	 delay(1000);
		     P0=table[i];
			 //1001 0000
			// P0=0xc0;
	    }

	}
}