#include "global.h"
#include "code_8092334.h"
#include "code_809447C.h"
#include "item.h"
#include "moves.h"

struct unkStruct_8113080
{
    u8 unk0;
    u8 *unk4; // some string
};

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[];
extern u8 *gUnknown_811383C[];
extern struct unkStruct_8113080 gUnknown_8113080[];

void sub_80928C0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *param_3);
extern void xxx_format_string(const char *, u8 *, void *, u32);

void sub_809447C(struct unkStruct_8094924 *r0, u8 *r1)
{
    RestoreIntegerBits(r0, r1, 0x10);
    RestoreIntegerBits(r0, r1 + 2, 0x10);
}

void sub_809449C(struct unkStruct_8094924 *r0, u8 *r1)
{
    SaveIntegerBits(r0, r1, 0x10);
    SaveIntegerBits(r0, r1 + 2, 0x10);
}

void sub_80944BC(s16 moveID, u8 *arg2)
{
    u16 moveID_u16;
    s32 moveID_s32 = moveID;
    struct Move stack;

    if (moveID_s32 < 0x1F4) {
        // Needed this cast/variable to match
        moveID_u16 = moveID_s32;
        sub_8092AA8(&stack, moveID_u16);
        sub_80928C0(gUnknown_202DE58, &stack, NULL);
        xxx_format_string(*gUnknown_811383C, arg2, arg2 + 200, 0);
    } else {
        strncpy(arg2, gUnknown_8113080[moveID - 0x1F4].unk4, 200);
    }
}

u8 sub_8094528(s16 moveID)
{
    if(moveID < 0x1F4)
    {
        return 1;
    }
    else
    {
        return gUnknown_8113080[moveID  - 0x1F4].unk0;
    }
}

