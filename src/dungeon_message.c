#include "global.h"
#include "dungeon_message.h"
#include "dungeon.h"
#include "structs/dungeon_entity.h"
#include "code_803E46C.h"
#include "code_80130A8.h"
#include "code_800E9E4.h"
#include "menu_input.h"
#include "code_803E668.h"
#include "bg_palette_buffer.h"
#include "input.h"
#include "text2.h"
#include "pokemon.h"
#include "file_system.h"
#include "dungeon_util_1.h"
#include "code_800D090.h"
#include "dungeon_util.h"
#include "code_8045A00.h"
#include "exclusive_pokemon.h"
#include "dungeon_leader.h"
#include "text1.h"

void sub_80526D0(s32 r0);
static void PutStringsOnMessageLog(void);
static bool8 TryScrollLogDown(s32 a0);
static bool8 TryScrollLogUp(s32 a0);
static void CopyStringToMessageLog(const u8 *src, u32 a1, u32 a2);
static void CreateMessageLogArrow(bool8 upArrow, s32 y);
static void DisplayMessageAddToLog(Entity *r0, const char *str, u8 r2);
static bool8 sub_8052DC0(Entity *);

extern bool8 sub_8045888(Entity *r0);
extern u8 sub_803F428(Position *);
extern void sub_805E804(void);
extern void sub_803EAF0(s32, s32);
extern void sub_8052210(u32);
extern void sub_8040238(void);
extern void sub_8083E28(void);
extern bool8 sub_8008D8C(u32 strId);
extern u32 sub_8014140(s32 a0, const void *a1);
extern void sub_8083D30(void);
extern void sub_8083D08(void);
extern void sub_8007334(s32 a0);
extern void sub_80087EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void sub_8083CE0(u8 param_1);

extern u8 gUnknown_203B40C;
extern u8 gUnknown_202EE01;
extern Entity *gUnknown_202F1E8;
extern u8 gUnknown_203B434;
extern void (*gUnknown_203B08C)(s32);
extern void (*gUnknown_203B084)(s32 a0);
extern void (*gUnknown_203B080)(s32 a0);
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202E5D8[];
extern u8 gUnknown_202DFE8[];
extern SpriteOAM gUnknown_202F1F0;
extern SpriteOAM gUnknown_202F200;
extern s32 gUnknown_202F1F8;
extern u8 gUnknown_202F1FC;
extern UnkTextStruct1 gUnknown_2027370[4];
extern s32 gUnknown_202EDCC;
extern u8 gFontPalette[];

extern const u8 gUnknown_80F7AF8[];
extern const u8 gUnknown_80F7AFC[];
extern const u8 gUnknown_80F7B04[];
extern const u16 gUnknown_80F7AEA[];

// Used for gUnknown_202F1FC
#define FLAG_CAN_SCROLL_UP      0x1
#define FLAG_CAN_SCROLL_DOWN    0x2

void sub_805229C(void)
{
    return sub_80526D0(0x50);
}

void TryDisplayDungeonLoggableMessage(Entity *pokemon, const char *str)
{
    if (sub_8045888(pokemon)){
        DisplayMessageAddToLog(pokemon, str, TRUE);
    }
}

UNUSED void TryDisplayDungeonLoggableMessage2(Entity *r0, const char *str)
{
    if (sub_8045888(r0)){
        DisplayMessageAddToLog(r0, str, FALSE);
    }
}

void DisplayDungeonLoggableMessageFalse(Entity *r0, const char *str)
{
    DisplayMessageAddToLog(r0, str, FALSE);
}

void TryDisplayDungeonLoggableMessage3(Entity *attacker, Entity *target, const char *str)
{
    u8 flag;
    flag = sub_8045888(attacker) ? TRUE : FALSE;
    if(sub_8052DC0(target) != 0)
    {
        flag = TRUE;
    }
    if(flag)
    {
        DisplayMessageAddToLog(attacker, str, TRUE);
    }
}

void TryDisplayDungeonLoggableMessage4(Entity *attacker, Entity *target, const char *str)
{
    u8 flag;
    flag = sub_8045888(attacker) ? TRUE : FALSE;
    if(sub_8052DC0(target) != 0)
    {
        flag = TRUE;
    }
    if(flag)
    {
        DisplayMessageAddToLog(attacker, str, FALSE);
    }
}

void TryDisplayDungeonLoggableMessage5(Entity *r0, Position *pos, const char *str)
{
    u8 flag;
    flag = sub_8045888(r0) ? TRUE : FALSE;
    if(sub_803F428(pos) != 0)
    {
        flag = TRUE;
    }
    if(flag)
    {
        DisplayMessageAddToLog(r0, str, TRUE);
    }
}

void DisplayDungeonLoggableMessageTrue(Entity *r0, const char *str)
{
    DisplayMessageAddToLog(r0, str, TRUE);
}

static void DisplayMessageAddToLog(Entity *r0, const char *str, bool8 r2)
{
    u8 txt[64];
    u32 r7;
    bool32 r8, r9;

    if (gUnknown_202F1E8 != r0) {
        r7 = 1;
    }
    else {
        r7 = gUnknown_203B434;
    }

    r8 = 1;
    gUnknown_202F1E8 = r0;
    gUnknown_203B434 = 0;
    r9 = FALSE;
    while (1) {
        while (1) {
            s32 val = gDungeon->unk1BDD4.unk1C060;
            if (++val == UNK_1BBD4_STR_COUNT) {
                val = 0;
            }

            if (val != gDungeon->unk1BDD4.unk1C062) {
                break;
            }
            sub_803E46C(0);
        }

        if (*str == '\0')
            break;

        gDungeon->unk1BDD4.unk1C054[gDungeon->unk1BDD4.unk1C060] = r7;
        str = xxx_format_string(str, txt, txt + 62, 128);
        if (*str == '\r') str++;
        if (*str == '\n') str++;
        CopyStringToMessageLog(txt, r7, r8);
        r7 = 0;
        r8 = 0;
        if (r2) {
            u8 *dst;

            r9 = TRUE;
            dst = gDungeon->unk1BDD4.unk0[gDungeon->unk1BDD4.unk1C060];
            ASM_MATCH_TRICK(dst);
            strncpy(dst, txt, 64);
            if (++gDungeon->unk1BDD4.unk1C060 == UNK_1BBD4_STR_COUNT) {
                gDungeon->unk1BDD4.unk1C060 = 0;
            }
        }
    }

    if (r9) {
        gDungeon->unk1BDD4.unk1C064 = 0xF0;
        if (gDungeon->unk1BDD4.unk1C06C == 0) {
            gDungeon->unk1BDD4.unk1C06C = 1;
        }
        sub_805E804();
    }
}

void xxx_draw_string_80524F0(void)
{
    struct UnkStructDungeon1BDD4 *strPtr = &gDungeon->unk1BDD4;

    switch (strPtr->unk1C06C) {
        case 0:
            break;
        case 1:
            if (sub_800EC74())
                break;
            sub_803EAF0(3, 0);
        // fall through
        case 2: {
            struct UnkDrawStringStruct sp;
            s32 id = strPtr->unk1C062;
            if (id == strPtr->unk1C060) {
                strPtr->unk1C06C = 0;
            }
            else {
                const u8 *txtPtr = strPtr->unk0[id];

                sp.unk0 = 4;
                sp.unk2 = strPtr->unk1C066;
                sp.unk10 = 7;
                sub_80073B8(0);
                if (strPtr->unk1C054[id] != 0 && strPtr->unk1C066 >= 8) {
                    sub_80078A4(0, 0, strPtr->unk1C066 - 1, 0xE0, 7);
                }

                while (1) {
                    txtPtr = xxx_handle_format_global(txtPtr, &sp);
                    if (*txtPtr == '\0' || *txtPtr == '\r' || *txtPtr == '\n')
                        break;
                    txtPtr = xxx_get_next_char_from_string(txtPtr, &sp.unk34);
                    if (sp.unk34 == 96) {
                        sp.unk0 += 6;
                    }
                    else {
                        sp.unk0 += xxx_call_draw_char(sp.unk0, sp.unk2, sp.unk34, sp.unk10, 0);
                    }
                }
                sub_80073E0(0);
                strPtr->unk1C064 = 240;
                if (++id == UNK_1BBD4_STR_COUNT) {
                    id = 0;
                }
                strPtr->unk1C062 = id;
                strPtr->unk1C066 += 11;
                if (strPtr->unk1C066 >= 48) {
                    strPtr->unk1C066 = 37;
                    strPtr->unk1C068 = 0;
                    strPtr->unk1C06C = 3;
                }
            }
            break;
        }
    case 3:
        strPtr->unk1C068++;
        gUnknown_203B08C(0);
        if (strPtr->unk1C068 > 10) {
            strPtr->unk1C06C = 2;
        }
        break;
    }

    if (strPtr->unk1C05E == 0 && strPtr->unk1C064 != 0 && --strPtr->unk1C064 == 0) {
        strPtr->unk1C06C = 0;
        sub_803EAF0(0, 0);
        sub_8052210(0);
    }
}

void sub_80526D0(s32 r0)
{
    struct UnkStructDungeon1BDD4 *strPtr = &gDungeon->unk1BDD4;
    while (strPtr->unk1C06C != 0 || gDungeon->unk1BDD4.unk1C060 != gDungeon->unk1BDD4.unk1C062) {
        sub_803E46C(r0);
    }
}

void sub_8052740(s32 a0)
{
    s32 i;
    struct UnkStructDungeon1BDD4 *strPtr = &gDungeon->unk1BDD4;

    sub_80526D0(a0);
    for (i = 0; i < 240; i++) {
        if (strPtr->unk1C064 < 180)
            break;
        if ((gRealInputs.held & AB_BUTTONS) == AB_BUTTONS)
            break;
        if (gRealInputs.pressed & JOY_EXCL_DPAD)
            break;
        sub_803E46C(a0);
    }
}

// Prints string in dialogue box and waits for A/B button press
#define PRINT_STRING_WAIT_PRESS(chosenMenuIndex)   \
{                                           \
    s32 unkPrintRet;                        \
                                            \
    do {                                    \
        DrawDialogueBoxString();            \
        sub_803E46C(9);                     \
        unkPrintRet = sub_80144A4(chosenMenuIndex);\
    } while (unkPrintRet != 0);             \
}

void DisplayDungeonMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, bool8 a2)
{
    struct MonPortraitMsg monPortrait, *monPortraitPtr;
    s32 chosenMenuIndex;

    if (gUnknown_203B40C) {
        sub_8052740(10);
    }

    sub_803EAF0(2, 0);
    sub_8052210(0);

    monPortraitPtr = NULL;
    monPortrait.faceFile = NULL;
    monPortrait.faceData = NULL;
    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && monSpriteInfo != NULL
        && IsPokemonDialogueSpriteAvail(monSpriteInfo->species, monSpriteInfo->spriteId))
    {
        monPortrait.faceFile = GetDialogueSpriteDataPtr(monSpriteInfo->species);
        monPortrait.faceData = monPortrait.faceFile->data;
        monPortrait.pos.x = 2;
        monPortrait.pos.y = 9;
        monPortrait.spriteId = monSpriteInfo->spriteId;
        monPortrait.flip = FALSE;
        monPortrait.unkE = 0;
        monPortraitPtr = &monPortrait;
    }

    CreateMenuDialogueBoxAndPortrait(str, 0, 0, NULL, NULL, 3, 0, monPortraitPtr, (a2 != FALSE) ? 0x701 : 0x400);
    gDungeon->unk1BDD4.unk1C05F = 1;
    PRINT_STRING_WAIT_PRESS(&chosenMenuIndex);
    gDungeon->unk1BDD4.unk1C05F = 0;

    if (monPortrait.faceFile != NULL) {
        CloseFile(monPortrait.faceFile);
    }

    if (a2) {
        sub_805E804();
        sub_8040238();
        if (gUnknown_202EE01) {
            sub_803EAF0(0, 0);
        }
        else {
            sub_803EAF0(1, 0);
        }
    }

    sub_803E708(8, 9);
}

void DisplayDungeonLoggableMessage(Entity *a0, const u8 *str)
{
    DisplayDungeonMessage(NULL, str, TRUE);
    DisplayDungeonLoggableMessageFalse(a0, str);
}

struct Struct_sub_808CDB0
{
    Position pos;
    bool8 flip;
};

extern const struct Struct_sub_808CDB0 *sub_808CDB0(s32 a0);

void DisplayDungeonDialogue(const struct DungeonDialogueStruct *dialogueInfo)
{
    struct MonPortraitMsg monPortrait;
    s32 leaderId, partnerId, dialogueMonId;
    s32 chosenMenuIndex;
    Entity *leader = xxx_call_GetLeader();
    Entity *partner = GetPartnerEntity();
    struct MonPortraitMsg *monPortraitPtr = NULL;

    if (leader != NULL) {
        EntityInfo *leaderInfo = GetEntInfo(leader);
        PokemonStruct2 *monStruct2 = &gRecruitedPokemonRef->pokemon2[leaderInfo->teamIndex];

        sub_808DA0C(gAvailablePokemonNames, monStruct2);
        leaderId = leaderInfo->apparentID;
    }
    else {
        leaderId = MONSTER_NONE;
        strcpy(gAvailablePokemonNames, gUnknown_80F7AF8); // ??
    }

    if (partner != NULL) {
        EntityInfo *partnerInfo = GetEntInfo(partner);
        PokemonStruct2 *monStruct2 = &gRecruitedPokemonRef->pokemon2[partnerInfo->teamIndex];

        sub_808DA0C(gUnknown_202DFE8, monStruct2);
        partnerId = partnerInfo->apparentID;
    }
    else {
        partnerId = MONSTER_NONE;
        strcpy(gUnknown_202DFE8, gUnknown_80F7AF8); // ??
    }

    switch (dialogueInfo->unk4) {
        case 425:
            dialogueMonId = leaderId;
            sprintfStatic(gUnknown_202E5D8, gUnknown_80F7AFC, gAvailablePokemonNames);
            break;
        case 426:
            dialogueMonId = partnerId;
            sprintfStatic(gUnknown_202E5D8, gUnknown_80F7AFC, gUnknown_202DFE8);
            break;
        case 427:
            dialogueMonId = MONSTER_NONE;
            strcpy(gUnknown_202E5D8, gUnknown_80F7B04);
            break;
        default:
            dialogueMonId = dialogueInfo->unk4;
            CopyYellowMonsterNametoBuffer(gUnknown_202E5D8, dialogueMonId);
            break;
    }

    if (dialogueInfo->unk0 == 2 || dialogueInfo->unk0 == 3) {
        strcpy(gUnknown_202E5D8, gUnknown_80F7B04);
    }

    while (1) {
        if (dialogueInfo->unk6 == 0)
            break;
        if (dialogueInfo->unk6 == 7   && (dialogueMonId == MONSTER_SQUIRTLE || dialogueMonId == MONSTER_TOTODILE))
            break;
        if (dialogueInfo->unk6 == 1   && (dialogueMonId == MONSTER_BULBASAUR || dialogueMonId == MONSTER_CYNDAQUIL || dialogueMonId == MONSTER_MUDKIP || dialogueMonId == MONSTER_PIKACHU || dialogueMonId == MONSTER_CHARMANDER || dialogueMonId == MONSTER_TREECKO))
            break;
        if (dialogueInfo->unk6 == 280 && (dialogueMonId == MONSTER_TORCHIC || dialogueMonId == MONSTER_CHIKORITA))
            break;
        dialogueInfo++;
    }

    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && dialogueInfo->unk0 != 4
        && dialogueInfo->unk2 != 0x80
        && dialogueMonId != MONSTER_NONE)
    {
        const struct Struct_sub_808CDB0 *strPtr = sub_808CDB0(dialogueInfo->unk3);

        monPortraitPtr = &monPortrait;
        monPortraitPtr->faceFile = GetDialogueSpriteDataPtr(dialogueMonId);
        if (monPortraitPtr->faceFile != NULL) {
            monPortraitPtr->faceData = monPortraitPtr->faceFile->data;
            monPortraitPtr->unkE = 0;
            monPortraitPtr->spriteId = dialogueInfo->unk2;
            monPortraitPtr->flip = strPtr->flip;
            monPortraitPtr->pos.x = strPtr->pos.x;
            monPortraitPtr->pos.y = strPtr->pos.y;
            if (monPortraitPtr->pos.y < 2) {
                monPortraitPtr->pos.y = 2;
            }
        }
        else {
            monPortraitPtr = NULL;
        }
    }

    sub_8052740(10);
    sub_803EAF0(2, 0);
    sub_8052210(0);
    CreateDialogueBoxAndPortrait(dialogueInfo->str, 0, monPortraitPtr, gUnknown_80F7AEA[dialogueInfo->unk0]);
    PRINT_STRING_WAIT_PRESS(&chosenMenuIndex);

    if (monPortraitPtr != NULL) {
        CloseFile(monPortraitPtr->faceFile);
    }

    if (dialogueInfo->unk0 != 1 && dialogueInfo->unk0 != 3) {
        sub_8040238();
        sub_803EAF0(0, 0);
    }
    sub_803E708(8, 9);
}

bool32 DisplayDungeonYesNoMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, bool32 defaultYes)
{
    struct MonPortraitMsg monPortrait, *monPortraitPtr;
    s32 chosenMenuIndex;

    sub_8052740(10);
    sub_803EAF0(2, 0);
    sub_8052210(0);

    monPortraitPtr = NULL;
    monPortrait.faceFile = NULL;
    monPortrait.faceData = NULL;
    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && monSpriteInfo != NULL
        && IsPokemonDialogueSpriteAvail(monSpriteInfo->species, monSpriteInfo->spriteId))
    {
        monPortrait.faceFile = GetDialogueSpriteDataPtr(monSpriteInfo->species);
        monPortrait.faceData = monPortrait.faceFile->data;
        monPortrait.pos.x = 2;
        monPortrait.pos.y = 9;
        monPortrait.spriteId = monSpriteInfo->spriteId;
        monPortrait.flip = FALSE;
        monPortrait.unkE = 0;
        monPortraitPtr = &monPortrait;
    }

    if (defaultYes == TRUE) {
        CreateYesNoDialogueBoxAndPortrait_DefaultYes(str, monPortraitPtr, 0x300); // Yes/No - cursor starts at Yes
    }
    else {
        CreateYesNoDialogueBoxAndPortrait_DefaultNo(str, monPortraitPtr, 0x300); // Yes/No - cursor starts at NO
    }

    PRINT_STRING_WAIT_PRESS(&chosenMenuIndex);

    if (monPortrait.faceFile != NULL) {
        CloseFile(monPortrait.faceFile);
    }

    sub_8040238();
    sub_803EAF0(0, 0);

    if (chosenMenuIndex == 1)
        return TRUE;
    else
        return FALSE;
}

