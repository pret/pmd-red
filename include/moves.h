#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "code_809447C.h"
#include "constants/move.h"
#include "constants/move_id.h"
#include "pokemon.h"
#include "structs/subStruct_203B240.h"

// size: 0x8
typedef struct MoveLearnset
{
    const u8 *levelUpMoves;
    const u8 *HMTMMoves;
} MoveLearnset;

// size: 0x8
typedef struct MoveDataFile
{
    MoveDataEntry *moveData;
    MoveLearnset *moveLearnsets;
} MoveDataFile;

bool8 CanBeSnatched(u16 moveID);
void CopyAndResetMoves(Moves *destMoves, Move *srcMoves);
void CopyBareMoveData(Move *destMoves, Move *srcMoves);
bool8 DoesMoveCharge(u16 move);
bool8 FailsWhileMuzzled(u16 moveID);
const u8 *GetHMTMMoves(s16 species);
const u8 *GetLevelUpMoves(s16 species);
s32 GetLinkedSequence(s32 index, Move *moves, u16 *sequenceMoveIDs);
s32 GetMoveAccuracyOrAIChance(Move *move, u32 accuracyType);
u8 GetMoveAIWeight(Move *move);
s32 GetMoveBasePower(Move *move);
u32 GetMoveBasePP(Move *move);
u32 GetMoveCritChance(Move *move);
u32 GetMoveMaxUpgradeLevel(Move *move);
u32 GetMoveNumberOfChainedHits(Move *move);
s16 GetMoveTargetAndRange(Move *move, bool32 isAI);
u8 *GetMoveUseText(u16 moveID);
u8 GetMoveType(Move *move);
void InitPokemonMove(Move *move, u16 moveID);
void InitZeroedPPPokemonMove(Move *move, u16 moveID);
bool8 IsAnyMoveLinked(s32 unused, Move *moves);
bool8 IsMoveEnabled(s32 index, Move *moves);
bool8 IsMoveSet(s32 index, Move *moves);
bool8 IsNextMoveLinked(s32 index, Move *moves);
bool8 IsReflectedByMagicCoat(u16 moveID);
bool8 IsSoundMove(Move *move);
void LoadWazaParameters(void);
bool8 MoveCannotHitFrozen(Move *move);
bool8 MoveIgnoresTaunted(Move *move);
void RemoveLinkSequenceFromMoves8(Move *moves, s32 index);
void ReadPoke1MovesBits(DataSerializer *, Move *moveSet);
void WritePoke1MovesBits(DataSerializer *, Move *moveSet);
bool8 ToggleMoveEnabled(s32 index, Move *moves);
bool8 ToggleSetMove(s32 index, Move *moves);
bool8 TryLinkMovesAfter(s32 index, Move *moves);
void unk_CopyMoves4To8(Move *destMoves, Move *srcMoves);
void unk_CopyMoves4To8AndClearFlag2Unk4(Move *destMoves, Move *srcMoves);
s32 unk_FindMoveEnabledForAIAfter4(Move *moves, s32 index);
s32 unk_FindMoveEnabledForAIAfter8(Move *moves, s32 index);
s32 unk_FindMoveEnabledForAIAfter8_v2(Move *moves, s32 index);
s32 unk_FindMoveEnabledForAIBefore8(Move *moves, s32 index);
s32 unk_FindMoveEnabledForAIBefore8_v2(Move *moves, s32 index);
void unk_FixLinkedMovesSetEnabled4(Move *moves);
void unk_FixLinkedMovesSetEnabled8(Move *moves);
void unk_FixLinkedMovesSetEnabled8_v2(Move *moves);
s32 unk_MoveIDPrintMoveDescription(s32, u16 moveID, s32, struct subStruct_203B240 **);
s32 unk_PrintMoveDescription(s32 x, Move *move, s32, struct subStruct_203B240 **);
s32 unk_SetMoveToFirstInLinkedSequence4(Move *moves, s32 index);
s32 unk_SetMoveToFirstInLinkedSequence8_v2(Move *moves, s32 index);
s32 unk_SetMoveToLastInLinkedSequence4(Move *moves, s32 index);
s32 unk_SetMoveToLastInLinkedSequence8_v2(Move *moves, s32 index);
bool8 UnlinkMovesAfter(s32 index, Move *moves);
void UnSetMove(s32 index, Move *moves);

u8 sub_809287C(Move *move);
void sub_80928A0(u8 *buffer, Move *move, const unkStruct_80928C0 *);
void BufferMoveName(u8 *buffer, Move *move, const unkStruct_80928C0 *);
void InitPokemonMoveOrNullObject(Move *move, u16 moveID);
void sub_8092C84(u8 *buffer, u16 moveID);
s32 sub_8092DB8(Move *moves, s32 index);
s32 sub_8092F4C(Move *moves, s32 index);
bool8 sub_8093318(s32, Move *moves);
bool8 sub_809333C(s32, Move *moves);
s32 sub_80935B8(Move *moves, s32 index);
void sub_8094060(Move *srcMoves, Move *destMoves);
void WritePoke2MovesBits(DataSerializer *, struct Moves *);
void ReadPoke2MovesBits(DataSerializer *, struct Moves *);

static inline bool8 MoveFlagExists(Move *move)
{
    return (move->moveFlags & MOVE_FLAG_EXISTS);
}

static inline bool8 MoveFlagSet(Move *move)
{
    return (move->moveFlags & MOVE_FLAG_SET);
}

static inline bool8 MoveFlagLastUsed(Move *move)
{
    return (move->moveFlags & MOVE_FLAG_LAST_USED);
}

static inline bool8 MoveFlagLinkChain(Move *move)
{
    return (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN);
}

static inline bool8 MoveFlagDisabled(Move *move)
{
    return (move->moveFlags & MOVE_FLAG_DISABLED);
}

static inline bool8 MoveFlagSealed(Move *move)
{
    return (move->moveFlags2 & MOVE_FLAG_SEALED);
}

#endif // GUARD_MOVES_H
