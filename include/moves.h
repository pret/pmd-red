#ifndef GUARD_MOVES_H
#define GUARD_MOVES_H

#include "constants/move.h"
#include "constants/move_id.h"

void LoadWazaParameters(void);
u8 sub_809287C(struct Move *move);
void InitPokemonMove(struct Move *move, u16 moveID);
void sub_8092AA8(struct Move *move, u16 moveID);
void InitZeroedPPPokemonMove(struct Move *move, u16 moveID);
s16 GetMoveTargetAndRange(struct Move *move, u32 isAI);
u8 GetMoveType(struct Move *move);
u8* GetLevelUpMoves(s16 species);
u8* GetHMTMMoves(s16 species);
u8 GetMoveAIWeight(struct Move *move);
u32 GetMoveNumberOfChainedHits(struct Move *move);
s32 GetMoveBasePower(struct Move *move);
s32 GetMoveAccuracyOrAIChance(struct Move *move, u32 accuracyType);
u32 GetMoveBasePP(struct Move *move);
u32 GetMoveMaxUpgradeLevel(struct Move *move);
u32 GetMoveCritChance(struct Move *move);
bool8 MoveCannotHitFrozen(struct Move *move);
bool8 MovesIgnoresTaunted(struct Move *move);
u32 GetMoveRangeID(struct Move *move);
void sub_8092C84(u8 *buffer, u16 moveID);
u8 *GetMoveUseText(u16 moveID);
bool8 IsReflectedByMagicCoat(u16 moveID);
bool8 CanBeSnatched(u16 moveID);
bool8 FailsWhileMuzzled(u16 moveID);
bool8 IsSoundMove(struct Move *move);
bool8 DoesMoveCharge(u16 move);

bool8 IsAnyMoveLinked(int unused, struct Move* moves);
bool8 IsNextMoveLinked(int index, struct Move* moves);
void RemoveLinkSequenceFromMoves8(struct Move* moves, int index);
int GetLinkedSequence(int index, struct Move* moves, u16* sequenceMoveIDs);
void unk_CopyMoves4To8(struct Move* destMoves, struct Move* srcMoves);
void sub_8094060(struct Move* srcMoves, struct Move* destMoves);

void unk_FixLinkedMovesSetEnabled8_v2(struct Move* move);

void sub_8092D54(u8 *buffer, struct Move *move);
extern void CopyAndResetMove(struct Move *, struct Move *);

void unk_GetLinkedSequences4(struct Move* moves, struct Move linkedSequences[4][4]);
void unk_LinkedSequencesToMoves4(struct Move* moves, struct Move linkedSequences[4][4]);
void unk_GetLinkedSequences8(struct Move* moves, struct Move linkedSequences[8][8]);
void unk_LinkedSequencesToMoves8(struct Move* moves, struct Move linkedSequences[8][8]);
void unk_GetLinkedSequences8_v2(struct Move* moves, struct Move linkedSequences[8][8]);
void unk_LinkedSequencesToMoves8_v2(struct Move* moves, struct Move linkedSequences[8][8]);

int unk_FindMarkedMoveInLinkedSequences44(struct Move linkedSequences[4][4]);
void unk_LinkedSequencesToMoves4(struct Move* moves, struct Move linkedSequences[4][4]);
int unk_FindMarkedMoveInLinkedSequences88(struct Move linkedSequences[8][8]);
void unk_LinkedSequencesToMoves8(struct Move* moves, struct Move linkedSequences[8][8]);
int unk_FindMarkedMoveInLinkedSequences88_v2(struct Move linkedSequences[8][8]);
void unk_LinkedSequencesToMoves8_v2(struct Move* moves, struct Move linkedSequences[8][8]);

bool8 IsMoveSet(int index, struct Move* struct_ptr);
bool8 IsMoveEnabled(int index, struct Move* struct_ptr);

#endif // GUARD_MOVES_H
