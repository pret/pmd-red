#include "global.h"
#include "event_flag.h"
#include "flash.h"
#include "friend_area.h"
#include "memory.h"
#include "pokemon.h"
#include "random.h"
#include "save.h"
#include "exclusive_pokemon.h"

struct unk_struct
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 padding[504];
};

struct unk_203B188
{
    u32 state;
    u32 readStatus;
};


extern struct unk_203B188 *gUnknown_203B188;

struct unkStruct_203B18C
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

extern struct unkStruct_203B18C *gUnknown_203B18C;

struct unkStruct_203B190
{
    s32 state;
    u8 *dest;
    u32 size;
    bool8 saveValid;
};
extern struct unkStruct_203B190 *gUnknown_203B190;

struct unkStruct_203B194
{
    s32 state;
    u8 *unk4;
    u32 unk8;
    u8 unkC;
    u8 fillD[3];
    u32 quickSaveStatus;
};
extern struct unkStruct_203B194 *gUnknown_203B194;


extern s32 gUnknown_202DE28;
extern u32 gUnknown_203B17C;
extern char *gUnknown_203B180;
extern struct unkStruct_203B45C *gRecruitedPokemonRef;
extern struct unkStruct_203B460 *gUnknown_203B460;
extern struct RescueTeamData *gRescueTeamInfoRef;
extern bool8 *gFriendAreas;
extern u32 gUnknown_203B46C;
extern u8 *gUnknown_203B480;
extern u8 *gUnknown_203B484;
extern u32 *gUnknown_203B488;
extern u32 *gUnknown_203B48C;
extern u32 gUnknown_203B490;
extern u32 gUnknown_203B494;
extern struct ExclusivePokemonData *gUnknown_203B498;

ALIGNED(4) const char gSaveCorrupted[] = _("#+The game data is corrupted.\n"
                                            "#+Your data will be erased.");

ALIGNED(4) const char fill_save0[] = _("pksdir0");

ALIGNED(4) const char gSavingAdventure[] = _("#+Saving your adventure...\n"
                                            "#+Please don~27t turn off the power.");

ALIGNED(4) const char gWriteGamePak[] = _("#+Writing to GBA Game Pak.\n"
                                      "#+Do not remove the GBA Game Pak.\n"
                                      "#+Please wait with the power on.");

ALIGNED(4) const char gSaveCompleted[] = _("#+Save completed!");

ALIGNED(4) const char gSaveNotWritten[] = _("#+The data could not be written.\n"
                                        "#+Please turn off the power and remove\n"
                                        "#+and reinsert the DS Card.");

ALIGNED(4) const char gSaveFailed[] = _("#+Save failed.");

ALIGNED(4) const char fill_save1[] = _("pksdir0");

ALIGNED(4) const char gUnknown_80D44C8[] = _("#+Your data was not properly saved~2c\n"
                                             "#+so your game cannot be resumed\n"
                                             "#+from your last spot.#P"
                                             "#+Your last outing is considered a defeat.\n"
                                             "#+Before shutting down~2c save in your\n"
                                             "#+team base~2c or quicksave in a dungeon.");

ALIGNED(4) const char fill_save2[] = _("pksdir0");

ALIGNED(4) const char gUnknown_80D45AC[] = _("#+Quicksaving your adventure...\n"
                                             "#+Please don~27t turn off the power.");

ALIGNED(4) const char gUnknown_80D45F4[] = _("#+Your adventure has been saved.\n"
                                             "#+When you are in a dungeon~2c quicksave\n"
                                             "#+your progress before ending the game.");

ALIGNED(4) const char gUnknown_80D4668[] = _("#+Your adventure has been saved.\n"
                                             "#+When you resume play~2c the quicksave\n"
                                             "#+data will be deleted.#P"
                                             "#+When you are shutting down the game~2c\n"
                                             "#+save your progress in your team base~2c\n"
                                             "#+or quicksave in a dungeon.");

ALIGNED(4) const char gSaveNotWritten2[] = _("#+The data could not be written.\n"
                                             "#+Please turn off the power and remove\n"
                                             "#+and reinsert the DS Card.");

ALIGNED(4) const char gSaveFailed2[] = _("#+Save failed.");
ALIGNED(4) const char fill_save3[] = _("pksdir0");

extern volatile struct UnkStruct_203B184 *gUnknown_203B184;

