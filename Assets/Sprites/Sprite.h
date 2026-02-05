#pragma once
#include <d3d10.h>

class Sprite
{
    int id;
    int left, top, right, bottom;
    ID3D10ShaderResourceView* texture;

public:
    Sprite(
        int id,
        int left,
        int top,
        int right,
        int bottom,
        ID3D10ShaderResourceView* texture
    );

    int GetID() const { return id; }

    void GetRect(RECT& r) const
    {
        r.left = left;
        r.top = top;
        r.right = right;
        r.bottom = bottom;
    }

    ID3D10ShaderResourceView* GetTexture() const
    {
        return texture;
    }
};
