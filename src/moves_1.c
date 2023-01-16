#include "global.h"
#include "code_8092334.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"

u8 sub_8093468(int param_1, struct PokemonMove* src_struct);
u8 sub_8093400(int param_1, struct PokemonMove* src_struct);
u8 sub_80933D8(int param_1, void* src_struct);
bool8 DoesMoveCharge(u16 move);

// second arg should be some sort of struct pointer
void sub_8093784(int, u8*);
void sub_80937E0(int, u8*);
void sub_8093974(int, u8*);
void sub_8093A2C(int, u8*);

void sub_80939D0(struct PokemonMove*, struct PokemonMove*);
void sub_8093B40(struct PokemonMove*, struct PokemonMove*);


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

int sub_8093560(int index, struct PokemonMove* moves, u16* dest) {
    int i;
    int counter;
    struct PokemonMove* move;

    counter = 1;
    move = &moves[index];
    dest[0] = move->moveID;
    for (i = 1; i < 4; i++) {
        dest[i] = 0;
    }

    for (index++, dest++; index < 8 && counter <= 3; index++) {
        move = &moves[index];
        if ((move->moveFlags & MOVE_FLAG_LINKED) == 0) {
            return counter;
        }

        *dest++ = move->moveID;
        counter++;
    }
    return counter;
}

int sub_80935B8(struct PokemonMove *moves, int index) {
    int i;
    int last_index;
    int for_loop_any1;
    int any_move_linked;
    int pp;
    int v1;
    
    pp = 99;
    any_move_linked = 0;
    for_loop_any1 = 0;

    last_index = index;
    while (last_index >= 0) {
        struct PokemonMove *move = &moves[last_index];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_LINKED))) {
            break;
        }
        
        last_index--;
    }

    // this is so stupid but it works
    for_loop_any1++;for_loop_any1--;

    for (i = last_index + 1; i < 4; i++) {
        struct PokemonMove *move = &moves[i];
        if (!((move->moveFlags & MOVE_FLAG_EXISTS) && (move->moveFlags & MOVE_FLAG_LINKED))) {
            break;
        }
        
        for_loop_any1 = 1;
    }

    if (!for_loop_any1) {
        return 99;
    }

    v1 = 0;
    while (--i >= last_index) {
        struct PokemonMove* move = &moves[i];
        if (!(move->moveFlags & MOVE_FLAG_EXISTS)) {
            break;
        }
        if (pp > move->PP) {
            pp = move->PP;
        }
        if (!move->PP) {
            v1 = 1;
        }
        if (move->moveFlags2 & MOVE_FLAG_REPLACE) {
            v1 = 1;
        }
    }

    if (!v1) {
        return pp;
    }

    for (i = last_index + 1; i < 4; i++) {
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

void sub_80936D8(int index) {
    u8 someStruct[0x80];
    sub_8093784(index, someStruct);
    sub_80937E0(index, someStruct);
}

void sub_80936F4(int index) {
    u8 someStruct[0x80 * 4];
    sub_8093974(index, someStruct);
    sub_8093A2C(index, someStruct);
}

void sub_809371C(struct PokemonMove* move) {
    struct PokemonMove moves[64];

    sub_80939D0(move, moves);
    sub_8093B40(move, moves);
}

int sub_8093744(struct PokemonMove moves[4][4], int index) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if ((moves[i][j].moveFlags & 1) && (moves[i][j].moveFlags & 0x80)) {
                return i;
            }
        }
    }
    return -1;
}

