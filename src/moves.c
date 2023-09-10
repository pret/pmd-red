#include "global.h"
#include "code_800D090.h"
#include "code_80130A8.h"
#include "code_8092334.h"
#include "constants/colors.h"
#include "constants/monster.h"
#include "memory.h"
#include "moves.h"
#include "text_util.h"
#include "text2.h"

static EWRAM_DATA OpenedFile *sWazaParametersFile = {0};
static EWRAM_DATA MoveDataEntry *sMovesData = {0};
static EWRAM_DATA MoveLearnset *sMoveLearnsets = {0}; // 420 entries, aka (MONSTER_DEOXYS_SPEED + 1), aka (MONSTER_MUNCHLAX)

// ???
extern u32 gUnknown_202DE30;
extern u8 gAvailablePokemonNames[]; // 202DF98

// data_8107010.s
extern const unkStruct_80928C0 gUnknown_81098C4;
extern const u8 gUnknown_81098D0[];
extern const u8 gUnknown_81098DC[];
extern const u8 gUnknown_81098E0[];
extern const u8 gUnknown_81098EC[];
extern const u8 gUnknown_8109908[];
extern const u8 gUnknown_810990C[];
extern const u8 gUnknown_8109910[];
extern const u8 gUnknown_8109928[];
extern const u8 gUnknown_810992B;
extern const u8 gUnknown_810992C[];
extern const u8 gUnknown_8109930[];

// data_810AE24.s
extern const u8* gPtrTypeText;  // "Type"
extern const u8 *gRangeNames[];
extern const u8* gUnknown_810CF00; // "Range#=@.$m0 "

// system_sbin.s
extern const struct FileArchive gSystemFileArchive;

// code_8097DD0.s
extern u32 sub_8097DF0(u8 *, struct subStruct_203B240 **);

static void CopyAndResetMove(Move *, Move *);
static bool8 sub_80933D8(s32, Move *);
static s32 unk_FindMarkedMoveInLinkedSequences44(Move [MAX_MON_MOVES][MAX_MON_MOVES]);
static s32 unk_FindMarkedMoveInLinkedSequences88(Move [8][8]);
static s32 unk_FindMarkedMoveInLinkedSequences88_v2(Move [8][8]);
static void unk_GetLinkedSequences4(Move *, Move [MAX_MON_MOVES][MAX_MON_MOVES]);
static void unk_GetLinkedSequences8(Move *, Move [8][8]);
static void unk_GetLinkedSequences8_v2(Move *, Move [8][8]);
static void unk_LinkedSequencesToMoves4(Move *, Move [MAX_MON_MOVES][MAX_MON_MOVES]);
static void unk_LinkedSequencesToMoves8(Move *, Move [8][8]);
static void unk_LinkedSequencesToMoves8_v2(Move *, Move [8][8]);
static void unk_MovePrintData(Move *, s32);

void LoadWazaParameters(void)
{
    sWazaParametersFile = OpenFileAndGetFileDataPtr(gUnknown_81098D0, &gSystemFileArchive);

    sMovesData = ((MoveDataFile *)(sWazaParametersFile->data))->moveData;
    sMoveLearnsets = ((MoveDataFile *)(sWazaParametersFile->data))->moveLearnsets;
}

u8 sub_809287C(Move *move)
{
    if (move->moveFlags & MOVE_FLAG_DISABLED)
        return 50;
    if (!(move->moveFlags2 & MOVE_FLAG_SEALED))
        return 52;
    return 50;
}

void sub_80928A0(u8 *buffer, Move *move, const unkStruct_80928C0 *a2)
{
    Move stack;
    CopyAndResetMove(&stack, move);
    sub_80928C0(buffer, &stack, a2);
}

void sub_80928C0(u8 *buffer, Move *move, const unkStruct_80928C0 *param_3)
{
    u32 uVar2;
    u32 basePP;
    u8 localBuffer[12];

    uVar2 = sub_809287C(move);

    if (param_3 == NULL)
        param_3 = &gUnknown_81098C4;

    if (move->ginseng != 0)
        sprintfStatic(localBuffer, gUnknown_81098DC, move->ginseng); // %+d
    else
        localBuffer[0] = '\0';

    if (param_3->unk8 != 0)
        uVar2 = 2;
    if (param_3->unk9 != 0 && DoesMoveCharge(move->id))
        uVar2 = 2;

    switch (param_3->unk0) {
        case 0:
            sprintfStatic(buffer, gUnknown_81098E0,
                uVar2, sMovesData[move->id].name, localBuffer);
            break;
        case 1:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, gUnknown_81098EC,
                uVar2, move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                sMovesData[move->id].name, localBuffer, param_3->unk4, move->PP, basePP);
            break;
        case 2:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, gUnknown_8109910,
                uVar2, move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                sMovesData[move->id].name, localBuffer, param_3->unk4, move->PP, basePP);
            break;
        case 3:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, gUnknown_81098EC,
                uVar2, move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? gUnknown_8109928 : gUnknown_810990C,
                sMovesData[move->id].name, localBuffer, param_3->unk4, move->PP, basePP);
            break;
        case 4:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, gUnknown_8109910,
                uVar2, move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? gUnknown_8109928 : gUnknown_810990C,
                sMovesData[move->id].name, localBuffer, param_3->unk4, move->PP, basePP);
            break;
    }
}

