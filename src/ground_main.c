#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/move_id.h"
#include "structs/str_wonder_mail.h"
#include "structs/str_dungeon_setup.h"
#include "adventure_info.h"
#include "code_800558C.h"
#include "code_800C9CC.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_8099360.h"
#include "code_809D148.h"
#include "code_80A26CC.h"
#include "decompress_sir.h"
#include "debug.h"
#include "event_flag.h"
#include "graphics_memory.h"
#include "ground_effect.h"
#include "ground_event.h"
#include "ground_lives.h"
#include "ground_lives_helper.h"
#include "ground_main.h"
#include "ground_map.h"
#include "ground_map_conversion_table.h"
#include "ground_object.h"
#include "ground_place.h"
#include "ground_script.h"
#include "ground_script_file.h"
#include "ground_sprite.h"
#include "input.h"
#include "music_util.h"
#include "palette_util.h"
#include "play_time.h"
#include "pokemon.h"
#include "script_item.h"
#include "text_1.h"
#include "text_util.h"
#include "textbox.h"
#include "unk_ds_only_feature.h"

enum Unk_20398A8_Kind
{
    Unk_20398A8_UNK0,
    Unk_20398A8_UNK1,
    Unk_20398A8_UNK2,
    Unk_20398A8_UNK3,
    Unk_20398A8_UNK4,
    Unk_20398A8_UNK5,
    Unk_20398A8_UNK6,
    Unk_20398A8_UNK7,
    Unk_20398A8_UNK8,
    Unk_20398A8_UNK9,
    Unk_20398A8_UNK10,
};

static EWRAM_DATA u32 sUnknown_20398A8 = { Unk_20398A8_UNK0 }; // See enum "Unk_20398A8_Kind"
static EWRAM_DATA s32 sUnknown_20398AC = { 0 };
static EWRAM_DATA u32 sUnknown_20398B0 = { 0 };
static EWRAM_DATA u32 sUnknown_20398B4 = { STARTMODE_NEW_GAME }; // See enum "StartModeVal"
static EWRAM_DATA bool8 sUnknown_20398B8 = { FALSE };
static EWRAM_DATA bool8 sUnknown_20398B9 = { FALSE };
static EWRAM_DATA bool8 sScriptMode = { FALSE };
UNUSED static EWRAM_DATA u8 sUnused1 = { 0 };
static EWRAM_DATA u16 sUnknown_20398BC = { MAP_SQUARE }; // See enum "GroundMapID". Set but never read
static EWRAM_DATA s16 sUnknown_20398BE = { MAP_SQUARE }; // See enum "GroundMapID"
static EWRAM_DATA u32 sUnknown_20398C0 = { 0 }; // Related to GROUND_ENTER_LINK
static EWRAM_DATA s16 sUnknown_20398C4 = { SCRIPT_DUNGEON_TINY_WOODS }; // See enum "ScriptDungeonId"
static EWRAM_DATA DungeonSetupInfo sUnknown_20398C8 = { 0 };
static EWRAM_DATA u8 sUnknown_2039950 = 0; // Related to DUNGEON_ENTER_INDEX

static EWRAM_INIT bool8 sUnknown_203B49C = { FALSE };
static EWRAM_INIT bool8 sUnknown_203B49D = { FALSE };

static s16 sub_8098FCC(u32 unused);

UNUSED static const u8 sUnusedConstData[154] = {
    0,  0,  0,  0,
    1,  0,  0,  0,
    105,  0,  0,  0,
    9,  0,  0,  0,
    12,  0,  0,  0,
    1,  0,  0,  0,
    178,  0,  0,  0,
    180,  0,  0,  0,
    182,  0,  0,  0,
    184,  0,  0,  0,
    186,  0,  0,  0,
    188,  0,  0,  0,
    191,  0,  0,  0,
    193,  0,  0,  0,
    195,  0,  0,  0,
    198,  0,  0,  0,
    201,  0,  0,  0,
    204,  0,  0,  0,
    207,  0,  0,  0,
    162,  0,  0,  0,
    162,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0,  0,  0,
    0,  0
};

