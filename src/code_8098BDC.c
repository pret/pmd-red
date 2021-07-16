#include "global.h"
#include "play_time.h"
#include "input.h"
#include "debug.h"

extern struct PlayTimeStruct *gPlayTimeRef;
extern u32 gUnknown_20398A8;
extern u32 gUnknown_20398AC;
extern u32 gUnknown_20398B0;
extern u32 gUnknown_20398B4;
extern u8 gUnknown_20398B9;
extern u8 gUnknown_20398BA;
extern u32 gUnknown_20398C0;
extern s16 gUnknown_20398C4;
extern u16 gUnknown_20398BE;
extern u8 gUnknown_203B49D;
extern u8 gUnknown_203B49C;

extern const char gUnknown_8115F5C;
extern const char gUnknown_8115F80;
extern const char gUnknown_8115FA4;
extern const char gUnknown_8115FC8;
extern const char gUnknown_8115FE8;

extern void sub_809B57C();
extern void GroundScript_Unlock();
extern void sub_809D25C();
extern void sub_80A59DC();
extern void sub_809B614();
extern void sub_809CA20();
extern void sub_80A6E80();
extern void sub_8099BE4();
extern void sub_8099744();
extern void sub_8011860();
extern void sub_800CB20();
extern void nullsub_120();
extern void sub_80A5E70();
extern void sub_809B638();
extern void nullsub_106();
extern void sub_80A73EC();
extern void sub_8099750();
extern void sub_8009908();
extern void xxx_call_update_bg_sound_input();
extern void sub_80A6E68();
extern void GroundMap_Action();
extern void nullsub_124();
extern void GroundLives_Action();
extern void GroundObject_Action();
extern void GroundEffect_Action();

extern s32 sub_8001658(u8, u8);
extern s32 sub_8001784(u8, u8, u8);
extern void sub_809CB8C();
extern void sub_8001D88();
extern void sub_80015C0(u8, u8);
extern void sub_80018D8(u8, u8, u32);
extern void sub_800199C(u8, u8, u8, s32);
extern void sub_8098CC8();
extern void sub_809674C();
extern void sub_80961B4();
extern void ClearAllItems_8091FB4();
extern const char *sub_80A2B18(s16);
extern u8 sub_8001CC4(u8, u8, u8);
extern void xxx_inv_unk250_random_8091980(u32);

extern u8 sub_80023E4(u32);
extern void sub_80118C4(u16);
extern u8 sub_809C730();
extern s16 sub_80A2750(s16);

void sub_8098BDC(void)
{
    sub_809B57C();
    GroundScript_Unlock();
    sub_809D25C();
    sub_80A59DC();
    sub_809B614();
    sub_809CA20();
    sub_80A6E80();
    sub_8099BE4();
    sub_8099744();
    sub_8011860();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    nullsub_120();
    sub_80A5E70();
    sub_809B638();
    nullsub_106();
    sub_80A73EC();
    sub_8099750();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_80A6E68();
    GroundMap_Action();
    nullsub_124();
    GroundLives_Action();
    GroundObject_Action();
    GroundEffect_Action();
}

void sub_8098C58(void)
{
    s32 temp;
    sub_80015C0(0, 0x36);
    sub_80015C0(0, 0x39);
    sub_809CB8C();
    sub_8001D88();

    if(sub_8001658(0, 0x2A) != 0)
    {
        temp = sub_8001658(0, 0x29);
        temp++;
        if(temp > 0xF){
            temp = 0;
        }
        sub_80018D8(0, 0x29, temp);
        sub_80018D8(0, 0x2A, 0);
    }

    // TODO this uses r2 but it should be r3
    // Else this matches so nonmatch for now
#ifdef NONMATCHING
    temp = sub_8001784(0, 0x42, 0);
    if(temp <= 0)
    {
        temp = 1;
    }
    sub_800199C(0, 0x42, 0, temp - 1);
#else
    asm_unified("\tmovs r0, 0\n"
	"\tmovs r1, 0x42\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8001784\n"
	"\tadds r3, r0, 0\n"
	"\tcmp r3, 0\n"
	"\tbgt _08098CB4\n"
	"\tmovs r3, 0x1\n"
"_08098CB4:\n"
	"\tsubs r3, 0x1\n"
	"\tmovs r0, 0\n"
	"\tmovs r1, 0x42\n"
	"\tmovs r2, 0\n"
	"\tbl sub_800199C");
#endif

    sub_8098CC8();
}

