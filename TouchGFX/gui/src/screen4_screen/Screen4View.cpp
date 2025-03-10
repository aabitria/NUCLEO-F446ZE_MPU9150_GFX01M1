#include <gui/screen4_screen/Screen4View.hpp>
#include <touchgfx/widgets/canvas/CWRUtil.hpp>
#include <cstring>
#include <cstdio>

Screen4View::Screen4View()
{

}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}

void Screen4View::display_angle(float *val)
{
	char str[6] = {0};

	/* pitch readings */
	snprintf(str, sizeof(str), "%.1f", val[0]);
	Unicode::snprintf(textArea3Buffer, TEXTAREA3_SIZE, str);
	textArea3.invalidate();

	/* roll */
	snprintf(str, sizeof(str), "%.1f", val[1]);
	Unicode::snprintf(textArea4Buffer, TEXTAREA4_SIZE, str);
	textArea4.invalidate();

}
