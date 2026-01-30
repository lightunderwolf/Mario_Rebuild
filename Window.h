#pragma once
#include <windows.h>

class Window
{
public:
	// Biến cho game loop biết khi nào nên dừng
	static bool running;

	// Tạo cửa sổ game
	static HWND CreateGameWindow(
		HINSTANCE hInstance,
		int width,
		int height,
		int nCmdShow
	);

	// Xử lý message của Windows
	static void ProcessMessages();
};
