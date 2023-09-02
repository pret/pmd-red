#include "global.h"
#include "memory.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"

#include "menu_input.h"
#include "gulpin_shop.h"
#include "moves.h"
#include "felicity_bank.h"
#include "code_80130A8.h"
#include "code_801EE10_1.h"
#include "code_80118A4.h"

// size: 0x1E0
struct unkStruct_203B27C
{
    /* 0x0 */ bool32 isAsleep;
    /* 0x4 */ s32 state;
    /* 0x8 */ u32 fallbackState;
    /* 0xC */ s16 speciesNum;
    /* 0x10 */ PokemonStruct1 *pokeStruct;
    /* 0x14 */ bool8 isNextMoveLinked;
    bool8 unk15;
    /* 0x16 */ bool8 isTeamLeader;
    /* 0x18 */ u32 moveIndex;
    // Group of move ids but not sure purpose just yet...
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    /* 0x24 */ struct Move moves[MAX_MON_MOVES * 2];
    /* 0x64 */ u16 sequenceMoveIDs[MAX_MON_MOVES];
    /* 0x6C */ u32 menuAction1;
    /* 0x70 */ u32 menuAction2;
    /* 0x74 */ u32 menuAction3;
    /* 0x78 */ u32 menuAction4;
    MenuItem unk7C[8];
    u16 unkBC[8];
    MenuStruct unkCC;
    u8 fill11C[0x16C - 0x11C];
    /* 0x16C */ OpenedFile *faceFile;
    /* 0x170 */ u8 *faceData;
    u16 unk174;
    u16 unk176;
    u8 unk178;
    u8 unk179;
    u8 unk17A;
    OpenedFile **unk17C;
    UnkTextStruct2 unk180[4];
};

EWRAM_DATA_2 struct unkStruct_203B27C *gUnknown_203B27C = {0};

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DFE8[];
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

extern UnkTextStruct2 gUnknown_80DC31C;
extern UnkTextStruct2 gUnknown_80DC334;
extern UnkTextStruct2 gUnknown_80DC31C;
extern UnkTextStruct2 gUnknown_80DC34C;
extern UnkTextStruct2 gUnknown_80DC37C;

extern const u8 *gGulpinDialogue[2][25];
extern u8 gUnknown_80DC3D8[];
extern u8 gUnknown_80DC3E0[];
extern u8 gUnknown_80DC3E8[];
extern u8 gUnknown_80DC3F4[];
extern u8 gUnknown_80DC394[];
extern u8 gGulpinProceed[];
extern u8 gGulpinInfo[];
extern u8 *gUnknown_80D4934[];
extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 gGulpinForget[];
extern u8 gGulpinLink[];
extern u8 gGulpinDelink[];
extern u8 gGulpinSet[];
extern u8 gGulpinDeselect[];
extern u8 *gUnknown_80D4970[];
extern u8 gUnknown_80DC428[];
extern u8 gUnknown_80DC438[];
extern u8 gUnknown_80DC448[];
extern u8 gUnknown_202E128[];

bool8 sub_8021178(void);
void CreateGulpinShopMenu(void);
void sub_8020950(void);
void sub_8020900(void);
bool8 sub_801F808(u16 *moveIDs);
void sub_801F700(void);
bool8 sub_801F428(s16 index, s32 param_2);
void sub_801F5F0(u8 r0);
extern void sub_801F1B0(u32, u32);
extern void sub_801F280(u32);
void sub_8024458(u32, u32);
extern void sub_801BEEC(s16);
extern void sub_801EE10(u32, s16, struct Move *, u32, void *, u32);
void sub_80208B0(void);
void PrintPokeNameToBuffer(u8 *buffer, PokemonStruct1 *pokemon);
extern PokemonStruct1 *GetPlayerPokemonStruct(void);
extern void sub_801FDA8(s32);
extern void sub_8020A80(void);
extern void sub_8020B38(void);
extern void sub_8020C2C(void);
extern void sub_8020C48(void);
extern void sub_8020C64(void);
extern void sub_8020CC0(void);
extern void sub_8020D74(void);
extern void sub_8020D90(void);
extern void sub_8020DCC(void);
extern void sub_8020EB4(void);
extern void sub_80210C8(void);
extern void sub_80210E4(void);
extern void sub_8021154(void);
extern void sub_80209AC(void);
extern void sub_8021130(void);
extern void sub_80209FC(void);
extern void sub_8020A34(void);
extern void sub_801FDC0(void);
extern void sub_801FF28(void);
extern u32 sub_80244E4(void);
extern u32 sub_801BF48(void);
extern void sub_802453C(void);
extern void sub_801BF98(void);
extern u32 sub_801F520(u32);
extern void sub_801F63C(void);
extern u16 sub_801F5B4(void);
extern void sub_801F8D0(void);
extern u32 sub_801F890(void);
extern u32 sub_801E8C0(void);
extern u32 sub_801F194(void);
bool8 sub_801F1A4(void);
void sub_801F214(void);
extern u32 sub_801EF38(u32);

