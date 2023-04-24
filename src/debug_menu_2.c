#include "global.h"
#include "memory.h"
#include "pokemon.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "debug_menu.h"
#include "menu_input.h"

extern struct unkStruct_203B3F8 *gUnknown_203B3F8;
extern struct UnkTextStruct2 gUnknown_80E7ED4;
extern struct UnkTextStruct2 gUnknown_80E7EEC;
extern struct UnkTextStruct2 gUnknown_80E7F04;
extern u8 gDebug_NumberText2[];

extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);
extern void sub_8023DA4(void);
extern void xxx_call_draw_string(u32, u32, u8 *, u32, u32);

void sub_803ACD0(u32);
extern void sub_803ACE8();
extern void sub_803AD88();
extern void sub_803AF38();
extern void sub_803AF88();
extern void sub_803AFE8();
extern void sub_803B034();
extern void sub_8023868(u32, u32, u32, u32);
extern void sub_8023B7C(u32);
extern void sub_8023DA4();
extern void sub_8013AA0(u32 *);
extern void sub_803AE58();
extern void sub_801602C(u32, u8 *);

extern void sub_803AEB0();

u32 sub_803AC24(void)
{
    gUnknown_203B3F8 = MemoryAlloc(sizeof(struct unkStruct_203B3F8), 8);
    sub_803ACD0(0);
    return 1;
}

u32 sub_803AC48(void)
{
    switch(gUnknown_203B3F8->state)
    {
        case 0:
            sub_803ACD0(1);
            break;
        case 1:
        case 2:
            sub_803AF38();
            break;
        case 3:
            sub_803AF88();
            break;
        case 5:
            sub_803AFE8();
            break;
        case 6:
            sub_803B034();
            break;
        case 4:
        case 7:
        default:
            return 3;
    }
    return 0;
}

void sub_803ACB4(void)
{
    if(gUnknown_203B3F8 != NULL)
    {
        MemoryFree(gUnknown_203B3F8);
        gUnknown_203B3F8 = NULL;
    }
}

void sub_803ACD0(u32 newState)
{
    gUnknown_203B3F8->state = newState;
    sub_803ACE8();
    sub_803AD88();
}

void sub_803ACE8(void)
{
    s32 index;
    sub_8006518(gUnknown_203B3F8->unkE0);
    switch(gUnknown_203B3F8->state)
    {
        case 3:
            sub_803AEB0();
            gUnknown_203B3F8->unkE0[2] = gUnknown_80E7EEC;
            sub_8012CAC(&gUnknown_203B3F8->unkE0[2], gUnknown_203B3F8->unk90);
            break;
        case 5:
            gUnknown_203B3F8->unkE0[3] = gUnknown_80E7F04;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B3F8->unkE0[index] = gUnknown_80E7ED4;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B3F8->unkE0, 1, 1);
}

void sub_803AD88(void)
{
    switch(gUnknown_203B3F8->state)
    {
        case 1:
            sub_8023868(1, 0, 0, 10);
            break;
        case 2:
            sub_8023B7C(1);
            break;
        case 3:
            sub_8023DA4();
            sub_8012D60(&gUnknown_203B3F8->unk10, gUnknown_203B3F8->unk90, 0, gUnknown_203B3F8->unkD0, gUnknown_203B3F8->menuAction, 2);
            break;
        case 5:
            gUnknown_203B3F8->unk70 = 3;
            gUnknown_203B3F8->unk68 = 1;
            gUnknown_203B3F8->unk6C = 0x64;
            gUnknown_203B3F8->unk64 = gUnknown_203B3F8->pokemon->unkHasNextStage;
            gUnknown_203B3F8->unk74 = 3;
            gUnknown_203B3F8->unk78 = &gUnknown_203B3F8->unkE0[3];
            gUnknown_203B3F8->unk7C = 0x2C;
            gUnknown_203B3F8->unk80 = 0x12;
            sub_8013AA0(&gUnknown_203B3F8->unk60);
            sub_803AE58();
            break;
        case 6:
            sub_801602C(2, gUnknown_203B3F8->pokemon->name);
        case 0:
        case 4:
        case 7:
        default:
            break;

    }
}

void sub_803AE58(void)
{
    sub_8008C54(gUnknown_203B3F8->unk74);
    sub_80073B8(gUnknown_203B3F8->unk74);
    xxx_call_draw_string(4, 0, gDebug_NumberText2, gUnknown_203B3F8->unk74, 0);
    sub_8013C68(&gUnknown_203B3F8->unk60);
    sub_80073E0(gUnknown_203B3F8->unk74);
    sub_8023DA4();
    sub_8012EA4(&gUnknown_203B3F8->unk10, 0);
}
