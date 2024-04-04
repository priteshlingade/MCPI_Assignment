/*
 * delay.h
 *
 *  Created on: Apr 4, 2024
 *      Author: pritesh
 */

#ifndef DELAY_H_
#define DELAY_H_


#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define TCLK 16000000
#define TIM_PR	16000

void Tim_Init();
void delay(int ms);


#endif /* DELAY_H_ */
