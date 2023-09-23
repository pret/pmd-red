#include "global.h"
#include "pokemon_mail.h"

#include "data/pokemon_mail.h"

const u8 *GetPokemonMailHeadline(u8 index)
{
    return gPokemonMail[index].headline;
}

const u8 *GetPokemonMailText(u8 index)
{
    return gPokemonMail[index].text;
}
