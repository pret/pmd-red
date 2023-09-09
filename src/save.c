#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_8097670.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "flash.h"
#include "friend_area.h"
#include "game_options.h"
#include "memory.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"

EWRAM_DATA_2 u32 gUnknown_203B17C = {0};
EWRAM_DATA_2 char *gUnknown_203B180 = {0};
EWRAM_DATA_2 struct UnkStruct_203B184 *gUnknown_203B184 = {0};
extern GameOptions *gGameOptionsRef;

// size: 0x800
struct unk_struct
{
    u32 unk0;
    u8 gameInternalName[16]; // has "POKE_DUNGEON__05
    u32 checksum;
    u32 unk18;
    DungeonLocation dungeonLocation;
    u32 unk20;
    u32 padding[503];
};


extern s32 gUnknown_202DE28;
extern u32 *gUnknown_203B488;

ALIGNED(4) static const char debug_fill8[] = "pksdir0";
ALIGNED(4) const char sGameInternalVersion[] = _("POKE_DUNGEON__05");

ALIGNED(4) static const char fill_save0[] = _("pksdir0");
ALIGNED(4) static const char fill_save1[] = _("pksdir0");
ALIGNED(4) static const char fill_save2[] = _("pksdir0");


extern bool8 sub_800DAB0(u16, u8*, s32);
extern bool8 sub_800DAB4(u16, u8*, s32);
extern bool8 sub_800DAB8(void);
extern u32 SaveRecruitedPokemon(u8 *, u32);
extern u32 RestoreRecruitedPokemon(void* a, s32 b);
extern u32 SavePokemonStruct2(u8 *, u32);
extern u32 RestorePokemonStruct2(void* a, s32 b);
extern u32 sub_80921C4(u8 *, u32);
extern u32 sub_80954CC(void* a, s32 b);
extern u32 sub_8095624(u8 *, u32);
extern u32 RestoreMailInfo(void* a, s32 b);
extern u32 SaveMailInfo(u8 *, u32);
extern u32 sub_8097D60(u8 *, u32);
extern u32 sub_8097D98(void* a, s32 b);
extern void sub_800135C(void);
extern void sub_80958E4(u32 *a, u32 b);
extern unkStruct_203B490 *GetMailInfo(void);
extern void InitializeMailJobsNews(void);
extern void sub_80972F4(void);
extern void sub_80974E8(void);

u32 sub_8011C1C(void)
{
    return gUnknown_203B17C;
}

void sub_8011C28(u32 in)
{
    gUnknown_203B17C = in;
}

s32 sub_8011C34(void)
{
    return gUnknown_202DE28;
}

void sub_8011C40(s32 in)
{
    gUnknown_202DE28 = in;
}

char *GetGameInternalName(void)
{
    return gUnknown_203B180; // returns POKE_DUNGEON__05
}

void CalculateChecksum(u8 *out, u32 size)
{
    u32 checksum = 0;
    s32 i = size / 4;
    if (i > 1)
    {
        u32 *ptr = (u32 *)&out[4];
        --i;
        do
            checksum += *ptr++;
        while (--i);
    }
    *(u32 *)out = checksum;
}

bool8 ValidateChecksum(u8 *in, u32 size)
{
    u32 checksum = 0;
    s32 i = size / 4;
    if (i > 1)
	{
        u32 *ptr = (u32 *)&in[4];
        --i;
        do
            checksum += *ptr++;
        while (--i);
	}
    if (*(u32 *)in != checksum)
        return TRUE;
    return FALSE;
}

void sub_8011CA8(u32 *out, s32 size)
{
    if (gUnknown_203B184 == NULL) {
        AGB_WARNING("A warning most likely went here.");
        *out += (size + 0xFFF) / 0x1000;
    } else {
        *out += (size + 0xFFF) / 0x1000;
    }
}

u32 WriteSaveSector(s32 *a, u8 *src, s32 size)
{
    u32 r1;
    s32 sector = *a;
    sub_8011CA8(a, size);
    CalculateChecksum(src, size);
    if (gUnknown_203B184 == NULL) {
        r1 = WriteFlashData(sector, src, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB4(sector, src, size)) {
            r1 = 3;
        }
        else {
            r1 = 0;
        }
    }
    else {
        return SAVE_FAILED;
    }
    if (r1 == 4) {
        return SAVE_NOT_WRTTEN;
    }
    if (r1) {
        return SAVE_FAILED;
    }
    return SAVE_COMPLETED;
}

