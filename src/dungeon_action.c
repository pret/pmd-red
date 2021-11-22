#include "global.h"
#include "dungeon_action.h"

void SetAction(u16 *actionPointer, u16 action)
{
    u8 zero = 0;
    u8 *actionPointerU8 = (u8*) actionPointer;
    *actionPointer = action;
    // actionUseIndex
    actionPointerU8[4] = zero;
    // unk50
    actionPointerU8[0xC] = zero;
}
