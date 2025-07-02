#ifndef GUARD_AXDATA_H
#define GUARD_AXDATA_H

#include "structs/rgb.h"
#include "structs/str_file_system.h"
#include "structs/str_position.h"

// size: 0x8
typedef struct ax_sprite
{
    /* 0x0 */ const void *gfx;
    /* 0x4 */ s32 byteCount;
} ax_sprite;

// size: 0x20
typedef struct axdata1
{
    /* 0x0 */ DungeonPos pos;
    /* 0x4 */ DungeonPos offset;
    /* 0x8 */ DungeonPos shadow;
    u32 unkC;
    u32 unk10;
    /* 0x14 */ s16 vramTileOrMaybeAnimTimer;
    s16 unk16;
    /* 0x18 */ s16 poseId;
    /* 0x1A */ s16 lastPoseId;
    u8 fill1C[0x1E - 0x1C];
    u8 paletteNum;
} axdata1;

// Size: 0x2
typedef struct ALIGNED_PACKED(2) ax_pose_unk2
{
    u8 unk0;
    s8 unk1;
} ax_pose_unk2;

// size: 0xA
typedef struct ALIGNED_PACKED(2) ax_pose
{
    /* 0x0 */ s16 sprite;
    /* 0x2 */ ax_pose_unk2 unk2; // Always {0, 0} in red (except for end markers {0xFF, 0xFF} and Latios Pose189...)
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
    /* 0x4 */ DungeonPos offset;
    /* 0x8 */ DungeonPos shadow;
} ax_anim;

#define AX_POSITION_SETS_COUNT 4

struct PositionSets
{
    DungeonPos set[AX_POSITION_SETS_COUNT];
};

// size: 0x3C
typedef struct axdata
{
    /* 0x0 */ u16 flags; // 0x8000 - animating, 0x2000 finished? 0x1000 continue
    /* 0x2 */ s16 animFrames; // frames left in the current animation frame
    /* 0x4 */ s16 animWaitFrames; // frames to not update the animation for
    /* 0x6 */ s16 totalFrames; // max 30000
    /* 0x8 */ axdata1 sub1;
    /* 0x28 */ const ax_anim *nextAnimData; // next animation data (if flags&0x1000)
    /* 0x2C */ const ax_anim *activeAnimData; // current animation data
    /* 0x30 */ const struct PositionSets *positions;
    /* 0x34 */ const ax_pose *const *poseData;
    /* 0x38 */ const ax_sprite *const *spriteData;
} axdata;

// size: 0x14
typedef struct axmain
{
    /* 0x0 */ const ax_pose *const *poses;
    /* 0x4 */ const ax_anim *const *const *animations;
    /* 0x8 */ u32 animCount;
    /* 0xC */ const ax_sprite *const *spriteData;
    /* 0x10 */ const struct PositionSets *positions;
} axmain;

// size: 0x4C
typedef struct axObject
{
    /* 0x0 */ axdata axdata;
    /* 0x3C */ OpenedFile *spriteFile; // This might be a unkStruct_202EE8C instead and unkStruct_202EE8C.unk0 might be a OpenedFile* etc. See friend_areas_map_util.AnimateSprites()
    s16 unk40_maybeAnimTimer;
    u8 unk42_animId1;
    u8 unk43_animId2;
    u8 unk44_direction1;
    u8 unk45_orientation;
    u8 unk46;
    u8 unk47;
    /* 0x48 */ union
    {
        struct Item* item;
        struct EntityInfo* monster;
        struct Trap* trap;
    } info;
} axObject;

typedef struct Palette256
{
    RGB pal[256];
} Palette256;

// size: 0x20
typedef struct EfoFileData
{
    /* 0x0 */ ax_pose **poses; // TODO: Verify if these fields' names are actually valid
    /* 0x4 */ ax_anim ***animations;
    /* 0x8 */ s32 animCount;
    /* 0xC */ void *spriteData; // ?
    /* 0x10 */ Palette256 *unk10; // ?
    /* 0x14 */ const u32 *tiles;
    /* 0x18 */ const RGB *pal;
    /* 0x1C */ s32 tileCount;
} EfoFileData;

#endif // GUARD_AXDATA_H
