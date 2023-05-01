#include "global.h"
#include "constants/iq_skill.h"
#include "input.h"
#include "memory.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "team_inventory.h"
#include "text.h"
#include "subStruct_203B240.h"
#include "menu_input.h"

struct unkStruct_203B234
{
    // size: 0x154
    u32 unk0;
    u32 state;
    u32 fallbackState;
    u8 unkC;
    struct Item unk10;
    struct unkStruct_8090F58 unk14;
    struct Item unk20;
    u32 unk24;
    struct MenuStruct unk28;
    struct MenuStruct unk78;
    u32 menuAction;
    struct MenuItem unkCC[5];
    struct UnkTextStruct2 unkF4[4];
};

extern struct unkStruct_203B234 *gUnknown_203B234;


struct unkStruct_203B238
{
    // size: 0x124
    u32 state;
    s16 species;
    struct PokemonStruct *pokeStruct;
    u8 iqSkills[NUM_IQ_SKILLS];
    u32 unk24;
    u8 iqSkillIndex;
    u32 numIQSkills;
    s32 menuAction;
    struct MenuItem unk34[8];
    struct MenuStruct unk74;
    struct UnkTextStruct2 unkC4[4];
};

struct unkStruct_203B23C
{ 
    // size: 0xC4
    /* 0x0 */ s16 species;
    /* 0x4 */ struct PokemonStruct *pokeStruct;
    /* 0x8 */ u8 iqSkills[NUM_IQ_SKILLS];
    /* 0x20 */ s32 numIQSkills;
    /* 0x24 */ u32 unk24;
    u8 fill28[0x3C - 0x28];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u8 fill48[0x52 - 0x48];
    u8 unk52;
    u8 fill52[0x58 - 0x53];
    u32 unk58;
    /* 0x5C */ struct UnkTextStruct2 *unk5C;
    /* 0x60 */ struct UnkTextStruct2 unk60[4];
    u8 unkC0;
    u8 unkC1;
    u8 unkC2;
    u8 unkC3;
};

struct unkStruct_203B240
{
    // size: 0x94
    s32 state;
    u8 chosenIQSkill;
    s32 unk8;
    s32 unkC;
    struct subStruct_203B240 *unk10[2];
    u8 fill14[0x20 - 0x18];
    u32 unk20;
    u32 unk24;
    struct UnkTextStruct2 unk28[4];
    u32 unk88;
    u32 unk8C;
    u32 unk90;
};

struct unkStruct_203B244
{
    // size: 0x554
    u32 unk0;
    u8 fill4[0x4B4 - 0x4];
    u32 unk4B4;
    u8 fill4B8[0x4CC - 0x4B8];
    u16 unk4CC;
    u16 unk4CE;
    u16 unk4D0;
    u16 unk4D2;
    u8 fill4D4[0x4E8 - 0x4D4];
    u32 unk4E8;
    struct UnkTextStruct2 * unk4EC;
    struct UnkTextStruct2 unk4F0[4];
    u8 unk550[4];
};

extern const struct UnkTextStruct2 gUnknown_80DBE54;
extern struct UnkTextStruct2 gUnknown_80DBDD8;
extern struct UnkTextStruct2 gUnknown_80DBDF0;
extern struct UnkTextStruct2 gUnknown_80DBDB0;
extern struct UnkTextStruct2 gUnknown_80DBD98;

extern struct unkStruct_203B238 *gUnknown_203B238;
extern struct unkStruct_203B23C *gUnknown_203B23C;
extern struct unkStruct_203B240 *gUnknown_203B240;
extern struct unkStruct_203B244 *gUnknown_203B244;

extern u32 gUnknown_203B248;
extern u16 gUnknown_203B24C;
extern u16 gUnknown_203B24E;
extern u8 gUnknown_202DE58[0x58];
extern u8 gAvailablePokemonNames[0x58];

