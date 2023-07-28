#include "global.h"
#include "constants/wonder_mail.h"
#include "input.h"
#include "main_menu.h"
#include "play_time.h"
#include "file_system.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "text_util.h"
#include "pokemon.h"
#include "save.h"
#include "code_800D090.h"
#include "code_8094F88.h"
#include "menu_input.h"

extern const struct FileArchive gTitleMenuFileArchive;

struct LoadScreen
{
    // size: 0x27c
    u32 currMenu;
    struct MenuStruct unk4[4];
    struct UnkTextStruct2 unk144[4];
    /* 0x1A4 */ u8 formattedTeamName[0x24];
    /* 0x1C8 */ u8 formattedPlayerName[0x24];
    /* 0x1EC */ u8 formattedLocation[0x24];
    /* 0x210 */ u8 formattedPlayTime[0x24];
    /* 0x234 */ u8 formattedAdventures[0x24];
    /* 0x258 */ u8 formattedHelperInfo[0x24];
};

EWRAM_DATA_2 struct LoadScreen *gLoadScreen = {0};
EWRAM_DATA_2 struct MenuItem gUnknown_203B378[2] = {0};
EWRAM_DATA_2 u32 gUnknown_203B388[12] = {0};
EWRAM_DATA_2 u32 gUnknown_203B3B8[12] = {0};

extern struct unkStruct_203B484 *gUnknown_203B484;

u8 IsQuickSave(void);
void DrawLoadScreenText(void);
void sub_80397B4(void);

extern void sub_8035CF4(struct MenuStruct *, u32, u32);
extern void SetMenuItems(struct MenuStruct *, struct UnkTextStruct2 *, u32, const struct UnkTextStruct2 *, const struct MenuItem *, u32, u32, u32);

extern void sub_80920D8(u8 *);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern bool8 sub_80023E4(u32);
extern u8 *sub_8098FB4();
extern u8 *GetDungeonLocationInfo(void);
extern u32 GetNumAdventures(void);
extern void PrintDungeonLocationtoBuffer(u8 *, u8 *);
extern u32 sub_8001658(u32, u32);
extern void sub_80073E0(u32);

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void xxx_format_string(u8 *, u8 *, u8 *, u32);

extern void SetBGPaletteBufferColorArray(s32, s32);
extern void sub_8007E20(s32, s32, s32, u32, u32, s32, u32);

const struct UnkTextStruct2 gUnknown_80E75F8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E7610 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x1A, 0x0B,
   0x0B, 0x00,
   NULL
};

const u8 gUnkData_80E7628[] = {0x20, 0x00, 0x00, 0x00};

const struct UnkTextStruct2 gUnknown_80E762C = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x0F,
   0x13, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gResumeQuicksaveMenuItems[3] =
{
    {"Resuming from quicksave.", 5},
    {"Is that OK?", 5},
    {NULL, 3},
};

const struct MenuItem gResumeAdventureMenuItems[3] =
{
    {"Resuming saved adventure.", 5},
    {"Is that OK?", 5},
    {NULL, 3},
};

const struct MenuItem gQuitWaitingRescueMenuItems[3] =
{
    {"Quit awaiting rescue?", 5},
    {"Is that OK?", 5},
    {NULL, 3},
};

const struct MenuItem gDeleteSavePromptMenuItems[3] =
{
    {"Your saved data will be", 5},
    {"deleted. Is that OK?", 5},
    {NULL, 3},
};

const struct MenuItem gDeleteSaveConfirmMenuItems[3] =
{
    {"Are you sure you want to", 5},
    {"delete all of your saved data?", 5},
    {NULL, 3},
};

const struct UnkTextStruct2 gUnknown_80E7784 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x17, 0x0F,
    0x05, 0x03,
    0x03, 0x00,
    NULL
};

const struct MenuItem gLoadScreenYesNoMenu[3] =
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
ALIGNED(4) const char load_screen_fill[] = "pksdir0";

