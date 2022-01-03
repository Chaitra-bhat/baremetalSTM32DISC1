/*
 * rcc.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Navjeevan
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f4xx_driver.h"

//This returns the APB1 clock value
uint32_t RCC_GetPCLK1Value(void);

//This returns the APB2 clock value
uint32_t RCC_GetPCLK2Value(void);


uint32_t  RCC_GetPLLOutputClock(void);

#endif /* INC_RCC_H_ */
