/*
 * gpio.h
 *
 *  Created on: Dec 26, 2021
 *      Author: Navjeevan
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include<stm32f4xx_driver.h>

//PIN CONFIGURATION STRUCTURE OF GPIO
typedef struct{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_pinConfig_t;

//HANDLE STRUCTURE OF GPIO
typedef struct {
	GPIO_RegDef_t *pGPIOx;
	GPIO_pinConfig_t GPIO_PinConfig;
}GPIOHandle_t;


//function prototypes
void delay(uint32_t delayVal);
void GPIO_Init(GPIOHandle_t *pGPIOHandle);
void GPIO_DeInit(GPIOHandle_t *GPIOHandle);
void GPIO_PeriClockEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnaOrDis);
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx,  uint8_t value, uint8_t PinNumber);
void GPIO_WritePort(GPIO_RegDef_t *pGPIOx,  uint16_t value);
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,  uint8_t PinNumber);
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnaOrDis);
void GPIO_IRQHandler(uint8_t PinNumber);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQpriority);

/*
 * PIN MODE TYPES
 */
#define GPIO_MODE_INPUT				0U
#define GPIO_MODE_OUTPUT			1U
#define GPIO_MODE_ALTFUNC			2U
#define GPIO_MODE_ANALOG			3U
#define GPIO_MODE_FT				4U
#define GPIO_MODE_RT				5U
#define GPIO_MODE_RFT				6U

/*
 * OUTPUT TYPE
 */
#define GPIO_OTYPE_PUSHPULL			0U
#define GPIO_OTYPE_OPENDRAIN		1U

/*
 * OUTPUT SPEED TYPE
 */
#define GPIO_OSPEED_LOW				0U
#define GPIO_OSPEED_MEDIUM			1U
#define GPIO_OSPEED_HIGH			2U
#define GPIO_OSPEED_VHIGH			3U

/*
 * PULL UP PULL DOWN TYPE
 */
#define GPIO_PUPDTYPE_NONE			0U
#define GPIO_PUPDTYPE_PU			1U
#define GPIO_PUPDTYPE_PD			2U

/*
 * PIN NUMBERS
 */
#define GPIO_PINNUMBER_0			0U
#define GPIO_PINNUMBER_1			1U
#define GPIO_PINNUMBER_2			2U
#define GPIO_PINNUMBER_3			3U
#define GPIO_PINNUMBER_4			4U
#define GPIO_PINNUMBER_5			5U
#define GPIO_PINNUMBER_6			6U
#define GPIO_PINNUMBER_7			7U
#define GPIO_PINNUMBER_8			8U
#define GPIO_PINNUMBER_9			9U
#define GPIO_PINNUMBER_10			10U
#define GPIO_PINNUMBER_11			11U
#define GPIO_PINNUMBER_12			12U
#define GPIO_PINNUMBER_13			13U
#define GPIO_PINNUMBER_14			14U
#define GPIO_PINNUMBER_15			15U



#endif /* INC_GPIO_H_ */
