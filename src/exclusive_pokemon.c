#include "global.h"
#define NUM_EXCLUSIVE_POKEMON 12

struct ExclusivePokemon
{
    u16 poke_id;
    bool8 in_rrt; // red rescue team
    bool8 in_brt; // blue rescue team
};
extern struct ExclusivePokemon gExclusivePokemon[];

struct unkStruct_203B498
{
    u8 fill0[0x58];
    bool8 Exclusives[NUM_EXCLUSIVE_POKEMON];
};
extern struct unkStruct_203B498 *gUnknown_203B498;
extern struct unkStruct_203B498 gUnknown_2039840;


void LoadExclusivePokemon(void)
{
    gUnknown_203B498 = &gUnknown_2039840;
}

struct unkStruct_203B498 *GetExclusivePokemon(void)
{
    return &gUnknown_2039840;
}

void InitializeExclusivePokemon(void)
{
    s32 counter;
    memset(gUnknown_203B498, 0, sizeof(struct unkStruct_203B498));
    for(counter = 0; counter < NUM_EXCLUSIVE_POKEMON; counter++)
    {
        gUnknown_203B498->Exclusives[counter] = gExclusivePokemon[counter].in_rrt;
    }
}
