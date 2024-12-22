#include "global.h"
#include "cpu.h"
#include "random.h"
#include "sprite.h"

static EWRAM_DATA u16 sOAMSpriteCount = {0}; // 2025670 Written to but never read
static EWRAM_DATA s16 sUnknown_2025672[8] = {0};
static EWRAM_DATA s16 sUnknown_2025682[9] = {0};
static EWRAM_DATA DungeonPos sUnknown_2025694 = {0};
static EWRAM_DATA u32 sUnknown_2025698 = {0};
UNUSED static EWRAM_DATA u32 sUnused1 = {0}; // 202569C
static EWRAM_DATA SpriteList sUnknown_20256A0 = {0};
static EWRAM_DATA UnkSpriteLink sUnknown_2025EA8[128] = {0};
static EWRAM_DATA SpriteOAM sUnknown_20262A8[128] = {0};
static EWRAM_DATA s32 sSpriteCount = {0}; // 20266A8
UNUSED static EWRAM_DATA u32 sUnused2 = {0}; // 20266AC

#define UNK_20266B0_ARR_COUNT 160
static EWRAM_DATA unkStruct_20266B0 sUnknown_20266B0[UNK_20266B0_ARR_COUNT] = {0};

static EWRAM_DATA void *sCharMemCursor = {0}; // 2026E30
UNUSED static EWRAM_DATA u32 sUnused3 = {0}; // 2026E34

static EWRAM_INIT unkStruct_20266B0 *sUnknown_203B074 = {0};

// code.c
extern void nullsub_3(s32, s32);

static void RegisterSpriteParts_80052BC(UnkSpriteMem *);
static void AxResInitUnoriented(axdata *, axmain *, u32, u32, u32, bool8);

void InitSprites(void)
{
    ResetSprites(TRUE);
    SetSavingIconCoords(NULL);
}

void ResetSprites(bool8 a0)
{
    s32 i;
    UnkSpriteLink *a;
    UnkSpriteLink *b;
    SpriteOAM *c;
    SpriteOAM *d;
    UnkSpriteLink *e;

    sSpriteCount = 0;
    sCharMemCursor = OBJ_VRAM0;
    sUnknown_203B074 = &sUnknown_20266B0[0];

    a = &sUnknown_20256A0.sprites[0];
    b = a + 1;

    // 16 loops, very smart
    for (i = 0; i < 256; i += 16) {
        c = NULL;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
        a->unk0 = b;
        a->unk4 = c;
        a++;
        b++;
    }

    if (a0) {
        e = NULL;
        d = &sUnknown_20262A8[0];
        a = &sUnknown_2025EA8[0];
        for (i = 0; i < 128; i++) {
            a->unk0 = e;
            a->unk4 = d;
            d++;
            a++;
        }
    }

    sUnknown_20256A0.unk800 = 0;
    sUnknown_20256A0.unk804 = 0;
}

void sub_8004E8C(unkStruct_2039DB0 *a0)
{
    a0->unk0 = 0xFFFF;
    a0->unk2 = 0xFFFF;
    a0->unk4 = 0xFFFF;
    a0->unk6 = 0;
    a0->unk8 = 0;
    a0->unkA = 0;
}

// Needed to match AddAxSprite and AddAxSprite. These macros assume SpriteOAM struct has size of 8
#define SpriteCopy(_dst, _src)          \
{                                       \
    u16 *_dstVar = (void *) _dst;       \
    u16 *_srcVar = (void *) _src;       \
                                        \
    *(_dstVar++) = *(_srcVar++);        \
    *(_dstVar++) = *(_srcVar++);        \
    *(_dstVar++) = *(_srcVar++);        \
    *(_dstVar++) = *(_srcVar++);        \
}

#define SpriteCopyWithMasks(_dst, _src, _spriteMasks)                           \
{                                                                               \
    u16 *_dstVar = (void *) _dst;                                               \
    u16 *_srcVar = (void *) _src;                                               \
                                                                                \
    *(_dstVar++) = (*(_srcVar++) & _spriteMasks->unk0) | _spriteMasks->unk6;    \
    *(_dstVar++) = (*(_srcVar++) & _spriteMasks->unk2) | _spriteMasks->unk8;    \
    *(_dstVar++) = (*(_srcVar++) & _spriteMasks->unk4) | _spriteMasks->unkA;    \
    *(_dstVar++) = *(_srcVar++);                                                \
}

