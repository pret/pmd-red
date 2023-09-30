#ifndef GUARD_CODE_802DB28_H
#define GUARD_CODE_802DB28_H

#include "file_system.h"
#include "structs/str_text.h"
#include "structs/str_wonder_mail.h"

// size: 0xA8
struct unkStruct_203B2FC
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 fallbackState;
    unkStruct_802F204 unk8;
    /* 0x30 */ u8 jobSlotIndex;
    /* 0x34 */ WonderMail *jobInfo;
    /* 0x38 */ OpenedFile *faceFile;
    /* 0x3C */ u8 *faceData;
    u16 unk40;
    u16 unk42;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    UnkTextStruct2 unk48[4];
};

bool8 sub_802DB28(u8 jobSlotIndex, u8 dungeon);
u32 sub_802DBD4(void);
void sub_802DC00(void);

#endif // GUARD_CODE_802DB28_H