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
	GPIOHandle_t pGPIOLED, pGPIOButton;

	pGPIOLED.pGPIOx = GPIOD;
	pGPIOLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_14;
	pGPIOLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	//Button Init
	pGPIOButton.pGPIOx = GPIOA;
	pGPIOButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_0;
	pGPIOButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	pGPIOButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;


	GPIO_PeriClockEnable(GPIOD, ENABLE);
	GPIO_PeriClockEnable(GPIOA, ENABLE);
	GPIO_Init(&pGPIOLED);
	GPIO_Init(&pGPIOButton);

	while(1)
	{
		if(GPIO_ReadPin(GPIOA, GPIO_PINNUMBER_0) == BUTTON_PRESSED)
		{
			delay(10000);
			GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_14);
		}
	}


	return 0;
}
