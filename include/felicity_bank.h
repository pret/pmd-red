#ifndef GUARD_FELICITY_BANK_H
#define GUARD_FELICITY_BANK_H

#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_text.h"

#define FELICITY_BANK_ACTION_WITHDRAW 0
#define FELICITY_BANK_ACTION_DEPOSIT 1

// size: 0x108
typedef struct FelicityBankWork
{
    /* 0x0 */ u32 mode; // Corresponds to the enum: FelicityBankMode
    /* 0x4 */ s32 currState;
    /* 0x8 */ u32 fallbackState;
    /* 0xC */ u32 chosenAmount;
    /* 0x10 */ u32 menuAction;
    MenuItem unk14[8];
    u16 unk54[8];
    unkStructFor8013AA0 unk64;
    /* 0x94 */ OpenedFile *faceFile;
    /* 0x98 */ u8 *faceData;
    u16 unk9C;
    u16 unk9E;
    u8 unkA0;
    u8 unkA1;
    u8 unkA2;
    u8 unkA3;
    OpenedFile **unkA4;
    UnkTextStruct2 unkA8[4];
} FelicityBankWork;

bool8 CreateFelicityBank(s32 mode);
void DestroyFelicityBank(void);
void DrawTeamMoneyBox(u32);
u32 FelicityBankCallback(void);

#endif // GUARD_FELICITY_BANK_H