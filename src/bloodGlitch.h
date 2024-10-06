#include <windows.h>
#include <winuser.h>
#include <wingdi.h>
#include <time.h>
#include <stdlib.h>

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

#ifndef BLOOD_GLITCH
#define BLOOD_GLITCH

void bloodGlitch() {
    srand(time(NULL));
    HDC screen;
    HBRUSH bgBrush;

    int x;
    int y;
    int width = 5;
    int height = 5;
    COLORREF bgColor = RGB(255, 0, 0);

    for (;;) {
        screen = GetDC(NULL);
        x = randnum(0, 100);
        y = randnum(0, 100);
        bgBrush = CreateSolidBrush(bgColor);
        SelectObject(screen, bgBrush);
        Rectangle(screen, x, y, width, height);
        DeleteDC(screen);
        Sleep(100);
    }

    // for (;;) {
    //     screen = GetDC(NULL);
    //     x = randnum(0, 1920);
    //     y = randnum(0, 1080);
    //     bgBrush = CreateSolidBrush(bgColor);
    //     SelectObject(screen, bgBrush);
    //     Rectangle(screen, x, y, 0, 0);
    //     Sleep(2);
    //     CancelDC(screen);
    //     Sleep(2);
    // }
}

#endif