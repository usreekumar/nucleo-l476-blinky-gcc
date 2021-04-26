#include "gpio_stm32.h"

/*****************************************************************************

	@explaination	BSRR  Register : Bit set and reset register (GPIOx_ BSRR) 
					for bitwise write access to GPIOx_ODR

					BRR Register : Bit reset register. Writing a 1 ro this 
					register resets te pin
	
********************************************************-*********************/



void GPIO_TogglePin(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin)
{
	if(GPIO_Port->ODR & GPIO_PIN_MASK(GPIO_Pin) ==  0u)
	{
		GPIO_Port->BRR |= GPIO_PIN_MASK(GPIO_Pin);
	}
	else
	{
		GPIO_Port->BSRR |= GPIO_PIN_MASK(GPIO_Pin);
	}
}