u32 xxx_script_related_8098468(s32 startMode)
{
    s32 scriptID;
    s32 varE;

    sUnknown_20398B4 = startMode;
    sUnknown_20398B9 = FALSE;
    sUnknown_20398B8 = TRUE;
    sScriptMode = FALSE;

    switch (startMode) {
        case STARTMODE_13: {
            sScriptMode = TRUE;
            sUnknown_20398B8 = FALSE;
            sUnknown_20398B9 = TRUE;
            break;
        }
        case STARTMODE_14: {
            sUnknown_20398B8 = TRUE;
            sUnknown_20398B9 = TRUE;
            break;
        }
        case STARTMODE_15: {
            sUnknown_20398B8 = TRUE;
            sUnknown_20398B9 = TRUE;
            break;
        }
        case STARTMODE_16: {
            s32 main;
            u32 sub;

            GetScriptVarScenario(SCENARIO_MAIN, &main, &sub);
            sUnknown_20398B8 = main == 0; // Basically checking new game
            sUnknown_20398B9 = TRUE;
            break;
        }
        case STARTMODE_17: {
            sUnknown_20398B8 = FALSE;
            sUnknown_20398B9 = TRUE;
            break;
        }
        default: {
            break;
        }
    }

    ResetSoundEffectCounters();

    if (!sUnknown_20398B9 && !CheckQuest(QUEST_IN_WORLD_CALAMITY)) {
        FadeOutAllMusic(16);
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
    TextboxInit();
    InitInternalScriptItemsData();
    AllocGroundMapAction();
    nullsub_117();
    AllocGroundEvents();
    AllocGroundLives();
    AllocGroundObjects();
    AllocGroundEffects();
    TextboxResetAll();
    sUnknown_203B49C = FALSE;
    sUnknown_203B49D = FALSE;
    sUnknown_20398A8 = Unk_20398A8_UNK1;
    sUnknown_20398AC = 0;
    sUnknown_20398B0 = -1;
    sUnknown_20398BE = GetScriptVarValue(NULL, GROUND_ENTER);
    varE = GetScriptVarValue(NULL, GROUND_ENTER_LINK);
    sUnknown_20398C0 = varE;
    sUnknown_20398C4 = -1;
    scriptID = -1;

    while (sUnknown_20398A8 == Unk_20398A8_UNK1 || sUnknown_20398A8 == Unk_20398A8_UNK2) {
        SetAutoPressTextboxFrames(-1);
        ScriptClearTextbox();
        sub_809977C();
        switch (sUnknown_20398B4) {
            case STARTMODE_NEW_GAME:
                sub_8098C58();
                sUnknown_20398B4 = STARTMODE_CONTINUE_GAME;
                break;
            case STARTMODE_GROUND:
            case STARTMODE_3:
                sub_8001D88();
                break;
            case STARTMODE_DUNGEON_FROM_WORLD_MAP:
                scriptID = EVENT_RESCUE;
                break;
            case STARTMODE_DUNGEON_WON:
            case STARTMODE_10:
            case STARTMODE_11:
            case STARTMODE_DUNGEON_LOST: {
                s32 scriptVar13;

                SetScriptVarValue(NULL,DUNGEON_RESULT,sUnknown_20398B4);
                SetScriptVarValue(NULL,WARP_LOCK,0);
                sub_8098C58();
                UpdateScriptVarWithImmediate(0,DUNGEON_ENTER_FREQUENCY,1,2);
                scriptVar13 = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
                if (scriptVar13 != -1) {
                    s32 var;
                    const DungeonInfo *dungInfo;
                    if (scriptVar13 == 81) {
                        dungInfo = GetScriptDungeonInfo((s16)GetScriptVarValue(NULL,DUNGEON_ENTER_INDEX));
                    }
                    else {
                        dungInfo = GetScriptDungeonInfo(scriptVar13);
                    }
                    scriptID = dungInfo->scriptID3;
                    if (sUnknown_20398B4 == STARTMODE_DUNGEON_WON) {
                        SetScriptVarArrayValue(NULL,DUNGEON_CLEAR_LIST,(u16) scriptVar13,1);
                    }
                    var = sub_8098FCC(sUnknown_20398B4);
                    if (var != -1) {
                        sUnknown_20398BE = var;
                        sUnknown_20398C0 = 0;
                    }
                }
                break;
            }
            case STARTMODE_13:
                sub_8098C58();
                sUnknown_20398B4 = STARTMODE_CONTINUE_GAME;
                SetScriptVarValue(NULL,START_MODE,1);
                SetScriptVarValue(NULL,GROUND_GETOUT,0);
                SetScriptVarValue(NULL,GROUND_ENTER,0);
                SetScriptVarValue(NULL,GROUND_ENTER_LINK,0);
                scriptID = DEBUG_SCRIPT;
                break;
            case STARTMODE_14:
                scriptID = DEMO_01;
                break;
            case STARTMODE_15:
                scriptID = DEMO_02;
                break;
            case STARTMODE_16:
                scriptID = DEMO_03;
                break;
            case STARTMODE_17:
                scriptID = DEMO_04;
                break;
        }
        if (!sUnknown_20398B9) {
            s32 var = GetScriptVarValue(NULL,GROUND_ENTER);
            SetScriptVarValue(NULL,START_MODE,sUnknown_20398B4);
            if (sUnknown_20398B4 != STARTMODE_CONTINUE_GAME) {
                if (sUnknown_20398B4 == STARTMODE_3) {
                    SetScriptVarValue(NULL, GROUND_GETOUT, sUnknown_20398BE);
                }
                else {
                    SetScriptVarValue(NULL, GROUND_GETOUT, var);
                }
            }
            SetScriptVarValue(NULL, GROUND_ENTER, sUnknown_20398BE);
            SetScriptVarValue(NULL, GROUND_ENTER_LINK, sUnknown_20398C0);
        }
        sUnknown_20398B4 = STARTMODE_GROUND;
        sUnknown_20398A8 = Unk_20398A8_UNK0;
        sUnknown_20398AC = 0;
        sUnknown_20398B0 = -1;
        sUnknown_20398BC = sUnknown_20398BE;
        sUnknown_20398BE = -1;
        sub_809977C();
        sub_809D4B0();
        GroundSprite_Reset(-1);
        sub_809C63C();
        TextboxResetAll();
        GroundMap_Reset();
        sub_809D0BC();
        DeleteGroundEvents();
        DeleteGroundLives();
        DeleteGroundObjects();
        DeleteGroundEffects();
        sub_809C658();
        nullsub_16();
        UpdateAdventureAchievements();
        if (scriptID != -1) {
            GroundMap_ExecuteEvent(scriptID, FALSE);
        }
        else {
            GroundMap_ExecuteEvent(EVENT_DIVIDE, FALSE);
        }
        GroundMap_Action();
        sub_8005838(NULL,0);
        sub_80060EC();
        xxx_call_update_bg_sound_input();
        while ( 1 ) {
            xxx_call_update_bg_sound_input();
            sub_80A6E68();
            if (sUnknown_20398A8 != Unk_20398A8_UNK0) {
                if (sUnknown_20398AC > 0) {
                    sUnknown_20398AC--;
                    if (sUnknown_20398AC < 1) {
                        sub_80999D4(sUnknown_20398B0);
                    }
                }
                else if (!sub_8099B94()) {
                    if (sub_809C740())
                        break;
                }
            }
            else if (sUnknown_20398B9 && !sUnknown_20398B8 && !sub_809AFAC()) {
                u16 pressed = gRealInputs.pressed;
                if ((pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) || sub_80048BC()) {
                    GroundMap_ExecuteEvent(DEMO_CANCEL, FALSE);
                    GroundMainGameCancelRequest(30);
                    FadeOutAllMusic(30);
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
        scriptID = -1;
    }

    FreeGroundMapAction();
    nullsub_118();
    FreeGroundLives();
    FreeGroundObjects();
    FreeGroundEffects();
    FreeGroundEvents();
    FreeInternalScriptItemsData();
    TextboxFree();
    sub_809C618();
    sub_80A658C();
    sub_809D508();
    sub_80A7754();
    nullsub_119();
    sub_8099768();
    nullsub_103();
    nullsub_16();

    if (sUnknown_20398B9) {
        if (sUnknown_20398A8 == Unk_20398A8_UNK9) {
            FadeOutAllMusic(30);
            return 15;
        }
        else if (sUnknown_20398A8 == Unk_20398A8_UNK10) {
            return 16;
        }
        else {
            FadeOutAllMusic(30);
            return 15;
        }
    }
    else {
        switch (sUnknown_20398A8) {
            case Unk_20398A8_UNK3:
                SetScriptVarValue(NULL,DUNGEON_ENTER,-1);
                SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX,-1);
                SetScriptVarValue(NULL,START_MODE,4);
                SetScriptVarValue(NULL,DUNGEON_RESULT,4);
                SetScriptVarValue(NULL,GROUND_GETOUT,GetScriptVarValue(NULL,GROUND_ENTER));
                return 5;
            case Unk_20398A8_UNK4:
                SetScriptVarValue(NULL,DUNGEON_ENTER,0);
                SetScriptVarValue(NULL,START_MODE,5);
                SetScriptVarValue(NULL,DUNGEON_RESULT,5);
                SetScriptVarValue(NULL,DUNGEON_ENTER,-1);
                return 6;
            case Unk_20398A8_UNK5: {
                s32 rescueDungeonID = ScriptDungeonIDToRescueDungeonID(sUnknown_20398C4);
                SetScriptVarValue(NULL,DUNGEON_ENTER,sUnknown_20398C4);
                SetScriptVarValue(NULL, DUNGEON_ENTER_INDEX, rescueDungeonID);
                SetScriptVarArrayValue(NULL,DUNGEON_ENTER_LIST,(u16) sUnknown_20398C4,1);
                SetScriptVarValue(NULL,START_MODE,7);
                SetScriptVarValue(NULL,DUNGEON_RESULT,7);
                if ((s16)GetScriptVarValue(NULL,GROUND_PLACE) == 10) {
                    SetScriptVarValue(NULL,GROUND_PLACE,0);
                }
                return 7;
            }
            case Unk_20398A8_UNK6:
                SetScriptVarValue(NULL,DUNGEON_ENTER,81);
                SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX,sUnknown_20398C4);
                SetScriptVarValue(NULL,START_MODE,7);
                SetScriptVarValue(NULL,DUNGEON_RESULT,7);
                if ((s16)GetScriptVarValue(NULL,GROUND_PLACE) == 10) {
                    SetScriptVarValue(NULL,GROUND_PLACE,0);
                }
                return 8;
            case Unk_20398A8_UNK7:
                SetScriptVarValue(NULL,DUNGEON_ENTER,80);
                SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX, sUnknown_2039950);
                SetScriptVarValue(NULL,START_MODE,7);
                SetScriptVarValue(NULL,DUNGEON_RESULT,7);
                return 9;
            case Unk_20398A8_UNK8:
                SetScriptVarValue(NULL,DUNGEON_ENTER,82);
                SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX,sUnknown_20398C4);
                SetScriptVarValue(NULL,START_MODE,7);
                SetScriptVarValue(NULL,DUNGEON_RESULT,7);
                return 10;
            default:
                SetScriptVarValue(NULL,START_MODE,1);
                FadeOutAllMusic(16);
                return 14;
        }
    }
}

