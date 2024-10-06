#include <windows.h>

int	nRandWidth = 150, nRandHeight = 15, nSpeed = 1;
int	nScreenWidth, nScreenHeight;

LRESULT WINAPI MelterProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch(Msg){
		case WM_CREATE:
			{
				HDC hdcDesktop = GetDC(NULL);
				HDC hdcWindow  = GetDC(hWnd);	
				BitBlt(hdcWindow, 0, 0, nScreenWidth, nScreenHeight, hdcDesktop, 0, 0, SRCCOPY);
				ReleaseDC(hWnd, hdcWindow);
				ReleaseDC(NULL, hdcDesktop);
				SetTimer(hWnd, 0, nSpeed, NULL);
				ShowWindow(hWnd, SW_SHOW);
			}
			return 0;
		case WM_ERASEBKGND:
			return 0;
		case WM_PAINT:
			ValidateRect(hWnd, NULL);
			return 0;
		case WM_TIMER:
			{
				HDC hdcWindow  = GetDC(hWnd);
				int	nXPos  = (rand() % nScreenWidth) - (nRandWidth / 2),
					nYPos  = (rand() % nRandHeight),
					nWidth = (rand() % nRandWidth);
				BitBlt(hdcWindow, nXPos, nYPos, nWidth, nScreenHeight, hdcWindow, nXPos, 0, SRCCOPY);
				ReleaseDC(hWnd, hdcWindow);
			}
			return 0;
		case WM_CLOSE:
		case WM_DESTROY:
			{
				KillTimer(hWnd, 0);
				PostQuitMessage(0);
			}
			return 0;				
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmdLine, int nShowCmd)
{
	HWND window = GetConsoleWindow();
    ShowWindow(window, SW_HIDE);

	nScreenWidth  = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	WNDCLASS wndClass = { 0, MelterProc, 0, 0, hInstance, NULL, LoadCursor(NULL, IDC_ARROW), 0, NULL, "Melter" };
	if(!RegisterClass(&wndClass)) return MessageBox(NULL, "Cannot register class!", NULL, MB_ICONERROR | MB_OK);
	
	HWND hWnd = CreateWindow("Melter", NULL, WS_POPUP, 0, 0, nScreenWidth, nScreenHeight, NULL, NULL, hInstance, NULL);
	if(!hWnd) return MessageBox(NULL, "Cannot create window!", NULL, MB_ICONERROR | MB_OK);
	
	srand(GetTickCount());
	MSG Msg = { 0 };
	while(Msg.message != WM_QUIT){
		if(PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		// if(GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		// 	DestroyWindow(hWnd);
	}
	return 0;
}