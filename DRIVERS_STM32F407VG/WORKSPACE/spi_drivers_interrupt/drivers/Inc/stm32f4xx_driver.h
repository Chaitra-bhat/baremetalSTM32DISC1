/*
 * stm32f4xx_driver.h
 *
 *  Created on: Dec 25, 2021
 *      Author: Navjeevan
 */

#ifndef INC_STM32F4XX_DRIVER_H_
#define INC_STM32F4XX_DRIVER_H_

#include<stdint.h>
//#include<gpio.h>
//#include<spi.h>

//GENERAL MACROS
#define ENABLE			1U
#define DISABLE			0U
#define SET				ENABLE
#define RESET			DISABLE
#define BUTTON_PRESSED	SET


#define __vo volatile

//MEMORY ADDRESS OF MEMORY PERIPHERALS
#define	FLASH_BASEADDR				0x8000000U
#define SRAM1_BASEADDR				0x2000000U

//PERIPHERAL BASE ADDRESS DETAILS OF AHB1 INTERFACES
#define GPIOA_BASEADDR				0x40020000U
#define GPIOB_BASEADDR				0x40020400U
#define GPIOC_BASEADDR				0x40020800U
#define GPIOD_BASEADDR				0x40020C00U
#define GPIOE_BASEADDR				0x40021000U
#define GPIOF_BASEADDR				0x40021400U
#define GPIOG_BASEADDR				0x40021800U
#define GPIOH_BASEADDR				0x40021C00U
#define GPIOI_BASEADDR 				0x40022000U
#define GPIOJ_BASEADDR				0x40022400U
#define GPIOK_BASEADDR				0x40022800U
#define CRC_BASEADDR				0x40023000U
#define RCC_BASEADDR				0x40023800U
#define FLASH_INTERFACE_BASEADDR	0x40023C00U
#define BKPSRAM_BASEADDR			0x40024000U
#define DMA1_BASEADDR				0x40026000U
#define DMA2_BASEADDR				0x40026400U
#define ETHERNET_MAC_BASEADDR		0x40028000U
#define DMA2D_BASEADDR				0x4002B000U
#define USB_OTG_HS_BASEADDR			0x40040000U

//PERIPHERAL BASE ADDRESS DETAILS OF AHB2 INTERFACES
#define USB_OTG_FS_BASEADDR			0x50000000U
#define DCMI_BASEADDR				0x50050000U
#define CRYP_BASEADDR				0x50060000U
#define HASH_BASEADDR				0x50060400U
#define RNG_BASEADDR				0x50060800U

//PERIPHERAL BASE ADDRESS DETAILS OF AHB3 INTERFACES
#define FSMC_BASEADDR				0xA0000000U

//PERIPHERAL BASE ADDRESS DETAILS OF APB1 INTERFACES
#define	TIM2_BASEADDR				0x40000000U
#define TIM3_BASEADDR				0x40000400U
#define TIM4_BASEADDR				0x40000800U
#define TIM5_BASEADDR				0x40000C00U
#define TIM6_BASEADDR				0x40001000U
#define TIM7_BASEADDR				0x40001400U
#define TIM12_BASEADDR				0x40001800U
#define TIM13_BASEADDR				0x40001C00U
#define TIM14_BASEADDR				0x40002000U
#define RTC_BKP_BASEADDR			0x40002800U
#define WWDG_BASEADDR				0x40002C00U
#define IWDG_BASEADDR				0x40003000U
#define I2S2ext_BASEADDR			0x40003400U
#define SPI2_I2S2_BASEADDR			0x40003800U
#define SPI3_I2S3_BASEADDR			0x40003C00U
#define I2S3_ext_BASEADDR			0x40003C00U
#define USART2_BASEADDR				0x40004400U
#define USART3_BASEADDR				0x40004800U
#define UART4_BASEADDR				0x40004C00U
#define UART5_BASEADDR				0x40005000U
#define I2C1_BASEADDR				0x40005400U
#define I2C2_BASEADDR				0x40005800U
#define I2C3_BASEADDR				0x40005C00U
#define CAN1_BASEADDR				0x40006400U
#define CAN2_BASEADDR				0x40006800U
#define PWR_BASEADDR				0x40007000U
#define DAC_BASEADDR				0x40007400U
#define UART7_BASEADDR				0x40007800U
#define UART8_BASEADDR				0x40007C00U


//PERIPHERAL BASE ADDRESS DETAILS OF APB2 INTERFACES
#define TIM1_BASEADDR				0x40010000U
#define TIM8_BASEADDR				0x40010400U
#define USART1_BASEADDR				0x40011000U
#define USART6_BASEADDR				0x40011400U
#define ADC_1_2_3_BASEADDR			0x40012000U
#define SDIO_BASEADDR				0x40012C00U
#define SPI1_BASEADDR				0x40013000U
#define SPI4_BASEADDR				0x40013400U
#define SYSCFG_BASEADDR				0x40013800U
#define EXTI_BASEADDR				0x40013C00U
#define TIM9_BASEADDR				0x40014000U
#define TIM10_BASEADDR				0x40014400U
#define TIM11_BASEADDR				0x40014800U
#define SPI5_BASEADDR				0x40015000U
#define SPI6_BASEADDR				0x40015400U
#define SAI1_BASEADDR				0x40015800U
#define LCD_TFT_BASEADDR			0x40016800U

