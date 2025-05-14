#include "gba/defines.h"
#include "global.h"
#include "structs/axdata.h"
#include "code_800DAC0.h"
#include "debug.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "ground_map_1.h"
#include "ground_sprite.h"
#include "memory.h"
#include "sprite.h"

IWRAM_INIT unkStruct_3001B7C *gUnknown_3001B7C = {NULL};

EWRAM_DATA unkStruct_2039DB0 gUnknown_2039DB0 = {0};
EWRAM_DATA u32 sUnknown_2039DBC = {0}; // Unused, for alignment
EWRAM_DATA unkStruct_2039DB0 gUnknown_2039DC0 = {0};
EWRAM_DATA u16 gUnknown_2039DCC = {0};
EWRAM_DATA u16 gUnknown_2039DCE = {0};
EWRAM_DATA u8 gUnknown_2039DD0 = {0};
EWRAM_DATA u8 gUnknown_2039DD1[3] = {0, 0, 0}; // Unused, for alignment
EWRAM_DATA u32 gUnknown_2039DD4 = {0};

EWRAM_INIT OpenedFile *gUnknown_203B4B4 = {NULL};

// data_8115F5C.s
extern const u8 gUnknown_81177CC[];
extern const u8 gUnknown_81177D8[];
extern const u8 gUnknown_81177EC[];
extern const u8 *gUnknown_81178F4[];

// code_8098BDC.s
extern void sub_809971C(u16, const u8 *, s16);
extern void sub_80997F4(u16, u16);
// pokemon_2.s
extern void InitShadowSprites(u32, u32);

// ground_sprite.s
extern void sub_80A6460(void);

void sub_80A62F0(void)
{
    s32 r0;
    unkStruct_3001B7C_sub0 *sub0;
    unkStruct_3001B7C_sub108 *sub108;
    s32 r6;

    gUnknown_3001B7C = MemoryAlloc(sizeof(unkStruct_3001B7C), 6);
    gUnknown_203B4B4 = OpenFileAndGetFileDataPtr(gUnknown_81177CC, &gDungeonFileArchive);

    sub_800DAC0(1);

    sub0 = gUnknown_3001B7C->unk0;
    gUnknown_2039DD4 = 22;
    gUnknown_2039DD0 = 1;

    for (r0 = 0; r0 < 22; r0 = (s16)(r0 + 1), sub0++) {
        sub0->unk0 = 0;
        sub0->unk4 = r0 * 16;
        sub0->unk8 = 0;
    }

    sub108 = gUnknown_3001B7C->unk108;

    for (r6 = 0; r6 < 2; r6++, sub108++) {
        sub108->unk0 = 0;
        sub108->unk2 = 0;
        sub_80997F4(r6 + 29, 0);
    }

    GroundSprite_Reset(-1);
}

void GroundSprite_Reset(s16 a0)
{
    s32 uVar2;
    unkStruct_2039DB0 *bee;
    unkStruct_2039DB0 *see;

    uVar2 = a0;

    Log(0, gUnknown_81177D8);
    gUnknown_2039DCC = 0;
    gUnknown_2039DCE = 0;
    sub_80A6460();

    InitShadowSprites(496, sub_80A4D48(uVar2) ? 3 : 2);

    bee = &gUnknown_2039DB0;
    sub_8004E8C(bee);
    see = &gUnknown_2039DC0;
    sub_8004E8C(see);

    see->unk4 &= ~(0x400 | 0x800);
    see->unkA &= ~(0x400 | 0x800);
    see->unkA |= 0x800;

    if (sub_80A4D48(a0)) {
        bee->unk4 &= ~(0x400 | 0x800);
        bee->unkA &= ~(0x400 | 0x800);
        bee->unkA |= (0x400 | 0x800);
    }
    else {
        bee->unk4 &= ~(0x400 | 0x800);
        bee->unkA &= ~(0x400 | 0x800);
        bee->unkA |= 0x800;
    }

    ResetSprites(TRUE);
    nullsub_10(TRUE);
}

void sub_80A6460(void)
{
    OpenedFile *file;
    s32 i;
    const u8 *data;
    u16 something;

    file = OpenFileAndGetFileDataPtr(gUnknown_81177EC, &gMonsterFileArchive);

    something = 0x100;
    data = file->data;

    for (i = 0; i < 13; i++) {
        sub_809971C(something, data, 0x10);
        something += 0x10;
        data += 0x40;
    }

    CloseFile(file);
}

