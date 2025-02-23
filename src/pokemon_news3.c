#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "constants/input.h"
#include "constants/mailbox.h"
#include "input.h"
#include "code_80958E8.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "pokemon.h"
#include "pokemon_news3.h"
#include "structs/str_802C39C.h"
#include "text.h"
#include "string_format.h"

static EWRAM_INIT struct unkStruct_203B2D8 *sUnknown_203B2D8 = {NULL};
static EWRAM_INIT u16 sUnknown_203B2DC = {0};

#include "data/pokemon_news3.h"

static s32 CountEmptyMailSlots(void);

static void sub_802BF30(void);

bool8 sub_802BD14(s32 a0, DungeonPos *a1, u32 a2)
{
    if (HasNoMailinMailbox())
        return FALSE;

    if (sUnknown_203B2D8 == NULL)
        sUnknown_203B2D8 = MemoryAlloc(sizeof(struct unkStruct_203B2D8), 8);

    sUnknown_203B2D8->unk4.s0.unk34 = a0;
    sUnknown_203B2D8->unk4.s0.unk38 = &sUnknown_203B2D8->unk4.s0.windows.id[a0];
    RestoreUnkTextStruct_8006518(&sUnknown_203B2D8->unk4.s0.windows);
    sUnknown_203B2D8->unk4.s0.windows.id[sUnknown_203B2D8->unk4.s0.unk34] = sUnknown_80DFC74;
    sUnknown_203B2D8->unk4.s0.unk38->unk14 = &sUnknown_203B2D8->unk4.unk9C;

    if (a1 != NULL)
        sUnknown_203B2D8->unk4.s0.windows.id[sUnknown_203B2D8->unk4.s0.unk34].pos = *a1;

    sub_8012D34(sUnknown_203B2D8->unk4.s0.unk38, a2);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2D8->unk4.s0.windows, TRUE, TRUE);
    sub_8013848(&sUnknown_203B2D8->unk4.s0.input, CountEmptyMailSlots(), a2, a0);
    sUnknown_203B2D8->unk4.s0.input.menuIndex = sUnknown_203B2DC;
    sub_8013984(&sUnknown_203B2D8->unk4.s0.input);
    sub_802BF30();
    CreateMailMenu();
    return TRUE;
}

u32 sub_802BDEC(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2D8->unk4.s0.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2D8->unk4.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&sUnknown_203B2D8->unk4.s0.input, 1)) {
                sub_802BF30();
                CreateMailMenu();
                return 1;
            }
            return 0;
    }
}

u8 sub_802BE74(void)
{
    return sUnknown_203B2D8->unk0[(sUnknown_203B2D8->unk4.s0.input.unk1E * sUnknown_203B2D8->unk4.s0.input.unk1C) + sUnknown_203B2D8->unk4.s0.input.menuIndex];
}

void sub_802BE94(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2D8->unk4.s0.windows, FALSE, FALSE);

    sUnknown_203B2D8->unk4.s0.input.unk22 = CountEmptyMailSlots();
    sub_8013984(&sUnknown_203B2D8->unk4.s0.input);
    sub_802BF30();
    CreateMailMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2D8->unk4.s0.input);
}

void sub_802BEDC(void)
{
    if (sUnknown_203B2D8 != NULL) {
        sUnknown_203B2DC = sUnknown_203B2D8->unk4.s0.input.menuIndex;
        sUnknown_203B2D8->unk4.s0.windows.id[sUnknown_203B2D8->unk4.s0.unk34] = sUnknown_80DFC5C;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B2D8->unk4.s0.windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B2D8);
        sUnknown_203B2D8 = NULL;
    }
}

static void sub_802BF30(void)
{
    sUnknown_203B2D8->unk4.unk9C.f0 = 1;
    sUnknown_203B2D8->unk4.unk9C.f1 = 0;
    sUnknown_203B2D8->unk4.unk9C.f2 = 12;
    sUnknown_203B2D8->unk4.unk9C.f3 = 0;
    SUB_8009614_CALL(sUnknown_203B2D8->unk4.s0);
}

void CreateMailMenu(void)
{
    WonderMail *mail;
    s32 y;
    s32 i;
    unkStruct_802C39C local;
    u8 buffer[128];

    CallPrepareTextbox_8008C54(sUnknown_203B2D8->unk4.s0.unk34);
    sub_80073B8(sUnknown_203B2D8->unk4.s0.unk34);
    PrintStringOnWindow((sUnknown_203B2D8->unk4.s0.input.unk1E * 8) + 10, 0, sMailbox, sUnknown_203B2D8->unk4.s0.unk34, 0);

    for (i = 0; i < sUnknown_203B2D8->unk4.s0.input.unk1A; i++) {
        mail = GetMailboxSlotInfo(sUnknown_203B2D8->unk0[(sUnknown_203B2D8->unk4.s0.input.unk1E * sUnknown_203B2D8->unk4.s0.input.unk1C) + i]);
        local.unk0[0] = sUnknown_203B2D8->unk4.s0.unk34;
        local.y = sub_8013800(&sUnknown_203B2D8->unk4.s0.input, i);

        if (mail->mailType == MAIL_TYPE_UNK1) {
            y = sub_8013800(&sUnknown_203B2D8->unk4.s0.input, i);
            sub_803B6B0(10, y, 6, sUnknown_203B2D8->unk4.s0.unk34);
            PrintPokeNameToBuffer(gFormatBuffer_Monsters[0], GetPlayerPokemonStruct());
            sprintfStatic(buffer, GetPokemonMailHeadline(mail->unk4.dungeon.floor), gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(21, y, buffer, sUnknown_203B2D8->unk4.s0.unk34, 0);
        }
        else {
            sub_803B35C(mail, &local);
            if (IsMailinJobSlot(mail))
                local.unk43 = 2;

            CreateRescueTitle(&local);
        }
    }

    sub_80073E0(sUnknown_203B2D8->unk4.s0.unk34);
}

static s32 CountEmptyMailSlots(void)
{
    s32 mailSlots;
    s32 i;

    mailSlots = 0;

    for (i = 0; i < NUM_MAILBOX_SLOTS; i++) {
        if (!IsMailSlotEmpty(i)) {
            sUnknown_203B2D8->unk0[mailSlots] = i;
            mailSlots++;
        }
    }

    return mailSlots;
}

bool8 HasNoMailinMailbox(void)
{
    s32 i;

    for (i = 0; i < NUM_MAILBOX_SLOTS; i++) {
        if (!IsMailSlotEmpty(i))
            return FALSE;
    }

    return TRUE;
}
