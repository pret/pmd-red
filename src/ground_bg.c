#include "global.h"
#include "globaldata.h"
#include "ground_bg.h"
#include "ground_map.h"
#include "text_1.h"
#include "memory.h"
#include "file_system.h"
#include "code_8002774.h"
#include "map_files_table.h"
#include "code_8004AA0.h"
#include "graphics_memory.h"
#include "debug.h"
#include "bg_control.h"
#include "unk_dungeon_load.h"
#include "constants/dungeon.h"

// This file most likely deals with map loading and writing to VRAM. It even has a custom decompression function.

extern const FileArchive gGroundFileArchive;

void SetCameraPositionForLayer(GroundBg *groundBg, s32 id, const PixelPos *srcPos);
static void CloseOpenedFiles(GroundBg *groundBg);
static void CallMapTilemapRenderFunc(MapRender *mapRender);
static const u8 *BmaLayerNrlDecompressor(u16 **dstArray, const void *bmaData, SubStruct_52C *a2, BmaHeader *bmaHeader);
static void CopyBpcTilesToVram(void *vramDst, const u16 *src_, SubStruct_52C *a2, LayerSpecs *a3);
static void _UncompressCell(void * a0, u16 *a1, const void * a2, SubStruct_52C *a3, LayerSpecs *a4);
static void InitMapTilemapRenderContext(MapRender *mapRender, GroundBg *groundBg, s32 a2, s32 numBgs, bool8 a4);
static void UpdateMapCameraPosition(MapRender *mapRender, PixelPos *a1);
static void ClearSingleBgTilemap(MapRender *mapRender);
static void RenderChunksToBgTilemap_2x2(MapRender *mapRender);
static void RenderChunksToBgTilemap_3x3(MapRender *mapRender);
static void RenderChunksToBgTilemapWrapAround_3x3(MapRender *mapRender);
static void ClearDoubleBgTilemaps(MapRender *mapRender);
static void RenderChunksToBgTilemaps_2x2(MapRender *mapRender);
static void RenderChunksToBgTilemaps_3x3(MapRender *mapRender);

extern void sub_8003810(u16 param_1, RGB_Union param_2);
extern void sub_809971C(u16 idx, const RGB_Array *strPtrs, s32 n);

static const PixelPos sPositionZero = {0, 0};

void GroundBg_Init(GroundBg *groundBg, const SubStruct_52C *a1)
{
    SubStruct_0 *unk0Ptr;
    s32 id, unk0Id, unk3E0Id;
    s32 i;

    groundBg->unk52C = *a1;
    groundBg->tileMappings = MemoryAlloc(groundBg->unk52C.unk8 * 18, 6);
    for (id = 0; id < groundBg->unk52C.numLayers; id++) {
        groundBg->bgTilemaps[id] = &gBgTilemaps[2 + groundBg->unk52C.unkA + id][0][0];
        groundBg->chunkMappings[id] = MemoryAlloc(groundBg->unk52C.unk10 * 128, 6);
    }
    for (; id < NUM_LAYERS; id++) {
        groundBg->bgTilemaps[id] = NULL;
        groundBg->chunkMappings[id] = NULL;
    }

    if (groundBg->unk52C.unk14 != NULL) {
        groundBg->unk544 = MemoryAlloc(groundBg->unk52C.unkE * 256, 6);
    }
    else {
        groundBg->unk544 = NULL;
    }

    groundBg->bplFile = NULL;
    groundBg->bpcFile = NULL;
    groundBg->bmaFile = NULL;
    groundBg->unk43C = NULL;
    groundBg->unk440 = NULL;
    groundBg->unk52A = 0;
    groundBg->mapFileId = -1;
    groundBg->unk468 = 0;
    groundBg->bmaHeader.mapWidthTiles = 0;
    groundBg->bmaHeader.mapHeightTiles = 0;
    groundBg->bmaHeader.tilingWidth = 0;
    groundBg->bmaHeader.tilingHeight = 0;
    groundBg->bmaHeader.mapWidthChunks = 0;
    groundBg->bmaHeader.mapHeightChunks = 0;
    unk0Ptr = &groundBg->unk0[0];
    groundBg->animationSpecifications = 0;
    groundBg->unk470 = 0;
    groundBg->unk471 = 0;

    for (unk0Id = 0; unk0Id < UNK_0_ARR_COUNT; unk0Id++, unk0Ptr++) {
        unk0Ptr->unk0 = 0;
        unk0Ptr->unk2 = 0;
        unk0Ptr->unk8 = 0;
        unk0Ptr->unk4 = 0;
    }

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *unkPtr = &groundBg->unk3E0[unk3E0Id];
        unkPtr->unk0 = 0;
        unkPtr->unk1 = 0;
        unkPtr->unk2 = 0;
        unkPtr->unk4 = 0;
        unkPtr->bpaFile = NULL;
        unkPtr->unkC = 0;
        unkPtr->unk14 = 0;
        unkPtr->unk10 = 0;
        unkPtr->unk1C = 0;
        unkPtr->unk18 = 0;
        unkPtr->unk20 = 0;
        unkPtr->unk24 = 0;
    }

    for (i = 0; i < 2; i++) {
        SetCameraPositionForLayer(groundBg, i, &sPositionZero);
    }
}

void GroundBg_FreeAll(GroundBg *groundBg)
{
    s32 i;

    CloseOpenedFiles(groundBg);
    TRY_FREE_AND_SET_NULL(groundBg->unk544);
    FREE_AND_SET_NULL(groundBg->tileMappings);

    for (i = 0; i < NUM_LAYERS; i++) {
        if (groundBg->bgTilemaps[i] != NULL) {
            groundBg->bgTilemaps[i] = NULL;
        }
        TRY_FREE_AND_SET_NULL(groundBg->chunkMappings[i]);
    }
}

void sub_80A2D68(GroundBg *groundBg)
{
    TRY_FREE_AND_SET_NULL(groundBg->unk544);
}

void sub_80A2D88(GroundBg *groundBg)
{
    if (groundBg->unk52C.unk14 != NULL) {
        BmaHeader *bmaHeader = &groundBg->bmaHeader;
        groundBg->unk544 = MemoryAlloc(groundBg->unk52C.unkE * 256, 6);
        groundBg->unk52C.unk14(groundBg->unk544, groundBg->unk468, bmaHeader, groundBg->unk52C.unkE);
    }
}

static void CloseOpenedFiles(GroundBg *groundBg)
{
    s32 i;

    for (i = 0; i < UNK_3E0_ARR_COUNT; i++) {
        SubStruct_3E0 *unkPtr = &groundBg->unk3E0[i];
        TRY_CLOSE_FILE_AND_SET_NULL(unkPtr->bpaFile);
    }
    TRY_CLOSE_FILE_AND_SET_NULL(groundBg->unk43C);
    TRY_CLOSE_FILE_AND_SET_NULL(groundBg->unk440);
    TRY_CLOSE_FILE_AND_SET_NULL(groundBg->bplFile);
    TRY_CLOSE_FILE_AND_SET_NULL(groundBg->bpcFile);
    TRY_CLOSE_FILE_AND_SET_NULL(groundBg->bmaFile);
}

