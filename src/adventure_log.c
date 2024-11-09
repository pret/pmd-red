#include "global.h"
#include "globaldata.h"
#include "adventure_log.h"
#include "code_80118A4.h"
#include "string_format.h"
#include "code_8097670.h"
#include "constants/input.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"
#include "structs/struct_sub80095e4.h"

static EWRAM_DATA_2 struct_Sub80095E4_2 *sAdventureLog = {0};

#include "data/adventure_log.h"

static void DisplayAdventureLog();

static void sub_8032084();

bool8 CreateAdventureLogScreen(u32 kind)
{
    sAdventureLog = MemoryAlloc(sizeof(*sAdventureLog), 8);
    sAdventureLog->s0.unk34 = kind;
    sAdventureLog->s0.unk38 = &sAdventureLog->s0.unk3C[kind];
    RestoreUnkTextStruct_8006518(sAdventureLog->s0.unk3C);
    sAdventureLog->s0.unk3C[sAdventureLog->s0.unk34] = sUnknown_80E2008;
    sAdventureLog->s0.unk38->unk14 = &sAdventureLog->unk9C;

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sAdventureLog->s0.unk3C, TRUE, TRUE);
    sub_8013818(&sAdventureLog->s0.input, 0x20, 8, kind);
    sub_8032084();
    DisplayAdventureLog();
    return TRUE;
}

u32 HandleAdventureLogInput(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sAdventureLog->s0.input);
        return 0;
    }

    switch (GetKeyPress(&sAdventureLog->s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (sub_8013938(&sAdventureLog->s0.input)) {
                sub_8032084();
                DisplayAdventureLog();
                return 1;
            }
            return 0;
    }
}

void CleanAdventureLogScreen(void)
{
    if (sAdventureLog != NULL) {
        sAdventureLog->s0.unk3C[sAdventureLog->s0.unk34] = sUnknown_80E1FF0;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sAdventureLog->s0.unk3C, TRUE, TRUE);
        MemoryFree(sAdventureLog);
        sAdventureLog = NULL;
    }
}

static void sub_8032084(void)
{
    sAdventureLog->unk9C.f0 = sAdventureLog->s0.input.unk20;
    sAdventureLog->unk9C.f1 = sAdventureLog->s0.input.unk1E;
    sAdventureLog->unk9C.f2 = 11;
    sAdventureLog->unk9C.f3 = 0;

    SUB_80095E4_CALL(sAdventureLog->s0);
}

static void DisplayAdventureLog(void)
{
    s32 i;
    s32 r4; // r4
    s32 r6; // r6
    u8 aa;

    CallPrepareTextbox_8008C54(sAdventureLog->s0.unk34);
    sub_80073B8(sAdventureLog->s0.unk34);
    r4 = sAdventureLog->s0.input.unk1E * 8;
    r6 = r4;
    r6 += 10;
    PrintStringOnWindow(r6, 0, sAdventureLogText, sAdventureLog->s0.unk34, 0);

    r4 += 4;
    r6 = r4 + (sAdventureLog->unk9C.f2 * 8);
    sub_8012BC4(r6, 0, sAdventureLog->s0.input.unk1E + 1, 1, 7, sAdventureLog->s0.unk34);

    for (i = 0; i < sAdventureLog->s0.input.unk1A; i++) {
        aa = (sAdventureLog->s0.input.unk1E * sAdventureLog->s0.input.unk1C) + i;

        if (GetAdventureAchievement(aa)) {
            switch (aa) {
                case AA_NUM_FLOORS_EXPLORED: {
                    s32 v1 = GetAdventureFloorsExplored();
                    gFormatArgs[0] = (s16)v1;
                    PrintFormattedStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.unk34, 0);
                    break;
                }
                case AA_NUM_MOVES_LEARNED: {
                    s32 v2 = GetAdventureMovesLearned();
                    gFormatArgs[0] = (s16)v2;
                    PrintFormattedStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.unk34, 0);
                    break;
                }
                case AA_NUM_THIEVING_SUCCESSES: {
                    s32 v3 = GetThievingSuccesses();
                    gFormatArgs[0] = (s16)v3;
                    PrintFormattedStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.unk34, 0);
                    break;
                }
                case AA_NUM_FRIEND_RESCUE_SUCCESSES: {
                    s32 v4 = GetFriendRescueSuccesses();
                    gFormatArgs[0] = v4;
                    PrintFormattedStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.unk34, 0);
                    break;
                }
                case AA_NUM_POKEMON_EVOLVED: {
                    s32 v5 = GetAdventureNumEvolved();
                    gFormatArgs[0] = v5;
                    PrintFormattedStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.unk34, 0);
                    break;
                }
                case AA_NUM_POKEMON_JOINED: {
                    s32 v6 = GetAdventureNumJoined();
                    gFormatArgs[0] = (s16)v6;
                    // fallthrough
                }
                default: {
                    PrintFormattedStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), GetAdventureLogLine(aa), sAdventureLog->s0.unk34, 0);
                    break;
                }
            }
        }
        else
            PrintStringOnWindow(8, sub_8013800(&sAdventureLog->s0.input, i), sPlaceholder, sAdventureLog->s0.unk34, 0);
    }

    sub_80073E0(sAdventureLog->s0.unk34);
}