s32 DisplayDungeonMenuMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, const MenuItem *menuItems, u16 unkArg)
{
    struct MonPortraitMsg monPortrait, *monPortraitPtr;
    s32 chosenMenuIndex;

    sub_8052740(10);
    sub_803EAF0(2, 0);
    sub_8052210(0);

    monPortraitPtr = NULL;
    monPortrait.faceFile = NULL;
    monPortrait.faceData = NULL;
    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && monSpriteInfo != NULL
        && IsPokemonDialogueSpriteAvail(monSpriteInfo->species, monSpriteInfo->spriteId))
    {
        monPortrait.faceFile = GetDialogueSpriteDataPtr(monSpriteInfo->species);
        monPortrait.faceData = monPortrait.faceFile->data;
        monPortrait.pos.x = 2;
        monPortrait.pos.y = 9;
        monPortrait.spriteId = monSpriteInfo->spriteId;
        monPortrait.flip = FALSE;
        monPortrait.unkE = 0;
        monPortraitPtr = &monPortrait;
    }

    CreateMenuDialogueBoxAndPortrait(str, 0, -1, menuItems, NULL, 3, 0, monPortraitPtr, unkArg);
    PRINT_STRING_WAIT_PRESS(&chosenMenuIndex);

    if (monPortrait.faceFile != NULL) {
        CloseFile(monPortrait.faceFile);
    }

    sub_8040238();
    sub_803EAF0(0, 0);
    return chosenMenuIndex;
}

void sub_8052D44(s16 *ids, Entity *leader, Entity *partner)
{
    if (EntityExists(leader)) {
        SetMessageArgument(gAvailablePokemonNames, leader, 0);
        ids[0] = GetEntInfo(leader)->apparentID;
    }
    else {
        strcpy(gAvailablePokemonNames, gUnknown_80F7AF8);
        ids[0] = 0;
    }

    if (EntityExists(partner)) {
        SetMessageArgument(gUnknown_202DFE8, partner, 0);
        ids[1] = GetEntInfo(partner)->apparentID;
    }
    else {
        strcpy(gUnknown_202DFE8, gUnknown_80F7AF8);
        ids[1] = 0;
    }
}

static bool8 sub_8052DC0(Entity *entity)
{
    return sub_8045888(entity);
}

struct TutorialFlagMsg
{
    s32 flagId;
    const u8 *str;
};

extern const struct TutorialFlagMsg gUnknown_80FF020;
extern const struct TutorialFlagMsg gUnknown_80FF080;
extern const struct TutorialFlagMsg gUnknown_80FF0D8;
extern const struct TutorialFlagMsg gUnknown_80FF13C;
extern const struct TutorialFlagMsg gUnknown_80FF1B4;
extern const struct TutorialFlagMsg gMovementTutorial;
extern const struct TutorialFlagMsg gHungerTutorial;
extern const struct TutorialFlagMsg gFoodTutorial;
extern const struct TutorialFlagMsg gOranTutorial;
extern const struct TutorialFlagMsg gCheriTutorial;
extern const struct TutorialFlagMsg gBlastSeedTutorial;
extern const struct TutorialFlagMsg gUnknown_80FF4A0;
extern const struct TutorialFlagMsg gPechaTutorial;
extern const struct TutorialFlagMsg gSleepSeedTutorial;
extern const struct TutorialFlagMsg gMoneyTutorial;

extern const u8 *const gUnknown_80FF6F8;
extern const u8 *const gUnknown_80FF6A4;
extern const u8 gUnknown_8106990[]; // Possibly something menu related?

static inline bool32 DislayTutorialMsg(Entity *leader, const struct TutorialFlagMsg *tutorial, bool32 unkFunctionCall)
{
    const u8 *str;
    s32 flag = tutorial->flagId;
    bool8 flagDone = GetTutorialFlag(flag);

    if (!flagDone) {
        SetTutorialFlag(flag);
        sub_8083E28();
        str = tutorial->str;
        DisplayDungeonMessage(NULL, str, TRUE);
        if (unkFunctionCall) {
            DisplayDungeonLoggableMessageFalse(leader, str);
        }
        return TRUE;
    }
    return FALSE;
}

void TryDisplayGeneralTutorialMessage(void)
{
    Entity *leader = GetLeader();

    if (DislayTutorialMsg(leader, &gUnknown_80FF020, TRUE)) return;
    if (DislayTutorialMsg(leader, &gUnknown_80FF080, TRUE)) return;
    if (DislayTutorialMsg(leader, &gUnknown_80FF0D8, TRUE)) return;
    if (gDungeon->dungeonLocation.id == DUNGEON_THUNDERWAVE_CAVE) {
        if (DislayTutorialMsg(leader, &gUnknown_80FF13C, TRUE)) return;
        if (DislayTutorialMsg(leader, &gUnknown_80FF1B4, TRUE)) return;
        if (DislayTutorialMsg(leader, &gMovementTutorial, TRUE)) return;
        if (DislayTutorialMsg(leader, &gHungerTutorial, TRUE)) return;
    }
}

void TryDisplayItemPickupTutorialMessage(u8 itemId)
{
    u32 itemCategory = GetItemCategory(itemId);

    if (itemCategory == CATEGORY_FOOD_GUMMIES) {
        DislayTutorialMsg(NULL, &gFoodTutorial, FALSE);
    }
    else if (itemId == ITEM_ORAN_BERRY) {
        DislayTutorialMsg(NULL, &gOranTutorial, FALSE);
    }
    else if (itemId == ITEM_CHERI_BERRY) {
        DislayTutorialMsg(NULL, &gCheriTutorial, FALSE);
    }
    else if (itemId == ITEM_BLAST_SEED) {
        DislayTutorialMsg(NULL, &gBlastSeedTutorial, FALSE);
    }
    else if (itemId == ITEM_GRAVELEROCK) {
        DislayTutorialMsg(NULL, &gUnknown_80FF4A0, FALSE);
    }
    else if (itemId == ITEM_PECHA_BERRY) {
        DislayTutorialMsg(NULL, &gPechaTutorial, FALSE);
    }
    else if (itemId == ITEM_SLEEP_SEED) {
        DislayTutorialMsg(NULL, &gSleepSeedTutorial, FALSE);
    }
    else if (itemId == ITEM_POKE) {
        DislayTutorialMsg(NULL, &gMoneyTutorial, FALSE);
    }
}

void DisplayYouReachedDestFloorStr(void)
{
    if (gDungeon->unkA != 0) {
        DisplayDungeonMessage(NULL, gUnknown_80FF6F8, 1); // But the pokemon you seek isn't here...
    }
    else {
        DisplayDungeonMessage(NULL, gUnknown_80FF6A4, 1);
    }
}

// Used only for displaying Frosy Forest's text at floor 6
void sub_8052FB8(const u8 *str)
{
    s32 r8 = 0, r9, j;
    {
        s32 i;
        for (i = 1; i < 30; i++) {
            gUnknown_202B038[0][0][i] = 0;
        }
    }

    CreateMenuDialogueBoxAndPortrait(str, 0, 0, NULL, NULL, 2, 0, NULL, 0x30);
    r9 = 0;
    while (1) {
        if (r8 < 62) {
            r8++;
            for (j = 0; j < 8; j++) {
                SetBGPaletteBufferColorRGB(240 + j, &gFontPalette[j * 4], r8 / 2, NULL);
            }
        }
        else {
            r9++;
            if (r9 & 8) {
                u32 shape, tileNum, unk6, spriteX, mask, palNum;

                gUnknown_202F1F0.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1;
                gUnknown_202F1F0.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
                gUnknown_202F1F0.attrib1 &= ~SPRITEOAM_MASK_OBJMODE;
                gUnknown_202F1F0.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
                gUnknown_202F1F0.attrib1 &= ~SPRITEOAM_MASK_BPP;

                gUnknown_202F1F0.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
                shape = 1;
                shape <<= SPRITEOAM_SHIFT_SHAPE;
                ASM_MATCH_TRICK(shape);
                gUnknown_202F1F0.attrib1 |= shape;

                tileNum = 0x3F0 << SPRITEOAM_SHIFT_TILENUM;
                gUnknown_202F1F0.attrib3 &= ~SPRITEOAM_MASK_TILENUM;
                gUnknown_202F1F0.attrib3 |= tileNum;

                gUnknown_202F1F0.attrib3 &= ~SPRITEOAM_MASK_PRIORITY;

                mask = 0xF;
                palNum = (15 & SPRITEOAM_MAX_PALETTENUM) << SPRITEOAM_SHIFT_PALETTENUM;
                gUnknown_202F1F0.attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
                gUnknown_202F1F0.attrib3 |= palNum;

                unk6 = 0x78 << SPRITEOAM_SHIFT_UNK6_4;
                gUnknown_202F1F0.unk6 &= mask;
                gUnknown_202F1F0.unk6 |= unk6;

                gUnknown_202F1F0.attrib2 &= ~SPRITEOAM_MASK_X;
                gUnknown_202F1F0.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;

                spriteX = 0x70 & SPRITEOAM_MAX_X;
                gUnknown_202F1F0.attrib2 &= ~SPRITEOAM_MASK_SIZE;
                gUnknown_202F1F0.attrib2 |= spriteX;

                AddSprite(&gUnknown_202F1F0, 0x100, NULL, NULL);
            }
            if (gRealInputs.pressed & AB_BUTTONS)
                break;
        }
        DrawDialogueBoxString();
        sub_803E46C(9);
    }

    while (r8 >= 0) {
        for (j = 0; j < 8; j++) {
            SetBGPaletteBufferColorRGB(240 + j, &gFontPalette[j * 4], r8 / 2, NULL);
        }
        DrawDialogueBoxString();
        sub_803E46C(9);
        r8--;
    }

    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
    sub_803E46C(9);
    sub_8040238();
    for (j = 0; j < 8; j++) {
        SetBGPaletteBufferColorArray(240 + j, &gFontPalette[j * 4]);
    }
    sub_803E708(8, 9);
}

const u8 *GetCurrentDungeonName(void)
{
    if (gDungeon->unk678 == 1) {
        return GetDungeonName1(DUNGEON_OUT_ON_RESCUE);
    }
    else {
        return GetDungeonName1(gDungeon->dungeonLocation.id);
    }
}

void ResetMessageLog(void)
{
    s32 i;

    gDungeon->unk16 = 0;
    gDungeon->unkB = 1;
    for (i = 0; i < MESSAGE_LOG_STRINGS_COUNT; i++) {
        gDungeon->messageLogStrings[i].str[0] = '\0';
        gDungeon->messageLogStrings[i].unk0 = 0;
        gDungeon->messageLogStrings[i].unk1 = 0;
        gDungeon->messageLogStrings[i].unk2 = 0;
    }
}

UNUSED void sub_8053200(void)
{
    gDungeon->unkB = 1;
}

static void CopyStringToMessageLog(const u8 *src, u32 a1, u32 a2)
{
    u8 *dst = &gDungeon->messageLogStrings[gDungeon->unk16].str[0];
    u8 *maxDst = &gDungeon->messageLogStrings[gDungeon->unk16].str[MESSAGE_LOG_BUFFER_SIZE - 1];
    gDungeon->messageLogStrings[gDungeon->unk16].unk0 = 1;
    gDungeon->messageLogStrings[gDungeon->unk16].unk1 = a1;
    gDungeon->messageLogStrings[gDungeon->unk16].unk2 = a2;

    while (*src != '\0') {
        if (*src == '\r') break;
        if (dst < maxDst) {
            *(dst++) = *src;
        }
        src++;
    }

    *dst = '\0';
    if (++gDungeon->unk16 >= MESSAGE_LOG_STRINGS_COUNT) {
        gDungeon->unk16 = 0;
    }

    gDungeon->unkB = 1;
}

#define MESSAGE_LOG_ROW_COUNT 8 // How many log messages are shown

bool32 DisplayMessageLog(void)
{
    bool8 unkRet;
    MenuInputStructSub menuInput;

    sub_801317C(&menuInput);
    sub_803EAF0(9, 0);
    do {
        sub_803E46C(13);
        unkRet = sub_8008D8C(0);
    } while (unkRet);

    gUnknown_202F1F8 = 0;
    gUnknown_202F1FC = 0;
    PutStringsOnMessageLog();

    while (1) {
        s32 unkVar;
        bool32 scroll = FALSE;

        gUnknown_202F1FC = 0;
        nullsub_34(&menuInput, 0);
        unkVar = sub_8014140(0, gUnknown_8106990);

        if (TryScrollLogUp(unkVar))
            scroll = TRUE;
        if (TryScrollLogDown(unkVar))
            scroll = TRUE;

        if (!scroll) {
            sub_803E46C(0xD);
        }

        if (gUnknown_202F1FC & FLAG_CAN_SCROLL_UP) {
            CreateMessageLogArrow(TRUE, -8);
        }
        if (gUnknown_202F1FC & FLAG_CAN_SCROLL_DOWN) {
            CreateMessageLogArrow(FALSE, 114);
        }

        if (!sub_80048C8()) {
            if (gRealInputs.pressed & B_BUTTON || menuInput.b_button) {
                sub_8083D30();
                break;
            }
            else if (gRealInputs.pressed & A_BUTTON) {
                sub_8083D08();
                break;
            }
        }
    }

    sub_803EAF0(0, 0);
    return TRUE;
}

static void PutStringsOnMessageLog(void)
{
    s32 i;
    s32 arrId = gDungeon->unk16;
    s32 y = 16;

    arrId -= 8;
    if (arrId < 0)
        arrId += MESSAGE_LOG_STRINGS_COUNT;

    sub_80073B8(0);
    for (i = 0; i < MESSAGE_LOG_ROW_COUNT; i++) {
        struct MessageLogString *msgLogString = &gDungeon->messageLogStrings[arrId];

        if (msgLogString->unk0) {
            if (msgLogString->unk1) {
                sub_80078A4(0, 0, y, 0xE0, 7);
            }
            PrintStringOnWindow(8, y + 3, msgLogString->str, 0, 0xD);
            y += 14;
        }
        if (++arrId >= MESSAGE_LOG_STRINGS_COUNT)
            arrId = 0;
    }

    sub_80073E0(0);
    sub_8007334(0);
}

static bool8 TryScrollLogUp(s32 a0)
{
    s32 i;
    struct MessageLogString *msgLogString;
    s32 y;
    s32 arrId;

    while (1)
    {
        arrId = gDungeon->unk16 + gUnknown_202F1F8;
        y = 2;
        arrId -= 9;
        while (arrId < 0) {
            arrId += MESSAGE_LOG_STRINGS_COUNT;
        }
        while (arrId >= MESSAGE_LOG_STRINGS_COUNT) {
            arrId -= MESSAGE_LOG_STRINGS_COUNT;
        }

        if (gDungeon->messageLogStrings[arrId].unk0 && gUnknown_202F1F8 > -12) {
            gUnknown_202F1FC |= FLAG_CAN_SCROLL_UP;
            if (gRealInputs.repeated & DPAD_UP)
                break;
            if (a0 == 1)
                break;
        }

        return FALSE;
    }
    sub_8083CE0(0);
    sub_80073B8(0);
    msgLogString = &gDungeon->messageLogStrings[arrId];
    if (msgLogString->unk0) {
        sub_80087EC(0, 0, 0, 0xD0, 0x10);
        if (msgLogString->unk1) {
            sub_80078A4(0, 0, y, 0xE0, 7);
        }
        PrintStringOnWindow(8, y + 3, msgLogString->str, 0, 0xD);
    }
    sub_80073E0(0);
    sub_803E46C(0xD);

    for (i = 0; i < 7; i++) {
        gUnknown_203B084(0);
        sub_803E46C(0xD);
    }

    gUnknown_202F1F8--;
    return TRUE;
}

static bool8 TryScrollLogDown(s32 a0)
{
    s32 i;
    struct MessageLogString *msgLogString;
    s32 y;
    s32 arrId;

    while (1)
    {
        arrId = gDungeon->unk16 + gUnknown_202F1F8;
        y = 128;
        while (arrId < 0) {
            arrId += MESSAGE_LOG_STRINGS_COUNT;
        }
        while (arrId >= MESSAGE_LOG_STRINGS_COUNT) {
            arrId -= MESSAGE_LOG_STRINGS_COUNT;
        }

        if (gUnknown_202F1F8 < 0) {
            gUnknown_202F1FC |= FLAG_CAN_SCROLL_DOWN;
            if (gRealInputs.repeated & DPAD_DOWN)
                break;
            if (a0 == 2)
                break;
        }

        return FALSE;
    }
    sub_8083CE0(0);
    sub_80073B8(0);
    msgLogString = &gDungeon->messageLogStrings[arrId];
    if (msgLogString->unk0) {
        sub_80087EC(0, 0, y, 0x68, 0x10);
        if (msgLogString->unk1) {
            sub_80078A4(0, 0, y, 0xE0, 7);
        }
        PrintStringOnWindow(8, y + 3, msgLogString->str, 0, 0xD);
    }
    sub_80073E0(0);
    sub_803E46C(0xD);

    for (i = 0; i < 7; i++) {
        gUnknown_203B080(0);
        sub_803E46C(0xD);
    }

    gUnknown_202F1F8++;
    return TRUE;
}

static void CreateMessageLogArrow(bool8 upArrow, s32 y)
{
    struct UnkTextStruct1 *unkStr = &gUnknown_2027370[0];
    if (!(gUnknown_202EDCC & 8)) {
        u32 matrixNum, xSprite, mask, ySprite, shape, yMask;

        gUnknown_202F200.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1;
        gUnknown_202F200.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
        gUnknown_202F200.attrib1 &= ~SPRITEOAM_MASK_OBJMODE;
        gUnknown_202F200.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
        gUnknown_202F200.attrib1 &= ~SPRITEOAM_MASK_BPP;

        matrixNum = (upArrow != FALSE) ? (16) : 0;
        // You may be thinking what is this empty loop doing here, but the better question is: Why do these unholy sprite macros exist?
        do {} while (0);
        matrixNum <<= 9;
        gUnknown_202F200.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
        gUnknown_202F200.attrib2 |= matrixNum;

        mask = 0xF;
        yMask = 0xFFF;
        ySprite = (yMask & (unkStr->unk2 * 8 + y)) << 4;
        gUnknown_202F200.unk6 &= mask;
        gUnknown_202F200.unk6 |= ySprite;

        xSprite = 0x1FF & ((unkStr->unk0 * 8) + 92);
        gUnknown_202F200.attrib2 &= ~SPRITEOAM_MASK_X;
        gUnknown_202F200.attrib2 |= xSprite;

        shape = 1;
        shape <<= SPRITEOAM_SHIFT_SHAPE;
        gUnknown_202F200.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
        gUnknown_202F200.attrib1 |= shape;

        gUnknown_202F200.attrib2 &= ~SPRITEOAM_MASK_SIZE;

        gUnknown_202F200.attrib3 = 0xF3F0;

        AddSprite(&gUnknown_202F200, 127, NULL, NULL);
    }
}

// TODO: figure out if a new file starts here
#include "dungeon_pokemon_attributes.h"
#include "moves.h"
#include "status_checks_1.h"
#include "dungeon_ai_targeting.h"
#include "structs/str_damage.h"
#include "constants/ability.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "type_chart.h"
#include "position_util.h"
#include "code_806CD90.h"
#include "move_util.h"
#include "code_808417C.h"
#include "dungeon_capabilities.h"
#include "move_effects_target.h"
#include "status.h"
#include "weather.h"
#include "code_8077274_1.h"
#include "charge_move.h"
#include "dungeon_random.h"
#include "targeting_flags.h"
#include "targeting.h"
#include "called_move_data.h"
#include "dungeon_map_access.h"
#include "math.h"
#include "code_800DAC0.h"

