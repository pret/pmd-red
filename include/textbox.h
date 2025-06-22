#ifndef GUARD_TEXTBOX_H
#define GUARD_TEXTBOX_H

#include "structs/str_position.h"

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
void SetAutoPressTextboxFrames(s32 frames);
void SetAutoPressTextboxMidEndMsgFrames(s32 endMsgFrames, s32 midMsgFrames);
bool8 ScriptClearTextbox(void);
bool8 ScriptClearTextbox2(void);
void ResetTextboxPortrait(s16 id_);
bool8 ScriptSetPortraitInfo(s32 portraitId_, s32 spriteId_, s32 placementId_);
bool8 ScriptSetPortraitPosDelta(s32 portraitId_, PixelPos *newPosDelta);
bool8 ScriptPrintText(s32 scriptMsgType, s32 speakerId_, const char *text);
bool8 ScriptPrintTextOnBg(const char *text);
bool8 ScriptPrintTextOnBg2(const char *text);
bool8 ScriptPrintTextOnBgAuto(s32 unused, const char *text);

#endif // GUARD_WONDER_MAIL_H
