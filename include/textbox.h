#ifndef GUARD_TEXTBOX_H
#define GUARD_TEXTBOX_H

void TextboxInit(void);
void TextboxFree(void);

void SetAutoPressTextboxFrames(s32 frames);
void SetAutoPressTextboxMidEndMsgFrames(s32 endMsgFrames, s32 midMsgFrames);
bool8 ScriptClearTextbox(void);
bool8 ScriptClearTextbox2(void);
void ResetTextboxPortrait(s16 id_);
bool8 ScriptPrintText(s32 scriptMsgType, s32 speakerId_, const char *text);

#endif // GUARD_WONDER_MAIL_H
