/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : app_freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "w_code.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 128 * 4
};
/* Definitions for DisplayUpdate */
osThreadId_t DisplayUpdateHandle;
const osThreadAttr_t DisplayUpdate_attributes = {
  .name = "DisplayUpdate",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for ReadCommPorts */
osThreadId_t ReadCommPortsHandle;
const osThreadAttr_t ReadCommPorts_attributes = {
  .name = "ReadCommPorts",
  .priority = (osPriority_t) osPriorityBelowNormal7,
  .stack_size = 128 * 4
};
/* Definitions for uartDataKey */
osSemaphoreId_t uartDataKeyHandle;
const osSemaphoreAttr_t uartDataKey_attributes = {
  .name = "uartDataKey"
};
/* Definitions for adcDataKey */
osSemaphoreId_t adcDataKeyHandle;
const osSemaphoreAttr_t adcDataKey_attributes = {
  .name = "adcDataKey"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartDisplayUpdate(void *argument);
void StartReadCommPorts(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of uartDataKey */
  uartDataKeyHandle = osSemaphoreNew(1, 1, &uartDataKey_attributes);

  /* creation of adcDataKey */
  adcDataKeyHandle = osSemaphoreNew(1, 1, &adcDataKey_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of DisplayUpdate */
  DisplayUpdateHandle = osThreadNew(StartDisplayUpdate, NULL, &DisplayUpdate_attributes);

  /* creation of ReadCommPorts */
  ReadCommPortsHandle = osThreadNew(StartReadCommPorts, NULL, &ReadCommPorts_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
	w_Initialize();
	strcpy(w_uartBuff, "<<DATA>>");
	/* Infinite loop */
	for (;;) {
		osDelay(1);
	}
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartDisplayUpdate */
/**
 * @brief Function implementing the DisplayUpdate thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDisplayUpdate */
void StartDisplayUpdate(void *argument)
{
  /* USER CODE BEGIN StartDisplayUpdate */
	/* Infinite loop */
	for (;;) {

		osSemaphoreAcquire(uartDataKeyHandle, osWaitForever);
		osSemaphoreAcquire(adcDataKeyHandle, osWaitForever);

		w_oledCopyBuffer(w_oledParseUartData(w_uartBuff), 0, w_FONT2);

		sprintf(w_adcString, "ADC: %u", w_adcBuff);
		w_oledCopyBuffer(w_adcString, 1, w_FONT2);
		//memset(w_adcString, 0, 10);
		w_oledPageWrite();

		osSemaphoreRelease(uartDataKeyHandle);
		osSemaphoreRelease(adcDataKeyHandle);
		osDelay(10);
	}
  /* USER CODE END StartDisplayUpdate */
}

/* USER CODE BEGIN Header_StartReadCommPorts */
/**
 * @brief Function implementing the ReadCommPorts thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartReadCommPorts */
void StartReadCommPorts(void *argument)
{
  /* USER CODE BEGIN StartReadCommPorts */
	/* Infinite loop */
	for (;;) {
		osDelay(100);
	}
  /* USER CODE END StartReadCommPorts */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

