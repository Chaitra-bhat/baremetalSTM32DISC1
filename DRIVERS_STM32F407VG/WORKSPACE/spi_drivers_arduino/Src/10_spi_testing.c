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

#include<stm32f4xx_driver.h>
#include<string.h>
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

void ButtonInit(void)
{
	GPIOHandle_t  pGPIOButton;

		//Button Init
		pGPIOButton.pGPIOx = GPIOA;
		pGPIOButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINNUMBER_0;
		pGPIOButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
		pGPIOButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
		pGPIOButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPDTYPE_NONE;

		GPIO_PeriClockEnable(GPIOA, ENABLE);
		GPIO_Init(&pGPIOButton);

}

int main()
{
	char userData[] = "Hello World !";
	SPI2_GPIOInit();
	ButtonInit();
	SPI2_init();

	SPI_SSOEConfig(SPI2, ENABLE);

	while(1)
	{
			while(!(GPIO_ReadPin(GPIOA, GPIO_PINNUMBER_0)));

			for(int i=0; i<20000; i++);
			//SSI Enable
			SPI_SSIConfig(SPI2, ENABLE);

		// First send the length of data to be sent to slave
			uint8_t dataLength = strlen(userData);

			SPI_SendData(SPI2, &dataLength, 1);


			//Enable the SPI peripheral
			SPI_PeripheralEnable(SPI2, ENABLE);
			SPI_SendData(SPI2, (uint8_t*)userData, strlen(userData));

			//Get the flag status checking whether the transmsion is complete
			while(SPI_GetFlagStatus(SPI2, SPI_SR2_BUSY));

			SPI_PeripheralEnable(SPI2, ENABLE);

	}

	return 0;
}
