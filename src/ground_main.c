#include "global.h"
#include "constants/dungeon.h"
#include "constants/move_id.h"
#include "structs/str_wonder_mail.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_80958E8.h"
#include "code_8099360.h"
#include "code_80A26CC.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_main.h"
#include "ground_map_2.h"
#include "play_time.h"
#include "pokemon.h"
#include "text_util.h"

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
EWRAM_DATA struct unkStruct_20398C8 gUnknown_20398C8 = {0};
EWRAM_DATA u8 gUnknown_2039950 = 0;

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
extern void nullsub_120();
extern void sub_809B638();
extern void nullsub_106();
extern void sub_80A73EC();
extern void sub_80A6E68();
extern void GroundMap_Action();
extern void nullsub_124();
extern void GroundLives_Action();
extern void GroundObject_Action();
extern void GroundEffect_Action();

extern void sub_809CB8C();
extern void sub_8098CC8();
extern void ClearAllItems_8091FB4();
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
    WaitForNextFrameAndAdvanceRNG();
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

static inline bool8 sub_80990EC_sub(struct unkStruct_20398C8 *iVar1, u32 iVar2)
{
    bool8 flag = FALSE;
    iVar1->unkB = 0;

    if ((u16)(iVar2 - 0x25) < 3)
        flag = TRUE;
    else
        flag = FALSE;
    return flag;
}

extern void sub_80A8EC0(u8 *, u32);

u8 sub_80990EC(struct unkStruct_20398C8 *param_1, s16 param_2)
{
    const DungeonInfo *iVar1;
    u8 auStack_98 [24];
    u8 nameBuffer [24];
    u8 r5;
    u8 dungeonIndex;

    iVar1 = GetDungeonInfo_80A2608(param_2);
    dungeonIndex = iVar1->dungeonIndex;
    r5 = 0;
    param_1->unk0 = dungeonIndex;
    param_1->unk1 = 1;
    param_1->unkC = r5;

    switch(sub_80A2750(param_2))
    {
        case 1:
            if (sub_80990EC_sub(param_1, param_2)) {
                param_1->unkC = 1;
                sub_80A8EC0(auStack_98, 0x5b);
                BoundedCopyStringtoBuffer(nameBuffer, auStack_98, POKEMON_NAME_LENGTH);
                {
                    struct unkStruct_808D144 stack =
                        {
                            .name = nameBuffer,
                            .speciesNum = MONSTER_GENGAR,
                            .itemID = ITEM_NOTHING,
                            .dungeonLocation= {DUNGEON_RESCUE_TEAM_BASE, 0}, // DUNGEON_RESCUE_TEAM_BASE
                            .moveID = {MOVE_SCRATCH, MOVE_LEER, MOVE_TAUNT, MOVE_QUICK_ATTACK},
                            .pokeHP = 80,
                            .level = 15,
                            .IQ = 1,
                            .offenseAtk = {25, 25},
                            .offenseDef = {15, 15},
                            .currExp = 25000,
                        };

                    sub_808D144(&param_1->unk18, &stack);
                }
            }
            break;
        case 4:
            param_1->unkB = 0;
            break;
        case 2:
            param_1->unkB = 2;
            break;
    }
    param_1->unk4 = 0;
    param_1->unkD = 0;
    return iVar1->unk11;
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
