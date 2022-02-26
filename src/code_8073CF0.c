#include "global.h"
#include "dungeon_entity.h"

extern void sub_8067110(struct DungeonEntity *);
extern void sub_80671A0(struct DungeonEntity *);
extern void sub_8073D14(struct DungeonEntity *);

void sub_8073CF0(struct DungeonEntity *pokemon)
{
    sub_8067110(pokemon);
}

void sub_8073CFC(struct DungeonEntity *pokemon)
{
    sub_80671A0(pokemon);
}

void sub_8073D08(struct DungeonEntity *pokemon)
{
    sub_8073D14(pokemon);
}

