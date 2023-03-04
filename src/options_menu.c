#include "global.h"
#include "constants/input.h"
#include "input.h"
#include "memory.h"
#include "text.h"
#include "game_options.h"
#include "menu_input.h"

struct unkStruct_203B260  
{ 
    struct GameOptions *optionsMenu;           
    u32 unk4;           
    u8  unk8;           
    u8 fill9[0x10 - 0x9];
    u32 unk10;        
    u8 fill14[0x28 - 0x14];
    s16 unk28;        
    u8 fill2A[0x44 - 0x2A];
    u32 unk44;        
    struct UnkTextStruct2 * unk48;        
    struct UnkTextStruct2 unk4C[4];        
};
struct unkStruct_203B260  *gUnknown_203B260;
extern struct UnkTextStruct2 gUnknown_80DC020;
extern struct UnkTextStruct2 gUnknown_80DC03C;

extern u8 gWindowBGTitle[];
extern u8 gUnknown_80DC064[];
extern u8 gWindowBGGreenString[];
extern u8 gWindowBGRedString[];
extern u8 gWindowBGBlueString[];

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void xxx_call_draw_string(u32, u32, u8 *, u32, u32);
extern s32 sub_8008ED0(u8 *);
extern s32 sub_8013800(u32 *, u32);
extern void sub_80078A4(u32, u32, u32, u32, u32);
extern u8 sub_80138B8(u32 *, u32);
void PlayMenuSoundEffect(u32);
s32 sub_8012AE8(void);
void sub_801317C(u32 *);
extern void sub_8013818(void *, u32, u32, u32);

void CreateOptionsMenu(void);
void nullsub_38(void);

struct unkStruct_203B25C
{
    // size: 0x11C
    u32 state;
    u32 chosenHintIndex;
    struct GameOptions newOptions;
    u32 unk18;
    struct MenuStruct unk1C;
    struct MenuItem menuItems[8];
    u16 unkAC[8];
    struct UnkTextStruct2 unkBC[4];
};


extern void sub_801DD6C(u32);

extern void HandleOthersMenu();
extern void sub_801E088();
extern void sub_801E0E0();
extern void sub_801E0FC();
extern void HandleChangeSettingsMenu();
extern void sub_801DD84();
extern void sub_801DED0();
extern bool8 sub_801E198(struct GameOptions *);
extern void sub_8014248(const char *, u32, u32, struct MenuItem *, u32, u32, u32, u32, u32);
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
extern s32 sub_80144A4(s32 *);
extern void SetWindowBGColor(void);
extern void sub_8099690(u32);

extern struct GameOptions *gGameOptionsRef;
extern struct unkStruct_203B25C *gUnknown_203B25C;
extern const struct UnkTextStruct2 gUnknown_80DBFCC;
extern const struct UnkTextStruct2 gUnknown_80DBFB0;

extern const char gOthers_MenuOption[];
extern const char gUnknown_80DBFEC[];
extern const char gOthers_GameOptions[];
extern const char gOthers_Hints[];
extern const char *gUnknown_80D4920[];
extern const char *gUnknown_80D4928[];


enum 
{
    MENU_OPTION_DEFAULT = 1,
    MENU_OPTION_HINTS,
    MENU_OPTION_GAMEOPTIONS,
    MENU_OPTION_YES,
    MENU_OPTION_NO
};

u32 sub_801DCC4(void)
{
    gUnknown_203B25C = MemoryAlloc(sizeof(struct unkStruct_203B25C), 8);
    sub_801DD6C(0);
    return 1;
}