void sub_80A64A4(void)
{
    const u8 *r2;
    u16 r4;
    u32 r5;
    OpenedFile *file;
    unkStruct_3001B7C_sub108 *r7;
    s32 i;
    s16 r9;
    u16 sl;
    u16 flag;
    u16 flag2;

    r7 = gUnknown_3001B7C->unk108;
    sub_80A6460();

    for (i = 0; i < 2; i++, r7++)
    {
        if (r7->unk2 > 0) {
            r5 = r7->unk0;
            sl = i + 29;
            r9 = 0x1D0 + i * 16;

            flag = r5 & 0x200;
            if (flag) {
                file = OpenFileAndGetFileDataPtr(gUnknown_81177EC, &gMonsterFileArchive);
                r2 = file->data + (r5 & 0xFF) * 0x40;
            }
            else {
                file = OpenFileAndGetFileDataPtr((r5 & 0xFF)[gUnknown_81178F4], &gOrnamentFileArchive);
                r2 = file->data;
            }

            flag2 = r5 & 0x1000;
            r4 = flag2 != 0;

            flag = r5 & 0x2000;
            if (flag)
                r4 |= 2;

            sub_809971C(r9, r2, 16);
            sub_80997F4(sl, r4);

            if (file != NULL)
                CloseFile(file);
        }
    }
}

void sub_80A658C(void)
{
    sub_800DB7C();
    ResetSprites(FALSE);
    nullsub_10(FALSE);
    sub_8005180();
    nullsub_12();
    CopySpritesToOam();
    nullsub_13();
    sub_8005304();
    nullsub_14();
    CloseFile(gUnknown_203B4B4);
    MemoryFree(gUnknown_3001B7C);
    gUnknown_3001B7C = NULL;
}

UNUSED static u16 sub_80A65D8(u16 *a0)
{
    return a0[40];
}

u16 sub_80A65E0(u32 a0)
{
    return (a0 >> 16) & 0x337F;
}

void sub_80A65F0(struct UnkGroundSpriteStruct *ptr, u16 a1)
{
    ptr->unk50 = a1;
    ptr->unk6A = ((a1 & 4) ? 0x40 : 0) - ((a1 & 2) ? 0x40 : 0) + ((a1 & 1) ? 0x8 : 0) + 0x40;

    if (ptr->unk50 & 0x8) {
        ptr->unk3C = gUnknown_2039DC0;
    }
    else {
        ptr->unk3C = gUnknown_2039DB0;
    }

    if (ptr->unk50 & 0x20) {
        ptr->unk3C.unk0 &= 0xF3FF;
        ptr->unk3C.unk6 &= 0xF3FF;
        ptr->unk3C.unk6 |= 0x400;
    }
}

void sub_80A6688(struct UnkGroundSpriteStruct *ptr, s32 a0)
{
    sub_80A65F0(ptr, sub_80A65E0(a0));
}

bool8 SpriteHasPokemonSize_80A66A4(struct UnkGroundSpriteStruct *ptr)
{
    return (ptr->unk48.unk0 > 0);
}

