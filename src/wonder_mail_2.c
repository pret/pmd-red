#include "global.h"
#include "file_system.h"
#include "input.h"
#include "pokemon.h"
#include "memory.h"
#include "text.h"
#include "save.h"
#include "wonder_mail.h"
#include "sub_8095228.h"

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

extern struct unkStruct_203B2C8 *gUnknown_203B2C8;

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
extern void sub_80141B4(const char *r0, u32, u32 *r1, u32);
extern const char  gUnknown_80DFAA8[];
extern const char gUnknown_80DFB14[];
extern const char gUnknown_80DF9F0[];
extern const char gUnknown_80DF9F8[];
extern u8 sub_80023E4(u32);

extern void nullsub_131(void);
extern void sub_802ABF8(void);

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
        sub_80141B4(gUnknown_203B2C8->teamName, 0, (u32 *)&gUnknown_203B2C8->faceFile, 0x10d);
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
        sub_80141B4(gUnknown_80DFAA8, 0, (u32 *)&gUnknown_203B2C8->faceFile, 0x10d);
        break;
      case 4:
        // Oh yes, that's right. Please don't forget to send an A-OK Mail
        // to the friend you just rescued
        sub_80141B4(gUnknown_80DFB14, 0, (u32 *)&gUnknown_203B2C8->faceFile, 0x10d);
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
