#include "global.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "subStruct_203B240.h"

struct unkStruct_203B240
{
    // size: 0x94
    s32 state;
    u8 unk4;
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

extern struct unkStruct_203B240 *gUnknown_203B240;
extern char gUnknown_80DBE2C[]; // {ARG_MOVE_ITEM_0}
extern char gUnknown_80DBE30[]; // {ARG_POKEMON_0}
extern u8 gUnknown_202DE58[0x58];
extern u8 gAvailablePokemonNames[0x58];


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

void sub_801C6D0(s32);
void sub_801C7D4();
void sub_801C6E4();
void sub_801C848();

u32 sub_801C620(u8 param_1)
{
  ResetSprites(1);
  gUnknown_203B240 = MemoryAlloc(sizeof(struct unkStruct_203B240),8);
  gUnknown_203B240->unk4 = param_1;
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
        skillName = GetIQSkillName(gUnknown_203B240->unk4);
        strcpy(gUnknown_202DE58,skillName);
        xxx_format_and_draw(16,0,gUnknown_80DBE2C,0,0); // {ARG_MOVE_ITEM_0}
        xxx_call_draw_string(8,16,GetIQSkillDescription(gUnknown_203B240->unk4),gUnknown_203B240->unk24,0);
        sub_80073E0(gUnknown_203B240->unk24);
        gUnknown_203B240->unkC = sub_8097DF0(GetIQSkillDescription(gUnknown_203B240->unk4),gUnknown_203B240->unk10);
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
