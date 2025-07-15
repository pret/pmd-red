#ifndef GUARD_EFFECT_ANIM_FILE_H
#define GUARD_EFFECT_ANIM_FILE_H

#include "structs/str_file_system.h"

OpenedFile *OpenEffectFile(u32 animType, s32 effectID);
void CloseEffectFile(OpenedFile *file);

#endif // GUARD_EFFECT_ANIM_FILE_H
