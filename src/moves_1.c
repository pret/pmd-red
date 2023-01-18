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
extern struct MoveData *gMovesData;

u8 sub_8093468(int param_1, struct PokemonMove* src_struct);
u8 sub_8093400(int param_1, struct PokemonMove* src_struct);
u8 sub_80933D8(int param_1, void* src_struct);
bool8 DoesMoveCharge(u16 move);

void sub_8093784(struct PokemonMove* moves, struct PokemonMove moveSets[4][4]);
void sub_80937E0(struct PokemonMove* moves, struct PokemonMove moveSets[4][4]);
void sub_8093974(struct PokemonMove* moves, struct PokemonMove moveSets[8][8]);
void sub_8093A2C(struct PokemonMove* moves, struct PokemonMove moveSets[8][8]);

void sub_80939D0(struct PokemonMove*, struct PokemonMove[8][8]);
void sub_8093B40(struct PokemonMove*, struct PokemonMove[8][8]);

int sub_8093DE8(int, struct PokemonMove*, int, struct subStruct_203B240**);

extern void sub_80073B8(u32);
void sub_80928C0(u8 *buffer, struct PokemonMove *move, struct unkStruct_80928C0 *param_3);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern void sub_8093E90(struct PokemonMove*, int);  // print something
extern void sub_80073E0(u32);
extern u32 sub_8097DF0(char *, struct subStruct_203B240 **);

extern void sub_80078A4(u32, u32, u32, u32, u32);
extern u8 sub_8092B00(struct PokemonMove*);
extern u32 sub_8092BC0(struct PokemonMove*);
extern u32 gUnknown_202DE30;
extern u8* gPtrTypeText;     // "Type"
extern u8* gUnknown_810CF00; // "Range#=@.$m0 "


int IsMoveSet(int index, struct PokemonMove* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_SET) != 0) {
        return 1;
    }
    return 0;
}

int IsMoveEnabled(int index, struct PokemonMove* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_ENABLED) != 0) {
        return 1;
    }
    return 0;
}

int sub_8093318(int param_1, void* src_struct)
{
    struct PokemonMove dest_struct[8];
    MemoryCopy8((void*)dest_struct, src_struct, 64);
    return sub_8093400(param_1, dest_struct);
}

int sub_809333C(int param_1, void* src_struct)
{
    struct PokemonMove dest_struct[8];
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
int IsMoveNotSet(int index, struct PokemonMove* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & MOVE_FLAG_SET) != 0) {
        return 0;
    }
    return 1;
}

int IsAnyMoveLinked(int unused, struct PokemonMove* moves) {
    int i;
    int counter;

    counter = 0;
    for (i = 0; i < 8; i++) {
        if ((moves[i].moveFlags & MOVE_FLAG_EXISTS) && !(moves[i].moveFlags & MOVE_FLAG_LINKED)) {
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

  if (!sub_8093400(param_1, src_struct)) {
    result = sub_8093468(param_1, src_struct);
  }
  else {
    result = 1;
  }
  return result;
}

u8 sub_8093400(int index, struct PokemonMove* moves) {
    int i;
    const struct PokemonMove *move = &moves[index];
    if (DoesMoveCharge(move->moveID)) {
        return 0;
    }
    
    for (i = index + 1; i < 8; i++) {
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS)) {
            return 0;
        }
        if (DoesMoveCharge(moves[i].moveID)) {
            return 0;
        }
        if (!(moves[i].moveFlags & MOVE_FLAG_LINKED)) {
            moves[i].moveFlags |= MOVE_FLAG_LINKED;
            sub_809371C(moves);
            return 1;
        }
    }
    return 0;
}

NAKED
u8 sub_8093468(int index, struct PokemonMove* moves)
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
"	bl sub_809371C\n"
"	adds r0, r5, 0\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1\n");
}

u8 IsNextMoveLinked(int index, struct PokemonMove* moves) {
    struct PokemonMove* move;
    if (index + 1 >= 8) {
        return 0;
    }
    move = &moves[index + 1];
    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
        return 0;
    if ((move->moveFlags & MOVE_FLAG_LINKED))
        return 1;
    return 0;
}

