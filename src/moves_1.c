#include "global.h"
#include "code_8092334.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"
#include "subStruct_203B240.h"
#include "code_809447C.h"
#include "text_util.h"

extern u8 gAvailablePokemonNames[];
extern const char gUnknown_8109930[];
extern struct MoveDataEntry *gMovesData;

u8 sub_8093468(int param_1, struct Move* src_struct);
u8 TryLinkMovesAfter(int param_1, struct Move* src_struct);
u8 sub_80933D8(int param_1, void* src_struct);
bool8 DoesMoveCharge(u16 move);

void unk_GetLinkedSequences4(struct Move* moves, struct Move linkedSequences[4][4]);
void unk_LinkedSequencesToMoves4(struct Move* moves, struct Move linkedSequences[4][4]);
void unk_GetLinkedSequences8(struct Move* moves, struct Move linkedSequences[8][8]);
void unk_LinkedSequencesToMoves8(struct Move* moves, struct Move linkedSequences[8][8]);

void unk_GetLinkedSequences8_v2(struct Move*, struct Move[8][8]);
void unk_LinkedSequencesToMoves8_v2(struct Move*, struct Move[8][8]);

int unk_PrintMoveDescription(int, struct Move*, int, struct subStruct_203B240**);

extern void sub_80073B8(u32);
void sub_80928C0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *param_3);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern void unk_MovePrintData(struct Move*, int);  // print something
extern void sub_80073E0(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);

extern void sub_80078A4(u32, u32, u32, u32, u32);
extern u8 sub_8092B00(struct Move*);
extern u32 sub_8092BC0(struct Move*);
extern u32 gUnknown_202DE30;
extern u8* gPtrTypeText;     // "Type"
extern u8* gUnknown_810CF00; // "Range#=@.$m0 "


int IsMoveSet(int index, struct Move* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_SET) != 0) {
        return 1;
    }
    return 0;
}

int IsMoveEnabled(int index, struct Move* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) != 0) {
        return 1;
    }
    return 0;
}

int sub_8093318(int param_1, void* src_struct)
{
    struct Move dest_struct[8];
    MemoryCopy8((void*)dest_struct, src_struct, 64);
    return TryLinkMovesAfter(param_1, dest_struct);
}

int sub_809333C(int param_1, void* src_struct)
{
    struct Move dest_struct[8];
    MemoryCopy8((void*)dest_struct, src_struct, 64);
    return sub_8093468(param_1, dest_struct);
}

int sub_8093360(int param_1, void* src_struct)
{
    u8 dest_struct[64];
    MemoryCopy8(dest_struct, src_struct, 64);
    return sub_80933D8(param_1, dest_struct);
}

// appears unused
int IsMoveNotSet(int index, struct Move* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_SET) != 0) {
        return 0;
    }
    return 1;
}

