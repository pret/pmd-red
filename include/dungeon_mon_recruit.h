#ifndef GUARD_DUNGEON_MON_RECRUIT_H
#define GUARD_DUNGEON_MON_RECRUIT_H

#include "structs/dungeon_entity.h"
#include "dungeon_misc.h"

bool8 TryRecruitMonster(Entity *attacker, Entity *target);
bool8 IsMonsterRecruitable(s32 species);
bool8 HandleMonsterJoinSequence(Entity *entity1, Entity *entity2, struct unkStruct_8069D4C *param_3);
// These two functions are only used for Celebi's scene for some reason.
bool8 CanEntityBeRecruited(Entity *param_1);
bool8 HandleSpecialEntityJoinSequence(Entity *entity1,Entity *entity2,Entity **entityPtr);

#endif // GUARD_DUNGEON_MON_RECRUIT_H
