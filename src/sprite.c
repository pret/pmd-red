#include "global.h"
#include "cpu.h"
#include "random.h"
#include "sprite.h"

extern u16 gUnknown_2025670; // Number of sprites in OAM?
extern s16 gUnknown_2025672[8];
extern s16 gUnknown_2025682[9];
extern struct Position gUnknown_2025694;
extern u32 gUnknown_2025698;
extern struct SpriteList gUnknown_20256A0;
extern struct UnkSpriteLink gUnknown_2025EA8[128];
extern struct SpriteOAM gUnknown_20262A8[128];
extern s32 gSpriteCount; /* 20266A8 */
extern struct unkStruct_20266B0 gUnknown_20266B0[160];
extern void *gCharMemCursor; /* 2026E30 */
extern struct unkStruct_20266B0 *gUnknown_203B074;

// code.c
extern void nullsub_3(s32, s32);

void RegisterSpriteParts_80052BC(struct UnkSpriteMem *);
void sub_800545C(struct Entity_Sub28 *, struct Dungeon_Sub17B44_Sub4 *, u32, u32, u32, bool8);

void InitSprites(void)
{
    ResetSprites(TRUE);
    SetSavingIconCoords(NULL);
}

void ResetSprites(bool8 a0)
{
    s32 i;
    struct UnkSpriteLink *a;
    struct UnkSpriteLink *b;
    struct SpriteOAM *c;
    struct SpriteOAM *d;
    struct UnkSpriteLink *e;

    gSpriteCount = 0;
    gCharMemCursor = OBJ_VRAM0;
    gUnknown_203B074 = &gUnknown_20266B0[0];

    a = &gUnknown_20256A0.sprites[0];
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
        d = &gUnknown_20262A8[0];
        a = &gUnknown_2025EA8[0];
        for (i = 0; i < 128; i++) {
            a->unk0 = e;
            a->unk4 = d;
            d++;
            a++;
        }
    }

    gUnknown_20256A0.unk800 = 0;
    gUnknown_20256A0.unk804 = 0;
}

void sub_8004E8C(struct unkStruct_2039DB0 *a0)
{
    a0->unk0 = 0xFFFF;
    a0->unk2 = -1;
    a0->unk4 = 0xFFFF;
    a0->unk6 = 0;
    a0->unk8 = 0;
    a0->unkA = 0;
}

