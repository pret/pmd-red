#include "global.h"
#include "globaldata.h"
#include "code_800F958.h"
#include "code_8009804.h"
#include "cpu.h"
#include "dungeon_pokemon_sprites.h"
#include "memory.h"
#include "sprite.h"
#include "structs/sprite_oam.h"
#include <stdio.h>

struct StatusGraphicsInfo
{
     /* 0x0 */ s32 width;
     /* 0x4 */ s32 height;
     /* 0x8 */ s32 vramIndex;
     /* 0xC */ s32 unk;
     /* 0x10 */ s32 graphicsCount;
     /* 0x14 */ s32 offsetIntoGraphic;
};

#define TILE_SIZE_2BPP 32

const struct StatusGraphicsInfo gStatusGraphics[] = {
    {0, 0, 0,  0,  0,  0},
    {1, 1, 0,  0,  14, TILE_SIZE_2BPP * 0  },  // sleepless
    {2, 2, 1,  0,  7,  TILE_SIZE_2BPP * 14 },  // burned
    {2, 2, 5,  0,  16, TILE_SIZE_2BPP * 42 },  // poisoned
    {4, 4, 9,  0,  6,  TILE_SIZE_2BPP * 106},  // frozen
    {4, 2, 25, 0,  4,  TILE_SIZE_2BPP * 202},  // confused
    {2, 2, 33, 0,  9,  TILE_SIZE_2BPP * 234},  // whiffer
    {2, 2, 37, 0,  8,  TILE_SIZE_2BPP * 270},  // taunted
    {1, 2, 41, 0,  8,  TILE_SIZE_2BPP * 302},  // lowhp
    {2, 2, 43, 0,  13, TILE_SIZE_2BPP * 318},  // shield
    {2, 2, 47, 10, 10, TILE_SIZE_2BPP * 370},  // statdown
    {2, 2, 51, 0,  13, TILE_SIZE_2BPP * 410},  // sword
    {1, 1, 55, 0,  14, TILE_SIZE_2BPP * 462},  // blinker
    {2, 2, 56, 0,  10, TILE_SIZE_2BPP * 476},  // cross-eyed
    {1, 1, 60, 0,  14, TILE_SIZE_2BPP * 516},  // eyedrops
    {2, 2, 61, 0,  8,  TILE_SIZE_2BPP * 530},  // muzzled
    {2, 2, 65, 4,  10, TILE_SIZE_2BPP * 562},  // sleep
};

extern const u8 gStatusGraphics4bpp[16][3072];


// static const u8 *gStatusGraphics4bpp[16][3072] = {
//     INCBIN_U8("graphics/status/sleepless.4bpp"),
//     INCBIN_U8("graphics/status/burned.4bpp"),
//     INCBIN_U8("graphics/status/poisoned.4bpp"),
//     INCBIN_U8("graphics/status/frozen.4bpp"),
//     INCBIN_U8("graphics/status/confused.4bpp"),
//     INCBIN_U8("graphics/status/whiffer.4bpp"),
//     INCBIN_U8("graphics/status/taunted.4bpp"),
//     INCBIN_U8("graphics/status/lowhp.4bpp"),
//     INCBIN_U8("graphics/status/shield.4bpp"),
//     INCBIN_U8("graphics/status/statdown.4bpp"),
//     INCBIN_U8("graphics/status/sword.4bpp"),
//     INCBIN_U8("graphics/status/blinker.4bpp"),
//     INCBIN_U8("graphics/status/cross_eyed.4bpp"),
//     INCBIN_U8("graphics/status/eyedrops.4bpp"),
//     INCBIN_U8("graphics/status/muzzled.4bpp"),
//     INCBIN_U8("graphics/status/sleep.4bpp")
// };


struct StatusSprite
{
    u32 image;
    u32 palette;
};
extern struct StatusSprite gStatusSprites[8];

extern SpriteOAM gUnknown_203B0DC;

extern DungeonPos gUnknown_80D3564;

void DrawStatusSprite(s16 param_1,s32 status,DungeonPos *pos,DungeonPos *posOffset,
                      DungeonPos *posScreen,u32 priority, u32 unused);

DungeonPokemonSprite *GetDungeonPokemonSprite(s32 id)
{
    s32 index;

    for(index = 0; index < 22; index++)
    {

        if(gDungeonPokemonSprites->sprites[index].exists && gDungeonPokemonSprites->sprites[index].id == id)
        {
            return &gDungeonPokemonSprites->sprites[index];
        }
    }
    
    return NULL;
}

DungeonPokemonSprite *NewDungeonPokemonSprite(void){
    s32 index;
    DungeonPokemonSprite *sprite;

    for(index = 0; index < 22; index++)
    {
        sprite = &gDungeonPokemonSprites->sprites[index];

        if(!sprite->exists)
        {
            return sprite;
        }
    }
    return NULL;
}

u32 GetNextStatusSymbol(DungeonPokemonSprite *sprite, s32 statusIndex)
{
    u32 uVar1;
    u32 status;
    s32 counter;
    s32 max;
    u32 uVar5;
    u32 uVar6;
    DungeonPokemonStatusSprite *statusSprite;

    statusSprite = &sprite->statusSprites[statusIndex];  
    uVar5 = 0x10000000;
    if (statusIndex == 0) {
        uVar5 = 1;
    }
    uVar6 = 0x10000000;
    if (statusIndex == 0) {
        uVar6 = 0x8000000;
    }
    max = 1;
    if (statusIndex == 0) {
        max = 0x1c;
    }
    if (sprite->status == 0) {
        return 0;
    }

    status = statusSprite->status;
    uVar1 = uVar5;
    if (status != 0) {
        uVar1 = status;
    }

    for(counter = 0; counter < max; counter++)
    {
        uVar1 *= 2;
        if (uVar1 > uVar6) {
            uVar1 = uVar5;
        }
        if ((sprite->status & uVar1) != 0) {
            return uVar1;
        }
    }
    return 0;
}

