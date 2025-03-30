#ifndef GUARD_DUNGEON_LOGIC_H
#define GUARD_DUNGEON_LOGIC_H

#include "structs/map.h"
#include "structs/dungeon_entity.h"

extern u8 gWalkableTileToCrossableTerrain[8];

u8 GetCrossableTerrain(s16 species);
u8 sub_807034C(s32 id, const Tile *tile);
u8 sub_80703A0(Entity *pokemon, DungeonPos *pos);
bool8 CanCrossWalls(Entity *pokemon);
bool8 sub_807049C(Entity *pokemon, DungeonPos *pos);
bool8 sub_8070564(Entity *pokemon, DungeonPos *pos);
bool8 sub_80705F0(Entity *pokemon, DungeonPos *pos);
bool8 sub_80706A4(Entity *pokemon, DungeonPos *pos);
s32 CalcSpeedStage(Entity *pokemon);
s32 sub_8070828(Entity *pokemon, bool8 displayMessage);
void SetMessageArgument_2(u8 *buffer, EntityInfo *param_2, s32 colorNum);
void sub_8070968(u8 *buffer, EntityInfo *entityInfo, s32 colorNum);
void sub_80709C8(u8 *buffer, EntityInfo *entityInfo);
bool8 HasNegativeStatus(Entity *pokemon);
bool8 IsSleeping(Entity *pokemon);
bool8 HasLowHealth(Entity *pokemon);
bool8 CheckVariousStatuses2(Entity *pokemon, bool8 checkBlinker);
bool8 sub_8070BC0(Entity* entity);
bool8 CheckVariousConditions(Entity *pokemon);
bool8 CheckVariousStatuses(Entity *pokemon);
bool8 CannotAttack(Entity *pokemon, bool8 skipSleep);
bool8 CanMoveInDirection(Entity *pokemon, u32 direction);
bool8 sub_8070F3C(Entity * pokemon, DungeonPos *pos, s32 direction);
bool8 sub_8070F14(Entity * pokemon, s32 direction);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
bool8 CanAttackInDirection(Entity *pokemon, s32 direction);
bool8 CanAIMonsterMoveInDirection(Entity *pokemon, s32 direction, bool8 *pokemonInFront);
bool8 IsAtJunction(Entity *pokemon);
bool8 ShouldAvoidFirstHit(Entity *pokemon, bool8 forceAvoid);
bool8 ShouldMonsterRunAway(Entity *pokemon);
bool8 ShouldMonsterRunAwayAndShowEffect(Entity *pokemon, bool8 showRunAwayEffect);
void CheckRunAwayVisualFlag(Entity *pokemon, bool8 showRunAwayEffect);
u8 GetTreatmentBetweenMonsters(Entity *pokemon, Entity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified);
u8 sub_807167C(Entity * pokemon, Entity * target);
bool8 HasSafeguardStatus(Entity * pokemon, Entity * target, bool8 displayMessage);
bool8 sub_8071728(Entity * pokemon, Entity * target, bool8 displayMessage);
bool8 sub_80717A4(Entity *pokemon, u16 moveID);
bool8 AbilityIsActive(Entity *pokemon, u8 ability);
bool8 MonsterIsType(Entity *pokemon, u8 type);
bool8 CanSeeInvisibleMonsters(Entity *pokemon);
bool8 IsTacticSet(Entity *pokemon, u8 tactic);
bool8 IQSkillIsEnabled(Entity *pokemon, u8 IQSkill);
void LoadIQSkills(Entity *pokemon);
bool8 CanSeeTeammate(Entity * pokemon);
u8 GetMoveTypeForMonster(Entity *pokemon, Move *pokeMove);
s32 GetMovePower(Entity *pokemon, Move *pokeMove);
bool8 MonsterCanThrowItems(EntityInfo *pokemon);
bool8 sub_8071A8C(Entity *pokemon);
bool8 SetVisualFlags(EntityInfo *entityInfo, u16 newFlag, bool8 param_3);

#endif
