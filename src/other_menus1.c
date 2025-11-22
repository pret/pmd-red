#include "global.h"
#include "globaldata.h"
#include "constants/communication_error_codes.h"
#include "constants/main_menu.h"
#include "structs/str_dungeon.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "music_util.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus1.h"
#include "other_menus2.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT unkStruct_203B35C *sUnknown_203B35C = {NULL};

#include "data/other_menus1.h"

static void sub_80371B8(void);
static void sub_8037400(void);
static void sub_80376CC(void);
static void sub_8037748(void);
static u32 sub_8037798(void);
static void sub_8037810(void);
static void sub_8037900(void);

void sub_8036FDC(s32 param_1)
{
    s32 index1;
    s32 index2;

    ResetUnusedInputStruct();
    ShowWindows(NULL, TRUE, TRUE);
    ResetSprites(FALSE);

    if (sUnknown_203B35C == NULL) {
        sUnknown_203B35C = MemoryAlloc(sizeof(unkStruct_203B35C), 8);
        MemoryFill8(sUnknown_203B35C, 0, sizeof(unkStruct_203B35C));
    }

    sUnknown_203B35C->unk0 = param_1;
    sUnknown_203B35C->linkStatus = COMMS_GOOD;
    sUnknown_203B35C->state = 0;

    for (index1 = 0; index1 < 2; index1++) {
        sUnknown_203B35C->unk1BC[index1].numItems = 0;
        sUnknown_203B35C->unk1BC[index1].itemIndex = ITEM_NOTHING;
    }

    for (index2 = 0; index2 < 4; index2++)
        sUnknown_203B35C->unk15C.id[index2] = sUnknown_80E653C;

    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B35C->unk15C, TRUE, TRUE);
    SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6CD0, sUnknown_80E6CE8, FALSE, 6, FALSE);
    sub_8035CF4(sUnknown_203B35C->unk1C, 0, TRUE);
    sub_80376CC();
}

void sub_80370D4(void)
{
    if (sUnknown_203B35C != NULL) {
        MemoryFree(sUnknown_203B35C);
        sUnknown_203B35C = NULL;
    }
}

UNUSED static u32 sub_80370F0(void)
{
    u32 nextMenu;
    s32 local_10;

    local_10 = 4;
    nextMenu = MENU_NO_SCREEN_CHANGE;

    switch (sUnknown_203B35C->state) {
        case 0:
            if (!sub_80130A8(&sUnknown_203B35C->unk1C[0]))
                sub_8013114(&sUnknown_203B35C->unk1C[0],&local_10);

            if (local_10 == 4)
                sub_8037748();
            else {
                sUnknown_203B35C->state = 1;
                sub_8037900();
            }
            break;
        case 1:
            sub_80376CC();
            sUnknown_203B35C->state = 2;
            sub_80371B8();
            break;
        case 2:
            if (sUnknown_203B35C->unk0 < 2 && sUnknown_203B35C->linkStatus == COMMS_GOOD && sub_8037C10(FALSE) == 0)
                return 41; // TODO: what screen is this?

            if (!sub_80130A8(&sUnknown_203B35C->unk1C[0]))
                sub_8013114(&sUnknown_203B35C->unk1C[0], &local_10);

            if (local_10 != 4) {
                PlayMenuSoundEffect(3);
                nextMenu = sub_8037798();
                sUnknown_203B35C->state = 4;
            }

            sub_8037748();
            break;
    }
    return nextMenu;
}

