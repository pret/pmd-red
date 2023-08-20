#include "global.h"
#include "friend_area.h"
#include "constants/friend_area.h"
#include "constants/input.h"
#include "file_system.h"
#include "friend_list_menu.h"
#include "item.h"
#include "menu.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "memory.h"
#include "input.h"
#include "text1.h"
#include "text2.h"
#include "rescue_team_info.h"
#include "code_800D090.h"
#include "menu_input.h"
#include "code_8021774.h"
#include "code_80118A4.h"
#include "wigglytuff_shop.h"
#include "event_flag.h"

struct unkStruct_203B258
{
    // size: 0xA0
    struct MenuInputStruct input;
    u32 unk34;
    struct UnkTextStruct2 *unk38;
    struct UnkTextStruct2 unk3C[4];
    u8 unk9C[4];
};

extern struct unkStruct_203B258 *gUnknown_203B258;
extern struct UnkTextStruct2 gUnknown_80DBF88;
extern struct UnkTextStruct2 gUnknown_80DBF70;

struct unkStruct_811BAF4
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 *text;
};

extern struct unkStruct_811BAF4 gUnknown_811BAF4[10];

struct unkStruct_81188F0
{
    u8 *text1;
    u8 *text2;
    u8 *text3;
    u8 *text4;
    u32 unk1;
    u32 unk2;
    u32 unk3;
};

extern struct unkStruct_81188F0 gUnknown_81188F0[10];
extern u8 gUnknown_80DBFA0[]; // Field


extern void sub_801DB54();
extern void sub_801DBD4();

extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern void sub_801D208(u8);
extern u32 sub_801DCE8(void);
extern void sub_801DD50(void);
extern u32 sub_8022860();
extern void sub_8022908();
extern u32 sub_80244E4(void);
extern void sub_802453C(void);
extern u32 sub_8025F68();
extern u8 sub_802604C();
extern void sub_8026058();
extern void sub_8027168();
extern u32 sub_80270A4();
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);
extern void InitializeJobListMenu(u32);

extern const char *sub_8098FB4();
extern void xxx_format_string(const char *, u8 *, u32 **, u32);
extern s32 sub_8008ED0(u8 *);
void LoadTeamRankBadge(u32, u32, u32);
extern void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray);

extern struct FileArchive gTitleMenuFileArchive;
extern const char gTeamRankBadgeFileName;

extern u8 gAvailablePokemonNames[];

extern char gUnknown_80DBF3C[];
extern char gUnknown_80DBF4C[];
extern u8 gMenuItems[];
extern u8 gMenuJobList[];
extern u8 gMenuTeam[];
extern u8 gMenuOthers[];
extern u8 *gUnknown_80D49B4[];
extern u8 gUnknown_80DBF34[];
extern u8 *gUnknown_80D49A8[];
extern u8 *gUnknown_80D4970[];

struct TeamBadgeData
{
    /* 0x0 */ u8 *pics; // probably a pointer to an arrays of pixels?
    /* 0x4 */ u8 *pallete; // Pics share common pallete
};

struct unk_203B250
{
    struct PokemonStruct *pokeStruct;
    s16 index;
    /* 0x6 */ u8 currFriendAreaLocation; // 0 when not in a friend area
    u8 unk7;
    u8 unk8;
    u8 unk9;
    struct PokemonStruct *unkC;
    u32 state;
    u32 menuAction;
    struct MenuStruct unk18;
    struct MenuItem unk68[8];
    u16 unkA8[8];
    struct UnkTextStruct2 unkB8[4];
};

struct unk_203B250 *gUnknown_203B250;

extern bool8 HasNoAcceptedJobs(void);
extern bool8 sub_8024108(u32);
extern bool8 sub_8096E2C(void);
extern u32 sub_801DCC4(void);
extern u32 sub_8027074(void);
extern void sub_80227B8(struct PokemonStruct *);
extern bool8 sub_8024458(s16, u32);
extern bool8 sub_801BEEC(s16);
void sub_801D894(void);
u32 sub_8025EF4(struct PokemonStruct *);

