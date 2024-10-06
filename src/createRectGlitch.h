#include <windows.h>
#include <winuser.h>
#include <wingdi.h>
#include <time.h>
#include <stdlib.h>
#include "./progClock.h"
#include "./boolean.h"

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

#ifndef CREATE_RECT_GLITCH
#define CREATE_RECT_GLITCH

int createRectGlitch(int secs) {
    srand(time(NULL));
    HDC screen;
    HBRUSH bgBrush;

    int x;
    int y;
    int width;
    int height;
    COLORREF bgColor;

    time_t prog_time = clock();
    while ((float)prog_time / CLOCKS_PER_SEC <= secs) {
        prog_time = clock();
        printf("%f\n", (float)prog_time / CLOCKS_PER_SEC);
        screen = GetDC(NULL);
        x = randnum(0, 1920);
        y = randnum(0, 1080);
        width = randnum(0, 1920);
        height = randnum(0, 1080);
        bgColor = RGB(randnum(0, 255), randnum(0, 255), randnum(0, 255));
        bgBrush = CreateSolidBrush(bgColor);
        SelectObject(screen, bgBrush);
        Rectangle(screen, x, y, width, height);
        Sleep(5);
        CancelDC(screen);
    }

    return 0;
}

#endif