UNUSED static void sub_8098BDC(void)
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
    ClearScriptItemScriptVars();
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
// r0: enum "GroundMapID"
bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2)
{
    s32 temp = (s16) r0; // force a asr shift

    if (sUnknown_20398A8 == Unk_20398A8_UNK0) {
        Log(0, "GroundMain ground request %3d %3d", temp, r2);

        sUnknown_20398A8 = Unk_20398A8_UNK1;
        sUnknown_20398AC = 1;
        sUnknown_20398B0 = r2;
        sUnknown_20398B4 = STARTMODE_GROUND;
        sUnknown_20398BE = temp;
        sUnknown_20398C0 = r1;
        return TRUE;
    }

    return FALSE;
}

bool8 sub_8098D80(u32 speed)
{
    if (sUnknown_20398A8 == Unk_20398A8_UNK0) {
        sUnknown_20398A8 = Unk_20398A8_UNK3;
        sUnknown_20398AC = 1;
        sUnknown_20398B0 = speed;
        sub_809C730();

        if (!CheckQuest(QUEST_IN_WORLD_CALAMITY))
            FadeOutAllMusic(speed);

        return TRUE;
    }

    return FALSE;
}

bool8 sub_8098DCC(u32 speed)
{
    if (sUnknown_20398A8 == Unk_20398A8_UNK0) {
        sUnknown_20398A8 = Unk_20398A8_UNK4;
        sUnknown_20398AC = 1;
        sUnknown_20398B0 = speed;
        sub_809C730();

        if(!CheckQuest(QUEST_IN_WORLD_CALAMITY))
            FadeOutAllMusic(speed);

        return TRUE;
    }

    return FALSE;
}