NAKED void sub_8053704(Entity **unkArray, Entity *entity, Move *move, s32 itemId, s32 a4)
{
    asm_unified("\n"
	"	push {r4-r7,lr}\n"
	"	mov r7, r10\n"
	"	mov r6, r9\n"
	"	mov r5, r8\n"
	"	push {r5-r7}\n"
	"	sub sp, 0x48\n"
	"	str r0, [sp, 0x10]\n"
	"	adds r7, r1, 0\n"
	"	mov r8, r2\n"
	"	mov r9, r3\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x14]\n"
	"	ldrh r1, [r2, 0x2]\n"
	"	str r1, [sp, 0x18]\n"
	"	bl _08055570\n"
	"_08053724:\n"
	"	adds r0, r5, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	bne _08053734\n"
	"	bl _0805556A\n"
	"_08053734:\n"
	"	str r7, [sp, 0x1C]\n"
	"	ldr r2, [r5, 0x70]\n"
	"	str r2, [sp, 0x24]\n"
	"	movs r3, 0xAD\n"
	"	lsls r3, 1\n"
	"	adds r0, r2, r3\n"
	"	add r1, sp, 0x20\n"
	"	ldrb r1, [r1]\n"
	"	strb r1, [r0]\n"
	"	ldr r0, [sp, 0x18]\n"
	"	bl CanBeSnatched\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _080537B4\n"
	"	ldr r6, _080537A4\n"
	"	ldr r0, [r6]\n"
	"	ldr r2, _080537A8\n"
	"	adds r0, r2\n"
	"	ldr r4, [r0]\n"
	"	cmp r4, 0\n"
	"	beq _080537B4\n"
	"	adds r0, r4, 0\n"
	"	bl GetEntityType\n"
	"	cmp r0, 0x1\n"
	"	beq _0805376C\n"
	"	b _08053A1C\n"
	"_0805376C:\n"
	"	cmp r4, r7\n"
	"	bne _08053772\n"
	"	b _08053A1C\n"
	"_08053772:\n"
	"	ldr r1, [r4, 0x70]\n"
	"	adds r1, 0x98\n"
	"	ldr r0, [r6]\n"
	"	ldr r3, _080537AC\n"
	"	adds r0, r3\n"
	"	ldr r1, [r1]\n"
	"	ldr r0, [r0]\n"
	"	cmp r1, r0\n"
	"	beq _08053786\n"
	"	b _08053A1C\n"
	"_08053786:\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0xFF\n"
	"	ldrb r0, [r0]\n"
	"	cmp r0, 0\n"
	"	beq _08053792\n"
	"	b _08053A1C\n"
	"_08053792:\n"
	"	ldr r0, _080537B0\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	adds r5, r4, 0\n"
	"	b _08053A1C\n"
	"	.align 2, 0\n"
	"_080537A4: .4byte gDungeon\n"
	"_080537A8: .4byte 0x00017b30\n"
	"_080537AC: .4byte 0x00017b3c\n"
	"_080537B0: .4byte gUnknown_80FCD28\n"
	"_080537B4:\n"
	"	adds r0, r7, 0\n"
	"	mov r1, r8\n"
	"	bl GetMoveTypeForMonster\n"
	"	lsls r0, 24\n"
	"	lsrs r0, 24\n"
	"	cmp r0, 0x5\n"
	"	bne _08053854\n"
	"	ldr r2, _08053844\n"
	"	ldr r0, [r2]\n"
	"	ldr r1, _08053848\n"
	"	adds r0, r1\n"
	"	ldr r0, [r0]\n"
	"	cmp r0, 0\n"
	"	beq _08053854\n"
	"	adds r4, r0, 0\n"
	"	str r2, [sp, 0x44]\n"
	"	bl GetEntityType\n"
	"	ldr r2, [sp, 0x44]\n"
	"	cmp r0, 0x1\n"
	"	beq _080537E2\n"
	"	b _08053A1C\n"
	"_080537E2:\n"
	"	ldr r6, [r4, 0x70]\n"
	"	adds r1, r6, 0\n"
	"	adds r1, 0x98\n"
	"	ldr r0, [r2]\n"
	"	ldr r2, _0805384C\n"
	"	adds r0, r2\n"
	"	ldr r1, [r1]\n"
	"	ldr r0, [r0]\n"
	"	cmp r1, r0\n"
	"	beq _080537F8\n"
	"	b _08053A1C\n"
	"_080537F8:\n"
	"	adds r0, r4, 0\n"
	"	adds r1, r7, 0\n"
	"	movs r2, 0x1\n"
	"	movs r3, 0\n"
	"	bl GetTreatmentBetweenMonsters\n"
	"	lsls r0, 24\n"
	"	lsrs r0, 24\n"
	"	cmp r0, 0x1\n"
	"	beq _0805380E\n"
	"	b _08053A1C\n"
	"_0805380E:\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0xFF\n"
	"	ldrb r0, [r0]\n"
	"	cmp r0, 0\n"
	"	bne _08053822\n"
	"	adds r0, r6, 0\n"
	"	adds r0, 0xFF\n"
	"	ldrb r0, [r0]\n"
	"	cmp r0, 0\n"
	"	beq _08053828\n"
	"_08053822:\n"
	"	cmp r5, r4\n"
	"	beq _08053828\n"
	"	b _08053A1C\n"
	"_08053828:\n"
	"	adds r0, r4, 0\n"
	"	bl sub_8042930\n"
	"	ldr r0, _08053850\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	adds r5, r4, 0\n"
	"	movs r3, 0x1\n"
	"	str r3, [sp, 0x2C]\n"
	"	b _08053A1C\n"
	"	.align 2, 0\n"
	"_08053844: .4byte gDungeon\n"
	"_08053848: .4byte 0x00017b2c\n"
	"_0805384C: .4byte 0x00017b38\n"
	"_08053850: .4byte gUnknown_80FCD0C\n"
	"_08053854:\n"
	"	adds r0, r5, 0\n"
	"	movs r1, 0x2C\n"
	"	bl HasHeldItem\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	bne _08053864\n"
	"	b _08053A1C\n"
	"_08053864:\n"
	"	adds r0, r5, 0\n"
	"	movs r1, 0\n"
	"	bl CannotAttack\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053874\n"
	"	b _08053A1C\n"
	"_08053874:\n"
	"	adds r0, r7, 0\n"
	"	mov r1, r8\n"
	"	movs r2, 0\n"
	"	bl GetMoveTargetAndRangeForPokemon\n"
	"	movs r1, 0xF0\n"
	"	ands r1, r0\n"
	"	cmp r1, 0\n"
	"	beq _08053888\n"
	"	b _08053A1C\n"
	"_08053888:\n"
	"	ldr r1, [sp, 0x24]\n"
	"	movs r2, 0x9E\n"
	"	lsls r2, 1\n"
	"	adds r0, r1, r2\n"
	"	ldr r0, [r0]\n"
	"	bl FixedPointToInt\n"
	"	ldr r1, _080538C4\n"
	"	movs r3, 0\n"
	"	ldrsh r1, [r1, r3]\n"
	"	cmp r0, r1\n"
	"	bge _080538A2\n"
	"	b _08053A1C\n"
	"_080538A2:\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0xFF\n"
	"	ldrb r0, [r0]\n"
	"	cmp r0, 0\n"
	"	beq _080538AE\n"
	"	b _08053A1C\n"
	"_080538AE:\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0x46\n"
	"	ldrb r4, [r0]\n"
	"	mov r10, r4\n"
	"	bl IsBossFight\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _080538CC\n"
	"	ldr r0, _080538C8\n"
	"	b _080539FA\n"
	"	.align 2, 0\n"
	"_080538C4: .4byte gUnknown_80F5006\n"
	"_080538C8: .4byte gUnknown_80FDD88\n"
	"_080538CC:\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x34]\n"
	"	movs r2, 0x9E\n"
	"	lsls r2, 1\n"
	"	ldr r1, [sp, 0x24]\n"
	"	adds r2, r1, r2\n"
	"	str r2, [sp, 0x3C]\n"
	"_080538DA:\n"
	"	movs r3, 0x1\n"
	"	add r10, r3\n"
	"	movs r0, 0x7\n"
	"	mov r1, r10\n"
	"	ands r1, r0\n"
	"	mov r10, r1\n"
	"	movs r2, 0x4\n"
	"	ldrsh r0, [r5, r2]\n"
	"	ldr r1, _080539B4\n"
	"	mov r3, r10\n"
	"	lsls r2, r3, 2\n"
	"	adds r2, r1\n"
	"	movs r3, 0\n"
	"	ldrsh r1, [r2, r3]\n"
	"	adds r0, r1\n"
	"	movs r3, 0x6\n"
	"	ldrsh r1, [r5, r3]\n"
	"	movs r3, 0x2\n"
	"	ldrsh r2, [r2, r3]\n"
	"	adds r1, r2\n"
	"	bl GetTile\n"
	"	ldr r0, [r0, 0x10]\n"
	"	str r0, [sp, 0x38]\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _080539DC\n"
	"	ldr r0, [sp, 0x38]\n"
	"	bl GetEntityType\n"
	"	cmp r0, 0x1\n"
	"	bne _080539DC\n"
	"	adds r0, r5, 0\n"
	"	bl sub_8045888\n"
	"	lsls r0, 24\n"
	"	mov r1, sp\n"
	"	adds r1, 0xC\n"
	"	str r1, [sp, 0x40]\n"
	"	cmp r0, 0\n"
	"	beq _0805397C\n"
	"	movs r6, 0x17\n"
	"_08053932:\n"
	"	adds r0, r5, 0\n"
	"	adds r1, r4, 0\n"
	"	bl sub_806CE68\n"
	"	movs r0, 0x2\n"
	"	movs r1, 0x43\n"
	"	bl sub_803E708\n"
	"	adds r4, 0x1\n"
	"	movs r2, 0x7\n"
	"	ands r4, r2\n"
	"	subs r6, 0x1\n"
	"	cmp r6, 0\n"
	"	bge _08053932\n"
	"	cmp r4, r10\n"
	"	beq _0805396C\n"
	"	movs r6, 0x7\n"
	"_08053954:\n"
	"	adds r0, r5, 0\n"
	"	adds r1, r4, 0\n"
	"	bl sub_806CE68\n"
	"	movs r0, 0x2\n"
	"	movs r1, 0x43\n"
	"	bl sub_803E708\n"
	"	adds r4, 0x1\n"
	"	ands r4, r6\n"
	"	cmp r4, r10\n"
	"	bne _08053954\n"
	"_0805396C:\n"
	"	adds r0, r5, 0\n"
	"	adds r1, r4, 0\n"
	"	bl sub_806CE68\n"
	"	movs r0, 0x2\n"
	"	movs r1, 0x43\n"
	"	bl sub_803E708\n"
	"_0805397C:\n"
	"	ldr r3, [sp, 0x3C]\n"
	"	ldr r4, [r3]\n"
	"	ldr r0, _080539B8\n"
	"	movs r2, 0\n"
	"	ldrsh r1, [r0, r2]\n"
	"	add r0, sp, 0x8\n"
	"	bl IntToFixedPoint\n"
	"	ldr r2, [sp, 0x8]\n"
	"	ldr r0, [sp, 0x40]\n"
	"	adds r1, r4, 0\n"
	"	bl FixedPoint_Subtract\n"
	"	ldr r0, [sp, 0xC]\n"
	"	ldr r3, [sp, 0x3C]\n"
	"	str r0, [r3]\n"
	"	mov r0, r8\n"
	"	ldrh r1, [r0, 0x2]\n"
	"	ldr r0, _080539BC\n"
	"	cmp r1, r0\n"
	"	bne _080539C4\n"
	"	ldr r0, _080539C0\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	b _080539D0\n"
	"	.align 2, 0\n"
	"_080539B4: .4byte gAdjacentTileOffsets\n"
	"_080539B8: .4byte gUnknown_80F5006\n"
	"_080539BC: .4byte 0x00000163\n"
	"_080539C0: .4byte gUnknown_80FDDA8\n"
	"_080539C4:\n"
	"	ldr r0, _080539D8\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"_080539D0:\n"
	"	str r5, [sp, 0x20]\n"
	"	ldr r5, [sp, 0x38]\n"
	"	b _080539E8\n"
	"	.align 2, 0\n"
	"_080539D8: .4byte gUnknown_80FDD20\n"
	"_080539DC:\n"
	"	ldr r1, [sp, 0x34]\n"
	"	adds r1, 0x1\n"
	"	str r1, [sp, 0x34]\n"
	"	cmp r1, 0x7\n"
	"	bgt _080539E8\n"
	"	b _080538DA\n"
	"_080539E8:\n"
	"	ldr r2, [sp, 0x34]\n"
	"	cmp r2, 0x8\n"
	"	bne _08053A1C\n"
	"	mov r3, r8\n"
	"	ldrh r1, [r3, 0x2]\n"
	"	ldr r0, _08053A08\n"
	"	cmp r1, r0\n"
	"	bne _08053A10\n"
	"	ldr r0, _08053A0C\n"
	"_080539FA:\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	b _08053A1C\n"
	"	.align 2, 0\n"
	"_08053A08: .4byte 0x00000163\n"
	"_08053A0C: .4byte gUnknown_80FDDAC\n"
	"_08053A10:\n"
	"	ldr r0, _08053AD8\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"_08053A1C:\n"
	"	ldr r1, _08053ADC\n"
	"	ldr r0, [r1]\n"
	"	adds r0, 0x1\n"
	"	str r0, [r1]\n"
	"	ldr r1, _08053AE0\n"
	"	ldr r0, [r1]\n"
	"	adds r0, 0x1\n"
	"	str r0, [r1]\n"
	"	ldr r0, [r5, 0x70]\n"
	"	str r0, [sp, 0x24]\n"
	"	movs r6, 0xAD\n"
	"	lsls r6, 1\n"
	"	adds r1, r0, r6\n"
	"	movs r0, 0\n"
	"	strb r0, [r1]\n"
	"	ldr r1, [sp, 0x24]\n"
	"	ldrb r0, [r1, 0x6]\n"
	"	cmp r0, 0\n"
	"	beq _08053A4C\n"
	"	movs r2, 0xB6\n"
	"	lsls r2, 1\n"
	"	adds r1, r2\n"
	"	ldr r0, [r7, 0x4]\n"
	"	str r0, [r1]\n"
	"_08053A4C:\n"
	"	adds r0, r5, 0\n"
	"	bl sub_806A1E8\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TrySendImmobilizeSleepEndMsg\n"
	"	movs r4, 0\n"
	"	adds r0, r7, 0\n"
	"	mov r1, r8\n"
	"	bl MoveMatchesChargingStatus\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	bne _08053A7E\n"
	"	mov r3, r8\n"
	"	ldrh r1, [r3, 0x2]\n"
	"	adds r0, r7, 0\n"
	"	bl sub_805755C\n"
	"	lsls r0, 24\n"
	"	lsrs r0, 24\n"
	"	negs r1, r0\n"
	"	orrs r1, r0\n"
	"	lsrs r4, r1, 31\n"
	"_08053A7E:\n"
	"	ldr r0, [sp, 0x2C]\n"
	"	cmp r0, 0\n"
	"	beq _08053A86\n"
	"	b _08053BAE\n"
	"_08053A86:\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0xC4\n"
	"	ldrb r0, [r0]\n"
	"	cmp r0, 0x5\n"
	"	bne _08053AE8\n"
	"	ldr r0, [sp, 0x18]\n"
	"	bl IsReflectedByMagicCoat\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053B5C\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl sub_8055988\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053B5C\n"
	"	ldr r0, _08053AE4\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	adds r0, r5, 0\n"
	"	bl sub_8041B48\n"
	"	adds r0, r5, 0\n"
	"	adds r1, r7, 0\n"
	"	bl sub_80559DC\n"
	"	adds r5, r7, 0\n"
	"	ldr r1, [r7, 0x70]\n"
	"	str r1, [sp, 0x24]\n"
	"	adds r0, r1, r6\n"
	"	add r2, sp, 0x2C\n"
	"	ldrb r2, [r2]\n"
	"	strb r2, [r0]\n"
	"	movs r3, 0x1\n"
	"	str r3, [sp, 0x30]\n"
	"	b _08053B5C\n"
	"	.align 2, 0\n"
	"_08053AD8: .4byte gUnknown_80FDD48\n"
	"_08053ADC: .4byte gUnknown_202F208\n"
	"_08053AE0: .4byte gUnknown_202F20C\n"
	"_08053AE4: .4byte gUnknown_80FC52C\n"
	"_08053AE8:\n"
	"	cmp r0, 0xB\n"
	"	bne _08053B5C\n"
	"	adds r0, r7, 0\n"
	"	mov r1, r8\n"
	"	movs r2, 0\n"
	"	bl GetMoveTargetAndRangeForPokemon\n"
	"	lsls r0, 16\n"
	"	asrs r1, r0, 16\n"
	"	ldr r0, _08053C88\n"
	"	ldr r2, [sp, 0x18]\n"
	"	cmp r2, r0\n"
	"	beq _08053B5C\n"
	"	adds r0, 0x32\n"
	"	cmp r2, r0\n"
	"	beq _08053B5C\n"
	"	cmp r4, 0\n"
	"	bne _08053B5C\n"
	"	movs r0, 0xF\n"
	"	ands r0, r1\n"
	"	cmp r0, 0\n"
	"	beq _08053B20\n"
	"	cmp r0, 0x4\n"
	"	beq _08053B20\n"
	"	cmp r0, 0x5\n"
	"	beq _08053B20\n"
	"	cmp r0, 0x2\n"
	"	bne _08053B5C\n"
	"_08053B20:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl sub_8055988\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053B5C\n"
	"	ldr r0, _08053C8C\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	adds r0, r5, 0\n"
	"	bl sub_8041BA8\n"
	"	adds r0, r5, 0\n"
	"	adds r1, r7, 0\n"
	"	bl sub_80559DC\n"
	"	adds r5, r7, 0\n"
	"	ldr r3, [r7, 0x70]\n"
	"	str r3, [sp, 0x24]\n"
	"	movs r0, 0xAD\n"
	"	lsls r0, 1\n"
	"	adds r1, r3, r0\n"
	"	movs r0, 0\n"
	"	strb r0, [r1]\n"
	"	movs r1, 0x1\n"
	"	str r1, [sp, 0x30]\n"
	"_08053B5C:\n"
	"	ldr r2, [sp, 0x2C]\n"
	"	cmp r2, 0\n"
	"	bne _08053BAE\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0xC4\n"
	"	ldrb r0, [r0]\n"
	"	cmp r0, 0x7\n"
	"	bne _08053BAE\n"
	"	adds r0, r7, 0\n"
	"	mov r1, r8\n"
	"	movs r2, 0\n"
	"	bl GetMoveTargetAndRangeForPokemon\n"
	"	lsls r0, 16\n"
	"	movs r1, 0xF0\n"
	"	lsls r1, 12\n"
	"	ands r1, r0\n"
	"	asrs r1, 16\n"
	"	cmp r1, 0\n"
	"	beq _08053B90\n"
	"	cmp r1, 0x4\n"
	"	beq _08053B90\n"
	"	cmp r1, 0x5\n"
	"	beq _08053B90\n"
	"	cmp r1, 0x2\n"
	"	bne _08053BAE\n"
	"_08053B90:\n"
	"	cmp r4, 0\n"
	"	bne _08053BAE\n"
	"	ldr r0, _08053C90\n"
	"	adds r1, r5, 0\n"
	"	movs r2, 0\n"
	"	bl SetMessageArgument\n"
	"	ldr r0, _08053C94\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	movs r3, 0\n"
	"	str r3, [sp, 0x28]\n"
	"_08053BAE:\n"
	"	adds r0, r5, 0\n"
	"	mov r1, r8\n"
	"	bl sub_80571F0\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053BC0\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x28]\n"
	"_08053BC0:\n"
	"	ldr r1, [sp, 0x28]\n"
	"	cmp r1, 0\n"
	"	beq _08053C4A\n"
	"	adds r0, r5, 0\n"
	"	movs r1, 0x3C\n"
	"	bl HasAbility\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053BFA\n"
	"	mov r0, r8\n"
	"	bl IsSoundMove\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053BFA\n"
	"	ldr r0, _08053C90\n"
	"	adds r1, r5, 0\n"
	"	movs r2, 0\n"
	"	bl SetMessageArgument\n"
	"	ldr r0, _08053C98\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	movs r2, 0\n"
	"	str r2, [sp, 0x28]\n"
	"_08053BFA:\n"
	"	ldr r3, [sp, 0x28]\n"
	"	cmp r3, 0\n"
	"	beq _08053C4A\n"
	"	movs r0, 0\n"
	"	ldr r1, [sp, 0x30]\n"
	"	cmp r1, 0\n"
	"	bne _08053C0A\n"
	"	movs r0, 0x1\n"
	"_08053C0A:\n"
	"	adds r2, r0, 0\n"
	"	mov r3, r8\n"
	"	ldrh r1, [r3, 0x2]\n"
	"	cmp r1, 0x68\n"
	"	beq _08053C20\n"
	"	ldr r0, _08053C9C\n"
	"	cmp r1, r0\n"
	"	beq _08053C20\n"
	"	subs r0, 0x4\n"
	"	cmp r1, r0\n"
	"	bne _08053C22\n"
	"_08053C20:\n"
	"	movs r2, 0\n"
	"_08053C22:\n"
	"	str r2, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	movs r3, 0\n"
	"	bl sub_8056B34\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	bne _08053C3A\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x28]\n"
	"_08053C3A:\n"
	"	ldr r1, [sp, 0x28]\n"
	"	cmp r1, 0\n"
	"	beq _08053C4A\n"
	"	ldr r2, [sp, 0x2C]\n"
	"	cmp r2, 0\n"
	"	beq _08053C4A\n"
	"	movs r3, 0\n"
	"	str r3, [sp, 0x28]\n"
	"_08053C4A:\n"
	"	adds r0, r5, 0\n"
	"	bl sub_8045888\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053C6A\n"
	"	movs r0, 0x4\n"
	"	movs r1, 0x4A\n"
	"	bl sub_803E708\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	movs r3, 0\n"
	"	bl sub_8041168\n"
	"_08053C6A:\n"
	"	ldr r0, [sp, 0x28]\n"
	"	cmp r0, 0\n"
	"	beq _08053C72\n"
	"	b _08053D72\n"
	"_08053C72:\n"
	"	ldr r0, [r7, 0x70]\n"
	"	ldrb r0, [r0, 0x7]\n"
	"	cmp r0, 0\n"
	"	beq _08053CA0\n"
	"	movs r1, 0xAB\n"
	"	lsls r1, 1\n"
	"	adds r0, r7, 0\n"
	"	bl sub_80421C0\n"
	"	b _08053CA8\n"
	"	.align 2, 0\n"
	"_08053C88: .4byte 0x00000163\n"
	"_08053C8C: .4byte gUnknown_80FC558\n"
	"_08053C90: .4byte gUnknown_202DFE8\n"
	"_08053C94: .4byte gUnknown_80FC574\n"
	"_08053C98: .4byte gUnknown_8100524\n"
	"_08053C9C: .4byte 0x00000131\n"
	"_08053CA0:\n"
	"	ldr r1, _08053CC4\n"
	"	adds r0, r7, 0\n"
	"	bl sub_80421C0\n"
	"_08053CA8:\n"
	"	ldr r0, _08053CC8\n"
	"	ldr r1, [r5, 0x70]\n"
	"	movs r2, 0\n"
	"	bl SetMessageArgument_2\n"
	"	cmp r7, r5\n"
	"	bne _08053CD0\n"
	"	ldr r0, _08053CCC\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r7, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	b _08053D10\n"
	"	.align 2, 0\n"
	"_08053CC4: .4byte 0x00000157\n"
	"_08053CC8: .4byte gUnknown_202DFE8\n"
	"_08053CCC: .4byte gUnknown_80F9380\n"
	"_08053CD0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	movs r2, 0x1\n"
	"	movs r3, 0\n"
	"	bl GetTreatmentBetweenMonsters\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	bne _08053CEC\n"
	"	ldr r0, _08053CE8\n"
	"	b _08053CF4\n"
	"	.align 2, 0\n"
	"_08053CE8: .4byte gUnknown_80F9384\n"
	"_08053CEC:\n"
	"	ldr r1, [sp, 0x2C]\n"
	"	cmp r1, 0\n"
	"	beq _08053D04\n"
	"	ldr r0, _08053D00\n"
	"_08053CF4:\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"	b _08053D10\n"
	"	.align 2, 0\n"
	"_08053D00: .4byte gUnknown_80F93A4\n"
	"_08053D04:\n"
	"	ldr r0, _08053D48\n"
	"	ldr r2, [r0]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl TryDisplayDungeonLoggableMessage3\n"
	"_08053D10:\n"
	"	adds r0, r5, 0\n"
	"	bl sub_8045888\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053D2A\n"
	"	ldr r0, _08053D4C\n"
	"	movs r3, 0x1\n"
	"	negs r3, r3\n"
	"	adds r1, r5, 0\n"
	"	movs r2, 0x1\n"
	"	bl sub_803ED30\n"
	"_08053D2A:\n"
	"	ldr r2, [sp, 0x18]\n"
	"	cmp r2, 0xCC\n"
	"	beq _08053D50\n"
	"	cmp r2, 0xCE\n"
	"	bne _08053D60\n"
	"	movs r0, 0x1\n"
	"	str r0, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059FC8\n"
	"	b _08053D60\n"
	"	.align 2, 0\n"
	"_08053D48: .4byte gUnknown_80F9364\n"
	"_08053D4C: .4byte 0x0000270f\n"
	"_08053D50:\n"
	"	movs r0, 0x1\n"
	"	str r0, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059E54\n"
	"_08053D60:\n"
	"	bl sub_8044B28\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053D6E\n"
	"	bl _080555A2\n"
	"_08053D6E:\n"
	"	bl _08055568\n"
	"_08053D72:\n"
	"	ldr r0, [sp, 0x24]\n"
	"	adds r0, 0xFB\n"
	"	ldrb r3, [r0]\n"
	"	mov r10, r3\n"
	"	ldr r2, [sp, 0x24]\n"
	"	ldrb r1, [r2, 0x6]\n"
	"	adds r6, r0, 0\n"
	"	cmp r1, 0\n"
	"	beq _08053DA8\n"
	"	mov r3, r8\n"
	"	ldrh r1, [r3, 0x2]\n"
	"	ldr r0, _08053E88\n"
	"	cmp r1, r0\n"
	"	beq _08053D9E\n"
	"	mov r0, r9\n"
	"	cmp r0, 0\n"
	"	bne _08053D9E\n"
	"	mov r1, r10\n"
	"	cmp r1, 0\n"
	"	bne _08053D9E\n"
	"	movs r0, 0x1\n"
	"	strb r0, [r6]\n"
	"_08053D9E:\n"
	"	ldr r2, [sp, 0x68]\n"
	"	cmp r2, 0x1\n"
	"	bne _08053DA8\n"
	"	movs r0, 0x2\n"
	"	strb r0, [r6]\n"
	"_08053DA8:\n"
	"	ldr r3, [sp, 0x24]\n"
	"	movs r0, 0xB2\n"
	"	lsls r0, 1\n"
	"	adds r4, r3, r0\n"
	"	ldrb r0, [r4]\n"
	"	cmp r0, 0xFF\n"
	"	bne _08053DCE\n"
	"	adds r0, r5, 0\n"
	"	movs r1, 0xE3\n"
	"	bl sub_80717A4\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053DCE\n"
	"	adds r0, r5, 0x4\n"
	"	adds r1, r7, 0x4\n"
	"	bl GetDirectionTowardsPosition\n"
	"	strb r0, [r4]\n"
	"_08053DCE:\n"
	"	ldr r1, [sp, 0x24]\n"
	"	ldr r2, _08053E8C\n"
	"	adds r4, r1, r2\n"
	"	ldrb r0, [r4]\n"
	"	cmp r0, 0xFF\n"
	"	bne _08053DF2\n"
	"	adds r0, r5, 0\n"
	"	movs r1, 0x19\n"
	"	bl sub_80717A4\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053DF2\n"
	"	adds r0, r5, 0x4\n"
	"	adds r1, r7, 0x4\n"
	"	bl GetDirectionTowardsPosition\n"
	"	strb r0, [r4]\n"
	"_08053DF2:\n"
	"	adds r0, r5, 0\n"
	"	movs r1, 0x39\n"
	"	bl HasAbility\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08053E4A\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	movs r2, 0x1\n"
	"	movs r3, 0\n"
	"	bl GetTreatmentBetweenMonsters\n"
	"	lsls r0, 24\n"
	"	lsrs r0, 24\n"
	"	cmp r0, 0x1\n"
	"	bne _08053E4A\n"
	"	mov r3, r8\n"
	"	ldrh r1, [r3, 0x2]\n"
	"	ldr r0, _08053E88\n"
	"	cmp r1, r0\n"
	"	beq _08053E4A\n"
	"	subs r0, 0x3\n"
	"	cmp r1, r0\n"
	"	beq _08053E4A\n"
	"	mov r0, r9\n"
	"	cmp r0, 0\n"
	"	bne _08053E4A\n"
	"	ldrb r0, [r3, 0x4]\n"
	"	cmp r0, 0\n"
	"	beq _08053E4A\n"
	"	ldrb r1, [r3, 0x1]\n"
	"	movs r4, 0x10\n"
	"	movs r0, 0x10\n"
	"	ands r0, r1\n"
	"	cmp r0, 0\n"
	"	bne _08053E42\n"
	"	adds r0, r7, 0\n"
	"	bl sub_8042950\n"
	"_08053E42:\n"
	"	mov r1, r8\n"
	"	ldrb r0, [r1, 0x1]\n"
	"	orrs r0, r4\n"
	"	strb r0, [r1, 0x1]\n"
	"_08053E4A:\n"
	"	adds r0, r7, 0\n"
	"	mov r1, r8\n"
	"	movs r2, 0\n"
	"	bl GetMoveTargetAndRangeForPokemon\n"
	"	movs r1, 0xF\n"
	"	ands r1, r0\n"
	"	cmp r1, 0\n"
	"	bne _08053E64\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	bl SetShopkeeperAggression\n"
	"_08053E64:\n"
	"	ldr r2, [sp, 0x24]\n"
	"	movs r3, 0xAC\n"
	"	lsls r3, 1\n"
	"	adds r0, r2, r3\n"
	"	movs r1, 0x1\n"
	"	strb r1, [r0]\n"
	"	movs r0, 0xCE\n"
	"	lsls r0, 1\n"
	"	ldr r1, [sp, 0x18]\n"
	"	cmp r1, r0\n"
	"	bls _08053E7E\n"
	"	bl _080554C0\n"
	"_08053E7E:\n"
	"	lsls r0, r1, 2\n"
	"	ldr r1, _08053E90\n"
	"	adds r0, r1\n"
	"	ldr r0, [r0]\n"
	"	mov pc, r0\n"
	"	.align 2, 0\n"
	"_08053E88: .4byte 0x00000163\n"
	"_08053E8C: .4byte 0x00000165\n"
	"_08053E90: .4byte _08053E94\n"
	"	.align 2, 0\n"
	"_08053E94:\n"
	"	.4byte _08054520\n"
	"	.4byte _08054DB8\n"
	"	.4byte _08054C18\n"
	"	.4byte _08054888\n"
	"	.4byte _08054878\n"
	"	.4byte _08054D80\n"
	"	.4byte _08054D8E\n"
	"	.4byte _08054FB0\n"
	"	.4byte _08054FE8\n"
	"	.4byte _08054508\n"
	"	.4byte _08054FF6\n"
	"	.4byte _08055270\n"
	"	.4byte _08055190\n"
	"	.4byte _080548C8\n"
	"	.4byte _080552B6\n"
	"	.4byte _08054E1A\n"
	"	.4byte _0805527E\n"
	"	.4byte _080551F2\n"
	"	.4byte _08054508\n"
	"	.4byte _080549C8\n"
	"	.4byte _08054EEC\n"
	"	.4byte _08054968\n"
	"	.4byte _08054EDE\n"
	"	.4byte _0805528C\n"
	"	.4byte _08054B18\n"
	"	.4byte _08055422\n"
	"	.4byte _08054E1A\n"
	"	.4byte _08054AB8\n"
	"	.4byte _08054508\n"
	"	.4byte _0805529A\n"
	"	.4byte _080547A8\n"
	"	.4byte _08055200\n"
	"	.4byte _0805460A\n"
	"	.4byte _08054948\n"
	"	.4byte _08054878\n"
	"	.4byte _0805519E\n"
	"	.4byte _080545AE\n"
	"	.4byte _0805514A\n"
	"	.4byte _08054CD4\n"
	"	.4byte _08054508\n"
	"	.4byte _08055396\n"
	"	.4byte _08054EB4\n"
	"	.4byte _08054A68\n"
	"	.4byte _08054C28\n"
	"	.4byte _08054A58\n"
	"	.4byte _08054E8A\n"
	"	.4byte _080547A8\n"
	"	.4byte _08054DD4\n"
	"	.4byte _080553DC\n"
	"	.4byte _0805504A\n"
	"	.4byte _080554A0\n"
	"	.4byte _08054CD4\n"
	"	.4byte _0805455E\n"
	"	.4byte _0805456E\n"
	"	.4byte _080552D2\n"
	"	.4byte _080549B8\n"
	"	.4byte _08055004\n"
	"	.4byte _0805453E\n"
	"	.4byte _08054F94\n"
	"	.4byte _08054818\n"
	"	.4byte _08054D56\n"
	"	.4byte _08054CE2\n"
	"	.4byte _080547B8\n"
	"	.4byte _08054788\n"
	"	.4byte _08054868\n"
	"	.4byte _08054868\n"
	"	.4byte _08054F16\n"
	"	.4byte _08055112\n"
	"	.4byte _080545AE\n"
	"	.4byte _080545FA\n"
	"	.4byte _08054F94\n"
	"	.4byte _080546D8\n"
	"	.4byte _08054F86\n"
	"	.4byte _08054928\n"
	"	.4byte _0805459E\n"
	"	.4byte _08054D64\n"
	"	.4byte _08054AD8\n"
	"	.4byte _080550DA\n"
	"	.4byte _08054E52\n"
	"	.4byte _08054878\n"
	"	.4byte _08054AD8\n"
	"	.4byte _080545AE\n"
	"	.4byte _080546E8\n"
	"	.4byte _08054ED0\n"
	"	.4byte _08054878\n"
	"	.4byte _080550CC\n"
	"	.4byte _0805462A\n"
	"	.4byte _080545AE\n"
	"	.4byte _08054E28\n"
	"	.4byte _0805462A\n"
	"	.4byte _080545AE\n"
	"	.4byte _08054B78\n"
	"	.4byte _08055120\n"
	"	.4byte _080546E8\n"
	"	.4byte _08054C48\n"
	"	.4byte _08054CC6\n"
	"	.4byte _080551D6\n"
	"	.4byte _08054928\n"
	"	.4byte _08054FA2\n"
	"	.4byte _08054A38\n"
	"	.4byte _08054B58\n"
	"	.4byte _0805457E\n"
	"	.4byte _08055090\n"
	"	.4byte _080547E8\n"
	"	.4byte _08055238\n"
	"	.4byte _08054C18\n"
	"	.4byte _08054A88\n"
	"	.4byte _080546F8\n"
	"	.4byte _08054DF0\n"
	"	.4byte _0805464A\n"
	"	.4byte _08054A78\n"
	"	.4byte _08054878\n"
	"	.4byte _08054B98\n"
	"	.4byte _0805512E\n"
	"	.4byte _080546F8\n"
	"	.4byte _08055414\n"
	"	.4byte _08054AF8\n"
	"	.4byte _08054C78\n"
	"	.4byte _0805452E\n"
	"	.4byte _0805536C\n"
	"	.4byte _08054768\n"
	"	.4byte _080550DA\n"
	"	.4byte _08054DC6\n"
	"	.4byte _080550E8\n"
	"	.4byte _08054858\n"
	"	.4byte _080545FA\n"
	"	.4byte _08054508\n"
	"	.4byte _080547B8\n"
	"	.4byte _08055104\n"
	"	.4byte _08054898\n"
	"	.4byte _08054BF8\n"
	"	.4byte _080545CA\n"
	"	.4byte _08054508\n"
	"	.4byte _08054778\n"
	"	.4byte _08054BE8\n"
	"	.4byte _08054B08\n"
	"	.4byte _08054508\n"
	"	.4byte _080553B2\n"
	"	.4byte _08055388\n"
	"	.4byte _08054798\n"
	"	.4byte _08054AE8\n"
	"	.4byte _08054BD8\n"
	"	.4byte _08054EA6\n"
	"	.4byte _080545FA\n"
	"	.4byte _08054768\n"
	"	.4byte _08054508\n"
	"	.4byte _08054EA6\n"
	"	.4byte _08054738\n"
	"	.4byte _080549F8\n"
	"	.4byte _08054748\n"
	"	.4byte _080545DA\n"
	"	.4byte _08054B48\n"
	"	.4byte _08054838\n"
	"	.4byte _08054FBE\n"
	"	.4byte _08054508\n"
	"	.4byte _080550F6\n"
	"	.4byte _08054FDA\n"
	"	.4byte _0805456E\n"
	"	.4byte _08054508\n"
	"	.4byte _08054A48\n"
	"	.4byte _08055166\n"
	"	.4byte _08054508\n"
	"	.4byte _080546C8\n"
	"	.4byte _08054508\n"
	"	.4byte _08054B38\n"
	"	.4byte _08054C38\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054988\n"
	"	.4byte _08054AC8\n"
	"	.4byte _080548C8\n"
	"	.4byte _080550BE\n"
	"	.4byte _08054C58\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _080548B8\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _080549D8\n"
	"	.4byte _08054508\n"
	"	.4byte _080553C0\n"
	"	.4byte _08055468\n"
	"	.4byte _08055246\n"
	"	.4byte _08054A28\n"
	"	.4byte _08054F5C\n"
	"	.4byte _08054758\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _080548C8\n"
	"	.4byte _080548E8\n"
	"	.4byte _08054908\n"
	"	.4byte _080548A8\n"
	"	.4byte _080549B8\n"
	"	.4byte _080548D8\n"
	"	.4byte _08054EC2\n"
	"	.4byte _08054BA8\n"
	"	.4byte _080548D8\n"
	"	.4byte _0805463A\n"
	"	.4byte _08054508\n"
	"	.4byte _08054A28\n"
	"	.4byte _08054AF8\n"
	"	.4byte _0805509E\n"
	"	.4byte _08054FCC\n"
	"	.4byte _08054D28\n"
	"	.4byte _080547D8\n"
	"	.4byte _08054508\n"
	"	.4byte _08054C98\n"
	"	.4byte _08054B28\n"
	"	.4byte _08054508\n"
	"	.4byte _08054DAA\n"
	"	.4byte _08054E98\n"
	"	.4byte _08054CB8\n"
	"	.4byte _08054A08\n"
	"	.4byte _08054AC8\n"
	"	.4byte _08054A98\n"
	"	.4byte _08054C78\n"
	"	.4byte _0805461A\n"
	"	.4byte _080553A4\n"
	"	.4byte _08054788\n"
	"	.4byte _08054508\n"
	"	.4byte _0805520E\n"
	"	.4byte _08054DC6\n"
	"	.4byte _08054E7C\n"
	"	.4byte _08054828\n"
	"	.4byte _08054D0C\n"
	"	.4byte _0805521C\n"
	"	.4byte _08055066\n"
	"	.4byte _0805456E\n"
	"	.4byte _08054878\n"
	"	.4byte _08054C68\n"
	"	.4byte _08054DE2\n"
	"	.4byte _080546F8\n"
	"	.4byte _08054768\n"
	"	.4byte _08055182\n"
	"	.4byte _08054D1A\n"
	"	.4byte _0805458E\n"
	"	.4byte _0805458E\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _0805458E\n"
	"	.4byte _08054918\n"
	"	.4byte _0805469C\n"
	"	.4byte _08055174\n"
	"	.4byte _08054938\n"
	"	.4byte _080545DA\n"
	"	.4byte _08054508\n"
	"	.4byte _08055012\n"
	"	.4byte _08054508\n"
	"	.4byte _080545AE\n"
	"	.4byte _08054F24\n"
	"	.4byte _08054B78\n"
	"	.4byte _080552E0\n"
	"	.4byte _080546D8\n"
	"	.4byte _08055074\n"
	"	.4byte _08055254\n"
	"	.4byte _08054A28\n"
	"	.4byte _08054C08\n"
	"	.4byte _08054508\n"
	"	.4byte _08054778\n"
	"	.4byte _0805456E\n"
	"	.4byte _0805535E\n"
	"	.4byte _080547C8\n"
	"	.4byte _080549A8\n"
	"	.4byte _08055326\n"
	"	.4byte _08054AA8\n"
	"	.4byte _08054958\n"
	"	.4byte _0805530A\n"
	"	.4byte _0805457E\n"
	"	.4byte _08054788\n"
	"	.4byte _08054D3A\n"
	"	.4byte _08054EA6\n"
	"	.4byte _080548C8\n"
	"	.4byte _08054728\n"
	"	.4byte _080547F8\n"
	"	.4byte _08054BB8\n"
	"	.4byte _0805513C\n"
	"	.4byte _0805463A\n"
	"	.4byte _0805463A\n"
	"	.4byte _080548F8\n"
	"	.4byte _080552A8\n"
	"	.4byte _080546B8\n"
	"	.4byte _08054958\n"
	"	.4byte _08054508\n"
	"	.4byte _080553F8\n"
	"	.4byte _08054CB8\n"
	"	.4byte _08054978\n"
	"	.4byte _08054778\n"
	"	.4byte _08054508\n"
	"	.4byte _080545FA\n"
	"	.4byte _0805456E\n"
	"	.4byte _080551C8\n"
	"	.4byte _08054B88\n"
	"	.4byte _08054E0C\n"
	"	.4byte _08054E60\n"
	"	.4byte _08054508\n"
	"	.4byte _08054D72\n"
	"	.4byte _08054928\n"
	"	.4byte _08054508\n"
	"	.4byte _080550B0\n"
	"	.4byte _08054A18\n"
	"	.4byte _08054788\n"
	"	.4byte _08055090\n"
	"	.4byte _080550B0\n"
	"	.4byte _08054508\n"
	"	.4byte _08054DAA\n"
	"	.4byte _08054508\n"
	"	.4byte _08054708\n"
	"	.4byte _080547C8\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _080551E4\n"
	"	.4byte _08054EFA\n"
	"	.4byte _080552D2\n"
	"	.4byte _080551BA\n"
	"	.4byte _08055074\n"
	"	.4byte _08054C38\n"
	"	.4byte _080549E8\n"
	"	.4byte _08054AD8\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054D48\n"
	"	.4byte _08054680\n"
	"	.4byte _08054808\n"
	"	.4byte _08055492\n"
	"	.4byte _08055406\n"
	"	.4byte _08054DFE\n"
	"	.4byte _0805544C\n"
	"	.4byte _08054F32\n"
	"	.4byte _08054664\n"
	"	.4byte _080549B8\n"
	"	.4byte _080553EA\n"
	"	.4byte _08054718\n"
	"	.4byte _080545AE\n"
	"	.4byte _08055430\n"
	"	.4byte _08054BC8\n"
	"	.4byte _08054E1A\n"
	"	.4byte _08054CE2\n"
	"	.4byte _08054848\n"
	"	.4byte _08054768\n"
	"	.4byte _08054998\n"
	"	.4byte _0805457E\n"
	"	.4byte _0805457E\n"
	"	.4byte _08054508\n"
	"	.4byte _08054508\n"
	"	.4byte _08054E6E\n"
	"	.4byte _08054FA2\n"
	"	.4byte _08054508\n"
	"	.4byte _08054A88\n"
	"	.4byte _0805454E\n"
	"	.4byte _08054508\n"
	"	.4byte _08054AF8\n"
	"	.4byte _08054512\n"
	"	.4byte _080554C0\n"
	"	.4byte _08054CF0\n"
	"	.4byte _080554C0\n"
	"	.4byte _080554C0\n"
	"	.4byte _08054508\n"
	"	.4byte _0805529A\n"
	"	.4byte _08054508\n"
	"	.4byte _08055158\n"
	"	.4byte _08054CA8\n"
	"	.4byte _08055318\n"
	"	.4byte _08054508\n"
	"	.4byte _08054F24\n"
	"	.4byte _08054958\n"
	"	.4byte _08054F5C\n"
	"	.4byte _080552EE\n"
	"	.4byte _08054B68\n"
	"	.4byte _08054CC6\n"
	"	.4byte _08054F40\n"
	"	.4byte _08055058\n"
	"	.4byte _080552FC\n"
	"	.4byte _08055476\n"
	"	.4byte _08055484\n"
	"	.4byte _080553CE\n"
	"	.4byte _08055326\n"
	"	.4byte _08055090\n"
	"	.4byte _08054E44\n"
	"	.4byte _080548C8\n"
	"	.4byte _08054F08\n"
	"	.4byte _0805543E\n"
	"	.4byte _08055350\n"
	"	.4byte _08054C88\n"
	"	.4byte _08054E36\n"
	"	.4byte _08054F6A\n"
	"	.4byte _08055020\n"
	"	.4byte _08055334\n"
	"	.4byte _080551AC\n"
	"	.4byte _080545EA\n"
	"	.4byte _0805545A\n"
	"	.4byte _08054D9C\n"
	"	.4byte _08055342\n"
	"	.4byte _08055082\n"
	"	.4byte _080554AE\n"
	"	.4byte _08055262\n"
	"	.4byte _0805522A\n"
	"	.4byte _08054F4E\n"
	"	.4byte _08054CFE\n"
	"	.4byte _080554C0\n"
	"	.4byte _0805537A\n"
	"	.4byte _080554C0\n"
	"	.4byte _080554C0\n"
	"	.4byte _080554A0\n"
	"	.4byte _080552C4\n"
	"	.4byte _080554C0\n"
	"	.4byte _08054F78\n"
	"	.4byte _0805502E\n"
	"	.4byte _080554C0\n"
	"	.4byte _0805503C\n"
	"_08054508:\n"
	"	movs r3, 0x80\n"
	"	lsls r3, 1\n"
	"	mov r2, r9\n"
	"	str r2, [sp]\n"
	"	b _080545B6\n"
	"_08054512:\n"
	"	mov r3, r9\n"
	"	str r3, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	movs r3, 0x80\n"
	"	b _080545BC\n"
	"_08054520:\n"
	"	mov r0, r9\n"
	"	str r0, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	movs r3, 0\n"
	"	b _080545BC\n"
	"_0805452E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058F04\n"
	"	bl _080554BA\n"
	"_0805453E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058270\n"
	"	bl _080554BA\n"
	"_0805454E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B968\n"
	"	bl _080554BA\n"
	"_0805455E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805816C\n"
	"	bl _080554BA\n"
	"_0805456E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80581D0\n"
	"	bl _080554BA\n"
	"_0805457E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058B3C\n"
	"	bl _080554BA\n"
	"_0805458E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A568\n"
	"	bl _080554BA\n"
	"_0805459E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl FocusEnergyMoveAction\n"
	"	bl _080554BA\n"
	"_080545AE:\n"
	"	movs r3, 0x80\n"
	"	lsls r3, 1\n"
	"	mov r1, r9\n"
	"	str r1, [sp]\n"
	"_080545B6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"_080545BC:\n"
	"	bl sub_8055640\n"
	"	negs r1, r0\n"
	"	orrs r1, r0\n"
	"	lsrs r4, r1, 31\n"
	"	bl _080554C2\n"
	"_080545CA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80590D4\n"
	"	bl _080554BA\n"
	"_080545DA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80595EC\n"
	"	bl _080554BA\n"
	"_080545EA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C138\n"
	"	bl _080554BA\n"
	"_080545FA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B17C\n"
	"	bl _080554BA\n"
	"_0805460A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl WhirlpoolMoveAction\n"
	"	bl _080554BA\n"
	"_0805461A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SurfMoveAction\n"
	"	bl _080554BA\n"
	"_0805462A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805889C\n"
	"	bl _080554BA\n"
	"_0805463A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059E0C\n"
	"	bl _080554BA\n"
	"_0805464A:\n"
	"	ldr r0, _08054660\n"
	"	ldr r3, [r0]\n"
	"	mov r2, r9\n"
	"	str r2, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	bl sub_8058C98\n"
	"	bl _080554BA\n"
	"	.align 2, 0\n"
	"_08054660: .4byte gUnknown_8106A50\n"
	"_08054664:\n"
	"	ldr r0, _0805467C\n"
	"	ldr r3, [r0]\n"
	"	mov r0, r9\n"
	"	str r0, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	bl sub_8058C98\n"
	"	bl _080554BA\n"
	"	.align 2, 0\n"
	"_0805467C: .4byte gUnknown_8106A4C\n"
	"_08054680:\n"
	"	ldr r0, _08054698\n"
	"	ldr r3, [r0]\n"
	"	mov r1, r9\n"
	"	str r1, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	bl sub_805B3FC\n"
	"	bl _080554BA\n"
	"	.align 2, 0\n"
	"_08054698: .4byte gUnknown_8106A4C\n"
	"_0805469C:\n"
	"	ldr r0, _080546B4\n"
	"	ldr r3, [r0]\n"
	"	mov r2, r9\n"
	"	str r2, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	bl sub_805A5E8\n"
	"	bl _080554BA\n"
	"	.align 2, 0\n"
	"_080546B4: .4byte gUnknown_8106A4C\n"
	"_080546B8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B074\n"
	"	bl _080554BA\n"
	"_080546C8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059928\n"
	"	bl _080554BA\n"
	"_080546D8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058580\n"
	"	bl _080554BA\n"
	"_080546E8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058930\n"
	"	bl _080554BA\n"
	"_080546F8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058C00\n"
	"	bl _080554BA\n"
	"_08054708:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B324\n"
	"	bl _080554BA\n"
	"_08054718:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B910\n"
	"	bl _080554BA\n"
	"_08054728:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AE74\n"
	"	bl _080554BA\n"
	"_08054738:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059540\n"
	"	bl _080554BA\n"
	"_08054748:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80595A0\n"
	"	bl _080554BA\n"
	"_08054758:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059D00\n"
	"	bl _080554BA\n"
	"_08054768:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058FBC\n"
	"	bl _080554BA\n"
	"_08054778:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059190\n"
	"	bl _080554BA\n"
	"_08054788:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058430\n"
	"	bl _080554BA\n"
	"_08054798:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059424\n"
	"	bl _080554BA\n"
	"_080547A8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057C88\n"
	"	bl _080554BA\n"
	"_080547B8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80583D8\n"
	"	bl _080554BA\n"
	"_080547C8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AC90\n"
	"	bl _080554BA\n"
	"_080547D8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TriAttackMoveAction\n"
	"	bl _080554BA\n"
	"_080547E8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058B84\n"
	"	bl _080554BA\n"
	"_080547F8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AECC\n"
	"	bl _080554BA\n"
	"_08054808:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B454\n"
	"	bl _080554BA\n"
	"_08054818:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80582C4\n"
	"	bl _080554BA\n"
	"_08054828:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A408\n"
	"	bl _080554BA\n"
	"_08054838:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059714\n"
	"	bl _080554BA\n"
	"_08054848:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B808\n"
	"	bl _080554BA\n"
	"_08054858:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059050\n"
	"	bl _080554BA\n"
	"_08054868:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058478\n"
	"	bl _080554BA\n"
	"_08054878:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80576F8\n"
	"	bl _080554BA\n"
	"_08054888:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl YawnMoveAction\n"
	"	bl _080554BA\n"
	"_08054898:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059080\n"
	"	bl _080554BA\n"
	"_080548A8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059D98\n"
	"	bl _080554BA\n"
	"_080548B8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059AF8\n"
	"	bl _080554BA\n"
	"_080548C8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059AA8\n"
	"	bl _080554BA\n"
	"_080548D8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059DA4\n"
	"	bl _080554BA\n"
	"_080548E8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059D48\n"
	"	bl _080554BA\n"
	"_080548F8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B028\n"
	"	bl _080554BA\n"
	"_08054908:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059D58\n"
	"	bl _080554BA\n"
	"_08054918:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TickleMoveAction\n"
	"	bl _080554BA\n"
	"_08054928:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058638\n"
	"	bl _080554BA\n"
	"_08054938:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A688\n"
	"	bl _080554BA\n"
	"_08054948:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057D7C\n"
	"	bl _080554BA\n"
	"_08054958:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B0BC\n"
	"	bl _080554BA\n"
	"_08054968:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl PainSplitMoveAction\n"
	"	bl _080554BA\n"
	"_08054978:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B164\n"
	"	bl _080554BA\n"
	"_08054988:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059A18\n"
	"	bl _080554BA\n"
	"_08054998:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B884\n"
	"	bl _080554BA\n"
	"_080549A8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl BulkUpMoveAction\n"
	"	bl _080554BA\n"
	"_080549B8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80582D4\n"
	"	bl _080554BA\n"
	"_080549C8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RageMoveAction\n"
	"	bl _080554BA\n"
	"_080549D8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059B94\n"
	"	bl _080554BA\n"
	"_080549E8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B3B4\n"
	"	bl _080554BA\n"
	"_080549F8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059588\n"
	"	bl _080554BA\n"
	"_08054A08:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A2B0\n"
	"	bl _080554BA\n"
	"_08054A18:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B2FC\n"
	"	bl _080554BA\n"
	"_08054A28:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059CD8\n"
	"	bl _080554BA\n"
	"_08054A38:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058A7C\n"
	"	bl _080554BA\n"
	"_08054A48:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80598CC\n"
	"	bl _080554BA\n"
	"_08054A58:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057F7C\n"
	"	bl _080554BA\n"
	"_08054A68:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057ED0\n"
	"	bl _080554BA\n"
	"_08054A78:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058CEC\n"
	"	bl _080554BA\n"
	"_08054A88:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058BF0\n"
	"	bl _080554BA\n"
	"_08054A98:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A2C8\n"
	"	bl _080554BA\n"
	"_08054AA8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AD34\n"
	"	bl _080554BA\n"
	"_08054AB8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057C68\n"
	"	bl _080554BA\n"
	"_08054AC8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059A2C\n"
	"	bl _080554BA\n"
	"_08054AD8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80586DC\n"
	"	bl _080554BA\n"
	"_08054AE8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805946C\n"
	"	bl _080554BA\n"
	"_08054AF8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058E5C\n"
	"	bl _080554BA\n"
	"_08054B08:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80591E4\n"
	"	bl _080554BA\n"
	"_08054B18:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057BC4\n"
	"	bl _080554BA\n"
	"_08054B28:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A210\n"
	"	bl _080554BA\n"
	"_08054B38:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059988\n"
	"	bl _080554BA\n"
	"_08054B48:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SolarBeamMoveAction\n"
	"	bl _080554BA\n"
	"_08054B58:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SkyAttackMoveAction\n"
	"	bl _080554BA\n"
	"_08054B68:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BE90\n"
	"	bl _080554BA\n"
	"_08054B78:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80588B8\n"
	"	bl _080554BA\n"
	"_08054B88:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl WrapMoveAction\n"
	"	bl _080554BA\n"
	"_08054B98:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058D38\n"
	"	bl _080554BA\n"
	"_08054BA8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059DC4\n"
	"	bl _080554BA\n"
	"_08054BB8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl PresentMoveAction\n"
	"	bl _080554BA\n"
	"_08054BC8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ReflectMoveAction\n"
	"	bl _080554BA\n"
	"_08054BD8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SandstormMoveAction\n"
	"	bl _080554BA\n"
	"_08054BE8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SafeguardMoveAction\n"
	"	bl _080554BA\n"
	"_08054BF8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl MistMoveAction\n"
	"	bl _080554BA\n"
	"_08054C08:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl LightScreenMoveAction\n"
	"	bl _080554BA\n"
	"_08054C18:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805768C\n"
	"	bl _080554BA\n"
	"_08054C28:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057F24\n"
	"	bl _080554BA\n"
	"_08054C38:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80599EC\n"
	"	bl _080554BA\n"
	"_08054C48:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80589D4\n"
	"	bl _080554BA\n"
	"_08054C58:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059AC4\n"
	"	bl _080554BA\n"
	"_08054C68:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A4D4\n"
	"	bl _080554BA\n"
	"_08054C78:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058EE0\n"
	"	bl _080554BA\n"
	"_08054C88:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ScannerOrbAction\n"
	"	bl _080554BA\n"
	"_08054C98:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A120\n"
	"	bl _080554BA\n"
	"_08054CA8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BA50\n"
	"	bl _080554BA\n"
	"_08054CB8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A2A0\n"
	"	b _080554BA\n"
	"_08054CC6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058A08\n"
	"	b _080554BA\n"
	"_08054CD4:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl CounterMoveAction\n"
	"	b _080554BA\n"
	"_08054CE2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl BideMoveAction\n"
	"	b _080554BA\n"
	"_08054CF0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805836C\n"
	"	b _080554BA\n"
	"_08054CFE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TrapperOrbAction\n"
	"	b _080554BA\n"
	"_08054D0C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A450\n"
	"	b _080554BA\n"
	"_08054D1A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl CurseMoveAction\n"
	"	b _080554BA\n"
	"_08054D28:\n"
	"	movs r0, 0\n"
	"	str r0, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059FC8\n"
	"	b _080554BA\n"
	"_08054D3A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AE3C\n"
	"	b _080554BA\n"
	"_08054D48:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B3E0\n"
	"	b _080554BA\n"
	"_08054D56:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RazorWindMoveAction\n"
	"	b _080554BA\n"
	"_08054D64:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl FocusPunchMoveAction\n"
	"	b _080554BA\n"
	"_08054D72:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl MagicCoatMoveAction\n"
	"	b _080554BA\n"
	"_08054D80:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl NightmareMoveAction\n"
	"	b _080554BA\n"
	"_08054D8E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057748\n"
	"	b _080554BA\n"
	"_08054D9C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C1BC\n"
	"	b _080554BA\n"
	"_08054DAA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl MudWaterSportMoveAction\n"
	"	b _080554BA\n"
	"_08054DB8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057634\n"
	"	b _080554BA\n"
	"_08054DC6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A3DC\n"
	"	b _080554BA\n"
	"_08054DD4:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057FF4\n"
	"	b _080554BA\n"
	"_08054DE2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A4FC\n"
	"	b _080554BA\n"
	"_08054DF0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058C48\n"
	"	b _080554BA\n"
	"_08054DFE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl LeechSeedMoveAction\n"
	"	b _080554BA\n"
	"_08054E0C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SpikesMoveAction\n"
	"	b _080554BA\n"
	"_08054E1A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80578EC\n"
	"	b _080554BA\n"
	"_08054E28:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80588A8\n"
	"	b _080554BA\n"
	"_08054E36:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RadarOrbAction\n"
	"	b _080554BA\n"
	"_08054E44:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BC70\n"
	"	b _080554BA\n"
	"_08054E52:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80587E8\n"
	"	b _080554BA\n"
	"_08054E60:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B264\n"
	"	b _080554BA\n"
	"_08054E6E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SkullBashMoveAction\n"
	"	b _080554BA\n"
	"_08054E7C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl WishMoveAction\n"
	"	b _080554BA\n"
	"_08054E8A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057FCC\n"
	"	b _080554BA\n"
	"_08054E98:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A258\n"
	"	b _080554BA\n"
	"_08054EA6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059528\n"
	"	b _080554BA\n"
	"_08054EB4:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057E6C\n"
	"	b _080554BA\n"
	"_08054EC2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059DB4\n"
	"	b _080554BA\n"
	"_08054ED0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058838\n"
	"	b _080554BA\n"
	"_08054EDE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TormentMoveAction\n"
	"	b _080554BA\n"
	"_08054EEC:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057974\n"
	"	b _080554BA\n"
	"_08054EFA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B388\n"
	"	b _080554BA\n"
	"_08054F08:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BC98\n"
	"	b _080554BA\n"
	"_08054F16:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80584C0\n"
	"	b _080554BA\n"
	"_08054F24:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BB74\n"
	"	b _080554BA\n"
	"_08054F32:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B668\n"
	"	b _080554BA\n"
	"_08054F40:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl LuminousOrbAction\n"
	"	b _080554BA\n"
	"_08054F4E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl FillInOrbAction\n"
	"	b _080554BA\n"
	"_08054F5C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059CF0\n"
	"	b _080554BA\n"
	"_08054F6A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BF34\n"
	"	b _080554BA\n"
	"_08054F78:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl StairsOrbAction\n"
	"	b _080554BA\n"
	"_08054F86:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl BrickBreakMoveAction\n"
	"	b _080554BA\n"
	"_08054F94:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80582AC\n"
	"	b _080554BA\n"
	"_08054FA2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058A54\n"
	"	b _080554BA\n"
	"_08054FB0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl VitalThrowMoveAction\n"
	"	b _080554BA\n"
	"_08054FBE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl FlyMoveAction\n"
	"	b _080554BA\n"
	"_08054FCC:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059F38\n"
	"	b _080554BA\n"
	"_08054FDA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl DiveMoveAction\n"
	"	b _080554BA\n"
	"_08054FE8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl DigMoveAction\n"
	"	b _080554BA\n"
	"_08054FF6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057824\n"
	"	b _080554BA\n"
	"_08055004:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805825C\n"
	"	b _080554BA\n"
	"_08055012:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl KnockOffMoveAction\n"
	"	b _080554BA\n"
	"_08055020:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TrapbustOrbAction\n"
	"	b _080554BA\n"
	"_0805502E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl LongtossOrbAction\n"
	"	b _080554BA\n"
	"_0805503C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl PierceOrbAction\n"
	"	b _080554BA\n"
	"_0805504A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl GrudgeMoveAction\n"
	"	b _080554BA\n"
	"_08055058:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl PetrifyOrbAction\n"
	"	b _080554BA\n"
	"_08055066:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A4C0\n"
	"	b _080554BA\n"
	"_08055074:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AAD0\n"
	"	b _080554BA\n"
	"_08055082:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ShockerOrbAction\n"
	"	b _080554BA\n"
	"_08055090:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B314\n"
	"	b _080554BA\n"
	"_0805509E:\n"
	"	movs r0, 0\n"
	"	str r0, [sp]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059E54\n"
	"	b _080554BA\n"
	"_080550B0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ProtectMoveAction\n"
	"	b _080554BA\n"
	"_080550BE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059AB8\n"
	"	b _080554BA\n"
	"_080550CC:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058858\n"
	"	b _080554BA\n"
	"_080550DA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058770\n"
	"	b _080554BA\n"
	"_080550E8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8059004\n"
	"	b _080554BA\n"
	"_080550F6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80597F0\n"
	"	b _080554BA\n"
	"_08055104:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ChargeMoveAction\n"
	"	b _080554BA\n"
	"_08055112:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058548\n"
	"	b _080554BA\n"
	"_08055120:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80588F4\n"
	"	b _080554BA\n"
	"_0805512E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058D44\n"
	"	b _080554BA\n"
	"_0805513C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AFA4\n"
	"	b _080554BA\n"
	"_0805514A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SmokescreenMoveAction\n"
	"	b _080554BA\n"
	"_08055158:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BA44\n"
	"	b _080554BA\n"
	"_08055166:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl StockpileMoveAction\n"
	"	b _080554BA\n"
	"_08055174:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SpitUpMoveAction\n"
	"	b _080554BA\n"
	"_08055182:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SwallowMoveAction\n"
	"	b _080554BA\n"
	"_08055190:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RainDanceMoveAction\n"
	"	b _080554BA\n"
	"_0805519E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057D9C\n"
	"	b _080554BA\n"
	"_080551AC:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl InvisifyOrbAction\n"
	"	b _080554BA\n"
	"_080551BA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl MirrorCoatMoveAction\n"
	"	b _080554BA\n"
	"_080551C8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl PerishSongMoveAction\n"
	"	b _080554BA\n"
	"_080551D6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058A18\n"
	"	b _080554BA\n"
	"_080551E4:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl DestinyBondMoveAction\n"
	"	b _080554BA\n"
	"_080551F2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl EncoreMoveAction\n"
	"	b _080554BA\n"
	"_08055200:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057CD0\n"
	"	b _080554BA\n"
	"_0805520E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SunnyDayMoveAction\n"
	"	b _080554BA\n"
	"_0805521C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A464\n"
	"	b _080554BA\n"
	"_0805522A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C2A0\n"
	"	b _080554BA\n"
	"_08055238:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl EndureMoveAction\n"
	"	b _080554BA\n"
	"_08055246:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl HelpingHandMoveAction\n"
	"	b _080554BA\n"
	"_08055254:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl BellyDrumMoveAction\n"
	"	b _080554BA\n"
	"_08055262:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C288\n"
	"	b _080554BA\n"
	"_08055270:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805783C\n"
	"	b _080554BA\n"
	"_0805527E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_80578FC\n"
	"	b _080554BA\n"
	"_0805528C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057BB4\n"
	"	b _080554BA\n"
	"_0805529A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RockSmashMoveAction\n"
	"	b _080554BA\n"
	"_080552A8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TransformMoveAction\n"
	"	b _080554BA\n"
	"_080552B6:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl HailMoveAction\n"
	"	b _080554BA\n"
	"_080552C4:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl MobileOrbAction\n"
	"	b _080554BA\n"
	"_080552D2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8058234\n"
	"	b _080554BA\n"
	"_080552E0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805A85C\n"
	"	b _080554BA\n"
	"_080552EE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl TransferOrbAction\n"
	"	b _080554BA\n"
	"_080552FC:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BB98\n"
	"	b _080554BA\n"
	"_0805530A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AD54\n"
	"	b _080554BA\n"
	"_08055318:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ReboundOrbAction\n"
	"	b _080554BA\n"
	"_08055326:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805AD04\n"
	"	b _080554BA\n"
	"_08055334:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C080\n"
	"	b _080554BA\n"
	"_08055342:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C1E4\n"
	"	b _080554BA\n"
	"_08055350:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl EscapeOrbAction\n"
	"	b _080554BA\n"
	"_0805535E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SecretPowerMoveAction\n"
	"	b _080554BA\n"
	"_0805536C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl NaturePowerMoveAction\n"
	"	b _080554BA\n"
	"_0805537A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C3F8\n"
	"	b _080554BA\n"
	"_08055388:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SketchMoveAction\n"
	"	b _080554BA\n"
	"_08055396:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_8057E50\n"
	"	b _080554BA\n"
	"_080553A4:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RolePlayMoveAction\n"
	"	b _080554BA\n"
	"_080553B2:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SkillSwapMoveAction\n"
	"	b _080554BA\n"
	"_080553C0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl ConversionMoveAction\n"
	"	b _080554BA\n"
	"_080553CE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl CleanseOrbAction\n"
	"	b _080554BA\n"
	"_080553DC:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805805C\n"
	"	b _080554BA\n"
	"_080553EA:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SnatchMoveAction\n"
	"	b _080554BA\n"
	"_080553F8:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl HandleColorChange\n"
	"	b _080554BA\n"
	"_08055406:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B53C\n"
	"	b _080554BA\n"
	"_08055414:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl PsychUpMoveAction\n"
	"	b _080554BA\n"
	"_08055422:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SnoreMoveAction\n"
	"	b _080554BA\n"
	"_08055430:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl RecycleMoveAction\n"
	"	b _080554BA\n"
	"_0805543E:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl SilenceOrbAction\n"
	"	b _080554BA\n"
	"_0805544C:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805B618\n"
	"	b _080554BA\n"
	"_0805545A:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl IdentifyOrbAction\n"
	"	b _080554BA\n"
	"_08055468:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl Conversion2MoveAction\n"
	"	b _080554BA\n"
	"_08055476:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BEB8\n"
	"	b _080554BA\n"
	"_08055484:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805BEC8\n"
	"	b _080554BA\n"
	"_08055492:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl MimicMoveAction\n"
	"	b _080554BA\n"
	"_080554A0:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C45C\n"
	"	b _080554BA\n"
	"_080554AE:\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	mov r3, r9\n"
	"	bl sub_805C208\n"
	"_080554BA:\n"
	"	lsls r0, 24\n"
	"	lsrs r4, r0, 24\n"
	"	b _080554C2\n"
	"_080554C0:\n"
	"	movs r4, 0\n"
	"_080554C2:\n"
	"	bl sub_8044B28\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	bne _080555A2\n"
	"	ldr r0, [sp, 0x20]\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _080554E6\n"
	"	ldr r3, [sp, 0x20]\n"
	"	ldr r0, [r3, 0x70]\n"
	"	adds r0, 0x46\n"
	"	ldrb r1, [r0]\n"
	"	adds r0, r3, 0\n"
	"	bl sub_806CE68\n"
	"_080554E6:\n"
	"	cmp r4, 0\n"
	"	bne _08055510\n"
	"	adds r0, r7, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08055530\n"
	"	adds r0, r5, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08055530\n"
	"	ldr r1, [sp, 0x24]\n"
	"	ldrb r0, [r1, 0x6]\n"
	"	cmp r0, 0\n"
	"	beq _08055530\n"
	"	mov r2, r10\n"
	"	strb r2, [r6]\n"
	"	b _08055530\n"
	"_08055510:\n"
	"	mov r0, r8\n"
	"	bl MoveCausesPaused\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08055530\n"
	"	adds r0, r7, 0\n"
	"	movs r1, 0\n"
	"	bl sub_8057308\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08055530\n"
	"	ldr r1, _08055614\n"
	"	movs r0, 0x1\n"
	"	strb r0, [r1]\n"
	"_08055530:\n"
	"	adds r0, r5, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08055548\n"
	"	ldr r3, [sp, 0x24]\n"
	"	movs r0, 0xAC\n"
	"	lsls r0, 1\n"
	"	adds r1, r3, r0\n"
	"	movs r0, 0x1\n"
	"	strb r0, [r1]\n"
	"_08055548:\n"
	"	ldr r1, [sp, 0x18]\n"
	"	cmp r1, 0x89\n"
	"	beq _08055568\n"
	"	adds r0, r7, 0\n"
	"	bl TriggerAbilityEffect\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	bl sub_8069F9C\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r5, 0\n"
	"	mov r2, r8\n"
	"	bl sub_806A120\n"
	"_08055568:\n"
	"	ldr r7, [sp, 0x1C]\n"
	"_0805556A:\n"
	"	ldr r2, [sp, 0x14]\n"
	"	adds r2, 0x1\n"
	"	str r2, [sp, 0x14]\n"
	"_08055570:\n"
	"	ldr r3, [sp, 0x14]\n"
	"	cmp r3, 0x3F\n"
	"	bgt _080555A2\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x20]\n"
	"	lsls r0, r3, 2\n"
	"	ldr r1, [sp, 0x10]\n"
	"	adds r0, r1\n"
	"	ldr r5, [r0]\n"
	"	movs r2, 0x1\n"
	"	str r2, [sp, 0x28]\n"
	"	movs r3, 0\n"
	"	str r3, [sp, 0x2C]\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x30]\n"
	"	cmp r5, 0\n"
	"	beq _080555A2\n"
	"	adds r0, r7, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _080555A2\n"
	"	bl _08053724\n"
	"_080555A2:\n"
	"	bl sub_8044B28\n"
	"	lsls r0, 24\n"
	"	lsrs r4, r0, 24\n"
	"	cmp r4, 0\n"
	"	bne _08055604\n"
	"	adds r0, r7, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _080555D6\n"
	"	ldr r0, [r7, 0x70]\n"
	"	movs r2, 0xAA\n"
	"	lsls r2, 1\n"
	"	adds r1, r0, r2\n"
	"	ldrb r0, [r1]\n"
	"	cmp r0, 0\n"
	"	beq _080555D6\n"
	"	strb r4, [r1]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r7, 0\n"
	"	movs r2, 0\n"
	"	movs r3, 0\n"
	"	bl sub_807D148\n"
	"_080555D6:\n"
	"	adds r0, r7, 0\n"
	"	bl EntityExists\n"
	"	lsls r0, 24\n"
	"	cmp r0, 0\n"
	"	beq _08055604\n"
	"	ldr r0, [r7, 0x70]\n"
	"	ldr r3, _08055618\n"
	"	adds r1, r0, r3\n"
	"	ldrb r0, [r1]\n"
	"	cmp r0, 0\n"
	"	beq _08055604\n"
	"	movs r0, 0\n"
	"	strb r0, [r1]\n"
	"	ldr r1, _0805561C\n"
	"	ldr r2, [r1]\n"
	"	str r0, [sp]\n"
	"	str r0, [sp, 0x4]\n"
	"	adds r0, r7, 0\n"
	"	adds r1, r7, 0\n"
	"	movs r3, 0x2\n"
	"	bl LowerAttackStageTarget\n"
	"_08055604:\n"
	"	add sp, 0x48\n"
	"	pop {r3-r5}\n"
	"	mov r8, r3\n"
	"	mov r9, r4\n"
	"	mov r10, r5\n"
	"	pop {r4-r7}\n"
	"	pop {r0}\n"
	"	bx r0\n"
	"	.align 2, 0\n"
	"_08055614: .4byte gUnknown_202F222\n"
	"_08055618: .4byte 0x00000155\n"
	"_0805561C: .4byte gUnknown_8106A50\n");
}

