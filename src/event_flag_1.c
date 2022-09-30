#include "global.h"
#include "constants/friend_area.h"
#include "friend_area.h"
#include "item.h"
#include "debug.h"
#include "other_random.h"
#include "rescue_team_info.h"
#include "team_inventory.h"

extern u8 sub_809761C(void);
extern u8 sub_80973F4(u32);
extern u8 _FlagJudge(u32, u32, u32);
extern u32 sub_8001658(u32, s32);
extern u32 _FlagCalc(s32, s32, u32);
extern void sub_80018D8(u32, u32, u32);
extern u8 HasRecruitedMon(u32);
extern void sub_809733C(u32, u32);
extern void sub_80973A8(u32, u32);
extern void sub_8097418(u32, u32);
extern s32 sub_8001784(u32, s32, u16);

extern u8 gUnknown_80B7144[];
extern u8 *gUnknown_80B71A0[];
extern u8 *gUnknown_80B714C[];
extern u8 gUnknown_80B7388[];
extern u8 gUnknown_80B7378[];

struct unkStruct_80B6D90
{
    u8 *text;
    s32 num;
};
extern struct unkStruct_80B6D90 gUnknown_80B6D90[];

extern u8 gUnknown_80B735C[];
extern u32 gUnknown_80B7350;
extern u8 gUnknown_80B7324[];
extern u32 gUnknown_80B7318;
extern u8 gUnknown_80B72CC[];

extern void sub_80976F8(u32);
extern void sub_800199C(u32, s32, u32, s32);
bool8 sub_8001CC4(u32 param_1,u32 param_2,s32 param_3);
bool8 sub_8001D44(u32 param_1,u32 param_2,s32 param_3);

void FatalError(u32 *, const char *, ...) __attribute__((noreturn));


// TODO: rectify with UnkEventStruct
struct UnkEventStruct2_sub
{
    /* 0x0 */ s16 *unk0;
    u32 fill4;
    s16 unk8;
};

struct UnkEventStruct2
{
    /* 0x0 */ struct UnkEventStruct2_sub *unk0;
    /* 0x4 */ u8 *unk4;
};


extern void sub_800160C(struct UnkEventStruct2 *r0, u32 r1, s32 r2);


u8 *sub_8001A74(s16 param_1)
{
  struct UnkEventStruct2 local_1c;
  
  sub_800160C(&local_1c,0,param_1);
  return local_1c.unk4;
}

s16 sub_8001A90(s16 param_1)
{
  struct UnkEventStruct2 local_1c;
  
  sub_800160C(&local_1c,0,param_1);
  return local_1c.unk0->unk8;
}

s32 sub_8001AB0(s32 param_1,s16 param_2)
{
  s32 iVar1;
  s32 counter;
  s32 total;
  struct UnkEventStruct2 local_1c;
  s32 param_2_s32;

  param_2_s32 = param_2;
  
  total = 0;
  sub_800160C(&local_1c,0,param_2_s32);
  counter = 0;
  if (counter < local_1c.unk0->unk8) {
    for(; counter < local_1c.unk0->unk8; counter++)
    {
      iVar1 = sub_8001784(param_1, param_2_s32, counter);
      total += iVar1;
    }
  }
  return total;
}

void sub_8001AF8(s16 param_1, u8 *param_2, s32 param_3)
{
  u8 *r1;
  s32 r2;
  u8 r0;
  struct UnkEventStruct2 local_10;
  
  sub_800160C(&local_10,0,param_1);
  for (r1 = local_10.unk4, r2 = 0; r2 < param_3; r2++) {
    r0 = *r1;
    if (*r1++ == 0) break;
    *param_2 = r0;
    param_2++;
  }
 *param_2 = 0;
}

void sub_8001B34(s16 param_1,u32 param_2,s32 param_3)
{
  u8 *r1;
  s32 r2;
  u8 r0;
  struct UnkEventStruct2 local_10;
  
  sub_800160C(&local_10,0,param_1);
  for (r1 = local_10.unk4, r2 = 0; r2 < param_3; r1++, r2++) {
    r0 = *r1;
    if (*r1++ == 0) break;
    *r1 = r0;
  }
  if (r2 < local_10.unk0->unk8) {
    for(; r2 < local_10.unk0->unk8; r1++, r2++)
    {
      *r1 = 0;
    }
  }
}

void sub_8001B88(s32 param_1,u32 *param_2,u32 *param_3)
{
  *param_2 = sub_8001784(0, (s16)param_1, 0);
  *param_3 = sub_8001784(0, (s16)param_1, 1);
}

