#pragma once
#include <unordered_map>
#include "Sprite.h"

class SpriteManager
{
    static SpriteManager* __instance;
    std::unordered_map<int, Sprite*> sprites;

public:
    static SpriteManager* GetInstance();

    void Add(Sprite* sprite);
    Sprite* Get(int id);
    void Clear();
};