extern void CreateGulpinLinkMenu(void);
extern void sub_802069C(void);
extern void sub_80205D0(void);

bool8 sub_801FB50(bool32 isAsleep)
{
  char *name;
  OpenedFile *faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(NULL, TRUE, TRUE);
  gUnknown_203B27C = MemoryAlloc(sizeof(struct unkStruct_203B27C), 0x8);
  gUnknown_203B27C->menuAction2 = 0;
  gUnknown_203B27C->menuAction3 = 0;
  gUnknown_203B27C->menuAction4 = 0;
  gUnknown_203B27C->isAsleep = isAsleep;
  gUnknown_203B27C->unk15 = FALSE;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_GULPIN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_GULPIN);
  name = GetMonSpecies(MONSTER_GULPIN);
  strcpy(gUnknown_202E1C8 - 0x50, name);
  PrintPokeNameToBuffer(gUnknown_202E1C8 - 0xF0, GetPlayerPokemonStruct());
  if (gUnknown_203B27C->isAsleep == 1) {
    gUnknown_203B27C->unk17C = NULL;
  }
  else {
    gUnknown_203B27C->unk17C = &gUnknown_203B27C->faceFile;
  }
  faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
  gUnknown_203B27C->faceFile = faceFile;
  gUnknown_203B27C->faceData = faceFile->data;
  gUnknown_203B27C->unk178 = 0;
  gUnknown_203B27C->unk179 = 0;
  gUnknown_203B27C->unk17A = 0;
  gUnknown_203B27C->unk174 = 2;
  gUnknown_203B27C->unk176 = 8;
  sub_801FDA8(0);
  return TRUE;
}

u32 sub_801FC40(void)
{
    switch(gUnknown_203B27C->state) {
        case 0:
        case 1:
            sub_8021154();
            break;
        case 2:
            sub_80209AC();
            break;
        case 7:
            sub_80209FC();
            break;
        case 8:
            sub_8020A34();
            break;
        case 0xf:
        case 0x10:
            sub_8020A80();
            break;
        case 0x11:
            sub_8020B38();
            break;
        case 0x12:
            sub_8020C2C();
            break;
        case 0x13:
            sub_8020C48();
            break;
        case 0x15:
        case 0x16:
            sub_8020C64();
            break;
        case 0x17:
            sub_8020CC0();
            break;
        case 0x18:
            sub_8020D74();
            break;
        case 0x1d:
            sub_8020D90();
            break;
        case 0x1e:
        case 0x1f:
            sub_8020DCC();
            break;
        case 0x20:
            sub_8020EB4();
            break;
        case 0x21:
            sub_80210C8();
            break;
        case 0x22:
            sub_80210E4();
            break;
        case 0xd:
            if (gUnknown_203B27C->unk15 == TRUE) {
                gTeamInventoryRef->teamMoney -= 150;
            }
            return 3;
        default:
            sub_8021130();
            break;
    }
    return 0;
}

void sub_801FD7C(void)
{
    if(gUnknown_203B27C)
    {
        CloseFile(gUnknown_203B27C->faceFile);
        MemoryFree(gUnknown_203B27C);
        gUnknown_203B27C = NULL;
    }
}

void sub_801FDA8(s32 newState)
{
    gUnknown_203B27C->state = newState;
    sub_801FDC0();
    sub_801FF28();
}

void sub_801FDC0(void)
{
    s32 index;

    sub_8006518(gUnknown_203B27C->unk180);
    switch(gUnknown_203B27C->state)
    {
        case 0x2:
            gUnknown_203B27C->unk180[0].unk0 = 0x80;
            gUnknown_203B27C->unk180[1].unk0 = 0x80;
            gUnknown_203B27C->unk180[2].unk0 = 0x80;
            gUnknown_203B27C->unk180[3] = gUnknown_80DC37C;
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, TRUE, FALSE);
            break;
        case 0x11:
            sub_80205D0();
            gUnknown_203B27C->unk180[2] = gUnknown_80DC334;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
        case 0x17:
            sub_802069C();
            gUnknown_203B27C->unk180[2] = gUnknown_80DC334;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
        case 0x20:
            CreateGulpinLinkMenu();
            gUnknown_203B27C->unk180[1] = gUnknown_80DC31C;
            gUnknown_203B27C->unk180[2] = gUnknown_80DC34C;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B27C->unk180[index] = gUnknown_80DC31C;
            }
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, TRUE, TRUE);
            break;
    }
}

