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


// size: 0x8
struct unkStruct_8096AF8
{
    bool8 unk0;
    /* 0x2 */ u16 clientSpecies;
    /* 0x4 */ u16 targetSpecies;
};

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
s32 CountFilledMailboxSlots(void);
WonderMail *GetMailboxSlotInfo(u8 index);
bool8 IsMailSlotEmpty(u8 index);
void ResetMailboxSlot(u8 index);
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
WonderMail *GetPelipperBoardSlotInfo(u8);
bool8 IsPelipperBoardSlotEmpty(u8);
void ResetPelipperBoardSlot(u8);
void sub_80965F4(void);
void sub_8096C80(void);
void ReceivePKMNNews(u8 index);
bool8 CheckPKMNNewsSlot(u8 index);
void SortJobSlots(void);
u8 *sub_8096DD8(void);
u8 *sub_8096DE8(void);
u8 sub_8096E2C(void);
void sub_8096EEC(WonderMail *mail);

#endif // GUARD_CODE_80958E8_H
