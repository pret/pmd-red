#include "global.h"
#include "globaldata.h"
#include "dungeon_pokemon_sprites.h"
#include "structs/sprite_oam.h"
#include "graphics_memory.h"
#include "cpu.h"
#include "memory.h"
#include "sprite.h"
#include "constants/status.h"

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
    /* 0x20 */ DungeonPos unk20[2];
    /* 0x28 */ DungeonPokemonStatusSprite statusSprites[2];
    /* 0x38 */ u8 unk38;
    u16 fill3A;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
} DungeonPokemonSprite;

#define MAX_DUNGEON_POKEMON_SPRITES 22

// size: 0x584
typedef struct DungeonPokemonSprites
{
    /* 0x0 */ s32 frame;
    /* 0x4 */ DungeonPokemonSprite sprites[MAX_DUNGEON_POKEMON_SPRITES];
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

enum {
    STATUS_GFX_NONE,
    STATUS_GFX_SLEEPLESS,
    STATUS_GFX_BURNED,
    STATUS_GFX_POISONED,
    STATUS_GFX_FROZEN,
    STATUS_GFX_CONFUSED,
    STATUS_GFX_WHIFFER,
    STATUS_GFX_TAUNTED,
    STATUS_GFX_LOWHP,
    STATUS_GFX_SHIELD,
    STATUS_GFX_STATDOWN,
    STATUS_GFX_SWORD,
    STATUS_GFX_BLINKER,
    STATUS_GFX_CROSS_EYED,
    STATUS_GFX_EYEDROPS,
    STATUS_GFX_MUZZLED,
    STATUS_GFX_SLEEP,
};

#define TILE_SIZE_2BPP 32

static const struct StatusGraphicsInfo sStatusGfxInfo[] = {
    [STATUS_GFX_NONE]       = {0, 0, 0,  0,  0,  0},
    [STATUS_GFX_SLEEPLESS]  = {1, 1, 0,  0,  14, TILE_SIZE_2BPP * 0  },
    [STATUS_GFX_BURNED]     = {2, 2, 1,  0,  7,  TILE_SIZE_2BPP * 14 },
    [STATUS_GFX_POISONED]   = {2, 2, 5,  0,  16, TILE_SIZE_2BPP * 42 },
    [STATUS_GFX_FROZEN]     = {4, 4, 9,  0,  6,  TILE_SIZE_2BPP * 106},
    [STATUS_GFX_CONFUSED]   = {4, 2, 25, 0,  4,  TILE_SIZE_2BPP * 202},
    [STATUS_GFX_WHIFFER]    = {2, 2, 33, 0,  9,  TILE_SIZE_2BPP * 234},
    [STATUS_GFX_TAUNTED]    = {2, 2, 37, 0,  8,  TILE_SIZE_2BPP * 270},
    [STATUS_GFX_LOWHP]      = {1, 2, 41, 0,  8,  TILE_SIZE_2BPP * 302},
    [STATUS_GFX_SHIELD]     = {2, 2, 43, 0,  13, TILE_SIZE_2BPP * 318},
    [STATUS_GFX_STATDOWN]   = {2, 2, 47, 10, 10, TILE_SIZE_2BPP * 370},
    [STATUS_GFX_SWORD]      = {2, 2, 51, 0,  13, TILE_SIZE_2BPP * 410},
    [STATUS_GFX_BLINKER]    = {1, 1, 55, 0,  14, TILE_SIZE_2BPP * 462},
    [STATUS_GFX_CROSS_EYED] = {2, 2, 56, 0,  10, TILE_SIZE_2BPP * 476},
    [STATUS_GFX_EYEDROPS]   = {1, 1, 60, 0,  14, TILE_SIZE_2BPP * 516},
    [STATUS_GFX_MUZZLED]    = {2, 2, 61, 0,  8,  TILE_SIZE_2BPP * 530},
    [STATUS_GFX_SLEEP]      = {2, 2, 65, 4,  10, TILE_SIZE_2BPP * 562},
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
    u32 gfxIndex;
    u32 palIndex;
};

// + 1 because of how StatusSymbolBitToIndex operates
static const struct StatusSprite sStatusSpritesInfo[] = {
    [0] =                                   {STATUS_GFX_NONE, 0},
    [STATUS_SPRITE_ID_SLEEPLESS + 1] =      {STATUS_GFX_SLEEPLESS,  0},
    [STATUS_SPRITE_ID_BURNED + 1] =         {STATUS_GFX_BURNED,  0},
    [STATUS_SPRITE_ID_POISONED + 1] =       {STATUS_GFX_POISONED,  11},
    [STATUS_SPRITE_ID_BADLY_POISONED + 1] = {STATUS_GFX_POISONED,  7},
    [STATUS_SPRITE_ID_CONFUSED + 1] =       {STATUS_GFX_CONFUSED,  0},
    [STATUS_SPRITE_ID_COWERING + 1] =       {STATUS_GFX_WHIFFER,  0},
    [STATUS_SPRITE_ID_TAUNTED + 1] =        {STATUS_GFX_TAUNTED,  0},
    [STATUS_SPRITE_ID_ENCORE + 1] =         {STATUS_GFX_LOWHP,  0},
    [STATUS_SPRITE_ID_SHIELD_BLUE + 1] =    {STATUS_GFX_SHIELD,  0},
    [STATUS_SPRITE_ID_SHIELD_RED + 1] =     {STATUS_GFX_SHIELD,  4},
    [STATUS_SPRITE_ID_SHIELD_YELLOW + 1] =  {STATUS_GFX_SHIELD,  3},
    [STATUS_SPRITE_ID_SHIELD_GREEN + 1] =   {STATUS_GFX_SHIELD,  10},
    [STATUS_SPRITE_ID_ENDURE + 1] =         {STATUS_GFX_SHIELD,  5},
    [STATUS_SPRITE_ID_LOWHP + 1] =          {STATUS_GFX_LOWHP,  0},
    [STATUS_SPRITE_ID_CURSED + 1] =         {STATUS_GFX_POISONED,  6},
    [STATUS_SPRITE_ID_SNATCH + 1] =         {STATUS_GFX_LOWHP,  3},
    [STATUS_SPRITE_ID_SURE_SHOT + 1] =      {STATUS_GFX_SWORD, 0},
    [STATUS_SPRITE_ID_WHIFFER + 1] =        {STATUS_GFX_WHIFFER,  10},
    [STATUS_SPRITE_ID_SET_DAMAGE + 1] =     {STATUS_GFX_SWORD, 5},
    [STATUS_SPRITE_ID_FOCUS_ENERGY + 1] =   {STATUS_GFX_SWORD, 4},
    [STATUS_SPRITE_ID_BLINKER + 1] =        {STATUS_GFX_BLINKER, 0},
    [STATUS_SPRITE_ID_CROSS_EYED + 1] =     {STATUS_GFX_CROSS_EYED, 0},
    [STATUS_SPRITE_ID_EYEDROPS + 1] =       {STATUS_GFX_EYEDROPS, 0},
    [STATUS_SPRITE_ID_MUZZLED + 1] =        {STATUS_GFX_MUZZLED, 0},
    [STATUS_SPRITE_ID_GRUDGE + 1] =         {STATUS_GFX_SHIELD,  7},
    [STATUS_SPRITE_ID_EXPOSED + 1] =        {STATUS_GFX_EYEDROPS, 4},
    [STATUS_SPRITE_ID_SLEEP + 1] =          {STATUS_GFX_SLEEP, 4},
    [STATUS_SPRITE_ID_STAT_DOWN + 1] =      {STATUS_GFX_STATDOWN, 3},
    [STATUS_SPRITE_ID_FROZEN + 1] =         {STATUS_GFX_FROZEN,  0},
};

static EWRAM_INIT DungeonPokemonSprites *sDungeonPokemonSprites = NULL;
static EWRAM_INIT SpriteOAM sStatusSpriteOAM = {0};

static void DrawStatusSprite(s16 param_1,s32 status,DungeonPos *pos,DungeonPos *posOffset, DungeonPos *posScreen,u32 priority, u32 unused);

static DungeonPokemonSprite *GetSpriteById(s32 id)
{
    s32 i;

    for (i = 0; i < MAX_DUNGEON_POKEMON_SPRITES; i++) {
        if (sDungeonPokemonSprites->sprites[i].exists && sDungeonPokemonSprites->sprites[i].id == id) {
            return &sDungeonPokemonSprites->sprites[i];
        }
    }

    return NULL;
}

static DungeonPokemonSprite *GetFirstFreeSlot(void)
{
    s32 i;

    for (i = 0; i < MAX_DUNGEON_POKEMON_SPRITES; i++) {
        if (!sDungeonPokemonSprites->sprites[i].exists) {
            return &sDungeonPokemonSprites->sprites[i];
        }
    }
    return NULL;
}

static u32 GetNextStatusSymbol(DungeonPokemonSprite *sprite, s32 statusIndex)
{
    u32 bits;
    u32 status;
    s32 i;
    s32 n;
    u32 lastBit;
    u32 secondLastBit;
    DungeonPokemonStatusSprite *statusSprite;

    statusSprite = &sprite->statusSprites[statusIndex];
    lastBit = (1 << STATUS_SPRITE_ID_LAST);
    if (statusIndex == 0) {
        lastBit = 1;
    }
    secondLastBit = (1 << STATUS_SPRITE_ID_LAST);
    if (statusIndex == 0) {
        secondLastBit = (1 << (STATUS_SPRITE_ID_LAST - 1));
    }
    n = 1;
    if (statusIndex == 0) {
        n = STATUS_SPRITE_ID_LAST;
    }
    if (sprite->status == 0) {
        return 0;
    }

    status = statusSprite->status;
    bits = lastBit;
    if (status != 0) {
        bits = status;
    }

    for (i = 0; i < n; i++) {
        bits <<= 1;
        if (bits > secondLastBit) {
            bits = lastBit;
        }
        if (sprite->status & bits) {
            return bits;
        }
    }
    return 0;
}

static u32 StatusSymbolBitToIndex(u32 statusBit)
{
    u32 index = 0;
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

#define STATUS_GFX_VRAM_INDEX 0x32B

static void DrawStatusSprite(s16 species, s32 status, DungeonPos *pos, DungeonPos *posOffset, DungeonPos *posScreen, u32 priority, u32 unused)
{
    s32 posX, posY;
    s32 ySubbed;
    struct StatusSprite spriteInfo = sStatusSpritesInfo[status];
    const struct StatusGraphicsInfo *gfxInfo = &sStatusGfxInfo[spriteInfo.gfxIndex];
    s32 vramIndex = (gfxInfo->vramIndex + STATUS_GFX_VRAM_INDEX);

    SpriteSetPriority(&sStatusSpriteOAM, priority);
    posX = (pos->x - gfxInfo->width  * 4 - posScreen->x) + posOffset->x;
    posY = (pos->y - gfxInfo->height * 4 - posScreen->y) + posOffset->y;
    ySubbed = posY - 16;
    if (posX >= -32 && posY >= -32 && posX < 240 && posY < 160) {
        switch (spriteInfo.gfxIndex) {
            case STATUS_GFX_SLEEPLESS:
            case STATUS_GFX_BLINKER:
            case STATUS_GFX_EYEDROPS:
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 0);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, ySubbed);
                break;
            case STATUS_GFX_LOWHP:
                SpriteSetShape(&sStatusSpriteOAM, 2);
                SpriteSetSize(&sStatusSpriteOAM, 0);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, ySubbed);
                break;
            case STATUS_GFX_BURNED:
            case STATUS_GFX_POISONED:
            case STATUS_GFX_WHIFFER:
            case STATUS_GFX_TAUNTED:
            case STATUS_GFX_SHIELD:
            case STATUS_GFX_STATDOWN:
            case STATUS_GFX_SWORD:
            case STATUS_GFX_CROSS_EYED:
            case STATUS_GFX_MUZZLED:
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 1);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, ySubbed);
                break;
            case STATUS_GFX_SLEEP:
                SpriteSetShape(&sStatusSpriteOAM, 0);
                SpriteSetSize(&sStatusSpriteOAM, 1);
                SpriteSetX(&sStatusSpriteOAM, posX + 8);
                SpriteSetY(&sStatusSpriteOAM, ySubbed);
                break;
            case STATUS_GFX_CONFUSED:
                SpriteSetShape(&sStatusSpriteOAM, 1);
                SpriteSetSize(&sStatusSpriteOAM, 2);
                SpriteSetX(&sStatusSpriteOAM, posX);
                SpriteSetY(&sStatusSpriteOAM, ySubbed);
                break;
            case STATUS_GFX_FROZEN:
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
    const struct StatusGraphicsInfo *gfxInfo = &sStatusGfxInfo[graphicIndex];
    s32 offset = gfxInfo->offsetIntoGraphic;
    s32 graphicsCount = gfxInfo->graphicsCount;
    s32 size = gfxInfo->width  * gfxInfo->height * 32;
    s32 vramIndex = (gfxInfo->vramIndex + STATUS_GFX_VRAM_INDEX) * 32;
    s32 frame = (sDungeonPokemonSprites->frame / 4) % graphicsCount;
    const u8 *ptr = sStatusGfx + offset + (frame * size);

    if (queueLoad) {
        ScheduleMemCopy((void *)(VRAM + 0x10000 + vramIndex), (void *)ptr, size);
    }
    else {
        CpuCopy((void *)(VRAM + 0x10000 + vramIndex), ptr, size);
    }
}

