#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "constants/monster.h"
#include "code_800D090.h"
#include "data_serializer.h"
#include "code_8097DD0.h"
#include "def_filearchives.h"
#include "memory.h"
#include "moves.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "pokemon_types.h"
#include "strings.h"

static EWRAM_DATA OpenedFile *sWazaParametersFile = { NULL }; // NDS=213C188
static EWRAM_DATA MoveDataEntry *sMovesData = { NULL }; // NDS=213C18C
static EWRAM_DATA MoveLearnset *sMoveLearnsets = { NULL }; // NDS=0213C184 | 420 entries, aka (MONSTER_DEOXYS_SPEED + 1), aka (MONSTER_MUNCHLAX)

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

static const MoveBufferStruct sDefaultMoveBufferParams = {0};

// arm9.bin::020640A0
void LoadWazaParameters(void)
{
    sWazaParametersFile = OpenFileAndGetFileDataPtr("wazapara", &gSystemFileArchive);

    sMovesData = ((MoveDataFile *)(sWazaParametersFile->data))->moveData;
    sMoveLearnsets = ((MoveDataFile *)(sWazaParametersFile->data))->moveLearnsets;
}

static u8 GetColorForMove(Move *move)
{
    if (move->moveFlags & MOVE_FLAG_DISABLED)
        return 50;
    if (!(move->moveFlags2 & MOVE_FLAG_SEALED))
        return 52;
    return 50;
}

void BufferDefaultMoveName(u8 *buffer, Move *move, const MoveBufferStruct *bufferParams)
{
    Move moveCopy;
    CopyAndResetMove(&moveCopy, move);
    BufferMoveName(buffer, &moveCopy, bufferParams);
}

void BufferMoveName(u8 *buffer, Move *move, const MoveBufferStruct *bufferParams)
{
    u32 color;
    u32 basePP;
    u8 ginsengBoostStr[12];

    color = GetColorForMove(move);

    if (bufferParams == NULL)
        bufferParams = &sDefaultMoveBufferParams;

    if (move->ginseng != 0)
        sprintfStatic(ginsengBoostStr, _("%+d"), move->ginseng);
    else
        ginsengBoostStr[0] = '\0';

    if (bufferParams->redColor)
        color = COLOR_RED;
    if (bufferParams->useRedColorForChargingMoves && DoesMoveCharge(move->id))
        color = COLOR_RED;

    switch (bufferParams->style) {
        case BUFFER_MOVE_JUST_NAME:
            sprintfStatic(buffer, _("{color}%c%s%s{reset}"),
                color, sMovesData[move->id].name, ginsengBoostStr);
            break;
        case BUFFER_MOVE_SET_ICON_POSITIONED_PP_UNUSED:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, _("{color}%c#:%s%s%s#;%c%2d/%2d{reset}"),
                color, move->moveFlags & MOVE_FLAG_SET ? _("{ICON_SET}") : _("{ICON_BLANK}"),
                sMovesData[move->id].name, ginsengBoostStr, bufferParams->xPPCoord, move->PP, basePP);
            break;
        case BUFFER_MOVE_SET_ICON_POSITIONED_PP:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, _("{color}%c%s%s%s{MOVE_X_POSITION}%c%2d/%2d{reset}"),
                color, move->moveFlags & MOVE_FLAG_SET ? _("{ICON_SET}") : _("{ICON_BLANK}"),
                sMovesData[move->id].name, ginsengBoostStr, bufferParams->xPPCoord, move->PP, basePP);
            break;
        case BUFFER_MOVE_STAR_ICON_POSITIONED_PP_UNUSED:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, _("{color}%c#:%s%s%s#;%c%2d/%2d{reset}"),
                color, move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? _("{STAR_BULLET}") : _("{ICON_BLANK}"),
                sMovesData[move->id].name, ginsengBoostStr, bufferParams->xPPCoord, move->PP, basePP);
            break;
        case BUFFER_MOVE_STAR_ICON_POSITIONED_PP:
            basePP = GetMoveBasePP(move);
            sprintfStatic(buffer, _("{color}%c%s%s%s{MOVE_X_POSITION}%c%2d/%2d{reset}"),
                color, move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? _("{STAR_BULLET}") : _("{ICON_BLANK}"),
                sMovesData[move->id].name, ginsengBoostStr, bufferParams->xPPCoord, move->PP, basePP);
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

