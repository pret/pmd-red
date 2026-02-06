#include "global.h"
#include "code_803C1B4.h"
#include "structs/str_mission_rewards.h"
#include "structs/str_wonder_mail.h"
#include "dungeon_info.h"
#include "event_flag.h"
#include "pokemon.h"

extern u8 *gMissionRankText[];
extern s32 gUnknown_80E80A0[];

s32 sub_803C1B4(DungeonLocation *dungeon, u8 missionType)
{
    s32 temp;
    temp = GetDungeonLocMissionDifficulty(dungeon);
    if(missionType == 2)
    {
        temp += 2;
    }
    if(temp > 0xF)
        temp = 0xF;
    return temp;
}

u8 sub_803C1D0(DungeonLocation *dungeon, u8 missionType)
{
    s32 a = sub_803C1B4(dungeon, missionType);
    a /= 2;
    if ((u8)a >= 7) {
        a = 6;
        return a;
    }
    return a;
}

const u8 *GetMissionRankText(u8 index)
{
    return gMissionRankText[index];
}

u32 GetDungeonTeamRankPts(DungeonLocation *dungeon, u8 r1)
{
    u32 index = sub_803C1B4(dungeon, r1);
    return gUnknown_80E80A0[index];
}

void sub_803C21C(WonderMail *param_1, MissionRewards *rewards)
{
    s32 index;
    u32 uVar2;

    uVar2 = sub_803C1D0(&param_1->dungeonSeed.location,param_1->missionType);
    rewards->moneyReward = 0;

    for (index = 0; index < MAX_ITEM_REWARDS; index++) {
        rewards->itemRewards[index] = ITEM_NOTHING;
    }

    rewards->friendAreaReward = 0;
    rewards->quantity = 10;
    switch(param_1->rewardType) {
        case MONEY:
            rewards->rewardType = 0;
            rewards->moneyReward = (uVar2 + 1) * 100;
            break;
        case MONEY_EXTRA:
            rewards->rewardType = 1;
            rewards->moneyReward = (uVar2 + 1) * 100;
            rewards->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM:
            rewards->rewardType = 2;
            rewards->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM_EXTRA:
            rewards->rewardType = 3;
            rewards->itemRewards[0] = param_1->itemReward;
            do {
                sub_803C37C(&param_1->dungeonSeed.location, param_1->missionType, &rewards->itemRewards[1]);
            } while (rewards->itemRewards[0] == rewards->itemRewards[1]);
            break;
        case MONEY1:
            rewards->rewardType = 0;
            rewards->moneyReward = (uVar2 + 1) * 200;
            break;
        case MONEY1_EXTRA:
            rewards->rewardType = 1;
            rewards->moneyReward = (uVar2 + 1) * 200;
            rewards->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM1: // ITEM1
            rewards->rewardType = 2;
            rewards->itemRewards[0] = param_1->itemReward;
            break;
        case ITEM1_EXTRA:
            rewards->rewardType = 3;
            rewards->itemRewards[0] = param_1->itemReward;
            do {
                sub_803C37C(&param_1->dungeonSeed.location, param_1->missionType, &rewards->itemRewards[1]);
            } while (rewards->itemRewards[0] == rewards->itemRewards[1]);
            do {
                do {
                    sub_803C37C(&param_1->dungeonSeed.location, param_1->missionType, &rewards->itemRewards[2]);
                } while (rewards->itemRewards[0] == rewards->itemRewards[2]);
            } while (rewards->itemRewards[1] == rewards->itemRewards[2]);
            break;
        case FRIEND_AREA:
            rewards->rewardType = 4;
            rewards->friendAreaReward = param_1->friendAreaReward;
            break;
        default:
            rewards->rewardType = 5;
            break;
    }
    CopyYellowMonsterNametoBuffer(rewards->clientName, param_1->clientSpecies);
    rewards->clientSpecies = param_1->clientSpecies;
    rewards->teamRankPtsReward = GetDungeonTeamRankPts(&param_1->dungeonSeed.location,param_1->missionType);
}

void sub_803C37C(DungeonLocation *location, u8 r1, u8 *itemReward)
{
    s32 r7;
    bool8 flag;
    u8 r4;

    r7 = sub_803C1B4(location, r1);
    GetRandomItemForValidDungeonLoc(location, r7);

    do {
        flag = FALSE;
        r4 = GetRandomItemForValidDungeonLoc(location, r7);
        if(r4 == ITEM_WEAVILE_FIG)
            flag = GetScriptVarArrayValue(0, EVENT_B01P01, 1) ? TRUE : FALSE;
        if(r4 == ITEM_MIME_JR_FIG)
            if(GetScriptVarArrayValue(0, EVENT_B01P01, 0)) flag = TRUE;
    } while(flag);

    *itemReward = r4;
}

