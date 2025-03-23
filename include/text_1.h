#ifndef GUARD_TEXT_1_H
#define GUARD_TEXT_1_H

#include "structs/str_text.h"

// These should probably go to code_8009804.h
#define TILEMAP_TILE_NUM(num)(num & 0x3FF) // bits 0-9
#define TILEMAP_FLIP_HORIZONTAL(f)((f & 1) << 10) // bit 10
#define TILEMAP_FLIP_VERTICAL(f)((f & 1) << 11) // bit 11
#define TILEMAP_PAL(pal)((pal & 0xF) << 12) // bits 12-15

// size: 0x10
typedef struct unkShiftData
{
    u32 bytesA;
    u32 bytesB;
    u32 shift_left;
    u32 shift_right;
} unkShiftData;

typedef struct CharMapStruct
{
    s32 unk0;
    unkChar *unk4;
} CharMapStruct;

extern Window gWindows[MAX_WINDOWS];
extern CharMapStruct *gCharmaps[2];
extern s16 gCharacterSpacing;
extern u8 gUnknown_202749A[11];
extern bool8 gUnknown_20274A5;
extern u8 gUnknown_20274A6[6];
extern s32 gCurrentCharmap;
extern s32 gUnknown_202B020;
extern s32 gUnknown_202B024;
extern s32 gCharHeight[2];
extern u32 gTextShadowMask;
extern u8 gDrawTextShadow;
extern u16 gBgTilemaps[4][32][32];

extern void (*ScrollDownWindowFunc)(s32 windowId);
extern void (*ScrollUpWindowFunc)(s32 windowId);
extern void (*gIwramTextFunc3)(s32 a0);
extern void (*gIwramTextFunc4)(s32 a0);

extern s16 gUnknown_3000E94[161];

extern const u32 gUnknown_80B853C[16];
extern const unkShiftData gCharMasksOffsets[8];
extern const unkChar gUnknown_80B86A4;
extern const u32 gUnknown_80B86B4[][32];

void LoadCharmaps(void);
void RestoreSavedWindows(WindowTemplates *dst);
void SelectCharmap(u32);
void SetCharacterMask(s32);
void ShowWindows(const WindowTemplates *winTemplates, bool8, bool8);
u32 sub_80063B0(void);
u32 sub_8006544(u32 index);
void sub_8007334(s32 windowId);
void sub_80073B8(s32 windowId);
void sub_80073E0(s32 windowId);
u32 UpdateFadeInTile(u32);

#endif // GUARD_TEXT_1_H