void InitPokemonMove(Move *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
    move->moveFlags2 = 0;
    move->id = moveID;
    move->PP = GetMoveBasePP(move);
    move->ginseng = 0;
}

void sub_8092AA8(Move *move, u16 moveID)
{
    if (moveID == 0)
        move->moveFlags = 0;
    else {
        move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
        move->moveFlags2 = 0;
        move->id = moveID;
        move->PP = GetMoveBasePP(move);
        move->ginseng = 0;
    }
}

void InitZeroedPPPokemonMove(Move *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
    move->id = moveID;
    move->PP = 0;
}

s16 GetMoveTargetAndRange(Move *move, bool32 isAI)
{
    return sMovesData[move->id].targetingFlags[isAI];
}

u8 GetMoveType(Move *move)
{
    return sMovesData[move->id].type;
}

const u8 *GetLevelUpMoves(s16 species)
{
#ifndef NONMATCHING
    register s32 species1 asm("r1"), species2;
#else
    s32 species1, species2;
#endif

    species1 = species;
    species2 = species1;
    if (species1 == MONSTER_DECOY || species1 == MONSTER_NONE)
        return &gUnknown_810992B;

    if (species2 == MONSTER_MUNCHLAX)
        return &gUnknown_810992B;

    return sMoveLearnsets[species2].levelUpMoves;
}

const u8 *GetHMTMMoves(s16 species)
{
#ifndef NONMATCHING
    register s32 species1 asm("r1"), species2;
#else
    s32 species1, species2;
#endif

    species1 = species;
    species2 = species1;
    if (species1 == MONSTER_DECOY || species1 == MONSTER_NONE)
        return &gUnknown_810992B;

    if (species2 == MONSTER_MUNCHLAX)
        return &gUnknown_810992B;

    return sMoveLearnsets[species2].HMTMMoves;
}

u8 GetMoveAIWeight(Move *move)
{
    return sMovesData[move->id].aiWeight;
}

u32 GetMoveNumberOfChainedHits(Move *move)
{
    return sMovesData[move->id].numberOfChainedHits;
}

s32 GetMoveBasePower(Move *move)
{
    return sMovesData[move->id].basePower;
}

s32 GetMoveAccuracyOrAIChance(Move *move, u32 accuracyType)
{
    return sMovesData[move->id].accuracy[accuracyType];
}

u32 GetMoveBasePP(Move *move)
{
    return sMovesData[move->id].basePP;
}

u32 GetMoveMaxUpgradeLevel(Move *move)
{
    return sMovesData[move->id].maxUpgradeLevel;
}

u32 GetMoveCritChance(Move *move)
{
    return sMovesData[move->id].critChance;
}

bool8 MoveCannotHitFrozen(Move *move)
{
    return sMovesData[move->id].cannotHitFrozen;
}

bool8 MoveIgnoresTaunted(Move *move)
{
    return sMovesData[move->id].ignoresTaunted;
}

static u32 GetMoveRangeID(Move *move)
{
    return sMovesData[move->id].rangeID;
}

void sub_8092C84(u8 *buffer, u16 moveID)
{
    Move stack;
    InitPokemonMove(&stack, moveID);
    sub_80928C0(buffer, &stack, NULL);
}

u8 *GetMoveUseText(u16 moveID)
{
    return sMovesData[moveID].useText;
}

bool8 IsReflectedByMagicCoat(u16 moveID)
{
    return sMovesData[moveID].affectedByMagicCoat;
}

bool8 CanBeSnatched(u16 moveID)
{
    return sMovesData[moveID].isSnatchable;
}

bool8 FailsWhileMuzzled(u16 moveID)
{
    return sMovesData[moveID].usesMouth;
}

bool8 IsSoundMove(Move *move)
{
    if (move->id == MOVE_GROWL) return TRUE;
    if (move->id == MOVE_ROAR) return TRUE;
    if (move->id == MOVE_METAL_SOUND) return TRUE;
    if (move->id == MOVE_SING) return TRUE;
    if (move->id == MOVE_GRASSWHISTLE) return TRUE;
    if (move->id == MOVE_SUPERSONIC) return TRUE;
    if (move->id == MOVE_PERISH_SONG) return TRUE;
    if (move->id == MOVE_SCREECH) return TRUE;
    if (move->id == MOVE_HYPER_VOICE) return TRUE;
    if (move->id == MOVE_SNORE) return TRUE;
    if (move->id == MOVE_HEAL_BELL) return TRUE;

    return FALSE;
}

static void sub_8092D54(u8 *buffer, Move *move)
{
    sprintfStatic(buffer, gUnknown_810992C, gRangeNames[GetMoveRangeID(move)]);
}

// this function is the same as the two after the next one
// except this one is for 4, and the other 2 for 8 and 8_v2
s32 unk_FindMoveEnabledForAIAfter4(Move *moves, s32 index)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        u8 flag;

        if (++index == MAX_MON_MOVES)
            return 0;

        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1))
            return index;
    }

    return 0;
}

