#include <gui/screen3_screen/Screen3View.hpp>
#include <touchgfx/widgets/canvas/CWRUtil.hpp>
#include <cstring>
#include <cstdio>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::display_sensor_values (float *val)
{
	char str[6] = {0};

	/* Gyro readings */
	snprintf(str, sizeof(str), "%.1f", val[0]);
	Unicode::snprintf(textArea1_3Buffer, TEXTAREA1_3_SIZE, str);
	textArea1_3.invalidate();

	snprintf(str, sizeof(str), "%.1f", val[1]);
	Unicode::snprintf(textArea1_1_1Buffer, TEXTAREA1_1_1_SIZE, str);
	textArea1_1_1.invalidate();

	snprintf(str, sizeof(str), "%.1f", val[2]);
	Unicode::snprintf(textArea1_2_1Buffer, TEXTAREA1_2_1_SIZE, str);
	textArea1_2_1.invalidate();

	snprintf(str, sizeof(str), "%.1f", val[3]);
	Unicode::snprintf(textArea1_3_1Buffer, TEXTAREA1_3_1_SIZE, str);
	textArea1_3_1.invalidate();

	snprintf(str, sizeof(str), "%.1f", val[4]);
	Unicode::snprintf(textArea1_1_1_1Buffer, TEXTAREA1_1_1_1_SIZE, str);
	textArea1_1_1_1.invalidate();

	snprintf(str, sizeof(str), "%.1f", val[5]);
	Unicode::snprintf(textArea1_2_1_1Buffer, TEXTAREA1_2_1_1_SIZE, str);
	textArea1_2_1_1.invalidate();
}