UNUSED static bool8 sub_80A66BC(struct UnkGroundSpriteStruct *ptr)
{
    if (ptr->unk52 >= 0)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_80A66D4(struct UnkGroundSpriteStruct *ptr)
{
    if (ptr->unk52 < 0 && ptr->unk48.unk0 > 0)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_80A66F8(struct UnkGroundSpriteStruct *ptr)
{
    if (ptr->unk52 >= 0 && !(ptr->unk0 & 0x2000)) {
        return (ptr->unk0 & 0x8000) != 0;
    }
    return FALSE;
}

bool8 sub_80A671C(struct UnkGroundSpriteStruct *ptr)
{
    if (ptr->unk58 != 0) {
        if (ptr->unk58 == 0x1C0)
            return TRUE;
        if (ptr->unk5C == -1)
            return TRUE;
        if (sub_800E9E4(ptr->unk5C))
            return TRUE;
        ptr->unk5C = -1;
        ptr->unk58 = 0;
    }
    return FALSE;
}

extern u8 sub_809D248(PixelPos *r0);

bool8 IsOnscreen_80A675C(struct UnkGroundSpriteStruct *ptr, PixelPos *pixPosArg)
{
    PixelPos result;
    PixelPos pixelPos;

    if (sub_809D248(&pixelPos)) {
        result.x = (pixPosArg->x / 256) - pixelPos.x;
        result.y = (pixPosArg->y / 256) - pixelPos.y;
    }
    else {
        result.x = (pixPosArg->x / 256);
        result.y = (pixPosArg->y / 256);
    }

    if (result.x >= -64 && result.x <= 303 && result.y >= -16 && result.y <= 207) {
        return TRUE;
    }

    return FALSE;
}

bool8 sub_80A68F8(struct UnkGroundSpriteStruct *ptr, struct UnkGroundSpriteSubStructx48 *a1, s32 a2);
bool8 sub_80A6CF4(struct UnkGroundSpriteSubStructx48 *a0);
void sub_80A69FC(struct UnkGroundSpriteStruct *ptr);

void sub_80A67CC(struct UnkGroundSpriteStruct *ptr, struct UnkGroundSpriteSubStructx48 *a1, s32 a2)
{
    bool8 r7;

    if (a1 != NULL && a1->unk0 > 0) {
        r7 = TRUE;
    }
    else {
        r7 = FALSE;
    }

    sub_80A65F0(ptr, sub_80A65E0(a2));
    ptr->unk74 = 0;
    ptr->unk78 = 0;
    ptr->unk7C = -1;
    ptr->unk70 = 0;
    ptr->unk6C = 0;
    ptr->unk6E = 0;
    ptr->unk52 = -1;
    ptr->unk54 = NULL;
    ptr->unk64 = 0;
    ptr->unk66 = -1;
    ptr->unk68 = 0;
    ptr->unk58 = 0;
    ptr->unk5A = 0xFF;
    ptr->unk5C = -1;
    ptr->unk60 = -1;
    if (r7) {
        ptr->unk48 = *a1;
        if (!sub_80A68F8(ptr, &ptr->unk48, -1) && !(ptr->unk50 & 0x1000) && sub_80A6CF4(&ptr->unk48)) {
            sub_80A68F8(ptr, &ptr->unk48, -1);
        }
    }
    else {
        ptr->unk48.unk0 = -1;
        ptr->unk48.unk2 = 0;
        ptr->unk48.unk4 = 0;
    }
}

void sub_80A68A0(struct UnkGroundSpriteStruct *ptr)
{
    if ((ptr->unk50 & 0x200) && ptr->unk58 != 0 && ptr->unk5C != -1) {
        sub_800DC14(ptr->unk5C);
    }
    if (ptr->unk54 != NULL) {
        CloseFile(ptr->unk54);
        ptr->unk54 = NULL;
    }
    sub_80A69FC(ptr);
}

// I guess the code inside the loop was commented out or under an ifdef.
UNUSED static void sub_80A68E8(void)
{
    s32 i;
    for (i = 0; i < UNK_3001B7C_SUB0_COUNT; i++) {
        ;
    }
}

void GroundSprite_ExtendPaletteAdd(struct UnkGroundSpriteStruct *ptr, u16);
void GroundSprite_ExtendPaletteDelete(struct UnkGroundSpriteStruct *ptr);

bool8 sub_80A68F8(struct UnkGroundSpriteStruct *ptr, struct UnkGroundSpriteSubStructx48 *a1, s32 a2)
{
    s32 id, count;
    unkStruct_3001B7C_sub0 *unkPtr = &gUnknown_3001B7C->unk0[0];

    if (a1->unk0 >= a2) {
        a2 = a1->unk0;
        count = 0;
        for (id = 0; id < UNK_3001B7C_SUB0_COUNT; id = (s16)(id + 1), unkPtr++) {
            if (unkPtr->unk0 == 0) {
                if (++count >= a2) {
                    unkPtr -= count - 1;
                    id = (s16) (id - (count - 1));
                    break;
                }
            }
            else {
                count = 0;
            }
        }
    }
    else {
        count = 0;
        id = UNK_3001B7C_SUB0_COUNT - 1;
        unkPtr = &gUnknown_3001B7C->unk0[UNK_3001B7C_SUB0_COUNT - 1];
        for (; id >= 0; id = (s16)(id - 1), unkPtr--) {
            if (unkPtr->unk0 == 0) {
                if (++count >= a2) {
                    break;
                }
            }
            else {
                count = 0;
            }
        }
    }

    if (count >= a2) {
        s32 i;
        ptr->unk52 = id;
        ptr->unk64 = a2;
        unkPtr->unk0 = 1;
        unkPtr->unk8 = ptr;
        GroundSprite_ExtendPaletteAdd(ptr, a1->unk2);
        for (i = 1; i < a2; i++) {
            unkPtr[i].unk0 = 2;
        }

        gUnknown_2039DD4 -= a2;
        return TRUE;
    }
    else {
        gUnknown_2039DD0 = 0;
        ptr->unk7C = -1;
        ptr->unk70 = 0;
        ptr->unk52 = -1;
        ptr->unk64 = 0;
        ptr->unk6C = 0;
        ptr->unk6E = 0;
        return FALSE;
    }
}

void sub_80A69FC(struct UnkGroundSpriteStruct *ptr)
{
    s32 id = ptr->unk52;
    unkStruct_3001B7C_sub0 *unkPtr = &gUnknown_3001B7C->unk0[id];

    if (id >= 0) {
        GroundSprite_ExtendPaletteDelete(ptr);
        unkPtr->unk8 = NULL;
        unkPtr->unk0 = 0;
        unkPtr++;
        gUnknown_2039DD4++;
        id = (s16)(id + 1);
        for (; id < UNK_3001B7C_SUB0_COUNT && unkPtr->unk0 == 2; id = (s16)(id + 1)) {
            unkPtr->unk0 = 0;
            unkPtr++;
            gUnknown_2039DD4++;
        }

        ptr->unk52 = -1;
        ptr->unk64 = 0;
        gUnknown_2039DD0 = 1;
    }
}
