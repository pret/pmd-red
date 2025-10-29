#include "global.h"
#include "globaldata.h"
#include "textbox.h"
#include "constants/dungeon.h"
#include "constants/monster.h"
#include "code_800558C.h"
#include "code_800D090.h"
#include "confirm_name_menu.h"
#include "code_801B60C.h"
#include "code_802DB28.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"
#include "luminous_cave.h"
#include "makuhita_dojo1.h"
#include "makuhita_dojo2.h"
#include "music_util.h"
#include "code_801D014.h"
#include "code_803B050.h"
#include "code_8099360.h"
#include "credits2.h"
#include "event_flag.h"
#include "felicity_bank.h"
#include "flash.h"
#include "friend_list_menu.h"
#include "ground_lives.h"
#include "ground_map.h"
#include "ground_main.h"
#include "ground_script.h"
#include "gulpin_shop_801FB50.h"
#include "input.h"
#include "kangaskhan_storage1.h"
#include "kangaskhan_storage2.h"
#include "kecleon_bros1.h"
#include "kecleon_bros4.h"
#include "main_loops.h"
#include "memory.h"
#include "palette_util.h"
#include "personality_test1.h"
#include "portrait_placement.h"
#include "pokemon.h"
#include "save_write.h"
#include "string_format.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "wigglytuff_shop1.h"
#include "wigglytuff_shop3.h"
#include "wonder_mail.h"
#include "naming_screen.h"
#include "dungeon_list_menu.h"
#include "game_options.h"
#include "script_item.h"
#include "structs/menu.h"
#include "structs/str_file_system.h"
#include "structs/str_mon_portrait.h"

struct TextboxPortrait
{
    // size: 0x24
    s16 unk0;
    /* 0x2 */ s16 speciesID;
    bool8 showPortrait;
    u8 unk5;
    s8 spriteId;
    u8 placementId;
    PixelPos posDelta; // By default 0, 0. Allows to modify the position of the portrait. Can be changed by the scripting command 0x2f.
    MonPortraitMsg monPortrait;
    /* 0x20 */ OpenedFile *faceFile;
};

struct TextboxText
{
    u16 flags;
    u32 unk4;
    u8 buffer[0x400];
};

struct unkStruct_3001B64_unk418
{
    u16 unk0;
    u8 (*unk4)(void);
    void (*unk8)(void);
    u32 (*unkC)(void);
};

#define MAX_TEXTBOX_PORTRAITS 10

enum {
    TEXTBOX_TYPE_NORMAL = 1,
    TEXTBOX_TYPE_ON_BG_PRESS, // Prints text on a bg without window, waits for the player button press
    TEXTBOX_TYPE_ON_BG_AUTO, // Prints text on a bg, waits 32 frames and then fades out the text
};

union MonOrStringPtr
{
    u8 *str;
    Pokemon *mon;
};

struct Textbox
{
    // size: 0x5A8
    u32 type;
    s32 endMsgFrames;
    s32 midMsgFrames;
    struct TextboxText text;
    u32 unk414;
    const struct unkStruct_3001B64_unk418 *unk418;
    const MenuItem *unk41C;
    u32 unk420;
    u32 unk424;
    u32 unk428;
    union MonOrStringPtr unk42C;
    s32 unk430;
    s32 unk434;
    u32 fill438;
    struct TextboxPortrait portraits[MAX_TEXTBOX_PORTRAITS];
    s16 unk5A4;
};

static IWRAM_INIT struct Textbox *sTextbox = { NULL };

void sub_809B028(const MenuItem *, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text);
bool8 sub_809B18C(s32 *sp);
extern u8 sub_802B2D4(void);
extern void sub_802B3B8(void);
extern u32 sub_802B358(void);
void sub_8096BD0(void);
bool8 DrawCredits(s32 creditsCategoryIndex, s32);
u32 sub_8035574();
void sub_803565C(void);
bool8 sub_8015080(u8 *buffer, const MenuItem *menuItems);
s32 sub_801516C();
void sub_80151A4();
s32 sub_8015198();
void sub_8011C28(u32);
bool8 CreateHelperPelipperMenu(s16);
u32 sub_802E90C();
void sub_802E918();
u32 sub_80282DC(u8 *r0);
void sub_80282FC(void);
extern u8 CreateThankYouMailPelipper(void);
extern u8 sub_802E864(void);
extern u8 sub_802DFB0(void);
extern void CleanThankYouMailPelipper(void);
extern void CleanHelperPelipper(void);
extern void sub_802E06C(void);
extern u32 ThankYouMailPelipperCallback(void);
extern u32 HelperPelipperCallback(void);
extern u32 sub_802E890(void);
extern u32 sub_802DFD8(void);

#define TEXTBOX_FLAG_UNUSED_x2 0x2 // Unused, but set for almost all flag sets
#define TEXTBOX_FLAG_INSTANT_TEXT 0x20
// Both need to be set to wait for the player's button press. One flag would be sufficient in my opinion, but what can you do?
#define TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 0x40
#define TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS 0x80

#define TEXTBOX_FLAG_SPEAKER 0x100 // Speaker's name + dialogue sound
#define TEXTBOX_FLAG_DIALOGUE_SOUND 0x200 // Only dialogue sound

static const struct PortraitPlacementInfo sPortraitPlacements[PLACEMENT_COUNT] = {
    [PLACEMENT_LEFT]                    = {{2,  8}, FALSE},
    [PLACEMENT_MIDDLE_TOP]              = {{12, 5}, FALSE},
    [PLACEMENT_LEFT_]                   = {{2,  8}, FALSE},
    [PLACEMENT_RIGHT]                   = {{23, 8}, TRUE},
    [PLACEMENT_MIDDLE_LEFT]             = {{7,  8}, FALSE},
    [PLACEMENT_MIDDLE_RIGHT]            = {{18, 8}, TRUE},
    [PLACEMENT_MIDDLE_TOP_FLIP]         = {{13, 5}, TRUE},
    [PLACEMENT_LEFT_FLIP]               = {{2,  8}, TRUE},
    [PLACEMENT_RIGHT_FLIP]              = {{23, 8}, FALSE},
    [PLACEMENT_MIDDLE_LEFT_FLIP]        = {{7,  8}, TRUE},
    [PLACEMENT_MIDDLE_RIGHT_FLIP]       = {{18, 8}, FALSE},
    [PLACEMENT_TOP]                     = {{12, 1}, FALSE},
    [PLACEMENT_TOP_LEFT]                = {{2,  2}, FALSE},
    [PLACEMENT_TOP_RIGHT]               = {{23, 2}, TRUE},
    [PLACEMENT_MIDDLE_TOP_LEFT]         = {{7,  1}, FALSE},
    [PLACEMENT_MIDDLE_TOP_RIGHT]        = {{18, 1}, TRUE},
    [PLACEMENT_TOP_FLIP]                = {{13, 1}, TRUE},
    [PLACEMENT_TOP_LEFT_FLIP]           = {{2,  2}, TRUE},
    [PLACEMENT_TOP_RIGHT_FLIP]          = {{23, 2}, FALSE},
    [PLACEMENT_MIDDLE_TOP_LEFT_FLIP]    = {{7,  1}, TRUE},
    [PLACEMENT_MIDDLE_TOP_RIGHT_FLIP]   = {{18, 1}, FALSE},
};

static const MenuItem gUnknown_81160E8[] =
{
    {"*Yes", 1},
    {"No", 0},
    {NULL, 0},
};

static const MenuItem gUnknown_811610C[] =
{
    {"Yes", 1},
    {"*No", 0},
    {NULL, 0},
};

static const MenuItem sEmptyMenuItems[] =
{
    {NULL, 0},
};

