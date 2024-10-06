#include <windows.h>
#include <winreg.h>

#ifndef SWAP_MOUSE_BUTTONS
#define SWAP_MOUSE_BUTTONS

void swapMouseButtons() {
    HKEY hKey;
    LPCTSTR sk = TEXT("Control Panel\\Mouse");
    RegOpenKeyExA(HKEY_CURRENT_USER, sk, 0, KEY_ALL_ACCESS, &hKey);

    RegSetValueExA(hKey, TEXT("SwapMouseButtons"), 0, REG_SZ, (LPBYTE)"1\0", 2);
    RegCloseKey(hKey);
}

#endif