// https://decomp.me/scratch/VYqKb
// spriteMasks is a u16[6]
#if NONMATCHING
void sub_8004EA8(struct ax_pose *a0, struct axdata1 *a1, struct UnkSpriteMem *a2, u16 *spriteMasks)
{
    // size: 0xC
    struct UnkStackFor8004EA8
    {
        u16 unk0;
        u8 unk2;
        s8 unk3;
        u16 flags1;
        u16 flags2;
        u16 flags3;
        u16 unkA;
    } sp;
    struct SpriteOAM *sprite;
    u32 uVar9;
    s32 r7;

    s32 x;
    s32 y;
    s32 tileNum;
    s32 earlyMask;
    
    if (a2 != NULL)
        RegisterSpriteParts_80052BC(a2);

    if (gSpriteCount >= 128)
        return;

    sp.unk0 = a0->sprite;
    *((u16 *)&sp.unk2) = a0->unk2; // ?????????
    sp.flags1 = a0->flags1 & ~(0x100 | 0x200);
    sp.flags2 = a0->flags2 & ~(0x200 | 0x400 | 0x800);
    sp.flags3 = a0->flags3;
    sp.unkA = ((a0->flags2 & (0x200 | 0x400 | 0x800)) >> 9) | ((a0->flags1 & (0x1 | 0x2 | 0x4 | 0x8 | 0x10 | 0x20 | 0x40 | 0x80 | 0x100 | 0x200)) << 4);
    sprite = gUnknown_20262A8 + gSpriteCount;
    r7 = a1->unk16 + sp.unk3;

    if (r7 < 0)
        r7 = 0;
    if (r7 > 255)
        r7 = 255;

    if (spriteMasks == NULL) {
        sprite->atrib1 = sp.flags1;
        sprite->atrib2 = sp.flags2;
        sprite->atrib3 = sp.flags3;
        sprite->unk6 = sp.unkA;
    }
    else {
        sprite->atrib1 = (spriteMasks[0] & sp.flags1) | spriteMasks[3];
        sprite->atrib2 = (spriteMasks[1] & sp.flags2) | spriteMasks[4];
        sprite->atrib3 = (spriteMasks[2] & sp.flags3) | spriteMasks[5];
        sprite->unk6 = sp.unkA;
    }

    if (sp.unk2 != 0 && gUnknown_2025672[sp.unk2] != 0) {
        tileNum = gUnknown_2025672[sp.unk2] & 0x3FF;
    }
    else {
        tileNum = (sprite->atrib3 & 0x3FF) + a1->vramTileOrMaybeAnimTimer;
        tileNum &= 0x3FF;
    }

    // Set tileNum, maintain priority/paletteNum
    sprite->atrib3 = tileNum | (sprite->atrib3 & 0xFC00);

    x = (sprite->atrib2 & 0x1FF) - 256;
    x += a1->xPos;
    if (x < -64)
        return;
    if (x >= DISPLAY_WIDTH)
        return;

    // Set x, maintain matrixNum/size
    sprite->atrib2 = (x & 0x1FF) | (sprite->atrib2 & 0xFE00);

    uVar9 = sprite->unk6 << 16;
    earlyMask = 0xFFF;

    y = (uVar9 >> 20) - 512;
    y += a1->yPos;
    if (y < -64)
        return;
    if (y >= DISPLAY_HEIGHT)
        return;

    // Set y, maintain affineMode/objMode/mosaic/bpp/shape
    sprite->atrib1 = (y & 0xFF) | (sprite->atrib1 & 0xFF00);

    // Set paletteNum, maintain tileNum/priority
    if (((uVar9 >> 17) & 1) == 0)
        sprite->atrib3 = ((a1->paletteNum & 0xF) << 12) | (sprite->atrib3 & earlyMask);

    if (sp.unk2 != 0)
        sprite->atrib3 = ((gUnknown_2025682[sp.unk2] & 0xF) << 12) | (sprite->atrib3 & earlyMask);

    gUnknown_2025EA8[gSpriteCount].unk0 = gUnknown_20256A0.sprites[r7].unk0;
    gUnknown_20256A0.sprites[r7].unk0 = gUnknown_2025EA8 + gSpriteCount;
    gSpriteCount++;
}
#else
NAKED
void sub_8004EA8(struct ax_pose *a0, struct axdata1 *a1, struct UnkSpriteMem *a2, u16 *spriteMasks)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r9\n"
    "\tmov r6, r8\n"
    "\tpush {r6,r7}\n"
    "\tsub sp, 0xC\n"
    "\tadds r5, r0, 0\n"
    "\tmov r8, r1\n"
    "\tadds r0, r2, 0\n"
    "\tadds r6, r3, 0\n"
    "\tcmp r0, 0\n"
    "\tbeq _08004EC2\n"
    "\tbl RegisterSpriteParts_80052BC\n"
"_08004EC2:\n"
    "\tldr r0, _08004F40\n"
    "\tldr r7, [r0]\n"
    "\tmov r12, r0\n"
    "\tcmp r7, 0x7F\n"
    "\tble _08004ECE\n"
    "\tb _08005082\n"
"_08004ECE:\n"
    "\tmov r2, sp\n"
    "\tldrh r0, [r5]\n"
    "\tstrh r0, [r2]\n"
    "\tldrh r0, [r5, 0x2]\n"
    "\tstrh r0, [r2, 0x2]\n"
    "\tldrh r4, [r5, 0x4]\n"
    "\tldr r0, _08004F44\n"
    "\tands r0, r4\n"
    "\tstrh r0, [r2, 0x4]\n"
    "\tldrh r3, [r5, 0x6]\n"
    "\tldr r0, _08004F48\n"
    "\tands r0, r3\n"
    "\tstrh r0, [r2, 0x6]\n"
    "\tldrh r0, [r5, 0x8]\n"
    "\tstrh r0, [r2, 0x8]\n"
    "\tmovs r1, 0xE0\n"
    "\tlsls r1, 4\n"
    "\tands r1, r3\n"
    "\tlsrs r1, 9\n"
    "\tldr r0, _08004F4C\n"
    "\tands r0, r4\n"
    "\tlsls r0, 4\n"
    "\torrs r1, r0\n"
    "\tstrh r1, [r2, 0xA]\n"
    "\tlsls r1, r7, 3\n"
    "\tldr r0, _08004F50\n"
    "\tadds r3, r1, r0\n"
    "\tmov r0, r8\n"
    "\tmovs r2, 0x16\n"
    "\tldrsh r1, [r0, r2]\n"
    "\tmov r0, sp\n"
    "\tldrb r0, [r0, 0x3]\n"
    "\tlsls r0, 24\n"
    "\tasrs r0, 24\n"
    "\tadds r7, r1, r0\n"
    "\tcmp r7, 0\n"
    "\tbge _08004F1A\n"
    "\tmovs r7, 0\n"