void AddAxSprite(ax_pose *a0, axdata1 *a1, UnkSpriteMem *a2, unkStruct_2039DB0 *spriteMasks)
{
    // size: 0xC
    struct UnkStackFor8004EA8
    {
        s16 unk0;
        ax_pose_unk2 unk2;
        SpriteOAM oam;
    } sp;
    SpriteOAM *sprite;
    s32 spriteId;
    s32 pos; // Has to be used for both x and y to match
    struct UnkStackFor8004EA8 *spPtr;

    if (a2 != NULL)
        RegisterSpriteParts_80052BC(a2);

    if (sSpriteCount >= 128)
        return;

    spPtr = &sp;
    spPtr->unk0 = a0->sprite;
    spPtr->unk2 = a0->unk2;

    spPtr->oam.attrib1 = a0->flags1 & ~(0x100 | 0x200);
    spPtr->oam.attrib2 = a0->flags2 & ~(0x200 | 0x400 | 0x800);
    spPtr->oam.attrib3 = a0->flags3;
    spPtr->oam.unk6 = ((a0->flags2 & (0x200 | 0x400 | 0x800)) >> 9) | ((a0->flags1 & (0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20 | 0x40 | 0x80 | 0x100 | 0x200)) << 4);
    sprite = &sUnknown_20262A8[sSpriteCount];
    spriteId = a1->unk16 + sp.unk2.unk1;

    if (spriteId < 0)
        spriteId = 0;
    if (spriteId > 255)
        spriteId = 255;

    if (spriteMasks == NULL) {
        SpriteCopy(sprite, &spPtr->oam);
    }
    else {
        SpriteCopyWithMasks(sprite, &spPtr->oam, spriteMasks);
    }

    // Set tileNum
    if (sp.unk2.unk0 != 0 && sUnknown_2025672[sp.unk2.unk0] != 0) {
        SpriteSetTileNum(sprite, sUnknown_2025672[sp.unk2.unk0]);
    }
    else {
        // Animations add to existing tileNum
        s32 tileNum = sprite->attrib3;
        tileNum &= SPRITEOAM_MAX_TILENUM;
        tileNum >>= SPRITEOAM_SHIFT_TILENUM;

        SpriteSetTileNum(sprite, tileNum + a1->vramTileOrMaybeAnimTimer);
    }

    pos = ((sprite->attrib2 >> SPRITEOAM_SHIFT_X) & SPRITEOAM_MAX_X) ;
    pos += a1->pos.x - 0x100;

    if (pos < -64)
        return;
    if (pos >= DISPLAY_WIDTH)
        return;

    SpriteSetX(sprite, pos);

    pos = ((sprite->unk6 >> SPRITEOAM_SHIFT_WORKING_Y) & SPRITEOAM_MAX_WORKING_Y);
    pos += a1->pos.y - 0x200;
    if (pos < -64)
        return;
    if (pos >= DISPLAY_HEIGHT)
        return;

    SpriteSetOamY(sprite, pos);

    // Set paletteNum
    if (!((sprite->unk6 >> SPRITEOAM_SHIFT_UNK6_1) & SPRITEOAM_MAX_UNK6_1)) {
        SpriteSetPalNum(sprite, a1->paletteNum);
    }

    if (sp.unk2.unk0 != 0) {
        SpriteSetPalNum(sprite, sUnknown_2025682[sp.unk2.unk0]);
    }

    sUnknown_2025EA8[sSpriteCount].unk0 = sUnknown_20256A0.sprites[spriteId].unk0;
    sUnknown_20256A0.sprites[spriteId].unk0 = sUnknown_2025EA8 + sSpriteCount;
    sSpriteCount++;
}

// a2 and spriteMasks are always called with NULL lol
void AddSprite(struct SpriteOAM *a0, s32 a1, struct UnkSpriteMem *a2, struct unkStruct_2039DB0 *spriteMasks)
{
    s32 yPos;
    struct SpriteOAM *spr;

    if (sSpriteCount >= 128)
        return;

    spr = &sUnknown_20262A8[sSpriteCount];

    if (a1 < 0)
        a1 = 0;
    if (a1 > 255)
        a1 = 255;

    if (spriteMasks == NULL) {
        SpriteCopy(spr, a0);
    }
    else {
        SpriteCopyWithMasks(spr, a0, spriteMasks);
    }

    yPos = spr->unk6 >> SPRITEOAM_SHIFT_WORKING_Y;
    nullsub_3(yPos, 0);
    yPos &= SPRITEOAM_MAX_Y;
    spr->attrib1 &= ~SPRITEOAM_MASK_Y;
    spr->attrib1 |= yPos;

    if (a2 != NULL)
        RegisterSpriteParts_80052BC(a2);

    sUnknown_2025EA8[sSpriteCount].unk0 = sUnknown_20256A0.sprites[a1].unk0;
    sUnknown_20256A0.sprites[a1].unk0 = &sUnknown_2025EA8[sSpriteCount];

    sSpriteCount++;
}

