#ifndef GUARD_GROUND_MAP_H
#define GUARD_GROUND_MAP_H

#include "structs/str_file_system.h"
#include "structs/str_202EE8C.h"
#include "structs/str_position.h"

#define UNK_0_ARR_COUNT 14
#define UNK_E0_ARR_COUNT 32
#define UNK_3E0_ARR_COUNT 2
#define UNK_54C_ARR_COUNT 2
#define UNK_545_UNK6_ARR_COUNT 4

typedef struct SubStruct_0
{
    s16 unk0;
    s16 unk2;
    const void *unk4;
    const void *unk8;
    u8 fillC;
} SubStruct_0;

struct UnkFileStruct
{
    u8 unk0;
    s16 unk2;
    void *unk4[0]; // This is most likely wrong, will need to be fixed.
};

typedef struct SubStruct_3E0
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    OpenedFile *unk8;
    const struct UnkFileStruct *unkC;
    const void *unk10;
    const void *unk14;
    const void *unk18;
    const void *unk1C;
    void *unk20;
    u32 unk24;
} SubStruct_3E0;

typedef struct SubStruct_488
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    bool8 unk6;
    s32 unk8;
    s32 unkC;
    PixelPos unk10;
    void (*unk18)(struct SubStruct_488 *);
    u16 *unk1C;
    u16 *unk20[UNK_54C_ARR_COUNT];
    u16 *unk28[UNK_54C_ARR_COUNT];
    PixelPos unk30;
    PixelPos unk38;
    PixelPos unk40;
    PixelPos bgRegOffsets; // Either bg2 or bg3
} SubStruct_488;

// size: 0x18?
typedef struct SubStruct_52C
{
    s16 unk0; // 0x52C
    s16 unk2; // 0x52E
    s16 unk4; // 0x530
    s16 unk6; // 0x532
    s16 unk8; // 0x534
    s16 unkA; // 0x536
    s16 unkC; // 0x538
    s16 unkE; // 0x53A
    s16 unk10; // 0x53C
    s16 unk12; // 0x53E
    void (*unk14)(void *, const void *, void *, s32); // TODO: fix void * to proper ptr types 0x540
} SubStruct_52C;

typedef struct SubStruct_448
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u16 unk8;
    u16 unkA;
} SubStruct_448;

typedef struct SubStruct_545
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6[UNK_545_UNK6_ARR_COUNT];
    s16 unkE;
} SubStruct_545;

// size: 0x55C
typedef struct unkStruct_3001B70
{
    SubStruct_0 unk0[UNK_0_ARR_COUNT];
    unkStruct_202EE8C unkE0[UNK_E0_ARR_COUNT];
    SubStruct_3E0 unk3E0[UNK_3E0_ARR_COUNT];
    OpenedFile *unk430;
    OpenedFile *unk434;
    OpenedFile *unk438;
    OpenedFile *unk43C;
    OpenedFile *unk440;
    s16 unk444;
    SubStruct_448 unk448;
    SubStruct_545 unk454;
    s16 unk464[2];
    const void *unk468;
    const void *unk46C;
    u8 unk470;
    u8 unk471;
    s32 unk474;
    PixelPos unk478[UNK_54C_ARR_COUNT];
    struct SubStruct_488 unk488[UNK_54C_ARR_COUNT];
    u16 unk528;
    u8 unk52A;
    SubStruct_52C unk52C;
    u16 *unk544;
    u16 *unk548;
    u16 *unk54C[UNK_54C_ARR_COUNT];
    u16 *unk554[UNK_54C_ARR_COUNT];
} unkStruct_3001B70;

extern unkStruct_3001B70 *gGroundMapDungeon_3001B70;

void GroundMap_Reset(void);

void AllocGroundMapAction(void);
void FreeGroundMapAction(void);
void sub_80A4B38(void);
void sub_80A4B54(void);

#endif // GUARD_GROUND_MAP_H
