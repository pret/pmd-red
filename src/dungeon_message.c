#include "global.h"
#include "globaldata.h"
#include "dungeon_message.h"
#include "dungeon_message_log.h"
#include "structs/dungeon_entity.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "code_800D090.h"
#include "code_800E9E4.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_803E724.h"
#include "code_8045A00.h"
#include "dungeon.h"
#include "dungeon_leader.h"
#include "dungeon_map.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "exclusive_pokemon.h"
#include "file_system.h"
#include "input.h"
#include "menu_input.h"
#include "pokemon.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"

void sub_80526D0(s32 r0);
static bool8 sub_8052DC0(Entity *);
static void DisplayMessageAddToLog(Entity *pokemon, const u8 *str, bool8 r2);

extern bool8 sub_8045888(Entity *pokemon);
extern void sub_805E804(void);
extern void sub_8083E28(void);
extern u32 sub_8014140(s32 a0, const void *a1);
extern void PlayDungeonCancelSE(void);
extern void PlayDungeonConfirmationSE(void);

extern u32 gUnknown_202EDD0;
extern u8 gUnknown_203B40C;
extern u8 gUnknown_202EE01;
extern s32 gDungeonFramesCounter;

static EWRAM_DATA Entity *sLastLogMsgEntity = NULL;
static UNUSED EWRAM_DATA u8 sUnused = 0;
static EWRAM_DATA SpriteOAM sUnknown_202F1F0 = {0};
EWRAM_INIT u8 gUnknown_203B434 = 1;

void sub_80521D0(void)
{
    s32 i;

    for (i = 0; i < UNK_1BBD4_STR_COUNT; i++) {
        gDungeon->unk1BDD4.unk1C054[i] = 0;
    }
    sLastLogMsgEntity = NULL;
    gUnknown_203B434 = 1;
    sub_8052210(FALSE);
}

void sub_8052210(bool8 a0)
{
    s32 i;

    for (i = 0; i < UNK_1BBD4_STR_COUNT; i++) {
        InlineStrcpy(gDungeon->unk1BDD4.unk0[i], "");
    }
    gDungeon->unk1BDD4.unk1C05F = 0;
    gDungeon->unk1BDD4.unk1C060 = 0;
    gDungeon->unk1BDD4.unk1C062 = 0;
    gDungeon->unk1BDD4.unk1C064 = 0;
    gDungeon->unk1BDD4.unk1C066 = 4;
    gDungeon->unk1BDD4.unk1C06C = 0;

    if (a0 && gUnknown_202EDD0 == 3) {
        sub_803EAF0(0, NULL);
        DungeonRunFrameActions(11);
    }
}

void sub_805229C(void)
{
    return sub_80526D0(0x50);
}

void LogMessageByIdWithPopupCheckUser(Entity *pokemon, const u8 *str)
{
    if (sub_8045888(pokemon)){
        DisplayMessageAddToLog(pokemon, str, TRUE);
    }
}

UNUSED void TryDisplayDungeonLoggableMessage2(Entity *pokemon, const u8 *str)
{
    if (sub_8045888(pokemon)){
        DisplayMessageAddToLog(pokemon, str, FALSE);
    }
}

void DisplayDungeonLoggableMessageFalse(Entity *pokemon, const u8 *str)
{
    DisplayMessageAddToLog(pokemon, str, FALSE);
}

void TryDisplayDungeonLoggableMessage3(Entity *attacker, Entity *target, const u8 *str)
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

void TryDisplayDungeonLoggableMessage4(Entity *attacker, Entity *target, const u8 *str)
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

void TryDisplayDungeonLoggableMessage5(Entity *pokemon, DungeonPos *pos,
                                       const u8 *str)
{
    u8 flag;
    flag = sub_8045888(pokemon) ? TRUE : FALSE;
    if(sub_803F428(pos))
    {
        flag = TRUE;
    }
    if(flag)
    {
        DisplayMessageAddToLog(pokemon, str, TRUE);
    }
}

void DisplayDungeonLoggableMessageTrue(Entity *pokemon, const u8 *str)
{
    DisplayMessageAddToLog(pokemon, str, TRUE);
}

