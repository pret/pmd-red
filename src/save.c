#include "global.h"
#include "event_flag.h"
#include "flash.h"
#include "friend_area.h"
#include "memory.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"
#include "team_inventory.h"
#include "exclusive_pokemon.h"
#include "game_options.h"
#include "code_80130A8.h"
#include "code_80118A4.h"

EWRAM_DATA_2 u32 gUnknown_203B17C = {0};
EWRAM_DATA_2 char *gUnknown_203B180 = {0};
EWRAM_DATA_2 struct UnkStruct_203B184 *gUnknown_203B184 = {0};
extern struct GameOptions *gGameOptionsRef;

struct unk_struct
{
    // size: 0x800
    u32 unk0;
    u8 gameInternalName[0x10]; // has "POKE_DUNGEON__05
    u32 checksum;
    u32 unk18;
    u32 dungeonLocation;
    u32 unk20;
    u32 padding[503];
};

struct SavePakRead
{
    u32 state;
    u32 readStatus;
};

EWRAM_DATA_2 struct SavePakRead *gSavePakRead = {0};

struct SavePakWrite
{
    u32 state;
    s32 unk4;
    u32 saveStatus;
    struct OpenedFile *faceFile;
    u8 *faceData;
    u16 unk14;
    u16 unk16;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u16 pokeID;
};

EWRAM_DATA_2 struct SavePakWrite *gSavePakWrite = {0};

struct QuickSaveRead
{
    s32 state;
    u8 *dest;
    u32 size;
    bool8 saveValid;
};
EWRAM_DATA_2 struct QuickSaveRead *gQuickSaveRead = {0};

struct QuickSaveWrite
{
    s32 state;
    u8 *unk4;
    u32 unk8;
    u8 unkC;
    u32 quickSaveStatus;
};
EWRAM_DATA_2 struct QuickSaveWrite *gQuickSaveWrite = {0};


extern s32 gUnknown_202DE28;
extern u32 *gUnknown_203B488;
extern u32 gUnknown_203B494;

ALIGNED(4) const char sGameInternalVersion[] = _("POKE_DUNGEON__05");

ALIGNED(4) static const char fill_save0[] = _("pksdir0");
ALIGNED(4) static const char fill_save1[] = _("pksdir0");
ALIGNED(4) static const char fill_save2[] = _("pksdir0");
ALIGNED(4) static const char fill_save3[] = _("pksdir0");

ALIGNED(4) const char gSaveCorrupted[] = _("{CENTER_ALIGN}The game data is corrupted.\n"
                                            "{CENTER_ALIGN}Your data will be erased.");

ALIGNED(4) static const char fill_save4[] = _("pksdir0");

ALIGNED(4) const char gSavingAdventure[] = _("{CENTER_ALIGN}Saving your adventure...\n"
                                            "{CENTER_ALIGN}Please don{APOSTROPHE}t turn off the power.");

ALIGNED(4) const char gWriteGamePak[] = _("{CENTER_ALIGN}Writing to GBA Game Pak.\n"
                                      "{CENTER_ALIGN}Do not remove the GBA Game Pak.\n"
                                      "{CENTER_ALIGN}Please wait with the power on.");

ALIGNED(4) const char gSaveCompleted[] = _("{CENTER_ALIGN}Save completed!");

ALIGNED(4) const char gSaveNotWritten[] = _("{CENTER_ALIGN}The data could not be written.\n"
                                        "{CENTER_ALIGN}Please turn off the power and remove\n"
                                        "{CENTER_ALIGN}and reinsert the DS Card.");

ALIGNED(4) const char gSaveFailed[] = _("{CENTER_ALIGN}Save failed.");

ALIGNED(4) static const char fill_save5[] = _("pksdir0");

ALIGNED(4) const char gUnknown_80D44C8[] = _("{CENTER_ALIGN}Your data was not properly saved{COMMA}\n"
                                             "{CENTER_ALIGN}so your game cannot be resumed\n"
                                             "{CENTER_ALIGN}from your last spot.{EXTRA_MSG}"
                                             "{CENTER_ALIGN}Your last outing is considered a defeat.\n"
                                             "{CENTER_ALIGN}Before shutting down{COMMA} save in your\n"
                                             "{CENTER_ALIGN}team base{COMMA} or quicksave in a dungeon.");

ALIGNED(4) static const char fill_save6[] = _("pksdir0");

ALIGNED(4) const char gUnknown_80D45AC[] = _("{CENTER_ALIGN}Quicksaving your adventure...\n"
                                             "{CENTER_ALIGN}Please don{APOSTROPHE}t turn off the power.");

