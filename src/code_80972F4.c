#include "global.h"
#include "pokemon.h"
#include "wonder_mail.h"
#include "code_80958E8.h"

void SaveWonderMail(struct unkStruct_8094924 *a, struct WonderMail *b);
void RestoreWonderMail(struct unkStruct_8094924 *a, struct WonderMail *b);
extern s32 sub_8096EB0(struct WonderMail *);
extern void SaveDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void sub_80015C0(u32, u32);
extern u32 sub_8001784(u32, u32, u16);
extern void sub_809674C();
extern void sub_800199C(u32, s32, u32, s32);

bool8 sub_8096F50(struct WonderMail *mail)
{
    s32 index;
    s32 temp2;
    struct subStruct_203B490 *temp;

    temp2 = sub_8096EB0(mail);


    for(index = 0; index < 0x10; index++)
    {
        temp  = &gUnknown_203B490->unk230[index];
        if(temp->dungeon.dungeonIndex == mail->dungeon.dungeonIndex)
            if(temp->dungeon.dungeonFloor == mail->dungeon.dungeonFloor)
                if(temp->unk4 == mail->unk8)
                    if(temp->unk8 == temp2)
                        return TRUE;
    }
    return FALSE;
}

u32 sub_8096FA0(u8 *r0, u32 size)
{
    s32 index;
    struct unkStruct_8094924 backup;
    u32 temp;

    xxx_init_struct_8094924_restore_809485C(&backup, r0, size);
    for(index = 0; index < 4; index++)
    {
        RestoreWonderMail(&backup, &gUnknown_203B490->mailboxSlots[index]);
    }
    for(index = 0; index < 8; index++)
    {
        RestoreWonderMail(&backup, &gUnknown_203B490->pelliperBoardJobs[index]);
    }
    for(index = 0; index < 8; index++)
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
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk4, 0x18);
        RestoreDungeonLocation(&backup, &gUnknown_203B490->unk230[index].dungeon);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

u32 sub_80970D8(u8 *r0, u32 size)
{
    s32 index;
    struct unkStruct_8094924 backup;
    u32 temp;

    xxx_init_struct_8094924_save_809486C(&backup, r0, size);
    for(index = 0; index < 4; index++)
    {
        SaveWonderMail(&backup, &gUnknown_203B490->mailboxSlots[index]);
    }
    for(index = 0; index < 8; index++)
    {
        SaveWonderMail(&backup, &gUnknown_203B490->pelliperBoardJobs[index]);
    }
    for(index = 0; index < 8; index++)
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
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk4, 0x18);
        SaveDungeonLocation(&backup, &gUnknown_203B490->unk230[index].dungeon);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void RestoreWonderMail(struct unkStruct_8094924 *a, struct WonderMail *b)
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
    RestoreIntegerBits(a, &b->unk8, 0x18);
    RestoreDungeonLocation(a, &b->dungeon);
}

void SaveWonderMail(struct unkStruct_8094924 *a, struct WonderMail *b)
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
    SaveIntegerBits(a, &b->unk8, 0x18);
    SaveDungeonLocation(a, &b->dungeon);
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
                sub_809674C();
                break;
        }
      }
    }
}

bool32 sub_8097384(s16 param_1)
{
  bool32 iVar1;
  
  if (param_1 == 0xd) {
    iVar1 = FALSE;
  }
  else {
    iVar1 = sub_8001784(0,0x2c,param_1 & 0xffff);
    if (iVar1 != 0) {
      iVar1 = TRUE;
    }
  }
  return iVar1;
}
