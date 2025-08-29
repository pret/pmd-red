#ifndef GUARD_DUNGEON_VRAM_H
#define GUARD_DUNGEON_VRAM_H

#include "structs/str_text.h"
#include "structs/sprite_oam.h"
#include "structs/str_position.h"
#include "structs/dungeon_entity.h"

void sub_803E250(void);
void DungeonRunFrameActions(u32 a0);
void sub_803E668(u32 unused);
void sub_803E708(s32 numFrames, u32 a1);
void sub_803E724(s32 r0);
void sub_803E748(void);
void sub_803E7C8(void);
void sub_803E830(void);
void sub_803E874(bool8 r10, s32 r9);
void BgColorCallNullsub4(void);
void sub_803EA10(void);
void sub_803EAF0(u32 kind, u8 *name);
void DungeonShowWindows(const WindowTemplates *winTemplates, bool8 a1);
void sub_803ED30(s32 a0, Entity *mon, u8 a2, s32 a3);

struct unkStruct_202ED28
{
    SpriteOAM sprite;
    DungeonPos pos;
};

struct UnkStruct_202EDE8
{
    s16 unk0;
    s16 unk2;
    Entity *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern struct unkStruct_202ED28 gUnknown_202ED28[][6];
extern SpriteOAM gUnknown_202EDC0;
extern s32 gDungeonBrightness;
extern s32 gDungeonFramesCounter;
extern s32 gUnknown_202EDD0;
extern struct UnkStruct_202EDE8 gUnknown_202EDE8;

extern u8 gUnknown_203B40C;
extern u8 gUnknown_203B40D;

#endif // GUARD_DUNGEON_VRAM_H