s32 sub_8055640(Entity *, Entity *, Move *, s32, s32);
s32 sub_8055728(Entity *attacker, Entity *target, Move *move, struct DamageStruct *dmgStruct, s16 unk);
bool8 sub_8056B34(Entity *attacker, Entity *target, Move *move, s32 accuracyType, bool8 unkBool);
bool8 sub_8055FA0(struct Entity *entity, u32 r6, s32 itemId, u32 var_30, u32 arg_0, struct Move *move);

UNUSED bool32 sub_8055620(Entity *a0, Entity *a1, Move *a2, s32 a3)
{
    return (sub_8055640(a0, a1, a2, 0x100, a3) != FALSE);
}

extern void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC);
extern void sub_806EAF4(Entity *, Entity *, u8, u32, u32, struct DamageStruct *dmgStruct, u32, u16, u32);
extern s16 sub_8057600(Move *move, s32 itemID);
extern void sub_803ED30(s32, Entity *r0, u8, s32);
extern void sub_8042238(Entity *pokemon, Entity *target);
extern void sub_806A1E8(Entity *pokemon);
extern void sub_80574C4(Entity **a0, Entity *a1);

extern const u8 *const gUnknown_80F9688;

s32 sub_8055640(Entity *attacker, Entity *target, Move *move, s32 r9, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s16 unk;
    s32 moveType = GetMoveTypeForMonster(attacker, move);
    s32 movePower = GetMovePower(attacker, move);
    s32 critChance = GetMoveCritChance(move);

    sub_806EAF4(attacker, target, moveType, movePower, critChance, &dmgStruct, r9, move->id, 1);
    unk = sub_8057600(move, itemId);
    return sub_8055728(attacker, target, move, &dmgStruct, unk);
}