int IsAnyMoveLinked(int unused, struct Move* moves) {
    int i;
    int counter;

    counter = 0;
    for (i = 0; i < 8; i++) {
        if ((moves[i].moveFlags & MOVE_FLAG_EXISTS) && !(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            counter++;
        }
    }
    if (counter > 1) {
        return 1;
    }
    return 0;
}

u8 sub_80933D8(int param_1, void* src_struct)
{
  int result;

  if (!TryLinkMovesAfter(param_1, src_struct)) {
    result = sub_8093468(param_1, src_struct);
  }
  else {
    result = 1;
  }
  return result;
}

u8 TryLinkMovesAfter(int index, struct Move* moves) {
    int i;
    const struct Move *move = &moves[index];
    if (DoesMoveCharge(move->id)) {
        return 0;
    }
    
    for (i = index + 1; i < 8; i++) {
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        if (DoesMoveCharge(moves[i].id)) {
            return 0;
        }
        if (!(moves[i].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moves[i].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            unk_FixLinkedMovesSetEnabled8_v2(moves);
            return 1;
        }
    }
    return 0;
}

// unlinks move
NAKED
u8 sub_8093468(int index, struct Move* moves)
{
	asm_unified(
"   push {r4-r7,lr}\n"
"	adds r6, r1, 0\n"
"	movs r5, 0\n"
"	adds r1, r0, 0x1\n"
"	movs r4, 0\n"
"	cmp r1, 0x7\n"
"	bgt _080934A0\n"
"	movs r0, 0x2\n"
"	mov r12, r0\n"
"	movs r7, 0xFD\n"
"	lsls r0, r1, 3\n"
"	adds r3, r0, r6\n"
"_08093480:\n"
"	ldrb r2, [r3]\n"
"	mov r0, r12\n"
"	ands r0, r2\n"
"	cmp r0, 0\n"
"	beq _080934A0\n"
"	adds r0, r7, 0\n"
"	ands r0, r2\n"
"	strb r0, [r3]\n"
"	movs r5, 0x1\n"
"	adds r3, 0x8\n"
"	adds r1, 0x1\n"
"	adds r4, 0x1\n"
"	cmp r4, 0x7\n"
"	bgt _080934A0\n"
"	cmp r1, 0x7\n"
"	ble _08093480\n"
"_080934A0:\n"
"	adds r0, r6, 0\n"
"	bl unk_FixLinkedMovesSetEnabled8_v2\n"
"	adds r0, r5, 0\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1\n");
}

u8 IsNextMoveLinked(int index, struct Move* moves) {
    struct Move* move;
    if (index + 1 >= 8) {
        return 0;
    }
    move = &moves[index + 1];
    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
        return 0;
    if ((move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
        return 1;
    return 0;
}

int ToggleSetMove(int index, struct Move* moves) {
    struct Move* move;
    u8 flags;
    int i;

    move = &moves[index];
    if (moves[index].moveFlags & MOVE_FLAG_SET) {
        flags = move->moveFlags & ~MOVE_FLAG_SET;
    }
    else {
        // clear set flag from other moves
        for (i = 0; i < 4; i++) {
            if (moves[i].moveFlags & MOVE_FLAG_EXISTS) {
                moves[i].moveFlags &= ~MOVE_FLAG_SET;
            }
        }
        flags = move->moveFlags | MOVE_FLAG_SET;
    }
    move->moveFlags = flags;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return 1;
}

void UnSetMove(int index, struct Move* moves) {
    struct Move* move = &moves[index];
    move->moveFlags &= ~MOVE_FLAG_SET;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
}

int ToggleMoveEnabled(int index, struct Move* moves) {
    struct Move* move = &moves[index];
    move->moveFlags ^= MOVE_FLAG_ENABLED_FOR_AI;
    unk_FixLinkedMovesSetEnabled8_v2(moves);
    return 1;
}

int GetLinkedSequence(int index, struct Move* moves, u16* sequenceMoveIDs) {
    int i;
    int linkedSequenceLength;
    struct Move* move;

    linkedSequenceLength = 1;
    move = &moves[index];
    sequenceMoveIDs[0] = move->id;
    for (i = 1; i < 4; i++) {
        sequenceMoveIDs[i] = 0;
    }

    for (index++, sequenceMoveIDs++; index < 8 && linkedSequenceLength <= 3; index++) {
        move = &moves[index];
        if ((move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN) == 0) {
            return linkedSequenceLength;
        }

        *sequenceMoveIDs++ = move->id;
        linkedSequenceLength++;
    }
    return linkedSequenceLength;
}

int sub_80935B8(struct Move *moves, int index) {
    int i;
    int linkSequenceStart;
    int isNonTrivialLinkSequence;
    int any_move_linked;
    int pp;
    int v1;
    
    pp = 99;
    any_move_linked = 0;
    isNonTrivialLinkSequence = 0;

    linkSequenceStart = index;
    while (linkSequenceStart >= 0) {
        struct Move *move = &moves[linkSequenceStart];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))) {
            break;
        }
        
        linkSequenceStart--;
    }

    // this is so stupid but it works
    isNonTrivialLinkSequence++;isNonTrivialLinkSequence--;

    for (i = linkSequenceStart + 1; i < 4; i++) {
        struct Move *move = &moves[i];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))) {
            break;
        }
        
        isNonTrivialLinkSequence = 1;
    }

    if (!isNonTrivialLinkSequence) {
        return 99;
    }

    v1 = 0;
    while (--i >= linkSequenceStart) {
        struct Move* move = &moves[i];
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (pp > move->PP) {
            pp = move->PP;
        }
        if (move->PP == 0) {
            v1 = 1;
        }
        if (move->moveFlags2 & MOVE_FLAG_REPLACE) {
            v1 = 1;
        }
    }

    if (!v1) {
        return pp;
    }

    for (i = linkSequenceStart + 1; i < 4; i++) {
        struct Move* move = &moves[i];
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        
        if (move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN) {
            move->moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
            any_move_linked = 1;
        }
        else {
            break;
        }
    }

    if (any_move_linked) {
        return 0;
    }
    else {
        return pp;
    }
}

