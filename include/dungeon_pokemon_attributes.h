#ifndef GUARD_DUNGEON_POKEMON_ATTRIBUTES_H
#define GUARD_DUNGEON_POKEMON_ATTRIBUTES_H

#include "structs/dungeon_entity.h"

bool8 HasSafeguardStatus(Entity * param_1, Entity * param_2, bool8 displayMessage);
bool8 sub_8071728(Entity * pokemon, Entity * target, bool8 displayMessage);
bool8 sub_80717A4(Entity *pokemon, u16 moveID);
bool8 HasAbility(Entity *pokemon, u8 ability);
bool8 MonsterIsType(Entity *pokemon, u8 type);
bool8 CanSeeInvisibleMonsters(Entity *pokemon);
bool8 HasTactic(Entity *pokemon, u8 tactic);
bool8 IQSkillIsEnabled(Entity *pokemon, u8 IQSkill);
void LoadIQSkills(Entity *pokemon);
bool8 CanSeeTeammate(Entity * pokemon);
u8 GetMoveTypeForMonster(Entity *pokemon, Move *pokeMove);
s32 GetMovePower(Entity *pokemon, Move *pokeMove);
bool8 MonsterCanThrowItems(EntityInfo *pokemon);
bool8 SetVisualFlags(EntityInfo *entityInfo, u16 newFlag, bool8 param_3);

#endif
