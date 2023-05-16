#include "global.h"
#include "memory.h"
#include "input.h"
#include "item.h"
#include "menu.h"
#include "pokemon.h"
#include "save.h"
#include "text.h"
#include "main_menu.h"
#include "rescue_password_menu.h"
#include "code_8094F88.h"
#include "wonder_mail.h"
#include "menu_input.h"

#define RESCUE_PASSWORD_SIZE 0x36

EWRAM_DATA u32 gUnknown_202EC4C = {0};
EWRAM_DATA u8 gRescuePasswordBuffer[RESCUE_PASSWORD_SIZE] = {0};

extern struct unkStruct_203B484 *gUnknown_203B484;
extern struct UnkTextStruct2 gUnknown_80E71E4;

EWRAM_DATA_2 u8 gUnknown_203B368 = {0};
EWRAM_DATA_2 u32 gUnknown_203B36C = {0};
EWRAM_DATA_2 struct RescuePasswordMenu *gRescuePasswordMenu = {0};

extern s32 sub_8035D74(void);
extern void sub_80151C0(u32, u8 *);
extern void sub_8031D70(u32, u32);
extern u32 ConvertMenutoRescuePasswordState(u32);
extern void sub_8039174(void);
extern void sub_80155F0(void);
extern void sub_8031E10(void);
extern void DisplayPasswordAcceptScreen(void);


extern u32 sub_8039068(u32, u8 *passwordBuffer, struct unkStruct_203B480 *r0);

extern u32 sub_80154F0(void);
extern u32 sub_8031DCC(void);
extern void sub_80391F8(void);
extern void sub_8031E00();
extern void DisplayRescuePasswordError(u32);
extern struct MainMenu *GetMainMenu(void);


extern void SetMenuItems(struct MenuStruct *, struct UnkTextStruct2 *, u32, const struct UnkTextStruct2 *, const struct MenuItem *, u32, u32, u32);
extern void sub_8035CF4(struct MenuStruct *r0, u32, u32);
bool8 IsInvalidItemReward(u8);
bool8 sub_8095298(s32);
bool8 sub_803D204(u8 *, struct unkStruct_203B480 *);
extern s32 GetDungeonFloorCount(u8);

extern struct UnkTextStruct2 gUnknown_80E71FC;
extern struct UnkTextStruct2 gUnknown_80E7278;
extern struct UnkTextStruct2 gUnknown_80E72EC;
extern struct UnkTextStruct2 gUnknown_80E7344;
extern struct UnkTextStruct2 gUnknown_80E73AC;
extern struct UnkTextStruct2 gUnknown_80E7408;
extern struct UnkTextStruct2 gUnknown_80E7468;
extern struct UnkTextStruct2 gUnknown_80E74C8;
extern struct UnkTextStruct2 gUnknown_80E752C;
extern struct UnkTextStruct2 gUnknown_80E7588;

extern struct MenuItem gUnknown_80E7214[];
extern struct MenuItem gUnknown_80E7290[];
extern struct MenuItem gUnknown_80E7304[];
extern struct MenuItem gUnknown_80E735C[];
extern struct MenuItem gUnknown_80E73C4[];
extern struct MenuItem gUnknown_80E7420[];
extern struct MenuItem gUnknown_80E7480[];
extern struct MenuItem gUnknown_80E74E0[];
extern struct MenuItem gUnknown_80E7544[];
extern struct MenuItem gUnknown_80E75A0[];