void ScenarioCalc(s16 param_1,s32 param_2,s32 param_3)
{
  s32 param_1_s32;
  u32 local_18;
  u32 local_14;
  
  param_1_s32 = param_1;
  sub_8001B88(param_1_s32,&local_18,&local_14);
  Log(6,gUnknown_80B72CC,param_1_s32,local_18,local_14,param_2,param_3); // SCENARIO CALC [%3d] %4d %4d -> %4d %4d 
  if ((param_1_s32 == 3) && ((param_2 != local_18 || (param_3 != local_14)))) {
    sub_80018D8(0,0x19,0);
  }
  sub_800199C(0,param_1_s32,0,param_2);
  sub_800199C(0,param_1_s32,1,param_3);

  switch(param_1_s32)
  {
      case 3:
        if (((u32)(param_2 - 1) < 0x1b)) {
            if (sub_8001D44(3,8,-1)) {
                sub_80976F8(0);
            }
            if (sub_8001D44(3,0xb,3)) {
                sub_80976F8(1);
            }
            if (sub_8001D44(3,0x11,0)) {
                sub_80976F8(2);
            }
        }
        break;
      case 4:
        if (sub_8001CC4(4,0x1f,0) == 0) {
            sub_80976F8(4);
        }
        if (sub_8001CC4(4,0x20,0) == 0) {
            sub_80976F8(5);
        }
        break;
      case 0xC:
        if(sub_8001CC4(0xc,0x37,2) == 0) {
            sub_80976F8(3);
        }
        break;
  }
}

