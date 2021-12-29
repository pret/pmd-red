#include "global.h"
#include "pokemon_mail.h"
#include "data/pokemon_mail.h"

const char *GetPokemonMailHeadline(u8 index)
{
    return gPokemonMail[index].headline;
}

const char *GetPokemonMailText(u8 index)
{
    return gPokemonMail[index].text;
}
