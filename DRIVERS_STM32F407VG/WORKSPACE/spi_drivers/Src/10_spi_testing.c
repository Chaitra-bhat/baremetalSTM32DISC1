/*
 * 10_spi_testing.c
 *
 *  Created on: Dec 28, 2021
 *      Author: Navjeevan
 */

/* PB15 MOSI
 * PB14 MISO
 * PB13 SCLK
 * PB12 NSS
 * ALtMode  = 5
*/
#include<string.h>
#include<stm32f4xx_driver.h>

#include<gpio.h>
#include<spi.h>

void SPI2_GPIOInit(void)
{
	GPIOHandle_t pGPIOPin;


	pGPIOPin.pGPIOx = GPIOB;
	pGPIOPin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFUNC;
	pGPIOPin.GPIO_PinConfig.GPIO_PinAltFunMode = 5;
	pGPIOPin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OTYPE_PUSHPULL;
	pGPIOPin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;
	pGPIOPin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_HIGH;

	//Configure each pin as per comments
	//1. SCLK
	pGPIOPin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_13;
	GPIO_Init(&pGPIOPin);

	//2. MOSI
	pGPIOPin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_15;
	GPIO_Init(&pGPIOPin);

	//3. MISO
	//pGPIOPin->GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_14;
	//GPIO_Init(&pGPIOPin);

	//4. NSS
	//pGPIOPin->GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_12;
	//GPIO_Init(&pGPIOPin);
}

void SPI2_init()
{
	SPI_Handle_t pSPI2Handle;

	pSPI2Handle.pSPIx = SPI2;
	pSPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUSCONFIG_FULLDUPLEX;
	pSPI2Handle.SPIConfig.SPI_DEVICEMODE = SPI_DEVICEMODE_MASTER;
	pSPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_BAUDRATE_DIV2;
	pSPI2Handle.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	pSPI2Handle.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	pSPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	pSPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_ENABLE;

	SPI_Init(&pSPI2Handle);
}


int main()
{
	char userData[] = "hh";
	SPI2_GPIOInit();
	SPI2_init();

	//Enable the SPI peripheral
	//SPI_PeripheralEnable(SPI2, ENABLE);

	//SSI Enable
	SPI_SSIConfig(SPI2, ENABLE);

	//Enable the SPI peripheral
	SPI_PeripheralEnable(SPI2, ENABLE);
	SPI_SendData(SPI2, (uint8_t*)userData, strlen(userData));

	//lets confirm SPI is not busy
	while( SPI_GetFlagStatus(SPI2,(1<<8)) );

	//Disable the SPI2 peripheral
	SPI_PeripheralEnable(SPI2,DISABLE);

	while(1);
	return 0;
}
