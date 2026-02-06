#ifndef GUARD_STR_MISSION_REWARDS_H
#define GUARD_STR_MISSION_REWARDS_H

#define MAX_ITEM_REWARDS 3

enum RewardType
{
    MONEY,
    MONEY_EXTRA,
    ITEM,
    ITEM_EXTRA,
    BLANK_4,
    MONEY1,
    MONEY1_EXTRA,
    ITEM1,
    ITEM1_EXTRA,
    FRIEND_AREA,
    END_REWARDS
};

// Size: 0x28
typedef struct MissionRewards
{
    /* 0x0 */ u8 clientName[POKEMON_NAME_LENGTH];
    /* 0xA */ u8 name2[POKEMON_NAME_LENGTH]; // target name?
    /* 0x14 */ s16 clientSpecies;
    /* 0x16 */ u8 rewardType; // See enum "RewardType"
    /* 0x18 */ s32 moneyReward;
    /* 0x1C */ u8 itemRewards[MAX_ITEM_REWARDS];
    /* 0x1F */ u8 quantity;
    /* 0x20 */ u8 friendAreaReward;
    /* 0x24 */ u32 teamRankPtsReward;
} MissionRewards;

#endif // GUARD_STR_MISSION_REWARDS_H
