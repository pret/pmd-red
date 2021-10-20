#include "global.h"
#include "input.h"
#include "main_menu.h"
#include "play_time.h"
#include "file_system.h"
#include "memory.h"
#include "menu.h"
#include "text.h"
#include "pokemon.h"
#include "save.h"

extern const struct FileArchive gTitleMenuFileArchive;

struct unkStruct_203B484
{
    u8 fill0[0xC];
    /* 0xC */ s16 speciesIndex;
    u8 fillE[0x50 - 0xE];
    /* 0x50 */ u8 helperName[10];
};

struct LoadScreen
{
    // size: 0x27c
    u32 currMenu;
    u32 unk4;
    u8 fill8[0x54 - 8];
    u32 unk54;
    u8 fill58[0xA4 - 0x58];
    u32 unkA4;
    u8 fillA8[0x144 - 0xA8];
    struct UnkTextStruct2 unk144[4];
    /* 0x1A4 */ u8 formattedTeamName[0x24];
    /* 0x1C8 */ u8 formattedPlayerName[0x24];
    /* 0x1EC */ u8 formattedLocation[0x24];
    /* 0x210 */ u8 formattedPlayTime[0x24];
    /* 0x234 */ u8 formattedAdventures[0x24];
    /* 0x258 */ u8 formattedHelperInfo[0x24];
};

EWRAM_DATA struct LoadScreen *gLoadScreen;
EWRAM_DATA struct MenuItem gUnknown_203B378[2];
EWRAM_DATA u32 gUnknown_203B388[12];
EWRAM_DATA u32 gUnknown_203B3B8[12];

extern struct unkStruct_203B484 *gUnknown_203B484;

extern struct UnkTextStruct2 gUnknown_80E75F8;
extern struct UnkTextStruct2 gUnknown_80E7610;
extern struct UnkTextStruct2 gUnknown_80E762C;
extern struct MenuItem gResumeQuicksaveMenuItems[];
extern struct MenuItem gResumeAdventureMenuItems[];
extern struct MenuItem gQuitWaitingRescueMenuItems[];
extern struct MenuItem gDeleteSavePromptMenuItems[];
extern struct MenuItem gDeleteSaveConfirmMenuItems[];
extern struct UnkTextStruct2 gUnknown_80E7784;

extern const char No_80E77B4[];
extern const char Yes_80E77B8[];

const struct MenuItem gLoadScreenYesNoMenu[3] =
{
    {Yes_80E77B8, 1},
    {No_80E77B4, 2},
    {NULL, 3},
};

ALIGNED(4) const char No_80E77B4[] = "No";
ALIGNED(4) const char Yes_80E77B8[] = "Yes";

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


u8 IsQuickSave(void);
void DrawLoadScreenText(void);
void sub_80397B4(void);

