#include "global.h"
#include "memory.h"
#include "item.h"
#include "friend_area.h"
#include "constants/friend_area.h"
#include "wonder_mail.h"
#include "constants/wonder_mail.h"
#include "dungeon.h"
#include "code_80958E8.h"
#include "pokemon.h"
#include "code_8094F88.h"

extern s32 GetDungeonFloorCount(u8);
extern bool8 sub_809017C(struct DungeonLocation *);
extern s16 GetBaseSpecies(s16);
extern bool8 IsInvalidItemReward(u8);
extern u8 sub_803C1D0(struct DungeonLocation *, u8);
extern bool8 IsNotMoneyOrUsedTMItem(u8);
extern u8 xxx_bit_lut_lookup_8091E50(u8 ,u8 );
extern u32 GetMaxItemCount(u8);
extern bool8 sub_803C0DC(s16);
extern void ResetMailboxSlot(u8);
extern void ResetPelliperBoardSlot(u8);
extern void ResetJobSlot(u8);
extern bool8 ValidateWonderMail(struct WonderMail *);

extern struct unkStruct_203B490 *gUnknown_203B490;
extern struct unkStruct_203B490 gUnknown_2039448;

void LoadMailInfo(void)
{
    gUnknown_203B490 = &gUnknown_2039448;
}

struct unkStruct_203B490 *GetMailInfo(void)
{
    return &gUnknown_2039448;
}

void InitializeMailJobsNews(void)
{
    s32 index;
    for(index = 0; index < 4; index++)
    {
        ResetMailboxSlot(index);
    }
    for(index = 0; index < 8; index++)
    {
        ResetPelliperBoardSlot(index);
    }
    for(index = 0; index < 8; index++)
    {
        ResetJobSlot(index);
    }
    for(index = 0; index < 56; index++)
    {
        gUnknown_203B490->PKMNNewsReceived[index] = FALSE;
    }
    gUnknown_203B490->unk328 = FALSE;
    MemoryClear8(gUnknown_203B490->unk190, sizeof(gUnknown_203B490->unk190));
    MemoryClear8(gUnknown_203B490->unk1B8, sizeof(gUnknown_203B490->unk1B8));
    for(index = 0; index < 16; index++)
    {
        gUnknown_203B490->unk230[index].dungeon.dungeonIndex = 99;
        gUnknown_203B490->unk230[index].dungeon.dungeonFloor = 1;
        gUnknown_203B490->unk230[index].unk4 = 0;
        gUnknown_203B490->unk230[index].unk8 = 0;
    }
}

bool8 IsValidWonderMail(struct WonderMail *WonderMailData)
{
    // Has to equal 5 for Wonder Mail
    // https://web.archive.org/web/20080913124416/http://www.upokecenter.com/games/dungeon/guides/passwords.html
    //
    if(WonderMailData->mailType != WONDER_MAIL_TYPE_WONDER)
    {
        return FALSE;
    }
    else
    {
        return ValidateWonderMail(WonderMailData);
    }
}

bool8 ValidateWonderMail(struct WonderMail *data)
{

    if(data->missionType > WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM)
        return FALSE;
    else
    {
        if(data->missionType == WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM && GetMaxItemCount(data->dungeon.dungeonIndex) == 0)
            return FALSE;

        if(data->unk2 > 9)
            return FALSE;

        if(sub_809095C(data->dungeon.dungeonIndex))
            return FALSE;
        if(data->dungeon.dungeonFloor >= GetDungeonFloorCount(data->dungeon.dungeonIndex))
            return FALSE;
        if(sub_809017C(&data->dungeon))
            return FALSE;

        if(data->clientSpecies == SPECIES_NONE)
            return FALSE;
        if(data->clientSpecies > SPECIES_RAYQUAZA_CUTSCENE)
            return FALSE;
        if(data->clientSpecies != GetBaseSpecies(data->clientSpecies))
            return FALSE;
        if(!sub_803C0DC(data->clientSpecies))
            return FALSE;

        if(data->targetSpecies > SPECIES_RAYQUAZA_CUTSCENE)
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
        if(data->missionType == WONDER_MAIL_MISSION_TYPE_FIND_ITEM && xxx_bit_lut_lookup_8091E50(data->dungeon.dungeonIndex, data->targetItem) == 0)
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
            if(sub_803C1D0(&data->dungeon, data->missionType) == 0)
                return FALSE;
        }
        return TRUE;
    }
}
