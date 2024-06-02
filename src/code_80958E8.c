#include "global.h"
#include "code_803C1D0.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_80958E8_1.h"
#include "code_80A26CC.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/wonder_mail.h"
#include "dungeon.h"
#include "random.h"
#include "friend_area.h"
#include "items.h"
#include "memory.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "pokemon_mail.h"

extern bool8 sub_809017C(DungeonLocation *);
extern void ResetPelipperBoardSlot(u8);
bool8 sub_8095E38(WonderMail *mail, u8 dungeon, u32 floor, u8 param_4);
u8 sub_8095F28(u8 param_1);
bool8 GenerateMailJobDungeonInfo(WonderMail *mail);
extern void sub_803C4F0(WonderMail *);
extern void sub_803C3E0(WonderMail *);
extern void sub_803C45C(WonderMail *);
extern void sub_803C610(WonderMail *);
extern void sub_803C580(WonderMail *);
extern void sub_803C37C(struct DungeonLocation *, u8, u8 *);

extern u8 gUnknown_8109984[];

static EWRAM_DATA unkStruct_203B490 sUnknown_2039448 = {0};

EWRAM_DATA_2 unkStruct_203B490 *gUnknown_203B490 = {0};

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
        gUnknown_203B490->unk230[index].sub.dungeon.id = 99;
        gUnknown_203B490->unk230[index].sub.dungeon.floor = 1;
        gUnknown_203B490->unk230[index].sub.seed = 0;
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
        if(data->missionType == WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM && GetMaxItemsAllowed(data->unk4.dungeon.id) == 0)
            return FALSE;

        if(data->unk2 > 9)
            return FALSE;

        if(IsNotValidDungeon(data->unk4.dungeon.id))
            return FALSE;
        if(data->unk4.dungeon.floor >= GetDungeonFloorCount(data->unk4.dungeon.id))
            return FALSE;
        if(sub_809017C(&data->unk4.dungeon))
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
        if(IsThrowableItem(data->targetItem))
            return FALSE;
        if(!IsNotMoneyOrUsedTMItem(data->targetItem))
            return FALSE;

        // Item finding
        if(data->missionType == WONDER_MAIL_MISSION_TYPE_FIND_ITEM && xxx_bit_lut_lookup_8091E50(data->unk4.dungeon.id, data->targetItem) == 0)
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
            if(sub_803C1D0(&data->unk4.dungeon, data->missionType) == 0)
                return FALSE;
        }
        return TRUE;
    }
}


// https://decomp.me/scratch/1XsHS (99.96% matching - Seth)
#ifdef NONMATCHING
bool8 GenerateMailJobInfo(WonderMail *mail)
{
  u8 uVar3;
  u32 uVar4;
  s16 species;
  s32 index;
  s32 iVar6;
  s32 numPokemon;
  s16 speciesStack [424];
  register s32 itemCount asm("r1");
  
 
  if (!GenerateMailJobDungeonInfo(mail)) {
    return FALSE;
  }
  mail->mailType = 5;
  iVar6 = RandInt(8);
  uVar3 = (gUnknown_8109984)[iVar6];
  mail->missionType = uVar3;
  if ((uVar3 == 2) && (GetRescueTeamRank() == 0)) {
    mail->missionType = 0;
  }
  mail->unk2 = 0;
  mail->unk4.seed = Rand32Bit() & 0xffffff;
  numPokemon = 0;


  for(index = 1; index < 0x1A8; index++)
  {
    if (sub_803C110(index) != 0) {
      speciesStack[numPokemon] = index;
      numPokemon++;
    }
  }
    
  if (numPokemon != 0) {
    mail->clientSpecies = speciesStack[RandInt(numPokemon)];
    species = speciesStack[RandInt(numPokemon)];
  }
  else {
    mail->clientSpecies = 0x10;
    species = 0x122;
  }
  mail->targetSpecies = species;

  if (1 < (u8)(mail->missionType - 1)) {
    mail->targetSpecies = mail->clientSpecies;
  }
    
  uVar4 = sub_8095F28((mail->unk4.dungeon).id);
  mail->targetItem = uVar4;
  if ((u8)mail->targetItem  == 0) {
    mail->missionType = mail->targetItem;
    mail->targetSpecies = mail->clientSpecies;
    sub_803C37C(&mail->unk4.dungeon,0,&mail->targetItem);
  }
  itemCount = GetMaxItemsAllowed((mail->unk4.dungeon).id);    
  if ((itemCount == 0) && (mail->missionType == 4)) {
    mail->missionType = itemCount;
    mail->targetSpecies = mail->clientSpecies;
  }
  do { 
    sub_803C37C(&mail->unk4.dungeon,mail->missionType,&mail->itemReward);
  } while (mail->targetItem == mail->itemReward);
  mail->friendAreaReward = 0;

  switch(mail->missionType)
  {
      case 1:
        switch(Rand32Bit() & 0x70)
        {
            case 0x10:
                sub_803C3E0(mail);
                break;
            case 0x30:
                sub_803C45C(mail);
                break;
        }
        break;
      case 2:
        if ((Rand32Bit() & 0x3000) == 0x1000) {
          sub_803C4F0(mail);
        }
        break;
      case 3:
      case 4:
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
  }
  return TRUE;
}
#else
NAKED
bool8 GenerateMailJobInfo(WonderMail *mail)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r9\n"
	"\tmov r6, r8\n"
	"\tpush {r6,r7}\n"
	"\tldr r4, _08095B44\n"
	"\tadd sp, r4\n"
	"\tadds r4, r0, 0\n"
	"\tbl GenerateMailJobDungeonInfo\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _08095B48\n"
	"\tmovs r0, 0\n"
	"\tb _08095CCC\n"
	"\t.align 2, 0\n"
