#include "baton.h"

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & EXTI_PR_PR13){
		EXTI->PR = EXTI_PR_PR13;
		toggle_led();
	}
}	

void init_button(void){
	// APB2 peripheral clock enable register (RCC_APB2ENR)
	// IOPCEN: IO port B clock enable
	RCC->APB2ENR	|=	RCC_APB2ENR_IOPBEN;
	
	// Port Configuration Register high (GPIOx_CRH) (x=A..G)
	
	// MODEy[1:0]: Port x mode bits (y= 8 .. 15) 
	// 00: Input mode (reset state)
	GPIOB->CRH	&=	~GPIO_CRH_MODE13;
	// CNFy[1:0]: Port x configuration bits (y= 8 .. 15)
	// 10: Input with pull-up / pull-down
	GPIOB->CRH	|=	GPIO_CRH_CNF13_1;
	GPIOB->CRH	&=	~GPIO_CRH_CNF13_0;
	
	// pull down
	GPIOB->ODR	&=	~GPIO_ODR_ODR13;
	
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	// 1: Interrupt request from Line x is not masked
	EXTI->IMR |= EXTI_IMR_MR13;
	// 1: Rising trigger enabled (for Event and Interrupt) for input line.
	EXTI->RTSR |= EXTI_RTSR_TR13;
	// 0: Falling trigger disabled (for Event and Interrupt) for input line
	EXTI->FTSR &= ~EXTI_FTSR_TR13;
}
