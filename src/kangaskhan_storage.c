#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "item.h"
#include "kangaskhan_storage.h"
#include "memory.h"
#include "menu_input.h"
#include "team_inventory.h"
#include "kecleon_bros.h"

EWRAM_DATA_2 struct unkStruct_203B208 *gUnknown_203B208 = {0};
EWRAM_DATA_2 struct unkStruct_203B20C *gUnknown_203B20C = {0};

extern struct UnkTextStruct2 gUnknown_80DB748;
extern struct UnkTextStruct2 gUnknown_80DB778;
extern struct UnkTextStruct2 gUnknown_80DB790;
extern struct UnkTextStruct2 gUnknown_80DB760;
extern struct UnkTextStruct2 gUnknown_80DB7B8;
extern struct UnkTextStruct2 gUnknown_80DB7E8;
extern struct UnkTextStruct2 gUnknown_80DB7D0;
extern struct UnkTextStruct2 gUnknown_80DB800;
extern struct UnkTextStruct2 gUnknown_80DB818;
extern u8 gUnknown_80DB830[];
extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 gUnknown_80DB7A8;

extern u8 *gUnknown_80D4970[];
extern u8 *gUnknown_80D4964[];
extern u8 *gUnknown_80D4958[];
extern u8 *gUnknown_80D4984[];
extern u8 *gUnknown_80D4934[];

extern u8 *gKangaskhanStorageDialogue[2][20];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202E1C8[];
void UpdateKangaskhanStorageState(u32);

extern void sub_8017828();
extern void sub_8017AF8();
extern void sub_8017C7C();
extern void sub_8017DC0();
extern void sub_80178D0();
extern void sub_80179A8();
extern void sub_8017B88();
extern void sub_8017C28();
extern void sub_8017D24();
extern void sub_8017DDC();
extern void sub_8017928();
extern void sub_8017A1C();
extern void AdvanceToKangaskhanStorageFallbackState();
void sub_8016E80();
extern void sub_8016FF8();
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern s32 sub_80144A4(s32 *);
extern u8 sub_801CF50(u32);
extern void sub_801C8C4(u32, u32, u32, u32);
extern void sub_801CB5C(u32);
extern u32 sub_801CFE0(u8);
extern void sub_801CF94(void);
extern u8 sub_801CF14(u32);
extern u8 sub_801CF50(u32);
extern u32 sub_801A6E8(bool8);
extern void sub_80182E4(void);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern void sub_8099690(u32);
extern u32 sub_8013BBC(u32 *);
extern void sub_8017598(void);
extern u32 sub_801CA08(u32);
extern u32 sub_801CFB8(void);
extern u8 sub_801CB24();
extern void sub_801B450();
extern u32 sub_801B410(void);
extern void sub_8017F10(u32);
extern void sub_8018588(void);
extern void sub_8018620(void);
extern void sub_8018904(void);
extern void sub_8018AC8(void);
extern void sub_80186F8(void);
extern void sub_8018854(void);
extern void sub_80189C8(void);
extern void sub_8018AE4(void);
extern void sub_8017F28();
extern void sub_8018100();
extern void sub_801841C();
extern void sub_801CCD8();
extern void sub_80184D4();
extern void sub_8018280();
void sub_80175FC(void);
extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u16 *, u32, u32, struct OpenedFile **r5, u32);
extern void sub_801C8C4(u32, u32, u32, u32);
extern void sub_801CB5C(u32);
extern void sub_801BB20(void);
extern void sub_801BC24(void);
void sub_80176B8(void);
void sub_80177F8(void);
void sub_8017758(void);
void sub_801A928(void);
extern void sub_8013AA0(u32 *);
extern void sub_8017598(void);
extern void sub_801CCD8(void);
extern void sub_801CBB8(void);
extern void sub_801B3C0(struct Item *);
extern u8 sub_801CF14(u32);


u32 CreateKangaskhanStorage(bool32 isAsleep)
{
  char *monName;
  struct OpenedFile * faceFile;
  
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B208 = MemoryAlloc(sizeof(struct unkStruct_203B208),8);
  gUnknown_203B208->menuAction1 = 0;
  gUnknown_203B208->menuAction2 = 0;
  gUnknown_203B208->menuAction3 = 0;
  gUnknown_203B208->isAsleep = isAsleep;
  CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, MONSTER_KANGASKHAN);
  CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, MONSTER_KANGASKHAN);
  monName = GetMonSpecies(MONSTER_KANGASKHAN);
  strcpy(gUnknown_202E1C8 - 0x50, monName);
  if (gUnknown_203B208->isAsleep == 1) {
    gUnknown_203B208->unkE8 = 0;
  }
  else {
    gUnknown_203B208->unkE8 = &gUnknown_203B208->faceFile;
  }
  faceFile = GetDialogueSpriteDataPtr(MONSTER_KANGASKHAN);
  gUnknown_203B208->faceFile = faceFile;
  gUnknown_203B208->faceData = faceFile->data;
  gUnknown_203B208->unkE4 = 0;
  gUnknown_203B208->unkE5 = 0;
  gUnknown_203B208->unkE6 = 0;
  gUnknown_203B208->unkE0 = 2;
  gUnknown_203B208->unkE2 = 8;
  UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_INIT);
  return 1;
}

