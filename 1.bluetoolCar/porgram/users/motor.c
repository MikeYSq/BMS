#include <reg52.h>
#include "motor.h"

unsigned int   Indata;
unsigned int   Indata1;



 
//前进   
void  motor_adv()
{
	 //LED=!LED;
	Indata=PWM_HIG;
	Indata1=PWM_HIG;
}


//后退
void    motor_ret()
{
	 //LED=!LED;
  Indata=PWM_HIG;
	Indata1=PWM_HIG;

}


//左转
void   motor_r()
{
	 LED=!LED;
  Indata=PWM_STOP;
	Indata1=PWM_HIG;


}

//右转
void   motor_l()
{
	  //LED=!LED;
  Indata=PWM_HIG;
	Indata1=PWM_STOP;

}


//停止
void    motor_s()
{
	 //LED=!LED;
  Indata=PWM_STOP;
	Indata1=PWM_STOP;
}












