#include <windows.h>
#include <winuser.h>
#include <time.h>
#include <stdlib.h>

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

int MsgBox_X;
int MsgBox_Y;
    
static void CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd, LONG idObject, LONG idChild, DWORD dwEventThread, DWORD dwmsEventTime)
{
    if ((GetWindowLongPtr(hwnd, GWL_STYLE) & WS_CHILD) == 0) 
        SetWindowPos(hwnd, NULL, MsgBox_X, MsgBox_Y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}
    
int MessageBoxPos(HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType, int X, int Y)
{
    HWINEVENTHOOK hHook = SetWinEventHook(EVENT_OBJECT_CREATE, EVENT_OBJECT_CREATE, NULL, &WinEventProc, GetCurrentProcessId(), GetCurrentThreadId(), WINEVENT_OUTOFCONTEXT);
    MsgBox_X = X;
    MsgBox_Y = Y;
    int result = MessageBox(hWnd, lpText, lpCaption, uType);
    if (hHook)  UnhookWinEvent(hHook);
    return result;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    #define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

    MessageBoxA(NULL, "This is the point of no return. If you haven't removed the virus yet, your pc is fucked up. You can now enjoy your final minutes with this pc.", "WARNING", MB_ICONWARNING);
    for (int i = 0; i < 500; i++) {
        int ResultMB = MessageBoxPos(NULL, TEXT("It's your fault"), TEXT("TONIGHT"), MB_OK, randnum(0, 1920), randnum(0, 1080));
        if (ResultMB == IDOK)
        {
            ResultMB = MessageBoxPos(NULL, TEXT("It's your fault"), TEXT("TOINIGHT"), MB_OK, randnum(0, 1920), randnum(0, 1080));
        }
    }
}