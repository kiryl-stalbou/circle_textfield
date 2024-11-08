#include "utils.h"


Offset Offset::operator+(const Offset& other) const {
    return Offset(dx + other.dx, dy + other.dy);
}

Offset Offset::operator-(const Offset& other) const {
    return Offset(dx - other.dx, dy - other.dy);
}

bool Offset::operator==(const Offset& other) const {
    return dx == other.dx && dy == other.dy;
}

bool Offset::operator!=(const Offset& other) const {
    return !(*this == other);
}


bool Size::contains(const Offset& offset) const {
    return offset.dx >= 0 && offset.dx < width && offset.dy >= 0 && offset.dy < height;
}

Size Size::operator+(const Size& other) const {
    return Size(width + other.width, height + other.height);
}

Size Size::operator-(const Size& other) const {
    return Size(width - other.width, height - other.height);
}

bool Size::operator==(const Size& other) const {
    return width == other.width && height == other.height;
}

bool Size::operator!=(const Size& other) const {
    return !(*this == other);
}

int clampInt(int value, int minValue, int maxValue) {
    if (value <= minValue) {
        return minValue;
    }
    if (value >= maxValue) {
        return maxValue;
    }
    return value;
}

bool isRectWithinBounds(const RECT& rect, const RECT& bounds) {
    return (rect.right - rect.left <= bounds.right - bounds.left) &&
        (rect.bottom - rect.top <= bounds.bottom - bounds.top);
}

HFONT createFont(int size) {
    return CreateFont(
        size,
        0,
        0,
        0,
        FW_MEDIUM,
        FALSE,
        FALSE,
        FALSE,
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        L"Arial"
    );
}