void InitDungeonPokemonSprites(void)
{
    if (sDungeonPokemonSprites == NULL) {
        sDungeonPokemonSprites = MemoryAlloc(sizeof(DungeonPokemonSprites),12);
        MemoryClear8(sDungeonPokemonSprites,sizeof(DungeonPokemonSprites));
    }
    sDungeonPokemonSprites->frame = 0;
    LoadStatusGraphics(STATUS_GFX_SLEEPLESS,FALSE);
    LoadStatusGraphics(STATUS_GFX_BURNED,FALSE);
    LoadStatusGraphics(STATUS_GFX_POISONED,FALSE);
    LoadStatusGraphics(STATUS_GFX_FROZEN,FALSE);
    LoadStatusGraphics(STATUS_GFX_CONFUSED,FALSE);
    LoadStatusGraphics(STATUS_GFX_WHIFFER,FALSE);
    LoadStatusGraphics(STATUS_GFX_TAUNTED,FALSE);
    LoadStatusGraphics(STATUS_GFX_LOWHP,FALSE);
    LoadStatusGraphics(STATUS_GFX_SHIELD,FALSE);
    LoadStatusGraphics(STATUS_GFX_STATDOWN,FALSE);
    LoadStatusGraphics(STATUS_GFX_SWORD,FALSE);
    LoadStatusGraphics(STATUS_GFX_BLINKER,FALSE);
    LoadStatusGraphics(STATUS_GFX_CROSS_EYED,FALSE);
    LoadStatusGraphics(STATUS_GFX_EYEDROPS,FALSE);
    LoadStatusGraphics(STATUS_GFX_MUZZLED,FALSE);
    LoadStatusGraphics(STATUS_GFX_SLEEP,FALSE);
}

