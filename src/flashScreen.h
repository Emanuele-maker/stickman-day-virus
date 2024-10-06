#include <wingdi.h>

#ifndef FLASH_SCREEN
#define FLASH_SCREEN

void flashScreen(int secs) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    RECT dim = {
        left: 0,
        right: screenWidth,
        top: 0,
        bottom: screenHeight
    };
    HDC tempHdc         = GetDC(NULL);
    BLENDFUNCTION blend = {AC_SRC_OVER, 0, 127, 0};
    HBITMAP hbitmap;       // bitmap handle 
    BITMAPINFO bmi;        // bitmap header 
    // zero the memory for the bitmap info 
    ZeroMemory(&bmi, sizeof(BITMAPINFO));
    // setup bitmap info  
    // set the bitmap width and height to 60% of the width and height of each of the three horizontal areas. Later on, the blending will occur in the center of each of the three areas. 
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = screenWidth;
    bmi.bmiHeader.biHeight = screenHeight;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;         // four 8-bit components 
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage = (screenWidth) * (screenHeight) * 4;
    // create our DIB section and select the bitmap into the dc
    time_t prog_time = clock();
    while ((float)prog_time / CLOCKS_PER_SEC <= secs) {
        prog_time = clock();
        printf("%f\n", (float)prog_time / CLOCKS_PER_SEC);
        tempHdc = GetDC(NULL);
        hbitmap = CreateDIBSection(tempHdc, &bmi, DIB_RGB_COLORS, NULL, NULL, 0x0);
        SelectObject(tempHdc, hbitmap);
        SetDCPenColor(tempHdc, RGB(randnum(0, 255),randnum(0, 255),randnum(0, 255)));
        SetDCBrushColor(tempHdc, RGB(randnum(0, 255),randnum(0, 255),randnum(0, 255)));
        FillRect(tempHdc, &dim, CreateSolidBrush(RGB(randnum(0, 255),randnum(0, 255),randnum(0, 255))));
        AlphaBlend(NULL, 0, 0, screenWidth, screenHeight, tempHdc, 0, 0, screenWidth, screenHeight, blend);
        Sleep(25);
        CancelDC(tempHdc);
    }
}

#endif