ALIGNED(4) const char gUnknown_80D45F4[] = _("{CENTER_ALIGN}Your adventure has been saved.\n"
                                             "{CENTER_ALIGN}When you are in a dungeon{COMMA} quicksave\n"
                                             "{CENTER_ALIGN}your progress before ending the game.");

ALIGNED(4) const char gUnknown_80D4668[] = _("{CENTER_ALIGN}Your adventure has been saved.\n"
                                             "{CENTER_ALIGN}When you resume play{COMMA} the quicksave\n"
                                             "{CENTER_ALIGN}data will be deleted.{EXTRA_MSG}"
                                             "{CENTER_ALIGN}When you are shutting down the game{COMMA}\n"
                                             "{CENTER_ALIGN}save your progress in your team base{COMMA}\n"
                                             "{CENTER_ALIGN}or quicksave in a dungeon.");

ALIGNED(4) const char gSaveNotWritten2[] = _("{CENTER_ALIGN}The data could not be written.\n"
                                             "{CENTER_ALIGN}Please turn off the power and remove\n"
                                             "{CENTER_ALIGN}and reinsert the DS Card.");

ALIGNED(4) const char gSaveFailed2[] = _("{CENTER_ALIGN}Save failed.");
ALIGNED(4) static const char fill_save7[] = _("pksdir0");


extern bool8 sub_800DAB0(u16, u8*, s32);
extern bool8 sub_800DAB4(u16, u8*, s32);
extern bool8 sub_800DAB8(void);
extern void sub_80140DC();
extern void sub_8014114();
extern u32 SaveRecruitedPokemon(u8 *, u32);
extern u32 RestoreRecruitedPokemon(void* a, s32 b);
extern u32 SavePokemonStruct2(u8 *, u32);
extern u32 RestorePokemonStruct2(void* a, s32 b);
extern u32 sub_80921C4(u8 *, u32);
extern u32 sub_80954CC(void* a, s32 b);
extern u32 sub_8095624(u8 *, u32);
extern u32 RestoreMailInfo(void* a, s32 b);
extern u32 SaveMailInfo(u8 *, u32);
extern void sub_80976A8();
extern u32 sub_8097D60(u8 *, u32);
extern u32 sub_8097D98(void* a, s32 b);
extern void sub_80993E4();
extern void sub_800135C(void);
extern void sub_80958E4(u32 *a, u32 b);
extern struct unkStruct_203B490 *GetMailInfo(void);
extern void InitializeMailJobsNews(void);
extern void sub_80972F4(void);
extern u32 sub_8097680(void);
extern u32 *GetDungeonLocationInfo(void);
extern void sub_80974E8(void);
extern void ResetNumAdventures(void);
extern void sub_80993D8(void);

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

// Unused
bool8 sub_8011DA8(void)
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


// Unused
void nullsub_200(u32 r0)
{
}

// Unused
void sub_8012334(struct UnkStruct_203B184 *r0)
{
    gUnknown_203B184 = r0;
    if(r0 != NULL)
    {
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
       gFriendAreas     = r0->BoughtFriendAreas;
       gGameOptionsRef = r0->gameOptions;
       gPlayTimeRef     = r0->playTime;
       return;
    }
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
       gFriendAreas     = GetBoughtFriendAreas();
       gGameOptionsRef = GetGameOptions();
       gPlayTimeRef     = GetPlayTime();

}

void PrepareSavePakRead(void)
{
    gSavePakRead = MemoryAlloc(sizeof(struct SavePakRead), 5);
    gSavePakRead->state = 1;

}

u8 ReadSavePak(void)
{
    u32 temp;
    u32 temp2;
    switch(gSavePakRead->state)
    {
        case 0:
            gSavePakRead->state = 1;
            break;
        case 1:
            temp = 0;
            gSavePakRead->readStatus = ReadSaveFromPak(&temp);
            gSavePakRead->state = 2;
            break;
        case 2:
            if(gSavePakRead->readStatus != READ_SAVE_VALID)
            {
                if(IsSaveCorrupted())
                {
                    sub_80141B4(gSaveCorrupted, 0, 0, 0x301);
                    gSavePakRead->state = 3;
                }
                else
                {
                    gSavePakRead->state = 4;
                }
            }
            else
            {
                gSavePakRead->state = 6;
            }
            break;
        case 3:
            if(sub_80144A4(&temp2) == 0)
                gSavePakRead->state = 4;
            break;
        case 4:
            sub_8012298();
            gSavePakRead->state = 6;
        case 5:
            break;
        case 6:
            return 0;
    }
    return 1;
}

