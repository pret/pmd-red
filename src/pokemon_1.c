#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern int sprintf(char *, const char *, ...);

extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gUnknown_8510000;
extern const char gUnknown_8107684;

#ifndef NONMATCHING
NAKED
#endif
// Pretty confided args are correct yet compiler disagrees
u8 sub_808DD68(s16 r0, u32 r1)
{
#ifdef NONMATCHING
    if (r1 != 0)
    {
        return 0xA;
    }
    else 
    {
        return gMonsterParameters[r0].overworld_sprite;
    }
#else
	asm_unified("\tpush {lr}\n"
	"\tlsls r0, 16\n"
	"\tasrs r2, r0, 16\n"
	"\tcmp r1, 0\n"
	"\tbne _0808DD88\n"
	"\tldr r0, _0808DD84\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 3\n"
	"\tadds r0, r2\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tldrb r0, [r0, 0x8]\n"
	"\tb _0808DD8A\n"
	"\t.align 2, 0\n"
"_0808DD84: .4byte gMonsterParameters\n"
"_0808DD88:\n"
	"\tmovs r0, 0xA\n"
"_0808DD8A:\n"
	"\tpop {r1}\n"
	"\tbx r1");

#endif
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
