#ifndef GUARD_STR_SPAWN_POKEMON_DATA_H
#define GUARD_STR_SPAWN_POKEMON_DATA_H

#define PACKED_BITS_SPECIES 0x1FF
#define PACKED_BITS_LEVEL 0x7F
#define PACKED_BITS_LEVEL_SHIFT 9

// size: R=0x8 | B=0x6
typedef struct SpawnPokemonData
{
    u16 bits; // species first 9 bits, level last 7 bits
    s16 randNum[2];
} SpawnPokemonData;

#endif // GUARD_STR_SPAWN_POKEMON_DATA_H
