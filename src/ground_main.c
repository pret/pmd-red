#include "global.h"
#include "structs/str_wonder_mail.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_80A26CC.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_main.h"
#include "ground_map_2.h"
#include "play_time.h"

// size: 0x88
struct unkStruct_20398C8
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 fill5[0xB - 0x5];
    u8 unkB;
    u8 unkC;
    u8 unkD;
    WonderMailSub unk10;
    PokemonStruct1 unk18;
    u8 fill70[0x88 - 0x70];
};


EWRAM_DATA u32 gUnknown_20398A8 = {0};
EWRAM_DATA u32 gUnknown_20398AC = {0};
EWRAM_DATA u32 gUnknown_20398B0 = {0};
EWRAM_DATA u32 gUnknown_20398B4 = {0};
EWRAM_DATA u8 gUnknown_20398B8 = {0};
EWRAM_DATA bool8 gUnknown_20398B9 = {0};
EWRAM_DATA bool8 gScriptMode = {0};
UNUSED EWRAM_DATA static u8 gUnknown_20398BB = {0};
EWRAM_DATA u16 gUnknown_20398BC = {0};
EWRAM_DATA u16 gUnknown_20398BE = {0};
EWRAM_DATA u32 gUnknown_20398C0 = {0};
EWRAM_DATA s16 gUnknown_20398C4 = {0};
struct unkStruct_20398C8 gUnknown_20398C8;
extern u8 gUnknown_2039950;

EWRAM_INIT bool8 gUnknown_203B49C = {0};
EWRAM_INIT u8 gUnknown_203B49D = {0};

#include "data/ground_main.h"

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

extern void sub_809CB8C();
extern void sub_8098CC8();
extern void GeneratePelipperJobs();
extern void sub_80961B4();
extern void ClearAllItems_8091FB4();
extern void ChooseKecleonShopInventory(u32);
extern u8 sub_809C730();
extern void sub_8095494(WonderMailSub *param_1, u8 index);

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
    ClearScriptVarArray(NULL, GROUND_LOCAL);
    ClearScriptVarArray(NULL, EVENT_LOCAL);
    sub_809CB8C();
    sub_8001D88();

    if (GetScriptVarValue(NULL, FLAG_KIND_CHANGE_REQUEST) != 0) {
        temp = GetScriptVarValue(NULL, FLAG_KIND);
        temp++;
        if (temp > 15)
            temp = 0;

        SetScriptVarValue(NULL, FLAG_KIND, temp);
        SetScriptVarValue(NULL, FLAG_KIND_CHANGE_REQUEST, 0);
    }

    temp2 = GetScriptVarArrayValue(NULL, EVENT_GONBE, 0);
    if (temp2 <= 0)
        temp2 = 1;
    temp2--;
    SetScriptVarArrayValue(NULL, EVENT_GONBE, 0, temp2);

    sub_8098CC8();
}

