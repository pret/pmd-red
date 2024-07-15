#include "global.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_80A26CC.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_main.h"
#include "ground_map_2.h"
#include "play_time.h"

EWRAM_DATA u32 gUnknown_20398A8 = {0};
EWRAM_DATA u32 gUnknown_20398AC = {0};
EWRAM_DATA u32 gUnknown_20398B0 = {0};
EWRAM_DATA u32 gUnknown_20398B4 = {0};
EWRAM_DATA u8 gUnknown_20398B8 = {0};
EWRAM_DATA bool8 gUnknown_20398B9 = {0};
EWRAM_DATA bool8 gUnknown_20398BA = {0};
UNUSED EWRAM_DATA static u8 gUnknown_20398BB = {0};
EWRAM_DATA u16 gUnknown_20398BC = {0};
EWRAM_DATA u16 gUnknown_20398BE = {0};
EWRAM_DATA u32 gUnknown_20398C0 = {0};
EWRAM_DATA s16 gUnknown_20398C4 = {0};

EWRAM_DATA_2 u8 gUnknown_203B49C = {0};
EWRAM_DATA_2 u8 gUnknown_203B49D = {0};

#include "data/ground_main.h"

extern unkStruct_811BAF4 gUnknown_811BAF4[10];

extern void sub_809B57C();
extern void GroundScript_Unlock();
extern void sub_809D25C();
extern void sub_80A59DC();
extern void sub_809B614();
extern void sub_809CA20();
extern void sub_80A6E80();
extern void sub_8099BE4();
extern void sub_8099744();
extern void nullsub_120();
extern void sub_809B638();
extern void nullsub_106();
extern void sub_80A73EC();
extern void sub_8099750();
extern void sub_80A6E68();
extern void GroundMap_Action();
extern void nullsub_124();
extern void GroundLives_Action();
extern void GroundObject_Action();
extern void GroundEffect_Action();

extern s32 sub_8001784(u8, u8, u8);
extern void sub_809CB8C();
extern void sub_80018D8(u8, u8, u32);
extern void sub_800199C(u8, u8, u8, s32);
extern void sub_8098CC8();
extern void GeneratePelipperJobs();
extern void sub_80961B4();
extern void ClearAllItems_8091FB4();
extern void ChooseKecleonShopInventory(u32);
extern u8 sub_809C730();

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
    s32 temp, temp2;
    sub_80015C0(0, 54);
    sub_80015C0(0, 57);
    sub_809CB8C();
    sub_8001D88();

    if (sub_8001658(0, 42) != 0) {
        temp = sub_8001658(0, 41);
        temp++;
        if (temp > 15)
            temp = 0;

        sub_80018D8(0, 41, temp);
        sub_80018D8(0, 42, 0);
    }

    temp2 = sub_8001784(0, 66, 0);
    if (temp2 <= 0)
        temp2 = 1;
    temp2--;
    sub_800199C(0, 66, 0, temp2);

    sub_8098CC8();
}

void sub_8098CC8(void)
{
    u32 temp;
    if(sub_8001CC4(0x3, 0xB, 0))
    {
        temp = 0;
    }
    else if(sub_8001CC4(0x3, 0xF, 0))
    {
        temp = 1;
    }
    else if(sub_8001CC4(0x3, 0x12, 0))
    {
        temp = 2;
    }
    else
    {
        temp = 3;
    }
    ChooseKecleonShopInventory(temp);
    GeneratePelipperJobs();
    sub_80961B4();
    ClearAllItems_8091FB4();
}

bool8 GroundMainGroundRequest(s16 r0, u32 r1, u32 r2)
{
    s32 temp;
    temp = r0; // force a asr shift
    if(gUnknown_20398A8 == 0)
    {
        Log(0, sFmtGroundRequest, temp, r2);
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

bool8 sub_8098D80(u32 speed)
{
    if(gUnknown_20398A8 == 0)
    {
        gUnknown_20398A8 = 3;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = speed;
        sub_809C730();
        if(!sub_80023E4(0xD))
        {
            FadeOutAllMusic(speed);
        }
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8098DCC(u32 speed)
{
    if(gUnknown_20398A8 == 0)
    {
        gUnknown_20398A8 = 4;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = speed;
        sub_809C730();
        if(!sub_80023E4(0xD))
        {
            FadeOutAllMusic(speed);
        }
        return TRUE;
    }
    return FALSE;
}

bool8 GroundMainRescueRequest(s16 r0, u32 r1)
{
    s32 r2 = r0, r5 = r2;
    if(gUnknown_20398A8 == 0)
    {
        Log(0, sFmtRescueRequest, r2, r1);
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

UNUSED static bool8 GroundMainUserRescueRequest(u32 r0)
{
    if (gUnknown_20398A8 == 0) {
        if(gUnknown_203B49D != 0) {
            Log(0, sFmtUserRescueRequest, r0);
            gUnknown_20398A8 = 7;
            gUnknown_20398AC = 1;
            gUnknown_20398B0 = r0;
            sub_809C730();
            return TRUE;
        }
    }
    return FALSE;
}

bool32 GroundMainGameEndRequest(u32 r0)
{
    if (gUnknown_20398A8 == 0) {
        Log(0, sFmtGameEndRequest, r0);
        gUnknown_20398A8 = 9;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r0;
        sub_809C730();
        return TRUE;
    }
    return FALSE;
}

bool32 GroundMainGameCancelRequest(u32 r0)
{
    if (gUnknown_20398A8 == 0) {
        Log(0, sFmtGameCancelRequest, r0);
        gUnknown_20398A8 = 10;
        gUnknown_20398AC = 1;
        gUnknown_20398B0 = r0;
        sub_809C730();
        return TRUE;
    }
    return FALSE;
}

bool8 sub_8098F88(void)
{
    return gUnknown_20398B9;
}

bool8 sub_8098F94(void)
{
    return gUnknown_20398BA;
}

s16 sub_8098FA0(void)
{
    return sub_8001658(0, 0x11);
}

const char *sub_8098FB4(void)
{
    return sub_80A2B18(sub_8001658(0, 0x11));
}

s16 sub_8098FCC(u32 unused)
{
  s32 iVar4;
  s32 iVar5;
  s32 iVar6;
  const unkStruct_80A2608 *iVar3;

  iVar5 = (s16)sub_8001658(0,0x13);
  iVar6 = iVar5;
  if (iVar5 == -1) return 0xC;

  if (iVar5 == 0x51)
    iVar4 = (s16)sub_8001658(0,0x14);
  else
    iVar4 = iVar6;

  iVar3 = sub_80A2608(iVar4);
  if (gUnknown_20398B4 == 9) {
    return iVar3->unk2;
  }
  switch((s16)(iVar3->unk4 - 0xb2)) {
    case 0:
        if (sub_8001D44(3,2,-1) != 0) return 0xc;
        break;
    case 0xf:
    case 0x11:
    case 0x14:
    case 0x17:
        if (!sub_80023E4(5)) return 0xC;
        break;
    default:
        break;
  }
    return iVar3->unk4;
}

const char *sub_80990B8(void)
{
    s16 index;
    index = sub_8098FCC(0xB);
    if(index != -1)
    {
        return sub_80A2B18(gUnknown_811BAF4[index].unk2);
    }
    else
    {
        return sub_8098FB4();
    }
}