bool8 sub_8001CC4(u32 param_1,u32 param_2,s32 param_3)
{
  s32 uVar1;
  s32 iVar2;
  
  uVar1 = sub_8001784(0,(s16)param_1,0);
  iVar2 = sub_8001784(0,(s16)param_1,1);
  if ((uVar1 != 0x3a) &&
     (uVar1 < param_2 || (param_3 >= 0 && (uVar1 == param_2) && (iVar2 < param_3)))) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool8 sub_8001D08(u32 param_1,u32 param_2,s32 param_3)
{
  s32 uVar1;
  s32 iVar2;
  
  uVar1 = sub_8001784(0, (s16)param_1, 0);
  iVar2 = sub_8001784(0, (s16)param_1, 1);
  if (((uVar1 == param_2 && (((param_3 < 0) || (iVar2 == param_3)))))) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool8 sub_8001D44(u32 param_1,u32 param_2,s32 param_3)
{
  s32 uVar1;
  s32 iVar2;
  
  uVar1 = sub_8001784(0, (s16)param_1, 0);
  iVar2 = sub_8001784(0, (s16)param_1, 1);
  if ((uVar1 != 0x3a) &&
     ((uVar1 > param_2 || (((param_3 >= 0 && (uVar1 == param_2)) && (iVar2 > param_3)))))) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void sub_8001D88(void)
{
  u32 local_c;
  u32 auStack8;
  
  sub_8001B88(3, &auStack8, &local_c);
  if (auStack8 - 1 < 0x1b) {
    if (sub_8001CC4(4,0x1f,0) != 0) {
      if (sub_8001D44(3,0xf,7) != 0) {
        ScenarioCalc(4,0x1f,0);
        sub_8097418(0xe,1);
        sub_80018D8(0,0x28,2);
      }
      else {
        if ((sub_8001D08(4,0,0)) && (sub_8001D44(3,0xf,3) != 0)) {
          ScenarioCalc(4,0x1d,1);
        }
      }
    }
    if ((sub_8001D08(4,0x1f,0)) && (GetFriendAreaStatus(SKY_BLUE_PLAINS))) {
      ScenarioCalc(4,0x1f,1);
      sub_809733C(0xf,1);
    }
    if (auStack8 > 0x11) {
      sub_80973A8(0x25,1);
      if (((FindItemInInventory(ITEM_ID_DIVE) != -1) || (gTeamInventory_203B460->teamStorage[ITEM_ID_DIVE] != 0)) ||
         (sub_8001D44(5,0x21,3) != 0)) {
        sub_80973A8(0x22,1);
      }
      if (GetFriendAreaStatus(FURNACE_DESERT) != 0) {
        sub_80973A8(0x1f,1);
      }
      if (GetFriendAreaStatus(BOULDER_CAVE)) {
        sub_80973A8(0x20,1);
      }
      if (GetFriendAreaStatus(DRAGON_CAVE)) {
        sub_80973A8(0x21,1);
      }
      if (GetFriendAreaStatus(SECRETIVE_FOREST)) {
        sub_80973A8(0x23,1);
      }
      if (GetFriendAreaStatus(SERENE_SEA)) {
        sub_80973A8(0x24,1);
        sub_80973A8(0x28,1);
      }
      if ((GetFriendAreaStatus(AGED_CHAMBER_AN)) && (GetFriendAreaStatus(AGED_CHAMBER_O_EXCLAIM))) {
        sub_80973A8(0x26,1);
      }
      if (sub_8001D08(5,0,0)) {
        ScenarioCalc(5,0x21,1);
      }
      if ((FindItemInInventory(ITEM_ID_SURF) != -1) || (gTeamInventory_203B460->teamStorage[ITEM_ID_SURF] != 0)) {
        if (sub_8001D08(7,0,0)) {
          ScenarioCalc(7,0x26,1);
        }
        if ((sub_8001D08(9,0,0)) && (GetFriendAreaStatus(SOUTHERN_ISLAND))) {
          ScenarioCalc(9,0x2e,1);
        }
      }
      if (sub_8001CC4(9,0x30,0) == 0) {
        if ((sub_8001D08(5,0x22,0)) && HasRecruitedMon(SPECIES_ARTICUNO) && HasRecruitedMon(SPECIES_ZAPDOS) && HasRecruitedMon(SPECIES_MOLTRES)) {
          ScenarioCalc(5,0x22,1);
        }
        if (((sub_8001D08(0xb,0,0)) && (sub_8001D44(5,0x21,3) != 0)) &&
           (GetFriendAreaStatus(SKY_BLUE_PLAINS))) {
          ScenarioCalc(0xb,0x33,1);
        }
        if (GetFriendAreaStatus(SKY_BLUE_PLAINS)) {
          sub_80973A8(0x27,1);
        }
        if (GetFriendAreaStatus(SKY_BLUE_PLAINS)) {
          sub_80973A8(0x29,1);
        }
      }
      if (sub_8001CC4(5,0x22,0) == 0) {
        if (sub_8001D08(10,0,0)) {
          ScenarioCalc(10,0x31,1);
          sub_809733C(0x1b,1);
        }
        if ((sub_8001D08(0xc,0,0)) && (sub_8001CC4(0xb,0x34,0) == 0)) {
          ScenarioCalc(0xc,0x35,1);
        }
      }
      if ((sub_8001D08(6,0,0)) && (HasRecruitedMon(SPECIES_LUGIA))) {
        ScenarioCalc(6,0x24,1);
      }
      if ((sub_8001D08(8,0,0)) && (HasRecruitedMon(SPECIES_HO_OH))) {
        ScenarioCalc(8,0x2c,1);
      }
    }
  }
}

u32 _FlagCalc(s32 param_1, s32 param_2, u32 param_3)
{ 
  switch(param_3) {
    case 0:
        return param_2;
    case 1:
        return param_1 - param_2;
    case 2:
        return param_1 + param_2;
    case 3:
        return param_1 * param_2;
    case 4:
        return param_1 / param_2;
    case 5:
        return param_1 % param_2;
    case 6:
        return param_1 & param_2;
    case 7:
        return param_1 | param_2;
    case 8:
        return param_1 ^ param_2;
    case 9:
        return (1 << param_2) | param_1;
    case 10:
        return param_1 & ~(1 << param_2);
    case 0xb:
        return OtherRandomCapped(param_2);
    default:
        FatalError(&gUnknown_80B7318,gUnknown_80B7324, param_3); // event flag expansion error %d
  }
}

u8 _FlagJudge(u32 param_1, u32 param_2, u32 param_3)
{
  switch(param_3) {
      case 0:
        return 1;
      case 1:
        return 0;
      case 2:
        return param_1 == param_2;
      case 7:
        return (-(param_1 ^ param_2) | (param_1 ^ param_2)) >> 0x1f;  
      case 3:
        return (int)param_1 > (int)param_2;
      case 5:
        return (int)param_1 >= (int)param_2;
      case 4:
        return (int)param_1 < (int)param_2;
      case 6:
        return (int)param_1 <= (int)param_2;
      case 8:
          return (param_1 & param_2) != 0;
      case 9:
        return (param_1 ^ param_2) != 0;
      case 10:
        return (int)param_1 >> (param_2) & 1;
      default:
        FatalError(&gUnknown_80B7350,gUnknown_80B735C, param_3); // event flag rule error %d
  }
}

u32 FlagCalc(u32 r0, u32 r1, u32 r2)
{
    return _FlagCalc(r0, r1, r2);
}

void sub_800226C(u32 param_1, s16 param_2, s32 param_3, u32 param_4)
{
  u32 uVar1;
  u32 uVar3;

  s32 param_2_s32 = param_2;

  
  uVar1 = sub_8001658(param_1,param_2_s32  );
  uVar3 = _FlagCalc(uVar1,param_3,param_4);
  sub_80018D8(param_1,param_2_s32,uVar3);
}

void sub_80022A0(u32 param_1, s16 param_2, s16 param_3, u32 param_4)
{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;

  s32 param_2_s32 = param_2;
  s32 param_3_s32 = param_3;

  
  uVar1 = sub_8001658(param_1,param_2_s32);
  uVar2 = sub_8001658(param_1,param_3_s32);
  uVar3 = _FlagCalc(uVar1,uVar2,param_4);
  sub_80018D8(param_1,param_2_s32,uVar3);
}

u8 FlagJudge(u32 r0, u32 r1, u32 r2)
{
    return _FlagJudge(r0, r1, r2);
}

u8 sub_80022F8(u32 param_1, s16 param_2, s32 param_3, u32 param_4)
{
  u32 uVar1;
  
  uVar1 = sub_8001658(param_1, param_2);
  return _FlagJudge(uVar1,param_3,param_4);
}

u8 sub_8002318(u32 param_1, s16 param_2, s16 param_3, u32 param_4)
{
  u32 uVar1;
  u32 uVar2;

  s32 param_2_s32 = param_2;
  s32 param_3_s32 = param_3;
  
  uVar1 = sub_8001658(param_1,param_2_s32);
  uVar2 = sub_8001658(param_1,param_3_s32);
  return _FlagJudge(uVar1,uVar2,param_4);
}

s32 sub_8002354(u32 param_1)
{
  if (param_1 < 0x3b) {
    return gUnknown_80B6D90[param_1].num;
  }
  else {
    return -1;
  }
}

u8 *sub_8002374(u32 param_1)
{
  if (param_1 < 0x3b) {
    return gUnknown_80B6D90[param_1].text;
  }
  else {
    return gUnknown_80B7378;
  }
}

// Unused
u8 *sub_8002394(u32 param_1)
{
  if (param_1 - 0x12 < 9) {
    return  gUnknown_80B714C[param_1 - 0x12U];
  }
  else if (param_1 == 0xf) {
    return gUnknown_80B7388; // 1-1
  }
  else {
    return gUnknown_80B7144; // NONE
  }
}

// Unused
u8 *sub_80023C4(u32 param_1)
{
  if (param_1 < 4) {
   return gUnknown_80B71A0[param_1]; // CISTART, CECONTINUE, CNLAST, CWEND
  }
  else {
    return gUnknown_80B7144; // NONE
  }
}

u8 sub_80023E4(u32 param_1)
{
  switch(param_1) {
    case 0:
        return sub_8001D44(3,2,-1);
    case 1:
        return sub_8001D44(3,3,3);
    case 2:
        return sub_8001D44(3,4,3);
    case 3:
        return sub_8001D44(3,5,0);
    case 4:
        return (sub_8001D44(3,0xb,0) && sub_8001CC4(3,0xd,0));
    case 5:
        return (sub_8001D44(3,0xb,3) && sub_8001CC4(3,0xf,0));
    case 6:
        return sub_8001D44(3,0x11,-1);
    case 7:
        return sub_8001D44(3,0x12,2);
    case 8:
        return sub_8001D44(3,0x12,3);
    case 9:
        return sub_8001D44(3,0x12,-1);
    case 10:
        return sub_8001D44(3,5,4);
    case 0xb:
        return sub_8001D44(3,5,4);
    case 0xc:
        return (!sub_8001D08(3,0xb,2) && !sub_8001D08(3,0xb,3));
    case 0xd:
        return sub_8001D08(3,0x10,2);
    case 0xe:
        return !sub_8001CC4(3,5,7);
    case 0xf:
        return !sub_8001CC4(3,0xf,0);
    case 0x10:
        return sub_8001D44(3,7,-1);
    case 0x11:
        return sub_8001D44(3,0xc,-1);
    case 0x12:
        return sub_8001D44(3,0xd,-1);
    case 0x13:
        return sub_8001D44(3,0xf,-1);
    case 0x14:
        return sub_8001D44(3,0x10,-1);
    case 0x15:
        return sub_8001D44(5,0x21,-1);
    case 0x16:
        return sub_8001D44(5,0x22,-1);
    case 0x17:
        return sub_8001D44(6,0x24,-1);
    case 0x18:
        return sub_8001D44(7,0x2a,-1);
    case 0x19:
        return sub_8001D44(8,0x2c,-1);
    case 0x1a:
        return sub_8001D44(10,0x31,-1);
    case 0x1b:
        return sub_80973F4(0x29);
    case 0x1c:
        return GetRescueTeamRank() == LUCARIO_RANK;
    case 0x1d:
        return sub_809761C();
    default:
        return 0;
  }
}