extern bool8 sub_800DAB0(u16, u8*, s32);
extern bool8 sub_800DAB4(u16, u8*, s32);
extern bool8 sub_800DAB8(void);
extern void sub_8011830(void);
extern void sub_80140DC();
extern void sub_8014114();
extern void sub_80141B4(const char *r0, u32 r1, u8 *r2, u16 r3);
extern u32 sub_80144A4(u32 *a);
extern u32 SaveRecruitedPokemon(u8 *, u32);
extern u32 ReadRecruitedPokemon(void* a, s32 b);
extern u32 sub_808F154(u8 *, u32);
extern u32 sub_808F2B0(void* a, s32 b);
extern u32 sub_8091C68(u8 *, u32);
extern u32 sub_8091D14(void* a, s32 b);
extern u32 sub_80921C4(u8 *, u32);
extern u8 *sub_8095100(void);
extern u32 *sub_8095108(void);
extern u32 *sub_8095110(void);
extern void sub_8095118(void);
extern u32 sub_80954CC(void* a, s32 b);
extern u32 sub_8095624(u8 *, u32);
extern u32 sub_8096FA0(void* a, s32 b);
extern u32 sub_80970D8(u8 *, u32);
extern void sub_80976A8();
extern u32 sub_8097D60(u8 *, u32);
extern u32 sub_8097D98(void* a, s32 b);
extern void sub_80993E4();
extern void sub_800135C(void);
extern u32 GetGameOptions(void);
extern void InitializeGameOptions(u8 r0);
extern u8 *sub_80950F8(void);
extern void sub_80958E4(u8 *a, u32 b);
extern u32 sub_80958F8(void);
extern void sub_8095900(void);
extern void sub_80972F4(void);
extern u32 sub_8097680(void);
extern u32 *sub_809769C(void);
extern void sub_80974E8(void);
extern void ResetNumAdventures(void);
extern void sub_80993D8(void);

extern struct PlayTimeStruct *gPlayTimeRef;

extern void xxx_call_start_bg_music(void);


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

char *sub_8011C4C(void)
{
    return gUnknown_203B180;
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
    s32 r6 = *a;
    sub_8011CA8(a, size);
    CalculateChecksum(src, size);
    if (gUnknown_203B184 == NULL) {
        r1 = WriteFlashData(r6, src, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB4(r6, src, size)) {
            r1 = 3;
        }
        else {
            r1 = 0;
        }
    }
    else {
        return 2;
    }
    if (r1 == 4) {
        return 1;
    }
    if (r1) {
        return 2;
    }
    return 0;
}

