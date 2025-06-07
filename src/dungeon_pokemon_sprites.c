#include "global.h"
#include "globaldata.h"
#include "dungeon_pokemon_sprites.h"
#include "structs/sprite_oam.h"
#include "code_8009804.h"
#include "cpu.h"
#include "memory.h"
#include "sprite.h"

// size: 0x8
typedef struct DungeonPokemonStatusSprite
{
    /* 0x0 */ u32 status;
    /* 0x4 */ s32 frame;
} DungeonPokemonStatusSprite;

// size: 0x40
typedef struct DungeonPokemonSprite
{
    /* 0x0 */ bool8 exists;
    /* 0x4 */ u32 id;
    /* 0x8 */ u16 species; // Or sprite ID?
    /* 0xA */ u16 unkA;
    /* 0xC */ u32 status;
    /* 0x10 */ u8 visible;
    /* 0x11 */ u8 priority;
    /* 0x14 */ DungeonPos pos;
    /* 0x18 */ DungeonPos statusOffsets[2];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ DungeonPokemonStatusSprite statusSprites[2];
    /* 0x38 */ u8 unk38;
    u16 fill3A;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
} DungeonPokemonSprite;

#define MAX_DUNGEON_SPRITES 22

// size: 0x584
typedef struct DungeonPokemonSprites
{
    /* 0x0 */ s32 frame;
    /* 0x4 */ DungeonPokemonSprite sprites[MAX_DUNGEON_SPRITES];
} DungeonPokemonSprites;

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

static const u8 sStatusGfx[] = INCBIN_U8("graphics/status/sleepless.4bpp",
                                        "graphics/status/burned.4bpp",
                                        "graphics/status/poisoned.4bpp",
                                        "graphics/status/frozen.4bpp",
                                        "graphics/status/confused.4bpp",
                                        "graphics/status/whiffer.4bpp",
                                        "graphics/status/taunted.4bpp",
                                        "graphics/status/lowhp.4bpp",
                                        "graphics/status/shield.4bpp",
                                        "graphics/status/statdown.4bpp",
                                        "graphics/status/sword.4bpp",
                                        "graphics/status/blinker.4bpp",
                                        "graphics/status/cross_eyed.4bpp",
                                        "graphics/status/eyedrops.4bpp",
                                        "graphics/status/muzzled.4bpp",
                                        "graphics/status/sleep.4bpp");

struct StatusSprite
{
    u32 image;
    u32 palIndex;
};

static const struct StatusSprite sStatusSpritesInfo[] = {
    [0] = {0, 0},
    [1] = {1,  0},
    [2] = {2,  0},
    [3] = {3,  11},
    [4] = {3,  7},
    [5] = {5,  0},
    [6] = {6,  0},
    [7] = {7,  0},
    [8] = {8,  0},
    [9] = {9,  0},
    [10] = {9,  4},
    [11] = {9,  3},
    [12] = {9,  10},
    [13] = {9,  5},
    [14] = {8,  0},
    [15] = {3,  6},
    [16] = {8,  3},
    [17] = {11, 0},
    [18] = {6,  10},
    [19] = {11, 5},
    [20] = {11, 4},
    [21] = {12, 0},
    [22] = {13, 0},
    [23] = {14, 0},
    [24] = {15, 0},
    [25] = {9,  7},
    [26] = {14, 4},
    [27] = {16, 4},
    [28] = {10, 3},
    [29] = {4,  0},
};

EWRAM_INIT DungeonPokemonSprites *gDungeonPokemonSprites = NULL;
EWRAM_INIT SpriteOAM sStatusSpriteOAM = {0};

static void DrawStatusSprite(s16 param_1,s32 status,DungeonPos *pos,DungeonPos *posOffset, DungeonPos *posScreen,u32 priority, u32 unused);

static DungeonPokemonSprite *GetSpriteById(s32 id)
{
    s32 i;

    for (i = 0; i < MAX_DUNGEON_SPRITES; i++) {
        if (gDungeonPokemonSprites->sprites[i].exists && gDungeonPokemonSprites->sprites[i].id == id) {
            return &gDungeonPokemonSprites->sprites[i];
        }
    }

    return NULL;
}

static DungeonPokemonSprite *GetFirstFreeSlot(void)
{
    s32 i;

    for (i = 0; i < MAX_DUNGEON_SPRITES; i++) {
        if (!gDungeonPokemonSprites->sprites[i].exists) {
            return &gDungeonPokemonSprites->sprites[i];
        }
    }
    return NULL;
}

static u32 GetNextStatusSymbol(DungeonPokemonSprite *sprite, s32 statusIndex)
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

static u32 StatusSymbolBitToIndex(u32 statusBit)
{
  u32 index;

  index = 0;
  while (statusBit != 0) {
      statusBit >>= 1;
      index++;
  }
  return index;
}

