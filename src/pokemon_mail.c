#include "global.h"

struct Pokemon_Mail
{
    char *headline;
    char *text;
};

extern struct Pokemon_Mail gPokemonMail[];

char *GetPokemonMailHeadline(u8 index)
{
    return gPokemonMail[index].headline;
}


char *GetPokemonMailText(u8 index)
{
    return gPokemonMail[index].text;
}