extern u8 gUnknown_80DBE18[];
extern u8 gUnknown_80DBE14[];
extern u8 gUnknown_202DEA8[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_80DBE08[];
extern u8 gUnknown_80DBE1C[];
extern char gUnknown_80DBE2C[]; // {ARG_MOVE_ITEM_0}
extern char gUnknown_80DBE30[]; // {ARG_POKEMON_0}
extern u8 gUnknown_80DBDC8[];
extern u8 *gUnknown_80D4970[];


extern bool8 sub_801CF14(u32);
extern void sub_8013818(u32 *, u32, u32, u32);
extern u32 sub_801CE58(void);
extern void sub_8013984(void *);
extern void sub_801CC38(void);
extern void sub_801CCD8(void);
extern void sub_801CF94(void);
extern void ResetSprites(u32);
extern void sub_801317C(u32 *);
extern void sub_80140B4(struct UnkTextStruct2 *);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);
extern u32 sub_8012A64(u32 *, u32);
extern void sub_8013F84();
extern void PlayMenuSoundEffect(u32);
extern char * GetIQSkillDescription(u8 r0);
extern s32 GetNumAvailableIQSkills(u8 *param_1, s32 pokeIQ);
extern void sub_8013C68(u32 *);
extern void xxx_call_draw_string(u32, u32, const u8 *, u32, u32);
extern char * GetIQSkillName(u8 r0);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern s32 sub_8013800(u32 *, s32);
extern u32 sub_80095E4(s16, u32);
extern void sub_801C440(void);
extern void sub_801C4C8(void);
extern void AddMenuCursorSprite(u32 *);
extern u8 sub_80138B8(u32 *, u32);
extern void sub_8013660(u32 *);
extern s32 GetKeyPress(u32 *);
extern bool8 HasNoAvailIQSkills(s16 species);
extern u32 sub_801C674(void);
extern void sub_801C6B4(void);

void sub_801BFB4(s32);
void sub_801C6D0(s32);
void sub_801C7D4();
void sub_801C6E4();
void sub_801C848();

u32 sub_801C308(u8);
extern void PlaySound(u32);
void ToggleIQSkill(u8 *param_1, u32 skillIndex);
s32 sub_801C390(void);
void sub_801C3F8(void);

bool8 sub_801C244(s16 species, u32 index, u32 param_3);
void sub_801C0C8(void);
u32 sub_801C620(u8 iqSkill);
void sub_801C3B0(u8);
void sub_801BFCC(void);
void sub_801C03C(void);

void sub_801C118();
void sub_801C1A0();
void sub_801C228();

void sub_801B748(u32);


extern s32 sub_80144A4(s32 *);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
extern u32 sub_801A6E8(u32);
extern void sub_801A928(void);
extern void sub_8099690(u32);
extern u32 sub_801A8AC();

extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];

void sub_801BC24(void)
{
  struct unkStruct_203B234 *puVar1;
  u8 *nullText;
  u32 menuAction;
  
  puVar1 = gUnknown_203B234;
  nullText = NULL;
  puVar1->unkCC[0].text = *gUnknown_80D4920;
  gUnknown_203B234->unkCC[0].menuAction = 2;
  menuAction = 1;
  gUnknown_203B234->unkCC[1].text = *gUnknown_80D4928;
  gUnknown_203B234->unkCC[1].menuAction = 3;
  gUnknown_203B234->unkCC[2].text = nullText;
  gUnknown_203B234->unkCC[2].menuAction = menuAction;
}

void sub_801BC64(void)
{
    s32 temp;
    if(sub_80144A4(&temp)== 0)
    {
        switch(temp)
        {
            case 4:
                sub_801B748(0x8);
                break;
            case 5:
                sub_801B748(0x7);
                break;
        }
    }
}

void sub_801BC94(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 2:
                sub_801B748(0xD);
                break;
            case 1:
            case 3:
                sub_801B748(0x6);
                break;
        }
    }
}

