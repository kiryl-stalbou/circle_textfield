#include "circle_textfield.h"


CircleTextField::CircleTextField() {}

void CircleTextField::layout(Size _size, Offset _offset)
{
	size = _size;
	offset = _offset;

    int centerX = offset.dx + size.width / 2;
    int centerY = offset.dy + size.height / 2;
    int radius = min(size.width, size.height) / 2 - CIRCLE_TEXTFIELD_PADDING;

    float startAngleRadians = -0.5 * PI;

    for (int i = 0; i < textOffsets.size(); i++) 
    {
        float angleRadians = startAngleRadians + (i * CIRCLE_TEXT_ANGLE_STEP_RADIANS);

        textOffsets[i].dx = centerX + radius * cos(angleRadians);
        textOffsets[i].dy = centerY + radius * sin(angleRadians);
    }
}

void CircleTextField::paint(HDC hdc)
{
    HFONT hFont = createFont(CIRCLE_TEXT_FONT_SIZE);
    int oldBkMode = SetBkMode(hdc, TRANSPARENT);
    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

    for (int i = 0; i < text.size(); ++i) {
        wchar_t character = text[i];

        RECT rect = {
            textOffsets[i].dx,
            textOffsets[i].dy,
            textOffsets[i].dx + CIRCLE_TEXT_FONT_SIZE,
            textOffsets[i].dy + CIRCLE_TEXT_FONT_SIZE
        };

        DrawTextW(hdc, &character, 1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
    }

    SelectObject(hdc, hOldFont);
    SetBkMode(hdc, oldBkMode);
    DeleteObject(hFont);
}

void CircleTextField::onKeyPress(wchar_t character)
{
    if (character == '\b' && !text.empty())
    {
        text.pop_back();
    }
    else if (character != '\b' && text.size() < CIRCLE_TEXT_MAX_LENGTH)
    {
        text.push_back(character);
    }
    else
    {
        return;
    }

    textOffsets.resize(text.size());
    layout(size, offset);
}