u32 ReadSaveSector(s32 *a, u8 *dest, s32 size)
{
    u32 r1;
    s32 sector = *a;
    sub_8011CA8(a, size);
    if (gUnknown_203B184 == NULL) {
        r1 = ReadFlashData(sector, dest, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB0(sector, dest, size)) {
            r1 = 1;
        }
        else {
            r1 = 0;
        }
    }
    else {
        return READ_SAVE_FAILED;
    }
    if (r1) {
        return READ_SAVE_FAILED;
    }
    if (ValidateChecksum(dest, size)) {
        return READ_SAVE_CHECKSUM_ERROR;
    }
    return READ_SAVE_VALID;
}

UNUSED static bool8 sub_8011DA8(void)
{
    return TRUE;
}

u32 ReadSaveFromPak(u32 *a)
{
    struct UnkStruct_sub_8011DAC *playerSave = MemoryAlloc(sizeof(struct UnkStruct_sub_8011DAC), 5);
    u8 *r4 = playerSave->unk448;
    u32 saveStatus = ReadSaveSector(a, (u8*)playerSave, sizeof(struct UnkStruct_sub_8011DAC));
    u32 r1;
    if (saveStatus)
    {
        saveStatus = ReadSaveSector(a, (u8*)playerSave, sizeof(struct UnkStruct_sub_8011DAC));
    }
    else
    {
        sub_8011CA8(a, sizeof(struct UnkStruct_sub_8011DAC));
    }
    if (!saveStatus)
    {
        if (playerSave->checksum != 0x5071412) {
            saveStatus = 4;
        }
    }
    if (!saveStatus)
    {
        if (gUnknown_203B184 == NULL) {
            sub_8011C28(playerSave->unk41C);
            sub_8011C40(playerSave->unk418);
            SetRNGSeed(playerSave->RngState);
        }
        else {
            gUnknown_203B184->unk054 = playerSave->unk41C;
            gUnknown_203B184->unk050 = playerSave->unk418;
            gUnknown_203B184->RngState = playerSave->RngState;
        }
    }
    if (!saveStatus)
    {
        if (gUnknown_203B184 == NULL) {
            if (!sub_8002718(playerSave->unk004)) {
                saveStatus = 4;
            }
        }
        else {
            MemoryCopy8(gUnknown_203B184->unk04C, playerSave->unk004, ARRAY_COUNT(playerSave->unk004));
        }
    }
    if (!saveStatus)
    {
        r1 = RestoreRecruitedPokemon(r4, 0x4650);
        if (r1 != playerSave->savedRecruitedPokemon) {
            saveStatus = 3;
        }
        r4 += 0x4650;
        r1 = RestorePokemonStruct2(r4, 0x258);
        if (r1 != playerSave->unk428) {
            saveStatus = 3;
        }
        r4 += 0x258;
        r1 = RestoreTeamInventory(r4, 0x1D8);
        if (r1 != playerSave->savedTeamInventory) {
            saveStatus = 3;
        }
        r4 += 0x1d8;
        r1 = ReadRescueTeamInfo(r4, 0x10);
        if (r1 != playerSave->savedRescueTeamInfo) {
            saveStatus = 3;
        }
        r4 += 0x10;
        r1 = ReadSavedFriendAreas(r4, 0x8);
        if (r1 != playerSave->savedFriendAreas) {
            saveStatus = 3;
        }
        r4 += 0x8;
        r1 = sub_8097D98(r4, 0x100);
        if (r1 != playerSave->unk43C) {
            saveStatus = 3;
        }
        r4 += 0x100;
        r1 = sub_80954CC(r4, 0x594);
        if (r1 != playerSave->unk440) {
            saveStatus = 3;
        }
        r4 += 0x594;
        r1 = RestoreMailInfo(r4, 0x221);
        if (r1 != playerSave->savedMailInfo) {
            saveStatus = 3;
        }
    }
    MemoryFree(playerSave);
    return saveStatus;
}

