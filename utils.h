#pragma once

#include <wtypes.h>

struct Offset {
    int dx;
    int dy;

    constexpr Offset() : dx(0), dy(0) {}
    constexpr Offset(int _dx, int _dy) : dx(_dx), dy(_dy) {}

    Offset operator+(const Offset& other) const;
    Offset operator-(const Offset& other) const;
    bool operator==(const Offset& other) const;
    bool operator!=(const Offset& other) const;
};

struct Size {
    int width;
    int height;

    constexpr Size() : width(0), height(0) {}
    constexpr Size(int _width, int _height) : width(_width), height(_height) {}

    bool contains(const Offset& offset) const;

    Size operator+(const Size& other) const;
    Size operator-(const Size& other) const;
    bool operator==(const Size& other) const;
    bool operator!=(const Size& other) const;
};

int clampInt(int value, int minValue, int maxValue);
bool isRectWithinBounds(const RECT& rect, const RECT& bounds);
HFONT createFont(int size);