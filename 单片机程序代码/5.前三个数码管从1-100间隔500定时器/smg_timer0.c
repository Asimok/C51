/*
ǰ�����������ʾ0-100
��ʱ��0ʵ��
*/
#include"reg52.h"
sbit wela=P2^0;
sbit dula=P2^1;
#define ui unsigned int
#define uc unsigned char
uc  bai,shi,ge,time=0;
/*------------------------------------------------
                  ��������� 0-F
------------------------------------------------*/
unsigned char  code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

ui shu =0;                        
void delay(ui z);
void display();
void separate(ui);
void inittimer0();
void main()
{
    inittimer0();
    while(1)
    {	 
        	     
         if(time==10)
         {	 separate(shu); 
		 	 shu++;
		     if(shu>100)
				 shu=0;
             time=0;      
		  }	  	
		  display();
    }
}
void delay(ui z)
{
    ui a,b;
    for(a=z;a>0;a--)
    	for(b=110;b>0;b--);
} 
void display()
{

//��һ������� 0111 1111 ��ʾ ��λ
       
    P0=0xfe;  wela=1;
    wela=0;
	dula=1;
    P0=table[bai];
    dula=0;
 
 	delay(1);

	
    P0=0xfd;   	wela=1;
    wela=0;//�ڶ�������� 1011 1111 ��ʾ ʮλ
    dula=1;
    P0=table[shi];
    dula=0;

	delay(1); 


    P0=0xfb; 	wela=1;
    wela=0;
    //����������� 1101 1111 ��ʾ  ��λ 
    dula=1;
    P0=table[ge];
    dula=0;
	
	delay(1);
}
void separate(ui num)
{
//����3λ��
    bai=num/100;
    shi=num%100/10;
    ge=num%100%10;
}
void inittimer0()
{
    TMOD=0X01;
    TH0=(65536-50000)/256;  //��ʱ50ms
    TL0=(65536-50000)%256;

    EA=1; //���ж�
    ET0=1;  //T0�ж�
    TR0=1;  //����T0
}
void timer0() interrupt 1
{
    TH0=(65536-50000)/256;  //��ʱ50ms
    TL0=(65536-50000)%256;
    time++;
    
   
}