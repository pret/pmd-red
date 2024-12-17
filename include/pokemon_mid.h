#ifndef GUARD_POKEMON_MID_H
#define GUARD_POKEMON_MID_H

#include "pokemon.h"

// NOTE: this is kept separate since TransferOrbAction needs index to be s32
// and I haven't had the time to fix matching
void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index);

#endif // GUARD_POKEMON_MID_H
