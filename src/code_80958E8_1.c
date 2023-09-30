#include "constants/mailbox.h"
#include "global.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "constants/wonder_mail.h"
#include "items.h"
#include "code_80958E8.h"
#include "code_80958E8_1.h"
#include "random.h"
#include "pokemon.h"
#include "code_8096AF8.h"

extern bool8 IsValidWonderMail(WonderMail *WonderMailData);
extern u8 sub_8095E38(WonderMail *, u8, u8, bool8);
extern void sub_80965F4();
extern void SortPelipperJobs();
u8 sub_8097318(s16 param_1);
extern bool8 GenerateMailJobInfo(WonderMail *);

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
  sub_80965F4();
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

bool8 sub_8096A08(u8 dungeon, u8 *param_2)
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

                sub_808CFD0(param_2,mail->clientSpecies,NULL,0,&local_14,NULL);
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
  sub_8096C80();
  sub_8096D24();
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
