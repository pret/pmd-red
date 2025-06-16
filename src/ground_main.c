#include "global.h"
#include "constants/dungeon.h"
#include "constants/move_id.h"
#include "structs/str_wonder_mail.h"
#include "structs/str_dungeon_setup.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "music_util.h"
#include "code_80958E8.h"
#include "code_8099360.h"
#include "code_80A26CC.h"
#include "ground_place.h"
#include "debug.h"
#include "event_flag.h"
#include "ground_main.h"
#include "ground_map_2.h"
#include "play_time.h"
#include "pokemon.h"
#include "text_util.h"
#include "ground_map_conversion_table.h"

EWRAM_DATA u32 gUnknown_20398A8 = {0};
EWRAM_DATA s32 gUnknown_20398AC = {0};
EWRAM_DATA u32 gUnknown_20398B0 = {0};
EWRAM_DATA u32 gUnknown_20398B4 = {0};
EWRAM_DATA u8 gUnknown_20398B8 = {0};
EWRAM_DATA bool8 gUnknown_20398B9 = {0};
EWRAM_DATA bool8 gScriptMode = {0};
UNUSED EWRAM_DATA static u8 gUnknown_20398BB = {0};
EWRAM_DATA u16 gUnknown_20398BC = {0};
EWRAM_DATA s16 gUnknown_20398BE = {0};
EWRAM_DATA u32 gUnknown_20398C0 = {0};
EWRAM_DATA s16 gUnknown_20398C4 = {0};
EWRAM_DATA struct DungeonSetupInfo gUnknown_20398C8 = {0};
EWRAM_DATA u8 gUnknown_2039950 = 0;

EWRAM_INIT bool8 gUnknown_203B49C = {0};
EWRAM_INIT u8 gUnknown_203B49D = {0};

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

extern void sub_809CB8C();
extern void sub_8098CC8();
extern void ClearAllItems_8091FB4();
extern u8 sub_809C730();
extern void sub_8095494(DungeonMailSeed *param_1, u8 index);

extern u16 gUnknown_2026E4E;

// TODO: Move these externs to headers
extern void GroundSprite_Reset(s32);
extern s16 sub_8098FCC(u32 unused);
extern s16 sub_80A2654(s16 r0);
extern void sub_809A71C(s32);
extern bool8 sub_809AFAC(void);
extern bool8 sub_80048BC(void);
extern u8 sub_80023E4(u32);
extern bool8 sub_809C740(void);
extern bool8 sub_8099B94(void);
extern void FreeGroundMapAction(void);
extern void nullsub_118(void);
extern void FreeGroundLives(void);
extern void FreeGroundObjects(void);
extern void FreeGroundEffects(void);
extern void FreeGroundEvents(void);
extern void sub_809CB74(void);
extern void sub_809A610(void);
extern void sub_809C618(void);
extern void sub_80A658C(void);
extern void sub_809D508(void);
extern void sub_80A7754(void);
extern void nullsub_119(void);
extern void sub_8099768(void);
extern void nullsub_103(void);
extern void sub_8099648(void);
extern void sub_809975C(void);
extern void sub_809D0AC(void);
extern void sub_80A7744(void);
extern void sub_809D490(void);
extern void sub_80A62F0(void);
extern void sub_809C5C4(void);
extern void sub_809A560(void);
extern void sub_809CB50(void);
extern void AllocGroundMapAction(void);
extern void nullsub_117(void);
extern void AllocGroundEvents(void);
extern void AllocGroundLives(void);
extern void AllocGroundObjects(void);
extern void AllocGroundEffects(void);
extern void sub_809A62C(void);
extern void nullsub_124(void);
extern void GroundLives_Action(void);
extern void GroundObject_Action(void);
extern void GroundEffect_Action(void);
extern void nullsub_105(void);
extern void sub_809B474(void);
extern void GroundScript_Unlock();
extern void sub_809D25C(void);
extern void sub_80A59DC(void);
extern void sub_809B614(void);
extern void sub_809CA20(void);
extern void sub_80A6E80(void);
extern void sub_8099BE4(void);
extern void sub_8099744(void);
extern void WaitForNextFrameAndAdvanceRNG(void);
extern void LoadBufferedInputs(void);
extern void nullsub_120(void);
extern void sub_80A5E70(void);
extern void sub_809B638(void);
extern void nullsub_106(void);
extern void sub_80A73EC(void);
extern void sub_8099750(void);
extern void DoScheduledMemCopies(void);
extern void GroundMap_Reset(void);
extern void sub_809D0BC(void);
extern void DeleteGroundEvents(void);
extern void DeleteGroundLives(void);
extern void DeleteGroundObjects(void);
extern void DeleteGroundEffects(void);
extern void sub_809C658(void);
extern void nullsub_16(void);
extern void UpdateAdventureAchievements(void);
extern void xxx_call_update_bg_sound_input(void);
extern void sub_80A6E68(void);
extern void sub_80060EC(void);
extern void ScriptPrintNullTextbox(void);
extern void sub_809977C(void);
extern void GroundMap_ExecuteEvent(s32, u32);
extern void UpdateFadeInTile(s32);
extern void GroundMap_Action(void);
extern void sub_8098C58(void);
extern void sub_8001D88(void);
extern u32 GroundMainGameCancelRequest(u32 r0);
extern void sub_80999D4(s32);
extern void sub_809D4B0(void);
extern void sub_809C63C(void);
extern void sub_8005838(s32, s32);

