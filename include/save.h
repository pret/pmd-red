#ifndef SAVE_H
#define SAVE_H

#include "play_time.h"
#include "exclusive_pokemon.h"
#include "rescue_team_info.h"
#include "pokemon.h"
#include "item.h"

enum
{
    SAVE_COMPLETED,
    SAVE_NOT_WRTTEN,
    SAVE_FAILED
};

enum
{
    READ_SAVE_VALID,
    READ_SAVE_FAILED,
    READ_SAVE_CHECKSUM_ERROR
};


struct UnkStruct_sub_8011DAC {
    // size: 0x57D4
    u8 fill000[0x4];
    u8 unk004[0x400];
    u8 unk404[0x10]; // has "POKE_DUNGEON__05"
    u32 unk414;
    u32 unk418;
    u32 unk41C;
    u32 RngState;
    u32 savedRecruitedPokemon;
    u32 unk428;
    u8 fill42C[0x4];
    u32 unk430;
    u32 unk434;
    u32 savedFriendAreas;
    u32 unk43C;
    u32 unk440;
    u32 unk444;
    u8 unk448[0x538C];
};


struct UnkStruct_203B184 {
    /* 0x0 */ struct unkStruct_203B460 *MoneyItems;
    /* 0x4 */ struct unkStruct_203B45C *recruitedPokemon;
    /* 0x8 */ u8 *unk8;
    /* 0xC */ u8 *unkC;
    /* 0x10 */ u32 *unk10;
    /* 0x14 */ u32 *unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ struct RescueTeamData *RescueTeamInfo;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ struct ExclusivePokemonData *ExclusivePokemon;
    /* 0x28 */ bool8 *BoughtFriendAreas;
    /* 0x2C */ u32 gameOptions;
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

u32 sub_8011C1C(void);
void sub_8011C28(u32 in);
s32 sub_8011C34(void);
void sub_8011C40(s32 in);
char *sub_8011C4C(void);
void sub_8011CA8(u32 *out, s32 size);
u32 ReadSaveFromPak(u32 *a);
u32 sub_8011F9C(s32 *r0, u8 *dest, s32 size);
bool8 IsSaveCorrupted(void);
void sub_8012284(void);
void sub_8012298(void);
void sub_80122A8(void);
void PrepareSavePakRead(void);
bool8 ReadSavePak(void);
void FinishReadSavePak(void);
void PrepareSavePakWrite(s16 PokemonID);
bool8 WriteSavePak(void);
u32 GetSavePakStatus(void);
void FinishWriteSavePak(void);
bool8 ReadQuickSave(void);
bool8 IsQuickSaveValid(void);
void FinishQuickSaveRead(void);
void PrepareQuickSaveWrite(u8 *r0, u32 r1, u8 r2);
u32 WriteQuickSave(void);
void FinishQuickSaveWrite(void);

void sub_8012298();
void sub_80122D0();
void sub_80122F4();
void InitializePlayerData();
void sub_80122A8();

u32 ReadSaveSector(s32 *a, u8 *dest, s32 size);
u32 WriteSaveSector(s32 *a, u8 *src, s32 size);
void CalculateChecksum(u8 *out, u32 size);
bool8 ValidateChecksum(u8 *in, u32 size);

#endif
