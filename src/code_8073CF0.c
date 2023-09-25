#include "global.h"
#include "structs/dungeon_entity.h"

extern void sub_8067110(Entity *);
extern void sub_80671A0(Entity *);
extern void sub_8073D14(Entity *);

void sub_8073CF0(Entity *pokemon)
{
    sub_8067110(pokemon);
}

void sub_8073CFC(Entity *pokemon)
{
    sub_80671A0(pokemon);
}

void sub_8073D08(Entity *pokemon)
{
    sub_8073D14(pokemon);
}

