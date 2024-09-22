#ifndef GUARD_AXDATA_H
#define GUARD_AXDATA_H

#include "file_system.h"
#include "structs/str_position.h"

// size: 0x8
typedef struct UnkSpriteMem
{
    /* 0x0 */ void *src;
    /* 0x4 */ s32 byteCount;
} UnkSpriteMem;

// size: 0x20
typedef struct axdata1
{
    /* 0x0 */ Position pos;
    /* 0x4 */ Position offset;
    /* 0x8 */ Position shadow;
    u32 unkC;
    u32 unk10;
    /* 0x14 */ s16 vramTileOrMaybeAnimTimer;
    s16 unk16;
    /* 0x18 */ s16 poseId;
    /* 0x1A */ s16 lastPoseId;
    u8 fill1C[0x1E - 0x1C];
    u8 paletteNum;
} axdata1;

// size: 0xA
typedef struct __attribute__((packed, aligned(2))) ax_pose
{
    /* 0x0 */ s16 sprite;
    u16 unk2; // Always 0 in red (except for end markers which are 0xFFFF)
    /* 0x4 */ u16 flags1;
    /* 0x6 */ u16 flags2;
    /* 0x8 */ u16 flags3;
} ax_pose;

// size: 0xC
typedef struct ax_anim
{
    /* 0x0 */ u8 frames;
    /* 0x1 */ u8 unkFlags;
    /* 0x2 */ s16 poseId;
    /* 0x4 */ Position offset;
    /* 0x8 */ Position shadow;
} ax_anim;

// size: 0x3C
typedef struct axdata
{
    /* 0x0 */ u16 flags; // 0x8000 - animating, 0x2000 finished? 0x1000 continue
    /* 0x2 */ s16 animFrames; // frames left in the current animation frame
    /* 0x4 */ s16 animWaitFrames; // frames to not update the animation for
    /* 0x6 */ s16 totalFrames; // max 30000
    /* 0x8 */ axdata1 sub1;
    /* 0x28 */ ax_anim *nextAnimData; // next animation data (if flags&0x1000)
    /* 0x2C */ ax_anim *activeAnimData; // current animation data
    /* 0x30 */ void *paletteData; // ?
    /* 0x34 */ ax_pose **poseData;
    /* 0x38 */ UnkSpriteMem **spriteData;
} axdata;

// size: 0x14
typedef struct axmain
{
    /* 0x0 */ ax_pose **poses;
    /* 0x4 */ ax_anim ****animations;
    /* 0x8 */ u32 animCount;
    /* 0xC */ void *spriteData; // ?
    /* 0x10 */ void *palettes; // ?
} axmain;

// size: 0x4C
struct axObject
{
    /* 0x0 */ axdata axdata;
    /* 0x3C */ OpenedFile *spriteFile; // This might be a unkStruct_202EE8C instead and unkStruct_202EE8C.unk0 might be a OpenedFile* etc. See sub_8010F28
    s16 unk40_maybeAnimTimer;
    u8 unk42_animId1;
    u8 unk43_animId2;
    u8 unk44_direction1;
    u8 unk45_orientation;
    u8 unk46;
    u8 unk47;
    /* 0x48 */ struct EntityInfo* info;
};

// size: ?
struct axPokemon
{
    struct axObject obj;
    /* 0x4C */ axmain *axmain;
    u8 flags_0x50;
    u8 fill51;
    s16 unk52;
    u8 fill54[0x66 - 0x54];
    s16 unk66;
    u8 fill68[0x6C - 0x68];
    u16 unk6C;
    u16 unk6E;
    u8 unk70;
    u8 fill71[0x7C - 0x71];
    s32 unk7C;
};

#endif // GUARD_AXDATA_H