s32 sub_8092DB8(Move *moves, s32 index)
{
    s32 i, j;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        u8 flag;
        
        if (--index < 0) {
            for (j = MAX_MON_MOVES - 1; j >= 0; j--) {
                if (!(moves[j].moveFlags & MOVE_FLAG_EXISTS)) {
                    continue;
                }

                index = j;
                break;
            }

            // return 0 if loop ends without setting index
            if (j < 0)
                return 0;
        }

        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1))
            return index;
    }

    return 0;
}

s32 unk_FindMoveEnabledForAIAfter8(Move *moves, s32 index)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        u8 flag;
        
        if (++index == 8)
            return 0;

        if (!(moves[index].moveFlags & 1))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1))
            return index;
    }

    return 0;
}

s32 unk_FindMoveEnabledForAIAfter8_v2(Move *moves, s32 index)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        u8 flag;

        if (++index == 8)
            return 0;

        if (!(moves[index].moveFlags & 1))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1))
            return index;
    }

    return 0;
}

// the next 2 functions are the same
// should be 8 and 8_v2
s32 unk_FindMoveEnabledForAIBefore8(Move *moves, s32 index)
{
    s32 i, j;

    for (i = 0; i < 8; i++) {
        u8 flag;

        if (--index < 0) {
            for (j = 7; j > 0; j--) {
                if (!(moves[j].moveFlags & MOVE_FLAG_EXISTS))
                    continue;

                // checks MOVE_FLAG_ENABLED_FOR_AI
                flag = (moves[j].moveFlags >> 1);
                if (!(flag & 1))
                    return j;
            }
            return 0;
        }

        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1))
            return index;
    }

    return 0;
}

s32 unk_FindMoveEnabledForAIBefore8_v2(Move *moves, s32 index)
{
    s32 i, j;

    for (i = 0; i < 8; i++) {
        u8 flag;

        if (--index < 0) {
            for (j = 7; j > 0; j--) {
                if (!(moves[j].moveFlags & MOVE_FLAG_EXISTS))
                    continue;

                // checks MOVE_FLAG_ENABLED_FOR_AI
                flag = (moves[j].moveFlags >> 1);
                if (!(flag & 1))
                    return j;
            }
            return 0;
        }

        if (!(moves[index].moveFlags & MOVE_FLAG_EXISTS))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (moves[index].moveFlags >> 1);
        if (!(flag & 1))
            return index;
    }

    return 0;
}

s32 sub_8092F4C(Move *moves, s32 index)
{
    s32 i;

    for (i = index; i > 0; i--) {
        Move* move = &moves[i];
        u8 flag;

        if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            return 0;

        // checks MOVE_FLAG_ENABLED_FOR_AI
        flag = (move->moveFlags >> 1);
        if (!(flag & 1))
            return i;
    }

    return 0;
}

// the next 3 functions are the same, except the first
// is for 4, then for 8 then for 8_v2
s32 unk_SetMoveToLastInLinkedSequence4(Move *moves, s32 index)
{
    Move* move;
    Move linkedSequence[4][4];
    s32 startIndex;
    s32 result;
    s32 i;

    result = index;

    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences4(moves, linkedSequence);

    startIndex = unk_FindMarkedMoveInLinkedSequences44(linkedSequence);
    if (startIndex >= 0 && startIndex < 3) {
        for (i = 0; i < 4; i++) {
            const Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[startIndex + 1][i];
            linkedSequence[startIndex + 1][i] = temp;
        }
    }

    unk_LinkedSequencesToMoves4(moves, linkedSequence);
    for (startIndex = 0; startIndex < 4; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }

    return result;
}

UNUSED static s32 unk_SetMoveToLastInLinkedSequence8(Move *moves, s32 index)
{
    Move* move;
    Move linkedSequence[8][8];
    s32 startIndex;
    s32 result;
    s32 i;

    result = index;

    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8(moves, linkedSequence);

    startIndex = unk_FindMarkedMoveInLinkedSequences88(linkedSequence);
    if (startIndex >= 0 && startIndex < 7) {
        for (i = 0; i < 8; i++) {
            const Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[startIndex + 1][i];
            linkedSequence[startIndex + 1][i] = temp;
        }
    }

    unk_LinkedSequencesToMoves8(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }

    return result;
}

s32 unk_SetMoveToLastInLinkedSequence8_v2(Move *moves, s32 index)
{
    Move* move;
    Move linkedSequence[8][8];
    s32 startIndex;
    s32 result;
    s32 i;

    result = index;

    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8_v2(moves, linkedSequence);

    startIndex = unk_FindMarkedMoveInLinkedSequences88_v2(linkedSequence);
    if (startIndex >= 0 && startIndex < 7) {
        for (i = 0; i < 8; i++) {
            const Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[startIndex + 1][i];
            linkedSequence[startIndex + 1][i] = temp;
        }
    }

    unk_LinkedSequencesToMoves8_v2(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }

    return result;
}

