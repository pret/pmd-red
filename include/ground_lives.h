#ifndef GUARD_GROUND_LIVES_H
#define GUARD_GROUND_LIVES_H

#include "structs/str_position.h"
#include "structs/str_ground_script.h"
#include "structs/str_ground_lives.h"

// ground_lives.s
s32 sub_80A7AE8(s16);
s32 sub_80A8FD8(s32 id_, PixelPos *pixelPos);
bool8 GroundLives_ExecuteScript(s32 id_, ActionUnkIds *a1, ScriptInfoSmall *scriptInfo);
s16 GetFriendAreaDialogueId(s32 id_);

#endif // GUARD_GROUND_LIVES_H
