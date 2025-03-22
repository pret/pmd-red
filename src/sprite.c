#include "global.h"
#include "bg_palette_buffer.h"
#include "cpu.h"
#include "main_loops.h"
#include "random.h"
#include "sprite.h"

EWRAM_DATA static u16 sOAMSpriteCount = {0}; // GBA=2025670 | NDS=20EC504 | Written to but never read
EWRAM_DATA static s16 sUnknown_2025672[8] = {0};
EWRAM_DATA static s16 sUnknown_2025682[9] = {0};
EWRAM_DATA static DungeonPos sUnknown_2025694 = {0};
EWRAM_DATA static u32 sUnknown_2025698 = {0};
UNUSED EWRAM_DATA static u32 sUnused1 = {0}; // GBA=202569C
EWRAM_DATA static SpriteList sSpriteList = {0}; // NDS=20ED4C0
EWRAM_DATA static UnkSpriteLink sUnknown_2025EA8[128] = {0};
EWRAM_DATA static SpriteOAM sUnknown_20262A8[128] = {0};
EWRAM_DATA static s32 sSpriteCount = {0}; // GBA=20266A8
UNUSED EWRAM_DATA static u32 sUnused2 = {0}; // GBA=20266AC

#define UNK_20266B0_ARR_COUNT 160
EWRAM_DATA static unkStruct_20266B0 sUnknown_20266B0[UNK_20266B0_ARR_COUNT] = {0};

EWRAM_DATA static void *sCharMemCursor = {0}; // GBA=2026E30
UNUSED EWRAM_DATA static u32 sUnused3 = {0}; // GBA=2026E34

EWRAM_INIT static unkStruct_20266B0 *sUnknown_203B074 = {0};

static void AxResInitUnoriented(axdata *, axmain *, u32, u32, u32, bool8);
static void RegisterSpriteParts_80052BC(UnkSpriteMem *);
static void sub_800533C(ax_pose **, UnkSpriteMem **, axdata1 *, unkStruct_2039DB0 *spriteMasks, bool8);
static void sub_800561C(const EfoFileData *, s32 vramIdx, s32 brightness, const RGB *ramp);

// arm9.bin::0200265C
void InitSprites(void)
{
    ResetSprites(TRUE);
    SetSavingIconCoords(NULL);

    // NDS version has more here
}

// arm9.bin::020024f4
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

    a = &sSpriteList.sprites[0];
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

    sSpriteList.unk800 = 0;
    sSpriteList.unk804 = 0;
}

// arm9.bin::020024CC
void sub_8004E8C(unkStruct_2039DB0 *a0)
{
    a0->unk0 = 0xFFFF;
    a0->unk2 = 0xFFFF;
    a0->unk4 = 0xFFFF;
    a0->unk6 = 0;
    a0->unk8 = 0;
    a0->unkA = 0;
}

// Needed to match AddAxSprite and AddSprite. These macros assume SpriteOAM struct has size of 8
#define SpriteCopy(_dst, _src)      \
{                                   \
    u16 *_dstVar = (void *)_dst;    \
    u16 *_srcVar = (void *)_src;    \
                                    \
    *(_dstVar++) = *(_srcVar++);    \
    *(_dstVar++) = *(_srcVar++);    \
    *(_dstVar++) = *(_srcVar++);    \
    *(_dstVar++) = *(_srcVar++);    \
}

#define SpriteCopyWithMasks(_dst, _src, _spriteMasks)                           \
{                                                                               \
    u16 *_dstVar = (void *)_dst;                                                \
    u16 *_srcVar = (void *)_src;                                                \
                                                                                \
    *(_dstVar++) = (*(_srcVar++) & _spriteMasks->unk0) | _spriteMasks->unk6;    \
    *(_dstVar++) = (*(_srcVar++) & _spriteMasks->unk2) | _spriteMasks->unk8;    \
    *(_dstVar++) = (*(_srcVar++) & _spriteMasks->unk4) | _spriteMasks->unkA;    \
    *(_dstVar++) = *(_srcVar++);                                                \
}

// arm9.bin::020021C4
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
        SpriteAddTileNum(sprite, a1->vramTileOrMaybeAnimTimer);
    }

    pos = SpriteGetX(sprite);
    pos += a1->pos.x - 0x100;

    if (pos < -64)
        return;
    if (pos >= DISPLAY_WIDTH)
        return;

    SpriteSetX(sprite, pos);

    pos = SpriteGetY(sprite);
    pos += a1->pos.y - 0x200;
    if (pos < -64)
        return;
    if (pos >= DISPLAY_HEIGHT)
        return;

    SpriteSetOamY(sprite, pos);

    // Set paletteNum
    if (!SpriteGetUnk6_1(sprite)) {
        SpriteSetPalNum(sprite, a1->paletteNum);
    }

    if (sp.unk2.unk0 != 0) {
        SpriteSetPalNum(sprite, sUnknown_2025682[sp.unk2.unk0]);
    }

    sUnknown_2025EA8[sSpriteCount].unk0 = sSpriteList.sprites[spriteId].unk0;
    sSpriteList.sprites[spriteId].unk0 = sUnknown_2025EA8 + sSpriteCount;
    sSpriteCount++;
}

