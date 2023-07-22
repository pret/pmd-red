#include "global.h"
#include "menu.h"
#include "file_system.h"
#include "memory.h"
#include "input.h"
#include "text.h"
#include "text_util.h"

struct unkStruct_203B200
{
    // size: 0x50
    u32 unk0;
    u32 unk4;
    u8 *pokeName;
    s32 state;
    /* 0x10 */ struct MenuItem menus[3];
    u8 fill[0x50 - 0x28];
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
extern void CreateConfirmNameMenu(void);
extern void sub_80160F4(u32);
bool8 IsNameEmpty(void);
extern u32 sub_80154F0(void);
extern void sub_80155F0(void);

void nullsub_36(void);
void sub_8016110(void);
extern void sub_80161F8(void);
extern void HandleConfirmNameMenu(void);
extern void sub_8016280(void);
extern void sub_801629C(void);


enum
{
    MENU_ACTION_DEFAULT = 1,
    MENU_ACTION_YES,
    MENU_ACTION_NO,
};

extern u32 ReturnIntFromChar2(u8);

struct unkChar
{
    u32 unk0;
    s16 unk4;
    s16 unk6;
};

struct unkChar *GetCharacter(u32);


s32 sub_8015FEC(u8 *buffer, s32 size)
{
  struct unkChar *iVar2;
  s32 currLength;
  s32 length;
  u8 *bufferPtr;

  length = 0;
  currLength = 0;

 if(currLength < size && *buffer != '\0')
 {
    bufferPtr = buffer; // Had to have another variable to match..
    do {
        iVar2 = GetCharacter(ReturnIntFromChar2(*bufferPtr));
        length += iVar2->unk6;
        bufferPtr++;
        currLength++;
    } while (currLength < size && *bufferPtr != '\0');
 }
  return length;
}

s32 sub_8016028(void)
{
    return 60;
}

u32 sub_801602C(u32 r0, u8 *name)
{
    ResetUnusedInputStruct();
    sub_800641C(0, 1, 1);
    gUnknown_203B200 = MemoryAlloc(sizeof(struct unkStruct_203B200), 8);
    gUnknown_203B200->unk0 = r0;
    gUnknown_203B200->pokeName = name;
    switch(r0)
    {
        case 0:
            gUnknown_203B200->unk4 = 0;
            break;
        case 1:
            gUnknown_203B200->unk4 = 1;
            break;
        case 2:
            gUnknown_203B200->unk4 = 2;
            break;
        case 3:
            gUnknown_203B200->unk4 = 3;
            break;
        default:
            break;
    }
    sub_80160F4(0);
    return 1;
}

u32 sub_8016080(void)
{
  switch(gUnknown_203B200->state) {
    case 0:
        sub_80161F8();
        break;
    case 1:
        HandleConfirmNameMenu();
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
        sub_80151C0(gUnknown_203B200->unk4,gUnknown_203B200->pokeName);
        break;
    case 1:
        CreateConfirmNameMenu();
        if (gUnknown_203B200->unk4 == 1) {
            sub_80922B4(gAvailablePokemonNames,gUnknown_203B200->pokeName, POKEMON_NAME_LENGTH);
        }
        else {
            sub_80922B4(gAvailablePokemonNames,gUnknown_203B200->pokeName, POKEMON_NAME_LENGTH);
        }
        // Is the name {COLOR_1 CYAN}{ARG_POKEMON_0}{END_COLOR_TEXT_1} OK?
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

void CreateConfirmNameMenu(void)
{
  gUnknown_203B200->menus[0].text = gUnknown_80D4920; // Yes
  gUnknown_203B200->menus[0].menuAction = MENU_ACTION_YES;
  gUnknown_203B200->menus[1].text = gUnknown_80D4928; // No
  gUnknown_203B200->menus[1].menuAction = MENU_ACTION_NO;
  gUnknown_203B200->menus[2].text = NULL;
  gUnknown_203B200->menus[2].menuAction = MENU_ACTION_DEFAULT;
}

void sub_80161F8(void)
{
  s32 length;
  s32 maxLength;

  if (sub_80154F0() == 3) {
    sub_80155F0();
    if (IsNameEmpty()) {
        sub_80160F4(3);
    }
    else{
      length = sub_8015FEC(gUnknown_203B200->pokeName, POKEMON_NAME_LENGTH);
      maxLength = sub_8016028(); // returns 60
      if (length > maxLength) {
        sub_80160F4(2);
      }
      else {
        sub_80160F4(1);
      }
    }
  }
}

void HandleConfirmNameMenu(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    switch(temp)
    {
        case MENU_ACTION_YES:
            sub_80160F4(4);
            break;
        case MENU_ACTION_NO:
        case MENU_ACTION_DEFAULT:
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

bool8 IsNameEmpty(void)
{
  u8 character;
  s32 index;
  s32 max;

  max =  POKEMON_NAME_LENGTH; // constant needed at top of loop to match
  index = 0;
  do {
    character = gUnknown_203B200->pokeName[index];
    if (character == '\0') break;
    if (character != ' ') return FALSE;
    index++;
  } while (index < max);
  return TRUE;
}
