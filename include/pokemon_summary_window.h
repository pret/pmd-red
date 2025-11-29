#ifndef GUARD_POKEMON_SUMMARY_WINDOW_H
#define GUARD_POKEMON_SUMMARY_WINDOW_H

#include "structs/str_dungeon_location.h"
#include "structs/str_pokemon.h"

enum
{
    SUB_WINDOW_NONE,
    SUB_WINDOW_STATUS,
    SUB_WINDOW_STATS,
    SUB_WINDOW_FEATUERS,
    SUB_WINDOW_IQ,
    SUB_WINDOW_INFO,
};

#define MON_SUMMARY_UNK58_COUNT 12

struct MonSummaryInfo
{
    // size: 0x64
    s16 species;
    u8 nameBuffer[0x14];
    u8 types[2]; // 0x16
    u8 abilities[2]; // 0x18
    u8 fill1A[0x1C - 0x1A];
    DungeonLocation dungeonLocation; // 0x1C
    Item item; // 0x20
    s32 HP1;
    s32 HP2;
    s32 level;
    u32 exp;
    Offense offense;
    bool8 isTeamLeader;
    u8 atkBoost;
    u8 spAtkBoost;
    u8 defBoost;
    u8 spDefBoost;
    u8 fill3D;
    s16 IQ; // 0x3E
    s16 unk40;
    s16 fill42;
    struct unkPokeSubStruct_C unk44[2];
    u8 evoStringId;
    u8 fill4D[3];
    IqSkillFlags IQSkills; // 0x50
    u8 tactic;
    u8 fill55[1];
    s16 unk56;
    u8 unk58[MON_SUMMARY_UNK58_COUNT];
};

struct UnkInfoTabStruct
{
    u8 unk0[0xC];
    s32 unkC[9];
};

void ShowPokemonSummaryWindow(s32 which, s32 currSubWindowId, struct MonSummaryInfo *monInfo, struct UnkInfoTabStruct *param_4, u32 windowId);
void SetMonSummaryInfo(struct MonSummaryInfo *dst, struct Pokemon *pokemon, bool8 unlockedEvolutions);

#endif // GUARD_POKEMON_SUMMARY_WINDOW_H