void sub_801D3A8(void)
{
    switch(gUnknown_203B250->state)
    {
        case 0:
        case 1:
            if(gUnknown_203B250->pokeStruct != NULL)
                {
                    PrintColoredPokeNameToBuffer(gAvailablePokemonNames, gUnknown_203B250->pokeStruct, 7);
                    gUnknown_203B250->unk18.unk0 = gAvailablePokemonNames;
                    sub_8012D60(&gUnknown_203B250->unk18, gUnknown_203B250->unk68, 0, gUnknown_203B250->unkA8, gUnknown_203B250->menuAction, 0);
                }
            else {
                sub_801D894();
                sub_8012D60(&gUnknown_203B250->unk18, gUnknown_203B250->unk68, 0, gUnknown_203B250->unkA8, gUnknown_203B250->menuAction, 0);
            }
            break;
        case 3:
            sub_80227B8(gUnknown_203B250->pokeStruct);
            break;
        case 4:
            sub_8027074();
            break;
        case 5:
            sub_8025EF4(gUnknown_203B250->pokeStruct);
            break;
        case 6:
            sub_80252F0(0);
            break;
        case 7:
            sub_80252F0(1);
            break;
        case 8:
            sub_8024458(gUnknown_203B250->index, 2);
            break;
        case 9:
            sub_801BEEC(gUnknown_203B250->index);
            break;
        case 10:
            sub_8021774(gUnknown_203B250->currFriendAreaLocation, TRUE, 2);
            break;
        case 11:
            InitializeJobListMenu(0);
            break;
        case 12:
            sub_801DCC4();
            break;
    }
}

void sub_801D4C0(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B250->unkA8,0,sizeof(gUnknown_203B250->unkA8));
    if (gUnknown_203B250->currFriendAreaLocation == 0) {
        if (sub_8096E2C()) {
            gUnknown_203B250->unk68[loopMax].menuAction = 2;
            gUnknown_203B250->unk68[loopMax].text = gMenuItems;
            if (GetNumberOfFilledInventorySlots() == 0) {
                gUnknown_203B250->unkA8[loopMax] = 1;
            }
            loopMax++;
            gUnknown_203B250->unk68[loopMax].text = gMenuTeam;
            gUnknown_203B250->unk68[loopMax].menuAction = 4;
            loopMax++;
            if (sub_80023E4(2)) {
                gUnknown_203B250->unk68[loopMax].text = gMenuJobList;
                gUnknown_203B250->unk68[loopMax].menuAction = 9;
                if (HasNoAcceptedJobs()) {
                    gUnknown_203B250->unkA8[loopMax] = 1;
                }
                loopMax++;
            }
        }
        gUnknown_203B250->unk68[loopMax].text = gMenuOthers;
        gUnknown_203B250->unk68[loopMax].menuAction = 0xb;
        loopMax++;
    }
    else {
        strcpy(gAvailablePokemonNames,gUnknown_80DBF34);
        if (sub_8096E2C()) {
            gUnknown_203B250->unk68[loopMax].text = *gUnknown_80D49A8;
            gUnknown_203B250->unk68[loopMax].menuAction = 5;
            if (sub_8024108(4)) {
                gUnknown_203B250->unkA8[loopMax] = 1;
            }
            loopMax++;
            gUnknown_203B250->unk68[loopMax].menuAction = 2;
            gUnknown_203B250->unk68[loopMax].text = gMenuItems;
            if (GetNumberOfFilledInventorySlots() == 0) {
                gUnknown_203B250->unkA8[loopMax] = 1;
            }
            loopMax++;
        }

        gUnknown_203B250->unk68[loopMax].text = *gUnknown_80D4970;
        gUnknown_203B250->unk68[loopMax].menuAction = 8;
        loopMax++;
        gUnknown_203B250->unk68[loopMax].text = *gUnknown_80D49B4;
        gUnknown_203B250->unk68[loopMax].menuAction = 10;
        loopMax++;
    }
    gUnknown_203B250->unk68[loopMax].text = NULL;
    gUnknown_203B250->unk68[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B250->unkA8[index] == 0)
        {
            if(gUnknown_203B250->unk68[index].menuAction == gUnknown_203B250->menuAction)
            {
                return;
            }
        }
    }

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B250->unkA8[index] == 0)
        {
            gUnknown_203B250->menuAction = gUnknown_203B250->unk68[index].menuAction;
            break;
        }
    }
}