void sub_801BCCC(void)
{
    switch(sub_801A6E8(1))
    {
        case 0:
        case 1:
            break;
        case 3:
            gUnknown_203B234->unk24 = sub_801A8AC();
            gUnknown_203B234->unk20 = gTeamInventory_203B460->teamItems[gUnknown_203B234->unk24];
            sub_8090E14(gUnknown_202DEA8, &gUnknown_203B234->unk20, &gUnknown_203B234->unk14);
            sub_801B748(0xA);
            break;
        case 4:
            gUnknown_203B234->unk24 = sub_801A8AC();
            gUnknown_203B234->unk20 = gTeamInventory_203B460->teamItems[gUnknown_203B234->unk24];
            sub_8090E14(gUnknown_202DEA8, &gUnknown_203B234->unk20, &gUnknown_203B234->unk14);
            sub_8099690(0);
            sub_801B748(0xB);
            break;
        case 2:
            sub_801A928();
            sub_801B748(6);
            break;
    }
}

void sub_801BD80(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801A6E8(0);
  if (sub_8012FD8(&gUnknown_203B234->unk28) == '\0') {
    sub_8013114(&gUnknown_203B234->unk28,&menuAction);
    if (menuAction != 1) gUnknown_203B234->menuAction = menuAction;
  }
  switch(menuAction)
  {
    case 6:
        MoveToStorage(&gUnknown_203B234->unk20);
        ShiftItemsDownFrom(gUnknown_203B234->unk24);
        AddItemToInventory(&gUnknown_203B234->unk10);
        FillInventoryGaps();
        PlaySound(0xcb);
        sub_8099690(0);
        sub_801A928();
        sub_801B748(0xE);
        break;
    case 7:
        sub_801B748(0xC);
        break;
    case 8:
        sub_8099690(0);
        sub_801B748(0xB);
        break;
    case 1:
        sub_801B748(0x9);
        break;
  }
}

void sub_801BE30(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801A6E8(0);
  sub_8012FD8(&gUnknown_203B234->unk28);
  if (sub_8012FD8(&gUnknown_203B234->unk78) == '\0') {
    sub_8013114(&gUnknown_203B234->unk78,&menuAction);
  }
  switch(menuAction)
  {
    case 1:
    case 3:
        sub_801B748(9);
        break;
    case 2:
        ShiftItemsDownFrom(gUnknown_203B234->unk24);
        AddItemToInventory(&gUnknown_203B234->unk10);
        FillInventoryGaps();
        PlaySound(0xcb);
        sub_801A928();
        sub_801B748(0xf);
        break;
  }
}

void sub_801BEAC(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_801B748(9);
        case 0:
        case 1:
            break;
    }
}

void sub_801BEC8(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_801B748(gUnknown_203B234->fallbackState);
    }
}

bool8 sub_801BEEC(s16 species)
{
  s32 species_s32 = species;
  if (HasNoAvailIQSkills(species_s32)) {
    return FALSE;
  }
  else {
    gUnknown_203B238 = MemoryAlloc(sizeof(struct unkStruct_203B238),8);
    gUnknown_203B238->menuAction = 0;
    gUnknown_203B238->species = species_s32;
    gUnknown_203B238->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    gUnknown_203B238->numIQSkills = GetNumAvailableIQSkills(gUnknown_203B238->iqSkills,gUnknown_203B238->pokeStruct->IQ);
    sub_801BFB4(0);
    return TRUE;
  }
}

u32 sub_801BF48(void)
{
    switch(gUnknown_203B238->state)
    {
        case 4:
            return 3;
        case 0:
        case 1:
            sub_801C118();
            break;
        case 2:
            sub_801C1A0();
            break;
        case 3:
            sub_801C228();
            break;
    }
    return 0;
}

void sub_801BF98(void)
{
    if(gUnknown_203B238 != NULL)
    {
        MemoryFree(gUnknown_203B238);
        gUnknown_203B238 = NULL;
    }
}

void sub_801BFB4(s32 newState)
{
    gUnknown_203B238->state = newState;
    sub_801BFCC();
    sub_801C03C();
}

