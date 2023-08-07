#include "constants/input.h"
#include "global.h"
#include "file_system.h"
#include "input.h"
#include "pokemon.h"
#include "pokemon_mail.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "menu.h"
#include "save.h"
#include "menu_input.h"

struct unkStruct_203B2CC
{
    // size: 0xD4;
    u8 receivedNewsletters[NUM_POKEMON_NEWS];
    struct MenuInputStruct input;
    u32 unk6C;
    struct UnkTextStruct2 *unk70;
    struct UnkTextStruct2 unk74[4];
};
extern struct unkStruct_203B2CC *gUnknown_203B2CC;

struct unkStruct_203B2D4
{
    // size: 0x94
    /* 0x0 */ s32 state;
    /* 0x4 */ u8 currMailIndex;
    s32 unk8;
    s32 unkC;
    const u8 *unk10[4];
    u32 unk20;
    u32 unk24;
    struct UnkTextStruct2 unk28[4];
    struct MenuInputStructSub unk88;
};
extern struct unkStruct_203B2D4 *gUnknown_203B2D4;

struct unkStruct_203B2D8
{
    // size: 0xA4
    u8 unk0[4];
    struct MenuInputStruct input;
    u32 unk38;
    struct UnkTextStruct2 *unk3C;
    struct UnkTextStruct2 unk40[4];
    u8 unkA0[4];
};
extern struct unkStruct_203B2D8 *gUnknown_203B2D8;
extern struct GameOptions *gGameOptionsRef;

const struct UnkTextStruct2 gUnknown_80DFBD0 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const u8 gUnknown_80DFBE8[] = { 0x01, 0x00, 0x0C, 0x00 };

const struct UnkTextStruct2 gUnknown_80DFBEC =
{
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x18, 0x0E,
    0x0E, 0x00,
    gUnknown_80DFBE8
};

