/*
 * mpu9150.h
 *
 *  Created on: Feb 23, 2025
 *      Author: Lenovo310
 */

#ifndef INC_MPU9150_H_
#define INC_MPU9150_H_

#include "main.h"
#include "mpu9150_regs.h"
#include "i2c.h"

typedef struct imu_
{
	I2C_HandleTypeDef *hi2c;
	uint16_t dev_addr;

	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;

	int16_t accel_x;
	int16_t accel_y;
	int16_t accel_z;
} imu;

static inline void mpu9150_write(imu *i, uint16_t reg_addr, uint8_t *buf, uint16_t buf_len)
{
	HAL_I2C_Mem_Write(i->hi2c, (i->dev_addr) << 1, reg_addr, 1, buf, buf_len, 2);
}

static inline void mpu9150_read(imu *i, uint16_t reg_addr, uint8_t *buf, uint16_t buf_len)
{
	HAL_I2C_Mem_Read(i->hi2c, (i->dev_addr) << 1, reg_addr, 1, buf, buf_len, 2);
}

void mpu9150_read_gyro (imu *i, int16_t *dest);
void mpu9150_read_accel (imu *i, int16_t *dest);
void mpu9150_init (imu *i);


#endif /* INC_MPU9150_H_ */
