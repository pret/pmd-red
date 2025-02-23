#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_800D090.h"
#include "string_format.h"
#include "code_8094F88.h"
#include "code_8097670.h"
#include "constants/main_menu.h"
#include "constants/wonder_mail.h"
#include "dungeon.h"
#include "event_flag.h"
#include "file_system.h"
#include "ground_main.h"
#include "input.h"
#include "main_menu1.h"
#include "memory.h"
#include "structs/menu.h"
#include "menu_input.h"
#include "play_time.h"
#include "pokemon.h"
#include "save.h"
#include "text_util.h"
#include "text.h"

extern const struct FileArchive gTitleMenuFileArchive;

struct LoadScreen
{
    // size: 0x27c
    u32 currMenu;
    MenuStruct unk4[4];
    Windows unk144;
    /* 0x1A4 */ u8 formattedTeamName[0x24];
    /* 0x1C8 */ u8 formattedPlayerName[0x24];
    /* 0x1EC */ u8 formattedLocation[0x24];
    /* 0x210 */ u8 formattedPlayTime[0x24];
    /* 0x234 */ u8 formattedAdventures[0x24];
    /* 0x258 */ u8 formattedHelperInfo[0x24];
};

EWRAM_INIT struct LoadScreen *gLoadScreen = {NULL};

extern unkStruct_203B484 *gUnknown_203B484;

u8 IsQuickSave(void);
void DrawLoadScreenText(void);
void sub_80397B4(void);

extern void sub_80920D8(u8 *);

const Window gUnknown_80E75F8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const Window gUnknown_80E7610 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x1A, 0x0B,
   0x0B, 0x00,
   NULL
};

EWRAM_INIT MenuItem gUnknown_203B378[2] = {
    [0] = {
        .text = " ",
        .menuAction = 5,
    },
    [1] = {
        .text = NULL,
        .menuAction = 3,
    }
};

EWRAM_INIT u32 gUnknown_203B388[12] = {0xC, 0xC, 0xE, 0xE, 0xD, 0xE, 0xC, 0xD, 0xD, 0xB, 0xB, 0xB};
EWRAM_INIT u32 gUnknown_203B3B8[12] = {0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x1A, 0x18, 0x1B, 0x16, 0x19, 0x17};

const Window gUnknown_80E762C = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x0F,
   0x13, 0x03,
   0x03, 0x00,
   NULL
};

const MenuItem gResumeQuicksaveMenuItems[3] =
{
    {"Resuming from quicksave.", 5},
    {"Is that OK?", 5},
    {NULL, 3},
};

const MenuItem gResumeAdventureMenuItems[3] =
{
    {"Resuming saved adventure.", 5},
    {"Is that OK?", 5},
    {NULL, 3},
};

const MenuItem gQuitWaitingRescueMenuItems[3] =
{
    {"Quit awaiting rescue?", 5},
    {"Is that OK?", 5},
    {NULL, 3},
};

const MenuItem gDeleteSavePromptMenuItems[3] =
{
    {"Your saved data will be", 5},
    {"deleted. Is that OK?", 5},
    {NULL, 3},
};

const MenuItem gDeleteSaveConfirmMenuItems[3] =
{
    {"Are you sure you want to", 5},
    {"delete all of your saved data?", 5},
    {NULL, 3},
};

const Window gUnknown_80E7784 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x17, 0x0F,
    0x05, 0x03,
    0x03, 0x00,
    NULL
};

const MenuItem gLoadScreenYesNoMenu[3] =
{
    {"Yes", 1},
    {"No", 2},
    {NULL, 3},
};

