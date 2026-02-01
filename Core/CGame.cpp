#include "CGame.h"
#include "Window.h"
#include "Debugs.h"
#include "Graphics.h"
#include "TexturesManager.h"
#include "MarioTextures.h"
#include "TileTextures.h"
#include "EnemyTextures.h"

CGame* CGame::__instance = nullptr;

CGame* CGame::GetInstance() {
    if (__instance == nullptr)
        __instance = new CGame();
    return __instance;
}

void CGame::Init(HWND hWnd) {
    this->hWnd = hWnd;
    Graphics::Init(hWnd, 800, 600);
    DebugOut(L"[CGame] Initialized\n");
}

void CGame::Run() {
    DebugOut(L"[CGame] Run start\n");
    while (Window::running) {
        Window::ProcessMessages();
        // future: Update(dt); Render();
        Graphics::Clear(0.0f, 0.0f, 0.0f); // nền xanh
        Graphics::Present();
    }
    Graphics::Cleanup();
    DebugOut(L"[CGame] Run end\n");
}
void CGame::LoadResources() {
    Textures::Init();

    LoadMarioTextures();
    LoadTileTextures();
    LoadEnemyTextures();
}
