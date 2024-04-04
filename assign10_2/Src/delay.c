/*
 * delay.c
 *
 *  Created on: Apr 4, 2024
 *      Author: pritesh
 */

#include"delay.h"

void Tim_Init()
{
	//timer clock enable
	RCC->APB1ENR |= BV(5);

	//timer prescaler
	TIM7->PSC = 16000-1;
}


void delay(int ms)
{
	//no. of pulses calculation formula
	uint16_t cnt =(16000000 / 1000)*ms / 16000;

	//count store in data
	TIM7->ARR = cnt-1;

	TIM7->CNT= 0;

	TIM7->CR1 |=BV(0);

	while (!(TIM7->SR & BV(0)))
				;
	TIM7->SR &= ~BV(0);

	TIM7->CR1 &=~BV(0);

}