void unk_FixLinkedMovesSetEnabled4(struct Move* moves) {
    struct Move linkedSequences[4][4];

    // all that doing these in a row seems to do is
    // fix the set/enabled flags by moving them to
    // the first move of every linked sequence
    unk_GetLinkedSequences4(moves, linkedSequences);
    unk_LinkedSequencesToMoves4(moves, linkedSequences);
}

void unk_FixLinkedMovesSetEnabled8(struct Move* moves) {
    struct Move linkedSequences[8][8];
    unk_GetLinkedSequences8(moves, linkedSequences);
    unk_LinkedSequencesToMoves8(moves, linkedSequences);
}

void unk_FixLinkedMovesSetEnabled8_v2(struct Move* moves) {
    struct Move linkedSequences[8][8];

    unk_GetLinkedSequences8_v2(moves, linkedSequences);
    unk_LinkedSequencesToMoves8_v2(moves, linkedSequences);
}

int unk_FindMoveFlag2Unk80InLinkedSequences44(struct Move moves[4][4]) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if ((moves[i][j].moveFlags & MOVE_FLAG_EXISTS) && (moves[i][j].moveFlags & MOVE_FLAG_UNK80)) {
                return i;
            }
        }
    }
    return -1;
}

void unk_GetLinkedSequences4(struct Move* moves, struct Move linkedSequences[4][4]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            linkedSequences[i][j].moveFlags = 0;
        }
    }

    moveSetIndex = -1;
    for (j = 0, k = 0; k < 4; j++, k++) {
        if (k == 0 || !(moves[k].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moveSetIndex++;
            j = 0;
        }
        linkedSequences[moveSetIndex][j] = moves[k];
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}


void unk_LinkedSequencesToMoves4(struct Move* moves, struct Move linkedSequences[4][4]) {
    int i, j;
    int movesCopied;
    
    bool8 moves_set[4];
    bool8 moves_enabled[4];

    movesCopied = 0;
    
    // figure out which linked sequences contain set / enabled moves
    for (i = 0; i < 4; i++) {
        moves_set[i] = 0;
        moves_enabled[i] = 0;

        for (j = 0; j < 4; j++) {
            u8 flag;
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag) {
                moves_set[i] = TRUE;
            }
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) {
                moves_enabled[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = linkedSequences[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;
                if (moves_set[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moves_enabled[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                }

                movesCopied++;
                if (movesCopied == 4) {
                    return;
                }
            }
        }
    }
}

// the next two functions are exactly the same
int unk_FindMoveFlag2Unk80InLinkedSequences88(struct Move linkedSequences[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) && (linkedSequences[i][j].moveFlags & MOVE_FLAG_UNK80)) {
                return i;
            }
        }
    }
    
    return -1;
}

// I expect the intent was to check for a different flag in this one
// or the argument is a struct type that does hold the moves as a field
int unk_FindMoveFlag2Unk80InLinkedSequences88_v2(struct Move linkedSequences[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) && (linkedSequences[i][j].moveFlags & MOVE_FLAG_UNK80)) {
                return i;
            }
        }
    }
    
    return -1;
}

// again, the next two functions are exactly the same
// they are also the same as unk_GetLinkedSequences4 but for [8][8] linkedSequences instead of
// [4][4] linkedSequences

// it seems to find all the _actually_ separate moves, and split them
// out into link sequences in the destination linkedSequences
void unk_GetLinkedSequences8(struct Move* moves, struct Move linkedSequences[8][8]) {
    int i, j;
    int k;
    int moveSetIndex;

    // clear out linkedSequences
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            linkedSequences[i][j].moveFlags = 0;
        }
    }

    moveSetIndex = -1;
    for (j = 0, k = 0; k < 8; j++, k++) {
        struct Move* move = &moves[k];
        if (k == 0 || !(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            moveSetIndex++;
            j = 0;
        }
        linkedSequences[moveSetIndex][j] = *move;
        linkedSequences[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
    }
}

void unk_GetLinkedSequences8_v2(struct Move* moves, struct Move linkedSequences[8][8]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            linkedSequences[i][j].moveFlags = 0;
        }
    }
    moveSetIndex = -1;
    for (j = 0, k = 0; k < 8; j++, k++) {
        struct Move* move = &moves[k];
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
void unk_LinkedSequencesToMoves8(struct Move* moves, struct Move linkedSequences[8][8]) {
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
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = linkedSequences[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                }

                movesCopied++;
                if (movesCopied == 8) {
                    return;
                }
            }
        }
    }
}

