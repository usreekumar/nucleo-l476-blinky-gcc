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
	@explaination

		Plannning to select MSI as sysem clk
			The MSI RC can be switched on and off by using the MSION bit in 
			the Clock Control Register (RCC_CR).

	We need to wait till the clock is stable : 
		Use the MSIRDY flag in the Clock control register (RCC_CR)

	PLL configuration register (RCC_PLLCFGR). The internal PLLs can be used to 
	multiply the HSI16, HSE or MSI output clock frequency.

	Each peripheral clock can be enabled by the xxxxEN bit of the RCC_AHBxENR,
	RCC_APBxENRy registers.	When the peripheral clock is not active, the peripheral 
	registers read or write accesses are not supported.

***********************************************************************************/
void SystemClock_Init( void )
{
	/* Enabling the MSI clock. Clock control register (RCC_CR)
	   MSION: MSI clock enable*/
	RCC->CR |= RCC_CR_MSION; 

	/*Clock configuration register (RCC_CFGR). 
	  MCOSEL[2:0] Microcontroller clock output
	  0010: MSI clock selected

	  Note: This clock output may have some truncated cycles at 
	  		startup or during MCO clock source switching.*/
	RCC->CFGR |= RCC_CFGR_MCOSEL_1;

	/*MSIRDY: MSI clock ready flag. This bit is set by hardware to 
	  indicate that the MSI oscillator is stable.Once the MSION bit 
	  is cleared, MSIRDY goes low after 6 MSI clock cycles.

	  Waiting till MSIRDY bit (bit 1 of CR) is set by hardware. */
	while(RCC->CR & RCC_CR_MSIRDY == 0);

	/* These bits are configured by software to choose the frequency range of MSI 
		0111: range 7 around 8 MHz 

		Clearing just the MSIRANGE bits and setting it to desired value.

		Note: Warning: MSIRANGE can be modified when MSI is OFF (MSION=0) 
		or when MSI is ready (MSIRDY=1). MSIRANGE must NOT be modified when 
		MSI is ON and NOT ready (MSION=1 and MSIRDY=0)*/
	RCC->CR &=  ~RCC_CR_MSIRANGE;
	RCC->CR != RCC_CR_MSIRANGE_7; 

	/* MSIRGSEL: MSI clock range selection

	   Set by software to select the MSI clock range with MSIRANGE[3:0]. 
	   Write 0 has no effect.After a standby or a reset MSIRGSEL is at 0 
	   and the MSI range value is provided byMSISRANGE in CSR register.*/

	RCC->CR |= RCC_CR_MSIRGSEL;

	/* Waiting till MSIRDY bit (bit 1 of CR) is set by hardware. */
	while(RCC->CR & RCC_CR_MSIRDY == 0);
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