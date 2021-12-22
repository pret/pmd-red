#ifndef POKEMON_MAIL_H
#define POKEMON_MAIL_H

struct PokemonMail
{
    const char *headline;
    const char *text;
};

#define NUM_POKEMON_MAIL 56

const char *GetPokemonMailHeadline(u8 index);
const char *GetPokemonMailText(u8 index);

#endif // POKEMON_MAIL_H