void unk_LinkedSequencesToMoves8_v2(struct Move* moves, struct Move linkedSequences[8][8]) {
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
            
            if (!(linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= linkedSequences[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_ENABLED_FOR_AI) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (linkedSequences[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = linkedSequences[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED_FOR_AI;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED_FOR_AI;
                }

                movesCopied++;
                if (movesCopied == 8) {
                    return;
                }
            }
        }
    }
}


// the next two are again the same
void RemoveLinkSequenceFromMoves8_v2(struct Move* moves, int index) {
    int i;
    int copiedMoves;
    struct Move moveSet[8];
    
    moves[index].moveFlags = 0;
    for (i = index + 1; i < 8; i++) {
        struct Move* move = &moves[i];

        // TODO: don't do this trickery
        asm("");
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            break;
        }

        move->moveFlags = 0;
    }

    copiedMoves = 0;
    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS) {
            moveSet[copiedMoves++] = moves[i];
        }
    }

    while (copiedMoves < 8) {
        moveSet[copiedMoves++].moveFlags = 0;
    }

    for (i = 0; i < 8; i++) {
        moves[i] = moveSet[i];
    }
}

void RemoveLinkSequenceFromMoves8(struct Move* moves, int index) {
    int i;
    int copiedMoves;
    struct Move moveSet[8];
    
    // remove link sequence (set flags to 0)
    moves[index].moveFlags = 0;
    for (i = index + 1; i < 8; i++) {
        struct Move* move = &moves[i];
        asm("");
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (!(move->moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN)) {
            break;
        }

        move->moveFlags = 0;
    }

    // copy over other moves
    copiedMoves = 0;
    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS) {
            moveSet[copiedMoves++] = moves[i];
        }
    }

    // fill with nonexistent moves
    while (copiedMoves < 8) {
        moveSet[copiedMoves++].moveFlags = 0;
    }

    // copy back to original moves pointer
    for (i = 0; i < 8; i++) {
        moves[i] = moveSet[i];
    }
}

int unk_MoveIDPrintMoveDescription(int a1, u16 moveID, int a3, struct subStruct_203B240** a4) {
    struct Move move;

    InitPokemonMove(&move, moveID);
    return unk_PrintMoveDescription(a1, &move, a3, a4);
}

int unk_MovePrintMoveDescription(int a1, struct Move* move, int a3, struct subStruct_203B240** a4) {
    struct Move newMove;

    CopyAndResetMove(&newMove, move);
    return unk_PrintMoveDescription(a1, &newMove, a3, a4);
}

int unk_PrintMoveDescription(int x, struct Move* move, int a3, struct subStruct_203B240** a4) {
    char* moveDescription;
    int y;
    char buffer[800];
    
    sub_80073B8(a3);
    sub_80928C0(gAvailablePokemonNames, move, 0);
    xxx_format_and_draw(8 * x + 16, 0, gUnknown_8109930, a3, 0);
    y = 19;
    moveDescription = gMovesData[move->id].description;
    if (moveDescription[0] == '*')
    {
        y = 16;
        ++moveDescription;
    }
    xxx_format_and_draw(4, y, moveDescription, a3, 0);
    unk_MovePrintData(move, a3);
    sub_80073E0(a3);
    strcpy(buffer, gMovesData[move->id].description);
    return sub_8097DF0(buffer, a4);
}

void unk_MovePrintData(struct Move* move, int y) {
    u8 type;
    s32 power;
    const char* text;
    
    sub_80078A4(y, 4, 72, 200, 7);
    sub_8092D54(gAvailablePokemonNames, move);
    xxx_format_and_draw(4, 74, gUnknown_810CF00, y, 0);
    xxx_format_and_draw(4, 86, gPtrTypeText, y, 0);
    type = GetMoveType(move);
    text = GetUnformattedTypeString(type);
    xxx_format_and_draw(64, 86, text, y, 0);
    power = GetMoveBasePower(move);
    gUnknown_202DE30 = power;
}

void CopyAndResetMove(struct Move* dest, struct Move* src) {
    if (src->moveFlags & MOVE_FLAG_EXISTS) {
        dest->moveFlags = src->moveFlags;
        dest->moveFlags2 = 0;
        dest->id = src->id;
        dest->PP = gMovesData[src->id].basePP;
        dest->ginseng = src->PP;  // this seems horribly bugged
    }
    else {
        dest->moveFlags = 0;
    }
}

