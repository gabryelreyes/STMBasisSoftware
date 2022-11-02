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

#ifndef HAL_H_
#define HAL_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "pin.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/**
 *  Abstraction of the STM32 HAL
 */
class HAL
{
public:
    /**
     *  Default Constructor
     */
    HAL()
    {
    }

    /**
     *  Default Destructor
     */
    virtual ~HAL()
    {
    }

    /**
     *  Initialization of the HAL.
     */
    bool init(void)
    {
        bool isSuccess = true;

        /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
        if (HAL_OK != HAL_Init())
        {
            // Error initializing HAL
            isSuccess = false;
        }
        /* Configure the system clock */
        else if (false == configureSystemClock())
        {
            // Error initializing Clock
            isSuccess = false;
        }

        // Initialize GPIO
        if(isSuccess == true)
        {
            initializePorts();
            initializeUserGPIO();
        }

        return isSuccess;
    }

    /**
     *  Initialization of user GPIO Pins.
     */
    virtual void initializeUserGPIO(void) = 0;

private:
    /**
     *  Initialization of GPIO Ports.
     *  Sets all available pins to Analog Inputs.
     */
    void initializePorts(void)
    {
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
        GPIO_InitStruct.Pull = GPIO_NOPULL;

        // Configure Bank A
        // Do NOT reconfigure Pins 13, 14 and 15. These belong to JTAG.
        GPIO_InitStruct.Pin = GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6 |
                              GPIO_PIN_7 |
                              GPIO_PIN_8 |
                              GPIO_PIN_9 |
                              GPIO_PIN_10 |
                              GPIO_PIN_11 |
                              GPIO_PIN_12;
                            //   GPIO_PIN_13|
                            //   GPIO_PIN_14|
                            //   GPIO_PIN_15;

        __HAL_RCC_GPIOA_CLK_ENABLE();
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        // Configure Bank B
        // Do NOT reconfigure Pin 3. It belongs to JTAG.
        GPIO_InitStruct.Pin = GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              // GPIO_PIN_3|
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6 |
                              GPIO_PIN_7 |
                              GPIO_PIN_8 |
                              GPIO_PIN_9 |
                              GPIO_PIN_10 |
                              GPIO_PIN_11 |
                              GPIO_PIN_12 |
                              GPIO_PIN_13 |
                              GPIO_PIN_14 |
                              GPIO_PIN_15;

        __HAL_RCC_GPIOB_CLK_ENABLE();
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        // Configure Bank C
        GPIO_InitStruct.Pin = GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6 |
                              GPIO_PIN_7 |
                              GPIO_PIN_8 |
                              GPIO_PIN_9 |
                              GPIO_PIN_10 |
                              GPIO_PIN_11 |
                              GPIO_PIN_12 |
                              GPIO_PIN_13 |
                              GPIO_PIN_14 |
                              GPIO_PIN_15;

        __HAL_RCC_GPIOC_CLK_ENABLE();
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        // Configure Bank D
        GPIO_InitStruct.Pin = GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6 |
                              GPIO_PIN_7 |
                              GPIO_PIN_8 |
                              GPIO_PIN_9 |
                              GPIO_PIN_10 |
                              GPIO_PIN_11 |
                              GPIO_PIN_12 |
                              GPIO_PIN_13 |
                              GPIO_PIN_14 |
                              GPIO_PIN_15;

        __HAL_RCC_GPIOD_CLK_ENABLE();
        HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

        // Configure Bank E
        GPIO_InitStruct.Pin = GPIO_PIN_0 |
                              GPIO_PIN_1 |
                              GPIO_PIN_2 |
                              GPIO_PIN_3 |
                              GPIO_PIN_4 |
                              GPIO_PIN_5 |
                              GPIO_PIN_6 |
                              GPIO_PIN_7 |
                              GPIO_PIN_8 |
                              GPIO_PIN_9 |
                              GPIO_PIN_10 |
                              GPIO_PIN_11 |
                              GPIO_PIN_12 |
                              GPIO_PIN_13 |
                              GPIO_PIN_14 |
                              GPIO_PIN_15;

        __HAL_RCC_GPIOE_CLK_ENABLE();
        HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

        // Configure Bank H
        // Port H only has Pins 0 and 1
        GPIO_InitStruct.Pin = GPIO_PIN_0 |
                              GPIO_PIN_1;
                            //   GPIO_PIN_2|
                            //   GPIO_PIN_3|
                            //   GPIO_PIN_4|
                            //   GPIO_PIN_5|
                            //   GPIO_PIN_6|
                            //   GPIO_PIN_7|
                            //   GPIO_PIN_8|
                            //   GPIO_PIN_9|
                            //   GPIO_PIN_10|
                            //   GPIO_PIN_11|
                            //   GPIO_PIN_12|
                            //   GPIO_PIN_13|
                            //   GPIO_PIN_14|
                            //   GPIO_PIN_15;

        __HAL_RCC_GPIOH_CLK_ENABLE();
        HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
    }

    
    /**
     *  System Clock Configuration
     *  @return If succesfully configured, returns true. Otherwise, false.
     */
    bool configureSystemClock(void)
    {
        bool isSuccess = true;

        RCC_OscInitTypeDef RCC_OscInitStruct = {0};
        RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

        /**
         *  Configure the main internal regulator output voltage
         */
        __HAL_RCC_PWR_CLK_ENABLE();
        __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

        /** 
         *  Initializes the RCC Oscillators according to the specified parameters
         *  in the RCC_OscInitTypeDef structure.
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
};

#endif /* HAL_H_ */