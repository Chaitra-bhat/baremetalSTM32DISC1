/*
 * spi.c
 *
 *  Created on: Dec 27, 2021
 *      Author: Navjeevan
 */

#include<spi.h>

void SPI_PeriClkEnable(SPI_RegDef_t *pSPIx, uint8_t EnaOrDis)
{
	if(EnaOrDis == ENABLE)
	{
		if(pSPIx == SPI1)
			SPI1_PCLK_ENABLE();
		else if(pSPIx == SPI2)
			SPI2_PCLK_ENABLE();
		else if(pSPIx == SPI3)
			SPI3_PCLK_ENABLE();
	}
	else
	{
		if(pSPIx == SPI1)
			SPI1_PCLK_ENABLE();
		else if(pSPIx == SPI2)
			SPI2_PCLK_ENABLE();
		else if(pSPIx == SPI3)
			SPI3_PCLK_ENABLE();
	}
}

void SPI_Init(SPI_Handle_t *pSPIHandle)
{

	SPI_PeriClkEnable(pSPIHandle->pSPIx, ENABLE);
	//CONFIGURE spi CR1 REGISTER
	uint32_t temp = 0;

	//Configure device mode
	temp |= (pSPIHandle->SPIConfig.SPI_DEVICEMODE << 2);

	//2. Configure the bus config
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUSCONFIG_FULLDUPLEX)
	{
		// BIDI mode should be cleared
		temp &= ~(1<<15);

	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUSCONFIG_HALFDUPLEX)
	{
		//BIDI mode should be set
		temp |= (1<<15);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUSCONFIG_SIMPLEX_RXONLY)
	{
		//BIDI mode should be cleared
		temp &= ~(1<<15);
		// RXOnly bit must be set
		temp |= (1<<10);
	}

	//3. Configure the serail clock
	temp |= pSPIHandle->SPIConfig.SPI_SclkSpeed << 3;

	//4. Configure the DFF
	temp |= pSPIHandle->SPIConfig.SPI_DFF <<11;

	//5. configure the CPOL
	temp |= pSPIHandle->SPIConfig.SPI_CPOL << 1;

	//6. Configure the CPHA
	temp |= pSPIHandle->SPIConfig.SPI_CPHA << 0;

	//7. Configure SSM bit
	temp |= pSPIHandle->SPIConfig.SPI_SSM << 9;

	//Save in main resgiter
	pSPIHandle->pSPIx->SPI_CR1 = temp;

}


void SPI_DeInit(SPI_Handle_t *pSPIHandle)
{
	if(pSPIHandle->pSPIx == SPI1)
		SPI1_REG_RESET();
	else if(pSPIHandle->pSPIx == SPI2)
		SPI2_REG_RESET();
	else if(pSPIHandle->pSPIx == SPI3)
		SPI3_REG_RESET();
}

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t length)
{
	while(length > 0)
	{
		//1. Wait until TXE is 0
		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == RESET);
		//while(! (pSPIx->SPI_SR & (1<<1 )));

		//2. Check DFF bit
		if((pSPIx->SPI_CR1 & (1<<11)))
		{
			//16 bit data
			//1. Load the data in the DR
			pSPIx->SPI_DR = *((uint16_t*)pTxBuffer);
			length--;
			length--;
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			//8 bit data
			pSPIx->SPI_DR = *pTxBuffer;
			length--;
			pTxBuffer++;
		}
	}


}



void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t length)
{


}

void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnaOrDis)
{



}


void SPI_IRQHandler(SPI_Handle_t *pSPIHandle)
{



}


void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQpriority)
{



}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t Flagname)
{
	if(pSPIx->SPI_SR & Flagname)
	{
		return SET;
	}
	return RESET;
}

void SPI_PeripheralEnable(SPI_RegDef_t *pSPIx, uint8_t EnaOrDis)
{
	if(EnaOrDis == ENABLE)
	{
		pSPIx->SPI_CR1 |= (1<<6);
	}
	else
	{
		pSPIx->SPI_CR1 &= ~(1<<6);
	}

}


void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t EnaOrDis)
{
	if(EnaOrDis == ENABLE)
	{
		pSPIx->SPI_CR1 |= (1<<8);
	}
	else
	{
		pSPIx->SPI_CR1 &= ~(1<<8);
	}
}
