#include <windows.h>
#include <stdio.h>
#include <wingdi.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#ifndef HELP_GLITCH
#define HELP_GLITCH

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

void helpGlitch() {
    srand(time(NULL));
    char currentDir[PATH_MAX];
    GetCurrentDirectoryA(PATH_MAX, currentDir);
    char completePath[PATH_MAX];
    char maskPath[PATH_MAX];

    strcpy(completePath, currentDir);
    strcat(completePath, "\\assets\\HELP-glitch.bmp");
    strcpy(maskPath, currentDir);
    strcat(maskPath, "\\assets\\mask.bmp");

	BITMAP bm, bmmask;
	
	HBITMAP bi = (HBITMAP)LoadImage(0, completePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP bmask = (HBITMAP)LoadImage(0, maskPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	
	HDC whdc = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(whdc);
	HDC hdcMask = CreateCompatibleDC(whdc);
	
	SelectObject(hdcMem, bi);
	SelectObject(hdcMask, bmask);
	
	GetObject((HGDIOBJ)bi, sizeof(bm), &bm);
	GetObject((HGDIOBJ)bmask, sizeof(bmmask), &bmmask);

    int x, y;
	
	while(1)
	{
        x = randnum(0, 1400);
        y = randnum(0, 800);

        bi = (HBITMAP)LoadImage(0, completePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	    bmask = (HBITMAP)LoadImage(0, maskPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    
	    whdc = GetDC(FindWindowA("Notepad", NULL));
	    hdcMem = CreateCompatibleDC(whdc);
	    hdcMask = CreateCompatibleDC(whdc);
    
	    SelectObject(hdcMem, bi);
	    SelectObject(hdcMask, bmask);
    
	    GetObject((HGDIOBJ)bi, sizeof(bm), &bm);
	    GetObject((HGDIOBJ)bmask, sizeof(bmmask), &bmmask);

		BitBlt(whdc, x, y, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCPAINT);
		BitBlt(whdc, y, y, bm.bmWidth, bm.bmHeight, hdcMask, 0, 0, SRCAND);

        Sleep(5);
	    DeleteDC(hdcMem);
	    DeleteObject(bi);
	    DeleteDC(hdcMask);
	    DeleteObject(bmask);        
        Sleep(5);
	}
}

#endif