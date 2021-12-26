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
	GPIOHandle_t pGPIOLEDBlue, pGPIOLEDOrange, pGPIOLEDRed, pGPIOLEDGreen;

	pGPIOLEDBlue.pGPIOx = pGPIOLEDOrange.pGPIOx = pGPIOLEDRed.pGPIOx =  pGPIOLEDGreen.pGPIOx =  GPIOD;

	//Orange LED
	pGPIOLEDOrange.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_13;
	pGPIOLEDOrange.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLEDOrange.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLEDOrange.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLEDOrange.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	//Red LED
	pGPIOLEDRed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_14;
	pGPIOLEDRed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLEDRed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLEDRed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLEDRed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	// Blue LED
	pGPIOLEDBlue.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_15;
	pGPIOLEDBlue.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLEDBlue.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLEDBlue.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLEDBlue.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	//Green LED
	pGPIOLEDGreen.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_12;
	pGPIOLEDGreen.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLEDGreen.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLEDGreen.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLEDGreen.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	GPIO_PeriClockEnable(GPIOD, ENABLE);
	GPIO_Init(&pGPIOLEDBlue);
	GPIO_Init(&pGPIOLEDRed);
	GPIO_Init(&pGPIOLEDGreen);
	GPIO_Init(&pGPIOLEDOrange);

	while(1)
	{
		GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_13);
		delay(100000);
		GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_14);
		delay(100000);
		GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_15);
		delay(100000);
		GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_12);
		delay(100000);
	}


	return 0;
}
