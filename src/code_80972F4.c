#include "global.h"
#include "constants/dungeon.h"
#include "pokemon.h"
#include "wonder_mail.h"
#include "code_80958E8.h"
#include "dungeon.h"
#include "exclusive_pokemon.h"
#include "event_flag.h"
#include "code_80A26CC.h"
#include "code_80972F4.h"

extern MissionText gStoryMissionText[];
extern const char gFinalScenarioText[];
extern const char gMeetNinetalesText[];
extern const char gAvoidCaptureText[];
extern const u8 gUnknown_8109CC0[];
extern const u8 gDummyScenarioText[];

extern void sub_800199C(u8, u8, u16, s32);

void SaveWonderMail(struct unkStruct_8094924 *a, WonderMail *b);
void RestoreWonderMail(struct unkStruct_8094924 *a, WonderMail *b);
extern s32 sub_8096EB0(WonderMail *);
extern void SaveDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
extern u32 sub_8001784(u32, u32, u16);
extern void GeneratePelipperJobs(void);
extern void sub_80018D8(u8, u8, u32);

bool8 sub_8096F50(WonderMail *mail)
{
    s32 index;
    s32 temp2;
    subStruct_203B490 *temp;

    temp2 = sub_8096EB0(mail);

    for (index = 0; index < 0x10; index++) {
        temp  = &gUnknown_203B490->unk230[index];
        if (temp->dungeon.id == mail->unk4.dungeon.id)
            if (temp->dungeon.floor == mail->unk4.dungeon.floor)
                if (temp->seed == mail->unk4.seed)
                    if (temp->unk8 == temp2)
                        return TRUE;
    }

    return FALSE;
}

u32 RestoreMailInfo(u8 *r0, u32 size)
{
    s32 index;
    struct unkStruct_8094924 backup;
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
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk8, 0x20);
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].seed, 0x18);
        RestoreDungeonLocation(&backup, &gUnknown_203B490->unk230[index].dungeon);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

u32 SaveMailInfo(u8 *r0, u32 size)
{
    s32 index;
    struct unkStruct_8094924 backup;
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
        if(gUnknown_203B490->PKMNNewsReceived[index] != 0)
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
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk8, 0x20);
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].seed, 0x18);
        SaveDungeonLocation(&backup, &gUnknown_203B490->unk230[index].dungeon);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void RestoreWonderMail(struct unkStruct_8094924 *a, WonderMail *b)
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

void SaveWonderMail(struct unkStruct_8094924 *a, WonderMail *b)
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

void sub_80972F4(void)
{
    sub_80015C0(0, 0x2B);
    sub_80015C0(0, 0x2C);
    sub_80015C0(0, 0x2D);
}

void nullsub_128(void)
{}

s32 sub_8097318(s16 param_1)
{
  s32 iVar1;
  s32 param_1_s32;

  param_1_s32 = param_1;
  
  if (param_1_s32 == 0xd) {
    iVar1 = 0;
  }
  else {
    iVar1 = sub_8001784(0,0x2b,param_1_s32);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

void sub_809733C(short param_1,u32 param_2)
{
  s32 uVar2;
  u8 param_2_u8;
  u16 uVar2_u16;
  
  uVar2 = param_1;
  param_2_u8 = param_2;

  if (uVar2 != 0xd) {
    uVar2_u16 = uVar2;
    if ((((sub_8001784(0,0x2c,uVar2_u16) == 0) && (sub_800199C(0,0x2b,uVar2_u16,param_2_u8), param_2_u8 != '\0')))){
        switch(uVar2)
        {
            case 0xE:
            case 0xF:
            case 0x1C:
                GeneratePelipperJobs();
                break;
        }
      }
    }
}

bool32 sub_8097384(s16 param_1)
{
    bool32 val;

    if (param_1 == 13)
        val = FALSE;
    else {
        // May not need the & 0xFFFF if the 3rd param is s16
        val = sub_8001784(0, 44, param_1 & 0xFFFF);
        if (val != 0)
            val = TRUE;
    }

    return val;
}

void sub_80973A8(s16 param_1,u32 param_2)
{
  s32 sVar1;
  s32 param_1_s32 = param_1;
  u8 param_2_u32 = param_2;
  
  if (param_1_s32 != 0xd) {
    if (param_2_u32 != 0) {
      sVar1 = sub_80A26B8(param_1);
      sub_800199C(0,0x2b,param_1_s32,0);
      if (sVar1 != -1) {
        sub_80018D8(0,0x12,sVar1);
      }
    }
    sub_800199C(0,0x2c,param_1_s32,param_2_u32);
  }
}

bool32 sub_80973F4(s16 param_1)
{
    bool32 val;

    if (param_1 == 13)
        val = FALSE;
    else {
        // May not need the & 0xFFFF if the 3rd param is s16
        val = sub_8001784(0, 45, param_1 & 0xFFFF);
        if (val != 0)
            val = TRUE;
    }

    return val;
}

void sub_8097418(s16 index,u32 param_2)
{
  int index_s32 = index;
  u8 param_2_u8 = param_2;
  if (index_s32 != 0xd) {
    if ((param_2_u8 != 0) && (sub_800199C(0,0x2c,index_s32,0), index_s32 < 0x1f)) {
      MissionText *mt = &gStoryMissionText[index_s32];
      if (mt->unk4 != 0xFF) {
        sub_8097FA8(mt->unk4);
      }
      if (mt->unk5 != 0xFF) {
        sub_8097FA8(mt->unk5);
      }
      if (index_s32 == 9) {
        sub_8097FA8(0x1f);
      }
      sub_8097FF8();
    }
    sub_800199C(0,0x2d,index_s32,param_2_u8);
  }
}

const u8 *sub_809747C(s16 index)
{
    if(index == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(index));
    }
}

const u8 *sub_80974A0(s16 index)
{
    if(index == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(index));
    }
}

