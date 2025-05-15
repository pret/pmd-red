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
#include "code_800ED38.h"

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
extern const char gUnknown_81177CC[];
extern const char gUnknown_81177D8[];
extern const char gUnknown_81177F4[];
extern const char gUnknown_8117864[];
extern const char gUnknown_81177EC[];
extern const char gUnknown_8117894[];
extern const char gUnknown_81178C0[];
extern const char *gUnknown_81178F4[];
extern const DebugLocation gUnknown_8117858;
extern const DebugLocation gUnknown_8117888;

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
                u32 id = r5 & 0xFF;
                file = OpenFileAndGetFileDataPtr(id[gUnknown_81178F4], &gOrnamentFileArchive);
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
    ptr->flags_0x50 = a1;
    ptr->unk6A = ((a1 & 4) ? 0x40 : 0) - ((a1 & 2) ? 0x40 : 0) + ((a1 & 1) ? 0x8 : 0) + 0x40;

    if (ptr->flags_0x50 & 0x8) {
        ptr->unk3C = gUnknown_2039DC0;
    }
    else {
        ptr->unk3C = gUnknown_2039DB0;
    }

    if (ptr->flags_0x50 & 0x20) {
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
    if (ptr->unk52 >= 0 && !(ptr->axdata.flags & 0x2000)) {
        return (ptr->axdata.flags & 0x8000) != 0;
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
    ptr->unk74.x = 0;
    ptr->unk74.y = 0;
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
        if (!sub_80A68F8(ptr, &ptr->unk48, -1) && !(ptr->flags_0x50 & 0x1000) && sub_80A6CF4(&ptr->unk48)) {
            sub_80A68F8(ptr, &ptr->unk48, -1);
        }
    }
    else {
        ptr->unk48.unk0 = -1;
        ptr->unk48.unk2 = 0;
        ptr->unk48.axmain = NULL;
    }
}