ALIGNED(4) const char gTeamHeadingText[] = "Team:";
ALIGNED(4) const char gNameHeadingText[] = "Name:";
ALIGNED(4) const char gLocationHeadingText[] = "Location:";
ALIGNED(4) const char gPlayTimeHeadingText[] = "Play time:";
ALIGNED(4) const char gAdventuresHeadingText[] = "Adventures:";
ALIGNED(4) const char gHelperHeadingText[] = "Helper:";
ALIGNED(4) const char gNoTeamNamePlaceholder[] = _("？？？？");
ALIGNED(4) const char gUnknown_80E7804[] = "%s ";
ALIGNED(4) const char gNoNamePlaceholder[] = "???";
ALIGNED(4) const char gQuicksaveDataDeletedText[] = "Quicksave data deleted.";
ALIGNED(4) const char gLocationUnknownText[] = "Location unknown.";
ALIGNED(4) const char gPlayTimePlaceholder[] = "%d:%02d:%02d ";
ALIGNED(4) const char gNumAdventurePlaceholder[] = "%d";
ALIGNED(4) const char gHelperInfoPlaceholder[] = "%s (%s)";
ALIGNED(4) const char gNoHelperText[] = "-----";
ALIGNED(4) const char gClmkpatFileName[] = "clmkpat"; // clmkpat

void CreateLoadScreen(u32 currMenu)
{
  int index;

  if (gLoadScreen == NULL) {
    gLoadScreen = MemoryAlloc(sizeof(struct LoadScreen), 8);
    MemoryFill8(gLoadScreen, 0, sizeof(struct LoadScreen));
  }
  gLoadScreen->currMenu = currMenu;
  for(index = 0; index < 4; index++){
    gLoadScreen->unk144.id[index] = gUnknown_80E75F8;
  }
  ResetUnusedInputStruct();
  ShowWindows(&gLoadScreen->unk144, TRUE, TRUE);
  SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,0,&gUnknown_80E7610,gUnknown_203B378,FALSE,6,FALSE);
  switch(gLoadScreen->currMenu){
    case MENU_CONTINUE:
        if (IsQuickSave())
            SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,1,&gUnknown_80E762C,gResumeQuicksaveMenuItems,FALSE,6,FALSE);
        else
            SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,1,&gUnknown_80E762C,gResumeAdventureMenuItems,FALSE,6,FALSE);
        break;
    case MENU_AWAITING_RESCUE:
        SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,1,&gUnknown_80E762C,gQuitWaitingRescueMenuItems,FALSE,6,FALSE);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,1,&gUnknown_80E762C,gDeleteSavePromptMenuItems,FALSE,6,FALSE);
        break;
    case MENU_DELETE_SAVE_CONFIRM:
        SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,1,&gUnknown_80E762C, gDeleteSaveConfirmMenuItems,FALSE,6,FALSE);
        break;
  }
  SetMenuItems(gLoadScreen->unk4,&gLoadScreen->unk144,2,&gUnknown_80E7784,gLoadScreenYesNoMenu,TRUE,2,FALSE);
  sub_8035CF4(gLoadScreen->unk4,0,0);
  sub_8035CF4(gLoadScreen->unk4,1,0);
  sub_8035CF4(gLoadScreen->unk4,2,1);
  DrawLoadScreenText();
}

void CleanLoadScreen(void)
{
    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
    if(gLoadScreen != NULL)
    {
        MemoryFree(gLoadScreen);
        gLoadScreen = NULL;
    }
}

u32 UpdateLoadScreenMenu(void)
{
  u32 nextMenu;
  u32 menuAction;

  nextMenu = MENU_NO_SCREEN_CHANGE;
  menuAction = 4;
  sub_8012FD8(&gLoadScreen->unk4[1]);
  if (sub_8012FD8(&gLoadScreen->unk4[2]) == '\0') {
    sub_8013114(&gLoadScreen->unk4[2],&menuAction);
  }

  switch(menuAction)
  {
      case 3:
      case 2:
        nextMenu =  MENU_MAIN_SCREEN;
        break;
      case 1:
        switch(gLoadScreen->currMenu)
        {
            case MENU_CONTINUE:
                nextMenu = 2; // MENU_???
                break;
            case MENU_AWAITING_RESCUE:
                DeleteMailAtIndex(0);
                nextMenu = 4; // MENU_???
                break;
            case MENU_DELETE_SAVE_PROMPT:
                nextMenu = MENU_DELETE_SAVE_CONFIRM;
                break;
            case MENU_DELETE_SAVE_CONFIRM:
                sub_80122A8();
                nextMenu = MENU_DELETE_SAVE;
                break;
        }
        break;
      case 5:
      default:
        break;
  }
  return nextMenu;
}

