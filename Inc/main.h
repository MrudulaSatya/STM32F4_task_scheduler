/*
 * main.h
 *
 *  Created on: May 11, 2025
 *      Author: mrudula.y
 */

#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS				5

#define SRAM_START				0x20000000U
#define SRAM_SIZE				((128) * 1024) //BYTES
#define SRAM_END				((SRAM_START) + (SRAM_SIZE))

#define TASK_STACK_SIZE			1024U //BYTES
#define SCHED_STACK_SIZE		1024U //BYTES

#define T1_STACK_START			SRAM_END
#define T2_STACK_START			((SRAM_END) - (TASK_STACK_SIZE))
#define T3_STACK_START			((SRAM_END) - (2 * TASK_STACK_SIZE))
#define T4_STACK_START			((SRAM_END) - (3 * TASK_STACK_SIZE))
#define IDLE_STACK_START		((SRAM_END) - (4 * TASK_STACK_SIZE))
#define SCHED_STACK_START		((SRAM_END) - (5 * TASK_STACK_SIZE))

#define HSI_CLOCK 				16000000U
#define SYSTICK_TIM_CLK			HSI_CLOCK

#define TICK_HZ 				1000U

#define TASK_READY				0x00
#define TASK_BLOCKED			0xFF

#define MAX_DELAY 				0xFFFFFFFFU // 32 bit max delay

//Setting the last bit of PRIMASK special register to disable interrupts
#define DISABLE_INTERRUPTS() 	do {__asm volatile ("MOV R0, #0x1"); __asm volatile ("MSR PRIMASK, R0");} while(0)
//Clearing the last bit of PRIMASK special register to enable interrupts
#define ENABLE_INTERRUPTS() 	do {__asm volatile ("MOV R0, #0x0"); __asm volatile ("MSR PRIMASK, R0");} while(0)

#define PRIORITY_TASK			4U

#endif /* MAIN_H_ */
