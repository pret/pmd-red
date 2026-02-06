#include "global.h"
#include "globaldata.h"
#include "structs/str_mission_rewards.h"
#include "structs/str_mon_portrait.h"
#include "structs/str_text.h"
#include "structs/str_wonder_mail.h"
#include "code_803C1D0.h"
#include "code_80958E8.h"
#include "exclusive_pokemon.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "mission_reward.h"
#include "pokemon.h"
#include "string_format.h"
#include "text_1.h"
#include "thank_you_messages.h"

enum TYM_State
{
    TYM_STATE_0,
    TYM_STATE_1,
    TYM_STATE_2,
    TYM_STATE_3,
    TYM_STATE_4,
    TYM_STATE_5,
    TYM_STATE_6,
    TYM_STATE_7,
};

// Size: 0xA8
typedef struct TYM_Work
{
    /* 0x0 */ u32 state; // See enum "TYM_State"
    /* 0x4 */ u32 fallbackState; // See enum "TYM_State"
    /* 0x8 */ MissionRewards rewards;
    /* 0x30 */ u8 jobSlotIndex;
    /* 0x34 */ WonderMail *jobInfo;
    /* 0x38 */ MonPortraitMsg monPortrait;
    /* 0x48 */ WindowTemplates windows;
} TYM_Work;

EWRAM_INIT static TYM_Work *sTYMWork = { NULL };

#include "data/thank_you_messages.h"

static void TYM_InitStateDialogue(void);
static void TYM_InitStateWindows(void);
static void TYM_ProceedToNextState(void);
static void TYM_SetState(u32 newState);
static void sub_802DE44(void);

bool8 TYM_Create(u8 jobSlotIndex, u8 dungeon)
{
    struct unkStruct_8096AF8 local_18;

    sub_8096AF8(&local_18, jobSlotIndex, dungeon);

    if (!local_18.unk0)
        return FALSE;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);

    sTYMWork = MemoryAlloc(sizeof(TYM_Work), MEMALLOC_GROUP_8);
    sTYMWork->jobSlotIndex = jobSlotIndex;
    sTYMWork->jobInfo = GetJobSlotInfo(jobSlotIndex);
    sub_8096EEC(sTYMWork->jobInfo);
    sub_803C21C(sTYMWork->jobInfo, &sTYMWork->rewards);

    sTYMWork->monPortrait.faceFile = GetDialogueSpriteDataPtr(sTYMWork->jobInfo->clientSpecies);
    sTYMWork->monPortrait.faceData = NULL;
    sTYMWork->monPortrait.spriteId = 0;
    sTYMWork->monPortrait.flip = FALSE;
    sTYMWork->monPortrait.unkE = 0;
    sTYMWork->monPortrait.pos.x = 2;
    sTYMWork->monPortrait.pos.y = 8;

    if (sTYMWork->monPortrait.faceFile != NULL)
        sTYMWork->monPortrait.faceData = (PortraitGfx *)sTYMWork->monPortrait.faceFile->data;

    TYM_SetState(TYM_STATE_0);
    return TRUE;
}

u32 TYM_Update(void)
{
    switch (sTYMWork->state) {
        case TYM_STATE_7: {
            sTYMWork->jobInfo->mailType = WONDER_MAIL_TYPE_OKD;
            return 3;
        }
        case TYM_STATE_6: {
            sub_802DE44();
            return 0;
        }
        default: {
            TYM_ProceedToNextState();
            return 0;
        }
    }
}

void TYM_Destroy(void)
{
    if (sTYMWork != NULL) {
        TRY_CLOSE_FILE(sTYMWork->monPortrait.faceFile);
        FREE_AND_SET_NULL(sTYMWork);
    }
}

static void TYM_SetState(u32 newState)
{
    sTYMWork->state = newState;
    TYM_InitStateWindows();
    TYM_InitStateDialogue();
}

