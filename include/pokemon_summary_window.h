#ifndef GUARD_POKEMON_SUMMARY_WINDOW_H
#define GUARD_POKEMON_SUMMARY_WINDOW_H

#include "structs/str_pokemon.h"

enum MonSummarySubWindow
{
    SUB_WINDOW_NONE,
    SUB_WINDOW_STATUS,
    SUB_WINDOW_STATS,
    SUB_WINDOW_FEATURES,
    SUB_WINDOW_IQ,
    SUB_WINDOW_INFO,
};

#define MON_SUMMARY_UNK58_COUNT 12

// Size: R=0x64 | B=?
typedef struct MonSummaryInfo
{
    /* R=0x00 | B=0x00 */ s16 species;
    /* R=0x02 | B=0x02 */ u8 nameBuffer[20];
    /* R=0x16 | B=0x16 */ u8 types[2];
    /* R=0x18 | B=0x18 */ u8 abilities[2];
    /* R=0x1A | B=???? */ u8 fill1A[0x1C - 0x1A];
    /* R=0x1C | B=???? */ DungeonLocation dungeonLocation;
    /* R=0x20 | B=???? */ Item item;
    /* R=0x24 | B=???? */ s32 HP1;
    /* R=0x28 | B=???? */ s32 HP2;
    /* R=0x2C | B=???? */ s32 level;
    /* R=0x30 | B=???? */ u32 exp;
    /* R=0x34 | B=???? */ Offense offense;
    /* R=0x38 | B=???? */ bool8 isTeamLeader;
    /* R=0x39 | B=???? */ u8 atkBoost;
    /* R=0x3A | B=???? */ u8 spAtkBoost;
    /* R=0x3B | B=???? */ u8 defBoost;
    /* R=0x3C | B=???? */ u8 spDefBoost;
    /* R=0x3D | B=???? */ u8 fill3D;
    /* R=0x3E | B=???? */ s16 IQ;
    /* R=0x40 | B=???? */ s16 unk40;
    /* R=0x42 | B=???? */ s16 fill42;
    /* R=0x44 | B=???? */ unkPokeSubStruct_C unk44[2];
    /* R=0x4C | B=???? */ u8 evoStringId;
    /* R=0x4D | B=???? */ u8 fill4D[3];
    /* R=0x50 | B=???? */ IqSkillFlags IQSkills;
    /* R=0x54 | B=???? */ u8 tactic;
    /* R=0x55 | B=???? */ u8 fill55;
    /* R=0x56 | B=???? */ s16 unk56;
    /* R=0x58 | B=???? */ u8 unk58[MON_SUMMARY_UNK58_COUNT];
} MonSummaryInfo;

// Size: 0x30
typedef struct UnkInfoTabStruct
{
    u8 unk0[12];
    s32 unkC[9];
} UnkInfoTabStruct;

// which: See enum "MonSummarySubWindow"
void ShowPokemonSummaryWindow(s32 which, s32 currSubWindowId, MonSummaryInfo *monInfo, UnkInfoTabStruct *param_4, u32 windowId);
void SetMonSummaryInfo(MonSummaryInfo *dst, Pokemon *pokemon, bool8 unlockedEvolutions);

#endif // GUARD_POKEMON_SUMMARY_WINDOW_H
