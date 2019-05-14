#include <reg51.h>
#define ui unsigned int

void delay(ui z)
{
	ui a,b;
	for(a=z;a>0;a--)
		for(b=110;b>0;b--);
}
void main()
{
	unsigned char i;
	P0=0X01;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			delay(1000);
			P0<<=1;
			P0=P0|0X01;
		}
			P0=0X01;
	}

}