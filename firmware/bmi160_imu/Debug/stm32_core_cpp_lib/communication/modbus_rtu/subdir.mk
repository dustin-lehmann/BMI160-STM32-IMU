################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.cpp 

OBJS += \
./stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.o 

CPP_DEPS += \
./stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.d 


# Each subdirectory must supply rules for building sources it contributes
stm32_core_cpp_lib/communication/modbus_rtu/%.o stm32_core_cpp_lib/communication/modbus_rtu/%.su stm32_core_cpp_lib/communication/modbus_rtu/%.cyclo: ../stm32_core_cpp_lib/communication/modbus_rtu/%.cpp stm32_core_cpp_lib/communication/modbus_rtu/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"C:/work_dir/projects/testbed/software/robots/software_board/_workspace/bmi160_imu/firmware" -I"C:/work_dir/projects/testbed/software/robots/software_board/_workspace/bmi160_imu/stm32_core_cpp_lib" -I"C:/work_dir/projects/testbed/software/robots/software_board/_workspace/bmi160_imu/stm32_core_cpp_lib/utils" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/work_dir/projects/testbed/software/robots/software_board/_workspace/bmi160_imu/stm32_core_cpp_lib/communication/modbus_rtu" -I"C:/work_dir/projects/testbed/software/robots/software_board/_workspace/bmi160_imu/stm32_core_cpp_lib/hardware/UART" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-stm32_core_cpp_lib-2f-communication-2f-modbus_rtu

clean-stm32_core_cpp_lib-2f-communication-2f-modbus_rtu:
	-$(RM) ./stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.cyclo ./stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.d ./stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.o ./stm32_core_cpp_lib/communication/modbus_rtu/modbus_rtu.su

.PHONY: clean-stm32_core_cpp_lib-2f-communication-2f-modbus_rtu