ALIGNED(4) const u8 gUnknown_80DFC04[] = "News List";
ALIGNED(4) static const char wonder_mail_2_fill1[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80DFC18 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const u8 gUnkData_80DFC30[] = { 0x01, 0x00, 0x16, 0x00 };

const struct UnkTextStruct2 gUnknown_80DFC34 =
{
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x1A, 0x10,
    0x10, 0x00,
    gUnkData_80DFC30
};

ALIGNED(4) const u8 gUnknown_80DFC4C[] = "She";
ALIGNED(4) const u8 gUnknown_80DFC50[] = "He";
ALIGNED(4) static const char wonder_mail_2_fill2[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80DFC5C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DFC74 =
{
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x18, 0x0E,
    0x0E, 0x00,
    NULL
};

ALIGNED(4) const u8 gMailboxText[] = "Mailbox";
ALIGNED(4) static const char wonder_mail_2_fill3[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80DFC9C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DFCB4 =
{
    0x00, 0x00, 0x00, 0x00,
    0x06,
    0x02, 0x02,
    0x18, 0x0E,
    0x0E, 0x00,
    NULL
};

ALIGNED(4) const u8 gBulletinBoardText[] = "Bulletin Board";
ALIGNED(4) static const char wonder_mail_2_fill4[] = "pksdir0";

extern u8 HasNoPKMNNews(void);
extern u8 CheckPKMNNewsSlot(u8 r0);
extern u16 gUnknown_203B2D0;
extern u16 gUnknown_203B2D2;
extern u16 gUnknown_203B2DC;
extern s32 GetNumPKMNNews(void);
extern void sub_802B880(void);
extern void CreatePKMNNewsMenu(void);
extern void PlayMenuSoundEffect(u32);
extern void sub_802BCC4(void);
extern void sub_802BB14(u32);
extern u8 HasNoMailinMailbox(void);
extern void sub_802BF30(void);
extern void CreateMailMenu(void);
extern s32 CountEmptyMailSlots(void);
void sub_802BB28(void);
extern void sub_802BB98(void);
extern void sub_802BC08(void);
extern void sub_802BB28(void);
extern void sub_8013E54(void);
extern char gUnknown_202E5D8[0x50];
extern char gAvailablePokemonNames[0x50];
extern void sub_8008C54(u32);
extern void sub_802BC7C(void);
extern void sub_80073E0(u32);
extern void xxx_format_and_draw(u32, u32, const u8 *, u32, u32);
extern void sub_803B6B0(u32, u32, u32, u32);
extern struct PokemonStruct *sub_808D3BC(void);
extern void PrintPokeNameToBuffer(u8 *buffer, struct PokemonStruct *pokemon);

u32 sub_802B640(u32 r0, struct UnkTextStruct2_sub *r1, u32 r2)
{
    if (HasNoPKMNNews())
        return 0;

    if (gUnknown_203B2CC == NULL)
        gUnknown_203B2CC = MemoryAlloc(sizeof(struct unkStruct_203B2CC), 8);

    gUnknown_203B2CC->unk6C = r0;
    gUnknown_203B2CC->unk70 = &gUnknown_203B2CC->unk74[r0];

    sub_8006518(gUnknown_203B2CC->unk74);

    gUnknown_203B2CC->unk74[gUnknown_203B2CC->unk6C] = gUnknown_80DFBEC;

    if (r1 != NULL)
        gUnknown_203B2CC->unk74[gUnknown_203B2CC->unk6C].unk8 = *r1;

    sub_8012D08(gUnknown_203B2CC->unk70, r2);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2CC->unk74, 1, 1);

    sub_8013818(&gUnknown_203B2CC->input, GetNumPKMNNews(), r2, r0);

    gUnknown_203B2CC->input.menuIndex = gUnknown_203B2D0;
    gUnknown_203B2CC->input.unk1E = gUnknown_203B2D2;

    sub_8013984(&gUnknown_203B2CC->input);
    sub_802B880();
    CreatePKMNNewsMenu();

    return 1;
}

u32 sub_802B720(u8 r0)
{
    if (r0 == 0) {
        sub_8013660(&gUnknown_203B2CC->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2CC->input))
    {
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

    if (sub_80138B8(&gUnknown_203B2CC->input, 1) != 0)
    {
        sub_802B880();
        CreatePKMNNewsMenu();
        return 1;
    }
    else
        return 0;
}

u8 GetPokemonNewsIndex(void)
{
    return gUnknown_203B2CC->receivedNewsletters[(gUnknown_203B2CC->input.unk1E * gUnknown_203B2CC->input.unk1C) + gUnknown_203B2CC->input.menuIndex];
}

void sub_802B7D0(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2CC->unk74, 0, 0);

    gUnknown_203B2CC->input.unk22 = GetNumPKMNNews();
    sub_8013984(&gUnknown_203B2CC->input);
    sub_802B880();
    CreatePKMNNewsMenu();

    if (r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B2CC->input);
}

void sub_802B81C(void)
{
    if (gUnknown_203B2CC != NULL) {
        gUnknown_203B2D0 = gUnknown_203B2CC->input.menuIndex;

        gUnknown_203B2D2 = gUnknown_203B2CC->input.unk1E;

        gUnknown_203B2CC->unk74[gUnknown_203B2CC->unk6C] = gUnknown_80DFBD0;

        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2CC->unk74, 1, 1);

        MemoryFree(gUnknown_203B2CC);
        gUnknown_203B2CC = NULL;
    }
}

NAKED
void sub_802B880(void)
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
"\t_0802B8D0: .4byte gUnknown_203B2CC");
}

void CreatePKMNNewsMenu(void)
{
    s32 index;
    s32 y;
    s32 new_index;
    u8 mailIndex;

    sub_8008C54(gUnknown_203B2CC->unk6C);
    sub_80073B8(gUnknown_203B2CC->unk6C);
    xxx_call_draw_string(0xA, 0, gUnknown_80DFC04, gUnknown_203B2CC->unk6C, 0);
    sub_8012BC4(((gUnknown_80DFBE8[2] << 3) + 4), 0, gUnknown_203B2CC->input.unk1E + 1, 2, 7, gUnknown_203B2CC->unk6C);

    for (index = 0; index < gUnknown_203B2CC->input.unk1A; index++) {
        y = sub_8013800(&gUnknown_203B2CC->input, index);
        new_index = (gUnknown_203B2CC->input.unk1E * gUnknown_203B2CC->input.unk1C) + index;
        mailIndex = gUnknown_203B2CC->receivedNewsletters[new_index];
        sub_803B6B0(0xA, y, 6, gUnknown_203B2CC->unk6C);
        sub_802BC7C();
        xxx_format_and_draw(0x15, y, GetPokemonMailHeadline(mailIndex), gUnknown_203B2CC->unk6C, 0);
    }

    sub_80073E0(gUnknown_203B2CC->unk6C);
}

