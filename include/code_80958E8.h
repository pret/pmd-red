#ifndef GUARD_CODE_80958E8_H
#define GUARD_CODE_80958E8_H

#include "constants/mailbox.h"
#include "structs/str_wonder_mail.h"

// size: 0xC
typedef struct subStruct_203B490
{
    WonderMailSub sub;
    /* 0x8 */ s32 checksum; // really dumb checksum that just adds all the fields of WonderMail struct
} subStruct_203B490;

// size: 0x32C?
typedef struct unkStruct_203B490
{
    /* 0x0 */ WonderMail mailboxSlots[NUM_MAILBOX_SLOTS];
    /* 0x50 */ WonderMail pelipperBoardJobs[MAX_ACCEPTED_JOBS];
    /* 0xF0 */ WonderMail jobSlots[MAX_ACCEPTED_JOBS];
    u8 unk190[40];
    u8 unk1B8[120];
    subStruct_203B490 unk230[16];
    /* 0x2F0 */ bool8 PKMNNewsReceived[NUM_POKEMON_NEWS];
    bool8 unk328;
} unkStruct_203B490;

extern unkStruct_203B490 *gUnknown_203B490;

void LoadMailInfo(void);
unkStruct_203B490 *GetMailInfo(void);
void InitializeMailJobsNews(void);
bool8 IsValidWonderMail(WonderMail *WonderMailData);
bool8 ValidateWonderMail(WonderMail *data);

#endif // GUARD_CODE_80958E8_H
