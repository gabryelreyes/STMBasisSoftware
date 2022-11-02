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
 *  @brief  Class for definition of a microcontroller GPIO
 *  @author Gabryel Reyes <gabryelrdiaz@gmail.com>
 */

#ifndef PIN_H_
#define PIN_H_

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
 *  Class definition of a Microcontroller Pin.
 */
class PIN
{
public:
    /**
     *  Pin Constructor.
     *  @param[in] port GPIO Port.
     *  @param[in] pin GPIO Pin Number.
     */
    PIN(GPIO_TypeDef *port, 
        uint32_t pin, 
        uint32_t mode = GPIO_MODE_OUTPUT_PP, 
        uint32_t pull = GPIO_NOPULL, 
        uint32_t speed = GPIO_SPEED_FREQ_LOW) : m_port(port), 
                                                m_pinNumber(pin), 
                                                m_pinMode(mode), 
                                                m_pinPull(pull), 
                                                m_pinSpeed(speed)
    {
    }

    /**
     *  Default destructor.
     */
    ~PIN()
    {
    }

    /**
     *  Pin initialization using values provided on instancing.
     */
    void init(void)
    {
        GPIO_InitTypeDef GPIO_InitStruct = {0};
        GPIO_InitStruct.Pin = m_pinNumber;
        GPIO_InitStruct.Mode = m_pinMode;
        GPIO_InitStruct.Pull = m_pinPull;
        GPIO_InitStruct.Speed = m_pinSpeed;

        HAL_GPIO_DeInit(m_port, m_pinNumber);
        HAL_GPIO_WritePin(m_port, m_pinNumber, GPIO_PIN_RESET);
        HAL_GPIO_Init(m_port, &GPIO_InitStruct);
    }

    /**
     *  Get the GPIO Port of the Pin.
     *  @return GPIO Port.
     */
    GPIO_TypeDef *getPort()
    {
        return m_port;
    }

    /**
     *  Get the GPIO Pin Number.
     *  @return GPIO Pin Number.
     */
    uint32_t getPin()
    {
        return m_pinNumber;
    }

    /**
     *  Get the GPIO Pin Mode.
     *  @return GPIO Pin Mode.
     */
    uint32_t getMode()
    {
        return m_pinMode;
    }

    /**
     *  Get the GPIO Pin Pull.
     *  @return GPIO Pin Pull.
     */
    uint32_t getPull()
    {
        return m_pinPull;
    }

    /**
     *  Get the GPIO Pin Speed.
     *  @return GPIO Pin Speed.
     */
    uint32_t getSpeed()
    {
        return m_pinSpeed;
    }

private:
    /**
     *  GPIO Port.
     */
    GPIO_TypeDef *m_port;

    /**
     *  GPIO Pin Number.
     */
    uint32_t m_pinNumber;

    /**
     *  GPIO Pin Mode.
     */
    uint32_t m_pinMode;

    /**
     *  GPIO Pin Pull.
     */
    uint32_t m_pinPull;

    /**
     *  GPIO Pin Speed.
     */
    uint32_t m_pinSpeed;

    /**
     *  Default Constructor.
     *  Empty constructor is not allowed.
     */
    PIN();
};

#endif /* PIN_H_ */