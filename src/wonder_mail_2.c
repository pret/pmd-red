#include "global.h"
#include "file_system.h"
#include "input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "save.h"
#include "sub_8095228.h"
#include "gUnknown_203B46C.h"
#include "wonder_mail.h"

struct unkStruct_203B2C8
{
    // size: 0x140
    /* 0x0 */ u8 currState;
    /* 0x1 */ u8 unk1;
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
    struct unkStruct_802F204 unk114;
    u32 fill13C;
};

struct unkStruct_203B2CC
{
    // size: 0xD4;
    u8 receivedNewsletters[NUM_POKEMON_NEWS];

    u32 unk38;
    u8 fill3C[0x50 - 0x3C];

    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;

    u16 unk58;
    u16 numPKMNNews;

    u8 fill5C[0x6C - 0x5C];

    u32 unk6C;

    struct UnkTextStruct2 *unk70;
    struct UnkTextStruct2 unk74[4];
};
extern struct unkStruct_203B2CC *gUnknown_203B2CC;

struct unkStruct_203B2D4
{
    // size: 0x94
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 currMailIndex;
    s32 unk8;
    s32 unkC;
    const u8 *unk10[4];
    u32 unk20;
    u32 unk24;
    struct UnkTextStruct2 unk28[4];
    u32 unk88;
    u8 fill8C[0x94 - 0x8C];
};
extern struct unkStruct_203B2D4 *gUnknown_203B2D4;

struct unkStruct_203B2D8
{
    // size: 0xA4
    u8 unk0[4];
    u32 unk4;
    u8 fill8[0x1C - 0x8];
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 fill24;
    /* 0x26 */ s16 emptyMailSlots;
    u8 fill28[0x38 - 0x28];
    u32 unk38;
    struct UnkTextStruct2 *unk3C;
    struct UnkTextStruct2 unk40[4];
    u8 unkA0[4];
};
extern struct unkStruct_203B2D8 *gUnknown_203B2D8;

extern struct UnkSaveStruct1 *gUnknown_203B46C;


extern s32 GetNumPKMNNews(void);
extern void sub_802B880(void);
extern void sub_802B8D4(void);
extern void sub_8013818(void *, u32, u32, u32);
extern void sub_8012D08(struct UnkTextStruct2 *, s32);
extern void sub_8013984(u32 *);
extern u8 HasNoPKMNNews(void);
extern u8 CheckPKMNNewsSlot(u8 r0);
extern struct PokemonStruct *sub_808D3BC(void);
extern void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern u16 gUnknown_203B2D0;
extern u16 gUnknown_203B2D2;
extern u16 gUnknown_203B2DC;
extern u8 sub_80138B8(void *, u32);
extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(u32 *);
extern void sub_8013660(u32 *);
extern void AddMenuCursorSprite(u32 *);

extern void sub_802BB98(void);
extern void sub_802BC08(void);
extern void sub_802BB28(void);
extern void sub_8013E54(void);
extern s32 sub_8012A64(u32 *, u32);

extern struct UnkTextStruct2 gUnknown_80DFBEC;

extern struct UnkTextStruct2 gUnknown_80DFBD0;

extern struct UnkTextStruct2 gUnknown_80DFC34;

extern struct UnkTextStruct2 gUnknown_80DFC18;

extern struct unkStruct_203B2C8 *gUnknown_203B2C8;

extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, struct OpenedFile **r5, u32);

extern void sub_80920D8(u8 *buffer);
extern void sub_8097790(void);
extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];
extern u8 gUnknown_80DFC4C[];
extern u8 gUnknown_80DFC50[];
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
extern void sub_802F204(struct unkStruct_802F204 *, u32);
extern void sub_803C37C(u8 *, u32, u8 *);
extern u32 sub_803C200(u8 *, u32);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern u8 sub_80023E4(u32);
extern void nullsub_131(void);
extern void sub_802ABF8(void);

extern u8 gUnknown_80DFC04[];
extern u8 gUnknown_80DFBE8[];
extern struct UnkTextStruct2 gUnknown_80DFC74;
extern struct UnkTextStruct2 gUnknown_80DFC5C;
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_802BC7C(void);
extern void sub_80073E0(u32);
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern void sub_803B6B0(u32, u32, u32, u32);
extern s32 sub_8013800(u32 *, s32);

