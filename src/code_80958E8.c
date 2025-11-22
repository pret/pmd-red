#include "global.h"
#include "globaldata.h"
#include "code_803C1D0.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"
#include "rescue_scenario.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/wonder_mail.h"
#include "dungeon_info.h"
#include "random.h"
#include "friend_area.h"
#include "items.h"
#include "memory.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "pokemon_mail.h"
#include "event_flag.h"
#include "rescue_team_info.h"
#include "code_803C1B4.h"

bool8 sub_8095E38(WonderMail *mail, u8 dungeon, u32 floor, u8 param_4);
u8 sub_8095F28(u8 param_1);
bool8 GenerateMailJobDungeonInfo(WonderMail *mail);
bool8 GenerateMailJobInfo(WonderMail *);
bool8 sub_8096E80(u8);
u8 sub_8095E78(void);
bool8 sub_80963B4(void);
s32 CalculateMailChecksum(WonderMail *mail);

extern void sub_803C4F0(WonderMail *);
extern void sub_803C3E0(WonderMail *);
extern void sub_803C45C(WonderMail *);
extern void sub_803C610(WonderMail *);
extern void sub_803C580(WonderMail *);

static const u8 sPossibleMissionTypes[] = {MISSION_TYPE_FRIEND_RESCUE, MISSION_TYPE_FIND_ITEM, MISSION_TYPE_DELIVER_ITEM, MISSION_TYPE_RESCUE_CLIENT, MISSION_TYPE_RESCUE_TARGET, MISSION_TYPE_DELIVER_ITEM, MISSION_TYPE_FIND_ITEM, MISSION_TYPE_FRIEND_RESCUE};

static EWRAM_DATA unkStruct_203B490 sUnknown_2039448 = {0};

EWRAM_INIT unkStruct_203B490 *gUnknown_203B490 = {0};

void LoadMailInfo(void)
{
    gUnknown_203B490 = &sUnknown_2039448;
}

unkStruct_203B490 *GetMailInfo(void)
{
    return &sUnknown_2039448;
}

void InitializeMailJobsNews(void)
{
    s32 index;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        ResetMailboxSlot(index);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        ResetPelipperBoardSlot(index);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        ResetJobSlot(index);
    }
    for(index = 0; index < NUM_POKEMON_NEWS; index++)
    {
        gUnknown_203B490->PKMNNewsReceived[index] = FALSE;
    }
    gUnknown_203B490->unk328 = FALSE;
    MemoryClear8(gUnknown_203B490->unk190, sizeof(gUnknown_203B490->unk190));
    MemoryClear8(gUnknown_203B490->unk1B8, sizeof(gUnknown_203B490->unk1B8));
    for(index = 0; index < 16; index++)
    {
        gUnknown_203B490->unk230[index].dungeonSeed.location.id = 99;
        gUnknown_203B490->unk230[index].dungeonSeed.location.floor = 1;
        gUnknown_203B490->unk230[index].dungeonSeed.seed = 0;
        gUnknown_203B490->unk230[index].checksum = 0;
    }
}

bool8 IsValidWonderMail(WonderMail *WonderMailData)
{
    // Has to equal 5 for Wonder Mail
    // https://web.archive.org/web/20080913124416/http://www.upokecenter.com/games/dungeon/guides/passwords.html

    if(WonderMailData->mailType != WONDER_MAIL_TYPE_WONDER)
    {
        return FALSE;
    }
    else
    {
        return ValidateWonderMail(WonderMailData);
    }
}

bool8 ValidateWonderMail(WonderMail *data)
{

    if(data->missionType > WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM)
        return FALSE;
    else
    {
        if(data->missionType == WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM && GetMaxItemsAllowed(data->dungeonSeed.location.id) == 0)
            return FALSE;

        if(data->unk2 > 9)
            return FALSE;

        if(IsNotValidDungeon(data->dungeonSeed.location.id))
            return FALSE;
        if(data->dungeonSeed.location.floor >= GetDungeonFloorCount(data->dungeonSeed.location.id))
            return FALSE;
        if(sub_809017C(&data->dungeonSeed.location))
            return FALSE;

        if(data->clientSpecies == MONSTER_NONE)
            return FALSE;
        if(data->clientSpecies >= MONSTER_MAX)
            return FALSE;
        if(data->clientSpecies != GetBaseSpecies(data->clientSpecies))
            return FALSE;
        if(!sub_803C0DC(data->clientSpecies))
            return FALSE;

        if(data->targetSpecies >= MONSTER_MAX)
            return FALSE;
        if(data->targetSpecies != GetBaseSpecies(data->targetSpecies))
            return FALSE;
        if(!sub_803C0DC(data->targetSpecies))
            return FALSE;

        // Item Delivery/Finding
        if((u8)(data->missionType - 1) > WONDER_MAIL_MISSION_TYPE_RESCUE_TARGET)
            if(data->targetSpecies != data->clientSpecies)
                return FALSE;

        if(IsInvalidItemReward(data->targetItem))
            return FALSE;
        if(IsThrownItem(data->targetItem))
            return FALSE;
        if(!IsNotMoneyOrUsedTMItem(data->targetItem))
            return FALSE;

        // Item finding
        if(data->missionType == WONDER_MAIL_MISSION_TYPE_FIND_ITEM && xxx_bit_lut_lookup_8091E50(data->dungeonSeed.location.id, data->targetItem) == 0)
            return FALSE;

        if(data->rewardType == BLANK_4 || data->rewardType == END_REWARDS || data->rewardType > END_REWARDS)
            return FALSE;

        if(IsInvalidItemReward(data->itemReward))
            return FALSE;

        // Friend Area Reward
        if(data->friendAreaReward > FINAL_ISLAND)
            return FALSE;

        if(data->rewardType == FRIEND_AREA)
        {
            if(GetFriendAreaUnlockCondition(data->friendAreaReward) != UNLOCK_WONDER_MAIL)
                return FALSE;
            if(sub_803C1D0(&data->dungeonSeed.location, data->missionType) == 0)
                return FALSE;
        }
        return TRUE;
    }
}

