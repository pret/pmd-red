#ifndef GUARD_CODE_STR_802C39C_H
#define GUARD_CODE_STR_802C39C_H

#include "structs/str_wonder_mail.h"

// size: 0x58
typedef struct unkStruct_802C39C
{
    /* 0x0 */ u32 unk0[2];
    /* 0x8 */ WonderMailSub *unk8;
    /* 0xC */ u8 *playerName;
    /* 0x10 */ s16 clientSpecies;
    /* 0x12 */ s16 targetSpecies;
    /* 0x14 */ u8 targetItem;
    /* 0x15 */ u8 fill15[0x2E - 0x15];
    /* 0x2E */ u8 rewardType;
    u8 *unk30;
    /* 0x34 */ u8 rewardItem;
    u8 fill35[0x38 - 0x35];
    /* 0x38 */ u8 unk38[0x40 - 0x38];
    u8 mailTitleType;
    u8 mailDescriptionType;
    u8 mailMissionType;
    u8 unk43;
    u8 mailStatus; // mail status (suspend / take job / done)
    /* 0x48 */ u32 y;
    /* 0x4C */ u8 *unk4C;
    u8 *unk50;
    /* 0x54 */ WonderMail *mail;
} unkStruct_802C39C;

#endif // GUARD_CODE_STR_802C39C_H