unsigned char clock_state;

void timer_init(void)
{
 //Stop Timers
 TCCR0 = 0;
 TCCR1B = 0;
 //Set timers to output compare mode 
 TCCR1B |= (1<<WGM12); //Timer1 operation mode : CTC mode
 TCCR0 |= (1<<WGM01); //Timer0 operation mode : CTC mode
 //Enable Timer1 and Timer0 ouput compare interrupt
 TIMSK |= (1<<OCIE1A)|(1<<OCIE0);
 //OCR0 = 20; //T0 비교매치 발생주기, Prescale(1/8) -> 16MHz/8 = 2MHz = 0.5uS/1Count, 0.5 x 20Count = 10uS (This should be more than 2uS)
 OCR1A = 40; //T1 비교매치 발생주기, Prescale(1/8) -> 0.5uS x 40Count = 20uS  
}

#pragma interrupt_handler timer1_compa_isr:iv_TIM1_COMPA
void timer1_compa_isr(void)
{
  //static unsigned long step_count = 0;
  //static unsigned int rest = 0;
  
  PORTA |= mov.clock_a; //For motor1 and motor2
  PORTC |= mov.clock_c; //For motor3 ~ motor6
  OCR0 = 20; //Will trigger 10uS after timer0 start
  TCCR0 |= (1<<CS01); //Start timer0 with 1/8 cpu speed
  
  if(mov.mot1) { sbi(mov.clock_a, MOT1); }
  if(mov.mot2) { sbi(mov.clock_a, MOT2); }
  if(mov.mot3) { sbi(mov.clock_c, MOT3); }
  if(mov.mot4) { sbi(mov.clock_c, MOT4); }
  if(mov.mot5) { sbi(mov.clock_c, MOT5); }
  if(mov.mot6) { sbi(mov.clock_c, MOT6); }
  
  OCR1A = 40;
}

// 클럭발생용 타이머0 비교매치 인터럽트 서브루틴
// 외부함수에서 High로 된 클럭 로직을 Low로 반전시키고 다음 인터럽트에서 타이머를 끈다. 
#pragma interrupt_handler timer0_comp_isr:iv_TIM0_COMP
void timer0_comp_isr(void)
{
 if(clock_state == LOW) { TCCR0 &= ~(1<<CS01); return; }

 PORTA &= ~mov.clock_a;
 PORTC &= ~mov.clock_c;

 clock_state = LOW;
 OCR0 = 10; //Will turn off timer0 after 0.5uS x 10 = 5uS (This should be more than 2uS for SLA7062M)
}

