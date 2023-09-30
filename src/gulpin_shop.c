#include "global.h"
#include "code_80118A4.h"
#include "code_801EE10.h"
#include "code_801EE10_mid.h"
#include "code_80130A8.h"
#include "common_strings.h"
#include "gulpin_shop.h"
#include "input.h"
#include "pokemon.h"
#include "memory.h"
#include "menu_input.h"
#include "moves.h"
#include "text1.h"
#include "text2.h"

extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 GulpinShopWork *sGulpinShopWork = {0};

#include "data/gulpin_shop.h"

static void SetGulpinShopState(u32);

static void sub_801E980(void);
static void sub_801EA28(void);
static void sub_801EBC4(void);
static void sub_801EC7C(void);
static void sub_801ECBC(void);
static void sub_801ED28(void);
static void sub_801EDA4(void);
static void sub_801EDC0(void);

bool8 CreateGulpinShop(u32 mode, s16 pokeSpecies, Move *moves)
{
    OpenedFile *faceFile;
    s32 species_32;

    species_32 = pokeSpecies; // dumb cast needed to get lsr/asr combo

    sGulpinShopWork = MemoryAlloc(sizeof(GulpinShopWork), 8);
    sGulpinShopWork->mode = mode;
    sGulpinShopWork->speciesNum = species_32;
    sGulpinShopWork->moves = moves;
    sGulpinShopWork->unk1C = moves[4].id; // 5th move..?

    if (mode == GULPIN_SHOP_MODE_AWAKE)
        sGulpinShopWork->unk128 = &sGulpinShopWork->faceFile;
    else
        sGulpinShopWork->unk128 = NULL;

    faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
    sGulpinShopWork->faceFile = faceFile;
    sGulpinShopWork->faceData = faceFile->data;

    sGulpinShopWork->unk124 = 0;
    sGulpinShopWork->unk125 = 0;
    sGulpinShopWork->unk126 = 0;

    sGulpinShopWork->unk120 = 2;
    sGulpinShopWork->unk122 = 8;
    SetGulpinShopState(0);
    return TRUE;
}

u32 sub_801E8C0(void)
{
    switch (sGulpinShopWork->state) {
        case 0:
        case 1:
            sub_801ECBC();
            break;
        case 2:
            sub_801ED28();
            break;
        case 3:
            sub_801EDA4();
            break;
        case 4:
            sub_801EDC0();
            if (sGulpinShopWork->state == 5)
                return 3;
            break;
        case 5:
            return 3;
        case 6:
            return 2;
    }
    return 0;
}

bool8 GulpinIsNextMoveLinked(void)
{
    return sGulpinShopWork->isNextMoveLinked;
}

void DestroyGulpinShop(void)
{
    if (sGulpinShopWork != NULL) {
        CloseFile(sGulpinShopWork->faceFile);
        MemoryFree(sGulpinShopWork);
        sGulpinShopWork = NULL;
    }
}

static void SetGulpinShopState(u32 newState)
{
    sGulpinShopWork->state = newState;
    sub_801E980();
    sub_801EA28();
}

static void sub_801E980(void)
{
    s32 index;

    sub_8006518(sGulpinShopWork->unk12C);

    switch (sGulpinShopWork->state) {
        case 2:
            sub_801EBC4();
            sGulpinShopWork->unk12C[1] = gUnknown_80DC11C;
            sGulpinShopWork->unk12C[2] = gUnknown_80DC134;
            sub_8012CAC(&sGulpinShopWork->unk12C[2], sGulpinShopWork->unk28);
            break;
        default:
            for(index = 0; index < 4; index++) {
                sGulpinShopWork->unk12C[index] = gUnknown_80DC11C;
            }
            break;
    }

    ResetUnusedInputStruct();
    sub_800641C(sGulpinShopWork->unk12C, TRUE, TRUE);
}

static void sub_801EA28(void)
{
    switch (sGulpinShopWork->state) {
        case 0:
            sub_801EE10(2, sGulpinShopWork->speciesNum, sGulpinShopWork->moves, 0, sWillAMoveBeForgotten, 0);
            break;
        case 1:
            sub_801F1B0(TRUE, FALSE);
            break;
        case 2:
            sub_801F280(0);
            sub_8012D60(&sGulpinShopWork->unk78, sGulpinShopWork->unk28, 0, sGulpinShopWork->unk68, sGulpinShopWork->unk24, 2);
            break;
        case 3:
            GetLinkedSequence(sGulpinShopWork->unk20, sGulpinShopWork->moves, &sGulpinShopWork->unk14[0]);
            sub_801F808(&sGulpinShopWork->unk14[0]);
            break;
        case 4:
            sub_801EC7C();
            sub_8092C84(gAvailablePokemonNames, sGulpinShopWork->unk1C);
            sub_8092C84(&gAvailablePokemonNames[0x50], sGulpinShopWork->unk1E);

            switch (sGulpinShopWork->mode) {
                case GULPIN_SHOP_MODE_AWAKE:
                case GULPIN_SHOP_MODE_ASLEEP:
                    if (sGulpinShopWork->isNextMoveLinked)
                        sub_8014248(gCommonGulpin[sGulpinShopWork->mode][GULPIN_DLG_12], 0, 5, &sGulpinShopWork->unk28[0], &sGulpinShopWork->unk68, 4, 0, sGulpinShopWork->unk128, 12);
                    else
                        sub_8014248(gCommonGulpin[sGulpinShopWork->mode][GULPIN_DLG_11], 0, 5, &sGulpinShopWork->unk28[0], &sGulpinShopWork->unk68, 4, 0, sGulpinShopWork->unk128, 12);
                    break;
                case GULPIN_SHOP_MODE_UNK2:
                    if (sGulpinShopWork->isNextMoveLinked)
                        sub_8014248(sForgetMoveAndLinkedOnes, 0, 5, &sGulpinShopWork->unk28[0], &sGulpinShopWork->unk68, 4, 0, NULL, 32);
                    else
                        sub_8014248(sForgetMoveOnly, 0, 5, &sGulpinShopWork->unk28[0], &sGulpinShopWork->unk68, 4, 0, NULL, 32);
                    break;
            }
            break;
    }
}