// a2 and spriteMasks are always called with NULL lol
// arm9.bin::02002088
void AddSprite(SpriteOAM *a0, s32 a1, UnkSpriteMem *a2, unkStruct_2039DB0 *spriteMasks)
{
    s32 yPos;
    SpriteOAM *spr;

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

    sUnknown_2025EA8[sSpriteCount].unk0 = sSpriteList.sprites[a1].unk0;
    sSpriteList.sprites[a1].unk0 = &sUnknown_2025EA8[sSpriteCount];

    sSpriteCount++;
}

// arm9.bin::02002048
void sub_8005180(void)
{
    UnkSpriteLink *r1;
    UnkSpriteLink *r2;

    r2 = &sSpriteList.sprites[0];
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

// arm9.bin::02001FB0
void CopySpritesToOam(void)
{
    UnkSpriteLink *sLink;
    SpriteOAM *spr;
    vu16 *oam;
    s32 count;

    sLink = &sSpriteList.sprites[0];
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

// arm9.bin::02001F64
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

// arm9.bin::02001EE8
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

// arm9.bin::02001E70
static void RegisterSpriteParts_80052BC(UnkSpriteMem *a0)
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

// arm9.bin::02001E14
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

// arm9.bin::02001D88
static void sub_800533C(ax_pose **a0, UnkSpriteMem **a1, axdata1 *a2, unkStruct_2039DB0 *spriteMasks, bool8 a4)
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

// arm9.bin::02001D58
void AxResInitFile(axdata *a0, OpenedFile *a1, u32 a2, u32 a3, u32 a4, u32 spriteAnimIndex, bool8 a6)
{
    AxResInit(a0, (axmain *)a1->data, a2, a3, a4, spriteAnimIndex, a6);
}

// arm9.bin::02001CC4
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
    a0->positions = a1->positions;
}

// arm9.bin::02001C9C
void AxResInitUnorientedFile(axdata *a0, OpenedFile *a1, u32 a2, u32 a3, u32 spriteAnimIndex, bool8 a5)
{
    AxResInitUnoriented(a0, (axmain *)a1->data, a2, a3, spriteAnimIndex, a5);
}

// arm9.bin::02001C18
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
    a0->positions = NULL;
}

static inline s16 check_flag_for_80054BC(u16 flags)
{
    if (flags & 0x2000)
        return 0;
    else
        return flags >> 15;
}

// arm9.bin::02001AC4
void RunAxAnimationFrame(axdata *a0)
{
    ax_anim *aData;

    if (!check_flag_for_80054BC(a0->flags))
        return;

    if (a0->sub1.poseId >= 0) {
        if (a0->flags & 0x4000)
            return;

        if (a0->totalFrames < 30000)
            a0->totalFrames++;

        if (a0->animWaitFrames != 0) {
            a0->animWaitFrames--;
            return;
        }

        if (a0->animFrames != 0 && --a0->animFrames > 0)
            return;
    }

    if (a0->activeAnimData->frames == 0) {
        if (!(a0->flags & 0x1000)) {
            a0->flags |= 0x2000;
            return;
        }

        a0->activeAnimData = a0->nextAnimData;
        a0->animWaitFrames = Rand32Bit() & 1;
    }

    a0->flags |= 0x800;

    aData = a0->activeAnimData;
    a0->animFrames = aData->frames;
    a0->sub1.poseId = aData->poseId;
    a0->sub1.offset.x = aData->offset.x;
    a0->sub1.offset.y = aData->offset.y;
    a0->sub1.shadow.x = aData->shadow.x;
    a0->sub1.shadow.y = aData->shadow.y;
    a0->sub1.unkC = aData->unkFlags;
    a0->sub1.unk10 |= aData->unkFlags;
    a0->activeAnimData = aData + 1;
}

// arm9.bin::020019F4
void DoAxFrame_800558C(axdata *a0, s32 spriteX, s32 spriteY, u32 a3, u32 paletteNum, unkStruct_2039DB0 *spriteMasks)
{
    if (!(a0->flags >> 15))
        return;

    if (a0->sub1.poseId < 0)
        RunAxAnimationFrame(a0);

    if (!(a0->flags >> 15))
        return;

    a0->sub1.pos.x = a0->sub1.offset.x + spriteX;
    a0->sub1.pos.y = a0->sub1.offset.y + spriteY;
    a0->sub1.paletteNum = paletteNum;
    a0->sub1.unk16 = a3;
    sub_800533C(a0->poseData, a0->spriteData, &a0->sub1, spriteMasks, !!(a0->sub1.lastPoseId ^ a0->sub1.poseId));
    a0->sub1.lastPoseId = a0->sub1.poseId;

    if (a0->flags & 0x800)
        a0->flags &= 0xF7FF;
}