void FinishReadSavePak(void)
{
    if(gSavePakRead != NULL)
    {
        MemoryFree(gSavePakRead);
        gSavePakRead = NULL;
    }
}

void PrepareSavePakWrite(s16 PokemonID)
{
  struct OpenedFile *file;
  s32 id_s32;
  struct OpenedFile **preload_face;

  id_s32 = PokemonID; // had to cast for asr shift

  sub_80993D8();
  gSavePakWrite = MemoryAlloc(sizeof(struct SavePakWrite),5);
  gSavePakWrite->pokeID = id_s32;
  gSavePakWrite->faceFile = NULL;
  gSavePakWrite->faceData = NULL;
  if (PokemonID != MONSTER_NONE) {
    file = GetDialogueSpriteDataPtr(PokemonID);
    gSavePakWrite->faceFile = file;
    gSavePakWrite->faceData = file->data;
    gSavePakWrite->unk18 = 0;
    gSavePakWrite->unk19 = 0;
    gSavePakWrite->unk1A = 0;
    gSavePakWrite->unk14 = 2;
    gSavePakWrite->unk16 = 8;
  }
  if (gSavePakWrite->faceFile != 0) {
      preload_face = &gSavePakWrite->faceFile;
      sub_80141B4(gSavingAdventure,0,preload_face,0x20);
  }
  else {
      sub_80141B4(gSavingAdventure,0,NULL,0x20);
  }
  gSavePakWrite->state = 3;
}

bool8 WriteSavePak(void)
{
  struct OpenedFile **faceFile;
  u32 local_14;
  u32 other_stack;

  faceFile = NULL;
  if (gSavePakWrite->faceFile != 0) {
    faceFile = &gSavePakWrite->faceFile;
  }
  switch(gSavePakWrite->state)
  {
    case 0:
        gSavePakWrite->state = 7;
        break;
    case 1:
        gSavePakWrite->unk4++;
        if (gSavePakWrite->unk4 > 8) {
            sub_80141B4(gWriteGamePak, 0, 0, 0x20);
            gSavePakWrite->state = 3;
        }
        break;
    case 2:
        break;
    case 3:
        gSavePakWrite->state = 4;
        break;
    case 4:
        local_14 = 0;
        sub_80140DC();
        gSavePakWrite->saveStatus = WriteSavetoPak(&local_14, sub_8011C1C());
        switch(gSavePakWrite->saveStatus)
        {
            case SAVE_COMPLETED:
                if(gSavePakWrite->faceFile != NULL)
                    sub_80141B4(gSaveCompleted, 0, faceFile, 0x101);
                else
                    sub_80141B4(gSaveCompleted, 0, faceFile, 0x101);
                gSavePakWrite->state = 5;
                break;
            case SAVE_NOT_WRTTEN:
                sub_80141B4(gSaveNotWritten, 0, 0, 0);
                gSavePakWrite->state = 6;
                break;
            default:
                if(gSavePakWrite->faceFile != NULL)
                    sub_80141B4(gSaveFailed, 0, faceFile, 0x101);
                else
                    sub_80141B4(gSaveFailed, 0, faceFile, 0x101);
                gSavePakWrite->state = 5;
                break;
        }
        sub_8014114();
        break;
    case 5:
        if (sub_80144A4(&other_stack) == 0)
            gSavePakWrite->state = 7;
        break;
    case 6:
        break;
    case 7:
        return FALSE;
    }
    return TRUE;
}

u32 GetSavePakStatus(void)
{
    return gSavePakWrite->saveStatus;
}

void FinishWriteSavePak(void)
{
    if(gSavePakWrite != NULL)
    {
        if(gSavePakWrite->faceFile != NULL)
            CloseFile(gSavePakWrite->faceFile);
        MemoryFree(gSavePakWrite);
        gSavePakWrite = NULL;
    }
    sub_80993E4();
}

void PrepareQuickSaveRead(u8 *dest, u32 size)
{
    gQuickSaveRead = MemoryAlloc(sizeof(struct QuickSaveRead), 5);
    gQuickSaveRead->dest = dest;
    gQuickSaveRead->size = size;
    gQuickSaveRead->saveValid = FALSE;
    gQuickSaveRead->state = 1;
}

