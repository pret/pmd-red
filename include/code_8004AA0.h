#ifndef GUARD_CODE_8004AA0_H
#define GUARD_CODE_8004AA0_H

#include "file_system.h"
#include "menu_input.h"
#include "structs/rgb.h"
#include "structs/axdata.h"
#include "structs/str_position.h"

// size: 0x18
typedef struct unkStruct_202EE8C
{
    u32 unk0;
    u16 unk4;
    s16 unk6;
    RGB *unk8;
    RGB *unkC;
    RGB *unk10;
    RGB unk14;
} unkStruct_202EE8C;

extern unkStruct_202EE8C gUnknown_202EE8C[32];

struct FiendArea
{
    const u8 *name;
    DungeonPos unk4;
    u8 unk8[8];
    s16 unk10[8];
};

struct UnkStruct_4018
{
    u8 unk4018;
    s16 unk2[8];
    axdata unk14;
};

// size: 0x4DD8
struct UnkBgStruct
{
    OpenedFile *unk0[5];
    u16 unk14[64][64];
    u16 unk2014[64][64];
    const struct FiendArea *unk4014;
    struct UnkStruct_4018 unk4018[32];
    s32 unk4A18;
    s32 unk4A1C;
    s32 unk4A20;
    s32 unk4A24;
    s32 unk4A28;
    u8 unk4A2C;
    axdata unk4A30[8];
    axdata unk4C10;
    unkStruct_202EE8C unk4C4C[16];
    s32 unk4DCC;
    u32 unk4DD0;
    DungeonPos unk4DD4;
    DungeonPos unk4DD8;
    s32 unk4DDC;
    s32 unk4DE0;
    s32 unk4DE4;
    s32 unk4DE8;
    u8 unk4DEC[8];
    u8 unk4DF4;
    s32 unk4DF8;
    MenuInputStruct unk4DFC;
};

extern struct UnkBgStruct *gUnknown_203B0E4;

// size: Variable
typedef struct unkDataFor8004AA4
{
    /* 0x0 */ s16 colorCount;
    s16 unk2;
    /* 0x4 */ RGB colors[0];
} unkDataFor8004AA4;

void nullsub_6(void);
void sub_8004AA4(unkStruct_202EE8C *, OpenedFile *, s32);
bool8 sub_8004AF0(bool8, unkStruct_202EE8C *, s32, s32, s32, const RGB *);
bool8 sub_8004D14(unkStruct_202EE8C *, s32);
bool8 sub_8004D40(unkStruct_202EE8C *, s32);

#endif // GUARD_CODE_8004AA0_H
