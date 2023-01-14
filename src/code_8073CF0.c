#include "global.h"
#include "dungeon_entity.h"

extern void sub_8067110(struct Entity *);
extern void sub_80671A0(struct Entity *);
extern void sub_8073D14(struct Entity *);

void sub_8073CF0(struct Entity *pokemon)
{
    sub_8067110(pokemon);
}

void sub_8073CFC(struct Entity *pokemon)
{
    sub_80671A0(pokemon);
}

void sub_8073D08(struct Entity *pokemon)
{
    sub_8073D14(pokemon);
}

