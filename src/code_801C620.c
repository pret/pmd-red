#include "constants/item.h"
#include "global.h"
#include "constants/iq_skill.h"
#include "input.h"
#include "item.h"
#include "memory.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "team_inventory.h"
#include "text.h"
#include "subStruct_203B240.h"
#include "menu_input.h"

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
    /* 0x24 */ struct MenuInputStruct input;
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
    struct MenuInputStructSub unk88;
};

struct unkStruct_203B244
{
    // size: 0x554
    u32 unk0;
    u8 itemIDs[NUMBER_OF_ITEM_IDS];
    u32 unkF4[NUMBER_OF_ITEM_IDS];
    struct MenuInputStruct input;
    u32 unk4E8;
    struct UnkTextStruct2 * unk4EC;
    struct UnkTextStruct2 unk4F0[4];
    u8 unk550[4];
};

struct unk_203B250
{
    struct PokemonStruct *pokeStruct;
    s16 index;
    /* 0x6 */ u8 currFriendAreaLocation; // 0 when not in a friend area
    u8 unk7;
    u8 unk8;
    u8 unk9;
    struct PokemonStruct *unkC;
    u32 state;
    u32 menuAction;
    struct MenuStruct unk18;
    struct MenuItem unk68[8];
    u16 unkA8[8];
    struct UnkTextStruct2 unkB8[4];
};

extern struct unk_203B250 *gUnknown_203B250;
extern u32 gUnknown_203B254;

extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern u8 sub_8002658(s16);
extern s16 sub_80A5728(void);
extern void sub_801D208(u32);
extern void sub_801D680(void);
extern void sub_801D760(void);
extern void sub_801D77C(void);
extern void sub_801D798(void);
extern void sub_801D7CC(void);
extern void sub_801D808(void);
extern void sub_801D824(void);
extern void sub_801D840(void);
extern void sub_801D85C(void);
extern void sub_801D878(void);
s16 sub_80A7AE8(s32);
extern struct PokemonStruct *sub_808D3F8(void);

extern const struct UnkTextStruct2 gUnknown_80DBE54;
extern struct UnkTextStruct2 gUnknown_80DBDD8;
extern struct UnkTextStruct2 gUnknown_80DBDF0;
extern struct UnkTextStruct2 gUnknown_80DBDB0;
extern struct UnkTextStruct2 gUnknown_80DBD98;
extern struct UnkTextStruct2 gUnknown_80DBE3C;

extern struct unkStruct_203B238 *gUnknown_203B238;
extern struct unkStruct_203B23C *gUnknown_203B23C;
extern struct unkStruct_203B240 *gUnknown_203B240;
extern struct unkStruct_203B244 *gUnknown_203B244;

extern u32 gUnknown_203B248;
extern u16 gUnknown_203B24C;
extern u16 gUnknown_203B24E;
extern u8 gUnknown_202DE58[0x58];
extern u8 gAvailablePokemonNames[0x58];

extern u8 gUnknown_80DBE6C[];
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

extern void sub_8007B7C(s32, s32, s32, s32, s32);
extern bool8 sub_801CF14(s32);
extern u32 sub_801CE58(void);
extern void sub_801CC38(void);
extern void sub_801CCD8(void);
extern void sub_801CF94(void);
extern void ResetSprites(u32);
extern void sub_80140B4(struct UnkTextStruct2 *);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);
extern void sub_8013F84();
extern void PlayMenuSoundEffect(u32);
extern char * GetIQSkillDescription(u8 r0);
extern s32 GetNumAvailableIQSkills(u8 *param_1, s32 pokeIQ);
extern void sub_8013C68(u32 *);
extern char * GetIQSkillName(u8 r0);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern u32 sub_80095E4(s16, u32);
extern void sub_801C440(void);
extern void sub_801C4C8(void);
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

