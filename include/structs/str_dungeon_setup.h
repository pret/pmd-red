#ifndef GUARD_STR_DUNGEON_SETUP_H
#define GUARD_STR_DUNGEON_SETUP_H

#include "structs/str_dungeon.h"
#include "structs/str_dungeon_location.h"
#include "structs/str_dungeon_mail_seed.h"
#include "structs/str_pokemon.h"
#include "structs/str_wonder_mail.h"

// Apparently used in Dungeon and World Map SetUp Structs
typedef struct DungeonSetupSubstruct
{
    DungeonLocation unk0;
    u8 unk4;
    /* 0x5 */ bool8 canChangeLeader;
    /* 0x6 */ bool8 canRecruit;
    /* 0x7 */ bool8 canRecruitRescueTeamMazeBosses;
    /* 0x8 */ bool8 unlockedEvolutions;
    /* 0x9 */ bool8 hasInventory;
    u8 unkA;
    /* 0xB */ u8 missionKind; // See enum "DungeonMissionKind"
    u8 unkC;
    u8 unkD;
} DungeonSetupSubstruct;

typedef struct DungeonSetupInfo
{
    DungeonSetupSubstruct sub0; // TODO: find a better name
    DungeonMailSeed dungeonSeed;
    Pokemon mon;
    u8 *unk74;
    Dungeon *dungeon;
    s16 unk7C; // 4 = OutOnRescue related ... 5 = dungeon was skipped (quicksave read failed)
    u8 unk7E;
    DungeonLocation unk80;
    DungeonMailSeed unk84;
} DungeonSetupInfo;

typedef struct DungeonSetupStruct
{
    s32 unk0;
    DungeonSetupInfo info;
    u8 fill8C[44];
} DungeonSetupStruct;

#endif // GUARD_STR_DUNGEON_SETUP_H
