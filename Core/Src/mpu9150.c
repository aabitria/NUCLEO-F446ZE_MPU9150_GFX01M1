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
	param = MPU9150_GC_FSEL1;
	mpu9150_write(i, MPU9150_GYRO_CONFIG, &param, sizeof(uint8_t));
	switch (param)
	{
	case MPU9150_GC_FSEL0:
		i->gyro_sf = 131.0f;
		break;

	case MPU9150_GC_FSEL1:
		i->gyro_sf = 65.5f;
		break;

	case MPU9150_GC_FSEL2:
		i->gyro_sf = 32.8f;
		break;

	case MPU9150_GC_FSEL3:
		i->gyro_sf = 16.4f;
		break;

	default:
		i->gyro_sf = 1.0f;
	}

	param = MPU9150_AC_AFSEL1;
	mpu9150_write(i, MPU9150_ACCEL_CONFIG, &param, sizeof(uint8_t));
	switch (param)
	{
	case MPU9150_AC_AFSEL0:
		i->accel_sf = 16384.0f;
		break;

	case MPU9150_AC_AFSEL1:
		i->accel_sf = 8192.0f;
		break;

	case MPU9150_AC_AFSEL2:
		i->accel_sf = 4096.0f;
		break;

	case MPU9150_AC_AFSEL3:
		i->accel_sf = 2048.0f;
		break;

	default:
		i->accel_sf = 1.0f;
	}
}


void mpu9150_read_gyro (imu *i, int16_t *dest)
{
	uint8_t raw_data[6];
	mpu9150_read(i, MPU9150_GYRO_XOUT_H, raw_data, sizeof(raw_data));
	dest[0] = (int16_t)((raw_data[0] << 8) | (raw_data[1]));
	dest[1] = (int16_t)((raw_data[2] << 8) | (raw_data[3]));
	dest[2] = (int16_t)((raw_data[4] << 8) | (raw_data[5]));
}


void mpu9150_read_accel (imu *i, int16_t *dest)
{
	uint8_t raw_data[6];
	mpu9150_read(i, MPU9150_ACCEL_XOUT_H, raw_data, sizeof(raw_data));
	dest[0] = (int16_t)((raw_data[0] << 8) | (raw_data[1]));
	dest[1] = (int16_t)((raw_data[2] << 8) | (raw_data[3]));
	dest[2] = (int16_t)((raw_data[4] << 8) | (raw_data[5]));
}


void mpu9150_convert_from_raw (imu *i)
{
	i->gyro_x = (float)i->gyro_x_raw / i->gyro_sf;
	i->gyro_y = (float)i->gyro_y_raw / i->gyro_sf;
	i->gyro_z = (float)i->gyro_z_raw / i->gyro_sf;

	i->accel_x = (float)i->accel_x_raw / i->accel_sf;
	i->accel_y = (float)i->accel_y_raw / i->accel_sf;
	i->accel_z = (float)i->accel_z_raw / i->accel_sf;
}


void mpu9150_init (imu *i)
{
	// reset
	mpu9150_reset(i);
    HAL_Delay(100);

	// configure
	mpu9150_config(i);
}
