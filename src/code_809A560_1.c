#include "global.h"
#include "structs/str_3001B64.h"
#include "code_80118A4.h"
#include "code_801D014.h"
#include "credits2.h"
#include "event_flag.h"
#include "flash.h"
#include "friend_list_menu.h"
#include "ground_main.h"
#include "personality_test1.h"

extern struct unkStruct_3001B64 *gUnknown_3001B64;

u32 sub_802E90C();
void sub_802E918();
u32 sub_80282DC(u8 *r0);
void sub_809927C(u8);
void sub_80282FC(void);
void sub_80993C0(u32);
void sub_8001064(void);
void sub_809965C(void);

void sub_809C39C(void) {
    gUnknown_3001B64->unk430 = sub_801D178();
    if(gUnknown_3001B64->unk430 == 3)
        GroundMainGroundRequest(sub_8002694(sub_801D1D4()), 0, -1);
    sub_801D1E0();
}

void sub_809C3D8(void)
{
    gUnknown_3001B64->unk430 = sub_801D178();
    if(gUnknown_3001B64->unk430 == 3)
        GroundMainGroundRequest(sub_8002694(sub_801D1D4()), 0, -1);
    sub_801D1E0();
}

void sub_809C414(void)
{
    u8 val;

    val = sub_802540C();

    if(val != 0)
    {
        gUnknown_3001B64->unk430 = val;
        GroundMainGroundRequest(sub_8002694(val), 0, -1);
    }
    else
{
        gUnknown_3001B64->unk430 = -1;
    }
    CleanFriendListMenu();

}

void sub_809C464(void)
{
	DeleteTestTracker();
	sub_8001064();
	sub_809965C();
}

void sub_809C478(void)
{
    s32 temp;
    s32 temp1;
    
    if(sub_80356A0() == 0x3)
    {
        PlaySound(0x313);
        InitFlash();
        ClearFlashData();
    }
    
    sub_8035758();

    GetScriptVarScenario(3, &temp, &temp1);
    sub_80993C0(0);
}

// https://decomp.me/scratch/WyHAL  - (84.32% matching - Seth)
NAKED
void sub_809C4B0(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tmovs r4, 0x1\n"
	"\tnegs r4, r4\n"
	"\tldr r5, _0809C4FC\n"
	"\tldr r0, [r5]\n"
	"\tmovs r2, 0x86\n"
	"\tlsls r2, 3\n"
	"\tadds r1, r0, r2\n"
	"\tldr r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbne _0809C4DE\n"
	"\tbl sub_803B168\n"
	"\tlsls r0, 16\n"
	"\tldr r1, [r5]\n"
	"\tldr r3, _0809C500\n"
	"\tadds r2, r1, r3\n"
	"\tasrs r4, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r2]\n"
	"\tmovs r0, 0x86\n"
	"\tlsls r0, 3\n"
	"\tadds r1, r0\n"
"_0809C4DE:\n"
	"\tstr r4, [r1]\n"
	"\tbl sub_803B1BC\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r4, r0\n"
	"\tbeq _0809C4F4\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tbl GroundMap_ExecuteEvent\n"
"_0809C4F4:\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0809C4FC: .4byte gUnknown_3001B64\n"
"_0809C500: .4byte 0x000005a4");
}


void sub_809C504(void)
{
    u8 temp;

    if(sub_80282DC(&temp) == 1)
    {
        sub_809927C(temp);
        gUnknown_3001B64->unk430 = 1;
    }
    else
    {
        gUnknown_3001B64->unk430 = -1;
    }
    sub_80282FC();
}

void sub_809C550(void)
{
    u32 ret;
    s32 val;
    
    ret = sub_802E90C();
    val = 0;
    sub_802E918();

    switch(ret)
    {
        case 1:
            if(ScriptVarScenarioBefore(4, 0x1D, 0x3))
               val = 1;
            break;
        case 2:
            if(ScriptVarScenarioBefore(4, 0x1F, 0x2))
                val = 2;
            break;
        case 3:
            if(ScriptVarScenarioBefore(0xB, 0x33, 0x8))
               val = 3;
            break;
    }
    gUnknown_3001B64->unk430 = val;
}
