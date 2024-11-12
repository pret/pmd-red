#ifndef GUARD_STRING_FORMAT_H
#define GUARD_STRING_FORMAT_H

#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_text.h"
#include "structs/rgb.h"

// TODO: once the files close to string_format.c are decompiled, check if these should be included here. Most likely, they should be declared elsewhere.
// code_80130A8.s
void sub_8013E54(void);
void sub_8013F84(void);
void sub_80140B4(UnkTextStruct2 *);
void sub_80140DC(void);
void sub_8014114(void);
s32 sub_80144A4(s32 *);
void sub_80151C0(u32, u8 *);
u32 sub_80154F0(void);
void sub_80155F0(void);

struct PortraitGfxSub
{
    const RGB *pal;
    const u8 *gfx;
};

struct PortraitGfx
{
    struct PortraitGfxSub sprites[10];
};

struct MonPortraitMsg
{
    OpenedFile *faceFile;
    struct PortraitGfx *faceData;
    DungeonPos pos;
    u8 spriteId; // Which mon's sprite to use. For example Kecleon has multiple sprites depending on whether it's green or purple.
    bool8 flip; // Whether the mon's sprite is flipped.
    u8 unkE;
};

#define FORMAT_BUFFER_LEN 80
#define FRIEND_AREA_BUFFER_LEN 184

extern s32 gFormatArgs[10];
extern u8 gFormatBuffer_Items[4][FORMAT_BUFFER_LEN];
extern u8 gFormatBuffer_Monsters[10][FORMAT_BUFFER_LEN];
extern u8 gFormatBuffer_Names[10][FORMAT_BUFFER_LEN];
extern u8 gSpeakerNameBuffer[FORMAT_BUFFER_LEN];
extern u8 gFormatBuffer_FriendArea[FRIEND_AREA_BUFFER_LEN];

void sub_8014144(void);
void sub_801416C(s32 param_1,s32 param_2);
void CreateDialogueBoxAndPortrait(const u8 *text, void *param_2, struct MonPortraitMsg *monPortraitPtr, u16 flags);
void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 flags);
void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 flags);
void CreateMenuDialogueBoxAndPortrait(const u8 *text, void *a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, struct MonPortraitMsg *monPortraitPtr, u16 flags);
void sub_8014490(void);
s32 sub_80144A4(s32 *a0);
void DrawDialogueBoxString(void);
const u8 *FormatString(const u8 *str, u8 *dst, u8 *dstMax, u16 flags);
void PrintFormattedStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr);
void PrintFormattedStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing);

#endif // GUARD_STRING_FORMAT_H