"_08004F1A:\n"
    "\tcmp r7, 0xFF\n"
    "\tble _08004F20\n"
    "\tmovs r7, 0xFF\n"
"_08004F20:\n"
    "\tcmp r6, 0\n"
    "\tbne _08004F54\n"
    "\tadd r2, sp, 0x4\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3]\n"
    "\tadds r2, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r3, 0x2]\n"
    "\tadds r2, 0x2\n"
    "\tadds r1, r3, 0x4\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r1]\n"
    "\tadds r2, 0x2\n"
    "\tldrh r0, [r2]\n"
    "\tstrh r0, [r1, 0x2]\n"
    "\tb _08004F86\n"
    "\t.align 2, 0\n"
"_08004F40: .4byte gSpriteCount\n"
"_08004F44: .4byte 0x0000fcff\n"
"_08004F48: .4byte 0x0000f1ff\n"
"_08004F4C: .4byte 0x000003ff\n"
"_08004F50: .4byte gUnknown_20262A8\n"
"_08004F54:\n"
    "\tadd r4, sp, 0x4\n"
    "\tldrh r1, [r4]\n"
    "\tldrh r0, [r6]\n"
    "\tands r0, r1\n"
    "\tldrh r1, [r6, 0x6]\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r3]\n"
    "\tadds r4, 0x2\n"
    "\tldrh r1, [r4]\n"
    "\tldrh r0, [r6, 0x2]\n"
    "\tands r0, r1\n"
    "\tldrh r1, [r6, 0x8]\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r3, 0x2]\n"
    "\tadds r4, 0x2\n"
    "\tadds r2, r3, 0x4\n"
    "\tldrh r1, [r4]\n"
    "\tldrh r0, [r6, 0x4]\n"
    "\tands r0, r1\n"
    "\tldrh r1, [r6, 0xA]\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r2]\n"
    "\tadds r4, 0x2\n"
    "\tldrh r0, [r4]\n"
    "\tstrh r0, [r2, 0x2]\n"
"_08004F86:\n"
    "\tmov r0, sp\n"
    "\tldrb r0, [r0, 0x2]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08004FB0\n"
    "\tldr r1, _08004FA8\n"
    "\tmov r0, sp\n"
    "\tldrb r0, [r0, 0x2]\n"
    "\tlsls r0, 1\n"
    "\tadds r1, r0, r1\n"
    "\tmovs r4, 0\n"
    "\tldrsh r0, [r1, r4]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08004FB0\n"
    "\tadds r1, r0, 0\n"
    "\tldr r0, _08004FAC\n"
    "\tands r1, r0\n"
    "\tb _08004FC0\n"
    "\t.align 2, 0\n"
"_08004FA8: .4byte gUnknown_2025672\n"
"_08004FAC: .4byte 0x000003ff\n"
"_08004FB0:\n"
    "\tldrh r1, [r3, 0x4]\n"
    "\tldr r2, _08005090\n"
    "\tands r1, r2\n"
    "\tmov r6, r8\n"
    "\tmovs r4, 0x14\n"
    "\tldrsh r0, [r6, r4]\n"
    "\tadds r1, r0\n"
    "\tands r1, r2\n"
"_08004FC0:\n"
    "\tldrh r2, [r3, 0x4]\n"
    "\tmovs r0, 0xFC\n"
    "\tlsls r0, 8\n"
    "\tands r0, r2\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r3, 0x4]\n"
    "\tldrh r4, [r3, 0x2]\n"
    "\tldr r5, _08005094\n"
    "\tadds r2, r5, 0\n"
    "\tands r2, r4\n"
    "\tldr r6, _08005098\n"
    "\tadds r1, r2, r6\n"
    "\tmov r2, r8\n"
    "\tmovs r6, 0\n"
    "\tldrsh r0, [r2, r6]\n"
    "\tadds r2, r1, r0\n"
    "\tmovs r0, 0x40\n"
    "\tnegs r0, r0\n"
    "\tmov r9, r0\n"
    "\tcmp r2, r9\n"
    "\tblt _08005082\n"
    "\tcmp r2, 0xEF\n"
    "\tbgt _08005082\n"
    "\tands r2, r5\n"
    "\tmovs r0, 0xFE\n"
    "\tlsls r0, 8\n"
    "\tands r0, r4\n"
    "\torrs r0, r2\n"
    "\tstrh r0, [r3, 0x2]\n"
    "\tldrh r0, [r3, 0x6]\n"
    "\tlsls r4, r0, 16\n"
    "\tldr r1, _0800509C\n"
    "\tadds r5, r1, 0\n"
    "\tlsrs r2, r4, 20\n"
    "\tldr r6, _080050A0\n"
    "\tadds r1, r2, r6\n"
    "\tmov r2, r8\n"
    "\tmovs r6, 0x2\n"
    "\tldrsh r0, [r2, r6]\n"
    "\tadds r2, r1, r0\n"
    "\tcmp r2, r9\n"
    "\tblt _08005082\n"
    "\tcmp r2, 0x9F\n"
    "\tbgt _08005082\n"
    "\tmovs r0, 0xFF\n"
    "\tands r2, r0\n"
    "\tldrh r1, [r3]\n"
    "\tmovs r0, 0xFF\n"
    "\tlsls r0, 8\n"
    "\tands r0, r1\n"
    "\torrs r0, r2\n"
    "\tstrh r0, [r3]\n"
    "\tlsrs r0, r4, 17\n"
    "\tmovs r1, 0x1\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbne _08005044\n"
    "\tmov r0, r8\n"
    "\tldrb r1, [r0, 0x1E]\n"
    "\tmovs r0, 0xF\n"
    "\tands r1, r0\n"
    "\tlsls r1, 12\n"
    "\tldrh r0, [r3, 0x4]\n"
    "\tands r0, r5\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r3, 0x4]\n"
