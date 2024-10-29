#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_802DB28.h"
#include "code_802F204.h"
#include "code_803C1D0.h"
#include "code_80958E8.h"
#include "exclusive_pokemon.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"

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
    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);

    sUnknown_203B2FC = MemoryAlloc(sizeof(struct unkStruct_203B2FC), 8);
    sUnknown_203B2FC->jobSlotIndex = jobSlotIndex;
    sUnknown_203B2FC->jobInfo = GetJobSlotInfo(jobSlotIndex);
    sub_8096EEC(sUnknown_203B2FC->jobInfo);
    sub_803C21C(sUnknown_203B2FC->jobInfo, &sUnknown_203B2FC->unk8);

    sUnknown_203B2FC->monPortrait.faceFile = GetDialogueSpriteDataPtr(sUnknown_203B2FC->jobInfo->clientSpecies);
    sUnknown_203B2FC->monPortrait.faceData = NULL;
    sUnknown_203B2FC->monPortrait.spriteId = 0;
    sUnknown_203B2FC->monPortrait.flip = FALSE;
    sUnknown_203B2FC->monPortrait.unkE = 0;
    sUnknown_203B2FC->monPortrait.pos.x = 2;
    sUnknown_203B2FC->monPortrait.pos.y = 8;

    if (sUnknown_203B2FC->monPortrait.faceFile != NULL)
        sUnknown_203B2FC->monPortrait.faceData = (void *) sUnknown_203B2FC->monPortrait.faceFile->data;

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
        if (sUnknown_203B2FC->monPortrait.faceFile != NULL)
            CloseFile(sUnknown_203B2FC->monPortrait.faceFile);

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

    RestoreUnkTextStruct_8006518(sUnknown_203B2FC->unk48);

    switch (sUnknown_203B2FC->state) {
        case 0:
        case 7:
            for (i = 0; i < 4; i++)
                sUnknown_203B2FC->unk48[i]  = sUnknown_80E016C;
            break;
    }

    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sUnknown_203B2FC->unk48, TRUE, TRUE);
}

static void sub_802DC9C(void)
{
    u8 *speciesText;
    s32 index;

    switch (sUnknown_203B2FC->state) {
        case 0:
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, sUnknown_203B2FC->jobInfo->clientSpecies);
            CopyYellowMonsterNametoBuffer(gAvailablePokemonNames[7], sUnknown_203B2FC->jobInfo->clientSpecies);
            speciesText = GetMonSpecies(sUnknown_203B2FC->jobInfo->clientSpecies);
            strcpy(gAvailablePokemonNames[0], speciesText);
            speciesText = GetMonSpecies(sUnknown_203B2FC->jobInfo->targetSpecies);
            strcpy(gAvailablePokemonNames[1], speciesText);
            UnlockExclusivePokemon(sUnknown_203B2FC->jobInfo->clientSpecies);
            BufferItemName(gFormatItems[0], sUnknown_203B2FC->jobInfo->targetItem, NULL);
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
            CreateDialogueBoxAndPortrait(sThanksForRescuingMe, 0, &sUnknown_203B2FC->monPortrait, 0x10D);
            break;
        case 2:
            CreateDialogueBoxAndPortrait(sThanksForRescuingThem, 0, &sUnknown_203B2FC->monPortrait, 0x10D);
            break;
        case 3:
            CreateDialogueBoxAndPortrait(sThanksForEscortingMe, 0, &sUnknown_203B2FC->monPortrait, 0x10D);
            break;
        case 5:
            CreateDialogueBoxAndPortrait(sThanksForDelivering, 0, &sUnknown_203B2FC->monPortrait, 0x10D);
            break;
        case 4:
            index = FindItemInInventory(sUnknown_203B2FC->jobInfo->targetItem);
            if (index != -1) {
                ShiftItemsDownFrom(index);
                FillInventoryGaps();
            }
            CreateDialogueBoxAndPortrait(sThanksForGetting, 0, &sUnknown_203B2FC->monPortrait, 0x10D);
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
