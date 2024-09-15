#ifndef GUARD_CODE_80972F4_H
#define GUARD_CODE_80972F4_H

#include "structs/str_wonder_mail.h"

// size: 0x8
typedef struct MissionText
{
    /* 0x0 */ const u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} MissionText;

const u8 *GetCurrentMissionText(s16 index);
// TODO: this should probably be bool8 but can't get a match just yet
bool32 IsMazeCompleted(s16 mazeIndex);

bool8 sub_8096F50(WonderMail *mail);
void sub_8097418(s16 index, bool32);
bool8 sub_8097504(s16 mazeIndex);
const u8 *sub_80975DC(u32);

// These two are definitely bool8 but can't get them to match with it yet
//bool8 sub_8097384(s16);
//bool8 RescueScenarioConquered(s16);

#endif // GUARD_CODE_80972F4_H