void sub_801FF28(void)
{
    s32 index;

    switch(gUnknown_203B27C->state)
    {
        case 0:
            gUnknown_203B27C->menuAction1 = 2;
            CreateGulpinShopMenu();
            gUnknown_203B27C->fallbackState = 2;
            sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][0],0,gUnknown_203B27C->menuAction1,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,gUnknown_203B27C->unk17C,0xc);
            break;
        case 1:
            CreateGulpinShopMenu();
            gUnknown_203B27C->fallbackState = 2;
            sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][1],0,gUnknown_203B27C->menuAction1,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,gUnknown_203B27C->unk17C,0xc);
            break;
        case 2:
            DrawTeamMoneyBox(3);
            break;
        case 3:
            gUnknown_203B27C->fallbackState = 0x1f;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][2],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 4:
            gUnknown_203B27C->fallbackState = 0x1f;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][3],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 5:
            gUnknown_203B27C->fallbackState = 0x1f;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][4],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 6:
            gUnknown_203B27C->fallbackState = 0x1f;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][5],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 7:
            sub_8020900();
            sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][6],0,0x10,
                        gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                        gUnknown_203B27C->unk17C,0xc);
            break;
        case 8:
            sub_8020950();
            sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][21],0,0xd,
                        gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                        gUnknown_203B27C->unk17C,0xc);
            break;
        case 9:
            gUnknown_203B27C->fallbackState = 1;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][22],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 10:
            gUnknown_203B27C->fallbackState = 1;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][23],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0xb:
            gUnknown_203B27C->fallbackState = 1;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][24],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0xc:
            gUnknown_203B27C->fallbackState = 0xd;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][7],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0xe:
            gUnknown_203B27C->fallbackState = 0xf;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][8],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0xf:
            sub_8023868(2,0,0,10);
            break;
        case 0x10:
            sub_8023B7C(1);
            break;
        case 0x11:
            sub_8023DA4();
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->menuAction2,2);
            break;
        case 0x12:
            sub_8024458(gUnknown_203B27C->speciesNum,2);
            break;
        case 0x13:
            sub_801BEEC(gUnknown_203B27C->speciesNum);
            break;
        case 0x14:
            gUnknown_203B27C->fallbackState = 0x15;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][9],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0x15:
            sub_801F428(gUnknown_203B27C->speciesNum,0);
            break;
        case 0x16:
            sub_801F5F0(1);
            break;
        case 0x17:
            sub_801F700();
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->menuAction3,2);
            break;
        case 0x18:
            gUnknown_203B27C->sequenceMoveIDs[0] = gUnknown_203B27C->unk1C;
            for(index = 1; index < 4; index++)
            {
                gUnknown_203B27C->sequenceMoveIDs[index] = 0;
            }
            sub_801F808(gUnknown_203B27C->sequenceMoveIDs);
            break;
        case 0x19:
            sub_8094060(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            gUnknown_203B27C->fallbackState = 0x10;
            sub_8092C84(gAvailablePokemonNames,gUnknown_203B27C->unk1E);
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][10],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0x1a:
            sub_8094060(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            gUnknown_203B27C->fallbackState = 0x10;
            if (gUnknown_203B27C->isNextMoveLinked) {
                sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][14],0,gUnknown_203B27C->unk17C,0x10d);
            }
            else
        {
                sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][13],0,gUnknown_203B27C->unk17C,0x10d);
            }
            break;
        case 0x1d:
            if (gUnknown_203B27C->isAsleep == FALSE) {
                CreateGulpinShop(FALSE,gUnknown_203B27C->speciesNum,gUnknown_203B27C->moves);
            }
            else {
                CreateGulpinShop(TRUE,gUnknown_203B27C->speciesNum,gUnknown_203B27C->moves);
            }
            break;
        case 0x1b:
            gUnknown_203B27C->fallbackState = 0x10;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][15],0,gUnknown_203B27C->unk17C,0x10d);
            break;
        case 0x1c:
            gUnknown_203B27C->fallbackState = 0x10;
            sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][16],0,gUnknown_203B27C->unk17C,0x10d);
            break;

        case 0x1e:
            unk_CopyMoves4To8(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            sub_801EE10(1,gUnknown_203B27C->speciesNum,gUnknown_203B27C->moves,gUnknown_203B27C->unk15,gUnknown_80DC394,0);
            break;
        case 0x1f:
            sub_801F1B0(1,gUnknown_203B27C->unk15);
            break;
        case 0x20:
            sub_801F280(0);
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->menuAction4,2);
            break;
        case 0x21:
            GetLinkedSequence(gUnknown_203B27C->moveIndex,gUnknown_203B27C->moves,gUnknown_203B27C->sequenceMoveIDs);
            sub_801F808(gUnknown_203B27C->sequenceMoveIDs);
            break;
        case 0x22:
            sub_80208B0();
            sub_8092C84(gUnknown_202DFE8,gUnknown_203B27C->unk20);
            if (gUnknown_203B27C->isNextMoveLinked) {
                sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][18],0,0x11,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                            gUnknown_203B27C->unk17C,0xc);
            }
            else {
                sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][17],0,0x11,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,
                            gUnknown_203B27C->unk17C,0xc);
            }
            break;
        case 0x23:
            gUnknown_203B27C->fallbackState = 0x1f;
            sub_8092C84(gUnknown_202DFE8,gUnknown_203B27C->unk20);
            if (gUnknown_203B27C->isNextMoveLinked) 
            {
                sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][20],0,gUnknown_203B27C->unk17C,0x10d);
            }
            else
        {
                sub_80141B4(gGulpinDialogue[gUnknown_203B27C->isAsleep][19],0,gUnknown_203B27C->unk17C,0x10d);
            }
            break;
    }
}