// the next 3 functions are the same, but for
// 4, 8 and 8_v2
s32 unk_SetMoveToFirstInLinkedSequence4(Move *moves, s32 index)
{
    Move* move;
    Move linkedSequence[4][4];
    s32 startIndex, prevIndex;
    s32 result;
    s32 i;

    result = index;

    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences4(moves, linkedSequence);

    startIndex = unk_FindMarkedMoveInLinkedSequences44(linkedSequence);
    prevIndex = startIndex - 1;
    if (prevIndex >= 0 && prevIndex < 3) {
        for (i = 0; i < 4; i++) {
            const Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[prevIndex][i];
            linkedSequence[prevIndex][i] = temp;
        }
    }

    unk_LinkedSequencesToMoves4(moves, linkedSequence);
    for (startIndex = 0; startIndex < 4; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }

    return result;
}

UNUSED static s32 unk_SetMoveToFirstInLinkedSequence8(Move *moves, s32 index)
{
    Move* move;
    Move linkedSequence[8][8];
    s32 startIndex, prevIndex;
    int result;
    int i;

    result = index;

    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8(moves, linkedSequence);

    startIndex = unk_FindMarkedMoveInLinkedSequences88(linkedSequence);
    prevIndex = startIndex - 1;
    if (prevIndex >= 0 && prevIndex < 7) {
        for (i = 0; i < 8; i++) {
            const Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[prevIndex][i];
            linkedSequence[prevIndex][i] = temp;
        }
    }

    unk_LinkedSequencesToMoves8(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }

    return result;
}

s32 unk_SetMoveToFirstInLinkedSequence8_v2(Move *moves, s32 index)
{
    Move* move;
    Move linkedSequence[8][8];
    s32 startIndex, prevIndex;
    s32 result;
    s32 i;

    result = index;

    move = &moves[index];
    move->moveFlags |= MOVE_FLAG_INTERNAL_MARKER;
    unk_GetLinkedSequences8_v2(moves, linkedSequence);

    startIndex = unk_FindMarkedMoveInLinkedSequences88_v2(linkedSequence);
    prevIndex = startIndex - 1;
    if (prevIndex >= 0 && prevIndex < 7) {
        for (i = 0; i < 8; i++) {
            const Move temp = linkedSequence[startIndex][i];
            linkedSequence[startIndex][i] = linkedSequence[prevIndex][i];
            linkedSequence[prevIndex][i] = temp;
        }
    }

    unk_LinkedSequencesToMoves8_v2(moves, linkedSequence);
    for (startIndex = 0; startIndex < 8; startIndex++) {
        if (moves[startIndex].moveFlags & MOVE_FLAG_INTERNAL_MARKER) {
            moves[startIndex].moveFlags &= ~MOVE_FLAG_INTERNAL_MARKER;
            result = startIndex;
            break;
        }
    }

    return result;
}

bool8 IsMoveSet(s32 index, Move *moves)
{
    if (moves[index].moveFlags & MOVE_FLAG_SET)
        return TRUE;
    return FALSE;
}

