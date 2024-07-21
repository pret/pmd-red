#include "global.h"
#include "code_800F958.h"

extern DungeonPokemonSprites *gDungeonPokemonSprites;

extern DungeonPokemonSprite* GetDungeonPokemonSprite(s32 id);

void sub_800F958(s32 dungeonSpriteID, Position *pos, Position *statusOffsets, u32 a3)
{
    DungeonPokemonSprite *dSprite;

    if (gDungeonPokemonSprites == NULL)
        return;

    dSprite = GetDungeonPokemonSprite(dungeonSpriteID);
    if (dSprite == NULL)
        return;

    dSprite->pos = *pos;
    dSprite->unk11 = a3;
    dSprite->statusOffsets[0] = statusOffsets[0];
    dSprite->statusOffsets[1] = statusOffsets[3];
}
