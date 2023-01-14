#include "global.h"
#include "code_8092334.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"

u8 sub_8093468(int param_1, struct PokemonMove* src_struct);
u8 sub_8093400(int param_1, struct PokemonMove* src_struct);
u8 sub_80933D8(int param_1, void* src_struct);
bool8 DoesMoveCharge(u16 move);
void sub_809371C(struct PokemonMove*);

int sub_80932E0(int index, struct PokemonMove* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & 8) != 0) {
        return 1;
    }
    return 0;
}

int sub_80932FC(int index, struct PokemonMove* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & 4) != 0) {
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

int sub_8093384(int index, struct PokemonMove* struct_ptr)
{
    if ((struct_ptr[index].moveFlags & 8) != 0) {
        return 0;
    }
    return 1;
}

int sub_80933A0(int unused, struct PokemonMove* moves) {
    int i;
    int counter;

    counter = 0;
    for (i = 0; i < 8; i++) {
        if ((moves[i].moveFlags & 1) && !(moves[i].moveFlags & 2)) {
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
  int result; // r0

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
        if (!(moves[i].moveFlags & 1)) {
            return 0;
        }
        if (DoesMoveCharge(moves[i].moveID)) {
            return 0;
        }
        if (!(moves[i].moveFlags & 2)) {
            moves[i].moveFlags |= 2;
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

u8 sub_80934B0(int index, struct PokemonMove* moves) {
    struct PokemonMove* move;
    if (index + 1 >= 8) {
        return 0;
    }
    move = &moves[index + 1];
    if (!(move->moveFlags & 1))
        return 0;
    if ((move->moveFlags & 2))
        return 1;
    return 0;
}

int sub_80934DC(int index, struct PokemonMove* moves) {
    struct PokemonMove* move;
    u8 flags;
    int i;

    move = &moves[index];
    if (moves[index].moveFlags & 8) {
        flags = move->moveFlags & ~8;
    }
    else {
        for (i = 0; i < 4; i++) {
            if (moves[i].moveFlags & 1) {
                moves[i].moveFlags &= ~8;
            }
        }
        flags = move->moveFlags | 8;
    }
    move->moveFlags = flags;
    sub_809371C(moves);
    return 1;
}