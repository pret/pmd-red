#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
#include "code_80972F4.h"
#include "code_8099360.h"
#include "code_80A26CC.h"
#include "constants/mailbox.h"
#include "constants/wonder_mail.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "post_office_guide2.h"
#include "text1.h"
#include "text2.h"

extern u8 gFormatItems[];

static EWRAM_DATA_2 unkStruct_203B330 *sUnknown_203B330 = {0};

#include "data/post_office_guide2.h"

// code_8098BDC.s
extern u8 sub_80992E0(s16 *, s16 *);

static void DisplayMissionObjectives(void);

static void sub_8031A2C(void);
static void sub_8031A84(void);

bool8 sub_80319A4(u8 param_1, u8 dungeon, s32 param_3)
{
    sUnknown_203B330 = MemoryAlloc(sizeof(unkStruct_203B330), 8);
    sUnknown_203B330->unkC = param_1;
    sUnknown_203B330->dungeonIndex = dungeon;
    sub_801317C(&sUnknown_203B330->input);
    sUnknown_203B330->unk10 = param_3;
    sUnknown_203B330->unk14 = &sUnknown_203B330->unk18[param_3];
    sub_8031A2C();
    return TRUE;
}

u32 sub_80319F8(void)
{
    switch (sub_8012A64(&sUnknown_203B330->input, sUnknown_203B330->unk10)) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            return 0;
    }
}

static void sub_8031A2C(void)
{
    sub_8031A84();
    DisplayMissionObjectives();
}

void sub_8031A3C(void)
{
    if (sUnknown_203B330 != NULL) {
        sUnknown_203B330->unk18[sUnknown_203B330->unk10] = sUnknown_80E1EFC;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sUnknown_203B330->unk18, TRUE, TRUE);
        MemoryFree(sUnknown_203B330);
        sUnknown_203B330 = NULL;
    }
}

static void sub_8031A84(void)
{
    s32 jobs;

    RestoreUnkTextStruct_8006518(sUnknown_203B330->unk18);
    sUnknown_203B330->unk18[sUnknown_203B330->unk10] = sUnknown_80E1F18;

    if (sUnknown_203B330->unkC == 2) {
        jobs = CountJobsinDungeon(sUnknown_203B330->dungeonIndex);
        if (jobs == 0)
            jobs = 1;

        sub_8012D08(sUnknown_203B330->unk14, jobs);
    }

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B330->unk18, TRUE, TRUE);
}

static void DisplayMissionObjectives(void)
{
    s32 yCoord;
    s32 jobSlotIdx;
    unkStruct_203B480 *mail;
    WonderMail *jobInfo;
    u8 buffer[100];
    volatile u8 local_94;
    u8 buffer1[100];
    s16 auStack44;
    s16 missionIndex;
    u8 local_test;

    sub_80073B8(sUnknown_203B330->unk10);
    // Objectives
    PrintStringOnWindow(10, 0, sObjectives, sUnknown_203B330->unk10, 0);

    switch (sUnknown_203B330->unkC) {
        case 1:
            sub_8099394(&local_94);
            mail = GetMailatIndex(local_94);
            sub_803B6B0(10, 16, 3, sUnknown_203B330->unk10);
            // %dF
            sprintfStatic(buffer,sFmt1,mail->unk4.dungeon.floor);
            PrintStringOnWindow(21,16,buffer,sUnknown_203B330->unk10,0);
            // Rescue #C6%s#R
            sprintfStatic(buffer,sFmtRescue,GetMonSpecies(mail->clientSpecies));
            PrintStringOnWindow(40, 16, buffer, sUnknown_203B330->unk10, 0);
            break;
        case 2:
            if (CountJobsinDungeon(sUnknown_203B330->dungeonIndex) == 0)
                PrintStringOnWindow(10, 16, sJustGo, sUnknown_203B330->unk10, 0);
            else {
                yCoord = 16;

                // 8 Job Slots... check each of them
                for (jobSlotIdx = 0; jobSlotIdx < MAX_ACCEPTED_JOBS; jobSlotIdx++) {
                    jobInfo = GetJobSlotInfo(jobSlotIdx);

                    if (jobInfo->unk4.dungeon.id == sUnknown_203B330->dungeonIndex
                        && jobInfo->mailType != 0
                        && jobInfo->mailType != MAIL_TYPE_SUSPENDED_JOB
                        && jobInfo->mailType != MAIL_TYPE_UNK7) {
                        sub_803B6B0(10, yCoord, 3, sUnknown_203B330->unk10);

                        if (jobInfo->missionType != WONDER_MAIL_MISSION_TYPE_FIND_ITEM) {
                            sprintfStatic(buffer1, sFmt1, jobInfo->unk4.dungeon.floor);
                            PrintStringOnWindow(21, yCoord, buffer1, sUnknown_203B330->unk10, 0);
                        }

                        switch (jobInfo->missionType) {
                            case WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM:
                                BufferItemName(gFormatItems, jobInfo->targetItem, NULL);
                                sprintfStatic(buffer1, sFmtBring, gFormatItems);
                                PrintStringOnWindow(40, yCoord, buffer1, sUnknown_203B330->unk10, 0);
                                break;
                            case WONDER_MAIL_MISSION_TYPE_FIND_ITEM:
                                BufferItemName(gFormatItems, jobInfo->targetItem, NULL);
                                sprintfStatic(buffer1, sFmtFind, gFormatItems);
                                PrintStringOnWindow(40, yCoord, buffer1, sUnknown_203B330->unk10, 0);
                                break;
                            case WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT:
                                sprintfStatic(buffer1, sFmtEscort, GetMonSpecies(jobInfo->targetSpecies));
                                PrintStringOnWindow(40, yCoord, buffer1, sUnknown_203B330->unk10, 0);
                                break;
                            default:
                                sprintfStatic(buffer1, sFmtRescue, GetMonSpecies(jobInfo->targetSpecies));
                                PrintStringOnWindow(40, yCoord, buffer1, sUnknown_203B330->unk10, 0);
                                break;
                        }

                        yCoord += 12;
                    }
                }
            }
            break;
        case 3:
        case 0:
        default:
            if (sub_80992E0(&auStack44, &missionIndex) != 0)
                PrintStringOnWindow(10, 16, GetCurrentMissionText(missionIndex), sUnknown_203B330->unk10, 0);
            else if (sub_8099360(&local_test) != 0)
                PrintStringOnWindow(10, 16, sub_80975DC(sub_80A2688(local_test)), sUnknown_203B330->unk10, 0);
            else
                PrintStringOnWindow(10, 16, sRedQuestionMarks, sUnknown_203B330->unk10, 0);
            break;
    }

    sub_80073E0(sUnknown_203B330->unk10);
}
