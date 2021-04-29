/********************************************************************************
*
*	@file 			main.c
*
*	@author			Umamaheswaran Sreekumar 
*
*	@brief			This project is meant as a tutorial about embedded systems
*					programming using open source tools and librariers in Linux.
*
*	@target         STM32L476RG  (nucleo-l476rg)
*
*********************************************************************************/

#include "main.h"

int main( void )
{
	uint32_t delay = DEF_TOGGLE_DELAY;
	SystemInitiaize();

	while(1)
	{
		GPIO_TogglePin(GPIOA, 5); /*Toggle the pin PA.5*/
		
		/* Need to implement a custom delay function*/
		while(delay--);
		delay = DEF_TOGGLE_DELAY;

	}
}