s32 sub_80556BC(Entity *attacker, Entity *target, u8 moveType, Move *move, s32 r9, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s16 unk;
    s32 movePower = GetMovePower(attacker, move);
    s32 critChance = GetMoveCritChance(move);

    sub_806EAF4(attacker, target, moveType, movePower, critChance, &dmgStruct, r9, move->id, 1);
    unk = sub_8057600(move, itemId);
    return sub_8055728(attacker, target, move, &dmgStruct, unk);
}

s32 sub_8055728(Entity *attacker, Entity *target, Move *move, struct DamageStruct *dmgStruct, s16 unk_)
{
    s32 unk = unk_; // It's happening again...
    if (sub_8056B34(attacker, target, move, ACCURACY_2, TRUE)) {
        bool32 isFalseSwipe = (move->id == MOVE_FALSE_SWIPE);

        if (HasAbility(target, ABILITY_ILLUMINATE)) {
            gDungeon->unk662 = 999;
            gDungeon->unk17B34 = target;
            gDungeon->unk17B40 = target->spawnGenID;
        }

        HandleDealingDamage(attacker, target, dmgStruct, isFalseSwipe, TRUE, unk, TRUE, 0);
    }
    else {
        SetMessageArgument_2(gUnknown_202DFE8, GetEntInfo(target), 0);
        if (sub_8045888(attacker) && sub_8045888(target)) {
            sub_803ED30(9999, target, 1, -1);
            TryDisplayDungeonLoggableMessage4(attacker, target, gUnknown_80F9688); // It took no damage!
            sub_8042238(attacker, target);
        }
        else {
            TryDisplayDungeonLoggableMessage3(attacker, target, gUnknown_80F9688); // It took no damage!
        }
        dmgStruct->unkF = 1;
    }

    if (dmgStruct->unkF != 0) {
        return 0;
    }

    if (EntityExists(target)) {
        GetEntInfo(target)->unk15A = 1;
    }

    return dmgStruct->dmg;
}

