#include <windows.h>
#include <stdio.h>

#ifndef CREATE_CHILD_PROCESS
#define CREATE_CHILD_PROCESS

HANDLE createChildProcess(char* path) {
    HANDLE hProcess = 0;
    HANDLE hThread = 0;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwProcessID = 0;

    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));

    CreateProcessA(path, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

    // WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return pi.hProcess;
}

#endif