extern u8 sub_801CB24();
extern u32 sub_801CFE0(u8);
extern s32 sub_801CFB8(void);
extern void sub_801D220();
extern void sub_801D3A8();


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
    sub_8013818(&gUnknown_203B23C->input,gUnknown_203B23C->numIQSkills,param_3,index);
    sub_801C440();
    sub_801C4C8();
    return TRUE;
  }
}

u32 sub_801C308(u8 r0)
{
    if(r0 == 0)
    {
        sub_8013660(&gUnknown_203B23C->input);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B23C->input))
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
            if(sub_80138B8(&gUnknown_203B23C->input, 1) != 0)
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
    return (gUnknown_203B23C->input.unk1E * gUnknown_203B23C->input.unk1C) + gUnknown_203B23C->input.menuIndex;
}

void sub_801C3B0(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B23C->unk60, 0, 0);
    gUnknown_203B23C->input.unk22 = gUnknown_203B23C->numIQSkills;
    sub_8013984(&gUnknown_203B23C->input);
    sub_801C440();
    sub_801C4C8();
    if(r0)
       AddMenuCursorSprite(&gUnknown_203B23C->input); 
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
  
  gUnknown_203B23C->unkC0 = gUnknown_203B23C->unk24.unk20;
  gUnknown_203B23C->unkC1 = gUnknown_203B23C->unk24.unk1E;
  gUnknown_203B23C->unkC2 = 0xA;
  gUnknown_203B23C->unkC3 = 0;
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B23C->unk60, 1, 1);
  sVar2 = sub_80095E4(gUnknown_203B23C->unk24.unk1A, 0xc) + 2;
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
    x = gUnknown_203B23C->input.unk1E * 8;
    x2 = x;
    x2 += 10;
    xxx_call_draw_string(x2,0,gUnknown_80DBE08,gUnknown_203B23C->unk58,0);
    x += 4;
    x2 = x + gUnknown_203B23C->unkC2 * 8;
    sub_8012BC4(x2,0,gUnknown_203B23C->input.unk1E + 1,1,7,
                gUnknown_203B23C->unk58);
    for (counter = 0; counter < gUnknown_203B23C->input.unk1A; counter++) {
        skillIndex = gUnknown_203B23C->iqSkills
            [gUnknown_203B23C->input.unk1E * gUnknown_203B23C->input.unk1C + counter];
        y = sub_8013800(&gUnknown_203B23C->input,counter);
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
        strcpy(gAvailablePokemonNames,preload->pokeName);
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

    if (param_3 != NULL)
        gUnknown_203B244->unk4F0[gUnknown_203B244->unk4E8].unk8 = *param_3;

    sub_8012D08(gUnknown_203B244->unk4EC, param_4);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B244->unk4F0,1,1);
    sub_8013818(&gUnknown_203B244->input, sub_801CE58(), param_4, param_2);
    if (gUnknown_203B248 == gUnknown_203B244->unk0) {
      gUnknown_203B244->input.menuIndex = gUnknown_203B24C;
      gUnknown_203B244->input.unk1E = gUnknown_203B24E;
      sub_8013984(&gUnknown_203B244->input);
    }
    sub_801CC38();
    sub_801CCD8();
    return TRUE;
  }
}