static void TYM_InitStateWindows(void)
{
    s32 i;

    RestoreSavedWindows(&sTYMWork->windows);

    switch (sTYMWork->state) {
        case TYM_STATE_0:
        case TYM_STATE_7: {
            for (i = 0; i < MAX_WINDOWS; i++)
                sTYMWork->windows.id[i]  = sDummyWinTemplate;
            break;
        }
    }

    ResetUnusedInputStruct();
    ShowWindows(&sTYMWork->windows, TRUE, TRUE);
}

static void TYM_InitStateDialogue(void)
{
    switch (sTYMWork->state) {
        case TYM_STATE_0: {
            u8 *speciesText;

            CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, sTYMWork->jobInfo->clientSpecies);
            CopyYellowMonsterNametoBuffer(gFormatBuffer_Monsters[7], sTYMWork->jobInfo->clientSpecies);

            speciesText = GetMonSpecies(sTYMWork->jobInfo->clientSpecies);
            strcpy(gFormatBuffer_Monsters[0], speciesText);

            speciesText = GetMonSpecies(sTYMWork->jobInfo->targetSpecies);
            strcpy(gFormatBuffer_Monsters[1], speciesText);

            UnlockExclusivePokemon(sTYMWork->jobInfo->clientSpecies);
            BufferItemName(gFormatBuffer_Items[0], sTYMWork->jobInfo->targetItem, NULL);

            sTYMWork->fallbackState = TYM_STATE_6;

            switch (sTYMWork->jobInfo->missionType) {
                case WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM: {
                    TYM_SetState(TYM_STATE_5);
                    break;
                }
                case WONDER_MAIL_MISSION_TYPE_FIND_ITEM: {
                    TYM_SetState(TYM_STATE_4);
                    break;
                }
                case WONDER_MAIL_MISSION_TYPE_RESCUE_TARGET: {
                    TYM_SetState(TYM_STATE_2);
                    UnlockExclusivePokemon(sTYMWork->jobInfo->targetSpecies);
                    break;
                }
                case WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT: {
                    TYM_SetState(TYM_STATE_3);
                    UnlockExclusivePokemon(sTYMWork->jobInfo->targetSpecies);
                    break;
                }
                default:
                case WONDER_MAIL_MISSION_TYPE_RESCUE_CLIENT: {
                    TYM_SetState(TYM_STATE_1);
                    break;
                }
            }
            break;
        }
        case TYM_STATE_1: {
            CreateDialogueBoxAndPortrait(sThanksForRescuingMe, 0, &sTYMWork->monPortrait, 0x10D);
            break;
        }
        case TYM_STATE_2: {
            CreateDialogueBoxAndPortrait(sThanksForRescuingThem, 0, &sTYMWork->monPortrait, 0x10D);
            break;
        }
        case TYM_STATE_3: {
            CreateDialogueBoxAndPortrait(sThanksForEscortingMe, 0, &sTYMWork->monPortrait, 0x10D);
            break;
        }
        case TYM_STATE_5: {
            CreateDialogueBoxAndPortrait(sThanksForDelivering, 0, &sTYMWork->monPortrait, 0x10D);
            break;
        }
        case TYM_STATE_4: {
            s32 index = FindItemInInventory(sTYMWork->jobInfo->targetItem);
            if (index != -1) {
                ShiftItemsDownFrom(index);
                FillInventoryGaps();
            }
            CreateDialogueBoxAndPortrait(sThanksForGetting, 0, &sTYMWork->monPortrait, 0x10D);
            break;
        }
        case TYM_STATE_6: {
            MR_Create(&sTYMWork->rewards, TRUE);
            break;
        }
        case TYM_STATE_7:
        default: {
            break;
        }
    }
}

static void sub_802DE44(void)
{
    switch (MR_Update()) {
        case 2:
        case 3: {
            MR_Destroy();
            TYM_SetState(TYM_STATE_7);
            break;
        }
        case 0:
        case 1: {
            break;
        }
    }
}

static void TYM_ProceedToNextState(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        TYM_SetState(sTYMWork->fallbackState);
}
