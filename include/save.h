#ifndef GUARD_SAVE_H
#define GUARD_SAVE_H

#include "game_options.h"
#include "play_time.h"
#include "exclusive_pokemon.h"
#include "rescue_team_info.h"
#include "pokemon.h"
#include "items.h"
#include "code_8094F88.h"
#include "code_80958E8.h"

enum
{
    SAVE_NO_STATUS = -1,
    SAVE_COMPLETED,
    SAVE_NOT_WRTTEN,
    SAVE_FAILED,
    SAVE_UNK3
};

enum
{
    READ_SAVE_VALID,
    READ_SAVE_FAILED,
    READ_SAVE_CHECKSUM_ERROR
};

// size: 0x57D4
struct UnkStruct_sub_8011DAC
{
    u8 fill000[0x4];
    u8 unk004[0x400];
    u8 gameInternalName[0x10]; // has "POKE_DUNGEON__05"
    u32 checksum;
    u32 unk418;
    u32 unk41C;
    u32 RngState;
    u32 savedRecruitedPokemon;
    u32 unk428;
    u8 fill42C[0x4];
    u32 savedTeamInventory;
    u32 savedRescueTeamInfo;
    u32 savedFriendAreas;
    u32 unk43C;
    u32 unk440;
    u32 savedMailInfo;
    u8 unk448[0x538C];
};

// size: 0x5C
// This is most likely a debug savestate
struct UnkStruct_203B184
{
    /* 0x0 */ TeamInventory *MoneyItems;
    /* 0x4 */ RecruitedMon *recruitedPokemon;
    /* 0x8 */ unkStruct_203B480 *unk8;
    /* 0xC */ unkStruct_203B484 *unkC;
    /* 0x10 */ u32 *unk10;
    /* 0x14 */ unkStruct_203B48C *unk14;
    /* 0x18 */ unkStruct_203B490 *mailInfo;
    /* 0x1C */ struct RescueTeamData *RescueTeamInfo;
    /* 0x20 */ struct unkStruct_203B494 *unk20;
    /* 0x24 */ struct ExclusivePokemonData *ExclusivePokemon;
    /* 0x28 */ bool8 *BoughtFriendAreas;
    /* 0x2C */ GameOptions *gameOptions;
    /* 0x30 */ struct PlayTimeStruct *playTime;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u8 *unk04C;
    u32 unk050;
    u32 unk054;
    u32 RngState;
};

void nullsub_33(void);
u32 sub_8011C1C(void);
void sub_8011C28(u32 in);
s32 sub_8011C34(void);
void sub_8011C40(s32 in);
void sub_8011CA8(u32 *out, s32 size);
u32 ReadSaveFromPak(u32 *a);
u32 WriteSavetoPak(s32 *param_1, u32 param_2);
u32 sub_8011F9C(s32 *r0, u8 *dest, s32 size);
u32 sub_8011FA8(void);
bool8 IsSaveCorrupted(void);
void sub_8012284(void);
void sub_8012298(void);
void sub_80122A8(void);

void sub_8012298();
void sub_80122D0();
void sub_80122F4();
void InitializePlayerData();
void sub_80122A8();

u32 ReadSaveSector(s32 *a, u8 *dest, s32 size);
u32 WriteSaveSector(s32 *a, u8 *src, s32 size);
void CalculateChecksum(u8 *out, u32 size);
bool8 ValidateChecksum(u8 *in, u32 size);

s32 sub_80121D4(s32 *a, u8 *src, s32 size);
u32 sub_80121E0(u32);

#endif // GUARD_SAVE_H
