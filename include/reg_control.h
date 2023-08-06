#ifndef GUARD_CODE_800B5F0_H
#define GUARD_CODE_800B5F0_H

#include "main.h"

// size: 0x8
struct unkStruct_202D648
{
    s16 unk0;
    s16 unk2; // Vcount??
    IntrCallback unk4; // some function... just making it IntrCallback for now
};

extern EWRAM_DATA s16 gUnknown_203B0A8;
extern EWRAM_DATA s16 gUnknown_203B0AA;
extern EWRAM_DATA s16 gUnknown_203B0AC;
extern EWRAM_DATA s16 gUnknown_203B0AE;

void nullsub_17(void);
void xxx_update_bg_sound_input(void);

#endif // GUARD_CODE_800B5F0_H