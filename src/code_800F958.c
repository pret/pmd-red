#include "global.h"
#include "code_800F958.h"
#include "code_8009804.h"
#include "cpu.h"
#include "dungeon_pokemon_sprites.h"
#include "memory.h"

struct StatusGraphicsInfo
{
     /* 0x0 */ s32 width;
     /* 0x4 */ s32 height;
     /* 0x8 */ s32 vramIndex;
     /* 0xC */ s32 unk;
     /* 0x10 */ s32 graphicsCount;
     /* 0x14 */ s32 offsetIntoGraphic;
};

extern struct StatusGraphicsInfo gStatusGraphics[]; // 0x80CE79C
extern u8 *gStatusGraphics4bpp[]; // TODO use INCBIN_U8

extern DungeonPokemonSprite *NewDungeonPokemonSprite(void);
extern DungeonPokemonSprite* GetDungeonPokemonSprite(s32 id);

extern DungeonPos gUnknown_80D3564;

void sub_800F2EC(DungeonPokemonSprite *, s32, s16 *);

void LoadStatusGraphics(s32 graphicIndex, bool8 param_2)
{
    s32 frame;
    s32 size;
    s32 vramIndex;
    s32 offset;
    u8 *ptr;
    s32 graphicsCount;


    struct StatusGraphicsInfo *graphic = &gStatusGraphics[graphicIndex];


    offset = graphic->offsetIntoGraphic;
    graphicsCount = graphic->graphicsCount;
    size = graphic->width  * graphic->height * 0x20;
    vramIndex = (graphic->vramIndex + 0x32b) * 0x20;
    frame = (gDungeonPokemonSprites->frame / 4) % graphicsCount;
    frame *= size;
    ptr = (u8 *)gStatusGraphics4bpp + (offset) + (frame);

    if (param_2) {
        sub_80098BC((void *)(VRAM + 0x10000 + vramIndex), (void *)ptr, size);   
    }
    else {
        CpuCopy((void *)(VRAM + 0x10000 + vramIndex), ptr, size);
    }
    return;
}

void InitDungeonPokemonSprites(void)
{
    if (gDungeonPokemonSprites == NULL) {
        gDungeonPokemonSprites = MemoryAlloc(sizeof(DungeonPokemonSprites),0xc);
        MemoryClear8(gDungeonPokemonSprites,sizeof(DungeonPokemonSprites));
    }
    gDungeonPokemonSprites->frame = 0;
    LoadStatusGraphics(1,0);
    LoadStatusGraphics(2,0);
    LoadStatusGraphics(3,0);
    LoadStatusGraphics(4,0);
    LoadStatusGraphics(5,0);
    LoadStatusGraphics(6,0);
    LoadStatusGraphics(7,0);
    LoadStatusGraphics(8,0);
    LoadStatusGraphics(9,0);
    LoadStatusGraphics(10,0);
    LoadStatusGraphics(0xb,0);
    LoadStatusGraphics(0xc,0);
    LoadStatusGraphics(0xd,0);
    LoadStatusGraphics(0xe,0);
    LoadStatusGraphics(0xf,0);
    LoadStatusGraphics(0x10,0);
    return;
}

void FreeDungeonPokemonSprites(void)
{
    if (gDungeonPokemonSprites != 0) {
        MemoryFree(gDungeonPokemonSprites);
        gDungeonPokemonSprites = NULL;
    }
}

void UpdateDungeonPokemonSprite(s32 id, s32 species, s32 status, u32 visible)
{
  DungeonPokemonSprite *sprite;
  s32 species_s32 = (s16)species;
  u32 visible_u8 = (u8)visible;
  
  if (gDungeonPokemonSprites != 0) {
    sprite = GetDungeonPokemonSprite(id);
    if (sprite != 0) {
      sprite->species = species_s32;
      sprite->status = status;
      sprite->visible = visible_u8;
      sprite->unk38 = 0;
    }
  }
}

void sub_800F794(s32 id, s32 r1, s32 r2, s32 r3, s32 *r4)
{
    if(gDungeonPokemonSprites)
    {
        DungeonPokemonSprite *sprite = GetDungeonPokemonSprite(id);
        if(sprite)
        {
            sprite->unk38 = 1;
            sprite->unk3C = r2;
            sprite->unk3E = r3;
            sprite->unk20 = r4[0];
            sprite->unk24 = r4[3];
        }
    }
}

void sub_800F7D0(s16 *r0)
{
    s32 index;

    if (gDungeonPokemonSprites == NULL)
        return;

    switch(gDungeonPokemonSprites->frame % 4) {
        case 0:
            LoadStatusGraphics(1, 1);
            LoadStatusGraphics(2, 1);
            LoadStatusGraphics(3, 1);
            LoadStatusGraphics(4, 1);
            break;
        case 1:
            LoadStatusGraphics(5, 1);
            LoadStatusGraphics(6, 1);
            LoadStatusGraphics(7, 1);
            LoadStatusGraphics(8, 1);
            break;
        case 2:
            LoadStatusGraphics(9, 1);
            LoadStatusGraphics(0xA, 1);
            LoadStatusGraphics(0xB, 1);
            LoadStatusGraphics(0xC, 1);
            break;
        case 3:
            LoadStatusGraphics(0xD, 1);
            LoadStatusGraphics(0xE, 1);
            LoadStatusGraphics(0xF, 1);
            LoadStatusGraphics(0x10, 1);
            break;
    }

    for (index = 0; index < 22; index++) {
        if (gDungeonPokemonSprites->sprites[index].exists) {
            DungeonPokemonSprite *spritePtr = &gDungeonPokemonSprites->sprites[index];
            sub_800F2EC(spritePtr, 0, r0);
            sub_800F2EC(spritePtr, 1, r0);
        }
    }
    gDungeonPokemonSprites->frame++;
}

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

    if (gDungeonPokemonSprites == NULL)
        return;

    dSprite = GetDungeonPokemonSprite(id);
    if (dSprite == NULL)
        return;

    MemoryClear8(dSprite, sizeof(DungeonPokemonSprite));
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
