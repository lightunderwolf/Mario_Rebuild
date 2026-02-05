#include "SpriteMaker.h"
#include "SpriteManager.h"
#include "TexturesManager.h"
#include "TextureIDs.h"

void LoadMarioSprites()
{
    auto tex = Textures::Get(TEX_MARIO);

    SpriteManager::GetInstance()->Add(
        SpriteMaker::Create(10001, 0, 0, 16, 32, tex)
    );

    SpriteManager::GetInstance()->Add(
        SpriteMaker::Create(10002, 16, 0, 32, 32, tex)
    );
}
