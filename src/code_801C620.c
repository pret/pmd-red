#include "global.h"
#include "constants/iq_skill.h"
#include "input.h"
#include "memory.h"
#include "pokemon.h"
#include "text.h"
#include "subStruct_203B240.h"

struct unkStruct_203B240
{
    // size: 0x94
    s32 state;
    u8 chosenIQSkill;
    u8 fill5[3];
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

extern struct unkStruct_203B244 *gUnknown_203B244;
extern struct unkStruct_203B240 *gUnknown_203B240;
extern u32 gUnknown_203B248;
extern u16 gUnknown_203B24C;
extern u16 gUnknown_203B24E;

extern char gUnknown_80DBE2C[]; // {ARG_MOVE_ITEM_0}
extern char gUnknown_80DBE30[]; // {ARG_POKEMON_0}
extern u8 gUnknown_202DE58[0x58];
extern u8 gAvailablePokemonNames[0x58];

extern bool8 sub_801CF14(u32);
extern void sub_8012D08(struct UnkTextStruct2 *, u32);
extern void sub_8013818(u32 *, u32, u32, u32);
extern u32 sub_801CE58(void);
extern void sub_8013984(void *);
extern void sub_801CC38(void);
extern void sub_801CCD8(void);
extern void sub_801CF94(void);


extern void ResetSprites(u32);
extern void sub_801317C(u32 *);
extern void sub_80140B4(struct UnkTextStruct2 *);


extern void xxx_format_and_draw(u32, u32, char *, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void xxx_call_draw_string(u32, u32, char *, u32, u32);
extern void sub_80073E0(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);
extern u32 sub_8012A64(u32 *, u32);
extern void sub_8013F84();
extern void PlayMenuSoundEffect(u32);
extern char * GetIQSkillName(u8 r0);
extern char * GetIQSkillDescription(u8 r0);
extern s32 GetNumAvailableIQSkills(u8 *param_1, s32 pokeIQ);

void sub_801C6D0(s32);
void sub_801C7D4();
void sub_801C6E4();
void sub_801C848();

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
