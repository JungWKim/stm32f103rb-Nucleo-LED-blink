#include "GPIO_STM32F10x.h"

void delay(int num)
{
	int count = 0;
	
	while(count < num)
	{
		count++;
	}
	count = 0;
}

int main()
{
	//GPIO_PortClock (GPIOA, true);
	GPIO_PinConfigure(GPIOA, 5, GPIO_OUT_PUSH_PULL, GPIO_MODE_OUT10MHZ);
	
	while(1)
	{
		GPIO_PinWrite (GPIOA, 5, 1);
		delay(1000000);
		GPIO_PinWrite (GPIOA, 5, 0);
		delay(1000000);
	}
}
