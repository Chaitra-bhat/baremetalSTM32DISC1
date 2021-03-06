/*
 * 01_ledToggle.c
 *
 *  Created on: Dec 26, 2021
 *      Author: Navjeevan
 */

#include<stdio.h>
#include<gpio.h>


int main()
{
	GPIOHandle_t pGPIOLED;

	pGPIOLED.pGPIOx = GPIOD;
	pGPIOLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_14;
	pGPIOLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	GPIO_PeriClockEnable(GPIOD, ENABLE);
	GPIO_Init(&pGPIOLED);

	while(1)
	{
		GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_14);
		delay(50000);

	}


	return 0;
}