static void UpdateStatusSprite(DungeonPokemonSprite *sprite, s32 index, DungeonPos *screenPos)
{
    DungeonPokemonStatusSprite *statusSprite = &sprite->statusSprites[index];

    if (sprite->status == 0) {
        statusSprite->status = 0;
    }
    else {
        u32 newFrame;

        if (statusSprite->status == 0) {
            statusSprite->frame = 0;
        }
        if (statusSprite->frame < 1) {
            u32 statusSymbol = GetNextStatusSymbol(sprite,index);
            if (statusSprite->status != statusSymbol) {
                statusSprite->status = statusSymbol;
            }
            newFrame = 60;
        }
        else {
            newFrame = statusSprite->frame - 1;
        }
        statusSprite->frame = newFrame;
        if (sprite->visible && statusSprite->status != 0) {
            DrawStatusSprite(sprite->species,StatusSymbolBitToIndex(statusSprite->status),&sprite->pos,
                             &sprite->statusOffsets[index],screenPos,sprite->priority, sprite->id);
        }
    }
}

static void DrawStatusSprite(s16 species, s32 status, DungeonPos *pos, DungeonPos *posOffset, DungeonPos *posScreen, u32 priority, u32 unused)
{
    struct StatusSprite spriteInfo;
    s32 posY;
    s32 posX;
    u32 uVar7;
    s32 vramIndex;
    const struct StatusGraphicsInfo *ptr;

    spriteInfo = sStatusSpritesInfo[status];
    ptr = &gStatusGraphics[spriteInfo.image];
    vramIndex = (ptr->vramIndex + 0x32b);
    SpriteSetPriority(&sStatusSpriteOAM, priority);

    posX = (pos->x - ptr->width  * 4 - posScreen->x) + posOffset->x;
    posY = (pos->y - ptr->height * 4 - posScreen->y) + posOffset->y;
    uVar7 = posY - 16;
    if ((((-0x20 <= posX) && (-0x20 <= posY)) && (posX < 0xf0)) && (posY < 0xa0)) {
        switch(spriteInfo.image) {
            case 1:
            case 0xc:
            case 0xe:
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 0);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, uVar7);
                break;
            case 8:
                SpriteSetShape(&sStatusSpriteOAM, 2);
                SpriteSetSize(&sStatusSpriteOAM, 0);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, uVar7);
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
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 1);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, uVar7);
                break;
            case 0x10:
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 1);
                SpriteSetX(&sStatusSpriteOAM, posX + 8);
                SpriteSetY(&sStatusSpriteOAM, uVar7);
                break;
            case 5:
                SpriteSetShape(&sStatusSpriteOAM, 1);
                SpriteSetSize(&sStatusSpriteOAM, 2);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, uVar7);
                break;
            case 4:
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 2);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, posY);
                break;
        }
        SpriteSetTileNum(&sStatusSpriteOAM, vramIndex);
        SpriteSetPalNum(&sStatusSpriteOAM, spriteInfo.palIndex);
        AddSprite(&sStatusSpriteOAM,(pos->y - posScreen->y) / 2 + 1,NULL,NULL);
    }
}

static void LoadStatusGraphics(s32 graphicIndex, bool8 queueLoad)
{
    const struct StatusGraphicsInfo *graphic = &gStatusGraphics[graphicIndex];
    s32 offset = graphic->offsetIntoGraphic;
    s32 graphicsCount = graphic->graphicsCount;
    s32 size = graphic->width  * graphic->height * 0x20;
    s32 vramIndex = (graphic->vramIndex + 0x32b) * 0x20;
    s32 frame = (gDungeonPokemonSprites->frame / 4) % graphicsCount;
    const u8 *ptr = sStatusGfx + offset + (frame * size);

    if (queueLoad) {
        sub_80098BC((void *)(VRAM + 0x10000 + vramIndex), (void *)ptr, size);
    }
    else {
        CpuCopy((void *)(VRAM + 0x10000 + vramIndex), ptr, size);
    }
}

void InitDungeonPokemonSprites(void)
{
    if (gDungeonPokemonSprites == NULL) {
        gDungeonPokemonSprites = MemoryAlloc(sizeof(DungeonPokemonSprites),0xc);
        MemoryClear8(gDungeonPokemonSprites,sizeof(DungeonPokemonSprites));
    }
    gDungeonPokemonSprites->frame = 0;
    LoadStatusGraphics(1,FALSE);
    LoadStatusGraphics(2,FALSE);
    LoadStatusGraphics(3,FALSE);
    LoadStatusGraphics(4,FALSE);
    LoadStatusGraphics(5,FALSE);
    LoadStatusGraphics(6,FALSE);
    LoadStatusGraphics(7,FALSE);
    LoadStatusGraphics(8,FALSE);
    LoadStatusGraphics(9,FALSE);
    LoadStatusGraphics(10,FALSE);
    LoadStatusGraphics(0xb,FALSE);
    LoadStatusGraphics(0xc,FALSE);
    LoadStatusGraphics(0xd,FALSE);
    LoadStatusGraphics(0xe,FALSE);
    LoadStatusGraphics(0xf,FALSE);
    LoadStatusGraphics(0x10,FALSE);
}