u32 ReadSaveSector(s32 *a, u8 *dest, s32 size)
{
    u32 r1;
    s32 r6 = *a;
    sub_8011CA8(a, size);
    if (gUnknown_203B184 == NULL) {
        r1 = ReadFlashData(r6, dest, size);
    }
    else if (sub_800DAB8()) {
        if (!sub_800DAB0(r6, dest, size)) {
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
    struct UnkStruct_sub_8011DAC *r5 = MemoryAlloc(sizeof(struct UnkStruct_sub_8011DAC), 5);
    u8 *r4 = (u8*)r5->unk448;
    u32 r7 = ReadSaveSector(a, (u8*)r5, sizeof(struct UnkStruct_sub_8011DAC));
    u32 r1;
    if (r7)
    {
        r7 = ReadSaveSector(a, (u8*)r5, sizeof(struct UnkStruct_sub_8011DAC));
    }
    else
    {
        sub_8011CA8(a, sizeof(struct UnkStruct_sub_8011DAC));
    }
    if (!r7)
    {
        if (r5->unk414 != 0x5071412) {
            r7 = 4;
        }
    }
    if (!r7)
    {
        if (gUnknown_203B184 == NULL) {
            sub_8011C28(r5->unk41C);
            sub_8011C40(r5->unk418);
            SetRngState(r5->RngState);
        }
        else {
            gUnknown_203B184->unk054 = r5->unk41C;
            gUnknown_203B184->unk050 = r5->unk418;
            gUnknown_203B184->RngState = r5->RngState;
        }
    }
    if (!r7)
    {
        if (gUnknown_203B184 == NULL) {
            if (!sub_8002718(r5->unk004)) {
                r7 = 4;
            }
        }
        else {
            MemoryCopy8(gUnknown_203B184->unk04C, r5->unk004, ARRAY_COUNT(r5->unk004));
        }
    }
    if (!r7)
    {
        r1 = ReadRecruitedPokemon(r4, 0x4650);
        if (r1 != r5->savedRecruitedPokemon) {
            r7 = 3;
        }
        r4 += 0x4650;
        r1 = sub_808F2B0(r4, 0x258);
        if (r1 != r5->unk428) {
            r7 = 3;
        }
        r4 += 0x258;
        r1 = sub_8091D14(r4, 0x1D8);
        if (r1 != r5->unk430) {
            r7 = 3;
        }
        r4 += 0x1d8;
        r1 = sub_809222C(r4, 0x10);
        if (r1 != r5->unk434) {
            r7 = 3;
        }
        r4 += 0x10;
        r1 = ReadSavedFriendAreas(r4, 0x8);
        if (r1 != r5->savedFriendAreas) {
            r7 = 3;
        }
        r4 += 0x8;
        r1 = sub_8097D98(r4, 0x100);
        if (r1 != r5->unk43C) {
            r7 = 3;
        }
        r4 += 0x100;
        r1 = sub_80954CC(r4, 0x594);
        if (r1 != r5->unk440) {
            r7 = 3;
        }
        r4 += 0x594;
        r1 = sub_8096FA0(r4, 0x221);
        if (r1 != r5->unk444) {
            r7 = 3;
        }
    }
    MemoryFree(r5);
    return r7;
}

u32 sub_8011F9C(s32 *r0, u8 *dest, s32 size)
{
    return ReadSaveSector(r0, dest, size);
}

u32 sub_8011FA8(void)
{
    u32 temp2;
    u32 temp3;
    u32 temp;
    struct unk_struct *r5 = MemoryAlloc(sizeof(struct unk_struct), 5);
    temp = 0x1F;
    temp2 = ReadSaveSector(&temp, (u8 *)r5, sizeof(struct unk_struct));
    if( temp2 == READ_SAVE_VALID)
    {
        if(r5->unk14 != 0x5071412)
        {
            temp2 = 4;
        }
    }
    temp3 = 0xf1209;
    if(temp2 == READ_SAVE_VALID)
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
        if(r5->unk14 == 0x5071412)
        {
            isCorrupted = TRUE;
        }
    }
    MemoryFree(r5);
    return isCorrupted;
}

u32 WriteSavetoPak(s32 *param_1,u32 param_2)
{
  struct UnkStruct_sub_8011DAC *iVar1;
  char *__src;
  int r5;
  int r4;
  u8 *array_ptr;
  
  iVar1 = MemoryAlloc(sizeof(struct UnkStruct_sub_8011DAC),5);
  array_ptr = iVar1->unk448;
  if (gUnknown_203B184 == NULL) {
    iVar1->unk41C = param_2;
    iVar1->unk418 = sub_8011C34();
    iVar1->RngState = GetRngState();
  }
  else {
    iVar1->unk41C = gUnknown_203B184->unk054;
    iVar1->unk418 = gUnknown_203B184->unk050;
    iVar1->RngState = gUnknown_203B184->RngState;
  }
   iVar1->unk414 = 0x5071412;
  __src = sub_8011C4C();
  strncpy(iVar1->unk404,__src,16);
  if (gUnknown_203B184 == NULL) {
    sub_8002700(&iVar1->unk004);
  }
  else {
    MemoryCopy8(iVar1->unk004,gUnknown_203B184->unk04C,0x400);
  }

  iVar1->savedRecruitedPokemon = SaveRecruitedPokemon(array_ptr,0x4650);
  array_ptr += 0x4650;
  iVar1->unk428 = sub_808F154(array_ptr,0x258);
  array_ptr += 0x258;
  iVar1->unk430 = sub_8091C68(array_ptr,0x1D8);
  array_ptr += 0x1D8;
  iVar1->unk434 = sub_80921C4(array_ptr,0x10);
  array_ptr += 0x10;
  iVar1->savedFriendAreas = SaveFriendAreas(array_ptr,8);
  array_ptr += 8;
  iVar1->unk43C = sub_8097D60(array_ptr,0x100);
  array_ptr += 0x100;
  iVar1->unk440 = sub_8095624(array_ptr,0x594);
  array_ptr += 0x594;
  iVar1->unk444 = sub_80970D8(array_ptr,0x221);

  r5 = WriteSaveSector(param_1,(u8 *)iVar1,sizeof(struct UnkStruct_sub_8011DAC));
  r4 = WriteSaveSector(param_1,(u8 *)iVar1,sizeof(struct UnkStruct_sub_8011DAC));
  MemoryFree(iVar1);

  if (r5 != 0)
    return r5;
  if (r4 != 0)
    return r4;

  return 0; // Success
}


s32 sub_80121D4(s32 *a, u8 *src, s32 size)
{
    return WriteSaveSector(a, src, size);
}

u32 sub_80121E0(u32 r0)
{
    u32 temp;
    char *temp2;
    u32 temp3;
    struct unk_struct *r4 = MemoryAlloc(sizeof(struct unk_struct), 5);
    temp = 0x1F;

    r4->unk18 = r0;
    r4->unk1C = *sub_809769C();
    r4->unk14 = 0x5071412;

    temp2 = sub_8011C4C();
    strncpy((u8 *)r4 + 4, temp2, 16);
    sub_80958E4((u8 *)r4 + 32, 0);
    temp3 = WriteSaveSector(&temp, (u8 *)r4, sizeof(struct unk_struct));
    MemoryFree(r4);
    return temp3;
}

u32 sub_8012240(void)
{
    s32 temp;
    struct unk_struct *r5 = MemoryAlloc(sizeof(struct unk_struct), 5);
    MemoryFill8((u8 *)r5, 0xFF, 0x4);
    sub_8011830();
    temp = WriteFlashData(0x1F, (u8 *)r5, sizeof(struct unk_struct));
    xxx_call_start_bg_music();
    MemoryFree(r5);
    if(temp != 0)
        return 2;
    else
        return 0;
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
    InitializeResuceTeamInfo();
    sub_80972F4();
    sub_8095118();
    sub_8095900();
    sub_80974E8();
    InitializeGameOptions(1);
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
       gUnknown_203B460 = r0->MoneyItems;
       gRecruitedPokemonRef = r0->recruitedPokemon;
       gUnknown_203B480 = r0->unk8;
       gUnknown_203B484 = r0->unkC;
       gUnknown_203B488 = r0->unk10;
       gUnknown_203B48C = r0->unk14;
       gUnknown_203B490 = r0->unk18;
       gRescueTeamInfoRef = r0->RescueTeamInfo;
       gUnknown_203B494 = r0->unk20;
       gUnknown_203B498 = r0->ExclusivePokemon;
       gFriendAreas     = r0->BoughtFriendAreas;
       gUnknown_203B46C = r0->gameOptions;
       gPlayTimeRef     = r0->playTime;
       return;
    }
       gUnknown_203B460 = GetMoneyItemsInfo();
       gRecruitedPokemonRef = GetRecruitedPokemon();
       gUnknown_203B480 = sub_80950F8();
       gUnknown_203B484 = sub_8095100();
       gUnknown_203B488 = sub_8095108();
       gUnknown_203B48C = sub_8095110();
       gUnknown_203B490 = sub_80958F8();
       gRescueTeamInfoRef = GetRescueTeamInfo();
       gUnknown_203B494 = sub_8097680();
       gUnknown_203B498 = GetExclusivePokemon();
       gFriendAreas     = GetBoughtFriendAreas();
       gUnknown_203B46C = GetGameOptions();
       gPlayTimeRef     = GetPlayTime();

}

