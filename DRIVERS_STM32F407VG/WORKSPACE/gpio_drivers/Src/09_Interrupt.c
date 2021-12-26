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

	//LED
	pGPIOLED.pGPIOx = GPIOD;
	pGPIOLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_12;
	pGPIOLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	pGPIOLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLED.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	GPIO_PeriClockEnable(GPIOD, ENABLE);
	GPIO_Init(&pGPIOLED);

	//Button
	pGPIOLED.pGPIOx = GPIOA;
	pGPIOLED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_0;
	pGPIOLED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_FT;
	pGPIOLED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
	pGPIOLED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

	GPIO_PeriClockEnable(GPIOA, ENABLE);
	GPIO_Init(&pGPIOButton);

	GPIO_IRQPriorityConfig(IRQNumber_5_9, 15);
	GPIO_IRQInterruptConfig(IRQNumber_5_9, ENABLE);

	//while(1);
	return 0;
}


void EXTI9_5_IRQHandler(void)
{
	GPIO_IRQHandler(GPIO_PINNUMBER_5);

	GPIO_TogglePin(GPIOD, GPIO_PINNUMBER_12);
	//delay(50000);

}
