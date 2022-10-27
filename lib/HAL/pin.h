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
    PIN(GPIO_TypeDef *port, uint16_t pin) : m_port(port), m_pinNumber(pin)
    {
    }

    /**
     *  Default destructor.
     */
    ~PIN()
    {
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
    uint16_t getPin()
    {
        return m_pinNumber;
    }

private:
    /**
     *  GPIO Port.
     */
    GPIO_TypeDef *m_port;

    /**
     *  GPIO Pin Number.
     */
    uint16_t m_pinNumber;

    /**
     *  Default Constructor.
     *  Empty constructor is not allowed.
     */
    PIN();
};

#endif /* PIN_H_ */