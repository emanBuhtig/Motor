
#ifndef GLOBAL_H
#define GLOBAL_H

#define BV(bit)				(1<<(bit))
#define sbi(reg,bit)		reg |= (BV(bit))
#define cbi(reg,bit)		reg &= ~(BV(bit))
//#define inb(reg)			(reg)
//#define outb(reg,bit)		(reg = bit)
#define POWER_MANAGEMENT_ENABLED

struct GLOBAL_FLAGS {
	   				 unsigned char Order_Flag;
					 unsigned char Motor_Run_Flag;
					 unsigned char Stopit;
					 //signed char Stop_num[4];
					};
typedef struct {
			    unsigned int tray_shot_position;
			   } system_Constant;

extern system_Constant sysCon;
					
#define TRUE 1
#define FALSE 0

#define EEP_TSHOT 0x1					

#endif