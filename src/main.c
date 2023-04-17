/* Name : Belal Mohamed                                               */
/* Bench Number: 23													  */

#include "header_file.h"


int main()
{
	/*  Initialize System Clock */
	SET_BIT(RCC_AHB1ENR,RCC_GPIOB);


	GPIOB_MODER &= ~(0b11 << (PIN3 * 2));
	GPIOB_MODER |=  (GPIO_INPUT << (PIN3 * 2));
	GPIOB_PUPDR &= ~(0b11 << (PIN3 * 2));
	GPIOB_PUPDR |=  (INPUT_PULL_UP << (PIN3 * 2));

	/* Pin 5 intializtion*/
	GPIOB_MODER &= ~(0b11 << (PIN5 * 2));
	GPIOB_MODER |=  (GPIO_OUTPUT << (PIN5 * 2));
	CLR_BIT(GPIOB_OTYPER, PIN5);
	GPIOB_OTYPER |= (OUTPUT_PUSH_PULL << PIN5);
	CLR_BIT(GPIOB_ODR, PIN5);
	GPIOB_ODR |= (LOW << PIN5);

	/* Pin 6 intializtion*/
	GPIOB_MODER &= ~(0b11 << (PIN6 * 2));
	GPIOB_MODER |=  (GPIO_OUTPUT << (PIN6 * 2));
	CLR_BIT(GPIOB_OTYPER, PIN6);
	GPIOB_OTYPER |= (OUTPUT_PUSH_PULL << PIN6);
	CLR_BIT(GPIOB_ODR, PIN6);
	GPIOB_ODR |= (LOW << PIN6);

	/* Pin 7 intializtion*/
	GPIOB_MODER &= ~(0b11 << (PIN7 * 2));
	GPIOB_MODER |=  (GPIO_OUTPUT << (PIN7 * 2));
	CLR_BIT(GPIOB_OTYPER, PIN7);
	GPIOB_OTYPER |= (OUTPUT_PUSH_PULL << PIN7);
	CLR_BIT(GPIOB_ODR, PIN7);
	GPIOB_ODR |= (LOW << PIN7);


	uint16 counter = 0;
	uint8 current_state=1;
	uint8 prev_state=1;

	while (1)
	{
		// Read Button
		current_state =  GET_BIT(GPIOB_IDR, PIN3);

		// If Button is Pressed
		if((current_state==0) && (prev_state==1))
		{
			// Delay to make sure it wasn't noise
			for (uint16 i = 0; i < 1000000; i++);

			current_state = GET_BIT(GPIOB_IDR, PIN3);

			// If still Pressed so wasn't Noise
			if(current_state == 0)
			{
				if(counter == 7)
				{
					counter = -1;
				}
				++counter;
				prev_state=0;
			}
		}
		CLR_BIT(GPIOB_ODR, PIN5);
		GPIOB_ODR |= (GET_BIT(counter, 0) << PIN5);

		CLR_BIT(GPIOB_ODR, PIN6);
		GPIOB_ODR |= (GET_BIT(counter, 1) << PIN6);

		CLR_BIT(GPIOB_ODR, PIN7);
		GPIOB_ODR |= (GET_BIT(counter, 2) << PIN7);


		if(current_state==1)
		{
			prev_state=1;
		}
	}
	return 0;
}