"_08005044:\n"
    "\tmov r0, sp\n"
    "\tldrb r0, [r0, 0x2]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08005068\n"
    "\tldr r1, _080050A4\n"
    "\tmov r0, sp\n"
    "\tldrb r0, [r0, 0x2]\n"
    "\tlsls r0, 1\n"
    "\tadds r0, r1\n"
    "\tmovs r2, 0\n"
    "\tldrsh r1, [r0, r2]\n"
    "\tmovs r0, 0xF\n"
    "\tands r1, r0\n"
    "\tlsls r1, 12\n"
    "\tldrh r0, [r3, 0x4]\n"
    "\tands r0, r5\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r3, 0x4]\n"
"_08005068:\n"
    "\tldr r0, _080050A8\n"
    "\tmov r4, r12\n"
    "\tldr r3, [r4]\n"
    "\tlsls r2, r3, 3\n"
    "\tadds r2, r0\n"
    "\tldr r1, _080050AC\n"
    "\tlsls r0, r7, 3\n"
    "\tadds r0, r1\n"
    "\tldr r1, [r0]\n"
    "\tstr r1, [r2]\n"
    "\tstr r2, [r0]\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [r4]\n"
"_08005082:\n"
    "\tadd sp, 0xC\n"
    "\tpop {r3,r4}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_08005090: .4byte 0x000003ff\n"
"_08005094: .4byte 0x000001ff\n"
"_08005098: .4byte 0xffffff00\n"
"_0800509C: .4byte 0x00000fff\n"
"_080050A0: .4byte 0xfffffe00\n"
"_080050A4: .4byte gUnknown_2025682\n"
"_080050A8: .4byte gUnknown_2025EA8\n"
"_080050AC: .4byte gUnknown_20256A0");
}
#endif // NONMATCHING

// a2 and a3 are always called with NULL lol
#ifdef NONMATCHING // https://decomp.me/scratch/YCfKG
void AddSprite(struct SpriteOAM *a0, s32 a1, struct UnkSpriteMem *a2, struct unkStruct_2039DB0 *a3)
{
    s32 yPos;
    struct SpriteOAM *spr;
    struct UnkSpriteLink *a;
    struct UnkSpriteLink *b;

    if (gSpriteCount >= 128)
        return;

    spr = &gUnknown_20262A8[gSpriteCount];

    if (a1 < 0)
        a1 = 0;
    if (a1 > 255)
        a1 = 255;

    if (a3 == NULL) {
        spr->atrib1 = a0->atrib1;
        spr->atrib2 = a0->atrib2;
        spr->atrib3 = a0->atrib3;
        spr->unk6 = a0->unk6;
    }
    else {
        spr->atrib1 = (a0->atrib1 & a3->unk0) | a3->unk6;
        spr->atrib2 = (a0->atrib2 & a3->unk2) | a3->unk8;
        spr->atrib3 = (a0->atrib3 & a3->unk4) | a3->unkA;
        spr->unk6 = a0->unk6;
    }

    yPos = spr->unk6 / 16;
    nullsub_3(yPos, 0);
    yPos &= SPRITEOAM_MAX_Y;
    spr->atrib1 &= ~SPRITEOAM_MASK_Y;
    spr->atrib1 |= yPos;

    if (a2 != NULL)
        RegisterSpriteParts_80052BC(a2);

    a = &gUnknown_2025EA8[0];
    a += gSpriteCount;
    b = &gUnknown_20256A0.sprites[0];
    b += a1;
    a->unk0 = b->unk0;
    b->unk0 = a;

    gSpriteCount++;
}
#else
NAKED
void AddSprite(struct SpriteOAM *a0, s32 a1, struct UnkSpriteMem *a2, struct unkStruct_2039DB0 *a3)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r8\n"
    "\tpush {r7}\n"
    "\tadds r6, r0, 0\n"
    "\tadds r7, r1, 0\n"
    "\tmov r8, r2\n"
    "\tadds r4, r3, 0\n"
    "\tldr r0, _080050F4\n"
    "\tldr r0, [r0]\n"
    "\tcmp r0, 0x7F\n"
    "\tbgt _08005168\n"
    "\tlsls r1, r0, 3\n"
    "\tldr r0, _080050F8\n"
    "\tadds r5, r1, r0\n"
    "\tcmp r7, 0\n"
    "\tbge _080050D2\n"
    "\tmovs r7, 0\n"