void CreateGulpinShopMenu(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinProceed;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 2;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinInfo;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xb;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4934;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = 0x0;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;
}

void sub_80205D0(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;
    
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3D8;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 4;
    
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3E0;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xB;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3E8;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xC;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3F4;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x3;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->menuAction2)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->menuAction2 = gUnknown_203B27C->unk7C[i].menuAction;
            break;
        }
    }
}

void sub_802069C(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;
    
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC3F4;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x3;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xB;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->menuAction3)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->menuAction3 = gUnknown_203B27C->unk7C[i].menuAction;
            break;
        }
    }
}

void CreateGulpinLinkMenu(void)
{
    s32 loopMax;
    s32 i;
    loopMax = 0;
    
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));

    if(gUnknown_203B27C->isTeamLeader)
    {
        if(IsMoveSet(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinDeselect;
            gUnknown_203B27C->unk7C[loopMax].menuAction = 6;
        }
        else
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinSet;
            gUnknown_203B27C->unk7C[loopMax].menuAction = 5;
        }
    }
    else
    {
        if(IsMoveEnabled(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinDeselect;
        }
        else
        {
            gUnknown_203B27C->unk7C[loopMax].text = gGulpinSet;
        }
        gUnknown_203B27C->unk7C[loopMax].menuAction = 7;
    }
    
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinLink;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x8;
    
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinDelink;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x9;
    
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gGulpinForget;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xA;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xB;

    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;

    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->menuAction4)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->menuAction4 = gUnknown_203B27C->unk7C[i].menuAction;
            break;
        }
    }
}

void sub_80208B0(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x10;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x11;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;
}

void sub_8020900(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x10;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0x11;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = -1;
}

void sub_8020950(void)
{
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B27C->unkBC, 0, sizeof(gUnknown_203B27C->unkBC));

    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC428;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xD;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC438;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xE;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = gUnknown_80DC448;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 0xF;
    loopMax++;
    gUnknown_203B27C->unk7C[loopMax].text = NULL;
    gUnknown_203B27C->unk7C[loopMax].menuAction = 1;
}

void sub_80209AC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        gUnknown_203B27C->menuAction1 = menuAction;
        switch(menuAction)
        {
            case 2:
                sub_801FDA8(0xe);
                break;
            case 0xB:
                sub_801FDA8(0x8);
                break;
            case 1:
                sub_801FDA8(0xC);
                break;
        }
    }
}

void sub_80209FC(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 0x10:
                sub_801FDA8(0xe);
                break;
            case 0x11:
            case 1:
                sub_801FDA8(0xC);
                break;
        }
    }
}