// arm9.bin::020019E4
void sub_8005610(OpenedFile *a0, s32 vramIdx, s32 brightness, const RGB *ramp)
{
    sub_800561C((const EfoFileData *)a0->data, vramIdx, brightness, ramp);
}

// arm9.bin::02001970
static void sub_800561C(const EfoFileData *a0, s32 vramIdx, s32 brightness, const RGB *ramp)
{
    s32 i;

    if (a0->tiles != NULL)
        CpuCopy(OBJ_VRAM0 + vramIdx * 0x20, a0->tiles, a0->tileCount * 0x20);

    if (a0->pal != NULL) {
        for (i = 0; i < 16; i++)
            SetBGPaletteBufferColorRGB(i + 480, &a0->pal[i], brightness, ramp);
    }
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static const RGB *sub_8005668(OpenedFile *a0, s32 vramIdx)
{
    return sub_8005674((const EfoFileData *)a0->data, vramIdx);
}
#endif

// arm9.bin::0200193C
const RGB *sub_8005674(const EfoFileData *a0, s32 vramIdx)
{
    if (a0->tiles != NULL)
        CpuCopy(OBJ_VRAM0 + vramIdx * 0x20, a0->tiles, a0->tileCount * 0x20);

    return a0->pal;
}

// arm9.bin::02001894
void sub_800569C(DungeonPos *a0, axObject *a1, u8 a2)
{
    DungeonPos *ptr;
    DungeonPos *ptr2;
    DungeonPos *ptr3;

    a0->x = 0;
    a0->y = 0;

    if (!(a1->axdata.flags >> 15) || a2 >= 4)
        return;

    if (a1->axdata.paletteData != NULL) {
        ptr = &((DungeonPos*)a1->axdata.paletteData)[a1->axdata.sub1.poseId * 4];
        ptr2 = &ptr[a2];
        if (*&ptr2->x == 99 && *&ptr2->y == 99) {
            a0->x = 99;
            a0->y = 99;
        }
        else {
            ptr3 = &ptr[a2];
            a0->x = a1->axdata.sub1.offset.x + ptr3->x;
            a0->y = a1->axdata.sub1.offset.y + ptr3->y;
        }
    }
    else {
        a0->x = 99;
        a0->y = 99;
    }
}

// arm9.bin::020017D4
void sub_8005700(DungeonPos *a0, axObject *a1)
{
    s32 i;
    DungeonPos *ptr;

    if (!(a1->axdata.flags >> 15))
        return;

    if (a1->axdata.paletteData != NULL) {
        ptr = &((DungeonPos*)a1->axdata.paletteData)[a1->axdata.sub1.poseId * 4];
        for (i = 0; i < 4; i++) {
            if (*&ptr[i].x == 99 && *&ptr[i].y == 99) {
                a0->x = 99;
                a0->y = 99;
            }
            else {
                a0->x = a1->axdata.sub1.offset.x + ptr[i].x;
                a0->y = a1->axdata.sub1.offset.y + ptr[i].y;
            }
            a0++;
        }
    }
    else {
        for (i = 0; i < 4; i++) {
            a0->x = 99;
            a0->y = 99;
            a0++;
        }
    }
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void sub_8005764(s32 a0, OpenedFile *file, s32 a2, const RGB *a3)
{
    sub_8005770(a0, (const RGB*)file->data, a2, a3);
}
#endif

// arm9.bin::02001794
void sub_8005770(s32 param_1, const RGB *color, s32 brightness, const RGB *ramp)
{
    s32 i;

    for (i = 0; i < 16; i++)
        SetBGPaletteBufferColorRGB((param_1 + 0x10) * 0x10 + i, &color[i], brightness, ramp);
}

// Maybe DungeonPos
// arm9.bin::02001790
void nullsub_7(s16 *a0)
{
}

// arm9.bin::0200178C
void nullsub_8(u32 a0)
{
}

// Should be arm9.bin::02001788
void nullsub_9(void)
{
}

// TODO: Find these in blue if they exist

void nullsub_10(bool8 a0)
{
}

UNUSED static void nullsub_144(void)
{
}

void nullsub_11(SpriteOAM *a0, s32 a1, UnkSpriteMem *a2, unkStruct_2039DB0 *a3)
{
}

void nullsub_12(void)
{
}

void nullsub_13(void)
{
}

UNUSED static void nullsub_145(void)
{
}

void nullsub_14(void)
{
}

UNUSED static void nullsub_146(void)
{
}

UNUSED static void nullsub_147(void)
{
}

UNUSED static void nullsub_148(void)
{
}

UNUSED static void nullsub_149(void)
{
}

UNUSED static bool8 sub_80057D8(void)
{
    return FALSE;
}

UNUSED static bool8 sub_80057DC(void)
{
    return FALSE;
}

UNUSED static void nullsub_150(void)
{
}

UNUSED static void nullsub_151(void)
{
}