const u8 *GetCurrentMissionText(s16 index)
{
    if(index < 0x1F)
    {
        MissionText *mt = &gStoryMissionText[index];
        return mt->text;
    }
    else
    {
        return gUnknown_8109CC0;
    }
}

void sub_80974E8(void)
{
    sub_80015C0(0, 0x2E);
    sub_80015C0(0, 0x2F);
}

void nullsub_208(void)
{
}

bool8 sub_8097504(s16 mazeIndex)
{
    s32 mazeIndex_s32;

#ifndef NONMATCHING
    register s32 mazeIndex_s32_1 asm("r1");
#else
    s32 mazeIndex_s32_1;
#endif
    s32 uVar3;

    mazeIndex_s32 = mazeIndex;
    mazeIndex_s32_1 = mazeIndex_s32;

    if(mazeIndex_s32 < 17)
    {
        switch(mazeIndex_s32) {
            case 2:
            case 10:
            case 11:
            case 12:
                uVar3 = 14;
                break;
            case 0:
            case 1:
            case 5:
            case 7:
            case 9:
            case 14:
                uVar3 = 15;
                break;
            case 3:
            case 4:
            case 6:
            case 8:
                return TRUE;
            case 13:
                uVar3 = 6;
                break;
            default:
                return TRUE;
        }
    }
    else
    {
        if (mazeIndex_s32_1 > 22)  return FALSE;
        if (mazeIndex_s32_1 == 22) return FALSE;
        if (mazeIndex_s32_1 == 21) return FALSE;
        uVar3 = 6;
    }

    if (!sub_80023E4(uVar3)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

// TODO: this should probably be bool8 but can't get a match just yet
bool32 IsMazeCompleted(s16 mazeIndex)
{
    bool32 mazeCompletion;

    mazeCompletion = sub_8001784(0, 0x2e, mazeIndex);
    if (mazeCompletion) {
        mazeCompletion = TRUE;
    }
    return mazeCompletion;
}

void sub_80975A8(s16 param_1,u8 param_2)
{ 
    u16 param_1_u16 = param_1;
    sub_800199C(0,0x2e,param_1_u16,param_2);
}

const u8 *sub_80975C4(s16 index)
{
    return GetDungeonName1(sub_80A2728(index));
}

const u8 *sub_80975DC(u32 r0)
{
    // TODO: slight hack but matches
    r0 <<= 16;
    if((0xffe90000 + r0) >> 16 < 2)
        if(sub_8001D08(0x3, 0xE, -1))
            return gMeetNinetalesText;
        else
            return gAvoidCaptureText;
    else
        return gFinalScenarioText;
}

bool8 HasCompletedAllMazes(void)
{
    s32 index;
    for(index = 0; index < NUM_BASIC_DUNGEON_MAZE; index++)
    {
        if(!(bool8)IsMazeCompleted(index))
            return FALSE;
    }
    return TRUE;
}

bool8 sub_8097640(void)
{
    if(sub_8001784(0, 0x2E, 0x1F) == 0 && HasCompletedAllMazes())
    {
        sub_800199C(0, 0x2E, 0x1F, 1);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