bool8 IsMoveEnabled(s32 index, Move *moves)
{
    if (moves[index].moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
        return TRUE;
    return FALSE;
}

bool8 sub_8093318(s32 param_1, Move *moves)
{
    Move dest_struct[MAX_MON_MOVES * 2];
    MemoryCopy8((void *)dest_struct, (void *)moves, sizeof(Move) * MAX_MON_MOVES * 2);
    return TryLinkMovesAfter(param_1, dest_struct);
}

bool8 sub_809333C(s32 param_1, Move *moves)
{
    Move dest_struct[MAX_MON_MOVES * 2];
    MemoryCopy8((void *)dest_struct, (void *)moves, sizeof(Move) * MAX_MON_MOVES * 2);
    return UnlinkMovesAfter(param_1, dest_struct);
}

UNUSED static bool8 sub_8093360(s32 param_1, Move *moves)
{
    Move dest_struct[MAX_MON_MOVES * 2];
    MemoryCopy8((void *)dest_struct, (void *)moves, sizeof(Move) * MAX_MON_MOVES * 2);
    return sub_80933D8(param_1, dest_struct);
}

UNUSED static bool8 IsMoveNotSet(s32 index, Move* moves)
{
    if (moves[index].moveFlags & MOVE_FLAG_SET)
        return FALSE;
    return TRUE;
}

bool8 IsAnyMoveLinked(s32 unused, Move *moves)
{
    s32 i;
    s32 counter;

    counter = 0;

    for (i = 0; i < 8; i++) {
        if ((moves[i].moveFlags & MOVE_FLAG_EXISTS) && !(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            counter++;
    }

    if (counter > 1)
        return TRUE;
    return FALSE;
}

static bool8 sub_80933D8(s32 param_1, Move *src_struct)
{
    if (TryLinkMovesAfter(param_1, src_struct))
        return TRUE;

    return UnlinkMovesAfter(param_1, src_struct);
}

bool8 TryLinkMovesAfter(s32 index, Move *moves)
{
    s32 i;
    const Move *move = &moves[index];

    if (DoesMoveCharge(move->id))
        return FALSE;

    for (i = index + 1; i < 8; i++) {
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS))
            return FALSE;

        if (DoesMoveCharge(moves[i].id))
            return FALSE;

        if (!(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moves[i].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            unk_FixLinkedMovesSetEnabled8_v2(moves);
            return TRUE;
        }
    }

    return FALSE;
}

bool8 UnlinkMovesAfter(s32 index, Move *moves)
{
    s32 i;
    bool8 result = FALSE;
    s32 r4;

    for (i = index + 1, r4 = 0; r4 < 8 && i < 8; i++, r4++) {
        if (!(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            goto label; // for some reason we can't use break here

        moves[i].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
        result = TRUE;
    }
label:
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return result;
}

bool8 IsNextMoveLinked(s32 index, Move *moves)
{
    Move *move;

    if (index + 1 >= MAX_MON_MOVES * 2)
        return FALSE;

    move = &moves[index + 1];

    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
        return FALSE;

    if (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)
        return TRUE;

    return FALSE;
}

bool8 ToggleSetMove(s32 index, Move *moves)
{
    Move* move;
    u8 flags;
    s32 i;

    move = &moves[index];

    if (moves[index].moveFlags & MOVE_FLAG_SET)
        flags = move->moveFlags & ~MOVE_FLAG_SET;
    else {
        // clear set flag from other moves
        for (i = 0; i < MAX_MON_MOVES; i++) {
            if (moves[i].moveFlags & MOVE_FLAG_EXISTS)
                moves[i].moveFlags &= ~MOVE_FLAG_SET;
        }

        flags = move->moveFlags | MOVE_FLAG_SET;
    }

    move->moveFlags = flags;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return TRUE;
}

void UnSetMove(s32 index, Move *moves)
{
    Move* move = &moves[index];
    move->moveFlags &= ~MOVE_FLAG_SET;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
}

bool8 ToggleMoveEnabled(s32 index, Move *moves)
{
    Move* move = &moves[index];
    move->moveFlags ^= MOVE_FLAG_ENABLED_FOR_AI;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return TRUE;
}

s32 GetLinkedSequence(s32 index, Move *moves, u16 *sequenceMoveIDs)
{
    s32 i;
    s32 linkedSequenceLength;
    Move* move;

    linkedSequenceLength = 1;
    move = &moves[index];
    sequenceMoveIDs[0] = move->id;

    for (i = 1; i < 4; i++)
        sequenceMoveIDs[i] = 0;

    for (index++, sequenceMoveIDs++; index < 8 && linkedSequenceLength <= 3; index++) {
        move = &moves[index];
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            return linkedSequenceLength;

        *sequenceMoveIDs++ = move->id;
        linkedSequenceLength++;
    }

    return linkedSequenceLength;
}

s32 sub_80935B8(Move *moves, s32 index)
{
    s32 i;
    s32 linkSequenceStart;
    bool8 isNonTrivialLinkSequence;
    bool8 any_move_linked;
    s32 pp;
    bool8 v1;

    pp = 99;
    any_move_linked = FALSE;
    isNonTrivialLinkSequence = FALSE;
    linkSequenceStart = index;

    while (linkSequenceStart >= 0) {
        Move *move = &moves[linkSequenceStart];

        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)))
            break;

        linkSequenceStart--;
    }

    // this is so stupid but it works
    #ifndef NONMATCHING
    isNonTrivialLinkSequence++; isNonTrivialLinkSequence--;
    #endif

    for (i = linkSequenceStart + 1; i < MAX_MON_MOVES; i++) {
        Move *move = &moves[i];

        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)))
            break;

        isNonTrivialLinkSequence = TRUE;
    }

    if (!isNonTrivialLinkSequence)
        return 99;

    v1 = FALSE;

    while (--i >= linkSequenceStart) {
        Move* move = &moves[i];

        if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            break;

        if (pp > move->PP)
            pp = move->PP;
        if (move->PP == 0)
            v1 = TRUE;
        if (move->moveFlags2 & MOVE_FLAG_REPLACE)
            v1 = TRUE;
    }

    if (!v1)
        return pp;

    for (i = linkSequenceStart + 1; i < MAX_MON_MOVES; i++) {
        Move* move = &moves[i];

        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS))
            break;
        
        if (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN) {
            move->moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            any_move_linked = TRUE;
        }
        else
            break;
    }

    if (any_move_linked)
        return 0;
    return pp;
}

void unk_FixLinkedMovesSetEnabled4(Move *moves)
{
    Move linkedSequences[4][4];

    // all that doing these in a row seems to do is
    // fix the set/enabled flags by moving them to
    // the first move of every linked sequence
    unk_GetLinkedSequences4(moves, linkedSequences);
    unk_LinkedSequencesToMoves4(moves, linkedSequences);
}

void unk_FixLinkedMovesSetEnabled8(Move *moves)
{
    Move linkedSequences[8][8];

    unk_GetLinkedSequences8(moves, linkedSequences);
    unk_LinkedSequencesToMoves8(moves, linkedSequences);
}

void unk_FixLinkedMovesSetEnabled8_v2(Move *moves)
{
    Move linkedSequences[8][8];

    unk_GetLinkedSequences8_v2(moves, linkedSequences);
    unk_LinkedSequencesToMoves8_v2(moves, linkedSequences);
}

