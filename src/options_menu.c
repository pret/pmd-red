#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_8098BDC.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "game_options.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

struct unkStruct_203B25C
{
    // size: 0x11C
    u32 state;
    u32 chosenHintIndex;
    GameOptions newOptions;
    u32 menuAction;
    MenuStruct menu;
    MenuItem menuItems[8];
    u16 unkAC[8];
    UnkTextStruct2 unkBC[4];
};

struct unkStruct_203B260  
{ 
    GameOptions *optionsMenu;
    MenuInputStructSub unk4;
    MenuInputStruct input;
    u32 unk44;
    UnkTextStruct2 * unk48;
    UnkTextStruct2 unk4C[4];
};
struct unkStruct_203B260  *gUnknown_203B260;
extern GameOptions *gGameOptionsRef;
extern struct unkStruct_203B25C *gUnknown_203B25C;

extern const UnkTextStruct2 gUnknown_80DBFB0;
extern const UnkTextStruct2 gUnknown_80DBFCC;
extern const UnkTextStruct2 gUnknown_80DC020;
extern const UnkTextStruct2 gUnknown_80DC03C;

extern u8 gWindowBGTitle[];
extern u8 gUnknown_80DC064[];
extern u8 gWindowBGGreenString[];
extern u8 gWindowBGRedString[];
extern u8 gWindowBGBlueString[];

extern const char gOthers_MenuOption[];
extern const char gUnknown_80DBFEC[];
extern const char gOthers_GameOptions[];
extern const char gOthers_Hints[];
extern const char *gCommonYes[];
extern const char *gCommonNo[];

extern s32 sub_8008ED0(u8 *);
extern void CreateOthersMenu(void);
void CreateOptionsMenu(void);
void nullsub_38(void);
extern void SetOptionsMenuState(u32);
extern void HandleOthersMenu();
extern void sub_801E088();
extern void sub_801E0E0();
extern void sub_801E0FC();
extern void HandleChangeSettingsMenu();
extern void sub_801DD84();
extern void sub_801DED0();
extern bool8 sub_801E198(GameOptions *);
extern void CreateHintDisplayScreen(u32);
extern void sub_801E3F0(u32);
extern void CreateHintSelectionScreen(u32);
extern void CreateChangeSettingsConfirmMenu(void);
extern u32 sub_801E474(u32);
extern u32 GetChosenHintIndex(void);
extern void sub_801E54C(void);
extern u32 HandleHintDisplayScreenInput(void);
extern void DestroyHintDisplayScreen(void);
extern u32 sub_801E218(void);
extern void sub_801E2C4(void);
extern void SetWindowBGColor(void);

enum 
{
    MENU_OPTION_DEFAULT = 1,
    MENU_OPTION_HINTS,
    MENU_OPTION_GAMEOPTIONS,
    MENU_OPTION_YES,
    MENU_OPTION_NO
};

enum OptionsMenuStates {
    OPTIONS_MENU_INIT,
    OPTIONS_MENU_MAIN,
    OPTIONS_MENU_EXIT,
    OPTIONS_MENU_PRE_HINT_SELECTION,
    OPTIONS_MENU_HINT_SELECTION,
    OPTIONS_MENU_DISPLAY_HINT,
    OPTIONS_MENU_UNKNOWN_6,
    OPTIONS_MENU_CONFIRM_NEW_OPTIONS,
};

u32 sub_801DCC4(void)
{
    gUnknown_203B25C = MemoryAlloc(sizeof(struct unkStruct_203B25C), 8);
    SetOptionsMenuState(OPTIONS_MENU_INIT);
    return 1;
}

