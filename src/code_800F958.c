#include "global.h"
#include "code_800F958.h"
#include "code_8004AA0.h"
#include "code_8009804.h"
#include "code_800E9E4.h"
#include "code_801EE10.h"
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
extern struct StatusGraphicsInfo gStatusGraphics[]; // 0x80CE79C

struct StatusSprite
{
    u32 image;
    u32 palette;
};
extern struct StatusSprite gStatusSprites[8];

struct unkStruct_800F18C
{
    s32 effectID;
    u32 counter;
};

struct unkStruct_203B0D4
{
    struct unkStruct_800F18C unk0[2];
};

struct unkStruct_203B0D4 *gUnknown_203B0D4;
extern SpriteOAM gUnknown_203B0DC;

extern u8 *gStatusGraphics4bpp[]; // TODO use INCBIN_U8
extern DungeonPos gUnknown_80D3564;

void DrawStatusSprite(s16 param_1,s32 status,DungeonPos *pos,DungeonPos *posOffset,
                      DungeonPos *posScreen,u32 priority, u32 unused);

extern u8 gUnknown_80CE77C[];
extern u8 gUnknown_80CE788[];

extern struct FileArchive gEffectFileArchive;

void sub_800F034(void) {
    s32 index;
    if(gUnknown_203B0D4 == NULL)
    {
        gUnknown_203B0D4 = MemoryAlloc(sizeof(struct unkStruct_203B0D4), 0xB);
        MemoryClear8(gUnknown_203B0D4, sizeof(struct unkStruct_203B0D4));
    }
    for(index = 0; index < 2; index++)
    {
        gUnknown_203B0D4->unk0[index].effectID = -1;
        gUnknown_203B0D4->unk0[index].counter = 0;
    }
}

void sub_800F078(void)
{
    if(gUnknown_203B0D4)
    {
        MemoryFree(gUnknown_203B0D4);
        gUnknown_203B0D4 = NULL;
    }
}

void sub_800F094(void)
{
    s32 index;
    for(index = 0; index < 2; index++)
    {
        gUnknown_203B0D4->unk0[index].effectID = -1;
        gUnknown_203B0D4->unk0[index].counter = 0;
    }     
}

s32 sub_800F0C0(s32 animType, s32 effectID)
{
    if (animType == 3) {
        if (gUnknown_203B0D4->unk0[0].effectID == effectID) return 0;
    }
    else {
        if (gUnknown_203B0D4->unk0[1].effectID == effectID) return 1;
    }
    return -3;
}


s32 sub_800F0F4(s32 animType, s32 effectID)
{
    if (animType == 3) {
        if (gUnknown_203B0D4->unk0[0].effectID == effectID) return -2;
        if (gUnknown_203B0D4->unk0[0].counter == 0) return 0;
    }
    else {
        if (gUnknown_203B0D4->unk0[1].effectID == effectID) return -2;
        if (gUnknown_203B0D4->unk0[1].counter == 0) return 1;
    }
    return -1;
}

void sub_800F13C(s32 index, OpenedFile *file, unkStruct_80B9CC4 * r2) 
{
    if(gUnknown_203B0D4->unk0[index].counter == 0)
        gUnknown_203B0D4->unk0[index].effectID = r2->effectId;
}

void sub_800F15C(s32 effectID)
{
    s32 index;

    for(index = 0; index < 2; index++)
    {
        if(gUnknown_203B0D4->unk0[index].effectID == effectID)
        {
            gUnknown_203B0D4->unk0[index].counter++;
            break;
        }
    }
}

struct unkStruct_800F18C *sub_800F18C(s32 index) 
{
   return &gUnknown_203B0D4->unk0[index]; 
}

s32 sub_800F19C(s32 index)
{
    if(gUnknown_203B0D4->unk0[index].counter == 0)
        return 0;
    else
        return 1;
}

OpenedFile * sub_800F1C0(u32 animType, s32 effectID)
{
    u8 fileName [8];

    switch(animType)
    {
        case 1:
        case 2:
        case 3:
            sprintf(fileName,gUnknown_80CE77C,effectID); // efob
            break;
        case 4:
            sprintf(fileName,gUnknown_80CE788,effectID); // efbg
            break;

    }
    return Call_OpenFileAndGetFileDataPtr(fileName,&gEffectFileArchive);
}

void sub_800F204(OpenedFile *file)
{
    CloseFile(file); 
}

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
    struct StatusGraphicsInfo *ptr;

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