s32 GetNumPKMNNews(void)
{
    s32 index;
    s32 newsCount;

    newsCount = 0;

    for (index = 0; index < NUM_POKEMON_NEWS; index++) {
        if (CheckPKMNNewsSlot(index)) {
            gUnknown_203B2CC->receivedNewsletters[newsCount] = index;
            newsCount++;
        }
    }

    return newsCount;
}

bool8 HasNoPKMNNews(void)
{
    s32 index;

    for (index = 0; index < NUM_POKEMON_NEWS; index++) {
        if (CheckPKMNNewsSlot(index))
            return FALSE;
    }

    return TRUE;
}

u32 sub_802B9FC(u8 mailIndex)
{
    gUnknown_203B2D4 = MemoryAlloc(sizeof(struct unkStruct_203B2D4), 8);
    gUnknown_203B2D4->currMailIndex = mailIndex;
    sub_801317C(&gUnknown_203B2D4->unk88);
    gUnknown_203B2D4->unk24 = 0;
    gUnknown_203B2D4->unk28[0] = gUnknown_80DFC34;
    gUnknown_203B2D4->unk28[1] = gUnknown_80DFC18;
    gUnknown_203B2D4->unk28[2] = gUnknown_80DFC18;
    gUnknown_203B2D4->unk28[3] = gUnknown_80DFC18;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2D4->unk28, 1, 1);
    gUnknown_203B2D4->unk8 = 0;
    sub_802BCC4();
    sub_802BC7C();
    sub_802BB14(0);
    return 1;
}

u32 sub_802BA8C(void)
{
    switch (gUnknown_203B2D4->state) {
        case 0:
            sub_802BB98();
            break;
        case 1:
            sub_802BC08();
            break;
        case 3:
            return 3;
        case 2:
        default:
            return 2;

    }
    return 0;
}

void sub_802BACC(void)
{
    if (gUnknown_203B2D4 != NULL) {
        gUnknown_203B2D4->unk28[gUnknown_203B2D4->unk24] = gUnknown_80DFC18;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2D4->unk28, 1, 1);
        MemoryFree(gUnknown_203B2D4);
        gUnknown_203B2D4 = NULL;
    }
}

void sub_802BB14(u32 newState)
{
    gUnknown_203B2D4->state = newState;
    sub_802BB28();
}

void sub_802BB28(void)
{
    switch (gUnknown_203B2D4->state) {
        case 0:
        case 1:
            sub_8008C54(gUnknown_203B2D4->unk24);
            sub_80073B8(gUnknown_203B2D4->unk24);
            xxx_format_and_draw(0xA, 0, GetPokemonMailHeadline(gUnknown_203B2D4->currMailIndex), gUnknown_203B2D4->unk24, 0);
            xxx_format_and_draw(0x6, 0x14, gUnknown_203B2D4->unk10[gUnknown_203B2D4->unk8], gUnknown_203B2D4->unk24, 0);
            sub_80073E0(gUnknown_203B2D4->unk24);
            gUnknown_203B2D4->unk8++;
            break;
        case 2:
        case 3:
            break;
    }
}

