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
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
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
    s16 unk7C; // Set to 5 if the dungeon was skipped (quicksave read failed)
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