u32 sub_801DCE8(void)
{
    switch(gUnknown_203B25C->state)
    {
        case OPTIONS_MENU_EXIT:
            return 3;
        case OPTIONS_MENU_INIT:
        case OPTIONS_MENU_MAIN:
            HandleOthersMenu();
            break;
        case OPTIONS_MENU_PRE_HINT_SELECTION:
        case OPTIONS_MENU_HINT_SELECTION:
            sub_801E088();
            break;
        case OPTIONS_MENU_DISPLAY_HINT:
            sub_801E0E0();
            break;
        case 6:
            sub_801E0FC();
            break;
        case OPTIONS_MENU_CONFIRM_NEW_OPTIONS:
            HandleChangeSettingsMenu();
            break;
        default:
            break;
    }
    return 0;
}

void sub_801DD50(void)
{
    if(gUnknown_203B25C != NULL)
    {
        MemoryFree(gUnknown_203B25C);
        gUnknown_203B25C = NULL;
    }
}

void SetOptionsMenuState(u32 newState)
{
    gUnknown_203B25C->state = newState;
    sub_801DD84();
    sub_801DED0();
}

void sub_801DD84(void)
{
    s32 index;
    sub_8006518(gUnknown_203B25C->unkBC);
    switch(gUnknown_203B25C->state)
    {
        case OPTIONS_MENU_INIT:
            CreateOthersMenu();
            for(index = 0; index < 8; index++)
            {
                if(gUnknown_203B25C->unkAC[index] == 0)
                {
                    gUnknown_203B25C->menuAction = gUnknown_203B25C->menuItems[index].menuAction;
                    break;
                }
            }
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B25C->unkBC[index] = gUnknown_80DBFB0;
            }
            gUnknown_203B25C->unkBC[0] = gUnknown_80DBFCC;
            sub_8012CAC(&gUnknown_203B25C->unkBC[0], gUnknown_203B25C->menuItems);
            gUnknown_203B25C->unkBC[0].unkC = 0xA;
            break;
        case OPTIONS_MENU_MAIN:
            CreateOthersMenu();
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B25C->unkBC[index] = gUnknown_80DBFB0;
            }
            gUnknown_203B25C->unkBC[0] = gUnknown_80DBFCC;
            sub_8012CAC(&gUnknown_203B25C->unkBC[0], gUnknown_203B25C->menuItems);
            gUnknown_203B25C->unkBC[0].unkC = 0xA;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B25C->unkBC[index] = gUnknown_80DBFB0;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B25C->unkBC, TRUE, TRUE);
}

void sub_801DED0(void)
{
  switch(gUnknown_203B25C->state) {
    case OPTIONS_MENU_INIT:
    case OPTIONS_MENU_MAIN:
        gUnknown_203B25C->menu.unk0 = gOthers_MenuOption;
        sub_8012D60(&gUnknown_203B25C->menu,gUnknown_203B25C->menuItems,0,gUnknown_203B25C->unkAC,gUnknown_203B25C->menuAction,0);
        break;
    case OPTIONS_MENU_PRE_HINT_SELECTION:
        sub_801E3F0(0);
        break;
    case OPTIONS_MENU_HINT_SELECTION:
        CreateHintSelectionScreen(1);
        break;
    case OPTIONS_MENU_DISPLAY_HINT:
        CreateHintDisplayScreen(gUnknown_203B25C->chosenHintIndex);
        break;
    case 6:
        // Load our current options?
        gUnknown_203B25C->newOptions = *gGameOptionsRef;
        sub_801E198(&gUnknown_203B25C->newOptions);
        break;
    case OPTIONS_MENU_CONFIRM_NEW_OPTIONS:
        CreateChangeSettingsConfirmMenu();
        // Change settings?
        sub_8014248(gUnknown_80DBFEC,0,4,gUnknown_203B25C->menuItems,0,4,0,0,0x20);
        break;
  }
}

void CreateOthersMenu(void)
{
  s32 loopMax;
  
  MemoryFill16(gUnknown_203B25C->unkAC,0,sizeof(gUnknown_203B25C->unkAC));

  loopMax = 0;

  gUnknown_203B25C->menuItems[loopMax].text = gOthers_GameOptions;
  gUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_GAMEOPTIONS;
  loopMax += 1;
  gUnknown_203B25C->menuItems[loopMax].text = gOthers_Hints;
  gUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_HINTS;
  loopMax += 1;
  gUnknown_203B25C->menuItems[loopMax].text = NULL;
  gUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_DEFAULT;
}

