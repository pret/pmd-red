#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "code_809447C.h"
#include "constants/move.h"
#include "constants/move_id.h"
#include "pokemon.h"
#include "subStruct_203B240.h"

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
void CopyAndResetMoves(Move *, Move *);
void CopyBareMoveData(Move *, Move *);
bool8 DoesMoveCharge(u16 move);
bool8 FailsWhileMuzzled(u16 moveID);
const u8 *GetHMTMMoves(s16 species);
const u8 *GetLevelUpMoves(s16 species);
s32 GetLinkedSequence(s32, Move *, u16 *);
s32 GetMoveAccuracyOrAIChance(Move *move, u32 accuracyType);
u8 GetMoveAIWeight(Move *);
s32 GetMoveBasePower(Move *);
u32 GetMoveBasePP(Move *);
u32 GetMoveCritChance(Move *);
u32 GetMoveMaxUpgradeLevel(Move *);
u32 GetMoveNumberOfChainedHits(Move *);
s16 GetMoveTargetAndRange(Move *move, bool32 isAI);
u8 *GetMoveUseText(u16 moveID);
u8 GetMoveType(Move *);
void InitPokemonMove(Move *move, u16 moveID);
void InitZeroedPPPokemonMove(Move *move, u16 moveID);
bool8 IsAnyMoveLinked(s32, Move *);
bool8 IsMoveEnabled(s32 index, Move *moves);
bool8 IsMoveSet(s32 index, Move *moves);
bool8 IsNextMoveLinked(s32 index, Move *moves);
bool8 IsReflectedByMagicCoat(u16 moveID);
bool8 IsSoundMove(Move *);
void LoadWazaParameters(void);
bool8 MoveCannotHitFrozen(Move *);
bool8 MoveIgnoresTaunted(Move *);
void RemoveLinkSequenceFromMoves8(Move *, s32);
void RestorePokemonMoves(struct unkStruct_8094924 *, Move *);
void SavePokemonMoves(struct unkStruct_8094924 *, Move *);
bool8 ToggleMoveEnabled(s32 index, Move *moves);
bool8 ToggleSetMove(s32 index, Move *moves);
bool8 TryLinkMovesAfter(s32 index, Move *moves);
void unk_CopyMoves4To8(Move *, Move *);
void unk_CopyMoves4To8AndClearFlag2Unk4(Move *, Move *);
s32 unk_FindMoveEnabledForAIAfter4(Move *, s32);
s32 unk_FindMoveEnabledForAIAfter8(Move *, s32);
s32 unk_FindMoveEnabledForAIAfter8_v2(Move *, s32);
s32 unk_FindMoveEnabledForAIBefore8(Move *, s32);
s32 unk_FindMoveEnabledForAIBefore8_v2(Move *, s32);
void unk_FixLinkedMovesSetEnabled4(Move *);
void unk_FixLinkedMovesSetEnabled8(Move *);
void unk_FixLinkedMovesSetEnabled8_v2(Move *);
s32 unk_MoveIDPrintMoveDescription(s32, u16, s32, struct subStruct_203B240 **);
s32 unk_PrintMoveDescription(s32, Move *, s32, struct subStruct_203B240 **);
s32 unk_SetMoveToFirstInLinkedSequence4(Move *, s32);
s32 unk_SetMoveToFirstInLinkedSequence8_v2(Move *, s32);
s32 unk_SetMoveToLastInLinkedSequence4(Move *, s32);
s32 unk_SetMoveToLastInLinkedSequence8_v2(Move *, s32);
bool8 UnlinkMovesAfter(s32 index, Move *moves);
void UnSetMove(s32 index, Move *moves);

u8 sub_809287C(Move *);
void sub_80928A0(u8 *, Move *, const unkStruct_80928C0 *);
void sub_80928C0(u8 *, Move *, const unkStruct_80928C0 *);
void sub_8092AA8(Move *, u16);
void sub_8092C84(u8 *, u16);
s32 sub_8092DB8(Move *, s32);
s32 sub_8092F4C(Move *, s32);
bool8 sub_8093318(s32, Move *);
bool8 sub_809333C(s32, Move *);
s32 sub_80935B8(Move *, s32);
void sub_8094060(Move *, Move *);
void sub_8094184(struct unkStruct_8094924 *, struct unkStruct_8094184 *);
void sub_80941FC(struct unkStruct_8094924 *, struct unkStruct_8094184 *);

#endif // GUARD_MOVES_H