static const u32 sScriptTextboxTypes[] =
{
    [SCRIPT_TEXT_TYPE_INSTANT] =    TEXTBOX_TYPE_NORMAL,
    [SCRIPT_TEXT_TYPE_PLAYER] =     TEXTBOX_TYPE_NORMAL,
    [SCRIPT_TEXT_TYPE_NPC] =        TEXTBOX_TYPE_NORMAL,
    [SCRIPT_TEXT_TYPE_LETTER] =     TEXTBOX_TYPE_NORMAL,
    [SCRIPT_TEXT_TYPE_4] =          TEXTBOX_TYPE_NORMAL,
};

static const u16 sScriptFlagSets[] =
{
    [SCRIPT_TEXT_TYPE_INSTANT] =    TEXTBOX_FLAG_UNUSED_x2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS | TEXTBOX_FLAG_INSTANT_TEXT,
    [SCRIPT_TEXT_TYPE_PLAYER] =     TEXTBOX_FLAG_UNUSED_x2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS,
    [SCRIPT_TEXT_TYPE_NPC] =        TEXTBOX_FLAG_UNUSED_x2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS | TEXTBOX_FLAG_SPEAKER,
    [SCRIPT_TEXT_TYPE_LETTER] =     TEXTBOX_FLAG_UNUSED_x2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS | TEXTBOX_FLAG_DIALOGUE_SOUND,
    [SCRIPT_TEXT_TYPE_4] =          0x01,
    // These are effectively unused
    0x121, 0x101, 0x10D, 0x105, 0
};

ALIGNED(4) static const u8 sInvalidText[] = _("{COLOR RED_W}invalidity{RESET}");
ALIGNED(4) static const u8 sUndefineText[] = _("{COLOR RED_W}undefine{RESET}");
ALIGNED(4) static const u8 sSpeechBubbleText[] = _("{SPEECH_BUBBLE}");
ALIGNED(4) static const u8 sYellowSpeechBubbleText[] = _("{COLOR YELLOW_N}{SPEECH_BUBBLE}{RESET}");
ALIGNED(4) static const u8 sYellowStringText[] = _("{COLOR YELLOW_N}%s{RESET}");

EWRAM_DATA u16 gUnknown_20399DC = 0;
EWRAM_DATA u16 gUnknown_20399DE = 0;

static void ResetAllTextboxPortraits(void);
static bool8 ScriptPrintTextInternal(struct TextboxText *ptr, u32 flags_, s32 a2_, const char *text);
static u32 SetTextboxType(u32 textboxType, bool8 unused);
static void ResetTextbox(void);
static bool8 IsTextboxOpen_809B40C(struct TextboxText *a0);
static u8 *sub_809B428(u8 *a0, s32 a1, u8 *a2);
static bool8 sub_809B648(void);
static void sub_809C39C(void);
static void sub_809C3D8(void);
static void sub_809C504(void);
static void sub_809C464(void);
static void sub_809C478(void);
static void sub_809C414(void);
static void sub_809C4B0(void);
static void sub_809C550(void);

void TextboxInit(void)
{
    ResetDialogueBox();
    sTextbox = MemoryAlloc(sizeof(struct Textbox), 6);
    sTextbox->type = 0;
    sTextbox->endMsgFrames = -1;
    sTextbox->midMsgFrames = -1;
    gUnknown_20399DC = 0;
    gUnknown_20399DE = 0;
    sub_80095CC(0,0x14);
    ShowWindows(0,1,1);
    sub_8009408(0,0x14);
    ResetTextbox();
    sTextbox->unk414 = 0;
    sTextbox->unk418 = NULL;
    sTextbox->unk41C = 0;
    sTextbox->unk420 = 0;
    sTextbox->unk424 = 0;
    sTextbox->unk428 = 0;
    sTextbox->unk42C.str = NULL;
    sTextbox->unk430 = -1;
    sTextbox->unk434 = -1;
    ResetAllTextboxPortraits();
    sTextbox->unk5A4 = -1;
}

void TextboxFree(void)
{
    TextboxResetAll();
    FREE_AND_SET_NULL(sTextbox);
}

void TextboxResetAll(void)
{
    s32 index;

    sTextbox->type = 0;
    sTextbox->endMsgFrames = -1;
    sTextbox->midMsgFrames = -1;
    gUnknown_20399DC = 0;
    gUnknown_20399DE = 0;
    for (index = 0; index < MAX_TEXTBOX_PORTRAITS; index++) {
        ResetTextboxPortrait(index);
    }
    sTextbox->unk414 = 0;
    SetTextboxType(0, TRUE);
}

static u32 SetTextboxType(u32 textboxType, bool8 unused)
{
    switch (textboxType) {
        case 0:
            ResetTextbox();
            ShowWindows(0,1,1);
            break;
        case TEXTBOX_TYPE_NORMAL:
            ResetTextbox();
            break;
        case TEXTBOX_TYPE_ON_BG_PRESS:
            ResetTextbox();
            break;
        case TEXTBOX_TYPE_ON_BG_AUTO:
            ResetTextbox();
            break;
        case 4:
            ResetTextbox();
            break;
        default:
            ResetTextbox();
            ShowWindows(0,1,1);
            break;
    }
    sTextbox->type = textboxType;
    return 1;
}

void sub_809A6E4(u16 r0)
{
    gUnknown_20399DC |= r0;
}

void sub_809A6F8(u16 r0)
{
    gUnknown_20399DC &= ~r0;
}

UNUSED static u16 sub_809A70C(u16 r0)
{
    return gUnknown_20399DC;
}

UNUSED static void nullsub_209(void)
{
}

void SetAutoPressTextboxFrames(s32 frames)
{
    sTextbox->endMsgFrames = frames;
    sTextbox->midMsgFrames = frames;
    SetDialogueBoxAutoPressFrames(frames, frames);
}

void SetAutoPressTextboxMidEndMsgFrames(s32 endMsgFrames, s32 midMsgFrames)
{
    sTextbox->endMsgFrames = endMsgFrames;
    sTextbox->midMsgFrames = midMsgFrames;
    SetDialogueBoxAutoPressFrames(endMsgFrames, midMsgFrames);
}

bool8 IsTextboxOpen_809A750(void)
{
    return IsTextboxOpen_809B40C(&sTextbox->text);
}

bool8 sub_809A768(void)
{
    return FALSE;
}

// I think these two functions are functionally equivalent.
bool8 ScriptClearTextbox(void)
{
    switch (sTextbox->type) {
        case TEXTBOX_TYPE_ON_BG_AUTO:
            return ScriptPrintTextInternal(&sTextbox->text,4,-1,0);
        case TEXTBOX_TYPE_NORMAL:
        case TEXTBOX_TYPE_ON_BG_PRESS:
            return ScriptPrintTextInternal(&sTextbox->text,TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS | 0x4,-1,0);
        default:
            SetTextboxType(0, TRUE);
            return FALSE;
    }
}

bool8 ScriptClearTextbox2(void)
{
    switch (sTextbox->type) {
        case TEXTBOX_TYPE_ON_BG_AUTO:
        case TEXTBOX_TYPE_NORMAL:
        case TEXTBOX_TYPE_ON_BG_PRESS:
            return ScriptPrintTextInternal(&sTextbox->text,4,-1,0);
        default:
            SetTextboxType(0, TRUE);
            return FALSE;
    }
}

static void ResetAllTextboxPortraits(void)
{
    s32 i;
    struct TextboxPortrait *ptr = &sTextbox->portraits[0];

    for (i = 0; i < MAX_TEXTBOX_PORTRAITS; i++, ptr++) {
        ptr->unk0 = -1;
        ptr->speciesID = MONSTER_NONE;
        ptr->showPortrait = 0;
        ptr->unk5 = 0;
        ptr->spriteId = -1;
        ptr->placementId = 0;
        ptr->posDelta.x = 0;
        ptr->posDelta.y = 0;
        ptr->monPortrait.faceFile = NULL;
        ptr->monPortrait.faceData = NULL;
        ptr->monPortrait.spriteId = 0;
        ptr->faceFile = NULL;
    }
}