void sub_80A68A0(struct UnkGroundSpriteStruct *ptr)
{
    if ((ptr->flags_0x50 & 0x200) && ptr->unk58 != 0 && ptr->unk5C != -1) {
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

void GroundSprite_ExtendPaletteAdd(struct UnkGroundSpriteStruct *ptr, u16 a1)
{
    OpenedFile *file;
    s32 r8;
    unkStruct_3001B7C_sub108 *sub108Ptr;
    u16 var_28;
    u16 var_24;
    u16 r6;
    const void *r7;
    s32 r2;

    if (a1 & (0x100 | 0x200)) {
        if (a1 & 0x400) {
            sub108Ptr = &gUnknown_3001B7C->unk108[1];
            if (sub108Ptr->unk0 == a1) {
                sub108Ptr->unk2++;
                return;
            }
        }
        else {
            r8 = 0;
            sub108Ptr = &gUnknown_3001B7C->unk108[0];
            for (; r8 < UNK_3001B7C_SUB108_COUNT; r8++, sub108Ptr++) {
                if (sub108Ptr->unk0 == a1) {
                    u16 r1 = r8 + 29;
                    sub108Ptr->unk2++;
                    if (ptr != NULL) {
                        ptr->unk68 = r1 - 16;
                    }
                    Log(0, gUnknown_81177F4, r8, r1, r1 - 16, a1);
                    return;
                }
            }
        }

        if (a1 & 0x400) {
            r8 = 1;
            sub108Ptr = &gUnknown_3001B7C->unk108[1];
            if (sub108Ptr->unk2 > 0) {
                FatalError(&gUnknown_8117858, gUnknown_8117864, a1);
            }
        }
        else {
            r8 = 0;
            sub108Ptr = &gUnknown_3001B7C->unk108[0];
            for (; r8 < UNK_3001B7C_SUB108_COUNT; r8++, sub108Ptr++) {
                if (sub108Ptr->unk2 <= 0) {
                    break;
                }
            }

            if (r8 >= UNK_3001B7C_SUB108_COUNT) {
                FatalError(&gUnknown_8117888, gUnknown_8117864, a1);
            }
        }

        var_28 = r8 + 29;
        var_24 = (r8 * 16) + 464;
        if (a1 & 0x200) {
            file = OpenFileAndGetFileDataPtr(gUnknown_81177EC, &gMonsterFileArchive);
            r7 = file->data;
            r7 += (a1 & 0xFF) * 64;
        }
        else {
            u32 id = a1 & 0xff;
            file = OpenFileAndGetFileDataPtr(id[gUnknown_81178F4], &gOrnamentFileArchive);
            r7 = file->data;
        }

        if (a1 & 0x1000) {
            r6 = 1;
        }
        else {
            r6 = 0;
        }

        if (a1 & 0x2000) {
            r6 |= 2;
        }

        sub_80997F4(var_28, r6);
        sub_809971C(var_24, r7, 16);
        sub108Ptr->unk0 = a1;
        sub108Ptr->unk2 = 1;
        r2 = var_28 - 16;
        if (ptr != NULL) {
            ptr->unk68 = r2;
        }
        Log(0, gUnknown_8117894, r8, var_28, r2, a1, r6);
        if (file != NULL) {
            CloseFile(file);
        }
    }
    else {
        if (ptr != NULL) {
            ptr->unk68 = a1;
        }
    }
}

void GroundSprite_ExtendPaletteDelete(struct UnkGroundSpriteStruct *ptr)
{
    s32 r5;
    unkStruct_3001B7C_sub108 *sub108Ptr;

    if (ptr != NULL) {
        r5 = ptr->unk68 - 13;
        if (r5 < 0)
            return;
    }
    else {
        r5 = 1;
    }

    sub108Ptr = &gUnknown_3001B7C->unk108[r5];
    if (ptr != NULL) {
        ptr->unk68 = 0;
    }

    if (--sub108Ptr->unk2 <= 0) {
        Log(0, gUnknown_81178C0, r5, sub108Ptr->unk0);
        sub108Ptr->unk0 = 0;
        sub108Ptr->unk2 = 0;
        sub_80997F4(r5 + 29, 0);
    }
}

bool8 sub_80A6CF4(struct UnkGroundSpriteSubStructx48 *a0)
{
    struct UnkGroundSpriteStruct *spArray[UNK_3001B7C_SUB0_COUNT];
    s32 i;
    unkStruct_3001B7C_sub0 *sub0Ptr;
    PixelPos pixelPos;
    s32 count = 0;
    s32 r9 = a0->unk0;
    s32 r10 = 0;
    s32 var_28 = -1;
    s32 var_24 = -1;

    sub_809D248(&pixelPos);
    for (i = 0, sub0Ptr = &gUnknown_3001B7C->unk0[0]; i < UNK_3001B7C_SUB0_COUNT; i = (s16)(i+1), sub0Ptr++) {
        if (sub0Ptr->unk0 == 1) {
            struct UnkGroundSpriteStruct *ptr = sub0Ptr->unk8;

            if (!(ptr->flags_0x50 & 0x2000) && ptr->unk7C >= 0) {
                PixelPos resultPos;
                resultPos.x = (ptr->unk74.x / 256) - pixelPos.x;
                resultPos.y = (ptr->unk74.y / 256) - pixelPos.y;

                if (resultPos.y > 0) {
                    ptr->unk7C = 0x28 + resultPos.y;
                }
                else {
                    ptr->unk7C = 0x28 - resultPos.y;
                }

                if (resultPos.x > 0) {
                    if (resultPos.x > ptr->unk7C) {
                        ptr->unk7C = resultPos.x;
                    }
                }
                else {
                    if (-resultPos.x > ptr->unk7C) {
                        ptr->unk7C = -resultPos.x;
                    }
                }

                r10 += ptr->unk48.unk0;
                if (ptr->unk48.unk0 >= r9 && var_24 < ptr->unk7C) {
                    var_28 = count;
                    var_24 = ptr->unk7C;
                }
                spArray[count++] = ptr;
            }
        }
    }

    if (r10 < r9)
        return FALSE;
    if (var_28 >= 0) {
        sub_80A69FC(spArray[var_28]);
        return TRUE;
    }

    while (count > 0) {
        s32 i;
        s32 r5 = -1;
        s32 r3 = -1;
        s32 r6 = 0;

        for (i = 0; i < count; i++) {
            if (r3 < spArray[i]->unk7C) {
                r5 = count; // This looks like a mistake to me? I believe it should be r5 = i instead, however I cannot verify the behavior in-game as I can't find where, if anywhere, this function runs.
                r3 = spArray[i]->unk7C;
            }
        }
        sub_80A69FC(spArray[r5]);

        count--;
        for (i = r5; i < count; i++) {
            spArray[i] = spArray[i + 1];
        }

        for (i = 0, sub0Ptr = &gUnknown_3001B7C->unk0[0]; i < UNK_3001B7C_SUB0_COUNT; i++, sub0Ptr++) {
            if (sub0Ptr->unk0 == 0) {
                if (++r6 >= r9) {
                    return TRUE;
                }
            }
            else {
                r6 = 0;
            }
        }
    }

    return FALSE;
}

extern void sub_800E970(void);

extern PixelPos gUnknown_2039DD8;

void sub_80A6E68(void)
{
    ResetSprites(FALSE);
    nullsub_10(FALSE);
    sub_800E970();
}

void sub_80ABA7C(void);
void sub_80ACAD4(void);
void sub_80AD7AC(void);

void sub_80A6E80(void)
{
    DungeonPos pos;

    if (!sub_809D248(&gUnknown_2039DD8)) {
        gUnknown_2039DD8.x = 0;
        gUnknown_2039DD8.y = 0;
    }
    sub_80ABA7C();
    sub_80ACAD4();
    sub_80AD7AC();
    pos.x = gUnknown_2039DD8.x;
    pos.y = gUnknown_2039DD8.y;
    sub_800E90C(&pos);
    sub_8005180();
    nullsub_12();
}

void sub_80A6EC8(struct UnkGroundSpriteStruct *ptr, s32 a1)
{
    if (ptr->unk52 > 0) {
        if (a1 <= ptr->unk48.unk0) {
            a1 = ptr->unk48.unk0;
        }
        if (ptr->unk64 != a1) {
            ptr->unk66 = a1;
        }
    }
}

void sub_80A6EFC(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_)
{
    s32 flagResult;
    unkStruct_3001B7C_sub0 *sub0Ptr;
    s32 a1 = (s16) a1_;
    s32 a2 = (s8) a2_;

    if (ptr->unk52 < 0) {
        if (ptr->unk66 >= 0) {
            if (!sub_80A68F8(ptr, &ptr->unk48, ptr->unk66))
                return;
            ptr->unk66 = -1;
        }
        else {
            if (ptr->unk48.unk0 <= 0)
                return;
            if (!sub_80A68F8(ptr, &ptr->unk48, -1))
                return;
        }
    }
    else {
        if (ptr->unk66 >= 0) {
            sub_80A69FC(ptr);
            if (!sub_80A68F8(ptr, &ptr->unk48, ptr->unk66))
                return;
            ptr->unk66 = -1;
        }
    }

    // s16 memes...
    flagResult = a1 & 0x400;
    if ((s16)flagResult) {
        ptr->axdata.flags &= ~(0x1000);
        return;
    }

    sub0Ptr = &gUnknown_3001B7C->unk0[ptr->unk52];
    ptr->unk70 = 1;
    ptr->unk7C = -1;
    switch ((a1 & 0x700)) {
        case 0x300:
            ptr->unk6C = 0;
            break;
        case 0x100:
            ptr->unk6C = 0x80;
            break;
        case 0:
        default:
            ptr->unk6C = 0x100;
            break;
        case 0x200:
            ptr->unk6C = 0x200;
            break;
    }

    ptr->unk6E = 0;
    AxResInit(&ptr->axdata, ptr->unk48.axmain, (a1 & 0xFF) + a2 / 8, a2 & 7, sub0Ptr->unk4, 0, ((u16)a1 & 0x800) != 0);
}

void sub_80A7040(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_, s32 a3)
{
    s32 a1 = (s16) a1_;
    s32 a2 = (s8) a2_;

    if (!(ptr->flags_0x50 & 0x200))
        return;

    if (a1 == 0 || a1 == 0x1C0) {
        if (sub_80A671C(ptr)) {
            ptr->unk58 = 0x1C0;
        }
    }
    else {
        ptr->unk58 = a1;
        ptr->unk5A = a2;
        ptr->unk60 = a3;
    }
}

extern const unkStruct_2039DB0 gUnknown_81178E0;
void sub_80A72B8(struct UnkGroundSpriteStruct *ptr, bool8 a1);

bool8 sub_80A7094(struct UnkGroundSpriteStruct *ptr, PixelPos *r10, PixelPos *posArg, s32 a3)
{
    PixelPos resultPos;
    s32 unkY;

    ptr->unk74 = *posArg;
    ptr->unk7C = 0;
    if (ptr->flags_0x50 & 0x200 && ptr->unk58 != 0) {
        if (ptr->unk58 == 0x1C0) {
            if (ptr->unk5C != -1) {
                sub_800DC14(ptr->unk5C);
                ptr->unk5C = -1;
            }
            ptr->unk58 = 0;
        }
        else if (ptr->unk5C == -1) {
            unkStruct_2039DB0 unkSubStruct = gUnknown_81178E0;
            unkStruct_80416E0 unkStruct;

            sub_800EE5C(ptr->unk58);
            sub_800EF64();
            unkStruct.unk0 = ptr->unk58;
            unkStruct.unk4 = 0;
            unkStruct.dir = (s8) ptr->unk5A;
            unkStruct.x = posArg->x / 256;
            unkStruct.y = posArg->y / 256;
            unkStruct.unk10 = 0;
            unkStruct.unk12 = 0;
            unkStruct.unk14 = -1;
            unkStruct.unk18 = 0;
            unkStruct.unk1C = unkSubStruct;
            ptr->unk5C = sub_800E890(&unkStruct);
        }
        else if (!sub_800E9E4(ptr->unk5C)) {
            ptr->unk5C = -1;
            ptr->unk58 = 0;
        }
    }

    if (ptr->unk52 < 0)
        return FALSE;
    if (ptr->flags_0x50 & 0x40)
        return FALSE;

    resultPos = (PixelPos) {-1, -1};
    resultPos.x = (posArg->x / 256) - gUnknown_2039DD8.x;
    resultPos.y = (posArg->y / 256) - gUnknown_2039DD8.y;
    unkY = resultPos.y - (a3 / 256);
    if (resultPos.x >= -64 && resultPos.x <= 303 && resultPos.y >= -16 && resultPos.y <= 207 && unkY >= -16 && unkY <= 207) {
        if ((ptr->flags_0x50 & 0x10) && (gUnknown_2039DCC & 1)) {
            sub_80A72B8(ptr, FALSE);
            DoAxFrame_800558C(&ptr->axdata, 304, 208, 0, ptr->unk68, &ptr->unk3C);
            ptr->unk70 = 0;
            return FALSE;
        }
        else {
            sub_80A72B8(ptr, ptr->unk70);
            DoAxFrame_800558C(&ptr->axdata, resultPos.x, unkY, resultPos.y + ptr->unk6A, ptr->unk68, &ptr->unk3C);
            ptr->unk70 = 0;
            if (r10 != NULL) {
                *r10 = resultPos;
            }
            return TRUE;
        }
    }
    else if (ptr->unk70 != 0) {
        sub_80A72B8(ptr, TRUE);
        DoAxFrame_800558C(&ptr->axdata, 304, 208, 0, ptr->unk68, &ptr->unk3C);
        ptr->unk70 = 0;
        return FALSE;
    }
    else {
        return FALSE;
    }
}

void sub_80A72B8(struct UnkGroundSpriteStruct *ptr, bool8 a1)
{
    if (a1) {
        ptr->unk6E = 0;
        RunAxAnimationFrame(&ptr->axdata);
    }
    else {
        ptr->unk6E += ptr->unk6C;
        while (ptr->unk6E >= 0x100) {
            ptr->unk6E -= 0x100;
            RunAxAnimationFrame(&ptr->axdata);
        }
    }
}

bool8 sub_80A7310(struct UnkGroundSpriteStruct *ptr, PixelPos *posArg1, PixelPos *posArg2, s32 a3)
{
    if (ptr->flags_0x50 & 0x200 && ptr->unk5C != -1) {
        DungeonPos pos;
        s32 r7;

        pos.x = posArg1->x / 256;
        pos.y = posArg1->y / 256;
        r7 = (pos.y - gUnknown_2039DD8.y) + ptr->unk6A + 2;
        pos.y -= a3 / 256;
        if (posArg2 != NULL) {
            pos.x += posArg2->x;
            pos.y += posArg2->y;
        }

        sub_800E8AC(ptr->unk5C, &pos, NULL, r7, &ptr->unk3C);
        return TRUE;
    }
    else {
        return FALSE;
    }
}
