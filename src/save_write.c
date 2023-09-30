#include "global.h"
#include "globaldata.h"
#include "code_80130A8.h"
#include "code_8098BDC.h"
#include "memory.h"
#include "save.h"
#include "save_write.h"

static EWRAM_DATA_2 SavePakWrite *sSavePakWrite = {0};

#include "data/save_write.h"

void PrepareSavePakWrite(s16 pokemonID)
{
    OpenedFile *file;
    s32 id_s32;
    OpenedFile **preload_face;

    id_s32 = pokemonID; // had to cast for asr shift

    sub_80993D8();
    sSavePakWrite = MemoryAlloc(sizeof(SavePakWrite), 5);
    sSavePakWrite->pokeID = id_s32;
    sSavePakWrite->faceFile = NULL;
    sSavePakWrite->faceData = NULL;

    if (pokemonID != MONSTER_NONE) {
        file = GetDialogueSpriteDataPtr(pokemonID);
        sSavePakWrite->faceFile = file;
        sSavePakWrite->faceData = file->data;
        sSavePakWrite->unk18 = 0;
        sSavePakWrite->unk19 = 0;
        sSavePakWrite->unk1A = 0;
        sSavePakWrite->unk14 = 2;
        sSavePakWrite->unk16 = 8;
    }

    if (sSavePakWrite->faceFile != 0) {
        preload_face = &sSavePakWrite->faceFile;
        sub_80141B4(sSavingAdventure, 0, preload_face, 0x20);
    }
    else
        sub_80141B4(sSavingAdventure, 0, NULL, 0x20);

    sSavePakWrite->state = 3;
}

bool8 WriteSavePak(void)
{
    OpenedFile **faceFile;
    u32 local_14;
    u32 other_stack;

    faceFile = NULL;
    if (sSavePakWrite->faceFile != NULL)
        faceFile = &sSavePakWrite->faceFile;

    switch (sSavePakWrite->state) {
        case 0:
            sSavePakWrite->state = 7;
            break;
        case 1:
            sSavePakWrite->unk4++;
            if (sSavePakWrite->unk4 > 8) {
                sub_80141B4(sWriteGamePak, 0, 0, 0x20);
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
                    if (sSavePakWrite->faceFile != NULL)
                        sub_80141B4(sSaveCompleted, 0, faceFile, 0x101);
                    else
                        sub_80141B4(sSaveCompleted, 0, faceFile, 0x101);

                    sSavePakWrite->state = 5;
                    break;
                case SAVE_NOT_WRTTEN:
                    sub_80141B4(sSaveNotWritten, 0, 0, 0);
                    sSavePakWrite->state = 6;
                    break;
                default:
                    if (sSavePakWrite->faceFile != NULL)
                        sub_80141B4(sSaveFailed, 0, faceFile, 0x101);
                    else
                        sub_80141B4(sSaveFailed, 0, faceFile, 0x101);

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
        if (sSavePakWrite->faceFile != NULL)
            CloseFile(sSavePakWrite->faceFile);
        MemoryFree(sSavePakWrite);
        sSavePakWrite = NULL;
    }
    sub_80993E4();
}