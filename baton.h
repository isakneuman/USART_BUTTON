#ifndef _BUTTON
#define _BUTTON
#include "stm32f10x.h"
#include "led.h"
// button isnt baton unfunny joke i know :D sry

void EXTI15_10_IRQHandler(void);
void init_button(void);

#endif
