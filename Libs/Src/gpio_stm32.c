#include "gpio_stm32.h"

/*****************************************************************************

	@details	Toggle the GPIO pin
	
********************************************************-*********************/
void GPIO_TogglePin(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin)
{
	GPIO_Port->ODR ^= (1UL << GPIO_Pin);
}

/*****************************************************************************

	@details	Update the MODER, OTYPER and PUPDR.
	
********************************************************-*********************/
void GPIO_SetPinAs_Output(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin)
{
	/*2*pin  because the MODER bits for each pin is  2b its wide*/
	GPIO_Port->MODER &= ~(3UL << 2*GPIO_Pin); /*Clearing the mode bits*/
	GPIO_Port->MODER |= 1UL << 2*GPIO_Pin;	/*Mode bits = 01 => Output mode*/

	GPIO_Port->OTYPER &= ~(1UL << GPIO_Pin); /*0: Output push-pull (reset state)*/

	GPIO_Port->PUPDR &= ~(3UL << 2*GPIO_Pin); /*Clearing the PUPDR bits*/
	GPIO_Port->PUPDR |= 2UL << 2*GPIO_Pin; /*10: Pull-down*/
}

/*****************************************************************************

	@details	Update the MODER and PUPDR.
	
********************************************************-*********************/
void GPIO_SetPinAs_Input(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin)
{
	/*2*pin  because the MODER bits for each pin is  2b its wide*/
	GPIO_Port->MODER &= ~(3UL << 2*GPIO_Pin); /*Clearing the mode bits. 00 : Input mode*/
	GPIO_Port->PUPDR &= ~(3UL << 2*GPIO_Pin); /*Clearing the PUPDR bits. 00: No pull-up, pull-down*/
}