u32 xxx_script_related_8098468(s32 param_1)
{
    s32 r7;
    s32 varE;

    gUnknown_20398B4 = param_1;
    gUnknown_20398B9 = 0;
    gUnknown_20398B8 = 1;
    gScriptMode = 0;

    switch (param_1) {
        case 0xd:
            gScriptMode = 1;
            gUnknown_20398B8 = 0;
            gUnknown_20398B9 = 1;
            break;
        case 0xe:
            gUnknown_20398B8 = 1;
            gUnknown_20398B9 = 1;
            break;
        case 0xf:
            gUnknown_20398B8 = 1;
            gUnknown_20398B9 = 1;
            break;
        case 0x10: {
            s32 local_1c;
            u32 auStack24;

            GetScriptVarScenario(3,&local_1c,&auStack24);
            gUnknown_20398B8 = local_1c == 0;
            gUnknown_20398B9 = 1;
            break;
        }
        case 0x11:
            gUnknown_20398B8 = 0;
            gUnknown_20398B9 = 1;
            break;
        default:
            break;
    }
    ResetSoundEffectCounters();
    if (gUnknown_20398B9 == 0 && !sub_80023E4(0xd)) {
        FadeOutAllMusic(0x10);
    }
    gUnknown_2026E4E = 0x808;
    UpdateFadeInTile(0);
    sub_8099648();
    sub_809975C();
    sub_809D0AC();
    sub_80A7744();
    sub_809D490();
    sub_80A62F0();
    sub_809C5C4();
    sub_809A560();
    sub_809CB50();
    AllocGroundMapAction();
    nullsub_117();
    AllocGroundEvents();
    AllocGroundLives();
    AllocGroundObjects();
    AllocGroundEffects();
    sub_809A62C();
    gUnknown_203B49C = 0;
    gUnknown_203B49D = 0;
    gUnknown_20398A8 = 1;
    gUnknown_20398AC = 0;
    gUnknown_20398B0 = -1;
    gUnknown_20398BE = GetScriptVarValue(0,GROUND_ENTER);
    varE = GetScriptVarValue(0,GROUND_ENTER_LINK);
    gUnknown_20398C0 = varE;
    gUnknown_20398C4 = -1;
    r7 = -1;
    while (gUnknown_20398A8 - 1 <= 1) {
        sub_809A71C(-1);
        ScriptPrintNullTextbox();
        sub_809977C();
        switch (gUnknown_20398B4) {
            case 0:
                sub_8098C58();
                gUnknown_20398B4 = 1;
                break;
            case 2:
            case 3:
                sub_8001D88();
                break;
            case 5:
                r7 = 0x70;
                break;
            case 9:
            case 10:
            case 0xb:
            case 0xc: {
                s32 scriptVar13;

                SetScriptVarValue(0,DUNGEON_RESULT,gUnknown_20398B4);
                SetScriptVarValue(0,WARP_LOCK,0);
                sub_8098C58();
                UpdateScriptVarWithImmediate(0,DUNGEON_ENTER_FREQUENCY,1,2);
                scriptVar13 = (s16)GetScriptVarValue(0,DUNGEON_ENTER);
                if (scriptVar13 != -1) {
                    s32 var;
                    const DungeonInfo *dungInfo;
                    if (scriptVar13 == 0x51) {
                        dungInfo = GetDungeonInfo_80A2608((s16)GetScriptVarValue(0,DUNGEON_ENTER_INDEX));
                    }
                    else {
                        dungInfo = GetDungeonInfo_80A2608(scriptVar13);
                    }
                    r7 = dungInfo->unkA;
                    if (gUnknown_20398B4 == 9) {
                        SetScriptVarArrayValue(0,DUNGEON_CLEAR_LIST,(u16) scriptVar13,1);
                    }
                    var = sub_8098FCC(gUnknown_20398B4);
                    if (var != -1) {
                        gUnknown_20398BE = var;
                        gUnknown_20398C0 = 0;
                    }
                }
                break;
            }
            case 0xd:
                sub_8098C58();
                gUnknown_20398B4 = 1;
                SetScriptVarValue(0,START_MODE,1);
                SetScriptVarValue(0,GROUND_GETOUT,0);
                SetScriptVarValue(0,GROUND_ENTER,0);
                SetScriptVarValue(0,GROUND_ENTER_LINK,0);
                r7 = 0x71;
                break;
            case 0xe:
                r7 = 0x73;
                break;
            case 0xf:
                r7 = 0x74;
                break;
            case 0x10:
                r7 = 0x75;
                break;
            case 0x11:
                r7 = 0x76;
                break;
        }
        if (gUnknown_20398B9 == 0) {
            s32 var = GetScriptVarValue(0,GROUND_ENTER);
            SetScriptVarValue(0,START_MODE,gUnknown_20398B4);
            if (gUnknown_20398B4 != 1) {
                if (gUnknown_20398B4 == 3) {
                    SetScriptVarValue(0,GROUND_GETOUT,gUnknown_20398BE);
                }
                else {
                    SetScriptVarValue(0,GROUND_GETOUT,var);
                }
            }
            SetScriptVarValue(0,GROUND_ENTER,gUnknown_20398BE);
            SetScriptVarValue(0,GROUND_ENTER_LINK,gUnknown_20398C0);
        }
        gUnknown_20398B4 = 2;
        gUnknown_20398A8 = 0;
        gUnknown_20398AC = 0;
        gUnknown_20398B0 = -1;
        gUnknown_20398BC = gUnknown_20398BE;
        gUnknown_20398BE = -1;
        sub_809977C();
        sub_809D4B0();
        GroundSprite_Reset(-1);
        sub_809C63C();
        sub_809A62C();
        GroundMap_Reset();
        sub_809D0BC();
        DeleteGroundEvents();
        DeleteGroundLives();
        DeleteGroundObjects();
        DeleteGroundEffects();
        sub_809C658();
        nullsub_16();
        UpdateAdventureAchievements();
        if (r7 != -1) {
            GroundMap_ExecuteEvent(r7,0);
        }
        else {
            GroundMap_ExecuteEvent(0x66,0);
        }
        GroundMap_Action();
        sub_8005838(0,0);
        sub_80060EC();
        xxx_call_update_bg_sound_input();
        while ( 1 ) {
            xxx_call_update_bg_sound_input();
            sub_80A6E68();
            if (gUnknown_20398A8 != 0) {
                if (gUnknown_20398AC > 0) {
                    gUnknown_20398AC--;
                    if (gUnknown_20398AC < 1) {
                        sub_80999D4(gUnknown_20398B0);
                    }
                }
                else if (!sub_8099B94()) {
                    if (sub_809C740())
                        break;
                }
            }
            else if (gUnknown_20398B9 != 0 && gUnknown_20398B8 == 0 && !sub_809AFAC()) {
                u16 pressed = gRealInputs.pressed;
                if ((pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) || sub_80048BC()) {
                    GroundMap_ExecuteEvent(0x72,0);
                    GroundMainGameCancelRequest(0x1e);
                    FadeOutAllMusic(0x1e);
                }
            }
            GroundMap_Action();
            nullsub_124();
            GroundLives_Action();
            GroundObject_Action();
            GroundEffect_Action();
            nullsub_105();
            sub_809B474();
            GroundScript_Unlock();
            sub_809D25C();
            sub_80A59DC();
            sub_809B614();
            sub_809CA20();
            sub_80A6E80();
            sub_8099BE4();
            sub_8099744();
            UpdateSoundEffectCounters();
            IncrementPlayTime(gPlayTimeRef);
            WaitForNextFrameAndAdvanceRNG();
            LoadBufferedInputs();
            nullsub_120();
            sub_80A5E70();
            sub_809B638();
            nullsub_106();
            sub_80A73EC();
            sub_8099750();
            DoScheduledMemCopies();
        }

        GroundMap_Reset();
        r7 = -1;
    }

    FreeGroundMapAction();
    nullsub_118();
    FreeGroundLives();
    FreeGroundObjects();
    FreeGroundEffects();
    FreeGroundEvents();
    sub_809CB74();
    sub_809A610();
    sub_809C618();
    sub_80A658C();
    sub_809D508();
    sub_80A7754();
    nullsub_119();
    sub_8099768();
    nullsub_103();
    nullsub_16();
    if (gUnknown_20398B9 != 0) {
        if (gUnknown_20398A8 == 9) {
            FadeOutAllMusic(0x1e);
            return 0xf;
        }
        else if (gUnknown_20398A8 == 10) {
            return 0x10;
        }
        else {
            FadeOutAllMusic(0x1e);
            return 0xf;
        }
    }
    else {
        switch (gUnknown_20398A8) {
            case 3:
                SetScriptVarValue(0,DUNGEON_ENTER,-1);
                SetScriptVarValue(0,DUNGEON_ENTER_INDEX,-1);
                SetScriptVarValue(0,START_MODE,4);
                SetScriptVarValue(0,DUNGEON_RESULT,4);
                SetScriptVarValue(0,GROUND_GETOUT,GetScriptVarValue(0,GROUND_ENTER));
                return 5;
            case 4:
                SetScriptVarValue(0,DUNGEON_ENTER,0);
                SetScriptVarValue(0,START_MODE,5);
                SetScriptVarValue(0,DUNGEON_RESULT,5);
                SetScriptVarValue(0,DUNGEON_ENTER,-1);
                return 6;
            case 5: {
                s32 sVar2 = sub_80A2654(gUnknown_20398C4);
                SetScriptVarValue(0,DUNGEON_ENTER,gUnknown_20398C4);
                SetScriptVarValue(0,DUNGEON_ENTER_INDEX,sVar2);
                SetScriptVarArrayValue(0,DUNGEON_ENTER_LIST,(u16) gUnknown_20398C4,1);
                SetScriptVarValue(0,START_MODE,7);
                SetScriptVarValue(0,DUNGEON_RESULT,7);
                if ((s16)GetScriptVarValue(0,GROUND_PLACE) == 10) {
                    SetScriptVarValue(0,GROUND_PLACE,0);
                }
                return 7;
            }
            case 6:
                SetScriptVarValue(0,DUNGEON_ENTER,0x51);
                SetScriptVarValue(0,DUNGEON_ENTER_INDEX,gUnknown_20398C4);
                SetScriptVarValue(0,START_MODE,7);
                SetScriptVarValue(0,DUNGEON_RESULT,7);
                if ((s16)GetScriptVarValue(0,GROUND_PLACE) == 10) {
                    SetScriptVarValue(0,GROUND_PLACE,0);
                }
                return 8;
            case 7:
                SetScriptVarValue(0,DUNGEON_ENTER,0x50);
                SetScriptVarValue(0,DUNGEON_ENTER_INDEX,gUnknown_2039950);
                SetScriptVarValue(0,START_MODE,7);
                SetScriptVarValue(0,DUNGEON_RESULT,7);
                return 9;
            case 8:
                SetScriptVarValue(0,DUNGEON_ENTER,0x52);
                SetScriptVarValue(0,DUNGEON_ENTER_INDEX,gUnknown_20398C4);
                SetScriptVarValue(0,START_MODE,7);
                SetScriptVarValue(0,DUNGEON_RESULT,7);
                return 10;
            default:
                SetScriptVarValue(0,START_MODE,1);
                FadeOutAllMusic(0x10);
                return 0xe;
        }
    }
}

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
    UpdateSoundEffectCounters();
    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    nullsub_120();
    sub_80A5E70();
    sub_809B638();
    nullsub_106();
    sub_80A73EC();
    sub_8099750();
    DoScheduledMemCopies();
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