void sub_8012468(void)
{
    gUnknown_203B188 = MemoryAlloc(sizeof(struct unk_203B188), 5);
    gUnknown_203B188->state = 1;

}

u8 sub_8012484(void)
{
    u32 temp;
    u32 temp2;
    switch(gUnknown_203B188->state)
    {
        case 0:
            gUnknown_203B188->state = 1;
            break;
        case 1:
            temp = 0;
            gUnknown_203B188->readStatus = ReadSaveFromPak(&temp);
            gUnknown_203B188->state = 2;
            break;
        case 2:
            if(gUnknown_203B188->readStatus != READ_SAVE_VALID)
            {
                if(IsSaveCorrupted())
                {
                    sub_80141B4(gSaveCorrupted, 0, 0, 0x301);
                    gUnknown_203B188->state = 3;
                }
                else
                {
                    gUnknown_203B188->state = 4;
                }
            }
            else
            {
                gUnknown_203B188->state = 6;
            }
            break;
        case 3:
            if(sub_80144A4(&temp2) == 0)
                gUnknown_203B188->state = 4;
            break;
        case 4:
            sub_8012298();
            gUnknown_203B188->state = 6;
        case 5:
            break;
        case 6:
            return 0;
    }
    return 1;
}

void sub_8012558(void)
{
    if(gUnknown_203B188 != NULL)
    {
        MemoryFree(gUnknown_203B188);
        gUnknown_203B188 = NULL;
    }
}

