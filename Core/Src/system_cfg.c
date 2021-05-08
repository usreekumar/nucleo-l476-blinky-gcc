#include "system_cfg.h"

/****************************************************************************
	@actions 	Initlialize the system clock
				Initilaize the desired GPIO pins
*****************************************************************************/
void SystemInitialize( void )
{
	SystemClock_Init();
	Peripheral_Init();
}

/**********************************************************************************
	@explaination : Selecting MSI with freq 8MHz as System clock	
***********************************************************************************/
void SystemClock_Init( void )
{
	/*Clock configuration register (RCC_CFGR)
	  Or ing with 0 is fine. Since 00 is default. MSI = 00*/
	RCC->CFGR |= RCC_CFGR_SW_MSI; /*System Clock Switch*/
	while(RCC->CFGR & (3 << 2)); /*Wait till SWS bits are 00. ie MSI. By default 0*/

	/* These bits are configured by software to choose the frequency 
		range of MSI 0111: range 7 around 8 MHz */
	RCC->CR &=  ~RCC_CR_MSIRANGE;
	RCC->CR |= RCC_CR_MSIRANGE_7;

	/* MSIRGSEL: MSI clock range selection
	   Set by software to select the MSI clock range with MSIRANGE[3:0].*/
	RCC->CR |= RCC_CR_MSIRGSEL;

	/* Enabling the MSI clock. Clock control register (RCC_CR)
	   MSION: MSI clock enable*/
	RCC->CR |= RCC_CR_MSION; 

	/*Waiting till MSIRDY bit (bit 1 of CR) is set by hardware. */
	while(!(RCC->CR & RCC_CR_MSIRDY));
}

/* Initializing the Peripherals 
		1. Init the required GPIO pins*/
void Peripheral_Init( void )
{
	/* AHB2 peripheral clock enable register (RCC_AHB2ENR) 
		Enable the clock for GPIOA
		Set Port A, Pin 5 as an output pin*/
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 
	GPIO_SetPinAs_Output(GPIOA, 5);
}
