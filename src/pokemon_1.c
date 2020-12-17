#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern int sprintf(char *, const char *, ...);

extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gUnknown_8510000;
extern const char gUnknown_8107684[];

struct unkEvolve
{
    /* 0x0 */ struct EvolveStruct1 conditions;
    /* 0x4 */ struct EvolveNeeds needs;
};

s16 sub_808DD48(s16 r0, struct unkEvolve *r1)
{
    struct EvolveStruct1 temp2;
    struct EvolveNeeds temp1;
    temp1 = gMonsterParameters[r0].need;
    temp2 = gMonsterParameters[r0].pre;
    r1->conditions = temp2;
    r1->needs = temp1;
    // The return value is not used anywhere, but necessary for the function to match.
    return r0;
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

struct OpenedFile *sub_808DD90(s16 r0)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[r0].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, gUnknown_8107684, r0); // "kao%03d"
    return OpenFile(buffer, &gUnknown_8510000);
}

struct OpenedFile *sub_808DDD0(s16 r0)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[r0].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, gUnknown_8107684, r0); // "kao%03d"
    return OpenFileAndGetFileDataPtr(buffer, &gUnknown_8510000);
}

bool8 sub_808DE10(s16 r0, s32 r1)
{
    // checking to see if dialogue sprite is available??
    return (gMonsterParameters[r0].dialogue_sprites >> r1) & 1;
}