void CreateRescuePasswordMenu(u32 currMenu)
{
    struct unkStruct_203B480 *temp;
    s32 counter;

    if(gRescuePasswordMenu == NULL)
    {
        gRescuePasswordMenu = MemoryAlloc(sizeof(struct RescuePasswordMenu), 8);
        MemoryFill8((u8 *)gRescuePasswordMenu, 0, sizeof(struct RescuePasswordMenu));
    }

    for(counter = 0; counter < 4; counter++)
        gRescuePasswordMenu->unk148[counter] = gUnknown_80E71E4;

    ResetUnusedInputStruct();
    sub_800641C(gRescuePasswordMenu->unk148, 1, 1);

    if ((gUnknown_203B368 != 0) || (gUnknown_203B36C != currMenu)) {
        for(counter = 0; counter < RESCUE_PASSWORD_SIZE; counter++)
        {
            gRescuePasswordBuffer[counter] = 0;
        }
        gUnknown_203B368 = 0;
    }

    gRescuePasswordMenu->currMenu = currMenu;
    gUnknown_203B36C = currMenu;

    switch(currMenu)
    {
        case 0x1B:
        case 0x1D:
        case 0x1F:
            sub_8031D70(sub_8035D74(), 0);
            break;
        case 0x1C:
        case 0x1E:
        case 0x20:
            sub_80151C0(4, gRescuePasswordBuffer);
            break;
        case MENU_DISPLAY_RESCUE_PASSWORD:
            temp = GetMailatIndex(0x1F);
            MemoryFill8((u8 *)temp, 0, sizeof(struct unkStruct_203B480));
            temp->mailType = 2;
            temp->unk20.id = ITEM_NOTHING;
            sub_8031D70(0x1F, 0);
            break;
        case MENU_RESCUE_PASSWORD_ENTRY:
            sub_80151C0(4, gRescuePasswordBuffer);
            break;
    }

    gRescuePasswordMenu->state = ConvertMenutoRescuePasswordState(currMenu);
    sub_8039174();
}

void CleanRescuePasswordMenu(void)
{

  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gRescuePasswordMenu != NULL) {
    sub_80155F0();
    sub_8031E10();
    MemoryFree(gRescuePasswordMenu);
    gRescuePasswordMenu = NULL;
  }
}

static inline s32 UpdateRescuePasswordMenu_sub(s32 otherMenu)
{
    u32 iVar1;
    s32 nextMenu;

    iVar1 = sub_8031DCC();
    nextMenu = otherMenu;
    if (iVar1 != 0)
        return nextMenu;
    else
        return MENU_NO_SCREEN_CHANGE;
}