void sub_8012574(s16 PokemonID)
{
  struct OpenedFile *file;
  s32 id_s32;
  u8 *preload_face;

  id_s32 = PokemonID; // had to cast for asr shift
  
  sub_80993D8();
  gUnknown_203B18C = MemoryAlloc(sizeof(struct unkStruct_203B18C),5);
  gUnknown_203B18C->pokeID = id_s32;
  gUnknown_203B18C->faceFile = NULL;
  gUnknown_203B18C->faceData = NULL;
  if (PokemonID != 0) {
    file = GetDialogueSpriteDataPtr(PokemonID);
    gUnknown_203B18C->faceFile = file;
    gUnknown_203B18C->faceData = file->data;
    gUnknown_203B18C->unk18 = 0;
    gUnknown_203B18C->unk19 = 0;
    gUnknown_203B18C->unk1A = 0;
    gUnknown_203B18C->unk14 = 2;
    gUnknown_203B18C->unk16 = 8;
  }
  if (gUnknown_203B18C->faceFile != 0) {
      preload_face = (u8 *)&gUnknown_203B18C->faceFile; 
      sub_80141B4(gSavingAdventure,0,preload_face,0x20);
  }
  else {
      sub_80141B4(gSavingAdventure,0,0,0x20);
  }
  gUnknown_203B18C->state = 3;
}

bool8 sub_8012600(void)
{
  struct OpenedFile **faceFile;
  u32 local_14;
  u32 other_stack;
  
  faceFile = NULL;
  if (gUnknown_203B18C->faceFile != 0) {
    faceFile = &gUnknown_203B18C->faceFile;
  }
  switch(gUnknown_203B18C->state) 
  {
    case 0:
        gUnknown_203B18C->state = 7;
        break;
    case 1:
        gUnknown_203B18C->unk4++;
        if (gUnknown_203B18C->unk4 > 8) {
            sub_80141B4(gWriteGamePak, 0, 0, 0x20);
            gUnknown_203B18C->state = 3;
        }
        break;
    case 2:
        break;
    case 3:
        gUnknown_203B18C->state = 4;
        break;
    case 4:
        local_14 = 0;
        sub_80140DC();
        gUnknown_203B18C->saveStatus = WriteSavetoPak(&local_14, sub_8011C1C());
        switch(gUnknown_203B18C->saveStatus)
        {
            case SAVE_COMPLETED:
                if(gUnknown_203B18C->faceFile != NULL)
                    sub_80141B4(gSaveCompleted, 0, (u8 *)faceFile, 0x101);
                else
                    sub_80141B4(gSaveCompleted, 0, (u8 *)faceFile, 0x101);
                gUnknown_203B18C->state = 5;
                break;
            case SAVE_NOT_WRTTEN:
                sub_80141B4(gSaveNotWritten, 0, 0, 0);
                gUnknown_203B18C->state = 6;
                break;
            default:
                if(gUnknown_203B18C->faceFile != NULL)
                    sub_80141B4(gSaveFailed, 0, (u8 *)faceFile, 0x101);
                else
                    sub_80141B4(gSaveFailed, 0, (u8 *)faceFile, 0x101);
                gUnknown_203B18C->state = 5;
                break;
        }
        sub_8014114();
        break;
    case 5:
        if (sub_80144A4(&other_stack) == 0)
            gUnknown_203B18C->state = 7;
        break;
    case 6:
        break;
    case 7:
        return 0;
    }
    return 1;
}

u32 sub_8012744(void)
{
    return gUnknown_203B18C->saveStatus;
}

void sub_8012750(void)
{
    if(gUnknown_203B18C != NULL)
    {
        if(gUnknown_203B18C->faceFile != NULL)
            CloseFile(gUnknown_203B18C->faceFile);
        MemoryFree(gUnknown_203B18C);
        gUnknown_203B18C = NULL;
    }
    sub_80993E4();
}

