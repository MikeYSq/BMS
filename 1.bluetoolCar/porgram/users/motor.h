#ifndef   __MOTOR_H__
#define   __MOTOR_H__

sbit  LED=P1^0;    //判断的led


 
 
#define   PWM_MAX     200    //最大占空比

#define   PWM_LOW     100    //低速
#define   PWM_HIG     50      //高速
#define   PWM_STOP    200     //停止



void     motor_adv();  //前进
void     motor_ret();  // 后退
void     motor_r();    //右转
void     motor_l();    //左转
void     motor_s();    //停止


#endif