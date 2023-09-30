#include "global.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "code_803B050.h"
#include "code_8096AF8.h"
#include "constants/input.h"
#include "input.h"
#include "pokemon_mail.h"
#include "pokemon_news1.h"
#include "pokemon_news2.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B2CC *sUnknown_203B2CC = {0};
static EWRAM_DATA_2 u16 sUnknown_203B2D0 = {0};
static EWRAM_DATA_2 u16 sUnknown_203B2D2 = {0};

#include "data/pokemon_news1.h"

static void CreatePKMNNewsMenu(void);
static s32 GetNumPKMNNews(void);

static void sub_802B880(void);

bool8 sub_802B640(u32 a0, UnkTextStruct2_sub *a1, u32 a2)
{
    if (HasNoPKMNNews())
        return FALSE;

    if (sUnknown_203B2CC == NULL)
        sUnknown_203B2CC = MemoryAlloc(sizeof(struct unkStruct_203B2CC), 8);

    sUnknown_203B2CC->unk6C = a0;
    sUnknown_203B2CC->unk70 = &sUnknown_203B2CC->unk74[a0];

    sub_8006518(sUnknown_203B2CC->unk74);

    sUnknown_203B2CC->unk74[sUnknown_203B2CC->unk6C] = sUnknown_80DFBEC;

    if (a1 != NULL)
        sUnknown_203B2CC->unk74[sUnknown_203B2CC->unk6C].unk8 = *a1;

    sub_8012D08(sUnknown_203B2CC->unk70, a2);
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2CC->unk74, TRUE, TRUE);

    sub_8013818(&sUnknown_203B2CC->input, GetNumPKMNNews(), a2, a0);

    sUnknown_203B2CC->input.menuIndex = sUnknown_203B2D0;
    sUnknown_203B2CC->input.unk1E = sUnknown_203B2D2;

    sub_8013984(&sUnknown_203B2CC->input);
    sub_802B880();
    CreatePKMNNewsMenu();

    return TRUE;
}

u32 sub_802B720(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2CC->input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2CC->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
    }

    if (sub_80138B8(&sUnknown_203B2CC->input, 1)) {
        sub_802B880();
        CreatePKMNNewsMenu();
        return 1;
    }
    return 0;
}

u8 GetPokemonNewsIndex(void)
{
    return sUnknown_203B2CC->receivedNewsletters[(sUnknown_203B2CC->input.unk1E * sUnknown_203B2CC->input.unk1C) + sUnknown_203B2CC->input.menuIndex];
}

void sub_802B7D0(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B2CC->unk74, FALSE, FALSE);

    sUnknown_203B2CC->input.unk22 = GetNumPKMNNews();
    sub_8013984(&sUnknown_203B2CC->input);
    sub_802B880();
    CreatePKMNNewsMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2CC->input);
}

void sub_802B81C(void)
{
    if (sUnknown_203B2CC != NULL) {
        sUnknown_203B2D0 = sUnknown_203B2CC->input.menuIndex;

        sUnknown_203B2D2 = sUnknown_203B2CC->input.unk1E;

        sUnknown_203B2CC->unk74[sUnknown_203B2CC->unk6C] = sUnknown_80DFBD0;

        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B2CC->unk74, TRUE, TRUE);

        MemoryFree(sUnknown_203B2CC);
        sUnknown_203B2CC = NULL;
    }
}

NAKED // sub_80095E4 memes
static void sub_802B880(void)
{
    asm_unified(
    "\tpush {r4,lr}\n"
    "\tldr r4, _0802B8D0\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x52\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0xC\n"
    "\tbl sub_80095E4\n"
    "\tadds r0, 0x2\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [r4]\n"
    "\tldr r3, [r2, 0x6C]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r2, r1\n"
    "\tadds r1, 0x82\n"
    "\tasrs r3, r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, [r2, 0x6C]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 3\n"
    "\tadds r2, r0\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x84\n"
    "\tstrh r3, [r2]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r4]\n"
    "\tadds r0, 0x74\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl sub_800641C\n"
    "\tpop {r4}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"\t_0802B8D0: .4byte sUnknown_203B2CC");
}

static void CreatePKMNNewsMenu(void)
{
    s32 index;
    s32 y;
    s32 new_index;
    u8 mailIndex;

    sub_8008C54(sUnknown_203B2CC->unk6C);
    sub_80073B8(sUnknown_203B2CC->unk6C);
    xxx_call_draw_string(10, 0, sNewsList, sUnknown_203B2CC->unk6C, 0);

    sub_8012BC4((sUnknown_80DFBE8[2] * 8) + 4, 0, sUnknown_203B2CC->input.unk1E + 1, 2, 7, sUnknown_203B2CC->unk6C);

    for (index = 0; index < sUnknown_203B2CC->input.unk1A; index++) {
        y = sub_8013800(&sUnknown_203B2CC->input, index);
        new_index = (sUnknown_203B2CC->input.unk1E * sUnknown_203B2CC->input.unk1C) + index;
        mailIndex = sUnknown_203B2CC->receivedNewsletters[new_index];
        sub_803B6B0(10, y, 6, sUnknown_203B2CC->unk6C);
        sub_802BC7C();
        xxx_format_and_draw(21, y, GetPokemonMailHeadline(mailIndex), sUnknown_203B2CC->unk6C, 0);
    }

    sub_80073E0(sUnknown_203B2CC->unk6C);
}

static s32 GetNumPKMNNews(void)
{
    s32 i;
    s32 newsCount;

    newsCount = 0;

    for (i = 0; i < NUM_POKEMON_NEWS; i++) {
        if (CheckPKMNNewsSlot(i)) {
            sUnknown_203B2CC->receivedNewsletters[newsCount] = i;
            newsCount++;
        }
    }

    return newsCount;
}

bool8 HasNoPKMNNews(void)
{
    s32 i;

    for (i = 0; i < NUM_POKEMON_NEWS; i++) {
        if (CheckPKMNNewsSlot(i))
            return FALSE;
    }

    return TRUE;
}