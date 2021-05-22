#include "global.h"
#include "menu.h"
#include "file_system.h"

struct unkStruct_203B200
{
    u8 fill0[0x4];
    u32 unk4;
    u8 *unk8;
    s32 state;
    /* 0x10 */ struct MenuItem menus[3];
};
extern struct unkStruct_203B200 *gUnknown_203B200;
extern const char *gUnknown_80D4920;
extern const char *gUnknown_80D4928;

extern const char gUnknown_80DB6A4;
extern const char gUnknown_80DB6BC;
extern const char gUnknown_80DB688;
extern u8 gAvailablePokemonNames[0x58];

extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, struct OpenedFile **r5, u32);

extern s32 sub_80144A4(s32 *);
extern void sub_80151C0(u32, u8 *);
extern void sub_80161C8(void);
extern void sub_80160F4(u32);
extern u8 sub_80162B8(void);
extern u32 sub_80154F0(void);
extern s32 sub_8015FEC(u8 *, u32);
extern s32 sub_8016028(void);
extern void sub_80155F0(void);
extern void sub_80922B4(u8 *, u8 *, s32);

void nullsub_36(void);
void sub_8016110(void);
extern void sub_80161F8(void);
extern void sub_8016248(void);
extern void sub_8016280(void);
extern void sub_801629C(void);



u32 sub_8016080(void)
{
  switch(gUnknown_203B200->state) {
    case 0:
        sub_80161F8();
        break;
    case 1:
        sub_8016248();
        break;
    case 2:
        sub_8016280();
        break;
    case 3:
        sub_801629C();
        break;
    case 4:
        return 3;
  }
    return 0;
}

extern void MemoryFree(void *);

void sub_80160D8(void)
{
    if(gUnknown_203B200 != NULL)
    {
        MemoryFree(gUnknown_203B200);
        gUnknown_203B200 = NULL;
    }
}


void sub_80160F4(u32 newState)
{
    gUnknown_203B200->state = newState;
    nullsub_36();
    sub_8016110();
}

void nullsub_36(void)
{
}

void sub_8016110(void)
{ 
  switch(gUnknown_203B200->state)
  {
    case 0:
        sub_80151C0(gUnknown_203B200->unk4,gUnknown_203B200->unk8);
        break;
    case 1:
        sub_80161C8();
        if (gUnknown_203B200->unk4 == 1) {
            sub_80922B4(gAvailablePokemonNames,gUnknown_203B200->unk8,10);
        }
        else {
            sub_80922B4(gAvailablePokemonNames,gUnknown_203B200->unk8,10);
        }
        // Is the name #C5$m0#R OK?
        sub_8014248(&gUnknown_80DB688,0,3,gUnknown_203B200->menus,0,4,0,0,0x20);
        break;

    case 2:
        // This name is too long
        sub_80141B4(&gUnknown_80DB6A4,0,0,0x121);
        break;
    case 3:
        // Please enter a name
        sub_80141B4(&gUnknown_80DB6BC,0,0,0x121);
        break;
    default:
        break;
  }
}

void sub_80161C8(void)
{ 
  gUnknown_203B200->menus[0].text = gUnknown_80D4920; // Yes
  gUnknown_203B200->menus[0].menuAction = 2;
  gUnknown_203B200->menus[1].text = gUnknown_80D4928; // No
  gUnknown_203B200->menus[1].menuAction = 3;
  gUnknown_203B200->menus[2].text = NULL;
  gUnknown_203B200->menus[2].menuAction = 1;
}

void sub_80161F8(void)
{
  s32 iVar2;
  s32 iVar3;
  
  if (sub_80154F0() == 3) {
    sub_80155F0();
    if (sub_80162B8() != 0) {
        sub_80160F4(3);
    }
    else{
      iVar2 = sub_8015FEC(gUnknown_203B200->unk8,10);
      iVar3 = sub_8016028();
      if (iVar2 > iVar3) {
        sub_80160F4(2);
      }
      else {
        sub_80160F4(1);
      }
    }
  }
}

void sub_8016248(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    switch(temp)
    {
        case 2:
            sub_80160F4(4);
            break;
        case 3:
        case 1:
            sub_80160F4(0);
            break;
        default:
            break;
    }
  }
}

void sub_8016280(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    sub_80160F4(0);
  }
}


void sub_801629C(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    sub_80160F4(0);
  }
}

u8 sub_80162B8(void)
{
  char cVar1;
  int index;
  s32 max;

  max = 10; // constant needed at top of loop to match
  index = 0;
  do {
    cVar1 = gUnknown_203B200->unk8[index];
    if (cVar1 == 0) break;
    if (cVar1 != 0x20) return 0;
    index++;
  } while (index < max);
  return 1;
}
