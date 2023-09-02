#include "global.h"
#include "code_800558C.h"
#include "code_800DAC0.h"
#include "debug.h"
#include "file_system.h"
#include "ground_map_1.h"
#include "ground_sprite.h"
#include "memory.h"
#include "sprite.h"

extern unkStruct_2039DB0 gUnknown_2039DB0;
extern unkStruct_2039DB0 gUnknown_2039DC0;
extern u16 gUnknown_2039DCC;
extern u16 gUnknown_2039DCE;
extern u8 gUnknown_2039DD0;
extern u32 gUnknown_2039DD4;
extern OpenedFile *gUnknown_203B4B4;
extern unkStruct_3001B7C *gUnknown_3001B7C;

// dungeon_sbin.s
extern const struct FileArchive gDungeonFileArchive;
// monster_sbin.s
extern const struct FileArchive gMonsterFileArchive;
// ornament_sbin.s
extern const struct FileArchive gOrnamentFileArchive;
// data_8115F5C.s
extern const u8 gUnknown_81177CC[];
extern const u8 gUnknown_81177D8[];
extern const u8 gUnknown_81177EC[];
extern const u8 *gUnknown_81178F4[];

// code_8098BDC.s
extern void sub_809971C(u16, u8 *, s16);
extern void sub_80997F4(u16, u16);
// pokemon_2.s
extern void sub_808E53C(u32, u32);

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

    sub_808E53C(496, sub_80A4D48(uVar2) ? 3 : 2);

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
    u8 *data;
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
    u8 *r2;
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
    nullsub_10(0);
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

// Unused
u16 sub_80A65D8(u16 *a0)
{
    return a0[40];
}

u16 sub_80A65E0(u32 a0)
{
    return (a0 >> 16) & 0x337F;
}