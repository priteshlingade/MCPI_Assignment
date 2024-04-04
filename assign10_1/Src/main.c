/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "i2c_lcd.h"
#include "rtc.h"

#include"uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str1[24], str2[20];
	RTC_Date d, dt = { .Date = 31, .Month = 12, .Year = 23, .WeekDay = 7 };
	RTC_Time t, tm = { .Hours = 23, .Minutes = 59, .Seconds = 40 };

	SystemInit();
	UartInit(BAUD_9600);
	//LcdInit();
	//LcdPuts(LCD_LINE1, "DESD @ Sunbeam\n");
	//LcdPuts(LCD_LINE2, "STM32 RTC Demo!\n");
	//DelayMs(2000);
	//LcdWrite(LCD_CMD, LCD_CLEAR);
	RTC_Init(&dt, &tm);
	while(1) {
		RTC_GetTime(&t);
		RTC_GetDate(&d);

		UartPuts("\r \n");
		sprintf(str1, "DT=%02d-%02d-%02d W=%d", d.Date, d.Month, d.Year, d.WeekDay);
		UartPuts(str1);
		UartPuts("\r \n");
		sprintf(str2, "TM=%02d:%02d:%02d", t.Hours, t.Minutes, t.Seconds);
		UartPuts(str2);
		UartPuts("\r \n");

		DelayMs(1000);
	}
	return 0;
}
