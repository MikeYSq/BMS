#ifndef   __MOTOR_H__
#define   __MOTOR_H__

sbit  LED=P1^0;    //�жϵ�led


 
 
#define   PWM_MAX     200    //���ռ�ձ�

#define   PWM_LOW     100    //����
#define   PWM_HIG     50      //����
#define   PWM_STOP    200     //ֹͣ



void     motor_adv();  //ǰ��
void     motor_ret();  // ����
void     motor_r();    //��ת
void     motor_l();    //��ת
void     motor_s();    //ֹͣ


#endif