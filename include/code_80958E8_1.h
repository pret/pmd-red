#ifndef GUARD_CODE_80958E8_1_H
#define GUARD_CODE_80958E8_1_H

#include "structs/str_wonder_mail.h"

// size: 0x8
struct unkStruct_8096AF8
{
    bool8 unk0;
    /* 0x2 */ u16 clientSpecies;
    /* 0x4 */ u16 targetSpecies;
};

bool8 AcceptJob(WonderMail *mail);
s32 CountJobsinDungeon(u8 dungeon);
WonderMail *GetJobSlotInfo(u8 index);
s32 GetNumAcceptedJobs(void);
bool8 IsJobSlotEmpty(u8 index);
bool8 IsMailinJobSlot(WonderMail *mail);
void ResetJobSlot(u8 index);

bool8 sub_809693C(WonderMail *mail);
void sub_8096AF8(struct unkStruct_8096AF8 *, u8 slotIndex, u8 dungeon);
bool8 sub_8096C08(u8 *jobIndex);

// code_80958E8_1.s
extern WonderMail *GetPelipperBoardSlotInfo(u8);
extern bool8 IsPelipperBoardSlotEmpty(u8);

#endif // GUARD_CODE_80958E8_1_H