u32 sub_801DCE8(void)
{
    switch(gUnknown_203B25C->state)
    {
        case 2:
            return 3;
        case 0:
        case 1:
            HandleOthersMenu();
            break;
        case 3:
        case 4:
            sub_801E088();
            break;
        case 5:
            sub_801E0E0();
            break;
        case 6:
            sub_801E0FC();
            break;
        case 7:
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

void sub_801DD6C(u32 newState)
{
    gUnknown_203B25C->state = newState;
    sub_801DD84();
    sub_801DED0();
}

#ifdef NONMATCHING
void sub_801DD84(void)
{
    s32 iVar3;
    sub_8006518(gUnknown_203B25C->unkBC);
    switch(gUnknown_203B25C->state)
    {
        case 0:
            CreateOthersMenu();
            // TODO probably could be cleaned up to actually match
            iVar3 = 0;
            if (gUnknown_203B25C->unkAC[iVar3] == 0) {
                gUnknown_203B25C->unk18 = gUnknown_203B25C->menuItems[iVar3].menuAction;
            }
            else {
                do {
                    iVar3++;
                    if(iVar3 > 7)
                        break;
                    if(gUnknown_203B25C->unkAC[iVar3] == 0){
                        gUnknown_203B25C->unk18 = gUnknown_203B25C->menuItems[iVar3].menuAction;
                        break;
                    }
                } while (iVar3 < 8);
            }
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B25C->unkBC[iVar3] = gUnknown_80DBFCC;
            }
            gUnknown_203B25C->unkBC[0] = gUnknown_80DBFB0;
            sub_8012CAC(&gUnknown_203B25C->unkBC[0], gUnknown_203B25C->menuItems);
            gUnknown_203B25C->unkBC[0].unk0c = 0xA;
            break;
        case 1:
            CreateOthersMenu();
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B25C->unkBC[iVar3] = gUnknown_80DBFB0;
            }
            gUnknown_203B25C->unkBC[0] = gUnknown_80DBFCC;
            sub_8012CAC(&gUnknown_203B25C->unkBC[0], gUnknown_203B25C->menuItems);
            gUnknown_203B25C->unkBC[0].unk0c = 0xA;
            break;
        default:
            for(iVar3 = 0; iVar3 < 4; iVar3++)
            {
                gUnknown_203B25C->unkBC[iVar3] = gUnknown_80DBFB0;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B25C->unkBC, 1, 1);
}
#else
NAKED
void sub_801DD84(void)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r9\n"
	"\tmov r6, r8\n"
	"\tpush {r6,r7}\n"
	"\tldr r4, _0801DDAC\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0xBC\n"
	"\tbl sub_8006518\n"
	"\tldr r0, [r4]\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0801DDB4\n"
	"\tcmp r0, 0x1\n"
	"\tbeq _0801DE38\n"
	"\tmovs r3, 0\n"
	"\tadds r7, r4, 0\n"
	"\tldr r2, _0801DDB0\n"
	"\tb _0801DE90\n"
	"\t.align 2, 0\n"
"_0801DDAC: .4byte gUnknown_203B25C\n"
"_0801DDB0: .4byte gUnknown_80DBFB0\n"
"_0801DDB4:\n"
	"\tbl CreateOthersMenu\n"
	"\tmovs r3, 0\n"
	"\tldr r1, [r4]\n"
	"\tadds r0, r1, 0\n"
	"\tadds r0, 0xAC\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbne _0801DDCE\n"
	"\tldr r0, [r1, 0x70]\n"
	"\tstr r0, [r1, 0x18]\n"
	"\tadds r7, r4, 0\n"
	"\tb _0801DDF2\n"
"_0801DDCE:\n"
	"\tadds r3, 0x1\n"
	"\tldr r7, _0801DE2C\n"
	"\tcmp r3, 0x7\n"
	"\tbgt _0801DDF2\n"
	"\tldr r2, [r7]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r1, r2, 0\n"
	"\tadds r1, 0xAC\n"
	"\tadds r1, r0\n"
	"\tldrh r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbne _0801DDCE\n"
	"\tlsls r0, r3, 3\n"
	"\tadds r1, r2, 0\n"
	"\tadds r1, 0x70\n"
	"\tadds r1, r0\n"
	"\tldr r0, [r1]\n"
	"\tstr r0, [r2, 0x18]\n"
"_0801DDF2:\n"
	"\tldr r0, _0801DE30\n"
	"\tmov r9, r0\n"
	"\tldr r2, _0801DE2C\n"
	"\tmov r12, r2\n"
	"\tldr r3, _0801DE34\n"
	"\tmov r8, r3\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x3\n"
"_0801DE02:\n"
	"\tmov r4, r12\n"
	"\tldr r1, [r4]\n"
	"\tadds r1, r2\n"
	"\tadds r1, 0xBC\n"
	"\tmov r0, r8\n"
	"\tldm r0!, {r4-r6}\n"
	"\tstm r1!, {r4-r6}\n"
	"\tldm r0!, {r4-r6}\n"
	"\tstm r1!, {r4-r6}\n"
	"\tadds r2, 0x18\n"
	"\tsubs r3, 0x1\n"
	"\tcmp r3, 0\n"
	"\tbge _0801DE02\n"
	"\tldr r1, [r7]\n"
	"\tadds r1, 0xBC\n"
	"\tmov r0, r9\n"
	"\tldm r0!, {r2,r5,r6}\n"
	"\tstm r1!, {r2,r5,r6}\n"
	"\tldm r0!, {r3-r5}\n"
	"\tstm r1!, {r3-r5}\n"
	"\tb _0801DE70\n"
	"\t.align 2, 0\n"
"_0801DE2C: .4byte gUnknown_203B25C\n"
"_0801DE30: .4byte gUnknown_80DBFCC\n"
"_0801DE34: .4byte gUnknown_80DBFB0\n"
"_0801DE38:\n"
	"\tbl CreateOthersMenu\n"
	"\tmov r8, r4\n"
	"\tldr r6, _0801DE88\n"
	"\tmov r12, r6\n"
	"\tmov r7, r8\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x3\n"
"_0801DE48:\n"
	"\tmov r0, r8\n"
	"\tldr r1, [r0]\n"
	"\tadds r1, r2\n"
	"\tadds r1, 0xBC\n"
	"\tmov r0, r12\n"
	"\tldm r0!, {r4-r6}\n"
	"\tstm r1!, {r4-r6}\n"
	"\tldm r0!, {r4-r6}\n"
	"\tstm r1!, {r4-r6}\n"
	"\tadds r2, 0x18\n"
	"\tsubs r3, 0x1\n"
	"\tcmp r3, 0\n"
	"\tbge _0801DE48\n"
	"\tldr r1, [r7]\n"
	"\tadds r1, 0xBC\n"
	"\tldr r0, _0801DE8C\n"
	"\tldm r0!, {r2-r4}\n"
	"\tstm r1!, {r2-r4}\n"
	"\tldm r0!, {r2,r5,r6}\n"
	"\tstm r1!, {r2,r5,r6}\n"
"_0801DE70:\n"
	"\tldr r1, [r7]\n"
	"\tadds r0, r1, 0\n"
	"\tadds r0, 0xBC\n"
	"\tadds r1, 0x6C\n"
	"\tbl sub_8012CAC\n"
	"\tldr r0, [r7]\n"
	"\tadds r0, 0xC8\n"
	"\tmovs r1, 0xA\n"
	"\tstrh r1, [r0]\n"
	"\tb _0801DEAC\n"
	"\t.align 2, 0\n"
"_0801DE88: .4byte gUnknown_80DBFB0\n"
"_0801DE8C: .4byte gUnknown_80DBFCC\n"
"_0801DE90:\n"
	"\tldr r0, [r7]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r0, r1\n"
	"\tadds r0, 0xBC\n"
	"\tadds r1, r2, 0\n"
	"\tldm r1!, {r4-r6}\n"
	"\tstm r0!, {r4-r6}\n"
	"\tldm r1!, {r4-r6}\n"
	"\tstm r0!, {r4-r6}\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0x3\n"
	"\tble _0801DE90\n"
"_0801DEAC:\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, _0801DECC\n"
	"\tldr r0, [r0]\n"
	"\tadds r0, 0xBC\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r3,r4}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801DECC: .4byte gUnknown_203B25C");
}
#endif