void sub_80A2E64(GroundBg *groundBg)
{
    u16 r6;
    s32 i, j;
    SubStruct_0 *unk0Ptr;
    s32 unk0Id, unk3E0Id;

    CloseOpenedFiles(groundBg);
    groundBg->mapFileId = -1;
    groundBg->chunkDimensions = 0;
    groundBg->bmaHeader.mapWidthTiles = 0;
    groundBg->bmaHeader.mapHeightTiles = 0;
    groundBg->bmaHeader.tilingWidth = 0;
    groundBg->bmaHeader.tilingHeight = 0;
    groundBg->bmaHeader.mapWidthChunks = 0;
    groundBg->bmaHeader.mapHeightChunks = 0;
    unk0Ptr = &groundBg->unk0[0];
    groundBg->animationSpecifications = NULL;
    groundBg->unk470 = 0;
    groundBg->unk471 = 0;

    for (unk0Id = 0; unk0Id < UNK_0_ARR_COUNT; unk0Id++, unk0Ptr++) {
        unk0Ptr->unk0 = 0;
        unk0Ptr->unk2 = 0;
        unk0Ptr->unk8 = 0;
        unk0Ptr->unk4 = 0;
    }

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *unkPtr = &groundBg->unk3E0[unk3E0Id];
        unkPtr->unk0 = 0;
        unkPtr->unk1 = 0;
        unkPtr->unk2 = 0;
        unkPtr->unk4 = 0;
        unkPtr->bpaFile = NULL;
        unkPtr->unkC = 0;
        unkPtr->unk14 = 0;
        unkPtr->unk10 = 0;
        unkPtr->unk1C = 0;
        unkPtr->unk18 = 0;
        unkPtr->unk20 = 0;
        unkPtr->unk24 = 0;
    }

    r6 = groundBg->unk52C.unk0 * 16;
    for (i = 0; i < groundBg->unk52C.unk2; i++) {
        RGB_Union str1 = {0};
        RGB_Union str2 = {0xFF, 0xFF, 0xFF, 0};

        sub_8003810(r6++, str1);
        for (j = 0; j < 15; j++) {
            sub_8003810(r6++, str2);
        }
    }

    sub_80A3BB0(groundBg, 0);
    CallMapTilemapRenderFunc(groundBg->mapRender);
    groundBg->unk52A = 1;
}

void sub_80A2FBC(GroundBg *groundBg, s32 mapFileId_)
{
    SubStruct_0 *sub0Ptr;
    u16 r5;
    s32 i, j, k;
    const struct MapFilesStruct *mapFilesPtr;
    BplHeader *bplHeader;
    LayerSpecs *layerSpecs;
    const u16 *bpcData;
    const void *bmaData;
    const void *bplData;
    BmaHeader *bmaHeader;
    RGB_Union str2;
    RGB_Union str1;
    const RGB_Array *rgbPal;
    s32 unk0Id;
    s32 id;
    void *vramPtr;
    s32 sum;
    s32 mapFileId = (s16) mapFileId_;

    if (mapFileId == -1) {
        sub_80A2E64(groundBg);
        return;
    }

    CloseOpenedFiles(groundBg);
    groundBg->mapFileId = mapFileId;
    mapFilesPtr = &gMapFilesTable[mapFileId];
    groundBg->bplFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bplFileName, &gGroundFileArchive);
    groundBg->bpcFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bpcFileName, &gGroundFileArchive);
    groundBg->bmaFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bmaFileName, &gGroundFileArchive);
    bplData = groundBg->bplFile->data;
    bpcData = groundBg->bpcFile->data;
    bmaData = groundBg->bmaFile->data;
    bplHeader = &groundBg->bplHeader;
    layerSpecs = &groundBg->layerSpecs;
    bmaHeader = &groundBg->bmaHeader;

    bplHeader->numPalettes = *(u8 *)(bplData); bplData += 2;
    bplHeader->hasPalAnimations = *(u8 *)(bplData); bplData += 2;

    layerSpecs->chunkWidth = *bpcData++;
    layerSpecs->chunkHeight = *bpcData++;
    layerSpecs->numTiles = *bpcData++;

    sum = layerSpecs->numTiles;
    for (k = 0; k < MAX_BPA_SLOTS; k++) {
        layerSpecs->bpaSlotNumTiles[k] = *bpcData++;
        sum += layerSpecs->bpaSlotNumTiles[k];
    }
    layerSpecs->numChunks = *bpcData++;

    bmaHeader->mapWidthTiles = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->mapHeightTiles = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->tilingWidth = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->tilingHeight = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->mapWidthChunks = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->mapHeightChunks = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->numLayers = *(u8 *)(bmaData); bmaData += 2;
    bmaHeader->hasDataLayer = *(u8 *)(bmaData); bmaData += 2;
    bmaHeader->hasCollision = *(u8 *)(bmaData); bmaData += 2;

    rgbPal = bplData;
    r5 = groundBg->unk52C.unk0 * 16;
    str2 = (RGB_Union) {0};
    str1.asArr.c[0] = 0xff;
    str1.asArr.c[1] = 0xff;
    str1.asArr.c[2] = 0xff;
    str1.asArr.c[3] = 0;
    for (i = 0; i < bplHeader->numPalettes && i < groundBg->unk52C.unk2; i++) {
        sub_8003810(r5++, str2);
        sub_809971C(r5, rgbPal, 15);
        r5 += 15;
        rgbPal += 15;
    }
    for (; i < groundBg->unk52C.unk2; i++) {
        sub_8003810(r5++, str2);
        for (j = 0; j < 15; j++) {
            sub_8003810(r5++, str1);
        }
    }

    CopyBpcTilesToVram((void *)(VRAM + 0x8000 + groundBg->unk52C.unk4 * 32), bpcData, &groundBg->unk52C, &groundBg->layerSpecs);
    _UncompressCell(groundBg->tileMappings, &groundBg->chunkDimensions, bpcData + ((layerSpecs->numTiles - 1) * 16), &groundBg->unk52C, &groundBg->layerSpecs);
    bmaData = BmaLayerNrlDecompressor(groundBg->chunkMappings, bmaData, &groundBg->unk52C, &groundBg->bmaHeader);
    groundBg->unk468 = bmaData;
    if (groundBg->unk544 != NULL) {
        groundBg->unk52C.unk14(groundBg->unk544, bmaData, bmaHeader, groundBg->unk52C.unkE);
    }

    sub0Ptr = groundBg->unk0;
    unk0Id = 0;
    if (bplHeader->hasPalAnimations) {
        const AnimationSpecification *animSpecifications = bplData + (bplHeader->numPalettes * 60);
        const RGB_Array *animationPalette = ((void *) animSpecifications) + bplHeader->numPalettes * 4;

        groundBg->animationSpecifications = animSpecifications;
        groundBg->unk470 = 1;
        groundBg->unk471 = 1;
        for (; unk0Id < bplHeader->numPalettes && unk0Id < groundBg->unk52C.unk2; unk0Id++, sub0Ptr++, animSpecifications++) {
            if (animSpecifications->numFrames > 0) {
                sub0Ptr->unk4 = animationPalette;
                animationPalette += animSpecifications->numFrames * 15;
            }
            else {
                sub0Ptr->unk4 = NULL;
            }
            sub0Ptr->unk0 = 0;
            sub0Ptr->unk2 = 0;
            sub0Ptr->unk8 = 0;
        }
    }
    else {
        groundBg->animationSpecifications = NULL;
        groundBg->unk470 = 0;
        groundBg->unk471 = 0;
    }

    for (; unk0Id < UNK_0_ARR_COUNT; unk0Id++, sub0Ptr++) {
        sub0Ptr->unk0 = 0;
        sub0Ptr->unk2 = 0;
        sub0Ptr->unk4 = sub0Ptr->unk8 = 0;
    }

    vramPtr = (void *)(VRAM + 0x8000 + (groundBg->unk52C.unk4 + layerSpecs->numTiles) * 32);
    for (id = 0; id < 2; id++) {
        SubStruct_3E0 *sub3E0 = &groundBg->unk3E0[id];
        if (mapFilesPtr->bpaFileNames[id] != NULL) {
            const struct BpaHeader *bpaHeader;
            const void *r1, *r0;

            sub3E0->bpaFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bpaFileNames[id], &gGroundFileArchive);
            sub3E0->unk0 = 1;
            sub3E0->unk1 = 1;
            bpaHeader = sub3E0->bpaFile->data;
            sub3E0->unkC = bpaHeader;
            r1 = &bpaHeader->durationPerFrame;
            r0 = r1 + bpaHeader->numFrames * 4;
            sub3E0->unk10 = sub3E0->unk14 = r1;
            sub3E0->unk18 = sub3E0->unk1C = r0;
            sub3E0->unk2 = 0;
            sub3E0->unk4 = bpaHeader->durationPerFrame[0];
            sub3E0->unk20 = vramPtr;
            sub3E0->unk24 = layerSpecs->bpaSlotNumTiles[id] * 32;

            vramPtr += layerSpecs->bpaSlotNumTiles[id] * 32;
        }
        else {
            sub3E0->unk0 = 0;
            sub3E0->unk1 = 0;
            sub3E0->unk4 = 0;
            sub3E0->unk2 = 0;
            sub3E0->bpaFile = NULL;
            sub3E0->unkC = 0;
            sub3E0->unk14 = 0;
            sub3E0->unk10 = 0;
            sub3E0->unk1C = 0;
            sub3E0->unk18 = 0;
            sub3E0->unk20 = 0;
            sub3E0->unk24 = 0;
        }
    }
    for (; id < MAX_BPA_SLOTS; id++) {
        if (mapFilesPtr->bpaFileNames[id] != NULL) {
            s32 n;
            OpenedFile *file = OpenFileAndGetFileDataPtr(mapFilesPtr->bpaFileNames[id], &gGroundFileArchive);
            const struct BpaHeader *bpaHeader = file->data;
            const u16 *tiles = (void *) &bpaHeader->durationPerFrame;
            tiles += bpaHeader->numFrames * 2;

            n = layerSpecs->bpaSlotNumTiles[id] * 16;
            for (k = 0; k < n; k++) {
                *(u16 *)(vramPtr) = *tiles++;
                vramPtr += 2;
            }
            CloseFile(file);
        }
    }

    sub_80A3BB0(groundBg, 0);
    CallMapTilemapRenderFunc(groundBg->mapRender);
    groundBg->unk52A = 1;
}

