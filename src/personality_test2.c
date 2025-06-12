#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "constants/emotions.h"
#include "constants/input.h"
#include "constants/type.h"
#include "music_util.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "personality_test2.h"
#include "pokemon.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"

EWRAM_INIT struct PersonalityStruct_203B404 *gUnknown_203B404 = {NULL};

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
    gUnknown_203B404->s18.s0.winId = 0;
    gUnknown_203B404->s18.s0.unk38 = &gUnknown_203B404->s18.s0.windows.id[0];

    gUnknown_203B404->s18.s0.windows.id[0] = gUnknown_80F4290;
    gUnknown_203B404->s18.s0.windows.id[1] = gUnknown_80F42A8;
    gUnknown_203B404->s18.s0.windows.id[2] = gUnknown_80F4278;
    gUnknown_203B404->s18.s0.windows.id[3] = gUnknown_80F4278;

    gUnknown_203B404->s18.s0.unk38->header = &gUnknown_203B404->s18.header;

    gUnknown_203B404->s18.header.count = 1;
    gUnknown_203B404->s18.header.currId = 0;
    gUnknown_203B404->s18.header.width = 6;
    gUnknown_203B404->s18.header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B404->s18.s0.windows, TRUE, TRUE);
    CreateMenuOnWindow(&gUnknown_203B404->s18.s0.input, GetValidPartners(), 10, gUnknown_203B404->s18.s0.winId);
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

    if (MenuCursorUpdate(&gUnknown_203B404->s18.s0.input, TRUE))
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
    gUnknown_203B404->s18.s0.input.totalEntriesCount = GetValidPartners();
    MenuUpdatePagesData(&gUnknown_203B404->s18.s0.input);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B404->s18.s0.input);
}

void sub_803CE6C(void)
{
    gUnknown_203B404->s18.s0.windows.id[gUnknown_203B404->s18.s0.winId] = gUnknown_80F4278;
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B404->s18.s0.windows, TRUE, TRUE);
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

static void RedrawPartnerSelectionMenu(void)
{
    u32 yCoord;
    const u8 *monName;
    s32 monCounter;

    SUB_80095E4_CALL(gUnknown_203B404->s18.s0);

    CallPrepareTextbox_8008C54(gUnknown_203B404->s18.s0.winId);
    sub_80073B8(gUnknown_203B404->s18.s0.winId);
    PrintStringOnWindow(12, 0, gPartnerSelectionHeaderText, gUnknown_203B404->s18.s0.winId, 0);

    monCounter = 0;
    while (monCounter < gUnknown_203B404->s18.s0.input.currPageEntries) {
        yCoord = GetMenuEntryYCoord(&gUnknown_203B404->s18.s0.input, monCounter);
        monName = GetMonSpecies(gUnknown_203B404->PartnerArray[monCounter]);
        PrintStringOnWindow(8, yCoord, monName, gUnknown_203B404->s18.s0.winId, 0);
        monCounter++;
    }
    sub_80073E0(gUnknown_203B404->s18.s0.winId);
    gUnknown_203B404->unk16 = 1;
}

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
    gfx = ((PortraitGfx *)(faceFile->data))->sprites[EMOTION_NORMAL].gfx;
    emotionId = EMOTION_NORMAL;
    for (paletteIndex = 0; paletteIndex < 0x10; paletteIndex++) {
        SetBGPaletteBufferColorArray(paletteIndex + 0xE0, &((PortraitGfx *)(faceFile->data))->sprites[emotionId].pal[paletteIndex]);
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