// IRQ NUMBERS POSITION FROM REFERENCE MANUAL FOR GPIO
#define IRQNumber_0					6U
#define IRQNumber_1					7U
#define IRQNumber_2					8U
#define IRQNumber_3	 				9U
#define IRQNumber_4					10U
#define IRQNumber_5_9				23U
#define IRQNumber_10_15				40U

//IRQ NUMBERS POSITION FROM REFERENCE MANUAL FOR SPI
#define IRQNumber_SPI1				35U
#define IRQNumber_SPI2				36U
#define IRQNumber_SPI3				51U



//Processor specific details
#define NVIC_ISER0						((__vo uint32_t*)0xE000E100U)
#define NVIC_ISER1						((__vo uint32_t*)0xE000E104U)
#define NVIC_ISER2						((__vo uint32_t*)0xE000E108U)
#define NVIC_ICER0						((__vo uint32_t*)0XE000E180U)
#define NVIC_ICER1						((__vo uint32_t*)0XE000E184U)
#define NVIC_ICER2						((__vo uint32_t*)0XE000E188U)
#define NVIC_IPR0						((__vo uint32_t*)0xE000E400U)

#define NO_OF_PRIOBITS_IMPLEMENTED		4U

//REGISTER DEFINITION FOR RCC
typedef struct{
	__vo uint32_t RCC_CR;
	__vo uint32_t RCC_PLLCFGR;
	__vo uint32_t RCC_CFGR;
	__vo uint32_t CIR;
	__vo uint32_t RCC_AHB1RSTR;
	__vo uint32_t RCC_AHB2RSTR;
	__vo uint32_t RCC_AHB3RSTR;
	uint32_t RESERVED1;
	__vo uint32_t RCC_APB1RSTR;
	__vo uint32_t RCC_APB2RSTR;
	uint32_t RESERVED2;
	uint32_t RESERVED3;
	__vo uint32_t RCC_AHB1ENR;
	__vo uint32_t RCC_AHB2ENR;
	__vo uint32_t RCC_AHB3ENR;
	uint32_t RESERVED4;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
    uint32_t RESERVED5;
	uint32_t RESERVED6;
	__vo uint32_t RCC_AHB1LPENR;
	__vo uint32_t RCC_AHB2LPENR;
	__vo uint32_t RCC_AHB3LPENR;
	uint32_t RESERVED7;
	__vo uint32_t RCC_APB1LPENR;
	__vo uint32_t RCC_APB2LPENR;
	uint32_t RESERVED8;
	uint32_t RESERVED9;
	__vo uint32_t RCC_BDCR;
	__vo uint32_t RCC_CSR;
	uint32_t RESERVED10;
	uint32_t RESERVED11;
	__vo uint32_t RCC_SSCGR;
	__vo uint32_t RCC_PLLI2SCFGR;

}RCC_RegDef_t;

//REGISTER DEFINITION FOR RCC
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


// rEGISTER DEFINITION FOR EXTI
typedef struct
{
	__vo uint32_t EXTI_IMR;
	__vo uint32_t EXTI_EMR;
	__vo uint32_t EXTI_RTSR;
	__vo uint32_t EXTI_FTSR;
	__vo uint32_t EXTI_SWIER;
	__vo uint32_t EXTI_PR;

}EXTI_RegDef_t;

//REGISTER DEFINITION FOR SYSCFG
typedef struct
{
	__vo uint32_t SYSCFG_MEMRMP;
	__vo uint32_t SYSCFG_PMC;
	__vo uint32_t SYSCFG_EXTICR[4];
	__vo uint32_t SYSCFG_CMPCR;
}SYSCFG_RegDef_t;


// REGISTER DEFINITION FOR SPI
typedef struct{
	__vo uint32_t SPI_CR1;
	__vo uint32_t SPI_CR2;
	__vo uint32_t SPI_SR;
	__vo uint32_t SPI_DR;
	__vo uint32_t SPI_CRCPR;
	__vo uint32_t SPI_RXCRCR;
	__vo uint32_t SPI_TXCRCR;
	__vo uint32_t SPI_I2SCFGR;
	__vo uint32_t SPI_I2SPR;

}SPI_RegDef_t;


//PERIPHERAL ADDRESS  AHB1 PERIPHERALS
#define GPIOA			((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB			((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC			((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD			((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE			((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF			((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG			((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH			((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI			((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define GPIOJ			((GPIO_RegDef_t*)GPIOJ_BASEADDR)
#define GPIOK			((GPIO_RegDef_t*)GPIOK_BASEADDR)
#define RCC				((RCC_RegDef_t*)RCC_BASEADDR)

