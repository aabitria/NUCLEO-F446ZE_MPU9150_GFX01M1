/*
 * mpu9150.c
 *
 *  Created on: Feb 23, 2025
 *      Author: Lenovo310
 */


#include "mpu9150_regs.h"
#include "mpu9150.h"


static void mpu9150_reset (imu *i)
{
	uint8_t data = 0x80;
	mpu9150_write(i, MPU9150_PWR_MGMT_1, &data, sizeof(uint8_t));
}


static void mpu9150_config (imu *i)
{
	uint8_t param = 0;

	mpu9150_write(i, MPU9150_PWR_MGMT_1, &param, sizeof(uint8_t));

	param = 0x3;
	mpu9150_write(i, MPU9150_SMPLRT_DIV, &param, sizeof(uint8_t));

	param = 0x1;
	mpu9150_write(i, MPU9150_CONFIG, &param, sizeof(uint8_t));

	// Set up gyro and accel config
	param = (0x1 << 3);
	mpu9150_write(i, MPU9150_GYRO_CONFIG, &param, sizeof(uint8_t));
	mpu9150_write(i, MPU9150_ACCEL_CONFIG, &param, sizeof(uint8_t));
}


void mpu9150_read_gyro (imu *i, int16_t *dest)
{
	uint8_t raw_data[6];
	mpu9150_read(i, MPU9150_GYRO_XOUT_H, raw_data, sizeof(raw_data));
	dest[0] = (int16_t)((raw_data[0] << 8) | (raw_data[1]));
	dest[1] = (int16_t)((raw_data[2] << 8) | (raw_data[3]));
	dest[2] = (int16_t)((raw_data[4] << 8) | (raw_data[5]));
}


void mpu9150_init (imu *i)
{
	// reset
	mpu9150_reset(i);
    HAL_Delay(100);

	// configure
	mpu9150_config(i);
}
