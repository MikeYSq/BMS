/*------------------------------
/*PWM:����һ����i<50,    ���1

                i>=50,   ���0
iÿ�μ�1      �ӵ�100����λΪ0 .
-------------------------------*/
//��ʱ��0  ���pwm

//��ʱ��1  ��������
#include <reg52.H>
#include "scan.h"
#include "motor.h"


 
#define   uchar   unsigned     char
#define   uint    unsigned     int
	

extern     Indata;       // ��ʼֵPWM

extern     Indata1;       //��ʼֵPWM1 


sbit  PWM=P2^0;    //pwm�����
sbit  PWM1=P2^1;   //pwm�����


uchar  fuc;


//sbit  key=P3^0;   //  ������

int    Temp0,Temp1; //pwm������м�ֵ






uint  PWM_i=0,PWM_j=0;



//��ʱ
void  Delay_Ms(uchar ms)
{
   int   i;
	while(ms--)
		for(i=0;i<40;i++);
}






//IO�ڳ�ʼ��
void   IO_init()
{
P3=0XFF;
P2=0XFF;
LED=0;
}




//T0��ʼ��
void   T0_init()
{
TMOD=0x01;  //T0��ʽ1
//TH0=(65536-100)/256;
//TL0=(65536-100)%256;
ET0=1;
TR0=0;	
}



//T1��ʼ��
void  T1_init()
{

TMOD=0x10;  //T0��ʽ1
//TH1=(65536-100)/256;
//TL1=(65536-100)%256;
ET1=1;
TR1=0;
}



//������
void  main()
{
	IO_init();//io�ڳ�ʼ��
	T0_init();//T0��ʼ������
	T1_init();//T1��ʼ������	
	EA=1;     //�����ж�	
	PT1=1;    //��ʱ��1�ж�����	
	
while(1)
	{
	 
	if(P3!=0xff)   //fuc=P3
	{
		  fuc=P3;
		while(P3!=0xff); //����ɨ�赽��  //��ô��P3
		 //LED=!LED;
      TR1=1;
	}		
 }
}		


//����ɨ������T1�����й���ѡ��
 
//T1�жϷ�����
void   T1_IRQ()interrupt 3 using 2
{	
	//LED=!LED;
TH0=(65536-100)/256;  
TL0=(65536-100)%256;
 	// LED=!LED;
   
switch(fuc)     //����ɨ��
 {
   case  0xfe:       motor_adv();break;  //�ı�һ��ȫ�ֱ���
	 case  0xfd:       motor_ret();break;
	 case  0xfb:       motor_r();break;
	 case  0xf7:       motor_l();break;
	 case  0xef:       motor_s();break;	 
	 default:          motor_s();break; 
	 
	 
     }
  TR0=1;
  TR1=0;
  }






//T0�жϷ�����  pwm
void   T0_IRQ()interrupt 1 using 1
{
	//extern  uchar    Indata;         // ��ʼֵPWM  //�ⲿ����   indata.  //�����ѱ�������ⲿ����
 // extern  uchar   Indata1;        //��ʼֵPWM1   //�ⲿ����  indata1.
	//LED=!LED;

//	if(Indata==50)  LED=1;
	
TH0=(65536-100)/256;  
TL0=(65536-100)%256;

	
//һ�ŵ��
if(PWM_i>=PWM_MAX)   PWM_i=0;      //200*100=20000=20ms  ʵ��>20ms
	
if(PWM_i<Indata)    PWM=1;
	
else
	PWM=0;

  PWM_i++;


//2�ŵ��
if(PWM_j>=PWM_MAX)   PWM_j=0;      //200*100=20000=20ms  ʵ��>20ms
	
if(PWM_j<Indata1)    PWM1=1;

else
	   PWM1=0;
     PWM_j++;   


}




							
							