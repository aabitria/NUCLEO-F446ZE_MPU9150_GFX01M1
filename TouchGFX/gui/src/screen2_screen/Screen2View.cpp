#include <gui/screen2_screen/Screen2View.hpp>
#include <cstdio>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::display_raw_accel(short *accel)
{
	char str[6] = {0};

	snprintf(str, sizeof(str), "%d", accel[0]);
	Unicode::snprintf(textArea1_3Buffer, TEXTAREA1_3_SIZE, str);
	textArea1_3.invalidate();

	snprintf(str, sizeof(str), "%d", accel[1]);
	Unicode::snprintf(textArea1_1_1Buffer, TEXTAREA1_1_1_SIZE, str);
	textArea1_1_1.invalidate();

	snprintf(str, sizeof(str), "%d", accel[2]);
	Unicode::snprintf(textArea1_2_1Buffer, TEXTAREA1_2_1_SIZE, str);
	textArea1_2_1.invalidate();

}
