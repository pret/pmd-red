#include "global.h"
#include "constants/friend_area.h"
#include "file_system.h"

extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern void sub_801D208(u8);
extern u32 sub_801DCE8(void);
extern void sub_801DD50(void);
extern u32 sub_80217EC(void);
extern void sub_8021830(void);
extern u32 sub_8022860();
extern void sub_8022908();
extern u32 sub_80244E4(void);
extern void sub_802453C(void);
extern u32 sub_8025354(void);
extern u8 sub_802540C(void);
extern void sub_8025418(void);
extern u32 sub_8025F68();
extern u8 sub_802604C();
extern void sub_8026058();
extern void sub_8027168();
extern u32 sub_80270A4();
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);

extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);
extern const char *sub_8098FB4();
extern void xxx_format_string(const char *, u8 *, u32 **, u32);
extern const char *GetFriendAreaName(u8);
extern s32 sub_8008ED0(u8 *);
extern void  xxx_call_draw_string(s32 size, u32, u8 *, u32, u32);
extern const char *GetFriendAreaName(u8);
extern u8 GetRescueTeamRank();
extern const char *GetTeamRankString(u8);
extern s32 GetTeamRankPts();
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
void LoadTeamRankBadge(u32, u32, u32);
extern void sub_800D158(u8 *, u32 *, ...);
extern void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray);
extern void sub_8007E20(u32, u32, u32, u32, u32, u8 *, u32);

extern struct FileArchive gTitleMenuFileArchive;
extern const char gTeamRankBadgeFileName;

extern u32 gUnknown_80DBF3C;
extern u32 gUnknown_80DBF4C;

struct TeamBadgeData
{
    /* 0x0 */ u8 *pics; // probably a pointer to an arrays of pixels?
    /* 0x4 */ u8 *pallete; // Pics share common pallete
};

struct unk_203B250
{
    u32 unk0;
    u16 unk4;
    /* 0x6 */ u8 currFriendAreaLocation; // 0 when not in a friend area
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 fillA[0x14 - 0xA];
    u32 unk14;
    u32 unk18; // an input struct??
};

struct unk_203B250 *gUnknown_203B250;

struct unkStruct_203B460
{
    u8 padding[0x260];
    /* 0x260 */ u32 teamMoney;
};

extern struct unkStruct_203B460 *gUnknown_203B460;

void sub_801D680(void)
{
  int local_c;
  
  local_c = 0;
  if ((sub_8012FD8(&gUnknown_203B250->unk18) == '\0') && (sub_8013114(&gUnknown_203B250->unk18,&local_c), local_c != 1)) {
    gUnknown_203B250->unk14 = local_c;
  }
  switch(local_c) {
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
    u32 temp;
    temp = sub_8022860();
    if (temp <= 1)
        return;
    if (temp > 3)
        return;
    sub_8022908();
    sub_801D208(1);

}

void sub_801D77C()
{
    u32 temp;
    temp = sub_80270A4();
    if (temp <= 1)
        return;
    if (temp > 3)
        return;
    sub_8027168();
    sub_801D208(1);

}

void sub_801D798(void)
{
    u32 temp;
    temp = sub_8025F68();
    if (temp <= 1)
        return;
    if (temp > 3)
        return;
    if(sub_802604C() != 0)
        gUnknown_203B250->unk7 = gUnknown_203B250->currFriendAreaLocation;
    sub_8026058();
    sub_801D208(2);
}

void sub_801D7CC()
{
    u32 check;
    u32 temp2;

    check = sub_8025354();
    if(check <= 1)
        return;
    if(check > 3)
        return;

    temp2 = sub_802540C();
    gUnknown_203B250->unk7 = temp2;

    sub_8025418();

    if(gUnknown_203B250->unk7 != 0)
    {
        sub_801D208(2);
    }
    else
    {
        sub_801D208(1);
    }
}

void sub_801D808(void)
{
    u32 check;

    check = sub_80244E4();
    if(check <= 1)
        return;
    if(check > 3)
        return;

    sub_802453C();
    sub_801D208(1);
}

void sub_801D824(void)
{
    u32 check;
    check = sub_801BF48();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_801BF98();
    sub_801D208(1);
}

void sub_801D840(void)
{
    u32 check;
    check = sub_80217EC();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_8021830();
    sub_801D208(1);
}

void sub_801D85C(void)
{
    u32 check;
    check = sub_802C898();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_802C8F4();
    sub_801D208(1);
}

void sub_801D878(void)
{
    u32 check;
    check = sub_801DCE8();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_801DD50();
    sub_801D208(1);
}

void sub_801D894(void)
{
  u8 uVar1;
  const char *location;
  int iVar3;
  s32 size_var;

  // Stored on stack
  u32 *preload_string;
  u32 *r5; // R5
  u8 auStack116 [96]; // sp +4
  
  if (gUnknown_203B250->currFriendAreaLocation == NONE) {
    location = sub_8098FB4();
  }
  else {
    location = GetFriendAreaName(gUnknown_203B250->currFriendAreaLocation);
  }
  // TODO this is def a hack
  xxx_format_string(location, auStack116, &preload_string + 1, 0);
  iVar3 = sub_8008ED0(auStack116);
  size_var = (0x80 - iVar3) / 2; // have to calculate here
  sub_8008C54(1);
  sub_80073B8(1);
  xxx_call_draw_string(size_var, 4, auStack116, 1, 0);
  sub_80073E0(1);
  sub_8008C54(2);
  sub_80073B8(2);
  LoadTeamRankBadge(2, 8, 6);

  r5 = &gUnknown_80DBF3C; // Have to load before TeamRank funcs
  uVar1 = GetRescueTeamRank();
  sub_800D158(auStack116, r5, GetTeamRankString(uVar1), GetTeamRankPts());
  xxx_call_draw_string(0x20, 4, auStack116, 2, 0);
  sub_800D158(auStack116, &gUnknown_80DBF4C, gUnknown_203B460->teamMoney);
  xxx_call_draw_string(0x20, 0x12, auStack116, 2, 0);
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
