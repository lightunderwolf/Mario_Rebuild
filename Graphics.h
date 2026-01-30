#pragma once
#include <d3d10.h>
#include <d3dx10.h>

class Graphics
{
public:
    static ID3D10Device* device;
    static IDXGISwapChain* swapChain;
    static ID3D10RenderTargetView* renderTarget;
    static ID3DX10Sprite* spriteHandler;

    static void Init(HWND hWnd, int width, int height);
    static void Clear(float r, float g, float b);
    static void Present();
    static void Cleanup();
};