u32 sub_8016D54(void)
{ 
  switch(gUnknown_203B208->currState) {
    case KANGASKHAN_STORAGE_INIT:
    case KANGASKHAN_STORAGE_MAIN_MENU:
        sub_8017828();
        break;
    case 0xd:
    case 0xe:
        sub_8017AF8();
        break;
    case 0xf:
        sub_8017C7C();
        break;
    case 0x10:
        sub_8017DC0();
        break;
    case 0x11:
        sub_80178D0();
        break;
    case 0x12:
        sub_80179A8();
        break;
    case 0x16:
    case 0x17:
        sub_8017B88();
        break;
    case 0x18:
        sub_8017C28();
        break;
    case 0x19:
        sub_8017D24();
        break;
    case 0x1a:
        sub_8017DDC();
        break;
    case 0x1b:
        sub_8017928();
        break;
    case 0x1c:
        sub_8017A1C();
        break;
    case KANGASKHAN_STORAGE_EXIT:
        return 3;
    default:
        AdvanceToKangaskhanStorageFallbackState();
        break;
  }
    return 0;
}

void sub_8016E40(void)
{
    if(gUnknown_203B208 != NULL)
    {
        CloseFile(gUnknown_203B208->faceFile);
        MemoryFree(gUnknown_203B208);
        gUnknown_203B208 = NULL;
    }
}

void UpdateKangaskhanStorageState(u32 newState)
{
    gUnknown_203B208->currState = newState;
    sub_8016E80();
    sub_8016FF8();
}

void sub_8016E80(void)
{
    s32 index;

    sub_8006518(gUnknown_203B208->unkEC);
    switch(gUnknown_203B208->currState)
    {
        case 0xD:
        case 0xE:
            gUnknown_203B208->unkEC[0] = gUnknown_80DB748;
            gUnknown_203B208->unkEC[1] = gUnknown_80DB748;
            gUnknown_203B208->unkEC[2] = gUnknown_80DB748;
            gUnknown_203B208->unkEC[0] = gUnknown_80DB748;
            break;
        case 0x16:
        case 0x17:
            gUnknown_203B208->unkEC[0] = gUnknown_80DB748;
            gUnknown_203B208->unkEC[1] = gUnknown_80DB748;
            gUnknown_203B208->unkEC[2] = gUnknown_80DB748;
            gUnknown_203B208->unkEC[0] = gUnknown_80DB778;
            break;
        case 0x18:
            gUnknown_203B208->unkEC[1] = gUnknown_80DB790;
            break;
        case 0xF:
        case 0x19:
            gUnknown_203B208->unkEC[2] = gUnknown_80DB760;
            break;
        default:
            for(index = 0; index < 4; index++)
                gUnknown_203B208->unkEC[index] = gUnknown_80DB748;
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B208->unkEC, 1, 1);
}

