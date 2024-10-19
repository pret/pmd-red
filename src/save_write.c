#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_8099360.h"
#include "memory.h"
#include "save.h"
#include "save_write.h"

static EWRAM_DATA_2 SavePakWrite *sSavePakWrite = {0};

#include "data/save_write.h"

void PrepareSavePakWrite(s16 pokemonID)
{
    OpenedFile *file;
    s32 id_s32;

    id_s32 = pokemonID; // had to cast for asr shift

    sub_80993D8();
    sSavePakWrite = MemoryAlloc(sizeof(SavePakWrite), 5);
    sSavePakWrite->pokeID = id_s32;
    sSavePakWrite->faceInfo.faceFile = NULL;
    sSavePakWrite->faceInfo.faceData = NULL;

    if (pokemonID != MONSTER_NONE) {
        file = GetDialogueSpriteDataPtr(pokemonID);
        sSavePakWrite->faceInfo.faceFile = file;
        sSavePakWrite->faceInfo.faceData = file->data;
        sSavePakWrite->faceInfo.unkC = 0;
        sSavePakWrite->faceInfo.unkD = 0;
        sSavePakWrite->faceInfo.unkE = 0;
        sSavePakWrite->faceInfo.unk8 = 2;
        sSavePakWrite->faceInfo.unkA = 8;
    }

    if (sSavePakWrite->faceInfo.faceFile != 0) {
        struct UnkPrintFieldMsgStruct *faceInfoPtr = &sSavePakWrite->faceInfo;
        xxx_info_box_80141B4(sSavingAdventure, 0, faceInfoPtr, 0x20);
    }
    else
        xxx_info_box_80141B4(sSavingAdventure, 0, NULL, 0x20);

    sSavePakWrite->state = 3;
}

bool8 WriteSavePak(void)
{
    struct UnkPrintFieldMsgStruct *faceInfoPtr;
    u32 local_14;
    u32 other_stack;

    faceInfoPtr = NULL;
    if (sSavePakWrite->faceInfo.faceFile != NULL)
        faceInfoPtr = &sSavePakWrite->faceInfo;

    switch (sSavePakWrite->state) {
        case 0:
            sSavePakWrite->state = 7;
            break;
        case 1:
            sSavePakWrite->unk4++;
            if (sSavePakWrite->unk4 > 8) {
                xxx_info_box_80141B4(sWriteGamePak, 0, 0, 0x20);
                sSavePakWrite->state = 3;
            }
            break;
        case 2:
            break;
        case 3:
            sSavePakWrite->state = 4;
            break;
        case 4:
            local_14 = 0;
            sub_80140DC();
            sSavePakWrite->saveStatus = WriteSavetoPak(&local_14, sub_8011C1C());

            switch (sSavePakWrite->saveStatus) {
                case SAVE_COMPLETED:
                    if (sSavePakWrite->faceInfo.faceFile != NULL)
                        xxx_info_box_80141B4(sSaveCompleted, 0, faceInfoPtr, 0x101);
                    else
                        xxx_info_box_80141B4(sSaveCompleted, 0, faceInfoPtr, 0x101);

                    sSavePakWrite->state = 5;
                    break;
                case SAVE_NOT_WRTTEN:
                    xxx_info_box_80141B4(sSaveNotWritten, 0, 0, 0);
                    sSavePakWrite->state = 6;
                    break;
                default:
                    if (sSavePakWrite->faceInfo.faceFile != NULL)
                        xxx_info_box_80141B4(sSaveFailed, 0, faceInfoPtr, 0x101);
                    else
                        xxx_info_box_80141B4(sSaveFailed, 0, faceInfoPtr, 0x101);

                    sSavePakWrite->state = 5;
                    break;
            }
            sub_8014114();
            break;
        case 5:
            if (sub_80144A4(&other_stack) == 0)
                sSavePakWrite->state = 7;
            break;
        case 6:
            break;
        case 7:
            return FALSE;
    }
    return TRUE;
}

u32 GetSavePakStatus(void)
{
    return sSavePakWrite->saveStatus;
}

void FinishWriteSavePak(void)
{
    if (sSavePakWrite != NULL) {
        if (sSavePakWrite->faceInfo.faceFile != NULL)
            CloseFile(sSavePakWrite->faceInfo.faceFile);
        MemoryFree(sSavePakWrite);
        sSavePakWrite = NULL;
    }
    sub_80993E4();
}