bool8 GenerateMailJobInfo(struct WonderMail *mail)
{
    s32 missionType;
    s32 i;
    s32 rand;
    s32 numPokemon;
    s16 speciesStack[MONSTER_MAX];
    s32 itemCount;

    if (!GenerateMailJobDungeonInfo(mail)) {
        return FALSE;
    }
    mail->mailType = MAIL_TYPE_SUSPENDED_JOB;
    rand = RandInt(8);
    missionType = sPossibleMissionTypes[rand];
    mail->missionType = missionType;
    if (missionType == MISSION_TYPE_DELIVER_ITEM && GetRescueTeamRank() == 0) {
        mail->missionType = MISSION_TYPE_FRIEND_RESCUE;
    }
    mail->unk2 = 0;
    mail->dungeonSeed.seed = Rand32Bit() & 0xffffff;
    numPokemon = 0;

    for (i = 1; i < MONSTER_MAX; i++) {
        if (sub_803C110(i) != 0) {
            speciesStack[numPokemon] = i;
            numPokemon++;
        }
    }

    if (numPokemon != 0) {
        mail->clientSpecies = speciesStack[RandInt(numPokemon)];
        mail->targetSpecies = speciesStack[RandInt(numPokemon)];
    }
    else {
        mail->clientSpecies = 0x10;
        mail->targetSpecies = 0x122;
    }

    if (mail->missionType != MISSION_TYPE_FIND_ITEM && mail->missionType != MISSION_TYPE_DELIVER_ITEM) {
        mail->targetSpecies = mail->clientSpecies;
    }

    mail->targetItem = sub_8095F28(mail->dungeonSeed.location.id);
    if (mail->targetItem == 0) {
        mail->missionType = MISSION_TYPE_FRIEND_RESCUE;
        mail->targetSpecies = mail->clientSpecies;
        sub_803C37C(&mail->dungeonSeed.location,0,&mail->targetItem);
    }
    itemCount = GetMaxItemsAllowed(mail->dungeonSeed.location.id);
    if (itemCount == 0 && mail->missionType == MISSION_TYPE_RESCUE_TARGET) {
        mail->missionType = MISSION_TYPE_FRIEND_RESCUE;
        mail->targetSpecies = mail->clientSpecies;
    }

    do {
        sub_803C37C(&mail->dungeonSeed.location,mail->missionType,&mail->itemReward);
    } while (mail->targetItem == mail->itemReward);
    mail->friendAreaReward = 0;

    switch (mail->missionType) {
        case MISSION_TYPE_FIND_ITEM:
            switch(Rand32Bit() & 0x70) {
                case 0x10:
                    sub_803C3E0(mail);
                    break;
                case 0x30:
                    sub_803C45C(mail);
                    break;
            }
            break;
        case MISSION_TYPE_DELIVER_ITEM:
            if ((Rand32Bit() & 0x3000) == 0x1000) {
                sub_803C4F0(mail);
            }
            break;
        case MISSION_TYPE_RESCUE_CLIENT:
        case MISSION_TYPE_RESCUE_TARGET:
            switch(Rand32Bit() & 0x700)
            {
            case 0x100:
            case 0x600:
                sub_803C580(mail);
                break;
            case 0x300:
                sub_803C610(mail);
                break;
            }
            break;
    }
    return TRUE;
}

