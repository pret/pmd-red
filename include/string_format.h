#ifndef GUARD_STRING_FORMAT_H
#define GUARD_STRING_FORMAT_H

#include "structs/menu.h"
#include "structs/rgb.h"
#include "structs/str_file_system.h"
#include "structs/str_mon_portrait.h"
#include "structs/str_text.h"

#define FORMAT_BUFFER_LEN 80
#define FRIEND_AREA_BUFFER_LEN 184

extern s32 gFormatArgs[10];
extern u8 gFormatBuffer_Items[4][FORMAT_BUFFER_LEN];
extern u8 gFormatBuffer_Monsters[10][FORMAT_BUFFER_LEN];
extern u8 gFormatBuffer_Names[10][FORMAT_BUFFER_LEN];
extern u8 gSpeakerNameBuffer[FORMAT_BUFFER_LEN];
extern u8 gFormatBuffer_FriendArea[FRIEND_AREA_BUFFER_LEN];

void ResetDialogueBox(void);
void SetDialogueBoxAutoPressFrames(s32 endMsgFrames, s32 midMsgFrames);
void CreateDialogueBoxAndPortrait(const u8 *text, void *param_2, MonPortraitMsg *monPortraitPtr, u16 flags);
void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, MonPortraitMsg *monPortraitPtr, u16 flags);
void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, MonPortraitMsg *monPortraitPtr, u16 flags);
void CreateMenuDialogueBoxAndPortrait(const u8 *text, void *a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, MonPortraitMsg *monPortraitPtr, u16 flags);
void sub_8014490(void);
s32 sub_80144A4(s32 *a0);
void DrawDialogueBoxString_Async(void);
const u8 *FormatString(const u8 *str, u8 *dst, u8 *dstMax, u16 flags);
void PrintFormattedStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr);
void PrintFormattedStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing);

#define STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS_2 0x1 // Same as STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS, except the check is in a different place. Functionally, both need to be set to wait for the button press.
#define STR_FORMAT_FLAG_TIMED_AUTO_MSG_CLOSE 0x2 // Textbox closes automatically after waiting a couple of frames.
#define STR_FORMAT_FLAG_DIALOGUE_SOUND 0x4
#define STR_FORMAT_FLAG_SPEAKER_NAME 0x8
#define STR_FORMAT_FLAG_ONLY_TEXT 0x10 // No window, prints only text
#define STR_FORMAT_FLAG_INSTANT_TEXT 0x20
#define STR_FORMAT_FLAG_INSTANT_TEXT_ON_AB_PRESS 0x40
#define STR_FORMAT_FLAG_NEW_LINE_TERMINATES 0x80
#define STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS 0x100
#define STR_FORMAT_FLAG_x200 0x200

#endif // GUARD_STRING_FORMAT_H
