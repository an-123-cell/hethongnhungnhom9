#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018)
#define GPIOA_CRL   (*(volatile uint32_t*)0x40010800)
#define GPIOA_ODR   (*(volatile uint32_t*)0x4001080C)

void delay(void)
{
    for (volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    // Bật clock GPIOA
    RCC_APB2ENR |= (1 << 2);

    // PA0 -> PA7: Output Push-Pull
    GPIOA_CRL = 0x22222222;

    while (1)
    {
        // PA0 -> PA7
        for (int i = 0; i < 8; i++)
        {
            GPIOA_ODR = (1 << i);
            delay();
        }

        // PA7 -> PA0
        for (int i = 6; i >= 0; i--)
        {
            GPIOA_ODR = (1 << i);
            delay();
        }
    }
}
