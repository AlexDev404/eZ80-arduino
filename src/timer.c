#include "timer.h"
#include "led.h"
#include "sio.h"

#pragma interrupt
void isr_timer0(void) 
{
	setStatus(RUN);
	//putch('T');
}

//////////////////////////////////////////////////////////
//Intialize Timer-0 
void init_timer0(void)
{
	SET_VECTOR(TIMER0, isr_timer0); 
 	T0H		= 0xFF;	// Timer High	
	T0L 	= 0xFF;	// Timer Low
	T0RH 	= 0xFF;	// Reload Compare High
	T0RL 	= 0xFF;	// Reload Compare Low
	T0CTL 	= 0xE9;	// Continous/Prescale
	IRQ0ENH |= 0x20;	// Set Interrupt Priority Nominal 
	IRQ0ENL &= 0xDF;	// Set Interrupt Priority Nominal
}


