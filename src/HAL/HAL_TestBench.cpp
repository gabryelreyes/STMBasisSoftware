/* MIT License

Copyright (c) 2022 Gabryel Reyes <gabryelrdiaz@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

/*******************************************************************************
    DESCRIPTION
*******************************************************************************/
/**
 *  @brief  Abstraction of the auto-generated HAL
 *  @author Gabryel Reyes <gabryelrdiaz@gmail.com>
 */

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "HAL_TestBench.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/

/**
 *  @brief System Clock Configuration
 *  @retval None
 */
bool SystemClock_Config(void);

/** 
 *  Configure GPIO Ports.
 *  Sets all Pins to Analog Input.
 */
void initGpioPorts(void);

/**
 *  Configure the GPIO Pins for the current Board.
 */
void initBoardGpio(void);

/******************************************************************************
 * Local Variables
 *****************************************************************************/

/******************************************************************************
 * Public Methods
 *****************************************************************************/

bool HAL_TestBench::init()
{
    bool isSuccess = true;

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    if (HAL_OK != HAL_Init())
    {
        // Error initializing HAL
        isSuccess = false;
    }
    /* Configure the system clock */
    else if(false == SystemClock_Config())
    {
        // Error initializing Clock
        isSuccess = false;
    }

    // Initialize GPIO Banks. Sets all Pins to Analog Input.
    initGpioPorts();

    // Initialize GPIO for the current Board.
    initBoardGpio();

    return isSuccess;
}

/******************************************************************************
 * Private Methods
 *****************************************************************************/

/******************************************************************************
 * Local Functions
 *****************************************************************************/

bool SystemClock_Config(void)
{
    bool isSuccess = true;

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
        isSuccess = false;
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
        isSuccess = false;
    }

    return isSuccess;
}

void initGpioPorts ()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;

    // Configure Bank A
    // Do NOT reconfigure Pins 13, 14 and 15. These belong to JTAG.
    GPIO_InitStruct.Pin =   GPIO_PIN_0|
                            GPIO_PIN_1|
                            GPIO_PIN_2|
                            GPIO_PIN_3|
                            GPIO_PIN_4|
                            GPIO_PIN_5|
                            GPIO_PIN_6|
                            GPIO_PIN_7|
                            GPIO_PIN_8|
                            GPIO_PIN_9|
                            GPIO_PIN_10|
                            GPIO_PIN_11|
                            GPIO_PIN_12;
                            // GPIO_PIN_13|
                            // GPIO_PIN_14|
                            // GPIO_PIN_15;
    
    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


    // Configure Bank B
    // Do NOT reconfigure Pin 3. It belongs to JTAG.
    GPIO_InitStruct.Pin =   GPIO_PIN_0|
                            GPIO_PIN_1|
                            GPIO_PIN_2|
                            // GPIO_PIN_3|
                            GPIO_PIN_4|
                            GPIO_PIN_5|
                            GPIO_PIN_6|
                            GPIO_PIN_7|
                            GPIO_PIN_8|
                            GPIO_PIN_9|
                            GPIO_PIN_10|
                            GPIO_PIN_11|
                            GPIO_PIN_12|
                            GPIO_PIN_13|
                            GPIO_PIN_14|
                            GPIO_PIN_15;
    
    __HAL_RCC_GPIOB_CLK_ENABLE();
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    // Configure Bank C
    GPIO_InitStruct.Pin =   GPIO_PIN_0|
                            GPIO_PIN_1|
                            GPIO_PIN_2|
                            GPIO_PIN_3|
                            GPIO_PIN_4|
                            GPIO_PIN_5|
                            GPIO_PIN_6|
                            GPIO_PIN_7|
                            GPIO_PIN_8|
                            GPIO_PIN_9|
                            GPIO_PIN_10|
                            GPIO_PIN_11|
                            GPIO_PIN_12|
                            GPIO_PIN_13|
                            GPIO_PIN_14|
                            GPIO_PIN_15;

    __HAL_RCC_GPIOC_CLK_ENABLE();
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    // Configure Bank D
    GPIO_InitStruct.Pin =   GPIO_PIN_0|
                            GPIO_PIN_1|
                            GPIO_PIN_2|
                            GPIO_PIN_3|
                            GPIO_PIN_4|
                            GPIO_PIN_5|
                            GPIO_PIN_6|
                            GPIO_PIN_7|
                            GPIO_PIN_8|
                            GPIO_PIN_9|
                            GPIO_PIN_10|
                            GPIO_PIN_11|
                            GPIO_PIN_12|
                            GPIO_PIN_13|
                            GPIO_PIN_14|
                            GPIO_PIN_15;

    __HAL_RCC_GPIOD_CLK_ENABLE();
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    // Configure Bank E
    GPIO_InitStruct.Pin =   GPIO_PIN_0|
                            GPIO_PIN_1|
                            GPIO_PIN_2|
                            GPIO_PIN_3|
                            GPIO_PIN_4|
                            GPIO_PIN_5|
                            GPIO_PIN_6|
                            GPIO_PIN_7|
                            GPIO_PIN_8|
                            GPIO_PIN_9|
                            GPIO_PIN_10|
                            GPIO_PIN_11|
                            GPIO_PIN_12|
                            GPIO_PIN_13|
                            GPIO_PIN_14|
                            GPIO_PIN_15;

    __HAL_RCC_GPIOE_CLK_ENABLE();
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    // Configure Bank H
    // Port H only has Pins 0 and 1
    GPIO_InitStruct.Pin =   GPIO_PIN_0|
                            GPIO_PIN_1;
                            // GPIO_PIN_2|
                            // GPIO_PIN_3|
                            // GPIO_PIN_4|
                            // GPIO_PIN_5|
                            // GPIO_PIN_6|
                            // GPIO_PIN_7|
                            // GPIO_PIN_8|
                            // GPIO_PIN_9|
                            // GPIO_PIN_10|
                            // GPIO_PIN_11|
                            // GPIO_PIN_12|
                            // GPIO_PIN_13|
                            // GPIO_PIN_14|
                            // GPIO_PIN_15;

    __HAL_RCC_GPIOH_CLK_ENABLE();
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
}

