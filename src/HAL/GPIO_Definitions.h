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
 *  @brief  Definitions of GPIO Pins for Discovery Development Board
 *  @author Gabryel Reyes <gabryelrdiaz@gmail.com>
 */

#ifndef GPIO_DEFINITIONS_H_
#define GPIO_DEFINITIONS_H_

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
#ifdef Discovery_DevBoard
/** SPI 1 CS */
static DigitalOut NSS_1(GPIOA, 
                        GPIO_PIN_4,
                        GPIO_NOPULL, 
                        GPIO_SPEED_FREQ_VERY_HIGH);

/** SPI 2 CS */
static DigitalOut NSS_2(GPIOB, 
                        GPIO_PIN_9,
                        GPIO_NOPULL, 
                        GPIO_SPEED_FREQ_VERY_HIGH);

static DigitalOut LED_BLUE(GPIOD, GPIO_PIN_15);

static DigitalOut LED_RED(GPIOD, GPIO_PIN_14);

static DigitalOut LED_ORANGE(GPIOD, GPIO_PIN_13);

static DigitalOut LED_GREEN(GPIOD, GPIO_PIN_12);

static DigitalIn userButton(GPIOA, GPIO_PIN_0);

/** A list of all used i/o pins, used for initialization. */
static PIN* pinList[] =
{
    &NSS_1,
    &NSS_2,
    &LED_RED,
    &LED_GREEN,
    &LED_BLUE,
    &LED_ORANGE,
    &userButton
};

#endif /* Discovery_DevBoard */

#ifdef BMS
/** SPI 1 CS */
static DigitalOut NSS_1(GPIOA, 
                        GPIO_PIN_4,
                        GPIO_NOPULL, 
                        GPIO_SPEED_FREQ_VERY_HIGH);

/** SPI 2 CS */
static DigitalOut NSS_2(GPIOB, 
                        GPIO_PIN_9,
                        GPIO_NOPULL, 
                        GPIO_SPEED_FREQ_VERY_HIGH);

/** Red LED */
// static DigitalOut LED_RED(GPIOE, GPIO_PIN_0); // BMS PCB
static DigitalOut LED_RED(GPIOD, GPIO_PIN_15); // DISCO DevBoard

/** Green LED */
// static DigitalOut LED_GREEN(GPIOE, GPIO_PIN_1); // BMS PCB
static DigitalOut LED_GREEN(GPIOD, GPIO_PIN_14); // DISCO DevBoard

/** Blue LED */
// static DigitalOut LED_BLUE(GPIOE, GPIO_PIN_2); // BMS PCB
static DigitalOut LED_BLUE(GPIOD, GPIO_PIN_13); // DISCO DevBoard

/** BMS OK */
// static DigitalOut BMS_OK(GPIOE, GPIO_PIN_15); // BMS PCB
static DigitalOut BMS_OK(GPIOD, GPIO_PIN_12); // DISCO DevBoard

static DigitalIn TestButton(GPIOA, GPIO_PIN_0);

/** A list of all used i/o pins, used for initialization. */
static PIN* pinList[] =
{
    &NSS_1,
    &NSS_2,
    &LED_RED,
    &LED_GREEN,
    &LED_BLUE,
    &BMS_OK,
    &TestButton
};

#endif /* BMS */

#endif /* GPIO_DEFINITIONS_H_ */