int ToggleSetMove(int index, struct PokemonMove* moves) {
    struct PokemonMove* move;
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
    sub_809371C(moves);
    return 1;
}

void UnSetMove(int index, struct PokemonMove* moves) {
    struct PokemonMove* move = &moves[index];
    move->moveFlags &= ~MOVE_FLAG_SET;
    sub_809371C(moves);
}

int ToggleMoveEnabled(int index, struct PokemonMove* moves) {
    struct PokemonMove* move = &moves[index];
    move->moveFlags ^= MOVE_FLAG_ENABLED;
    sub_809371C(moves);
    return 1;
}

int GetLinkedSequence(int index, struct PokemonMove* moves, u16* sequenceMoveIDs) {
    int i;
    int linkedSequenceLength;
    struct PokemonMove* move;

    linkedSequenceLength = 1;
    move = &moves[index];
    sequenceMoveIDs[0] = move->moveID;
    for (i = 1; i < 4; i++) {
        sequenceMoveIDs[i] = 0;
    }

    for (index++, sequenceMoveIDs++; index < 8 && linkedSequenceLength <= 3; index++) {
        move = &moves[index];
        if ((move->moveFlags & MOVE_FLAG_LINKED) == 0) {
            return linkedSequenceLength;
        }

        *sequenceMoveIDs++ = move->moveID;
        linkedSequenceLength++;
    }
    return linkedSequenceLength;
}

int sub_80935B8(struct PokemonMove *moves, int index) {
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
        struct PokemonMove *move = &moves[linkSequenceStart];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_LINKED))) {
            break;
        }
        
        linkSequenceStart--;
    }

    // this is so stupid but it works
    isNonTrivialLinkSequence++;isNonTrivialLinkSequence--;

    for (i = linkSequenceStart + 1; i < 4; i++) {
        struct PokemonMove *move = &moves[i];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_LINKED))) {
            break;
        }
        
        isNonTrivialLinkSequence = 1;
    }

    if (!isNonTrivialLinkSequence) {
        return 99;
    }

    v1 = 0;
    while (--i >= linkSequenceStart) {
        struct PokemonMove* move = &moves[i];
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
        struct PokemonMove* move = &moves[i];
        if (!(moves[i].moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        
        if (move->moveFlags & MOVE_FLAG_LINKED) {
            move->moveFlags &= ~MOVE_FLAG_LINKED;
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

void sub_80936D8(struct PokemonMove* moves) {
    struct PokemonMove someStruct[4][4];
    sub_8093784(moves, someStruct);
    sub_80937E0(moves, someStruct);
}

void sub_80936F4(struct PokemonMove* moves) {
    struct PokemonMove moveSets[8][8];
    sub_8093974(moves, moveSets);
    sub_8093A2C(moves, moveSets);
}

void sub_809371C(struct PokemonMove* moves) {
    struct PokemonMove moveSets[8][8];

    sub_80939D0(moves, moveSets);
    sub_8093B40(moves, moveSets);
}

int sub_8093744(struct PokemonMove moves[4][4]) {
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

void sub_8093784(struct PokemonMove* moves, struct PokemonMove moveSets[4][4]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            moveSets[i][j].moveFlags = 0;
        }
    }

    moveSetIndex = -1;
    for (j = 0, k = 0; k < 4; j++, k++) {
        if (k == 0 || !(moves[k].moveFlags & MOVE_FLAG_LINKED)) {
            moveSetIndex++;
            j = 0;
        }
        moveSets[moveSetIndex][j] = moves[k];
        moveSets[moveSetIndex][j].moveFlags &= ~MOVE_FLAG_LINKED;
    }
}


void sub_80937E0(struct PokemonMove* moves, struct PokemonMove moveSets[4][4]) {
    int i, j;
    int movesCopied;
    
    bool8 moveFlags8[4];
    bool8 moveFlags4[4];

    movesCopied = 0;
    
    for (i = 0; i < 4; i++) {
        moveFlags8[i] = 0;
        moveFlags4[i] = 0;

        for (j = 0; j < 4; j++) {
            u8 flag;
            
            if (!(moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= moveSets[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (moveSets[i][j].moveFlags & MOVE_FLAG_ENABLED) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = moveSets[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_LINKED;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_LINKED;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED;
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
int sub_80938F4(struct PokemonMove moveSets[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS) && (moveSets[i][j].moveFlags & MOVE_FLAG_UNK80)) {
                return i;
            }
        }
    }
    
    return -1;
}

// I expect the intent was to check for a different flag in this one
// or the argument is a struct type that does hold the moves as a field
int sub_8093934(struct PokemonMove moveSets[8][8]) {
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS) && (moveSets[i][j].moveFlags & MOVE_FLAG_UNK80)) {
                return i;
            }
        }
    }
    
    return -1;
}

// again, the next two functions are exactly the same
// they are also the same as sub_8093784 but for [8][8] moveSets instead of
// [4][4] moveSets
void sub_8093974(struct PokemonMove* moves, struct PokemonMove moveSets[8][8]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            moveSets[i][j].moveFlags = 0;
        }
    }
    moveSetIndex = -1;
    for (j = 0, k = 0; k < 8; j++, k++) {
        struct PokemonMove* move = &moves[k];
        if (k == 0 || !(move->moveFlags & 2)) {
            moveSetIndex++;
            j = 0;
        }
        moveSets[moveSetIndex][j] = *move;
        moveSets[moveSetIndex][j].moveFlags &= ~2;
    }
}

void sub_80939D0(struct PokemonMove* moves, struct PokemonMove moveSets[8][8]) {
    int i, j;
    int k;
    int moveSetIndex;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            moveSets[i][j].moveFlags = 0;
        }
    }
    moveSetIndex = -1;
    for (j = 0, k = 0; k < 8; j++, k++) {
        struct PokemonMove* move = &moves[k];
        if (k == 0 || !(move->moveFlags & 2)) {
            moveSetIndex++;
            j = 0;
        }
        moveSets[moveSetIndex][j] = *move;
        moveSets[moveSetIndex][j].moveFlags &= ~2;
    }
}