void sub_801277C(u8 *dest, u32 size)
{
    gUnknown_203B190 = MemoryAlloc(sizeof(struct unkStruct_203B190), 5);
    gUnknown_203B190->dest = dest;
    gUnknown_203B190->size = size;
    gUnknown_203B190->saveValid = FALSE;
    gUnknown_203B190->state = 1;
}

u32 sub_80127A8(void)
{
    u32 stack_1;
    u32 stack_2;

    switch(gUnknown_203B190->state)
    {
        case 0:
            gUnknown_203B190->state = 1;
            break;
        case 1:
            stack_1 = 16;
            if(sub_8011F9C(&stack_1, gUnknown_203B190->dest, gUnknown_203B190->size) == READ_SAVE_VALID)
            {
                gUnknown_203B190->saveValid = TRUE;
                gUnknown_203B190->state = 3;
            }
            else
            {
                // Data was not properly saved
                // so your game cannot be resumed
                // from your last spot. Your last outing is considered a defeat.
                // Before shutting down, save in your
                // team base or quicksave in a dungeon
                sub_80141B4(gUnknown_80D44C8, 0, 0, 0x301);
                gUnknown_203B190->state = 2;
            }
            break;
        case 2:
            if(sub_80144A4(&stack_2) == 0)
                gUnknown_203B190->state = 3;
            break;
        case 3:
            return 0;
        default:
            break;
    }
    return 1;
}

bool8 sub_8012828(void)
{
    return gUnknown_203B190->saveValid;
}

void sub_8012834(void)
{
    if(gUnknown_203B190 != NULL){
        MemoryFree(gUnknown_203B190);
        gUnknown_203B190 = 0;
    }
}

void sub_8012850(u8 *r0, u32 r1, u8 r2)
{
    gUnknown_203B194 = MemoryAlloc(sizeof(struct unkStruct_203B194), 5);
    gUnknown_203B194->unk4 = r0;
    gUnknown_203B194->unk8 = r1;
    gUnknown_203B194->unkC = r2;
    gUnknown_203B194->state = 0;
    if(gUnknown_203B194->unkC != 0)
        // Quicksaving your adventure...
        // Please don't turn off the power.
        sub_80141B4(gUnknown_80D45AC, 0, 0, 0x20);
    else
        // Quicksaving your adventure...
        // Please don't turn off the power.
        sub_80141B4(gUnknown_80D45AC, 0, 0, 0x20);
}

u32 sub_80128B0(void)
{
    u32 stack_1;
    u32 stack_2;
    switch(gUnknown_203B194->state)
    {
        case 0:
            gUnknown_203B194->state = 1;
            break;
        case 1:
            sub_80140DC();
            stack_1 = 16;
            gUnknown_203B194->quickSaveStatus = sub_80121D4(&stack_1, gUnknown_203B194->unk4, gUnknown_203B194->unk8);
            gUnknown_203B194->state = 2;
            return 1;
        case 2:
            stack_1 = 0;
            if(gUnknown_203B194->quickSaveStatus == 0)
                gUnknown_203B194->quickSaveStatus = WriteSavetoPak(&stack_1, 2);
            switch(gUnknown_203B194->quickSaveStatus)
            {
                case SAVE_COMPLETED:
                    sub_80121E0(0xf1207);
                    if(gUnknown_203B194->unkC != 0)
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
                    gUnknown_203B194->state = 3;
                    break;
                case SAVE_NOT_WRTTEN:
                    // The data could not be written.
                    // Please turn off the power and remove
                    // and reinsert the DS Card
                    sub_80141B4(gSaveNotWritten2, 0, 0, 0);
                    gUnknown_203B194->state = 4;
                    break;
                default:
                    sub_80121E0(0xf1209);
                    sub_80141B4(gSaveFailed2, 0, 0, 0x301);
                    gUnknown_203B194->state = 3;
                    break;
            }
            sub_8014114();
            break;
        case 3:
            if(sub_80144A4(&stack_2) == 0)
                gUnknown_203B194->state = 5;
            break;
        case 4:
            break;
        case 5:
            if(gUnknown_203B194->quickSaveStatus == SAVE_COMPLETED)
                return 2;
            else
                return 3;
            break;
        default:
            break;
    }
    return 0;
}

void sub_80129FC()
{
    if (gUnknown_203B194) {
        MemoryFree(gUnknown_203B194);
        gUnknown_203B194 = NULL;
    }
}