void sub_8020A34(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 0xD:
                sub_801FDA8(0x9);
                break;
            case 0xE:
                sub_801FDA8(10);
                break;
            case 0xF:
                sub_801FDA8(0xb);
                break;
            case 1:
                sub_801FDA8(0x1);
                break;
        }
    }
}

void sub_8020A80(void)
{
    switch(sub_8023A94(TRUE))
    {
        case 3:
            gUnknown_203B27C->speciesNum = sub_8023B44();
            gUnknown_203B27C->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B27C->speciesNum];
            gUnknown_203B27C->isTeamLeader = gUnknown_203B27C->pokeStruct->isTeamLeader;
            PrintPokeNameToBuffer(gUnknown_202E128, gUnknown_203B27C->pokeStruct);
            sub_801FDA8(0x11);
            break;
        case 4:
            gUnknown_203B27C->speciesNum = sub_8023B44();
            gUnknown_203B27C->pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B27C->speciesNum];
            gUnknown_203B27C->isTeamLeader = gUnknown_203B27C->pokeStruct->isTeamLeader;
            PrintPokeNameToBuffer(gUnknown_202E128, gUnknown_203B27C->pokeStruct);
            sub_801FDA8(0x12);
            break;
        case 0:
        case 1:
            break;
        case 2:
            sub_8023C60();
            sub_801FDA8(7);
            break;
    }
}

void sub_8020B38(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_8023A94(FALSE);
    if (!sub_8012FD8(&gUnknown_203B27C->unkCC)) {
        sub_8013114(&gUnknown_203B27C->unkCC,&menuAction);
        if (menuAction != 1) {
            gUnknown_203B27C->menuAction2 = menuAction;
        }
    }

    switch(menuAction)
    {
        case 0x1:
        case 0x11:
            sub_801FDA8(0x10);
            break;
        case 0x3:
            if(GetBaseSpeciesNoUnown(gUnknown_203B27C->pokeStruct->speciesNum) == MONSTER_DEOXYS_NORMAL)
            {
                sub_801FDA8(0x1C);
            }
            else if(sub_8021178())
            {
                sub_801FDA8(0x1b);
            }
            else
            {
                sub_801FDA8(0x14);
            }
            break;
        case 0x4:
            sub_801FDA8(0x1e);
            break;
        case 0xB:
            sub_801FDA8(0x12);
            break;
        case 0xC:
            sub_801FDA8(0x13);
            break;
    }
}

