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
    gUnknown_203B404->unk4C = 0;
    gUnknown_203B404->unk50 = gUnknown_203B404->unk54;

    gUnknown_203B404->unk54[0] = gUnknown_80F4290;
    gUnknown_203B404->unk54[1] = gUnknown_80F42A8;
    gUnknown_203B404->unk54[2] = gUnknown_80F4278;
    gUnknown_203B404->unk54[3] = gUnknown_80F4278;

    gUnknown_203B404->unk50->unk14 = gUnknown_203B404->unkb4;

    gUnknown_203B404->unkb4[0] = 1;
    gUnknown_203B404->unkb4[1] = 0;
    gUnknown_203B404->unkb4[2] = 6;
    gUnknown_203B404->unkb4[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B404->unk54, TRUE, TRUE);
    sub_8013818(&gUnknown_203B404->input, GetValidPartners(), 10, gUnknown_203B404->unk4C);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();
}

u16 HandlePartnerSelectionInput(void)
{
    s32 partnerID;

    partnerID = gUnknown_203B404->input.menuIndex;
    gUnknown_203B404->unk16 = 0;

    if (GetKeyPress(&gUnknown_203B404->input) == INPUT_A_BUTTON) {
        PlayMenuSoundEffect(0);
        return gUnknown_203B404->PartnerArray[gUnknown_203B404->input.menuIndex];
    }

    if (sub_80138B8(&gUnknown_203B404->input, TRUE))
        RedrawPartnerSelectionMenu();

    if (partnerID != gUnknown_203B404->input.menuIndex)
        PersonalityTest_DisplayPartnerSprite();

    if (gUnknown_203B404->unk16 != 0) {
        return -2;
    }
    return -1;
}

UNUSED static void sub_803CE34(bool8 cursorSprite)
{
    gUnknown_203B404->input.unk22 = GetValidPartners();
    sub_8013984(&gUnknown_203B404->input);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B404->input);
}

void sub_803CE6C(void)
{
    gUnknown_203B404->unk54[gUnknown_203B404->unk4C] = gUnknown_80F4278;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B404->unk54, TRUE, TRUE);
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
static void RedrawPartnerSelectionMenu(void)
{
    s32 sVar1;
    u32 yCoord;
    const u8 *monName;
    s32 monCounter;

    sVar1 = sub_80095E4(gUnknown_203B404->unk32, 12);

    // Have a feeling this is some graphical thing but
    // still not sure structure so it's not matching yet bc of that
    // and some casting stuff
    sVar1 += 2;
    sVar1 <<= 16;
    gUnknown_203B404->unk54[gUnknown_203B404->unk4C].unk0[7] = sVar1;
    gUnknown_203B404->unk54[gUnknown_203B404->unk4C].unk0[8] = sVar1 + 2;

    // Everything after this matches
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B404->unk54, TRUE, TRUE);
    sub_8008C54(gUnknown_203B404->unk4C);
    sub_80073B8(gUnknown_203B404->unk4C);
    xxx_call_draw_string(12, 0, gPartnerSelectionHeaderText, gUnknown_203B404->unk4C, 0);

    monCounter = 0;
    while (monCounter < gUnknown_203B404->unk32) {
        yCoord = sub_8013800(&gUnknown_203B404->unk18, monCounter);
        monName = GetMonSpecies(gUnknown_203B404->PartnerArray[monCounter]);
        xxx_call_draw_string(8, yCoord, monName, gUnknown_203B404->unk4C, 0);
        monCounter++;
    }
    sub_80073E0(gUnknown_203B404->unk4C);
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
    "\tbl sub_800641C\n"
    "\tldr r0, [r6]\n"
    "\tldr r0, [r0, 0x4C]\n"
    "\tbl sub_8008C54\n"
    "\tldr r0, [r6]\n"
    "\tldr r0, [r0, 0x4C]\n"
    "\tbl sub_80073B8\n"
    "\tldr r2, _0803CF64\n"
    "\tldr r0, [r6]\n"
    "\tldr r3, [r0, 0x4C]\n"
    "\tstr r4, [sp]\n"
    "\tmovs r0, 0xC\n"
    "\tmovs r1, 0\n"
    "\tbl xxx_call_draw_string\n"
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
    "\tbl xxx_call_draw_string\n"
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
    OpenedFile *faceFile;
    s32 palleteIndex;
    u8 *r6;
    u32 faceIndex;

    partnerID = gUnknown_203B404->PartnerArray[gUnknown_203B404->input.menuIndex];
    sub_8008C54(1);
    sub_80073B8(1);
    faceFile = GetDialogueSpriteDataPtr(partnerID);
    r6 = ((struct FaceData *)faceFile->data)->unk0[1 + EMOTION_NORMAL];
    faceIndex = EMOTION_NORMAL;

    for (palleteIndex = 0; palleteIndex < 0x10; palleteIndex++)
        SetBGPaletteBufferColorArray(palleteIndex + 0xE0, &((struct FaceData *)faceFile->data)->unk0[faceIndex][palleteIndex * 4]);

    sub_800836C(1, r6, 14);
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