void sub_8016FF8(void)
{

    switch(gUnknown_203B208->currState) {
        case KANGASKHAN_STORAGE_INIT:
            sub_80175FC();
            gUnknown_203B208->unkE4 = 1;
            sub_8014248(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][0],0,gUnknown_203B208->menuAction1,gUnknown_203B208->unk24,
                        gUnknown_203B208->unk4C,4,0,gUnknown_203B208->unkE8,0xc);
            break;
        case KANGASKHAN_STORAGE_MAIN_MENU:
            sub_80175FC();
            gUnknown_203B208->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][1],0,gUnknown_203B208->menuAction1,gUnknown_203B208->unk24,
                        gUnknown_203B208->unk4C,4,0,gUnknown_203B208->unkE8,0xc);
            break;
        case 2:
            gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][19],0,gUnknown_203B208->unkE8,0x10d);
            break;
        case 3:
            gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_EXIT;
            gUnknown_203B208->unkE4 = 1;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][2],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case KANGASKHAN_STORAGE_NO_INV_ITEMS:
            gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][13],0,gUnknown_203B208->unkE8,0x10d);
            break;
        case KANGASKHAN_STORAGE_TOO_MANY_ITEMS:
            gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][14],0,gUnknown_203B208->unkE8,0x10d);
            break;
        case 7:
            gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][15],0,gUnknown_203B208->unkE8,0x10d);
            break;
        case 8:
            gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][18],0,gUnknown_203B208->unkE8,0x10d);
            break;
        case KANGASKHAN_STORAGE_IS_MONEY_USED_TM:
            sub_8090E14(gUnknown_202DE58,&gUnknown_203B208->storedItem,0);
            gUnknown_203B208->fallbackState = 0xe;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][16],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case 10:
            gUnknown_203B208->fallbackState = 0xe;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][17],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case 0xb:
            gUnknown_203B208->fallbackState = 0xd;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][3],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case 0xc:
            gUnknown_203B208->fallbackState = 0xe;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][4],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case 0xd:
            sub_801A5D8(3,3,0,10);
            break;
        case 0xe:
            sub_801A8D0(1);
            break;
        case 0xf:
            sub_801A9E0();
            sub_80176B8();
            sub_8012D60(&gUnknown_203B208->unk58,gUnknown_203B208->unk24,0,
                        gUnknown_203B208->unk4C,gUnknown_203B208->menuAction2,2);
            break;

        case 0x11:
            sub_80177F8();
            sub_8090E14(gUnknown_202DE58,&gUnknown_203B208->storedItem,0);
            gUnknown_203B208->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][5],0,4,gUnknown_203B208->unk24,0,4,0,
                        gUnknown_203B208->unkE8,0xc);
            break;
        case 0x12:
            sub_80177F8();
            gUnknown_203B208->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][6],0,4,gUnknown_203B208->unk24,0,4,0,
                        gUnknown_203B208->unkE8,0xc);
            break;
        case 0x13:
            if (GetNumberOfFilledInventorySlots() == 0) {
                sub_801A928();
                gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            }
            else {
                gUnknown_203B208->fallbackState = 0xc;
            }
            gUnknown_203B208->unkE4 = 1;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][7],0,gUnknown_203B208->unkE8,0x10d);
            break;
        case 0x14:
            gUnknown_203B208->fallbackState = 0x16;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][8],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case 0x15:
            gUnknown_203B208->fallbackState = 0x17;
            gUnknown_203B208->unkE4 = 0;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][9],0,gUnknown_203B208->unkE8,0x30d);
            break;
        case 0x16:
            sub_801C8C4(1,3,0,10);
            sub_801AD34(0);
            break;
        case 0x17:
            sub_801CB5C(1);
            sub_801AD34(0);
            break;
        case 0x18:
            gUnknown_203B208->unkB8 = 2;
            gUnknown_203B208->unkB0 = 1;
            if (gTeamInventory_203B460->teamStorage[gUnknown_203B208->storedItem.id] >= 100)
                {
                    gUnknown_203B208->unkB4 = 99;
                }
            else {
                gUnknown_203B208->unkB4 = gTeamInventory_203B460->teamStorage [gUnknown_203B208->storedItem.id];

            }
            gUnknown_203B208->unkAC = gUnknown_203B208->unkB4;
            gUnknown_203B208->unkBC = 1;
            gUnknown_203B208->unkC0 = &gUnknown_203B208->unkEC[1];
            gUnknown_203B208->unkC4 = 0x28;
            gUnknown_203B208->unkC8 = 0x12;
            sub_8013AA0(&gUnknown_203B208->unkA8);
            sub_8017598();
            break;
        case 0x19:
            sub_801CCD8();
            sub_801AD34(0);
            sub_8017758();
            sub_8012D60(&gUnknown_203B208->unk58,gUnknown_203B208->unk24,0,
                        gUnknown_203B208->unk4C,gUnknown_203B208->menuAction3,2);
            break;
        case 0x10:
        case 0x1a:
            sub_801B3C0(&gUnknown_203B208->storedItem);
            break;
        case 0x1b:
            sub_80177F8();
            sub_8090E14(gUnknown_202DE58,&gUnknown_203B208->storedItem,0);
            gUnknown_203B208->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][10],0,4,gUnknown_203B208->unk24,0,4,0,
                        gUnknown_203B208->unkE8,0xc);
            break;
        case 0x1c:
            sub_80177F8();
            gUnknown_203B208->unkE4 = 0;
            sub_8014248(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][11],0,4,gUnknown_203B208->unk24,0,4,0,
                        gUnknown_203B208->unkE8,0xc);
            break;
        case 0x1d:
            if ((sub_801CF14(1)) || (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)) {
                sub_801CBB8();
                gUnknown_203B208->fallbackState = KANGASKHAN_STORAGE_MAIN_MENU;
            }
            else {
                gUnknown_203B208->fallbackState = 0x15;
            }
            gUnknown_203B208->unkE4 = 1;
            sub_80141B4(gKangaskhanStorageDialogue[gUnknown_203B208->isAsleep][12],0,gUnknown_203B208->unkE8,0x10d);
            break;
    }
}

void sub_8017598(void)
{
  
  sub_8008C54(gUnknown_203B208->unkBC);
  sub_80073B8(gUnknown_203B208->unkBC);
  xxx_call_draw_string(4,0,&gUnknown_80DB7A8,gUnknown_203B208->unkBC,0); // Number?
  sub_8013C68(&gUnknown_203B208->unkA8);
  sub_80073E0(gUnknown_203B208->unkBC);
  sub_801CCD8();
  sub_801AD34(0);
  sub_8012EA4(&gUnknown_203B208->unk58,0);
}

void sub_80175FC(void)
{
  int index;

  s32 loopMax;
  MemoryFill16(gUnknown_203B208->unk4C,0, sizeof(gUnknown_203B208->unk4C));
  loopMax = 0;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4958;
  gUnknown_203B208->unk24[loopMax].menuAction = 2;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4964;
  gUnknown_203B208->unk24[loopMax].menuAction = 3;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B208->unk24[loopMax].menuAction = 6;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4934;
  gUnknown_203B208->unk24[loopMax].menuAction = 1;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = NULL;
  gUnknown_203B208->unk24[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B208->unk4C[index] == 0)
      {
          if(gUnknown_203B208->unk24[index].menuAction == gUnknown_203B208->menuAction1)
              return;
      }
  }
  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B208->unk4C[index] == 0)
      {
           gUnknown_203B208->menuAction1 =  gUnknown_203B208->unk24[index].menuAction;
           break;
      }
  }
}

