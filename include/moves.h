#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "code_809447C.h"
#include "constants/move.h"
#include "constants/move_id.h"
#include "pokemon.h"
#include "subStruct_203B240.h"

// size: 0x8
struct MoveLearnset
{
    const u8 *levelUpMoves;
    const u8 *HMTMMoves;
};

// size: 0x8
struct MoveDataFile
{
    struct MoveDataEntry *moveData;
    struct MoveLearnset *moveLearnsets;
};

bool8 CanBeSnatched(u16);
void CopyAndResetMoves(struct Move *, struct Move *);
void CopyBareMoveData(struct Move *, struct Move *);
bool8 DoesMoveCharge(u16);
bool8 FailsWhileMuzzled(u16);
const u8 *GetHMTMMoves(s16);
const u8 *GetLevelUpMoves(s16);
s32 GetLinkedSequence(s32, struct Move *, u16 *);
s32 GetMoveAccuracyOrAIChance(struct Move *, u32);
u8 GetMoveAIWeight(struct Move *);
s32 GetMoveBasePower(struct Move *);
u32 GetMoveBasePP(struct Move *);
u32 GetMoveCritChance(struct Move *);
u32 GetMoveMaxUpgradeLevel(struct Move *);
u32 GetMoveNumberOfChainedHits(struct Move *);
s16 GetMoveTargetAndRange(struct Move *, bool32);
u8 *GetMoveUseText(u16);
u8 GetMoveType(struct Move *);
void InitPokemonMove(struct Move *, u16);
void InitZeroedPPPokemonMove(struct Move *, u16);
bool8 IsAnyMoveLinked(s32, struct Move *);
bool8 IsMoveEnabled(s32, struct Move *);
bool8 IsMoveSet(s32, struct Move *);
bool8 IsNextMoveLinked(s32, struct Move *);
bool8 IsReflectedByMagicCoat(u16);
bool8 IsSoundMove(struct Move *);
void LoadWazaParameters(void);
bool8 MoveCannotHitFrozen(struct Move *);
bool8 MoveIgnoresTaunted(struct Move *);
void RemoveLinkSequenceFromMoves8(struct Move *, s32);
void RestorePokemonMoves(struct unkStruct_8094924 *, struct Move *);
void SavePokemonMoves(struct unkStruct_8094924 *, struct Move *);
bool8 ToggleMoveEnabled(s32, struct Move *);
bool8 ToggleSetMove(s32, struct Move *);
bool8 TryLinkMovesAfter(s32, struct Move *);
void unk_CopyMoves4To8(struct Move *, struct Move *);
void unk_CopyMoves4To8AndClearFlag2Unk4(struct Move *, struct Move *);
s32 unk_FindMoveEnabledForAIAfter4(struct Move *, s32);
s32 unk_FindMoveEnabledForAIAfter8(struct Move *, s32);
s32 unk_FindMoveEnabledForAIAfter8_v2(struct Move *, s32);
s32 unk_FindMoveEnabledForAIBefore8(struct Move *, s32);
s32 unk_FindMoveEnabledForAIBefore8_v2(struct Move *, s32);
void unk_FixLinkedMovesSetEnabled4(struct Move *);
void unk_FixLinkedMovesSetEnabled8(struct Move *);
void unk_FixLinkedMovesSetEnabled8_v2(struct Move *);
s32 unk_MoveIDPrintMoveDescription(s32, u16, s32, struct subStruct_203B240 **);
s32 unk_PrintMoveDescription(s32, struct Move *, s32, struct subStruct_203B240 **);
s32 unk_SetMoveToFirstInLinkedSequence4(struct Move *, s32);
s32 unk_SetMoveToFirstInLinkedSequence8_v2(struct Move *, s32);
s32 unk_SetMoveToLastInLinkedSequence4(struct Move *, s32);
s32 unk_SetMoveToLastInLinkedSequence8_v2(struct Move *, s32);
bool8 UnlinkMovesAfter(s32, struct Move *);
void UnSetMove(s32, struct Move *);

u8 sub_809287C(struct Move *);
void sub_80928A0(u8 *, struct Move *, const struct unkStruct_80928C0 *);
void sub_80928C0(u8 *, struct Move *, const struct unkStruct_80928C0 *);
void sub_8092AA8(struct Move *, u16);
void sub_8092C84(u8 *, u16);
s32 sub_8092DB8(struct Move *, s32);
s32 sub_8092F4C(struct Move *, s32);
bool8 sub_8093318(s32, struct Move *);
bool8 sub_809333C(s32, struct Move *);
s32 sub_80935B8(struct Move *, s32);
void sub_8094060(struct Move *, struct Move *);
void sub_8094184(struct unkStruct_8094924 *, struct unkStruct_8094184 *);
void sub_80941FC(struct unkStruct_8094924 *, struct unkStruct_8094184 *);

#endif // GUARD_MOVES_H
