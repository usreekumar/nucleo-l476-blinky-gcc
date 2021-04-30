#include "main.h"

int main( void )
{
	uint32_t delay = DEF_TOGGLE_DELAY;
	SystemInitialize();

	while(1)
	{
		GPIO_TogglePin(GPIOA, 5); /*Toggle the pin PA.5*/
		
		/* Need to implement a custom delay function*/
		while(delay--);
		delay = DEF_TOGGLE_DELAY;

	}
}