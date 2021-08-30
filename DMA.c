#include "DMA.h"

static void init_DMA(void){
	
	// AHB Peripheral Clock enable register
	// DMA1EN: DMA1 clock enable
	RCC->AHBENR |= RCC_AHBENR_DMA1EN;
	
	NVIC_EnableIRQ(DMA1_Channel4_IRQn);
	NVIC_EnableIRQ(DMA1_Channel5_IRQn);
}