void sub_801D680(void)
{
  int menuAction;

  menuAction = 0;
  if (!(sub_8012FD8(&gUnknown_203B250->unk18)) && (sub_8013114(&gUnknown_203B250->unk18,&menuAction), menuAction != 1)) {
    gUnknown_203B250->menuAction = menuAction;
  }
  switch(menuAction) {
      case 2:
        sub_801D208(3);
        break;
      case 4:
        sub_801D208(6);
        break;
      case 3:
        sub_801D208(4);
        break;
      case 5:
        sub_801D208(7);
        break;
      case 6:
        sub_801D208(8);
        break;
      case 7:
        sub_801D208(9);
        break;
      case 8:
        sub_801D208(10);
        break;
      case 9:
        sub_801D208(0xb);
        break;
      case 10:
        gUnknown_203B250->unk9 = 1;
        sub_801D208(2);
        break;
      case 11:
        sub_801D208(0xc);
        break;
      case 1:
        sub_801D208(2);
        break;
  }
}

void sub_801D760()
{
    switch(sub_8022860())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_8022908();
            sub_801D208(1);
            break;
    }
}

void sub_801D77C()
{
    switch(sub_80270A4())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_8027168();
            sub_801D208(1);
            break;
    }
}

void sub_801D798(void)
{
    switch(sub_8025F68())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            if(sub_802604C() != 0)
                gUnknown_203B250->unk7 = gUnknown_203B250->currFriendAreaLocation;
            sub_8026058();
            sub_801D208(2);
            break;
    }
}

void sub_801D7CC()
{
    switch(sub_8025354())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            gUnknown_203B250->unk7 = sub_802540C();
            sub_8025418();
            if(gUnknown_203B250->unk7 != 0)
            {
                sub_801D208(2);
            }
            else
            {
                sub_801D208(1);
            }
            break;
    }
}

void sub_801D808(void)
{
    switch(sub_80244E4())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_802453C();
            sub_801D208(1);
            break;
    }
}

void sub_801D824(void)
{
    switch(sub_801BF48())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801BF98();
            sub_801D208(1);
            break;
    }
}

void sub_801D840(void)
{
    switch(sub_80217EC())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_8021830();
            sub_801D208(1);
            break;
    }
}

void sub_801D85C(void)
{
    switch(sub_802C898())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_802C8F4();
            sub_801D208(1);
            break;
    }
}

void sub_801D878(void)
{
    switch(sub_801DCE8())
    {
        case 0:
        case 1:
        default:
            break;
        case 2:
        case 3:
            sub_801DD50();
            sub_801D208(1);
            break;
    }
}

void sub_801D894(void)
{
  u8 rank;
  const char *location;
  int location_length;
  s32 x_coord;

  // Stored on stack
  u32 *preload_string;
  char *r5; // R5
  char buffer [96]; // sp +4

  if (gUnknown_203B250->currFriendAreaLocation == NONE) {
    location = sub_8098FB4();
  }
  else {
    location = GetFriendAreaName(gUnknown_203B250->currFriendAreaLocation);
  }
  // TODO this is def a hack
  xxx_format_string(location, buffer, &preload_string + 1, 0);
  location_length = sub_8008ED0(buffer);
  x_coord = (128 - location_length) / 2; // Centers the location name
  sub_8008C54(1);
  sub_80073B8(1);
  xxx_call_draw_string(x_coord, 4, buffer, 1, 0);
  sub_80073E0(1);
  sub_8008C54(2);
  sub_80073B8(2);
  LoadTeamRankBadge(2, 8, 6);

// Have to load before TeamRank funcs
  r5 = gUnknown_80DBF3C; // %s {COLOR_1 CYAN}%d{END_COLOR_TEXT_1} Pts.
  rank = GetRescueTeamRank();
  sprintfStatic(buffer, r5, GetTeamRankString(rank), GetTeamRankPts());
  xxx_call_draw_string(32, 4, buffer, 2, 0);
  sprintfStatic(buffer, gUnknown_80DBF4C, gTeamInventoryRef->teamMoney);
  xxx_call_draw_string(32, 18, buffer, 2, 0);
  sub_80073E0(2);
}

void LoadTeamRankBadge(u32 param_1, u32 param_2, u32 param_3)
{
  struct OpenedFile *teamBadgeFile;
  s32 palleteIndex;
  u8 rank;
  u8 *colorArray;
  u8 *teamBadgePic;

  teamBadgeFile = OpenFileAndGetFileDataPtr(&gTeamRankBadgeFileName, &gTitleMenuFileArchive);
  teamBadgePic = ((struct TeamBadgeData *)(teamBadgeFile->data))->pics;
  colorArray = ((struct TeamBadgeData *)(teamBadgeFile->data))->pallete;
  for(palleteIndex = 0; palleteIndex < 16; palleteIndex++){
    SetBGPaletteBufferColorArray(palleteIndex + 224,colorArray);
    colorArray = colorArray + 4;
  }
  rank = GetRescueTeamRank();
  teamBadgePic = &teamBadgePic[rank << 7]; // TODO figure out why the lft shft 7 is needed
  sub_8007E20(param_1, param_2, param_3, 16, 16, teamBadgePic, 14);
  CloseFile(teamBadgeFile);
}