void sub_80A3440(GroundBg *groundBg, s32 mapFileId_, const DungeonLocation *dungLoc, s32 a3)
{
    SubStruct_0 *sub0Ptr;
    s32 i;
    LayerSpecs *layerSpecs;
    const u16 *bpcData;
    const void *bmaData;
    const void *bplData;
    BmaHeader *bmaHeader;
    s32 unk0Id, sub3E0Id;
    const struct MapFilesStruct *mapFilesPtr;
    BplHeader *bplHeader;
    u16 *unkPtrArray[2];
    s32 mapFileId = (s16) mapFileId_;

    if (mapFileId == -1 || dungLoc->id == DUNGEON_INVALID) {
        sub_80A2E64(groundBg);
        return;
    }

    sub_80A2FBC(groundBg, mapFileId);
    CloseOpenedFiles(groundBg);
    groundBg->mapFileId = mapFileId;
    mapFilesPtr = &gMapFilesTable[mapFileId];
    groundBg->bplFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bplFileName, &gGroundFileArchive);
    groundBg->bpcFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bpcFileName, &gGroundFileArchive);
    groundBg->bmaFile = OpenFileAndGetFileDataPtr(mapFilesPtr->bmaFileName, &gGroundFileArchive);
    bplData = groundBg->bplFile->data;
    bpcData = groundBg->bpcFile->data;
    bmaData = groundBg->bmaFile->data;
    bplHeader = &groundBg->bplHeader;
    layerSpecs = &groundBg->layerSpecs;
    bmaHeader = &groundBg->bmaHeader;

    bplHeader->numPalettes = *(u8 *)(bplData); bplData += 2;
    bplHeader->hasPalAnimations = *(u8 *)(bplData); bplData += 2;

    layerSpecs->chunkWidth = *bpcData++;
    layerSpecs->chunkHeight = *bpcData++;
    layerSpecs->numTiles = *bpcData++;

    for (i = 0; i < MAX_BPA_SLOTS; i++) {
        layerSpecs->bpaSlotNumTiles[i] = *bpcData++;
    }
    layerSpecs->numChunks = *bpcData++;

    bmaHeader->mapWidthTiles = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->mapHeightTiles = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->tilingWidth = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->tilingHeight = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->mapWidthChunks = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->mapHeightChunks = *(u8 *)(bmaData); bmaData += 1;
    bmaHeader->numLayers = *(u8 *)(bmaData); bmaData += 2;
    bmaHeader->hasDataLayer = *(u8 *)(bmaData); bmaData += 2;
    bmaHeader->hasCollision = *(u8 *)(bmaData); bmaData += 2;

    unkPtrArray[0] = groundBg->unk544;
    unkPtrArray[1] = NULL;
    bmaData = BmaLayerNrlDecompressor(unkPtrArray, bmaData, &groundBg->unk52C, &groundBg->bmaHeader);
    groundBg->unk468 = bmaData;
    sub_80ADD9C(&groundBg->unk43C, &groundBg->unk440, (void *)(VRAM + 0x8000), groundBg->tileMappings, groundBg->chunkMappings[0], dungLoc, a3, 0x40, bmaHeader->mapHeightChunks, groundBg->unk544, 0);
    // Unused return values
    GetFileDataPtr(groundBg->unk43C, 0);
    GetFileDataPtr(groundBg->unk440, 0);

    groundBg->unk52C.unk14(groundBg->unk544, bmaData, bmaHeader, groundBg->unk52C.unkE);
    layerSpecs->numTiles = 512;
    for (i = 0; i < MAX_BPA_SLOTS; i++) {
        layerSpecs->bpaSlotNumTiles[i] = 0;
    }

    layerSpecs->numChunks = 250;
    groundBg->bplHeader.numPalettes = 12;
    groundBg->bplHeader.hasPalAnimations = FALSE;
    if (groundBg->unk43C != NULL) {
        s32 i, j;
        const RGB_Union *strPtr = groundBg->unk43C->data;
        u16 r7 = 0;
        RGB_Union str0 = {0};
        RGB_Union str1;

        str1.asArr.c[0] = 0xff;
        str1.asArr.c[1] = 0xff;
        str1.asArr.c[2] = 0xff;
        str1.asArr.c[3] = 0;

        for (i = 0; i < 12 && i < groundBg->unk52C.unk2; i++) {
            sub_8003810(r7++, str0);
            strPtr++;
            for (j = 0; j < 15; j++) {
                RGB_Union str2 = {strPtr->asArr.c[0], strPtr->asArr.c[1], strPtr->asArr.c[2], strPtr->asArr.c[3]};
                sub_8003810(r7++, str2);
                strPtr++;
            }
        }
        for (; i < groundBg->unk52C.unk2; i++) {
            sub_8003810(r7++, str0);
            for (j = 0; j < 15; j++) {
                sub_8003810(r7++, str1);
            }
        }
    }

    sub0Ptr = groundBg->unk0;
    if (groundBg->unk440 != NULL) {
        sub_8004AA4(groundBg->unkE0, groundBg->unk440, UNK_E0_ARR_COUNT);
    }
    groundBg->animationSpecifications = NULL;
    groundBg->unk470 = 0;
    groundBg->unk471 = 0;

    for (unk0Id = 0; unk0Id < UNK_0_ARR_COUNT; unk0Id++, sub0Ptr++) {
        sub0Ptr->unk0 = 0;
        sub0Ptr->unk2 = 0;
        sub0Ptr->unk4 = sub0Ptr->unk8 = 0;
    }

    for (sub3E0Id = 0; sub3E0Id < UNK_3E0_ARR_COUNT; sub3E0Id++) {
        SubStruct_3E0 *sub3E0 = &groundBg->unk3E0[sub3E0Id];
        sub3E0->unk0 = 0;
        sub3E0->unk1 = 0;
        sub3E0->unk4 = 0;
        sub3E0->unk2 = 0;
        sub3E0->bpaFile = NULL;
        sub3E0->unkC = 0;
        sub3E0->unk14 = 0;
        sub3E0->unk10 = 0;
        sub3E0->unk1C = 0;
        sub3E0->unk18 = 0;
        sub3E0->unk20 = 0;
        sub3E0->unk24 = 0;
    }
    sub_80A3BB0(groundBg, 0);
    CallMapTilemapRenderFunc(groundBg->mapRender);
    groundBg->unk52A = 1;
    // bad sp alloc for compiler generated variables...
    ASM_MATCH_TRICK(layerSpecs->bpaSlotNumTiles[0]);
}

