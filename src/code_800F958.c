#include "global.h"
#include "code_800F958.h"
#include "dungeon_pokemon_sprites.h"
#include "memory.h"

extern DungeonPokemonSprite *NewDungeonPokemonSprite(void);
extern DungeonPokemonSprite* GetDungeonPokemonSprite(s32 id);

extern DungeonPos gUnknown_80D3564;

void AddPokemonDungeonSprite(s32 id, s16 species, DungeonPos *pos, u32 r3) {
    DungeonPokemonSprite *dSprite;
    DungeonPokemonSprite *newSprite;
    DungeonPos newPos;
    s32 species_s32;

    species_s32 = species;

    if(gDungeonPokemonSprites == NULL)
        return;

    dSprite = GetDungeonPokemonSprite(id);
    if(dSprite != NULL)
        return;

    newSprite = NewDungeonPokemonSprite();
    if(newSprite == NULL)
        return;

    newSprite->exists = 1;
    newSprite->id = id;
    newSprite->species = species_s32;
    newSprite->status = 0;
    newSprite->pos = *pos;
    newSprite->unk11 = r3;
    newPos = gUnknown_80D3564;
    newSprite->statusOffsets[1] = newPos;
    newSprite->statusOffsets[0] = newPos;
    newSprite->statusSprites[0].status = 0;
    newSprite->statusSprites[0].frame = 0;
    newSprite->statusSprites[1].status = 0;
    newSprite->statusSprites[1].frame = 0;
}

void DeletePokemonDungeonSprite(s32 id)
{
    DungeonPokemonSprite *dSprite;

    if(gDungeonPokemonSprites == NULL)
        return;

    dSprite = GetDungeonPokemonSprite(id);
    if(dSprite == NULL)
        return;

    MemoryClear8((u8 *)dSprite, sizeof(DungeonPokemonSprite));
}

void sub_800F958(s32 dungeonSpriteID, DungeonPos *pos,
                 DungeonPos *statusOffsets, u32 a3)
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
