#include "global.h"
#include "globaldata.h"
#include "constants/main_menu.h"
#include "code_803D0D8.h"
#include "code_8094F88.h"
#include "dungeon.h"
#include "input.h"
#include "items.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "rescue_password_menu.h"
#include "save.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "naming_screen.h"

#define RESCUE_PASSWORD_SIZE 0x36

EWRAM_DATA s32 gCommsTimeout = {0};
EWRAM_DATA u8 gRescuePasswordBuffer[RESCUE_PASSWORD_SIZE] = {0};

extern unkStruct_203B484 *gUnknown_203B484;

EWRAM_INIT u8 gUnknown_203B368 = {1};
EWRAM_INIT u32 gUnknown_203B36C = {65502};
EWRAM_INIT struct RescuePasswordMenu *gRescuePasswordMenu = {NULL};

const WindowTemplate gUnknown_80E71E4 = {
    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E71FC = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 Error_80E7268[];
const u8 IncorrectPassword_80E7250[];
const u8 CheckAgain_80E7234[];

const MenuItem gUnknown_80E7214[4] = {
    {Error_80E7268, 0xC},
    {IncorrectPassword_80E7250, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 CheckAgain_80E7234[] = _("{CENTER_ALIGN}Please check it again.");
ALIGNED(4) const u8 IncorrectPassword_80E7250[] = _("{CENTER_ALIGN}Incorrect password!");
ALIGNED(4) const u8 Error_80E7268[] = _("{CENTER_ALIGN}{COLOR RED}Error!{RESET} ");

const WindowTemplate gUnknown_80E7278 = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 Success_80E72D8[];
const u8 PasswordAccept_80E72B4[];
const u8 DATA_80E72B0[];

const MenuItem gUnknown_80E7290[4] = {
    {Success_80E72D8, 0xC},
    {PasswordAccept_80E72B4, 0xC},
    {DATA_80E72B0, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 DATA_80E72B0[] = "  ";
ALIGNED(4) const u8 PasswordAccept_80E72B4[] = _("{CENTER_ALIGN}The password has been accepted.");
ALIGNED(4) const u8 Success_80E72D8[] = _("{CENTER_ALIGN}{COLOR CYAN_G}Success!{RESET} ");

const WindowTemplate gUnknown_80E72EC = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 NotSOSMail_80E7324[];

const MenuItem gUnknown_80E7304[4] = {
    {Error_80E7268, 0xC},
    {NotSOSMail_80E7324, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 NotSOSMail_80E7324[] = _("{CENTER_ALIGN}This is not an {COLOR CYAN_G}SOS Mail{RESET}.");

const WindowTemplate gUnknown_80E7344 = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 ReceiveSOSMail_80E737C[];

const MenuItem gUnknown_80E735C[4] = {
    {Error_80E7268, 0xC},
    {ReceiveSOSMail_80E737C, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 ReceiveSOSMail_80E737C[] = _("{CENTER_ALIGN}This {COLOR CYAN_G}SOS Mail{RESET} has been received already.");

const WindowTemplate gUnknown_80E73AC = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E73E4[];

const MenuItem gUnknown_80E73C4[4] = {
    {Error_80E7268, 0xC},
    {sUnknown_80E73E4, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 sUnknown_80E73E4[] = _("{CENTER_ALIGN}This is not an {COLOR CYAN_G}A-OK Mail{RESET}.");

const WindowTemplate gUnknown_80E7408 = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E7440[];

const MenuItem gUnknown_80E7420[4] = {
    {Error_80E7268, 0xC},
    {sUnknown_80E7440, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 sUnknown_80E7440[] = _("{CENTER_ALIGN}This {COLOR CYAN_G}A-OK Mail{RESET} cannot be used.");

const WindowTemplate gUnknown_80E7468 = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E74A0[];

const MenuItem gUnknown_80E7480[4] = {
    {Error_80E7268, 0xC},
    {sUnknown_80E74A0, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};
ALIGNED(4) const u8 sUnknown_80E74A0[] = _("{CENTER_ALIGN}This is not a {COLOR CYAN_G}Thank-You Mail{RESET}.");

const WindowTemplate gUnknown_80E74C8 = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E7500[];

const MenuItem gUnknown_80E74E0[4] = {
    {Error_80E7268, 0xC},
    {sUnknown_80E7500, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};

ALIGNED(4) const u8 sUnknown_80E7500[] = _("{CENTER_ALIGN}This {COLOR CYAN_G}Thank-You Mail{RESET} cannot be used.");

const WindowTemplate gUnknown_80E752C = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E7564[];

const MenuItem gUnknown_80E7544[4] = {
    {Error_80E7268, 0xC},
    {sUnknown_80E7564, 0xC},
    {CheckAgain_80E7234, 0xC},
    {NULL, 0xA},
};
ALIGNED(4) const u8 sUnknown_80E7564[] = _("{CENTER_ALIGN}This is not a {COLOR CYAN_G}Wonder Mail{RESET}.");

const WindowTemplate gUnknown_80E7588 = {
    0,
    0x03,
    0x03, 0x09,
    0x17, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E75C0[];
const u8 sUnknown_80E75CC[];
const MenuItem gUnknown_80E75A0[4] = {
    {Error_80E7268, 0xC},
    {sUnknown_80E75CC, 0xC},
    {sUnknown_80E75C0, 0xC},
    {NULL, 0xA},
};
ALIGNED(4) const u8 sUnknown_80E75C0[] = _("{CENTER_ALIGN}new mail.");
ALIGNED(4) const u8 sUnknown_80E75CC[] = _("{CENTER_ALIGN}There is no space for receiving");

extern void sub_8031D70(u32, u32);
extern void sub_8031E10(void);
extern u32 sub_8031DCC(void);
extern void sub_8031E00(void);

void DisplayRescuePasswordError(u32 error);
void sub_8039174(void);
void DisplayPasswordAcceptScreen(void);
u32 sub_8039068(u32, u8 *passwordBuffer, unkStruct_203B480 *r0);
void sub_80391F8(void);
u32 ConvertMenutoRescuePasswordState(u32);

void CreateRescuePasswordMenu(u32 currMenu)
{
    unkStruct_203B480 *temp;
    s32 counter;

    if(gRescuePasswordMenu == NULL)
    {
        gRescuePasswordMenu = MemoryAlloc(sizeof(struct RescuePasswordMenu), 8);
        MemoryFill8(gRescuePasswordMenu, 0, sizeof(struct RescuePasswordMenu));
    }

    for(counter = 0; counter < 4; counter++)
        gRescuePasswordMenu->unk148.id[counter] = gUnknown_80E71E4;

    ResetUnusedInputStruct();
    ShowWindows(&gRescuePasswordMenu->unk148, TRUE, TRUE);

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
            NamingScreen_Init(4, gRescuePasswordBuffer);
            break;
        case MENU_DISPLAY_RESCUE_PASSWORD:
            temp = GetMailatIndex(0x1F);
            MemoryFill8(temp, 0, sizeof(unkStruct_203B480));
            temp->mailType = 2;
            temp->item.id = ITEM_NOTHING;
            sub_8031D70(0x1F, 0);
            break;
        case MENU_RESCUE_PASSWORD_ENTRY:
            NamingScreen_Init(4, gRescuePasswordBuffer);
            break;
    }

    gRescuePasswordMenu->state = ConvertMenutoRescuePasswordState(currMenu);
    sub_8039174();
}

void CleanRescuePasswordMenu(void)
{

  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  if (gRescuePasswordMenu != NULL) {
    NamingScreen_Free();
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
  unkStruct_203B480 *mailPtr1;
  unkStruct_203B480 *mailPtr2;
  u32 iVar7;
  MainMenu1Work *mainMenuPtr;
  s32 nextMenu;
  unkStruct_203B480 mail;
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
        iVar7 = NamingScreen_HandleInput();
        MemoryFill8(&mail, 0, sizeof(unkStruct_203B480));
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
                        MemoryFill8(&gUnknown_203B484, 0, sizeof(unkStruct_203B484));
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
        switch(NamingScreen_HandleInput())
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
        if (!sub_8012FD8(&gRescuePasswordMenu->unk8[0])) {
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
                ShowWindows(NULL, TRUE, TRUE);
                NamingScreen_Init(4,gRescuePasswordBuffer);
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
        if (!sub_8012FD8(&gRescuePasswordMenu->unk8[0])) {
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
                ShowWindows(NULL, TRUE, TRUE);
                NamingScreen_Init(4,gRescuePasswordBuffer);
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
  RestoreSavedWindows(&gRescuePasswordMenu->unk1A8);
  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  NamingScreen_Free();
  switch(passwordError) {
    case PASSWORD_ENTRY_INCORRECT_PASSWORD:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E71FC,gUnknown_80E7214,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_NOT_SOS_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E72EC,gUnknown_80E7304,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_DUPLICATE_SOS_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E7344,gUnknown_80E735C,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_NO_SPACE:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E7588,gUnknown_80E75A0,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_NOT_AOK_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E73AC,gUnknown_80E73C4,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_DUPLICATE_AOK_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E7408,gUnknown_80E7420,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_NOT_THANK_YOU_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E7468,gUnknown_80E7480,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_DUPLICATE_THANK_YOU_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E74C8,gUnknown_80E74E0,FALSE,13,FALSE);
        break;
    case PASSWORD_ENTRY_NOT_WONDER_MAIL:
        SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E752C,gUnknown_80E7544,FALSE,13,FALSE);
        break;
    default:
        break;
  }
  sub_8035CF4(gRescuePasswordMenu->unk8,0,TRUE);
}

void DisplayPasswordAcceptScreen(void)
{
  RestoreSavedWindows(&gRescuePasswordMenu->unk1A8);
  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  NamingScreen_Free();
  SetMenuItems(gRescuePasswordMenu->unk8,&gRescuePasswordMenu->unk148,0,&gUnknown_80E7278,gUnknown_80E7290,FALSE,13,FALSE);
  sub_8035CF4(gRescuePasswordMenu->unk8,0,TRUE);
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

u32 sub_8039068(u32 mailMode, u8 *passwordBuffer, unkStruct_203B480 *param_3)
{
  if ( (!sub_803D204(passwordBuffer, param_3)) || (WONDER_MAIL_TYPE_OKD < param_3->mailType) ||
       (param_3->unk4.dungeon.floor >= GetDungeonFloorCount(param_3->unk4.dungeon.id)) ||
       (param_3->clientSpecies == MONSTER_NONE) || (MONSTER_MAX - 1 < param_3->clientSpecies) ||
       (IsInvalidItemReward(param_3->item.id))) {
        return PASSWORD_ENTRY_INCORRECT_PASSWORD;
  }
  else
  switch(mailMode)
  {
    case PASSWORD_ENTRY_SOS_MAIL_MODE:
        if (param_3->mailType != WONDER_MAIL_TYPE_SOS) {
            return PASSWORD_ENTRY_NOT_SOS_MAIL;
        }
        else if ( (HasMail(WONDER_MAIL_TYPE_SOS_1, param_3->unk10.unk10)) || (HasMail(WONDER_MAIL_TYPE_AOK, param_3->unk10.unk10)) || (HasMail(WONDER_MAIL_TYPE_COMPLETED, param_3->unk10.unk10)) || (sub_8095298(param_3->unk10.unk10))) {
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

void sub_8039174(void)
{
    SpriteSetAffine1(&gRescuePasswordMenu->unk208, 0);
    SpriteSetAffine2(&gRescuePasswordMenu->unk208, 0);
    SpriteSetObjMode(&gRescuePasswordMenu->unk208, 0);
    SpriteSetMosaic(&gRescuePasswordMenu->unk208, 0);
    SpriteSetBpp(&gRescuePasswordMenu->unk208, 0);
    SpriteSetShape(&gRescuePasswordMenu->unk208, 1);
    SpriteSetTileNum(&gRescuePasswordMenu->unk208, 0x3F0);
    SpriteSetPriority(&gRescuePasswordMenu->unk208, 0);
    SpriteSetPalNum(&gRescuePasswordMenu->unk208, 15);
    SpriteSetMatrixNum(&gRescuePasswordMenu->unk208, 0);
    SpriteSetSize(&gRescuePasswordMenu->unk208, 0);

    SpriteSetX(&gRescuePasswordMenu->unk208, 0);
    SpriteSetY(&gRescuePasswordMenu->unk208, 192);
}

void sub_80391F8(void)
{
    SpriteSetX(&gRescuePasswordMenu->unk208, 112);
    SpriteSetY(&gRescuePasswordMenu->unk208, 112);

    if (gRescuePasswordMenu->unk210 & 8)
        AddSprite(&gRescuePasswordMenu->unk208, 0x100, NULL, NULL);

    DrawDialogueBoxString();
    gRescuePasswordMenu->unk210++;
}
