#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "constants/mailbox.h"
#include "structs/str_802C39C.h"
#include "code_800D090.h"
#include "music_util.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "pokemon_news3.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

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

    sUnknown_203B2D8->unk4.m.menuWinId = a0;
    sUnknown_203B2D8->unk4.m.menuWindow = &sUnknown_203B2D8->unk4.m.windows.id[a0];
    RestoreSavedWindows(&sUnknown_203B2D8->unk4.m.windows);
    sUnknown_203B2D8->unk4.m.windows.id[sUnknown_203B2D8->unk4.m.menuWinId] = sUnknown_80DFC74;
    sUnknown_203B2D8->unk4.m.menuWindow->header = &sUnknown_203B2D8->unk4.header;

    if (a1 != NULL)
        sUnknown_203B2D8->unk4.m.windows.id[sUnknown_203B2D8->unk4.m.menuWinId].pos = *a1;

    sub_8012D34(sUnknown_203B2D8->unk4.m.menuWindow, a2);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2D8->unk4.m.windows, TRUE, TRUE);
    CreateMenuOnWindowTwoLinesEntry(&sUnknown_203B2D8->unk4.m.input, CountEmptyMailSlots(), a2, a0);
    sUnknown_203B2D8->unk4.m.input.menuIndex = sUnknown_203B2DC;
    MenuUpdatePagesData(&sUnknown_203B2D8->unk4.m.input);
    sub_802BF30();
    CreateMailMenu();
    return TRUE;
}

u32 sub_802BDEC(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2D8->unk4.m.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2D8->unk4.m.input)) {
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
            if (MenuCursorUpdate(&sUnknown_203B2D8->unk4.m.input, 1)) {
                sub_802BF30();
                CreateMailMenu();
                return 1;
            }
            return 0;
    }
}

u8 sub_802BE74(void)
{
    return sUnknown_203B2D8->unk0[GET_CURRENT_MENU_ENTRY(sUnknown_203B2D8->unk4.m.input)];
}

void sub_802BE94(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2D8->unk4.m.windows, FALSE, FALSE);

    sUnknown_203B2D8->unk4.m.input.totalEntriesCount = CountEmptyMailSlots();
    MenuUpdatePagesData(&sUnknown_203B2D8->unk4.m.input);
    sub_802BF30();
    CreateMailMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2D8->unk4.m.input);
}

void sub_802BEDC(void)
{
    if (sUnknown_203B2D8 != NULL) {
        sUnknown_203B2DC = sUnknown_203B2D8->unk4.m.input.menuIndex;
        sUnknown_203B2D8->unk4.m.windows.id[sUnknown_203B2D8->unk4.m.menuWinId] = sUnknown_80DFC5C;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B2D8->unk4.m.windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B2D8);
        sUnknown_203B2D8 = NULL;
    }
}

static void sub_802BF30(void)
{
    sUnknown_203B2D8->unk4.header.count = 1;
    sUnknown_203B2D8->unk4.header.currId = 0;
    sUnknown_203B2D8->unk4.header.width = 12;
    sUnknown_203B2D8->unk4.header.f3 = 0;
    UPDATE_TWO_LINES_MENU_WINDOW_HEIGHT(sUnknown_203B2D8->unk4.m);
}

void CreateMailMenu(void)
{
    WonderMail *mail;
    s32 y;
    s32 i;
    unkStruct_802C39C local;
    u8 buffer[128];

    CallPrepareTextbox_8008C54(sUnknown_203B2D8->unk4.m.menuWinId);
    sub_80073B8(sUnknown_203B2D8->unk4.m.menuWinId);
    PrintStringOnWindow((sUnknown_203B2D8->unk4.m.input.currPage * 8) + 10, 0, sMailbox, sUnknown_203B2D8->unk4.m.menuWinId, 0);

    for (i = 0; i < sUnknown_203B2D8->unk4.m.input.currPageEntries; i++) {
        mail = GetMailboxSlotInfo(sUnknown_203B2D8->unk0[(sUnknown_203B2D8->unk4.m.input.currPage * sUnknown_203B2D8->unk4.m.input.entriesPerPage) + i]);
        local.unk0[0] = sUnknown_203B2D8->unk4.m.menuWinId;
        local.y = GetMenuEntryYCoord(&sUnknown_203B2D8->unk4.m.input, i);

        if (mail->mailType == MAIL_TYPE_UNK1) {
            y = GetMenuEntryYCoord(&sUnknown_203B2D8->unk4.m.input, i);
            sub_803B6B0(10, y, 6, sUnknown_203B2D8->unk4.m.menuWinId);
            PrintPokeNameToBuffer(gFormatBuffer_Monsters[0], GetLeaderMon1());
            sprintfStatic(buffer, GetPokemonMailHeadline(mail->dungeonSeed.location.floor), gFormatBuffer_Monsters[0]);
            PrintStringOnWindow(21, y, buffer, sUnknown_203B2D8->unk4.m.menuWinId, 0);
        }
        else {
            sub_803B35C(mail, &local);
            if (IsMailinJobSlot(mail))
                local.unk43 = 2;

            CreateRescueTitle(&local);
        }
    }

    sub_80073E0(sUnknown_203B2D8->unk4.m.menuWinId);
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
