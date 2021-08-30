#ifndef _USART
#define _USART
#include "stm32f10x.h"
#include "led.h"

extern uint8_t fl;
extern uint8_t new_status;

extern char data1[];
extern char data2[];
extern char data3[];

extern char* current_data_ptr;
extern char* start_data_ptr;

void status_change(void);
void USART_get_push(void);
void init_USART(void);
void init_USART_with_interrupt(void);
void USART1_IRQHandler(void);

#endif
