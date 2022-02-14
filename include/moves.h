#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "constants/move.h"

// 0x92A88
void InitPokemonMove(struct PokemonMove *move, u16 moveID);
// 0x92AE0
s16 GetMoveTargetingFlags(struct PokemonMove *move, u32 isAI);
// 0x92B90
u8 GetMoveWeight(struct PokemonMove *move);
// 0x92BF4
u32 GetMoveMaxPP(struct PokemonMove *move);
// 0x92C54
bool8 GetMoveDealsDirectDamage(struct PokemonMove *move);

#endif
