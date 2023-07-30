#include "global.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "text.h"
#include "team_inventory.h"
#include "menu_input.h"
#include "gulpin_shop.h"
#include "moves.h"

// size: 0x1E0
struct unkStruct_203B27C
{
    /* 0x0 */ bool32 isAsleep;
    /* 0x4 */ s32 state;
    /* 0x8 */ u32 fallbackState;
    /* 0xC */ s16 speciesNum;
    /* 0x10 */ struct PokemonStruct *pokeStruct;
    /* 0x14 */ bool8 isNextMoveLinked;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    /* 0x18 */ u32 moveIndex;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 fill22;
    /* 0x24 */ struct Move moves[4];
    u8 fill44[0x20];
    /* 0x64 */ u16 sequenceMoveIDs[4];
    u32 unk6C;
    u32 unk70;
    u32 unk74;
    u32 unk78;
    struct MenuItem unk7C[8];
    u16 unkBC[8];
    struct MenuStruct unkCC;
    u8 fill11C[0x16C - 0x11C];
    struct OpenedFile *unk16C;
    u8 *unk170;
    u16 unk174;
    u16 unk176;
    u8 unk178;
    u8 unk179;
    u8 unk17A;
    struct OpenedFile **unk17C;
    struct UnkTextStruct2 unk180[4];
};

extern struct unkStruct_203B27C *gUnknown_203B27C;

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DFE8[];
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

extern struct UnkTextStruct2 gUnknown_80DC31C;
extern struct UnkTextStruct2 gUnknown_80DC334;
extern struct UnkTextStruct2 gUnknown_80DC31C;
extern struct UnkTextStruct2 gUnknown_80DC34C;
extern struct UnkTextStruct2 gUnknown_80DC37C;

extern const u8 *gGulpinDialogue[2][25];
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

void CreateGulpinShopMenu(void);
extern void sub_8014248(const u8 *, u32, u32, const struct MenuItem *, void *, u32, u32, struct OpenedFile **, u32);
extern void sub_80141B4(const u8 *, u32, struct OpenedFile **, u32);
extern void DrawTeamMoneyBox(u32);
void sub_8020950(void);
void sub_8020900(void);
bool8 sub_801F808(u16 *moveIDs);
void sub_801F700(void);
bool8 sub_801F428(s16 index, s32 param_2);
void sub_801F5F0(u8 r0);
extern void sub_8023DA4(void);
extern void sub_8023868(u32, u32, u32, u32);
extern void sub_8023B7C(u32);
extern void sub_801F1B0(u32, u32);
extern void sub_801F280(u32);
void sub_8024458(u32, u32);
extern void sub_801BEEC(s16);
extern void sub_801EE10(u32, s16, struct Move *, u32, void *, u32);
void sub_80208B0(void);
void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
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

extern void CreateGulpinLinkMenu(void);
extern void sub_802069C(void);
extern void sub_80205D0(void);

bool8 sub_801FB50(bool32 isAsleep)
{
  char *name;
  struct OpenedFile *faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B27C = MemoryAlloc(sizeof(struct unkStruct_203B27C), 0x8);
  gUnknown_203B27C->unk70 = 0;
  gUnknown_203B27C->unk74 = 0;
  gUnknown_203B27C->unk78 = 0;
  gUnknown_203B27C->isAsleep = isAsleep;
  gUnknown_203B27C->unk15 = 0;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8,MONSTER_GULPIN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8,MONSTER_GULPIN);
  name = GetMonSpecies(MONSTER_GULPIN);
  strcpy(gUnknown_202E1C8 - 0x50, name);
  PrintPokeNameToBuffer(gUnknown_202E1C8 - 0xF0, GetPlayerPokemonStruct());
  if (gUnknown_203B27C->isAsleep == 1) {
    gUnknown_203B27C->unk17C = NULL;
  }
  else {
    gUnknown_203B27C->unk17C = &gUnknown_203B27C->unk16C;
  }
  faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
  gUnknown_203B27C->unk16C = faceFile;
  gUnknown_203B27C->unk170 = faceFile->data;
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
            if (gUnknown_203B27C->unk15 == 1) {
                gTeamInventory_203B460->teamMoney -= 150;
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
        CloseFile(gUnknown_203B27C->unk16C);
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
            sub_800641C(gUnknown_203B27C->unk180, 1, 0);
            break;
        case 0x11:
            sub_80205D0();
            gUnknown_203B27C->unk180[2] = gUnknown_80DC334;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, 1, 1);
            break;
        case 0x17:
            sub_802069C();
            gUnknown_203B27C->unk180[2] = gUnknown_80DC334;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, 1, 1);
            break;
        case 0x20:
            CreateGulpinLinkMenu();
            gUnknown_203B27C->unk180[1] = gUnknown_80DC31C;
            gUnknown_203B27C->unk180[2] = gUnknown_80DC34C;
            sub_8012CAC(&gUnknown_203B27C->unk180[2], gUnknown_203B27C->unk7C);
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, 1, 1);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B27C->unk180[index]  = gUnknown_80DC31C;
            }
            ResetUnusedInputStruct();
            sub_800641C(gUnknown_203B27C->unk180, 1, 1);
            break;
    }
}

void sub_801FF28(void)
{
    s32 index;

    switch(gUnknown_203B27C->state)
    {
        case 0:
            gUnknown_203B27C->unk6C = 2;
            CreateGulpinShopMenu();
            gUnknown_203B27C->fallbackState = 2;
            sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][0],0,gUnknown_203B27C->unk6C,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,gUnknown_203B27C->unk17C,0xc);
            break;
        case 1:
            CreateGulpinShopMenu();
            gUnknown_203B27C->fallbackState = 2;
            sub_8014248(gGulpinDialogue[gUnknown_203B27C->isAsleep][1],0,gUnknown_203B27C->unk6C,gUnknown_203B27C->unk7C,gUnknown_203B27C->unkBC,4,0,gUnknown_203B27C->unk17C,0xc);
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
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->unk70,2);
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
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->unk74,2);
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
            sub_8012D60(&gUnknown_203B27C->unkCC,gUnknown_203B27C->unk7C,0,gUnknown_203B27C->unkBC,gUnknown_203B27C->unk78,2);
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

extern u8 gUnknown_80DC3D8[];
extern u8 gUnknown_80DC3E0[];
extern u8 gUnknown_80DC3E8[];
extern u8 gUnknown_80DC3F4[];
extern u8 *gUnknown_80D4970[];

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
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->unk70)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->unk70 = gUnknown_203B27C->unk7C[i].menuAction;
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
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->unk74)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->unk74 = gUnknown_203B27C->unk7C[i].menuAction;
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

    if(gUnknown_203B27C->unk16)
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
        if (gUnknown_203B27C->unkBC[i] == 0 && gUnknown_203B27C->unk7C[i].menuAction == gUnknown_203B27C->unk78)
            return;
    }
    for (i = 0; i < loopMax; i++) {
        if (gUnknown_203B27C->unkBC[i] == 0) {
            gUnknown_203B27C->unk78 = gUnknown_203B27C->unk7C[i].menuAction;
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
