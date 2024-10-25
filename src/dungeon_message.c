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
#include "constants/iq_skill.h"
#include "type_chart.h"
#include "position_util.h"
#include "dungeon_items.h"
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
#include "text_util.h"
#include "dungeon_visibility.h"
#include "code_807CD9C.h"
#include "dungeon_engine.h"
#include "status_actions.h"

extern void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC);
extern void sub_806EAF4(Entity *, Entity *, u8, u32, u32, struct DamageStruct *dmgStruct, u32, u16, u32);
extern s16 sub_8057600(Move *move, s32 itemID);
extern void sub_803ED30(s32, Entity *r0, u8, s32);
extern void sub_8042238(Entity *pokemon, Entity *target);
extern void sub_806A1E8(Entity *pokemon);
extern void sub_80574C4(Entity **a0, Entity *a1);
extern bool8 sub_8044B28(void);
extern void sub_804178C(u32);
extern void sub_8071DA4(Entity *);
extern void sub_80428A0(Entity *r0);
extern bool8 sub_8040BB0(Entity *entity, Move *move, bool8);
extern void sub_8040DA0(Entity *entity, Move *move);
extern u16 sub_80412E0(u16 moveId, u8 weather, u8 a2);
extern void sub_800569C(Position *, EntitySpriteInfo *, u8);
extern u8 GetBodySize(s16 index);
extern void sub_800EF10(u16 r0);
extern s32 sub_800E710(s16 a0, u16 a1);
extern void sub_800E3AC(s32 a0, Position *pos, s32 a2);
extern void sub_8041168(Entity *entity, Entity *entity2, Move *,Position *);
extern Entity *sub_80696A8(Entity *a0);
extern Entity *sub_804AD0C(Position *pos);
extern Entity *sub_80696FC(Entity *);
extern Entity *sub_806977C(Entity *);
extern void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct);
extern void sub_806ACE8(Entity *entity, Move *move);
extern s32 sub_8057070(Move *move);
extern bool8 sub_805755C(Entity* pokemon,u16 param_2);
extern s32 sub_800ED20(u16 param_1);
extern bool32 sub_8058F04(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern void sub_8042930(Entity *r0);
extern void sub_8041B48(Entity *pokemon);
extern void sub_8041BA8(Entity *pokemon);
extern void sub_8042950(Entity *r0);
extern void sub_80421C0(Entity *pokemon, u16 r1);
extern bool8 sub_8057634(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 YawnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 NightmareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805783C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057974(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PainSplitMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057BC4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057C88(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WhirlpoolMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SurfMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805889C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057D7C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057D9C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057FCC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057FF4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805805C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805816C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80581D0(Entity *pokemon, Entity *target, Move *move, u32 param_4);
extern bool8 sub_8058B3C(Entity *pokemon, Entity *target, Move *move, u32 param_4);
extern bool8 sub_8058270(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80582C4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80583D8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058430(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058478(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80584C0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058548(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058638(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80586DC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058770(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80587E8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058838(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058858(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80588B8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80588F4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058930(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058C00(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058A18(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058BF0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058FBC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80590D4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059190(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80591E4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059424(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805946C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059540(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80595A0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80595EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805C138(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80598CC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059928(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059988(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059A2C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AA8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AB8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AF8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D00(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D48(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D98(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059DA4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059DB4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059DC4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059E0C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TriAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A120(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A210(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A258(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A2A0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A3DC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A464(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CurseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A568(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FocusEnergyMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A688(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 KnockOffMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SecretPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AC90(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD04(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD34(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD54(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AE3C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AE74(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AECC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PresentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AFA4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B028(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B074(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B0BC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B17C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WrapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B264(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B324(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DestinyBondMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B388(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B3E0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B454(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MimicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B53C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LeechSeedMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B668(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B910(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B808(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A408(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059050(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059FC8(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5);
extern bool8 sub_8059E54(Entity * pokemon,Entity * target,Move * move,u32 param_4,u8 param_5);
extern void SetShopkeeperAggression(Entity *, Entity *);
extern bool8 MoveCausesPaused(Move *move);
extern void sub_8069F9C(Entity *pokemon,Entity * target,Move *move);
extern void sub_806A120(Entity *pokemon,Entity * target,Move *move);
extern bool8 sub_8058C98(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5);
extern bool8 sub_805B3FC(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5);
extern bool8 sub_805A5E8(Entity *pokemon, Entity *target, Move *move, u32 param_4, u32 param_5);
extern bool8 sub_8058B84(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059714(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80576F8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059080(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D58(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B164(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059A18(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BulkUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80582D4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059B94(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B3B4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059588(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A2B0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B2FC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059CD8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058A7C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057F7C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057ED0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058CEC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A2C8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057C68(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SolarBeamMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SkyAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058D38(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SandstormMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SafeguardMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MistMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LightScreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805768C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057F24(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80599EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80589D4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AC4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A4D4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058EE0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058A08(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CounterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BideMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805836C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TrapperOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A450(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RazorWindMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FocusPunchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MagicCoatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057748(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MudWaterSportMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A4FC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058C48(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SpikesMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80578EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80588A8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WishMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057E6C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059CF0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80582AC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058A54(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 VitalThrowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FlyMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059F38(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DiveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DigMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057824(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805825C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GrudgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A4C0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AAD0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B314(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ProtectMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059004(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80597F0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ChargeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058D44(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 StockpileMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SpitUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SwallowMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RainDanceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 InvisifyOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MirrorCoatMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PerishSongMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057CD0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SunnyDayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EndureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HelpingHandMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BellyDrumMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80578FC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057BB4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TransformMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058234(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A85C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ReboundOrbAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 NaturePowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SketchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057E50(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ConversionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SnatchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HandleColorChange(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PsychUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SnoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B618(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 Conversion2MoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);

s32 HandleDamagingMove(Entity *, Entity *, Move *, s32, s32);
static s32 TryHitTarget(Entity *attacker, Entity *target, Move *move, struct DamageStruct *dmgStruct, s16 unk);
static void TriggerTargetAbilityEffect(Entity *attacker);
static bool8 AccuracyCalc(Entity *attacker, Entity *target, Move *move, s32 accuracyType, bool8 selfAlwaysHits);
bool8 TryUseChosenMove(struct Entity *attacker, u32 r6, s32 itemId, u32 var_30, bool32 isLinkedMove, struct Move *move);
bool8 sub_8056468(Entity *entity, Move *move, const u8 *str, Entity **unkArray, bool32 itemId, bool8 arg_4, bool32 unused);
bool8 sub_805744C(Entity * pokemon, Move *move, bool8 param_3);
static void SetTargetsForMove(Entity **targetsArray, Entity *attacker, Move *move);
void sub_80566F8(Entity *attacker, Move *move, s32 a2, bool8 a3, s32 itemId, s32 isLinkedMove);
static s32 SetNewTarget(s32 targetArrId, Entity **targetsArray, s32 targetFlags_, Entity *attacker, Entity *target, Move *move, bool32 canHitAnyone_);
bool8 sub_8055988(Entity *r2, Entity *r4);
void sub_80559DC(Entity *entity1, Entity *entity2);

extern const s32 gUnknown_8106A50;
extern const s32 gUnknown_8106A4C;
extern const s16 gUnknown_80F5006;
extern const s32 gUnknown_80F519C;
extern const s32 gUnknown_80F51A0;
extern const s32 gUnknown_80F50F4[2][21];
extern const s32 gUnknown_81069D4[];
extern const s32 gUnknown_81069BC[];
extern const s16 gUnknown_80F4E70[];
extern const s16 gUnknown_80F4E74[];
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
extern const u8 *const gUnknown_80F9688;
extern const u8 *const gUnknown_80FC714;
extern const u8 *const gUnknown_80FC718;
extern const u8 *const gUnknown_80FC6A8;
extern const u8 *const gUnknown_80FD2D0;
extern const u8 *const gUnknown_80FD2DC;
extern const u8 *const gUnknown_80F93C8;
extern const u8 *const gUnknown_80FC690;
extern const u8 *const gUnknown_80FC6A4;
extern const u8 *const gUnknown_80FCD28;
extern const u8 *const gUnknown_80FCD0C;
extern const u8 *const gUnknown_80FDD88;
extern const u8 *const gUnknown_80FDD20;
extern const u8 *const gUnknown_80FDDA8;
extern const u8 *const gUnknown_80FDD48;
extern const u8 *const gUnknown_80FDDAC;
extern const u8 *const gUnknown_80FC52C;
extern const u8 *const gUnknown_80FC558;
extern const u8 *const gUnknown_80FC574;
extern const u8 *const gUnknown_8100524;
extern const u8 *const gUnknown_80F9364;
extern const u8 *const gUnknown_80F93A4;
extern const u8 *const gUnknown_80F9384;
extern const u8 *const gUnknown_80F9380;

extern u8 gFormatItems[];
extern u8 gUnknown_202F221;
extern u8 gUnknown_202F222;
extern s32 gUnknown_202F208;
extern s32 gMetronomeCalledArrayId;
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

#define MAX_MOVE_TARGETS 64

static void UseMoveAgainstTargets(Entity **targetsArray, Entity *attacker, Move *move, s32 itemId, bool32 isLinkedMove)
{
    s32 i = 0;
    u16 moveId;
    Entity *originalAttacker;
    Entity *currTargetSaved;
    Entity *currTarget;
    EntityInfo *targetInfo;
    bool32 moveHits;
    bool32 lightRodRedirect;
    bool32 moveRedirected;

    moveId = move->id;
    for (i = 0; i < MAX_MOVE_TARGETS; i++) {
        currTargetSaved = NULL; // Only for Pass Scarf
        currTarget = targetsArray[i];
        moveHits = TRUE;
        lightRodRedirect = FALSE;
        moveRedirected = FALSE;
        if (currTarget == NULL)
            break;
        if (!EntityExists(attacker))
            break;
        if (EntityExists(currTarget)) {
            bool32 r4;
            bool8 moveHadEffect;

            originalAttacker = attacker;
            targetInfo = GetEntInfo(currTarget);
            targetInfo->unk15A = 0;
            if (CanBeSnatched(moveId) && gDungeon->snatchPokemon != NULL) {
                Entity *snatchMon = gDungeon->snatchPokemon;
                if (GetEntityType(snatchMon) == ENTITY_MONSTER
                    && snatchMon != attacker
                    &&  GetEntInfo(snatchMon)->unk98 == gDungeon->unk17B3C
                    && targetInfo->unkFF == 0)
                {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FCD28); // The move was snatched.
                    currTarget = snatchMon;
                }
            }
            else if (GetMoveTypeForMonster(attacker, move) == TYPE_ELECTRIC && gDungeon->lightningRodPokemon != NULL) {
                Entity *lightRodMon = gDungeon->lightningRodPokemon;
                if (GetEntityType(lightRodMon) == ENTITY_MONSTER) {
                    EntityInfo *lightRodInfo = GetEntInfo(lightRodMon);
                    if (lightRodInfo->unk98 == gDungeon->unk17B38
                        && GetTreatmentBetweenMonsters(lightRodMon, attacker, TRUE, FALSE) == 1
                        && ((targetInfo->unkFF == 0 && lightRodInfo->unkFF == 0) || currTarget == lightRodMon))
                    {
                        sub_8042930(lightRodMon);
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FCD0C); // A Lightningrod took the move
                        currTarget = lightRodMon;
                        lightRodRedirect = TRUE;
                    }
                }
            }
            else if (HasHeldItem(currTarget, ITEM_PASS_SCARF)) {
                if (!CannotAttack(currTarget, FALSE)
                    && (GetMoveTargetAndRangeForPokemon(attacker, move, FALSE) & 0xF0) == 0
                    && FixedPointToInt(targetInfo->belly) >= gUnknown_80F5006
                    && targetInfo->unkFF == 0)
                {
                    s32 direction1 = targetInfo->action.direction;
                    s32 direction2 = targetInfo->action.direction;
                    if (IsBossFight()) {
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDD88); // A mysterious force prevents moves from being passed off!
                    }
                    else {
                        s32 j;
                        Entity *tileEntity;

                        for (j = 0; j < 8; j++) {
                            direction2++;
                            direction2 &= DIRECTION_MASK;
                            tileEntity = GetTile(currTarget->pos.x + gAdjacentTileOffsets[direction2].x, currTarget->pos.y + gAdjacentTileOffsets[direction2].y)->monster;
                            if (EntityExists(tileEntity) && GetEntityType(tileEntity) == ENTITY_MONSTER) {
                                if (sub_8045888(currTarget)) {
                                    s32 k;
                                    for (k = 0; k < 24; k++) {
                                        sub_806CE68(currTarget, direction1);
                                        sub_803E708(2, 0x43);
                                        direction1++;
                                        direction1 &= DIRECTION_MASK;
                                    }
                                    while (direction1 != direction2) {
                                        sub_806CE68(currTarget, direction1);
                                        sub_803E708(2, 0x43);
                                        direction1++;
                                        direction1 &= DIRECTION_MASK;
                                    }
                                    sub_806CE68(currTarget, direction1);
                                    sub_803E708(2, 0x43);
                                }
                                targetInfo->belly = FixedPoint_Subtract(targetInfo->belly, IntToFixedPoint(gUnknown_80F5006));
                                if (move->id == MOVE_REGULAR_ATTACK) {
                                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDDA8); // Attack was passed off
                                }
                                else {
                                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDD20); // Move was passed off
                                }
                                currTargetSaved = currTarget;
                                currTarget = tileEntity;
                                break;
                            }
                        }
                        if (j == 8) {
                            if (move->id == MOVE_REGULAR_ATTACK) {
                                TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDDAC); // There's no one to pass off to!
                            }
                            else {
                                TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FDD48); //There's no one to pass off to!
                            }
                        }
                    }
                }
            }

            gUnknown_202F208++;
            gUnknown_202F20C++;
            targetInfo = currTarget->info; // currTarget could've been changed, hence info pointers needs to be reloaded
            targetInfo->unk15A = 0;
            if (targetInfo->isNotTeamMember) {
                targetInfo->targetPos = attacker->pos;
            }
            sub_806A1E8(currTarget);
            TrySendImmobilizeSleepEndMsg(attacker, currTarget);
            r4 = FALSE;
            if (!MoveMatchesChargingStatus(attacker, move)) {
                r4 = (sub_805755C(attacker, move->id) != 0);
            }

            if (!lightRodRedirect) {
                if (targetInfo->protection.protectionStatus == STATUS_MAGIC_COAT) {
                    if (IsReflectedByMagicCoat(moveId) && sub_8055988(attacker, currTarget)) {
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FC52C); // The target~27s Magic Coat bounced it back!
                        sub_8041B48(currTarget);
                        sub_80559DC(currTarget, attacker);
                        currTarget = attacker;
                        targetInfo = attacker->info;
                        targetInfo->unk15A = 0;
                        moveRedirected = TRUE;
                    }
                }
                else if (targetInfo->protection.protectionStatus == STATUS_MIRROR_MOVE) {
                    s32 target = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
                    if (moveId != MOVE_REGULAR_ATTACK
                        && moveId != MOVE_PROJECTILE
                        && !r4
                        && ((target & 0xF) == 0 || (target & 0xF) == 4 || (target & 0xF) == 5 || (target & 0xF) == 2)
                        && sub_8055988(attacker, currTarget))
                    {
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FC558); // The target~27s Mirror Move returned it!
                        sub_8041BA8(currTarget);
                        sub_80559DC(currTarget, attacker);
                        currTarget = attacker;
                        targetInfo = attacker->info;
                        targetInfo->unk15A = 0;
                        moveRedirected = TRUE;
                    }
                }
            }
            if (!lightRodRedirect) {
                if (targetInfo->protection.protectionStatus == STATUS_PROTECT) {
                    s16 targetFlags = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
                    s32 targetFlagsAnd = targetFlags & 0xF;
                    if ((targetFlagsAnd == 0 || targetFlagsAnd == 4 || targetFlagsAnd == 5 || targetFlagsAnd == 2) && !r4) {
                        SetMessageArgument(gUnknown_202DFE8, currTarget, 0);
                        TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80FC574); // protected itself!
                        moveHits = FALSE;
                    }
                }
            }

            if (sub_80571F0(currTarget, move)) {
                moveHits = FALSE;
            }

            if (moveHits) {
                if (HasAbility(currTarget, ABILITY_SOUNDPROOF) && IsSoundMove(move)) {
                    SetMessageArgument(gUnknown_202DFE8, currTarget, 0);
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_8100524); // Soundproof suppressed the sound move!
                    moveHits = FALSE;
                }
            }
            if (moveHits) {
                bool8 selfAlwaysHits = (moveRedirected == FALSE);
                if (move->id == MOVE_ENDURE || move->id == MOVE_DETECT || move->id == MOVE_PROTECT) {
                    selfAlwaysHits = FALSE;
                }
                if (!AccuracyCalc(attacker, currTarget, move, ACCURACY_1, selfAlwaysHits)) {
                    moveHits = FALSE;
                }
            }

            if (moveHits && lightRodRedirect) {
                moveHits = FALSE;
            }

            if (sub_8045888(currTarget)) {
                sub_803E708(4, 0x4A);
                sub_8041168(attacker, currTarget, move, NULL);
            }

            if (!moveHits) {
                if (GetEntInfo(attacker)->isTeamLeader) {
                    sub_80421C0(attacker, 0x156);
                }
                else {
                    sub_80421C0(attacker, 0x157);
                }
                SetMessageArgument_2(gUnknown_202DFE8, GetEntInfo(currTarget), 0);
                // Interesting that these 3 strings are the same. Curious if that's the case in Blue/Europe versions.
                if (attacker == currTarget) {
                    TryDisplayDungeonLoggableMessage3(attacker, attacker, gUnknown_80F9380); // The move missed
                }
                else if (GetTreatmentBetweenMonsters(attacker, currTarget, TRUE, FALSE) == 0) {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80F9384); // The move missed
                }
                else if (lightRodRedirect) {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80F93A4); // The move missed
                }
                else {
                    TryDisplayDungeonLoggableMessage3(attacker, currTarget, gUnknown_80F9364); // is unaffected!
                }

                if (sub_8045888(currTarget)) {
                    sub_803ED30(9999, currTarget, 1, -1);
                }

                switch (moveId) {
                    case MOVE_HI_JUMP_KICK:
                        sub_8059FC8(attacker, currTarget, move, itemId, 1);
                        break;
                    case MOVE_JUMP_KICK:
                        sub_8059E54(attacker, currTarget, move, itemId, 1);
                        break;

                }

                if (sub_8044B28())
                    break; // breaks out of the loop
            }
            else {
                s32 expMultiplierBeforeMove = targetInfo->expMultiplier;
                if (targetInfo->isNotTeamMember) {
                    if (move->id != MOVE_REGULAR_ATTACK && itemId == 0 && expMultiplierBeforeMove == EXP_HALVED) {
                        targetInfo->expMultiplier = EXP_REGULAR;
                    }
                    if (isLinkedMove == TRUE) {
                        targetInfo->expMultiplier = EXP_BOOSTED;
                    }
                }

                if (targetInfo->unk164 == 0xFF && sub_80717A4(currTarget, MOVE_SLEEP_TALK)) {
                    targetInfo->unk164 = GetDirectionTowardsPosition(&currTarget->pos, &attacker->pos);
                }
                if (targetInfo->unk165 == 0xFF && sub_80717A4(currTarget, MOVE_SNORE)) {
                    targetInfo->unk165 = GetDirectionTowardsPosition(&currTarget->pos, &attacker->pos);
                }

                if (HasAbility(currTarget, ABILITY_PRESSURE)
                    && GetTreatmentBetweenMonsters(attacker, currTarget, TRUE, FALSE) == 1
                    && move->id != MOVE_REGULAR_ATTACK
                    && move->id != MOVE_STRUGGLE
                    && itemId == 0
                    && move->PP != 0)
                {
                    if (!(move->moveFlags2 & MOVE_FLAG2_x10)) {
                        sub_8042950(attacker);
                    }
                    move->moveFlags2 |= MOVE_FLAG2_x10;
                }

                if ((GetMoveTargetAndRangeForPokemon(attacker, move, FALSE) & 0xF) == 0) {
                    SetShopkeeperAggression(attacker, currTarget);
                }
                targetInfo->unk158 = 1;

                // They really must've had a soft spot for all these giant switches
                switch (moveId) {
                    case 9:
                    case 18:
                    case 28:
                    case 39:
                    case 126:
                    case 132:
                    case 136:
                    case 145:
                    case 154:
                    case 158:
                    case 161:
                    case 163:
                    case 166:
                    case 167:
                    case 168:
                    case 174:
                    case 175:
                    case 176:
                    case 178:
                    case 179:
                    case 180:
                    case 182:
                    case 189:
                    case 190:
                    case 201:
                    case 208:
                    case 211:
                    case 222:
                    case 240:
                    case 241:
                    case 248:
                    case 250:
                    case 260:
                    case 285:
                    case 290:
                    case 297:
                    case 300:
                    case 306:
                    case 308:
                    case 311:
                    case 312:
                    case 321:
                    case 322:
                    case 323:
                    case 346:
                    case 347:
                    case 350:
                    case 353:
                    case 360:
                    case 362:
                    case 366:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, 0x100, itemId) != 0);
                        break;
                    case MOVE_REGULAR_ATTACK:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, 0x80, itemId) != 0);
                        break;
                    case MOVE_NOTHING:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, 0, itemId) != 0);
                        break;
                    case MOVE_EARTHQUAKE:
                        moveHadEffect = sub_8058F04(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_GUST:
                        moveHadEffect = sub_8058270(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_STRUGGLE:
                        moveHadEffect = sub_805B968(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FLAME_WHEEL:
                        moveHadEffect = sub_805816C(attacker, currTarget, move, itemId);
                        break;
                    case 53:
                    case 157:
                    case 230:
                    case 262:
                    case 292:
                        moveHadEffect = sub_80581D0(attacker, currTarget, move, itemId);
                        break;
                    case 101:
                    case 270:
                    case 344:
                    case 345:
                        moveHadEffect = sub_8058B3C(attacker, currTarget, move, itemId);
                        break;
                    case 238:
                    case 239:
                    case 242:
                        moveHadEffect = sub_805A568(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_FOCUS_ENERGY:
                        moveHadEffect = FocusEnergyMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 36:
                    case 68:
                    case 81:
                    case 87:
                    case 90:
                    case 251:
                    case MOVE_LEAF_BLADE:
                        moveHadEffect = (HandleDamagingMove(attacker, currTarget, move, 0x100, itemId) != 0);
                        break;
                    case MOVE_FISSURE:
                        moveHadEffect = sub_80590D4(attacker, currTarget, move, itemId);
                        break;
                    case 150:
                    case 247:
                        moveHadEffect = sub_80595EC(attacker, currTarget, move, itemId);
                        break;
                    case 392:
                        moveHadEffect = sub_805C138(attacker, currTarget, move, itemId);
                        break;
                    case 69:
                    case 125:
                    case 143:
                    case 291:
                        moveHadEffect = sub_805B17C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WHIRLPOOL:
                        moveHadEffect = WhirlpoolMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SURF:
                        moveHadEffect = SurfMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 86:
                    case 89:
                        moveHadEffect = sub_805889C(attacker, currTarget, move, itemId);
                        break;
                    case 200:
                    case 279:
                    case 280:
                        moveHadEffect = sub_8059E0C(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PSYCHIC:
                        moveHadEffect = sub_8058C98(attacker, currTarget, move, gUnknown_8106A50, itemId);
                        break;
                    case 332:
                        moveHadEffect = sub_8058C98(attacker, currTarget, move, gUnknown_8106A4C, itemId);
                        break;
                    case 325:
                        moveHadEffect = sub_805B3FC(attacker, currTarget, move, gUnknown_8106A4C, itemId);
                        break;
                    case 244:
                        moveHadEffect = sub_805A5E8(attacker, currTarget, move, gUnknown_8106A4C, itemId);
                        break;
                    case 283:
                        moveHadEffect = sub_805B074(attacker, currTarget, move, itemId);
                        break;
                    case 162:
                        moveHadEffect = sub_8059928(attacker, currTarget, move, itemId);
                        break;
                    case 71:
                    case 255:
                        moveHadEffect = sub_8058580(attacker, currTarget, move, itemId);
                        break;
                    case 82:
                    case 93:
                        moveHadEffect = sub_8058930(attacker, currTarget, move, itemId);
                        break;
                    case 107:
                    case 114:
                    case 234:
                        moveHadEffect = sub_8058C00(attacker, currTarget, move, itemId);
                        break;
                    case 309:
                        moveHadEffect = sub_805B324(attacker, currTarget, move, itemId);
                        break;
                    case 335:
                        moveHadEffect = sub_805B910(attacker, currTarget, move, itemId);
                        break;
                    case 275:
                        moveHadEffect = sub_805AE74(attacker, currTarget, move, itemId);
                        break;
                    case 147:
                        moveHadEffect = sub_8059540(attacker, currTarget, move, itemId);
                        break;
                    case 149:
                        moveHadEffect = sub_80595A0(attacker, currTarget, move, itemId);
                        break;
                    case 188:
                        moveHadEffect = sub_8059D00(attacker, currTarget, move, itemId);
                        break;
                    case 120:
                    case 144:
                    case 235:
                    case 342:
                        moveHadEffect = sub_8058FBC(attacker, currTarget, move, itemId);
                        break;
                    case 133:
                    case 261:
                    case 289:
                        moveHadEffect = sub_8059190(attacker, currTarget, move, itemId);
                        break;
                    case 63:
                    case 221:
                    case 271:
                    case 303:
                        moveHadEffect = sub_8058430(attacker, currTarget, move, itemId);
                        break;
                    case 139:
                        moveHadEffect = sub_8059424(attacker, currTarget, move, itemId);
                        break;
                    case 30:
                    case 46:
                        moveHadEffect = sub_8057C88(attacker, currTarget, move, itemId);
                        break;
                    case 62:
                    case 127:
                        moveHadEffect = sub_80583D8(attacker, currTarget, move, itemId);
                        break;
                    case 264:
                    case 310:
                        moveHadEffect = sub_805AC90(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_TRI_ATTACK:
                        moveHadEffect = TriAttackMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 103:
                        moveHadEffect = sub_8058B84(attacker, currTarget, move, itemId);
                        break;
                    case 276:
                        moveHadEffect = sub_805AECC(attacker, currTarget, move, itemId);
                        break;
                    case 326:
                        moveHadEffect = sub_805B454(attacker, currTarget, move, itemId);
                        break;
                    case 59:
                        moveHadEffect = sub_80582C4(attacker, currTarget, move, itemId);
                        break;
                    case 226:
                        moveHadEffect = sub_805A408(attacker, currTarget, move, itemId);
                        break;
                    case 152:
                        moveHadEffect = sub_8059714(attacker, currTarget, move, itemId);
                        break;
                    case 341:
                        moveHadEffect = sub_805B808(attacker, currTarget, move, itemId);
                        break;
                    case 124:
                        moveHadEffect = sub_8059050(attacker, currTarget, move, itemId);
                        break;
                    case 64:
                    case 65:
                        moveHadEffect = sub_8058478(attacker, currTarget, move, itemId);
                        break;
                    case 4:
                    case 34:
                    case 79:
                    case 84:
                    case 111:
                    case 231:
                        moveHadEffect = sub_80576F8(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_YAWN:
                        moveHadEffect = YawnMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 129:
                        moveHadEffect = sub_8059080(attacker, currTarget, move, itemId);
                        break;
                    case 194:
                        moveHadEffect = sub_8059D98(attacker, currTarget, move, itemId);
                        break;
                    case 177:
                        moveHadEffect = sub_8059AF8(attacker, currTarget, move, itemId);
                        break;
                    case 13:
                    case 171:
                    case 191:
                    case 274:
                    case 382:
                        moveHadEffect = sub_8059AA8(attacker, currTarget, move, itemId);
                        break;
                    case 196:
                    case 199:
                        moveHadEffect = sub_8059DA4(attacker, currTarget, move, itemId);
                        break;
                    case 192:
                        moveHadEffect = sub_8059D48(attacker, currTarget, move, itemId);
                        break;
                    case 281:
                        moveHadEffect = sub_805B028(attacker, currTarget, move, itemId);
                        break;
                    case 193:
                        moveHadEffect = sub_8059D58(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_SUPERPOWER:
                        moveHadEffect = TickleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 73:
                    case 97:
                    case 299:
                        moveHadEffect = sub_8058638(attacker, currTarget, move, itemId);
                        break;
                    case 246:
                        moveHadEffect = sub_805A688(attacker, currTarget, move, itemId);
                        break;
                    case 33:
                        moveHadEffect = sub_8057D7C(attacker, currTarget, move, itemId);
                        break;
                    case 268:
                    case 284:
                    case 368:
                        moveHadEffect = sub_805B0BC(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_PAIN_SPLIT:
                        moveHadEffect = PainSplitMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 288:
                        moveHadEffect = sub_805B164(attacker, currTarget, move, itemId);
                        break;
                    case 169:
                        moveHadEffect = sub_8059A18(attacker, currTarget, move, itemId);
                        break;
                    case 343:
                        moveHadEffect = sub_805B884(attacker, currTarget, move, itemId);
                        break;
                    case 265:
                        moveHadEffect = BulkUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 55:
                    case 195:
                    case 333:
                        moveHadEffect = sub_80582D4(attacker, currTarget, move, itemId);
                        break;
                    case 19:
                        moveHadEffect = RageMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 181:
                        moveHadEffect = sub_8059B94(attacker, currTarget, move, itemId);
                        break;
                    case 319:
                        moveHadEffect = sub_805B3B4(attacker, currTarget, move, itemId);
                        break;
                    case 148:
                        moveHadEffect = sub_8059588(attacker, currTarget, move, itemId);
                        break;
                    case 215:
                        moveHadEffect = sub_805A2B0(attacker, currTarget, move, itemId);
                        break;
                    case 302:
                        moveHadEffect = sub_805B2FC(attacker, currTarget, move, itemId);
                        break;
                    case 186:
                    case 202:
                    case 258:
                        moveHadEffect = sub_8059CD8(attacker, currTarget, move, itemId);
                        break;
                    case 99:
                        moveHadEffect = sub_8058A7C(attacker, currTarget, move, itemId);
                        break;
                    case 159:
                        moveHadEffect = sub_80598CC(attacker, currTarget, move, itemId);
                        break;
                    case 44:
                        moveHadEffect = sub_8057F7C(attacker, currTarget, move, itemId);
                        break;
                    case 42:
                        moveHadEffect = sub_8057ED0(attacker, currTarget, move, itemId);
                        break;
                    case 110:
                        moveHadEffect = sub_8058CEC(attacker, currTarget, move, itemId);
                        break;
                    case 106:
                    case 351:
                        moveHadEffect = sub_8058BF0(attacker, currTarget, move, itemId);
                        break;
                    case 217:
                        moveHadEffect = sub_805A2C8(attacker, currTarget, move, itemId);
                        break;
                    case 267:
                        moveHadEffect = sub_805AD34(attacker, currTarget, move, itemId);
                        break;
                    case 27:
                        moveHadEffect = sub_8057C68(attacker, currTarget, move, itemId);
                        break;
                    case 170:
                    case 216:
                        moveHadEffect = sub_8059A2C(attacker, currTarget, move, itemId);
                        break;
                    case 76:
                    case 80:
                    case 320:
                        moveHadEffect = sub_80586DC(attacker, currTarget, move, itemId);
                        break;
                    case 140:
                        moveHadEffect = sub_805946C(attacker, currTarget, move, itemId);
                        break;
                    case 116:
                    case 203:
                    case 354:
                        moveHadEffect = sub_8058E5C(attacker, currTarget, move, itemId);
                        break;
                    case 135:
                        moveHadEffect = sub_80591E4(attacker, currTarget, move, itemId);
                        break;
                    case 24:
                        moveHadEffect = sub_8057BC4(attacker, currTarget, move, itemId);
                        break;
                    case 210:
                        moveHadEffect = sub_805A210(attacker, currTarget, move, itemId);
                        break;
                    case 164:
                        moveHadEffect = sub_8059988(attacker, currTarget, move, itemId);
                        break;
                    case 151:
                        moveHadEffect = SolarBeamMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 100:
                        moveHadEffect = SkyAttackMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 371:
                        moveHadEffect = sub_805BE90(attacker, currTarget, move, itemId);
                        break;
                    case 91:
                    case 253:
                        moveHadEffect = sub_80588B8(attacker, currTarget, move, itemId);
                        break;
                    case 294:
                        moveHadEffect = WrapMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 112:
                        moveHadEffect = sub_8058D38(attacker, currTarget, move, itemId);
                        break;
                    case 198:
                        moveHadEffect = sub_8059DC4(attacker, currTarget, move, itemId);
                        break;
                    case 277:
                        moveHadEffect = PresentMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 338:
                        moveHadEffect = ReflectMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 141:
                        moveHadEffect = SandstormMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 134:
                        moveHadEffect = SafeguardMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 130:
                        moveHadEffect = MistMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 259:
                        moveHadEffect = LightScreenMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 2:
                    case 105:
                        moveHadEffect = sub_805768C(attacker, currTarget, move, itemId);
                        break;
                    case 43:
                        moveHadEffect = sub_8057F24(attacker, currTarget, move, itemId);
                        break;
                    case 165:
                    case 318:
                        moveHadEffect = sub_80599EC(attacker, currTarget, move, itemId);
                        break;
                    case 94:
                        moveHadEffect = sub_80589D4(attacker, currTarget, move, itemId);
                        break;
                    case 173:
                        moveHadEffect = sub_8059AC4(attacker, currTarget, move, itemId);
                        break;
                    case 232:
                        moveHadEffect = sub_805A4D4(attacker, currTarget, move, itemId);
                        break;
                    case 117:
                    case 218:
                        moveHadEffect = sub_8058EE0(attacker, currTarget, move, itemId);
                        break;
                    case 386:
                        moveHadEffect = ScannerOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 209:
                        moveHadEffect = sub_805A120(attacker, currTarget, move, itemId);
                        break;
                    case 364:
                        moveHadEffect = sub_805BA50(attacker, currTarget, move, itemId);
                        break;
                    case 214:
                    case 287:
                        moveHadEffect = sub_805A2A0(attacker, currTarget, move, itemId);
                        break;
                    case 95:
                    case 372:
                        moveHadEffect = sub_8058A08(attacker, currTarget, move, itemId);
                        break;
                    case 38:
                    case 51:
                        moveHadEffect = CounterMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 61:
                    case 340:
                        moveHadEffect = BideMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 357:
                        moveHadEffect = sub_805836C(attacker, currTarget, move, itemId);
                        break;
                    case 401:
                        moveHadEffect = TrapperOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 227:
                        moveHadEffect = sub_805A450(attacker, currTarget, move, itemId);
                        break;
                    case 237:
                        moveHadEffect = CurseMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 206:
                        moveHadEffect = sub_8059FC8(attacker, currTarget, move, itemId, 0);
                        break;
                    case 272:
                        moveHadEffect = sub_805AE3C(attacker, currTarget, move, itemId);
                        break;
                    case 324:
                        moveHadEffect = sub_805B3E0(attacker, currTarget, move, itemId);
                        break;
                    case 60:
                        moveHadEffect = RazorWindMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 75:
                        moveHadEffect = FocusPunchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 298:
                        moveHadEffect = MagicCoatMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 5:
                        moveHadEffect = NightmareMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 6:
                        moveHadEffect = sub_8057748(attacker, currTarget, move, itemId);
                        break;
                    case 394:
                        moveHadEffect = sub_805C1BC(attacker, currTarget, move, itemId);
                        break;
                    case 212:
                    case 307:
                        moveHadEffect = MudWaterSportMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 1:
                        moveHadEffect = sub_8057634(attacker, currTarget, move, itemId);
                        break;
                    case 122:
                    case 224:
                        moveHadEffect = sub_805A3DC(attacker, currTarget, move, itemId);
                        break;
                    case 47:
                        moveHadEffect = sub_8057FF4(attacker, currTarget, move, itemId);
                        break;
                    case 233:
                        moveHadEffect = sub_805A4FC(attacker, currTarget, move, itemId);
                        break;
                    case 108:
                        moveHadEffect = sub_8058C48(attacker, currTarget, move, itemId);
                        break;
                    case 329:
                        moveHadEffect = LeechSeedMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 295:
                        moveHadEffect = SpikesMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 15:
                    case 26:
                    case 339:
                        moveHadEffect = sub_80578EC(attacker, currTarget, move, itemId);
                        break;
                    case 88:
                        moveHadEffect = sub_80588A8(attacker, currTarget, move, itemId);
                        break;
                    case 387:
                        moveHadEffect = RadarOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 381:
                        moveHadEffect = sub_805BC70(attacker, currTarget, move, itemId);
                        break;
                    case 78:
                        moveHadEffect = sub_80587E8(attacker, currTarget, move, itemId);
                        break;
                    case 296:
                        moveHadEffect = sub_805B264(attacker, currTarget, move, itemId);
                        break;
                    case 348:
                        moveHadEffect = SkullBashMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 225:
                        moveHadEffect = WishMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 45:
                        moveHadEffect = sub_8057FCC(attacker, currTarget, move, itemId);
                        break;
                    case 213:
                        moveHadEffect = sub_805A258(attacker, currTarget, move, itemId);
                        break;
                    case 142:
                    case 146:
                    case 273:
                        moveHadEffect = sub_8059528(attacker, currTarget, move, itemId);
                        break;
                    case 41:
                        moveHadEffect = sub_8057E6C(attacker, currTarget, move, itemId);
                        break;
                    case 197:
                        moveHadEffect = sub_8059DB4(attacker, currTarget, move, itemId);
                        break;
                    case 83:
                        moveHadEffect = sub_8058838(attacker, currTarget, move, itemId);
                        break;
                    case 22:
                        moveHadEffect = TormentMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 20:
                        moveHadEffect = sub_8057974(attacker, currTarget, move, itemId);
                        break;
                    case 314:
                        moveHadEffect = sub_805B388(attacker, currTarget, move, itemId);
                        break;
                    case 383:
                        moveHadEffect = sub_805BC98(attacker, currTarget, move, itemId);
                        break;
                    case 66:
                        moveHadEffect = sub_80584C0(attacker, currTarget, move, itemId);
                        break;
                    case 252:
                    case 367:
                        moveHadEffect = sub_805BB74(attacker, currTarget, move, itemId);
                        break;
                    case 331:
                        moveHadEffect = sub_805B668(attacker, currTarget, move, itemId);
                        break;
                    case 373:
                        moveHadEffect = LuminousOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 400:
                        moveHadEffect = FillInOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 187:
                    case 369:
                        moveHadEffect = sub_8059CF0(attacker, currTarget, move, itemId);
                        break;
                    case 388:
                        moveHadEffect = sub_805BF34(attacker, currTarget, move, itemId);
                        break;
                    case 409:
                        moveHadEffect = StairsOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 72:
                        moveHadEffect = BrickBreakMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 58:
                    case 70:
                        moveHadEffect = sub_80582AC(attacker, currTarget, move, itemId);
                        break;
                    case 98:
                    case 349:
                        moveHadEffect = sub_8058A54(attacker, currTarget, move, itemId);
                        break;
                    case 7:
                        moveHadEffect = VitalThrowMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 153:
                        moveHadEffect = FlyMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 205:
                        moveHadEffect = sub_8059F38(attacker, currTarget, move, itemId);
                        break;
                    case 156:
                        moveHadEffect = DiveMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 8:
                        moveHadEffect = DigMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 10:
                        moveHadEffect = sub_8057824(attacker, currTarget, move, itemId);
                        break;
                    case 56:
                        moveHadEffect = sub_805825C(attacker, currTarget, move, itemId);
                        break;
                    case 249:
                        moveHadEffect = KnockOffMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 389:
                        moveHadEffect = TrapbustOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 410:
                        moveHadEffect = LongtossOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 412:
                        moveHadEffect = PierceOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 49:
                        moveHadEffect = GrudgeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 374:
                        moveHadEffect = PetrifyOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 229:
                        moveHadEffect = sub_805A4C0(attacker, currTarget, move, itemId);
                        break;
                    case 256:
                    case 317:
                        moveHadEffect = sub_805AAD0(attacker, currTarget, move, itemId);
                        break;
                    case 396:
                        moveHadEffect = ShockerOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 102:
                    case 304:
                    case 380:
                        moveHadEffect = sub_805B314(attacker, currTarget, move, itemId);
                        break;
                    case 204:
                        moveHadEffect = sub_8059E54(attacker, currTarget, move, itemId, 0);
                        break;
                    case 301:
                    case 305:
                        moveHadEffect = ProtectMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 172:
                        moveHadEffect = sub_8059AB8(attacker, currTarget, move, itemId);
                        break;
                    case 85:
                        moveHadEffect = sub_8058858(attacker, currTarget, move, itemId);
                        break;
                    case 77:
                    case 121:
                        moveHadEffect = sub_8058770(attacker, currTarget, move, itemId);
                        break;
                    case 123:
                        moveHadEffect = sub_8059004(attacker, currTarget, move, itemId);
                        break;
                    case 155:
                        moveHadEffect = sub_80597F0(attacker, currTarget, move, itemId);
                        break;
                    case 128:
                        moveHadEffect = ChargeMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 67:
                        moveHadEffect = sub_8058548(attacker, currTarget, move, itemId);
                        break;
                    case 92:
                        moveHadEffect = sub_80588F4(attacker, currTarget, move, itemId);
                        break;
                    case 113:
                        moveHadEffect = sub_8058D44(attacker, currTarget, move, itemId);
                        break;
                    case 278:
                        moveHadEffect = sub_805AFA4(attacker, currTarget, move, itemId);
                        break;
                    case 37:
                        moveHadEffect = SmokescreenMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 363:
                        moveHadEffect = sub_805BA44(attacker, currTarget, move, itemId);
                        break;
                    case 160:
                        moveHadEffect = StockpileMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 245:
                        moveHadEffect = SpitUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 236:
                        moveHadEffect = SwallowMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 12:
                        moveHadEffect = RainDanceMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 35:
                        moveHadEffect = sub_8057D9C(attacker, currTarget, move, itemId);
                        break;
                    case 391:
                        moveHadEffect = InvisifyOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 316:
                        moveHadEffect = MirrorCoatMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 293:
                        moveHadEffect = PerishSongMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 96:
                        moveHadEffect = sub_8058A18(attacker, currTarget, move, itemId);
                        break;
                    case 313:
                        moveHadEffect = DestinyBondMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 17:
                        moveHadEffect = EncoreMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case MOVE_WEATHER_BALL:
                        moveHadEffect = sub_8057CD0(attacker, currTarget, move, itemId);
                        break;
                    case 223:
                        moveHadEffect = SunnyDayMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 228:
                        moveHadEffect = sub_805A464(attacker, currTarget, move, itemId);
                        break;
                    case 399:
                        moveHadEffect = sub_805C2A0(attacker, currTarget, move, itemId);
                        break;
                    case 104:
                        moveHadEffect = EndureMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 185:
                        moveHadEffect = HelpingHandMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 257:
                        moveHadEffect = BellyDrumMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 398:
                        moveHadEffect = sub_805C288(attacker, currTarget, move, itemId);
                        break;
                    case 11:
                        moveHadEffect = sub_805783C(attacker, currTarget, move, itemId);
                        break;
                    case 16:
                        moveHadEffect = sub_80578FC(attacker, currTarget, move, itemId);
                        break;
                    case 23:
                        moveHadEffect = sub_8057BB4(attacker, currTarget, move, itemId);
                        break;
                    case 29:
                    case 361:
                        moveHadEffect = RockSmashMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 282:
                        moveHadEffect = TransformMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 14:
                        moveHadEffect = HailMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 407:
                        moveHadEffect = MobileOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 54:
                    case 315:
                        moveHadEffect = sub_8058234(attacker, currTarget, move, itemId);
                        break;
                    case 254:
                        moveHadEffect = sub_805A85C(attacker, currTarget, move, itemId);
                        break;
                    case 370:
                        moveHadEffect = TransferOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 375:
                        moveHadEffect = sub_805BB98(attacker, currTarget, move, itemId);
                        break;
                    case 269:
                        moveHadEffect = sub_805AD54(attacker, currTarget, move, itemId);
                        break;
                    case 365:
                        moveHadEffect = ReboundOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 266:
                    case 379:
                        moveHadEffect = sub_805AD04(attacker, currTarget, move, itemId);
                        break;
                    case 390:
                        moveHadEffect = sub_805C080(attacker, currTarget, move, itemId);
                        break;
                    case 395:
                        moveHadEffect = sub_805C1E4(attacker, currTarget, move, itemId);
                        break;
                    case 385:
                        moveHadEffect = EscapeOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 263:
                        moveHadEffect = SecretPowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 119:
                        moveHadEffect = NaturePowerMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 403:
                        moveHadEffect = sub_805C3F8(attacker, currTarget, move, itemId);
                        break;
                    case 138:
                        moveHadEffect = SketchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 40:
                        moveHadEffect = sub_8057E50(attacker, currTarget, move, itemId);
                        break;
                    case 220:
                        moveHadEffect = RolePlayMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 137:
                        moveHadEffect = SkillSwapMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 183:
                        moveHadEffect = ConversionMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 378:
                        moveHadEffect = CleanseOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 48:
                        moveHadEffect = sub_805805C(attacker, currTarget, move, itemId);
                        break;
                    case 334:
                        moveHadEffect = SnatchMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 286:
                        moveHadEffect = HandleColorChange(attacker, currTarget, move, itemId);
                        break;
                    case 328:
                        moveHadEffect = sub_805B53C(attacker, currTarget, move, itemId);
                        break;
                    case 115:
                        moveHadEffect = PsychUpMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 25:
                        moveHadEffect = SnoreMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 337:
                        moveHadEffect = RecycleMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 384:
                        moveHadEffect = SilenceOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 330:
                        moveHadEffect = sub_805B618(attacker, currTarget, move, itemId);
                        break;
                    case 393:
                        moveHadEffect = IdentifyOrbAction(attacker, currTarget, move, itemId);
                        break;
                    case 184:
                        moveHadEffect = Conversion2MoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 376:
                        moveHadEffect = sub_805BEB8(attacker, currTarget, move, itemId);
                        break;
                    case 377:
                        moveHadEffect = sub_805BEC8(attacker, currTarget, move, itemId);
                        break;
                    case 327:
                        moveHadEffect = MimicMoveAction(attacker, currTarget, move, itemId);
                        break;
                    case 50:
                    case 406:
                        moveHadEffect = sub_805C45C(attacker, currTarget, move, itemId);
                        break;
                    case 397:
                        moveHadEffect = sub_805C208(attacker, currTarget, move, itemId);
                        break;
                    default:
                        moveHadEffect = FALSE;
                        break;
                }

                if (sub_8044B28()) {
                    break;
                }

                if (EntityExists(currTargetSaved)) {
                    sub_806CE68(currTargetSaved, GetEntInfo(currTargetSaved)->action.direction);
                }

                if (!moveHadEffect) {
                    if (EntityExists(attacker) && EntityExists(currTarget) && targetInfo->isNotTeamMember) {
                        targetInfo->expMultiplier = expMultiplierBeforeMove;
                    }
                }
                else {
                    if (MoveCausesPaused(move) && sub_8057308(attacker, 0)) {
                        gUnknown_202F222 = 1;
                    }
                }

                if (EntityExists(currTarget)) {
                    targetInfo->unk158 = 1;
                }

                if (moveId != MOVE_SKILL_SWAP) {
                    TriggerTargetAbilityEffect(attacker);
                    sub_8069F9C(attacker, currTarget, move);
                    sub_806A120(attacker, currTarget, move);
                }
            }

            attacker = originalAttacker;
        }
    }

    if (!sub_8044B28()) {
        if (EntityExists(attacker) && GetEntInfo(attacker)->unk154 != 0) {
            GetEntInfo(attacker)->unk154 = 0;
            sub_807D148(attacker, attacker, 0, NULL);
        }
        if (EntityExists(attacker) && GetEntInfo(attacker)->unk155 != 0) {
            GetEntInfo(attacker)->unk155 = 0;
            LowerAttackStageTarget(attacker, attacker, gUnknown_8106A50, 2, 0, FALSE);
        }
    }
}

bool32 HandleRegularDamagingMove(Entity *attacker, Entity *target, Move *move, s32 itemId)
{
    return (HandleDamagingMove(attacker, target, move, 0x100, itemId) != 0);
}

s32 HandleDamagingMove(Entity *attacker, Entity *target, Move *move, s32 r9, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s16 unk;
    s32 moveType = GetMoveTypeForMonster(attacker, move);
    s32 movePower = GetMovePower(attacker, move);
    s32 critChance = GetMoveCritChance(move);

    sub_806EAF4(attacker, target, moveType, movePower, critChance, &dmgStruct, r9, move->id, 1);
    unk = sub_8057600(move, itemId);
    return TryHitTarget(attacker, target, move, &dmgStruct, unk);
}

s32 sub_80556BC(Entity *attacker, Entity *target, u8 moveType, Move *move, s32 r9, s32 itemId)
{
    struct DamageStruct dmgStruct;
    s16 unk;
    s32 movePower = GetMovePower(attacker, move);
    s32 critChance = GetMoveCritChance(move);

    sub_806EAF4(attacker, target, moveType, movePower, critChance, &dmgStruct, r9, move->id, 1);
    unk = sub_8057600(move, itemId);
    return TryHitTarget(attacker, target, move, &dmgStruct, unk);
}

static s32 TryHitTarget(Entity *attacker, Entity *target, Move *move, struct DamageStruct *dmgStruct, s16 unk_)
{
    s32 unk = unk_; // It's happening again...
    if (AccuracyCalc(attacker, target, move, ACCURACY_2, TRUE)) { // Move hits
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

bool32 sub_8055A00(Entity *attacker, s32 firstMoveId, s32 var_34, s32 itemId, s32 arg_0)
{
    s32 i, j;
    s32 moveId;
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    bool32 isLinkedMove;

    moveId = firstMoveId;
    if (firstMoveId >= MAX_MON_MOVES)
        return FALSE;

    attackerInfo->abilityEffectFlags = 0;
    attackerInfo->unk159 = 0;
    if (attackerInfo->volatileStatus.volatileStatus == STATUS_CRINGE) {
        SetMessageArgument(gAvailablePokemonNames, attacker, 0);
        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC714); // is cringing!
        return FALSE;
    }
    else if (attackerInfo->volatileStatus.volatileStatus == STATUS_INFATUATED) {
        SetMessageArgument(gAvailablePokemonNames, attacker, 0);
        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC718); // is infatuated!
        return FALSE;
    }
    else if (attackerInfo->nonVolatile.nonVolatileStatus == STATUS_PARALYSIS) {
        SetMessageArgument(gAvailablePokemonNames, attacker, 0);
        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC6A8); // is paralyzed!
        return FALSE;
    }

    gUnknown_202F222 = 0;
    gUnknown_202F208 = 0;
    gUnknown_202F221 = 0;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        attackerInfo->mimicMoveIDs[i] = 0;
    }

    for (i = 0, j = 0; i < MAX_MON_MOVES; i++) {
        j++;
        if (++moveId >= MAX_MON_MOVES)
            break;
        if (!(attackerInfo->moves.moves[moveId].moveFlags & MOVE_FLAG_SUBSEQUENT_IN_LINK_CHAIN))
            break;
    }

    isLinkedMove = (j > 1);
    moveId = firstMoveId;

    while (1) {
        Move *currMove = &attackerInfo->moves.moves[moveId];
        if (!EntityExists(attacker) || sub_8044B28())
            break;

        if (currMove->id == MOVE_SNORE || currMove->id == MOVE_SLEEP_TALK) {
            if (!IsSleeping(attacker)) {
                if (CannotAttack(attacker, TRUE))
                    break;
            }
        }
        else {
            if (CannotAttack(attacker, FALSE))
                break;
        }

        if (gUnknown_202F221 != 0)
            break;

        if (MoveFlagExists(currMove)) {
            bool32 moveUsable = TRUE;
            bool32 var_28 = FALSE;
            bool32 statusMoveMatch = MoveMatchesChargingStatus(attacker, currMove);

            if (currMove->PP != 0) {
                if (!statusMoveMatch) {
                    var_28 = TRUE;
                }
            }
            else {
                if (!statusMoveMatch) {
                    sub_80928C0(gFormatItems,  currMove, NULL);
                    TryDisplayDungeonLoggableMessage(attacker, gUnknown_80F93C8); // The move can't be used!
                    moveUsable = FALSE;
                }
            }

            if (moveUsable) {
                bool32 moveWasUsed;
                s32 unkBefore = gUnknown_202F208;

                attackerInfo->unk159 = statusMoveMatch;
                if (currMove->id == MOVE_ASSIST) {
                    Move assistMove = *currMove;

                    assistMove.id = sub_8057144(attacker);
                    sub_80928C0(gFormatItems, &assistMove, NULL);
                    TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FD2DC); // Assist:
                    moveWasUsed = TryUseChosenMove(attacker, var_34, itemId, arg_0, isLinkedMove, &assistMove);
                }
                else {
                    moveWasUsed = TryUseChosenMove(attacker, var_34, itemId, arg_0, isLinkedMove, currMove);
                }

                if (var_28 && moveWasUsed) {
                    if (currMove->moveFlags2 & MOVE_FLAG2_UNK4) {
                        currMove->moveFlags2 &= ~(MOVE_FLAG2_UNK4);
                    }
                    else {
                        currMove->moveFlags2 |= MOVE_FLAG_TEMPORARY;
                    }
                }

                if (unkBefore == gUnknown_202F208) {
                    if (itemId == 0) {
                        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC690); // The currMove failed!
                    }
                    else {
                        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC6A4); // The Orb failed!
                    }
                }
            }
        }

        sub_804178C(1);
        if (!EntityExists(attacker) || sub_8044B28())
            break;
        if (++moveId >= MAX_MON_MOVES)
            break;
        if (!MoveFlagLinkChain(&attackerInfo->moves.moves[moveId]))
            break;
    }

    if (EntityExists(attacker)) {
        for (i = 0; i < MAX_MON_MOVES; i++) {
            if (attackerInfo->mimicMoveIDs[i] != 0) {
                Move mimicMove, assistMove;
                Move *movePtr;

                movePtr = &mimicMove;
                sub_8092AA8(&mimicMove, attackerInfo->mimicMoveIDs[i]);
                if (MoveFlagExists(&mimicMove)) {
                    if (mimicMove.id == MOVE_ASSIST) {
                        assistMove = mimicMove;
                        assistMove.id = sub_8057144(attacker);
                        movePtr = &assistMove;
                        sub_80928C0(gFormatItems, &assistMove, NULL);
                        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FD2DC); // Assist:
                    }
                    TryUseChosenMove(attacker, 0, itemId, arg_0, isLinkedMove, movePtr);
                }
                sub_804178C(1);
            }
        }
    }

    if (EntityExists(attacker)) {
        sub_8071DA4(attacker);
        if (EntityExists(attacker) && gUnknown_202F222 != 0) {
            gUnknown_202F222 = 0;
            if (EntityExists(attacker)) {
                EntityInfo *attackerInfo = GetEntInfo(attacker);
                s32 statusTurns = CalculateStatusTurns(attacker, gUnknown_80F4E70, TRUE);
                PausedStatusTarget(attacker, attacker, 1, statusTurns, FALSE);
                SetExpMultplier(attackerInfo);
            }
        }
    }

    return TRUE;
}

static void TriggerTargetAbilityEffect(Entity *attacker)
{
    if (EntityExists(attacker)) {
        EntityInfo *entInfo = GetEntInfo(attacker);

        if (entInfo->abilityEffectFlags & ABILITY_FLAG_ARENA_TRAP) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEEA4); // Arena Trap prevents movement!
            ImmobilizedStatusTarget(attacker, attacker);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_SHADOW_TAG) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEEC8); // Shadow Tag prevents movement!
            ImmobilizedStatusTarget(attacker, attacker);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_MAGNET_PULL) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEEEC); // Magnet Pull prevents movement!
            ImmobilizedStatusTarget(attacker, attacker);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_STATIC) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF0C); // Static caused paralysis!
            ParalyzeStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_PRLZ) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF30); // Effect Spore scattered spores
            ParalyzeStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_POISON_POINT) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF4C); // Poison Point struck!
            PoisonedStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_PSN) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF50); // Effect Spore scattered spores!
            PoisonedStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_EFFECT_SPORE_SLP) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF54); // Effect Spore scattered spores!
            sub_8075C58(attacker, attacker, CalculateStatusTurns(attacker, gUnknown_80F4E74, TRUE), TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_FLAME_BODY) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF74); // Flame Body caused a burn!
            BurnedStatusTarget(attacker, attacker, TRUE, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_CUTE_CHARM) {
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEF98); // Cute Charm caused infatuation
            InfatuateStatusTarget(attacker, attacker, TRUE);
        }
        if (entInfo->abilityEffectFlags & ABILITY_FLAG_STENCH) {
            SetMessageArgument(gAvailablePokemonNames, attacker, 0);
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FEFD0); // A horrid stench billowed out
            sub_80428A0(attacker);
            entInfo->terrifiedTurns = gUnknown_80F5004;
        }

        entInfo->abilityEffectFlags = 0;
    }
}

bool8 TryUseChosenMove(struct Entity *attacker, u32 r6, s32 itemId, u32 var_30, bool32 isLinkedMove, struct Move *move)
{
    s32 i;
    Entity *targetsArray[MAX_MOVE_TARGETS + 1];
    const u8 *msg;
    Move metronomeMove, naturePwrMove;
    s32 var_2C;
    s32 var_28;
    s32 var_24;
    bool8 moveUsable;

    msg = NULL;
    targetsArray[0] = NULL;

    sub_804178C(1);
    if (move->id == MOVE_METRONOME) {
        gMetronomeCalledArrayId = DungeonRandInt(METRONOME_AVAILABLE_CALLED_MOVES);
        InitPokemonMove(&metronomeMove, gMetronomeCalledMoves[gMetronomeCalledArrayId].moveID);
        metronomeMove.moveFlags = move->moveFlags;
        metronomeMove.moveFlags2 = move->moveFlags2;
        sub_8056468(attacker, move, gUnknown_80FECBC, targetsArray, itemId, TRUE, FALSE);
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
        sub_8056468(attacker, move, gUnknown_80FECE0, targetsArray, itemId, TRUE, FALSE);
        sub_804178C(1);
        move = &naturePwrMove;
    }

    var_28 = 0;
    if ((GetMoveTargetAndRangeForPokemon(attacker, move, TRUE)
         & (0xF0)) == TARGETING_FLAG_TARGET_LINE)
    {
        var_28 = 10;
    }
    if ((GetMoveTargetAndRangeForPokemon(attacker, move, TRUE)
         & (0xF0)) == TARGETING_FLAG_CUT_CORNERS)
        {
        var_28 = 1;
        if ((move->id != MOVE_SOLARBEAM || GetApparentWeather(attacker) != WEATHER_SUNNY) && DoesMoveCharge(move->id)) {
            if (!MoveMatchesChargingStatus(attacker, move)) {
                var_28 = 0;
            }
        }
    }

    SetMessageArgument_2(gAvailablePokemonNames, GetEntInfo(attacker), 0);
    sub_80928C0(gFormatItems, move, NULL);
    if (MoveMatchesChargingStatus(attacker, move)) {
        msg = gUnknown_80FC72C; // mon loosed move
        GetEntInfo(attacker)->unkFF = 0;
        moveUsable = sub_805744C(attacker, move, TRUE);
    }
    else {
        if (itemId == 0) {
            msg = GetMoveUseText(move->id);
        }
        else {
            msg = gUnknown_80F9158;
        }
        moveUsable = CanMonsterUseMove(attacker, move, TRUE);
    }

    if (moveUsable && r6) {
        sub_806ACE8(attacker, move);
    }

    if (GetEntInfo(attacker)->muzzled.muzzled == TRUE && FailsWhileMuzzled(move->id)) {
        SetMessageArgument(gAvailablePokemonNames, attacker, 0);
        TryDisplayDungeonLoggableMessage(attacker, msg);
        sub_803E708(0xA, 0x3F);
        TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC710); // is muzzled!
        return FALSE;
    }
    else if (!moveUsable) {
        SetMessageArgument_2(gAvailablePokemonNames, GetEntInfo(attacker), 0);
        if (itemId == 0) {
            sub_80928C0(gFormatItems, move, NULL);
            TryDisplayDungeonLoggableMessage(attacker, msg);
            sub_803E708(0xA, 0x3F);
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC6D0); // But the move couldn't be used!
        }
        else {
            BufferItemName(gFormatItems, itemId, NULL);
            TryDisplayDungeonLoggableMessage(attacker, msg);
            sub_803E708(0xA, 0x3F);
            TryDisplayDungeonLoggableMessage(attacker, gUnknown_80FC6FC); // But Orbs are prevented from being used!
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
    if (isLinkedMove && GetEntInfo(attacker)->unk153 <= 3) {
        GetEntInfo(attacker)->unk153++;
    }

    var_2C = sub_8057070(move);
    for (i = 0; i < var_2C; i++) {
        u8 r4;
        EntityInfo *entInfo;

        var_24 = 1;
        if (gUnknown_202F220 != 0 || gUnknown_202F221 != 0)
            break;
        if (!EntityExists(attacker) || sub_8044B28())
            return TRUE;

        entInfo = GetEntInfo(attacker);
        if (var_30 != 0 || move->id == MOVE_SNORE || move->id == MOVE_SLEEP_TALK) {
            if (!IsSleeping(attacker) && CannotAttack(attacker, TRUE))
                break;
        }
        else {
            if (CannotAttack(attacker, FALSE))
                break;
        }
        entInfo->unk14A = 0;
        if (move->id == MOVE_THRASH) {
            GetEntInfo(attacker)->action.direction = DungeonRandInt(NUM_DIRECTIONS);
            TargetTileInFront(attacker);
            var_24 = 0;
        }
        gUnknown_203B438 = NULL;
        targetsArray[0] = 0;
        if (var_28 == 0 || var_28 == 1) {
            SetTargetsForMove(targetsArray, attacker, move);
            sub_80574C4(targetsArray, attacker); // Todo fix sub_80574C4
            if (i != 0 && var_24 != 0 && targetsArray[0] == NULL)
                break;
        }
        r4 = sub_8056468(attacker, move, msg, targetsArray, itemId, (i == 0), var_28);
        msg = NULL;
        if (gUnknown_203B438 != 0) {
            sub_806A1E8(gUnknown_203B438);
        }

        if (GetEntInfo(attacker)->volatileStatus.volatileStatus != STATUS_CONFUSED && GetEntInfo(attacker)->volatileStatus.volatileStatus != STATUS_COWERING) {
            EntityInfo *entInfo = GetEntInfo(attacker);
            entInfo->targetPos.x = 0;
            entInfo->targetPos.y = 0;
        }

        gUnknown_202F214++;
        if (var_28 != 0) {
            sub_80566F8(attacker, move, var_28, r4, itemId, isLinkedMove);
        }
        else {
            UseMoveAgainstTargets(targetsArray, attacker, move, itemId, isLinkedMove);
        }

        if (!EntityExists(attacker))
            break;

        sub_806CF18(attacker);
        if (GetEntInfo(attacker)->unk14A == 0) {
            GetEntInfo(attacker)->unk14A = 0; // Redundant as it's already 0
            sub_8079764(attacker);
        }
    }


    if (gUnknown_202F21A != 0) {
        SendImmobilizeEndMessage(attacker, attacker);
        SendLinkedEndMessage(attacker, attacker);
    }

    if (gUnknown_202F219 != 0 && EntityExists(attacker)) {
        EntityInfo *entInfo = GetEntInfo(attacker);

        ConfuseStatusTarget(attacker, attacker, FALSE);
        SetExpMultplier(entInfo);
    }
    return TRUE;
}

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

// This function looks important, but what does it do?
void sub_80566F8(Entity *attacker, Move *move, s32 a2, bool8 a3, s32 itemId, s32 isLinkedMove)
{
    Position var_68;
    Position var_64;
    Entity *targetsArray[2]; // Only 2 hmm
    s32 var_4C, var_48;
    s32 i, j;
    s32 targetArrId;
    s32 var_3C;
    s32 var_38;
    s32 var_34;
    s32 var_30;
    s32 var_2C;
    s32 var_28, var_24;
    s32 someCount;
    EntityInfo *attackerInfo;
    s32 unkRetVal;
    s32 divResult;
    s32 r9;

    targetArrId = 0;
    someCount = 0;
    attackerInfo = GetEntInfo(attacker);
    unkRetVal = sub_800ED20(move->id);
    var_30 = 2;
    if (unkRetVal != 1) {
        var_30 = 6;
        if (unkRetVal == 2) {
            var_30 = 3;
        }
    }

    var_68.x = attacker->pos.x;
    var_68.y = attacker->pos.y;
    var_4C = gAdjacentTileOffsets[attackerInfo->action.direction].x;
    var_48 = gAdjacentTileOffsets[attackerInfo->action.direction].y;
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

    if (sub_805755C(attacker, move->id) && !MoveMatchesChargingStatus(attacker, move)) {
        var_34 = -1;
    }
    else {
        var_34 = sub_8056564(attacker, &var_68, move, a2);
    }

    var_68.x = attacker->pos.x;
    var_68.y = attacker->pos.y;
    var_4C = gAdjacentTileOffsets[attackerInfo->action.direction].x;
    var_48 = gAdjacentTileOffsets[attackerInfo->action.direction].y;
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
    var_38 = gUnknown_81069D4[attackerInfo->action.direction];
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
            if (targetArrId <= 0) {
                bool8 canHitAnyone = FALSE;
                s32 targetFlags;
                EntityInfo *attackerInfo = GetEntInfo(attacker);
                if (attackerInfo->volatileStatus.volatileStatus == STATUS_CONFUSED
                    || attackerInfo->eyesightStatus.eyesightStatus == STATUS_BLINKER
                    || attackerInfo->volatileStatus.volatileStatus == STATUS_COWERING)
                {
                    canHitAnyone = TRUE;
                }
                targetFlags = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
                targetArrId = SetNewTarget(targetArrId, targetsArray, targetFlags, attacker, tile->monster, move, canHitAnyone);
            }
            break;
        }
    }

    if (var_34 >= 0) {
        sub_800DC14(var_34);
    }
    sub_804178C(1);
    gDungeon->unk1BDD4.unk1C05E = 0;

    if (targetArrId > 0) {
        targetsArray[targetArrId] = NULL;
        UseMoveAgainstTargets(targetsArray, attacker, move, itemId, isLinkedMove);
    }
    else if (a2 == 1 && sub_803F428(&var_68)) {
        sub_803E708(1, 0x4A);
        sub_8041168(attacker, NULL, move, &var_68);
    }
}

static bool8 AccuracyCalc(Entity *attacker, Entity *target, Move *move, s32 accuracyType, bool8 selfAlwaysHits)
{
    s32 statStageAccuracy, statStageEvasion;
    s32 statStageMul;
    s32 accuracy = GetMoveAccuracyOrAIChance(move, accuracyType);
    s32 rand = DungeonRandInt(100);
    EntityInfo *attackerInfo = GetEntInfo(attacker);
    EntityInfo *targetInfo = GetEntInfo(target);

    if (selfAlwaysHits && attacker == target)
        return TRUE;
    if (move->id == MOVE_REGULAR_ATTACK && IQSkillIsEnabled(attacker, IQ_SURE_HIT_ATTACKER))
        return TRUE;
    if (attackerInfo->moveStatus.moveStatus == STATUS_SURE_SHOT)
        return TRUE;
    if (attackerInfo->moveStatus.moveStatus == STATUS_WHIFFER)
        return FALSE;
    if (accuracy > 100)
        return TRUE;

    if (HasHeldItem(target, ITEM_DETECT_BAND)) {
        accuracy -= gUnknown_80F519C;
    }
    if (IQSkillIsEnabled(target, IQ_QUICK_DODGER)) {
        accuracy -= gUnknown_80F51A0;
    }

    statStageAccuracy = attackerInfo->hitChanceStages[0];
    if (HasAbility(attacker, ABILITY_COMPOUNDEYES)) {
        statStageAccuracy += 2;
    }
    if (move->id == MOVE_THUNDER) {
        s32 weather = GetApparentWeather(attacker);
        if (weather == WEATHER_RAIN) {
            return TRUE;
        }
        else if (weather == WEATHER_SUNNY) {
            statStageAccuracy -= 2;
        }
    }

    if (statStageAccuracy < 0) statStageAccuracy = 0;
    if (statStageAccuracy > 20) statStageAccuracy = 20;

    statStageMul = gUnknown_80F50F4[0][statStageAccuracy];
    if (statStageMul < 0) statStageMul = 0;
    if (statStageMul > (256 * 100)) statStageMul = (256 * 100);

    accuracy *= statStageMul;
    accuracy /= 256;

    statStageEvasion = targetInfo->hitChanceStages[1];
    if (targetInfo->exposed) {
        statStageEvasion = 10;
    }
    if (GetApparentWeather(target) == WEATHER_SANDSTORM && HasAbility(target, ABILITY_SAND_VEIL)) {
        statStageEvasion += 2;
    }
    if (HasAbility(attacker, ABILITY_HUSTLE)) {
        bool32 specialMove = (IsTypePhysical(GetMoveType(move)) == FALSE);
        if (!specialMove) {
            statStageEvasion += 2;
        }
    }

    if (statStageEvasion < 0) statStageEvasion = 0;
    if (statStageEvasion > 20) statStageEvasion = 20;

    statStageMul = gUnknown_80F50F4[1][statStageEvasion];
    if (statStageMul < 0) statStageMul = 0;
    if (statStageMul > (256 * 100)) statStageMul = (256 * 100);

    accuracy *= statStageMul;
    accuracy /= 256;
    if (rand < accuracy)
        return TRUE;
    else
        return FALSE;
}

static void SetTargetsForMove(Entity **targetsArray, Entity *attacker, Move *move)
{
    s32 targetFlags;
    s32 targetFlagsAnd;
    s32 arrId = 0;
    bool8 canHitPartner = (GetEntInfo(attacker)->volatileStatus.volatileStatus == STATUS_CONFUSED
                    || GetEntInfo(attacker)->eyesightStatus.eyesightStatus == STATUS_BLINKER
                    || GetEntInfo(attacker)->volatileStatus.volatileStatus == STATUS_COWERING);
    bool8 canHitSelf = (GetEntInfo(attacker)->volatileStatus.volatileStatus == STATUS_CONFUSED || GetEntInfo(attacker)->volatileStatus.volatileStatus == STATUS_COWERING);

    if (IQSkillIsEnabled(attacker, IQ_NONTRAITOR)) {
        canHitSelf = FALSE;
        canHitPartner = FALSE;
    }
    targetFlags = GetMoveTargetAndRangeForPokemon(attacker, move, FALSE);
    if ((targetFlags & 0xF) == 4) {
        bool32 usable = MoveMatchesChargingStatus(attacker, move);
        if (move->id == MOVE_SOLARBEAM && GetApparentWeather(attacker) == WEATHER_SUNNY) {
            usable = TRUE;
        }
        if (usable)
            targetFlags = 0;
        else
            targetFlags = 0x73;
    }

    targetFlagsAnd = targetFlags & 0xF0;
    if (targetFlagsAnd == 0) {
        Entity *targetEntity = sub_80696A8(attacker);
        if (targetEntity != NULL) {
            arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
        }
    }
    else if (targetFlagsAnd == 0x10 || targetFlagsAnd == 0x20) {
        s32 i;
        s32 direction, to;
        EntityInfo *entInfo = GetEntInfo(attacker);
        if (targetFlagsAnd == 0x20) {
            direction = entInfo->action.direction;
            to = 8;
        }
        else {
            direction = entInfo->action.direction - 1;
            to = 3;
        }
        for (i = 0; i < to; i++, direction++) {
            Entity *targetEntity;
            Position unkPositon;

            direction &= DIRECTION_MASK;
            unkPositon.x = attacker->pos.x + gAdjacentTileOffsets[direction].x ;
            unkPositon.y = attacker->pos.y + gAdjacentTileOffsets[direction].y;
            targetEntity = sub_804AD0C(&unkPositon);
            if (targetEntity != NULL) {
                arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
            }
        }
    }
    else if (targetFlagsAnd == 0x30) {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *dungeonMon = gDungeon->allPokemon[i];
            if (EntityExists(dungeonMon) && sub_8045A70(attacker, dungeonMon)) {
                if (dungeonMon == attacker) {
                    arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, attacker, move, canHitSelf);
                }
                else {
                    arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, dungeonMon, move, canHitPartner);
                }
            }
        }
    }
    else if (targetFlagsAnd == 0x40) {
        bool32 r4 = FALSE;
        Entity *targetEntity = sub_80696FC(attacker);
        if (targetEntity != NULL) {
            s32 arrIdBefore = arrId;
            arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
            r4 = (arrId != arrIdBefore);
        }
        if (!r4) {
            targetEntity = sub_806977C(attacker);
            if (targetEntity != NULL) {
                arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
            }
        }
    }
    else if (targetFlagsAnd == 0x50) {
        // Nothing happens here
    }
    else if (targetFlagsAnd == 0x80) {
        Entity *targetEntity = sub_80696FC(attacker);
        if (targetEntity != NULL) {
            arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, targetEntity, move, canHitPartner);
        }
    }
    else if (targetFlagsAnd == 0x60) {
        s32 i;
        for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
            Entity *dungeonMon = gDungeon->allPokemon[i];
            if (EntityExists(dungeonMon)) {
                arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, dungeonMon, move, canHitPartner);
            }
        }
    }
    else if (targetFlagsAnd == 0x70) {
        arrId = SetNewTarget(arrId, targetsArray, targetFlags, attacker, attacker, move, canHitPartner);
    }

    targetsArray[arrId] = NULL;
}

static s32 SetNewTarget(s32 targetArrId, Entity **targetsArray, s32 targetFlags_, Entity *attacker, Entity *target, Move *move, bool32 canHitAnyone_)
{
    bool32 canHitTarget;
    EntityInfo *targetInfo;

    // It's happening again, all over the codebase there are problems with s16 arguments, where the lsl/asr asm can't be matched. What is going on with that?
    s32 targetFlags = (s16)targetFlags_;
    bool8 canHitAnyone = canHitAnyone_;
    canHitTarget = FALSE;
    targetInfo = GetEntInfo(target);

    if (move->id == MOVE_BATON_PASS && attacker == target)
        return targetArrId;
    if (targetInfo->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER)
        return targetArrId;
    if (targetInfo->clientType == CLIENT_TYPE_DONT_MOVE || targetInfo->clientType == CLIENT_TYPE_CLIENT)
        return targetArrId;

    if (canHitAnyone) {
        canHitTarget = TRUE;
    }
    else {
        s32 targetFlagsAnd = targetFlags & 0xF;
        if (targetFlagsAnd == 0 || targetFlagsAnd == 4) {
            if (GetTreatmentBetweenMonsters(attacker, target, TRUE, FALSE) == 1) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 1) {
            if (GetTreatmentBetweenMonsters(attacker, target, TRUE, FALSE) == 0) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 2) {
            canHitTarget = TRUE;
        }
        else if (targetFlagsAnd == 5) {
            if (attacker != target) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 6) {
            if (GetTreatmentBetweenMonsters(attacker, target, TRUE, FALSE) == 0 && attacker != target) {
                canHitTarget = TRUE;
            }
        }
        else if (targetFlagsAnd == 3) {
            canHitTarget = TRUE;
        }
    }

    if (sub_80571F0(target, move)) {
        canHitTarget = FALSE;
    }

    if (canHitTarget && targetArrId < MAX_MOVE_TARGETS) {
        targetsArray[targetArrId] = target;
        if (!GetEntInfo(target)->isNotTeamMember && gUnknown_203B438 == NULL) {
            gUnknown_203B438 = target;
        }
        targetArrId++;
    }

    return targetArrId;
}
