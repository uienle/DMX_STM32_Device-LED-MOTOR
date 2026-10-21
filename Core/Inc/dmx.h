/*
 * DMX.h
 *
 *  Created on: Nov 6, 2025
 *      Author: UYEN
 */

#ifndef INC_DMX_H_
#define INC_DMX_H_


#include "stm32f1xx_hal.h"

#define DMX_CHANNELS   513
extern uint8_t dmxData[DMX_CHANNELS];
extern volatile uint8_t dmxNewFrame;

void DMX_Init(UART_HandleTypeDef *huart);
void DMX_Process(void);


#endif /* INC_DMX_H_ */
