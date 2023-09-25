#ifndef POKEMON_MAIL_H
#define POKEMON_MAIL_H

struct PokemonMail
{
    const u8 *headline;
    const u8 *text;
};

#define NUM_POKEMON_MAIL 56

const u8 *GetPokemonMailHeadline(u8 index);
const u8 *GetPokemonMailText(u8 index);

#endif // POKEMON_MAIL_H
