#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "constants/communication_error_codes.h"
#include "constants/main_menu.h"
#include "structs/str_dungeon.h"
#include "input.h"
#include "items.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus1.h"
#include "other_menus2.h"
#include "sprite.h"
#include "text1.h"

// TODO: MAKE STATIC WHEN other_menus1.s IS DED
EWRAM_DATA_2 unkStruct_203B35C *sUnknown_203B35C = {0};

#include "data/other_menus1.h"

// other_menus1.s
extern void sub_8037810(void);
extern void sub_8037900(void);
// text.s
extern void xxx_call_update_bg_vram();
// other_menus2.s
extern s32 sub_8037B28(u32);

static void sub_80371B8(void);
static void sub_8037400(void);
static void sub_80376CC(void);
static void sub_8037748(void);
static u32 sub_8037798(void);

void sub_8036FDC(s32 param_1)
{
    s32 index1;
    s32 index2;

    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    ResetSprites(FALSE);

    if (sUnknown_203B35C == NULL) {
        sUnknown_203B35C = MemoryAlloc(sizeof(unkStruct_203B35C), 8);
        MemoryFill8((u8 *)sUnknown_203B35C, 0, sizeof(unkStruct_203B35C));
    }

    sUnknown_203B35C->unk0 = param_1;
    sUnknown_203B35C->linkStatus = COMMS_GOOD;
    sUnknown_203B35C->state = 0;

    for (index1 = 0; index1 < 2; index1++) {
        sUnknown_203B35C->unk1BC[index1].numItems = 0;
        sUnknown_203B35C->unk1BC[index1].itemIndex.itemIndex_u8 = ITEM_NOTHING;
    }

    for (index2 = 0; index2 < 4; index2++)
        sUnknown_203B35C->unk15C[index2] = sUnknown_80E653C;

    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B35C->unk15C, TRUE, TRUE);
    SetMenuItems(sUnknown_203B35C->unk1C, sUnknown_203B35C->unk15C, 0, &sUnknown_80E6CD0, sUnknown_80E6CE8, FALSE, 6, FALSE);
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
            if (sUnknown_203B35C->unk0 < 2 && sUnknown_203B35C->linkStatus == COMMS_GOOD && !sub_8037C10(FALSE))
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
    const UnkTextStruct2 *puVar5;

    puVar5 = NULL;
    MenuItems = NULL;
    sub_8037400();

    if (sUnknown_203B35C->unk0 < 2 && sUnknown_203B35C->linkStatus == COMMS_GOOD) {
        if (sub_8037C10(FALSE)) {
            sub_80376CC();
            sub_8035CC0(sUnknown_203B35C->unk15C, 0);
            // Success!
            // The item exchange with your friend
            // went through successfully
            SetMenuItems(sUnknown_203B35C->unk1C, sUnknown_203B35C->unk15C, 0, &sUnknown_80E6C50, sUnknown_80E6C68, FALSE, 6, FALSE);
            sub_8035CF4(sUnknown_203B35C->unk1C, 0, TRUE);
        }
    }
    else {
        sub_80376CC();
        sub_8035CC0(sUnknown_203B35C->unk15C, 0);

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

        SetMenuItems(sUnknown_203B35C->unk1C, sUnknown_203B35C->unk15C, 0, puVar5, MenuItems, FALSE, 6, FALSE);
        sub_8035CF4(sUnknown_203B35C->unk1C, 0, TRUE);

        if (sUnknown_203B35C->linkStatus != COMMS_GOOD && sUnknown_203B35C->unk0 == 0) {
            item = sub_8035D94();
            if (item->itemIndex.itemIndex_u8 != ITEM_NOTHING && item->numItems != 0)
                gTeamInventoryRef->teamStorage[item->itemIndex.itemIndex_u8] += item->numItems;
        }
    }
}

void sub_80373C4(void)
{
    sub_8005838(NULL, 0);
    sub_80060EC();
    sub_800CB20();
    LoadBufferedInputs();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
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
    unkStruct_8035D94 *puVar5;
    unkStruct_8035D94 *puVar6;

    r6 = NULL;
    r5 = NULL;
    sub_8037810();
    sub_8011830();
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
                {
    #ifndef NONMATCHING
                    register u32 temp1 asm("r1");
    #else
                    u32 temp1;
    #endif
                    puVar5 = sub_8035D94();
                    puVar6 = &sUnknown_203B35C->unk1BC[0];
                    temp1 = puVar5->numItems;
                    puVar6->itemIndex.itemIndex_u32 = puVar5->itemIndex.itemIndex_u32;
                    puVar6->numItems = temp1;
                }
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

    xxx_call_start_bg_music();
}

static void sub_80376CC(void)
{
#ifdef NONMATCHING // SpriteOAM memes. TODO: Match like sub_8039174 with multiple vars and while(0)
    u32 r0;
    u32 r2;
#else
    register u32 r0 asm("r0");
    register u32 r2 asm("r2");
#endif
    u32 r1;
    u32 r4;

    r1 = sUnknown_203B35C->unkC.attrib1;
    r0 = (u16)~SPRITEOAM_MASK_AFFINEMODE1;
    r0 &= r1;

    r0 &= (u16)~SPRITEOAM_MASK_AFFINEMODE2;

    r0 &= (u16)~SPRITEOAM_MASK_OBJMODE;

    r0 &= (u16)~SPRITEOAM_MASK_MOSAIC;

    r0 &= (u16)~SPRITEOAM_MASK_BPP;

    r2 = 1 << SPRITEOAM_SHIFT_SHAPE;
    r0 &= (u16)~SPRITEOAM_MASK_SHAPE;
    r0 |= r2;

    sUnknown_203B35C->unkC.attrib1 = r0;

    r2 = 0x3F0 << SPRITEOAM_SHIFT_TILENUM;
    r1 = sUnknown_203B35C->unkC.attrib3;
    r0 = (u16)~SPRITEOAM_MASK_TILENUM;
    r0 &= r1;
    r0 |= r2;

    r0 &= (u16)~SPRITEOAM_MASK_PRIORITY;

    r2 = (u16)~SPRITEOAM_MASK_UNK6_4;

    r4 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
    r0 &= (u16)~SPRITEOAM_MASK_PALETTENUM;
    r0 |= r4;

    sUnknown_203B35C->unkC.attrib3 = r0;

    r0 = 0; // Set x/matrixNum/size to 0
    sUnknown_203B35C->unkC.attrib2 = r0;

    r1 = 192 << SPRITEOAM_SHIFT_UNK6_4;
    r0 = sUnknown_203B35C->unkC.unk6;
    r2 &= r0;
    r2 |= r1;
    sUnknown_203B35C->unkC.unk6 = r2;
}

static void sub_8037748(void)
{
    u16 temp2;

    sUnknown_203B35C->unkC.attrib2 &= ~SPRITEOAM_MASK_X; // Clear x
    sUnknown_203B35C->unkC.attrib2 |= 112; // Set x to 112

    temp2 = 104 << SPRITEOAM_SHIFT_UNK6_4;
    sUnknown_203B35C->unkC.unk6 &= ~SPRITEOAM_MASK_UNK6_4;
    sUnknown_203B35C->unkC.unk6 |= temp2;

    if ((sUnknown_203B35C->unk14 & 8) != 0)
      AddSprite(&sUnknown_203B35C->unkC, 0x100, NULL, NULL);

    xxx_draw_string_80144C4();
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