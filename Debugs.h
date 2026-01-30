#pragma once
#include <windows.h>
#include <stdarg.h>
#include <stdio.h>
void DebugOut(const wchar_t* fmt, ...);
void SetDebugWindow(HWND hwnd);
