#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_80118A4.h"
#include "constants/emotions.h"
#include "constants/input.h"
#include "constants/type.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "personality_test2.h"
#include "pokemon.h"
#include "text1.h"
#include "text2.h"
#include "string_format.h"

EWRAM_DATA_2 struct PersonalityStruct_203B404 *gUnknown_203B404 = {0};

#include "data/personality_test2.h"

static s32 GetValidPartners(void);
static void nullsub_135(void);
static void PersonalityTest_DisplayPartnerSprite(void);
static void RedrawPartnerSelectionMenu(void);

static void sub_803CEAC(void);
static void sub_803CECC(void);

void CreatePartnerSelectionMenu(s16 starterID)
{
    s32 starterID_s32;
    starterID_s32 = starterID; // force an asr shift.. does lsr without it

    sub_803CEAC();
    gUnknown_203B404->StarterID = starterID_s32;
    gUnknown_203B404->s18.s0.unk34 = 0;
    gUnknown_203B404->s18.s0.unk38 = gUnknown_203B404->s18.s0.unk3C;

    gUnknown_203B404->s18.s0.unk3C[0] = gUnknown_80F4290;
    gUnknown_203B404->s18.s0.unk3C[1] = gUnknown_80F42A8;
    gUnknown_203B404->s18.s0.unk3C[2] = gUnknown_80F4278;
    gUnknown_203B404->s18.s0.unk3C[3] = gUnknown_80F4278;

    gUnknown_203B404->s18.s0.unk38->unk14 = &gUnknown_203B404->s18.unk9C;

    gUnknown_203B404->s18.unk9C.f0 = 1;
    gUnknown_203B404->s18.unk9C.f1 = 0;
    gUnknown_203B404->s18.unk9C.f2 = 6;
    gUnknown_203B404->s18.unk9C.f3 = 0;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_203B404->s18.s0.unk3C, TRUE, TRUE);
    sub_8013818(&gUnknown_203B404->s18.s0.input, GetValidPartners(), 10, gUnknown_203B404->s18.s0.unk34);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();
}

u16 HandlePartnerSelectionInput(void)
{
    s32 partnerID;

    partnerID = gUnknown_203B404->s18.s0.input.menuIndex;
    gUnknown_203B404->unk16 = 0;

    if (GetKeyPress(&gUnknown_203B404->s18.s0.input) == INPUT_A_BUTTON) {
        PlayMenuSoundEffect(0);
        return gUnknown_203B404->PartnerArray[gUnknown_203B404->s18.s0.input.menuIndex];
    }

    if (sub_80138B8(&gUnknown_203B404->s18.s0.input, TRUE))
        RedrawPartnerSelectionMenu();

    if (partnerID != gUnknown_203B404->s18.s0.input.menuIndex)
        PersonalityTest_DisplayPartnerSprite();

    if (gUnknown_203B404->unk16 != 0) {
        return -2;
    }
    return -1;
}

UNUSED static void sub_803CE34(bool8 cursorSprite)
{
    gUnknown_203B404->s18.s0.input.unk22 = GetValidPartners();
    sub_8013984(&gUnknown_203B404->s18.s0.input);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B404->s18.s0.input);
}

void sub_803CE6C(void)
{
    gUnknown_203B404->s18.s0.unk3C[gUnknown_203B404->s18.s0.unk34] = gUnknown_80F4278;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_203B404->s18.s0.unk3C, TRUE, TRUE);
    sub_803CECC();
}

static void sub_803CEAC(void)
{
    gUnknown_203B404 = MemoryAlloc(sizeof(struct PersonalityStruct_203B404), 8);
    nullsub_135();
}

static void nullsub_135(void)
{
}

static void sub_803CECC(void)
{
    if (gUnknown_203B404 != NULL) {
        nullsub_135();
        MemoryFree(gUnknown_203B404);
        gUnknown_203B404 = NULL;
    }
}

