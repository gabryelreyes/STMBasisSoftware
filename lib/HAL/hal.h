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
#include "stm32f4xx_hal.h"

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
    virtual bool init() = 0;

    /**
     *  Delay in milliseconds.
     */
    virtual void delay(uint32_t delay) = 0;

    /**
     *  Set a GPIO
     *  @param gpio GPIO Number.
     */
    virtual void setGPIO(uint8_t gpio) = 0;

    /**
     *  Reset a GPIO
     *  @param gpio GPIO Number.
     */
    virtual void resetGPIO(uint8_t gpio) = 0;

    /**
     *  Toggle a GPIO
     *  @param gpio GPIO Number.
     */
    virtual void toggleGPIO(uint8_t gpio) = 0;

};

#endif /* HAL_H_ */