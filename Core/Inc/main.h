#include "system_cfg.h"
#include "gpio_stm32.h"

#ifndef __STM32L476xx_H
	#include "stm32l476xx.h"
#endif

/*Default toggle delay for LED*/
#define DEF_TOGGLE_DELAY 1500