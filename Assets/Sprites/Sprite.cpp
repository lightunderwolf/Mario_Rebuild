#include "Sprite.h"

Sprite::Sprite(
    int id,
    int left,
    int top,
    int right,
    int bottom,
    ID3D10ShaderResourceView* texture
)
{
    this->id = id;
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->texture = texture;
}
