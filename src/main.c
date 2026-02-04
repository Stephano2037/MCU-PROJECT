#include "stm32f446xx.h"

void SystemClock_Config(void);

int main(void)
{
    //Clock Enable
    SystemClock_Config();

    //GPIO LED (PA5) settings 
    RCC->AHB1ENR |=RCC_AHB1ENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;

    while(1) {
        GPIOA->ODR ^=GPIO_ODR_ODR_5; //toggle
        for(volatile int i=0; i<100000; ++i) ; //Delay;
    }
}


void SystemClock_Config(void){
    //Phase 1 코드 
    RCC->CR |= RCC_CR_HSEON;
    while(!(RCC->CR & RCC_CR_HSERDY));

}