void sub_8098CC8(void)
{
    u32 temp;
    if(sub_8001CC4(0x3, 0xB, 0) != 0)
    {
        temp = 0;
    }
    else if(sub_8001CC4(0x3, 0xF, 0) != 0)
    {
        temp = 1;
    }
    else if(sub_8001CC4(0x3, 0x12, 0) != 0)
    {
        temp = 2;
    }
    else
    {
        temp = 3;
    }
    xxx_inv_unk250_random_8091980(temp);
    sub_809674C();
    sub_80961B4();
    ClearAllItems_8091FB4();
}

bool8 sub_8098D1C(s16 r0, u32 r1, u32 r2)
{
    s32 temp;
    temp = r0; // force a asr shift
    if(gUnknown_20398A8 == 0)
    {
        Log(NULL, &gUnknown_8115F5C, temp, r2);
        gUnknown_20398A8 = 1;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r2;
        gUnknown_20398B4 = 2;
        gUnknown_20398BE = temp;
        gUnknown_20398C0 = r1;
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8098D80(u32 r0)
{
    if(gUnknown_20398A8 == 0)
    {
        gUnknown_20398A8 = 3;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r0;
        sub_809C730();
        if(sub_80023E4(0xD) == 0)
        {
            sub_80118C4(r0);
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8098DCC(u32 r0)
{
    if(gUnknown_20398A8 == 0)
    {
        gUnknown_20398A8 = 4;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r0;
        sub_809C730();
        if(sub_80023E4(0xD) == 0)
        {
            sub_80118C4(r0);
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8098E18(s16 r0, u32 r1)
{
    s32 r2 = r0, r5 = r2;
    if(gUnknown_20398A8 == 0)
    {
        Log(NULL, &gUnknown_8115F80, r2, r1);
        if(gUnknown_203B49D != 0)
        {
            gUnknown_20398A8 = 7;
        }
        else
        {
            if(gUnknown_203B49C == 0)
            {
                gUnknown_20398C4 = r5;
            }
            switch(sub_80A2750(gUnknown_20398C4))
            {
                case 4: gUnknown_20398A8 = 8; break;
                case 1: gUnknown_20398A8 = 5; break;
                case 2: gUnknown_20398A8 = 6; break;
            }
        }
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r1;
        sub_809C730();
        return TRUE;
    }
    return FALSE;
}

// Unused
u32 sub_8098EB0(u32 r0)
{
    if(gUnknown_20398A8 == 0)
    {
        if(gUnknown_203B49D != 0)
        {
            Log(NULL, &gUnknown_8115FA4, r0);
            gUnknown_20398A8 = 7;
            gUnknown_20398AC = 1;
            gUnknown_20398B0 = r0;
            sub_809C730();
            return 1;
        }
    }
    return 0;
}

u32 sub_8098F00(u32 r0)
{
    if(gUnknown_20398A8 == 0)
    {
        Log(NULL, &gUnknown_8115FC8, r0);
        gUnknown_20398A8 = 9;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r0;
        sub_809C730();
        return 1;
    }
    return 0;
}

u32 sub_8098F44(u32 r0)
{
    if(gUnknown_20398A8 == 0)
    {
        Log(NULL, &gUnknown_8115FE8, r0);
        gUnknown_20398A8 = 10;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r0;
        sub_809C730();
        return 1;
    }
    return 0;
}

u32 sub_8098F88(void)
{
    return gUnknown_20398B9;
}

u32 sub_8098F94(void)
{
    return gUnknown_20398BA;
}

s16 sub_8098FA0(void)
{
    return sub_8001658(0, 0x11);
}

const char  *sub_8098FB4(void)
{
    return sub_80A2B18(sub_8001658(0, 0x11));
}