void InitPokemonMoveOrNullObject(Move *move, u16 moveID)
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

// arm9.bin::02063CE4
u8 GetMoveType(Move *move)
{
    return sMovesData[move->id].type;
}

static const u8 gDummyMoves[] = {0};

const u8 *GetLevelUpMoves(s16 species)
{
    s32 id = SpeciesId(species);
    if (species == MONSTER_DECOY || species == MONSTER_NONE)
        return gDummyMoves;
    if (id == MONSTER_MUNCHLAX)
        return gDummyMoves;

    return sMoveLearnsets[id].levelUpMoves;
}

const u8 *GetHMTMMoves(s16 species)
{
    s32 id = SpeciesId(species);
    if (species == MONSTER_DECOY || species == MONSTER_NONE)
        return gDummyMoves;
    if (id == MONSTER_MUNCHLAX)
        return gDummyMoves;

    return sMoveLearnsets[id].HMTMMoves;
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
    BufferMoveName(buffer, &stack, NULL);
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
    sprintfStatic(buffer, _("%s"), gRangeNames[GetMoveRangeID(move)]);
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
    MemoryCopy8(dest_struct, moves, sizeof(dest_struct));
    return TryLinkMovesAfter(param_1, dest_struct);
}

bool8 sub_809333C(s32 param_1, Move *moves)
{
    Move dest_struct[MAX_MON_MOVES * 2];
    MemoryCopy8(dest_struct, moves, sizeof(dest_struct));
    return UnlinkMovesAfter(param_1, dest_struct);
}