u32 StatusSymbolBitToIndex(u32 statusBit)
{
  u32 index;
  
  index = 0;
  while (statusBit != 0) {
      statusBit >>= 1;
      index++;
  }
  return index;
}

void sub_800F2EC(DungeonPokemonSprite *sprite, s32 index, DungeonPos *screenPos)
{
    u32 newFrame;
    DungeonPokemonStatusSprite *statusSprite;
    u32 statusSymbol;

    statusSprite = sprite->statusSprites + index;
    if (sprite->status == 0) {
        statusSprite->status = 0;
    }
    else {
        if (statusSprite->status == 0) {
            statusSprite->frame = 0;
        }
        if (statusSprite->frame < 1) {
            statusSymbol = GetNextStatusSymbol(sprite,index);
            if (statusSprite->status != statusSymbol) {
                statusSprite->status = statusSymbol;
            }
            newFrame = 0x3c;
        }
        else {
            newFrame = statusSprite->frame - 1;
        }
        statusSprite->frame = newFrame;
        if ((sprite->visible != 0) && (statusSprite->status != 0)) {
            DrawStatusSprite(sprite->species,StatusSymbolBitToIndex(statusSprite->status),&(sprite->pos),
                             &sprite->statusOffsets[index],screenPos,sprite->priority, sprite->id);
        }
    }
}

void DrawStatusSprite(s16 param_1, s32 status, DungeonPos *pos, DungeonPos *posOffset,
                      DungeonPos *posScreen, u32 priority, u32 unused)
{
    struct StatusSprite sprite;
    s32 posY;
    s32 posX;
    u32 uVar7;
    s32 vramIndex;
    const struct StatusGraphicsInfo *ptr;

    sprite = gStatusSprites[status];

    ptr = &gStatusGraphics[sprite.image];
    vramIndex = (ptr->vramIndex + 0x32b);
    SpriteSetPriority(&gUnknown_203B0DC, priority);

    posX = (pos->x - ptr->width  * 4 - posScreen->x) + posOffset->x;
    posY = (pos->y - ptr->height * 4 - posScreen->y) + posOffset->y;
    uVar7 = posY - 0x10;
    if ((((-0x20 <= posX) && (-0x20 <= posY)) && (posX < 0xf0)) && (posY < 0xa0)) {
        switch(sprite.image) {
            case 1:
            case 0xc:
            case 0xe:
                SpriteSetShape(&gUnknown_203B0DC, 0);
                SpriteSetSize(&gUnknown_203B0DC, 0);
                SpriteSetX(&gUnknown_203B0DC, posX);
                SpriteSetY(&gUnknown_203B0DC, uVar7);
                break;
            case 8:
                SpriteSetShape(&gUnknown_203B0DC, 2);
                SpriteSetSize(&gUnknown_203B0DC, 0);
                SpriteSetX(&gUnknown_203B0DC, posX);
                SpriteSetY(&gUnknown_203B0DC, uVar7);
                break;
            case 2:
            case 3:
            case 6:
            case 7:
            case 9:
            case 10:
            case 11:
            case 13:
            case 15:
                SpriteSetShape(&gUnknown_203B0DC, 0);
                SpriteSetSize(&gUnknown_203B0DC, 1);
                SpriteSetX(&gUnknown_203B0DC, posX);
                SpriteSetY(&gUnknown_203B0DC, uVar7);
                break;
            case 0x10:
                SpriteSetShape(&gUnknown_203B0DC, 0);
                SpriteSetSize(&gUnknown_203B0DC, 1);
                SpriteSetX(&gUnknown_203B0DC, posX + 8);
                SpriteSetY(&gUnknown_203B0DC, uVar7);
                break;
            case 5:
                SpriteSetShape(&gUnknown_203B0DC, 1);
                SpriteSetSize(&gUnknown_203B0DC, 2);
                SpriteSetX(&gUnknown_203B0DC, posX);
                SpriteSetY(&gUnknown_203B0DC, uVar7);
                break;
            case 4:
                SpriteSetShape(&gUnknown_203B0DC, 0);
                SpriteSetSize(&gUnknown_203B0DC, 2);
                SpriteSetX(&gUnknown_203B0DC, posX);
                SpriteSetY(&gUnknown_203B0DC, posY);
                break;
        }
        SpriteSetTileNum(&gUnknown_203B0DC, vramIndex);
        SpriteSetPalNum(&gUnknown_203B0DC, sprite.palette);
        AddSprite(&gUnknown_203B0DC,(pos->y - posScreen->y) / 2 + 1,NULL,NULL);
    }
}

void LoadStatusGraphics(s32 graphicIndex, bool8 param_2)
{
    s32 frame;
    s32 size;
    s32 vramIndex;
    s32 offset;
    u8 *ptr;
    s32 graphicsCount;


    const struct StatusGraphicsInfo *graphic = &gStatusGraphics[graphicIndex];


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

void sub_800F7D0(DungeonPos *r0)
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

void AddPokemonDungeonSprite(s32 id, s16 species, DungeonPos *pos, u32 priority) {
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
    newSprite->priority = priority;
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
                 DungeonPos *statusOffsets, u32 priority)
{
    DungeonPokemonSprite *dSprite;

    if (gDungeonPokemonSprites == NULL)
        return;

    dSprite = GetDungeonPokemonSprite(dungeonSpriteID);
    if (dSprite == NULL)
        return;

    dSprite->pos = *pos;
    dSprite->priority = priority;
    dSprite->statusOffsets[0] = statusOffsets[0];
    dSprite->statusOffsets[1] = statusOffsets[3];
}