void sub_80176B8(void)
{
  int index;
  s32 loopMax;

  MemoryFill16(gUnknown_203B208->unk4C,0,sizeof(gUnknown_203B208->unk4C));
  loopMax = 0;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4958;
  gUnknown_203B208->unk24[loopMax].menuAction = 2;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B208->unk24[loopMax].menuAction = 6;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = NULL;
  gUnknown_203B208->unk24[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B208->unk4C[index] == 0)
      {
          if(gUnknown_203B208->unk24[index].menuAction == gUnknown_203B208->menuAction2)
              return;
      }
  }
  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B208->unk4C[index] == 0)
      {
           gUnknown_203B208->menuAction2 =  gUnknown_203B208->unk24[index].menuAction;
           break;
      }
  }
}

void sub_8017758(void)
{
  int index;
  s32 loopMax;

  MemoryFill16(gUnknown_203B208->unk4C,0,sizeof(gUnknown_203B208->unk4C));
  loopMax = 0;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4964;
  gUnknown_203B208->unk24[loopMax].menuAction = 3;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B208->unk24[loopMax].menuAction = 6;
  loopMax += 1;
  gUnknown_203B208->unk24[loopMax].text = NULL;
  gUnknown_203B208->unk24[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if(gUnknown_203B208->unk4C[index] == 0)
      {
          if(gUnknown_203B208->unk24[index].menuAction == gUnknown_203B208->menuAction3)
              return;
      }
  }
  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B208->unk4C[index] == 0)
      {
           gUnknown_203B208->menuAction3 =  gUnknown_203B208->unk24[index].menuAction;
           break;
      }
  }
}

void sub_80177F8(void)
{
    s32 loopMax;

    loopMax = 0;
    gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B208->unk24[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B208->unk24[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B208->unk24[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B208->unk24[loopMax].text = NULL;
    gUnknown_203B208->unk24[loopMax].menuAction = 1;
}

void sub_8017828(void)
{
  s32 menuAction;

  if (sub_80144A4(&menuAction) == 0) {
    if (menuAction != 1) {
      gUnknown_203B208->menuAction1 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
            if (GetNumberOfFilledInventorySlots() == 0) {
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_NO_INV_ITEMS);
            }
            else if (sub_801CF50(0) != 0) {
                UpdateKangaskhanStorageState(8);
            }
            else {
                UpdateKangaskhanStorageState(0xb);
            }
            break;
        case 3:
            if (sub_801CF14(1) != 0) {
                UpdateKangaskhanStorageState(7);
            }
            else if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE) {
                UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_TOO_MANY_ITEMS);
            }
            else {
                UpdateKangaskhanStorageState(0x14);
            }
            break;
        case 6:
            UpdateKangaskhanStorageState(2);
            break;
        case 1:
            UpdateKangaskhanStorageState(3);
            break;
    }
  }
}

void sub_80178D0(void)
{
  s32 menuAction;
  
  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction)
    {
      case 4:
        MoveToStorage(&gUnknown_203B208->storedItem);
        ShiftItemsDownFrom(gUnknown_203B208->itemIndex);
        FillInventoryGaps();
        UpdateKangaskhanStorageState(0x13);
        break;
      case 1:
      case 5:
        UpdateKangaskhanStorageState(0xe);
        break;
    }
  }
}

void sub_8017928(void)
{
  int menuAction;
  struct BulkItem item;
  
  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction)
    {
        case 4:
            gTeamInventory_203B460->teamStorage[gUnknown_203B208->storedItem.id] -= gUnknown_203B208->storedItem.quantity;
            item.id = gUnknown_203B208->storedItem.id;
            item.quantity = gUnknown_203B208->storedItem.quantity;
            AddHeldItemToInventory(&item);
            UpdateKangaskhanStorageState(0x1d);
            break;
        case 1:
        case 5:
            UpdateKangaskhanStorageState(0x17);
            break;
    }
  }
}

void sub_80179A8(void)
{
  s32 index;
  s32 menuAction;
  
  if (sub_80144A4(&menuAction) == 0) {
    switch(menuAction)
    {
      case 4:
        for(index = 0; index < INVENTORY_SIZE; index++)
        {
          if (sub_801AED0(index) != 0) {
            MoveToStorage(&gTeamInventory_203B460->teamItems[index]);
            gTeamInventory_203B460->teamItems[index].id = 0;
            gTeamInventory_203B460->teamItems[index].flags = 0;
          }
        }
        FillInventoryGaps();
        sub_801AE84();
        UpdateKangaskhanStorageState(0x13);
        break;
      case 1:
      case 5:
        UpdateKangaskhanStorageState(0xe);
        break;
    }
  }
}

