#ifndef GUARD_CODE_80130A8_H
#define GUARD_CODE_80130A8_H

#include "file_system.h"
#include "structs/menu.h"
#include "structs/str_text.h"

struct PortraitGfxSub
{
    const u8 *pal;
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
    Position pos;
    u8 spriteId; // Which mon's sprite to use. For example Kecleon has multiple sprites depending on whether it's green or purple.
    bool8 flip; // Whether the mon's sprite is flipped.
    u8 unkE;
};

// code_80130A8.s
void sub_8013E54(void);
void sub_8013F84(void);
void sub_80140B4(UnkTextStruct2 *);
void sub_80140DC(void);
void sub_8014114(void);
void CreateDialogueBoxAndPortrait(const u8 *, u32, struct MonPortraitMsg *, u16);
void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3);
void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3);
void CreateMenuDialogueBoxAndPortrait(const u8 *text, u32 a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, struct MonPortraitMsg *monPortraitPtr, u16 r10);
s32 sub_80144A4(s32 *);
void sub_80151C0(u32, u8 *);
u32 sub_80154F0(void);
void sub_80155F0(void);
void DrawDialogueBoxString(void);
void PrintFormatStringOnWindow(u32, u32, const u8 *, u32 windowId, u32);
u8 *xxx_format_string(const u8 *, u8 *, u8 *, u32);

#endif // GUARD_CODE_80130A8_H
