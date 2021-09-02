#include "global.h"
#include "file_system.h"
#include "input.h"
#include "pokemon.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "save.h"
#include "sub_8095228.h"
#include "wonder_mail.h"

extern struct WonderMailStruct_203B2C4 *gUnknown_203B2C4;

struct unkStruct_203B2C8
{
    // size: 0x140
    u8 currState;
    u8 unk1;
    u16 unk2;
    /* 0x4 */ struct OpenedFile *faceFile;
    /* 0x8 */ u8 *faceData;
    /* 0xC */ u16 unkC;
    /* 0xE */ u16 unkE;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 teamName[4]; // Figure out size of this buffer
    u8 fill18[0x114 - 0x18];
    u8 speciesName[0xA]; // holds species name
    u8 fill118[0x128 - 0x11E];
    u16 unk128;
    u8 unk12A;
    u8 unk12B;
    u32 unk12C;
    u8 unk130;
    u8 unk131;
    u8 unk132;
    u8 unk133;
    u8 unk134;
    u8 fill135[0x3];
    u32 unk138;
    u32 fill13C;
};

struct unkStruct_203B2CC
{
    // size: 0xD4;
    u8 unk0[0x38];

    u32 unk38;
    u8 fill3C[0x50 - 0x3C];

    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;

    u16 unk58;
    u16 unk5A;

    u8 fill5C[0x6C - 0x5C];

    u32 unk6C;

    struct UnkTextStruct2 *unk70;
    struct UnkTextStruct2 unk74[4];
};

extern struct unkStruct_203B2CC *gUnknown_203B2CC;
extern u32 sub_802B9A8(void);
extern void sub_802B880(void);
extern void sub_802B8D4(void);
extern void sub_8013818(void *, u32, u32, u32);
extern void sub_8012D08(struct UnkTextStruct2 *, s32);
extern void sub_8013984(u32 *);
extern u8 sub_802B9D8(void);
extern u16 gUnknown_203B2D0;
extern u16 gUnknown_203B2D2;

extern u8 sub_80138B8(void *, u32);
extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(u32 *);
extern void sub_8013660(u32 *);
extern void AddMenuCursorSprite(u32 *);

extern struct UnkTextStruct2 gUnknown_80DFBEC;

extern struct UnkTextStruct2 gUnknown_80DFBD0;

extern struct unkStruct_203B2C8 *gUnknown_203B2C8;

extern struct MenuItem gUnknown_80DED78[];
extern struct MenuItem gUnknown_80DEDB8[];
extern u8 gUnknown_80DF6F0[];
extern u8 gUnknown_80DF44C[];
extern u8 gUnknown_80DF380[];
extern u8 gUnknown_80DF544[];
extern u8 gUnknown_80DF96C[];
extern u8 gUnknown_80DF9A4[];
extern u8 gUnknown_80DF4F4[];
extern u8 gUnknown_80DF46C[];
extern u8 gUnknown_80DF94C[];
extern u8 gUnknown_80DF928[];
extern u8 gUnknown_80DF8EC[];
extern u8 gUnknown_80DF7D4[];
extern u8 gUnknown_80DF8B4[];
extern u8 gUnknown_80DF3B4[];
extern u8 gUnknown_80DF63C[];
extern u8 gUnknown_80DF250[];
extern u8 gUnknown_80DF594[];
extern u8 gUnknown_80DF870[];
extern u8 gUnknown_80DF77C[];
extern u8 gUnknown_80DF5E4[];
extern u8 gUnknown_80DF710[];
extern u8 gUnknown_80DF694[];
extern u8 gUnknown_80DF73C[];
extern u8 gUnknown_80DF330[];
extern u8 gUnknown_80DF418[];
extern u8 gUnknown_80DF304[];
extern struct UnkTextStruct2 gUnknown_80DED60;
extern struct UnkTextStruct2 gUnknown_80DED48;
extern struct MenuItem gUnknown_80DEE44[];
extern struct MenuItem gUnknown_80DEE08[];
extern struct MenuItem gUnknown_80DEE7C[];
extern struct MenuItem gUnknown_80DEEBC[];
extern struct MenuItem gUnknown_80DEEE4[];
extern struct MenuItem gUnknown_80DEE60[];

