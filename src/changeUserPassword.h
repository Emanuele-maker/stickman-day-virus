#include <windows.h>
#include <lmaccess.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stringapiset.h>

#ifndef CHANGE_USER_PASSWORD
#define CHANGE_USER_PASSWORD

void changeUserPassword() {
    char* username = "Emanuele";
    LPWSTR wideUsername;
    MultiByteToWideChar(CP_ACP, MB_COMPOSITE, username, sizeof(username), wideUsername, strlen(username));

    long err = NetUserChangePassword(NULL, wideUsername, L"BLOOD", L"");

    if (err != NERR_Success) {
        int n;
        printf("There was an error changing user's password: %d\n", err);
        scanf("%d", &n);
    }
}

#endif