/*
 * core_hardware_led.hpp
 *
 *  Created on: Jul 6, 2022
 *      Author: Dustin Lehmann
 */

#ifndef CORE_HARDWARE_LED_CORE_HARDWARE_LED_H_
#define CORE_HARDWARE_LED_CORE_HARDWARE_LED_H_

#include "core_includes.h"

class core_hardware_LED {
public:
	core_hardware_LED(GPIO_TypeDef* GPIOx, uint16_t PINx);
	GPIO_TypeDef* GPIOx;
	uint16_t PINx;

	void on();
	void off();
	void toggle();

};



#endif /* CORE_HARDWARE_LED_CORE_HARDWARE_LED_H_ */
