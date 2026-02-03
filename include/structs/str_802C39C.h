#ifndef GUARD_STR_802C39C_H
#define GUARD_STR_802C39C_H

#include "structs/str_mission_rewards.h"
#include "structs/str_wonder_mail.h"

// size: 0x58
typedef struct unkStruct_802C39C
{
    /* 0x0 */ u32 unk0[2];
    /* 0x8 */ DungeonMailSeed *dungeonSeed;
    /* 0xC */ u8 *playerName;
    /* 0x10 */ s16 clientSpecies;
    /* 0x12 */ s16 targetSpecies;
    /* 0x14 */ u8 targetItem;
    /* 0x18 */ MissionRewards rewards;
    /* 0x40 */ u8 mailTitleType;
    /* 0x41 */ u8 mailDescriptionType;
    /* 0x42 */ u8 mailMissionType;
    u8 unk43;
    u8 mailStatus; // mail status (suspend / take job / done)
    /* 0x48 */ u32 y;
    /* 0x4C */ u8 *unk4C;
    u8 *unk50;
    /* 0x54 */ WonderMail *mail;
} unkStruct_802C39C;

#endif // GUARD_STR_802C39C_H
