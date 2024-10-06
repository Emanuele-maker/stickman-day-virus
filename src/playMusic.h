#include <windows.h>
#include <playsoundapi.h>
#include <stdio.h>
#include <string.h>
#include <mmsystem.h>

#ifndef _PLAY_MUSIC
#define _PLAY_MUSIC

bool playMusic(const char* audioPath, bool async) {
    char currentDir[PATH_MAX];
    char completePath[PATH_MAX];

    GetCurrentDirectoryA(PATH_MAX, currentDir);

    strcpy(completePath, currentDir);
    strcat(completePath, audioPath);

    return PlaySound((LPCSTR)completePath, NULL, SND_FILENAME | async);
}

#endif