// the next 2 functions are again exactly the same
// these functions are the same as sub_80937E0 but for [8][8] moveSets
// instead of [4][4] moveSets
void sub_8093A2C(struct PokemonMove* moves, struct PokemonMove moveSets[8][8]) {
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
            
            if (!(moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= moveSets[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (moveSets[i][j].moveFlags & MOVE_FLAG_ENABLED) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = moveSets[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_LINKED;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_LINKED;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED;
                }

                movesCopied++;
                if (movesCopied == 8) {
                    return;
                }
            }
        }
    }
}

void sub_8093B40(struct PokemonMove* moves, struct PokemonMove moveSets[8][8]) {
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
            
            if (!(moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS)) {
                continue;
            }

            flag = MOVE_FLAG_SET;
            flag &= moveSets[i][j].moveFlags;
            if (flag) {
                moveFlags8[i] = TRUE;
            }
            if (moveSets[i][j].moveFlags & MOVE_FLAG_ENABLED) {
                moveFlags4[i] = TRUE;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (moveSets[i][j].moveFlags & MOVE_FLAG_EXISTS) {
                moves[movesCopied] = moveSets[i][j];

                if (j == 0) {
                    moves[movesCopied].moveFlags &= ~MOVE_FLAG_LINKED;
                }
                else {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_LINKED;
                }
                
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_SET;
                moves[movesCopied].moveFlags &= ~MOVE_FLAG_ENABLED;
                if (moveFlags8[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_SET;
                }
                if (moveFlags4[i] && (j == 0)) {
                    moves[movesCopied].moveFlags |= MOVE_FLAG_ENABLED;
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
void sub_8093C54(struct PokemonMove* moves, int index) {
    int i;
    int copiedMoves;
    struct PokemonMove moveSet[8];
    
    moves[index].moveFlags = 0;
    for (i = index + 1; i < 8; i++) {
        struct PokemonMove* move = &moves[i];

        // TODO: don't do this trickery
        asm("");
        if (!(move->moveFlags & 1)) {
            break;
        }
        if (!(move->moveFlags & 2)) {
            break;
        }

        move->moveFlags = 0;
    }

    copiedMoves = 0;
    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & 1) {
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

void sub_8093CF8(struct PokemonMove* moves, int index) {
    int i;
    int copiedMoves;
    struct PokemonMove moveSet[8];
    
    moves[index].moveFlags = 0;
    for (i = index + 1; i < 8; i++) {
        struct PokemonMove* move = &moves[i];
        asm("");
        if (!(move->moveFlags & 1)) {
            break;
        }
        if (!(move->moveFlags & 2)) {
            break;
        }

        move->moveFlags = 0;
    }

    copiedMoves = 0;
    for (i = 0; i < 8; i++) {
        if (moves[i].moveFlags & 1) {
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

int sub_8093D9C(int a1, u16 moveID, int a3, struct subStruct_203B240** a4) {
    struct PokemonMove move;

    InitPokemonMove(&move, moveID);
    return sub_8093DE8(a1, &move, a3, a4);
}

int sub_8093DC4(int a1, struct PokemonMove* move, int a3, struct subStruct_203B240** a4) {
    struct PokemonMove newMove;

    CopyAndResetMove(&newMove, move);
    return sub_8093DE8(a1, &newMove, a3, a4);
}

int sub_8093DE8(int x, struct PokemonMove* move, int a3, struct subStruct_203B240** a4) {
    char* moveDescription;
    int y;
    char buffer[800];
    
    sub_80073B8(a3);
    sub_80928C0(gAvailablePokemonNames, move, 0);
    xxx_format_and_draw(8 * x + 16, 0, gUnknown_8109930, a3, 0);
    y = 19;
    moveDescription = gMovesData[move->moveID].descriptionPointer;
    if (moveDescription[0] == '*')
    {
        y = 16;
        ++moveDescription;
    }
    xxx_format_and_draw(4, y, moveDescription, a3, 0);
    sub_8093E90(move, a3);
    sub_80073E0(a3);
    strcpy(buffer, gMovesData[move->moveID].descriptionPointer);
    return sub_8097DF0(buffer, a4);
}

void sub_8093E90(struct PokemonMove* move, int y) {
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
    power = GetMovePower(move);
    gUnknown_202DE30 = power;
}

void CopyAndResetMove(struct PokemonMove* dest, struct PokemonMove* src) {
    if (src->moveFlags & MOVE_FLAG_EXISTS) {
        dest->moveFlags = src->moveFlags;
        dest->moveFlags2 = 0;
        dest->moveID = src->moveID;
        dest->PP = gMovesData[src->moveID].maxPP;
        dest->powerBoost = src->PP;  // this seems horribly bugged
    }
    else {
        dest->moveFlags = 0;
    }
}

void sub_8093F50(struct PokemonMove *destMoves, struct PokemonMove *srcMoves) {
    int i;

    for (i = 0; i < 4; i++) {
        if (srcMoves[i].moveFlags & 1) {
            destMoves[i].moveFlags = srcMoves[i].moveFlags;
            destMoves[i].moveFlags2 = 0;
            destMoves[i].moveID = srcMoves[i].moveID;
            destMoves[i].PP = gMovesData[srcMoves[i].moveID].maxPP;
            destMoves[i].powerBoost = srcMoves[i].PP;
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

void sub_8093FA8(struct PokemonMove *destMoves, struct PokemonMove *srcMoves) {
    int i;

    for (i = 0; i < 4; i++) {
        destMoves[i].moveFlags = srcMoves[i].moveFlags;
        destMoves[i].moveID = srcMoves[i].moveID;
        destMoves[i].PP = srcMoves[i].powerBoost;
    }
}

void sub_8093FC8(struct PokemonMove* destMoves, struct PokemonMove* srcMoves) {
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

void sub_809401C(struct PokemonMove* destMoves, struct PokemonMove* srcMoves) {
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

void sub_8094060(struct PokemonMove* srcMoves, struct PokemonMove* destMoves) {
    int i, j;

    j = 0;
    for (i = 0; i < 8; i++) {
        struct PokemonMove* srcMove = &srcMoves[i];
        struct PokemonMove* destMove;
        if (!(srcMove->moveFlags & 1)) {
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