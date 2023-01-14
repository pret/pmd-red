#ifndef GUARD_DUNGEON_POKEMON_ATTRIBUTES_H
#define GUARD_DUNGEON_POKEMON_ATTRIBUTES_H

#include "dungeon_entity.h"

bool8 HasSafeguardStatus(struct Entity * param_1, struct Entity * param_2, bool8 displayMessage);
bool8 sub_80717A4(struct Entity *pokemon, u16 moveID);
bool8 HasAbility(struct Entity *pokemon, u8 ability);
bool8 MonsterIsType(struct Entity *pokemon, u8 type);
bool8 CanSeeInvisibleMonsters(struct Entity *pokemon);
bool8 HasTactic(struct Entity *pokemon, u8 tactic);
bool8 IQSkillIsEnabled(struct Entity *pokemon, u8 IQSkill);
void LoadIQSkills(struct Entity *pokemon);
bool8 CanSeeTeammate(struct Entity * pokemon);
u8 GetMoveTypeForMonster(struct Entity *pokemon, struct Move *pokeMove);
s32 GetMovePower(struct Entity *pokemon, struct Move *pokeMove);
bool8 ToolboxEnabled(struct EntityInfo *pokemon);
bool8 SetVisualFlags(struct EntityInfo *entityInfo, u16 newFlag, bool8 param_3);

#endif