void FreeDungeonPokemonSprites(void)
{
    TRY_FREE_AND_SET_NULL(sDungeonPokemonSprites);
}

void UpdateDungeonPokemonSprite(s32 dungeonSpriteId, s32 species_, s32 status, u32 visible_)
{
    s32 species = (s16) species_;
    u32 visible = (u8) visible_;

    if (sDungeonPokemonSprites != NULL) {
        DungeonPokemonSprite *sprite = GetSpriteById(dungeonSpriteId);
        if (sprite != NULL) {
            sprite->species = species;
            sprite->status = status;
            sprite->visible = visible;
            sprite->unk38 = 0;
        }
    }
}

UNUSED static void sub_800F794(s32 id, s32 r1, s32 r2, s32 r3, DungeonPos *statusOffsets)
{
    if (sDungeonPokemonSprites != NULL) {
        DungeonPokemonSprite *sprite = GetSpriteById(id);
        if (sprite != NULL) {
            sprite->unk38 = 1;
            sprite->unk3C = r2;
            sprite->unk3E = r3;
            sprite->unk20[0] = statusOffsets[0];
            sprite->unk20[1] = statusOffsets[3];
        }
    }
}

void FrameUpdateDungeonStatusSprites(DungeonPos *screenPos)
{
    s32 i;

    if (sDungeonPokemonSprites == NULL)
        return;

    switch (sDungeonPokemonSprites->frame % 4) {
        case 0:
            LoadStatusGraphics(STATUS_GFX_SLEEPLESS, TRUE);
            LoadStatusGraphics(STATUS_GFX_BURNED, TRUE);
            LoadStatusGraphics(STATUS_GFX_POISONED, TRUE);
            LoadStatusGraphics(STATUS_GFX_FROZEN, TRUE);
            break;
        case 1:
            LoadStatusGraphics(STATUS_GFX_CONFUSED, TRUE);
            LoadStatusGraphics(STATUS_GFX_WHIFFER, TRUE);
            LoadStatusGraphics(STATUS_GFX_TAUNTED, TRUE);
            LoadStatusGraphics(STATUS_GFX_LOWHP, TRUE);
            break;
        case 2:
            LoadStatusGraphics(STATUS_GFX_SHIELD, TRUE);
            LoadStatusGraphics(STATUS_GFX_STATDOWN, TRUE);
            LoadStatusGraphics(STATUS_GFX_SWORD, TRUE);
            LoadStatusGraphics(STATUS_GFX_BLINKER, TRUE);
            break;
        case 3:
            LoadStatusGraphics(STATUS_GFX_CROSS_EYED, TRUE);
            LoadStatusGraphics(STATUS_GFX_EYEDROPS, TRUE);
            LoadStatusGraphics(STATUS_GFX_MUZZLED, TRUE);
            LoadStatusGraphics(STATUS_GFX_SLEEP, TRUE);
            break;
    }

    for (i = 0; i < MAX_DUNGEON_POKEMON_SPRITES; i++) {
        if (sDungeonPokemonSprites->sprites[i].exists) {
            DungeonPokemonSprite *spritePtr = &sDungeonPokemonSprites->sprites[i];
            UpdateStatusSprite(spritePtr, 0, screenPos);
            UpdateStatusSprite(spritePtr, 1, screenPos);
        }
    }
    sDungeonPokemonSprites->frame++;
}

void AddPokemonDungeonSprite(s32 dungeonSpriteId, s32 species_, DungeonPos *pos, u32 priority)
{
    static const DungeonPos posZero = {0, 0};
    DungeonPokemonSprite *newSprite;
    s32 species = (s16) species_;

    if (sDungeonPokemonSprites == NULL)
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

    if (sDungeonPokemonSprites == NULL)
        return;

    dSprite = GetSpriteById(dungeonSpriteId);
    if (dSprite == NULL)
        return;

    MemoryClear8(dSprite, sizeof(*dSprite));
}

void UpdateDungeonPokemonSprite2(s32 dungeonSpriteId, DungeonPos *pos, DungeonPos *statusOffsets, u32 priority)
{
    if (sDungeonPokemonSprites != NULL) {
        DungeonPokemonSprite *sprite = GetSpriteById(dungeonSpriteId);
        if (sprite != NULL) {
            sprite->pos = *pos;
            sprite->priority = priority;
            sprite->statusOffsets[0] = statusOffsets[0];
            sprite->statusOffsets[1] = statusOffsets[3];
        }
    }
}
