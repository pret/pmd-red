#ifndef GUARD_SAVE_WRITE_H
#define GUARD_SAVE_WRITE_H

#include "file_system.h"

// size: 0x20
typedef struct SavePakWrite
{
    /* 0x0 */ u32 state;
    s32 unk4;
    /* 0x8 */ u32 saveStatus;
    /* 0xC */ struct UnkPrintFieldMsgStruct faceInfo;
    /* 0x1C */ u16 pokeID;
} SavePakWrite;

void FinishWriteSavePak(void);
u32 GetSavePakStatus(void);
void PrepareSavePakWrite(s16 pokemonID);
bool8 WriteSavePak(void);

#endif // GUARD_SAVE_WRITE_H