static void DisplayMessageAddToLog(Entity *pokemon, const u8 *str, bool8 r2)
{
    u8 txt[64];
    u32 r7;
    bool32 r8, r9;

    if (sLastLogMsgEntity != pokemon) {
        r7 = 1;
    }
    else {
        r7 = gUnknown_203B434;
    }

    r8 = 1;
    sLastLogMsgEntity = pokemon;
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
            DungeonRunFrameActions(0);
        }

        if (*str == '\0')
            break;

        gDungeon->unk1BDD4.unk1C054[gDungeon->unk1BDD4.unk1C060] = r7;
        str = FormatString(str, txt, txt + 62, 128);
        if (*str == '\r') str++;
        if (*str == '\n') str++;
        CopyStringToMessageLog(txt, r7, r8);
        r7 = 0;
        r8 = 0;
        if (r2) {
            r9 = TRUE;
            InlineStrncpy(gDungeon->unk1BDD4.unk0[gDungeon->unk1BDD4.unk1C060], txt, 64);
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
            sub_803EAF0(3, NULL);
        // fall through
        case 2: {
            UnkDrawStringStruct sp;
            u32 currChr;

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
                    AddDoubleUnderScoreHighlight(0, 0, strPtr->unk1C066 - 1, 0xE0, 7);
                }

                while (1) {
                    txtPtr = xxx_handle_format_global(txtPtr, &sp);
                    if (*txtPtr == '\0' || *txtPtr == '\r' || *txtPtr == '\n')
                        break;
                    txtPtr = xxx_get_next_char_from_string(txtPtr, &currChr);
                    if (currChr == '`') {
                        sp.unk0 += 6;
                    }
                    else {
                        sp.unk0 += xxx_call_draw_char(sp.unk0, sp.unk2, currChr, sp.unk10, 0);
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
        gIwramTextFunc4(0);
        if (strPtr->unk1C068 > 10) {
            strPtr->unk1C06C = 2;
        }
        break;
    }

    if (strPtr->unk1C05E == 0 && strPtr->unk1C064 != 0 && --strPtr->unk1C064 == 0) {
        strPtr->unk1C06C = 0;
        sub_803EAF0(0, NULL);
        sub_8052210(FALSE);
    }
}

void sub_80526D0(s32 r0)
{
    struct UnkStructDungeon1BDD4 *strPtr = &gDungeon->unk1BDD4;
    while (strPtr->unk1C06C != 0 || gDungeon->unk1BDD4.unk1C060 != gDungeon->unk1BDD4.unk1C062) {
        DungeonRunFrameActions(r0);
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
        DungeonRunFrameActions(a0);
    }
}

// Prints string in dialogue box and waits for A/B button press
#define PRINT_STRING_WAIT_PRESS(chosenMenuIndex)   \
{                                           \
    s32 unkPrintRet;                        \
                                            \
    do {                                    \
        DrawDialogueBoxString();            \
        DungeonRunFrameActions(9);                     \
        unkPrintRet = sub_80144A4(chosenMenuIndex);\
    } while (unkPrintRet != 0);             \
}

void DisplayDungeonMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, bool8 a2)
{
    MonPortraitMsg monPortrait, *monPortraitPtr;
    s32 chosenMenuIndex;

    if (gUnknown_203B40C) {
        sub_8052740(10);
    }

    sub_803EAF0(2, NULL);
    sub_8052210(FALSE);

    monPortraitPtr = NULL;
    monPortrait.faceFile = NULL;
    monPortrait.faceData = NULL;
    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && monSpriteInfo != NULL
        && IsPokemonDialogueSpriteAvail(monSpriteInfo->species, monSpriteInfo->spriteId))
    {
        monPortrait.faceFile = GetDialogueSpriteDataPtr(monSpriteInfo->species);
        monPortrait.faceData = (PortraitGfx *) monPortrait.faceFile->data;
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
        LoadDungeonMapPalette();
        if (gShowDungeonMap) {
            sub_803EAF0(0, NULL);
        }
        else {
            sub_803EAF0(1, NULL);
        }
    }

    sub_803E708(8, 9);
}

void DisplayDungeonLoggableMessage(Entity *pokemon, const u8 *str)
{
    DisplayDungeonMessage(NULL, str, TRUE);
    DisplayDungeonLoggableMessageFalse(pokemon, str);
}

struct Struct_sub_808CDB0
{
    DungeonPos pos;
    bool8 flip;
};

extern const struct Struct_sub_808CDB0 *sub_808CDB0(s32 a0);

