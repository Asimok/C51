/*
����ܶ�̬��ʾ 1357����ܶ�̬��ʾ1357 
��ʱ����ʵ��
*/
#include"reg52.h"
sbit wela=P2^0;
sbit dula=P2^1;
#define ui unsigned int
#define uc unsigned char
uc qian, bai,shi,ge;
/*------------------------------------------------
                  ��������� 0-F
------------------------------------------------*/
unsigned char code table[]={    0x3f,0x06,0x5b,0x4f,
                                0x66,0x6d,0x7d,0x07,
                                0x7f,0x6f,0x77,0x7c,
                                0x39,0x5e,0x79,0x71

						  }	  ;
ui shu =1357;                        
void delay(ui z);
void display(uc qian,uc bai,uc shi,uc ge);
void separate(ui);
void main()
{
    separate(shu);
    while(1)
    {
         display( qian, bai, shi, ge);
    }
}
void delay(ui z)
{
    ui a,b;
    for(a=z;a>0;a--)
    	for(b=110;b>0;b--);
} 
void display(uc qian,uc bai,uc shi,uc ge)
{
    //��һ������� 0111 1111 ��ʾ 1 ǧλ 
    
   
    dula=1;
    P0=table[qian];
    dula=0;
	wela=1;
    P0=0xfe;
    wela=0;
	delay(1);

//����������� 1101 1111 ��ʾ 3 ��λ
   
    dula=1;
    P0=table[bai];
    dula=0;
	 wela=1;
    P0=0xfb;
    wela=0;
    delay(1);

//���������� 1111 0111 ��ʾ 5 ʮλ
    
    dula=1;
    P0=table[shi];
    dula=0;
	wela=1;
    P0=0xef;
    wela=0;
    delay(1);

    //���߸������ 1111 1101 ��ʾ 7 ��λ 
   
    dula=1;
    P0=table[ge];
    dula=0;
	wela=1;
    P0=0xbf;
    wela=0;
    delay(1);
}
void separate(ui num)
{
//����4λ��
    qian=num/1000;
    bai=num%1000/100;
    shi=num%100/10;
    ge=num%10;
}