bool8 sub_801CA08(u8 param_1)
{
  u32 index;
  u32 temp;
  u32 flag;
  
  if (param_1 == 0) {
    sub_8013660(&gUnknown_203B244->input);
    return 0;
  }
  switch(GetKeyPress(&(gUnknown_203B244->input))) 
  {
    case 2:
        PlayMenuSoundEffect(1);
        return 2;
    case 1:
        PlayMenuSoundEffect(0);
        return 3;
    case 5:
    case 6:
        if (gUnknown_203B244->unk0 != 1) goto _0801CAF2;
        index = sub_801CB24();
        if ((temp = sub_801CFE0(index), flag = FALSE, temp != 0) || (flag = (INVENTORY_SIZE > GetNumberOfFilledInventorySlots() + sub_801CFB8())) || flag != 0  ) {
            PlayMenuSoundEffect(6);
            gUnknown_203B244->unkF4[index] = gUnknown_203B244->unkF4[index] ^ 1;
            sub_80138B8(&gUnknown_203B244->input,0);
            sub_801CCD8();
            return 1;
        }
        else
        {
            PlayMenuSoundEffect(2);
            goto _0801CAF2;
        }
    case 4:
        PlayMenuSoundEffect(4);
        return 4;
    default:
_0801CAF2:
        if (sub_80138B8(&gUnknown_203B244->input,1) != 0) {
            sub_801CC38();
            sub_801CCD8();
            return 1;
        }
        else
        {
            return 0;
        }
  }
}

u8 sub_801CB24(void) {
   return gUnknown_203B244->itemIDs[(gUnknown_203B244->input.unk1E * gUnknown_203B244->input.unk1C) + gUnknown_203B244->input.menuIndex];
}

void sub_801CB5C(u8 r0) {
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B244->unk4F0, 0, 0);
    gUnknown_203B244->input.unk22 = sub_801CE58();
    sub_8013984(&gUnknown_203B244->input);
    sub_801CC38();
    sub_801CCD8();
    if(r0)
    {
        AddMenuCursorSprite(&gUnknown_203B244->input);
    }
}

void sub_801CBB8(void) {
    if(gUnknown_203B244 != NULL)
    {
        gUnknown_203B248 = gUnknown_203B244->unk0;
        gUnknown_203B24C = gUnknown_203B244->input.menuIndex;
        gUnknown_203B24E = gUnknown_203B244->input.unk1E;
        gUnknown_203B244->unk4F0[gUnknown_203B244->unk4E8] = gUnknown_80DBE3C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B244->unk4F0, 1, 1);
        MemoryFree(gUnknown_203B244);
        gUnknown_203B244 = NULL;
    }
}

NAKED
void sub_801CC38(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tldr r4, _0801CCC4\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0xAA\n"
	"\tlsls r1, 3\n"
	"\tadds r0, r1\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, _0801CCC8\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r1, 0x1\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0xC\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r1, _0801CCCC\n"
	"\tadds r0, r1\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tldr r2, _0801CCD0\n"
	"\tadds r0, r2\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r3, [r4]\n"
	"\tmovs r2, 0x9D\n"
	"\tlsls r2, 3\n"
	"\tadds r5, r3, r2\n"
	"\tldr r2, [r5]\n"
	"\tlsls r1, r2, 1\n"
	"\tadds r1, r2\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r3, r1\n"
	"\tldr r2, _0801CCD4\n"
	"\tadds r1, r2\n"
	"\tasrs r2, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r5]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r3, r0\n"
	"\tadds r2, 0x2\n"
	"\tmovs r0, 0xA0\n"
	"\tlsls r0, 3\n"
	"\tadds r3, r0\n"
	"\tstrh r2, [r3]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x9E\n"
	"\tlsls r1, 3\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801CCC4: .4byte gUnknown_203B244\n"
"_0801CCC8: .4byte 0x00000551\n"
"_0801CCCC: .4byte 0x00000553\n"
"_0801CCD0: .4byte 0x000004ce\n"
"_0801CCD4: .4byte 0x000004fe");
}

