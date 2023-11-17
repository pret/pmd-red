#include "global.h"
#include "constants/dungeon.h"
#include "pokemon.h"
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
extern void SaveDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, DungeonLocation*);
extern u32 sub_8001784(u32, u32, u16);
extern void GeneratePelipperJobs(void);
extern void sub_80018D8(u8, u8, u32);

void SaveWonderMail(struct unkStruct_8094924 *a, WonderMail *b);
void RestoreWonderMail(struct unkStruct_8094924 *a, WonderMail *b);
s32 CalculateMailChecksum(WonderMail *mail);

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
        if(gUnknown_203B490->PKMNNewsReceived[index] == FALSE) return index;
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

// 100 (97.92% matching - Seth)
// https://decomp.me/scratch/gl6SB 
#ifdef NONMATCHING
void sub_8096EEC(WonderMail *mail)
{
    register WonderMail *temp1 asm("ip");
    s32 index;

    temp1 = mail;

    for(index = 15; index > 0; index--)
    {
         gUnknown_203B490->unk230[index] =  gUnknown_203B490->unk230[index - 1];
    }
    {
        register DungeonLocation temp;
        register subStruct_203B490 *org;
        register s32 seed;
        
        org = &gUnknown_203B490->unk230[0];
        temp = temp1->unk4.dungeon;
        seed = temp1->unk4.seed;
        org->dungeon = temp;
        org->seed = seed;
    }
    gUnknown_203B490->unk230[0].checksum = CalculateMailChecksum(temp1);
}
#else
NAKED
void sub_8096EEC(WonderMail *mail)
{
	asm_unified(
    "\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tmov r12, r0\n"
	"\tmovs r3, 0xF\n"
	"\tldr r5, _08096F4C\n"
	"\tmov r8, r5\n"
	"\tmovs r4, 0x8C\n"
	"\tlsls r4, 2\n"
"_08096EFE:\n"
	"\tmov r0, r8\n"
	"\tldr r2, [r0]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 2\n"
	"\tadds r1, r2, r1\n"
	"\tsubs r3, 0x1\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 2\n"
	"\tadds r2, r0\n"
	"\tadds r1, r4\n"
	"\tadds r2, r4\n"
	"\tldm r2!, {r0,r6,r7}\n"
	"\tstm r1!, {r0,r6,r7}\n"
	"\tcmp r3, 0\n"
	"\tbgt _08096EFE\n"
	"\tldr r2, [r5]\n"
	"\tmovs r3, 0x8C\n"
	"\tlsls r3, 2\n"
	"\tadds r2, r3\n"
	"\tmov r6, r12\n"
	"\tldr r0, [r6, 0x4]\n"
	"\tldr r1, [r6, 0x8]\n"
	"\tstr r0, [r2]\n"
	"\tstr r1, [r2, 0x4]\n"
	"\tmov r0, r12\n"
	"\tbl CalculateMailChecksum\n"
	"\tldr r1, [r5]\n"
	"\tmovs r7, 0x8E\n"
	"\tlsls r7, 2\n"
	"\tadds r1, r7\n"
	"\tstr r0, [r1]\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08096F4C: .4byte gUnknown_203B490");
}
#endif

bool8 sub_8096F50(WonderMail *mail)
{
    s32 index;
    s32 checksum;
    subStruct_203B490 *temp;

    checksum = CalculateMailChecksum(mail);

    for (index = 0; index < 0x10; index++) {
        temp  = &gUnknown_203B490->unk230[index];
        if (temp->dungeon.id == mail->unk4.dungeon.id)
            if (temp->dungeon.floor == mail->unk4.dungeon.floor)
                if (temp->seed == mail->unk4.seed)
                    if (temp->checksum == checksum)
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
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].checksum, 0x20);
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

void sub_8097418(s16 index,bool32 param_2)
{
  int index_s32 = index;
  bool8 param_2_u8 = param_2;
  if (index_s32 != 0xd) {
    if ((param_2_u8) && (sub_800199C(0,0x2c,index_s32,0), index_s32 < 0x1f)) {
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
