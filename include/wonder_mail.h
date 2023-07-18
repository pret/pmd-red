#ifndef GUARD_WONDER_MAIL_H
#define GUARD_WONDER_MAIL_H

#include "file_system.h"
#include "text.h"
#include "item.h"
#include "menu.h"
#include "pokemon.h"
#include "code_8094F88.h"

#include "constants/wonder_mail.h"

// size: 0x28
struct unkStruct_802F204
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
};

// size: 0x14
struct WonderMail
{
    /* 0x0 */ u8 mailType; // mail type
    /* 0x1 */ u8 missionType; // mission type
    u8 unk2;
    u8 unk3;
    /* 0x4 */ struct DungeonLocation dungeon;
    u32 unk8;
    /* 0xC */ s16 clientSpecies; // client pokemon
    /* 0xE */ s16 targetSpecies; // target
    /* 0x10 */ u8 targetItem; // item to find/deliver
    /* 0x11 */ u8 rewardType; // reward type
    /* 0x12 */ u8 itemReward; // item reward
    /* 0x13 */ u8 friendAreaReward; // friend area
};


// size: 0x88
struct WonderMailStruct_203B2C0_sub
{
    /* 0x0 */ struct unkStruct_203B480 mail;
    /* 0x30 */ struct PokemonStruct pokemon;
};

// size: 0x548
struct WonderMailStruct_203B2C0
{
    /* 0x0 */ u32 fallbackState;
    /* 0x4 */ u32 state;
    /* 0x8 */ u8 passwordBuffer[PASSWORD_BUFFER_SIZE];
    u8 unk3E;
    u32 unk40;
    /* 0x44 */ u32 linkError;
    struct unkStruct_203B480 unk48;
    struct unkStruct_203B480 unk78;
    struct WonderMailStruct_203B2C0_sub unkA8;
    struct WonderMailStruct_203B2C0_sub unk130;
    u8 fill16A[0x218 - 0x1B8];
    /* 0x218 */ u8 mailIndex;
    struct MenuStruct unk21C[4];
    struct UnkTextStruct2 unk35C[4];
    struct UnkTextStruct2 unk3BC[4];
    /* 0x41C */ u32 unkfill; // ItemSlot?
    /* 0x420 */ struct OpenedFile *faceFile;
    /* 0x424 */ u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    /* 0x430 */ u8 padding3[0x534 - 0x430];
    u32 unk534;
    s32 unk538; // A7 << 3
    u32 unk53C;
    /* 0x540 */ u32 mailCount; // A8 << 4
    /* 0x544 */ s16 speciesNum;
};

// size: 0x564
struct WonderMailStruct_203B2C4
{
    /* 0x0 */ u8 state;
    /* 0x4 */ u32 fallbackState; // wonder mail link status??
    /* 0x8 */ u8 passwordBuffer[PASSWORD_BUFFER_SIZE]; // Probably a buffer for entry
    u8 unk3E;
    u32 unk40;
    /* 0x44 */ u32 linkError; // another link status
    u8 filler48[0x1B8 - 0x48];
    struct unkStruct_203B480 unk1B8;
    struct unkStruct_203B480 unk1E8;
    /* 0x218 */ s8 mailIndex;
    struct MenuStruct unk21C[4];
    struct UnkTextStruct2 unk35C[4];
    struct UnkTextStruct2 unk3BC[4];
    struct Item unk41C;
    /* 0x420 */ struct OpenedFile *faceFile;
    /* 0x424 */ u8 *faceData;
    u16 unk428;
    u16 unk42A;
    u8 unk42C;
    u8 unk42D;
    u8 unk42E;
    u32 unk430;
    /* 0x434 */ u8 formattedString[0x100];
    /* 0x534 */ s32 wonderMailMethod;
    /* 0x538 */ u32 wonderMailMode;
    struct unkStruct_802F204 unk53C;
};

void SetFriendRescueCounterState(u32 r0);

#endif