static void sub_80371B8(void)
{
    unkStruct_8035D94 *item;
    const MenuItem *MenuItems;
    const WindowTemplate *puVar5;

    puVar5 = NULL;
    MenuItems = NULL;
    sub_8037400();

    if (sUnknown_203B35C->unk0 < 2 && sUnknown_203B35C->linkStatus == COMMS_GOOD) {
        if (sub_8037C10(FALSE) != 0) {
            sub_80376CC();
            sub_8035CC0(&sUnknown_203B35C->unk15C, 0);
            // Success!
            // The item exchange with your friend
            // went through successfully
            SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6C50, sUnknown_80E6C68, FALSE, 6, FALSE);
            sub_8035CF4(sUnknown_203B35C->unk1C, 0, TRUE);
        }
    }
    else {
        sub_80376CC();
        sub_8035CC0(&sUnknown_203B35C->unk15C, 0);

        switch (sUnknown_203B35C->linkStatus) {
            case 0:
                puVar5 = &sUnknown_80E66BC;
                MenuItems = sUnknown_80E66D4;
                break;
            case 3:
                puVar5 = &sUnknown_80E6D54;
                MenuItems = sUnknown_80E6D6C;
                break;
            case 2:
                puVar5 = &sUnknown_80E6DDC;
                MenuItems = sUnknown_80E6DF4;
                break;
            case 4:
                puVar5 = &sUnknown_80E67D4;
                MenuItems = sUnknown_80E67EC;
                break;
            case 1:
            case 5:
                puVar5 = &sUnknown_80E6748;
                MenuItems = sUnknown_80E6760;
                break;
            case 6:
                puVar5 = &sUnknown_80E689C;
                MenuItems = sUnknown_80E68B4;
                break;
            case 7:
                puVar5 = &sUnknown_80E6938;
                MenuItems = sUnknown_80E6950;
                break;
            case 9:
                puVar5 = &sUnknown_80E69B0;
                MenuItems = sUnknown_80E69C8;
                break;
            case 11:
                puVar5 = &sUnknown_80E6A10;
                MenuItems = sUnknown_80E6A28;
                break;
            case 13:
                puVar5 = &sUnknown_80E6A74;
                MenuItems = sUnknown_80E6A8C;
                break;
            case 14:
                puVar5 = &sUnknown_80E6B78;
                // Error, there was a problem on your friend's end
                MenuItems = sUnknown_80E6B90;
                break;
            case 15:
                puVar5 = &sUnknown_80E6BF4;
                // Error, your friend is not responding
                MenuItems = sUnknown_80E6C0C;
                break;
        }

        SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, puVar5, MenuItems, FALSE, 6, FALSE);
        sub_8035CF4(sUnknown_203B35C->unk1C, 0, TRUE);

        if (sUnknown_203B35C->linkStatus != COMMS_GOOD && sUnknown_203B35C->unk0 == 0) {
            item = sub_8035D94();
            if (item->itemIndex != ITEM_NOTHING && item->numItems != 0)
                gTeamInventoryRef->teamStorage[item->itemIndex] += item->numItems;
        }
    }
}

void sub_80373C4(void)
{
    sub_8005838(NULL, 0);
    sub_80060EC();
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    DoScheduledMemCopies();
    xxx_call_update_bg_sound_input();
    ResetSprites(FALSE);
}

UNUSED static unkStruct_203B35C *sub_80373F4(void)
{
    return sUnknown_203B35C;
}

