#include <reg51.h>
#include <intrins.h>
#define ui unsigned	int
void delay(ui z)
{
	ui a,b;
	for(a=z;a>0;a--)
		for(b=110;b>0;b--);
}
void main()
{
	P0=0X01;
	while(1)
	{
		delay(1000);
		P0=_crol_(P0,1);
	}
}