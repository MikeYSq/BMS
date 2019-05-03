/*------------------------------
/*PWM:周期一定，i<50,    输出1

                i>=50,   输出0
i每次加1      加到100，复位为0 .
-------------------------------*/
//定时器0  输出pwm

//定时器1  决定功能
#include <reg52.H>
#include "scan.h"
#include "motor.h"


 
#define   uchar   unsigned     char
#define   uint    unsigned     int
	

extern     Indata;       // 初始值PWM

extern     Indata1;       //初始值PWM1 


sbit  PWM=P2^0;    //pwm输出角
sbit  PWM1=P2^1;   //pwm输出脚


uchar  fuc;


//sbit  key=P3^0;   //  按键加

int    Temp0,Temp1; //pwm输出的中间值






uint  PWM_i=0,PWM_j=0;



//延时
void  Delay_Ms(uchar ms)
{
   int   i;
	while(ms--)
		for(i=0;i<40;i++);
}






//IO口初始化
void   IO_init()
{
P3=0XFF;
P2=0XFF;
LED=0;
}




//T0初始化
void   T0_init()
{
TMOD=0x01;  //T0方式1
//TH0=(65536-100)/256;
//TL0=(65536-100)%256;
ET0=1;
TR0=0;	
}



//T1初始化
void  T1_init()
{

TMOD=0x10;  //T0方式1
//TH1=(65536-100)/256;
//TL1=(65536-100)%256;
ET1=1;
TR1=0;
}



//主函数
void  main()
{
	IO_init();//io口初始化
	T0_init();//T0初始化设置
	T1_init();//T1初始化设置	
	EA=1;     //开总中断	
	PT1=1;    //定时器1中断优先	
	
while(1)
	{
	 
	if(P3!=0xff)   //fuc=P3
	{
		  fuc=P3;
		while(P3!=0xff); //按键扫描到这  //怎么给P3
		 //LED=!LED;
      TR1=1;
	}		
 }
}		


//按键扫描后进入T1，进行功能选择
 
//T1中断服务函数
void   T1_IRQ()interrupt 3 using 2
{	
	//LED=!LED;
TH0=(65536-100)/256;  
TL0=(65536-100)%256;
 	// LED=!LED;
   
switch(fuc)     //按键扫描
 {
   case  0xfe:       motor_adv();break;  //改变一个全局变量
	 case  0xfd:       motor_ret();break;
	 case  0xfb:       motor_r();break;
	 case  0xf7:       motor_l();break;
	 case  0xef:       motor_s();break;	 
	 default:          motor_s();break; 
	 
	 
     }
  TR0=1;
  TR1=0;
  }






//T0中断服务函数  pwm
void   T0_IRQ()interrupt 1 using 1
{
	//extern  uchar    Indata;         // 初始值PWM  //外部来的   indata.  //声明已被定义的外部变量
 // extern  uchar   Indata1;        //初始值PWM1   //外部来的  indata1.
	//LED=!LED;

//	if(Indata==50)  LED=1;
	
TH0=(65536-100)/256;  
TL0=(65536-100)%256;

	
//一号电机
if(PWM_i>=PWM_MAX)   PWM_i=0;      //200*100=20000=20ms  实际>20ms
	
if(PWM_i<Indata)    PWM=1;
	
else
	PWM=0;

  PWM_i++;


//2号电机
if(PWM_j>=PWM_MAX)   PWM_j=0;      //200*100=20000=20ms  实际>20ms
	
if(PWM_j<Indata1)    PWM1=1;

else
	   PWM1=0;
     PWM_j++;   


}




							
							