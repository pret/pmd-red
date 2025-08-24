#ifndef GUARD_GROUND_BG_H
#define GUARD_GROUND_BG_H

#include "structs/str_ground_bg.h"
#include "structs/str_dungeon_location.h"

void GroundBg_Init(GroundBg *groundBg, const SubStruct_52C *a1);
void GroundBg_FreeAll(GroundBg *groundBg);
void sub_80A2D68(GroundBg *groundBg);
void sub_80A2D88(GroundBg *groundBg);
void sub_80A2FBC(GroundBg *groundBg, s32 mapFileId_);
void sub_80A3440(GroundBg *groundBg, s32 mapFileId_, const DungeonLocation *dungLoc, s32 a3);
void sub_80A3B80(GroundBg *groundBg, u8 a1, u8 a2);
void sub_80A3BB0(GroundBg *groundBg, s32 a0_);
void sub_80A4558(GroundBg *groundBg, s32 id, PixelPos *dstPos);
void sub_80A456C(GroundBg *groundBg, s32 id, const PixelPos *srcPos);
void sub_80A4580(GroundBg *groundBg, s32 id, PixelPos *pixPos);
void sub_80A4608(GroundBg *groundBg, PixelPos *dstPos);
u16 sub_80A4720(GroundBg *groundBg, s32 id, PixelPos *pixPos);
void sub_80A4740(GroundBg *groundBg, s32 id, PixelPos *pixPos, u32 dstVal);
void sub_80A4764(GroundBg *groundBg);
void sub_80A49E8(GroundBg *groundBg);
void GetDungeonBounds(GroundBg *groundBg, PixelPos *dstPos1, PixelPos *dstPos2);

#endif // GUARD_GROUND_BG_H
