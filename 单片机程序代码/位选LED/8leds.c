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

  	//λѡ
//�͵�ƽѡ��
//��2468�� 0101 0101
	wela=1;
	P0=0xaa;
	wela=0;

//��ѡ
	//dp g f e d c b a
	//�ߵ�ƽ���� 
	dula=1;
	P0=0X5B;
	dula=0;
	delay();


//��ѭ��
	while(1);



}