void sub_8017A1C(void)
{
  s32 itemID;
  int menuAction;
  struct BulkItem item;
  
  if (sub_80144A4(&menuAction) == 0) {

    switch(menuAction)
    {
        case 4:
            for(itemID = 0; itemID < NUMBER_OF_ITEM_IDS; itemID++)
            {
                if(sub_801CFE0(itemID) != 0)
                {
                    item.id = itemID;
                    if(IsThrowableItem(item.id))
                        if(gTeamInventory_203B460->teamStorage[item.id] > 0x63)
                        {
                            item.quantity = 0x63;
                        }
                        else
                        {
                            item.quantity = gTeamInventory_203B460->teamStorage[item.id];
                        }
                    else
                    {
                        item.quantity = 1;
                    }
                    gTeamInventory_203B460->teamStorage[item.id] -= item.quantity;
                    AddHeldItemToInventory(&item);
                }
            }
            FillInventoryGaps();
            sub_801CF94();
            UpdateKangaskhanStorageState(0x1d);
            break;
        case 1:
        case 5:
            UpdateKangaskhanStorageState(0x17);
            break;
    }
  }
}

void sub_8017AF8(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            if(sub_801AEA8() != 0)
            {
                sub_8099690(0);
                UpdateKangaskhanStorageState(0x12);
            }
            else
            {
                gUnknown_203B208->itemIndex = sub_801A8AC();
                gUnknown_203B208->storedItem = gTeamInventory_203B460->teamItems[gUnknown_203B208->itemIndex];
                UpdateKangaskhanStorageState(0xF);
            }
            break;
        case 4:
            gUnknown_203B208->itemIndex = sub_801A8AC();
            gUnknown_203B208->storedItem = gTeamInventory_203B460->teamItems[gUnknown_203B208->itemIndex];
            UpdateKangaskhanStorageState(0x10);
            break;
        case 2:
            sub_801A928();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_MAIN_MENU);
            break;
    }
}

void sub_8017B88(void)
{
    switch(sub_801CA08(1))
    {
        case 3:
            if(sub_801CFB8() != 0){
                UpdateKangaskhanStorageState(0x1C);
            }
            else
            {
                gUnknown_203B208->id = sub_801CB24();
                xxx_init_itemslot_8090A8C(&gUnknown_203B208->storedItem, gUnknown_203B208->id, 0);
                gUnknown_203B208->storedItem.quantity = 1;
                UpdateKangaskhanStorageState(0x19);
            }
            break;
        case 4:
            gUnknown_203B208->id = sub_801CB24();
            xxx_init_itemslot_8090A8C(&gUnknown_203B208->storedItem, gUnknown_203B208->id, 0);
            gUnknown_203B208->storedItem.quantity = 1;
            UpdateKangaskhanStorageState(0x1A);
            break;
        case 2:
            sub_801CBB8();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_MAIN_MENU);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

void sub_8017C28(void)
{
    sub_801CA08(0);
    sub_8012FD8(&gUnknown_203B208->unk58);
    switch(sub_8013BBC(&gUnknown_203B208->unkA8))
    {
        case 1:
            sub_8017598();
            break;
        case 3:
            gUnknown_203B208->storedItem.quantity = gUnknown_203B208->unkA8;
            UpdateKangaskhanStorageState(0x1B);
            break;
        case 2:
            UpdateKangaskhanStorageState(0x17);
            break;
        case 0:
        default:
            break;
    }
}

void sub_8017C7C(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801A6E8(FALSE);
    if (sub_8012FD8(&gUnknown_203B208->unk58) == 0) {
        sub_8013114(&gUnknown_203B208->unk58, &menuAction);
        if(menuAction != 1) gUnknown_203B208->menuAction2 = menuAction;
    }

    switch(menuAction)
    {
      case 2:
        sub_8099690(0);
        if(!IsNotMoneyOrUsedTMItem(gUnknown_203B208->storedItem.id))
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_IS_MONEY_USED_TM);
        else if(!sub_801ADA0(gUnknown_203B208->itemIndex))
            UpdateKangaskhanStorageState(0xA);
        else
            UpdateKangaskhanStorageState(0x11);
        break;
      case 6:
        sub_8099690(0);
        UpdateKangaskhanStorageState(0x10);
        break;
      case 1:
        UpdateKangaskhanStorageState(0xE);
        break;
    }
}

void sub_8017D24(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801CA08(0);
    if (sub_8012FD8(&gUnknown_203B208->unk58) == 0) {
        sub_8013114(&gUnknown_203B208->unk58, &menuAction);
        if(menuAction != 1) gUnknown_203B208->menuAction3 = menuAction;
    }

    switch(menuAction)
    {
      case 3:
        if (GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
        {
            sub_801CBB8();
            UpdateKangaskhanStorageState(KANGASKHAN_STORAGE_TOO_MANY_ITEMS);
        }
        else if(IsThrowableItem(gUnknown_203B208->storedItem.id))
            UpdateKangaskhanStorageState(0x18);
        else
            UpdateKangaskhanStorageState(0x1B);
        break;
      case 6:
        UpdateKangaskhanStorageState(0x1A);
        break;
      case 1:
        UpdateKangaskhanStorageState(0x17);
        break;
    }
}

void sub_8017DC0(void)
{
    switch(sub_801B410())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(0xE);
            break;
    }
}

void sub_8017DDC(void)
{
    switch(sub_801B410())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801B450();
            UpdateKangaskhanStorageState(0x17);
            break;
    }
}

void AdvanceToKangaskhanStorageFallbackState(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateKangaskhanStorageState(gUnknown_203B208->fallbackState);
    }
}

