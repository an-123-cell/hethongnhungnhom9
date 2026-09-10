#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018)

#define GPIOA_CRL   (*(volatile uint32_t*)0x40010800)
#define GPIOA_CRH   (*(volatile uint32_t*)0x40010804)
#define GPIOA_IDR   (*(volatile uint32_t*)0x40010808)
#define GPIOA_ODR   (*(volatile uint32_t*)0x4001080C)

void delay(void)
{
    volatile uint32_t i;
    for (i = 0; i < 100000; i++);
}

int main(void)
{
    RCC_APB2ENR |= (1 << 2);

    GPIOA_CRL &= ~(0xF << 0);
    GPIOA_CRL |=  (0x8 << 0);

    GPIOA_CRH &= ~(0xF << 0);
    GPIOA_CRH |=  (0x2 << 0);

    GPIOA_ODR |= (1 << 0);
    GPIOA_ODR &= ~(1 << 8);

    while (1)
    {
        if ((GPIOA_IDR & (1 << 0)) == 0)
        {
            delay();

            if ((GPIOA_IDR & (1 << 0)) == 0)
            {
                GPIOA_ODR ^= (1 << 8);

                while ((GPIOA_IDR & (1 << 0)) == 0)
                {
                }

                delay();
            }
        }
    }

    return 0;
}
