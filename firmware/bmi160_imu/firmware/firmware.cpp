/*
 * firmware.cpp
 *
 *  Created on: Feb 19, 2024
 *      Author: Dustin Lehmann
 */

#include "main.h"
#include "firmware_c.h"
#include "firmware.h"

#include "elapsedMillis.h"

bmi160_config_t imu_config = { .hspi = hspi3, .CS_GPIOx = GPIOB, .CS_GPIO_Pin =
GPIO_PIN_6,
};

elapsedMillis blinkTimer;

uint32_t comm_tick = 0;

BMI160 imu;

void imu_task(void *attributes);
void communication_task(void *attributes);

const osThreadAttr_t imu_task_attributes = { .name = "imu_task", .stack_size =
		2560 * 4, .priority = (osPriority_t) osPriorityNormal, };

const osThreadAttr_t comm_task_attributes = { .name = "comm_task", .stack_size =
		2560 * 4, .priority = (osPriority_t) osPriorityNormal, };

void firmware() {

	imu.init(imu_config);

	osThreadNew(imu_task, NULL, &imu_task_attributes);
	osThreadNew(imu_task, NULL, &comm_task_attributes);

}

void imu_task(void *attributes) {

	while (true) {
		imu.update();
		osDelay(IMU_UPDATE_TIME);
	}
}

void communication_task(void *attributes) {
	float imu_gyr_x, imu_gyr_y, imu_gyr_z, imu_acc_x, imu_acc_y, imu_acc_z = 0;
	uint8_t data[28] = {0};
	uint8_t data_encoded[100] = {0};

	while (true) {
		comm_tick++;

		// Blink LED
		if (blinkTimer >= 250) {
			blinkTimer = 0;
			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		}

		// Get the IMU Data
		imu_gyr_x = imu.gyr.x;
		imu_gyr_y = imu.gyr.y;
		imu_gyr_z = imu.gyr.z;

		imu_acc_x = imu.acc.x;
		imu_acc_y = imu.acc.y;
		imu_acc_z = imu.acc.z;

		uint32_to_bytearray(comm_tick, &data[0]);
		float_to_bytearray(imu_gyr_x, &data[4]);
		float_to_bytearray(imu_gyr_y, &data[8]);
		float_to_bytearray(imu_gyr_z, &data[12]);
		float_to_bytearray(imu_acc_x, &data[16]);
		float_to_bytearray(imu_acc_y, &data[20]);
		float_to_bytearray(imu_acc_z, &data[24]);

		uint8_t encode_length = cobsEncode(data, 28, data_encoded);
		data_encoded[encode_length] = 0x00;

		HAL_UART_Transmit(huart1, data_encoded, encode_length+1, 10);


	}

}