bool8 GenerateMailJobDungeonInfo(WonderMail *mail)
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

      for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
      {
        if (sub_8095E38(&gUnknown_203B490->mailboxSlots[index],dungeon,floor,1)) {
          flag = FALSE;
        }
      }

      for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
      {
        if (sub_8095E38(&gUnknown_203B490->pelipperBoardJobs[index],dungeon,floor,1)) {
          flag = FALSE;
        }
      }

      for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
      {
        if (sub_8095E38(&gUnknown_203B490->jobSlots[index],dungeon,floor,1)) {
          flag = FALSE;
        }
      }

      if (flag) {
        mail->dungeonSeed.location.id = dungeon;
        mail->dungeonSeed.location.floor = floor;
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

bool8 sub_8095E38(WonderMail *mail, u8 dungeon, u32 floor, u8 param_4)
{
    if (mail->mailType != MAIL_TYPE_NONE) {
        if ((mail->missionType == WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT) && (param_4 == 1)) {
            if (mail->dungeonSeed.location.id == dungeon) {
                return TRUE;
            }
        }
        else if ((mail->dungeonSeed.location.id == dungeon) && (mail->dungeonSeed.location.floor == floor)) {
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


        for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
        {
            if((gUnknown_203B490->mailboxSlots[index].mailType != MAIL_TYPE_NONE) && (gUnknown_203B490->mailboxSlots[index].rewardType == FRIEND_AREA))
                flag = TRUE;
        }


        for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
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
    return FRIEND_AREA_NONE;
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
      if ((!IsThrownItem(itemID)) && (IsNotMoneyOrUsedTMItem(itemID))) {
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

s32 CountFilledMailboxSlots(void)
{
    s32 index;
    s32 counter;

    counter = 0;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(!IsMailSlotEmpty(index))
            counter++;
    }
    return counter;
}

UNUSED static bool8 sub_8095FB0(WonderMail *mail)
{
    s32 index;

    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(gUnknown_203B490->mailboxSlots[index].mailType == MAIL_TYPE_NONE)
        {
            gUnknown_203B490->mailboxSlots[index] = *mail;
            return FALSE;
        }
    }
    return TRUE;
}

WonderMail *GetMailboxSlotInfo(u8 index)
{
    return &gUnknown_203B490->mailboxSlots[index];
}

bool8 IsMailSlotEmpty(u8 index)
{
    if(gUnknown_203B490->mailboxSlots[index].mailType == MAIL_TYPE_NONE)
        return TRUE;
    else
        return FALSE;
}

void ResetMailbox(void)
{
    s32 index;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        ResetMailboxSlot(index);
    }
}

void ResetMailboxSlot(u8 index)
{
    gUnknown_203B490->mailboxSlots[index].mailType = MAIL_TYPE_NONE;
    gUnknown_203B490->mailboxSlots[index].dungeonSeed.location.id = 99;
    gUnknown_203B490->mailboxSlots[index].dungeonSeed.location.floor = 0;
    gUnknown_203B490->mailboxSlots[index].rewardType = MONEY1;
}

void ShiftMailboxSlotsDown(void)
{
  int counter1; // r5
  int counter2;


  counter1 = 0;
  counter2 = 0;

  do {
    for( ; counter1 < NUM_MAILBOX_SLOTS; counter1++)
    {
        if (gUnknown_203B490->mailboxSlots[counter1].mailType != 0)
            break;
    }

    if (counter1 == NUM_MAILBOX_SLOTS) {
        break;
    }

    if (counter1 > counter2) {
        gUnknown_203B490->mailboxSlots[counter2] = gUnknown_203B490->mailboxSlots[counter1];
    }
    counter1++;
    counter2++;
  } while( 1 );

  for(; counter2 < NUM_MAILBOX_SLOTS; counter2++)
  {
    gUnknown_203B490->mailboxSlots[counter2].mailType = 0;
  }
}

static void SortMailboxSlots(void)
{
    s32 r1;
    s32 r6;
    WonderMail job;

    for(r1 = 0; r1 < NUM_MAILBOX_SLOTS - 1; r1++)
    {
         for(r6 = r1 + 1; r6 < NUM_MAILBOX_SLOTS; r6++)
        {
                if(gUnknown_203B490->mailboxSlots[r6].mailType != 0)
                {
                    if((gUnknown_203B490->mailboxSlots[r1].dungeonSeed.location.id > gUnknown_203B490->mailboxSlots[r6].dungeonSeed.location.id) ||
                        ((gUnknown_203B490->mailboxSlots[r1].dungeonSeed.location.id == gUnknown_203B490->mailboxSlots[r6].dungeonSeed.location.id) &&
                        (gUnknown_203B490->mailboxSlots[r1].dungeonSeed.location.floor > gUnknown_203B490->mailboxSlots[r6].dungeonSeed.location.floor)))
                    {
                        job = gUnknown_203B490->mailboxSlots[r1];
                        gUnknown_203B490->mailboxSlots[r1] = gUnknown_203B490->mailboxSlots[r6];
                        gUnknown_203B490->mailboxSlots[r6] = job;
                    }
                }
        }
    }
}

void sub_80961B4(void)
{
  if (sub_8096E2C() != 0) {
    gUnknown_203B490->unk328 = TRUE;
  }
}

bool8 sub_80961D8(void)
{
    s32 num;
    s32 index;
    u32 floor;
    s32 friendAreaReward;
    WonderMail *slot;
    bool8 flag = FALSE;

    num = CountFilledMailboxSlots();
    index = RandRange(num, NUM_MAILBOX_SLOTS);
    if(num >= NUM_MAILBOX_SLOTS) return 0;
    if(!gUnknown_203B490->unk328)
        return 0;
    else
    {
         gUnknown_203B490->unk328 = flag;
    }
    floor = 0x38;
    if(ScriptVarScenarioEqual(SCENARIO_SUB7, 0x31, 0x1))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x35])
            if(!sub_8096E80(0x35)) floor = 0x35;
    }
    if(CheckQuest(QUEST_MAZE_15))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x34])
            if(!sub_8096E80(0x34)) floor = 0x34;
        if(!gUnknown_203B490->PKMNNewsReceived[0x33])
            if(!sub_8096E80(0x33)) floor = 0x33;
        if(!gUnknown_203B490->PKMNNewsReceived[0x32])
            if(!sub_8096E80(0x32)) floor = 0x32;

    }
    if(GetRescueTeamRank() == LUCARIO_RANK)
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x36])
            if(!sub_8096E80(0x36)) floor = 0x36;
    }
    if(CheckQuest(QUEST_REACHED_POSTGAME))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x37])
            if(!sub_8096E80(0x37)) floor = 0x37;
    }

    if(floor != 0x38) goto _slot;
    if(num > index) goto _08096392;
    floor = sub_8096E2C();
    if(!CheckQuest(QUEST_MAZE_14) && (floor > 2)) goto _0809638E;
    if (floor > 0x31) goto _0809638E;
_slot:
    slot = GetMailboxSlotInfo(num);
    slot->mailType = 1;
    slot->dungeonSeed.location.id = NUM_DUNGEONS;
    slot->dungeonSeed.location.floor = floor;
    goto _flag;
