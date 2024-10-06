#include <windows.h>
#include <string.h>
#include <stdio.h>

#ifndef _RUN_ON_STARTUP
#define _RUN_ON_STARTUP

void runOnStartup() {
    // char currentDir[PATH_MAX];
    // GetCurrentDirectoryA(PATH_MAX, currentDir);
    // char exePath[PATH_MAX];

    // strcpy(exePath, currentDir);
    // strcat(exePath, "\\main.exe");

    // printf("%s\n", exePath);

    // HKEY hKey;
    // LPCSTR sk = TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
    // long openKey = RegOpenKeyExA(HKEY_CURRENT_USER, sk, 0, KEY_ALL_ACCESS, &hKey);

    // if (openKey != ERROR_SUCCESS) return false;
    
    // LPCSTR value = TEXT("Stickman day");
    // LPCSTR data = TEXT(exePath);

    // long setValue = RegSetValueExA(hKey, value, 0, REG_SZ, (LPBYTE)data, strlen(data) + 1);

    // if (setValue != ERROR_SUCCESS) return false;

    // long closeKey = RegCloseKey(hKey);

    // return closeKey == ERROR_SUCCESS;
}

#endif