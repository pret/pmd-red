#ifndef GUARD_GROUND_MAP_H
#define GUARD_GROUND_MAP_H

#include "structs/str_file_system.h"

typedef struct SubStruct_0
{
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    u8 fillC;
} SubStruct_0;

typedef struct SubStruct_3E0
{
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    OpenedFile *unk8;
    s32 unkC;
    s32 unk10;
    s32 unk12;
    s32 unk14;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
} SubStruct_3E0;

// size: 0x18?
typedef struct SubStruct_52C
{
    u8 fill0[8]; // 0x52C
    s16 unk8; // 0x534
    s16 unkA; // 0x536
    s16 unkC; // 0x538
    s16 unkE; // 0x53A
    s16 unk10; // 0x53C
    s16 unk12; // 0x53E
    void (*unk14)(void *, s32, void *, s32); // TODO: fix void * to proper ptr types 0x540
} SubStruct_52C;

#define UNK_0_ARR_COUNT 14
#define UNK_3E0_ARR_COUNT 2

#define UNK_54C_ARR_COUNT 2

// size: 0x55C
typedef struct unkStruct_3001B70
{
    SubStruct_0 unk0[UNK_0_ARR_COUNT];
    u8 fillUnk[0x300];
    SubStruct_3E0 unk3E0[UNK_3E0_ARR_COUNT];
    OpenedFile *unk430;
    OpenedFile *unk434;
    OpenedFile *unk438;
    OpenedFile *unk43C;
    OpenedFile *unk440;
    s16 unk444;
    u8 fill446[2];
    u8 unk448;
    u8 unk449;
    u8 unk44A;
    u8 unk44B;
    u8 unk44C;
    u8 unk44D;
    u8 fill44E[0x468-0x44E];
    s32 unk468;
    s32 unk46C;
    u8 unk470;
    u8 unk471;
    u8 fill472[0x52A-0x472];
    u8 unk52A;
    SubStruct_52C unk52C;
    void *unk544;
    void *unk548;
    void *unk54C[UNK_54C_ARR_COUNT];
    u16 *unk554[UNK_54C_ARR_COUNT];
} unkStruct_3001B70;

extern unkStruct_3001B70 *gGroundMapDungeon_3001B70;

void GroundMap_Reset(void);

void AllocGroundMapAction(void);
void FreeGroundMapAction(void);
void sub_80A4B38(void);
void sub_80A4B54(void);

#endif // GUARD_GROUND_MAP_H