void initBoardGpio(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure BMS_OK */
    GPIO_InitStruct.Pin = BMS_OK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_DeInit(BMS_OK_GPIO_Port, BMS_OK_Pin);
    HAL_GPIO_WritePin(BMS_OK_GPIO_Port, BMS_OK_Pin, GPIO_PIN_RESET);
    HAL_GPIO_Init(BMS_OK_GPIO_Port, &GPIO_InitStruct);


    /*Configure SPI_CS_1 */
    GPIO_InitStruct.Pin = NSS_1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    HAL_GPIO_DeInit(NSS_1_GPIO_Port, NSS_1_Pin);
    HAL_GPIO_WritePin(NSS_1_GPIO_Port, NSS_1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_Init(NSS_1_GPIO_Port, &GPIO_InitStruct);

    /*Configure SPI_CS_2 */
    GPIO_InitStruct.Pin = NSS_2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

    HAL_GPIO_DeInit(NSS_2_GPIO_Port, NSS_2_Pin);
    HAL_GPIO_WritePin(NSS_2_GPIO_Port, NSS_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_Init(NSS_2_GPIO_Port, &GPIO_InitStruct);

    /*Configure Red LED */
    GPIO_InitStruct.Pin = LED_Red_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_DeInit(LED_Red_GPIO_Port, LED_Red_Pin);
    HAL_GPIO_WritePin(LED_Red_GPIO_Port, LED_Red_Pin, GPIO_PIN_RESET);
    HAL_GPIO_Init(LED_Red_GPIO_Port, &GPIO_InitStruct);

    /*Configure Blue LED */
    GPIO_InitStruct.Pin = LED_Blue_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_DeInit(LED_Blue_GPIO_Port, LED_Blue_Pin);
    HAL_GPIO_WritePin(LED_Blue_GPIO_Port, LED_Blue_Pin, GPIO_PIN_RESET);
    HAL_GPIO_Init(LED_Blue_GPIO_Port, &GPIO_InitStruct);

    /*Configure Green LED */
    GPIO_InitStruct.Pin = LED_Green_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_DeInit(LED_Green_GPIO_Port, LED_Green_Pin);
    HAL_GPIO_WritePin(LED_Green_GPIO_Port, LED_Green_Pin, GPIO_PIN_RESET);
    HAL_GPIO_Init(LED_Green_GPIO_Port, &GPIO_InitStruct);
}

/******************************************************************************
 * External Functions
 *****************************************************************************/

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