static const u16 sUnknownDialogueFlags[] = {0x30D, 0x10D, 0x30D, 0x10D, 0x301, 1, 0x11};

void DisplayDungeonDialogue(const struct DungeonDialogueStruct *dialogueInfo)
{
    MonPortraitMsg monPortrait;
    s32 leaderId, partnerId, dialogueMonId;
    s32 chosenMenuIndex;
    Entity *leader = xxx_call_GetLeader();
    Entity *partner = GetPartnerEntity();
    MonPortraitMsg *monPortraitPtr = NULL;

    if (leader != NULL) {
        EntityInfo *leaderInfo = GetEntInfo(leader);
        PokemonStruct2 *monStruct2 = &gRecruitedPokemonRef->pokemon2[leaderInfo->teamIndex];

        sub_808DA0C(gFormatBuffer_Monsters[0], monStruct2);
        leaderId = leaderInfo->apparentID;
    }
    else {
        leaderId = MONSTER_NONE;
        InlineStrcpy(gFormatBuffer_Monsters[0], "??");
    }

    if (partner != NULL) {
        EntityInfo *partnerInfo = GetEntInfo(partner);
        PokemonStruct2 *monStruct2 = &gRecruitedPokemonRef->pokemon2[partnerInfo->teamIndex];

        sub_808DA0C(gFormatBuffer_Monsters[1], monStruct2);
        partnerId = partnerInfo->apparentID;
    }
    else {
        partnerId = MONSTER_NONE;
        InlineStrcpy(gFormatBuffer_Monsters[1], "??");
    }

    switch (dialogueInfo->unk4) {
        case 425:
            dialogueMonId = leaderId;
            sprintfStatic(gSpeakerNameBuffer, _("{COLOR YELLOW}%s{RESET}"), gFormatBuffer_Monsters);
            break;
        case 426:
            dialogueMonId = partnerId;
            sprintfStatic(gSpeakerNameBuffer, _("{COLOR YELLOW}%s{RESET}"), gFormatBuffer_Monsters[1]);
            break;
        case 427:
            dialogueMonId = MONSTER_NONE;
            InlineStrcpy(gSpeakerNameBuffer, _("{COLOR YELLOW}{SPEECH_BUBBLE}{RESET}"));
            break;
        default:
            dialogueMonId = dialogueInfo->unk4;
            CopyYellowMonsterNametoBuffer(gSpeakerNameBuffer, dialogueMonId);
            break;
    }

    if (dialogueInfo->unk0 == 2 || dialogueInfo->unk0 == 3) {
        InlineStrcpy(gSpeakerNameBuffer, _("{COLOR YELLOW}{SPEECH_BUBBLE}{RESET}"));
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
            monPortraitPtr->faceData = (PortraitGfx *) monPortraitPtr->faceFile->data;
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
    sub_803EAF0(2, NULL);
    sub_8052210(FALSE);
    CreateDialogueBoxAndPortrait(dialogueInfo->str, 0, monPortraitPtr, sUnknownDialogueFlags[dialogueInfo->unk0]);
    PRINT_STRING_WAIT_PRESS(&chosenMenuIndex);

    if (monPortraitPtr != NULL) {
        CloseFile(monPortraitPtr->faceFile);
    }

    if (dialogueInfo->unk0 != 1 && dialogueInfo->unk0 != 3) {
        LoadDungeonMapPalette();
        sub_803EAF0(0, NULL);
    }
    sub_803E708(8, 9);
}

bool32 DisplayDungeonYesNoMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, bool32 defaultYes)
{
    MonPortraitMsg monPortrait, *monPortraitPtr;
    s32 chosenMenuIndex;

    sub_8052740(10);
    sub_803EAF0(2, NULL);
    sub_8052210(FALSE);

    monPortraitPtr = NULL;
    monPortrait.faceFile = NULL;
    monPortrait.faceData = NULL;
    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && monSpriteInfo != NULL
        && IsPokemonDialogueSpriteAvail(monSpriteInfo->species, monSpriteInfo->spriteId))
    {
        monPortrait.faceFile = GetDialogueSpriteDataPtr(monSpriteInfo->species);
        monPortrait.faceData = (PortraitGfx *) monPortrait.faceFile->data;
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

    LoadDungeonMapPalette();
    sub_803EAF0(0, NULL);

    if (chosenMenuIndex == 1)
        return TRUE;
    else
        return FALSE;
}