static void sub_8037400(void)
{
    u8 mailIndex;
    void *r5;
    void *r6;
    s32 species;

    r6 = NULL;
    r5 = NULL;
    sub_8037810();
    StopBGMResetSoundEffectCounters();
    sUnknown_203B35C->linkStatus = sub_8037B28(sUnknown_203B35C->unk0);
    if (sUnknown_203B35C->linkStatus == COMMS_GOOD) {
        switch (sUnknown_203B35C->unk0) {
            case 10:
                r6 = &sUnknown_203B35C->unk39C;
                r5 = &sUnknown_203B35C->unk450;
                break;
            case 9:
                r6 = &sUnknown_203B35C->unk39C;
                r5 = &sUnknown_203B35C->unk450;
                break;
            case 0:
                sUnknown_203B35C->unk1BC[0] = *sub_8035D94();
                r6 = &sUnknown_203B35C->unk1BC[0];
                r5 = &sUnknown_203B35C->unk1BC[1];
                break;
            case 1:
                r6 = &sUnknown_203B35C->unk1BC[0];
                r5 = &sUnknown_203B35C->unk1BC[1];
                break;
            case 7:
                r6 = &sUnknown_203B35C->unk1CC;
                r5 = &sUnknown_203B35C->unk1FC;
                break;
            case 6:
                mailIndex = sub_8035D74();
                sUnknown_203B35C->unk1CC = *GetMailatIndex(mailIndex);
                r6 = &sUnknown_203B35C->unk1CC;
                r5 = &sUnknown_203B35C->unk1FC;
                break;
            case 3:
                r6 = &sUnknown_203B35C->unk22C;
                r5 = &sUnknown_203B35C->unk25C;
                break;
            case 2:
                mailIndex = sub_8035D74();
                sUnknown_203B35C->unk22C = *GetMailatIndex(mailIndex);
                r6 = &sUnknown_203B35C->unk22C;
                r5 = &sUnknown_203B35C->unk25C;
                break;
            case 4:
                mailIndex = sub_8035D74();
                sUnknown_203B35C->unk28C = *GetMailatIndex(mailIndex);
                if ((u16)sub_8035D3C() != 0xFFFF) {
                    species = sub_8035D3C();
                    sUnknown_203B35C->unk2BC = gRecruitedPokemonRef->pokemon[(s16)species];
                }
                r6 = &sUnknown_203B35C->unk28C;
                r5 = &sUnknown_203B35C->unk314;
                break;
            case 5:
                r6 = &sUnknown_203B35C->unk28C;
                r5 = &sUnknown_203B35C->unk314;
                break;
        }

        sUnknown_203B35C->linkStatus = sub_8037D64(sUnknown_203B35C->unk0, r6, r5);

        if (sUnknown_203B35C->linkStatus == COMMS_GOOD) {
            switch (sUnknown_203B35C->unk0) {
                case 0:
                case 1:
                    r6 = &sUnknown_203B35C->unk1BC[0];
                    r5 = &sUnknown_203B35C->unk1BC[1];
                    break;
                case 2:
                case 3:
                    r6 = &sUnknown_203B35C->unk22C;
                    r5 = &sUnknown_203B35C->unk25C;
                    break;
                case 4:
                case 5:
                    r6 = &sUnknown_203B35C->unk28C;
                    r5 = &sUnknown_203B35C->unk314;
                    break;
                case 6:
                case 7:
                    r6 = &sUnknown_203B35C->unk1CC;
                    r5 = &sUnknown_203B35C->unk1FC;
                    break;
                case 9:
                case 10:
                    r6 = &sUnknown_203B35C->unk39C;
                    r5 = &sUnknown_203B35C->unk450;
                    break;
            }

            sUnknown_203B35C->linkStatus = sub_80381F4(sUnknown_203B35C->unk0, r6, r5);
        }
    }

    StartBGMusic();
}

static void sub_80376CC(void)
{
    SpriteSetAffine1(&sUnknown_203B35C->unkC, 0);
    SpriteSetAffine2(&sUnknown_203B35C->unkC, 0);
    SpriteSetObjMode(&sUnknown_203B35C->unkC, 0);
    SpriteSetMosaic(&sUnknown_203B35C->unkC, 0);
    SpriteSetBpp(&sUnknown_203B35C->unkC, 0);
    SpriteSetShape(&sUnknown_203B35C->unkC, 1);
    SpriteSetTileNum(&sUnknown_203B35C->unkC, 0x3F0);
    SpriteSetPriority(&sUnknown_203B35C->unkC, 0);
    SpriteSetPalNum(&sUnknown_203B35C->unkC, 15);
    SpriteSetX(&sUnknown_203B35C->unkC, 0);
    SpriteSetMatrixNum(&sUnknown_203B35C->unkC, 0);
    SpriteSetSize(&sUnknown_203B35C->unkC, 0);
    SpriteSetY(&sUnknown_203B35C->unkC, 192);
}