void CopyAndResetMoves(struct Move *destMoves, struct Move *srcMoves) {
    int i;

    for (i = 0; i < 4; i++) {
        if (srcMoves[i].moveFlags & 1) {
            destMoves[i].moveFlags = srcMoves[i].moveFlags;
            destMoves[i].moveFlags2 = 0;
            destMoves[i].id = srcMoves[i].id;
            destMoves[i].PP = gMovesData[srcMoves[i].id].basePP;
            destMoves[i].ginseng = srcMoves[i].PP;
        }
        else {
            destMoves[i].moveFlags = 0;
        }
    }

    // possibly destMoves is not just an array and this is the
    // next struct field
    // this index would be out of bounds after all
    destMoves[4].moveFlags = 0;
}

void CopyBareMoveData(struct Move *destMoves, struct Move *srcMoves) {
    int i;

    for (i = 0; i < 4; i++) {
        destMoves[i].moveFlags = srcMoves[i].moveFlags;
        destMoves[i].id = srcMoves[i].id;
        destMoves[i].PP = srcMoves[i].ginseng;
    }
}

void unk_CopyMoves4To8AndClearFlag2Unk4(struct Move* destMoves, struct Move* srcMoves) {
    int movesCopied;

    movesCopied = 0;
    for (movesCopied = 0; movesCopied < 4; movesCopied++) {
        if (!(srcMoves[movesCopied].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }

        destMoves[movesCopied] = srcMoves[movesCopied];
        destMoves[movesCopied].moveFlags2 &= ~MOVE_FLAG2_UNK4;
    }

    while (movesCopied < 8) {
        destMoves[movesCopied++].moveFlags = 0;
    }
}

void unk_CopyMoves4To8(struct Move* destMoves, struct Move* srcMoves) {
    int movesCopied;

    movesCopied = 0;
    for (movesCopied = 0; movesCopied < 4; movesCopied++) {
        if (!(srcMoves[movesCopied].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }

        destMoves[movesCopied] = srcMoves[movesCopied];
    }

    while (movesCopied < 8) {
        destMoves[movesCopied++].moveFlags = 0;
    }
}

void sub_8094060(struct Move* srcMoves, struct Move* destMoves) {
    int i, j;

    j = 0;
    for (i = 0; i < 8; i++) {
        struct Move* srcMove = &srcMoves[i];
        struct Move* destMove;
        if (!(srcMove->moveFlags & MOVE_FLAG_EXISTS)) {
            continue;
        }
        
        if (j >= 4) {
            break;
        }
        destMove = &destMoves[j];
        *destMove = *srcMove;
        j++;
    }

    while (j < 4) {
        destMoves[j++].moveFlags = 0;
    }
}

void SavePokemonMove(struct unkStruct_8094924 *r0, struct Move *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->id, 9);
    SaveIntegerBits(r0, &move->PP, 7);
}

void RestorePokemonMove(struct unkStruct_8094924 *r0, struct Move *move)
{
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->id, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
}

void SavePokemonMoves(struct unkStruct_8094924 *r0, struct Move *moveSet)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        SavePokemonMove(r0, &moveSet[iVar4]);
    }
}

void RestorePokemonMoves(struct unkStruct_8094924 *r0, struct Move *moveSet)
{
    s32 iVar4;
    for(iVar4 = 0; iVar4 < MAX_MON_MOVES; iVar4++)
    {
        RestorePokemonMove(r0, &moveSet[iVar4]);
    }
}

void sub_8094148(struct unkStruct_8094924 *r0, struct Move *move)
{
    SaveIntegerBits(r0, &move->moveFlags, 4);
    SaveIntegerBits(r0, &move->moveFlags2, 1);
    SaveIntegerBits(r0, &move->id, 9);
    SaveIntegerBits(r0, &move->PP, 7);
    SaveIntegerBits(r0, &move->ginseng, 7);
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

void sub_80941B0(struct unkStruct_8094924 *r0, struct Move *move)
{
    memset(move, 0, sizeof(struct Move));
    RestoreIntegerBits(r0, &move->moveFlags, 4);
    RestoreIntegerBits(r0, &move->moveFlags2, 1);
    RestoreIntegerBits(r0, &move->id, 9);
    RestoreIntegerBits(r0, &move->PP, 7);
    RestoreIntegerBits(r0, &move->ginseng, 7);
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