void sub_801CCD8(void)
{
  u32 y;
  u32 y2;
  u32 uVar3;
  int index;
  u8 buffer [80];
  
  sub_8008C54(gUnknown_203B244->unk4E8);
  sub_80073B8(gUnknown_203B244->unk4E8);
  xxx_call_draw_string(10,0,gUnknown_80DBE6C,gUnknown_203B244->unk4E8,0);
  sub_8012BC4(gUnknown_203B244->unk550[2] * 8 + 4,0,
              gUnknown_203B244->input.unk1E + 1,2,7,gUnknown_203B244->unk4E8);
  for(index = 0; index < gUnknown_203B244->input.unk1A; index++) {
      uVar3 = gUnknown_203B244->itemIDs[(gUnknown_203B244->input.unk1E * gUnknown_203B244->input.unk1C) + index];
      sub_8090DC4(buffer,uVar3,0);
      y = sub_8013800(&gUnknown_203B244->input,index);
      xxx_call_draw_string(8,y,buffer,gUnknown_203B244->unk4E8,0);
      y2 = sub_8013800(&gUnknown_203B244->input,index);
      sub_8012BC4((gUnknown_203B244->unk4EC->unkC << 3) - 2,y2,
                  gTeamInventory_203B460->teamStorage[uVar3],3,5,gUnknown_203B244->unk4E8);
      if ((sub_801CFE0(uVar3) & 1) != 0) {
        sub_8007B7C(gUnknown_203B244->unk4E8,0x8,sub_8013800(&gUnknown_203B244->input,index), (gUnknown_203B244->unk4EC->unkC + -1) * '\b',10);
      }
   }
  sub_80073E0(gUnknown_203B244->unk4E8);
}

u32 sub_801CE58(void)
{
  u8 uVar1;
  int orderL;
  int orderR;
  int itemCount;
  int itemR;
  s32 itemIndex; // re-used variable to match
  
  itemCount = 0;
  for(itemIndex = 1; itemIndex < NUMBER_OF_ITEM_IDS; itemIndex++)
  {
    if ((gUnknown_203B244->unk0 == 2) ||
       ((gTeamInventory_203B460->teamStorage[itemIndex] != 0) && (IsNotMoneyOrUsedTMItem(itemIndex)))) {
      gUnknown_203B244->itemIDs[itemCount] = itemIndex;
      itemCount++;
    }
  }
    
  for(itemIndex = 0; itemIndex < itemCount - 1; itemIndex++) {
    for(itemR = itemIndex + 1; itemR < itemCount; itemR++) {
        orderL = GetItemOrder(gUnknown_203B244->itemIDs[itemIndex]);
        orderR = GetItemOrder(gUnknown_203B244->itemIDs[itemR]);
        if (orderL > orderR) {
          uVar1 = gUnknown_203B244->itemIDs[itemIndex];
          gUnknown_203B244->itemIDs[itemIndex] =  gUnknown_203B244->itemIDs[itemR];
          gUnknown_203B244->itemIDs[itemR] = uVar1;
        }
      }
  }
  return itemCount;
}

bool8 sub_801CF14(s32 param_1) {
    s32 itemID;
    if(param_1 == 2){
        return FALSE;
    }
    else {
        for(itemID = ITEM_STICK; itemID < NUMBER_OF_ITEM_IDS; itemID++)
        {
            if ((gTeamInventory_203B460->teamStorage[itemID] != 0) && (IsNotMoneyOrUsedTMItem(itemID))) return FALSE;
        }
        return TRUE;
    }
}

bool8 sub_801CF50(s32 param_1) {
    s32 itemID;
    if(param_1 == 2){
        return FALSE;
    }
    else {
        for(itemID = ITEM_STICK; itemID < NUMBER_OF_ITEM_IDS; itemID++)
        {
            if ((IsNotMoneyOrUsedTMItem(itemID)) && (gTeamInventory_203B460->teamStorage[itemID] < 999)) return FALSE;
        }
        return TRUE;
    }
}

void sub_801CF94(void)
{
    s32 itemID;

    for(itemID = ITEM_NOTHING; itemID < NUMBER_OF_ITEM_IDS; itemID++)
    {
        gUnknown_203B244->unkF4[itemID] = 0;
    }
}

s32 sub_801CFB8(void)
{
    s32 itemID;
    s32 counter;

    counter = 0;
    for(itemID = ITEM_NOTHING; itemID < NUMBER_OF_ITEM_IDS; itemID++)
    {
        if(gUnknown_203B244->unkF4[itemID] != 0)
        {
            counter++;
        }
    }
    return counter;
}

