#include"reg51.h" 
#define ui unsigned int 
sbit wela=P2^1;
sbit dula=P2^0;
sbit led=P3^0;

void delay()
{
ui x,b;
 for( x=1000;x>0;x--)
 	for( b=110;b>0;b--);
 
}
void main()
{
   led=0;

  	//位选
//低电平选中
//第2468块 0101 0101
	wela=1;
	P0=0xaa;
	wela=0;

//段选
	//dp g f e d c b a
	//高电平灯亮 
	dula=1;
	P0=0X5B;
	dula=0;
	delay();


//死循环
	while(1);



}