void FreeDungeonPokemonSprites(void)
{
    TRY_FREE_AND_SET_NULL(gDungeonPokemonSprites);
}

void UpdateDungeonPokemonSprite(s32 dungeonSpriteId, s32 species_, s32 status, u32 visible_)
{
    s32 species = (s16) species_;
    u32 visible = (u8) visible_;

    if (gDungeonPokemonSprites != NULL) {
        DungeonPokemonSprite *sprite = GetSpriteById(dungeonSpriteId);
        if (sprite != NULL) {
            sprite->species = species;
            sprite->status = status;
            sprite->visible = visible;
            sprite->unk38 = 0;
        }
    }
}

UNUSED static void sub_800F794(s32 id, s32 r1, s32 r2, s32 r3, s32 *r4)
{
    if (gDungeonPokemonSprites != NULL) {
        DungeonPokemonSprite *sprite = GetSpriteById(id);
        if (sprite != NULL) {
            sprite->unk38 = 1;
            sprite->unk3C = r2;
            sprite->unk3E = r3;
            sprite->unk20 = r4[0];
            sprite->unk24 = r4[3];
        }
    }
}

void FrameUpdateDungeonStatusSprites(DungeonPos *screenPos)
{
    s32 i;

    if (gDungeonPokemonSprites == NULL)
        return;

    switch (gDungeonPokemonSprites->frame % 4) {
        case 0:
            LoadStatusGraphics(1, TRUE);
            LoadStatusGraphics(2, TRUE);
            LoadStatusGraphics(3, TRUE);
            LoadStatusGraphics(4, TRUE);
            break;
        case 1:
            LoadStatusGraphics(5, TRUE);
            LoadStatusGraphics(6, TRUE);
            LoadStatusGraphics(7, TRUE);
            LoadStatusGraphics(8, TRUE);
            break;
        case 2:
            LoadStatusGraphics(9, TRUE);
            LoadStatusGraphics(0xA, TRUE);
            LoadStatusGraphics(0xB, TRUE);
            LoadStatusGraphics(0xC, TRUE);
            break;
        case 3:
            LoadStatusGraphics(0xD, TRUE);
            LoadStatusGraphics(0xE, TRUE);
            LoadStatusGraphics(0xF, TRUE);
            LoadStatusGraphics(0x10, TRUE);
            break;
    }

    for (i = 0; i < MAX_DUNGEON_SPRITES; i++) {
        if (gDungeonPokemonSprites->sprites[i].exists) {
            DungeonPokemonSprite *spritePtr = &gDungeonPokemonSprites->sprites[i];
            UpdateStatusSprite(spritePtr, 0, screenPos);
            UpdateStatusSprite(spritePtr, 1, screenPos);
        }
    }
    gDungeonPokemonSprites->frame++;
}

void AddPokemonDungeonSprite(s32 dungeonSpriteId, s32 species_, DungeonPos *pos, u32 priority)
{
    static const DungeonPos posZero = {0, 0};
    DungeonPokemonSprite *newSprite;
    s32 species = (s16) species_;

    if (gDungeonPokemonSprites == NULL)
        return;
    if (GetSpriteById(dungeonSpriteId) != NULL)
        return;

    newSprite = GetFirstFreeSlot();
    if (newSprite == NULL)
        return;

    newSprite->exists = TRUE;
    newSprite->id = dungeonSpriteId;
    newSprite->species = species;
    newSprite->status = 0;
    newSprite->pos = *pos;
    newSprite->priority = priority;
    newSprite->statusOffsets[0] = newSprite->statusOffsets[1] = posZero;
    newSprite->statusSprites[0].status = 0;
    newSprite->statusSprites[0].frame = 0;
    newSprite->statusSprites[1].status = 0;
    newSprite->statusSprites[1].frame = 0;
}

void DeletePokemonDungeonSprite(s32 dungeonSpriteId)
{
    DungeonPokemonSprite *dSprite;

    if (gDungeonPokemonSprites == NULL)
        return;

    dSprite = GetSpriteById(dungeonSpriteId);
    if (dSprite == NULL)
        return;

    MemoryClear8(dSprite, sizeof(*dSprite));
}

void UpdateDungeonPokemonSprite2(s32 dungeonSpriteId, DungeonPos *pos, DungeonPos *statusOffsets, u32 priority)
{
    if (gDungeonPokemonSprites != NULL) {
        DungeonPokemonSprite *sprite = GetSpriteById(dungeonSpriteId);
        if (sprite != NULL) {
            sprite->pos = *pos;
            sprite->priority = priority;
            sprite->statusOffsets[0] = statusOffsets[0];
            sprite->statusOffsets[1] = statusOffsets[3];
        }
    }
}
