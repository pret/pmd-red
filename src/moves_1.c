#include "global.h"
#include "code_8092334.h"
#include "memory.h"
#include "moves.h"
#include "pokemon.h"

u8 sub_8093468(int param_1, void* src_struct);
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
    return sub_8093400(param_1, (struct PokemonMove*)dest_struct);
}

int sub_809333C(int param_1, void* src_struct)
{
    u8 dest_struct[64];
    MemoryCopy8(dest_struct, src_struct, 64);
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