s32 DisplayDungeonMenuMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, const MenuItem *menuItems, u16 unkArg)
{
    MonPortraitMsg monPortrait, *monPortraitPtr;
    s32 chosenMenuIndex;

    sub_8052740(10);
    sub_803EAF0(2, NULL);
    sub_8052210(FALSE);

    monPortraitPtr = NULL;
    monPortrait.faceFile = NULL;
    monPortrait.faceData = NULL;
    if (!gDungeon->unk181e8.blinded
        && !gDungeon->unk181e8.hallucinating
        && monSpriteInfo != NULL
        && IsPokemonDialogueSpriteAvail(monSpriteInfo->species, monSpriteInfo->spriteId))
    {
        monPortrait.faceFile = GetDialogueSpriteDataPtr(monSpriteInfo->species);
        monPortrait.faceData = (PortraitGfx *) monPortrait.faceFile->data;
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

    LoadDungeonMapPalette();
    sub_803EAF0(0, NULL);
    return chosenMenuIndex;
}

void sub_8052D44(s16 *ids, Entity *leader, Entity *partner)
{
    if (EntityIsValid(leader)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], leader, 0);
        ids[0] = GetEntInfo(leader)->apparentID;
    }
    else {
        InlineStrcpy(gFormatBuffer_Monsters[0], "??");
        ids[0] = 0;
    }

    if (EntityIsValid(partner)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], partner, 0);
        ids[1] = GetEntInfo(partner)->apparentID;
    }
    else {
        InlineStrcpy(gFormatBuffer_Monsters[1], "??");
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
    if (gDungeon->unk644.dungeonLocation.id == DUNGEON_THUNDERWAVE_CAVE) {
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
            gBgTilemaps[0][0][i] = 0;
        }
    }

    CreateMenuDialogueBoxAndPortrait(str, 0, 0, NULL, NULL, 2, 0, NULL, 0x30);
    r9 = 0;
    while (1) {
        if (r8 < 62) {
            r8++;
            for (j = 0; j < 8; j++) {
                SetBGPaletteBufferColorRGB(240 + j, &gFontPalette[j], r8 / 2, NULL);
            }
        }
        else {
            r9++;
            if (r9 & 8) {
                SpriteSetAffine1(&sUnknown_202F1F0, 0);
                SpriteSetAffine2(&sUnknown_202F1F0, 0);
                SpriteSetObjMode(&sUnknown_202F1F0, 0);
                SpriteSetMosaic(&sUnknown_202F1F0, 0);
                SpriteSetBpp(&sUnknown_202F1F0, 0);
                SpriteSetShape(&sUnknown_202F1F0, 1);
                SpriteSetTileNum(&sUnknown_202F1F0, 0x3F0);
                SpriteSetPriority(&sUnknown_202F1F0, 0);
                SpriteSetPalNum(&sUnknown_202F1F0, 15);
                SpriteSetY(&sUnknown_202F1F0, 120);
                SpriteSetMatrixNum(&sUnknown_202F1F0, 0);
                SpriteSetSize(&sUnknown_202F1F0, 0);
                SpriteSetX(&sUnknown_202F1F0, 112);

                AddSprite(&sUnknown_202F1F0, 0x100, NULL, NULL);
            }
            if (gRealInputs.pressed & AB_BUTTONS)
                break;
        }
        DrawDialogueBoxString();
        DungeonRunFrameActions(9);
    }

    while (r8 >= 0) {
        for (j = 0; j < 8; j++) {
            SetBGPaletteBufferColorRGB(240 + j, &gFontPalette[j], r8 / 2, NULL);
        }
        DrawDialogueBoxString();
        DungeonRunFrameActions(9);
        r8--;
    }

    ShowWindows(NULL, TRUE, TRUE);
    DungeonRunFrameActions(9);
    LoadDungeonMapPalette();
    for (j = 0; j < 8; j++) {
        SetBGPaletteBufferColorArray(240 + j, &gFontPalette[j]);
    }
    sub_803E708(8, 9);
}

const u8 *GetCurrentDungeonName(void)
{
    if (gDungeon->unk644.unk34 == 1) {
        return GetDungeonName1(DUNGEON_OUT_ON_RESCUE);
    }
    else {
        return GetDungeonName1(gDungeon->unk644.dungeonLocation.id);
    }
}