bool8 GroundMainRescueRequest(s32 scriptDungeon, s32 r1)
{
    // Needed to match
    s32 dungeonId = (s16)scriptDungeon;
    s32 _dungeonId = dungeonId;

    if (sUnknown_20398A8 == Unk_20398A8_UNK0) {
        Log(0, "GroundMain recue request %3d %3d", dungeonId, r1);
        if (sUnknown_203B49D) {
            sUnknown_20398A8 = Unk_20398A8_UNK7;
        }
        else {
            if (!sUnknown_203B49C)
                sUnknown_20398C4 = _dungeonId;

            switch (sub_80A2750(sUnknown_20398C4)) {
                case 4: sUnknown_20398A8 = Unk_20398A8_UNK8; break;
                case 1: sUnknown_20398A8 = Unk_20398A8_UNK5; break;
                case 2: sUnknown_20398A8 = Unk_20398A8_UNK6; break;
            }
        }

        sUnknown_20398AC = 1;
        sUnknown_20398B0 = r1;
        sub_809C730();
        return TRUE;
    }

    return FALSE;
}

UNUSED static bool8 GroundMainUserRescueRequest(u32 r0)
{
    if (sUnknown_20398A8 == Unk_20398A8_UNK0 && sUnknown_203B49D) {
        Log(0, "GroundMain user rescue request %3d", r0);
        sUnknown_20398A8 = Unk_20398A8_UNK7;
        sUnknown_20398AC = 1;
        sUnknown_20398B0 = r0;
        sub_809C730();
        return TRUE;
    }

    return FALSE;
}

