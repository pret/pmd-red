#ifndef GUARD_STR_WONDER_MAIL_H
#define GUARD_STR_WONDER_MAIL_H

#include "constants/wonder_mail.h"
#include "structs/str_dungeon.h"
#include "structs/str_pokemon.h"

// size: 0x8
typedef struct WonderMailSub
{
    /* 0x0 */ DungeonLocation dungeon;
    /* 0x4 */ u32 seed;
} WonderMailSub;

// size: 0x14
typedef struct WonderMail
{
    /* 0x0 */ u8 mailType;
    /* 0x1 */ u8 missionType;
    u8 unk2;
    /* 0x4 */ WonderMailSub unk4;
    /* 0xC */ s16 clientSpecies;
    /* 0xE */ s16 targetSpecies;
    /* 0x10 */ u8 targetItem;
    /* 0x11 */ u8 rewardType;
    /* 0x12 */ u8 itemReward;
    /* 0x13 */ u8 friendAreaReward;
} WonderMail;

// size: 0x28
typedef struct unkStruct_802F204
{
    /* 0x0 */ u8 clientName[POKEMON_NAME_LENGTH];
    /* 0xA */ u8 name2[POKEMON_NAME_LENGTH]; // target name?
    /* 0x14 */ s16 clientSpecies;
    u8 unk16;
    /* 0x18 */ s32 moneyReward;
    /* 0x1C */ u8 itemRewards[MAX_ITEM_REWARDS];
    /* 0x1F */ u8 quantity;
    /* 0x20 */ u8 friendAreaReward;
    /* 0x24 */ u32 teamRankPtsReward;
} unkStruct_802F204;

// size: 0xB4
typedef struct unkStruct_803B344
{
    /* 0x0 */ WonderMail mail;
    u8 *unk14;
    u8 *unk18;
    u8 fill1C[0x3C - 0x1C];
    u8 unk3C[0xB4 - 0x3C];
} unkStruct_803B344;

// size: 0x30
typedef struct unkStruct_203B480
{
    /* 0x0 */ u8 mailType;
    /* 0x1 */ u8 missionType;
    WonderMailSub unk4;
    /* 0xC */ s16 clientSpecies;
    /* 0xE */ s16 targetSpecies;
    union unk10_temp
    {
        u32 unk10;
        u16 unk10_u16;
    } unk10;
    /* 0x14 */ u8 playerName[0x20 - 0x14];
    Item item;
    u32 unk24;
    u32 unk28;
    /* 0x2C */ s8 rescuesAllowed;
    u8 unk2D;
} unkStruct_203B480;

// size: 0x88
typedef struct WonderMailStruct_203B2C0_sub
{
    /* 0x0 */ unkStruct_203B480 mail;
    /* 0x30 */ PokemonStruct1 pokemon;
} WonderMailStruct_203B2C0_sub;

#endif // GUARD_STR_WONDER_MAIL_H