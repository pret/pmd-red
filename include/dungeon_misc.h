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

#define DUNGEON_EXIT_TRANSFORMED_INTO_FRIEND        0x1f4
#define DUNGEON_EXIT_LEFT_WITHOUT_BEING_BEFRIENDED  0x1f5
#define DUNGEON_EXIT_FAINTED_FROM_DEBUG_ATTACK      0x1f6
#define DUNGEON_EXIT_MISSED_JUMP_KICK               0x1f7
#define DUNGEON_EXIT_MISSED_HI_JUMP_KICK            0x1f8
#define DUNGEON_EXIT_FAINTED_FROM_DESTINY_BOND      0x1f9
#define DUNGEON_EXIT_FAINTED_COVERED_IN_SLUDGE      0x1fa
#define DUNGEON_EXIT_UNUSED_507                     0x1fb
#define DUNGEON_EXIT_UNUSED_508                     0x1fc
#define DUNGEON_EXIT_FAINTED_FROM_RECOIL            0x1fd
#define DUNGEON_EXIT_FAINTED_FROM_DAMAGE_BOUNCING   0x1fe
#define DUNGEON_EXIT_DEFEATED_PENT_UP_ENERGY        0x1ff
#define DUNGEON_EXIT_UNUSED_512                     0x200
#define DUNGEON_EXIT_UNUSED_513                     0x201
#define DUNGEON_EXIT_UNUSED_514                     0x202
#define DUNGEON_EXIT_UNUSED_515                     0x203
#define DUNGEON_EXIT_UNUSED_516                     0x204
#define DUNGEON_EXIT_UNUSED_517                     0x205
#define DUNGEON_EXIT_FAINTED_FROM_SPIKES            0x206
#define DUNGEON_EXIT_DEBUG_DAMAGE                   0x207
#define DUNGEON_EXIT_FAINTED_FROM_BURN              0x208
#define DUNGEON_EXIT_FAINTED_FROM_CONSTRICTION      0x209
#define DUNGEON_EXIT_FAINTED_FROM_POISON            0x20a
#define DUNGEON_EXIT_FAINTED_FROM_WRAP              0x20b
#define DUNGEON_EXIT_FELLED_BY_CURSE                0x20c
#define DUNGEON_EXIT_DRAINED_BY_LEECH_SEED          0x20d
#define DUNGEON_EXIT_FAINTED_FROM_PERISH_SONG       0x20e
#define DUNGEON_EXIT_FAINTED_WHILE_IN_NIGHTMARE     0x20f
#define DUNGEON_EXIT_FELLED_BY_THROWN_ROCK          0x210
#define DUNGEON_EXIT_FAINTED_FROM_HUNGER            0x211
#define DUNGEON_EXIT_DISAPPEARED_IN_EXPLOSION       0x212
#define DUNGEON_EXIT_TRIPPED_CHESTNUT_TRAP          0x213
#define DUNGEON_EXIT_FAINTED_DUE_TO_TRAP            0x214
#define DUNGEON_EXIT_FELL_INTO_PITFALL              0x215
#define DUNGEON_EXIT_DEFEATED_BLAST_SEED            0x216
#define DUNGEON_EXIT_FELLED_BY_THROWN_ITEM          0x217
#define DUNGEON_EXIT_TRANSFORMED_INTO_ITEM          0x218
#define DUNGEON_EXIT_FAINTED_FROM_BEING_KNOCKED     0x219
#define DUNGEON_EXIT_FELLED_BY_POKEMON_FLYING       0x21a
#define DUNGEON_EXIT_GAVE_UP_EXPLORATION            0x21b
#define DUNGEON_EXIT_DELETED_FOR_EVENT              0x21c
#define DUNGEON_EXIT_WENT_AWAY                      0x21d
#define DUNGEON_EXIT_BLOWN_OUT_UNSEEN_FORCE         0x21e
#define DUNGEON_EXIT_RETURNED_WITH_FALLEN_PARTNER   0x21f
#define DUNGEON_EXIT_FAINTED_DUE_TO_WEATHER         0x220
#define DUNGEON_EXIT_WAS_POSSESSED                  0x221
#define DUNGEON_EXIT_FAILED_TO_PROTECT_CLIENT       0x222
#define DUNGEON_EXIT_FAINTED_FROM_WONDER_ORB        0x223
#define DUNGEON_EXIT_FAINTED_FROM_ITEM              0x224
#define DUNGEON_EXIT_UNK                            0x225
#define DUNGEON_EXIT_ESCAPED_MIDDLE_OF_EXPLORATION  0x226
#define DUNGEON_EXIT_CLEARED_DUNGEON                0x227
#define DUNGEON_EXIT_SUCCEEDED_IN_RESCUE_MISSION    0x228
#define DUNGEON_EXIT_IMPRESSIVELY_COMPLETED_MISSION 0x229
#define DUNGEON_EXIT_BEFRIENDED_MEW                 0x22a

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
