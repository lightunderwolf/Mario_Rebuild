#include "Graphics.h"
#include "Debugs.h"

ID3D10Device* Graphics::device = nullptr;
IDXGISwapChain* Graphics::swapChain = nullptr;
ID3D10RenderTargetView* Graphics::renderTarget = nullptr;
ID3DX10Sprite* Graphics::spriteHandler = nullptr;

void Graphics::Init(HWND hWnd, int width, int height)
{
    DXGI_SWAP_CHAIN_DESC sd{};
    sd.BufferCount = 1;
    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;

    HRESULT hr = D3D10CreateDeviceAndSwapChain(
        nullptr,
        D3D10_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        D3D10_SDK_VERSION,
        &sd,
        &swapChain,
        &device
    );

    if (FAILED(hr))
    {
        DebugOut(L"[ERROR] D3D10CreateDeviceAndSwapChain failed\n");
        return;
    }

    ID3D10Texture2D* backBuffer = nullptr;
    swapChain->GetBuffer(0, __uuidof(ID3D10Texture2D), (void**)&backBuffer);

    device->CreateRenderTargetView(backBuffer, nullptr, &renderTarget);
    backBuffer->Release();

    device->OMSetRenderTargets(1, &renderTarget, nullptr);
    D3D10_VIEWPORT vp{};
    vp.Width = width;
    vp.Height = height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;

    device->RSSetViewports(1, &vp);
    D3DX10CreateSprite(device, 0, &spriteHandler);
    DebugOut(L"[Graphics] DirectX init OK\n");
}
void Graphics::Clear(float r, float g, float b)
{
    float color[4] = { r, g, b, 1.0f };
    device->ClearRenderTargetView(renderTarget, color);
}

void Graphics::Present()
{
    swapChain->Present(0, 0);
}
void Graphics::Cleanup()
{
    if (spriteHandler) spriteHandler->Release();
    if (renderTarget) renderTarget->Release();
    if (swapChain) swapChain->Release();
    if (device) device->Release();
}