extern void sub_8031D70(u8, u32);
extern u8 sub_809539C(u32, u32);
extern u8 sub_800D588(void);
extern u32 sub_803C200(u8 *, u32);

extern struct PokemonStruct *sub_808D33C(void);

extern void sub_802F204(u8 *, u32);
extern void sub_80151C0(u32, u8 *);
extern void xxx_call_start_bg_music(void);
extern void sub_803092C(void);
extern void sub_801CCD8(void);
extern void sub_8011830(void);
extern void nullsub_23(u32);
extern void sub_80922B4(u8 *, u8 *, u32);
extern s32 sub_8037B28(u32);
extern u32 sub_8030894(void);
extern u32 sub_801D008(void);
extern void sub_80306A8(u32, u32, u32, u32);
extern void sub_8035CF4(u32 *, u32, u32);
extern s32 sub_8037D64(u32, void *, void *);
extern s32 sub_80381F4(u32, void *, void *);
extern void sub_801C8C4(u32, u32, s32 * , u32);


void ExpandPlaceholdersBuffer(u8 *buffer, const char *text, ...);
extern void SetMenuItems(void *menu, struct UnkTextStruct2 *, u32, const struct UnkTextStruct2 *, const struct MenuItem *entries, u32, u32, u32);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, struct OpenedFile **r5, u32);

extern void sub_80920D8(u8 *buffer);
extern void sub_8097790();
extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];
extern u32 sub_802F298();
extern void sub_802F2C0();
extern u8 sub_8099394(u8 *);
extern void sub_802B548(u32);
extern u32 sub_80144A4(s32 *);

extern void sub_802B560();
extern void sub_802B57C();
extern void sub_802B5B8();
extern void sub_802B5FC();
extern void sub_802B624();

void ExpandPlaceholdersBuffer(u8 *buffer, const char *text, ...);
extern void sub_802F204(u8 *, u32);
extern void sub_803C37C(u8 *, u32, u8 *);
extern u32 sub_803C200(u8 *, u32);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern const char  gUnknown_80DFAA8[];
extern const char gUnknown_80DFB14[];
extern const char gUnknown_80DF9F0[];
extern const char gUnknown_80DF9F8[];
extern u8 sub_80023E4(u32);

extern void nullsub_131(void);
extern void sub_802ABF8(void);

