#include "TexturesManager.h"
#include "Graphics.h"
#include "Debugs.h"

std::unordered_map<int, ID3D10ShaderResourceView*> Textures::textures;

void Textures::Add(int id, LPCWSTR filePath)
{
    if (textures[id])
        return;

    ID3D10ShaderResourceView* texture = nullptr;

    HRESULT hr = D3DX10CreateShaderResourceViewFromFile(
        Graphics::device,
        filePath,
        nullptr,
        nullptr,
        &texture,
        nullptr
    );

    if (FAILED(hr))
    {
        DebugOut(L"[ERROR] Cannot load texture %s\n", filePath);
        return;
    }

    textures[id] = texture;
    DebugOut(L"[TEXTURE] Loaded %s\n", filePath);
}

ID3D10ShaderResourceView* Textures::Get(int id)
{
    return textures[id];
}

void Textures::Clear()
{
    for (auto& t : textures)
        if (t.second) t.second->Release();

    textures.clear();
}
