/* Name   : Belal Mohamed											  */
/* Bench     : 23												   	  */
#ifndef FILE_HEADER_H
#define FILE_HEADER_H

        /* STD TYPES */
typedef unsigned char           uint8;         
typedef unsigned short          uint16;        
typedef unsigned long           uint32;     
typedef unsigned long long      uint64;

        /* BIT_MATH */
#define SET_BIT(VAR, BIT)       VAR |= (1 << (BIT))
#define CLR_BIT(VAR, BIT)       (VAR &= ~(1 << (BIT)))
#define GET_BIT(VAR, BIT)       ((VAR >> BIT) & 1)
#define TOG_BIT(VAR, BIT)       VAR ^= (1 << (BIT))

#define REG32(BASE_ADDR, OFFSET)  (*(volatile uint32 *)((BASE_ADDR) + (OFFSET)))

            /* RCC Register Definition  ON AHB1*/
#define RCC_BASE_ADDR       0x40023800
#define RCC_AHB1ENR         REG32(RCC_BASE_ADDR, 0x30UL)



			/* GPIO Registers Definition */
#define GPIOB_BASE_ADDR 		0x40020400

			/* Registers Definition For PORT B */
#define GPIOB_MODER 			REG32(GPIOB_BASE_ADDR, 0x00)
#define GPIOB_OTYPER 			REG32(GPIOB_BASE_ADDR, 0x04)
#define GPIOB_PUPDR 			REG32(GPIOB_BASE_ADDR, 0x0C)
#define GPIOB_IDR 				REG32(GPIOB_BASE_ADDR, 0x10)
#define GPIOB_ODR 				REG32(GPIOB_BASE_ADDR, 0x14)
#define GPIOB_BSRR 				REG32(GPIOB_BASE_ADDR, 0x18)


        /* Define BUS-es	*/
#define RCC_AHB1 0UL
#define RCC_AHB2 1UL
#define RCC_APB1 2UL
#define RCC_APB2 3UL

        /* Define AHB1 Peripherals */
#define RCC_GPIOA (uint8)(RCC_AHB1 + 0UL)
#define RCC_GPIOB (uint8)(RCC_AHB1 + 1UL)
#define RCC_GPIOC (uint8)(RCC_AHB1 + 2UL)

                /*      RCC Functions    */
/*  Initialize System Clock */
void RCC_voidInitSysClock(void);  

/* Enable Clock for a Peripheral */
void RCC_voidEnableClock(uint8 Copy_uint8PeripheralId);

		/* Define Ports */
#define GPIO_B  1

		/* Define PIN_S */
#define		PIN3	3
#define		PIN5	5
#define		PIN6	6
#define		PIN7	7


		/*PinMode   (MODER) */
#define GPIO_INPUT  0
#define GPIO_OUTPUT 1
#define GPIO_AF     2
#define GPIO_ANALOG 3

		// /DefaultState/
		/* OutPut Type (OTYPER) */
#define OUTPUT_PUSH_PULL  0
#define OUTPUT_OPEN_DRAIN 1

		/* InPut Type (PUPDR) */
#define INPUT_NO_PULL		0	
#define INPUT_PULL_UP		1
#define INPUT_PULL_DOWN		2


		/* Data */
#define LOW  	0
#define HIGH 	1


#endif