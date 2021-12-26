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

	// LED at PD14
	pGPIOLED.pGPIOx = GPIOD;
	pGPIOLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_14;
	pGPIOLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	GPIO_PeriClockEnable(GPIOD, ENABLE);
	GPIO_Init(&pGPIOLED);

	//Button at PB12
	pGPIOButton.pGPIOx = GPIOB;
	pGPIOButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_12;
	pGPIOButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	pGPIOButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	GPIO_PeriClockEnable(GPIOB, ENABLE);
	GPIO_Init(&pGPIOButton);

	while(1)
	{
		if(GPIO_ReadPin(GPIOB, GPIO_PINNUMBER_12) == BUTTON_PRESSED)
		{
			delay(90000);
			GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_14);
		}
	}


	return 0;
}