// Note: these not compressed like in pmd-sky.
static void CopyBpcTilesToVram(void *vramDst, const u16 *src_, SubStruct_52C *a2, LayerSpecs *layerSpecs)
{
    const u16 *src = src_;
    u16 *dst = vramDst;
    s32 id, i;

    for (i = 0; i < 16; i++) {
        *dst++ = 0;
    }
    for (id = 1; id < layerSpecs->numTiles; id++) {
        for (i = 0; i < 16; i++) {
            *dst++ = *src++;
        }
    }
    for (; id < a2->unk6; id++) {
        for (i = 0; i < 16; i++) {
            *dst++ = 0xFFFF;
        }
    }
}

static void _UncompressCell(void *dst_, u16 *chunkDimensions, const void *src_, SubStruct_52C *a3, LayerSpecs *layerSpecs)
{
    s32 id, i;
    s32 n;

    const u16 *src = src_;
    u16 *dst = dst_;
    u16 r6 = (a3->unk0 << 12) | a3->unk4;

    if (layerSpecs->chunkWidth == 2 && layerSpecs->chunkHeight == 2) {
        *chunkDimensions = CHUNK_DIMENSIONS_2x2;
        n = 2 * 2;
    }
    else if (layerSpecs->chunkWidth == 3 && layerSpecs->chunkHeight == 3) {
        *chunkDimensions = CHUNK_DIMENSIONS_3x3;
        n = 3 * 3;
    }
    else {
        *chunkDimensions = CHUNK_DIMENSIONS_INVALID;
        FatalError(DEBUG_LOC_PTR("../ground/ground_bg.c", 1184, "_UncompressCell"), _("GroundBg cell type　error %d %d"), layerSpecs->chunkWidth, layerSpecs->chunkHeight);
    }

    for (i = 0; i < 9; i++) {
        *dst++ = 0;
    }
    for (id = 1; id < layerSpecs->numChunks; id++) {
        for (i = 0; i < n; i++) {
            *dst++ = *src++ + r6;
        }
        for (; i < 9; i++) {
            *dst++ = 0;
        }
    }
    for (; id < a3->unk8; id++) {
        for (i = 0; i < 9; i++) {
            *dst++ = 0;
        }
    }
}

static const u8 *BmaLayerNrlDecompressor(u16 **dstArray, const void *bmaData, SubStruct_52C *a2, BmaHeader *bmaHeader)
{
    s32 i, k, j, l;
    const u8 *src = bmaData;

    for (i = 0; i < a2->numLayers; i++) {
        // Interestingly enough it's swapped in Sky dstArray[a2->numLayers - i - 1]
        u16 *dst = dstArray[i];
        for (j = 0; j < bmaHeader->mapHeightChunks; j++) {
            k = 0;
            if (j == 0) {
                while (k < bmaHeader->mapWidthChunks) {
                    s32 cmd = *src++;
                    if (cmd >= 0xc0) {
                        for (l = 0xC0; l <= cmd; l++) {
                            s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                            *dst++ = dstVal & 0xFFF;
                            *dst++ = (dstVal >> 12) & 0xFFF;
                        }
                        k += (cmd - 0xBF) * 2;
                    }
                    else if (cmd >= 0x80) {
                        s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                        for (l = 0x80; l <= cmd; l++) {
                            *dst++ = dstVal & 0xFFF;
                            *dst++ = (dstVal >> 12) & 0xFFF;
                        }
                        k += (cmd - 0x7F) * 2;
                    }
                    else {
                        for (l = 0; l <= cmd; l++) {
                            *dst++ = 0;
                            *dst++ = 0;
                        }
                        k += (cmd + 1) * 2;
                    }
                }
            }
            else {
                u16 *ptrVal = dst - 64;
                while (k < bmaHeader->mapWidthChunks) {
                    s32 cmd = *src++;
                    if (cmd >= 0xC0) {
                        for (l = 0xC0; l <= cmd; l++) {
                            s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                            *dst++ = *ptrVal++ ^ (dstVal & 0xFFF);
                            *dst++ = *ptrVal++ ^ ((dstVal >> 12) & 0xFFF);
                        }
                        k += (cmd - 0xBF) * 2;
                    }
                    else if (cmd >= 0x80) {
                        s32 dstVal = src[0] | (src[1] << 8) | (src[2] << 16); src += 3;
                        for (l = 0x80; l <= cmd; l++) {
                            *dst++ = *ptrVal++ ^ (dstVal & 0xFFF);
                            *dst++ = *ptrVal++ ^ ((dstVal >> 12) & 0xFFF);
                        }
                        k += (cmd - 0x7F) * 2;
                    }
                    else {
                        for (l = 0; l <= cmd; l++) {
                            *dst++ = *ptrVal++;
                            *dst++ = *ptrVal++;
                        }
                        k += (cmd + 1) * 2;
                    }
                }
            }

            for (; k < 64; k++) {
                *dst++ = 0;
            }
        }
        for (; j < a2->unk10; j++) {
            for (k = 0; k < 64; k++) {
                *dst++ = 0;
            }
        }
    }

    return src;
}