_0809638E:
    for(; num <= index; num++)
    {
        slot = GetMailboxSlotInfo(num);
        if(GenerateMailJobInfo(slot))
        {
            friendAreaReward = sub_8095E78();
            if(!sub_803C1D0(&slot->dungeonSeed.location, slot->missionType)) friendAreaReward = FRIEND_AREA_NONE;
            slot->rewardType = RandRange(MONEY1, END_REWARDS);
            if(slot->rewardType == FRIEND_AREA)
            {
                if(friendAreaReward == FRIEND_AREA_NONE)
                {
                    slot->rewardType = MONEY1;
                    flag = TRUE;
                }
                else
                {
                    slot->friendAreaReward = friendAreaReward;
                    flag = TRUE;
                }
            }
            else
            {
_flag:
                flag = TRUE;
            }
        } else break;
    }
_08096392:
    if(sub_80963B4())
        flag = TRUE;
    ShiftMailboxSlotsDown();
    SortMailboxSlots();
    return flag;
}

bool8 sub_80963B4(void)
{
    u8 floor;
    s32 num;
    WonderMail *slot;
    bool8 flag = FALSE;

    floor = sub_8096E2C();
    num = CountFilledMailboxSlots();
    if(num >= NUM_MAILBOX_SLOTS) return FALSE;
    if(CheckQuest(QUEST_MAZE_14))
    {
        if(floor < 0x32)
        {
            slot = GetMailboxSlotInfo(num);
            slot->mailType = 1;
            slot->dungeonSeed.location.id = NUM_DUNGEONS;
            slot->dungeonSeed.location.floor = floor;
            flag = TRUE;
        }
    }
    return flag;
}

void sub_80963FC(void)
{
    s32 index;
    WonderMail *slot;

    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        slot = GetMailboxSlotInfo(index);
        if(slot->mailType != 1)
        {
            ResetMailboxSlot(index);
        }
    }
    ShiftMailboxSlotsDown();
    slot = GetMailboxSlotInfo(CountFilledMailboxSlots());
    slot->mailType = 5;
    slot->missionType = 0;
    slot->unk2 = 0;
    slot->dungeonSeed.location.id = DUNGEON_MT_STEEL;
    slot->dungeonSeed.location.floor = 3;
    slot->dungeonSeed.seed = 0x00ffffff & Rand32Bit();
    slot->clientSpecies = MONSTER_PIDGEY;
    slot->targetSpecies = MONSTER_PIDGEY;
    slot->targetItem = sub_8095F28(slot->dungeonSeed.location.id);
    slot->rewardType = MONEY1;
    do
    {
        sub_803C37C(&slot->dungeonSeed.location, slot->missionType, &slot->itemReward);
    } while (slot->targetItem == slot->itemReward);
    slot->friendAreaReward = FRIEND_AREA_NONE;
    ShiftMailboxSlotsDown();
    SortMailboxSlots();
}

void sub_8096488(void)
{
    WonderMail *mail;
    s32 index;

    for(index = 0; index < NUM_MAILBOX_SLOTS; index++){
        ResetMailboxSlot(index);
    }
    mail = GetMailboxSlotInfo(0);
    mail->mailType = 1;
    mail->dungeonSeed.location.id = NUM_DUNGEONS;
    mail->dungeonSeed.location.floor = 0;
}

