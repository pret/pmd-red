#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern int sprintf(char *, const char *, ...);

extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gUnknown_8510000;
extern const char gUnknown_8107684;

//u8 sub_808DDD0(s16 r0)
//{
//    // Looks like this loads the dialogue sprite for the pokemon
//
//    // TODO stack is being added instead of being substracted
//    // Else this matches
//    char buffer[0xC];
//    if(gMonsterParameters[r0].dialogue_sprites != 0)
//    {
//        sprintf(buffer, &gUnknown_8107684);
//        OpenFileAndGetFileDataPtr(buffer, &gUnknown_8510000);
//        return;
//    }
//    return 0;
//}

bool8 sub_808DE10(s16 r0, s32 r1)
{
    // checking to see if dialogue sprite is available??
    return (gMonsterParameters[r0].dialogue_sprites >> r1) & 1;
}