u32 sub_8017E1C(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    gUnknown_203B20C = MemoryAlloc(sizeof(struct unkStruct_203B20C), 8);
    gUnknown_203B20C->menuAction1 = 0;
    gUnknown_203B20C->menuAction2 = 0;
    gUnknown_203B20C->menuAction3 = 0;
    sub_8017F10(0);
    return 1;
}

u32 sub_8017E54(void)
{
  switch(gUnknown_203B20C->state)
  {
      case 0:
        sub_8017F10(1);
        break;
      case 1:
        sub_8018588();
        break;
      case 4:
      case 5:
        sub_8018620();
        break;
      case 6:
        sub_8018904();
        break;
      case 7:
        sub_8018AC8();
        break;
      case 10:
      case 11:
        sub_80186F8();
        break;
      case 12:
        sub_8018854();
        break;
      case 13:
        sub_80189C8();
        break;
      case 14:
        sub_8018AE4();
        break;
      case 3:
        return 3;
  }
  return 0;
}

void sub_8017EF4(void)
{
    if(gUnknown_203B20C != NULL)
    {
        MemoryFree(gUnknown_203B20C);
        gUnknown_203B20C = NULL;
    }
}

void sub_8017F10(u32 newState)
{
    gUnknown_203B20C->state = newState;
    sub_8017F28();
    sub_8018100();
}

void sub_8017F28(void)
{
    s32 index;

    sub_8006518(gUnknown_203B20C->unkF0);

    switch(gUnknown_203B20C->state)
    {
        case 1:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            sub_80182E4();
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7D0;
            sub_8012CAC(&gUnknown_203B20C->unkF0[2], gUnknown_203B20C->unk20);
            break;
        case 4:
        case 5:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            break;
        case 10:
        case 11:
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7B8;
            gUnknown_203B20C->unkF0[0] = gUnknown_80DB800;
            break;
        case 12:
            gUnknown_203B20C->unkF0[1] = gUnknown_80DB818;
            break;
        case 6:
        case 13:
            gUnknown_203B20C->unkF0[2] = gUnknown_80DB7E8;
            break;
        default:
        case 0:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B20C->unkF0[index] = gUnknown_80DB7B8;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B20C->unkF0, 1, 1);
}

void sub_8018100(void)
{

    switch(gUnknown_203B20C->state)
    {
        case 1:
            sub_8012D60(&gUnknown_203B20C->unk70, gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->menuAction1, 2);
            break;
        case 4:
            sub_801A5D8(3, 3, 0, 0xA);
            break;
        case 5:
            sub_801A8D0(1);
            break;
        case 6:
            sub_801A9E0();
            sub_801841C();
            sub_8012D60(&gUnknown_203B20C->unk70, gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->menuAction2, 2);
            break;
        case 7:
            sub_801B3C0(&gUnknown_203B20C->item);
            break;
        case 10:
            sub_801C8C4(1, 3, 0, 0xA);
            sub_801AD34(0);
            break;
        case 11:
            sub_801CB5C(1);
            sub_801AD34(0);
            break;
        case 12:
            gUnknown_203B20C->unkD0 = 2;
            gUnknown_203B20C->unkC8 = 1;
            if(gTeamInventory_203B460->teamStorage[gUnknown_203B20C->item.id] > 99)
                gUnknown_203B20C->unkCC = 99;
            else
                gUnknown_203B20C->unkCC = gTeamInventory_203B460->teamStorage[gUnknown_203B20C->item.id];
            gUnknown_203B20C->unkC4 = gUnknown_203B20C->unkCC;
            gUnknown_203B20C->unkD4 = 1;
            gUnknown_203B20C->unkD8 = &gUnknown_203B20C->unkF0[1];
            gUnknown_203B20C->unkDC = 0x28;
            gUnknown_203B20C->unkE0 = 0x12;
            sub_8013AA0(&gUnknown_203B20C->unkC0);
            sub_8018280();
            break;
        case 13:
            sub_801CCD8();
            sub_801AD34(0);
            sub_80184D4();
            sub_8012D60(&gUnknown_203B20C->unk70, gUnknown_203B20C->unk20, 0, gUnknown_203B20C->unk60, gUnknown_203B20C->menuAction3, 2);
            break;
        case 14:
            sub_801B3C0(&gUnknown_203B20C->item);
            break;
        case 0:
        default:
            break;
    }
}

void sub_8018280(void)
{
    sub_8008C54(gUnknown_203B20C->unkD4);
    sub_80073B8(gUnknown_203B20C->unkD4);
    xxx_call_draw_string(4, 0, gUnknown_80DB830, gUnknown_203B20C->unkD4, 0); // Number?
    sub_8013C68(&gUnknown_203B20C->unkC0);
    sub_80073E0(gUnknown_203B20C->unkD4);
    sub_801CCD8();
    sub_801AD34(0);
    sub_8012EA4(&gUnknown_203B20C->unk70,0);
}