void sub_801DED0(void)
{
  switch(gUnknown_203B25C->state) {
    case 0:
    case 1:
        gUnknown_203B25C->unk1C.unk0 = gOthers_MenuOption;
        sub_8012D60(&gUnknown_203B25C->unk1C,gUnknown_203B25C->menuItems,0,gUnknown_203B25C->unkAC,gUnknown_203B25C->unk18,0);
        break;
    case 3:
        sub_801E3F0(0);
        break;
    case 4:
        CreateHintSelectionScreen(1);
        break;
    case 5:
        CreateHintDisplayScreen(gUnknown_203B25C->chosenHintIndex);
        break;
    case 6:
        // Load our current options?
        gUnknown_203B25C->newOptions = *gGameOptionsRef;
        sub_801E198(&gUnknown_203B25C->newOptions);
        break;
    case 7:
        CreateChangeSettingsConfirmMenu();
        // Change settings?
        sub_8014248(gUnknown_80DBFEC,0,4,gUnknown_203B25C->menuItems,0,4,0,0,0x20);
        break;
  }
}

void CreateOthersMenu(void)
{
  const char *blankText;
  s32 defaultAction;
  struct unkStruct_203B25C *preload;
  
  MemoryFill16(gUnknown_203B25C->unkAC,0,sizeof(gUnknown_203B25C->unkAC));

  // This is dumb that I have to squeeze this in like this
  preload = gUnknown_203B25C;
  blankText = NULL;
  preload->menuItems[0].text = gOthers_GameOptions;
  preload->menuItems[0].menuAction = MENU_OPTION_GAMEOPTIONS;
  defaultAction = MENU_OPTION_DEFAULT;
  preload->menuItems[1].text = gOthers_Hints;
  preload->menuItems[1].menuAction = MENU_OPTION_HINTS;
  preload->menuItems[2].text = blankText;
  preload->menuItems[2].menuAction = defaultAction;
}