s32 UpdateRescuePasswordMenu(void)
{
  struct unkStruct_203B480 *mailPtr1;
  struct unkStruct_203B480 *mailPtr2;
  u32 iVar7;
  struct MainMenu *mainMenuPtr;
  s32 nextMenu;
  struct unkStruct_203B480 mail;
  u32 menuAction;
  u32 subtract;

  menuAction = 0xb;
  nextMenu = MENU_NO_SCREEN_CHANGE;
  switch(gRescuePasswordMenu->state) {
    case 0:
    case 2:
    case 4:
        nextMenu = UpdateRescuePasswordMenu_sub(MENU_FRIEND_RESCUE);
        break;
    case 1:
    case 3:
    case 5:
        iVar7 = sub_80154F0();
        MemoryFill8((u8 *)&mail, 0, sizeof(struct unkStruct_203B480));
        switch(iVar7)
        {
            case 1:
                sub_8031E00();
                nextMenu = MENU_NO_SCREEN_CHANGE;
                break;
            case 0:
                nextMenu = MENU_NO_SCREEN_CHANGE;
                break;
            case 2:
                nextMenu = MENU_FRIEND_RESCUE;
                break;
            case 3:
                switch(sub_8039068(gRescuePasswordMenu->currMenu, gRescuePasswordBuffer, &mail)) {
                    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
                        nextMenu = PASSWORD_ENTRY_INCORRECT_PASSWORD;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_NO_SPACE:
                        nextMenu = PASSWORD_ENTRY_NO_SPACE;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_NOT_SOS_MAIL:
                        nextMenu = PASSWORD_ENTRY_NOT_SOS_MAIL;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
                        nextMenu = PASSWORD_ENTRY_DUPLICATE_SOS_MAIL;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_SOS_MAIL_SUCCESS:
                        sub_8095274(mail.unk10.unk10);
                        DisplayPasswordAcceptScreen();
                        gRescuePasswordMenu->state = 9;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        mail.mailType = 2;
                        sub_80951BC(&mail);
                        break;
                    case PASSWORD_ENTRY_NOT_AOK_MAIL:
                        nextMenu = PASSWORD_ENTRY_NOT_AOK_MAIL;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_AOK_MAIL:
                        nextMenu = PASSWORD_ENTRY_DUPLICATE_AOK_MAIL;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_AOK_MAIL_SUCCESS:
                        DisplayPasswordAcceptScreen();
                        gRescuePasswordMenu->state = 9;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        mail.mailType = 5;
                        sub_80951FC(&mail);
                        mailPtr1 = GetMailatIndex(GetMailIndex(1, mail.unk10.unk10));
                        mailPtr1->mailType = WONDER_MAIL_TYPE_OKD;
                        MemoryFill8((u8 *)&gUnknown_203B484, 0, sizeof(struct unkStruct_203B484));
                        break;
                    case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
                        nextMenu = PASSWORD_ENTRY_NOT_THANK_YOU_MAIL;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
                        nextMenu = PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL;
                        DisplayRescuePasswordError(nextMenu);
                        gRescuePasswordMenu->state = 8;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        break;
                    case PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS:
                        DisplayPasswordAcceptScreen();
                        gRescuePasswordMenu->state = 9;
                        nextMenu = MENU_NO_SCREEN_CHANGE;
                        mailPtr2 = GetMailatIndex(GetMailIndex(4, mail.unk10.unk10));
                        *mailPtr2 = mail;
                        mailPtr2->mailType = 6;
                        mainMenuPtr = GetMainMenu();
                        mainMenuPtr->unk3A = 1;
                        break;
                }
                break;
            default:
                break;
        }
        break;
    case 6:
        nextMenu =  UpdateRescuePasswordMenu_sub(MENU_WONDER_MAIL);
        break;
    case 7:
        switch(sub_80154F0())
        {
            case 3:
                nextMenu = PASSWORD_ENTRY_NOT_WONDER_MAIL;
                DisplayRescuePasswordError(nextMenu);
                gRescuePasswordMenu->state = 8;
                nextMenu = MENU_NO_SCREEN_CHANGE;
                break;
            case 0:
                nextMenu = MENU_NO_SCREEN_CHANGE;
                break;
            case 1:
                sub_8031E00();
                nextMenu = MENU_NO_SCREEN_CHANGE;
                break;
            default:
                break;
            case 2:
                nextMenu = MENU_WONDER_MAIL;
                break;
        }
        break;
    case 8:
        if (sub_8012FD8(&gRescuePasswordMenu->unk8[0]) == '\0') {
            sub_8013114(&gRescuePasswordMenu->unk8[0], &menuAction);
        }
        switch(menuAction)
        {
            default:
            case 0xD:
                break;
            case 0xA:
            case 0xC:
                sub_8039174();
                ResetUnusedInputStruct();
                sub_800641C(0,1,1);
                sub_80151C0(4,gRescuePasswordBuffer);
                gRescuePasswordMenu->state = 8;
                subtract = gRescuePasswordMenu->currMenu - 0x21;
                nextMenu = MENU_FRIEND_RESCUE;
                if (1 < subtract) break;
                nextMenu = MENU_WONDER_MAIL;
                break;
            case 11:
                gRescuePasswordMenu->state = 8;
                nextMenu = MENU_NO_SCREEN_CHANGE;
                sub_80391F8();
                break;
        }
        break;
    case 9:
        if (sub_8012FD8(&gRescuePasswordMenu->unk8[0]) == '\0') {
            sub_8013114(&gRescuePasswordMenu->unk8[0], &menuAction);
        }
        switch(menuAction)
        {
            default:
            case 0xD:
                break;
            case 0xA:
            case 0xC:
                sub_8039174();
                ResetUnusedInputStruct();
                sub_800641C(0,1,1);
                sub_80151C0(4,gRescuePasswordBuffer);
                gRescuePasswordMenu->state = ConvertMenutoRescuePasswordState(gRescuePasswordMenu->currMenu);
                subtract = gRescuePasswordMenu->currMenu - 0x21;
                nextMenu = 0x2a;
                if (subtract < 2) {
                    nextMenu = 0x2b;
                }
                break;
            case 0xB:
                 gRescuePasswordMenu->state = 9;
                 nextMenu = MENU_NO_SCREEN_CHANGE;
                 sub_80391F8();
                 break;
        }
    }
    return nextMenu;
}

void DisplayRescuePasswordError(u32 passwordError)
{
  sub_8006518(gRescuePasswordMenu->unk1A8);
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  sub_80155F0();
  switch(passwordError) {
    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E71FC,gUnknown_80E7214,0,0xd,0);
        break;
    case PASSWORD_ENTRY_NOT_SOS_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E72EC,gUnknown_80E7304,0,0xd,0);
        break;
    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E7344,gUnknown_80E735C,0,0xd,0);
        break;
    case PASSWORD_ENTRY_NO_SPACE:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E7588,gUnknown_80E75A0,0,0xd,0);
        break;
    case PASSWORD_ENTRY_NOT_AOK_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E73AC,gUnknown_80E73C4,0,0xd,0);
        break;
    case PASSWORD_ENTRY_DUPLICATE_AOK_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E7408,gUnknown_80E7420,0,0xd,0);
        break;
    case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E7468,gUnknown_80E7480,0,0xd,0);
        break;
    case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E74C8,gUnknown_80E74E0,0,0xd,0);
        break;
    case PASSWORD_ENTRY_NOT_WONDER_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E752C,gUnknown_80E7544,0,0xd,0);
        break;
    default:
        break;
  }
  sub_8035CF4(gRescuePasswordMenu->unk8,0,1);
}

