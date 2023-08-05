#ifndef GUARD_FELICITY_BANK_H
#define GUARD_FELICITY_BANK_H

#include "file_system.h"
#include "text.h"
#include "menu.h"

// size: 0x108
struct FelicityBankWork
{
    /* 0x0 */ u32 isAsleep;
    /* 0x4 */ s32 currState;
    /* 0x8 */ u32 fallbackState;
    /* 0xC */ u32 chosenAmount;
    /* 0x10 */ u32 menuAction;
    struct MenuItem unk14[8];
    u16 unk54[8];
    u32 unk64;
    s32 unk68;
    s32 unk6C;
    /* 0x70 */ s32 maximumDepositWithdraw;
    s32 unk74;
    u32 unk78;
    struct UnkTextStruct2 *unk7C;
    s32 unk80;
    s32 unk84;
    u8 fill88[0x94 - 0x88];
    /* 0x94 */ struct OpenedFile *faceFile;
    /* 0x98 */ u8 *faceData;
    u16 unk9C;
    u16 unk9E;
    u8 unkA0;
    u8 unkA1;
    u8 unkA2;
    u8 unkA3;
    struct OpenedFile **unkA4;
    struct UnkTextStruct2 unkA8[4];
};

extern struct FelicityBankWork *gFelicityBankWork;

#define FELICITY_BANK_ACTION_WITHDRAW 0
#define FELICITY_BANK_ACTION_DEPOSIT 1

void DrawTeamMoneyBox(u32 param_1);

#endif