//PERIPHERAL ADDRESS OF APB1 REGISTERS
#define SPI2			((SPI_RegDef_t*)SPI2_I2S2_BASEADDR)
#define SPI3			((SPI_RegDef_t*)SPI3_I2S3_BASEADDR)

/*
#define
#define
#define
*/

// PERIPHERAL ADDRESS OF APB2 REGISTERS
#define EXTI			((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG			((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
#define SPI1			((SPI_RegDef_t*)SPI1_BASEADDR)



//MACROS FOR GPIO PERIPHERAL ENABLE
#define GPIOA_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<0))
#define GPIOB_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<1))
#define GPIOC_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<2))
#define GPIOD_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<3))
#define GPIOE_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<4))
#define GPIOF_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<5))
#define GPIOG_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<6))
#define GPIOH_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<7))
#define GPIOI_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<8))
#define GPIOJ_PCLK_ENABLE()				(RCC->RCC_AHB1ENR |= (1<<9))

//MACROS FOR GPIO PERIPHERAL DISABLE
#define GPIOA_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<8))
#define GPIOJ_PCLK_DISABLE()			(RCC->RCC_AHB1ENR &= ~(1<<9))

//MACROS FOR GPIO PERIPHERAL REG RESET
#define GPIOA_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<0)); (RCC->RCC_AHB1RSTR &= ~(1<<0)); }while(0)
#define GPIOB_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<1)); (RCC->RCC_AHB1RSTR &= ~(1<<1)); }while(0)
#define GPIOC_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<2)); (RCC->RCC_AHB1RSTR &= ~(1<<2)); }while(0)
#define GPIOD_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<3)); (RCC->RCC_AHB1RSTR &= ~(1<<3)); }while(0)
#define GPIOE_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<4)); (RCC->RCC_AHB1RSTR &= ~(1<<4)); }while(0)
#define GPIOF_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<5)); (RCC->RCC_AHB1RSTR &= ~(1<<5)); }while(0)
#define GPIOG_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<6)); (RCC->RCC_AHB1RSTR &= ~(1<<6)); }while(0)
#define GPIOH_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<7)); (RCC->RCC_AHB1RSTR &= ~(1<<7)); }while(0)
#define GPIOI_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<8)); (RCC->RCC_AHB1RSTR &= ~(1<<8)); }while(0)
#define GPIOJ_REG_RESET()				do{ (RCC->RCC_AHB1RSTR |= (1<<9)); (RCC->RCC_AHB1RSTR &= ~(1<<9)); }while(0)

//MACROS FOR SPI PERIPHERAL REG RESET
#define SPI1_REG_RESET()				do { (RCC->APB2ENR |= (1<<12)); (RCC->APB2ENR &= ~(1<<12)); }while(0)
#define SPI2_REG_RESET()				do { (RCC->APB2ENR |= (1<<14)); (RCC->APB2ENR &= ~(1<<14)); }while(0)
#define SPI3_REG_RESET()				do { (RCC->APB2ENR |= (1<<15)); (RCC->APB2ENR &= ~(1<<15)); }while(0)

/*
#define
#define
#define
#define
#define
*/

//Peripheral clock enable for SYSCFG
#define SYSCFG_PCLK_ENABLE()			(RCC->APB2ENR |= (1<<14))

//Peripheral clock enable for SPI
#define SPI1_PCLK_ENABLE()				((RCC->APB2ENR) |= (1<<12))
#define SPI2_PCLK_ENABLE()				((RCC->APB1ENR) |= (1<<14))
#define SPI3_PCLK_ENABLE()				((RCC->APB1ENR) |= (1<<15))

//Peripheral clock disable for SPi
#define SPI1_PCLK_DISABLE()				((RCC->APB2ENR) &= ~(1<<12))
#define SPI2_PCLK_DISABLE()				((RCC->APB1ENR) &= ~(1<<14))
#define SPI3_PCLK_DISABLE()				((RCC->APB1ENR) &= ~(1<<15))

//
#define GPIOBASEADDR_TO_CODE(x)		   ((x == GPIOA) ? 0 :\
										(x == GPIOB) ? 1 :\
										(x == GPIOC) ? 2 :\
										(x == GPIOD) ? 3 :\
										(x == GPIOE) ? 4 :\
										(x == GPIOF) ? 5 :\
										(x == GPIOG) ? 6 :\
										(x == GPIOH) ? 7 :\
										(x == GPIOI) ? 8 :\
										(x == GPIOJ) ? 9 : 0)


//Register definitions for each register so that its readable, like for CR1 of SPi make a set
/*
 * #define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
#define
 *
 */
#include<gpio.h>
#include<spi.h>

#endif /* INC_STM32F4XX_DRIVER_H_ */