"_080050D2:\n"
    "\tcmp r7, 0xFF\n"
    "\tble _080050D8\n"
    "\tmovs r7, 0xFF\n"
"_080050D8:\n"
    "\tcmp r4, 0\n"
    "\tbne _080050FC\n"
    "\tldrh r0, [r6]\n"
    "\tstrh r0, [r5]\n"
    "\tldrh r0, [r6, 0x2]\n"
    "\tstrh r0, [r5, 0x2]\n"
    "\tadds r1, r6, 0x4\n"
    "\tadds r2, r5, 0x4\n"
    "\tldrh r0, [r1]\n"
    "\tstrh r0, [r2]\n"
    "\tldrh r0, [r1, 0x2]\n"
    "\tstrh r0, [r2, 0x2]\n"
    "\tb _08005128\n"
    "\t.align 2, 0\n"
"_080050F4: .4byte gSpriteCount\n"
"_080050F8: .4byte gUnknown_20262A8\n"
"_080050FC:\n"
    "\tldrh r1, [r6]\n"
    "\tldrh r0, [r4]\n"
    "\tands r0, r1\n"
    "\tldrh r1, [r4, 0x6]\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r5]\n"
    "\tldrh r1, [r6, 0x2]\n"
    "\tldrh r0, [r4, 0x2]\n"
    "\tands r0, r1\n"
    "\tldrh r1, [r4, 0x8]\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r5, 0x2]\n"
    "\tadds r2, r6, 0x4\n"
    "\tadds r3, r5, 0x4\n"
    "\tldrh r1, [r2]\n"
    "\tldrh r0, [r4, 0x4]\n"
    "\tands r0, r1\n"
    "\tldrh r1, [r4, 0xA]\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r3]\n"
    "\tldrh r0, [r2, 0x2]\n"
    "\tstrh r0, [r3, 0x2]\n"
"_08005128:\n"
    "\tldrh r4, [r5, 0x6]\n"
    "\tlsrs r4, 4\n"
    "\tadds r0, r4, 0\n"
    "\tmovs r1, 0\n"
    "\tbl nullsub_3\n"
    "\tmovs r0, 0xFF\n"
    "\tands r4, r0\n"
    "\tldrh r1, [r5]\n"
    "\tmovs r0, 0xFF\n"
    "\tlsls r0, 8\n"
    "\tands r0, r1\n"
    "\torrs r0, r4\n"
    "\tstrh r0, [r5]\n"
    "\tmov r0, r8\n"
    "\tcmp r0, 0\n"
    "\tbeq _0800514E\n"
    "\tbl RegisterSpriteParts_80052BC\n"
"_0800514E:\n"
    "\tldr r0, _08005174\n"
    "\tldr r4, _08005178\n"
    "\tldr r3, [r4]\n"
    "\tlsls r2, r3, 3\n"
    "\tadds r2, r0\n"
    "\tldr r1, _0800517C\n"
    "\tlsls r0, r7, 3\n"
    "\tadds r0, r1\n"
    "\tldr r1, [r0]\n"
    "\tstr r1, [r2]\n"
    "\tstr r2, [r0]\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [r4]\n"
"_08005168:\n"
    "\tpop {r3}\n"
    "\tmov r8, r3\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_08005174: .4byte gUnknown_2025EA8\n"
"_08005178: .4byte gSpriteCount\n"
"_0800517C: .4byte gUnknown_20256A0");
}
#endif

