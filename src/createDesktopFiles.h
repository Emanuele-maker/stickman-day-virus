#include <stdio.h>
#include <windows.h>

#define DESKTOP_FILES 50

typedef struct _FILE_WITH_NAME {
    FILE* f;
    char name[20];
} FILE_WITH_NAME;

#ifndef CREATE_DESKTOP_FILES
#define CREATE_DESKTOP_FILES

void createDesktopFiles() {
    char desktopDir[100];
    FILE_WITH_NAME desktopFiles[DESKTOP_FILES];

    /* init desktop dir */
    strcpy(desktopDir, getenv("SystemDrive"));
    strcat(desktopDir, "\\Users\\");
    strcat(desktopDir, getenv("USERNAME"));
    strcat(desktopDir, "\\Desktop");

    for (int i = 0; i < DESKTOP_FILES; i++) {
        char indexString[3];
        sprintf(indexString, "%d", i);
        strcpy(desktopFiles[i].name, desktopDir);
        strcat(desktopFiles[i].name, "\\TONIGHT");
        strcat(desktopFiles[i].name, indexString);
        strcat(desktopFiles[i].name, ".txt");
        desktopFiles[i].f = fopen64(desktopFiles[i].name, "w");
        char fileContent[1000];
        strcpy(fileContent, "TONIGHT\n");
        for (int j = 0; j < 40; j++) {
            strcat(fileContent, "TONIGHT\n");
        }
        fprintf(desktopFiles[i].f, fileContent);
        fclose(desktopFiles[i].f);
    }
}

#endif