bool8 sub_80964B4(void)
{
    if ((!gUnknown_203B490->PKMNNewsReceived[0x35]) && (sub_8096E80(0x35) == 0)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

bool8 sub_80964E4(void)
{
    if ((!gUnknown_203B490->PKMNNewsReceived[0x36]) && (sub_8096E80(0x36) == 0)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

s32 CountFilledPelipperBoardSlots(void)
{
    s32 index;
    s32 slots;

    slots = 0;
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++) {
        if (!IsPelipperBoardSlotEmpty(index)) {
            slots++;
        }
    }
    return slots;
}

UNUSED bool8 sub_8096538(WonderMail *mail)
{
    s32 index;
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        if(gUnknown_203B490->pelipperBoardJobs[index].mailType == 0)
        {
            gUnknown_203B490->pelipperBoardJobs[index] = *mail;
            return FALSE;
        }
    }
    return TRUE;
}

WonderMail *GetPelipperBoardSlotInfo(u8 index)
{
    return &gUnknown_203B490->pelipperBoardJobs[index];
}


bool8 IsPelipperBoardSlotEmpty(u8 index)
{
    if (gUnknown_203B490->pelipperBoardJobs[index].mailType == 0)
        return TRUE;
    else
        return FALSE;
}

void ResetPelipperBoardSlot(u8 index)
{
    gUnknown_203B490->pelipperBoardJobs[index].mailType = MAIL_TYPE_NONE;
    gUnknown_203B490->pelipperBoardJobs[index].dungeonSeed.location.id = 99;
    gUnknown_203B490->pelipperBoardJobs[index].dungeonSeed.location.floor = 0;
    gUnknown_203B490->pelipperBoardJobs[index].rewardType = 0;
}

void ShiftPelipperJobsDown(void)
{
  int counter1; // r5
  int counter2;


  counter1 = 0;
  counter2 = 0;

  do {
    for( ; counter1 < MAX_ACCEPTED_JOBS; counter1++)
    {
        if (gUnknown_203B490->pelipperBoardJobs[counter1].mailType != 0)
            break;
    }

    if (counter1 == MAX_ACCEPTED_JOBS) {
        break;
    }

    if (counter1 > counter2) {
        gUnknown_203B490->pelipperBoardJobs[counter2] = gUnknown_203B490->pelipperBoardJobs[counter1];
    }
    counter1++;
    counter2++;
  } while( 1 );

  for(; counter2 < MAX_ACCEPTED_JOBS; counter2++)
  {
    gUnknown_203B490->pelipperBoardJobs[counter2].mailType = 0;
  }
}


void SortPelipperJobs(void)
{
    s32 index1;
    s32 index2;

    WonderMail mail;

    for(index1 = 0; index1 < MAX_ACCEPTED_JOBS - 1; index1++)
    {
        for(index2 = index1 + 1; index2 < MAX_ACCEPTED_JOBS; index2++)
        {
            if(gUnknown_203B490->pelipperBoardJobs[index2].mailType != MAIL_TYPE_NONE)
            {
                if((gUnknown_203B490->pelipperBoardJobs[index1].dungeonSeed.location.id > gUnknown_203B490->pelipperBoardJobs[index2].dungeonSeed.location.id) ||
                ((gUnknown_203B490->pelipperBoardJobs[index1].dungeonSeed.location.id == gUnknown_203B490->pelipperBoardJobs[index2].dungeonSeed.location.id) && (gUnknown_203B490->pelipperBoardJobs[index1].dungeonSeed.location.floor > gUnknown_203B490->pelipperBoardJobs[index2].dungeonSeed.location.floor)))
                {
                    mail = gUnknown_203B490->pelipperBoardJobs[index1];
                    gUnknown_203B490->pelipperBoardJobs[index1] = gUnknown_203B490->pelipperBoardJobs[index2];
                    gUnknown_203B490->pelipperBoardJobs[index2] = mail;
                }
            }
        }
    }
}

void GeneratePelipperJobs(void)
{
  s32 range;
  WonderMail *mail;
  s32 index;

  range = RandRange(4,8);
  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
    gUnknown_203B490->pelipperBoardJobs[index].mailType = MAIL_TYPE_NONE;
  }

  index = 0;
  if (sub_8097318(0xe) != 0) {
    mail = GetPelipperBoardSlotInfo(0);
    mail->mailType = MAIL_TYPE_UNK2;
    mail->missionType = WONDER_MAIL_MISSION_TYPE_UNK6;
    mail->unk2 = 1;
    mail->dungeonSeed.location.id = DUNGEON_UPROAR_FOREST;
    mail->dungeonSeed.location.floor = 10;
    mail->dungeonSeed.seed = Rand32Bit() & 0xffffff;
    mail->clientSpecies = MONSTER_WYNAUT;
    mail->targetSpecies = MONSTER_MANKEY;
    mail->targetItem = 0;
    mail->rewardType = ITEM;
    mail->itemReward = ITEM_REVIVER_SEED;
    mail->friendAreaReward = 0;
    index = 1;
  }


  if (sub_8097318(0xf) != 0) {
    mail = GetPelipperBoardSlotInfo(index);
    mail->mailType = MAIL_TYPE_UNK3;
    mail->missionType = WONDER_MAIL_MISSION_TYPE_UNK6;
    mail->unk2 = 2;
    mail->dungeonSeed.location.id = DUNGEON_HOWLING_FOREST;
    mail->dungeonSeed.location.floor = 15;
    mail->dungeonSeed.seed = Rand32Bit() & 0xffffff;
    mail->clientSpecies = MONSTER_SMEARGLE;
    mail->targetSpecies = MONSTER_SMEARGLE;
    mail->targetItem = 0;
    mail->rewardType = ITEM;
    mail->itemReward = ITEM_REVIVER_SEED;
    mail->friendAreaReward = 0;
    index++;
  }

  if (sub_8097318(0x1c) != 0) {
    mail = GetPelipperBoardSlotInfo(index);
    mail->mailType = MAIL_TYPE_UNK4;
    mail->missionType = WONDER_MAIL_MISSION_TYPE_UNK6;
    mail->unk2 = 3;
    mail->dungeonSeed.location.id = DUNGEON_WISH_CAVE;
    mail->dungeonSeed.location.floor = 20;
    mail->dungeonSeed.seed = Rand32Bit() & 0xffffff;
    mail->clientSpecies = MONSTER_MEDICHAM;
    mail->targetSpecies = MONSTER_MEDICHAM;
    mail->targetItem = 0;
    mail->rewardType = ITEM;
    mail->itemReward = ITEM_REVIVER_SEED;
    mail->friendAreaReward = 0;
    index++;
  }
  for (; index <= range; index++) {
    if (!GenerateMailJobInfo(&gUnknown_203B490->pelipperBoardJobs[index])) break;
    gUnknown_203B490->pelipperBoardJobs[index].rewardType = RandRange(MONEY, BLANK_4);
  }
  ShiftPelipperJobsDown();
  SortPelipperJobs();
}

bool8 IsMailinJobSlot(WonderMail *mail)
{
  WonderMail *jobSlot;
  s32 index;

  for(index = 0, jobSlot = &gUnknown_203B490->jobSlots[0]; index < MAX_ACCEPTED_JOBS; jobSlot++, index++)
  {
      if(jobSlot->mailType != MAIL_TYPE_NONE)
        if(mail->missionType == jobSlot->missionType)
            if(mail->unk2 == jobSlot->unk2)
                    if(mail->dungeonSeed.location.id == jobSlot->dungeonSeed.location.id)
                        if(mail->dungeonSeed.location.floor == jobSlot->dungeonSeed.location.floor)
                            if(mail->dungeonSeed.seed == jobSlot->dungeonSeed.seed)
                                if(mail->clientSpecies == jobSlot->clientSpecies)
                                    if(mail->targetSpecies == jobSlot->targetSpecies)
                                        if(mail->targetItem == jobSlot->targetItem)
                                            if(mail->rewardType == jobSlot->rewardType)
                                                if(mail->itemReward == jobSlot->itemReward)
                                                    if(mail->friendAreaReward == jobSlot->friendAreaReward)
                                                        return TRUE;
  }
  return FALSE;
}

bool8 sub_809693C(WonderMail *mail)
{
  u8 dungeonIndex;
  u8 floor;
  bool8 escortMission;
  s32 index;

  dungeonIndex = mail->dungeonSeed.location.id;
  floor = mail->dungeonSeed.location.floor;
  escortMission = FALSE;
  if (!IsValidWonderMail(mail)) {
      return FALSE;
  }
  else
  {
    if(mail->missionType == WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT)
        escortMission = TRUE;
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
      if ((gUnknown_203B490->jobSlots[index].mailType == MAIL_TYPE_TAKEN_JOB) &&
         (sub_8095E38(&gUnknown_203B490->jobSlots[index],dungeonIndex,floor,escortMission) != 0))
      {
        return TRUE;
      }
    }
  }
  return FALSE;
}

