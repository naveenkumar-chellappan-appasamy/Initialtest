#include <stm32f10x.h>
#include "stdio.h"

static uint32_t Time;

void systick()
{
        SysTick_Config(SystemCoreClock / 1000000);
}
void SysTick_Handler(void)
{
        if (Time != 0x00)
        {
                Time--;
        }
}
void Delayus(uint32_t r)
{
	Time=r;
	while(Time != 0);
}
void Delayms(uint32_t nTime)
{
//         TimingDelay = nTime;
//         while(TimingDelay != 0);
			while(nTime--)
			{
			Delayus(1000);
			}				
}

int main()
{
//	int i;
//	SystemInit();
		//systick();	
	RCC->CR=0x00000001;
	RCC->CFGR=0x05000000;
	systick();
	RCC->APB2ENR=(1<<4)|(1<<3);
	GPIOC->CRH=0x00200000;
	GPIOB->CRH=0x08;
	GPIOC->BRR=(1<<13);
	while(1)
	{
		if((GPIOB->IDR & (0<<8))==1)
		{
		GPIOC->BSRR=0x00002000;
		//for(i=0;i<100000;i++);
		}
		//Delayms(500);
		else
		GPIOC->BRR=0x00002000;
		//for(i=0;i<100000;i++);
		//Delayms(500);
	}
}