void sub_8005180(void)
{
    struct UnkSpriteLink *r1;
    struct UnkSpriteLink *r2;

    r2 = &gUnknown_20256A0.sprites[0];
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
    struct UnkSpriteLink *sLink;
    struct SpriteOAM *spr;
    vu16 *oam;
    s32 count;

    sLink = &gUnknown_20256A0.sprites[0];
    oam = (vu16 *)(OAM + OAM_SIZE); // End of OAM. Work backwards
    count = 0;

    while (sLink != NULL && (u32)oam > (OAM + sizeof(struct OamData))) {
        spr = sLink->unk4;

        // Each OAM entry is 8 bytes [struct OamData]
        if (spr != NULL) {
            // Skip affineParam
            oam -= 2;
            // Set tileNum/priority/paletteNum
            *oam = spr->atrib3;
            // Set x/matrixNum/size
            oam--;
            *oam = spr->atrib2;
            // Set y/affineMode/objMode/mosaic/bpp/shape
            oam--;
            *oam = spr->atrib1;

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

    gUnknown_2025670 = count;
}

void SetSavingIconCoords(struct Position *pos)
{
    if (pos == NULL) {
        gUnknown_2025694.x = 0;
        gUnknown_2025694.y = DISPLAY_HEIGHT;
    }
    else {
        gUnknown_2025694.x = pos->x;
        gUnknown_2025694.y = pos->y;
        gUnknown_2025698 = 0;
    }
}

void BlinkSavingIcon(void)
{
    volatile u16 *oam;
    u32 uVar1;

    oam = (u16 *)OAM;
    uVar1 = gUnknown_2025698++;

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
        // Set y to gUnknown_2025694.y
        // Set affineMode/objMode/mosaic/bpp/shape to 0
        *oam++ = gUnknown_2025694.y;
        // Set x to gUnknown_2025694.x
        // Set matrixNum to 0
        // Set size to 1
        *oam++ = gUnknown_2025694.x + 0x4000;
        // Set tileNum to 0x3FC
        // Set priority to 0
        // Set paletteNum to 15
        *oam++ = 0xF3FC;
        // Set affineParam to 0
        *oam = 0;
    }
}

#ifdef NONMATCHING // https://decomp.me/scratch/taTIU
extern u32 RegisterSpriteParts_80052BC_end[0] asm("gCharMemCursor");
void RegisterSpriteParts_80052BC(struct UnkSpriteMem *a0)
{
    if (a0->byteCount) {
        struct unkStruct_20266B0 **r5 = &gUnknown_203B074;
        void *r6 = RegisterSpriteParts_80052BC_end;
        void **r4 = &gCharMemCursor;
        do {
            struct unkStruct_20266B0 *r2 = *r5;
            if ((uintptr_t)r2 >= (uintptr_t)r6)
                return;
            r2->byteCount = a0->byteCount;
            r2->src = a0->src;
            r2->dest = *r4;
            *r4 = r2->dest + a0->byteCount;
            *r5 = r2 + 1;
            a0++;
        } while (a0->byteCount);
    }
}
#else
NAKED
void RegisterSpriteParts_80052BC(struct UnkSpriteMem *a0)
{
    asm_unified(
    "push {r4-r6,lr}\n"
    "\tadds r3, r0, 0\n"
    "\tldr r0, [r3, 0x4]\n"
    "\tcmp r0, 0\n"
    "\tbeq _080052F2\n"
    "\tldr r5, _080052F8\n"
    "\tldr r6, _080052FC\n"
    "\tldr r4, _08005300\n"
"_080052CC:\n"
    "\tldr r2, [r5]\n"
    "\tcmp r2, r6\n"
    "\tbcs _080052F2\n"
    "\tldr r0, [r3, 0x4]\n"
    "\tstr r0, [r2]\n"
    "\tldr r0, [r3]\n"
    "\tstr r0, [r2, 0x4]\n"
    "\tldr r1, [r4]\n"
    "\tstr r1, [r2, 0x8]\n"
    "\tldr r0, [r3, 0x4]\n"
    "\tadds r1, r0\n"
    "\tstr r1, [r4]\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0xC\n"
    "\tstr r0, [r5]\n"
    "\tadds r3, 0x8\n"
    "\tldr r0, [r3, 0x4]\n"
    "\tcmp r0, 0\n"
    "\tbne _080052CC\n"
"_080052F2:\n"
    "\tpop {r4-r6}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_080052F8: .4byte gUnknown_203B074\n"
"_080052FC: .4byte gCharMemCursor\n"
"_08005300: .4byte gCharMemCursor");
}
#endif // NONMATCHING

void sub_8005304(void)
{
    struct unkStruct_20266B0 *s;

    for (s = &gUnknown_20266B0[0]; s < gUnknown_203B074; s++) {
        if (s->src != NULL)
            CpuCopy(s->dest, s->src, s->byteCount);
        else
            CpuClear(s->dest, s->byteCount);
    }
}

// spriteMasks is a u16[6]. a4 might be a bool8
void sub_800533C(struct ax_pose **a0, struct UnkSpriteMem **a1, struct axdata1 *a2, u16 *spriteMasks, char a4)
{
    struct UnkSpriteMem *mem;
    struct ax_pose *r4;

    r4 = a0[a2->poseId];
    gCharMemCursor = OBJ_VRAM0 + (a2->vramTileOrMaybeAnimTimer * 0x20);
    for (mem = NULL; (u16)r4->sprite != 0xFFFF || r4->unk2 != 0xFFFF; r4++, mem = NULL) {
        if (a4 != 0 && r4->sprite > -1)
            mem = a1[r4->sprite];

        sub_8004EA8(r4, a2, mem, spriteMasks);
    }
}

void sub_80053AC(struct Entity_Sub28 *a0, struct Dungeon_Sub17B44 *a1, u32 a2, u32 a3, u32 a4, u32 spriteAnimIndex, bool8 a6)
{
    sub_80053D0(a0, a1->unk4, a2, a3, a4, spriteAnimIndex, a6);
}

void sub_80053D0(struct Entity_Sub28 *a0, struct Dungeon_Sub17B44_Sub4 *a1, u32 a2, u32 direction, u32 a4, u32 spriteAnimIndex, bool8 a6)
{
    a0->unk0 = 0x8000;
    if (a6)
        a0->unk0 |= 0x1000;

    a0->spriteAnimationCounter = 0;
    a0->spriteAnimationIndex = spriteAnimIndex;
    a0->spritePosOffset.x = 0;
    a0->spritePosOffset.y = 0;
    a0->unk1C = a4;
    a0->spriteIndexForEntity = 0xFFFF;
    a0->spriteIndexForEntity2 = 0xFFFF;
    a0->unk14 = 0;
    a0->unk18 = 0;
    a0->spriteAnimationCounter2 = 0;
    a0->spriteBaseForDirection = a1->unk4[a2][direction];
    a0->spriteGlobalIndex = a0->spriteBaseForDirection;
    a0->unk34 = a1->unk0;
    a0->unk38 = a1->unkC;
    a0->unk30 = a1->unk10;
}

void sub_800543C(struct Entity_Sub28 *a0, struct Dungeon_Sub17B44 *a1, u32 a2, u32 a3, u32 spriteAnimIndex, bool8 a5)
{
    sub_800545C(a0, a1->unk4, a2, a3, spriteAnimIndex, a5);
}

void sub_800545C(struct Entity_Sub28 *a0, struct Dungeon_Sub17B44_Sub4 *a1, u32 a2, u32 a3, u32 spriteAnimIndex, bool8 a5)
{
    a0->unk0 = 0x8000;
    if (a5)
        a0->unk0 |= 0x1000;

    a0->spriteAnimationCounter = 0;
    a0->spriteAnimationIndex = spriteAnimIndex;
    a0->spritePosOffset.x = 0;
    a0->spritePosOffset.y = 0;
    a0->unk1C = a3;
    a0->spriteIndexForEntity = 0xFFFF;
    a0->spriteIndexForEntity2 = 0xFFFF;
    a0->unk14 = 0;
    a0->unk18 = 0;
    a0->spriteAnimationCounter2 = 0;
    a0->spriteBaseForDirection = a1->unk4[a2][0];
    a0->spriteGlobalIndex = a0->spriteBaseForDirection;
    a0->unk34 = a1->unk0;
    a0->unk30 = 0;
}

#if NONMATCHING // https://decomp.me/scratch/n4Umb
void sub_80054BC(struct axPokemon *a0)
{
    struct ax_anim *aData;
    s16 flag;

    if (a0->axdata.flags & 0x2000)
        flag = 0;
    else
        flag = a0->axdata.flags >> 15;

    if (flag == 0)
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
    a0->axdata.sub1.xOffset = aData->xOffset;
    a0->axdata.sub1.yOffset = aData->yOffset;
    a0->axdata.sub1.xShadow = aData->xShadow;
    a0->axdata.sub1.yShadow = aData->yShadow;
    a0->axdata.sub1.unkC = aData->unkFlags;
    a0->axdata.sub1.unk10 |= aData->unkFlags;
    a0->axdata.activeAnimData = aData + 1;
}
#else
NAKED
void sub_80054BC(struct axPokemon *a0)
{
    asm_unified(
    "push {r4,lr}\n"
    "\tadds r4, r0, 0\n"
    "\tldrh r1, [r4]\n"
    "\tmovs r0, 0x80\n"
    "\tlsls r0, 6\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbeq _080054D0\n"
    "\tmovs r0, 0\n"
    "\tb _080054D2\n"
"_080054D0:\n"
    "\tlsrs r0, r1, 15\n"
"_080054D2:\n"
    "\tcmp r0, 0\n"
    "\tbeq _08005586\n"
    "\tmovs r1, 0x20\n"
    "\tldrsh r0, [r4, r1]\n"
    "\tldrh r3, [r4]\n"
    "\tcmp r0, 0\n"
    "\tblt _08005524\n"
    "\tmovs r0, 0x80\n"
    "\tlsls r0, 7\n"
    "\tands r0, r3\n"
    "\tcmp r0, 0\n"
    "\tbne _08005586\n"
    "\tldrh r2, [r4, 0x6]\n"
    "\tmovs r0, 0x6\n"
    "\tldrsh r1, [r4, r0]\n"
    "\tldr r0, _0800550C\n"
    "\tcmp r1, r0\n"
    "\tbgt _080054FA\n"
    "\tadds r0, r2, 0x1\n"
    "\tstrh r0, [r4, 0x6]\n"
"_080054FA:\n"
    "\tldrh r1, [r4, 0x4]\n"
    "\tmovs r2, 0x4\n"
    "\tldrsh r0, [r4, r2]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08005510\n"
    "\tsubs r0, r1, 0x1\n"
    "\tstrh r0, [r4, 0x4]\n"
    "\tb _08005586\n"
    "\t.align 2, 0\n"
"_0800550C: .4byte 0x0000752f\n"
"_08005510:\n"
    "\tldrh r1, [r4, 0x2]\n"
    "\tmovs r2, 0x2\n"
    "\tldrsh r0, [r4, r2]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08005524\n"
    "\tsubs r0, r1, 0x1\n"
    "\tstrh r0, [r4, 0x2]\n"
    "\tlsls r0, 16\n"
    "\tcmp r0, 0\n"
    "\tbgt _08005586\n"
"_08005524:\n"
    "\tldr r0, [r4, 0x2C]\n"
    "\tldrb r0, [r0]\n"
    "\tcmp r0, 0\n"
    "\tbne _08005550\n"
    "\tmovs r0, 0x80\n"
    "\tlsls r0, 5\n"
    "\tands r0, r3\n"
    "\tcmp r0, 0\n"
    "\tbne _08005542\n"
    "\tmovs r1, 0x80\n"
    "\tlsls r1, 6\n"
    "\tadds r0, r1, 0\n"
    "\torrs r0, r3\n"
    "\tstrh r0, [r4]\n"
    "\tb _08005586\n"
"_08005542:\n"
    "\tldr r0, [r4, 0x28]\n"
    "\tstr r0, [r4, 0x2C]\n"
    "\tbl Rand32Bit\n"
    "\tmovs r1, 0x1\n"
    "\tands r0, r1\n"
    "\tstrh r0, [r4, 0x4]\n"
"_08005550:\n"
    "\tldrh r1, [r4]\n"
    "\tmovs r2, 0x80\n"
    "\tlsls r2, 4\n"
    "\tadds r0, r2, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r1, [r4, 0x2C]\n"
    "\tldrb r0, [r1]\n"
    "\tstrh r0, [r4, 0x2]\n"
    "\tldrh r0, [r1, 0x2]\n"
    "\tstrh r0, [r4, 0x20]\n"
    "\tldrh r0, [r1, 0x4]\n"
    "\tstrh r0, [r4, 0xC]\n"
    "\tldrh r0, [r1, 0x6]\n"
    "\tstrh r0, [r4, 0xE]\n"
    "\tldrh r0, [r1, 0x8]\n"
    "\tstrh r0, [r4, 0x10]\n"
    "\tldrh r0, [r1, 0xA]\n"
    "\tstrh r0, [r4, 0x12]\n"
    "\tldrb r0, [r1, 0x1]\n"
    "\tstr r0, [r4, 0x14]\n"
    "\tldrb r2, [r1, 0x1]\n"
    "\tldr r0, [r4, 0x18]\n"
    "\torrs r0, r2\n"
    "\tstr r0, [r4, 0x18]\n"
    "\tadds r1, 0xC\n"
    "\tstr r1, [r4, 0x2C]\n"
"_08005586:\n"
    "\tpop {r4}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}
#endif // NONMATCHING