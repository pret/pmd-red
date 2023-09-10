#ifndef GUARD_CODE_80958E8_H
#define GUARD_CODE_80958E8_H

#include "wonder_mail.h"
#include "constants/mailbox.h"

// size: 0xC
typedef struct subStruct_203B490
{
    /* 0x0 */ DungeonLocation dungeon;
    /* 0x4 */ u32 seed;
    u32 unk8;
} subStruct_203B490;

// size: 0x32C?
typedef struct unkStruct_203B490
{
    /* 0x0 */ WonderMail mailboxSlots[NUM_MAILBOX_SLOTS];
    /* 0x50 */ WonderMail pelipperBoardJobs[MAX_ACCEPTED_JOBS];
    /* 0xF0 */ WonderMail jobSlots[MAX_ACCEPTED_JOBS];
    u8 unk190[0x28];
    u8 unk1B8[0x78];
    subStruct_203B490 unk230[16];
    /* 0x2F0 */ u8 PKMNNewsReceived[NUM_POKEMON_NEWS];
    bool8 unk328;
} unkStruct_203B490;

extern unkStruct_203B490 *gUnknown_203B490;

#endif // GUARD_CODE_80958E8_H