static s32 unk_FindMarkedMoveInLinkedSequences44(Move moves[MAX_MON_MOVES][MAX_MON_MOVES])
{
    s32 i, j;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        for (j = 0; j < MAX_MON_MOVES; j++) {
            if ((moves[i][j].moveFlags & MOVE_FLAG_EXISTS) && (moves[i][j].moveFlags & MOVE_FLAG_INTERNAL_MARKER))
                return i;
        }
    }

    return -1;
}

static void unk_GetLinkedSequences4(Move *moves, Move linkedSequences[MAX_MON_MOVES][MAX_MON_MOVES])
{
    s32 i, j;
    s32 k;
    s32 moveSetIndex;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        for (j = 0; j < MAX_MON_MOVES; j++)
            linkedSequences[i][j].moveFlags = 0;
    }

    moveSetIndex = -1;

    for (j = 0, k = 0; k < MAX_MON_MOVES; j++, k++) {
        if (k == 0 || !(moves[k].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moveSetIndex++;
            j = 0;
        }

        linkedSequences[moveSetIndex][j] = moves[k];
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}

static void unk_LinkedSequencesToMoves4(Move *moves, Move linkedSequences[MAX_MON_MOVES][MAX_MON_MOVES])
{
    s32 i, j;
    s32 movesCopied;

    bool8 moves_set[MAX_MON_MOVES];
    bool8 moves_enabled[MAX_MON_MOVES];

    movesCopied = 0;

    // Figure out which linked sequences contain set / enabled moves
    for (i = 0; i < MAX_MON_MOVES; i++) {
        moves_set[i] = 0;
        moves_enabled[i] = 0;

        for (j = 0; j < MAX_MON_MOVES; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS))
                continue;

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag)
                moves_set[i] = TRUE;

            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
                moves_enabled[i] = TRUE;
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++) {
        for (j = 0; j < MAX_MON_MOVES; j++) {
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS))
                continue;

            moves[movesCopied] = linkedSequences[i][j];

            if (j == 0)
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            else
                moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;

            moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
            moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;

            if (moves_set[i] && j == 0)
                moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
            if (moves_enabled[i] && j == 0)
                moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;

            movesCopied++;
            if (movesCopied == MAX_MON_MOVES)
                return;
        }
    }
}

// The next two functions are exactly the same
static s32 unk_FindMarkedMoveInLinkedSequences88(Move linkedSequences[8][8])
{
    s32 i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) && (linkedSequences[i][j].moveFlags & MOVE_FLAG_INTERNAL_MARKER))
                return i;
        }
    }

    return -1;
}

// I expect the intent was to check for a different flag in this one...
// or the argument is a struct type that does hold the moves as a field
static s32 unk_FindMarkedMoveInLinkedSequences88_v2(Move linkedSequences[8][8])
{
    s32 i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) && (linkedSequences[i][j].moveFlags & MOVE_FLAG_INTERNAL_MARKER))
                return i;
        }
    }

    return -1;
}

// again, the next two functions are exactly the same
// they are also the same as unk_GetLinkedSequences4 but for [8][8] linkedSequences instead of
// [4][4] linkedSequences

// it seems to find all the _actually_ separate moves, and split them
// out into link sequences in the destination linkedSequences
static void unk_GetLinkedSequences8(Move *moves, Move linkedSequences[8][8])
{
    s32 i, j;
    s32 k;
    s32 moveSetIndex;

    // clear out linkedSequences
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            linkedSequences[i][j].moveFlags = 0;
    }

    moveSetIndex = -1;

    for (j = 0, k = 0; k < 8; j++, k++) {
        Move* move = &moves[k];

        if (k == 0 || !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moveSetIndex++;
            j = 0;
        }

        linkedSequences[moveSetIndex][j] = *move;
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}

static void unk_GetLinkedSequences8_v2(Move *moves, Move linkedSequences[8][8])
{
    s32 i, j;
    s32 k;
    s32 moveSetIndex;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            linkedSequences[i][j].moveFlags = 0;
    }

    moveSetIndex = -1;

    for (j = 0, k = 0; k < 8; j++, k++) {
        Move* move = &moves[k];

        if (k == 0 || !(move->moveFlags & 2)) {
            moveSetIndex++;
            j = 0;
        }

        linkedSequences[moveSetIndex][j] = *move;
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}

// the next 2 functions are again exactly the same
// these functions are the same as unk_LinkedSequencesToMoves4 but for [8][8] linkedSequences
// instead of [4][4] linkedSequences
static void unk_LinkedSequencesToMoves8(Move *moves, Move linkedSequences[8][8])
{
    int i, j;
    int movesCopied;

    bool8 moveFlags8[8];
    bool8 moveFlags4[8];

    movesCopied = 0;

    for (i = 0; i < 8; i++) {
        moveFlags8[i] = 0;
        moveFlags4[i] = 0;

        for (j = 0; j < 8; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS))
                continue;

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;

            if (flag)
                moveFlags8[i] = TRUE;

            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
                moveFlags4[i] = TRUE;
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS))
                continue;

            moves[movesCopied] = linkedSequences[i][j];

            if (j == 0)
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            else
                moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;

            moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
            moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;

            if (moveFlags8[i] && (j == 0))
                moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
            if (moveFlags4[i] && (j == 0))
                moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;

            movesCopied++;
            if (movesCopied == 8)
                return;
        }
    }
}

