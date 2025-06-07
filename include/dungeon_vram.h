#ifndef GUARD_DUNGEON_VRAM_H
#define GUARD_DUNGEON_VRAM_H

// TODO: copy stuff from dungeon_vram.c to this header

extern u8 gUnknown_203B40D;

#include "structs/str_text.h"

void sub_803E668(u32 unused);
void sub_803E708(s32 numFrames, u32 a1);
void DungeonShowWindows(const WindowTemplates *winTemplates, bool8 a1);
void DungeonRunFrameActions(u32);

#endif // GUARD_DUNGEON_VRAM_H
