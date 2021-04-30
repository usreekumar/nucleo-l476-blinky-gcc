#include "stm32l4xx.h"
#include "gpio_stm32.h"

/*Initializes the system :
	@calls
		System clock configs
		Initialization of peripherals*/
void SystemInitialize(void);

/* System clock configs */
void SystemClock_Init( void );

/* Initialization of peripherals*/
void Peripheral_Init( void );