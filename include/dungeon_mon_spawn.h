#ifndef GUARD_DUNGEON_MON_SPAWN_H
#define GUARD_DUNGEON_MON_SPAWN_H

#include "structs/dungeon_entity.h"
#include "structs/str_pokemon.h"

struct MonSpawnInfo
{
    s16 species;
    u8 unk2;
    u32 unk4;
    s16 level;
    DungeonPos pos;
    u8 unk10;
};

void sub_806AD3C(void);
void sub_806B168(void);
void sub_806B404(void);
void sub_806B678(void);
void SpawnWildMonsOnFloor(void);
Entity* SpawnWildMon(struct MonSpawnInfo *monSpawnInfo, bool8 a1);
bool8 SpawnTeamMember(s16 _species, s32 x, s32 y, DungeonMon *monPtr, Entity **a4, bool32 _a5, u32 _a6);
void UpdateEntitySpecies(Entity *entity, s32 _species);
void ResetMonEntityData(EntityInfo *entInfo, bool8 setStatsToOne);
void sub_806C1D8(void);
void sub_806C264(s32 teamIndex, EntityInfo *entInfo);
void sub_806C330(s32 _x, s32 _y, s16 _species, u32 _a3);
void sub_806C3C0(void);
void sub_806C42C(void);

#endif