void CreateChangeSettingsConfirmMenu(void)
{
  const char *blankText;
  s32 defaultAction;
  struct unkStruct_203B25C *preload;
  
  MemoryFill16(gUnknown_203B25C->unkAC,0,sizeof(gUnknown_203B25C->unkAC));

  // This is dumb that I have to squeeze this in like this
  preload = gUnknown_203B25C;
  blankText = NULL;
  preload->menuItems[0].text = *gUnknown_80D4920; // Yes
  preload->menuItems[0].menuAction = MENU_OPTION_YES;
  defaultAction = MENU_OPTION_DEFAULT;
  preload->menuItems[1].text = *gUnknown_80D4928; // No
  preload->menuItems[1].menuAction = MENU_OPTION_NO;
  preload->menuItems[2].text = blankText;
  preload->menuItems[2].menuAction = defaultAction;
}

void HandleOthersMenu(void)
{
  s32 menuAction;
  
  menuAction = 0;
  if (sub_8012FD8(&gUnknown_203B25C->unk1C) == '\0') {
    sub_8013114(&gUnknown_203B25C->unk1C,&menuAction);
    gUnknown_203B25C->unk18 = menuAction;
  }
  switch(menuAction)
  {
    case MENU_OPTION_HINTS:
        sub_801DD6C(3);
        break;
    case MENU_OPTION_GAMEOPTIONS:
        sub_801DD6C(6);
        break;
    case MENU_OPTION_DEFAULT:
        sub_801DD6C(2);
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
        sub_801DD6C(5);
        break;
    case 2:
        sub_801E54C();
        sub_801DD6C(1);
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
        sub_801DD6C(4);
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
            sub_801DD6C(1);
        }
        else {
            sub_801DD6C(7);
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
            sub_801DD6C(1);
            break;
        case MENU_OPTION_DEFAULT:
        case MENU_OPTION_NO:
            sub_801DD6C(1);
            break;
    }
  }
}

bool8 sub_801E198(struct GameOptions *optionsMenu)
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
  sub_800641C(gUnknown_203B260->unk4C,1,1);
  sub_8013818(&gUnknown_203B260->unk10,1,1,gUnknown_203B260->unk44);
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
            if (gUnknown_203B260->unk28 == 0)
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
            if(gUnknown_203B260->unk28 == 0)
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
    if ((sub_80138B8(&gUnknown_203B260->unk10,1) != 0) || (flag == TRUE)) {
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
        sub_800641C(gUnknown_203B260->unk4C, 1, 1);
        MemoryFree(gUnknown_203B260);
        gUnknown_203B260 = NULL;
    }
}


void nullsub_38(void)
{
    
}

void CreateOptionsMenu(void)
{
  u32 uVar2;
  u32 y;
  
  sub_8008C54(gUnknown_203B260->unk44);
  sub_80073B8(gUnknown_203B260->unk44);
  xxx_call_draw_string(0x10,0,gWindowBGTitle,gUnknown_203B260->unk44,0);
  y = sub_8013800(&gUnknown_203B260->unk10,0);
  xxx_call_draw_string(8,y,gUnknown_80DC064,gUnknown_203B260->unk44,0);

  switch(gUnknown_203B260->optionsMenu->windowColor)
  {
      case WINDOW_COLOR_BLUE:
        uVar2 = sub_8008ED0(gWindowBGBlueString);
        sub_80078A4(gUnknown_203B260->unk44,gUnknown_203B260->optionsMenu->windowColor * '(' + 0x50,
              y + 0xA,uVar2,7);
        break;
      case WINDOW_COLOR_RED:
        uVar2 = sub_8008ED0(gWindowBGRedString);
        sub_80078A4(gUnknown_203B260->unk44,gUnknown_203B260->optionsMenu->windowColor * '(' + 0x50,
              y + 0xA,uVar2,7);
        break;
      case WINDOW_COLOR_GREEN:
        uVar2 = sub_8008ED0(gWindowBGGreenString);
        sub_80078A4(gUnknown_203B260->unk44,gUnknown_203B260->optionsMenu->windowColor * '(' + 0x50,
              y + 0xA,uVar2,7);
        break;
  }
  sub_80073E0(gUnknown_203B260->unk44);
}
