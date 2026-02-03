#include "global.h"
#include "globaldata.h"
#include "code_8099360.h"
#include "memory.h"
#include "save.h"
#include "save_write.h"
#include "string_format.h"
#include "menu_input.h"
#include "ground_main.h"

// size: 0x20
typedef struct SavePakWrite
{
    /* 0x0 */ u32 state;
    s32 unk4;
    /* 0x8 */ u32 saveStatus;
    /* 0xC */ MonPortraitMsg monPortrait;
    /* 0x1C */ u16 pokeID;
} SavePakWrite;

static EWRAM_INIT SavePakWrite *sSavePakWrite = {NULL};

#include "data/save_write.h"

void PrepareSavePakWrite(s16 pokemonID)
{
    OpenedFile *file;
    s32 id_s32;

    id_s32 = pokemonID; // had to cast for asr shift

    sub_80993D8();
    sSavePakWrite = MemoryAlloc(sizeof(SavePakWrite), MEMALLOC_GROUP_5);
    sSavePakWrite->pokeID = id_s32;
    sSavePakWrite->monPortrait.faceFile = NULL;
    sSavePakWrite->monPortrait.faceData = NULL;

    if (pokemonID != MONSTER_NONE) {
        file = GetDialogueSpriteDataPtr(pokemonID);
        sSavePakWrite->monPortrait.faceFile = file;
        sSavePakWrite->monPortrait.faceData = (PortraitGfx *) file->data;
        sSavePakWrite->monPortrait.spriteId = 0;
        sSavePakWrite->monPortrait.flip = FALSE;
        sSavePakWrite->monPortrait.unkE = 0;
        sSavePakWrite->monPortrait.pos.x = 2;
        sSavePakWrite->monPortrait.pos.y = 8;
    }

    if (sSavePakWrite->monPortrait.faceFile != 0) {
        MonPortraitMsg *monPortraitPtr = &sSavePakWrite->monPortrait;
        CreateDialogueBoxAndPortrait(sSavingAdventure, 0, monPortraitPtr, 0x20);
    }
    else
        CreateDialogueBoxAndPortrait(sSavingAdventure, 0, NULL, 0x20);

    sSavePakWrite->state = 3;
}

bool8 WriteSavePak(void)
{
    MonPortraitMsg *monPortraitPtr;
    u32 local_14;
    u32 other_stack;

    monPortraitPtr = NULL;
    if (sSavePakWrite->monPortrait.faceFile != NULL)
        monPortraitPtr = &sSavePakWrite->monPortrait;

    switch (sSavePakWrite->state) {
        case 0:
            sSavePakWrite->state = 7;
            break;
        case 1:
            sSavePakWrite->unk4++;
            if (sSavePakWrite->unk4 > 8) {
                CreateDialogueBoxAndPortrait(sWriteGamePak, 0, 0, 0x20);
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
                    if (sSavePakWrite->monPortrait.faceFile != NULL)
                        CreateDialogueBoxAndPortrait(sSaveCompleted, 0, monPortraitPtr, 0x101);
                    else
                        CreateDialogueBoxAndPortrait(sSaveCompleted, 0, monPortraitPtr, 0x101);

                    sSavePakWrite->state = 5;
                    break;
                case SAVE_NOT_WRTTEN:
                    CreateDialogueBoxAndPortrait(sSaveNotWritten, 0, 0, 0);
                    sSavePakWrite->state = 6;
                    break;
                default:
                    if (sSavePakWrite->monPortrait.faceFile != NULL)
                        CreateDialogueBoxAndPortrait(sSaveFailed, 0, monPortraitPtr, 0x101);
                    else
                        CreateDialogueBoxAndPortrait(sSaveFailed, 0, monPortraitPtr, 0x101);

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
        TRY_CLOSE_FILE(sSavePakWrite->monPortrait.faceFile);
        FREE_AND_SET_NULL(sSavePakWrite);
    }
    sub_80993E4();
}