void CreateLoadScreen(u32 currMenu)
{
  int index;

  if (gLoadScreen == NULL) {
    gLoadScreen = MemoryAlloc(sizeof(struct LoadScreen),8);
    MemoryFill8((u8 *)gLoadScreen,0,sizeof(struct LoadScreen));
  }
  gLoadScreen->currMenu = currMenu;
  for(index = 0; index < 4; index++){
    gLoadScreen->unk144[index] = gUnknown_80E75F8;
  }
  ResetUnusedInputStruct();
  sub_800641C(gLoadScreen->unk144,1,1);
  SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,0,&gUnknown_80E7610,gUnknown_203B378,0,6,0);
  switch(gLoadScreen->currMenu){
    case MENU_CONTINUE:
        if (IsQuickSave())
            SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gResumeQuicksaveMenuItems,0,6,0);
        else
            SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gResumeAdventureMenuItems,0,6,0);
        break;
    case MENU_AWAITING_RESCUE:
        SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gQuitWaitingRescueMenuItems,0,6,0);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gDeleteSavePromptMenuItems,0,6,0);
        break;
    case MENU_DELETE_SAVE_CONFIRM:
        SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C, gDeleteSaveConfirmMenuItems,0,6,0);
        break;
  }
  SetMenuItems(gLoadScreen->unk4,gLoadScreen->unk144,2,&gUnknown_80E7784,gLoadScreenYesNoMenu,1,2,0);
  sub_8035CF4(gLoadScreen->unk4,0,0);
  sub_8035CF4(gLoadScreen->unk4,1,0);
  sub_8035CF4(gLoadScreen->unk4,2,1);
  DrawLoadScreenText();
}

void CleanLoadScreen(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
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
  struct PokemonStruct *playerInfo;
  struct unkStruct_203B484 *temp2;
  u8 *r2;

  iVar2 = sub_8011FA8();
  sub_8008C54(0);
  sub_80073B8(0);
  xxx_call_draw_string(8,0, gTeamHeadingText,0,0); // Team:
  xxx_call_draw_string(8,12,gNameHeadingText,0,0); // Name:
  xxx_call_draw_string(8,24,gLocationHeadingText,0,0); // Location:
  xxx_call_draw_string(8,36,gPlayTimeHeadingText,0,0); // Play time:
  xxx_call_draw_string(8,48,gAdventuresHeadingText,0,0); // Adventures:
  xxx_call_draw_string(8,60,gHelperHeadingText,0,0); // Helper:

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
  xxx_call_draw_string(64,0,gLoadScreen->formattedTeamName,0,0);

  // Draw Player Name
  playerInfo = GetPlayerPokemonStruct();
  if (playerInfo == NULL)
        sub_80922B4(playerName, gNoNamePlaceholder, POKEMON_NAME_LENGTH);
  else
        sub_80922B4(playerName, playerInfo->name, POKEMON_NAME_LENGTH);
  sprintfStatic(gLoadScreen->formattedPlayerName,gUnknown_80E7804,playerName);
  xxx_call_draw_string(64,12,gLoadScreen->formattedPlayerName,0,0);

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
            switch(sub_8001658(0,24))
            {
                default:
                    sprintfStatic(auStack356,gUnknown_80E7804,sub_8098FB4());
                    xxx_format_string(auStack356,gLoadScreen->formattedLocation,gLoadScreen->formattedPlayTime,0);
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
  xxx_call_draw_string(64,24,gLoadScreen->formattedLocation,0,0);

  // Draw Play Time
  DeconstructPlayTime(gPlayTimeRef,&hours,&minutes,&seconds);
  sprintfStatic(gLoadScreen->formattedPlayTime,gPlayTimePlaceholder,hours,minutes,seconds);
  xxx_call_draw_string(64,36,gLoadScreen->formattedPlayTime,0,0);

  // Draw Adventures Info
  numAdventures = GetNumAdventures();
  sprintfStatic(gLoadScreen->formattedAdventures,gNumAdventurePlaceholder,numAdventures); // %d
  xxx_call_draw_string(64,48,gLoadScreen->formattedAdventures,0,0);

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
  xxx_call_draw_string(64,60,gLoadScreen->formattedHelperInfo,0,0);

  sub_80397B4(); // Draw event icons??
  sub_80073E0(0);
}

// Think structure of clmkFile is like Team Rank Badges except each pic has a diff pallete
// TODO clean up but it matches so yea
void sub_80397B4(void)
{
  struct OpenedFile *clmkFile;
  int index;
  int x;
  s32 y;

  clmkFile = OpenFileAndGetFileDataPtr(gClmkpatFileName,&gTitleMenuFileArchive); // clmkpat

  for(index = 0; index < 64; index++)
  {
    SetBGPaletteBufferColorArray(index + 176,*(int *)((clmkFile->data) + 4) + index * 4);
  }

  x = 8;
  y = 0x49;

  // Draw the 12 legendary icons
  for(index = 0; index < 12; index++)
  {
    if (sub_80023E4(gUnknown_203B3B8[index])) {
      sub_8007E20(0,x,y,0x10,0x10,*(int *)(clmkFile->data) + index * 0x80,
                  gUnknown_203B388[index]);
      x += 16;
    }
  }
  CloseFile(clmkFile);
}

bool8 IsQuickSave(void)
{
  int iVar1;
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