void sub_80A3B80(GroundBg *groundBg, u8 a1, u8 a2)
{
    if (groundBg->animationSpecifications != NULL) {
        groundBg->unk470 = a1;
        groundBg->unk471 = a2;
    }
}

static const PixelPos sUnknownPosition = {96, 24};

void sub_80A3BB0(GroundBg *groundBg, s32 a0_)
{
    s32 i;
    // s16 memes strike yet again
    s32 a0Match = (s16) a0_;
    s32 a0 = a0Match;

    MapRender *mapRender = groundBg->mapRender;

    switch (a0) {
        default:
        case 0:
        case 1:
            groundBg->unk474 = 1;
            InitMapTilemapRenderContext(&mapRender[0], groundBg, 0, groundBg->unk52C.numLayers, (a0 == 1));
            break;
        case 2:
        case 3:
        case 4:
            groundBg->unk474 = 2;
            InitMapTilemapRenderContext(&mapRender[0], groundBg, 0, groundBg->unk52C.numLayers - 1, (a0 == 4));
            InitMapTilemapRenderContext(&mapRender[1], groundBg, groundBg->unk52C.numLayers - 1, 1, (a0 != 2));
            break;
    }

    for (i = 0; i < groundBg->unk474; i++) {
        SetCameraPositionForLayer(groundBg, i, &sUnknownPosition);
        switch (mapRender[i].numBgs) {
            default:
            case 1:
                switch (mapRender[i].chunkDimensions) {
                    default:
                    case CHUNK_DIMENSIONS_INVALID:
                        mapRender[i].tilemapRenderFunc = ClearSingleBgTilemap;
                        break;
                    case CHUNK_DIMENSIONS_2x2:
                        mapRender[i].tilemapRenderFunc = RenderChunksToBgTilemap_2x2;
                        break;
                    case CHUNK_DIMENSIONS_3x3:
                        mapRender[i].tilemapRenderFunc = (mapRender[i].wrapAround != FALSE) ? RenderChunksToBgTilemapWrapAround_3x3 : RenderChunksToBgTilemap_3x3;
                        break;
                }
                break;
            case 2:
                switch (mapRender[i].chunkDimensions) {
                    default:
                    case CHUNK_DIMENSIONS_INVALID:
                        mapRender[i].tilemapRenderFunc = ClearDoubleBgTilemaps;
                        break;
                    case CHUNK_DIMENSIONS_2x2:
                        mapRender[i].tilemapRenderFunc = RenderChunksToBgTilemaps_2x2;
                        break;
                    case CHUNK_DIMENSIONS_3x3:
                        mapRender[i].tilemapRenderFunc = RenderChunksToBgTilemaps_3x3;
                        break;
                }
                break;
        }
        UpdateMapCameraPosition(&mapRender[i], &groundBg->cameraPixelPosition[i]);
    }

    for (i = groundBg->unk474; i < NUM_LAYERS; i++) {
        SetCameraPositionForLayer(groundBg, i, &sUnknownPosition);
        InitMapTilemapRenderContext(&mapRender[i], groundBg, 0, 0, FALSE);
    }
}

static void InitMapTilemapRenderContext(MapRender *mapRender, GroundBg *groundBg, s32 a2, s32 numBgs, bool8 wrapAround)
{
    s32 i, j;

    mapRender->chunkDimensions = groundBg->chunkDimensions;
    mapRender->unk2 = a2;
    mapRender->numBgs = numBgs;
    mapRender->wrapAround = wrapAround;
    mapRender->widthChunks = groundBg->bmaHeader.mapWidthChunks;
    mapRender->heightChunks = groundBg->bmaHeader.mapHeightChunks;
    mapRender->mapSizePixels.x = groundBg->bmaHeader.mapWidthTiles * 8;
    mapRender->mapSizePixels.y = groundBg->bmaHeader.mapHeightTiles * 8;
    mapRender->tileMappings = groundBg->tileMappings;

    for (i = 0, j = a2; i < numBgs && j < groundBg->unk52C.numLayers; i++, j++) {
        mapRender->chunkMappings[i] = groundBg->chunkMappings[j];
        mapRender->bgTilemaps[i] = groundBg->bgTilemaps[j];
    }
    for (; i < NUM_LAYERS; i++) {
        mapRender->chunkMappings[i] = NULL;
        mapRender->bgTilemaps[i] = NULL;
    }

    UpdateMapCameraPosition(mapRender, &groundBg->cameraPixelPosition[0]);
}

static void UpdateMapCameraPosition(MapRender *mapRender, PixelPos *cameraPos)
{
    mapRender->cameraPos.x = cameraPos->x;
    mapRender->tilePos.x = mapRender->cameraPos.x / 8;
    mapRender->cameraPos.y = cameraPos->y;
    mapRender->tilePos.y = mapRender->cameraPos.y / 8;

    switch (mapRender->chunkDimensions) {
        case CHUNK_DIMENSIONS_INVALID:
            mapRender->chunkPos.x = 0;
            mapRender->chunkPos.y = 0;
            mapRender->bgRegOffsets.x = 0;
            mapRender->bgRegOffsets.y = 0;
            break;
        case CHUNK_DIMENSIONS_2x2:
            mapRender->chunkPos.x = mapRender->tilePos.x / 2;
            mapRender->chunkPos.y = mapRender->tilePos.y / 2;
            mapRender->bgRegOffsets.x = mapRender->cameraPos.x % 16;
            mapRender->bgRegOffsets.y = mapRender->cameraPos.y % 16;
            break;
        case CHUNK_DIMENSIONS_3x3:
            mapRender->chunkPos.x = mapRender->tilePos.x / 3;
            mapRender->chunkPos.y = mapRender->tilePos.y / 3;
            mapRender->bgRegOffsets.x = mapRender->cameraPos.x % 8;
            mapRender->bgRegOffsets.y = mapRender->cameraPos.y % 24;
            break;
    }
}