// TODO: Figure out if this is the right file
#include "random.h"
#include "pokemon_mail.h"
#include "pokemon_mail_pre.h"

bool8 sub_803C3E0(WonderMail *mail)
{
    const unkStruct_80E9920 *ptr;
    s32 counter, id;
    s32 stack[ARRAY_COUNT(gUnknown_80E9920)];

    counter = 0;
    for (ptr = gUnknown_80E9920, id = 0; id < ARRAY_COUNT_INT(gUnknown_80E9920); ptr++, id++) {
        if (sub_803C110(ptr->parentSpecies) && sub_803C110(ptr->childSpecies)) {
            stack[counter++] = id;
        }
    }

    if (counter != 0) {
        id = stack[RandInt(counter)];
        ptr = &gUnknown_80E9920[id];
        mail->clientSpecies = ptr->parentSpecies;
        mail->targetSpecies = ptr->childSpecies;
        mail->unk2 = 7;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C45C(WonderMail *mail)
{
    s32 counter, id;
    s32 stack[ARRAY_COUNT(gUnknown_80E9F8C)];
    const unkStruct_80E9F8C *ptr;

    counter = 0;
    ptr = &gUnknown_80E9F8C[0];
    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E9F8C); ptr++, id++) {
        if (sub_803C110(ptr->species.speciesA) && sub_803C110(ptr->species.speciesB)) {
            stack[counter++] = id;
        }
    }

    if (counter != 0) {
        id = stack[RandInt(counter)];
        ptr = &gUnknown_80E9F8C[id];

        if ((Rand32Bit() & 0x10)) {
            mail->clientSpecies = ptr->species.speciesA;
            mail->targetSpecies = ptr->species.speciesB;
        }
        else {
            mail->clientSpecies = ptr->species.speciesB;
            mail->targetSpecies = ptr->species.speciesA;
        }

        mail->unk2 = 8;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C4F0(WonderMail *mail)
{
    s32 counter, id;
    s32 stack[ARRAY_COUNT(gUnknown_80E8168)];
    const struct PokemonPair *ptr;

    counter = 0;
    ptr = &gUnknown_80E8168[0];
    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E8168); ptr++, id++) {
        if (sub_803C110(ptr->speciesA) && sub_803C110(ptr->speciesB)) {
            stack[counter++] = id;
        }
    }

    if (counter != 0) {
        id = stack[RandInt(counter)];
        ptr = &gUnknown_80E8168[id];

        if ((Rand32Bit() & 0x10)) {
            mail->clientSpecies = ptr->speciesA;
            mail->targetSpecies = ptr->speciesB;
        }
        else {
            mail->clientSpecies = ptr->speciesB;
            mail->targetSpecies = ptr->speciesA;
        }

        mail->unk2 = 9;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C580(WonderMail *param_1)
{
    s32 counter, id;
    s32 array[ARRAY_COUNT(gUnknown_80E8180)];
    const struct PokemonItem *ptr;

    counter = 0;
    ptr = gUnknown_80E8180;

    if (!CheckQuest(QUEST_REACHED_POSTGAME))
        return FALSE;

    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E8180); ptr++, id++) {
        if (sub_803C110(ptr->species) && xxx_bit_lut_lookup_8091E50(param_1->dungeonSeed.location.id, ptr->itemId)) {
            array[counter++] = id;
        }
    }

    if (counter != 0) {
        id = array[RandInt(counter)];
        ptr = &gUnknown_80E8180[id];
        param_1->clientSpecies = ptr->species;
        param_1->targetSpecies = ptr->species;
        param_1->targetItem = ptr->itemId;
        param_1->unk2 = 5;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_803C610(WonderMail *param_1)
{
    s32 counter, id;
    s32 array[ARRAY_COUNT(gUnknown_80E81D4)];
    const struct PokemonItem *ptr;

    counter = 0;
    ptr = gUnknown_80E81D4;
    for (id = 0; id < ARRAY_COUNT_INT(gUnknown_80E81D4); ptr++, id++) {
        if (sub_803C110(ptr->species) && xxx_bit_lut_lookup_8091E50(param_1->dungeonSeed.location.id, ptr->itemId)) {
            array[counter++] = id;
        }
    }

    if (counter != 0) {
        id = array[RandInt(counter)];
        ptr = &gUnknown_80E81D4[id];
        param_1->clientSpecies = ptr->species;
        param_1->targetSpecies = ptr->species;
        param_1->targetItem = ptr->itemId;
        param_1->unk2 = 6;
        return TRUE;
    }

    return FALSE;
}