void sub_801BFCC(void) 
{
    s32 index;

    sub_8006518(gUnknown_203B238->unkC4);
    if(gUnknown_203B238->state == 2)
    {
        gUnknown_203B238->unkC4[2] = gUnknown_80DBDB0;
    }
    else
    {
        for(index = 0; index < 4; index++)
        {
            gUnknown_203B238->unkC4[index] = gUnknown_80DBD98;
        }

    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B238->unkC4, 1, 1);
}

void sub_801C03C(void)
{
  switch(gUnknown_203B238->state) {
      case 0:
        sub_801C244(gUnknown_203B238->species,0,8);
        break;
      case 1:
        sub_801C3B0(1);
        break;
      case 2:
        sub_801C4C8();
        sub_801C0C8();
        sub_8012D60(&gUnknown_203B238->unk74,gUnknown_203B238->unk34,0,0,gUnknown_203B238->menuAction,2);
        break;
      case 3:
        sub_801C620(gUnknown_203B238->iqSkillIndex);
        break;
      case 4:
        break;
  }
}

void sub_801C0C8(void)
{
  struct unkStruct_203B238 *puVar1;
  int index;
  u8 *nullText;
  u32 menuAction;
  s32 max;
  
  puVar1 = gUnknown_203B238;
  nullText = NULL;
  gUnknown_203B238->unk34[0].text = gUnknown_80DBDC8;
  puVar1->unk34[0].menuAction = 2;
  menuAction = 1;
  puVar1->unk34[1].text = *gUnknown_80D4970;
  puVar1->unk34[1].menuAction = 3;
    
  max = 2;
  puVar1->unk34[2].text = nullText;
  puVar1->unk34[2].menuAction = menuAction;
    
  for(index = 0; index < max; index++) 
  {
    if(gUnknown_203B238->unk34[index].menuAction == gUnknown_203B238->menuAction)
        return;
  }
  gUnknown_203B238->menuAction = 2;
}

void sub_801C118(void)
{
  switch(sub_801C308(1)) {
      case 3:
        gUnknown_203B238->unk24 = sub_801C390();
        gUnknown_203B238->iqSkillIndex = gUnknown_203B238->iqSkills[gUnknown_203B238->unk24];
        sub_801BFB4(2);
        break;
      case 4:
        gUnknown_203B238->unk24 = sub_801C390();
        gUnknown_203B238->iqSkillIndex = gUnknown_203B238->iqSkills[gUnknown_203B238->unk24];
        sub_801BFB4(3);
        break;
      case 2:
        sub_801C3F8();
        sub_801BFB4(4);
        break;
      case 0:
      case 1:
          break;
  }
}

void sub_801C1A0(void)
{
  s32 menuAction;
  
  menuAction = 0;
  sub_801C308(0);
  if (!(sub_8012FD8(&gUnknown_203B238->unk74)) && (sub_8013114(&gUnknown_203B238->unk74,&menuAction), menuAction != 1)) {
    gUnknown_203B238->menuAction = menuAction;
  }

  switch(menuAction)
  {
      case 2:
          PlaySound(0x133);
          ToggleIQSkill((u8 *)&gUnknown_203B238->pokeStruct->IQSkills,gUnknown_203B238->iqSkillIndex);
          sub_801BFB4(1);  
          break;
      case 3:
          sub_801BFB4(3);
          break;
      case 1:
          sub_801BFB4(1);
          break;
  }
}

void sub_801C228(void)
{
    switch(sub_801C674())
    {
        case 2:
        case 3:
            sub_801C6B4();
            sub_801BFB4(1);
        case 0:
        case 1:
            break;
    }
}

