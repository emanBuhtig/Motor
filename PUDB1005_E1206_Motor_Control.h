/*
Title : PUDB-1005 Stepper Motor Controller Driver Edition 1206
Publish Date : 
Programed by : IKS
Copyright : Pumyon, Inc.
Version : 1.0
*/

#ifndef PUDB1005_MOTOR_CONTROL_H
#define PUDB1005_MOTOR_CONTROL_H

#define MCU_SPEED 16000000
#define PRESCALE2 8
#define PRESCALE3 32
#define PRESCALE4 64
#define PRESCALE5 128
#define PRESCALE6 256
#define PRESCALE7 1024

//Motor Control Pin Assignment =================================================
//Motor1 : Enable = PA0, Dir = PC4, Clock = PA6
//Motor2 : Enable = PA1, Dir = PC5, Clock = PA7
//Motor3 : Enable = PA2, Dir = PC6, Clock = PC0
//Motor4 : Enable = PA3, Dir = PC7, Clock = PC1
//Motor5 : Enable = PA4, Dir = PB2, Clock = PC2
//Motor6 : Enable = PA5, Dir = PB3, Clock = PC3

//Switch Pin Assignment ========================================================
//J20=SW1:PB0 J21=SW2:PB4 J22=SW3:PB5 J23=SW4:PB6 J24=SW5:PB7
//-> PORTB&0b11110001 = PORTB&0xF1
//J25=SW6:PG3 J26=SW7:PG4 J27=SW8:PG1 J28=SW9:PG0 J29=SW10:PG2
//-> PORTG&0b00011111 = PORTG&0x1F

//Photointerrupt Pin Assignment ================================================
// J8=Photointerruptor1:PE2
// J9=Photointerruptor2:PE3
//J10=Photointerruptor3:PE4(INT4)
//J11=Photointerruptor4:PE5(INT5)
//J12=Photointerruptor5:PE6(INT6)
//J13=Photointerruptor6:PE7(INT7)

//Motor enable and disable =====================================================
#define MOT1_ENABLE PORTA|=0x01
#define MOT2_ENABLE PORTA|=0x02
#define MOT3_ENABLE PORTA|=0x04
#define MOT4_ENABLE PORTA|=0x08
#define MOT5_ENABLE PORTA|=0x10
#define MOT6_ENABLE PORTA|=0x20
#define MOTS_ENABLE PORTA|=0x3F

#define MOT1_DISABLE PORTA&=0xFE
#define MOT2_DISABLE PORTA&=0xFD
#define MOT3_DISABLE PORTA&=0xFB
#define MOT4_DISABLE PORTA&=0xF7
#define MOT5_DISABLE PORTA&=0xEF
#define MOT6_DISABLE PORTA&=0xDF
#define MOTS_DISABLE PORTA&=0xC0

//Motor direction definition ===================================================
#define MOT1_CW  PORTC|=0x10
#define MOT1_CCW PORTC&=0xEF
#define MOT2_CW  PORTC|=0x20 
#define MOT2_CCW PORTC&=0xDF
#define MOT3_CW  PORTC|=0x40
#define MOT3_CCW PORTC&=0xBF
#define MOT4_CW  PORTC|=0x80
#define MOT4_CCW PORTC&=0x7F 
#define MOT5_CW  PORTB|=0x04 
#define MOT5_CCW PORTB&=0xFB
#define MOT6_CW  PORTB|=0x08 
#define MOT6_CCW PORTB&=0xF7

//Motor clock pin set ==========================================================
#define MOT1_CLK_H	 sbi(PORTA,6)
#define MOT1_CLK_L	 cbi(PORTA,6)
#define MOT2_CLK_H	 sbi(PORTA,7)
#define MOT2_CLK_L	 cbi(PORTA,7)
#define MOT3_CLK_H	 sbi(PORTC,0)
#define MOT3_CLK_L	 cbi(PORTC,0)
#define MOT4_CLK_H	 sbi(PORTC,1)
#define MOT4_CLK_L	 cbi(PORTC,1)
#define MOT5_CLK_H	 sbi(PORTC,2)
#define MOT5_CLK_L	 cbi(PORTC,2)
#define MOT6_CLK_H	 sbi(PORTC,3)
#define MOT6_CLK_L	 cbi(PORTC,3)

//Motor clock number
#define MOT1 6
#define MOT2 7
#define MOT3 0
#define MOT4 1
#define MOT5 2
#define MOT6 3

//Onoff switch setup ===========================================================
//J20=SW1:PB0 J21=SW2:PB4 J22=SW3:PB5 J23=SW4:PB6 J24=SW5:PB7 -> PORTB&0b11110001 = PORTB&0xF1
//J25=SW6:PG3 J26=SW7:PG4 J27=SW8:PG1 J28=SW9:PG0 J29=SW10:PG2 -> PORTB&0b00011111 = PORTG&0x1F
#define SW1 (PINB&0x01)
#define SW2 (PINB&0x10)
#define SW3 (PINB&0x20)
#define SW4 (PINB&0x40)
#define SW5 (PINB&0x80)
#define SW6 (PING&0x08)
#define SW7 (PING&0x10)
#define SW8 (PING&0x02)
#define SW9 (PING&0x01)
#define SW10 (PING&0x04)

//Photointerrupt setup =========================================================
//J8=Photointerruptor1:PE2
//J9=Photointerruptor2:PE3
//J10=Photointerruptor3:PE4(INT4)
//J11=Photointerruptor4:PE5(INT5)
//J12=Photointerruptor5:PE6(INT6)
//J13=Photointerruptor6:PE7(INT7)
#define PI1 (PINE&0x04)
#define PI2 (PINE&0x08)
#define PI3 (PINE&0x10)
#define PI4 (PINE&0x20)
#define PI5 (PINE&0x40)
#define PI6 (PINE&0x80)

//Microstepping Manifest
#define HALF_SPR 400
#define QUAD_SPR 800
#define OCTO_SPR 1600
#define SEDE_SPR 3200

#define CW  0
#define CCW 1
#define ON  1
#define OFF 0

typedef struct{
		unsigned char mot1;
		unsigned char mot2;
		unsigned char mot3;
		unsigned char mot4;
		unsigned char mot5;
		unsigned char mot6;
		signed char mot1_dir;
		signed char mot2_dir;
		signed char mot3_dir;
		signed char mot4_dir;
		signed char mot5_dir;
		signed char mot6_dir;
		unsigned int mot1_speed;
		unsigned int mot2_speed;
		unsigned int mot3_speed;
		unsigned int mot4_speed;
		unsigned int mot5_speed;
		unsigned int mot6_speed;
		unsigned char clock_a;
		unsigned char clock_c;
		} motor_variables;

extern motor_variables mov;