void sub_80182E4(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(gUnknown_203B20C->unk60,0,sizeof(gUnknown_203B20C->unk60));
  gUnknown_203B20C->unk20[0].text = *gUnknown_80D4958;
  gUnknown_203B20C->unk20[0].menuAction = 2;
  if ((GetNumberOfFilledInventorySlots() == 0) || (sub_801CF50(0) != 0)) {
    gUnknown_203B20C->unk60[0] = 1;
  }
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4964;
  gUnknown_203B20C->unk20[loopMax].menuAction = 3;
  if ((sub_801CF14(1) != 0) || (INVENTORY_SIZE <=  GetNumberOfFilledInventorySlots())) {
    gUnknown_203B20C->unk60[loopMax] = 1;
  }
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4934;
  gUnknown_203B20C->unk20[loopMax].menuAction = 1;
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = NULL;
  gUnknown_203B20C->unk20[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B20C->unk60[index] == 0) {
        if(gUnknown_203B20C->unk20[index].menuAction == gUnknown_203B20C->menuAction1)
            return;
      }
  }

  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B20C->unk60[index] == 0) {
        gUnknown_203B20C->menuAction1 = gUnknown_203B20C->unk20[index].menuAction;
        break;
      }
  }
}

void sub_801841C(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(gUnknown_203B20C->unk60,0,sizeof(gUnknown_203B20C->unk60));
  gUnknown_203B20C->unk20[0].text = *gUnknown_80D4958;
  gUnknown_203B20C->unk20[0].menuAction = 2;
  if (!sub_801ADA0(gUnknown_203B20C->itemIndex)) {
    gUnknown_203B20C->unk60[0] = 1;
  }
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B20C->unk20[loopMax].menuAction = 4;
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = NULL;
  gUnknown_203B20C->unk20[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B20C->unk60[index] == 0) {
        if(gUnknown_203B20C->unk20[index].menuAction == gUnknown_203B20C->menuAction2)
            return;
      }
  }

  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B20C->unk60[index] == 0) {
        gUnknown_203B20C->menuAction2 = gUnknown_203B20C->unk20[index].menuAction;
        break;
      }
  }
}

void sub_80184D4(void)
{
  int index;
  s32 loopMax;

  loopMax = 0;
  MemoryFill16(gUnknown_203B20C->unk60,0,sizeof(gUnknown_203B20C->unk60));
  gUnknown_203B20C->unk20[0].text = *gUnknown_80D4964;
  gUnknown_203B20C->unk20[0].menuAction = 3;
  if ((GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)) {
    gUnknown_203B20C->unk60[0] = 1;
  }
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = *gUnknown_80D4970;
  gUnknown_203B20C->unk20[loopMax].menuAction = 4;
  loopMax += 1;
  gUnknown_203B20C->unk20[loopMax].text = NULL;
  gUnknown_203B20C->unk20[loopMax].menuAction = 1;

  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B20C->unk60[index] == 0) {
        if(gUnknown_203B20C->unk20[index].menuAction == gUnknown_203B20C->menuAction3)
            return;
      }
  }

  for(index = 0; index < loopMax; index++)
  {
      if (gUnknown_203B20C->unk60[index] == 0) {
        gUnknown_203B20C->menuAction3 = gUnknown_203B20C->unk20[index].menuAction;
        break;
      }
  }
}

void sub_8018588(void)
{
    s32 menuAction;
    menuAction = 0;

    if(sub_8012FD8(&gUnknown_203B20C->unk70) == 0)
    {
        sub_8013114(&gUnknown_203B20C->unk70, &menuAction);
        if(menuAction != 1) gUnknown_203B20C->menuAction1 = menuAction;
    }

    switch(menuAction)
    {
        case 2:
            if((GetNumberOfFilledInventorySlots() != 0) && sub_801CF50(0) == 0)
                sub_8017F10(4);
            else
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);;
            break;
        case 3:
            if(sub_801CF14(1) != 0)
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            else
                sub_8017F10(0xA);
            break;
        case 1:
            sub_8017F10(3);
            break;
    }
}

void sub_8018620(void)
{
    s32 index;
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            if(sub_801AEA8() != 0)
            {
                for(index = 0; index < INVENTORY_SIZE; index++)
                {
                    if(sub_801AED0(index) != 0)
                    {
                        MoveToStorage(&gTeamInventory_203B460->teamItems[index]);
                        gTeamInventory_203B460->teamItems[index].id = 0;
                        gTeamInventory_203B460->teamItems[index].flags = 0;
                    }
                }
                FillInventoryGaps();
                sub_801AE84();
                if(GetNumberOfFilledInventorySlots() == 0)
                {
                    sub_801A928();
                    sub_8017F10(1);
                }
                else
                {
                    sub_8017F10(5);
                }
            }
            else
            {
                gUnknown_203B20C->itemIndex = sub_801A8AC();
                gUnknown_203B20C->item = gTeamInventory_203B460->teamItems[gUnknown_203B20C->itemIndex];
                sub_8017F10(6);
            }
            break;
        case 4:
            gUnknown_203B20C->itemIndex = sub_801A8AC();
            gUnknown_203B20C->item = gTeamInventory_203B460->teamItems[gUnknown_203B20C->itemIndex];
            sub_8017F10(7);
            break;
        case 2:
            sub_801A928();
            sub_8017F10(1);
            break;
    }
}