bool8 sub_801C244(s16 species, u32 index, u32 param_3)
{
#ifndef NONMATCHING
  register s32 species_s32 asm("r4");
#else
  s32 species_s32;
#endif

  species_s32 = species;
  
  if (HasNoAvailIQSkills(species)) {
      return FALSE;
  }
  else
  {
    if (gUnknown_203B23C == NULL) {
      gUnknown_203B23C = MemoryAlloc(sizeof(struct unkStruct_203B23C),8);
    }
    gUnknown_203B23C->species = species_s32;
    gUnknown_203B23C->pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    gUnknown_203B23C->numIQSkills = GetNumAvailableIQSkills(gUnknown_203B23C->iqSkills,gUnknown_203B23C->pokeStruct->IQ);
    gUnknown_203B23C->unk58 = index;
    gUnknown_203B23C->unk5C = &gUnknown_203B23C->unk60[index];
    sub_8006518(gUnknown_203B23C->unk60);
    gUnknown_203B23C->unk60[gUnknown_203B23C->unk58] = gUnknown_80DBDF0;
    gUnknown_203B23C->unk5C->unk14 = &gUnknown_203B23C->unkC0;
    sub_8012D08(gUnknown_203B23C->unk5C,param_3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B23C->unk60,1,1);
    sub_8013818(&gUnknown_203B23C->unk24,gUnknown_203B23C->numIQSkills,param_3,index);
    sub_801C440();
    sub_801C4C8();
    return TRUE;
  }
}

u32 sub_801C308(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B23C->unk24);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B23C->unk24))
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
            if(sub_80138B8(&gUnknown_203B23C->unk24, 1) != 0)
            {
                sub_801C440();
                sub_801C4C8();
                return 1;
            }
            else
                return 0;
    }
}

s32 sub_801C390(void)
{
    return (gUnknown_203B23C->unk42 * gUnknown_203B23C->unk40) + gUnknown_203B23C->unk3C;
}

void sub_801C3B0(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B23C->unk60, 0, 0);
    gUnknown_203B23C->unk46 = gUnknown_203B23C->numIQSkills;
    sub_8013984(&gUnknown_203B23C->unk24);
    sub_801C440();
    sub_801C4C8();
    if(r0)
       AddMenuCursorSprite(&gUnknown_203B23C->unk24); 
}

void sub_801C3F8(void)
{
    if(gUnknown_203B23C != NULL)
    {
        gUnknown_203B23C->unk60[gUnknown_203B23C->unk58] = gUnknown_80DBDD8;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B23C->unk60, 1, 1);
        MemoryFree(gUnknown_203B23C);
        gUnknown_203B23C = NULL;
    }
}

#ifdef NONMATCHING
// https://decomp.me/scratch/NdDP3  (98.06% matching) - Seth
void sub_801C440(void)
{
  u16 sVar2;
  
  gUnknown_203B23C->unkC0 = gUnknown_203B23C->unk44;
  gUnknown_203B23C->unkC1 = gUnknown_203B23C->unk42;
  gUnknown_203B23C->unkC2 = 0xA;
  gUnknown_203B23C->unkC3 = 0;
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B23C->unk60, 1, 1);
  sVar2 = sub_80095E4(gUnknown_203B23C->unk3E, 0xc) + 2;
  gUnknown_203B23C->unk60[gUnknown_203B23C->unk58].unkE = sVar2;
  gUnknown_203B23C->unk60[gUnknown_203B23C->unk58].unk10 = sVar2;
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B23C->unk60, 1, 1);
}
#else
NAKED
void sub_801C440(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _0801C4C4\n"
	"\tldr r0, [r4]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x44\n"
	"\tldrh r1, [r1]\n"
	"\tadds r0, 0xC0\n"
	"\tmovs r2, 0\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x42\n"
	"\tldrh r1, [r1]\n"
	"\tadds r0, 0xC1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xC2\n"
	"\tmovs r1, 0xA\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xC3\n"
	"\tstrb r2, [r0]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x60\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x3E\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x58]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x6E\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r3, [r2, 0x58]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r2, r1\n"
	"\tadds r2, 0x70\n"
	"\tstrh r0, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x60\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801C4C4: .4byte gUnknown_203B23C"
    );
}
#endif


