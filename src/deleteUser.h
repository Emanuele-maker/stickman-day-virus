#include <windows.h>
#include <lm.h>
#include <lmaccess.h>
#include <stdio.h>

#ifndef _DELETE_USER
#define _DELETE_USER

void deleteUser(LPWSTR userName) {
    NET_API_STATUS status = NetUserDel(NULL, userName);
    if (status != NERR_Success) {
        printf("Error while deleting a user: %d\n", status);
    }
}

#endif