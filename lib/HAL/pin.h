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
     *  Constructor of a Pin.
     *  @param[in] port GPIO Port (A..F)
     *  @param[in] pin GPIO Pin Number
     *  @param[in] pull Pin Pull direction
     *  @param[in] speed Pin Speed
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
    void init(void) const
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
    GPIO_TypeDef *getPort() const
    {
        return m_port;
    }

    /**
     *  Get the GPIO Pin Number.
     *  @return GPIO Pin Number.
     */
    uint32_t getPin() const
    {
        return m_pinNumber;
    }

    /**
     *  Get the GPIO Pin Mode.
     *  @return GPIO Pin Mode.
     */
    uint32_t getMode() const
    {
        return m_pinMode;
    }

    /**
     *  Get the GPIO Pin Pull.
     *  @return GPIO Pin Pull.
     */
    uint32_t getPull() const
    {
        return m_pinPull;
    }

    /**
     *  Get the GPIO Pin Speed.
     *  @return GPIO Pin Speed.
     */
    uint32_t getSpeed() const
    {
        return m_pinSpeed;
    }

protected:
    /**
     *  GPIO Port.
     */
    GPIO_TypeDef *m_port;

    /**
     *  GPIO Pin Number.
     */
    const uint32_t m_pinNumber;

    /**
     *  GPIO Pin Mode.
     */
    const uint32_t m_pinMode;

    /**
     *  GPIO Pin Pull.
     */
    const uint32_t m_pinPull;

    /**
     *  GPIO Pin Speed.
     */
    const uint32_t m_pinSpeed;

private:
    /**
     *  Default Constructor.
     *  Empty constructor is not allowed.
     */
    PIN();

    /* An instance shall not be copied. */
    PIN(const PIN &Pin);
    PIN &operator=(const PIN &Pin);
};

/**
 *  Digital Output Pin
 */
class DigitalOut : public PIN
{
public:
    /**
     *  Constructor of Digital Output Pin.
     *  @param[in] port GPIO Port (A..F)
     *  @param[in] pin GPIO Pin Number
     *  @param[in] pull Pin Pull direction
     *  @param[in] speed Pin Speed
     */
    DigitalOut(GPIO_TypeDef *port, uint32_t pin, uint32_t pull = GPIO_NOPULL, uint32_t speed = GPIO_SPEED_FREQ_LOW) : 
               PIN(port, pin, GPIO_MODE_OUTPUT_PP, pull, speed)
    {
    }

    /**
     *  Default destructor.
     */
    ~DigitalOut()
    {
    }

    /**
     *  Set the Digital Output
     */
    void set(void) const
    {
        HAL_GPIO_WritePin(m_port, m_pinNumber, GPIO_PIN_SET);
    }

    /**
     *  Reset the Digital Output
     */
    void reset(void) const
    {
        HAL_GPIO_WritePin(m_port, m_pinNumber, GPIO_PIN_RESET);
    }

    /**
     *  Toggle the Digital Output
     */
    void toggle(void) const
    {
        HAL_GPIO_TogglePin(m_port, m_pinNumber);
    }

private:
    /* An instance shall not be copied. */
    DigitalOut(const DigitalOut &Pin);
    DigitalOut &operator=(const DigitalOut &Pin);
};


/**
 *  Digital Input Pin
 */
class DigitalIn : public PIN
{
public:
    /**
     *  Constructor of Digital Pin.
     *  @param[in] port GPIO Port (A..F)
     *  @param[in] pin GPIO Pin Number
     *  @param[in] pull Pin Pull direction
     */
    DigitalIn(GPIO_TypeDef *port, uint32_t pin, uint32_t pull = GPIO_NOPULL) : 
              PIN(port, pin, GPIO_MODE_INPUT, pull, GPIO_SPEED_FREQ_LOW)
    {
    }

    ~DigitalIn()
    {
    }

    bool read()
    {
        return (bool)(HAL_GPIO_ReadPin(m_port, m_pinNumber));
    }

private:
};

#endif /* PIN_H_ */