extern void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct);

s32 sub_8055864(Entity *attacker, Entity *target, Move *move, s32 param_4, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s32 moveType = GetMoveTypeForMonster(attacker, move);

    sub_806F2BC(attacker, target, moveType, param_4, &dmgStruct);
    HandleDealingDamage(attacker, target, &dmgStruct, FALSE, TRUE, sub_8057600(move, itemId), TRUE, 0);
    if (dmgStruct.unkF != 0) {
        return 0;
    }

    if (EntityExists(target)) {
        GetEntInfo(target)->unk15A = 1;
    }
    return dmgStruct.dmg;
}

extern const s32 gUnknown_81069BC[];

// This unused function returns FALSE if target's typing makes it immune to move's type.
UNUSED bool32 TargetNotImmuneTo(Move *move, Entity *target)
{
    s32 i;
    s32 dmg = 1;
    bool32 ghostImmunity = FALSE;
    EntityInfo *targetInfo = GetEntInfo(target);
    s32 moveType = GetMoveType(move);

    if (moveType == TYPE_NORMAL || moveType == TYPE_FIGHTING) {
        ghostImmunity = TRUE;
    }

    for (i = 0; i < 2; i++) {
        s32 multiplier[4]; // 0, 1, 1, 1 ; 0 is for EFFECTIVENESS_IMMUNE
        s32 effectiveness;

        memcpy(multiplier, &gUnknown_81069BC, sizeof(multiplier));
        if (ghostImmunity && targetInfo->types[i] == TYPE_GHOST && !targetInfo->exposed) {
            effectiveness = EFFECTIVENESS_IMMUNE;
        }
        else {
            effectiveness = gTypeEffectivenessChart[moveType][targetInfo->types[i]];
        }

        dmg *= multiplier[effectiveness];
        if (dmg == 0)
            break;
    }

    return (dmg != 0);
}

