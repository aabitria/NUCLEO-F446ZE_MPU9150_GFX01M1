#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "mpu9150.h"

extern "C" {
    extern imu mpu9150_imu;
}


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	++cnt;

	/* this tick is called 60/s, but we will update display only 3x/sec */
	if (cnt == 10)
	{
		modelListener->get_raw_gyro((short *)&mpu9150_imu.gyro_x_raw);
		modelListener->get_raw_accel((short *)&mpu9150_imu.accel_x_raw);
		modelListener->get_sensor_val(&mpu9150_imu.gyro_x);
		cnt = 0;
	}
}
