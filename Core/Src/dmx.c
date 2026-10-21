/*
 * dmx.c
 *
 *  Created on: Nov 6, 2025
 *      Author: UYEN
 */

#include "dmx.h"
#include "main.h"

uint8_t dmxData[DMX_CHANNELS];
volatile uint8_t dmxNewFrame = 0;
static UART_HandleTypeDef *dmxUart;

extern TIM_HandleTypeDef htim2;

void DMX_Init(UART_HandleTypeDef *huart)
{
    dmxUart = huart;
    HAL_UART_Receive_DMA(dmxUart, dmxData, DMX_CHANNELS);
    __HAL_UART_ENABLE_IT(dmxUart, UART_IT_ERR); // Cho phép FE interrupt
}

void DMX_Process(void)
{
    if (dmxNewFrame)
    {
        dmxNewFrame = 0;

        if (dmxData[0] == 0x00) // Start code hợp lệ
        {
//            uint8_t m = dmxData[16];
//
            uint8_t r = dmxData[7];
            uint8_t g = dmxData[8];
            uint8_t b = dmxData[9];

//            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, m);
//
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, r);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, g);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, b);
        }
        HAL_UART_Receive_DMA(dmxUart, dmxData, DMX_CHANNELS);
    }
}

