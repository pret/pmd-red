#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "constants/move.h"
#include "constants/move_id.h"

void LoadWazaParameters(void);
u8 sub_809287C(struct PokemonMove *move);
void InitPokemonMove(struct PokemonMove *move, u16 moveID);
void sub_8092AA8(struct PokemonMove *move, u16 moveID);
void InitZeroedPPPokemonMove(struct PokemonMove *move, u16 moveID);
s16 GetMoveTargetingFlags(struct PokemonMove *move, u32 isAI);
u8 GetMoveType(struct PokemonMove *move);
u8 GetMoveWeight(struct PokemonMove *move);
u32 GetMoveHitCount(struct PokemonMove *move);
s32 GetMovePower(struct PokemonMove *move);
s32 GetMoveAccuracy(struct PokemonMove *move, u32 accuracyType);
u32 GetMoveMaxPP(struct PokemonMove *move);
u8 GetMoveUnk12(struct PokemonMove *move);
u8 GetMoveCriticalHitChance(struct PokemonMove *move);
bool8 MoveCannotHitFrozen(struct PokemonMove *move);
bool8 MoveDealsDirectDamage(struct PokemonMove *move);
u32 GetMoveRangeType(struct PokemonMove *move);
void sub_8092C84(u8 *buffer, u16 moveID);
u8 *GetMoveUseText(u16 moveID);
bool8 MoveAffectedByMagicCoat(u16 moveID);
bool8 MoveTargetsUser(u16 moveID);
bool8 MoveAffectedByMuzzled(u16 moveID);
bool8 IsBlockedBySoundproof(struct PokemonMove *move);
bool8 DoesMoveCharge(u16 move);

#endif // GUARD_MOVES_H
