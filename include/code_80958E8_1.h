#ifndef GUARD_CODE_80958E8_1_H
#define GUARD_CODE_80958E8_1_H

#include "wonder_mail.h"

// size: 0x8
struct unkStruct_8096AF8
{
    bool8 unk0;
    /* 0x2 */ u16 clientSpecies;
    /* 0x4 */ u16 targetSpecies;
};

s32 CountJobsinDungeon(u8 dungeon);
WonderMail *GetJobSlotInfo(u8 index);

void sub_8096AF8(struct unkStruct_8096AF8 *, u8 slotIndex, u8 dungeon);

#endif // GUARD_CODE_80958E8_1_H