bool8 ReadQuickSave(void)
{
    u32 stack_1;
    u32 stack_2;

    switch(gQuickSaveRead->state)
    {
        case 0:
            gQuickSaveRead->state = 1;
            break;
        case 1:
            stack_1 = 16;
            if(sub_8011F9C(&stack_1, gQuickSaveRead->dest, gQuickSaveRead->size) == READ_SAVE_VALID)
            {
                gQuickSaveRead->saveValid = TRUE;
                gQuickSaveRead->state = 3;
            }
            else
            {
                // Data was not properly saved
                // so your game cannot be resumed
                // from your last spot. Your last outing is considered a defeat.
                // Before shutting down, save in your
                // team base or quicksave in a dungeon
                sub_80141B4(gUnknown_80D44C8, 0, 0, 0x301);
                gQuickSaveRead->state = 2;
            }
            break;
        case 2:
            if(sub_80144A4(&stack_2) == 0)
                gQuickSaveRead->state = 3;
            break;
        case 3:
            return FALSE;
        default:
            break;
    }
    return TRUE;
}

bool8 IsQuickSaveValid(void)
{
    return gQuickSaveRead->saveValid;
}

void FinishQuickSaveRead(void)
{
    if(gQuickSaveRead != NULL){
        MemoryFree(gQuickSaveRead);
        gQuickSaveRead = 0;
    }
}

void PrepareQuickSaveWrite(u8 *r0, u32 r1, u8 r2)
{
    gQuickSaveWrite = MemoryAlloc(sizeof(struct QuickSaveWrite), 5);
    gQuickSaveWrite->unk4 = r0;
    gQuickSaveWrite->unk8 = r1;
    gQuickSaveWrite->unkC = r2;
    gQuickSaveWrite->state = 0;
    if(gQuickSaveWrite->unkC != 0)
        // Quicksaving your adventure...
        // Please don't turn off the power.
        sub_80141B4(gUnknown_80D45AC, 0, 0, 0x20);
    else
        // Quicksaving your adventure...
        // Please don't turn off the power.
        sub_80141B4(gUnknown_80D45AC, 0, 0, 0x20);
}

u32 WriteQuickSave(void)
{
    u32 stack_1;
    u32 stack_2;
    switch(gQuickSaveWrite->state)
    {
        case 0:
            gQuickSaveWrite->state = 1;
            break;
        case 1:
            sub_80140DC();
            stack_1 = 16;
            gQuickSaveWrite->quickSaveStatus = sub_80121D4(&stack_1, gQuickSaveWrite->unk4, gQuickSaveWrite->unk8);
            gQuickSaveWrite->state = 2;
            return 1;
        case 2:
            stack_1 = 0;
            if(gQuickSaveWrite->quickSaveStatus == 0)
                gQuickSaveWrite->quickSaveStatus = WriteSavetoPak(&stack_1, 2);
            switch(gQuickSaveWrite->quickSaveStatus)
            {
                case SAVE_COMPLETED:
                    sub_80121E0(0xf1207);
                    if(gQuickSaveWrite->unkC != 0)
                        // Your adventure has been saved
                        // When you are in a dungeon, quicksave
                        // your progress before ending the game.
                        sub_80141B4(gUnknown_80D45F4, 0, 0, 0x301);
                    else
                        // Your adventure has been saved.
                        // When you resume play, the quicksave
                        // data will be deleted. When you are shutting down the game,
                        // save your progress in your team base,
                        // or quicksave in a dungeon.
                        sub_80141B4(gUnknown_80D4668, 0, 0, 0x301);
                    gQuickSaveWrite->state = 3;
                    break;
                case SAVE_NOT_WRTTEN:
                    // The data could not be written.
                    // Please turn off the power and remove
                    // and reinsert the DS Card
                    sub_80141B4(gSaveNotWritten2, 0, 0, 0);
                    gQuickSaveWrite->state = 4;
                    break;
                default:
                    sub_80121E0(0xf1209);
                    sub_80141B4(gSaveFailed2, 0, 0, 0x301);
                    gQuickSaveWrite->state = 3;
                    break;
            }
            sub_8014114();
            break;
        case 3:
            if(sub_80144A4(&stack_2) == 0)
                gQuickSaveWrite->state = 5;
            break;
        case 4:
            break;
        case 5:
            if(gQuickSaveWrite->quickSaveStatus == SAVE_COMPLETED)
                return 2;
            else
                return 3;
            break;
        default:
            break;
    }
    return 0;
}

void FinishQuickSaveWrite()
{
    if (gQuickSaveWrite) {
        MemoryFree(gQuickSaveWrite);
        gQuickSaveWrite = NULL;
    }
}

