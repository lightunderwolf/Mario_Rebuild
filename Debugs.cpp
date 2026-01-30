#include "Debugs.h"

static HWND debugWindow = NULL;


void DebugOut(const wchar_t* fmt, ...)
{
    wchar_t buffer[1024];

    va_list args;
    va_start(args, fmt);
    vswprintf_s(buffer, fmt, args);
    va_end(args);

    OutputDebugString(buffer);
}
void SetDebugWindow(HWND hwnd)
{
    debugWindow = hwnd;
}