// arm9.bin::0206C1A4
bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2)
{
    s32 temp = (s16) r0; // force a asr shift
    if(gUnknown_20398A8 == 0)
    {
        Log(0, "GroundMain ground request %3d %3d", temp, r2);
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
        Log(0, "GroundMain recue request %3d %3d", r2, r1);
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
            Log(0, "GroundMain user rescue request %3d", r0);
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
        Log(0, "GroundMain game end request %3d", r0);
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
        Log(0, "GroundMain game cancel request %3d", r0);
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

UNUSED static s16 sub_8098FA0(void)
{
    return GetScriptVarValue(NULL, GROUND_PLACE);
}

const char *GetCurrentGroundPlaceName(void)
{
    return GetGroundPlaceName(GetScriptVarValue(NULL, GROUND_PLACE));
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

UNUSED static const char *sub_80990B8(void)
{
    s16 index = sub_8098FCC(0xB);
    if (index != -1) {
        return GetGroundPlaceName(gGroundMapConversionTable[index].groundPlaceId);
    }
    else {
        return GetCurrentGroundPlaceName();
    }
}

static inline bool8 sub_80990EC_sub(struct DungeonSetupInfo *iVar1, u32 iVar2)
{
    bool8 flag = FALSE;
    iVar1->sub0.unkB = 0;

    if ((u16)(iVar2 - 0x25) < 3)
        flag = TRUE;
    else
        flag = FALSE;
    return flag;
}

extern void sub_80A8EC0(u8 *, u32);

u8 sub_80990EC(struct DungeonSetupInfo *param_1, s16 param_2)
{
    const DungeonInfo *iVar1;
    u8 auStack_98 [24];
    u8 nameBuffer [24];
    u8 dungeonIndex;

    iVar1 = GetDungeonInfo_80A2608(param_2);
    dungeonIndex = iVar1->dungeonIndex;

    param_1->sub0.unk0.id = dungeonIndex;
    param_1->sub0.unk0.floor = 1;
    param_1->sub0.unkC = 0;

    switch (sub_80A2750(param_2)) {
        case 1:
            if (sub_80990EC_sub(param_1, param_2)) {
                param_1->sub0.unkC = 1;
                sub_80A8EC0(auStack_98, 0x5b);
                BoundedCopyStringtoBuffer(nameBuffer, auStack_98, POKEMON_NAME_LENGTH);
                {
                    struct StoryMonData gengarData =
                    {
                        .name = nameBuffer,
                        .speciesNum = MONSTER_GENGAR,
                        .itemID = ITEM_NOTHING,
                        .dungeonLocation= {DUNGEON_RESCUE_TEAM_BASE, 0},
                        .moveID = {MOVE_SCRATCH, MOVE_LEER, MOVE_TAUNT, MOVE_QUICK_ATTACK},
                        .pokeHP = 80,
                        .level = 15,
                        .IQ = 1,
                        .offenseAtk = {25, 25},
                        .offenseDef = {15, 15},
                        .currExp = 25000,
                    };

                    ConvertStoryMonToPokemon(&param_1->mon, &gengarData);
                }
            }
            break;
        case 4:
            param_1->sub0.unkB = 0;
            break;
        case 2:
            param_1->sub0.unkB = 2;
            break;
    }
    param_1->sub0.unk4 = 0;
    param_1->sub0.unkD = 0;
    return iVar1->unk11;
}

u8 sub_80991E0(struct DungeonSetupInfo *param_1,short *param_2)
{
    *param_2 = gUnknown_20398C4;
    if (gUnknown_203B49C) {
        memcpy(param_1, &gUnknown_20398C8, sizeof(struct DungeonSetupInfo));
        return TRUE;
    }
    else {
        return sub_80990EC(param_1,gUnknown_20398C4);
    }
}

void sub_8099220(struct DungeonSetupInfo *param_1, s16 param_2)
{
    s32 param_2_s32 = (s16)param_2;
    if (param_1 != NULL)
    {
        gUnknown_203B49C = TRUE;
        gUnknown_203B49D = 0;
        gUnknown_20398C4 = param_2_s32;
        memcpy(&gUnknown_20398C8, param_1, sizeof(struct DungeonSetupInfo));
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
    sub_8095494(&gUnknown_20398C8.dungeonSeed,param_1);
    gUnknown_20398C8.sub0.unkB = 1;
    gUnknown_20398C8.sub0.unkC = 0;
    gUnknown_20398C8.sub0.unk4 = 0;
    gUnknown_20398C8.sub0.unkD = 0;
}

bool8 sub_80992E0(s16 *param_1, s16 *param_2)
{
    s32 sVar2;

    sVar2 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
    if ((((sVar2 != -1) && (sVar2 != 0x50)) && (sVar2 != 0x51)) && (sVar2 != 0x52)) {
        *param_1 = sVar2;
        *param_2 = GetScriptVarValue(NULL,DUNGEON_ENTER_INDEX);
        return TRUE;
    }
    else {
        *param_1 = -1;
        *param_2 = -1;
        return FALSE;
    }
}

bool8 sub_8099328(u8 *dungeonId)
{
    s16 script_disc;
    const DungeonInfo* dungeonInfo;

    script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 0x51) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        dungeonInfo = GetDungeonInfo_80A2608(script_disc);
        if (dungeonInfo->dungeonIndex < 0x3f) {
            *dungeonId = dungeonInfo->dungeonIndex;
            return TRUE;
        }
    }
    return FALSE;
}

bool8 sub_8099360(u8 *dungeonId)
{
    s16 script_disc;
    const DungeonInfo* dungeonInfo;

    script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 0x52) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        dungeonInfo = GetDungeonInfo_80A2608(script_disc);
            *dungeonId = dungeonInfo->dungeonIndex;
            return TRUE;
    }
    return FALSE;
}

bool8 sub_8099394(u8 *param)
{
    s16 script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 0x50) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        *param = script_disc;
        return TRUE;
    }
    return FALSE;
}

void sub_80993C0(bool8 param)
{
    gUnknown_20398B8 = (param == FALSE);
}

extern void sub_80A4B38(void);
extern void sub_80A4B54(void);

void sub_80993D8(void)
{
    sub_80A4B38();
}

void sub_80993E4(void)
{
    sub_80A4B54();
}
