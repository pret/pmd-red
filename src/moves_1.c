#include "global.h"
#include "code_8092334.h"
#include "moves.h"
#include "pokemon.h"

void SavePokemonMove(struct unkStruct_8094924 *r0, struct PokemonMove *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->moveID, 9);
    SaveIntegerBits(r0, &move->PP, 7);
}

void RestorePokemonMove(struct unkStruct_8094924 *r0, struct PokemonMove *move)
{
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->moveID, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
}

void SavePokemonMoves(struct unkStruct_8094924 *r0, struct PokemonMove *moveSet)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        SavePokemonMove(r0, &moveSet[iVar4]);
    }
}

void RestorePokemonMoves(struct unkStruct_8094924 *r0, struct PokemonMove *moveSet)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        RestorePokemonMove(r0, &moveSet[iVar4]);
    }
}

void sub_8094148(struct unkStruct_8094924 *r0, struct PokemonMove *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->moveFlags2, 1);
    SaveIntegerBits(r0, &move->moveID, 9);
    SaveIntegerBits(r0, &move->PP, 7);
    SaveIntegerBits(r0, &move->powerBoost, 7);
}

void sub_8094184(struct unkStruct_8094924 *r0, struct unkStruct_8094184 *r1)
{
    s32 r4;

    for(r4 = 0; r4 < MAX_MON_MOVES; r4++)
    {
        sub_8094148(r0, &r1->moves[r4]);
    }
    SaveIntegerBits(r0, &r1->unk20, 8);
}

void sub_80941B0(struct unkStruct_8094924 *r0, struct PokemonMove *move)
{
    memset(move, 0, sizeof(struct PokemonMove));
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->moveFlags2, 1);
    RestoreIntegerBits(r0, &move->moveID, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
    RestoreIntegerBits(r0, &move->powerBoost, 7);
}

void sub_80941FC(struct unkStruct_8094924 *r0, struct unkStruct_8094184 *r1)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        sub_80941B0(r0, &r1->moves[iVar4]);
    }
    r1->unk20 = 0;
    RestoreIntegerBits(r0, &r1->unk20, 8);
}

bool8 DoesMoveCharge(u16 move)
{
    if(move == MOVE_SOLARBEAM)
        return TRUE;
    if(move == MOVE_SKY_ATTACK)
        return TRUE;
    if(move == MOVE_RAZOR_WIND)
        return TRUE;
    if(move == MOVE_FOCUS_PUNCH)
        return TRUE;
    if(move == MOVE_SKULL_BASH)
        return TRUE;
    if(move == MOVE_FLY)
        return TRUE;
    if(move == MOVE_BOUNCE)
        return TRUE;
    if(move == MOVE_DIVE)
        return TRUE;
    if(move == MOVE_DIG)
        return TRUE;
    return FALSE;
}
