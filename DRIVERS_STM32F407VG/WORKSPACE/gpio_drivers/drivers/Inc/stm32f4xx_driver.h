/*
 * stm32f4xx_driver.h
 *
 *  Created on: Dec 25, 2021
 *      Author: Navjeevan
 */

#ifndef INC_STM32F4XX_DRIVER_H_
#define INC_STM32F4XX_DRIVER_H_

#include<stdint.h>

//GENERAL MACROS
#define ENABLE			1U
#define DISABLE			0U
#define SET				ENABLE
#define RESET			DISABLE
#define __vo volatile

//MEMORY ADDRESS OF MEMORY PERIPHERALS
#define	FLASH_BASEADDR		0x8000000U
#define SRAM1_BASEADDR		0x2000000U

//REGISTER DETAILS OF AHB1 INTERFACES
#define GPIOA				0x40020000U
#define GPIOB				0x40020400U
#define GPIOC				0x40020800U
#define GPIOD				0x40020C00U
#define GPIOE				0x40021000U
#define GPIOF				0x40021400U
#define GPIOG				0x40021800U
#define GPIOH				0x40021C00U
#define GPIOI 				0x40022000U
#define GPIOJ				0x40022400U
#define GPIOK				0x40022800U
#define CRC					0x40023000U
#define RCC					0x40023800U
#define FLASH_INTERFACE		0x40023C00U
#define BKPSRAM				0x40024000U
#define DMA1				0x40026000U
#define DMA2				0x40026400U
#define ETHERNET_MAC		0x40028000U
#define DMA2D				0x4002B000U
#define USB_OTG_HS			0x40040000U

//REGISTER DETAILS OF AHB2 INTERFACES
#define USB_OTG_FS			0x50000000U
#define DCMI				0x50050000U
#define CRYP				0x50060000U
#define HASH				0x50060400U
#define RNG					0x50060800U

//REGISTER DETAILS OF AHB3 INTERFACES
#define FSMC				0xA0000000U

//REGISTER DETAILS OF APB1 INTERFACES
#define	TIM2				0x40000000U
#define TIM3				0x40000400U
#define TIM4				0x40000800U
#define TIM5				0x40000C00U
#define TIM6				0x40001000U
#define TIM7				0x40001400U
#define TIM12				0x40001800U
#define TIM13				0x40001C00U
#define TIM14				0x40002000U
#define RTC_BKP				0x40002800U
#define WWDG				0x40002C00U
#define IWDG				0x40003000U
#define I2S2ext				0x40003400U
#define SPI2_I2S2			0x40003800U
#define SPI3_I2S3			0x40003C00U
#define I2S3_ext			0x40003C00U
#define USART2				0x40004400U
#define USART3				0x40004800U
#define UART4				0x40004C00U
#define UART5				0x40005000U
#define I2C1				0x40005400U
#define I2C2				0x40005800U
#define I2C3				0x40005C00U
#define CAN1				0x40006400U
#define CAN2				0x40006800U
#define PWR					0x40007000U
#define DAC					0x40007400U
#define UART7				0x40007800U
#define UART8				0x40007C00U


//REGISTER DETAILS OF APB2 INTERFACES
#define TIM1				0x40010000U
#define TIM8				0x40010400U
#define USART1				0x40011000U
#define USART6				0x40011400U
#define ADC_1_2_3			0x40012000U
#define SDIO				0x40012C00U
#define SPI1				0x40013000U
#define SPI4				0x40013400U
#define SYSCFG				0x40013800U
#define EXTI				0x40013C00U
#define TIM9				0x40014000U
#define TIM10				0x40014400U
#define TIM11				0x40014800U
#define SPI5				0x40015000U
#define SPI6				0x40015400U
#define SAI1				0x40015800U
#define LCD_TFT				0x40016800U

//REGISTER DEFINITION FOR RCC
typedef struct{
	__vo uint32_t RCC_CR;
	__vo uint32_t RCC_PLLCFGR;
	__vo uint32_t RCC_CFGR;
	__vo uint32_t CIR;
	__vo uint32_t RCC_AHB1RSTR;
	__vo uint32_t RCC_AHB2RSTR;
	__vo uint32_t RCC_AHB3RSTR;
	__vo uint32_t RESERVED1;
	__vo uint32_t RCC_APB1RSTR;
	__vo uint32_t RCC_APB2RSTR;
	__vo uint32_t RESERVED2;
	__vo uint32_t RESERVED3;
	__vo uint32_t RCC_AHB1ENR;
	__vo uint32_t RCC_AHB2ENR;
	__vo uint32_t RCC_AHB3ENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED5;
	__vo uint32_t RESERVED6;
	__vo uint32_t RCC_AHB1LPENR;
	__vo uint32_t RCC_AHB2LPENR;
	__vo uint32_t RCC_AHB3LPENR;
	__vo uint32_t RESERVED7;
	__vo uint32_t RCC_APB1LPENR;
	__vo uint32_t RCC_APB2LPENR;
	__vo uint32_t RESERVED8;
	__vo uint32_t RESERVED9;
	__vo uint32_t RCC_BDCR;
	__vo uint32_t RCC_CSR;
	__vo uint32_t RESERVED10;
	__vo uint32_t RESERVED11;
	__vo uint32_t RCC_SSCGR;
	__vo uint32_t RCC_PLLI2SCFGR;

}RCC_RegDef_t;


typedef struct{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];

}GPIO_RegDef_t;

//MACROS FOR GPIO PERIPHERAL ENABLE
#define GPIOA_ENABLE			(uint32_t*)()
#define GPIOB_ENABLE
#define GPIOC_ENABLE
#define GPIOD_ENABLE
#define GPIOE_ENABLE
#define GPIOF_ENABLE
#define GPIOG_ENABLE
#define GPIOH_ENABLE
#define GPIOI_ENABLE
#define GPIOJ_ENABLE

//MACROS FOR GPIO PERIPHERAL DISABLE
#define GPIOA_DISABLE
#define GPIOB_DISABLE
#define GPIOC_DISABLE
#define GPIOD_DISABLE
#define GPIOE_DISABLE
#define GPIOF_DISABLE
#define GPIOG_DISABLE
#define GPIOH_DISABLE
#define GPIOI_DISABLE
#define GPIOJ_DISABLE




//#define
//#define
//#define




#endif /* INC_STM32F4XX_DRIVER_H_ */
