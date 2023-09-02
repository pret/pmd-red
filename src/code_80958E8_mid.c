#include "global.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/wonder_mail.h"
#include "items.h"
#include "random.h"
#include "friend_area.h"
#include "code_80958E8.h"

bool8 sub_8095E38(struct WonderMail *mail, u8 dungeon, u32 floor, u8 param_4);
extern s32 sub_80A29B0(u8 *param_1);
extern s32 GetDungeonFloorCount(u8);
extern bool8 sub_809017C(DungeonLocation *);

bool8 GenerateMailJobDungeonInfo(struct WonderMail *mail)
{
  s32 counter;
  s32 floor;
  s32 index;
  u8 dungeon;
  bool8 flag;
  u8 dungeonStack [64];
  s32 counter_1;
  s32 cap;
  s32 floor_1;
  s32 halfFloorCount;
  s32 floorCount;
  DungeonLocation dungeonLoc;
  

  cap = sub_80A29B0(dungeonStack);
  if (cap == 0) {
    dungeonStack[0] = DUNGEON_TINY_WOODS;
    dungeonStack[1] = DUNGEON_THUNDERWAVE_CAVE;
    cap = 2;
  }
  counter = RandInt(cap);
  counter_1 = counter;
  do {
    dungeon = dungeonStack[counter];
    floorCount = GetDungeonFloorCount(dungeon);
    halfFloorCount = floorCount / 2;
    floor = RandRange(halfFloorCount, floorCount);
    floor_1 = floor;
    do {
      flag = TRUE;
      dungeonLoc.id = dungeon;
      dungeonLoc.floor = floor;

      if(sub_809017C(&dungeonLoc))
        flag = FALSE;

      for(index = 0; index < 4; index++)
      {
        if (sub_8095E38(&gUnknown_203B490->mailboxSlots[index],dungeon,floor,1)) {
          flag = FALSE;
        }
      }

      for(index = 0; index < 8; index++)
      {
        if (sub_8095E38(&gUnknown_203B490->pelipperBoardJobs[index],dungeon,floor,1)) {
          flag = FALSE;
        }
      }

      for(index = 0; index < 8; index++)
      {
        if (sub_8095E38(&gUnknown_203B490->jobSlots[index],dungeon,floor,1)) {
          flag = FALSE;
        }
      }

      if (flag) {
        mail->unk4.dungeon.id = dungeon;
        mail->unk4.dungeon.floor = floor;
        return TRUE;
      }
      floor++;
      if (floor >= floorCount) {
        floor = halfFloorCount;
      }
    } while (floor != floor_1);
    
    counter++;
    if (counter == cap) {
      counter = 0;
    }
    if (counter == counter_1) {
      return FALSE;
    }
  } while( TRUE );
}

bool8 sub_8095E38(struct WonderMail *mail, u8 dungeon, u32 floor, u8 param_4)
{
    if (mail->mailType != MAIL_TYPE_NONE) {
        if ((mail->missionType == WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT) && (param_4 == 1)) {
            if (mail->unk4.dungeon.id == dungeon) {
                return TRUE;
            }
        }
        else if ((mail->unk4.dungeon.id == dungeon) && (mail->unk4.dungeon.floor == floor)) {
            return TRUE;
        }
    }
    return FALSE;
}

u8 sub_8095E78(void)
{
  bool8 flag;
  s32 index;
  s32 friendAreaIndex;
  s32 counter;

  u8 friendAreaStack[NUM_FRIEND_AREAS];
  
  counter = 0;
  for(friendAreaIndex = BOUNTIFUL_SEA; friendAreaIndex < NUM_FRIEND_AREAS; friendAreaIndex++)
  {
    if ((!gFriendAreas[friendAreaIndex]) &&
       (GetFriendAreaUnlockCondition(friendAreaIndex) == UNLOCK_WONDER_MAIL)) {
        flag = FALSE;


        for(index = 0; index < 4; index++)
        {
            if((gUnknown_203B490->mailboxSlots[index].mailType != MAIL_TYPE_NONE) && (gUnknown_203B490->mailboxSlots[index].rewardType == FRIEND_AREA))
                flag = TRUE;
        }
      

        for(index = 0; index < 8; index++)
        {
            if((gUnknown_203B490->jobSlots[index].mailType != MAIL_TYPE_NONE) && (gUnknown_203B490->jobSlots[index].rewardType == FRIEND_AREA))
                flag = TRUE;
        }

        if (!flag) {
            friendAreaStack[counter] = friendAreaIndex;
            counter++;
        }
    }
  }
  if (counter != 0) {
    return friendAreaStack[RandInt(counter)];
  }
  else {
    return NONE;
  }
}

u8 sub_8095F28(u8 param_1)
{
  s32 itemID;
  s32 counter;
  u8 itemStack [NUMBER_OF_ITEM_IDS];
  
  counter = 0;
  for(itemID = ITEM_STICK; itemID < NUMBER_OF_ITEM_IDS; itemID++)
  {
    if ((param_1 == 0x63) ||
       (xxx_bit_lut_lookup_8091E50(param_1, itemID) != 0)) {
      if ((!IsThrowableItem(itemID)) && (IsNotMoneyOrUsedTMItem(itemID))) {
        itemStack[counter] = itemID;
        counter++;
      }
    }
  }
  if (counter == 0) {
    return ITEM_NOTHING;
  }
  else {
    return itemStack[RandInt(counter)];
  }
}
