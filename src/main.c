/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

#include "cmsis_os.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

void Error_Handler(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
osThreadId_t loopTaskHandle;
const osThreadAttr_t loopTask_attributes = {
  .name = "loopTask",
  .attr_bits = osThreadDetached,
  .cb_mem = NULL,
  .cb_size = 0,
  .stack_mem = NULL,
  .stack_size = 128 * 64,
  .priority = (osPriority_t) osPriorityNormal,
  .tz_module = 0,
  .reserved = 0
};
/* Definitions for BlinkBlue */
osThreadId_t BlinkBlueHandle;
const osThreadAttr_t BlinkBlue_attributes = {
  .name = "BlinkBlue",
  .attr_bits = osThreadDetached,
  .cb_mem = NULL,
  .cb_size = 0,
  .stack_mem = NULL,
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
  .tz_module = 0,
  .reserved = 0
};
/* Definitions for BlinkGreen */
osThreadId_t BlinkGreenHandle;
const osThreadAttr_t BlinkGreen_attributes = {
  .name = "BlinkGreen",
  .attr_bits = osThreadDetached,
  .cb_mem = NULL,
  .cb_size = 0,
  .stack_mem = NULL,
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
  .tz_module = 0,
  .reserved = 0
};
/* Definitions for timer_10ms */
osTimerId_t timer_10msHandle;
const osTimerAttr_t timer_10ms_attributes = {
  .name = "timer_10ms",
  .attr_bits = 0,
  .cb_mem = NULL,
  .cb_size = 0
};
/* Definitions for timer_100ms */
osTimerId_t timer_100msHandle;
const osTimerAttr_t timer_100ms_attributes = {
  .name = "timer_100ms"
};
/* Definitions for timer_1000ms */
osTimerId_t timer_1000msHandle;
const osTimerAttr_t timer_1000ms_attributes = {
  .name = "timer_1000ms"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LoopTask(void *argument);
void StartBlinkBlue(void *argument);
void StartBlinkGreen(void *argument);
void timer_callback_10ms(void *argument);
void timer_callback_100ms(void *argument);
void timer_callback_1000ms(void *argument);

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
  loopTaskHandle = osThreadNew(LoopTask, NULL, &loopTask_attributes);

  /* creation of BlinkBlue */
  BlinkBlueHandle = osThreadNew(StartBlinkBlue, NULL, &BlinkBlue_attributes);

  /* creation of BlinkGreen */
  BlinkGreenHandle = osThreadNew(StartBlinkGreen, NULL, &BlinkGreen_attributes);

  /* creation of timer_10ms */
  timer_10msHandle = osTimerNew(timer_callback_10ms, osTimerPeriodic, NULL, &timer_10ms_attributes);

  /* creation of timer_100ms */
  timer_100msHandle = osTimerNew(timer_callback_100ms, osTimerPeriodic, NULL, &timer_100ms_attributes);

  /* creation of timer_1000ms */
  timer_1000msHandle = osTimerNew(timer_callback_1000ms, osTimerPeriodic, NULL, &timer_1000ms_attributes);

  // osTimerStart(timer_10msHandle, 10);
  // osTimerStart(timer_100msHandle, 100);
  // osTimerStart(timer_1000msHandle, 1000);


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
void LoopTask(void *argument)
{
  /* USER CODE BEGIN LoopTask */
  /* Infinite loop */
  for(;;)
  {
    // HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2);
    osDelay(1);
  }
  /* USER CODE END LoopTask */
}

/* USER CODE BEGIN Header_StartBlinkBlue */
/**
* @brief Function implementing the BlinkBlue thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBlinkBlue */
void StartBlinkBlue(void *argument)
{
  /* USER CODE BEGIN StartBlinkBlue */
  /* Infinite loop */
  for(;;)
  {
	// HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2);
  osDelay(500);
  }
  /* USER CODE END StartBlinkBlue */
}

/* USER CODE BEGIN Header_StartBlinkGreen */
/**
* @brief Function implementing the BlinkGreen thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartBlinkGreen */
void StartBlinkGreen(void *argument)
{
  /* USER CODE BEGIN StartBlinkGreen */
  /* Infinite loop */
  for(;;)
  {
	  // HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);
	  osDelay(1000);
  }
  /* USER CODE END StartBlinkGreen */
}

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void timer_callback_10ms(void *argument)
{
  /* USER CODE BEGIN timer_callback_10ms */

  /* USER CODE END timer_callback_10ms */
}

/* timer_callback_100ms function */
void timer_callback_100ms(void *argument)
{
  /* USER CODE BEGIN timer_callback_100ms */
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2);
  /* USER CODE END timer_callback_100ms */
}

/* timer_callback_1000ms function */
void timer_callback_1000ms(void *argument)
{
  /* USER CODE BEGIN timer_callback_1000ms */
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);
  /* USER CODE END timer_callback_1000ms */
}

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
