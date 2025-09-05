#ifndef GUARD_DUNGEON_MISC_H
#define GUARD_DUNGEON_MISC_H

#include "structs/dungeon_entity.h"
#include "structs/str_moves.h"
#include "structs/str_pokemon.h"
#include "pokemon_summary_window.h"

struct unkStruct_8069D4C
{
    s16 id;
    DungeonPos pos;
    s16 HP;
    u8 att[2]; // Atk, SpAtk
    u8 def[2]; // Def, SpDef
    u16 level;
    u32 exp;
    FixedPoint belly;
    FixedPoint maxBelly;
    Item heldItem;
    Moves moves;
    HiddenPower hiddenPower;
};

void OpenDungeonPaletteFile(void);
void CloseDungeonPaletteFile(void);
void LoadDungeonPokemonSprites(void);
void LoadDungeonActivePokemonSprites(void);
void sub_80687AC(void);
OpenedFile *GetSpriteData(s32 _species);
void LoadPokemonSprite(s32 _id, bool32 _ignoreDeoxys);
void CloseAllSpriteFiles(void);
void SetDungeonMonsFromTeam(void);
void sub_8068A84(Pokemon *pokemon);
void sub_8068BDC(bool8 a0);
void sub_8068F28(void);
void sub_8068F80(void);
void HandleFaint(Entity *entity, s32 dungeonExitReason, Entity *param_3);
void sub_80694C0(Entity *target,s32 x,s32 y,u8 param_4);
void sub_80695EC(Entity *param_1,int x,int y);
Entity * sub_8069660(Entity *target);
Entity * sub_80696A8(Entity *target);
Entity * sub_80696FC(Entity *target);
Entity * sub_806977C(Entity *target);
void SetMonSummaryInfoFromEntity(struct MonSummaryInfo *param_1, Entity *target);
bool8 sub_8069D18(DungeonPos *pos,Entity *entity);
void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target);
void TargetTileInFront(Entity *pokemon);
void sub_8069E0C(Entity *pokemon);
void TryActivateArtificialWeatherAbilities(void);
s32 GetMonsterApparentID(Entity *pokemon, s32 _id);
void sub_8069F9C(Entity *pokemon, Entity *target, Move *move);
void sub_806A120(Entity * pokemon, Entity * target, Move* move);
void sub_806A1B0(Entity *pokemon);
void sub_806A1E8(Entity *pokemon);
void sub_806A240(Entity *pokemon, Entity *target);
void TryPointCameraToMonster(Entity *pokemon, u8 param_2);
void sub_806A338(void);
void sub_806A390(Entity *pokemon);
void sub_806A3D4(u8 *dst, s32 _a1, s32 id, bool32 _a3);
bool8 sub_806A458(Entity *pokemon);
s32 sub_806A4DC(EntityInfo *info);
bool8 sub_806A538(s16 r0);
bool8 sub_806A564(s16 r0);
bool8 sub_806A58C(s16 r0);
void sub_806A5B8(Entity *entity);
void sub_806A6E8(Entity *entity);
void DisplayMsgIfNewIqSkillLearned(EntityInfo *info, s32 iqBefore);
void sub_806A898(Entity *entity, bool8 r7, bool8 showRunAwayEffect);
void sub_806A914(bool8 a0, bool8 a1, bool8 showRunAwayEffect);
void sub_806A974(void);
void sub_806A9B4(Entity *entity, s32 moveIndex);
bool8 sub_806AA0C(s32 _species, bool32 _a1);
void sub_806AA70(void);
void sub_806AB2C(void);
void EndAbilityImmuneStatus(Entity *attacker, Entity *target);
void MarkLastUsedMonMove(Entity *entity, Move *move);

#endif // GUARD_DUNGEON_MISC_H
