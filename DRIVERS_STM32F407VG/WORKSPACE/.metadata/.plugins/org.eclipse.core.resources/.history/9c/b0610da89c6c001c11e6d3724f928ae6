/*
 * uart.h
 *
 *  Created on: Dec 31, 2021
 *      Author: Navjeevan
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include<stm32f4xx_driver.h>

typedef struct
{
	uint32_t USARTMode;
	uint32_t USARTBaud;
	uint32_t USART_StopBits;
	uint32_t USART_WordLength;
	uint32_t USART_ParityControl;
	uint32_t USART_HWFlowControl;
}USART_Config_t;


typedef struct
{
 USART_RegDef_t *pUSARTx;
 USART_Config_t pUSARTPinConfig;
}USART_Handle_t;

//DEFEINITIONS
#define USART_CR1_SBK		(1<<0)
#define USART_CR1_RWU		(1<<1)
#define USART_CR1_RE 		(1<<2)
#define USART_CR1_TE		(1<<3)
#define USART CR1_IDLEIE	(1<<4)
#define USART_CR1_RXNEIE	(1<<5)
#define USART_CR1_TCIE		(1<<6)
#define USART_CR1_TXEIE		(1<<7)
#define USART_CR1_PEIE		(1<<8)
#define USART_CR1_PS		(1<<9)
#define USART_CR1_PCE		(1<<10)
#define USART_CR1_WAKE		(1<<11)
#define USART_CR1_M			(1<<12)
#define USART_CR1_UE		(1<<13)
#define USART_CR1_OVER8		(1<<15)



/*
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
*/


//FUNCTION PROTOTYPES
void USART_PeriClockEnable(USART_RegDef_t *pUSARTx, uint8_t EnaOrDis);
void USART_PeripheralEnable(USART_RegDef_t *pUSARTx, uint8_t EnaOrDis);
void USART_Init(USART_Handle_t *pUSARTHandle);
void USART_DeInit(USART_RegDef_t *pUSARTx);
uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx, uint32_t Flagname);
void USART_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnaOrDis);
void USART_IRQHandler(USART_Handle_t *pUSARTHandle);
void USART_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQpriority);


#endif /* INC_UART_H_ */
