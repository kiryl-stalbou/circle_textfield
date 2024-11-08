#pragma once

#include "utils.h"
#include <wtypes.h>


constexpr Offset CIRCLE_TEXTFIELD_OFFSET = Offset(0, 0);
constexpr POINT WINDOW_MIN_SIZE = POINT{ 500, 500 };

bool initWindow(HINSTANCE hInstance, int nCmdShow);

int runWindowMessageLoop();

LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);