bool32 GroundMainGameEndRequest(u32 r0)
{
    if (sUnknown_20398A8 == Unk_20398A8_UNK0) {
        Log(0, "GroundMain game end request %3d", r0);
        sUnknown_20398A8 = Unk_20398A8_UNK9;
        sUnknown_20398AC = 1;
        sUnknown_20398B0 = r0;
        sub_809C730();
        return TRUE;
    }

    return FALSE;
}

bool32 GroundMainGameCancelRequest(u32 r0)
{
    if (sUnknown_20398A8 == Unk_20398A8_UNK0) {
        Log(0, "GroundMain game cancel request %3d", r0);
        sUnknown_20398A8 = Unk_20398A8_UNK10;
        sUnknown_20398AC = 1;
        sUnknown_20398B0 = r0;
        sub_809C730();
        return TRUE;
    }

    return FALSE;
}

bool8 sub_8098F88(void)
{
    return sUnknown_20398B9;
}

bool8 GetScriptMode(void)
{
    return sScriptMode;
}

UNUSED static s16 sub_8098FA0(void)
{
    return GetScriptVarValue(NULL, GROUND_PLACE);
}

const char *GetCurrentGroundPlaceName(void)
{
    return GetGroundPlaceName(GetScriptVarValue(NULL, GROUND_PLACE));
}

