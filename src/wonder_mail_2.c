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
extern u8 HasNoPKMNNews(void);
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

extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, struct OpenedFile **r5, u32);

extern void sub_80920D8(u8 *buffer);
extern void sub_8097790(void);
extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];
extern u32 sub_802F298(void);
extern void sub_802F2C0(void);
extern u8 sub_8099394(u8 *);
extern void sub_802B548(u32);
extern u32 sub_80144A4(s32 *);

extern void sub_802B560(void);
extern void sub_802B57C(void);
extern void sub_802B5B8(void);
extern void sub_802B5FC(void);
extern void sub_802B624(void);

void ExpandPlaceholdersBuffer(u8 *buffer, const char *text, ...);
extern void sub_802F204(u8 *, u32);
extern void sub_803C37C(u8 *, u32, u8 *);
extern u32 sub_803C200(u8 *, u32);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern u8 sub_80023E4(u32);
extern void nullsub_131(void);
extern void sub_802ABF8(void);

ALIGNED(4) const char gUnknown_80DF9F0[] = "????";

// NOTE: had to be pre-proc'd to match
ALIGNED(4) const char gUnknown_80DF9F8[] = _(
	" Oh~2c hello!\n"
	"Your rescue mission went well~2c didn~27t it?\n"
	"I wouldn~27t expect any less~2c #CG%s#R!#P"
	" Well~2c well!\n"
	"Here is your reward from the Pokémon\n"
	"Rescue Organization!");

ALIGNED(4) const char gUnknown_80DFAA8[] = 
	" I hope you will keep on\n"
	"rescuing your friends in\n"
	"dire straits.#P"
	" And now~2c I must save\n"
	"your adventure.";

ALIGNED(4) const char gUnknown_80DFB14[] =
	" Oh~2c yes~2c that~27s right.\n"
	"Please don~27t forget to send an #CGA-OK Mail#R\n"
	"to the friend you just rescued.#P"
	" Please give me a shout if\n"
	"you would like to send #CGA-OK Mail#R.";

ALIGNED(4) const char wonder_mail_2_fill[] = "pksdir0";



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
        // Display to screen with Peliper face
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

// Start of some Pokemon News related stuff
u32 sub_802B640(u32 r0, struct UnkTextStruct2_sub *r1, u32 r2)
{

    if(HasNoPKMNNews())
    {
        return 0;
    }
    else
    {
        if(gUnknown_203B2CC == NULL)
        {
            gUnknown_203B2CC = MemoryAlloc(sizeof(struct unkStruct_203B2CC), 8);
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
