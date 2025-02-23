#include <gui/screen1_screen/Screen1View.hpp>
#include <cstring>
#include <cstdio>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::display_raw_gyro(short *gyro)
{
	char str[6] = {0};

	snprintf(str, sizeof(str), "%d", gyro[0]);
	Unicode::snprintf(textArea1_3Buffer, TEXTAREA1_3_SIZE, str);
	textArea1_3.invalidate();

	snprintf(str, sizeof(str), "%d", gyro[1]);
	Unicode::snprintf(textArea1_1_1Buffer, TEXTAREA1_1_1_SIZE, str);
	textArea1_1_1.invalidate();

	snprintf(str, sizeof(str), "%d", gyro[2]);
	Unicode::snprintf(textArea1_2_1Buffer, TEXTAREA1_2_1_SIZE, str);
	textArea1_2_1.invalidate();
}
