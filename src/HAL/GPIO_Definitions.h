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
 *  @brief  Definitions of GPIO Pins for Testbench
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

/** SPI 1 CS */
static PIN NSS_1(GPIOA, 
                 GPIO_PIN_4, 
                 GPIO_MODE_OUTPUT_PP, 
                 GPIO_NOPULL, 
                 GPIO_SPEED_FREQ_VERY_HIGH);

/** SPI 2 CS */
static PIN NSS_2(GPIOB, 
                 GPIO_PIN_9,
                 GPIO_MODE_OUTPUT_PP, 
                 GPIO_NOPULL, 
                 GPIO_SPEED_FREQ_VERY_HIGH);

/** Red LED */
static PIN LED_RED(GPIOE, GPIO_PIN_0);

/** Green LED */
static PIN LED_GREEN(GPIOE, GPIO_PIN_1);

/** Blue LED */
static PIN LED_BLUE(GPIOE, GPIO_PIN_2);

/** BMS OK */
static PIN BMS_OK(GPIOE, GPIO_PIN_15);

#endif /* GPIO_DEFINITIONS_H_ */