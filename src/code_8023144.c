#include "constants/input.h"
#include "global.h"
#include "constants/iq_skill.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "text.h"
#include "input.h"
#include "item.h"
#include "menu_input.h"

struct unkStruct_3001B5C
{
    // size: 0x3fC
    u8 unk0;
    u32 unk4;
    u32 unk8;
    s16 unkC[2];
    u32 unk10;
    u8 fill14[0x354 - 0x14];
    u8 unk354;
    u8 fill355[0x35C - 0x355];
    u8 unk35C;
    u8 fill35D[0x374 - 0x35D];
    s16 unk374;
    s16 unk376;
    s16 unk378;
    s16 unk37A;
    u8 fill37C[0x390 - 0x37C];
    u32 unk390;
    struct UnkTextStruct2 *unk394;
    struct UnkTextStruct2 unk398[4];
    u8 unk3F8[4];
};

IWRAM_DATA struct unkStruct_3001B5C *gUnknown_3001B5C;

extern u32 gUnknown_203B298;
extern u16 gUnknown_203B29C;
extern u16 gUnknown_203B29E;
extern struct UnkTextStruct2 gUnknown_80DC91C;
extern struct UnkTextStruct2 gUnknown_80DC904;

extern u8 sub_8023704(u8);
extern void sub_8013818(void *, u32, u32, u32);
extern void sub_8013984(u8 *);
extern void sub_8023420(void);
extern void sub_80234BC(void);
extern u32 sub_80236A4(void);
extern u8 sub_80138B8(void *, u32);
extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(void *);
extern void sub_8013660(void *);
extern void AddMenuCursorSprite(void *);

struct unkStruct_203B294
{   
    // size: 0x1A8
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 fallbackState;
    u8 iqSkillPreGummi[NUM_IQ_SKILLS];
    u8 iqSkillPostGummi[NUM_IQ_SKILLS];
    u32 availIQSkillPreGummi;
    u32 availIQSkillPostGummi;
    u32 unk40; // Gummi eaten flag?
    struct Gummi gummi;
    /* 0x48 */ struct PokemonStruct *pokeStruct;
    u32 itemIndex;
    struct Item item;
    struct MenuStruct unk54;
    struct MenuStruct unkA4;
    u32 menuAction;
    u32 unkF8;
    u16 unkFC;
};

struct unkStruct_203B294 *gUnknown_203B294;

extern u8 gUnknown_80DC5EC[];
extern u8 gUnknown_202DE58[];
extern void sub_8022924(s32);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801B00C(void);
extern void sub_801B048(void);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
void GetGummiItemStatBoost(struct PokemonStruct* pokemon, u8 id, bool8 checkBoostFlags, struct Gummi* gummi);

extern u32 sub_801A6E8(u32);
extern void sub_8099690(u32);
extern void sub_801A928(void);
s32 GetNumAvailableIQSkills(u8 *iqSkillBuffer, s32 pokeIQ);
extern u32 sub_801A8AC(void);

void sub_8022E78(void)
{ 
  switch(sub_801A6E8(1))
  {
      case 3:
        gUnknown_203B294->itemIndex = sub_801A8AC();
        gUnknown_203B294->item = gTeamInventory_203B460->teamItems[gUnknown_203B294->itemIndex];
        sub_8022924(2);
        break;
      case 4:
        gUnknown_203B294->itemIndex = sub_801A8AC();
        gUnknown_203B294->item = gTeamInventory_203B460->teamItems[gUnknown_203B294->itemIndex];
        sub_8099690(0);
        sub_8022924(4);
        break;
      case 2:
        sub_8022924(0x16);
        break;
  }
}

void sub_8022EF4(void)
{
  s32 menuAction;
  s32 boostAmount;
  
  menuAction = 0;
  sub_801A6E8(0);
  if (sub_8012FD8(&gUnknown_203B294->unk54) == 0) {
    sub_8013114(&gUnknown_203B294->unk54,&menuAction);
    if(menuAction != 1) gUnknown_203B294->menuAction = menuAction;
  }

  switch(menuAction)
  {
      case 1:
        sub_8022924(1);
        break;
      case 2:
      case 3:
        break;
      case 5:
        gUnknown_203B294->availIQSkillPreGummi = GetNumAvailableIQSkills(gUnknown_203B294->iqSkillPreGummi, gUnknown_203B294->pokeStruct->IQ);
        GetGummiItemStatBoost(gUnknown_203B294->pokeStruct, gUnknown_203B294->item.id, FALSE, &gUnknown_203B294->gummi);
        gUnknown_203B294->availIQSkillPostGummi = GetNumAvailableIQSkills(gUnknown_203B294->iqSkillPostGummi, gUnknown_203B294->pokeStruct->IQ);
        gUnknown_203B294->unk40 = 1;
        boostAmount = gUnknown_203B294->gummi.boostAmount;

        sub_8090E14(gUnknown_202DE58, &gTeamInventory_203B460->teamItems[gUnknown_203B294->itemIndex], NULL);
        
        if(boostAmount != -1)
            ShiftItemsDownFrom(gUnknown_203B294->itemIndex);

        sub_8099690(0);
        gUnknown_203B294->fallbackState = 0xA;

        switch(boostAmount + 1)
        {
            case 1:
                sub_8022924(6);
                break;
            case 2:
                sub_8022924(7);
                break;
            case 3:
                sub_8022924(8);
                break;
            case 4:
                sub_8022924(9);
                break;
            default:
            case 0:
                gUnknown_203B294->fallbackState = 0x16;
                sub_8022924(5);
                break;
        }
        break;
      case 6:
        sub_8022924(0x15);
        break;
      case 4:
        sub_8022924(3);
        break;
      case 7:
        sub_8099690(0);
        sub_8022924(4);
        break;
  }
}