void sub_801C4C8(void)
{
    u32 y;
    s32 x;
    s32 x2;
    u32 skillIndex;
    s32 counter;

    sub_8008C54(gUnknown_203B23C->unk58);
    sub_80073B8(gUnknown_203B23C->unk58);
    x = gUnknown_203B23C->unk42 * 8;
    x2 = x;
    x2 += 10;
    xxx_call_draw_string(x2,0,gUnknown_80DBE08,gUnknown_203B23C->unk58,0);
    x += 4;
    x2 = x + gUnknown_203B23C->unkC2 * 8;
    sub_8012BC4(x2,0,gUnknown_203B23C->unk42 + 1,1,7,
                gUnknown_203B23C->unk58);
    for (counter = 0; counter < gUnknown_203B23C->unk3E; counter++) {
        skillIndex = gUnknown_203B23C->iqSkills
            [gUnknown_203B23C->unk42 * gUnknown_203B23C->unk40 + counter];
        y = sub_8013800(&gUnknown_203B23C->unk24,counter);
        strncpy(gUnknown_202DEA8,GetIQSkillName(skillIndex),0x50);
        if (IsIQSkillSet((u8 *)&gUnknown_203B23C->pokeStruct->IQSkills,1 << skillIndex)) {
            strcpy(gUnknown_202DEA8 - 0x50,gUnknown_80DBE14);
        }
        else {
            strcpy(gUnknown_202DEA8 - 0x50,gUnknown_80DBE18);
        }
        xxx_format_and_draw(0xc,y,gUnknown_80DBE1C,gUnknown_203B23C->unk58,0);
    }
    sub_80073E0(gUnknown_203B23C->unk58);
}

bool8 HasNoAvailIQSkills(s16 species)
{
    s32 species_s32;
    u8 iqSkillBuffer[NUM_IQ_SKILLS];
    struct PokemonStruct *pokeStruct;

    species_s32 = species;

    pokeStruct = &gRecruitedPokemonRef->pokemon[species_s32];
    if(GetNumAvailableIQSkills(iqSkillBuffer, pokeStruct->IQ) == 0)
        return TRUE;
    else
        return FALSE;
}

u32 sub_801C620(u8 iqSkill)
{
  ResetSprites(1);
  gUnknown_203B240 = MemoryAlloc(sizeof(struct unkStruct_203B240),8);
  gUnknown_203B240->chosenIQSkill = iqSkill;
  sub_801317C(&gUnknown_203B240->unk88);
  gUnknown_203B240->unk24 = 0;
  sub_80140B4(gUnknown_203B240->unk28);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B240->unk28,1,1);
  sub_801C6D0(0);
  return 1;
}

u32 sub_801C674(void)
{
    switch(gUnknown_203B240->state)
    {
        case 0:
            sub_801C7D4();
            break;
        case 1:
            sub_801C848();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;
    }
    return 0;
}

void sub_801C6B4(void)
{
    if(gUnknown_203B240 != NULL)
    {
        MemoryFree(gUnknown_203B240);
        gUnknown_203B240 = NULL;
    }
}

void sub_801C6D0(s32 newState)
{
    gUnknown_203B240->state = newState;
    sub_801C6E4();
}

void sub_801C6E4(void)
{
  char *skillName;
  struct subStruct_203B240 *preload;

  switch(gUnknown_203B240->state)
  {
    case 0:
        sub_8008C54(gUnknown_203B240->unk24);
        sub_80073B8(gUnknown_203B240->unk24);
        skillName = GetIQSkillName(gUnknown_203B240->chosenIQSkill);
        strcpy(gUnknown_202DE58,skillName);
        xxx_format_and_draw(16,0,gUnknown_80DBE2C,0,0); // {ARG_MOVE_ITEM_0}
        xxx_call_draw_string(8,16,GetIQSkillDescription(gUnknown_203B240->chosenIQSkill),gUnknown_203B240->unk24,0);
        sub_80073E0(gUnknown_203B240->unk24);
        gUnknown_203B240->unkC = sub_8097DF0(GetIQSkillDescription(gUnknown_203B240->chosenIQSkill),gUnknown_203B240->unk10);
        gUnknown_203B240->unk20 = 0;
        break;
    case 1:
        sub_8008C54(gUnknown_203B240->unk24);
        sub_80073B8(gUnknown_203B240->unk24);
        preload = gUnknown_203B240->unk10[gUnknown_203B240->unk8];
        strcpy(gAvailablePokemonNames,preload->unk0);
        xxx_format_and_draw(16,0,gUnknown_80DBE30,gUnknown_203B240->unk24,0); // {ARG_POKEMON_0}
        xxx_format_and_draw(4,16,gUnknown_203B240->unk10[gUnknown_203B240->unk8]->unk4, gUnknown_203B240->unk24,0);
        sub_80073E0(gUnknown_203B240->unk24);
        break;
    case 2:
    case 3:
        break;
  }
}

