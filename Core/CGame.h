#pragma once
#include <windows.h>

class CGame {
private:
    static CGame* __instance;
    HWND hWnd;
public:
    static CGame* GetInstance();
    void Init(HWND hWnd);
    void Run();
    void LoadResources();
};