UNUSED static bool8 sub_8093360(s32 param_1, Move *moves)
{
    Move dest_struct[MAX_MON_MOVES * 2];
    MemoryCopy8(dest_struct, moves, sizeof(dest_struct));
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
    ASM_MATCH_TRICK(isNonTrivialLinkSequence);

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
        if (!MoveFlagExists(move) || !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
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
        if (!MoveFlagExists(move) || !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
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

s32 unk_MoveIDPrintMoveDescription(s32 a1, u16 moveID, s32 a3, STATUSTEXTS(statuses))
{
    Move move;

    InitPokemonMove(&move, moveID);
    return unk_PrintMoveDescription(a1, &move, a3, statuses);
}

UNUSED static s32 unk_MovePrintMoveDescription(s32 a1, Move *move, s32 a3, STATUSTEXTS(statuses))
{
    Move newMove;

    CopyAndResetMove(&newMove, move);
    return unk_PrintMoveDescription(a1, &newMove, a3, statuses);
}

s32 unk_PrintMoveDescription(s32 x, Move *move, s32 a3, STATUSTEXTS(statuses))
{
    u8 *moveDescription;
    s32 y;
    u8 buffer[800];

    sub_80073B8(a3);
    BufferMoveName(gFormatBuffer_Monsters[0], move, 0);
    PrintFormattedStringOnWindow(8 * x + 16, 0, _("{POKEMON_0}"), a3, 0);
    y = 19;
    moveDescription = sMovesData[move->id].description;

    if (moveDescription[0] == '*') {
        y = 16;
        ++moveDescription;
    }

    PrintFormattedStringOnWindow(4, y, moveDescription, a3, 0);
    unk_MovePrintData(move, a3);
    sub_80073E0(a3);
    strcpy(buffer, sMovesData[move->id].description);
    return PrepareStatusStringArrays(buffer, statuses);
}

static void unk_MovePrintData(Move *move, s32 y)
{
    u8 type;
    s32 power;
    const u8 *text;

    AddDoubleUnderScoreHighlight(y, 4, 72, 200, COLOR_WHITE_2);
    sub_8092D54(gFormatBuffer_Monsters[0], move);
    PrintFormattedStringOnWindow(4, 74, gUnknown_810CF00, y, 0);
    PrintFormattedStringOnWindow(4, 86, gTextType, y, 0);
    type = GetMoveType(move);
    text = GetUnformattedTypeString(type);
    PrintFormattedStringOnWindow(64, 86, text, y, 0);
    power = GetMoveBasePower(move);
    gFormatArgs[0] = power;
}

static void CopyAndResetMove(Move *dest, Move *src)
{
    if (MoveFlagExists(src)) {
        dest->moveFlags = src->moveFlags;
        dest->moveFlags2 = 0;
        dest->id = src->id;
        dest->PP = sMovesData[src->id].basePP;
        dest->ginseng = src->PP; // This seems horribly bugged
    }
    else
        dest->moveFlags = 0;
}

void CopyAndResetMoves(Moves *destMoves, Move *srcMoves)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (MoveFlagExists(&srcMoves[i])) {
            destMoves->moves[i].moveFlags = srcMoves[i].moveFlags;
            destMoves->moves[i].moveFlags2 = 0;
            destMoves->moves[i].id = srcMoves[i].id;
            destMoves->moves[i].PP = sMovesData[srcMoves[i].id].basePP;
            destMoves->moves[i].ginseng = srcMoves[i].PP; // This seems horribly bugged
        }
        else
            destMoves->moves[i].moveFlags = 0;
    }

    destMoves->struggleMoveFlags = 0;
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

// arm9.bin::02061E58
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

// arm9.bin::02061DC0
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

// arm9.bin::02061D80
static void WritePoke1MoveBits(DataSerializer *r0, Move *move)
{
    WriteBits(r0, &move->moveFlags, 4);
    WriteBits(r0, &move->id, 9);
    WriteBits(r0, &move->PP, 7);
}

// arm9.bin::02061D40
static void ReadPoke1MoveBits(DataSerializer *r0, Move *move)
{
    ReadBits(r0, &move->moveFlags, 4);
    ReadBits(r0, &move->id, 9);
    ReadBits(r0, &move->PP, 7);
}

// arm9.bin::02061D08
void WritePoke1MovesBits(DataSerializer *r0, Move *moveSet)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        WritePoke1MoveBits(r0, &moveSet[i]);
}

// arm9.bin::02061CD0
void ReadPoke1MovesBits(DataSerializer *r0, Move *moveSet)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        ReadPoke1MoveBits(r0, &moveSet[i]);
}

// arm9.bin::02061C70
static void WritePoke2MoveBits(DataSerializer *r0, Move *move)
{
    WriteBits(r0, &move->moveFlags, 4);
    WriteBits(r0, &move->moveFlags2, 1);
    WriteBits(r0, &move->id, 9);
    WriteBits(r0, &move->PP, 7);
    WriteBits(r0, &move->ginseng, 7);
}

// arm9.bin::02061C28
void WritePoke2MovesBits(DataSerializer *r0, Moves *r1)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        WritePoke2MoveBits(r0, &r1->moves[i]);

    WriteBits(r0, &r1->struggleMoveFlags, 8);
}

// arm9.bin::02061BB0
static void ReadPoke2MoveBits(DataSerializer *r0, Move *move)
{
    memset(move, 0, sizeof(Move));
    ReadBits(r0, &move->moveFlags, 4);
    ReadBits(r0, &move->moveFlags2, 1);
    ReadBits(r0, &move->id, 9);
    ReadBits(r0, &move->PP, 7);
    ReadBits(r0, &move->ginseng, 7);
}

// arm9.bin::02061B60
void ReadPoke2MovesBits(DataSerializer *r0, Moves* r1)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        ReadPoke2MoveBits(r0, &r1->moves[i]);

    r1->struggleMoveFlags = 0;
    ReadBits(r0, &r1->struggleMoveFlags, 8);
}

// arm9.bin::02061AEC
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