extern void sub_802BCC4(void);
extern void sub_802BB14(u32);
extern void sub_801317C(u32 *);
extern u8 HasNoMailinMailbox(void);
extern void sub_802BF30(void);
extern void CreateMailMenu(void);
extern void sub_8012D34(struct UnkTextStruct2 *, u32);
extern s32 CountEmptyMailSlots(void);
extern void sub_8013848(u32 *, s32, u32, u32);

ALIGNED(4) const char gUnknown_80DF9F0[] = "????";

// NOTE: had to be pre-proc'd to match
ALIGNED(4) const char gUnknown_80DF9F8[] = _(
	" Oh{COMMA} hello!\n"
	"Your rescue mission went well{COMMA} didn{APOSTROPHE}t it?\n"
	"I wouldn{APOSTROPHE}t expect any less{COMMA} {COLOR_1 LIGHT_BLUE_2}%s{END_COLOR_TEXT_1}!{EXTRA_MSG}"
	" Well{COMMA} well!\n"
	"Here is your reward from the Pokémon\n"
	"Rescue Organization!");

ALIGNED(4) const char gUnknown_80DFAA8[] = _(
	" I hope you will keep on\n"
	"rescuing your friends in\n"
	"dire straits.{EXTRA_MSG}"
	" And now{COMMA} I must save\n"
	"your adventure.");

ALIGNED(4) const char gUnknown_80DFB14[] = _(
	" Oh{COMMA} yes{COMMA} that{APOSTROPHE}s right.\n"
	"Please don{APOSTROPHE}t forget to send an {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}\n"
	"to the friend you just rescued.{EXTRA_MSG}"
	" Please give me a shout if\n"
	"you would like to send {COLOR_1 LIGHT_BLUE_2}A-OK Mail{END_COLOR_TEXT_1}.");

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
        // Display to screen with Pelipper face
        sub_80141B4(gUnknown_203B2C8->teamName, 0, &gUnknown_203B2C8->faceFile, 0x10d);
        break;
      case 1:
        monName = GetMonSpecies(SPECIES_PELIPPER);
        strcpy(gUnknown_203B2C8->unk114.clientName, monName);
        gUnknown_203B2C8->unk114.unk14 = SPECIES_PELIPPER;
        gUnknown_203B2C8->unk114.unk16 = 2;
        gUnknown_203B2C8->unk114.moneyReward = 0;
        sub_8097790();
        iVar3 = sub_8095228(gUnknown_203B2C8->unk1);
        sub_803C37C(&iVar3->unk4, 0, gUnknown_203B2C8->unk114.itemRewards);
        gUnknown_203B2C8->unk114.teamRankPtsReward = sub_803C200(&iVar3->unk4, 0);
        gUnknown_203B2C8->unk114.itemRewards[1] = 0;
        gUnknown_203B2C8->unk114.itemRewards[2] = 0;
        gUnknown_203B2C8->unk114.numItems = 10;
        gUnknown_203B2C8->unk114.friendAreaReward = 0;
        sub_802F204(&gUnknown_203B2C8->unk114, 0);
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

        sub_8013818(&gUnknown_203B2CC->unk38, GetNumPKMNNews(), r2, r0);

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

u8 GetPokemonNewsIndex(void)
{
    return gUnknown_203B2CC->receivedNewsletters[(gUnknown_203B2CC->unk56 * gUnknown_203B2CC->unk54) + gUnknown_203B2CC->unk50];
}

void sub_802B7D0(u32 r0)
{
    u8 temp;

    temp = r0;

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2CC->unk74, 0, 0);

    gUnknown_203B2CC->numPKMNNews = GetNumPKMNNews();
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

NAKED
void sub_802B880(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _0802B8D0\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x52\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x6C]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x82\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x6C]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x84\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x74\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"\t_0802B8D0: .4byte gUnknown_203B2CC");
}

void sub_802B8D4(void)
{
    s32 iVar2;
    s32 retvar;
    s32 new_index;
    u8 mailIndex;


    sub_8008C54(gUnknown_203B2CC->unk6C);
    sub_80073B8(gUnknown_203B2CC->unk6C);
    xxx_call_draw_string(0xA, 0, gUnknown_80DFC04, gUnknown_203B2CC->unk6C, 0);
    sub_8012BC4(((gUnknown_80DFBE8[2] << 3) + 4), 0, gUnknown_203B2CC->unk56 + 1, 2, 7, gUnknown_203B2CC->unk6C);
    for(iVar2 = 0; iVar2 < gUnknown_203B2CC->unk52; iVar2++)
    {
        retvar = sub_8013800(&gUnknown_203B2CC->unk38, iVar2);
        new_index =  (gUnknown_203B2CC->unk56 * gUnknown_203B2CC->unk54) + iVar2;
        mailIndex = gUnknown_203B2CC->receivedNewsletters[new_index];
        sub_803B6B0(0xA, retvar, 6, gUnknown_203B2CC->unk6C);
        sub_802BC7C();
        xxx_format_and_draw(0x15, retvar, GetPokemonMailHeadline(mailIndex), gUnknown_203B2CC->unk6C, 0);
    }
    sub_80073E0(gUnknown_203B2CC->unk6C);
}

