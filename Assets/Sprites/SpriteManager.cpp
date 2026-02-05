#include "SpriteManager.h"

SpriteManager* SpriteManager::__instance = nullptr;

SpriteManager* SpriteManager::GetInstance()
{
    if (!__instance)
        __instance = new SpriteManager();
    return __instance;
}

void SpriteManager::Add(Sprite* sprite)
{
    int id = sprite->GetID();
    if (sprites[id] != nullptr)
        return;

    sprites[id] = sprite;
}

Sprite* SpriteManager::Get(int id)
{
    auto it = sprites.find(id);
    if (it == sprites.end())
        return nullptr;

    return it->second;
}

void SpriteManager::Clear()
{
    for (auto& s : sprites)
        delete s.second;

    sprites.clear();
}
