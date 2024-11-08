#include "utils.h"
#include "window.h"
#include "Resource.h"
#include "circle_textfield.h"
#include <windowsx.h>


CircleTextField circleTextField;

bool initWindow(HINSTANCE hInstance, int nCmdShow)
{
    WNDCLASSEXW wcexw;

    wcexw.cbSize = sizeof(WNDCLASSEX);

    wcexw.cbClsExtra = 0;
    wcexw.cbWndExtra = 0;
    wcexw.lpfnWndProc = wndProc;
    wcexw.lpszMenuName = nullptr;
    wcexw.hInstance = hInstance;
    wcexw.lpszClassName = L"Table_Class";
    wcexw.style = CS_HREDRAW | CS_VREDRAW;
    wcexw.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcexw.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcexw.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIRCLETEXTFIELD));
    wcexw.hIconSm = LoadIcon(wcexw.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcexw);

    HWND hWnd = CreateWindowW(
        L"Table_Class", L"Table", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
        nullptr, nullptr, hInstance, nullptr
    );

    if (!hWnd) return false;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return true;
}

int runWindowMessageLoop()
{
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_GETMINMAXINFO:
        {
            MINMAXINFO* minMaxInfo = (MINMAXINFO*)lParam;
            minMaxInfo->ptMinTrackSize = WINDOW_MIN_SIZE;
            break;
        }
        case WM_SIZE:
        {
            Size size = Size(LOWORD(lParam) - CIRCLE_TEXTFIELD_OFFSET.dx, HIWORD(lParam) - CIRCLE_TEXTFIELD_OFFSET.dy);
            circleTextField.layout(size, CIRCLE_TEXTFIELD_OFFSET);
            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            circleTextField.paint(hdc);
            EndPaint(hWnd, &ps);
            break;
        }
        case WM_KEYDOWN:
        {
            circleTextField.onKeyPress(wParam);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
        default:
        {
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    return 0;
}