extern void sub_8035CF4(u32 *, u32, u32);
extern void SetMenuItems(u32 *, struct UnkTextStruct2 *, u32, struct UnkTextStruct2 *, const struct MenuItem *, u32, u32, u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern void sub_8095240(u32);

extern void sub_80920D8(u8 *);
extern struct PokemonStruct *sub_808D33C(void);
extern u8 sub_80023E4(u32);
extern u8 *sub_8098FB4();
extern void ExpandPlaceholdersBuffer(u8 *buffer, const u8 *text, ...);
extern u8 *GetDungeonLocationInfo(void);
extern u32 GetNumAdventures(void);
extern void xxx_call_draw_string(u32 x, u32 y, const u8 *, u32, u32);
extern void PrintDungeonLocationtoBuffer(u8 *, u8 *);
extern void sub_80922B4(u8 *, const u8 *, u32);
extern s32 sub_8095324(u32);
extern u32 sub_8001658(u32, u32);
extern void sub_80073E0(u32);

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_808D930(u8 *, s16);
extern void xxx_format_string(u8 *, u8 *, u8 *, u32);

extern void SetBGPaletteBufferColorArray(s32, s32);
extern void sub_8007E20(s32, s32, s32, u32, u32, s32, u32);


void CreateLoadScreen(u32 currMenu)
{
  int iVar8;
  
  if (gLoadScreen == NULL) {
    gLoadScreen = MemoryAlloc(sizeof(struct LoadScreen),8);
    MemoryFill8((u8 *)gLoadScreen,0,sizeof(struct LoadScreen));
  }
  gLoadScreen->currMenu = currMenu;
  for(iVar8 = 0; iVar8 < 4; iVar8++){
    gLoadScreen->unk144[iVar8] = gUnknown_80E75F8;
  }
  ResetUnusedInputStruct();
  sub_800641C(gLoadScreen->unk144,1,1);
  SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,0,&gUnknown_80E7610,gUnknown_203B378,0,6,0);
  switch(gLoadScreen->currMenu){
    case MENU_CONTINUE:
        if (IsQuickSave())
            SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gResumeQuicksaveMenuItems,0,6,0);
        else
            SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gResumeAdventureMenuItems,0,6,0);
        break;
    case MENU_AWAITING_RESCUE:
        SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gQuitWaitingRescueMenuItems,0,6,0);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C,gDeleteSavePromptMenuItems,0,6,0);
        break;
    case MENU_DELETE_SAVE_CONFIRM:
        SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,1,&gUnknown_80E762C, gDeleteSaveConfirmMenuItems,0,6,0);
        break;
  }
  SetMenuItems(&gLoadScreen->unk4,gLoadScreen->unk144,2,&gUnknown_80E7784,gLoadScreenYesNoMenu,1,2,0);
  sub_8035CF4(&gLoadScreen->unk4,0,0);
  sub_8035CF4(&gLoadScreen->unk4,1,0);
  sub_8035CF4(&gLoadScreen->unk4,2,1);
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
  sub_8012FD8(&gLoadScreen->unk54);
  if (sub_8012FD8(&gLoadScreen->unkA4) == '\0') {
    sub_8013114(&gLoadScreen->unkA4,&menuAction);
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
                sub_8095240(0);
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
  if (sub_80023E4(0) != '\0') {
    sub_80920D8(teamNameBuffer);
    r2 = teamNameBuffer;
  }
  else {
    // NOTE: static inline was needed here to match -jiang
    r2 = DrawLoadScreenTextSub(teamNameBuffer);
  }

  ExpandPlaceholdersBuffer(gLoadScreen->formattedTeamName,gUnknown_80E7804,r2);
  xxx_call_draw_string(64,0,gLoadScreen->formattedTeamName,0,0);

  // Draw Player Name
  playerInfo = sub_808D33C();
  if (playerInfo == NULL)
        sub_80922B4(playerName, gNoNamePlaceholder, POKEMON_NAME_LENGTH);
  else
        sub_80922B4(playerName, playerInfo->name, POKEMON_NAME_LENGTH);
  ExpandPlaceholdersBuffer(gLoadScreen->formattedPlayerName,gUnknown_80E7804,playerName);
  xxx_call_draw_string(64,12,gLoadScreen->formattedPlayerName,0,0);

  // Draw Location Info
  if ((sub_8095324(1) != 0) || (sub_8095324(7) != 0)) {
    if (iVar2 == 0xf1207)
        PrintDungeonLocationtoBuffer(gLoadScreen->formattedLocation,GetDungeonLocationInfo());
    else
        ExpandPlaceholdersBuffer(gLoadScreen->formattedLocation,gQuicksaveDataDeletedText); // Quicksave data deleted
  }
  else {
    switch(sub_8011C1C())
    {
        case 1:
            switch(sub_8001658(0,24))
            {
                default:
                    ExpandPlaceholdersBuffer(auStack356,gUnknown_80E7804,sub_8098FB4());
                    xxx_format_string(auStack356,gLoadScreen->formattedLocation,gLoadScreen->formattedPlayTime,0);
                    break;
                case 0x7:
                case 0xB:
                    ExpandPlaceholdersBuffer(gLoadScreen->formattedLocation,gQuicksaveDataDeletedText); // Quicksave data deleted
                    break;
            }
            break;
        case 2:
            if (iVar2 == 0xf1207)
                PrintDungeonLocationtoBuffer(gLoadScreen->formattedLocation,GetDungeonLocationInfo());
            else
                ExpandPlaceholdersBuffer(gLoadScreen->formattedLocation,gQuicksaveDataDeletedText); // Quicksave data deleted
            break;
        default:
            ExpandPlaceholdersBuffer(gLoadScreen->formattedLocation,gLocationUnknownText); // Location unknown
            break;
    }
  }
  xxx_call_draw_string(64,24,gLoadScreen->formattedLocation,0,0);

  // Draw Play Time
  DeconstructPlayTime(gPlayTimeRef,&hours,&minutes,&seconds);
  ExpandPlaceholdersBuffer(gLoadScreen->formattedPlayTime,gPlayTimePlaceholder,hours,minutes,seconds);
  xxx_call_draw_string(64,36,gLoadScreen->formattedPlayTime,0,0);

  // Draw Adventures Info 
  numAdventures = GetNumAdventures();
  ExpandPlaceholdersBuffer(gLoadScreen->formattedAdventures,gNumAdventurePlaceholder,numAdventures); // %d
  xxx_call_draw_string(64,48,gLoadScreen->formattedAdventures,0,0);

  // Draw Helper Info
  if (iVar2 == 0xf1207){
       // NOTE: very hacky match here but needed var here to match
       temp2 =  gUnknown_203B484;
       if(temp2->speciesIndex != SPECIES_NONE) {
            sub_808D930(speciesHelper,temp2->speciesIndex);
            sub_80922B4(nameHelper,temp2->helperName,POKEMON_NAME_LENGTH);
            ExpandPlaceholdersBuffer(gLoadScreen->formattedHelperInfo,gHelperInfoPlaceholder,nameHelper,speciesHelper); // %s (%s)
       }
       else
            goto print_helper_placeholder;
  }
  else {
    print_helper_placeholder:
        ExpandPlaceholdersBuffer(gLoadScreen->formattedHelperInfo,gNoHelperText); // -----
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
  int iVar3;
  int iVar4;
  s32 other_arg;
  
  clmkFile = OpenFileAndGetFileDataPtr(gClmkpatFileName,&gTitleMenuFileArchive); // clmkpat

  for(iVar3 = 0; iVar3 < 64; iVar3++)
  {
    SetBGPaletteBufferColorArray(iVar3 + 176,*(int *)((clmkFile->data) + 4) + iVar3 * 4);
  }

  iVar4 = 8;
  other_arg = 0x49;

  // Draw the 12 legendary icons
  for(iVar3 = 0; iVar3 < 12; iVar3++)
  {
    if (sub_80023E4(gUnknown_203B3B8[iVar3]) != 0) {
      sub_8007E20(0,iVar4,other_arg,0x10,0x10,*(int *)(clmkFile->data) + iVar3 * 0x80,
                  gUnknown_203B388[iVar3]);
      iVar4 += 16;
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
  if (sub_8095324(1) != 0 || sub_8095324(7) != 0)
  {
      if (iVar1 == 0xf1207)
        isQuicksave  = TRUE;
  }
  else if (sub_8011C1C() == 2 && iVar1 == 0xf1207)
    isQuicksave = TRUE;
  return isQuicksave;
}
