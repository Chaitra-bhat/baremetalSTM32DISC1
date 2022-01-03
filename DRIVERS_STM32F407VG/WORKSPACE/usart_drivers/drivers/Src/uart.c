/*
 * uart.c
 *
 *  Created on: Dec 31, 2021
 *      Author: Navjeevan
 */

#include<uart.h>
#include<rcc.h>

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

void USART_SetBaudRate(USART_RegDef_t *pUSARTx, uint32_t BaudRate)
{

	//Variable to hold the APB clock
	uint32_t PCLKx;

	uint32_t usartdiv;

	//variables to hold Mantissa and Fraction values
	uint32_t M_part,F_part;

  uint32_t tempreg=0;

  //Get the value of APB bus clock in to the variable PCLKx
  if(pUSARTx == USART1 || pUSARTx == USART6)
  {
	   //USART1 and USART6 are hanging on APB2 bus
	   PCLKx = RCC_GetPCLK2Value();
  }else
  {
	   PCLKx = RCC_GetPCLK1Value();
  }

  //Check for OVER8 configuration bit
  if(pUSARTx->USART_CR1 & (1 << USART_CR1_OVER8))
  {
	   //OVER8 = 1 , over sampling by 8
	   usartdiv = ((25 * PCLKx) / (2 *BaudRate));
  }else
  {
	   //over sampling by 16
	   usartdiv = ((25 * PCLKx) / (4 *BaudRate));
  }

  //Calculate the Mantissa part
  M_part = usartdiv/100;

  //Place the Mantissa part in appropriate bit position . refer USART_BRR
  tempreg |= M_part << 4;

  //Extract the fraction part
  F_part = (usartdiv - (M_part * 100));

  //Calculate the final fractional
  if(pUSARTx->USART_CR1 & ( 1 << USART_CR1_OVER8))
   {
	  //OVER8 = 1 , over sampling by 8
	  F_part = ((( F_part * 8)+ 50) / 100)& ((uint8_t)0x07);

   }else
   {
	   //over sampling by 16
	   F_part = ((( F_part * 16)+ 50) / 100) & ((uint8_t)0x0F);

   }

  //Place the fractional part in appropriate bit position . refer USART_BRR
  tempreg |= F_part;

  //copy the value of tempreg in to BRR register
  pUSARTx->USART_BRR = tempreg;
}

void USART_Init(USART_Handle_t *pUSARTHandle)
{

	//Temporary variable
		uint32_t tempreg=0;

	/******************************** Configuration of CR1******************************************/

		//Implement the code to enable the Clock for given USART peripheral
		 USART_PeripheralEnable(pUSARTHandle->pUSARTx, ENABLE);

		//Enable USART Tx and Rx engines according to the USART_Mode configuration item
		if ( pUSARTHandle->pUSARTPinConfig.USARTMode == USART_MODE_ONLY_RX)
		{
			//Implement the code to enable the Receiver bit field
			tempreg|= (1 << USART_CR1_RE);
		}else if (pUSARTHandle->pUSARTPinConfig.USARTMode == USART_MODE_ONLY_TX)
		{
			//Implement the code to enable the Transmitter bit field
			tempreg |= ( 1 << USART_CR1_TE );

		}else if (pUSARTHandle->pUSARTPinConfig.USARTMode == USART_MODE_TXRX)
		{
			//Implement the code to enable the both Transmitter and Receiver bit fields
			tempreg |= ( ( 1 << USART_CR1_RE) | ( 1 << USART_CR1_TE) );
		}

	    //Implement the code to configure the Word length configuration item
		tempreg |= (pUSARTHandle->pUSARTPinConfig.USART_WordLength << USART_CR1_M) ;


	    //Configuration of parity control bit fields
		if ( pUSARTHandle->pUSARTPinConfig.USART_WordLength == USART_PARITY_EN_EVEN)
		{
			//Implement the code to enable the parity control
			tempreg |= ( 1 << 10);

			//Implement the code to enable EVEN parity
			//Not required because by default EVEN parity will be selected once you enable the parity control

		}else if (pUSARTHandle->pUSARTPinConfig.USART_ParityControl == USART_PARITY_EN_ODD )
		{
			//Implement the code to enable the parity control
		    tempreg |= ( 1 << 10);

		    //Implement the code to enable ODD parity
		    tempreg |= ( 1 << USART_CR1_PS);

		}

	   //Program the CR1 register
		pUSARTHandle->pUSARTx->USART_CR1 = tempreg;

	/******************************** Configuration of CR2******************************************/

		tempreg=0;

		//Implement the code to configure the number of stop bits inserted during USART frame transmission
		tempreg |= pUSARTHandle->pUSARTPinConfig.USART_StopBits << USART_CR2_STOP;

		//Program the CR2 register
		pUSARTHandle->pUSARTx->USART_CR2 = tempreg;

	/******************************** Configuration of CR3******************************************/

		tempreg=0;

		//Configuration of USART hardware flow control
		if ( pUSARTHandle->pUSARTPinConfig.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS)
		{
			//Implement the code to enable CTS flow control
			tempreg |= ( 1 << USART_CR3_CTSE);


		}else if (pUSARTHandle->pUSARTPinConfig.USART_HWFlowControl == USART_HW_FLOW_CTRL_RTS)
		{
			//Implement the code to enable RTS flow control
			tempreg |= ( 1 << USART_CR3_RTSE);

		}else if (pUSARTHandle->pUSARTPinConfig.USART_HWFlowControl == USART_HW_FLOW_CTRL_CTS_RTS)
		{
			//Implement the code to enable both CTS and RTS Flow control
			tempreg |= ( 1 << USART_CR3_CTSE);
			tempreg |= ( 1 << USART_CR3_RTSE);
		}


		pUSARTHandle->pUSARTx->USART_CR3 = tempreg;

	/******************************** Configuration of BRR(Baudrate register)******************************************/

		//Implement the code to configure the baud rate
		//We will cover this in the lecture. No action required here
		USART_SetBaudRate(pUSARTHandle->pUSARTx, pUSARTHandle->pUSARTPinConfig.USARTBaud);

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


void USART_ClearFlag(USART_RegDef_t *pUSARTx, uint16_t StatusFlagName)
{
	pUSARTx->USART_SR &= ~( StatusFlagName);

}