"_08095B44: .4byte 0xfffffcb0\n"
"_08095B48:\n"
	"\tmovs r0, 0x5\n"
	"\tstrb r0, [r4]\n"
	"\tmovs r0, 0x8\n"
	"\tbl RandInt\n"
	"\tldr r1, _08095BC8\n"
	"\tadds r0, r1\n"
	"\tldrb r0, [r0]\n"
	"\tstrb r0, [r4, 0x1]\n"
	"\tcmp r0, 0x2\n"
	"\tbne _08095B6C\n"
	"\tbl GetRescueTeamRank\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _08095B6C\n"
	"\tstrb r0, [r4, 0x1]\n"
"_08095B6C:\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r4, 0x2]\n"
	"\tbl Rand32Bit\n"
	"\tldr r1, _08095BCC\n"
	"\tands r1, r0\n"
	"\tstr r1, [r4, 0x8]\n"
	"\tmovs r7, 0\n"
	"\tmovs r5, 0x1\n"
	"\tadds r0, r4, 0x4\n"
	"\tmov r8, r0\n"
	"\tmovs r1, 0x12\n"
	"\tadds r1, r4\n"
	"\tmov r9, r1\n"
	"\tmov r6, sp\n"
"_08095B8A:\n"
	"\tlsls r0, r5, 16\n"
	"\tasrs r0, 16\n"
	"\tbl sub_803C110\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _08095B9E\n"
	"\tstrh r5, [r6]\n"
	"\tadds r6, 0x2\n"
	"\tadds r7, 0x1\n"
"_08095B9E:\n"
	"\tadds r5, 0x1\n"
	"\tldr r0, _08095BD0\n"
	"\tcmp r5, r0\n"
	"\tble _08095B8A\n"
	"\tcmp r7, 0\n"
	"\tbeq _08095BD4\n"
	"\tadds r0, r7, 0\n"
	"\tbl RandInt\n"
	"\tlsls r0, 1\n"
	"\tadd r0, sp\n"
	"\tldrh r0, [r0]\n"
	"\tstrh r0, [r4, 0xC]\n"
	"\tadds r0, r7, 0\n"
	"\tbl RandInt\n"
	"\tlsls r0, 1\n"
	"\tadd r0, sp\n"
	"\tldrh r0, [r0]\n"
	"\tb _08095BDC\n"
	"\t.align 2, 0\n"
"_08095BC8: .4byte gUnknown_8109984\n"
"_08095BCC: .4byte 0x00ffffff\n"
"_08095BD0: .4byte 0x000001a7\n"
"_08095BD4:\n"
	"\tmovs r0, 0x10\n"
	"\tstrh r0, [r4, 0xC]\n"
	"\tmovs r0, 0x91\n"
	"\tlsls r0, 1\n"
"_08095BDC:\n"
	"\tstrh r0, [r4, 0xE]\n"
	"\tldrb r0, [r4, 0x1]\n"
	"\tsubs r0, 0x1\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, 0x1\n"
	"\tbls _08095BEE\n"
	"\tldrh r0, [r4, 0xC]\n"
	"\tstrh r0, [r4, 0xE]\n"