void sub_8098CC8(void)
{
    u32 temp;
    if(ScriptVarScenarioBefore(SCENARIO_MAIN, 0xB, 0))
    {
        temp = 0;
    }
    else if(ScriptVarScenarioBefore(SCENARIO_MAIN, 0xF, 0))
    {
        temp = 1;
    }
    else if(ScriptVarScenarioBefore(SCENARIO_MAIN, 0x12, 0))
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

bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2)
{
    s32 temp = (s16) r0; // force a asr shift
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

bool8 GroundMainRescueRequest(s32 r0, s32 r1)
{
    s32 r2 = (s16) r0;
    s32 r5 = r2;
    if(gUnknown_20398A8 == 0)
    {
        Log(0, sFmtRescueRequest, r2, r1);
        if(gUnknown_203B49D != 0)
        {
            gUnknown_20398A8 = 7;
        }
        else
        {
            if(!gUnknown_203B49C)
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

bool8 GetScriptMode(void)
{
    return gScriptMode;
}

s16 sub_8098FA0(void)
{
    return GetScriptVarValue(NULL, GROUND_PLACE);
}

const char *sub_8098FB4(void)
{
    return sub_80A2B18(GetScriptVarValue(NULL, GROUND_PLACE));
}

s16 sub_8098FCC(u32 unused)
{
  s32 iVar4;
  s32 iVar5;
  s32 iVar6;
  const DungeonInfo *iVar3;

  iVar5 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
  iVar6 = iVar5;
  if (iVar5 == -1) return 0xC;

  if (iVar5 == 0x51)
    iVar4 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER_INDEX);
  else
    iVar4 = iVar6;

  iVar3 = GetDungeonInfo_80A2608(iVar4);
  if (gUnknown_20398B4 == 9) {
    return iVar3->unk2;
  }
  switch((s16)(iVar3->unk4 - 0xb2)) {
    case 0:
        if (ScriptVarScenarioAfter(SCENARIO_MAIN,2,-1) != 0) return 0xc;
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
        return sub_80A2B18(gGroundConversion_811BAF4[index].unk2);
    }
    else
    {
        return sub_8098FB4();
    }
}

// https://decomp.me/scratch/1QxJZ

NAKED
u8 sub_80990EC(struct unkStruct_20398C8 *param_1, s16 param_2)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tsub sp, 0x80\n"
	"\tadds r7, r0, 0\n"
	"\tlsls r1, 16\n"
	"\tasrs r4, r1, 16\n"
	"\tadds r0, r4, 0\n"
	"\tbl GetDungeonInfo_80A2608\n"
	"\tmov r8, r0\n"
	"\tldrb r0, [r0, 0xC]\n"
	"\tmovs r5, 0\n"
	"\tstrb r0, [r7]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r7, 0x1]\n"
	"\tstrb r5, [r7, 0xC]\n"
	"\tadds r0, r4, 0\n"
	"\tbl sub_80A2750\n"
	"\tlsls r0, 16\n"
	"\tasrs r6, r0, 16\n"
	"\tcmp r6, 0x2\n"
	"\tbeq _080991C8\n"
	"\tcmp r6, 0x2\n"
	"\tbgt _08099126\n"
	"\tcmp r6, 0x1\n"
	"\tbeq _0809912C\n"
	"\tb _080991CA\n"
"_08099126:\n"
	"\tcmp r6, 0x4\n"
	"\tbeq _080991C4\n"
	"\tb _080991CA\n"
"_0809912C:\n"
	"\tmovs r1, 0\n"
	"\tstrb r5, [r7, 0xB]\n"
	"\tadds r0, r4, 0\n"
	"\tsubs r0, 0x25\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x2\n"
	"\tbhi _0809913E\n"
	"\tmovs r1, 0x1\n"
"_0809913E:\n"
	"\tcmp r1, 0\n"
	"\tbeq _080991CA\n"
	"\tstrb r6, [r7, 0xC]\n"
	"\tmov r0, sp\n"
	"\tmovs r1, 0x5B\n"
	"\tbl sub_80A8EC0\n"
	"\tadd r4, sp, 0x18\n"
	"\tadds r0, r4, 0\n"
	"\tmov r1, sp\n"
	"\tmovs r2, 0xA\n"
	"\tbl BoundedCopyStringtoBuffer\n"
	"\tadd r5, sp, 0x30\n"
	"\tstr r4, [sp, 0x58]\n"
	"\tadd r1, sp, 0x5C\n"
	"\tmovs r2, 0\n"
	"\tmovs r0, 0x5E\n"
	"\tstrh r0, [r1]\n"
	"\tmov r0, sp\n"
	"\tadds r0, 0x5E\n"
	"\tstrb r2, [r0]\n"
	"\tadd r0, sp, 0x60\n"
	"\tmovs r1, 0x47\n"
	"\tstrb r1, [r0]\n"
	"\tstrb r2, [r0, 0x1]\n"
	"\tadd r1, sp, 0x64\n"
	"\tmovs r0, 0x82\n"
	"\tlsls r0, 1\n"
	"\tstrh r0, [r1]\n"
	"\tmovs r0, 0xE0\n"
	"\tstrh r0, [r1, 0x2]\n"
	"\tmovs r0, 0xAC\n"
	"\tstrh r0, [r1, 0x4]\n"
	"\tmovs r0, 0xBE\n"
	"\tstrh r0, [r1, 0x6]\n"
	"\tadd r1, sp, 0x6C\n"
	"\tmovs r0, 0x50\n"
	"\tstrh r0, [r1]\n"
	"\tmov r0, sp\n"
	"\tadds r0, 0x6E\n"
	"\tmovs r2, 0xF\n"
	"\tstrh r2, [r0]\n"
	"\tadd r0, sp, 0x70\n"
	"\tstrh r6, [r0]\n"
	"\tadds r0, 0x2\n"
	"\tmovs r1, 0x19\n"
	"\tstrh r1, [r0]\n"
	"\tstrh r1, [r0, 0x2]\n"
	"\tadds r0, 0x4\n"
	"\tstrh r2, [r0]\n"
	"\tstrh r2, [r0, 0x2]\n"
	"\tldr r0, _080991C0\n"
	"\tstr r0, [sp, 0x7C]\n"
	"\tadd r1, sp, 0x58\n"
	"\tadds r0, r5, 0\n"
	"\tmovs r2, 0x28\n"
	"\tbl memcpy\n"
	"\tadds r0, r7, 0\n"
	"\tadds r0, 0x18\n"
	"\tadds r1, r5, 0\n"
	"\tbl sub_808D144\n"
	"\tb _080991CA\n"
	"\t.align 2, 0\n"
"_080991C0: .4byte 0x000061a8\n"
"_080991C4:\n"
	"\tstrb r5, [r7, 0xB]\n"
	"\tb _080991CA\n"
"_080991C8:\n"
	"\tstrb r6, [r7, 0xB]\n"
"_080991CA:\n"
	"\tmovs r0, 0\n"
	"\tstrb r0, [r7, 0x4]\n"
	"\tstrb r0, [r7, 0xD]\n"
	"\tmov r1, r8\n"
	"\tldrb r0, [r1, 0x11]\n"
	"\tadd sp, 0x80\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r1}\n"
	"\tbx r1");
}

u8 sub_80991E0(struct unkStruct_20398C8 *param_1,short *param_2)
{
    *param_2 = gUnknown_20398C4;
    if (gUnknown_203B49C) {
        memcpy(param_1, &gUnknown_20398C8, sizeof(struct unkStruct_20398C8));
        return TRUE;   
    }
    else {
        return sub_80990EC(param_1,gUnknown_20398C4);
    }
}

void sub_8099220(struct unkStruct_20398C8 *param_1, s16 param_2)
{
    s32 param_2_s32 = (s16)param_2;
    if (param_1 != NULL) 
    {
        gUnknown_203B49C = TRUE;
        gUnknown_203B49D = 0;
        gUnknown_20398C4 = param_2_s32;
        memcpy(&gUnknown_20398C8, param_1, sizeof(struct unkStruct_20398C8));
    }
    else {
        gUnknown_203B49C = FALSE;
        gUnknown_203B49D = 0;
        gUnknown_20398C4 = -1;
    }
}

void sub_809927C(u8 param_1)
{
    gUnknown_203B49C = 1;
    gUnknown_203B49D = 1;
    gUnknown_20398C4 = 0x50;
    gUnknown_2039950 = param_1;
    SetScriptVarValue(0x0,DUNGEON_ENTER,0x50);
    SetScriptVarValue(0x0,DUNGEON_ENTER_INDEX,gUnknown_2039950);
    sub_8095494(&gUnknown_20398C8.unk10,param_1);
    gUnknown_20398C8.unkB = 1;
    gUnknown_20398C8.unkC = 0;
    gUnknown_20398C8.unk4 = 0;
    gUnknown_20398C8.unkD = 0;
}