void sub_802BB98(void)
{
    if (gUnknown_203B2D4->unkC != 0) {
        if (gUnknown_203B2D4->unk20 & 8)
            sub_8013E54();
        gUnknown_203B2D4->unk20++;
    }

    switch (sub_8012A64(&gUnknown_203B2D4->unk88, gUnknown_203B2D4->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);
            if (gUnknown_203B2D4->unkC != 0)
                sub_802BB14(1);
            else
                sub_802BB14(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_802BB14(2);
            break;
    }
}

void sub_802BC08(void)
{
    if (gUnknown_203B2D4->unk8 < gUnknown_203B2D4->unkC) {
        if (gUnknown_203B2D4->unk20 & 8)
            sub_8013E54();
        gUnknown_203B2D4->unk20++;
    }

    switch (sub_8012A64(&gUnknown_203B2D4->unk88, gUnknown_203B2D4->unk24)) {
        case 1:
            PlayMenuSoundEffect(0);
            if (gUnknown_203B2D4->unk8 < gUnknown_203B2D4->unkC)
                sub_802BB14(1);
            else
                sub_802BB14(3);
            break;
        case 2:
            PlayMenuSoundEffect(1);
            sub_802BB14(2);
            break;
    }
}

void sub_802BC7C(void)
{
    PrintPokeNameToBuffer(gAvailablePokemonNames, sub_808D3BC());
    if (gGameOptionsRef->playerGender == FEMALE)
        strcpy(gAvailablePokemonNames + 0x50, gUnknown_80DFC4C); // She
    else
        strcpy(gAvailablePokemonNames + 0x50, gUnknown_80DFC50); // He
}

void sub_802BCC4(void)
{
  const char *mailTextPtr;

  mailTextPtr = GetPokemonMailText(gUnknown_203B2D4->currMailIndex);
  gUnknown_203B2D4->unkC = 0;
  gUnknown_203B2D4->unk10[0] = mailTextPtr;

  // Count all the {EXTRA_MSG}'s
  while (*mailTextPtr != '\0') {
    if (*mailTextPtr == '#') {
      if ((mailTextPtr[1] == 'P') || (mailTextPtr[1] == 'p')) {
            gUnknown_203B2D4->unkC++;
            gUnknown_203B2D4->unk10[gUnknown_203B2D4->unkC] = mailTextPtr + 2;
      }
      mailTextPtr += 2;
    }
    else {
      mailTextPtr++;
    }
  }
}

u32 sub_802BD14(s32 param_1, struct UnkTextStruct2_sub *param_2, u32 param_3)
{
    if (HasNoMailinMailbox())
        return 0;

    if (gUnknown_203B2D8 == NULL)
        gUnknown_203B2D8 = MemoryAlloc(sizeof(struct unkStruct_203B2D8), 8);

    gUnknown_203B2D8->unk38 = param_1;
    gUnknown_203B2D8->unk3C = &gUnknown_203B2D8->unk40[param_1];
    sub_8006518(gUnknown_203B2D8->unk40);
    gUnknown_203B2D8->unk40[gUnknown_203B2D8->unk38] = gUnknown_80DFC74;
    gUnknown_203B2D8->unk3C->unk14 = gUnknown_203B2D8->unkA0;

    if (param_2 != NULL)
        gUnknown_203B2D8->unk40[gUnknown_203B2D8->unk38].unk8 = *param_2;
    
    sub_8012D34(gUnknown_203B2D8->unk3C,param_3);
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2D8->unk40,1,1);
    sub_8013848(&gUnknown_203B2D8->input,CountEmptyMailSlots(),param_3,param_1);
    gUnknown_203B2D8->input.menuIndex = gUnknown_203B2DC;
    sub_8013984(&gUnknown_203B2D8->input);
    sub_802BF30();
    CreateMailMenu();
    return 1;
}

u32 sub_802BDEC(u8 r0)
{
    if (r0 == 0) {
        sub_8013660(&gUnknown_203B2D8->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2D8->input)) {
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
            if (sub_80138B8(&gUnknown_203B2D8->input, 1) != 0) {
                sub_802BF30();
                CreateMailMenu();
                return 1;
            }
            else
                return 0;
    }
}

u8 sub_802BE74(void)
{
    return gUnknown_203B2D8->unk0[(gUnknown_203B2D8->input.unk1E * gUnknown_203B2D8->input.unk1C) + gUnknown_203B2D8->input.menuIndex];
}

void sub_802BE94(u8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2D8->unk40, 0, 0);

    gUnknown_203B2D8->input.unk22 = CountEmptyMailSlots();
    sub_8013984(&gUnknown_203B2D8->input);
    sub_802BF30();
    CreateMailMenu();

    if (r0 != 0)
        AddMenuCursorSprite(&gUnknown_203B2D8->input);
}

void sub_802BEDC(void)
{
    if (gUnknown_203B2D8 != NULL) {
        gUnknown_203B2DC = gUnknown_203B2D8->input.menuIndex;
        gUnknown_203B2D8->unk40[gUnknown_203B2D8->unk38] = gUnknown_80DFC5C;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2D8->unk40, 1, 1);
        MemoryFree(gUnknown_203B2D8);
        gUnknown_203B2D8 = NULL;
    }
}

NAKED
void sub_802BF30(void)
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
"_0802BF9C: .4byte gUnknown_203B2D8"
    );
}

