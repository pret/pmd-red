#include "global.h"
#define NUM_EXCLUSIVE_POKEMON 12

struct ExclusivePokemon
{
    u16 poke_id;
    bool8 in_rrt; // red rescue team
    bool8 in_brt; // blue rescue team
};
extern struct ExclusivePokemon gExclusivePokemon[];

extern u8 gUnknown_810ACC0[];
extern u8 *gUnknown_203B498;
extern u8 gUnknown_2039840;

bool8 sub_8097F40(u32 r0)
{
    return gUnknown_810ACC0[r0] == 2;
}

void sub_8097F5C(void)
{
    gUnknown_203B498 = &gUnknown_2039840;
}

u8 *sub_8097F6C(void)
{
    return &gUnknown_2039840;
}

#ifdef NONMATCHING
void sub_8097F74(void)
{
    s32 counter;
    memset(gUnknown_203B498, 0, 0x64);
    for(counter = 0; counter < NUM_EXCLUSIVE_POKEMON; counter++)
    {
        // TODO fix switching of addition statements (when it figures out the index)
        gUnknown_203B498[counter + 0x58] = gExclusivePokemon[counter].in_rrt;
    }
}
#else
NAKED
void sub_8097F74(void)
{
	asm_unified("\tpush {r4,lr}\n"
	"\tldr r4, _08097FA0\n"
	"\tldr r0, [r4]\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0x64\n"
	"\tbl memset\n"
	"\tmovs r2, 0\n"
	"\tldr r3, _08097FA4\n"
"_08097F86:\n"
	"\tldr r0, [r4]\n"
	"\tadds r0, 0x58\n"
	"\tadds r0, r2\n"
	"\tldrb r1, [r3, 0x2]\n"
	"\tstrb r1, [r0]\n"
	"\tadds r3, 0x4\n"
	"\tadds r2, 0x1\n"
	"\tcmp r2, 0xB\n"
	"\tble _08097F86\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08097FA0: .4byte gUnknown_203B498\n"
"_08097FA4: .4byte gExclusivePokemon");

}
#endif