static void CallMapTilemapRenderFunc(MapRender *mapRender)
{
    mapRender->tilemapRenderFunc(mapRender);
}

static void ClearSingleBgTilemap(MapRender *mapRender)
{
    s32 i;
    u16 *dst = mapRender->bgTilemaps[0];

    for (i = 0; i < 1024; i++) {
        *dst++ = 0;
    }
}

static void ClearDoubleBgTilemaps(MapRender *mapRender)
{
    s32 i;
    u16 *dst1 = mapRender->bgTilemaps[0];
    u16 *dst2 = mapRender->bgTilemaps[1];

    for (i = 0; i < 1024; i++) {
        *dst1++ = 0;
        *dst2++ = 0;
    }
}

static void RenderChunksToBgTilemap_2x2(MapRender *mapRender)
{
    s32 arrPtrId;
    s32 i, j;
    u16 *tilemapPtrs[2];
    u16 *ptr = &mapRender->chunkMappings[0][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    s32 unk28Id = 0;

    for (i = 0; i < 11; ptr += 64, i++) {
        u16 *currPtr = ptr;

        for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
            tilemapPtrs[arrPtrId] = &mapRender->bgTilemaps[0][unk28Id];
            unk28Id += 32;
        }

        for (j = 0; j < 16; j++) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];
            for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
                u16 *currDst = tilemapPtrs[arrPtrId];
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                tilemapPtrs[arrPtrId] = currDst;
            }
        }
    }
}

static void RenderChunksToBgTilemaps_2x2(MapRender *mapRender)
{
    s32 arrPtrId;
    u16 *ptr1, *ptr2;
    u16 *tilemapPtrs1[2];
    u16 *tilemapPtrs2[2];
    s32 unk28Id;
    s32 i, j;

    ptr1 = &mapRender->chunkMappings[0][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    ptr2 = &mapRender->chunkMappings[1][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    unk28Id = 0;
    for (i = 0; i < 11; ptr1 += 64, ptr2 += 64, i++) {
        u16 *currPtr1 = ptr1;
        u16 *currPtr2 = ptr2;

        for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
            tilemapPtrs1[arrPtrId] = &mapRender->bgTilemaps[0][unk28Id];
            tilemapPtrs2[arrPtrId] = &mapRender->bgTilemaps[1][unk28Id];
            unk28Id += 32;
        }

        for (j = 0; j < 16; j++) {
            u16 *currSrc1 = &mapRender->tileMappings[*currPtr1++ * 9];
            u16 *currSrc2 = &mapRender->tileMappings[*currPtr2++ * 9];
            for (arrPtrId = 0; arrPtrId < 2; arrPtrId++) {
                u16 *currDst1 = tilemapPtrs1[arrPtrId];
                u16 *currDst2 = tilemapPtrs2[arrPtrId];
                *currDst1++ = *currSrc1++;
                *currDst1++ = *currSrc1++;
                *currDst2++ = *currSrc2++;
                *currDst2++ = *currSrc2++;
                tilemapPtrs1[arrPtrId] = currDst1;
                tilemapPtrs2[arrPtrId] = currDst2;
            }
        }
    }
}

static void RenderChunksToBgTilemap_3x3(MapRender *mapRender)
{
    s32 arrPtrId;
    s32 i, j;
    u16 *tilemapPtrs[3];
    s32 mod3 = mapRender->tilePos.x % 3;
    u16 *ptr = &mapRender->chunkMappings[0][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    s32 unk28Id = 0;

    for (i = 0; i < 8; ptr += 64, i++) {
        u16 *currPtr = ptr;

        for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
            tilemapPtrs[arrPtrId] = &mapRender->bgTilemaps[0][unk28Id];
            unk28Id += 32;
        }

        if (mod3 != 0) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];

            if (mod3 == 1) {
                currSrc++;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    *currDst++ = currSrc[0];
                    *currDst++ = currSrc[1];
                    tilemapPtrs[arrPtrId] = currDst;
                    currSrc += 3;
                }
            }
            else {
                currSrc += 2;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    *currDst++ = currSrc[0];
                    tilemapPtrs[arrPtrId] = currDst;
                    currSrc += 3;
                }
            }
        }

        for (j = 0; j < 10; j++) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];
            for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                u16 *currDst = tilemapPtrs[arrPtrId];
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                tilemapPtrs[arrPtrId] = currDst;
            }
        }

        if (mod3 != 1) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];
            if (mod3 == 0) {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currDst[1] = currSrc[1];
                    currSrc += 3;
                }
            }
            else {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currSrc += 3;
                }
            }
        }
    }
}

static void RenderChunksToBgTilemapWrapAround_3x3(MapRender *mapRender)
{
    s32 mod3;
    s32 arrPtrId;
    u16 *ptr;
    u16 *tilemapPtrs[3];
    s32 unk28Id;
    s32 i, j;
    s32 sub1, sub2;

    // Screw you agbcc...
    ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);ASM_MATCH_TRICK(ptr);

    mod3 = mapRender->tilePos.x % 3;
    ptr = &mapRender->chunkMappings[0][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    unk28Id = 0;
    sub1 = mapRender->heightChunks - mapRender->chunkPos.y;
    sub2 = mapRender->widthChunks - mapRender->chunkPos.x;

    for (i = 0; i < 8; ptr += 64, i++) {
        u16 *currPtr;
        s32 currSub2 = sub2;

        if (sub1 > 0) {
            sub1--;
            currPtr = ptr;
        }
        else {
            sub1 = mapRender->heightChunks;
            ptr = &mapRender->chunkMappings[0][mapRender->chunkPos.x];
            currPtr = ptr;
        }

        for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
            tilemapPtrs[arrPtrId] = &mapRender->bgTilemaps[0][unk28Id];
            unk28Id += 32;
        }

        if (mod3 != 0) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];

            if (mod3 == 1) {
                currSrc++;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    *currDst++ = currSrc[0];
                    *currDst++ = currSrc[1];
                    tilemapPtrs[arrPtrId] = currDst;
                    currSrc += 3;
                }
            }
            else {
                currSrc += 2;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    *tilemapPtrs[arrPtrId]++ = *currSrc;
                    currSrc += 3;
                }
            }

            currSub2--;
            if (currSub2 <= 0) {
                currSub2 = mapRender->widthChunks;
                currPtr -= currSub2;
            }
        }

        for (j = 0; j < 10; j++) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];

            for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                u16 *currDst = tilemapPtrs[arrPtrId];
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                *currDst++ = *currSrc++;
                tilemapPtrs[arrPtrId] = currDst;
            }

            if (--currSub2 <= 0) {
                currSub2 = mapRender->widthChunks;
                currPtr -= currSub2;
            }
        }

        // Interestingly enough this part is NOT present in Blue...
        if (mod3 != 1) {
            u16 *currSrc = &mapRender->tileMappings[*currPtr++ * 9];
            if (mod3 == 0) {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currDst[1] = currSrc[1];
                    currSrc += 3;
                }
            }
            else {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst = tilemapPtrs[arrPtrId];
                    currDst[0] = currSrc[0];
                    currSrc += 3;
                }
            }
        }
    }
}

