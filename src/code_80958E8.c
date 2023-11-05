#include "global.h"
#include "code_803C1D0.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_80958E8_1.h"
#include "constants/friend_area.h"
#include "constants/wonder_mail.h"
#include "dungeon.h"
#include "friend_area.h"
#include "items.h"
#include "mailbox_8095F8C.h"
#include "memory.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "pokemon_mail.h"

extern bool8 sub_809017C(DungeonLocation *);
extern void ResetPelipperBoardSlot(u8);

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
        gUnknown_203B490->unk230[index].dungeon.id = 99;
        gUnknown_203B490->unk230[index].dungeon.floor = 1;
        gUnknown_203B490->unk230[index].seed = 0;
        gUnknown_203B490->unk230[index].unk8 = 0;
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

        if(sub_809095C(data->unk4.dungeon.id))
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
