#include "stm32l476xx.h"

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

/*
*	Gets the bit mask for the pin number	
*/
#define GPIO_PIN_MASK(PinNum) ((PinNum == 0) ? GPIO_PIN_0 : \
							   (PinNum == 1) ? GPIO_PIN_1 : \
							   (PinNum == 2) ? GPIO_PIN_2 : \
							   (PinNum == 3) ? GPIO_PIN_3 : \
							   (PinNum == 4) ? GPIO_PIN_4 : \
							   (PinNum == 5) ? GPIO_PIN_5 : \
							   (PinNum == 6) ? GPIO_PIN_6 : \
							   (PinNum == 7) ? GPIO_PIN_7 : \
							   (PinNum == 8) ? GPIO_PIN_8 : \
							   (PinNum == 9) ? GPIO_PIN_9 : \
							  (PinNum == 10) ? GPIO_PIN_10 : \
							  (PinNum == 11) ? GPIO_PIN_11 : \
							  (PinNum == 12) ? GPIO_PIN_12 : \
							  (PinNum == 13) ? GPIO_PIN_13 : \
							  (PinNum == 14) ? GPIO_PIN_14 : \
							  (PinNum == 15) ? GPIO_PIN_15 : GPIO_PIN_All)

/*
*	@function		GPIO_TogglePin
*	@args			Port Base Address, Pin Number
*	@return			void
*	@details		Toggles the specified GPIO pin
*/

void GPIO_TogglePin(GPIO_TypeDef* GPIO_Port, uint8_t GPIO_Pin); 