s32 GetNumPKMNNews(void)
{
    s32 iVar2;
    s32 newsCount;

    newsCount = 0;

    for(iVar2 = 0; iVar2 < NUM_POKEMON_NEWS; iVar2++)
    {
        if(CheckPKMNNewsSlot(iVar2))
        {
            gUnknown_203B2CC->receivedNewsletters[newsCount] = iVar2;
            newsCount++;
        }
    }
    return newsCount;
}

bool8 HasNoPKMNNews(void)
{
    s32 iVar2;

    for(iVar2 = 0; iVar2 < NUM_POKEMON_NEWS; iVar2++)
    {
        if(CheckPKMNNewsSlot(iVar2))
        {
            return FALSE;
        }
    }
    return TRUE;
}

u32 sub_802B9FC(u8 mailIndex)
{
    gUnknown_203B2D4 = MemoryAlloc(sizeof(struct unkStruct_203B2D4), 8);
    gUnknown_203B2D4->currMailIndex = mailIndex;
    sub_801317C(&gUnknown_203B2D4->unk88);
    gUnknown_203B2D4->unk24 = 0;
    gUnknown_203B2D4->unk28[0] = gUnknown_80DFC34;
    gUnknown_203B2D4->unk28[1] = gUnknown_80DFC18;
    gUnknown_203B2D4->unk28[2] = gUnknown_80DFC18;
    gUnknown_203B2D4->unk28[3] = gUnknown_80DFC18;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2D4->unk28, 1, 1);
    gUnknown_203B2D4->unk8 = 0;
    sub_802BCC4();
    sub_802BC7C();
    sub_802BB14(0);
    return 1;
}

u32 sub_802BA8C(void)
{
    switch(gUnknown_203B2D4->state)
    {
        case 0:
            sub_802BB98();
            break;
        case 1:
            sub_802BC08();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;

    }
    return 0;
}

void sub_802BACC(void)
{
    if(gUnknown_203B2D4 != NULL)
    {
        gUnknown_203B2D4->unk28[gUnknown_203B2D4->unk24] = gUnknown_80DFC18;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2D4->unk28, 1, 1);
        MemoryFree(gUnknown_203B2D4);
        gUnknown_203B2D4 = NULL;
    }
}

void sub_802BB14(u32 newState)
{
    gUnknown_203B2D4->state = newState;
    sub_802BB28();
}

void sub_802BB28(void)
{
    switch(gUnknown_203B2D4->state)
    {
        case 0:
        case 1:
            sub_8008C54(gUnknown_203B2D4->unk24);
            sub_80073B8(gUnknown_203B2D4->unk24);
            xxx_format_and_draw(0xA, 0, GetPokemonMailHeadline(gUnknown_203B2D4->currMailIndex), gUnknown_203B2D4->unk24, 0);
            xxx_format_and_draw(0x6, 0x14, gUnknown_203B2D4->unk10[gUnknown_203B2D4->unk8], gUnknown_203B2D4->unk24, 0);
            sub_80073E0(gUnknown_203B2D4->unk24);
            gUnknown_203B2D4->unk8++;
            break;
        case 2:
        case 3:
            break;
    }
}