static void unk_LinkedSequencesToMoves8_v2(Move *moves, Move linkedSequences[8][8])
{
    s32 i, j;
    s32 movesCopied;

    bool8 moveFlags8[8];
    bool8 moveFlags4[8];

    movesCopied = 0;

    for (i = 0; i < 8; i++) {
        moveFlags8[i] = 0;
        moveFlags4[i] = 0;

        for (j = 0; j < 8; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS))
                continue;

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;

            if (flag)
                moveFlags8[i] = TRUE;

            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI)
                moveFlags4[i] = TRUE;
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS))
                continue;

            moves[movesCopied] = linkedSequences[i][j];

            if (j == 0)
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            else
                moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;

            moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
            moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;

            if (moveFlags8[i] && (j == 0))
                moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
            if (moveFlags4[i] && (j == 0))
                moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;

            movesCopied++;
            if (movesCopied == 8)
                return;
        }
    }
}

// The next two are the same again
UNUSED static void RemoveLinkSequenceFromMoves8_v2(Move *moves, s32 index)
{
    s32 i;
    s32 copiedMoves;
    Move moveSet[8];

    moves[index].moveFlags = 0;

    for (i = index + 1; i < 8; i++) {
        Move* move = &moves[i];

        #ifndef NONMATCHING
        asm("");
        #endif

        if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            break;

        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;

        move->moveFlags = 0;
    }

    copiedMoves = 0;

    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS)
            moveSet[copiedMoves++] = moves[i];
    }

    while (copiedMoves < 8)
        moveSet[copiedMoves++].moveFlags = 0;

    for (i = 0; i < 8; i++)
        moves[i] = moveSet[i];
}

void RemoveLinkSequenceFromMoves8(Move *moves, s32 index)
{
    s32 i;
    s32 copiedMoves;
    Move moveSet[8];

    // remove link sequence (set flags to 0)
    moves[index].moveFlags = 0;

    for (i = index + 1; i < 8; i++) {
        Move* move = &moves[i];

        #ifndef NONMATCHING
        asm("");
        #endif

        if (!(move->moveFlags & MOVE_FLAG_EXISTS))
            break;

        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;

        move->moveFlags = 0;
    }

    // copy over other moves
    copiedMoves = 0;

    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS)
            moveSet[copiedMoves++] = moves[i];
    }

    // fill with nonexistent moves
    while (copiedMoves < 8)
        moveSet[copiedMoves++].moveFlags = 0;

    // copy back to original moves pointer
    for (i = 0; i < 8; i++)
        moves[i] = moveSet[i];
}

s32 unk_MoveIDPrintMoveDescription(s32 a1, u16 moveID, s32 a3, struct subStruct_203B240 **a4)
{
    Move move;

    InitPokemonMove(&move, moveID);
    return unk_PrintMoveDescription(a1, &move, a3, a4);
}

UNUSED static s32 unk_MovePrintMoveDescription(s32 a1, Move *move, s32 a3, struct subStruct_203B240 **a4)
{
    Move newMove;

    CopyAndResetMove(&newMove, move);
    return unk_PrintMoveDescription(a1, &newMove, a3, a4);
}

s32 unk_PrintMoveDescription(s32 x, Move *move, s32 a3, struct subStruct_203B240 **a4)
{
    u8 *moveDescription;
    s32 y;
    u8 buffer[800];

    sub_80073B8(a3);
    sub_80928C0(gAvailablePokemonNames, move, 0);
    xxx_format_and_draw(8 * x + 16, 0, gUnknown_8109930, a3, 0);
    y = 19;
    moveDescription = sMovesData[move->id].description;

    if (moveDescription[0] == '*') {
        y = 16;
        ++moveDescription;
    }

    xxx_format_and_draw(4, y, moveDescription, a3, 0);
    unk_MovePrintData(move, a3);
    sub_80073E0(a3);
    strcpy(buffer, sMovesData[move->id].description);
    return sub_8097DF0(buffer, a4);
}

static void unk_MovePrintData(Move *move, s32 y)
{
    u8 type;
    s32 power;
    const u8 *text;

    sub_80078A4(y, 4, 72, 200, COLOR_WHITE_2);
    sub_8092D54(gAvailablePokemonNames, move);
    xxx_format_and_draw(4, 74, gUnknown_810CF00, y, 0);
    xxx_format_and_draw(4, 86, gPtrTypeText, y, 0);
    type = GetMoveType(move);
    text = GetUnformattedTypeString(type);
    xxx_format_and_draw(64, 86, text, y, 0);
    power = GetMoveBasePower(move);
    gUnknown_202DE30 = power;
}

static void CopyAndResetMove(Move *dest, Move *src)
{
    if (src->moveFlags & MOVE_FLAG_EXISTS) {
        dest->moveFlags = src->moveFlags;
        dest->moveFlags2 = 0;
        dest->id = src->id;
        dest->PP = sMovesData[src->id].basePP;
        dest->ginseng = src->PP; // This seems horribly bugged
    }
    else
        dest->moveFlags = 0;
}