void ResetTextboxPortrait(s16 id_)
{
    s32 id = id_;
    struct TextboxPortrait *ptr = &sTextbox->portraits[id];

    ptr->unk0 = -1;
    ptr->speciesID = MONSTER_NONE;
    ptr->showPortrait = 0;
    ptr->unk5 = 0;
    ptr->spriteId = -1;
    ptr->placementId = 0;
    ptr->posDelta.x = 0;
    ptr->posDelta.y = 0;
    ptr->monPortrait.faceFile = NULL;
    ptr->monPortrait.faceData = NULL;
    ptr->monPortrait.spriteId = 0;
    strcpy(gFormatBuffer_Monsters[id_], sInvalidText);
    strcpy(gFormatBuffer_Names[id_], sInvalidText);
    TRY_CLOSE_FILE_AND_SET_NULL(ptr->faceFile);
}

static bool8 sub_809A8B8(s32 param_1, s32 param_2)
{
    bool8 ret;
    s16 speciesId;
    s32 portraitId = (s16) param_1;
    s16 local_28 = (s16) param_2;
    struct TextboxPortrait *portraitPtr = &sTextbox->portraits[portraitId];
    bool8 showPortrait = TRUE;
    bool8 byte1 = FALSE;

    TRY_CLOSE_FILE_AND_SET_NULL(portraitPtr->faceFile);

    sub_80A7DDC(&local_28,&speciesId);
    if (local_28 >= 10 && local_28 <= 29) {
        Pokemon *pPVar6 = sub_80A8D54(local_28);
        if (pPVar6 == NULL) {
            showPortrait = FALSE;
        }
        else if (pPVar6 == sub_808D3BC()) {
            local_28 = 0x21;
        }
        else if (pPVar6 == sub_808D3F8()) {
            local_28 = 0x22;
        }
        else if (pPVar6->dungeonLocation.id == DUNGEON_FROSTY_GROTTO_2
                 || pPVar6->dungeonLocation.id == DUNGEON_HOWLING_FOREST_2
                 || pPVar6->dungeonLocation.id == DUNGEON_POKEMON_SQUARE
                 || pPVar6->dungeonLocation.id == DUNGEON_POKEMON_SQUARE_2)
        {
            switch (speciesId) {
                case MONSTER_SMEARGLE:
                case MONSTER_GARDEVOIR:
                case MONSTER_ABSOL:
                case MONSTER_LATIAS:
                case MONSTER_LATIOS:
                    break;
                default:
                    showPortrait = FALSE;
                    break;
            }
        }
        else {
            switch (speciesId) {
                case MONSTER_ARTICUNO:
                case MONSTER_ZAPDOS:
                case MONSTER_MOLTRES:
                case MONSTER_MEWTWO:
                case MONSTER_RAIKOU:
                case MONSTER_ENTEI:
                case MONSTER_SUICUNE:
                case MONSTER_LUGIA:
                case MONSTER_HO_OH:
                case MONSTER_KYOGRE:
                case MONSTER_GROUDON:
                case MONSTER_RAYQUAZA:
                case MONSTER_JIRACHI:
                case MONSTER_DEOXYS_NORMAL:
                case MONSTER_RAYQUAZA_CUTSCENE:
                    break;
                default:
                    showPortrait = FALSE;
                    break;
            }
        }
    }

    switch (local_28) {
        case 1:
        case 2:
        case 6:
        case 7:
        case 0x21:
        case 0x22:
        if (IsStarterMonster(speciesId)) {
            byte1 = TRUE;
        }
        else {
            showPortrait = FALSE;
        }
        break;
    }

    if (local_28 != -1) {
        s32 sVar3 = (s16) sub_80A7AE8(local_28);
        if (sVar3 >= 0) {
            portraitPtr->unk0 = local_28;
            portraitPtr->speciesID = sub_80A8BFC(sVar3);
            strcpy(gFormatBuffer_Monsters[portraitId], sUndefineText);
            strcpy(gFormatBuffer_Names[portraitId], sUndefineText);
            portraitPtr->showPortrait = showPortrait;
            portraitPtr->unk5 = byte1;
            portraitPtr->spriteId = -1;
            portraitPtr->placementId = 0;
            portraitPtr->posDelta.x = 0;
            portraitPtr->posDelta.y = 0;
            portraitPtr->monPortrait.faceFile = NULL;
            portraitPtr->monPortrait.faceData = NULL;
            portraitPtr->monPortrait.spriteId = 0;
            ret = TRUE;
        }
        else if (speciesId != 0) {
            portraitPtr->unk0 = local_28;
            portraitPtr->speciesID = speciesId;
            strcpy(gFormatBuffer_Monsters[portraitId], sUndefineText);
            strcpy(gFormatBuffer_Names[portraitId], sUndefineText);
            portraitPtr->showPortrait = showPortrait;
            portraitPtr->unk5 = byte1;
            portraitPtr->spriteId = -1;
            portraitPtr->placementId = 0;
            portraitPtr->posDelta.x = 0;
            portraitPtr->posDelta.y = 0;
            portraitPtr->monPortrait.faceFile = NULL;
            portraitPtr->monPortrait.faceData = NULL;
            portraitPtr->monPortrait.spriteId = 0;
            ret = TRUE;
        }
        else {
            ResetTextboxPortrait(portraitId);
            ret = FALSE;
        }
    }
    else {
        ResetTextboxPortrait(portraitId);
        ret = FALSE;
    }

    return ret;
}

