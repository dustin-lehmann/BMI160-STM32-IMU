/*
 * firmware.h
 *
 *  Created on: Feb 19, 2024
 *      Author: Dustin Lehmann
 */

#ifndef FIRMWARE_H_
#define FIRMWARE_H_

#include "core.h"


#define IMU_UPDATE_TIME 10
#define COMM_TIME 20

extern SPI_HandleTypeDef* hspi3;
extern UART_HandleTypeDef* huart1;





#endif /* FIRMWARE_H_ */
