#include "global.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "file_system.h"
#include "input.h"
#include "text.h"
#include "team_inventory.h"

extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202E1C8[];

// size: 0x1E0
struct unkStruct_203B27C
{
    bool32 isAsleep;
    s32 state;
    u32 unk8;
    s16 unkC;
    struct PokemonStruct *unk10;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u32 unk18;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u8 fill22[0x64 - 0x22];
    u16 unk64[4];
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
                gTeamInventory_203B460->teamMoney -= 0x96;
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
