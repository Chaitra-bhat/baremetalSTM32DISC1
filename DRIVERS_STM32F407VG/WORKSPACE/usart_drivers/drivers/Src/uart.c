/*
 * uart.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Navjeevan
 */

#include<uart.h>

void USART_PeriClockEnable(USART_RegDef_t *pUSARTx, uint8_t EnaOrDis)
{
	if(EnaOrDis == ENABLE)
	{
		if(pUSARTx == USART1)
			USART1_PCLK_ENABLE();
		else if(pUSARTx == USART2)
			USART2_PCLK_ENABLE();
		else if(pUSARTx == USART3)
			USART3_PCLK_ENABLE();
		else if(pUSARTx == UART4)
			UART4_PCLK_ENABLE();
		else if(pUSARTx == UART5)
			UART5_PCLK_ENABLE();
		else if(pUSARTx == USART6)
			USART6_PCLK_ENABLE();
	}
	else
	{	if(pUSARTx == USART1)
				USART1_PCLK_DISABLE();
			else if(pUSARTx == USART2)
				USART2_PCLK_DISABLE();
			else if(pUSARTx == USART3)
				USART3_PCLK_DISABLE();
			else if(pUSARTx == UART4)
				UART4_PCLK_DISABLE();
			else if(pUSARTx == UART5)
				UART5_PCLK_DISABLE();
			else if(pUSARTx == USART6)
				USART6_PCLK_DISABLE();
	}
}

void USART_Init(USART_Handle_t *pUSARTHandle)
{

	//Enable the M bit



}

void USART_DeInit(USART_RegDef_t *pUSARTx)
{
			if(pUSARTx == USART1)
				USART1_REG_RESET();
			else if(pUSARTx == USART2)
				USART2_REG_RESET();
			else if(pUSARTx == USART3)
				USART3_REG_RESET();
			else if(pUSARTx == UART4)
				UART4_REG_RESET();
			else if(pUSARTx == UART5)
				UART5_REG_RESET();
			else if(pUSARTx == USART6)
				USART6_REG_RESET();

}


void USART_PeripheralEnable(USART_RegDef_t *pUSARTx, uint8_t EnaOrDis)
{
	if(EnaOrDis == ENABLE)
	{
		pUSARTx->USART_CR1 |= (USART_CR1_UE);
	}
	else
	{
		pUSARTx->USART_CR1 &= ~(USART_CR1_UE);
	}

}

uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx, uint32_t Flagname)
{
	if(pUSARTx->USART_SR & Flagname)
	{
		return SET;
	}
	return RESET;
}

void USART_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnaOrDis)
{

}