static void RenderChunksToBgTilemaps_3x3(MapRender *mapRender)
{
    s32 arrPtrId;
    s32 i, j;
    u16 *tilemapPtrs1[3];
    u16 *tilemapPtrs2[3];
    s32 mod3 = mapRender->tilePos.x % 3;
    u16 *ptr1 = &mapRender->chunkMappings[0][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    u16 *ptr2 = &mapRender->chunkMappings[1][(mapRender->chunkPos.y * 64) + mapRender->chunkPos.x];
    s32 unk28Id = 0;

    // Stack memes again...
    ASM_MATCH_TRICK(ptr2);ASM_MATCH_TRICK(ptr2);ASM_MATCH_TRICK(ptr2);

    for (i = 0; i < 8; ptr1 += 64, ptr2 += 64, i++) {
        u16 *currPtr1 = ptr1;
        u16 *currPtr2 = ptr2;

        for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
            tilemapPtrs1[arrPtrId] = &mapRender->bgTilemaps[0][unk28Id];
            tilemapPtrs2[arrPtrId] = &mapRender->bgTilemaps[1][unk28Id];
            unk28Id += 32;
        }

        if (mod3 != 0) {
            u16 *currSrc1 = &mapRender->tileMappings[*currPtr1++ * 9];
            u16 *currSrc2 = &mapRender->tileMappings[*currPtr2++ * 9];

            if (mod3 == 1) {
                currSrc1++;
                currSrc2++;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst1, *currDst2;
                    currDst1 = tilemapPtrs1[arrPtrId];
                    currDst2 = tilemapPtrs2[arrPtrId];
                    *currDst1++ = currSrc1[0];
                    *currDst1++ = currSrc1[1];
                    *currDst2++ = currSrc2[0];
                    *currDst2++ = currSrc2[1];
                    tilemapPtrs1[arrPtrId] = currDst1;
                    tilemapPtrs2[arrPtrId] = currDst2;
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
            else {
                currSrc1 += 2;
                currSrc2 += 2;
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    *tilemapPtrs1[arrPtrId]++ = currSrc1[0];
                    *tilemapPtrs2[arrPtrId]++ = currSrc2[0];
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
        }

        for (j = 0; j < 10; j++) {
            u16 *currSrc1 = &mapRender->tileMappings[*currPtr1++ * 9];
            u16 *currSrc2 = &mapRender->tileMappings[*currPtr2++ * 9];
            for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                u16 *currDst1 = tilemapPtrs1[arrPtrId];
                u16 *currDst2 = tilemapPtrs2[arrPtrId];
                *currDst1++ = *currSrc1++;
                *currDst1++ = *currSrc1++;
                *currDst1++ = *currSrc1++;
                *currDst2++ = *currSrc2++;
                *currDst2++ = *currSrc2++;
                *currDst2++ = *currSrc2++;
                tilemapPtrs1[arrPtrId] = currDst1;
                tilemapPtrs2[arrPtrId] = currDst2;
            }
        }

        if (mod3 != 1) {
            u16 *currSrc1 = &mapRender->tileMappings[*currPtr1++ * 9];
            u16 *currSrc2 = &mapRender->tileMappings[*currPtr2++ * 9];
            if (mod3 == 0) {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst1 = tilemapPtrs1[arrPtrId];
                    u16 *currDst2 = tilemapPtrs2[arrPtrId];
                    currDst1[0] = currSrc1[0];
                    currDst1[1] = currSrc1[1];
                    currDst2[0] = currSrc2[0];
                    currDst2[1] = currSrc2[1];
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
            else {
                for (arrPtrId = 0; arrPtrId < 3; arrPtrId++) {
                    u16 *currDst1, *currDst2;

                    currDst1 = tilemapPtrs1[arrPtrId];
                    currDst1[0] = currSrc1[0];
                    currDst2 = tilemapPtrs2[arrPtrId];
                    currDst2[0] = currSrc2[0];
                    currSrc1 += 3;
                    currSrc2 += 3;
                }
            }
        }
    }
}

void GetCameraPositionForLayer(GroundBg *groundBg, s32 id, PixelPos *dstPos)
{
    *dstPos = groundBg->cameraPixelPosition[id];
}

void SetCameraPositionForLayer(GroundBg *groundBg, s32 id, const PixelPos *srcPos)
{
    groundBg->cameraPixelPosition[id] = *srcPos;
}

void sub_80A4580(GroundBg *groundBg, s32 id, PixelPos *pixPos)
{
    MapRender *mapRender = &groundBg->mapRender[id];

    if (pixPos->x < 0) {
        if (mapRender->wrapAround) {
            do {
                pixPos->x += mapRender->mapSizePixels.x;
            } while (pixPos->x < 0);
        }
        else {
            pixPos->x = 0;
        }
    }
    else if (pixPos->x >= mapRender->mapSizePixels.x) {
        if (mapRender->wrapAround) {
            do {
                pixPos->x -= mapRender->mapSizePixels.x;
            } while (pixPos->x >= mapRender->mapSizePixels.x);
        }
        else {
            pixPos->x = mapRender->mapSizePixels.x - 1;
        }
    }

    if (pixPos->y < 0) {
        if (mapRender->wrapAround) {
            do {
                pixPos->y += mapRender->mapSizePixels.y;
            } while (pixPos->y < 0);
        }
        else {
            pixPos->y = 0;
        }
    }
    else if (pixPos->y >= mapRender->mapSizePixels.y) {
        if (mapRender->wrapAround) {
            do {
                pixPos->y -= mapRender->mapSizePixels.y;
            } while (pixPos->y >= mapRender->mapSizePixels.y);
        }
        else {
            pixPos->y = mapRender->mapSizePixels.y - 1;
        }
    }
}

void sub_80A4608(GroundBg *groundBg, PixelPos *dstPos)
{
    dstPos->x = groundBg->bmaHeader.mapWidthTiles;
    dstPos->y = groundBg->bmaHeader.mapHeightTiles;
}

UNUSED static void sub_80A4620(GroundBg *groundBg, PixelPos *dstPos)
{
    dstPos->x = groundBg->bmaHeader.mapWidthTiles * 8;
    dstPos->y = groundBg->bmaHeader.mapHeightTiles * 8;
}

void GetDungeonBounds(GroundBg *groundBg, PixelPos *dstPos1, PixelPos *dstPos2)
{
    dstPos1->x = 0;
    dstPos1->y = 0;
    dstPos2->x = groundBg->bmaHeader.mapWidthTiles << 11;
    dstPos2->y = groundBg->bmaHeader.mapHeightTiles << 11;
}

u8 sub_80A4660(GroundBg *groundBg, u8 bits, PixelPos *pixPos1, PixelPos *boundary)
{
    s32 i, j;
    u8 *currPtr;
    void *ptr = groundBg->unk544;

    if (ptr == NULL)
        return 0;

    ptr += ((pixPos1->y * 256) + pixPos1->x + 0x405);
    for (i = boundary->y; i > 0; i--) {
        for (j = boundary->x, currPtr = ptr; j > 0; j--) {
            u8 ret = *currPtr++ & bits;
            if (ret)
                return ret;
        }
        ptr += 256;
    }

    return 0;
}

u8 sub_80A46C0(GroundBg *groundBg, u8 bits, PixelPos *pixPos1, PixelPos *boundary)
{
    s32 i, j;
    u8 *currPtr;
    void *ptr = groundBg->unk544;

    if (ptr == NULL)
        return 0;

    ptr += ((pixPos1->y * 256) + pixPos1->x + 0x405);
    for (i = boundary->y; i > 0; i--) {
        for (j = boundary->x, currPtr = ptr; j > 0; j--) {
            u8 ret = *currPtr++ & bits;
            if (ret != bits)
                return 0;
        }
        ptr += 256;
    }

    return 1;
}

u16 sub_80A4720(GroundBg *groundBg, s32 id, PixelPos *pixPos)
{
    u16 *ptr = groundBg->chunkMappings[id] + (pixPos->y * 64);
    ptr += pixPos->x;
    return *ptr;
}

void sub_80A4740(GroundBg *groundBg, s32 id, PixelPos *pixPos, u32 dstVal)
{
    u16 *ptr = groundBg->chunkMappings[id] + (pixPos->y * 64);
    ptr += pixPos->x;
    *ptr = dstVal;
}

void sub_80A4764(GroundBg *groundBg)
{
    s32 i, j;
    s32 unk3E0Id;
    MapRender *mapRender;
    PixelPos *map478;

    if (groundBg->mapFileId == -1)
        return;

    if (groundBg->bplHeader.hasPalAnimations) {
        s32 i;
        SubStruct_0 *sub0Ptr = groundBg->unk0;
        const AnimationSpecification *animSpecifications = groundBg->animationSpecifications;
        u16 r6 = groundBg->unk52C.unk0 * 16;

        for (i = 0; i < groundBg->bplHeader.numPalettes; i++, sub0Ptr++, animSpecifications++, r6 += 16) {
            if (sub0Ptr->unk4 != NULL && --sub0Ptr->unk2 <= 0) {
                if (--sub0Ptr->unk0 <= 0) {
                    if (groundBg->unk471) {
                        sub0Ptr->unk2 = animSpecifications->durationPerFrame;
                        sub0Ptr->unk0 = animSpecifications->numFrames;
                        sub0Ptr->unk8 = sub0Ptr->unk4;
                    }
                    else {
                        sub0Ptr->unk0 = 0;
                        sub0Ptr->unk2 = 0;
                        sub0Ptr->unk8 = NULL;
                    }
                }
                else {
                    sub0Ptr->unk2 = animSpecifications->durationPerFrame;
                }

                if (sub0Ptr->unk8 != NULL) {
                    RGB_Union empty = {0};
                    sub_8003810(r6, empty);
                    sub_809971C(r6 + 1, sub0Ptr->unk8, 15);
                    sub0Ptr->unk8 += 60;
                }
            }
        }

        groundBg->unk471 = groundBg->unk470;
    }
    else if (groundBg->unk440 != NULL) {
        s32 i;
        unkStruct_202EE8C *unkE0Ptr = groundBg->unkE0;
        s32 r6 = 160;

        for (i = 0; i < 32; i++, unkE0Ptr++, r6++) {
            RGB_Union color;

            if (sub_8004D14(unkE0Ptr, 1) && !sub_8004D40(unkE0Ptr, 1) && --unkE0Ptr->unk6 <= 0) {
                unkE0Ptr->unk6 = unkE0Ptr->unk4;
                if (unkE0Ptr->unkC >= unkE0Ptr->unk10) {
                    unkE0Ptr->unkC = unkE0Ptr->unk8;
                }
                unkE0Ptr->unk14 = *unkE0Ptr->unkC++;
                color = (RGB_Union) {unkE0Ptr->unk14.r, unkE0Ptr->unk14.g, unkE0Ptr->unk14.b, unkE0Ptr->unk14.unk4};
                sub_8003810(r6, color);
            }
        }
    }

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *sub3E0Ptr = &groundBg->unk3E0[unk3E0Id];

        if (sub3E0Ptr->unk0 && sub3E0Ptr->unk4-- <= 0) {
            sub3E0Ptr->unk14 += 4;
            sub3E0Ptr->unk1C += (sub3E0Ptr->unk24 / 2) * 2;
            if (++sub3E0Ptr->unk2 >= sub3E0Ptr->unkC->numFrames) {
                sub3E0Ptr->unk14 = sub3E0Ptr->unk10;
                sub3E0Ptr->unk1C = sub3E0Ptr->unk18;
                sub3E0Ptr->unk2 = 0;
            }
            sub3E0Ptr->unk1 = 1;
            sub3E0Ptr->unk4 = *(u32 *)(sub3E0Ptr->unk14);
        }
    }

    mapRender = groundBg->mapRender;
    map478 = groundBg->cameraPixelPosition;
    for (i = 0; i < groundBg->unk474; i++, mapRender++, map478++) {
        s32 unk;

        UpdateMapCameraPosition(mapRender, map478);
        CallMapTilemapRenderFunc(mapRender);
        for (j = 0, unk = mapRender->unk2 + groundBg->unk52C.unkA; j < mapRender->numBgs; j++, unk++) {
            switch (unk) {
                case 0:
                    SetBG2RegOffsets(mapRender->bgRegOffsets.x, mapRender->bgRegOffsets.y);
                    break;
                case 1:
                    SetBG3RegOffsets(mapRender->bgRegOffsets.x, mapRender->bgRegOffsets.y);
                    break;
            }
        }
    }

    groundBg->unk52A = 1;
}

void sub_80A49E8(GroundBg *groundBg)
{
    s32 i;
    s32 unk3E0Id;

    for (unk3E0Id = 0; unk3E0Id < UNK_3E0_ARR_COUNT; unk3E0Id++) {
        SubStruct_3E0 *sub3E0Ptr = &groundBg->unk3E0[unk3E0Id];

        if (sub3E0Ptr->unk1) {
            MemoryCopy32(sub3E0Ptr->unk20, sub3E0Ptr->unk1C, sub3E0Ptr->unk24);
            sub3E0Ptr->unk1 = FALSE;
            groundBg->unk52A = 1;
        }
    }

    if (groundBg->unk52A) {
        s32 unk;
        for (i = 0, unk = groundBg->unk52C.unkA; i < groundBg->unk52C.numLayers; i++, unk++) {
            ScheduleBgTilemapCopy(unk + 2);
        }
        groundBg->unk52A = 0;
    }
}
