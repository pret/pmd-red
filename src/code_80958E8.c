#include "global.h"
#include "memory.h"
#include "friend_area.h"
#include "constants/friend_area.h"
#include "wonder_mail.h"
#include "constants/wonder_mail.h"

struct subStruct_203B490
{
    // size: 0xC
    u8 unk0;
    u8 unk1;
    u8 fill2[2];
    u32 unk4;
    u32 unk8;
};
 

struct unkStruct_203B490
{
    // size: 0x330?

    u8 fill0[0x190];
    u8 unk190[0x28];
    u8 unk1B8[0x78];
    struct subStruct_203B490 unk230[16];
    u8 unk2F0[0x38];
    u8 unk328;
};


extern u8 sub_809095C(u8);
extern s32 sub_8090298(u8);
extern u8 sub_809017C(u8 *);
extern s16 sub_808E770(s16);
extern u8 sub_8092040(u8);
extern u8 sub_803C1D0(u8 *, u8);
extern u8 sub_8090A60(u8);
extern u8 sub_8091524(u8);
extern u8 sub_8091E60(u8 ,u8 );
extern u32 GetMaxItemCount(u8);
extern u8 sub_803C0DC(s16);
extern void sub_8096040(u8);
extern void sub_80965B8(u8);
extern void sub_8096C3C(u8);
extern bool8 ValidateWonderMail(struct WonderMail *);

extern struct unkStruct_203B490 *gUnknown_203B490;
extern struct unkStruct_203B490 gUnknown_2039448;

void sub_80958E8()
{
    gUnknown_203B490 = &gUnknown_2039448;
}

struct unkStruct_203B490 *sub_80958F8(void)
{
    return &gUnknown_2039448;
}

void sub_8095900(void)
{
    s32 iVar2;
    for(iVar2 = 0; iVar2 < 4; iVar2++)
    {
        sub_8096040(iVar2);
    }
    for(iVar2 = 0; iVar2 < 8; iVar2++)
    {
        sub_80965B8(iVar2);
    }
    for(iVar2 = 0; iVar2 < 8; iVar2++)
    {
        sub_8096C3C(iVar2);
    }
    for(iVar2 = 0; iVar2 < 0x38; iVar2++)
    {
        gUnknown_203B490->unk2F0[iVar2] = 0;
    }
    gUnknown_203B490->unk328 = 0;
    MemoryClear8(gUnknown_203B490->unk190, sizeof(gUnknown_203B490->unk190));
    MemoryClear8(gUnknown_203B490->unk1B8, sizeof(gUnknown_203B490->unk1B8));
    for(iVar2 = 0; iVar2 < 16; iVar2++)
    {
        gUnknown_203B490->unk230[iVar2].unk0 = 0x63;
        gUnknown_203B490->unk230[iVar2].unk1 = 1;
        gUnknown_203B490->unk230[iVar2].unk4 = 0;
        gUnknown_203B490->unk230[iVar2].unk8 = 0;
    }
}

bool8 IsValidWonderMail(struct WonderMail *WonderMailData)
{
    // Has to equal 5 for Wonder Mail
    // https://web.archive.org/web/20080913124416/http://www.upokecenter.com/games/dungeon/guides/passwords.html
    //
    if(WonderMailData->mailType != 5)
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

    if(data->missionType > DELIVER_ITEM)
        return FALSE;
    else
    {
        if(data->missionType == DELIVER_ITEM && GetMaxItemCount(data->dungeon) == 0)
            return FALSE;

        if(data->unk2 > 9)
            return FALSE;

        if(sub_809095C(data->dungeon) != 0)
            return FALSE;
        if(data->floor >= sub_8090298(data->dungeon))
            return FALSE;
        if(sub_809017C(&(data->dungeon)) != 0)
            return FALSE;

        if(data->clientPoke == SPECIES_NONE)
            return FALSE;
        if(data->clientPoke > SPECIES_RAYQUAZA_CUTSCENE)
            return FALSE;
        if(data->clientPoke != sub_808E770(data->clientPoke))
            return FALSE;
        if(sub_803C0DC(data->clientPoke) == 0)
            return FALSE;

        if(data->targetPoke > SPECIES_RAYQUAZA_CUTSCENE)
            return FALSE;
        if(data->targetPoke != sub_808E770(data->targetPoke))
            return FALSE;
        if(sub_803C0DC(data->targetPoke) == 0)
            return FALSE;

        // Item Delivery/Finding
        if((u8)(data->missionType - 1) > FIND_POKE)
            if(data->targetPoke != data->clientPoke)
                return FALSE;

        if(sub_8092040(data->targetItem) != 0)
            return FALSE;
        if(sub_8090A60(data->targetItem) != 0)
            return FALSE;
        if(sub_8091524(data->targetItem) == 0)
            return FALSE;

        // Item finding
        if(data->missionType == FIND_ITEM && sub_8091E60(data->dungeon, data->targetItem) == 0)
            return FALSE;

        if(data->rewardType == BLANK_4 || data->rewardType == END_REWARDS || data->rewardType > END_REWARDS)
            return FALSE;

        if(sub_8092040(data->itemReward) != 0)
            return FALSE;

        // Friend Area Reward
        if(data->friendAreaReward > FINAL_ISLAND)
            return FALSE;

        if(data->rewardType == FRIEND_AREA)
        {
            if(GetFriendAreaUnlockCondition(data->friendAreaReward) != UNLOCK_WONDER_MAIL)
                return FALSE;
            if(sub_803C1D0(&(data->dungeon), data->missionType) == 0)
                return FALSE;
        }
        return TRUE;
    }
}