void sub_8005180(void)
{
    UnkSpriteLink *r1;
    UnkSpriteLink *r2;

    r2 = &sUnknown_20256A0.sprites[0];
    r1 = r2;

    if (r2 != NULL) {
        do {
            if (r1->unk4 != NULL) {
                if (r2 != NULL)
                    r2->unk0 = r1;
                r2 = r1;
            }
            r1 = r1->unk0;
        } while (r1 != NULL);
    }

    r2->unk0 = NULL;
}

void CopySpritesToOam(void)
{
    UnkSpriteLink *sLink;
    SpriteOAM *spr;
    vu16 *oam;
    s32 count;

    sLink = &sUnknown_20256A0.sprites[0];
    oam = (vu16 *)(OAM + OAM_SIZE); // End of OAM. Work backwards
    count = 0;

    while (sLink != NULL && (u32)oam > (OAM + sizeof(struct OamData))) {
        spr = sLink->unk4;

        // Each OAM entry is 8 bytes [struct OamData]
        if (spr != NULL) {
            // Skip affineParam
            oam -= 2;
            // Set tileNum/priority/paletteNum
            *oam = spr->attrib3;
            // Set x/matrixNum/size
            oam--;
            *oam = spr->attrib2;
            // Set y/affineMode/objMode/mosaic/bpp/shape
            oam--;
            *oam = spr->attrib1;

            count++;
        }

        sLink = sLink->unk0;
    }

    // Clear remaining object slots
    while ((u32)oam > (OAM + sizeof(struct OamData))) {
        // Skip affineParam
        oam -= 2;
        // Set tileNum/priority/paletteNum
        *oam = 0;
        // Set x/matrixNum/size
        oam--;
        *oam = 0;
        // Set y/affineMode/objMode/mosaic/bpp/shape
        oam--;
        *oam = DISPLAY_HEIGHT;
    }

    sOAMSpriteCount = count;
}

void SetSavingIconCoords(DungeonPos *pos)
{
    if (pos == NULL) {
        sUnknown_2025694.x = 0;
        sUnknown_2025694.y = DISPLAY_HEIGHT;
    }
    else {
        sUnknown_2025694.x = pos->x;
        sUnknown_2025694.y = pos->y;
        sUnknown_2025698 = 0;
    }
}

void BlinkSavingIcon(void)
{
    vu16 *oam;
    u32 uVar1;

    oam = (vu16 *)OAM;
    uVar1 = sUnknown_2025698++;

    if (uVar1 & 16) {
        // Set y to 160
        // Set affineMode/objMode/mosaic/bpp/shape to 0
        *oam++ = DISPLAY_HEIGHT;
        // Set x/matrixNum to 0
        // Set size to 1
        *oam++ = 0x4000;
        // Set tileNum to 0x3FC
        // Set priority to 0
        // Set paletteNum to 15
        *oam++ = 0xF3FC;
        // Set affineParam to 0
        *oam = 0;
    }
    else {
        // Set y to sUnknown_2025694.y
        // Set affineMode/objMode/mosaic/bpp/shape to 0
        *oam++ = sUnknown_2025694.y;
        // Set x to sUnknown_2025694.x
        // Set matrixNum to 0
        // Set size to 1
        *oam++ = sUnknown_2025694.x + 0x4000;
        // Set tileNum to 0x3FC
        // Set priority to 0
        // Set paletteNum to 15
        *oam++ = 0xF3FC;
        // Set affineParam to 0
        *oam = 0;
    }
}

void RegisterSpriteParts_80052BC(struct UnkSpriteMem *a0)
{
    while (a0->byteCount != 0) {
        if ((uintptr_t)sUnknown_203B074 >= (uintptr_t)&sUnknown_20266B0[UNK_20266B0_ARR_COUNT])
            return;
        sUnknown_203B074->byteCount = a0->byteCount;
        sUnknown_203B074->src = a0->src;
        sUnknown_203B074->dest = sCharMemCursor;
        sCharMemCursor += a0->byteCount;
        sUnknown_203B074++;
        a0++;
    }
}

void sub_8005304(void)
{
    unkStruct_20266B0 *s;

    for (s = &sUnknown_20266B0[0]; s < sUnknown_203B074; s++) {
        if (s->src != NULL)
            CpuCopy(s->dest, s->src, s->byteCount);
        else
            CpuClear(s->dest, s->byteCount);
    }
}

