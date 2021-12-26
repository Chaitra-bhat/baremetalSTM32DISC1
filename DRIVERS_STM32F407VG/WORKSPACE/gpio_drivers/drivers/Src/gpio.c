/*
 * gpio.c
 *
 *  Created on: Dec 25, 2021
 *      Author: Navjeevan
 */
#include<gpio.h>

/*
 * ddelay function
 */
void delay(uint32_t delayVal)
{
	for(int i =0; i<delayVal;i++);
}


/*
 * INITILIZATION AND DEINITILIZATION
 */
void GPIO_Init(GPIOHandle_t *pGPIOHandle)
{

	uint32_t temp;

	//1. Configure the mode
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//Non interrupt mode

		//Initilly clear the bits
		pGPIOHandle->pGPIOx->MODER &= ~(0x3U << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <<(2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp = 0;


	}
	else
	{
		//Interrupt mode




	}


	//2. Configure the speed

	//Initally clear the bit
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3U << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;

	//3. Configure PuPd mode
	//Initally clear the bit
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3U << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	//4.Configure Output type
	//Initally clear the bit
	pGPIOHandle->pGPIOx->OTYPER &= ~(1U << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	//5. Configure Alternate functionality type
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFUNC)
	{
		uint32_t temp1, temp2;
		temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)/8;
		temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)%8;

		//Initially clear the bit
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode);
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*temp2));
		temp1 = 0;
		temp2 = 0;
	}



}

void GPIO_DeInit(GPIOHandle_t *GPIOHandle)
{
		if(GPIOHandle->pGPIOx == GPIOA)
			GPIOA_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOB)
			GPIOB_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOC)
			GPIOC_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOD)
			GPIOD_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOE)
			GPIOE_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOF)
			GPIOF_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOG)
			GPIOG_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOH)
			GPIOH_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOI)
			GPIOI_REG_RESET();
		else if(GPIOHandle->pGPIOx == GPIOJ)
			GPIOJ_REG_RESET();
}


/*
 * PERIPHERAL CLOCK ENABLE AND DISABLE
 */
void GPIO_PeriClockEnable(GPIO_RegDef_t *pGPIOx, uint8_t EnaOrDis)
{
	if(EnaOrDis == ENABLE)
	{
	if(pGPIOx == GPIOA)
		GPIOA_PCLK_ENABLE();
	else if(pGPIOx == GPIOB)
		GPIOB_PCLK_ENABLE();
	else if(pGPIOx == GPIOC)
		GPIOC_PCLK_ENABLE();
	else if(pGPIOx == GPIOD)
		GPIOD_PCLK_ENABLE();
	else if(pGPIOx == GPIOE)
		GPIOE_PCLK_ENABLE();
	else if(pGPIOx == GPIOF)
		GPIOF_PCLK_ENABLE();
	else if(pGPIOx == GPIOG)
		GPIOG_PCLK_ENABLE();
	else if(pGPIOx == GPIOH)
		GPIOH_PCLK_ENABLE();
	else if(pGPIOx == GPIOI)
		GPIOI_PCLK_ENABLE();
	else if(pGPIOx == GPIOJ)
		GPIOJ_PCLK_ENABLE();
	}
	else
	{
		if(pGPIOx == GPIOA)
			GPIOA_PCLK_DISABLE();
		else if(pGPIOx == GPIOB)
			GPIOB_PCLK_DISABLE();
		else if(pGPIOx == GPIOC)
			GPIOC_PCLK_DISABLE();
		else if(pGPIOx == GPIOD)
			GPIOD_PCLK_DISABLE();
		else if(pGPIOx == GPIOE)
			GPIOE_PCLK_DISABLE();
		else if(pGPIOx == GPIOF)
			GPIOF_PCLK_DISABLE();
		else if(pGPIOx == GPIOG)
			GPIOG_PCLK_DISABLE();
		else if(pGPIOx == GPIOH)
			GPIOH_PCLK_DISABLE();
		else if(pGPIOx == GPIOI)
			GPIOI_PCLK_DISABLE();
		else if(pGPIOx == GPIOJ)
			GPIOJ_PCLK_DISABLE();
	}
}


/*
 * READING FROM PIN AND PORT
 */
uint8_t GPIO_ReadPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}

/*
 *WRITING TO PIN AND PORT
 */
void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx,  uint8_t value, uint8_t PinNumber)
{
	if(value == SET)
	{
		pGPIOx->ODR |= (1U<<PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1U<<PinNumber);
	}
}

void GPIO_WritePort(GPIO_RegDef_t *pGPIOx,  uint16_t value)
{
	pGPIOx->ODR =  value;

}

/*
 * TOGGLE PIN
 */
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,  uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);
}

/*
 * IRQ RELATED FUNCTIONS
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQpriority, uint8_t EnaOrDis)
{

}

void IRQHandle(uint8_t PinNumber){

}

