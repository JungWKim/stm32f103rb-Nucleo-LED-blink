#define RCC 0x40021000
#define RCC_APB2ENR (unsigned int*)(RCC + 0x18)

#define GPIOA 0x40010800
#define GPIOA_CRL (unsigned int*)(GPIOA + 0x00)
#define GPIOA_ODR (unsigned int*)(GPIOA + 0x0c)
#define GPIOA_BSRR (unsigned int*)(GPIOA + 0x10)

int main()
{
	volatile int count = 0;
	
	//IOPA clock enable
	*RCC_APB2ENR |= (1<<2);
	
	//GPIOA_BSRR(0x10) - BR5[21] = 1(reset)
	//GPIOA_BSRR(0x10) - BS5[5] = 1(set)
	
	//PA5 push-pull output
	*GPIOA_CRL &= (unsigned int)~(1<<23);
	*GPIOA_CRL &= (unsigned int)~(1<<22);
	
	//PA5 max speed 10MHz
	*GPIOA_CRL &= (unsigned int)~(1<<21);
	*GPIOA_CRL |= (unsigned int)(1<<20);
	
	while(1)
	{
		//PA5 output 1
		*GPIOA_ODR |= (unsigned int)(1<<5);
		
		//delay
		while(count < 1000000)
			count++;
		count = 0;
		
		//PA5 output 0(reset)
		*GPIOA_BSRR |= (1<<21);
		
		//delay
		while(count < 1000000)
			count++;
		count = 0;
	}
}