void CreateChangeSettingsConfirmMenu(void)
{
  s32 loopMax;

  MemoryFill16(gUnknown_203B25C->unkAC,0,sizeof(gUnknown_203B25C->unkAC));
  loopMax = 0;

  gUnknown_203B25C->menuItems[loopMax].text = *gCommonYes;
  gUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_YES;
  loopMax += 1;
  gUnknown_203B25C->menuItems[loopMax].text = *gCommonNo;
  gUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_NO;
  loopMax += 1;
  gUnknown_203B25C->menuItems[loopMax].text = NULL;
  gUnknown_203B25C->menuItems[loopMax].menuAction = MENU_OPTION_DEFAULT;
}

void HandleOthersMenu(void)
{
  s32 menuAction;
  
  menuAction = 0;
  if (sub_8012FD8(&gUnknown_203B25C->menu) == '\0') {
    sub_8013114(&gUnknown_203B25C->menu,&menuAction);
    gUnknown_203B25C->menuAction = menuAction;
  }
  switch(menuAction)
  {
    case MENU_OPTION_HINTS:
        SetOptionsMenuState(OPTIONS_MENU_PRE_HINT_SELECTION);
        break;
    case MENU_OPTION_GAMEOPTIONS:
        SetOptionsMenuState(6);
        break;
    case MENU_OPTION_DEFAULT:
        SetOptionsMenuState(OPTIONS_MENU_EXIT);
        break;
  }
}

void sub_801E088(void)
{

  switch(sub_801E474(1)) 
  {
    case 3:
    case 4:
        gUnknown_203B25C->chosenHintIndex = GetChosenHintIndex();
        SetOptionsMenuState(OPTIONS_MENU_DISPLAY_HINT);
        break;
    case 2:
        sub_801E54C();
        SetOptionsMenuState(OPTIONS_MENU_MAIN);
        break;
    case 0:
    case 1:
    default:
        break;
  }
}


void sub_801E0E0(void)
{
  switch(HandleHintDisplayScreenInput())
  {
    case 3:
    case 2:
        DestroyHintDisplayScreen();
        SetOptionsMenuState(OPTIONS_MENU_HINT_SELECTION);
        break;
    case 0:
    case 1:
    default:
        break;
  }
}

void sub_801E0FC(void)
{
  switch(sub_801E218())
  {
    case 2: 
    case 3:
        sub_801E2C4();
        // Check to see if the options changed?
        if (GameOptionsNotChange(&gUnknown_203B25C->newOptions)) {
            SetOptionsMenuState(OPTIONS_MENU_MAIN);
        }
        else {
            SetOptionsMenuState(OPTIONS_MENU_CONFIRM_NEW_OPTIONS);
        }
        break;
    case 0:
    case 1:
        break;
  }
}

void HandleChangeSettingsMenu(void)
{
  s32 menuAction;
  
  if (sub_80144A4(&menuAction) == 0) 
  {
    switch(menuAction)
    {
        case MENU_OPTION_YES:
            // Save our option changes??
            *gGameOptionsRef = gUnknown_203B25C->newOptions;
            SetWindowBGColor();
            sub_8099690(0);
            SetOptionsMenuState(OPTIONS_MENU_MAIN);
            break;
        case MENU_OPTION_DEFAULT:
        case MENU_OPTION_NO:
            SetOptionsMenuState(OPTIONS_MENU_MAIN);
            break;
    }
  }
}

