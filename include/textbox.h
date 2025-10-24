#ifndef GUARD_TEXTBOX_H
#define GUARD_TEXTBOX_H

#include "structs/str_position.h"
#include "structs/menu.h"

enum
{
    SCRIPT_TEXT_TYPE_INSTANT, // 0x32 Used for narration and signposts
    SCRIPT_TEXT_TYPE_PLAYER, // 0x33 Used for player's thoughts, player's dialogue and Murky Cave's judge of darkness
    SCRIPT_TEXT_TYPE_NPC, // 0x34 Used for all NPCs, has the speaker's name and dialogue sound
    SCRIPT_TEXT_TYPE_LETTER, // 0x35 Used for Mails/Letters. Has a dialogue sound when priting text, similarly to SCRIPT_TEXT_TYPE_NPC
    SCRIPT_TEXT_TYPE_4, // 0x36 Used for sound-like texts such as "Flap-flap" or roars "Gyaaaaaaaah". It doesn't wait for button press, so the message just closes after printing unless WAIT command is used afterwards.
};

void TextboxInit(void);
void TextboxFree(void);
void TextboxResetAll(void);
void sub_809A6E4(u16 r0);
void sub_809A6F8(u16 r0);
void SetAutoPressTextboxFrames(s32 frames);
void SetAutoPressTextboxMidEndMsgFrames(s32 endMsgFrames, s32 midMsgFrames);
bool8 IsTextboxOpen_809A750(void);
bool8 sub_809A768(void);
bool8 ScriptClearTextbox(void);
bool8 ScriptClearTextbox2(void);
void ResetTextboxPortrait(s16 id_);
bool8 sub_809AB4C(s32 a0_, s32 a1_);
bool8 sub_809ABB4(s32 id_, s32 a1_);
bool8 sub_809AC18(s32 a0_, s32 a1_);
bool8 ScriptSetPortraitInfo(s32 portraitId_, s32 spriteId_, s32 placementId_);
bool8 ScriptSetPortraitPosDelta(s32 portraitId_, PixelPos *newPosDelta);
bool8 ScriptPrintText(s32 scriptMsgType, s32 speakerId_, const char *text);
bool8 ScriptPrintTextOnBg(const char *text);
bool8 ScriptPrintTextOnBg2(const char *text);
bool8 ScriptPrintTextOnBgAuto(s32 unused, const char *text);
bool8 sub_809AFAC(void);
void sub_809AFC8(s32 a0_, s32 a1, s32 a2_, const char *text);
bool8 sub_809AFFC(u8 *a0);
void sub_809B028(const MenuItem * menuItems, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text);
bool8 sub_809B18C(s32 *sp);
bool8 sub_809B1C0(s32 a0, u32 kind, void *a2);
bool8 sub_809B1D4(s32 a0, u32 kind, s32 a2, void *a3);
bool8 sub_809B260(s32 *a0);
void sub_809B474(void);
void sub_809B57C(void);
void sub_809B614(void);
void sub_809B638(void);

#endif // GUARD_WONDER_MAIL_H