bool8 sub_809AB4C(s32 a0_, s32 a1_)
{
    s32 a0 = (s16) a0_;
    s32 a1 = (s16) a1_;
    struct TextboxPortrait *portrait = &sTextbox->portraits[a0];

    if (sub_809A8B8(a0, a1)) {
        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[a0], portrait->speciesID);
        strcpy(gFormatBuffer_Names[a0], sSpeechBubbleText);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_809ABB4(s32 id_, s32 a1_)
{
    s32 id = (s16) id_;
    s32 a1 = (s16) a1_;
    struct TextboxPortrait *portrait = &sTextbox->portraits[id];

    if (sub_809A8B8(id, a1)) {
        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[id], portrait->speciesID);
        strcpy(gFormatBuffer_Names[id], gFormatBuffer_Monsters[id]);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_809AC18(s32 a0_, s32 a1_)
{
    s32 a0 = (s16) a0_;
    s32 a1 = (s16) a1_;
    struct TextboxPortrait *portrait = &sTextbox->portraits[a0];

    if (sub_809A8B8(a0, a1)) {
        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[a0], portrait->speciesID);
        sub_80A8EC0(gFormatBuffer_Names[a0], portrait->unk0);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 ScriptSetPortraitInfo(s32 portraitId_, s32 spriteId_, s32 placementId_)
{
    s32 portraitId = (s16) portraitId_;
    s32 spriteId = (s8) spriteId_;
    u8 placementId = (u8) placementId_;
    struct TextboxPortrait *portraitPtr = &sTextbox->portraits[portraitId];

    TRY_CLOSE_FILE_AND_SET_NULL(portraitPtr->faceFile);

    if (portraitPtr->speciesID >= 0 && spriteId != -1 && portraitPtr->speciesID != 0) {
        // Keep previous placementId if PLACEMENT_COUNT is passed.
        if (placementId != PLACEMENT_COUNT) {
            portraitPtr->placementId = placementId;
            portraitPtr->posDelta.x = 0;
            portraitPtr->posDelta.y = 0;
        }
        portraitPtr->monPortrait.pos.x = sPortraitPlacements[portraitPtr->placementId].pos.x + portraitPtr->posDelta.x;
        portraitPtr->monPortrait.pos.y = sPortraitPlacements[portraitPtr->placementId].pos.y + portraitPtr->posDelta.y;
        portraitPtr->monPortrait.flip = sPortraitPlacements[portraitPtr->placementId].flip;
        portraitPtr->monPortrait.unkE = 0;
        if (spriteId == -2) {
            portraitPtr->spriteId = -2;
            portraitPtr->monPortrait.faceFile = NULL;
            portraitPtr->monPortrait.faceData = NULL;
            portraitPtr->monPortrait.spriteId = 0;
            return FALSE;
        }

        if (portraitPtr->showPortrait) {
            portraitPtr->faceFile = OpenPokemonDialogueSpriteFile(portraitPtr->speciesID);
            if (portraitPtr->faceFile != NULL) {
                portraitPtr->spriteId = spriteId;
                portraitPtr->monPortrait.faceFile = portraitPtr->faceFile;
                GetFileDataPtr(portraitPtr->faceFile, 0);
                // first 4 bits are actually spriteId, there's also some 0x40 flag which isn't really used. I assume it marks that the spriteId was changed?
                switch (portraitPtr->unk0) {
                    case 0x47:
                        if ((spriteId & 0xF) < 6) {
                            spriteId = (s8) (spriteId + 6);
                            spriteId = (s8) (spriteId | 0x40);
                        }
                        break;
                    case 0x4D:
                        if (portraitPtr->monPortrait.flip && (spriteId & 0xF) < 4) {
                            portraitPtr->monPortrait.flip = FALSE;
                            spriteId = (s8) (spriteId + 4);
                            spriteId = (s8) (spriteId | 0x40);
                        }
                        break;
                    case 0x53:
                        if (portraitPtr->monPortrait.flip && (spriteId & 0xF) < 1) {
                            portraitPtr->monPortrait.flip = FALSE;
                            spriteId = (s8) (spriteId + 1);
                            spriteId = (s8) (spriteId | 0x40);
                        }
                        break;
                    case 0x73:
                        if (portraitPtr->monPortrait.flip && (spriteId & 0xF) < 2) {
                            portraitPtr->monPortrait.flip = FALSE;
                            spriteId = (s8) (spriteId + 2);
                            spriteId = (s8) (spriteId | 0x40);
                        }
                        break;
                }

                portraitPtr->monPortrait.faceData = (void *) portraitPtr->faceFile->data;
                portraitPtr->monPortrait.spriteId = spriteId & 0xF;
            }
            else {
                portraitPtr->monPortrait.faceFile = NULL;
                portraitPtr->monPortrait.faceData = NULL;
                portraitPtr->monPortrait.spriteId = 0;
            }
            return TRUE;
        }
    }

    portraitPtr->spriteId = -1;
    portraitPtr->placementId = 0;
    portraitPtr->posDelta.x = 0;
    portraitPtr->posDelta.y = 0;
    portraitPtr->monPortrait.faceFile = NULL;
    portraitPtr->monPortrait.faceData = NULL;
    portraitPtr->monPortrait.spriteId = 0;
    return FALSE;
}

bool8 ScriptSetPortraitPosDelta(s32 portraitId_, PixelPos *newPosDelta)
{
    s32 portraitId = (s16) portraitId_;
    struct TextboxPortrait *portraitPtr = &sTextbox->portraits[portraitId];

    if (portraitPtr->speciesID < 0)
        return FALSE;
    if (portraitPtr->speciesID == MONSTER_NONE)
        return FALSE;

    portraitPtr->posDelta = *newPosDelta;
    portraitPtr->monPortrait.pos.x = sPortraitPlacements[portraitPtr->placementId].pos.x + portraitPtr->posDelta.x;
    portraitPtr->monPortrait.pos.y = sPortraitPlacements[portraitPtr->placementId].pos.y + portraitPtr->posDelta.y;
    return TRUE;
}

static MonPortraitMsg *GetSpeakerPortrait(s32 portraitId_)
{
    s32 portraitId = (s16) portraitId_;

    if (portraitId >= 0) {
        struct TextboxPortrait *portraitPtr = &sTextbox->portraits[portraitId];
        if (portraitPtr->speciesID != MONSTER_NONE && portraitPtr->spriteId == -1) {
            ScriptSetPortraitInfo(portraitId, 0, 0);
        }
        if (portraitPtr->monPortrait.faceFile != NULL) {
            return &portraitPtr->monPortrait;
        }
    }

    return NULL;
}

bool8 ScriptPrintText(s32 scriptMsgType, s32 speakerId_, const char *text)
{
    s32 speakerId = (s16) speakerId_;

    if (text == NULL) {
        return ScriptClearTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptClearTextbox2();
    }
    else {
        SetTextboxType(sScriptTextboxTypes[scriptMsgType], FALSE);
        return ScriptPrintTextInternal(&sTextbox->text, sScriptFlagSets[scriptMsgType], speakerId, text);
    }
}

// These 2 functions are identical.
bool8 ScriptPrintTextOnBg(const char *text)
{
    if (text == NULL) {
        return ScriptClearTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptClearTextbox();
    }
    else {
        SetTextboxType(TEXTBOX_TYPE_ON_BG_PRESS, TRUE);
        return ScriptPrintTextInternal(&sTextbox->text, TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 | TEXTBOX_FLAG_UNUSED_x2, -1, text);
    }
}

bool8 ScriptPrintTextOnBg2(const char *text)
{
    if (text == NULL) {
        return ScriptClearTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptClearTextbox();
    }
    else {
        SetTextboxType(TEXTBOX_TYPE_ON_BG_PRESS, TRUE);
        return ScriptPrintTextInternal(&sTextbox->text, TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS | TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2 | TEXTBOX_FLAG_UNUSED_x2, -1, text);
    }
}

bool8 ScriptPrintTextOnBgAuto(s32 unused, const char *text)
{
    if (text == NULL) {
        return ScriptClearTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptClearTextbox();
    }
    else {
        SetTextboxType(TEXTBOX_TYPE_ON_BG_AUTO, TRUE);
        return ScriptPrintTextInternal(&sTextbox->text, 0x65, -1, text);
    }
}

bool8 sub_809AFAC(void)
{
    return (sTextbox->type == 4);
}

void sub_809AFC8(s32 a0_, s32 a1, s32 a2_, const char *text)
{
    s32 a0 = (u8) a0_;
    s32 a2 = (s16) a2_;

    sub_809B028(gUnknown_81160E8, 0, (a0 != 0), a1, a2, text);
}

bool8 sub_809AFFC(u8 *a0)
{
    s32 sp;
    bool8 ret = sub_809B18C(&sp);

    if (a0 != NULL) {
        *a0 = (sp == 1);
    }
    return ret;
}

void sub_809B028(const MenuItem * menuItems, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text)
{
    s32 a1 = (u8) a1_;
    s32 a4 = (s16) a4_;

    SetTextboxType(sScriptTextboxTypes[a3], FALSE);
    sTextbox->unk414 = 1;
    sTextbox->unk418 = NULL;
    sTextbox->unk41C = menuItems;
    sTextbox->unk420 = 2;
    sTextbox->unk424 = (a1 != 0) ? 2 : 0;
    sTextbox->unk428 = 0;
    sTextbox->unk430 = a2;
    if (sScriptFlagSets[a3] & TEXTBOX_FLAG_SPEAKER) {
        if (a4 < 0) {
            strcpy(gSpeakerNameBuffer, sYellowSpeechBubbleText);
        }
        else {
            sprintfStatic(gSpeakerNameBuffer, sYellowStringText, gFormatBuffer_Names[a4]);
        }
    }

    CreateMenuDialogueBoxAndPortrait(text, sub_809B428, a2, menuItems, 0, 4, 0, GetSpeakerPortrait(a4),
         ((sScriptFlagSets[a3] & TEXTBOX_FLAG_SPEAKER) ? STR_FORMAT_FLAG_SPEAKER_NAME | STR_FORMAT_FLAG_DIALOGUE_SOUND : 0)
        | ((sScriptFlagSets[a3] & TEXTBOX_FLAG_DIALOGUE_SOUND) ? STR_FORMAT_FLAG_DIALOGUE_SOUND : 0)
        | ((sScriptFlagSets[a3] & TEXTBOX_FLAG_INSTANT_TEXT) ? STR_FORMAT_FLAG_INSTANT_TEXT | STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS_2 : STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS_2));

    if (sTextbox->unk424 & 2) {
        sub_809A6E4(1);
    }
}

bool8 sub_809B18C(s32 *sp)
{
    if (sp != NULL) {
        *sp = sTextbox->unk430;
    }

    return (sTextbox->unk420 == 3);
}

bool8 sub_809B1C0(s32 a0, u32 kind, void *a2)
{
    return sub_809B1D4(a0, kind, 0, a2);
}

bool8 sub_809B1D4(s32 a0, u32 kind, s32 a2, void *a3)
{
    switch (a0) {
        case 0xB:
            if (sub_8021700(kind)) {
                return FALSE;
            }
            break;
        case 0xC:
            sub_8001D88();
            if (HasZeroUnlockedDungeons()) {
                return FALSE;
            }
            break;
    }

    SetTextboxType(4, FALSE);
    sTextbox->unk414 = a0;
    sTextbox->unk418 = NULL;
    sTextbox->unk41C = NULL;
    sTextbox->unk420 = 1;
    sTextbox->unk424 = kind;
    sTextbox->unk428 = a2;
    sTextbox->unk42C.str = a3;
    sTextbox->unk430 = -1;
    return TRUE;
}

// The same as sub_809B18C
bool8 sub_809B260(s32 *a0)
{
    if (a0 != NULL) {
        *a0 = sTextbox->unk430;
    }

    return (sTextbox->unk420 == 3);
}

static void ResetTextbox(void)
{
    SetCharacterMask(3);
    // All this function call does is basically setting textboxText->unk4 = 0;
    ScriptPrintTextInternal(&sTextbox->text, 0, -1, NULL);
}

static bool8 ScriptPrintTextInternal(struct TextboxText *textboxText, u32 flags_, s32 speakerId_, const char *text)
{
    u16 flags = (u16) flags_;
    s32 speakerId = (s16) speakerId_;

    textboxText->flags = flags;
    if (text == NULL) {
        if (flags == 0) {
            textboxText->unk4 = 0;
            return FALSE;
        }

        if (flags & 4) {
            sub_8014490();
            SetTextboxType(0, TRUE);
        }
        return TRUE;
    }

    textboxText->unk4 = 1;
    if (flags & TEXTBOX_FLAG_SPEAKER) {
        if (speakerId < 0) {
            strcpy(gSpeakerNameBuffer, sYellowSpeechBubbleText);
        }
        else {
            sprintfStatic(gSpeakerNameBuffer, sYellowStringText, gFormatBuffer_Names[speakerId]);
        }
    }

    if (sTextbox->type == TEXTBOX_TYPE_ON_BG_AUTO) {
        sprintfStatic(textboxText->buffer, _("%s#[I]{WAIT_FRAMES 0x20}{0x81}{0x40}{WAIT_PRESS}\n#[O]{WAIT_FRAMES 0x20}{0x81}{0x40}"), text); // #[I] and #[O] are text macros to be documented
        text = textboxText->buffer;
    }

    CreateMenuDialogueBoxAndPortrait(text, sub_809B428, -1, NULL, 0, 3, 0, GetSpeakerPortrait(speakerId),
         ((flags & TEXTBOX_FLAG_SPEAKER) ? STR_FORMAT_FLAG_SPEAKER_NAME | STR_FORMAT_FLAG_DIALOGUE_SOUND : 0)
         | ((flags & TEXTBOX_FLAG_DIALOGUE_SOUND) ? STR_FORMAT_FLAG_DIALOGUE_SOUND : 0)
         | ((sTextbox->type == TEXTBOX_TYPE_ON_BG_AUTO) ? STR_FORMAT_FLAG_ONLY_TEXT : 0)
         | ((sTextbox->type == TEXTBOX_TYPE_ON_BG_PRESS) ? STR_FORMAT_FLAG_ONLY_TEXT : 0)
         | ((flags & TEXTBOX_FLAG_INSTANT_TEXT) ? STR_FORMAT_FLAG_INSTANT_TEXT : 0)
         | ((flags & TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS_2) ? STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS_2 : 0)
         | ((flags & TEXTBOX_FLAG_WAIT_FOR_BUTTON_PRESS) ? STR_FORMAT_FLAG_WAIT_FOR_BUTTON_PRESS : 0)
         | ((flags & 0x4) ? 0x200 : 0)
         | ((sTextbox->endMsgFrames != -1) ? STR_FORMAT_FLAG_TIMED_AUTO_MSG_CLOSE : 0)
                                     );

    return TRUE;
}

static bool8 IsTextboxOpen_809B40C(struct TextboxText *a0)
{
    switch (a0->unk4) {
        case 0:
        case 2:
        case 3:
            return FALSE;
    }
    return TRUE;
}

// It seems this function is effectively unused. It could be different in Blue however. The u8 * arguments most likely are pointers to some text drawing structures.
static u8 *sub_809B428(u8 *a0, s32 a1, u8 *a2)
{
    switch (a0[2]) {
        case 0x49:
            sub_8099A34(0x1E);
            a2[0x21] = 1;
            return NULL;
        case 0x4F:
            sub_8099A48(0x1E);
            a2[0x21] = 1;
            return NULL;
        case 0x57:
            if (sub_8099B94()) {
                return a0;
            }
            a2[0x21] = 1;
            return NULL;
        default:
            return NULL;
    }
}

void sub_809B474(void)
{
    const struct unkStruct_3001B64_unk418 *unkStructPtr;

    switch (sTextbox->type) {
        case 0:
        case 1:
        case 2:
        case 3:
        default:
            break;
        case 4:
            switch (sTextbox->unk420) {
                case 1:
                    if (!sub_809B648()) {
                        sTextbox->unk420 = 3;
                        SetTextboxType(0, TRUE);
                        break;
                    }

                    unkStructPtr = sTextbox->unk418;
                    if (unkStructPtr != NULL) {
                        if (unkStructPtr->unk4 != NULL) {
                            ResetTextbox();
                            if (!unkStructPtr->unk4()) {
                                sTextbox->unk430 = -1;
                                sTextbox->unk420 = 3;
                                SetTextboxType(0, TRUE);
                                break;
                            }
                        }
                        sub_809A6E4(unkStructPtr->unk0);
                    }
                    sTextbox->unk420 = 2;
                    // Fallthrough
                case 2:
                    unkStructPtr = sTextbox->unk418;
                    if (unkStructPtr != NULL) {
                        s32 retVal = unkStructPtr->unkC();
                        if (retVal == 0 || retVal == 1)
                            break;
                        sTextbox->unk430 = (retVal == 2) ? -1 : 0;
                        if (unkStructPtr->unk8 != NULL) {
                            unkStructPtr->unk8();
                        }
                        sub_809A6F8(unkStructPtr->unk0);
                    }
                    else if (sub_809B648()) {
                        break;
                    }
                    sTextbox->unk420 = 3;
                    SetTextboxType(0, TRUE);
                    break;
            }
            break;
    }
    sub_809B57C();
}

void sub_809B57C(void)
{
    DrawDialogueBoxString();
    switch (sTextbox->type) {
        case 1:
        case 2:
        case 3:
            switch (sTextbox->unk420) {
                default: {
                    s32 sp;
                    if (sub_80144A4(&sp) == 0) {
                        GroundScriptLock(1, sp);
                        sTextbox->unk420 = 3;
                        sTextbox->unk430 = sp;
                    }
                    break;
                }
                case 0:
                case 3: {
                    s32 sp;
                    if (sub_80144A4(&sp) == 0) {
                        GroundScriptLockJumpZero(0);
                        sTextbox->type = 0;
                    }
                    break;
                }
            }
            break;
    }

    if (sTextbox->unk434 < 0) {
        sub_8005838(0, 0);
    }
    else {
        sub_8005838(0, 5);
    }
}

void sub_809B614(void)
{
    sub_80060EC();
    gUnknown_20399DE = gUnknown_20399DC;
    gUnknown_20399DC &= 0xFFFD;
}

void sub_809B638(void)
{
    xxx_call_update_bg_vram();
}

UNUSED static void nullsub_210(void)
{

}

static const struct unkStruct_3001B64_unk418 gUnknown_81161A8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = sub_809C39C,
    .unkC = sub_801D0DC,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81161B8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = sub_809C3D8,
    .unkC = sub_801D0DC,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81161C8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = DeleteKangaskhanStorage,
    .unkC = KangaskhanStorageCallback,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81161D8 =
{
    .unk0 = 1,
    .unk4 = sub_8017E1C,
    .unk8 = sub_8017EF4,
    .unkC = sub_8017E54,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81161E8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = DestroyFelicityBank,
    .unkC = FelicityBankCallback,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81161F8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = DeleteKecleonBros,
    .unkC = KecleonBrosCallback,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116208 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = sub_801FD7C,
    .unkC = sub_801FC40,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116218 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = CleanWigglytuffShop,
    .unkC = sub_8021C5C,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116228 =
{
    .unk0 = 1,
    .unk4 = sub_8027F88,
    .unk8 = sub_809C504,
    .unkC = sub_8028078,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116238 =
{
    .unk0 = 1,
    .unk4 = sub_802B2D4,
    .unk8 = sub_802B3B8,
    .unkC = sub_802B358,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116248 =
{
    .unk0 = 1,
    .unk4 = CreateThankYouMailPelipper,
    .unk8 = CleanThankYouMailPelipper,
    .unkC = ThankYouMailPelipperCallback,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116258 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = CleanHelperPelipper,
    .unkC = HelperPelipperCallback,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116268 =
{
    .unk0 = 1,
    .unk4 = sub_802E864,
    .unk8 = sub_809C550,
    .unkC = sub_802E890,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116278 =
{
    .unk0 = 1,
    .unk4 = sub_802DFB0,
    .unk8 = sub_802E06C,
    .unkC = sub_802DFD8,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116288 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = sub_802DC00,
    .unkC = sub_802DBD4,
};

// These 3 are identical
static const struct unkStruct_3001B64_unk418 gUnknown_8116298 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = MakuhitaDojo_Delete,
    .unkC = HandleMakuhitaDojoState,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81162A8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = MakuhitaDojo_Delete,
    .unkC = HandleMakuhitaDojoState,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81162B8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = MakuhitaDojo_Delete,
    .unkC = HandleMakuhitaDojoState,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81162C8 =
{
    .unk0 = 0,
    .unk4 = CreateTestTracker,
    .unk8 = sub_809C464,
    .unkC = HandleTestTrackerState,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81162D8 =
{
    .unk0 = 0,
    .unk4 = sub_8035678,
    .unk8 = sub_809C478,
    .unkC = sub_80356A0,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81162E8 =
{
    .unk0 = 0,
    .unk4 = NULL,
    .unk8 = sub_809C4B0,
    .unkC = sub_803B120,
};

static const struct unkStruct_3001B64_unk418 gUnknown_81162F8 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = sub_809C414,
    .unkC = sub_8025354,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116308 =
{
    .unk0 = 0,
    .unk4 = NULL,
    .unk8 = NULL,
    .unkC = ScriptItemTextboxFunc,
};

static const struct unkStruct_3001B64_unk418 gUnknown_8116318 =
{
    .unk0 = 1,
    .unk4 = NULL,
    .unk8 = sub_801B72C,
    .unkC = sub_801B6AC,
};

static bool8 sub_809B648(void)
{
    switch (sTextbox->unk414) {
        case 2:
            if (sTextbox->unk420 != 1) {
                u32 pressed = gRealInputs.pressed;
                if ((pressed & AB_BUTTONS) != 0) {
                    sTextbox->unk430 = 1;
                    return 0;
                }

                if (sub_8094D14()) {
                    sTextbox->unk430 = 2;
                    return 0;
                }
                else {
                    return 1;
                }
            }
            ResetTextbox();
            return 1;
        case 3:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                return 1;
            }
            else {
                u32 held = gRealInputs.held;
                u32 pressed = gRealInputs.pressed;
                if ((!(pressed & B_BUTTON)) && ((held & B_BUTTON))) {
                    return 1;
                }
                return 0;
             }
            break;
        case 4:
             if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (sTextbox->unk424 == 0) {
                    CreateConfirmNameMenu(0, sTextbox->unk42C.str);
                }
                else {
                    CreateConfirmNameMenu(2, sTextbox->unk42C.str);
                }
                return 1;
             }
             else {
                s32 var = sub_8016080();
                if (var == 3) {
                    CleanConfirmNameMenu();
                    sTextbox->unk430 = 1;
                }
                else if (var == 2)  {
                    if (sTextbox->unk424 == 0) {
                        return 1;
                    }
                    CleanConfirmNameMenu();
                    sTextbox->unk430 = 0;
                    return 0;
                }
                else {
                    return 1;
                }
             }
             break;
          case 5:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                CreateConfirmNameMenu(1, sTextbox->unk42C.str);
            }
            else {
                s32 var = sub_8016080();
                if (var == 3) {
                    CleanConfirmNameMenu();
                    sTextbox->unk430 = 1;
                    return 0;
                }
                else if (var == 2) {
                    if (sTextbox->unk424 == 0) {
                        return 1;
                    }
                    CleanConfirmNameMenu();
                    sTextbox->unk430 = 0;
                    return 0;
                }
            }
            return 1;
        case 6:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                NamingScreen_Init(4,sTextbox->unk42C.str);
            }
            else {
                s32 var = NamingScreen_HandleInput();
                if (var == 3)
                {
                    NamingScreen_Free();
                    sTextbox->unk430 = 1;
                    return 0;
                }
                else if (var == 2)
                {
                    if (sTextbox->unk424 == 0) {
                        return 1;
                    }
                    NamingScreen_Free();
                    sTextbox->unk430 = 0;
                    return 0;
                }
            }
            return 1;
          case 7:
            sub_801D014(sTextbox->unk42C.mon);
            sTextbox->unk418 = &gUnknown_81161A8;
            PlayMenuSoundEffect(4);
            return 1;
          case 8:
            sub_801D014(sTextbox->unk42C.mon);
            sTextbox->unk418 = &gUnknown_81161B8;
            PlayMenuSoundEffect(4);
            return 1;
          case 9:
            ResetTextbox();
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (!sub_8015080(sTextbox->unk42C.str, gUnknown_811610C)) {
                    sTextbox->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch( sub_801516C())
                {
                    case 3:
                        sTextbox->unk430 = sub_8015198();
                        sub_80151A4();
                        return 0;
                    case 2:
                        sTextbox->unk430 = -1;
                        sub_80151A4();
                        return 0;
                }
            }
            return 1;
          case 10:
            ResetTextbox();
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (!sub_8015080(sTextbox->unk42C.str, sEmptyMenuItems)) {
                    sTextbox->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch( sub_801516C()) {
                    case 3:
                        sTextbox->unk430 = sub_8015198();
                        sub_80151A4();
                        return 0;
                    case 2:
                        sTextbox->unk430 = -1;
                        sub_80151A4();
                        return 0;
                }
            }
            return 1;
          case 11:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (!sub_80211AC(sTextbox->unk424,3)) {
                    sTextbox->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch(sub_8021274(1)) {
                    case 3:
                        sTextbox->unk430 =  sub_802132C();
                        sub_80213A0();
                        return 0;
                    case 2:
                        sTextbox->unk430 = -1;
                        sub_80213A0();
                        return 0;
                }
            }
            return 1;
        case 0xc:
            if (sTextbox->unk420 == 1) {
                s32 var = sub_80A2654(GetScriptVarValue(0,0x12));
                ResetTextbox();
                if (!DungeonListMenu_Init(3,0,10,TRUE)) {
                    sTextbox->unk430 = -1;
                    return 0;
                }
                if ((var != -1) && (!DungeonListMenu_MoveMenuTo(var))) {
                    SetScriptVarValue(0,0x12,-1);
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch (DungeonListMenu_GetInput(1)) {
                    case 3: {
                        s32 rescueDungeonId = DungeonListMenu_GetCurrentRescueDungeonId();
                        SetScriptVarValue(0, 0x12, RescueDungeonToScriptDungeonId(rescueDungeonId));
                        sTextbox->unk430 = rescueDungeonId;
                        DungeonListMenu_Free();
                        return 0;
                    }
                    case 2:
                        sTextbox->unk430 = -1;
                        DungeonListMenu_Free();
                        return 0;
                }
            }
            return 1;
          case 0xd:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (!sub_80302E8(3,0,10)) {
                    sTextbox->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch(sub_80303AC(1)) {
                    case 3:
                        sTextbox->unk430 = sub_8030418();
                        sub_8030480();
                        return 0;
                    case 2:
                        sTextbox->unk430 = -1;
                        sub_8030480();
                        return 0;
                }
            }
            return 1;
          case 0xe:
          case 0xf:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (sTextbox->unk414 == 0xe) {
                    SetScriptVarValue(0,0x18,1);
                }
                sub_8011C28(1);
                PrepareSavePakWrite(0);

                return 1;
            }
            if (WriteSavePak()) {
                return 1;
            }
            FinishWriteSavePak();
            return 0;
          case 0x10: {
            bool8 unkBool = (sub_80023E4(4) != 0);
            ResetTextbox();
            if (CreateKangaskhanStorage(unkBool)) {
                sTextbox->unk418 = &gUnknown_81161C8;
                return 1;
            }
            sTextbox->unk430 = -1;
            return 0;
          }
          case 0x11:
            sTextbox->unk418 = &gUnknown_81161D8;
            return 1;
          case 0x13: {
            bool8 unkBool = (sub_80023E4(4) != 0);
            ResetTextbox();
            if (CreateFelicityBank(unkBool)) {
                sTextbox->unk418 = &gUnknown_81161E8;
                return 1;
            }
            else {
                sTextbox->unk430 = -1;
                return 0;
            }
          }
          case 0x17:
          case 0x18: {
            u8 var;
            bool8 unkBool = sub_80023E4(4);
            ResetTextbox();
            if (sTextbox->unk414 == 0x17) {
                var = (unkBool == 0) ? 0 : 1;
            }
            else {
                var = 2;
                if (unkBool) {
                    var = 3;
                }
            }

            if (CreateKecleonBros(var)) {
                sTextbox->unk418 = &gUnknown_81161F8;
                return 1;
            }
            else {
               sTextbox->unk430 = -1;
                return 0;
            }
          }
          case 0x19: {
            bool8 unkBool = (sub_80023E4(4) != 0);
            ResetTextbox();
            if (sub_801FB50(unkBool)) {
                sTextbox->unk418 = &gUnknown_8116208;
                return 1;
            }
            else {
                sTextbox->unk430 = -1;
                return 0;
            }
          }
        case 0x1a:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                ClearScriptVarArray(0,0x39);
                sub_802465C();
                return 1;
            }
            else {
                s32 iVar10 = sub_80246F0();
                if (GetScriptVarValue(0,0x39) == 0 && HasEvolutionCompleted()) {
                    SetScriptVarValue(0,0x39,1);
                    GroundMap_ExecuteEvent(0x46,0);
                }

                if (iVar10 == 3) {
                    CleanLuminousCave();
                    sTextbox->unk430 = 1;
                    return 0;
                }
                else if (iVar10 == 2) {
                    CleanLuminousCave();
                    sTextbox->unk430 = 0;
                    return 0;
                }
                else {
                    return 1;
                }
            }
           return 0;
        case 0x1b: {
            bool8 unk = (sub_80023E4(4) != 0);
            ResetTextbox();
            if (CreateWigglytuffShop(unk)) {
                sTextbox->unk418 = &gUnknown_8116218;
                return 1;
            }
            sTextbox->unk430 = -1;
            return 0;
        }
          case 0x1c:
            sTextbox->unk418 = &gUnknown_8116228;
            return 1;
          case 0x1d:
            sTextbox->unk418 = &gUnknown_8116238;
            return 1;
          case 0x1e:
            sTextbox->unk418 = &gUnknown_8116248;
            return 1;
          case 0x1f:
            ResetTextbox();
            if (!CreateHelperPelipperMenu(0x130)) {
                sTextbox->unk430 = -1;
                return 0;
            }
            sTextbox->unk418 = &gUnknown_8116258;
            return 1;
          case 0x20:
            PlayMenuSoundEffect(4);
            sTextbox->unk418 = &gUnknown_8116268;
            return 1;
          case 0x21:
            PlayMenuSoundEffect(4);
            sTextbox->unk418 = &gUnknown_8116278;
            return 1;
          case 0x22: {
            u8 local_34;
            u32 local_30;
            s32 local_2c;
            struct unkStruct_8096AF8 local_28;

            if (sub_8099328(&local_34)) {
                GetScriptVarScenario(2,&local_30,&local_2c);
                while (local_2c < 8) {
                    sub_8096AF8(&local_28,local_2c,local_34);
                    if (local_28.unk0) {
                        ScenarioCalc(2,local_30,local_2c);
                        sTextbox->unk430 = (local_28.clientSpecies == 0 ? 0 : 1) + ((local_28.targetSpecies != 0) ? 2 : 0);
                        if (sTextbox->unk430 != 0) {
                            return 0;
                        }
                        else {
                            sTextbox->unk430 = 3;
                            return 0;
                        }
                    }
                    local_2c++;
                }
            }
            sTextbox->unk430 = 0;
            sub_8096BD0();
            ScenarioCalc(2,0,0);
            return 0;
          }
          case 0x23: {
            u32 local_20;
            u32 local_1c;
            struct unkStruct_8096AF8 local_18;
            u8 local_33;

            if (!sub_8099328(&local_33)) {
                return 0;
            }
            GetScriptVarScenario(2,&local_20,&local_1c);
            sub_8096AF8(&local_18,local_1c,local_33);
            if (!local_18.unk0) {
                return 0;
            }
            else if (!sub_802DB28(local_1c,local_33)) {
                return 0;
            }
            else {
                s32 iVar14 = GetScriptVarValue(0,0x19);
                if (iVar14 < 100) {
                    SetScriptVarValue(0,0x19,iVar14 + 1);
                }
                SetScriptVarValue(0,0x39,1);
                ScenarioCalc(2,local_20,local_1c + 1);
                sTextbox->unk418 = &gUnknown_8116288;
                return 1;
            }
          }
          case 0x24:
            if (sTextbox->unk420 == 1) {
              u32 uVar19 = sub_80023E4(4) == 0 ? 0 : 4;
              ResetTextbox();
              if (MakuhitaDojo_New(uVar19)) {
                   return 1;
              }
              else
              {
                  sTextbox->unk430 = -1;
                  return 0;
              }
            }
            else
            {
                 switch(HandleMakuhitaDojoState())
                {
                    default:
                        return 1;
                    case 3:
                        sTextbox->unk430 = sub_802FED0();
                        MakuhitaDojo_Delete();
                        return 0;
                    case 2:
                        sTextbox->unk430 = -1;
                        MakuhitaDojo_Delete();
                        return 0;

                }
            }
            return 0;
          case 0x25: {
            s32 var = 1;
            if (sub_80023E4(4)) {
                var = 5;
            }
            ResetTextbox();
            if (MakuhitaDojo_New(var)) {
                sTextbox->unk418 = &gUnknown_8116298;
                return 1;
            }
            else {
                sTextbox->unk430 = -1;
                return 0;
            }
          }
          case 0x26: {
            s32 var = 2;
            if (sub_80023E4(4)) {
                var = 6;
            }
            ResetTextbox();
            if (MakuhitaDojo_New(var)) {
                sTextbox->unk418 = &gUnknown_81162A8;
                return 1;
            }
            else {
                sTextbox->unk430 = -1;
                return 0;
            }
          }
          case 0x27: {
            s32 var = 3;
            if (sub_80023E4(4)) {
                var = 7;
            }
            ResetTextbox();
            if (MakuhitaDojo_New(var)) {
                sTextbox->unk418 = &gUnknown_81162B8;
                return 1;
            }
            else {
               sTextbox->unk430 = -1;
                return 0;
            }
          }
        case 0x28:
            sTextbox->unk418 = &gUnknown_81162C8;
            return 1;
        case 0x29:
            sTextbox->unk418 = &gUnknown_81162D8;
            return 1;
        case 0x2a:
            ResetTextbox();
            if (sub_803B050()) {
                sub_803B100(sTextbox->unk5A4);
                sTextbox->unk418 = &gUnknown_81162E8;
                return 1;
            }
            sTextbox->unk430 = -1;
            return 0;
        case 0x12:
            sTextbox->unk430 = 1;
            break;
        case 0x14:
        case 0x15:
            ResetTextbox();
            return 0;
          case 0x16:
            if (CreateFriendListMenu(2)) {
                sTextbox->unk418 = &gUnknown_81162F8;
                return 1;
            }
            sTextbox->unk430 = -2;
            return 0;
        case 0x2b:
            sTextbox->unk430 = TryGiveScriptItem(sTextbox->unk424,sTextbox->unk428);
            sTextbox->unk418 = &gUnknown_8116308;
            return 1;
        case 0x2c: {
            s32 uVar13 = sTextbox->unk428;
            u8 uVar1 = sTextbox->unk424;
            ResetTextbox();
            if (sub_801B60C(uVar13,uVar1,1)) {
                sTextbox->unk418 = &gUnknown_8116318;
                return 1;
            }
            else {
                sTextbox->unk430 = -1;
                return 0;
            }
        }
        case 0x2d:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                ShowWindows(NULL, 1, 1);
                if (sub_801A5D8(0,0,NULL,10)) {
                    return 1;
                }
                else {
                    sTextbox->unk430 = -1;
                    return 0;
                }
            }
            else {
                switch(sub_801A6E8(TRUE)) {
                    case 3: {
                        s32 itemArrayId = sub_801A8AC();
                        s32 itemId = gTeamInventoryRef->teamItems[itemArrayId].id;
                        if (IsEdibleItem(itemId)) {
                            BufferItemName(gFormatBuffer_Items[0],itemId,0);
                            ShiftItemsDownFrom(itemArrayId);
                            sTextbox->unk430 = 1;
                        }
                        else {
                            sTextbox->unk430 = -1;
                        }
                        sub_801A928();
                        return 0;
                    }
                    case 2:
                        sTextbox->unk430 = -1;sub_801A928();return 0;
                        return 0;
                    default:
                        return 1;
                }
            }
            break;
        case 0x2E:
            if (sTextbox->unk420 == 1) {
                ResetTextbox();
                if (DrawCredits(sTextbox->unk424, sTextbox->unk428)) {
                    return 1;
                }
                sTextbox->unk430 = -1;
                return 0;
            }
            else {
                switch (sub_8035574()) {
                    case 2:
                    case 3:
                        sTextbox->unk430 = -1;
                        sub_803565C();
                        return 0;
                    default:
                        return 1;
                }
            }
            break;
    }

    return 0;
}

static void sub_809C39C(void)
{
    sTextbox->unk430 = sub_801D178();
    if(sTextbox->unk430 == 3)
        GroundMainGroundRequest(FriendAreaIdToMapId(sub_801D1D4()), 0, -1);
    sub_801D1E0();
}

static void sub_809C3D8(void)
{
    sTextbox->unk430 = sub_801D178();
    if(sTextbox->unk430 == 3)
        GroundMainGroundRequest(FriendAreaIdToMapId(sub_801D1D4()), 0, -1);
    sub_801D1E0();
}

static void sub_809C414(void)
{
    u8 val;

    val = sub_802540C();

    if(val != 0)
    {
        sTextbox->unk430 = val;
        GroundMainGroundRequest(FriendAreaIdToMapId(val), 0, -1);
    }
    else
{
        sTextbox->unk430 = -1;
    }
    CleanFriendListMenu();

}

static void sub_809C464(void)
{
	DeleteTestTracker();
	sub_8001064();
	sub_809965C();
}

static void sub_809C478(void)
{
    s32 temp;
    s32 temp1;

    if(sub_80356A0() == 0x3)
    {
        PlaySound(0x313);
        InitFlash();
        ClearFlashData();
    }

    sub_8035758();

    GetScriptVarScenario(SCENARIO_MAIN, &temp, &temp1);
    sub_80993C0(0);
}

static void sub_809C4B0(void)
{
    s16 scriptIndex_s16;
    s32 scriptIndex = -1;

    if (sTextbox->unk430 == 0) {
        scriptIndex = sub_803B168();

        ASM_MATCH_TRICK(sTextbox->unk5A4);
        scriptIndex_s16 = scriptIndex;

        sTextbox->unk5A4 = scriptIndex_s16;
        sTextbox->unk430 = scriptIndex;
    }
    else {
        sTextbox->unk430 = -1;
    }

    sub_803B1BC();

    if (scriptIndex != -1)
        GroundMap_ExecuteEvent(scriptIndex, 0);
}

static void sub_809C504(void)
{
    u8 temp;

    if(sub_80282DC(&temp) == 1)
    {
        sub_809927C(temp);
        sTextbox->unk430 = 1;
    }
    else
    {
        sTextbox->unk430 = -1;
    }
    sub_80282FC();
}

static void sub_809C550(void)
{
    u32 ret;
    s32 val;

    ret = sub_802E90C();
    val = 0;
    sub_802E918();

    switch(ret)
    {
        case 1:
            if(ScriptVarScenarioBefore(SCENARIO_SUB1, 0x1D, 0x3))
               val = 1;
            break;
        case 2:
            if(ScriptVarScenarioBefore(SCENARIO_SUB1, 0x1F, 0x2))
                val = 2;
            break;
        case 3:
            if(ScriptVarScenarioBefore(SCENARIO_SUB8, 0x33, 0x8))
               val = 3;
            break;
    }
    sTextbox->unk430 = val;
}