void sub_80186F8(void)
{
    struct BulkItem item;
    s32 itemID;

    switch(sub_801CA08(1))
    {
        case 3:
            if(sub_801CFB8() != 0)
            {
                for(itemID = 0; itemID < NUMBER_OF_ITEM_IDS; itemID++)
                {
                    if(sub_801CFE0(itemID) != 0)
                    {
                        item.id = itemID;
                        if(IsThrowableItem(item.id))
                            if(gTeamInventory_203B460->teamStorage[item.id] > 0x63)
                            {
                                item.quantity = 0x63;
                            }
                            else
                            {
                                item.quantity = gTeamInventory_203B460->teamStorage[item.id];
                            }
                        else
                        {
                            item.quantity = 1;
                        }
                        gTeamInventory_203B460->teamStorage[item.id] -= item.quantity;
                        AddHeldItemToInventory(&item);
                    }
                }
                FillInventoryGaps();
                sub_801CF94();
                if((sub_801CF14(1) == 0) && (GetNumberOfFilledInventorySlots() < INVENTORY_SIZE))
                    sub_8017F10(0xB);
                else
                {
                    sub_801CBB8();
                    sub_8017F10(1);
                }
            }
            else
            {
                gUnknown_203B20C->id = sub_801CB24();
                xxx_init_itemslot_8090A8C(&gUnknown_203B20C->item, gUnknown_203B20C->id, 0);
                gUnknown_203B20C->item.quantity = 1;
                sub_8017F10(0xD);
            }
            break;
        case 4:
            gUnknown_203B20C->id = sub_801CB24();
            xxx_init_itemslot_8090A8C(&gUnknown_203B20C->item, gUnknown_203B20C->id, 0);
            gUnknown_203B20C->item.quantity = 1;
            sub_8017F10(0xE);
            break;
        case 2:
            sub_801CBB8();
            sub_8017F10(1);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

void sub_8018854(void)
{
    struct BulkItem item;

    sub_801CA08(0);
    sub_8012FD8(&gUnknown_203B20C->unk70);

    switch(sub_8013BBC(&gUnknown_203B20C->unkC0))
    {
        case 3:
            gUnknown_203B20C->item.quantity = gUnknown_203B20C->unkC0;
            gTeamInventory_203B460->teamStorage[gUnknown_203B20C->item.id] -= gUnknown_203B20C->item.quantity;
            item.id = gUnknown_203B20C->item.id;
            item.quantity = gUnknown_203B20C->item.quantity;
            AddHeldItemToInventory(&item);
            if(sub_801CF14(1) == 0)
                if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                {
                    error:
                        sub_801CBB8();
                        sub_8017F10(0x1);
                }
                else
                    sub_8017F10(0xB);
            else
                goto error;
            break;
        case 2:
            sub_8017F10(0xB);
            break;
        case 1:
            sub_8018280();
            break;
        case 0:
            break;
    }
}

void sub_8018904(void)
{
    s32 menuAction;

    menuAction = 0;

    sub_801A6E8(FALSE);
    if(sub_8012FD8(&gUnknown_203B20C->unk70) == 0)
    {
        sub_8013114(&gUnknown_203B20C->unk70, &menuAction);
        if(menuAction != 1) gUnknown_203B20C->menuAction2 = menuAction;
    }
    switch(menuAction)
    {
        case 2:
            if(IsNotMoneyOrUsedTMItem(gUnknown_203B20C->item.id))
                if(sub_801ADA0(gUnknown_203B20C->itemIndex) == 0)
            error:
                    sub_8012EA4(&gUnknown_203B20C->unk70, 1);
                else
                {
                    MoveToStorage(&gUnknown_203B20C->item);
                    ShiftItemsDownFrom(gUnknown_203B20C->itemIndex);
                    FillInventoryGaps();
                    if(GetNumberOfFilledInventorySlots() == 0)
                    {
                        sub_801A928();
                        sub_8017F10(1);
                    }
                    else
                        sub_8017F10(5);
                }
            else
                goto error;
            break;
        case 4:
            sub_8099690(0);
            sub_8017F10(7);
            break;
        case 1:
            sub_8017F10(5);
            break;
    }
}

void sub_80189C8(void)
{
    struct BulkItem item;
    s32 menuAction;

    menuAction = 0;

    sub_801CA08(0);
    if(sub_8012FD8(&gUnknown_203B20C->unk70) == 0)
    {
        sub_8013114(&gUnknown_203B20C->unk70, &menuAction);
        if(menuAction != 1) gUnknown_203B20C->menuAction3 = menuAction;
    }
    switch(menuAction)
    {
        case 3:
            if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            else if(IsThrowableItem(gUnknown_203B20C->item.id))
                sub_8017F10(0xC);
            else
            {
                gTeamInventory_203B460->teamStorage[gUnknown_203B20C->item.id] -= gUnknown_203B20C->item.quantity;
                item.id = gUnknown_203B20C->item.id;
                item.quantity = gUnknown_203B20C->item.quantity;
                AddHeldItemToInventory(&item);
                if(sub_801CF14(1) == 0)
                    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                    {
                        error:
                            sub_801CBB8();
                            sub_8017F10(1);
                    }
                    else
                    {
                        sub_8017F10(0xB);
                    }
                else
                    goto error;
            }
            break;
        case 4:
            sub_8017F10(0xE);
            break;
        case 1:
            sub_8017F10(0xB);
            break;
    }
}

void sub_8018AC8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(0x5);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

void sub_8018AE4(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(0xB);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