void DisplayPasswordAcceptScreen(void)
{
  sub_8006518(gRescuePasswordMenu->unk1A8);
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  sub_80155F0();
  SetMenuItems(gRescuePasswordMenu->unk8,gRescuePasswordMenu->unk148,0,&gUnknown_80E7278,gUnknown_80E7290,0,0xd,0);
  sub_8035CF4(gRescuePasswordMenu->unk8,0,1);
}

u32 ConvertMenutoRescuePasswordState(u32 unused)
{
  u32 state;

  state = 0xb;
  switch(gRescuePasswordMenu->currMenu) {
    case 0x1b:
        state = 0;
        break;
    case 0x1f:
        state = 4;
        break;
    case 0x1d:
        state = 2;
        break;
    case MENU_DISPLAY_RESCUE_PASSWORD:
        state = 6;
        break;
    case 0x1c:
        state = 1;
        break;
    case 0x20:
        state = 5;
        break;
    case 0x1e:
        state = 3;
        break;
    case MENU_RESCUE_PASSWORD_ENTRY:
        state = 7;
        break;
  }
  return state;
}

u32 sub_8039068(u32 mailMode, u8 *passwordBuffer, struct unkStruct_203B480 *param_3)
{
  if ( (!sub_803D204(passwordBuffer, param_3)) || (WONDER_MAIL_TYPE_OKD < param_3->mailType) ||
       (param_3->dungeon.floor >= GetDungeonFloorCount(param_3->dungeon.id)) ||
       (param_3->clientSpecies == MONSTER_NONE) || (MONSTER_RAYQUAZA_CUTSCENE < param_3->clientSpecies) ||
       (IsInvalidItemReward(param_3->unk20.id))) {
        return PASSWORD_ENTRY_INCORRECT_PASSWORD;
  }
  else
  switch(mailMode)
  {
    case PASSWORD_ENTRY_SOS_MAIL_MODE:
        if (param_3->mailType != WONDER_MAIL_TYPE_SOS) {
            return PASSWORD_ENTRY_NOT_SOS_MAIL;
        }
        else if ( (HasMail(2, param_3->unk10.unk10)) || (HasMail(WONDER_MAIL_TYPE_AOK, param_3->unk10.unk10)) || (HasMail(WONDER_MAIL_TYPE_COMPLETED, param_3->unk10.unk10)) || (sub_8095298(param_3->unk10.unk10))) {
            return PASSWORD_ENTRY_DUPLICATE_SOS_MAIL;
        }
        else if (FindOpenMailSlot() == -1) {
            return PASSWORD_ENTRY_NO_SPACE;
        }
        else {
            return PASSWORD_ENTRY_SOS_MAIL_SUCCESS;
        }
        break;
    case PASSWORD_ENTRY_AOK_MAIL_MODE:
        if (param_3->mailType != WONDER_MAIL_TYPE_AOK) {
            return PASSWORD_ENTRY_NOT_AOK_MAIL;
        }
        else if (!HasMail(1, param_3->unk10.unk10)) {
            return PASSWORD_ENTRY_DUPLICATE_AOK_MAIL;
        }
        else {
            return PASSWORD_ENTRY_AOK_MAIL_SUCCESS;
        }
        break;
    case PASSWORD_ENTRY_THANK_YOU_MAIL_MODE:
        if (param_3->mailType != WONDER_MAIL_TYPE_THANK_YOU) {
            return PASSWORD_ENTRY_NOT_THANK_YOU_MAIL;
        }
        else if ((!HasMail(4, param_3->unk10.unk10)) || (param_3->unk28 != sub_8011C34())) {
            return PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL;
        }
        else {
            return PASSWORD_ENTRY_THANK_YOU_MAIL_SUCCESS;
        }
        break;
    default:
        return -1;
    }
}
