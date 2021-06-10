#include "global.h"
#include "input.h"
#include "main_menu.h"
#include "play_time.h"
#include "file_system.h"
#include "memory.h"
#include "text.h"

extern struct PlayTimeStruct *gPlayTimeRef;
extern struct PlayTimeStruct gPlayTime;

extern const struct FileArchive gTitleMenuFileArchive;

struct unkStruct_808D33C
{
    u8 fill0[0x4C];
    u8 unk4C;
};

struct unkStruct_203B484
{
    u8 fill0[0xC];
    s16 speciesIndex;
    u8 fillE[0x50 - 0xE];
    u32 unk50;
};

struct unkStruct_203B374
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

extern struct unkStruct_203B374 *gUnknown_203B374;
extern u32 gUnknown_203B378;
extern u32 gUnknown_203B3B8[];
extern u32 gUnknown_203B388[];
extern struct unkStruct_203B484 *gUnknown_203B484;

extern struct UnkTextStruct2 gUnknown_80E75F8;
extern struct UnkTextStruct2 gUnknown_80E7610;
extern struct UnkTextStruct2 gUnknown_80E762C;
extern u32 gUnknown_80E7644;
extern u32 gUnknown_80E7684;
extern u32 gUnknown_80E76B8;
extern u32 gUnknown_80E76E8;
extern u32 gUnknown_80E7730;
extern struct UnkTextStruct2 gUnknown_80E7784;
extern u32 gUnknown_80E779C;
extern u8 gUnknown_80E77BC;
extern u8 gUnknown_80E77C4;
extern u8 gUnknown_80E77CC;
extern u8 gUnknown_80E77D8;
extern u8 gUnknown_80E77E4;
extern u8 gUnknown_80E77F0;
extern u8 gUnknown_80E77F8;
extern u8 gUnknown_80E7804;
extern u8 gUnknown_80E7808;
extern u8 gUnknown_80E780C;
extern u8 gUnknown_80E7824;
extern u8 gUnknown_80E7838;
extern u8 gUnknown_80E7848;
extern u8 gUnknown_80E784C;
extern u8 gUnknown_80E7854;
extern const char gUnknown_80E785C[]; // clmkpat


u8 IsQuickSave(void);
void DrawLoadScreenText(void);
extern void sub_8035CF4(u32 *, u32, u32);
extern void SetMenuItems(u32 *, struct UnkTextStruct2 *, u32, struct UnkTextStruct2 *, u32 *, u32, u32, u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern void sub_8095240(u32);
extern void sub_80122A8(void);

extern void sub_80920D8(u8 *);
extern struct unkStruct_808D33C *sub_808D33C(void);
extern u8 sub_80023E4(u32);
extern u8 *sub_8098FB4();
extern void ExpandPlaceholdersBuffer(u8 *buffer, u8 *text, ...);
extern s32 sub_8011C1C(void);
extern u8 *sub_809769C(void);
extern u32 GetNumAdventures(void);
extern void xxx_call_draw_string(u32 x, u32 y, u8 *, u32, u32);
extern void sub_8090228(u8 *, u8 *);
extern void sub_80922B4(u8 *, u8 *, u32);
extern s32 sub_8095324(u32);
extern u32 sub_8001658(u32, u32);
void sub_80397B4(void);
extern void sub_80073E0(u32);
extern s32 sub_8011FA8(void);

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_808D930(u8 *, s16);
extern void xxx_format_string(u8 *, u8 *, u8 *, u32);

extern void SetBGPaletteBufferColorArray(s32, s32);
extern void sub_8007E20(s32, s32, s32, u32, u32, s32, u32);


void CreateLoadScreen(u32 currMenu)
{
  int iVar8;
  
  if (gUnknown_203B374 == NULL) {
    gUnknown_203B374 = MemoryAlloc(sizeof(struct unkStruct_203B374),8);
    MemoryFill8((u8 *)gUnknown_203B374,0,sizeof(struct unkStruct_203B374));
  }
  gUnknown_203B374->currMenu = currMenu;
  for(iVar8 = 0; iVar8 < 4; iVar8++){
    gUnknown_203B374->unk144[iVar8] = gUnknown_80E75F8;
  }
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B374->unk144,1,1);
  SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,0,&gUnknown_80E7610,&gUnknown_203B378,0,6,0);
  switch(gUnknown_203B374->currMenu){
    case MENU_CONTINUE:
        if (IsQuickSave())
            SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,1,&gUnknown_80E762C,&gUnknown_80E7644,0,6,0);
        else
            SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,1,&gUnknown_80E762C,&gUnknown_80E7684,0,6,0);
        break;
    case MENU_AWAITING_RESCUE:
        SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,1,&gUnknown_80E762C,&gUnknown_80E76B8,0,6,0);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,1,&gUnknown_80E762C,&gUnknown_80E76E8,0,6,0);
        break;
    case MENU_DELETE_SAVE_CONFIRM:
        SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,1,&gUnknown_80E762C, &gUnknown_80E7730,0,6,0);
        break;
  }
  SetMenuItems(&gUnknown_203B374->unk4,gUnknown_203B374->unk144,2,&gUnknown_80E7784,&gUnknown_80E779C,1,2,0);
  sub_8035CF4(&gUnknown_203B374->unk4,0,0);
  sub_8035CF4(&gUnknown_203B374->unk4,1,0);
  sub_8035CF4(&gUnknown_203B374->unk4,2,1);
  DrawLoadScreenText();
}

