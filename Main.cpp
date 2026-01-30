#include <windows.h>
#include "Window.h"
#include "Debugs.h"
#include "CGame.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
) {
	HWND hWnd = Window::CreateGameWindow(
		hInstance,
		800,
		600,
		nCmdShow);

	SetDebugWindow(hWnd);
	if (!hWnd) return 0;

	SetDebugWindow(hWnd);
	CGame* game = CGame::GetInstance();
	game->Init(hWnd);
	game->Run();

	return 0;
}