void sub_802ABF8(void)
{
  char cVar1;
  char *monName;
  u8 auStack180 [80];
  u8 auStack100 [80];
  u8 uVar2;
  struct PokemonStruct *pokeStruct;
  struct PokemonStruct *pokeStruct2;
  s32 iVar6;
  struct unkStruct_8095228 *puVar4;


  
  switch(gUnknown_203B2C4->state) {
    case 5:
        pokeStruct = sub_808D33C();
        sub_80922B4(auStack180,pokeStruct->name, POKEMON_NAME_LENGTH);
        ExpandPlaceholdersBuffer(gUnknown_203B2C4->formattedString,gUnknown_80DF250,auStack180);
        sub_80141B4(gUnknown_203B2C4->formattedString,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0xe:
        sub_8014248(gUnknown_80DF304,0,7,gUnknown_80DEE60,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 0xf:
        sub_80141B4(gUnknown_80DF330,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x10:
        if (sub_8030894() != 0)
            break;
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_80306A8(5,0,0,6);
        break;
    case 0x11:
        sub_8006518(gUnknown_203B2C4->unk35C);
        SetMenuItems(&gUnknown_203B2C4->unk21C,gUnknown_203B2C4->unk35C,3,&gUnknown_80DED60,gUnknown_80DED78,1,0,0);
        sub_803092C();
        sub_8035CF4(&gUnknown_203B2C4->unk21C,3,1);
        break;
    case 0x13:
        if (sub_801D008() != 0)
            break;
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        // TODO: Probably a macro - Pika
        {
        struct {u16 a; u16 b;} local_x = {3, 2};
        sub_801C8C4(0, 1, (s32 *)&local_x, 9);
        }
        break;
    case 0x14:
        sub_8006518(gUnknown_203B2C4->unk35C);
        SetMenuItems(&gUnknown_203B2C4->unk21C,gUnknown_203B2C4->unk35C,3,&gUnknown_80DED48,gUnknown_80DED78,1,0,0);
        sub_801CCD8();
        sub_8035CF4(&gUnknown_203B2C4->unk21C,3,1);
        break;
    case 0x1e:
        gUnknown_203B2C4->linkError = 0;
        sub_8011830();
        iVar6 = sub_8037B28(gUnknown_203B2C4->unk40);
        gUnknown_203B2C4->linkError = iVar6;
        if (iVar6 != 0) goto _0802AEE6;
        switch(gUnknown_203B2C4->unk40)
        {
            case 6:
                MemoryFill8((u8 *)&gUnknown_203B2C4->unk1B8,0, sizeof(struct unkStruct_8095228));
                gUnknown_203B2C4->unk1B8 = *sub_8095228(gUnknown_203B2C4->unk218);
                gUnknown_203B2C4->linkError = sub_8037D64(gUnknown_203B2C4->unk40,&gUnknown_203B2C4->unk1B8,&gUnknown_203B2C4->unk1E8);
                break;
            case 7:
                MemoryFill8((u8 *)&gUnknown_203B2C4->unk1B8,0, sizeof(struct unkStruct_8095228));
                MemoryFill8((u8 *)&gUnknown_203B2C4->unk1E8,0, sizeof(struct unkStruct_8095228));
                gUnknown_203B2C4->linkError = sub_8037D64(gUnknown_203B2C4->unk40,&gUnknown_203B2C4->unk1B8,&gUnknown_203B2C4->unk1E8);
                break;
        }
        if (gUnknown_203B2C4->linkError == 0){
            switch(gUnknown_203B2C4->unk40){
                case 6:
                case 7:
                    gUnknown_203B2C4->linkError = sub_80381F4(gUnknown_203B2C4->unk40,&gUnknown_203B2C4->unk1B8,&gUnknown_203B2C4->unk1E8);
                    if ( sub_800D588() != '\0') {
                        gUnknown_203B2C4->unk430 = gUnknown_203B2C4->unk1E8.unk10;
                    }
                    else {
                        gUnknown_203B2C4->unk430 = gUnknown_203B2C4->unk1B8.unk10;
                    }
                break;
            }
        }
    _0802AEE6:
        xxx_call_start_bg_music();
        break;
    case 0x26:
        sub_80141B4(gUnknown_80DF380,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x27:
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_80151C0(4,gUnknown_203B2C4->passwordBuffer);
        break;
    case 0x1a:
        sub_8006518(gUnknown_203B2C4->unk3BC);
        ResetUnusedInputStruct();
        sub_800641C(0,1,1);
        sub_8031D70(gUnknown_203B2C4->unk218,0);
        break;
    case 0x1b:
        sub_80141B4(gUnknown_80DF3B4,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x19:
        sub_80141B4(gUnknown_80DF418,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x24:
        sub_80141B4(gUnknown_80DF44C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x20:
        sub_80141B4(gUnknown_80DF46C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x21:
        switch(gUnknown_203B2C4->unk534)
        {
            case 3:
            case 5:
            case 6:
                sub_80141B4(gUnknown_80DF4F4,0,&gUnknown_203B2C4->faceFile,0x10d);
                break;
            case 4:
                break;
        }
        break;
    case 0x22:
        monName = GetMonSpecies(SPECIES_PELIPPER);
        strcpy(gUnknown_203B2C4->unk53C,monName);
        gUnknown_203B2C4->unk550 = 0x130;
        gUnknown_203B2C4->unk552 = 2;
        gUnknown_203B2C4->unk554 = 0;
        uVar2 = sub_809539C(6,gUnknown_203B2C4->unk430);
        puVar4 = sub_8095228(uVar2);
        cVar1 = puVar4->unk20.itemIndex;
        if (cVar1 != '\0')
            gUnknown_203B2C4->unk558 = cVar1;
        else
            gUnknown_203B2C4->unk558 = 0;
        gUnknown_203B2C4->unk55B = 1;
        gUnknown_203B2C4->unk560 = sub_803C200(&puVar4->unk4, 0);
        gUnknown_203B2C4->unk559 = 0;
        gUnknown_203B2C4->unk55A = 0;
        gUnknown_203B2C4->unk55C = 0;
        sub_802F204(gUnknown_203B2C4->unk53C,0);
        break;
    case 0x16:
        nullsub_23(0);
        sub_80141B4(gUnknown_80DF544,0,0,0);
        break;
    case 0x17:
        sub_80141B4(gUnknown_80DF594,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x1d:
        sub_8014248(gUnknown_80DF5E4,0,7,gUnknown_80DEE44,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 0xd:
        pokeStruct2 = sub_808D33C();
        sub_80922B4(auStack100, pokeStruct2->name, POKEMON_NAME_LENGTH);
        ExpandPlaceholdersBuffer(gUnknown_203B2C4->formattedString,gUnknown_80DF63C,auStack100);
        sub_80141B4(gUnknown_203B2C4->formattedString,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0xc:
        sub_8014248(gUnknown_80DF694,0,7,gUnknown_80DEEE4,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 0x29:
        sub_80141B4(gUnknown_80DF44C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0x2a:
        sub_80141B4(gUnknown_80DF6F0,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0xb:
        sub_80141B4(gUnknown_80DF710,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 10:
        sub_8014248(gUnknown_80DF73C,0,0,gUnknown_80DEEBC,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 9:
        sub_8014248(gUnknown_80DF77C,0,0,gUnknown_80DEE7C,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 7:
        sub_80141B4(gUnknown_80DF7D4,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 8:
        sub_8014248(gUnknown_80DF870,0,7,gUnknown_80DEE44,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 4:
        sub_80141B4(gUnknown_80DF8B4,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 0:
        sub_8014248(gUnknown_80DF8EC,0,1,gUnknown_80DEDB8,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 1:
        sub_8014248(gUnknown_80DF928,0,1,gUnknown_80DEDB8,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
        break;
    case 2:
        sub_80141B4(gUnknown_80DF94C,0,&gUnknown_203B2C4->faceFile,0x10d);
        break;
    case 6:
        switch(gUnknown_203B2C4->unk538){
            case 1:
                sub_8014248(gUnknown_80DF96C,0,3,gUnknown_80DEE08,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
                break;
            case 2:
                sub_8014248(gUnknown_80DF9A4,0,3,gUnknown_80DEE08,0,4,0,&gUnknown_203B2C4->faceFile,0xc);
                break;
        }
        break;
  }
}

void sub_802B2BC(u32 newState)
{
    gUnknown_203B2C4->state = newState;
    nullsub_131();
    sub_802ABF8();
}

u32 sub_802B2D4(void)
{
  s32 iVar1;
  struct OpenedFile *faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B2C8 = MemoryAlloc(sizeof(struct unkStruct_203B2C8),8);
  MemoryFill8((u8 *)gUnknown_203B2C8,0,sizeof(struct unkStruct_203B2C8));
  gUnknown_203B2C8->unk1 = -1;
  CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_PELIPPER);
  faceFile = GetDialogueSpriteDataPtr(SPECIES_PELIPPER);
  gUnknown_203B2C8->faceFile = faceFile;
  gUnknown_203B2C8->faceData  = faceFile->data;
  gUnknown_203B2C8->unk10 = 0;
  gUnknown_203B2C8->unk11 = 0;
  gUnknown_203B2C8->unk12 = 0;
  gUnknown_203B2C8->unkC = 2;
  gUnknown_203B2C8->unkE = 8;
  if (sub_8099394(&gUnknown_203B2C8->unk1) == 1) {
    sub_802B548(0);
    iVar1  = 1;
  }
  else
    iVar1 = 0;
  return iVar1;
}

u32 sub_802B358(void)
{
  switch(gUnknown_203B2C8->currState) {
    case 0:
        sub_802B560();
        break;
    case 1:
        sub_802B57C();
        break;
    case 2:
        sub_802B5B8();
        break;
    case 3:
        sub_802B5FC();
        break;
    case 4:
        sub_802B624();
        break;
    case 5:
        return 3;
  }
  return 0;
}

void sub_802B3B8(void)
{
    if(gUnknown_203B2C8 != NULL)
    {
        CloseFile(gUnknown_203B2C8->faceFile);
        MemoryFree(gUnknown_203B2C8);
        gUnknown_203B2C8 = NULL;
    }
}

void nullsub_132(void)
{
}

void sub_802B3E0(void)
{
  struct unkStruct_8095228 *iVar3;
  char *monName;
  char teamNameBuffer[40];

  switch(gUnknown_203B2C8->currState) {
      case 0:
        if (sub_80023E4(0) != '\0') {
            // Copy Team Name to buffer
            sub_80920D8(teamNameBuffer);
        }
        else {
            // Copy "????" to buffer
            strcpy(teamNameBuffer,gUnknown_80DF9F0);
        }
        // Print and expand placeholders?
        ExpandPlaceholdersBuffer(gUnknown_203B2C8->teamName,gUnknown_80DF9F8,teamNameBuffer);
        // Display to screen with Pelliper face
        sub_80141B4(gUnknown_203B2C8->teamName, 0, &gUnknown_203B2C8->faceFile, 0x10d);
        break;
      case 1:
        monName = GetMonSpecies(SPECIES_PELIPPER);
        strcpy(gUnknown_203B2C8->speciesName, monName);
        gUnknown_203B2C8->unk128 = 0x130;
        gUnknown_203B2C8->unk12A = 2;
        gUnknown_203B2C8->unk12C = 0;
        sub_8097790();
        iVar3 = sub_8095228(gUnknown_203B2C8->unk1);
        sub_803C37C(&iVar3->unk4, 0, &gUnknown_203B2C8->unk130);
        gUnknown_203B2C8->unk138 = sub_803C200(&iVar3->unk4, 0);
        gUnknown_203B2C8->unk131 = 0;
        gUnknown_203B2C8->unk132 = 0;
        gUnknown_203B2C8->unk133 = 10;
        gUnknown_203B2C8->unk134 = 0;
        sub_802F204(gUnknown_203B2C8->speciesName, 0);
        break;
      case 2:
        // I hope you will keep on rescuing your friends
        // I must save your adventure
        sub_80141B4(gUnknown_80DFAA8, 0, &gUnknown_203B2C8->faceFile, 0x10d);
        break;
      case 4:
        // Oh yes, that's right. Please don't forget to send an A-OK Mail
        // to the friend you just rescued
        sub_80141B4(gUnknown_80DFB14, 0, &gUnknown_203B2C8->faceFile, 0x10d);
      case 3:
      case 5:
        break;
  }
}

void sub_802B548(u32 newState)
{
    gUnknown_203B2C8->currState = newState;
    nullsub_132();
    sub_802B3E0();
}

void sub_802B560(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_802B548(1);
    }
}

void sub_802B57C(void)
{
  char *monName;

  if (sub_802F298() == 3) {
    sub_802F2C0();
    CopyYellowSpeciesNametoBuffer(gUnknown_202E5D8, SPECIES_PELIPPER);
    monName = GetMonSpecies(SPECIES_PELIPPER);
    strcpy(gAvailablePokemonNames, monName);
    sub_802B548(2);
  }
}

void sub_802B5B8(void)
{
  u32 uVar2;
  struct unkStruct_8095228 *puVar3;
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    uVar2 = sub_8011C34();
    puVar3 = sub_8095228(gUnknown_203B2C8->unk1);
    puVar3->unk0 = 4;
    puVar3->unk28 = uVar2;
    sub_802B548(3);
    sub_8011C28(1);
    PrepareSavePakWrite(SPECIES_NONE);
  }
}

void sub_802B5FC(void)
{
  s32 temp;
  
  if (sub_80144A4(&temp) == 0) {
    if (!WriteSavePak()) {
      FinishWriteSavePak();
      sub_802B548(4);
    }
  }
}


void sub_802B624(void)
{
  s32 temp;
  
  if (sub_80144A4(&temp) == 0) {
    sub_802B548(5);
  }
}

u32 sub_802B640(u32 r0, struct UnkTextStruct2_sub *r1, u32 r2)
{

    if(sub_802B9D8())
    {
        return 0;
    }
    else
    {
        if(gUnknown_203B2CC == NULL)
        {
            gUnknown_203B2CC = MemoryAlloc(0xD4, 8);
        }
        gUnknown_203B2CC->unk6C = r0;
        gUnknown_203B2CC->unk70 = &gUnknown_203B2CC->unk74[r0];

        sub_8006518(gUnknown_203B2CC->unk74);

        gUnknown_203B2CC->unk74[gUnknown_203B2CC->unk6C] = gUnknown_80DFBEC;

        if(r1 != NULL)
        {
            gUnknown_203B2CC->unk74[gUnknown_203B2CC->unk6C].unk08 = *r1;
        }

        sub_8012D08(gUnknown_203B2CC->unk70, r2);
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2CC->unk74, 1, 1);

        sub_8013818(&gUnknown_203B2CC->unk38, sub_802B9A8(), r2, r0);

        gUnknown_203B2CC->unk50 = gUnknown_203B2D0;
        gUnknown_203B2CC->unk56 = gUnknown_203B2D2;

        sub_8013984(&gUnknown_203B2CC->unk38);
        sub_802B880();
        sub_802B8D4();

        return 1;
    }
}

u32 sub_802B720(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B2CC->unk38);
        return 0;
    }
    else
    {
        switch(GetKeyPress(&gUnknown_203B2CC->unk38))
        {
            case 2:
                PlayMenuSoundEffect(1);
                return 2;
            case 1:
                PlayMenuSoundEffect(0);
                return 3;
            case 4:
                PlayMenuSoundEffect(4);
                return 4;
        }
        if(sub_80138B8(&gUnknown_203B2CC->unk38, 1) != 0)
        {
            sub_802B880();
            sub_802B8D4();
            return 1;
        }
        else
            return 0;
    }
}

u8 sub_802B7A8(void)
{
    return gUnknown_203B2CC->unk0[(gUnknown_203B2CC->unk56 * gUnknown_203B2CC->unk54) + gUnknown_203B2CC->unk50];
}

void sub_802B7D0(u32 r0)
{
    u8 temp;

    temp = r0;

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2CC->unk74, 0, 0);

    gUnknown_203B2CC->unk5A = sub_802B9A8();
    sub_8013984(&gUnknown_203B2CC->unk38);
    sub_802B880();
    sub_802B8D4();

    if(temp != 0)
    {
        AddMenuCursorSprite(&gUnknown_203B2CC->unk38);
    }
}

void sub_802B81C(void)
{
    if(gUnknown_203B2CC  != NULL)
    {
        gUnknown_203B2D0 = gUnknown_203B2CC->unk50;

        gUnknown_203B2D2 = gUnknown_203B2CC->unk56;

        gUnknown_203B2CC->unk74[gUnknown_203B2CC->unk6C] = gUnknown_80DFBD0;

        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2CC->unk74, 1, 1);

        MemoryFree(gUnknown_203B2CC);
        gUnknown_203B2CC = NULL;
    }
}