static void sub_801EBC4(void)
{
    s32 which;
    s32 i;
    which = 0;
    
    MemoryFill16(sGulpinShopWork->unk68, 0, sizeof(sGulpinShopWork->unk68));
    
    sGulpinShopWork->unk28[which].text = sForget;
    sGulpinShopWork->unk28[which].menuAction = 2;
    
    if (!IsAnyMoveLinked(sGulpinShopWork->unk1E, sGulpinShopWork->moves) || (s32)sGulpinShopWork->unk20 >= 4)
        sGulpinShopWork->unk68[0] = 1;
    
    which++;
    sGulpinShopWork->unk28[which].text = gCommonInfo[0];
    sGulpinShopWork->unk28[which].menuAction = 3;
    which++;
    sGulpinShopWork->unk28[which].text = NULL;
    sGulpinShopWork->unk28[which].menuAction = 1;

    i = 0;
    if (i < which) {
        if (sGulpinShopWork->unk68[0] == 0)
            sGulpinShopWork->unk24 = sGulpinShopWork->unk28[0].menuAction;
        else {
            while (i < which) {
                if (sGulpinShopWork->unk68[i] == 0) {
                    sGulpinShopWork->unk24 = sGulpinShopWork->unk28[i].menuAction;
                    break;
                }
                i++;
            }
        }
    }
}

static void sub_801EC7C(void)
{
    s32 which;
    which = 0;
    
    MemoryFill16(sGulpinShopWork->unk68, 0, sizeof(sGulpinShopWork->unk68));
    sGulpinShopWork->unk28[which].text = gCommonYes[0];
    sGulpinShopWork->unk28[which].menuAction = 4;
    which++;
    sGulpinShopWork->unk28[which].text = gCommonNo[0];
    sGulpinShopWork->unk28[which].menuAction = 5;
    which++;
    sGulpinShopWork->unk28[which].text = NULL;
    sGulpinShopWork->unk28[which].menuAction = 1;
}

static void sub_801ECBC(void)
{
    switch (sub_801EF38(1)) {
        case 3:
        {
            Move* move;
            sGulpinShopWork->unk20 = sub_801F194();
            move = sGulpinShopWork->moves;
            move = &move[sGulpinShopWork->unk20];
            sGulpinShopWork->unk1E = move->id;
            SetGulpinShopState(2);
            break;
        }
        case 4:
        {
            Move* move;
            sGulpinShopWork->unk20 = sub_801F194();
            move = sGulpinShopWork->moves;
            move = &move[sGulpinShopWork->unk20];
            sGulpinShopWork->unk1E = move->id;
            SetGulpinShopState(3);
            break;
        }
        case 2:
            sub_801F214();
            SetGulpinShopState(6);
            break;
    }
}

static void sub_801ED28(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801EF38(0);
    if (sub_8012FD8(&sGulpinShopWork->unk78) == 0)
        sub_8013114(&sGulpinShopWork->unk78, &menuAction);

    switch (menuAction) {
        case 1:
        case 5:
            SetGulpinShopState(1);
            break;
        case 2:
            PlaySound(0x133);
            sGulpinShopWork->isNextMoveLinked = IsNextMoveLinked(sGulpinShopWork->unk20, sGulpinShopWork->moves);
            SetGulpinShopState(4);
            break;
        case 3:
            SetGulpinShopState(3);
            break;
    }
}

static void sub_801EDA4(void)
{
    switch (sub_801F890()) {
        case 2:
        case 3:
            sub_801F8D0();
            SetGulpinShopState(1);
            break;
        case 0:
        case 1:
            break;
    }
}

static void sub_801EDC0(void)
{
    s32 temp;

    if (sub_80144A4(&temp) == 0) {
        switch (temp) {
            case 4:
                sub_801F214();
                RemoveLinkSequenceFromMoves8(sGulpinShopWork->moves, sGulpinShopWork->unk20);
                sGulpinShopWork->state = 5;
                break;
            case 1:
            case 5:
                SetGulpinShopState(1);
                break;
        }
    }
}