static void sub_8037748(void)
{
    SpriteSetX(&sUnknown_203B35C->unkC, 112);
    SpriteSetY(&sUnknown_203B35C->unkC, 104);

    if ((sUnknown_203B35C->unk14 & 8) != 0)
      AddSprite(&sUnknown_203B35C->unkC, 0x100, NULL, NULL);

    DrawDialogueBoxString_Async();
    sUnknown_203B35C->unk14++;
}

static u32 sub_8037798(void)
{
    u32 nextMenu = MENU_NO_SCREEN_CHANGE;
    switch (sUnknown_203B35C->unk0) {
        case 0:
        case 1:
            nextMenu = MENU_MAIN_SCREEN;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            nextMenu = (sUnknown_203B35C->linkStatus == COMMS_GOOD) ? 42 : MENU_MAIN_SCREEN;
            break;
        case 9:
        case 10:
            nextMenu = (sUnknown_203B35C->linkStatus == COMMS_GOOD) ? 43 : MENU_WONDER_MAIL;
            break;
    }
    return nextMenu;
}

static void sub_8037810(void)
{
    unkStruct_8035D94 blank = {0, 0};

    MemoryFill8(&sUnknown_203B35C->unk1BC[0], 0, sizeof(unkStruct_8035D94));
    MemoryFill8(&sUnknown_203B35C->unk1BC[1], 0, sizeof(unkStruct_8035D94));
    sUnknown_203B35C->unk1BC[0] = blank;
    sUnknown_203B35C->unk1BC[1] = blank;

    MemoryFill8(&sUnknown_203B35C->unk1CC, 0, sizeof(unkStruct_203B480));
    MemoryFill8(&sUnknown_203B35C->unk1FC, 0, sizeof(unkStruct_203B480));
    MemoryFill8(&sUnknown_203B35C->unk22C, 0, sizeof(unkStruct_203B480));
    MemoryFill8(&sUnknown_203B35C->unk25C, 0, sizeof(unkStruct_203B480));
    MemoryFill8(&sUnknown_203B35C->unk28C, 0, sizeof(unkStruct_203B480));
    MemoryFill8(&sUnknown_203B35C->unk314, 0, sizeof(unkStruct_203B480));
    MemoryFill8(&sUnknown_203B35C->unk2BC, 0, sizeof(Pokemon));
    MemoryFill8(&sUnknown_203B35C->unk344, 0, sizeof(Pokemon));
    MemoryFill8(sUnknown_203B35C->unk39C, 0, 0xb4); // unkStruct_803B344?
    MemoryFill8(sUnknown_203B35C->unk450, 0, 0xb4); // unkStruct_803B344?

    sUnknown_203B35C->unk2BC.speciesNum = 0;
    sUnknown_203B35C->unk344.speciesNum = 0;
}

void sub_8037900(void)
{
    sub_8035CC0(&sUnknown_203B35C->unk15C, 0);

    switch (sUnknown_203B35C->unk0) {
        case 0:
        case 1: {
            SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6554, sUnknown_80E656C, FALSE, 6, FALSE);
            break;
        }
        case 2:
        case 3: {
            SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6554, sUnknown_80E65D8, FALSE, 6, FALSE);
            break;
        }
        case 4:
        case 5: {
            SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6554, sUnknown_80E661C, FALSE, 6, FALSE);
            break;
        }
        case 6:
        case 7: {
            SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6554, sUnknown_80E665C, FALSE, 6, FALSE);
            break;
        }
        case 8: {
            break;
        }
        case 9:
        case 10: {
            SetMenuItems(sUnknown_203B35C->unk1C, &sUnknown_203B35C->unk15C, 0, &sUnknown_80E6554, sUnknown_80E667C, FALSE, 6, FALSE);
            break;
        }
    }

    sub_8035CF4(sUnknown_203B35C->unk1C, 0, TRUE);
    sub_80373C4();
    sub_80130A8(sUnknown_203B35C->unk1C);
}

UNUSED static void nullsub_202(void)
{
}