u32 sub_8011F9C(s32 *r0, u8 *dest, s32 size)
{
    return ReadSaveSector(r0, dest, size);
}

u32 sub_8011FA8(void)
{
    u32 saveStatus;
    u32 temp3;
    u32 temp;
    struct unk_struct *r5 = MemoryAlloc(sizeof(struct unk_struct), 5);
    temp = 0x1F;
    saveStatus = ReadSaveSector(&temp, (u8 *)r5, sizeof(struct unk_struct));
    if( saveStatus == READ_SAVE_VALID)
    {
        if(r5->checksum != 0x5071412)
        {
            saveStatus = 4;
        }
    }
    temp3 = 0xf1209;
    if(saveStatus == READ_SAVE_VALID)
    {
        temp3 = r5->unk18;
    }
    MemoryFree(r5);
    return temp3;
}

bool8 IsSaveCorrupted(void)
{
    u32 temp;
    bool8 isCorrupted;
    struct unk_struct *r5 = MemoryAlloc(sizeof(struct unk_struct), 5);
    temp = 0x1F;
    isCorrupted = FALSE;
    if(ReadSaveSector(&temp, (u8 *)r5, sizeof(struct unk_struct)) == READ_SAVE_VALID)
    {
        if(r5->checksum == 0x5071412)
        {
            isCorrupted = TRUE;
        }
    }
    MemoryFree(r5);
    return isCorrupted;
}

u32 WriteSavetoPak(s32 *param_1, u32 param_2)
{
  struct UnkStruct_sub_8011DAC *playerSave;
  char *gameName;
  int saveStatus1;
  int saveStatus2;
  u8 *array_ptr;

  playerSave = MemoryAlloc(sizeof(struct UnkStruct_sub_8011DAC),5);
  array_ptr = playerSave->unk448;
  if (gUnknown_203B184 == NULL) {
    playerSave->unk41C = param_2;
    playerSave->unk418 = sub_8011C34();
    playerSave->RngState = GetRNGSeed();
  }
  else {
    playerSave->unk41C = gUnknown_203B184->unk054;
    playerSave->unk418 = gUnknown_203B184->unk050;
    playerSave->RngState = gUnknown_203B184->RngState;
  }
   playerSave->checksum = 0x5071412;
  gameName = GetGameInternalName();
  strncpy(playerSave->gameInternalName,gameName, ARRAY_COUNT(playerSave->gameInternalName));
  if (gUnknown_203B184 == NULL) {
    sub_8002700(playerSave->unk004);
  }
  else {
    MemoryCopy8(playerSave->unk004,gUnknown_203B184->unk04C,ARRAY_COUNT(playerSave->unk004));
  }

  playerSave->savedRecruitedPokemon = SaveRecruitedPokemon(array_ptr,0x4650);
  array_ptr += 0x4650;
  playerSave->unk428 = SavePokemonStruct2(array_ptr,0x258);
  array_ptr += 0x258;
  playerSave->savedTeamInventory = SaveTeamInventory(array_ptr,0x1D8);
  array_ptr += 0x1D8;
  playerSave->savedRescueTeamInfo = SaveRescueTeamInfo(array_ptr,0x10);
  array_ptr += 0x10;
  playerSave->savedFriendAreas = SaveFriendAreas(array_ptr,8);
  array_ptr += 8;
  playerSave->unk43C = sub_8097D60(array_ptr,0x100);
  array_ptr += 0x100;
  playerSave->unk440 = sub_8095624(array_ptr,0x594);
  array_ptr += 0x594;
  playerSave->savedMailInfo = SaveMailInfo(array_ptr,0x221);

  saveStatus1 = WriteSaveSector(param_1,(u8 *)playerSave,sizeof(struct UnkStruct_sub_8011DAC));
  saveStatus2 = WriteSaveSector(param_1,(u8 *)playerSave,sizeof(struct UnkStruct_sub_8011DAC));
  MemoryFree(playerSave);

  if (saveStatus1 != SAVE_COMPLETED)
    return saveStatus1;
  if (saveStatus2 != SAVE_COMPLETED)
    return saveStatus2;

  return SAVE_COMPLETED;
}

