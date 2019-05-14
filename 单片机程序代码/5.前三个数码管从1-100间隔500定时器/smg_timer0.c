/*
前三个数码管显示0-100
定时器0实现
*/
#include"reg52.h"
sbit wela=P2^0;
sbit dula=P2^1;
#define ui unsigned int
#define uc unsigned char
uc  bai,shi,ge,time=0;
/*------------------------------------------------
                  共阴数码管 0-F
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

//第一个数码管 0111 1111 显示 百位
       
    P0=0xfe;  wela=1;
    wela=0;
	dula=1;
    P0=table[bai];
    dula=0;
 
 	delay(1);

	
    P0=0xfd;   	wela=1;
    wela=0;//第二个数码管 1011 1111 显示 十位
    dula=1;
    P0=table[shi];
    dula=0;

	delay(1); 


    P0=0xfb; 	wela=1;
    wela=0;
    //第三个数码管 1101 1111 显示  个位 
    dula=1;
    P0=table[ge];
    dula=0;
	
	delay(1);
}
void separate(ui num)
{
//分离3位数
    bai=num/100;
    shi=num%100/10;
    ge=num%100%10;
}
void inittimer0()
{
    TMOD=0X01;
    TH0=(65536-50000)/256;  //定时50ms
    TL0=(65536-50000)%256;

    EA=1; //总中断
    ET0=1;  //T0中断
    TR0=1;  //开启T0
}
void timer0() interrupt 1
{
    TH0=(65536-50000)/256;  //定时50ms
    TL0=(65536-50000)%256;
    time++;
    
   
}