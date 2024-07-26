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
#include "pokemon_mid.h"
#include "pokemon_news3.h"
#include "structs/str_802C39C.h"
#include "text1.h"
#include "text2.h"

extern u8 gAvailablePokemonNames[]; // 202DF98

static EWRAM_DATA_2 struct unkStruct_203B2D8 *sUnknown_203B2D8 = {0};
static EWRAM_DATA_2 u16 sUnknown_203B2DC = {0};

#include "data/pokemon_news3.h"

static s32 CountEmptyMailSlots(void);

static void sub_802BF30(void);

bool8 sub_802BD14(s32 a0, UnkTextStruct2_sub *a1, u32 a2)
{
    if (HasNoMailinMailbox())
        return FALSE;

    if (sUnknown_203B2D8 == NULL)
        sUnknown_203B2D8 = MemoryAlloc(sizeof(struct unkStruct_203B2D8), 8);

    sUnknown_203B2D8->unk38 = a0;
    sUnknown_203B2D8->unk3C = &sUnknown_203B2D8->unk40[a0];
    sub_8006518(sUnknown_203B2D8->unk40);
    sUnknown_203B2D8->unk40[sUnknown_203B2D8->unk38] = sUnknown_80DFC74;
    sUnknown_203B2D8->unk3C->unk14 = &sUnknown_203B2D8->unkA0;

    if (a1 != NULL)
        sUnknown_203B2D8->unk40[sUnknown_203B2D8->unk38].unk8 = *a1;

    sub_8012D34(sUnknown_203B2D8->unk3C, a2);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2D8->unk40, TRUE, TRUE);
    sub_8013848(&sUnknown_203B2D8->input, CountEmptyMailSlots(), a2, a0);
    sUnknown_203B2D8->input.menuIndex = sUnknown_203B2DC;
    sub_8013984(&sUnknown_203B2D8->input);
    sub_802BF30();
    CreateMailMenu();
    return TRUE;
}

u32 sub_802BDEC(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2D8->input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2D8->input)) {
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
            if (sub_80138B8(&sUnknown_203B2D8->input, 1)) {
                sub_802BF30();
                CreateMailMenu();
                return 1;
            }
            return 0;
    }
}

u8 sub_802BE74(void)
{
    return sUnknown_203B2D8->unk0[(sUnknown_203B2D8->input.unk1E * sUnknown_203B2D8->input.unk1C) + sUnknown_203B2D8->input.menuIndex];
}

void sub_802BE94(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2D8->unk40, FALSE, FALSE);

    sUnknown_203B2D8->input.unk22 = CountEmptyMailSlots();
    sub_8013984(&sUnknown_203B2D8->input);
    sub_802BF30();
    CreateMailMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2D8->input);
}

void sub_802BEDC(void)
{
    if (sUnknown_203B2D8 != NULL) {
        sUnknown_203B2DC = sUnknown_203B2D8->input.menuIndex;
        sUnknown_203B2D8->unk40[sUnknown_203B2D8->unk38] = sUnknown_80DFC5C;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B2D8->unk40, TRUE, TRUE);
        MemoryFree(sUnknown_203B2D8);
        sUnknown_203B2D8 = NULL;
    }
}

NAKED
static void sub_802BF30(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0802BF9C\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA0\n"
    "\tmovs r2, 0\n"
    "\tmovs r1, 0x1\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA1\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA2\n"
    "\tmovs r1, 0xC\n"
    "\tstrb r1, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0xA3\n"
    "\tstrb r2, [r0]\n"
    "\tldr r0, [r4]\n"
    "\tmovs r1, 0x1E\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0x18\n"
    "\tbl sub_8009614\n"
    "\tadds r0, 0x2\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [r4]\n"
    "\tldr r3, [r2, 0x38]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r2, r1\n"
    "\tadds r1, 0x4E\n"
    "\tasrs r3, r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, [r2, 0x38]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 3\n"
    "\tadds r2, r0\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x50\n"
    "\tstrh r3, [r2]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x40\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tpop {r4}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_0802BF9C: .4byte sUnknown_203B2D8"
    );
}

void CreateMailMenu(void)
{
    WonderMail *mail;
    s32 y;
    s32 i;
    unkStruct_802C39C local;
    u8 buffer[128];

    sub_8008C54(sUnknown_203B2D8->unk38);
    sub_80073B8(sUnknown_203B2D8->unk38);
    PrintStringOnWindow((sUnknown_203B2D8->input.unk1E * 8) + 10, 0, sMailbox, sUnknown_203B2D8->unk38, 0);

    for (i = 0; i < sUnknown_203B2D8->input.unk1A; i++) {
        mail = GetMailboxSlotInfo(sUnknown_203B2D8->unk0[(sUnknown_203B2D8->input.unk1E * sUnknown_203B2D8->input.unk1C) + i]);
        local.unk0[0] = sUnknown_203B2D8->unk38;
        local.y = sub_8013800(&sUnknown_203B2D8->input, i);

        if (mail->mailType == MAIL_TYPE_UNK1) {
            y = sub_8013800(&sUnknown_203B2D8->input, i);
            sub_803B6B0(10, y, 6, sUnknown_203B2D8->unk38);
            PrintPokeNameToBuffer(gAvailablePokemonNames, GetPlayerPokemonStruct());
            sprintfStatic(buffer, GetPokemonMailHeadline(mail->unk4.dungeon.floor), gAvailablePokemonNames);
            PrintStringOnWindow(21, y, buffer, sUnknown_203B2D8->unk38, 0);
        }
        else {
            sub_803B35C(mail, &local);
            if (IsMailinJobSlot(mail))
                local.unk43 = 2;

            CreateRescueTitle(&local);
        }
    }

    sub_80073E0(sUnknown_203B2D8->unk38);
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
