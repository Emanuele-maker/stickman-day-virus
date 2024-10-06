#include <windows.h>
#include <string.h>
#include "boolean.h"

#ifndef CHANGE_DESKTOP_IMAGE
#define CHANGE_DESKTOP_IMAGE

bool changeDesktopImage(char* imagePath) {
    char currentDir[PATH_MAX];
    GetCurrentDirectoryA(PATH_MAX, currentDir);
    char completePath[PATH_MAX];

    strcpy(completePath, currentDir);
    strcat(completePath, imagePath);

    return SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, completePath, SPIF_UPDATEINIFILE);
}

#endif