static inline u8 *DrawLoadScreenTextSub(u8 *teamNameBuffer) {
  strcpy(teamNameBuffer,gNoTeamNamePlaceholder);
  return teamNameBuffer;
}

void DrawLoadScreenText(void)
{
  int iVar2;
  u32 numAdventures;
  u8 auStack356 [100];
  u8 teamNameBuffer [40];
  u8 playerName [80];
  u8 nameHelper [80];
  u8 speciesHelper [20];
  u32 hours;
  u32 minutes;
  u32 seconds;
  PokemonStruct1 *playerInfo;
  unkStruct_203B484 *temp2;
  u8 *r2;

  iVar2 = sub_8011FA8();
  CallPrepareTextbox_8008C54(0);
  sub_80073B8(0);
  PrintStringOnWindow(8,0, gTeamHeadingText,0,0); // Team:
  PrintStringOnWindow(8,12,gNameHeadingText,0,0); // Name:
  PrintStringOnWindow(8,24,gLocationHeadingText,0,0); // Location:
  PrintStringOnWindow(8,36,gPlayTimeHeadingText,0,0); // Play time:
  PrintStringOnWindow(8,48,gAdventuresHeadingText,0,0); // Adventures:
  PrintStringOnWindow(8,60,gHelperHeadingText,0,0); // Helper:

  // Draw Team Name
  if (sub_80023E4(0)) {
    sub_80920D8(teamNameBuffer);
    r2 = teamNameBuffer;
  }
  else {
    // NOTE: static inline was needed here to match -jiang
    r2 = DrawLoadScreenTextSub(teamNameBuffer);
  }

  sprintfStatic(gLoadScreen->formattedTeamName,gUnknown_80E7804,r2);
  PrintStringOnWindow(64,0,gLoadScreen->formattedTeamName,0,0);

  // Draw Player Name
  playerInfo = GetPlayerPokemonStruct();
  if (playerInfo == NULL)
        sub_80922B4(playerName, gNoNamePlaceholder, POKEMON_NAME_LENGTH);
  else
        sub_80922B4(playerName, playerInfo->name, POKEMON_NAME_LENGTH);
  sprintfStatic(gLoadScreen->formattedPlayerName,gUnknown_80E7804,playerName);
  PrintStringOnWindow(64,12,gLoadScreen->formattedPlayerName,0,0);

  // Draw Location Info
  if ((CountMailType(WONDER_MAIL_TYPE_SOS) != 0) || (CountMailType(WONDER_MAIL_TYPE_OKD) != 0)) {
    if (iVar2 == 0xf1207)
        PrintDungeonLocationtoBuffer(gLoadScreen->formattedLocation,GetDungeonLocationInfo());
    else
        sprintfStatic(gLoadScreen->formattedLocation,gQuicksaveDataDeletedText); // Quicksave data deleted
  }
  else {
    switch(sub_8011C1C())
    {
        case 1:
            switch(GetScriptVarValue(NULL,START_MODE))
            {
                default:
                    sprintfStatic(auStack356,gUnknown_80E7804,sub_8098FB4());
                    FormatString(auStack356,gLoadScreen->formattedLocation,gLoadScreen->formattedPlayTime,0);
                    break;
                case 0x7:
                case 0xB:
                    sprintfStatic(gLoadScreen->formattedLocation,gQuicksaveDataDeletedText); // Quicksave data deleted
                    break;
            }
            break;
        case 2:
            if (iVar2 == 0xf1207)
                PrintDungeonLocationtoBuffer(gLoadScreen->formattedLocation,GetDungeonLocationInfo());
            else
                sprintfStatic(gLoadScreen->formattedLocation,gQuicksaveDataDeletedText); // Quicksave data deleted
            break;
        default:
            sprintfStatic(gLoadScreen->formattedLocation,gLocationUnknownText); // Location unknown
            break;
    }
  }
  PrintStringOnWindow(64,24,gLoadScreen->formattedLocation,0,0);

  // Draw Play Time
  DeconstructPlayTime(gPlayTimeRef,&hours,&minutes,&seconds);
  sprintfStatic(gLoadScreen->formattedPlayTime,gPlayTimePlaceholder,hours,minutes,seconds);
  PrintStringOnWindow(64,36,gLoadScreen->formattedPlayTime,0,0);

  // Draw Adventures Info
  numAdventures = GetNumAdventures();
  sprintfStatic(gLoadScreen->formattedAdventures,gNumAdventurePlaceholder,numAdventures); // %d
  PrintStringOnWindow(64,48,gLoadScreen->formattedAdventures,0,0);

  // Draw Helper Info
  if (iVar2 == 0xf1207){
       // NOTE: very hacky match here but needed var here to match
       temp2 =  gUnknown_203B484;
       if(temp2->unk4.speciesNum != MONSTER_NONE) {
            sub_808D930(speciesHelper,temp2->unk4.speciesNum);
            sub_80922B4(nameHelper,temp2->unk4.name,POKEMON_NAME_LENGTH);
            sprintfStatic(gLoadScreen->formattedHelperInfo,gHelperInfoPlaceholder,nameHelper,speciesHelper); // %s (%s)
       }
       else
            goto print_helper_placeholder;
  }
  else {
    print_helper_placeholder:
        sprintfStatic(gLoadScreen->formattedHelperInfo,gNoHelperText); // -----
  }
  PrintStringOnWindow(64,60,gLoadScreen->formattedHelperInfo,0,0);

  sub_80397B4(); // Draw event icons??
  sub_80073E0(0);
}

