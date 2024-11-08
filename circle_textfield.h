#pragma once

#include "utils.h"
#include <vector>
#include <string>


constexpr int CIRCLE_TEXTFIELD_PADDING = 50;

constexpr int CIRCLE_TEXT_FONT_SIZE = 20;
constexpr int CIRCLE_TEXT_ANGLE_STEP_DEGREES = 5;
constexpr int CIRCLE_TEXT_MAX_LENGTH = 360 / CIRCLE_TEXT_ANGLE_STEP_DEGREES;

constexpr float PI = 3.14159265358979323846f;
constexpr float CIRCLE_TEXT_ANGLE_STEP_RADIANS = CIRCLE_TEXT_ANGLE_STEP_DEGREES * (PI / 180.0f);

using namespace std;

class CircleTextField {
public:
	CircleTextField();

	void layout(Size _size, Offset _offset);
	void paint(HDC hdc);
	void onKeyPress(wchar_t character);

private:
	Size size;
	Offset offset;
	wstring text;
	vector<Offset> textOffsets;
};