#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_802DB28.h"
#include "code_802F204.h"
#include "code_803C1D0.h"
#include "code_80958E8_1.h"
#include "code_8096AF8.h"
#include "exclusive_pokemon.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

extern u8 gUnknown_202DE58[];
extern u8 gUnknown_202E1C8[];
extern u8 gUnknown_202E5D8[];

static EWRAM_DATA_2 struct unkStruct_203B2FC *sUnknown_203B2FC = {0};

#include "data/code_802DB28.h"

static void sub_802DC28(u32 newState);
static void sub_802DC40(void);
static void sub_802DC9C(void);
static void sub_802DE44(void);
static void sub_802DE60(void);

bool8 sub_802DB28(u8 jobSlotIndex, u8 dungeon)
{
    struct unkStruct_8096AF8 local_18;

    sub_8096AF8(&local_18, jobSlotIndex, dungeon);

    if (!local_18.unk0)
        return FALSE;

    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);

    sUnknown_203B2FC = MemoryAlloc(sizeof(struct unkStruct_203B2FC), 8);
    sUnknown_203B2FC->jobSlotIndex = jobSlotIndex;
    sUnknown_203B2FC->jobInfo = GetJobSlotInfo(jobSlotIndex);
    sub_8096EEC(sUnknown_203B2FC->jobInfo);
    sub_803C21C(sUnknown_203B2FC->jobInfo, &sUnknown_203B2FC->unk8);

    sUnknown_203B2FC->faceFile = GetDialogueSpriteDataPtr(sUnknown_203B2FC->jobInfo->clientSpecies);
    sUnknown_203B2FC->faceData = NULL;
    sUnknown_203B2FC->unk44 = 0;
    sUnknown_203B2FC->unk45 = 0;
    sUnknown_203B2FC->unk46 = 0;
    sUnknown_203B2FC->unk40 = 2;
    sUnknown_203B2FC->unk42 = 8;

    if (sUnknown_203B2FC->faceFile != NULL)
        sUnknown_203B2FC->faceData = sUnknown_203B2FC->faceFile->data;

    sub_802DC28(0);
    return TRUE;
}

u32 sub_802DBD4(void)
{
    switch (sUnknown_203B2FC->state) {
        case 7:
            sUnknown_203B2FC->jobInfo->mailType = WONDER_MAIL_TYPE_OKD;
            return 3;
        case 6:
            sub_802DE44();
            return 0;
        default:
            sub_802DE60();
            return 0;
    }
}

void sub_802DC00(void)
{
    if (sUnknown_203B2FC != NULL) {
        if (sUnknown_203B2FC->faceFile != NULL)
            CloseFile(sUnknown_203B2FC->faceFile);

        MemoryFree(sUnknown_203B2FC);
        sUnknown_203B2FC = NULL;
    }
}

static void sub_802DC28(u32 newState)
{
    sUnknown_203B2FC->state = newState;
    sub_802DC40();
    sub_802DC9C();
}

static void sub_802DC40(void)
{
    s32 i;

    sub_8006518(sUnknown_203B2FC->unk48);

    switch (sUnknown_203B2FC->state) {
        case 0:
        case 7:
            for (i = 0; i < 4; i++)
                sUnknown_203B2FC->unk48[i]  = sUnknown_80E016C;
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2FC->unk48, TRUE, TRUE);
}

static void sub_802DC9C(void)
{
    u8 *speciesText;
    s32 index;

    switch (sUnknown_203B2FC->state) {
        case 0:
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, sUnknown_203B2FC->jobInfo->clientSpecies);
            CopyYellowMonsterNametoBuffer(gUnknown_202E1C8, sUnknown_203B2FC->jobInfo->clientSpecies);
            speciesText = GetMonSpecies(sUnknown_203B2FC->jobInfo->clientSpecies);
            strcpy(gUnknown_202E1C8 - 560, speciesText);
            speciesText = GetMonSpecies(sUnknown_203B2FC->jobInfo->targetSpecies);
            strcpy(gUnknown_202E1C8 - 480, speciesText);
            UnlockExclusivePokemon(sUnknown_203B2FC->jobInfo->clientSpecies);
            BufferItemName(gUnknown_202DE58, sUnknown_203B2FC->jobInfo->targetItem, NULL);
            sUnknown_203B2FC->fallbackState = 6;

            switch (sUnknown_203B2FC->jobInfo->missionType) {
                case WONDER_MAIL_MISSION_TYPE_DELIVER_ITEM:
                    sub_802DC28(5);
                    break;
                case WONDER_MAIL_MISSION_TYPE_FIND_ITEM:
                    sub_802DC28(4);
                    break;
                case WONDER_MAIL_MISSION_TYPE_RESCUE_TARGET:
                    sub_802DC28(2);
                    UnlockExclusivePokemon(sUnknown_203B2FC->jobInfo->targetSpecies);
                    break;
                case WONDER_MAIL_MISSION_TYPE_ESCORT_CLIENT:
                    sub_802DC28(3);
                    UnlockExclusivePokemon(sUnknown_203B2FC->jobInfo->targetSpecies);
                    break;
                default:
                case WONDER_MAIL_MISSION_TYPE_RESCUE_CLIENT:
                    sub_802DC28(1);
                    break;
            }
            break;
        case 1:
            sub_80141B4(sThanksForRescuingMe, 0, &sUnknown_203B2FC->faceFile, 0x10D);
            break;
        case 2:
            sub_80141B4(sThanksForRescuingThem, 0, &sUnknown_203B2FC->faceFile, 0x10D);
            break;
        case 3:
            sub_80141B4(sThanksForEscortingMe, 0, &sUnknown_203B2FC->faceFile, 0x10D);
            break;
        case 5:
            sub_80141B4(sThanksForDelivering, 0, &sUnknown_203B2FC->faceFile, 0x10D);
            break;
        case 4:
            index = FindItemInInventory(sUnknown_203B2FC->jobInfo->targetItem);
            if (index != -1) {
                ShiftItemsDownFrom(index);
                FillInventoryGaps();
            }
            sub_80141B4(sThanksForGetting, 0, &sUnknown_203B2FC->faceFile, 0x10D);
            break;
        case 6:
            sub_802F204(&sUnknown_203B2FC->unk8, 1);
            break;
        case 7:
        default:
            break;
    }
}

static void sub_802DE44(void)
{
    switch (sub_802F298()) {
        case 2:
        case 3:
            sub_802F2C0();
            sub_802DC28(7);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_802DE60(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0)
        sub_802DC28(sUnknown_203B2FC->fallbackState);
}