s32 GetNumAcceptedJobs(void)
{
  s32 index;
  s32 count;

  count = 0;
  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
    if (!IsJobSlotEmpty(index)) {
      count++;
    }
  }
  return count;
}

s32 CountJobsinDungeon(u8 dungeon)
{
  WonderMail *mail;
  s32 index;
  s32 count;

  count = 0;
  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
    mail = GetJobSlotInfo(index);
    if ((mail->dungeonSeed.location.id == dungeon) &&
       (((mail->mailType == MAIL_TYPE_TAKEN_JOB || (mail->mailType == MAIL_TYPE_UNK8)) || (mail->mailType == MAIL_TYPE_UNK9)))) {
      count++;
    }
  }
  return count;
}

bool8 sub_8096A08(u8 dungeon, Pokemon *pokemon)
{
  WonderMail *mail;
  s32 index;
  u32 local_14;
  s32 temp;

  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
      mail = GetJobSlotInfo(index);
      if(mail->dungeonSeed.location.id == dungeon)
        if(mail->mailType == MAIL_TYPE_TAKEN_JOB)
            if(mail->missionType == WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT)
            {
                temp = 0xffffff00;
                local_14 &= temp;
                temp = 0x4A;
                local_14 |= temp;

                temp = 0xffff00ff;
                local_14 &= temp;
                temp = 0x100;
                local_14 |= temp;

                CreateLevel1Pokemon(pokemon,mail->clientSpecies,NULL,0,(DungeonLocation *) &local_14,NULL);
                return TRUE;
            }
  }
  return FALSE;
}

bool8 AcceptJob(WonderMail *mail)
{
  s32 index;

  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
    if(gUnknown_203B490->jobSlots[index].mailType == MAIL_TYPE_NONE)
    {
        gUnknown_203B490->jobSlots[index] = *mail;
        return FALSE;
    }
  }
  return TRUE;
}

WonderMail *GetJobSlotInfo(u8 index)
{
    return &gUnknown_203B490->jobSlots[index];
}

bool8 IsJobSlotEmpty(u8 index)
{
    if(gUnknown_203B490->jobSlots[index].mailType == MAIL_TYPE_NONE)
        return TRUE;
    else
        return FALSE;
}

void sub_8096AF8(struct unkStruct_8096AF8 *param_1, u8 slotIndex,u8 dungeon)
{
  WonderMail *jobSlot;
  Item *item;
  s32 index;

  jobSlot = GetJobSlotInfo(slotIndex);
  param_1->unk0 = FALSE;
  param_1->clientSpecies = jobSlot->clientSpecies;
  param_1->targetSpecies = MONSTER_NONE;
  if (jobSlot->dungeonSeed.location.id == dungeon) {
    switch(jobSlot->missionType) {
        case WONDER_MAIL_MISSION_TYPE_FIND_ITEM:
            if (jobSlot->mailType == MAIL_TYPE_TAKEN_JOB) {
                for(index = 0; index < INVENTORY_SIZE; index++)
                {
                    item = &gTeamInventoryRef->teamItems[index];
                    if (((item->flags & ITEM_FLAG_EXISTS)) && (item->id == jobSlot->targetItem)) {
                        param_1->unk0 = TRUE;
                    }
                }
            }
            break;
        case WONDER_MAIL_MISSION_TYPE_RESCUE_CLIENT:
        case WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM:
            if (jobSlot->mailType == MAIL_TYPE_UNK9) {
                param_1->unk0 = TRUE;
            }
            break;
        case WONDER_MAIL_MISSION_TYPE_RESCUE_TARGET:
        case WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT:
            if (jobSlot->mailType == MAIL_TYPE_UNK9) {
                param_1->unk0 = TRUE;
                param_1->targetSpecies = jobSlot->targetSpecies;
            }
            break;
    }
  }
}

// Unused
s16 sub_8096B98(u8 dungeon)
{
  WonderMail *mail;
  s32 index;

  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
    mail = GetJobSlotInfo(index);
    if(mail->mailType == MAIL_TYPE_TAKEN_JOB)
        if(mail->missionType == WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT)
            if(mail->dungeonSeed.location.id == dungeon)
                return mail->targetSpecies;
  }
  return 0;
}

