#ifndef GUARD_CODE_80958E8_H
#define GUARD_CODE_80958E8_H

#include "constants/mailbox.h"
#include "structs/str_pokemon.h"
#include "structs/str_wonder_mail.h"
#include "data_serializer.h"

// size: 0xC
typedef struct subStruct_203B490
{
    DungeonMailSeed dungeonSeed;
    /* 0x8 */ s32 checksum; // really dumb checksum that just adds all the fields of WonderMail struct
} subStruct_203B490;


// size: 0x8
struct unkStruct_8096AF8
{
    bool8 unk0;
    /* 0x2 */ s16 clientSpecies;
    /* 0x4 */ s16 targetSpecies;
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

bool8 AcceptJob(WonderMail *mail);
bool8 CheckPKMNNewsSlot(u8 index);
s32 CountFilledMailboxSlots(void);
s32 CountJobsinDungeon(u8 dungeon);
void GeneratePelipperJobs(void);
WonderMail *GetJobSlotInfo(u8 index);
WonderMail *GetMailboxSlotInfo(u8 index);
unkStruct_203B490 *GetMailInfo(void);
s32 GetNumAcceptedJobs(void);
WonderMail *GetPelipperBoardSlotInfo(u8);
void InitializeMailJobsNews(void);
bool8 IsJobSlotEmpty(u8 index);
bool8 IsMailinJobSlot(WonderMail *mail);
bool8 IsMailSlotEmpty(u8 index);
bool8 IsPelipperBoardSlotEmpty(u8);
bool8 IsValidWonderMail(WonderMail *WonderMailData);
void LoadMailInfo(void);
void ReadWonderMailBits(DataSerializer *a, WonderMail *b);
void ReceivePKMNNews(u8 index);
void ResetJobSlot(u8 index);
void ResetMailbox(void);
void ResetMailboxSlot(u8 index);
void ResetPelipperBoardSlot(u8);
u32 RestoreMailInfo(u8 *r0, u32 size);
u32 SaveMailInfo(u8 *r0, u32 size);
void ShiftJobSlotsDown(void);
void ShiftMailboxSlotsDown(void);
void ShiftPelipperJobsDown(void);
void SortJobSlots(void);
void sub_80961B4(void);
bool8 sub_80961D8(void);
void sub_80963FC(void);
void sub_8096488(void);
bool8 sub_80964B4(void);
bool8 sub_80964E4(void);
bool8 sub_809693C(WonderMail *mail);
bool8 sub_8096A08(u8 dungeon, Pokemon *pokemon);
void sub_8096AF8(struct unkStruct_8096AF8 *, u8 slotIndex, u8 dungeon);
void sub_8096BD0(void);
bool8 sub_8096C08(u8 *jobIndex);
u8 *sub_8096DD8(void);
u8 *sub_8096DE8(void);
u8 sub_8096E2C(void);
void sub_8096EEC(WonderMail *mail);
bool8 sub_8096F50(WonderMail *mail);
bool8 ValidateWonderMail(WonderMail *data);
void WriteWonderMailBits(DataSerializer *a, WonderMail *b);

#endif // GUARD_CODE_80958E8_H
