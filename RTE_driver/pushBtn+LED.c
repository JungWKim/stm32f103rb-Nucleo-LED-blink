#include "GPIO_STM32F10x.h"

int main()
{
	//USER LED ENABLE
	GPIO_PortClock (GPIOA, true);
	GPIO_PinConfigure(GPIOA, 5, GPIO_OUT_PUSH_PULL, GPIO_MODE_OUT10MHZ);
	
	//USER BUTTON ENABLE
	GPIO_PortClock (GPIOC, true);
	GPIO_PinConfigure(GPIOC, 13, GPIO_IN_FLOATING, GPIO_MODE_INPUT);
	
	while(1)
	{
		if(GPIO_PinRead (GPIOC, 13))
			GPIO_PinWrite (GPIOA, 5, 0);
		else
			GPIO_PinWrite (GPIOA, 5, 1);
	}
}
