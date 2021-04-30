#include "stm32l4xx.h"

/*
*	@function		GPIO_SetPinAs_Output
*	@args			Port Base Address, Pin Number
*	@return			void
*	@details		Configure the specified GPIO pin as output
*/
void GPIO_SetPinAs_Output(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin);

/*
*	@function		GPIO_SetPinAs_Input
*	@args			Port Base Address, Pin Number
*	@return			void
*	@details		Configure the specified GPIO pin as input
*/
void GPIO_SetPinAs_Input(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin);

/*
*	@function		GPIO_TogglePin
*	@args			Port Base Address, Pin Number
*	@return			void
*	@details		Toggles the specified GPIO pin
*/
void GPIO_TogglePin(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin); 