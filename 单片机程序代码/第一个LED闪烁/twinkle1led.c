#include  <reg51.h>
#define ui unsigned int 
void delay(ui x)
{
	ui a,b;
	for(a=x;a>0;a--)
		for(b=110;b>0;b--);
}

void main()
{
	while(1)
	{
		P0=0XFE;
		delay(1000);
		P0=0xFF;
		delay(1000);
	}
	
}