u32 sub_801D9E4(void)
{
  gUnknown_203B258 = MemoryAlloc(sizeof(struct unkStruct_203B258),8);
  gUnknown_203B258->unk34 = 3;
  gUnknown_203B258->unk38 = &gUnknown_203B258->unk3C[3];
  sub_8006518(gUnknown_203B258->unk3C);
  gUnknown_203B258->unk3C[gUnknown_203B258->unk34] = gUnknown_80DBF88;
  gUnknown_203B258->unk38->unk14 = gUnknown_203B258->unk9C;
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B258->unk3C,1,1);
  sub_8013818(&gUnknown_203B258->input,0xe5,10,gUnknown_203B258->unk34);
  sub_801DB54();
  sub_801DBD4();
  return 1;
}

void sub_801DA58(s16 param_0)
{
    s32 cast;
    cast = param_0;
    sub_8013878(&gUnknown_203B258->input, cast);
    sub_801DB54();
    sub_801DBD4();
}

u32 sub_801DA78(void)
{
    switch(GetKeyPress(&gUnknown_203B258->input))
    {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            return 3;
        default:
            if(sub_80138B8(&gUnknown_203B258->input, 1) != 0)
            {
                sub_801DB54();
                sub_801DBD4();
                return 1;
            }
            else {
                return 0;
            }
    }
}

s16 sub_801DAC0(void)
{
    return (gUnknown_203B258->input.unk1E * gUnknown_203B258->input.unk1C) + gUnknown_203B258->input.menuIndex;
}

void sub_801DADC(u8 r0)
{
    gUnknown_203B258->input.unk22 = 0xE5;
    sub_8013984(&gUnknown_203B258->input);
    sub_801DB54();
    sub_801DBD4();
    if(r0)
        AddMenuCursorSprite(&gUnknown_203B258->input);
}

void sub_801DB0C(void)
{
    if(gUnknown_203B258 != NULL)
    {
        gUnknown_203B258->unk3C[gUnknown_203B258->unk34] = gUnknown_80DBF70;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B258->unk3C, 1, 1);
        MemoryFree(gUnknown_203B258);
        gUnknown_203B258 = NULL;
    }
}

NAKED
void sub_801DB54(void)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tldr r4, _0801DBD0\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9C\n"
	"\tmovs r2, 0\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9D\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9E\n"
	"\tmovs r1, 0x8\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x9F\n"
	"\tstrb r2, [r0]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0x1A\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r4]\n"
	"\tldr r3, [r2, 0x34]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x4A\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x34]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x4C\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x3C\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0801DBD0: .4byte gUnknown_203B258");
}

void sub_801DBD4(void)
{
    struct unkStruct_811BAF4 *temp;
    struct unkStruct_81188F0 *temp2;
    s32 y;
#ifndef NONMATCHING
    register s32 x asm("r4");
#else
    register s32 x;
#endif
    s16 index;
    int counter;

    sub_8008C54(gUnknown_203B258->unk34);
    sub_80073B8(gUnknown_203B258->unk34);
    xxx_call_draw_string(10,0,gUnknown_80DBFA0,gUnknown_203B258->unk34,0); // Field
    x = gUnknown_203B258->unk9C[2] * 8 - 2;
    sub_8012BC4(x,0,gUnknown_203B258->input.unk1E + 1,2,7,gUnknown_203B258->unk34);
    for(counter = 0; counter < gUnknown_203B258->input.unk1A; counter++)
    {
        index = gUnknown_203B258->input.unk1E * gUnknown_203B258->input.unk1C + counter;
        temp = &gUnknown_811BAF4[index];
        temp2 = &gUnknown_81188F0[temp->unk4];
        y = sub_8013800(&gUnknown_203B258->input, counter);
        xxx_call_draw_string(8,y,temp2->text1,gUnknown_203B258->unk34,0);
        y = sub_8013800(&gUnknown_203B258->input,counter);
        xxx_call_draw_string(0x3e,y,temp->text,gUnknown_203B258->unk34,0);
    }
    sub_80073E0(gUnknown_203B258->unk34);
}
