#ifndef GUARD_STR_DUNGEON_8042F6C_H
#define GUARD_STR_DUNGEON_8042F6C_H

#include "structs/str_dungeon.h"
#include "structs/str_dungeon_location.h"
#include "structs/str_pokemon.h"
#include "structs/str_wonder_mail.h"

struct UnkStruct_xxx_dungeon_8042F6C
{
    u8 unk0;
    DungeonLocation unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    u8 unk10;
    u8 unk11;
    unkStruct_Dungeon64C unk14;
    PokemonStruct1 unk1C;
    u8 *unk74;
    Dungeon *unk78;
    s16 unk7C;
    u8 unk7E;
    DungeonLocation unk80;
    WonderMailSub unk84;
};

void xxx_dungeon_8042F6C(struct UnkStruct_xxx_dungeon_8042F6C *r8);

#endif // GUARD_STR_DUNGEON_8042F6C_H