void CopyAndResetMoves(Move *destMoves, Move *srcMoves)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (srcMoves[i].moveFlags & 1) {
            destMoves[i].moveFlags = srcMoves[i].moveFlags;
            destMoves[i].moveFlags2 = 0;
            destMoves[i].id = srcMoves[i].id;
            destMoves[i].PP = sMovesData[srcMoves[i].id].basePP;
            destMoves[i].ginseng = srcMoves[i].PP; // This seems horribly bugged
        }
        else
            destMoves[i].moveFlags = 0;
    }

    // possibly destMoves is not just an array and this is the
    // next struct field
    // this index would be out of bounds after all
    destMoves[MAX_MON_MOVES].moveFlags = 0;
}

void CopyBareMoveData(Move *destMoves, Move *srcMoves)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        destMoves[i].moveFlags = srcMoves[i].moveFlags;
        destMoves[i].id = srcMoves[i].id;
        destMoves[i].PP = srcMoves[i].ginseng;
    }
}

void unk_CopyMoves4To8AndClearFlag2Unk4(Move *destMoves, Move *srcMoves)
{
    s32 movesCopied;

    movesCopied = 0;

    for (movesCopied = 0; movesCopied < MAX_MON_MOVES; movesCopied++) {
        if (!(srcMoves[movesCopied].moveFlags & MOVE_FLAG_EXISTS))
            break;

        destMoves[movesCopied] = srcMoves[movesCopied];
        destMoves[movesCopied].moveFlags2 &= ~MOVE_FLAG2_UNK4;
    }

    while (movesCopied < 8)
        destMoves[movesCopied++].moveFlags = 0;
}

void unk_CopyMoves4To8(Move *destMoves, Move *srcMoves)
{
    s32 movesCopied;

    movesCopied = 0;
    for (movesCopied = 0; movesCopied < MAX_MON_MOVES; movesCopied++) {
        if (!(srcMoves[movesCopied].moveFlags & MOVE_FLAG_EXISTS))
            break;

        destMoves[movesCopied] = srcMoves[movesCopied];
    }

    while (movesCopied < 8)
        destMoves[movesCopied++].moveFlags = 0;
}

void sub_8094060(Move *srcMoves, Move *destMoves)
{
    s32 i, j;

    j = 0;
    for (i = 0; i < 8; i++) {
        Move* srcMove = &srcMoves[i];
        Move* destMove;

        if (!(srcMove->moveFlags & MOVE_FLAG_EXISTS))
            continue;

        if (j >= MAX_MON_MOVES)
            break;

        destMove = &destMoves[j];
        *destMove = *srcMove;
        j++;
    }

    while (j < MAX_MON_MOVES)
        destMoves[j++].moveFlags = 0;
}

static void SavePokemonMove(struct unkStruct_8094924 *r0, Move *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->id, 9);
    SaveIntegerBits(r0, &move->PP, 7);
}

static void RestorePokemonMove(struct unkStruct_8094924 *r0, Move *move)
{
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->id, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
}

void SavePokemonMoves(struct unkStruct_8094924 *r0, Move *moveSet)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        SavePokemonMove(r0, &moveSet[i]);
}

void RestorePokemonMoves(struct unkStruct_8094924 *r0, Move *moveSet)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        RestorePokemonMove(r0, &moveSet[i]);
}

static void sub_8094148(struct unkStruct_8094924 *r0, Move *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->moveFlags2, 1);
    SaveIntegerBits(r0, &move->id, 9);
    SaveIntegerBits(r0, &move->PP, 7);
    SaveIntegerBits(r0, &move->ginseng, 7);
}

void sub_8094184(struct unkStruct_8094924 *r0, struct unkStruct_8094184 *r1)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        sub_8094148(r0, &r1->moves[i]);

    SaveIntegerBits(r0, &r1->unk20, 8);
}

static void sub_80941B0(struct unkStruct_8094924 *r0, Move *move)
{
    memset(move, 0, sizeof(Move));
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->moveFlags2, 1);
    RestoreIntegerBits(r0, &move->id, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
    RestoreIntegerBits(r0, &move->ginseng, 7);
}

void sub_80941FC(struct unkStruct_8094924 *r0, struct unkStruct_8094184 *r1)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        sub_80941B0(r0, &r1->moves[i]);

    r1->unk20 = 0;
    RestoreIntegerBits(r0, &r1->unk20, 8);
}

bool8 DoesMoveCharge(u16 move)
{
    if (move == MOVE_SOLARBEAM) return TRUE;
    if (move == MOVE_SKY_ATTACK) return TRUE;
    if (move == MOVE_RAZOR_WIND) return TRUE;
    if (move == MOVE_FOCUS_PUNCH) return TRUE;
    if (move == MOVE_SKULL_BASH) return TRUE;
    if (move == MOVE_FLY) return TRUE;
    if (move == MOVE_BOUNCE) return TRUE;
    if (move == MOVE_DIVE) return TRUE;
    if (move == MOVE_DIG) return TRUE;

    return FALSE;
}