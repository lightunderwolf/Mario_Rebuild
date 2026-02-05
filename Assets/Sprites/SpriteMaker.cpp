#include "SpriteMaker.h"

Sprite* SpriteMaker::Create(
    int id,
    int left,
    int top,
    int right,
    int bottom,
    ID3D10ShaderResourceView* texture
)
{
    return new Sprite(id, left, top, right, bottom, texture);
}