void sub_8096BD0(void)
{
  s32 index;
  WonderMail *mail;

  for(mail = &gUnknown_203B490->jobSlots[0], index = 0; index < MAX_ACCEPTED_JOBS; mail++, index++)
  {
    switch(mail->mailType)
    {
        case MAIL_TYPE_UNK7:
        case MAIL_TYPE_UNK8:
        case MAIL_TYPE_UNK9:
            ResetJobSlot(index);
            break;
    }
  }
  ShiftJobSlotsDown();
  SortJobSlots();
}

bool8 sub_8096C08(u8 *jobIndex)
{
  s32 index;
  WonderMail *mail;

  for(mail = &gUnknown_203B490->jobSlots[0], index = 0; index < MAX_ACCEPTED_JOBS; mail++, index++)
  {
    if(mail->mailType > 4 && mail->unk2 == 4)
    {

        *jobIndex = index;
        return TRUE;
    }
  }
  return FALSE;
}

void ResetJobSlot(u8 index)
{
  gUnknown_203B490->jobSlots[index].mailType = MAIL_TYPE_NONE;
  gUnknown_203B490->jobSlots[index].dungeonSeed.location.id = 99;
  gUnknown_203B490->jobSlots[index].dungeonSeed.location.floor = 0;
  gUnknown_203B490->jobSlots[index].rewardType = MONEY1;
}

void ShiftJobSlotsDown(void)
{
  int counter1; // r5
  int counter2;


  counter1 = 0;
  counter2 = 0;

  do {
    for( ; counter1 < MAX_ACCEPTED_JOBS; counter1++)
    {
        if (gUnknown_203B490->jobSlots[counter1].mailType != 0)
            break;
    }

    if (counter1 == MAX_ACCEPTED_JOBS) {
        break;
    }

    if (counter1 > counter2) {
        gUnknown_203B490->jobSlots[counter2] = gUnknown_203B490->jobSlots[counter1];
    }
    counter1++;
    counter2++;
  } while( 1 );

  for(; counter2 < MAX_ACCEPTED_JOBS; counter2++)
  {
    gUnknown_203B490->jobSlots[counter2].mailType = 0;
  }
}

void SortJobSlots(void)
{
    s32 r1;
    s32 r6;
    WonderMail job;

    for(r1 = 0; r1 < MAX_ACCEPTED_JOBS - 1; r1++)
    {
         for(r6 = r1 + 1; r6 < MAX_ACCEPTED_JOBS; r6++)
        {
                if(gUnknown_203B490->jobSlots[r6].mailType != 0)
                {
                    if((gUnknown_203B490->jobSlots[r1].dungeonSeed.location.id > gUnknown_203B490->jobSlots[r6].dungeonSeed.location.id) ||
                        ((gUnknown_203B490->jobSlots[r1].dungeonSeed.location.id == gUnknown_203B490->jobSlots[r6].dungeonSeed.location.id) &&
                        (gUnknown_203B490->jobSlots[r1].dungeonSeed.location.floor > gUnknown_203B490->jobSlots[r6].dungeonSeed.location.floor)))
                    {
                        job = gUnknown_203B490->jobSlots[r1];
                        gUnknown_203B490->jobSlots[r1] = gUnknown_203B490->jobSlots[r6];
                        gUnknown_203B490->jobSlots[r6] =  job;
                    }
                }
        }
    }
}

u8 *sub_8096DD8(void)
{
    return gUnknown_203B490->unk190;
}

u8 *sub_8096DE8(void)
{
    return gUnknown_203B490->unk1B8;
}

void ReceivePKMNNews(u8 index)
{
    gUnknown_203B490->PKMNNewsReceived[index] = TRUE;
}

bool8 CheckPKMNNewsSlot(u8 index)
{
    return gUnknown_203B490->PKMNNewsReceived[index];
}

u8 sub_8096E2C(void)
{
    s32 index;
    s32 floor = 0;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(gUnknown_203B490->mailboxSlots[index].mailType == 1)
        {
             if(floor <= gUnknown_203B490->mailboxSlots[index].dungeonSeed.location.floor)
                 if( gUnknown_203B490->mailboxSlots[index].dungeonSeed.location.floor < 0x32)
                    floor =  gUnknown_203B490->mailboxSlots[index].dungeonSeed.location.floor + 1;
        }
    }

    for(index = floor; index < 0x32; index++)
    {
        if(!gUnknown_203B490->PKMNNewsReceived[index]) return index;
    }
    return 0x38;
}

bool8 sub_8096E80(u8 floor)
{
    s32 index;
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        if(gUnknown_203B490->mailboxSlots[index].mailType == 1)
        {
             if(floor == gUnknown_203B490->mailboxSlots[index].dungeonSeed.location.floor)
                return TRUE;
        }
    }
    return FALSE;
}

s32 CalculateMailChecksum(WonderMail *mail)
{
    s32 sum;

    sum = (mail->unk2 + mail->missionType);

    sum += mail->dungeonSeed.location.id;
    sum += mail->dungeonSeed.location.floor;

    sum += mail->dungeonSeed.seed << 8;

    sum += mail->clientSpecies << 12;

    sum += mail->targetSpecies << 16;

    sum += mail->targetItem << 24;

    sum += mail->rewardType;

    sum += mail->itemReward;

    sum += mail->friendAreaReward;

    return sum;
}