void sub_802BB98(void)
{
    if(gUnknown_203B2D4->unkC != 0)
    {
        if(gUnknown_203B2D4->unk20 & 8)
            sub_8013E54();
        gUnknown_203B2D4->unk20++;
    }
    switch(sub_8012A64(&gUnknown_203B2D4->unk88, gUnknown_203B2D4->unk24))
    {
        case 1:
            PlayMenuSoundEffect(0);
            if(gUnknown_203B2D4->unkC != 0)
                sub_802BB14(1);
            else
                sub_802BB14(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_802BB14(2);
            break;
    }
}

void sub_802BC08(void)
{
    if(gUnknown_203B2D4->unk8 < gUnknown_203B2D4->unkC)
    {
        if(gUnknown_203B2D4->unk20 & 8)
            sub_8013E54();
        gUnknown_203B2D4->unk20++;
    }
    switch(sub_8012A64(&gUnknown_203B2D4->unk88, gUnknown_203B2D4->unk24))
    {
        case 1:
            PlayMenuSoundEffect(0);
            if(gUnknown_203B2D4->unk8 < gUnknown_203B2D4->unkC)
                sub_802BB14(1);
            else
                sub_802BB14(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_802BB14(2);
            break;
    }
}

void sub_802BC7C(void)
{
    PrintPokeNameToBuffer(gAvailablePokemonNames, sub_808D3BC());
    if(gUnknown_203B46C->playerGender == FEMALE)
    {
        strcpy(gAvailablePokemonNames + 0x50, gUnknown_80DFC4C); // She
    }
    else
    {
        strcpy(gAvailablePokemonNames + 0x50, gUnknown_80DFC50); // He
    }
}

void sub_802BCC4(void)
{
  const char *mailTextPtr;

  mailTextPtr = GetPokemonMailText(gUnknown_203B2D4->currMailIndex);
  gUnknown_203B2D4->unkC = 0;
  gUnknown_203B2D4->unk10[0] = mailTextPtr;

  // Count all the {EXTRA_MSG}'s
  while (*mailTextPtr != '\0') {
    if (*mailTextPtr == '#') {
      if ((mailTextPtr[1] == 'P') || (mailTextPtr[1] == 'p')) {
            gUnknown_203B2D4->unkC++;
            gUnknown_203B2D4->unk10[gUnknown_203B2D4->unkC] = mailTextPtr + 2;
      }
      mailTextPtr += 2;
    }
    else {
      mailTextPtr++;
    }
  }
}

u32 sub_802BD14(s32 param_1, struct UnkTextStruct2_sub *param_2, u32 param_3)
{

  if (HasNoMailinMailbox()) {
      return 0;
  }
  else
  {
    if (gUnknown_203B2D8 == NULL) {
      gUnknown_203B2D8 = MemoryAlloc(sizeof(struct unkStruct_203B2D8),8);
    }
    gUnknown_203B2D8->unk38 = param_1;
    gUnknown_203B2D8->unk3C = &gUnknown_203B2D8->unk40[param_1];
    sub_8006518(gUnknown_203B2D8->unk40);
    gUnknown_203B2D8->unk40[gUnknown_203B2D8->unk38] = gUnknown_80DFC74;
    gUnknown_203B2D8->unk3C->unk14 = gUnknown_203B2D8->unkA0;
    if (param_2 != NULL) {
        gUnknown_203B2D8->unk40[gUnknown_203B2D8->unk38].unk08 = *param_2;
    }
    sub_8012D34(gUnknown_203B2D8->unk3C,param_3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2D8->unk40,1,1);
    sub_8013848(&gUnknown_203B2D8->unk4,CountEmptyMailSlots(),param_3,param_1);
    gUnknown_203B2D8->unk1C = gUnknown_203B2DC;
    sub_8013984(&gUnknown_203B2D8->unk4);
    sub_802BF30();
    CreateMailMenu();
    return 1;
  }
}

u32 sub_802BDEC(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B2D8->unk4);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B2D8->unk4))
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
        default:
            if(sub_80138B8(&gUnknown_203B2D8->unk4, 1) != 0)
            {
                sub_802BF30();
                CreateMailMenu();
                return 1;
            }
            else
                return 0;
    }
}

u8 sub_802BE74(void) {
  return gUnknown_203B2D8->unk0[(gUnknown_203B2D8->unk22 * gUnknown_203B2D8->unk20) + gUnknown_203B2D8->unk1C];
}

void sub_802BE94(u32 r0)
{
    u8 temp;

    temp = r0;

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2D8->unk40, 0, 0);

    gUnknown_203B2D8->emptyMailSlots = CountEmptyMailSlots();
    sub_8013984(&gUnknown_203B2D8->unk4);
    sub_802BF30();
    CreateMailMenu();

    if(temp != 0)
    {
        AddMenuCursorSprite(&gUnknown_203B2D8->unk4);
    }
}

void sub_802BEDC(void)
{
    if(gUnknown_203B2D8 != NULL)
    {
        gUnknown_203B2DC = gUnknown_203B2D8->unk1C;
        gUnknown_203B2D8->unk40[gUnknown_203B2D8->unk38] = gUnknown_80DFC5C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2D8->unk40, 1, 1);
        MemoryFree(gUnknown_203B2D8);
        gUnknown_203B2D8 = NULL;
    }
}
