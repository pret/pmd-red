#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern int sprintf(char *, const char *, ...);

extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gUnknown_8510000;
extern const char gUnknown_8107684;

struct unkEvolve
{
    /* 0x0 */ struct EvolveStruct1 conditions;
    /* 0x4 */ struct EvolveNeeds needs;
};

#ifndef NONMATCHING
NAKED
#endif
void sub_808DD48(s16 r0, struct unkEvolve *r1)
{
#ifdef NONMATCHING
    struct EvolveStruct1 temp2;
    struct EvolveNeeds temp1;
    temp1 = gMonsterParameters[r0].need;
    temp2 = gMonsterParameters[r0].pre; // TODO should be using r2 but it uses r0
    r1->conditions = temp2;
    r1->needs = temp1;
#else
	asm_unified("\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tldr r2, _0808DD64\n"
	"\tldr r3, [r2]\n"
	"\tlsls r2, r0, 3\n"
	"\tadds r2, r0\n"
	"\tlsls r2, 3\n"
	"\tadds r2, r3\n"
	"\tldr r3, [r2, 0x38]\n"
	"\tldr r2, [r2, 0x34]\n"
	"\tstr r2, [r1]\n"
	"\tstr r3, [r1, 0x4]\n"
	"\tbx lr\n"
	"\t.align 2, 0\n"
"_0808DD64: .4byte gMonsterParameters");
#endif
}

u8 sub_808DD68(s16 r0, u32 r1)
{
    // Had to have this cast to match
    u32 temp;
    temp = r0;
    if (r1 != 0)
    {
        return 0xA;
    }
    else 
    {
        return gMonsterParameters[temp].overworld_sprite;
    }
}

#ifndef NONMATCHING
NAKED
#endif
struct OpenedFile *sub_808DD90(s16 r0)
{
#ifdef NONMATCHING
    // Looks like this loads the dialogue sprite for the pokemon

    // Two words: register memes... else it matches
    // Fix this and then one after matches too
    char buffer[0xC];
    if(gMonsterParameters[r0].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, &gUnknown_8107684);
    return OpenFile(buffer, &gUnknown_8510000);
#else
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0xC\n"
	"\tlsls r0, 16\n"
	"\tasrs r2, r0, 16\n"
	"\tldr r0, _0808DDBC\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 3\n"
	"\tadds r0, r2\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tldrh r0, [r0, 0x10]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808DDC8\n"
	"\tldr r1, _0808DDC0\n"
	"\tmov r0, sp\n"
	"\tbl sprintf\n"
	"\tldr r1, _0808DDC4\n"
	"\tmov r0, sp\n"
	"\tbl OpenFile\n"
	"\tb _0808DDCA\n"
	"\t.align 2, 0\n"
"_0808DDBC: .4byte gMonsterParameters\n"
"_0808DDC0: .4byte gUnknown_8107684\n"
"_0808DDC4: .4byte gUnknown_8510000\n"
"_0808DDC8:\n"
	"\tmovs r0, 0\n"
"_0808DDCA:\n"
	"\tadd sp, 0xC\n"
	"\tpop {r1}\n"
	"\tbx r1");
#endif
}

#ifndef NONMATCHING
NAKED
#endif
struct OpenedFile *sub_808DDD0(s16 r0)
{
#ifdef NONMATCHING
    // Looks like this loads the dialogue sprite for the pokemon

    // Two words: register memes... else it matches
    char buffer[0xC];
    if(gMonsterParameters[r0].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, &gUnknown_8107684);
    return OpenFileAndGetFileDataPtr(buffer, &gUnknown_8510000);
#else
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0xC\n"
	"\tlsls r0, 16\n"
	"\tasrs r2, r0, 16\n"
	"\tldr r0, _0808DDFC\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 3\n"
	"\tadds r0, r2\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tldrh r0, [r0, 0x10]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808DE08\n"
	"\tldr r1, _0808DE00\n"
	"\tmov r0, sp\n"
	"\tbl sprintf\n"
	"\tldr r1, _0808DE04\n"
	"\tmov r0, sp\n"
	"\tbl OpenFileAndGetFileDataPtr\n"
	"\tb _0808DE0A\n"
	"\t.align 2, 0\n"
        "_0808DDFC: .4byte gMonsterParameters\n"
        "_0808DE00: .4byte gUnknown_8107684\n"
        "_0808DE04: .4byte gUnknown_8510000\n"
        "_0808DE08:\n"
	"\tmovs r0, 0\n"
        "_0808DE0A:\n"
	"\tadd sp, 0xC\n"
	"\tpop {r1}\n"
	"\tbx r1");

#endif
}

bool8 sub_808DE10(s16 r0, s32 r1)
{
    // checking to see if dialogue sprite is available??
    return (gMonsterParameters[r0].dialogue_sprites >> r1) & 1;
}
