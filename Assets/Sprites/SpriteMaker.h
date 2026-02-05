#pragma once
#include "Sprite.h"

class SpriteMaker
{
public:
    static Sprite* Create(
        int id,
        int left,
        int top,
        int right,
        int bottom,
        ID3D10ShaderResourceView* texture
    );
};
