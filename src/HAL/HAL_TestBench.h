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
 *  @brief  Implementation of HAL for the Testbench
 *  @author Gabryel Reyes <gabryelrdiaz@gmail.com>
 */

#ifndef HAL_TESTBENCH_H_
#define HAL_TESTBENCH_H_

/******************************************************************************
 * Includes
 *****************************************************************************/

#include "hal.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

class HAL_TestBench : public HAL
{   
public:
    /**
     *  Enum of available GPIO.
     */
    enum GPIO
    {
        BMS_OK = 0,
        SPI_CS_1,
        SPI_CS_2,
        LED_RED,
        LED_BLUE,
        LED_GREEN
    };

    HAL_TestBench() : HAL()
    {
    }

    ~HAL_TestBench()
    {
    }

    /**
     *  Initialization of the HAL.
     */
    virtual bool init();

    /**
     *  Set a GPIO
     *  @param gpio GPIO Number.
     */
    virtual void setGPIO(uint8_t gpio);

    /**
     *  Reset a GPIO
     *  @param gpio GPIO Number.
     */
    virtual void resetGPIO(uint8_t gpio);

    /**
     *  Toggle a GPIO
     *  @param gpio GPIO Number.
     */
    virtual void toggleGPIO(uint8_t gpio);

private:
    /**
     *  Get the Port and Pin Number of an specific GPIO.
     *  @param[in] gpio GPIO.
     *  @param[out] pinPort GPIO Port.
     *  @param[out] pinNumber GPIO Pin.
     *  @return If successfull, returns true. Otherwise, false.
     */
    bool getGPIO(uint8_t gpio, GPIO_TypeDef **pinPort, uint16_t &pinNumber);

    /**
     *  Write the Digital State of a GPIO.
     */
    void digitalWrite(uint8_t gpio, GPIO_PinState set);

};

#endif /* HAL_TESTBENCH_H_ */