// Returns an enum GroundMapID
static s16 sub_8098FCC(u32 unused)
{
    s32 scriptDungeon;
    s32 scriptDungeon__;
    s32 scriptDungeon_;
    const DungeonInfo *di;

    scriptDungeon__ = (s16)GetScriptVarValue(NULL,DUNGEON_ENTER);
    scriptDungeon_ = scriptDungeon__;
    if (scriptDungeon__ == -1)
        return MAP_TEAM_BASE_INSIDE;

    if (scriptDungeon__ == SCRIPT_DUNGEON_81)
        scriptDungeon = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
    else
        scriptDungeon = scriptDungeon_;

    di = GetScriptDungeonInfo(scriptDungeon);
    if (sUnknown_20398B4 == STARTMODE_DUNGEON_WON)
        return di->mapID2;

    switch (di->mapID3) {
        case MAP_TINY_WOODS_ENTRY: {
            if (ScriptVarScenarioAfter(SCENARIO_MAIN, 2, -1))
                return MAP_TEAM_BASE_INSIDE;
            break;
        }
        case MAP_LAPIS_CAVE_ENTRY:
        case MAP_MT_BLAZE_ENTRY:
        case MAP_FROSTY_FOREST_ENTRY:
        case MAP_MT_FREEZE_ENTRY: {
            if (!CheckQuest(QUEST_UNK5))
                return MAP_TEAM_BASE_INSIDE;
            break;
        }
        default:
            break;
    }

    return di->mapID3;
}

UNUSED static const char *sub_80990B8(void)
{
    s16 index = sub_8098FCC(11);
    if (index != -1) {
        return GetGroundPlaceName(gGroundMapConversionTable[index].groundPlaceId);
    }
    else {
        return GetCurrentGroundPlaceName();
    }
}

static inline bool8 sub_80990EC_sub(DungeonSetupInfo *iVar1, u32 scriptDungeon)
{
    bool8 flag = FALSE;
    iVar1->sub0.missionKind = DUNGEON_MISSION_UNK0;

    /*if (scriptDungeon == SCRIPT_DUNGEON_MT_FREEZE_2
        || scriptDungeon == SCRIPT_DUNGEON_MT_FREEZE_PEAK_2
        || scriptDungeon == SCRIPT_DUNGEON_MURKY_CAVE)*/
    if ((u16)(scriptDungeon - SCRIPT_DUNGEON_MT_FREEZE_2) < 3)
        flag = TRUE;
    else
        flag = FALSE;
    return flag;
}

