#include "global.h"
#include "code_803C1D0.h"
#include "code_80958E8.h"
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
#include "event_flag.h"
#include "rescue_team_info.h"

extern bool8 sub_809017C(DungeonLocation *);
extern void sub_803C37C(struct DungeonLocation *, u8, u8 *);

extern u8 sub_8097318(s16 param_1);

bool8 sub_8095E38(WonderMail *mail, u8 dungeon, u32 floor, u8 param_4);
u8 sub_8095F28(u8 param_1);
bool8 GenerateMailJobDungeonInfo(WonderMail *mail);
bool8 GenerateMailJobInfo(WonderMail *);
bool8 sub_8096E80(u8);
u8 sub_8095E78(void);
bool8 sub_80963B4(void);
s32 CalculateMailChecksum(WonderMail *mail);

extern void SaveDungeonLocation(unkStruct_8094924*, DungeonLocation*);
extern void RestoreDungeonLocation(unkStruct_8094924*, DungeonLocation*);
extern void sub_803C4F0(WonderMail *);
extern void sub_803C3E0(WonderMail *);
extern void sub_803C45C(WonderMail *);
extern void sub_803C610(WonderMail *);
extern void sub_803C580(WonderMail *);

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
                    if((gUnknown_203B490->mailboxSlots[r1].unk4.dungeon.id > gUnknown_203B490->mailboxSlots[r6].unk4.dungeon.id) || 
                        ((gUnknown_203B490->mailboxSlots[r1].unk4.dungeon.id == gUnknown_203B490->mailboxSlots[r6].unk4.dungeon.id) && 
                        (gUnknown_203B490->mailboxSlots[r1].unk4.dungeon.floor > gUnknown_203B490->mailboxSlots[r6].unk4.dungeon.floor)))
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
    if(sub_80023E4(0xF))
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
    if(sub_80023E4(6))
    {
        if(!gUnknown_203B490->PKMNNewsReceived[0x37])
            if(!sub_8096E80(0x37)) floor = 0x37;
    }
    
    if(floor != 0x38) goto _slot;
    if(num > index) goto _08096392;
    floor = sub_8096E2C();
    if(!sub_80023E4(0xE) && (floor > 2)) goto _0809638E;
    if (floor > 0x31) goto _0809638E;
_slot:
    slot = GetMailboxSlotInfo(num);
    slot->mailType = 1;
    slot->unk4.dungeon.id = NUM_DUNGEONS;
    slot->unk4.dungeon.floor = floor;
    goto _flag;