s32 sub_80121D4(s32 *a, u8 *src, s32 size)
{
    return WriteSaveSector(a, src, size);
}

u32 sub_80121E0(u32 r0)
{
    u32 temp;
    char *gameName;
    u32 saveStatus;
    struct unk_struct *r4 = MemoryAlloc(sizeof(struct unk_struct), 5);
    temp = 0x1F;

    r4->unk18 = r0;
    r4->dungeonLocation = *GetDungeonLocationInfo();
    r4->checksum = 0x5071412;

    gameName = GetGameInternalName();
    strncpy(r4->gameInternalName, gameName, ARRAY_COUNT(r4->gameInternalName));
    sub_80958E4(&r4->unk20, 0);
    saveStatus = WriteSaveSector(&temp, (u8 *)r4, sizeof(struct unk_struct));
    MemoryFree(r4);
    return saveStatus;
}

u32 sub_8012240(void)
{
    s32 status;
    struct unk_struct *r5 = MemoryAlloc(sizeof(struct unk_struct), 5);
    MemoryFill8((u8 *)r5, 0xFF, 0x4);
    sub_8011830();
    status = WriteFlashData(0x1F, (u8 *)r5, sizeof(struct unk_struct));
    xxx_call_start_bg_music();
    MemoryFree(r5);
    if(status != 0)
        return SAVE_FAILED;
    else
        return SAVE_COMPLETED;
}

void sub_8012284(void)
{
    sub_80122D0();
    sub_80122F4();
    InitializePlayerData();
}

void sub_8012298(void)
{
    sub_80976A8();
    sub_80122A8();
}

void sub_80122A8(void)
{
    sub_80122D0();
    sub_80122F4();
    InitializePlayerData();
    sub_8012240();
}

void nullsub_33(void)
{
}

void sub_80122C4(void)
{
    sub_80122A8();
}

void sub_80122D0(void)
{
    sub_8011C28(0);
    sub_8011C40(-1);
    ResetNumAdventures();
    ResetPlayTime(gPlayTimeRef);
}

void sub_80122F4(void)
{
    sub_800135C();
}

void InitializePlayerData(void)
{
    InitializeFriendAreas();
    InitializeRecruitedPokemon();
    InitializeMoneyItems();
    InitializeRescueTeamInfo();
    sub_80972F4();
    sub_8095118();
    InitializeMailJobsNews();
    sub_80974E8();
    InitializeGameOptions(TRUE);
    InitializeExclusivePokemon();
}


UNUSED static void nullsub_200(u32 r0)
{
}

UNUSED static void sub_8012334(struct UnkStruct_203B184 *r0)
{
    gUnknown_203B184 = r0;
    if (r0 != NULL) {
        gTeamInventoryRef = r0->MoneyItems;
        gRecruitedPokemonRef = r0->recruitedPokemon;
        gUnknown_203B480 = r0->unk8;
        gUnknown_203B484 = r0->unkC;
        gUnknown_203B488 = r0->unk10;
        gUnknown_203B48C = r0->unk14;
        gUnknown_203B490 = r0->mailInfo;
        gRescueTeamInfoRef = r0->RescueTeamInfo;
        gUnknown_203B494 = r0->unk20;
        gUnknown_203B498 = r0->ExclusivePokemon;
        gFriendAreas = r0->BoughtFriendAreas;
        gGameOptionsRef = r0->gameOptions;
        gPlayTimeRef = r0->playTime;
    }
    else {
        gTeamInventoryRef = GetMoneyItemsInfo();
        gRecruitedPokemonRef = GetRecruitedPokemon();
        gUnknown_203B480 = sub_80950F8();
        gUnknown_203B484 = sub_8095100();
        gUnknown_203B488 = sub_8095108();
        gUnknown_203B48C = sub_8095110();
        gUnknown_203B490 = GetMailInfo();
        gRescueTeamInfoRef = GetRescueTeamInfo();
        gUnknown_203B494 = sub_8097680();
        gUnknown_203B498 = GetExclusivePokemon();
        gFriendAreas = GetBoughtFriendAreas();
        gGameOptionsRef = GetGameOptions();
        gPlayTimeRef = GetPlayTime();
    }
}