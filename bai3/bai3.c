#include <stdint.h>

#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018)
#define AFIO_MAPR   (*(volatile uint32_t*)0x40010004)

#define GPIOA_CRL   (*(volatile uint32_t*)0x40010800)
#define GPIOA_CRH   (*(volatile uint32_t*)0x40010804)
#define GPIOA_IDR   (*(volatile uint32_t*)0x40010808)
#define GPIOA_ODR   (*(volatile uint32_t*)0x4001080C)

#define GPIOB_CRL   (*(volatile uint32_t*)0x40010C00)
#define GPIOB_ODR   (*(volatile uint32_t*)0x40010C0C)

void delay(void)
{
    for(volatile uint32_t i=0;i<80000;i++);
}

int main(void)
{
    RCC_APB2ENR|=(1<<0)|(1<<2)|(1<<3);

    AFIO_MAPR&=~(7<<24);
    AFIO_MAPR|=(2<<24);

    GPIOA_CRL=0x88888888;
    GPIOA_CRH=0x22222222;

    GPIOA_ODR|=0xFF;

    GPIOB_CRL&=~((0xF<<12)|(0xF<<16));
    GPIOB_CRL|=(0x2<<12)|(0x2<<16);

    GPIOA_ODR|=(1<<8)|(1<<9)|(1<<10)|(1<<11)|(1<<12)|(1<<15);
    GPIOB_ODR|=(1<<3)|(1<<4);

    while(1)
    {
        if(!(GPIOA_IDR&(1<<0)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<0)))
            {
                GPIOA_ODR^=(1<<8);
                while(!(GPIOA_IDR&(1<<0)));
            }
        }

        if(!(GPIOA_IDR&(1<<1)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<1)))
            {
                GPIOA_ODR^=(1<<9);
                while(!(GPIOA_IDR&(1<<1)));
            }
        }

        if(!(GPIOA_IDR&(1<<2)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<2)))
            {
                GPIOA_ODR^=(1<<10);
                while(!(GPIOA_IDR&(1<<2)));
            }
        }

        if(!(GPIOA_IDR&(1<<3)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<3)))
            {
                GPIOA_ODR^=(1<<11);
                while(!(GPIOA_IDR&(1<<3)));
            }
        }

        if(!(GPIOA_IDR&(1<<4)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<4)))
            {
                GPIOA_ODR^=(1<<12);
                while(!(GPIOA_IDR&(1<<4)));
            }
        }

        if(!(GPIOA_IDR&(1<<5)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<5)))
            {
                GPIOA_ODR^=(1<<15);
                while(!(GPIOA_IDR&(1<<5)));
            }
        }

        if(!(GPIOA_IDR&(1<<6)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<6)))
            {
                GPIOB_ODR^=(1<<3);
                while(!(GPIOA_IDR&(1<<6)));
            }
        }

        if(!(GPIOA_IDR&(1<<7)))
        {
            delay();
            if(!(GPIOA_IDR&(1<<7)))
            {
                GPIOB_ODR^=(1<<4);
                while(!(GPIOA_IDR&(1<<7)));
            }
        }
    }
}