#ifdef NONMATCHING // sub_80095E4 memes
// Unfortunately `SUB_80095E4_CALL` doesn't work in this case, because of a `mov r4, #0` instruction put 2 instructions too late...
static void RedrawPartnerSelectionMenu(void)
{
    u32 yCoord;
    const u8 *monName;
    s32 monCounter;

    SUB_80095E4_CALL(gUnknown_203B404->s18.s0);

    CallPrepareTextbox_8008C54(gUnknown_203B404->s18.s0.unk34);
    sub_80073B8(gUnknown_203B404->s18.s0.unk34);
    PrintStringOnWindow(12, 0, gPartnerSelectionHeaderText, gUnknown_203B404->s18.s0.unk34, 0);

    monCounter = 0;
    while (monCounter < gUnknown_203B404->s18.s0.input.unk1A) {
        yCoord = sub_8013800(&gUnknown_203B404->s18.s0.input, monCounter);
        monName = GetMonSpecies(gUnknown_203B404->PartnerArray[monCounter]);
        PrintStringOnWindow(8, yCoord, monName, gUnknown_203B404->s18.s0.unk34, 0);
        monCounter++;
    }
    sub_80073E0(gUnknown_203B404->s18.s0.unk34);
    gUnknown_203B404->unk16 = 1;
}
#else
NAKED
static void RedrawPartnerSelectionMenu(void)
{
    asm_unified("\tpush {r4-r6,lr}\n"
    "\tsub sp, 0x4\n"
    "\tldr r6, _0803CF60\n"
    "\tldr r0, [r6]\n"
    "\tmovs r1, 0x32\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmovs r1, 0xC\n"
    "\tbl sub_80095E4\n"
    "\tadds r0, 0x2\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [r6]\n"
    "\tldr r3, [r2, 0x4C]\n"
    "\tlsls r1, r3, 1\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r1, r2, r1\n"
    "\tadds r1, 0x62\n"
    "\tmovs r4, 0\n"
    "\tasrs r3, r0, 16\n"
    "\tlsrs r0, 16\n"
    "\tstrh r0, [r1]\n"
    "\tldr r1, [r2, 0x4C]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, r1\n"
    "\tlsls r0, 3\n"
    "\tadds r2, r0\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x64\n"
    "\tstrh r3, [r2]\n"
    "\tbl ResetUnusedInputStruct\n"
    "\tldr r0, [r6]\n"
    "\tadds r0, 0x54\n"
    "\tmovs r1, 0x1\n"
    "\tmovs r2, 0x1\n"
    "\tbl xxx_call_save_unk_text_struct_800641C\n"
    "\tldr r0, [r6]\n"
    "\tldr r0, [r0, 0x4C]\n"
    "\tbl CallPrepareTextbox_8008C54\n"
    "\tldr r0, [r6]\n"
    "\tldr r0, [r0, 0x4C]\n"
    "\tbl sub_80073B8\n"
    "\tldr r2, _0803CF64\n"
    "\tldr r0, [r6]\n"
    "\tldr r3, [r0, 0x4C]\n"
    "\tstr r4, [sp]\n"
    "\tmovs r0, 0xC\n"
    "\tmovs r1, 0\n"
    "\tbl PrintStringOnWindow\n"
    "\tmovs r5, 0\n"
    "\tb _0803CF98\n"
    "\t.align 2, 0\n"
"_0803CF60: .4byte gUnknown_203B404\n"
"_0803CF64: .4byte gPartnerSelectionHeaderText\n"
"_0803CF68:\n"
    "\tldr r0, [r6]\n"
    "\tadds r0, 0x18\n"
    "\tadds r1, r5, 0\n"
    "\tbl sub_8013800\n"
    "\tadds r4, r0, 0\n"
    "\tldr r0, [r6]\n"
    "\tlsls r1, r5, 1\n"
    "\tadds r0, 0x2\n"
    "\tadds r0, r1\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tbl GetMonSpecies\n"
    "\tadds r2, r0, 0\n"
    "\tldr r0, [r6]\n"
    "\tldr r3, [r0, 0x4C]\n"
    "\tmovs r0, 0\n"
    "\tstr r0, [sp]\n"
    "\tmovs r0, 0x8\n"
    "\tadds r1, r4, 0\n"
    "\tbl PrintStringOnWindow\n"
    "\tadds r5, 0x1\n"
"_0803CF98:\n"
    "\tldr r0, [r6]\n"
    "\tmovs r1, 0x32\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r5, r0\n"
    "\tblt _0803CF68\n"
    "\tldr r4, _0803CFBC\n"
    "\tldr r0, [r4]\n"
    "\tldr r0, [r0, 0x4C]\n"
    "\tbl sub_80073E0\n"
    "\tldr r1, [r4]\n"
    "\tmovs r0, 0x1\n"
    "\tstrb r0, [r1, 0x16]\n"
    "\tadd sp, 0x4\n"
    "\tpop {r4-r6}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_0803CFBC: .4byte gUnknown_203B404");
}
#endif

static void PersonalityTest_DisplayPartnerSprite(void)
{
    s32 partnerID;
    struct OpenedFile *faceFile;
    s32 paletteIndex;
    const u8 *gfx;
    s32 emotionId;

    partnerID = gUnknown_203B404->PartnerArray[gUnknown_203B404->s18.s0.input.menuIndex];
    CallPrepareTextbox_8008C54(1);
    sub_80073B8(1);
    faceFile = GetDialogueSpriteDataPtr(partnerID);
    gfx = ((struct PortraitGfx *)(faceFile->data))->sprites[EMOTION_NORMAL].gfx;
    emotionId = EMOTION_NORMAL;
    for (paletteIndex = 0; paletteIndex < 0x10; paletteIndex++) {
        SetBGPaletteBufferColorArray(paletteIndex + 0xE0, &((struct PortraitGfx *)(faceFile->data))->sprites[emotionId].pal[paletteIndex]);
    }

    DisplayMonPortraitSpriteFlipped(1, gfx, 14);
    CloseFile(faceFile);
    sub_80073E0(1);
    gUnknown_203B404->unk16 = 1;
}

static s32 GetValidPartners(void)
{
    u8 PlayerType[2];
    u8 currentPartnerTypes[2];
    s32 i;
    s32 ValidPartnerCounter;
    s32 CurrentPartnerID;

    ValidPartnerCounter = 0;
    PlayerType[0] = GetPokemonType(gUnknown_203B404->StarterID, 0);
    PlayerType[1] = GetPokemonType(gUnknown_203B404->StarterID, 1);

    for (i = 0; i < NUM_PARTNERS; i++) {
        CurrentPartnerID = gPartners[i];
        currentPartnerTypes[0] = GetPokemonType(CurrentPartnerID, 0);
        currentPartnerTypes[1] = GetPokemonType(CurrentPartnerID, 1);

        if ((currentPartnerTypes[0] == TYPE_NONE || (currentPartnerTypes[0] != PlayerType[0] && currentPartnerTypes[0] != PlayerType[1]))
        && ((currentPartnerTypes[1] == TYPE_NONE || (currentPartnerTypes[1] != PlayerType[0] && currentPartnerTypes[1] != PlayerType[1])))) {
            gUnknown_203B404->PartnerArray[ValidPartnerCounter] = CurrentPartnerID;
            ValidPartnerCounter++;
        }
    }

    return ValidPartnerCounter;
}
