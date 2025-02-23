# IMU Experimentation Project with TouchGFX for Measurement Display

This STM32F4 project uses MPU-9150 (MPU-6050 is also applicable) for study and for
characterizing its response to different motion stimulus and cases.  It also 
uses TouchGFX with ILI9341 display driver on X-NUCLEO-GFX01M1 for easy reading
of measurement results.


# Current State

As of now, the boilerplate portion of the project code is working, including 
the basic display.  Display for now focuses on MPU9150 raw gyroscope 
measurement.


# To Dos

The measurement scope will expand later on, which will include raw accel readings,
and processed accel and gyro readings.  Additional screens in display with button
control for changing screens will also be added for these additional categories.