void sub_8096EEC(WonderMail *mail)
{
    s32 index;

    for (index = 16 - 1; index > 0; index--) {
         gUnknown_203B490->unk230[index] =  gUnknown_203B490->unk230[index - 1];
    }

    gUnknown_203B490->unk230[0].dungeonSeed = mail->dungeonSeed;
    gUnknown_203B490->unk230[0].checksum = CalculateMailChecksum(mail);
}

bool8 sub_8096F50(WonderMail *mail)
{
    s32 index;
    s32 checksum;
    subStruct_203B490 *temp;

    checksum = CalculateMailChecksum(mail);

    for (index = 0; index < 16; index++) {
        temp  = &gUnknown_203B490->unk230[index];
        if (temp->dungeonSeed.location.id == mail->dungeonSeed.location.id)
            if (temp->dungeonSeed.location.floor == mail->dungeonSeed.location.floor)
                if (temp->dungeonSeed.seed == mail->dungeonSeed.seed)
                    if (temp->checksum == checksum)
                        return TRUE;
    }

    return FALSE;
}

u32 RestoreMailInfo(u8 *r0, u32 size)
{
    s32 index;
    DataSerializer backup;
    u32 temp;

    InitBitReader(&backup, r0, size);
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        ReadWonderMailBits(&backup, &gUnknown_203B490->mailboxSlots[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        ReadWonderMailBits(&backup, &gUnknown_203B490->pelipperBoardJobs[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        ReadWonderMailBits(&backup, &gUnknown_203B490->jobSlots[index]);
    }
    for(index = 0; index < 56; index++)
    {
        ReadBits(&backup, &temp, 1);
        if(temp & 1)
            gUnknown_203B490->PKMNNewsReceived[index] = TRUE;
        else
            gUnknown_203B490->PKMNNewsReceived[index] = FALSE;
    }
    ReadBits(&backup, &temp, 1);
    if(temp & 1)
        gUnknown_203B490->unk328 = TRUE;
    else
        gUnknown_203B490->unk328 = FALSE;

    ReadBits(&backup, gUnknown_203B490->unk190, 40 * 8);
    ReadBits(&backup, gUnknown_203B490->unk1B8, 120 * 8);
    for (index = 0; index < 16; index++)
    {
        ReadBits(&backup, &gUnknown_203B490->unk230[index].checksum, 32);
        ReadBits(&backup, &gUnknown_203B490->unk230[index].dungeonSeed.seed, 24);
        ReadDungeonLocationBits(&backup, &gUnknown_203B490->unk230[index].dungeonSeed.location);
    }
    FinishBitSerializer(&backup);
    return backup.count;
}

u32 SaveMailInfo(u8 *r0, u32 size)
{
    s32 index;
    DataSerializer backup;
    u32 temp;

    InitBitWriter(&backup, r0, size);
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        WriteWonderMailBits(&backup, &gUnknown_203B490->mailboxSlots[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        WriteWonderMailBits(&backup, &gUnknown_203B490->pelipperBoardJobs[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        WriteWonderMailBits(&backup, &gUnknown_203B490->jobSlots[index]);
    }
    for(index = 0; index < 0x38; index++)
    {
        if(gUnknown_203B490->PKMNNewsReceived[index])
            temp = -1;
        else
            temp = 0;
        WriteBits(&backup, &temp, 1);
    }
    if(gUnknown_203B490->unk328)
        temp = -1;
    else
        temp = 0;
    WriteBits(&backup, &temp, 1);
    WriteBits(&backup, gUnknown_203B490->unk190, 0x140);
    WriteBits(&backup, gUnknown_203B490->unk1B8, 0x3C0);
    for(index = 0; index < 0x10; index++)
    {
        WriteBits(&backup, &gUnknown_203B490->unk230[index].checksum, 0x20);
        WriteBits(&backup, &gUnknown_203B490->unk230[index].dungeonSeed.seed, 0x18);
        WriteDungeonLocationBits(&backup, &gUnknown_203B490->unk230[index].dungeonSeed.location);
    }
    FinishBitSerializer(&backup);
    return backup.count;
}

// arm9.bin::020662A0
void ReadWonderMailBits(DataSerializer *a, WonderMail *b)
{
    ReadBits(a, &b->mailType, 4);
    ReadBits(a, &b->missionType, 3);
    ReadBits(a, &b->unk2, 4);
    ReadBits(a, &b->clientSpecies, 9);
    ReadBits(a, &b->targetSpecies, 9);
    ReadBits(a, &b->targetItem, 8);
    ReadBits(a, &b->rewardType, 4);
    ReadBits(a, &b->itemReward, 8);
    ReadBits(a, &b->friendAreaReward, 6);
    ReadBits(a, &b->dungeonSeed.seed, 24);
    ReadDungeonLocationBits(a, &b->dungeonSeed.location);
}

// arm9.bin::020661E4
void WriteWonderMailBits(DataSerializer *a, WonderMail *b)
{
    WriteBits(a, &b->mailType, 4);
    WriteBits(a, &b->missionType, 3);
    WriteBits(a, &b->unk2, 4);
    WriteBits(a, &b->clientSpecies, 9);
    WriteBits(a, &b->targetSpecies, 9);
    WriteBits(a, &b->targetItem, 8);
    WriteBits(a, &b->rewardType, 4);
    WriteBits(a, &b->itemReward, 8);
    WriteBits(a, &b->friendAreaReward, 6);
    WriteBits(a, &b->dungeonSeed.seed, 24);
    WriteDungeonLocationBits(a, &b->dungeonSeed.location);
}
