#include <reg52.h>
#include "motor.h"

unsigned int   Indata;
unsigned int   Indata1;



 
//ǰ��   
void  motor_adv()
{
	 //LED=!LED;
	Indata=PWM_HIG;
	Indata1=PWM_HIG;
}


//����
void    motor_ret()
{
	 //LED=!LED;
  Indata=PWM_HIG;
	Indata1=PWM_HIG;

}


//��ת
void   motor_r()
{
	 LED=!LED;
  Indata=PWM_STOP;
	Indata1=PWM_HIG;


}

//��ת
void   motor_l()
{
	  //LED=!LED;
  Indata=PWM_HIG;
	Indata1=PWM_STOP;

}


//ֹͣ
void    motor_s()
{
	 //LED=!LED;
  Indata=PWM_STOP;
	Indata1=PWM_STOP;
}












