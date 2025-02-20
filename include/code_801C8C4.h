#ifndef GUARD_CODE_801C8C4_H
#define GUARD_CODE_801C8C4_H

#include "constants/item.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "structs/struct_sub80095e4.h"

// size: 0x554
struct unkStruct_203B244
{
    u32 unk0;
    /* 0x4 */ u8 itemIDs[NUMBER_OF_ITEM_IDS];
    u32 unkF4[NUMBER_OF_ITEM_IDS];
    /* 0x4B4 */ struct_Sub80095E4_2 unk4B4;
};

bool8 sub_801C8C4(s32, s32, DungeonPos *, u32);
u32 sub_801CA08(bool8);
u8 sub_801CB24(void);
void sub_801CB5C(bool8);
void sub_801CBB8(void);
void sub_801CCD8(void);
bool8 sub_801CF14(s32);
bool8 sub_801CF50(s32);
void sub_801CF94(void);
s32 sub_801CFB8(void);
u32 sub_801CFE0(u8 index);
struct unkStruct_203B244 *sub_801D008(void);

#endif // GUARD_CODE_801C8C4_H
