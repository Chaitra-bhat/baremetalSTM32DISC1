
#include <stdint.h>
#include <stm32f407xx.h>
#include <gpio.h>
#include <string.h>


void delay(int n){
	for(int i=0; i<n;i++);
}

int main(void)
{
  GPIO_Handle_t GPIOLed;

  GPIOLed.pGPIOx = GPIOD;
  GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PINUMBER_12;
  GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
  GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEED_MEDIUM;
  GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PUSHPULL;
  GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO;
  GPIO_PeriClockControl(GPIOD, ENABLE);
  GPIO_Init(&GPIOLed);


}
}