u32 sub_801CFE0(u8 index)
{
    return gUnknown_203B244->unkF4[index];
}

// Unused
void sub_801CFF4(u8 index, u32 value)
{
    gUnknown_203B244->unkF4[index] = value;
}

struct unkStruct_203B244 *sub_801D008(void)
{
    return gUnknown_203B244;
}

bool8 sub_801D014(struct PokemonStruct *param_1)
{
    s32 index;
    struct PokemonStruct *pokemon;
    struct unk_203B250 *preload;

    ResetUnusedInputStruct();
    sub_800641C(0,1,1);
    gUnknown_203B250 = MemoryAlloc(sizeof(struct unk_203B250), 8);
    gUnknown_203B250->menuAction = gUnknown_203B254;
    gUnknown_203B250->pokeStruct = param_1;
    if (gUnknown_203B250->pokeStruct != NULL) {
        for(index = 0; index < NUM_MONSTERS; index++)
        {
            preload = gUnknown_203B250;
            pokemon = &gRecruitedPokemonRef->pokemon[(s16)index]; // cast is needed here
            if(preload->pokeStruct == pokemon)
            {
                preload->index = index;
                break;
            }
        }
    }
    else {
        gUnknown_203B250->index = NUM_MONSTERS;
    }
    gUnknown_203B250->currFriendAreaLocation = sub_8002658(sub_80A5728());
    gUnknown_203B250->unk8 = 0;
    gUnknown_203B250->unk9 = 0;
    gUnknown_203B250->unkC = GetPlayerPokemonStruct();
    gUnknown_203B250->unk7 = 0;
    if (gUnknown_203B250->pokeStruct != NULL) {
        sub_801D208(5);
    }
    else {
        sub_801D208(0);
    }
    return 1;
}

u32 sub_801D0DC(void)
{
    switch(gUnknown_203B250->state)
    {
        case 0:
        case 1:
            sub_801D680();
            break;
        case 3:
            sub_801D760();
            break;
        case 4:
            sub_801D77C();
            break;
        case 5:
            sub_801D798();
            break;
        case 6:
        case 7:
            sub_801D7CC();
            break;
        case 8:
            sub_801D808();
            break;
        case 9:
            sub_801D824();
            break;
        case 10:
            sub_801D840();
            break;
        case 0xb:
            sub_801D85C();
            break;
        case 0xc:
            sub_801D878();
            break;
        default:
            return 3;
    }
    return 0;
}


u32 sub_801D178(void)
{
    struct PokemonStruct *pokeStruct;

    if (gUnknown_203B250->unk9 != 0)
    {
        return 2;
    }
    else if (gUnknown_203B250->unk7 != 0) 
    {
        return 3;
    }
    else if (gUnknown_203B250->unk8 != 0) 
    {
        return 1;
    }
    else if (gUnknown_203B250->unkC != GetPlayerPokemonStruct())
    {
        goto _ret4;
    }
    else if (sub_80A7AE8(7) < 0)
    {
        return 0;
    }
    else if((pokeStruct = sub_808D3F8(), (pokeStruct->unk0 >> 1 & 1) == 0))
    {
_ret4:
        return 4;
    } 
    else 
    {
        return 0;
    }
}

u8 sub_801D1D4(void)
{
    return gUnknown_203B250->unk7;
}

void sub_801D1E0(void)
{
    if(gUnknown_203B250 != NULL)
    {
        gUnknown_203B254 = gUnknown_203B250->menuAction;
        MemoryFree(gUnknown_203B250);
        gUnknown_203B250 = NULL;
    }
}

void sub_801D208(u32 newState)
{
    gUnknown_203B250->state = newState;
    sub_801D220();
    sub_801D3A8();
}