bool8 sub_8055988(Entity *r2, Entity *r4)
{
    if (r2 != r4
        && abs(r2->pos.x - r4->pos.x) <= 1 && abs(r2->pos.y - r4->pos.y) <= 1
        && CanAttackInDirection(r4, GetDirectionTowardsPosition(&r4->pos, &r2->pos)))
    {
        return TRUE;
    }

    return FALSE;
}

void sub_80559DC(Entity *entity1, Entity *entity2)
{
    EntityInfo *entInfo = GetEntInfo(entity1);
    s32 direction = GetDirectionTowardsPosition(&entity1->pos, &entity2->pos);

    entInfo->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(entity1, direction);
}

extern const u8 *const gUnknown_80FC714;
extern const u8 *const gUnknown_80FC718;
extern const u8 *const gUnknown_80FC6A8;
extern const u8 *const gUnknown_80FD2D0;
extern const u8 *const gUnknown_80FD2DC;
extern const u8 *const gUnknown_80F93C8;
extern const u8 *const gUnknown_80FC690;
extern const u8 *const gUnknown_80FC6A4;

extern const s16 gUnknown_80F4E70[];
extern const s16 gUnknown_80F4E74[];

extern u8 gFormatItems[];
extern u8 gUnknown_202F221;
extern u8 gUnknown_202F222;
extern s32 gUnknown_202F208;


extern bool8 sub_8044B28(void);
extern void sub_804178C(u32);
extern void sub_8071DA4(Entity *);
extern void sub_80428A0(Entity *r0);

bool32 sub_8055A00(Entity *entity, s32 firstMoveId, s32 var_34, s32 itemId, s32 arg_0)
{
    s32 i, j;
    s32 moveId;
    EntityInfo *entInfo = GetEntInfo(entity);
    bool32 var_2C;

    moveId = firstMoveId;
    if (firstMoveId >= MAX_MON_MOVES)
        return FALSE;

    entInfo->abilityEffectFlags = 0;
    entInfo->unk159 = 0;
    if (entInfo->volatileStatus.volatileStatus == STATUS_CRINGE) {
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC714); // is cringing!
        return FALSE;
    }
    else if (entInfo->volatileStatus.volatileStatus == STATUS_INFATUATED) {
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC718); // is infatuated!
        return FALSE;
    }
    else if (entInfo->nonVolatile.nonVolatileStatus == STATUS_PARALYSIS) {
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC6A8); // is paralyzed!
        return FALSE;
    }

    gUnknown_202F222 = 0;
    gUnknown_202F208 = 0;
    gUnknown_202F221 = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        entInfo->mimicMoveIDs[i] = 0;
    }

    for (i = 0, j = 0; i < MAX_MON_MOVES; i++) {
        j++;
        if (++moveId >= MAX_MON_MOVES)
            break;
        if (!(entInfo->moves.moves[moveId].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;
    }

    var_2C = (j > 1);
    moveId = firstMoveId;

    while (1) {
        Move *currMove = &entInfo->moves.moves[moveId];
        if (!EntityExists(entity) || sub_8044B28())
            break;

        if (currMove->id == MOVE_SNORE || currMove->id == MOVE_SLEEP_TALK) {
            if (!IsSleeping(entity)) {
                if (CannotAttack(entity, TRUE))
                    break;
            }
        }
        else {
            if (CannotAttack(entity, FALSE))
                break;
        }

        if (gUnknown_202F221 != 0)
            break;

        if (MoveFlagExists(currMove)) {
            bool32 moveUsable = TRUE;
            bool32 var_28 = FALSE;
            bool32 statusMoveMatch = MoveMatchesChargingStatus(entity, currMove);

            if (currMove->PP != 0) {
                if (!statusMoveMatch) {
                    var_28 = TRUE;
                }
            }
            else {
                if (!statusMoveMatch) {
                    sub_80928C0(gFormatItems,  currMove, NULL);
                    TryDisplayDungeonLoggableMessage(entity, gUnknown_80F93C8); // The move can't be used!
                    moveUsable = FALSE;
                }
            }

            if (moveUsable) {
                bool32 r0;
                s32 unkBefore = gUnknown_202F208;

                entInfo->unk159 = statusMoveMatch;
                if (currMove->id == MOVE_ASSIST) {
                    Move assistMove = *currMove;

                    assistMove.id = sub_8057144(entity);
                    sub_80928C0(gFormatItems, &assistMove, NULL);
                    TryDisplayDungeonLoggableMessage(entity, gUnknown_80FD2DC); // Assist:
                    r0 = sub_8055FA0(entity, var_34, itemId, arg_0, var_2C, &assistMove);
                }
                else {
                    r0 = sub_8055FA0(entity, var_34, itemId, arg_0, var_2C, currMove);
                }

                if (var_28 && r0) {
                    if (currMove->moveFlags2 & MOVE_FLAG2_UNK4) {
                        currMove->moveFlags2 &= ~(MOVE_FLAG2_UNK4);
                    }
                    else {
                        currMove->moveFlags2 |= MOVE_FLAG_TEMPORARY;
                    }
                }

                if (unkBefore == gUnknown_202F208) {
                    if (itemId == 0) {
                        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC690); // The currMove failed!
                    }
                    else {
                        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC6A4); // The Orb failed!
                    }
                }
            }
        }

        sub_804178C(1);
        if (!EntityExists(entity) || sub_8044B28())
            break;
        if (++moveId >= MAX_MON_MOVES)
            break;
        if (!MoveFlagLinkChain(&entInfo->moves.moves[moveId]))
            break;
    }

    if (EntityExists(entity)) {
        for (i = 0; i < MAX_MON_MOVES; i++) {
            if (entInfo->mimicMoveIDs[i] != 0) {
                Move mimicMove, assistMove;
                Move *movePtr;

                movePtr = &mimicMove;
                sub_8092AA8(&mimicMove, entInfo->mimicMoveIDs[i]);
                if (MoveFlagExists(&mimicMove)) {
                    if (mimicMove.id == MOVE_ASSIST) {
                        assistMove = mimicMove;
                        assistMove.id = sub_8057144(entity);
                        movePtr = &assistMove;
                        sub_80928C0(gFormatItems, &assistMove, NULL);
                        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FD2DC); // Assist:
                    }
                    sub_8055FA0(entity, 0, itemId, arg_0, var_2C, movePtr);
                }
                sub_804178C(1);
            }
        }
    }

    if (EntityExists(entity)) {
        sub_8071DA4(entity);
        if (EntityExists(entity) && gUnknown_202F222 != 0) {
            gUnknown_202F222 = 0;
            if (EntityExists(entity)) {
                EntityInfo *entInfo = GetEntInfo(entity);
                s32 statusTurns = CalculateStatusTurns(entity, gUnknown_80F4E70, TRUE);
                PausedStatusTarget(entity, entity, 1, statusTurns, FALSE);
                SetExpMultplier(entInfo);
            }
        }
    }

    return TRUE;
}

extern const u16 gUnknown_80F5004;
extern const u8 *const gUnknown_80FEEA4;
extern const u8 *const gUnknown_80FEEC8;
extern const u8 *const gUnknown_80FEEEC;
extern const u8 *const gUnknown_80FEF0C;
extern const u8 *const gUnknown_80FEF30;
extern const u8 *const gUnknown_80FEF4C;
extern const u8 *const gUnknown_80FEF50;
extern const u8 *const gUnknown_80FEF54;
extern const u8 *const gUnknown_80FEF74;
extern const u8 *const gUnknown_80FEF98;
extern const u8 *const gUnknown_80FEFD0;
extern const u8 *const gUnknown_80FECA4;
extern const u8 *const gUnknown_80F9158;
extern const u8 *const gUnknown_80FC72C;
extern const u8 *const gUnknown_80FC700;
extern const u8 *const gUnknown_80FC6D0;
extern const u8 *const gUnknown_80FC710;
extern const u8 *const gUnknown_80FC6FC;
extern const u8 *const gUnknown_80FECBC;
extern const u8 *const gUnknown_80FECE0;

void TriggerAbilityEffect(Entity *entity)
{
    if (EntityExists(entity)) {
        EntityInfo *entInfo = GetEntInfo(entity);

        if (entInfo->abilityEffectFlags & ABILITY_FLAG_ARENA_TRAP) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEEA4); // Arena Trap prevents movement!
            ImmobilizedStatusTarget(entity, entity);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_SHADOW_TAG) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEEC8); // Shadow Tag prevents movement!
            ImmobilizedStatusTarget(entity, entity);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_MAGNET_PULL) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEEEC); // Magnet Pull prevents movement!
            ImmobilizedStatusTarget(entity, entity);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_STATIC) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF0C); // Static caused paralysis!
            ParalyzeStatusTarget(entity, entity, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_PRLZ) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF30); // Effect Spore scattered spores
            ParalyzeStatusTarget(entity, entity, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_POISON_POINT) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF4C); // Poison Point struck!
            PoisonedStatusTarget(entity, entity, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_PSN) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF50); // Effect Spore scattered spores!
            PoisonedStatusTarget(entity, entity, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_SLP) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF54); // Effect Spore scattered spores!
            sub_8075C58(entity, entity, CalculateStatusTurns(entity, gUnknown_80F4E74, TRUE), TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_FLAME_BODY) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF74); // Flame Body caused a burn!
            BurnedStatusTarget(entity, entity, TRUE, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_CUTE_CHARM) {
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEF98); // Cute Charm caused infatuation
            InfatuateStatusTarget(entity, entity, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_STENCH) {
            SetMessageArgument(gAvailablePokemonNames, entity, 0);
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FEFD0); // A horrid stench billowed out
            sub_80428A0(entity);
            entInfo->terrifiedTurns = gUnknown_80F5004;
        }

        entInfo->abilityEffectFlags = 0;
    }
}

extern s32 gMetronomeCalledArrayId;

extern void sub_806ACE8(Entity *entity, Move *move);
extern s32 sub_8057070(Move *move);

bool8 sub_8056468(Entity *entity, Move *move, const u8 *str, Entity **unkArray, bool32 itemId, bool8 arg_4, bool32 unused);
bool8 sub_805744C(Entity * pokemon, Move *move, bool8 param_3);
void sub_8056CE8(Entity **, Entity * pokemon, Move *move);
void sub_80566F8(Entity*, Move *, s32 a2, bool8 a3, s32 a4, s32 a5);

extern s32 gUnknown_202F214;
extern s32 gUnknown_202F20C;
extern s32 gUnknown_202F210;
extern s32 gUnknown_202F21C;
extern Entity *gUnknown_203B438;
extern u8 gUnknown_202F218;
extern u8 gUnknown_202F219;
extern u8 gUnknown_202F21A;
extern u8 gUnknown_202F220;
extern u8 gUnknown_202F221;

bool8 sub_805755C(Entity* pokemon,u16 param_2);

bool8 sub_8055FA0(struct Entity *entity, u32 r6, s32 itemId, u32 var_30, u32 arg_0, struct Move *move)
{
    s32 i;
    Entity *var_144[65]; //????
    const u8 *msg;
    Move metronomeMove, naturePwrMove;
    s32 var_2C;
    s32 var_28;
    s32 var_24;
    bool8 moveUsable;

    msg = NULL;
    var_144[0] = NULL;

    sub_804178C(1);
    if (move->id == MOVE_METRONOME) {
        gMetronomeCalledArrayId = DungeonRandInt(METRONOME_AVAILABLE_CALLED_MOVES);
        InitPokemonMove(&metronomeMove, gMetronomeCalledMoves[gMetronomeCalledArrayId].moveID);
        metronomeMove.moveFlags = move->moveFlags;
        metronomeMove.moveFlags2 = move->moveFlags2;
        sub_8056468(entity, move, gUnknown_80FECBC, var_144, itemId, TRUE, FALSE);
        sub_804178C(1);
        move = &metronomeMove;
    }
    else if (move->id == MOVE_NATURE_POWER)
    {
        s32 tileset = gDungeon->tileset;

        if (tileset < 0)
            tileset = 0;
        if (tileset > 74)
            tileset = 74;

        InitPokemonMove(&naturePwrMove, gNaturePowerCalledMoves[tileset].moveID);
        naturePwrMove.moveFlags = move->moveFlags;
        naturePwrMove.moveFlags2 = move->moveFlags2;
        sub_8056468(entity, move, gUnknown_80FECE0, var_144, itemId, TRUE, FALSE);
        sub_804178C(1);
        move = &naturePwrMove;
    }

    var_28 = 0;
    if ((GetMoveTargetAndRangeForPokemon(entity, move, TRUE)
         & (0xF0)) == TARGETING_FLAG_TARGET_LINE)
    {
        var_28 = 10;
    }
    if ((GetMoveTargetAndRangeForPokemon(entity, move, TRUE)
         & (0xF0)) == TARGETING_FLAG_CUT_CORNERS)
        {
        var_28 = 1;
        if ((move->id != MOVE_SOLARBEAM || GetApparentWeather(entity) != WEATHER_SUNNY) && DoesMoveCharge(move->id)) {
            if (!MoveMatchesChargingStatus(entity, move)) {
                var_28 = 0;
            }
        }
    }

    SetMessageArgument_2(gAvailablePokemonNames, GetEntInfo(entity), 0);
    sub_80928C0(gFormatItems, move, NULL);
    if (MoveMatchesChargingStatus(entity, move)) {
        msg = gUnknown_80FC72C; // mon loosed move
        GetEntInfo(entity)->unkFF = 0;
        moveUsable = sub_805744C(entity, move, TRUE);
    }
    else {
        if (itemId == 0) {
            msg = GetMoveUseText(move->id);
        }
        else {
            msg = gUnknown_80F9158;
        }
        moveUsable = CanMonsterUseMove(entity, move, TRUE);
    }

    if (moveUsable && r6) {
        sub_806ACE8(entity, move);
    }

    if (GetEntInfo(entity)->muzzled.muzzled == TRUE && FailsWhileMuzzled(move->id)) {
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        TryDisplayDungeonLoggableMessage(entity, msg);
        sub_803E708(0xA, 0x3F);
        TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC710); // is muzzled!
        return FALSE;
    }
    else if (!moveUsable) {
        SetMessageArgument_2(gAvailablePokemonNames, GetEntInfo(entity), 0);
        if (itemId == 0) {
            sub_80928C0(gFormatItems, move, NULL);
            TryDisplayDungeonLoggableMessage(entity, msg);
            sub_803E708(0xA, 0x3F);
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC6D0); // But the move couldn't be used!
        }
        else {
            BufferItemName(gFormatItems, itemId, NULL);
            TryDisplayDungeonLoggableMessage(entity, msg);
            sub_803E708(0xA, 0x3F);
            TryDisplayDungeonLoggableMessage(entity, gUnknown_80FC6FC); // But Orbs are prevented from being used!
        }
        return FALSE;
    }

    gUnknown_202F214 = 0;
    gUnknown_202F20C = 0;
    gUnknown_202F210 = 0;
    gUnknown_202F218 = 0;
    gUnknown_202F219 = 0;
    gUnknown_202F21A = 0;
    gUnknown_202F21C = 0;
    gUnknown_202F220 = 0;
    if (arg_0 && GetEntInfo(entity)->unk153 <= 3) {
        GetEntInfo(entity)->unk153++;
    }

    var_2C = sub_8057070(move);
    for (i = 0; i < var_2C; i++) {
        u8 r4;
        EntityInfo *entInfo;

        var_24 = 1;
        if (gUnknown_202F220 != 0 || gUnknown_202F221 != 0)
            break;
        if (!EntityExists(entity) || sub_8044B28())
            return TRUE;

        entInfo = GetEntInfo(entity);
        if (var_30 != 0 || move->id == MOVE_SNORE || move->id == MOVE_SLEEP_TALK) {
            if (!IsSleeping(entity) && CannotAttack(entity, TRUE))
                break;
        }
        else {
            if (CannotAttack(entity, FALSE))
                break;
        }
        entInfo->unk14A = 0;
        if (move->id == MOVE_THRASH) {
            GetEntInfo(entity)->action.direction = DungeonRandInt(NUM_DIRECTIONS);
            TargetTileInFront(entity);
            var_24 = 0;
        }
        gUnknown_203B438 = NULL;
        var_144[0] = 0;
        if (var_28 == 0 || var_28 == 1) {
            sub_8056CE8(var_144, entity, move);
            sub_80574C4(var_144, entity); // Todo fix sub_80574C4
            if (i != 0 && var_24 != 0 && var_144[0] == 0)
                break;
        }
        r4 = sub_8056468(entity, move, msg, var_144, itemId, (i == 0), var_28);
        msg = NULL;
        if (gUnknown_203B438 != 0) {
            sub_806A1E8(gUnknown_203B438);
        }

        if (GetEntInfo(entity)->volatileStatus.volatileStatus != STATUS_CONFUSED && GetEntInfo(entity)->volatileStatus.volatileStatus != STATUS_COWERING) {
            EntityInfo *entInfo = GetEntInfo(entity);
            entInfo->targetPos.x = 0;
            entInfo->targetPos.y = 0;
        }

        gUnknown_202F214++;
        if (var_28 != 0) {
            sub_80566F8(entity, move, var_28, r4, itemId, arg_0);
        }
        else {
            sub_8053704(var_144, entity, move, itemId, arg_0);
        }

        if (!EntityExists(entity))
            break;

        sub_806CF18(entity);
        if (GetEntInfo(entity)->unk14A == 0) {
            GetEntInfo(entity)->unk14A = 0; // Redundant as it's already 0
            sub_8079764(entity);
        }
    }


    if (gUnknown_202F21A != 0) {
        SendImmobilizeEndMessage(entity, entity);
        SendLinkedEndMessage(entity, entity);
    }

    if (gUnknown_202F219 != 0 && EntityExists(entity)) {
        EntityInfo *entInfo = GetEntInfo(entity);

        ConfuseStatusTarget(entity, entity, FALSE);
        SetExpMultplier(entInfo);
    }
    return TRUE;
}