u8 sub_80990EC(DungeonSetupInfo *param_1, s32 scriptDungeon)
{
    const DungeonInfo *iVar1;
    u8 auStack_98 [24];
    u8 nameBuffer [24];
    u8 dungeonIndex;
    s32 param2 = (s16)scriptDungeon;

    iVar1 = GetScriptDungeonInfo(param2);
    dungeonIndex = iVar1->dungeonID;

    param_1->sub0.unk0.id = dungeonIndex;
    param_1->sub0.unk0.floor = 1;
    param_1->sub0.unkC = 0;

    switch (sub_80A2750(param2)) {
        case 1:
            if (sub_80990EC_sub(param_1, param2)) {
                param_1->sub0.unkC = 1;
                sub_80A8EC0(auStack_98, 91);
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
            param_1->sub0.missionKind = DUNGEON_MISSION_UNK0;
            break;
        case 2:
            param_1->sub0.missionKind = DUNGEON_MISSION_ACCEPTEDJOB_RELATED;
            break;
    }
    param_1->sub0.unk4 = 0;
    param_1->sub0.unkD = 0;
    return iVar1->unk11;
}

u8 sub_80991E0(DungeonSetupInfo *param_1, s16 *scriptDungeon)
{
    *scriptDungeon = sUnknown_20398C4;
    if (sUnknown_203B49C) {
        memcpy(param_1, &sUnknown_20398C8, sizeof(DungeonSetupInfo));
        return TRUE;
    }
    else {
        return sub_80990EC(param_1,sUnknown_20398C4);
    }
}

void sub_8099220(DungeonSetupInfo *param_1, s32 scriptDungeon)
{
    s32 param_2_s32 = (s16)scriptDungeon;
    if (param_1 != NULL) {
        sUnknown_203B49C = TRUE;
        sUnknown_203B49D = FALSE;
        sUnknown_20398C4 = param_2_s32;
        memcpy(&sUnknown_20398C8, param_1, sizeof(DungeonSetupInfo));
    }
    else {
        sUnknown_203B49C = FALSE;
        sUnknown_203B49D = FALSE;
        sUnknown_20398C4 = -1;
    }
}

void sub_809927C(u8 param_1)
{
    sUnknown_203B49C = TRUE;
    sUnknown_203B49D = TRUE;
    sUnknown_20398C4 = SCRIPT_DUNGEON_80;
    sUnknown_2039950 = param_1;
    SetScriptVarValue(NULL,DUNGEON_ENTER,sUnknown_20398C4);
    SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX,sUnknown_2039950);
    sub_8095494(&sUnknown_20398C8.dungeonSeed, param_1);
    sUnknown_20398C8.sub0.missionKind = DUNGEON_MISSION_OUTONRESCUE;
    sUnknown_20398C8.sub0.unkC = 0;
    sUnknown_20398C8.sub0.unk4 = 0;
    sUnknown_20398C8.sub0.unkD = 0;
}

bool8 sub_80992E0(s16 *param_1, s16 *rescueDungeonId)
{
    s32 sVar2;

    sVar2 = (s16)GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (sVar2 != -1 && sVar2 != 80 && sVar2 != 81 && sVar2 != 82) {
        *param_1 = sVar2;
        *rescueDungeonId = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        return TRUE;
    }
    else {
        *param_1 = -1;
        *rescueDungeonId = RESCUE_DUNGEON_INVALID;
        return FALSE;
    }
}

bool8 sub_8099328(u8 *dungeonId)
{
    s16 script_disc;
    const DungeonInfo* dungeonInfo;

    script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 81) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        dungeonInfo = GetScriptDungeonInfo(script_disc);
        if (dungeonInfo->dungeonID < DUNGEON_OUT_ON_RESCUE) {
            *dungeonId = dungeonInfo->dungeonID;
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
    if (script_disc == 82) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        dungeonInfo = GetScriptDungeonInfo(script_disc);
            *dungeonId = dungeonInfo->dungeonID;
            return TRUE;
    }
    return FALSE;
}

bool8 sub_8099394(u8 *param)
{
    s16 script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 80) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        *param = script_disc;
        return TRUE;
    }
    return FALSE;
}

void sub_80993C0(bool8 param)
{
    sUnknown_20398B8 = (param == FALSE);
}

void sub_80993D8(void)
{
    sub_80A4B38();
}

void sub_80993E4(void)
{
    sub_80A4B54();
}
