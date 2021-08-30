#ifndef _DELAY
#define _DELAY

#include "stm32f10x.h"
#define SYSCLOCK 72000000U

extern volatile uint32_t ticks_delay;

void delay_ms(uint32_t ms);
void SysTick_Handler(void);
void init_systick(void);

#endif