void sub_800533C(ax_pose **a0, UnkSpriteMem **a1, axdata1 *a2, unkStruct_2039DB0 *spriteMasks, bool8 a4)
{
    UnkSpriteMem *mem;
    ax_pose *r4;

    r4 = a0[a2->poseId];
    sCharMemCursor = OBJ_VRAM0 + (a2->vramTileOrMaybeAnimTimer * 0x20);
    for (mem = NULL; (u16)r4->sprite != 0xFFFF || *((u16*)&r4->unk2) != 0xFFFF; r4++, mem = NULL) {
        if (a4 != 0 && r4->sprite > -1)
            mem = a1[r4->sprite];

        AddAxSprite(r4, a2, mem, spriteMasks);
    }
}

void AxResInitFile(axdata *a0, OpenedFile *a1, u32 a2, u32 a3, u32 a4, u32 spriteAnimIndex, bool8 a6)
{
    AxResInit(a0, (axmain *)a1->data, a2, a3, a4, spriteAnimIndex, a6);
}

void AxResInit(axdata *a0, axmain *a1, u32 a2, u32 direction, u32 a4, u32 spriteAnimIndex, bool8 a6)
{
    a0->flags = 0x8000;
    if (a6)
        a0->flags |= 0x1000;

    a0->animFrames = 0;
    a0->animWaitFrames = spriteAnimIndex;
    a0->sub1.offset.x = 0;
    a0->sub1.offset.y = 0;
    a0->sub1.vramTileOrMaybeAnimTimer = a4;
    a0->sub1.poseId = 0xFFFF;
    a0->sub1.lastPoseId = 0xFFFF;
    a0->sub1.unkC = 0;
    a0->sub1.unk10 = 0;
    a0->totalFrames = 0;
    a0->nextAnimData = a1->animations[a2][direction];
    a0->activeAnimData = a0->nextAnimData;
    a0->poseData = a1->poses;
    a0->spriteData = a1->spriteData;
    a0->paletteData = a1->palettes;
}

void AxResInitUnorientedFile(axdata *a0, OpenedFile *a1, u32 a2, u32 a3, u32 spriteAnimIndex, bool8 a5)
{
    AxResInitUnoriented(a0, (axmain *)a1->data, a2, a3, spriteAnimIndex, a5);
}

static void AxResInitUnoriented(axdata *a0, axmain *a1, u32 a2, u32 a3, u32 spriteAnimIndex, bool8 a5)
{
    a0->flags = 0x8000;
    if (a5)
        a0->flags |= 0x1000;

    a0->animFrames = 0;
    a0->animWaitFrames = spriteAnimIndex;
    a0->sub1.offset.x = 0;
    a0->sub1.offset.y = 0;
    a0->sub1.vramTileOrMaybeAnimTimer = a3;
    a0->sub1.poseId = 0xFFFF;
    a0->sub1.lastPoseId = 0xFFFF;
    a0->sub1.unkC = 0;
    a0->sub1.unk10 = 0;
    a0->totalFrames = 0;
    a0->nextAnimData = a1->animations[a2][0];
    a0->activeAnimData = a0->nextAnimData;
    a0->poseData = a1->poses;
    a0->paletteData = 0;
}

static inline s16 check_flag_for_80054BC(u16 flags) {
    if (flags & 0x2000)
        return 0;
    else
        return flags >> 15;
}


void RunAxAnimationFrame(struct axObject *a0)
{
    ax_anim *aData;

    if (!check_flag_for_80054BC(a0->axdata.flags))
        return;

    if (a0->axdata.sub1.poseId >= 0) {
        if (a0->axdata.flags & 0x4000)
            return;

        if (a0->axdata.totalFrames < 30000)
            a0->axdata.totalFrames++;

        if (a0->axdata.animWaitFrames != 0) {
            a0->axdata.animWaitFrames--;
            return;
        }

        if (a0->axdata.animFrames != 0 && --a0->axdata.animFrames > 0)
            return;
    }

    if (a0->axdata.activeAnimData->frames == 0) {
        if (!(a0->axdata.flags & 0x1000)) {
            a0->axdata.flags |= 0x2000;
            return;
        }

        a0->axdata.activeAnimData = a0->axdata.nextAnimData;
        a0->axdata.animWaitFrames = Rand32Bit() & 1;
    }

    a0->axdata.flags |= 0x800;

    aData = a0->axdata.activeAnimData;
    a0->axdata.animFrames = aData->frames;
    a0->axdata.sub1.poseId = aData->poseId;
    a0->axdata.sub1.offset.x = aData->offset.x;
    a0->axdata.sub1.offset.y = aData->offset.y;
    a0->axdata.sub1.shadow.x = aData->shadow.x;
    a0->axdata.sub1.shadow.y = aData->shadow.y;
    a0->axdata.sub1.unkC = aData->unkFlags;
    a0->axdata.sub1.unk10 |= aData->unkFlags;
    a0->axdata.activeAnimData = aData + 1;
}