void sub_8020C2C(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            sub_801FDA8(0x10);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8020C48(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            sub_801BF98();
            sub_801FDA8(0x10);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8020C64(void)
{
    switch(sub_801F520(1))
    {
        case 3:
            gUnknown_203B27C->unk1E = gUnknown_203B27C->unk1C = sub_801F5B4();
            sub_801FDA8(0x17);
            break;
        case 4:
            gUnknown_203B27C->unk1E = gUnknown_203B27C->unk1C = sub_801F5B4();
            sub_801FDA8(0x18);
            break;
        case 2:
            sub_801F63C();
            sub_801FDA8(0x10);
            break;
    }
}

void sub_8020CC0(void)
{
    s32 menuAction;
    s32 index;
    struct Move *move;
    
    menuAction = 0;
    sub_801F520(0);
    if (!sub_8012FD8(&gUnknown_203B27C->unkCC)) {
        sub_8013114(&gUnknown_203B27C->unkCC,&menuAction);
        if (menuAction != 1) {
            gUnknown_203B27C->menuAction3 = menuAction;
        }
    }

    switch(menuAction)
    {
        case 0x1:
        case 0x11:
            sub_801FDA8(0x16);
            break;
        case 0x3:
            sub_801F63C();
            unk_CopyMoves4To8(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
            for(index = 0; index < MAX_MON_MOVES * 2; index++)
            {
                move = &gUnknown_203B27C->moves[index];
                if(!(move->moveFlags & MOVE_FLAG_EXISTS))
                {
                    InitZeroedPPPokemonMove(move,gUnknown_203B27C->unk1E);
                    break;
                }
            }
            if(index >= MAX_MON_MOVES)
            {
                sub_801FDA8(0x1d);
            }
            else
            {
                sub_801FDA8(0x19);
            }
            break;
        case 0xB:
            sub_801FDA8(0x18);
            break;
    }
}

void sub_8020D74(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            sub_801FDA8(0x16);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8020D90(void)
{
    switch(sub_801E8C0())
    {
        case 3:
            gUnknown_203B27C->isNextMoveLinked = GulpinIsNextMoveLinked();
            DestroyGulpinShop();
            sub_801FDA8(0x1A);
            break;
        case 2:
            DestroyGulpinShop();
            sub_801FDA8(0x10);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8020DCC(void)
{
  switch(sub_801EF38(1)) {
      case 3:
        if (sub_801F1A4() != 0) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        gUnknown_203B27C->moveIndex = sub_801F194();
        gUnknown_203B27C->unk1C = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        gUnknown_203B27C->unk20 = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        sub_801FDA8(0x20);
        break;
      case 4:
        if (sub_801F1A4() != 0) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        gUnknown_203B27C->moveIndex = sub_801F194();
        gUnknown_203B27C->unk1C = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        gUnknown_203B27C->unk20 = gUnknown_203B27C->moves [gUnknown_203B27C->moveIndex].id;
        sub_801FDA8(0x21);
        break;
      case 2:
        if (sub_801F1A4() != 0) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        sub_801F214();
        sub_8094060(gUnknown_203B27C->moves,gUnknown_203B27C->pokeStruct->moves);
        sub_801FDA8(0x10);
        break;
      case 1:
        if (sub_801F1A4() != 0) {
          gUnknown_203B27C->unk15 = TRUE;
        }
        break;
      case 0:
          break;
  }
}

void sub_8020EB4(void)
{
    s32 menuAction;
    
    menuAction = 0;
    sub_801EF38(0);
    if (!sub_8012FD8(&gUnknown_203B27C->unkCC)) {
        sub_8013114(&gUnknown_203B27C->unkCC,&menuAction);
        if (menuAction != 1) {
            gUnknown_203B27C->menuAction4 = menuAction;
        }
    }

    switch(menuAction)
    {
        case 5:
            if(ToggleSetMove(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlaySound(0x133);
                sub_801FDA8(0x1F);
            }
            else
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x1F);
            }
            break;
        case 6:
            PlaySound(0x133);
            UnSetMove(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves);
            sub_801FDA8(0x1F);
            break;
        case 7:
            if(ToggleMoveEnabled(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlaySound(0x133);
                asm("");
            }
            else
            {
                PlayMenuSoundEffect(2);
            }
            sub_801FDA8(0x1F);
            break;
        case 8:
            if(gTeamInventoryRef->teamMoney < 150)
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x3);        
            }
            else if(!sub_8093318(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x4);        
            }
            else
            {
                if(!gUnknown_203B27C->unk15)
                {
                    gUnknown_203B27C->unk15 = TRUE;
                    PlaySound(0x14c);
                }
                else
                {
                    PlaySound(0x133);
                }
                TryLinkMovesAfter(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves);
                sub_801FDA8(0x1F);
            }
            break;
        case 9:
            if(!sub_809333C(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x5);     
            }
            else
            {
                PlaySound(0x133);
                UnlinkMovesAfter(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves);
                sub_801FDA8(0x1F);
            }
            break;
        case 1:
        case 0x11:
            sub_801FDA8(0x1F);
            break;
        case 0xA:
            if(!IsAnyMoveLinked(gUnknown_203B27C->moveIndex, gUnknown_203B27C->moves))
            {
                PlayMenuSoundEffect(2);
                sub_801FDA8(0x6);
            }
            else
            {
                PlaySound(0x133);
                gUnknown_203B27C->isNextMoveLinked = IsNextMoveLinked(gUnknown_203B27C->moveIndex,gUnknown_203B27C->moves);
                sub_801FDA8(0x22);
            }
            break;
        case 0xB:
            sub_801FDA8(0x21);
            break;
        case 0xC ... 0xF:
            break;
    }
}

void sub_80210C8(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            sub_801FDA8(0x1F);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_80210E4(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        switch(menuAction)
        {
            case 0x10:
                RemoveLinkSequenceFromMoves8(gUnknown_203B27C->moves, gUnknown_203B27C->moveIndex);
                sub_801FDA8(0x23);
                break;
            case 1:
            case 0x11:
                sub_801FDA8(0x1F);
                break;
        }
    }
}

void sub_8021130(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_801FDA8(gUnknown_203B27C->fallbackState);
    }
}

void sub_8021154(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 4)
    {
        sub_801FDA8(gUnknown_203B27C->fallbackState);
    }
}

bool8 sub_8021178(void)
{
    s32 count;
    unkStruct_808E218_arg local;

    count = sub_808E218(&local, gUnknown_203B27C->pokeStruct);
    if(count == 0) return TRUE;
    else return FALSE;
}