void sub_801C7D4(void)
{
  if (gUnknown_203B240->unkC != 0) {
    if ((gUnknown_203B240->unk20 & 8)) {
      sub_8013F84();
    }
    gUnknown_203B240->unk20++;
  }
  switch(sub_8012A64(&gUnknown_203B240->unk88,gUnknown_203B240->unk24))
  {
    case 1:
        PlayMenuSoundEffect(0);
        if (gUnknown_203B240->unkC != 0) {
            gUnknown_203B240->unk8 = 0;
            sub_801C6D0(1);
        }
        else {
            sub_801C6D0(3);
        }
        break;
    case 2:
        PlayMenuSoundEffect(1);
        sub_801C6D0(2);
        break;
  }
}

void sub_801C848(void)
{

  if (gUnknown_203B240->unk8 < (gUnknown_203B240->unkC - 1)) {
    if ((gUnknown_203B240->unk20 & 8)) {
      sub_8013F84();
    }
    gUnknown_203B240->unk20++;
  }
  switch(sub_8012A64(&gUnknown_203B240->unk88,gUnknown_203B240->unk24))
  {
    case 1:
        PlayMenuSoundEffect(0);
        gUnknown_203B240->unk8++;
        if (gUnknown_203B240->unk8 < gUnknown_203B240->unkC) {
            sub_801C6D0(1);
        }
        else {
            sub_801C6D0(0);
        }
        break;
    case 2:
        PlayMenuSoundEffect(1);
        sub_801C6D0(2);
        break;
  }
}

bool8 sub_801C8C4(s32 param_1, s32 param_2, struct UnkTextStruct2_sub *param_3, u32 param_4)
{
  if (sub_801CF14(param_1)) {
      return FALSE;
  }
  else
  {
    if (gUnknown_203B244 == NULL) {
      gUnknown_203B244 = MemoryAlloc(sizeof(struct unkStruct_203B244), 8);
    }
    gUnknown_203B244->unk0 = param_1;
    sub_801CF94();
    gUnknown_203B244->unk4E8 = param_2;
    gUnknown_203B244->unk4EC = &gUnknown_203B244->unk4F0[param_2];
    sub_8006518(gUnknown_203B244->unk4F0);
    gUnknown_203B244->unk4F0[gUnknown_203B244->unk4E8] = gUnknown_80DBE54;
    gUnknown_203B244->unk4EC->unk14 = gUnknown_203B244->unk550;
    if (param_3 != NULL) {
        gUnknown_203B244->unk4F0[gUnknown_203B244->unk4E8].unk08 = *param_3;
    }
    sub_8012D08(gUnknown_203B244->unk4EC, param_4);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B244->unk4F0,1,1);
    sub_8013818(&gUnknown_203B244->unk4B4, sub_801CE58(), param_4, param_2);
    if (gUnknown_203B248 == gUnknown_203B244->unk0) {
      gUnknown_203B244->unk4CC = gUnknown_203B24C;
      gUnknown_203B244->unk4D2 = gUnknown_203B24E;
      sub_8013984(&gUnknown_203B244->unk4B4);
    }
    sub_801CC38();
    sub_801CCD8();
    return TRUE;
  }
}