"_08095BEE:\n"
	"\tldrb r0, [r4, 0x4]\n"
	"\tbl sub_8095F28\n"
	"\tstrb r0, [r4, 0x10]\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _08095C10\n"
	"\tstrb r0, [r4, 0x1]\n"
	"\tldrh r0, [r4, 0xC]\n"
	"\tstrh r0, [r4, 0xE]\n"
	"\tadds r2, r4, 0\n"
	"\tadds r2, 0x10\n"
	"\tmov r0, r8\n"
	"\tmovs r1, 0\n"
	"\tbl sub_803C37C\n"
"_08095C10:\n"
	"\tldrb r0, [r4, 0x4]\n"
	"\tbl GetMaxItemsAllowed\n"
	"\tadds r1, r0, 0\n"
	"\tcmp r1, 0\n"
	"\tbne _08095C28\n"
	"\tldrb r0, [r4, 0x1]\n"
	"\tcmp r0, 0x4\n"
	"\tbne _08095C28\n"
	"\tstrb r1, [r4, 0x1]\n"
	"\tldrh r0, [r4, 0xC]\n"
	"\tstrh r0, [r4, 0xE]\n"
"_08095C28:\n"
	"\tldrb r1, [r4, 0x1]\n"
	"\tmov r0, r8\n"
	"\tmov r2, r9\n"
	"\tbl sub_803C37C\n"
	"\tldrb r0, [r4, 0x10]\n"
	"\tldrb r1, [r4, 0x12]\n"
	"\tcmp r0, r1\n"
	"\tbeq _08095C28\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r4, 0x13]\n"
	"\tldrb r0, [r4, 0x1]\n"
	"\tcmp r0, 0x2\n"
	"\tbeq _08095C90\n"
	"\tcmp r0, 0x2\n"
	"\tbgt _08095C4E\n"
	"\tcmp r0, 0x1\n"
	"\tbeq _08095C6C\n"
	"\tb _08095CCA\n"
"_08095C4E:\n"
	"\tcmp r0, 0x4\n"
	"\tbgt _08095CCA\n"
	"\tbl Rand32Bit\n"
	"\tadds r1, r0, 0\n"
	"\tmovs r0, 0xE0\n"
	"\tlsls r0, 3\n"
	"\tands r1, r0\n"
	"\tmovs r0, 0xC0\n"
	"\tlsls r0, 2\n"
	"\tcmp r1, r0\n"
	"\tbeq _08095CC4\n"
	"\tcmp r1, r0\n"
	"\tbgt _08095CB4\n"
	"\tb _08095CAA\n"
"_08095C6C:\n"
	"\tbl Rand32Bit\n"
	"\tadds r1, r0, 0\n"
	"\tmovs r0, 0x70\n"
	"\tands r1, r0\n"
	"\tcmp r1, 0x10\n"
	"\tbeq _08095C80\n"
	"\tcmp r1, 0x30\n"
	"\tbeq _08095C88\n"
	"\tb _08095CCA\n"
"_08095C80:\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_803C3E0\n"
	"\tb _08095CCA\n"
"_08095C88:\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_803C45C\n"
	"\tb _08095CCA\n"
"_08095C90:\n"
	"\tbl Rand32Bit\n"
	"\tmovs r1, 0xC0\n"
	"\tlsls r1, 6\n"
	"\tands r1, r0\n"
	"\tmovs r0, 0x80\n"
	"\tlsls r0, 5\n"
	"\tcmp r1, r0\n"
	"\tbne _08095CCA\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_803C4F0\n"
	"\tb _08095CCA\n"
"_08095CAA:\n"
	"\tmovs r0, 0x80\n"
	"\tlsls r0, 1\n"
	"\tcmp r1, r0\n"
	"\tbeq _08095CBC\n"
	"\tb _08095CCA\n"
"_08095CB4:\n"
	"\tmovs r0, 0xC0\n"
	"\tlsls r0, 3\n"
	"\tcmp r1, r0\n"
	"\tbne _08095CCA\n"
"_08095CBC:\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_803C580\n"
	"\tb _08095CCA\n"
"_08095CC4:\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_803C610\n"
"_08095CCA:\n"
	"\tmovs r0, 0x1\n"
"_08095CCC:\n"
	"\tmovs r3, 0xD4\n"
	"\tlsls r3, 2\n"
	"\tadd sp, r3\n"
	"\tpop {r3,r4}\n"
	"\tmov r8, r3\n"
	"\tmov r9, r4\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1"
    );
}
#endif

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

bool8 sub_8095E38(WonderMail *mail, u8 dungeon, u32 floor, u8 param_4)
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
    gUnknown_203B490->mailboxSlots[index].unk4.dungeon.id = 99;
    gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor = 0;
    gUnknown_203B490->mailboxSlots[index].rewardType = MONEY1;
}
