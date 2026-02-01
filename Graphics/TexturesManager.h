#pragma once
#include <d3d10.h>
#include <d3dx10.h>
#include <unordered_map>

class Textures
{
    static std::unordered_map<int, ID3D10ShaderResourceView*> textures;

public:
    static void Init();
    static void Add(int id, LPCWSTR filePath);
    static ID3D10ShaderResourceView* Get(int id);
    static void Clear();
};
