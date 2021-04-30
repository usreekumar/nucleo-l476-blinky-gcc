#include "system_cfg.h"
#include "gpio_stm32.h"

#ifndef __STM32L4xx_H
	#include "stm32l4xx.h"
#endif

/*Default toggle delay for LED*/
#define DEF_TOGGLE_DELAY 150000