_0809638E:
    for(; num <= index; num++)
    {
        slot = GetMailboxSlotInfo(num);
        if(GenerateMailJobInfo(slot))
        {
            friendAreaReward = sub_8095E78();
            if(!sub_803C1D0(&slot->unk4.dungeon, slot->missionType)) friendAreaReward = FRIEND_AREA_NONE;
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
    if(sub_80023E4(0xE))
    {
        if(floor < 0x32)
        {
            slot = GetMailboxSlotInfo(num);
            slot->mailType = 1;
            slot->unk4.dungeon.id = NUM_DUNGEONS;
            slot->unk4.dungeon.floor = floor;
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
    slot->unk4.dungeon.id = DUNGEON_MT_STEEL;
    slot->unk4.dungeon.floor = 3;
    slot->unk4.seed = 0x00ffffff & Rand32Bit();
    slot->clientSpecies = MONSTER_PIDGEY;
    slot->targetSpecies = MONSTER_PIDGEY;
    slot->targetItem = sub_8095F28(slot->unk4.dungeon.id);
    slot->rewardType = MONEY1;
    do
    {
        sub_803C37C(&slot->unk4.dungeon, slot->missionType, &slot->itemReward);
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
    mail->unk4.dungeon.id = NUM_DUNGEONS;
    mail->unk4.dungeon.floor = 0;
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
    gUnknown_203B490->pelipperBoardJobs[index].unk4.dungeon.id = 99;
    gUnknown_203B490->pelipperBoardJobs[index].unk4.dungeon.floor = 0;
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
                if((gUnknown_203B490->pelipperBoardJobs[index1].unk4.dungeon.id > gUnknown_203B490->pelipperBoardJobs[index2].unk4.dungeon.id) ||
                ((gUnknown_203B490->pelipperBoardJobs[index1].unk4.dungeon.id == gUnknown_203B490->pelipperBoardJobs[index2].unk4.dungeon.id) && (gUnknown_203B490->pelipperBoardJobs[index1].unk4.dungeon.floor > gUnknown_203B490->pelipperBoardJobs[index2].unk4.dungeon.floor)))
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
    mail->unk4.dungeon.id = DUNGEON_UPROAR_FOREST;
    mail->unk4.dungeon.floor = 10;
    mail->unk4.seed = Rand32Bit() & 0xffffff;
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
    mail->unk4.dungeon.id = DUNGEON_HOWLING_FOREST;
    mail->unk4.dungeon.floor = 15;
    mail->unk4.seed = Rand32Bit() & 0xffffff;
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
    mail->unk4.dungeon.id = DUNGEON_WISH_CAVE;
    mail->unk4.dungeon.floor = 20;
    mail->unk4.seed = Rand32Bit() & 0xffffff;
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
                    if(mail->unk4.dungeon.id == jobSlot->unk4.dungeon.id)
                        if(mail->unk4.dungeon.floor == jobSlot->unk4.dungeon.floor)
                            if(mail->unk4.seed == jobSlot->unk4.seed)
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
  
  dungeonIndex = mail->unk4.dungeon.id;
  floor = mail->unk4.dungeon.floor;
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
    if ((mail->unk4.dungeon.id == dungeon) &&
       (((mail->mailType == MAIL_TYPE_TAKEN_JOB || (mail->mailType == MAIL_TYPE_UNK8)) || (mail->mailType == MAIL_TYPE_UNK9)))) {
      count++;
    }
  } 
  return count;
}

bool8 sub_8096A08(u8 dungeon, PokemonStruct1 *pokemon)
{
  WonderMail *mail;
  s32 index;
  u32 local_14;
  s32 temp;

  for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
  {
      mail = GetJobSlotInfo(index);
      if(mail->unk4.dungeon.id == dungeon)
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

                sub_808CFD0(pokemon,mail->clientSpecies,NULL,0,(DungeonLocation *) &local_14,NULL);
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
  if (jobSlot->unk4.dungeon.id == dungeon) {
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
            if(mail->unk4.dungeon.id == dungeon)
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
  gUnknown_203B490->jobSlots[index].unk4.dungeon.id = 99;
  gUnknown_203B490->jobSlots[index].unk4.dungeon.floor = 0;
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
                    if((gUnknown_203B490->jobSlots[r1].unk4.dungeon.id > gUnknown_203B490->jobSlots[r6].unk4.dungeon.id) || 
                        ((gUnknown_203B490->jobSlots[r1].unk4.dungeon.id == gUnknown_203B490->jobSlots[r6].unk4.dungeon.id) && 
                        (gUnknown_203B490->jobSlots[r1].unk4.dungeon.floor > gUnknown_203B490->jobSlots[r6].unk4.dungeon.floor)))
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
             if(floor <= gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor)
                 if( gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor < 0x32) 
                    floor =  gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor + 1;
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
             if(floor == gUnknown_203B490->mailboxSlots[index].unk4.dungeon.floor)
                return TRUE;
        }
    }
    return FALSE;
}

s32 CalculateMailChecksum(WonderMail *mail)
{
    s32 sum;

    sum = (mail->unk2 + mail->missionType);
    
    sum += mail->unk4.dungeon.id;
    sum += mail->unk4.dungeon.floor;

    sum += mail->unk4.seed << 0x8;

    sum += mail->clientSpecies << 0xC;

    sum += mail->targetSpecies << 0x10;

    sum += mail->targetItem << 0x18;

    sum += mail->rewardType;

    sum += mail->itemReward;

    sum += mail->friendAreaReward;

    return sum;
}

void sub_8096EEC(WonderMail *mail)
{
    s32 index;

    for(index = 15; index > 0; index--)
    {
         gUnknown_203B490->unk230[index] =  gUnknown_203B490->unk230[index - 1];
    }
    gUnknown_203B490->unk230[0].sub = mail->unk4;
    gUnknown_203B490->unk230[0].checksum = CalculateMailChecksum(mail);
}

bool8 sub_8096F50(WonderMail *mail)
{
    s32 index;
    s32 checksum;
    subStruct_203B490 *temp;

    checksum = CalculateMailChecksum(mail);

    for (index = 0; index < 0x10; index++) {
        temp  = &gUnknown_203B490->unk230[index];
        if (temp->sub.dungeon.id == mail->unk4.dungeon.id)
            if (temp->sub.dungeon.floor == mail->unk4.dungeon.floor)
                if (temp->sub.seed == mail->unk4.seed)
                    if (temp->checksum == checksum)
                        return TRUE;
    }

    return FALSE;
}

u32 RestoreMailInfo(u8 *r0, u32 size)
{
    s32 index;
    unkStruct_8094924 backup;
    u32 temp;

    xxx_init_struct_8094924_restore_809485C(&backup, r0, size);
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        RestoreWonderMail(&backup, &gUnknown_203B490->mailboxSlots[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        RestoreWonderMail(&backup, &gUnknown_203B490->pelipperBoardJobs[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        RestoreWonderMail(&backup, &gUnknown_203B490->jobSlots[index]);
    }
    for(index = 0; index < 0x38; index++)
    {
        RestoreIntegerBits(&backup, &temp, 1);
        if(temp & 1)
            gUnknown_203B490->PKMNNewsReceived[index] = TRUE;
        else
            gUnknown_203B490->PKMNNewsReceived[index] = FALSE;
    }
    RestoreIntegerBits(&backup, &temp, 1);
    if(temp & 1)
        gUnknown_203B490->unk328 = TRUE;
    else
        gUnknown_203B490->unk328 = FALSE;
    
    RestoreIntegerBits(&backup, gUnknown_203B490->unk190, 0x140);
    RestoreIntegerBits(&backup, gUnknown_203B490->unk1B8, 0x3C0);
    for(index = 0; index < 0x10; index++)
    {
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].checksum, 0x20);
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].sub.seed, 0x18);
        RestoreDungeonLocation(&backup, &gUnknown_203B490->unk230[index].sub.dungeon);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

u32 SaveMailInfo(u8 *r0, u32 size)
{
    s32 index;
    unkStruct_8094924 backup;
    u32 temp;

    xxx_init_struct_8094924_save_809486C(&backup, r0, size);
    for(index = 0; index < NUM_MAILBOX_SLOTS; index++)
    {
        SaveWonderMail(&backup, &gUnknown_203B490->mailboxSlots[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        SaveWonderMail(&backup, &gUnknown_203B490->pelipperBoardJobs[index]);
    }
    for(index = 0; index < MAX_ACCEPTED_JOBS; index++)
    {
        SaveWonderMail(&backup, &gUnknown_203B490->jobSlots[index]);
    }
    for(index = 0; index < 0x38; index++)
    {
        if(gUnknown_203B490->PKMNNewsReceived[index])
            temp = -1;
        else
            temp = 0;
        SaveIntegerBits(&backup, &temp, 1);
    }
    if(gUnknown_203B490->unk328)
        temp = -1;
    else
        temp = 0;
    SaveIntegerBits(&backup, &temp, 1);
    SaveIntegerBits(&backup, gUnknown_203B490->unk190, 0x140);
    SaveIntegerBits(&backup, gUnknown_203B490->unk1B8, 0x3C0);
    for(index = 0; index < 0x10; index++)
    {
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].checksum, 0x20);
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].sub.seed, 0x18);
        SaveDungeonLocation(&backup, &gUnknown_203B490->unk230[index].sub.dungeon);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void RestoreWonderMail(unkStruct_8094924 *a, WonderMail *b)
{
    RestoreIntegerBits(a, &b->mailType, 4);
    RestoreIntegerBits(a, &b->missionType, 3);
    RestoreIntegerBits(a, &b->unk2, 4);
    RestoreIntegerBits(a, &b->clientSpecies, 9);
    RestoreIntegerBits(a, &b->targetSpecies, 9);
    RestoreIntegerBits(a, &b->targetItem, 8);
    RestoreIntegerBits(a, &b->rewardType, 4);
    RestoreIntegerBits(a, &b->itemReward, 8);
    RestoreIntegerBits(a, &b->friendAreaReward, 6);
    RestoreIntegerBits(a, &b->unk4.seed, 0x18);
    RestoreDungeonLocation(a, &b->unk4.dungeon);
}

void SaveWonderMail(unkStruct_8094924 *a, WonderMail *b)
{
    SaveIntegerBits(a, &b->mailType, 4);
    SaveIntegerBits(a, &b->missionType, 3);
    SaveIntegerBits(a, &b->unk2, 4);
    SaveIntegerBits(a, &b->clientSpecies, 9);
    SaveIntegerBits(a, &b->targetSpecies, 9);
    SaveIntegerBits(a, &b->targetItem, 8);
    SaveIntegerBits(a, &b->rewardType, 4);
    SaveIntegerBits(a, &b->itemReward, 8);
    SaveIntegerBits(a, &b->friendAreaReward, 6);
    SaveIntegerBits(a, &b->unk4.seed, 0x18);
    SaveDungeonLocation(a, &b->unk4.dungeon);
}