// Think structure of clmkFile is like Team Rank Badges except each pic has a diff palette
struct ClmkFileData
{
    /* 0x0 */ u32 *pics;
    /* 0x4 */ RGB *palette;
};

void sub_80397B4(void)
{
  OpenedFile *clmkFile;
  s32 index;
  s32 x;
  s32 y;

  clmkFile = OpenFileAndGetFileDataPtr(gClmkpatFileName,&gTitleMenuFileArchive); // clmkpat

  for(index = 0; index < 64; index++)
  {
    SetBGPaletteBufferColorArray(index + 176, &((struct ClmkFileData *)(clmkFile->data))->palette[index]);
  }

  x = 8;
  y = 0x49;

  // Draw the 12 legendary icons
  for(index = 0; index < 12; index++)
  {
    if (sub_80023E4(gUnknown_203B3B8[index])) {
      sub_8007E20(0,x,y,0x10,0x10,(&((struct ClmkFileData *)(clmkFile->data))->pics[index * 32]), gUnknown_203B388[index]);
      x += 16;
    }
  }
  CloseFile(clmkFile);
}

bool8 IsQuickSave(void)
{
  s32 iVar1;
  bool8 isQuicksave;

  iVar1 = sub_8011FA8();
  isQuicksave = FALSE;
  if (CountMailType(WONDER_MAIL_TYPE_SOS) != 0 || CountMailType(WONDER_MAIL_TYPE_OKD) != 0)
  {
      if (iVar1 == 0xf1207)
        isQuicksave  = TRUE;
  }
  else if (sub_8011C1C() == 2 && iVar1 == 0xf1207)
    isQuicksave = TRUE;
  return isQuicksave;
}

bool8 sub_8039880(void)
{
  return (CountMailType(WONDER_MAIL_TYPE_SOS) != 0 || CountMailType(WONDER_MAIL_TYPE_OKD) != 0 || sub_8011C1C() == 2);
}