extern bool8 sub_8040BB0(Entity *entity, Move *move, bool8);
extern void sub_8040DA0(Entity *entity, Move *move);

bool8 sub_8056468(Entity *entity, Move *move, const u8 *str, Entity **unkArray, bool32 itemId, bool8 arg_4, bool32 unused)
{
    s32 i;
    bool8 ret = FALSE;
    bool32 r7 = (sub_8045888(entity) != FALSE);

    if (str != NULL) {
        for (i = 0; i < 65; i++) {
            if (unkArray[i] == NULL) {
                break;
            }
            if (sub_8045888(unkArray[i])) {
                r7 = TRUE;
                break;
            }
        }

        if (r7) {
            SetMessageArgument_2(gAvailablePokemonNames, GetEntInfo(entity), 0);
            if (itemId == 0) {
                sub_80928C0(gFormatItems, move, NULL);
            }
            else {
                BufferItemName(gFormatItems, itemId, NULL);
            }
        }

        if (move->id != MOVE_REGULAR_ATTACK) {
            DisplayDungeonLoggableMessageTrue(entity, str);
        }
        else {
            DisplayDungeonLoggableMessageFalse(entity, str);
        }
    }

    if (r7) {
        if (arg_4) {
            ret = sub_8040BB0(entity, move, TRUE);
        }
        else {
            ret = sub_8040BB0(entity, move, FALSE);
        }
        sub_8040DA0(entity, move);
    }
    else {
        sub_806CE68(entity, GetEntInfo(entity)->action.direction);
    }

    return ret;
}

extern u16 sub_80412E0(u16 moveId, u8 weather, u8 a2);
extern void sub_800569C(Position *, EntitySpriteInfo *, u8);

struct UnkStruct_sub_800E308_1
{
    s16 unk0;
    s16 unk2;
    Position unk4;
    Position unk8;
    s32 unkC;
    s32 unk10;
};

// Maybe Position? Maybe not, sub_800E308 is called only by sub_8056564, so :shrug:
struct UnkStruct_sub_800E308_2
{
    s16 u0;
    s16 u2;
};

extern s32 sub_800E308(struct UnkStruct_sub_800E308_1 *, struct UnkStruct_sub_800E308_2 *);
extern u8 GetBodySize(s16 index);
extern void sub_800EF10(u16 r0);
extern s32 sub_800E710(s16 a0, u16 a1);

#ifdef NONMATCHING // https://decomp.me/scratch/fTUsI
s32 sub_8056564(Entity *entity, Position *pos, Move *move, s32 r4)
{
    struct UnkStruct_sub_800E308_1 unkSp1;
    struct UnkStruct_sub_800E308_2 unkSp2;
    EntityInfo *entInfo = GetEntInfo(entity);

    if (!gDungeon->unk181e8.blinded && (GetBodySize(entInfo->apparentID) < 4 || r4 == 1)) {
        unkStruct_80BDBC4 *unkStruct = sub_800ECB8(sub_80412E0(move->id, GetApparentWeather(entity), 1));
        s32 unk6 = unkStruct->unk6;
        // This part with unkPos doesn't match
        Position32 unkPos = {pos->x * 0x1800, pos->y * 0x1800};

        unkPos.x += 0x1000;
        unkPos.y += 0xC00;

        unkSp2.u0 = unkPos.x / 256;
        unkSp2.u2 = unkPos.y / 256;

        if (unk6 != 0) {
            s32 someRetVal;

            sub_800EF10(sub_80412E0(move->id, GetApparentWeather(entity), 1));
            sub_803E46C(0x5E);
            someRetVal = sub_800E710(entInfo->apparentID, sub_80412E0(move->id, GetApparentWeather(entity), 1));
            if (someRetVal != -1) {
                sub_800569C(&unkSp1.unk8, &entity->spriteInfo, someRetVal);
            }
            else {
                unkSp1.unk8 = (Position) {0};
            }
            unkSp1.unk0 = sub_80412E0(move->id, GetApparentWeather(entity), 1);
            unkSp1.unk2 = entInfo->apparentID;
            unkSp1.unk4.x = entity->pixelPos.x / 256;
            unkSp1.unk4.y = entity->pixelPos.y / 256;
            unkSp1.unkC = entInfo->action.direction;
            unkSp1.unk10 = 0;

            return sub_800E308(&unkSp1, &unkSp2);
        }
    }

    return -1;
}
#else
NAKED s32 sub_8056564(Entity *entity, Position *pos, Move *move, s32 r4)
{
    asm_unified("push {r4-r7,lr}\n"
	"	mov r7, r9\n"
	"	mov r6, r8\n"
	"	push {r6,r7}\n"
	"	sub sp, 0x18\n"
	"	adds r6, r0, 0\n"
	"	adds r5, r1, 0\n"
	"	adds r7, r2, 0\n"
	"	adds r4, r3, 0\n"
	"	ldr r0, [r6, 0x70]\n"
	"	mov r8, r0\n"
	"	ldr r0, _08056680\n"
	"	ldr r0, [r0]\n"
	"	ldr r1, _08056684\n"
	"	adds r0, r1\n"
	"	ldrb r0, [r0]\n"
	"	mov r9, r0\n"
	"	cmp r0, 0\n"
	"	beq _0805658C\n"
	"	b _080566E4\n"
	"_0805658C:\n"
	"	mov r2, r8\n"
	"	movs r1, 0x4\n"
	"	ldrsh r0, [r2, r1]\n"
	"	bl GetBodySize\n"
	"	lsls r0, 24\n"
	"	lsrs r0, 24\n"
	"	cmp r0, 0x3\n"
	"	bls _080565A4\n"
	"	cmp r4, 0x1\n"
	"	bne _080565A4\n"
	"	b _080566E4\n"
	"_080565A4:\n"
	"	ldrh r4, [r7, 0x2]\n"
	"	adds r0, r6, 0\n"
	"	bl GetApparentWeather\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, 24\n"
	"	lsrs r1, 24\n"
	"	adds r0, r4, 0\n"
	"	movs r2, 0x1\n"
	"	bl sub_80412E0\n"
	"	lsls r0, 16\n"
	"	lsrs r0, 16\n"
	"	bl sub_800ECB8\n"
	"	movs r2, 0x6\n"
	"	ldrsh r4, [r0, r2]\n"
	"	movs r1, 0\n"
	"	ldrsh r0, [r5, r1]\n"
	"	lsls r1, r0, 1\n"
	"	adds r1, r0\n"
	"	lsls r1, 11\n"
	"	movs r0, 0x2\n"
	"	ldrsh r2, [r5, r0]\n"
	"	lsls r0, r2, 1\n"
	"	adds r0, r2\n"
	"	lsls r0, 11\n"
	"	movs r2, 0x80\n"
	"	lsls r2, 5\n"
	"	adds r3, r0, r2\n"
	"	movs r2, 0xC0\n"
	"	lsls r2, 4\n"
	"	adds r0, r1, r2\n"
	"	cmp r0, 0\n"
	"	bge _080565EC\n"
	"	adds r0, 0xFF\n"
	"_080565EC:\n"
	"	lsls r0, 8\n"
	"	lsrs r0, 16\n"
	"	ldr r1, _08056688\n"
	"	ldr r2, [sp, 0x14]\n"
	"	ands r2, r1\n"
	"	orrs r2, r0\n"
	"	str r2, [sp, 0x14]\n"
	"	adds r0, r3, 0\n"
	"	cmp r0, 0\n"
	"	bge _08056602\n"
	"	adds r0, 0xFF\n"
	"_08056602:\n"
	"	lsls r0, 8\n"
	"	lsrs r0, 16\n"
	"	lsls r0, 16\n"
	"	ldr r1, _0805668C\n"
	"	ands r2, r1\n"
	"	orrs r2, r0\n"
	"	str r2, [sp, 0x14]\n"
	"	cmp r4, 0\n"
	"	beq _080566E4\n"
	"	ldrh r4, [r7, 0x2]\n"
	"	adds r0, r6, 0\n"
	"	bl GetApparentWeather\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, 24\n"
	"	lsrs r1, 24\n"
	"	adds r0, r4, 0\n"
	"	movs r2, 0x1\n"
	"	bl sub_80412E0\n"
	"	lsls r0, 16\n"
	"	lsrs r0, 16\n"
	"	bl sub_800EF10\n"
	"	bl sub_800EF64\n"
	"	movs r0, 0x5E\n"
	"	bl sub_803E46C\n"
	"	mov r0, r8\n"
	"	movs r1, 0x4\n"
	"	ldrsh r5, [r0, r1]\n"
	"	ldrh r4, [r7, 0x2]\n"
	"	adds r0, r6, 0\n"
	"	bl GetApparentWeather\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, 24\n"
	"	lsrs r1, 24\n"
	"	adds r0, r4, 0\n"
	"	movs r2, 0x1\n"
	"	bl sub_80412E0\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, 16\n"
	"	lsrs r1, 16\n"
	"	adds r0, r5, 0\n"
	"	bl sub_800E710\n"
	"	adds r2, r0, 0\n"
	"	movs r0, 0x1\n"
	"	negs r0, r0\n"
	"	cmp r2, r0\n"
	"	beq _08056690\n"
	"	add r0, sp, 0x8\n"
	"	adds r1, r6, 0\n"
	"	adds r1, 0x28\n"
	"	lsls r2, 24\n"
	"	lsrs r2, 24\n"
	"	bl sub_800569C\n"
	"	b _08056694\n"
	"	.align 2, 0\n"
	"_08056680: .4byte gDungeon\n"
	"_08056684: .4byte 0x0001820a\n"
	"_08056688: .4byte 0xffff0000\n"
	"_0805668C: .4byte 0x0000ffff\n"
	"_08056690:\n"
	"	mov r2, r9\n"
	"	str r2, [sp, 0x8]\n"
	"_08056694:\n"
	"	ldrh r4, [r7, 0x2]\n"
	"	adds r0, r6, 0\n"
	"	bl GetApparentWeather\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, 24\n"
	"	lsrs r1, 24\n"
	"	adds r0, r4, 0\n"
	"	movs r2, 0x1\n"
	"	bl sub_80412E0\n"
	"	mov r1, sp\n"
	"	strh r0, [r1]\n"
	"	mov r2, r8\n"
	"	ldrh r0, [r2, 0x4]\n"
	"	strh r0, [r1, 0x2]\n"
	"	ldr r0, [r6, 0xC]\n"
	"	cmp r0, 0\n"
	"	bge _080566BC\n"
	"	adds r0, 0xFF\n"
	"_080566BC:\n"
	"	asrs r0, 8\n"
	"	strh r0, [r1, 0x4]\n"
	"	mov r1, sp\n"
	"	ldr r0, [r6, 0x10]\n"
	"	cmp r0, 0\n"
	"	bge _080566CA\n"
	"	adds r0, 0xFF\n"
	"_080566CA:\n"
	"	asrs r0, 8\n"
	"	strh r0, [r1, 0x6]\n"
	"	mov r0, r8\n"
	"	adds r0, 0x46\n"
	"	ldrb r0, [r0]\n"
	"	str r0, [sp, 0xC]\n"
	"	movs r0, 0\n"
	"	str r0, [sp, 0x10]\n"
	"	add r1, sp, 0x14\n"
	"	mov r0, sp\n"
	"	bl sub_800E308\n"
	"	b _080566E8\n"
	"_080566E4:\n"
	"	movs r0, 0x1\n"
	"	negs r0, r0\n"
	"_080566E8:\n"
	"	add sp, 0x18\n"
	"	pop {r3,r4}\n"
	"	mov r8, r3\n"
	"	mov r9, r4\n"
	"	pop {r4-r7}\n"
	"	pop {r1}\n"
	"	bx r1");
}
#endif // NONMATCHING

extern s32 sub_800ED20(u16 param_1);

extern const s32 gUnknown_81069D4[];

extern void sub_800E3AC(s32 a0, Position *pos, s32 a2);
extern void sub_8041168(Entity *entity, Entity *entity2, Move *,Position *);

s32 sub_8056F80(s32 a0, Entity **entitiesArray, s16 target, Entity *entity1, Entity *entity2, Move *move, bool8 arg8);

void sub_80566F8(Entity *entity, Move *move, s32 a2, bool8 a3, s32 itemId, s32 a5)
{
    Position var_68;
    Position var_64;
    Entity *var_60[2];
    s32 var_4C, var_48;
    s32 i, j;
    s32 var_40;
    s32 var_3C;
    s32 var_38;
    s32 var_34;
    s32 var_30;
    s32 var_2C;
    s32 var_28, var_24;
    s32 someCount;
    EntityInfo *entInfo;
    s32 unkRetVal;
    s32 divResult;
    s32 r9;

    var_40 = 0;
    someCount = 0;
    entInfo = GetEntInfo(entity);
    unkRetVal = sub_800ED20(move->id);
    var_30 = 2;
    if (unkRetVal != 1) {
        var_30 = 6;
        if (unkRetVal == 2) {
            var_30 = 3;
        }
    }

    var_68.x = entity->pos.x;
    var_68.y = entity->pos.y;
    var_4C = gAdjacentTileOffsets[entInfo->action.direction].x;
    var_48 = gAdjacentTileOffsets[entInfo->action.direction].y;
    for (i = 0; i < a2; i++)
    {
        Tile *tile;

        if (var_68.x < 0 || var_68.y < 0 || var_68.x > 55 || var_68.y > 31)
            break;

        var_68.x += var_4C;
        var_68.y += var_48;
        someCount++;
        tile = GetTile(var_68.x, var_68.y);
        if (!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
            break;
        if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER)
            break;
    }

    if (sub_805755C(entity, move->id) && !MoveMatchesChargingStatus(entity, move)) {
        var_34 = -1;
    }
    else {
        var_34 = sub_8056564(entity, &var_68, move, a2);
    }

    var_68.x = entity->pos.x;
    var_68.y = entity->pos.y;
    var_4C = gAdjacentTileOffsets[entInfo->action.direction].x;
    var_48 = gAdjacentTileOffsets[entInfo->action.direction].y;
    divResult = someCount * (24 / var_30);
    if (a2 > 1) {
        var_3C = divResult + 8;
        if (var_3C >= 64) {
            var_3C = 64;
        }
    }
    else {
        var_3C = 32;
    }

    r9 = 0;
    var_2C = 0x80000 / divResult;
    var_38 = gUnknown_81069D4[entInfo->action.direction];
    gDungeon->unk1BDD4.unk1C05E = 1;

    for (i = 0; i < a2; i++)
    {
        Position var_68Before;
        Tile *tile;

        if (var_68.x < 0 || var_68.y < 0 || var_68.x > 55 || var_68.y > 31)
            break;

        var_68Before = var_68;
        var_68.x += var_4C;
        var_68.y += var_48;
        if (sub_803F428(&var_68) && !gDungeon->unk181e8.blinded) {
            Position32 pos32;
            pos32.x = (var_68Before.x * 0x1800) + 0xC00;
            pos32.y = (var_68Before.y * 0x1800) + 0x1000;
            var_28 = var_30 * (var_4C << 8);
            var_24 = var_30 * (var_48 << 8);
            for (j = 0; j < 24 / var_30; j++) {
                if (var_34 >= 0) {
                    s32 r3;
                    s32 r2;

                    if (a3 != 0) {
                        r3 = sin_abs_4096(r9 / 256) * var_3C;
                    }
                    else {
                        r3 = 0;
                    }
                    var_64.x = pos32.x / 256;
                    var_64.y = (pos32.y - r3) / 256;
                    r2 = pos32.y / 256;
                    r2 -= gDungeon->unk181e8.cameraPixelPos.y;
                    r2 /= 2;
                    sub_800E3AC(var_34, &var_64, r2 + var_38);
                }
                sub_803E46C(0x30);
                pos32.x += var_28;
                pos32.y += var_24;
                r9 += var_2C;
            }
        }
        else {
            r9 += (24 / var_30) * var_2C;
        }

        tile = GetTile(var_68.x, var_68.y);
        if (!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
            break;
        if (tile->monster != NULL && GetEntityType(tile->monster) == ENTITY_MONSTER && !sub_80571F0(tile->monster, move)) {
            if (var_40 <= 0) {
                bool8 r4 = FALSE;
                s32 target;
                EntityInfo *entInfo = GetEntInfo(entity);
                if (entInfo->volatileStatus.volatileStatus == STATUS_CONFUSED
                    || entInfo->eyesightStatus.eyesightStatus == STATUS_BLINKER
                    || entInfo->volatileStatus.volatileStatus == STATUS_COWERING)
                {
                    r4 = TRUE;
                }
                target = GetMoveTargetAndRangeForPokemon(entity, move, FALSE);
                var_40 = sub_8056F80(var_40, var_60, target, entity, tile->monster, move, r4);
            }
            break;
        }
    }

    if (var_34 >= 0) {
        sub_800DC14(var_34);
    }
    sub_804178C(1);
    gDungeon->unk1BDD4.unk1C05E = 0;

    if (var_40 > 0) {
        var_60[var_40] = NULL;
        sub_8053704(var_60, entity, move, itemId, a5);
    }
    else if (a2 == 1 && sub_803F428(&var_68)) {
        sub_803E708(1, 0x4A);
        sub_8041168(entity, NULL, move, &var_68);
    }
}

//
