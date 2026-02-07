#ifndef GUARD_STR_GROUND_BG_H
#define GUARD_STR_GROUND_BG_H

#include "structs/str_file_system.h"
#include "structs/str_202EE8C.h"
#include "structs/str_position.h"

#define UNK_0_ARR_COUNT 14
#define UNK_E0_ARR_COUNT 32
#define UNK_3E0_ARR_COUNT 2
#define NUM_LAYERS 2
#define MAX_BPA_SLOTS 4

typedef struct SubStruct_0
{
    s16 unk0;
    s16 unk2;
    const void *unk4;
    const void *unk8;
    u8 fillC;
} SubStruct_0;

struct BpaHeader
{
    u8 numTiles; // The number of individual tiles.
    s16 numFrames; // The number of frames for each tile.
    s32 durationPerFrame[0]; // Settings for each frame. One entry per frame.
    // Tiles data below
};

typedef struct SubStruct_3E0
{
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    OpenedFile *bpaFile;
    const struct BpaHeader *unkC;
    const void *unk10;
    const void *unk14;
    const void *unk18;
    const void *unk1C;
    void *unk20;
    u32 unk24;
} SubStruct_3E0;

typedef struct MapRender
{
    s16 chunkDimensions;
    s16 unk2;
    s16 numBgs;
    bool8 wrapAround;
    s32 widthChunks;
    s32 heightChunks;
    PixelPos mapSizePixels;
    void (*tilemapRenderFunc)(struct MapRender *);
    u16 *tileMappings;
    u16 *chunkMappings[NUM_LAYERS];
    u16 *bgTilemaps[NUM_LAYERS];
    PixelPos cameraPos;
    PixelPos tilePos;
    PixelPos chunkPos;
    PixelPos bgRegOffsets; // Either bg2 or bg3
} MapRender;

// Size: 0xC
typedef struct BmaHeader
{
    // Map width/height that the camera in game will travel in tiles. Also the width/height of the collision and unknown data layers! For most maps (Map Width Chunks) * (Tiling Width) = (Map Width Camera).
    /* 0x0 */ u8 mapWidthTiles;
    /* 0x1 */ u8 mapHeightTiles;

    // Width/Height of chunks in tiles. Always 3, the value is ignored for these.
    /* 0x2 */ u8 tilingWidth;
    /* 0x3 */ u8 tilingHeight;

    // Map width/height in chunks. Also the width/height of the chunk mappings.
    /* 0x4 */ u8 mapWidthChunks;
    /* 0x5 */ u8 mapHeightChunks;

    /* 0x6 */ u16 numLayers; // Number of layers in this map. Must match BPC layer size. Allowed values are only 1 or 2.
    /* 0x8 */ s16 hasDataLayer; // Seems to be a boolean flag (0 or 1). If >0, the Unknown Data Layer exists.
    /* 0xA */ s16 hasCollision; // Number of Collision layers. 0, 1 or 2.
} BmaHeader;

// size: 0x18?
typedef struct SubStruct_52C
{
    s16 unk0; // 0x52C
    s16 unk2; // 0x52E
    s16 unk4; // 0x530
    s16 unk6; // 0x532
    s16 unk8; // 0x534
    s16 unkA; // 0x536
    s16 numLayers; // 0x538
    s16 unkE; // 0x53A
    s16 unk10; // 0x53C
    s16 unk12; // 0x53E
    u8* (*unk14)(void *, const u8 *, BmaHeader *, s32); // TODO: fix void * to proper ptr types 0x540
} SubStruct_52C;

typedef struct LayerSpecs
{
    // Apparently these two fields are not present in pmd-sky?
    s16 chunkWidth; // Must be 2 or 3
    s16 chunkHeight; // Must be 2 or 3

    s16 numTiles; // The number of tiles stored in the data + 1. The +1 is the null tile at the beginning of tiles.
    s16 bpaSlotNumTiles[MAX_BPA_SLOTS]; // The number of tiles in the BPA on this slot. 0 if no BPA is assigned.
    s16 numChunks; // Number of chunks in the tilemap + 1. The +1 is the null chunk at the beginning of tile mappings, that is not stored.
} LayerSpecs;

typedef struct AnimationSpecification
{
    s16 durationPerFrame; // Time in game frames to hold a single palette frame for
    s16 numFrames; // Number of frames. This is also usually the length of frames in animation palette, but it can also be less.
} AnimationSpecification;

typedef struct BplHeader
{
    s16 numPalettes;
    s16 hasPalAnimations;
    // RGB palettes
    // Animation Specification array
    // Animation RGB palettes
} BplHeader;

// Note: Always 3x3 in Sky
#define CHUNK_DIMENSIONS_INVALID 0
#define CHUNK_DIMENSIONS_2x2 1
#define CHUNK_DIMENSIONS_3x3 2

// size: 0x55C
typedef struct GroundBg
{
    SubStruct_0 unk0[UNK_0_ARR_COUNT];
    AnimatedColor unkE0[UNK_E0_ARR_COUNT];
    SubStruct_3E0 unk3E0[UNK_3E0_ARR_COUNT];
    OpenedFile *bplFile;
    OpenedFile *bpcFile;
    OpenedFile *bmaFile;
    OpenedFile *unk43C;
    OpenedFile *unk440;
    s16 mapFileId;
    BmaHeader bmaHeader;
    LayerSpecs layerSpecs;
    BplHeader bplHeader;
    const u8 *decompressedBMAData;
    const AnimationSpecification *animationSpecifications;
    u8 unk470;
    u8 unk471;
    s32 unk474;
    PixelPos cameraPixelPosition[NUM_LAYERS];
    struct MapRender mapRender[NUM_LAYERS];
    u16 chunkDimensions;
    u8 unk52A;
    SubStruct_52C unk52C;
    u16 *unk544;
    u16 *tileMappings;
    u16 *chunkMappings[NUM_LAYERS];
    u16 *bgTilemaps[NUM_LAYERS];
} GroundBg;

extern GroundBg *gGroundMapDungeon_3001B70;

#endif // GUARD_STR_GROUND_BG_H
