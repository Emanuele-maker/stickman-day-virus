#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

#ifndef MOVE_DESKTOP_ICONS
#define MOVE_DESKTOP_ICONS

void moveDesktopIcons(int secs) {
  srand(time(NULL));
	HWND hd;
	
	HANDLE he;
	DWORD Pi;
	
	hd = FindWindowA("Progman", NULL);
	hd = FindWindowEx(hd, 0, "SHELLDLL_DefView", NULL);
	hd = FindWindowEx(hd, 0, "SysListView32", NULL);
	
	GetWindowThreadProcessId(hd, &Pi);
	he = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, false, Pi);
	
	POINT *pC = (POINT*) VirtualAllocEx(he, NULL, sizeof(POINT), MEM_COMMIT, PAGE_READWRITE);
	WriteProcessMemory(he, pC, &pC, sizeof(POINT), NULL);
	
	/* POINT pt;
	ListView_GetItemPosition(hd, 0, pC);
	ReadProcessMemory(he, pC, &pt, sizeof(POINT), NULL);
	cout<<"X : "<<pt.x<<" Y : "<<pt.y<<endl; */
	
  	time_t prog_time = clock();
	while ((float)prog_time / CLOCKS_PER_SEC <= secs) {
    	prog_time = clock();
    	printf("%f\n", (float)prog_time / CLOCKS_PER_SEC);
		// POINT px;
		// GetCursorPos(&px);
    	// int count;
		  // count = SendMessage(hd, LVM_GETITEMCOUNT, 0, 0);
    	for (int i = 0; i < 300; i++) {
			ListView_SetItemPosition(hd, i, randnum(0, 1920), randnum(0, 1080));
    	}
		Sleep(2);
	}
	
	VirtualFreeEx(he, pC, 0, MEM_RELEASE);
}

#endif