void CleanLoadScreen(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    if(gUnknown_203B374 != NULL)
    {
        MemoryFree(gUnknown_203B374);
        gUnknown_203B374 = NULL;
    }
}

u32 UpdateLoadScreenMenu(void)
{
  u32 nextMenu;
  u32 menuAction;
  
  nextMenu = MENU_NO_SCREEN_CHANGE;
  menuAction = 4;
  sub_8012FD8(&gUnknown_203B374->unk54);
  if (sub_8012FD8(&gUnknown_203B374->unkA4) == '\0') {
    sub_8013114(&gUnknown_203B374->unkA4,&menuAction);
  }

  switch(menuAction)
  {
      case 3:
      case 2:
        nextMenu =  MENU_MAIN_SCREEN;
        break;
      case 1:
        switch(gUnknown_203B374->currMenu)
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

#ifdef NONMATCHING
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
  struct unkStruct_808D33C *playerInfo;

  iVar2 = sub_8011FA8();
  sub_8008C54(0);
  sub_80073B8(0);
  xxx_call_draw_string(8,0, &gUnknown_80E77BC,0,0); // Team:
  xxx_call_draw_string(8,12,&gUnknown_80E77C4,0,0); // Name:
  xxx_call_draw_string(8,24,&gUnknown_80E77CC,0,0); // Location:
  xxx_call_draw_string(8,36,&gUnknown_80E77D8,0,0); // Play time:
  xxx_call_draw_string(8,48,&gUnknown_80E77E4,0,0); // Adventures:
  xxx_call_draw_string(8,60,&gUnknown_80E77F0,0,0); // Helper:

  // Draw Team Name
  if (sub_80023E4(0) != '\0') {
    sub_80920D8(teamNameBuffer);
  }
  else {
    strcpy(teamNameBuffer,&gUnknown_80E77F8);
  }
  ExpandPlaceholdersBuffer(gUnknown_203B374->formattedTeamName,&gUnknown_80E7804,teamNameBuffer);
  xxx_call_draw_string(64,0,gUnknown_203B374->formattedTeamName,0,0);

  // Draw Player Name
  playerInfo = sub_808D33C();
  if (playerInfo == NULL) {
    sub_80922B4(playerName,&gUnknown_80E7808,10);
  }
  else {
    sub_80922B4(playerName,&playerInfo->unk4C,10);
  }
  ExpandPlaceholdersBuffer(gUnknown_203B374->formattedPlayerName,&gUnknown_80E7804,playerName);
  xxx_call_draw_string(64,12,gUnknown_203B374->formattedPlayerName,0,0);

  // Draw Location Info
  // TODO: fix these branches.. correct logic but branching isn't right
  if ((sub_8095324(1) != 0) || (sub_8095324(7) != 0)) {
    if (iVar2 == 0xf1207) {
        sub_8090228(gUnknown_203B374->formattedLocation,sub_809769C());
    }
    else {
        ExpandPlaceholdersBuffer(gUnknown_203B374->formattedLocation,&gUnknown_80E780C); // Quicksave data deleted
    }
  }
  else {
    switch(sub_8011C1C())
    {
        default:
            ExpandPlaceholdersBuffer(gUnknown_203B374->formattedLocation,&gUnknown_80E7824); // Location unknown
            break;
        case 1:
            switch(sub_8001658(0,24))
            {
                default:
                    ExpandPlaceholdersBuffer(auStack356,&gUnknown_80E7804,sub_8098FB4());
                    xxx_format_string(auStack356,gUnknown_203B374->formattedLocation,gUnknown_203B374->formattedPlayTime,0);
                    break;
                case 0x7:
                case 0xB:
                    ExpandPlaceholdersBuffer(gUnknown_203B374->formattedLocation,&gUnknown_80E780C); // Quicksave data deleted
                    break;
            }
            break;
        case 2:
            if (iVar2 == 0xf1207)
            {
                sub_8090228(gUnknown_203B374->formattedLocation,sub_809769C());
            } else {
                ExpandPlaceholdersBuffer(gUnknown_203B374->formattedLocation,&gUnknown_80E780C); // Quicksave data deleted
            }
            break;
    }
  }
  xxx_call_draw_string(64,24,gUnknown_203B374->formattedLocation,0,0);

  // Draw Play Time
  DeconstructPlayTime(gPlayTimeRef,&hours,&minutes,&seconds);
  ExpandPlaceholdersBuffer(gUnknown_203B374->formattedPlayTime,&gUnknown_80E7838,hours,minutes,seconds);
  xxx_call_draw_string(64,36,gUnknown_203B374->formattedPlayTime,0,0);

  // Draw Adventures Info 
  numAdventures = GetNumAdventures();
  ExpandPlaceholdersBuffer(gUnknown_203B374->formattedAdventures,&gUnknown_80E7848,numAdventures); // %d
  xxx_call_draw_string(64,48,gUnknown_203B374->formattedAdventures,0,0);

  // Draw Helper Info
  if ((iVar2 == 0xf1207) && (gUnknown_203B484->speciesIndex != 0)) {
    sub_808D930(speciesHelper,gUnknown_203B484->speciesIndex);
    // TODO very hacky match here
    sub_80922B4(nameHelper,(u8 *)(&gUnknown_203B484 + 0x14),10);
    ExpandPlaceholdersBuffer(gUnknown_203B374->formattedHelperInfo,&gUnknown_80E784C,nameHelper,speciesHelper); // %s (%s)
  }
  else {
    ExpandPlaceholdersBuffer(gUnknown_203B374->formattedHelperInfo,&gUnknown_80E7854); // -----
  }
  xxx_call_draw_string(64,60,gUnknown_203B374->formattedHelperInfo,0,0);

  sub_80397B4(); // Draw event icons??
  sub_80073E0(0);
}
#else
NAKED
void DrawLoadScreenText(void)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tsub sp, 0x150\n"
	"\tbl sub_8011FA8\n"
	"\tmov r8, r0\n"
	"\tmovs r0, 0\n"
	"\tbl sub_8008C54\n"
	"\tmovs r0, 0\n"
	"\tbl sub_80073B8\n"
	"\tldr r2, _0803952C\n"
	"\tmovs r4, 0\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tmovs r1, 0\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r2, _08039530\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tmovs r1, 0xC\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r2, _08039534\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tmovs r1, 0x18\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r2, _08039538\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tmovs r1, 0x24\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r2, _0803953C\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tmovs r1, 0x30\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r2, _08039540\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tmovs r1, 0x3C\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tmovs r0, 0\n"
	"\tbl sub_80023E4\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08039544\n"
	"\tadd r4, sp, 0x68\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_80920D8\n"
	"\tadds r2, r4, 0\n"
	"\tb _0803954E\n"
	"\t.align 2, 0\n"
"_0803952C: .4byte gUnknown_80E77BC\n"
"_08039530: .4byte gUnknown_80E77C4\n"
"_08039534: .4byte gUnknown_80E77CC\n"
"_08039538: .4byte gUnknown_80E77D8\n"
"_0803953C: .4byte gUnknown_80E77E4\n"
"_08039540: .4byte gUnknown_80E77F0\n"
"_08039544:\n"
	"\tldr r1, _08039588\n"
	"\tadd r0, sp, 0x68\n"
	"\tbl strcpy\n"
	"\tadd r2, sp, 0x68\n"
"_0803954E:\n"
	"\tldr r5, _0803958C\n"
	"\tldr r0, [r5]\n"
	"\tmovs r4, 0xD2\n"
	"\tlsls r4, 1\n"
	"\tadds r0, r4\n"
	"\tldr r1, _08039590\n"
	"\tbl ExpandPlaceholdersBuffer\n"
	"\tldr r2, [r5]\n"
	"\tadds r2, r4\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [sp]\n"
	"\tmovs r0, 0x40\n"
	"\tmovs r1, 0\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tbl sub_808D33C\n"
	"\tcmp r0, 0\n"
	"\tbne _08039598\n"
	"\tadd r4, sp, 0x90\n"
	"\tldr r1, _08039594\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r2, 0xA\n"
	"\tbl sub_80922B4\n"
	"\tb _080395A6\n"
	"\t.align 2, 0\n"
"_08039588: .4byte gUnknown_80E77F8\n"
"_0803958C: .4byte gUnknown_203B374\n"
"_08039590: .4byte gUnknown_80E7804\n"
"_08039594: .4byte gUnknown_80E7808\n"
"_08039598:\n"
	"\tadd r4, sp, 0x90\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x4C\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r2, 0xA\n"
	"\tbl sub_80922B4\n"
"_080395A6:\n"
	"\tadds r2, r4, 0\n"
	"\tldr r5, _080395F0\n"
	"\tldr r0, [r5]\n"
	"\tmovs r4, 0xE4\n"
	"\tlsls r4, 1\n"
	"\tadds r0, r4\n"
	"\tldr r6, _080395F4\n"
	"\tadds r1, r6, 0\n"
	"\tbl ExpandPlaceholdersBuffer\n"
	"\tldr r2, [r5]\n"
	"\tadds r2, r4\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [sp]\n"
	"\tmovs r0, 0x40\n"
	"\tmovs r1, 0xC\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tmovs r0, 0x1\n"
	"\tbl sub_8095324\n"
	"\tcmp r0, 0\n"
	"\tbne _080395E0\n"
	"\tmovs r0, 0x7\n"
	"\tbl sub_8095324\n"
	"\tcmp r0, 0\n"
	"\tbeq _08039606\n"
"_080395E0:\n"
	"\tldr r0, _080395F8\n"
	"\tcmp r8, r0\n"
	"\tbne _080395FC\n"
	"\tldr r4, [r5]\n"
	"\tmovs r0, 0xF6\n"
	"\tlsls r0, 1\n"
	"\tadds r4, r0\n"
	"\tb _08039676\n"
	"\t.align 2, 0\n"
"_080395F0: .4byte gUnknown_203B374\n"
"_080395F4: .4byte gUnknown_80E7804\n"
"_080395F8: .4byte 0x000f1207\n"
"_080395FC:\n"
	"\tldr r0, [r5]\n"
	"\tmovs r1, 0xF6\n"
	"\tlsls r1, 1\n"
	"\tadds r0, r1\n"
	"\tb _08039690\n"
"_08039606:\n"
	"\tbl sub_8011C1C\n"
	"\tcmp r0, 0x1\n"
	"\tbeq _08039624\n"
	"\tcmp r0, 0x2\n"
	"\tbeq _08039668\n"
	"\tldr r0, [r5]\n"
	"\tmovs r2, 0xF6\n"
	"\tlsls r2, 1\n"
	"\tadds r0, r2\n"
	"\tldr r1, _08039620\n"
	"\tb _08039692\n"
	"\t.align 2, 0\n"
"_08039620: .4byte gUnknown_80E7824\n"
"_08039624:\n"
	"\tmovs r0, 0\n"
	"\tmovs r1, 0x18\n"
	"\tbl sub_8001658\n"
	"\tcmp r0, 0x7\n"
	"\tbeq _08039658\n"
	"\tcmp r0, 0xB\n"
	"\tbeq _08039658\n"
	"\tbl sub_8098FB4\n"
	"\tadds r2, r0, 0\n"
	"\tadd r0, sp, 0x4\n"
	"\tadds r1, r6, 0\n"
	"\tbl ExpandPlaceholdersBuffer\n"
	"\tldr r0, [r5]\n"
	"\tmovs r3, 0xF6\n"
	"\tlsls r3, 1\n"
	"\tadds r1, r0, r3\n"
	"\tadds r3, 0x24\n"
	"\tadds r2, r0, r3\n"
	"\tadd r0, sp, 0x4\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_format_string\n"
	"\tb _08039696\n"
"_08039658:\n"
	"\tldr r0, _08039664\n"
	"\tldr r0, [r0]\n"
	"\tmovs r1, 0xF6\n"
	"\tlsls r1, 1\n"
	"\tadds r0, r1\n"
	"\tb _08039690\n"
	"\t.align 2, 0\n"
"_08039664: .4byte gUnknown_203B374\n"
"_08039668:\n"
	"\tldr r0, _08039684\n"
	"\tcmp r8, r0\n"
	"\tbne _08039688\n"
	"\tldr r4, [r5]\n"
	"\tmovs r2, 0xF6\n"
	"\tlsls r2, 1\n"
	"\tadds r4, r2\n"
"_08039676:\n"
	"\tbl sub_809769C\n"
	"\tadds r1, r0, 0\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_8090228\n"
	"\tb _08039696\n"
	"\t.align 2, 0\n"
"_08039684: .4byte 0x000f1207\n"
"_08039688:\n"
	"\tldr r0, [r5]\n"
	"\tmovs r3, 0xF6\n"
	"\tlsls r3, 1\n"
	"\tadds r0, r3\n"
"_08039690:\n"
	"\tldr r1, _0803974C\n"
"_08039692:\n"
	"\tbl ExpandPlaceholdersBuffer\n"
"_08039696:\n"
	"\tldr r7, _08039750\n"
	"\tldr r2, [r7]\n"
	"\tmovs r0, 0xF6\n"
	"\tlsls r0, 1\n"
	"\tadds r2, r0\n"
	"\tmovs r6, 0\n"
	"\tstr r6, [sp]\n"
	"\tmovs r0, 0x40\n"
	"\tmovs r1, 0x18\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r0, _08039754\n"
	"\tldr r0, [r0]\n"
	"\tadd r1, sp, 0x144\n"
	"\tadd r2, sp, 0x148\n"
	"\tadd r3, sp, 0x14C\n"
	"\tbl DeconstructPlayTime\n"
	"\tldr r0, [r7]\n"
	"\tmovs r5, 0x84\n"
	"\tlsls r5, 2\n"
	"\tadds r0, r5\n"
	"\tldr r1, _08039758\n"
	"\tadd r2, sp, 0x144\n"
	"\tldr r2, [r2]\n"
	"\tadd r3, sp, 0x148\n"
	"\tldr r3, [r3]\n"
	"\tadd r4, sp, 0x14C\n"
	"\tldr r4, [r4]\n"
	"\tstr r4, [sp]\n"
	"\tbl ExpandPlaceholdersBuffer\n"
	"\tldr r2, [r7]\n"
	"\tadds r2, r5\n"
	"\tstr r6, [sp]\n"
	"\tmovs r0, 0x40\n"
	"\tmovs r1, 0x24\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tbl GetNumAdventures\n"
	"\tadds r2, r0, 0\n"
	"\tldr r0, [r7]\n"
	"\tmovs r4, 0x8D\n"
	"\tlsls r4, 2\n"
	"\tadds r0, r4\n"
	"\tldr r1, _0803975C\n"
	"\tbl ExpandPlaceholdersBuffer\n"
	"\tldr r2, [r7]\n"
	"\tadds r2, r4\n"
	"\tstr r6, [sp]\n"
	"\tmovs r0, 0x40\n"
	"\tmovs r1, 0x30\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tldr r0, _08039760\n"
	"\tcmp r8, r0\n"
	"\tbne _0803976C\n"
	"\tldr r0, _08039764\n"
	"\tldr r6, [r0]\n"
	"\tmovs r1, 0xC\n"
	"\tldrsh r0, [r6, r1]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0803976C\n"
	"\tadd r5, sp, 0x130\n"
	"\tadds r1, r0, 0\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_808D930\n"
	"\tadd r4, sp, 0xE0\n"
	"\tadds r1, r6, 0\n"
	"\tadds r1, 0x50\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r2, 0xA\n"
	"\tbl sub_80922B4\n"
	"\tldr r0, [r7]\n"
	"\tmovs r3, 0x96\n"
	"\tlsls r3, 2\n"
	"\tadds r0, r3\n"
	"\tldr r1, _08039768\n"
	"\tadds r2, r4, 0\n"
	"\tadds r3, r5, 0\n"
	"\tbl ExpandPlaceholdersBuffer\n"
	"\tb _0803977C\n"
	"\t.align 2, 0\n"
"_0803974C: .4byte gUnknown_80E780C\n"
"_08039750: .4byte gUnknown_203B374\n"
"_08039754: .4byte gPlayTimeRef\n"
"_08039758: .4byte gUnknown_80E7838\n"
"_0803975C: .4byte gUnknown_80E7848\n"
"_08039760: .4byte 0x000f1207\n"
"_08039764: .4byte gUnknown_203B484\n"
"_08039768: .4byte gUnknown_80E784C\n"
"_0803976C:\n"
	"\tldr r0, _080397AC\n"
	"\tldr r0, [r0]\n"
	"\tmovs r1, 0x96\n"
	"\tlsls r1, 2\n"
	"\tadds r0, r1\n"
	"\tldr r1, _080397B0\n"
	"\tbl ExpandPlaceholdersBuffer\n"
"_0803977C:\n"
	"\tldr r0, _080397AC\n"
	"\tldr r2, [r0]\n"
	"\tmovs r3, 0x96\n"
	"\tlsls r3, 2\n"
	"\tadds r2, r3\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [sp]\n"
	"\tmovs r0, 0x40\n"
	"\tmovs r1, 0x3C\n"
	"\tmovs r3, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tbl sub_80397B4\n"
	"\tmovs r0, 0\n"
	"\tbl sub_80073E0\n"
	"\tadd sp, 0x150\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_080397AC: .4byte gUnknown_203B374\n"
"_080397B0: .4byte gUnknown_80E7854");
}
#endif

// Think structure of clmkFile is like Team Rank Badges except each pic has a diff pallete
// TODO clean up but it matches so yea
void sub_80397B4(void)
{
  struct OpenedFile *clmkFile;
  int iVar3;
  int iVar4;
  s32 other_arg;
  
  clmkFile = OpenFileAndGetFileDataPtr(gUnknown_80E785C,&gTitleMenuFileArchive); // clmkpat

  for(iVar3 = 0; iVar3 < 64; iVar3++)
  {
    SetBGPaletteBufferColorArray(iVar3 + 176,*(int *)((clmkFile->data) + 4) + iVar3 * 4);
  }

  iVar4 = 8;
  other_arg = 0x49;
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