bool8 sub_801E198(GameOptions *optionsMenu)
{
  gUnknown_203B260 = MemoryAlloc(sizeof(struct unkStruct_203B260), 8);
  gUnknown_203B260->optionsMenu = optionsMenu;
  sub_801317C(&gUnknown_203B260->unk4);
  gUnknown_203B260->unk44 = 0;
  gUnknown_203B260->unk48 = &gUnknown_203B260->unk4C[0];
  sub_8006518(gUnknown_203B260->unk4C);
  gUnknown_203B260->unk4C[gUnknown_203B260->unk44] = gUnknown_80DC03C;
  sub_8012D08(gUnknown_203B260->unk48,1);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B260->unk4C, TRUE, TRUE);
  sub_8013818(&gUnknown_203B260->input,1,1,gUnknown_203B260->unk44);
  nullsub_38();
  CreateOptionsMenu();
  return TRUE;
}

u32 sub_801E218(void)
{
    bool32 flag;

    flag = FALSE;

    switch(sub_8012AE8())
    {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_DPAD_LEFT:
            if (gUnknown_203B260->input.menuIndex == 0)
            {
                if (gUnknown_203B260->optionsMenu->windowColor == WINDOW_COLOR_BLUE) {
                    gUnknown_203B260->optionsMenu->windowColor = WINDOW_COLOR_GREEN;
                }
                else {
                    gUnknown_203B260->optionsMenu->windowColor--;
                }
                PlayMenuSoundEffect(3);
                flag = TRUE;
            }
            break;
        case INPUT_DPAD_RIGHT:
            if(gUnknown_203B260->input.menuIndex == 0)
            {
                if (gUnknown_203B260->optionsMenu->windowColor > WINDOW_COLOR_RED) {
                    gUnknown_203B260->optionsMenu->windowColor = WINDOW_COLOR_BLUE;
                }
                else
                    gUnknown_203B260->optionsMenu->windowColor++;
                PlayMenuSoundEffect(3);
                flag = TRUE;
            }
            break;
    }

    // == 1 is needed for matching
    if ((sub_80138B8(&gUnknown_203B260->input,1) != 0) || (flag == TRUE)) {
        nullsub_38();
        CreateOptionsMenu();
        return 1;
    }
    else {
        return 0;
    }
}

void sub_801E2C4(void)
{
    if(gUnknown_203B260 != NULL)
    {
        gUnknown_203B260->unk4C[gUnknown_203B260->unk44] = gUnknown_80DC020;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B260->unk4C, TRUE, TRUE);
        MemoryFree(gUnknown_203B260);
        gUnknown_203B260 = NULL;
    }
}


void nullsub_38(void)
{
    
}

void CreateOptionsMenu(void)
{
  u32 length;
  u32 y;
  
  sub_8008C54(gUnknown_203B260->unk44);
  sub_80073B8(gUnknown_203B260->unk44);
  xxx_call_draw_string(0x10,0,gWindowBGTitle,gUnknown_203B260->unk44,0);
  y = sub_8013800(&gUnknown_203B260->input,0);
  xxx_call_draw_string(8,y,gUnknown_80DC064,gUnknown_203B260->unk44,0);

  switch(gUnknown_203B260->optionsMenu->windowColor)
  {
      case WINDOW_COLOR_BLUE:
        length = sub_8008ED0(gWindowBGBlueString);
        sub_80078A4(gUnknown_203B260->unk44,gUnknown_203B260->optionsMenu->windowColor * 0x28 + 0x50,
              y + 0xA,length,COLOR_WHITE_2);
        break;
      case WINDOW_COLOR_RED:
        length = sub_8008ED0(gWindowBGRedString);
        sub_80078A4(gUnknown_203B260->unk44,gUnknown_203B260->optionsMenu->windowColor * 0x28 + 0x50,
              y + 0xA,length,COLOR_WHITE_2);
        break;
      case WINDOW_COLOR_GREEN:
        length = sub_8008ED0(gWindowBGGreenString);
        sub_80078A4(gUnknown_203B260->unk44,gUnknown_203B260->optionsMenu->windowColor * 0x28 + 0x50,
              y + 0xA,length,COLOR_WHITE_2);
        break;
  }
  sub_80073E0(gUnknown_203B260->unk44);
}