void sub_8023068(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801A6E8(0);
  sub_8012FD8(&gUnknown_203B294->unk54);
  if (sub_8012FD8(&gUnknown_203B294->unkA4) == 0) {
    sub_8013114(&gUnknown_203B294->unkA4,&menuAction);
  }

  switch(menuAction)
  {      
      case 1:
      case 3:
            sub_8022924(1);
            break;
      case 2:
        ShiftItemsDownFrom(gUnknown_203B294->itemIndex);
        if (GetNumberOfFilledInventorySlots() == 0) {
            sub_8099690(0);
            sub_801A928();
            sub_8022924(0x14);
        }
        else {
            sub_8022924(1);
        }
        break;
  }
}

void sub_80230E8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8022924(1);
        case 1:
        case 0:
            break;
    }
}

void sub_8023104(void)
{
    switch(sub_801B00C())
    {
        case 2:
        case 3:
            sub_801B048();
            sub_8022924(1);
        case 1:
        case 0:
            break;
    }
}

void sub_8023120(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_8022924(gUnknown_203B294->fallbackState);
    }
}

bool8 sub_8023144(s32 param_1, s32 index, struct UnkTextStruct2_sub *sub, u32 param_4)
{
  u8 param_1_u8 = param_1;

  if (sub_8023704(param_1_u8)) {
    return 0;
  }
  if (gUnknown_3001B5C == NULL) {
    gUnknown_3001B5C = MemoryAlloc(sizeof(struct unkStruct_3001B5C), 8);
  }
  gUnknown_3001B5C->unk0 = param_1_u8;
  gUnknown_3001B5C->unk4 = gUnknown_203B298;

  gUnknown_3001B5C->unk390 = index;
  gUnknown_3001B5C->unk394 = &gUnknown_3001B5C->unk398[index];
  sub_8006518(gUnknown_3001B5C->unk398);
  gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390] = gUnknown_80DC91C;

  gUnknown_3001B5C->unk394->unk14 = gUnknown_3001B5C->unk3F8;
  if (sub != NULL) {
    gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390].unk08 = *sub;
  }
  sub_8012D08(gUnknown_3001B5C->unk394,param_4);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_3001B5C->unk398,1,1);
  sub_8013818(&gUnknown_3001B5C->unk35C,sub_80236A4(),param_4,index);
  gUnknown_3001B5C->unk374 = gUnknown_203B29C;
  gUnknown_3001B5C->unk37A = gUnknown_203B29E;
  sub_8013984(&gUnknown_3001B5C->unk35C);
  sub_8023420();
  sub_80234BC();
  return 1;
}


u8 sub_8023278(u8 param_1)
{
  s32 iVar3;
  u32 temp;
  
  if (param_1 == 0) {
    sub_8013660(&gUnknown_3001B5C->unk35C);
    return 0;
  }
  switch(GetKeyPress(&gUnknown_3001B5C->unk35C))
  {
    case INPUT_B_BUTTON:
        PlayMenuSoundEffect(1);
        return 2;
    case INPUT_A_BUTTON:
      PlayMenuSoundEffect(0);
      return 3;
    case INPUT_SELECT_BUTTON:
        PlayMenuSoundEffect(5);
        if (temp = gUnknown_3001B5C->unk4, iVar3 = 1, temp < 2) {
            iVar3 = temp + 1;
        }
        gUnknown_3001B5C->unk4 = iVar3;
        sub_80236A4();
        break;
    default:
        if (sub_80138B8(&gUnknown_3001B5C->unk35C, 1) == 0) {
            return 0;
        }
        break;
  }
  sub_8023420();
  sub_80234BC();
  return 1;
}

s16 sub_802331C(void)
{
  return gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk37A * gUnknown_3001B5C->unk378 + gUnknown_3001B5C->unk374];
}

void sub_8023354(u8 param_1)
{
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_3001B5C->unk398,0,0);
  sub_8013984(&gUnknown_3001B5C->unk35C);
  sub_8023420();
  sub_80234BC();
  if (param_1 != 0) {
    AddMenuCursorSprite(&gUnknown_3001B5C->unk35C);
  }
}


void sub_80233A0(void)
{
  if (gUnknown_3001B5C != NULL) {
    gUnknown_203B298 = gUnknown_3001B5C->unk4;
    gUnknown_203B29C = gUnknown_3001B5C->unk374;
    gUnknown_203B29E = gUnknown_3001B5C->unk37A;
    gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390] = gUnknown_80DC904;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_3001B5C->unk398,1,1);
    MemoryFree(gUnknown_3001B5C);
    gUnknown_3001B5C = NULL;
  }
}
