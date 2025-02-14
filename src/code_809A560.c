#include "global.h"
#include "globaldata.h"
#include "text.h"
#include "memory.h"
#include "pokemon.h"
#include "ground_script.h"
#include "code_8099360.h"
#include "code_800D090.h"
#include "code_800558C.h"
#include "pokemon_mid.h"
#include "string_format.h"
#include "structs/str_3001B64.h"
#include "constants/dungeon.h"
#include "wigglytuff_shop1.h"
#include "event_flag.h"
#include "input.h"
#include "ground_main.h"
#include "code_801D014.h"
#include "kangaskhan_storage1.h"
#include "kangaskhan_storage2.h"
#include "felicity_bank.h"
#include "kecleon_bros1.h"
#include "gulpin_shop_801FB50.h"
#include "wigglytuff_shop3.h"
#include "wonder_mail.h"
#include "flash.h"
#include "code_80118A4.h"
#include "friend_list_menu.h"
#include "personality_test1.h"
#include "credits2.h"

IWRAM_INIT struct unkStruct_3001B64 *gUnknown_3001B64 = {NULL};

extern u16 gUnknown_20399DC;
extern u16 gUnknown_20399DE;

extern bool8 sub_802FCF0(void);
u8 ScriptPrintText_809B2B8(struct unkStruct_3001B64_unkC *, s32, s32, const char *);
bool8 IsTextboxOpen_809B40C(struct unkStruct_3001B64_unkC *);
extern void sub_801416C(s32, s32);
extern void ResetTextbox_809B294(void);
extern void sub_8014144(void);

u32 xxx_script_textboxes_809A680(u32 param_1, u32 param_2);
void sub_809A62C(void);
void sub_809A7EC(void);
void sub_809A83C(s16 index);
extern void sub_80A8EC0(u8 *, u32);
PokemonStruct1 *sub_808D3BC(void);
PokemonStruct1 *sub_808D3F8(void);
PokemonStruct1 *sub_80A8D54(s16);
void sub_80A7DDC(s16 *, s16*);
u8 sub_80A8CF0(s16);
s16 sub_80A7AE8(s16);
s16 sub_80A8BFC(s32);

struct Unk8116040Struct
{
    s16 x;
    s16 y;
    bool8 flip;
};

static const struct Unk8116040Struct gUnknown_8116040[] =
{
    {2, 8, FALSE},
    {12, 5, FALSE},
    {2, 8, FALSE},
    {23, 8, TRUE},
    {7, 8, FALSE},
    {18, 8, TRUE},
    {13, 5, TRUE},
    {2, 8, TRUE},
    {23, 8, FALSE},
    {7, 8, TRUE},
    {18, 8, FALSE},
    {12, 1, FALSE},
    {2, 2, FALSE},
    {23, 2, TRUE},
    {7, 1, FALSE},
    {18, 1, TRUE},
    {13, 1, TRUE},
    {2, 2, TRUE},
    {23, 2, FALSE},
    {7, 1, TRUE},
    {18, 1, FALSE},
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

static const MenuItem gUnknown_811612C[] =
{
    {NULL, 0},
};

static const u32 gUnknown_8116134[] =
{
    1, 1, 1, 1, 1
};

static const u16 gUnknown_8116148[] =
{
    226, 194, 450, 706, 1, 289, 257, 269, 261, 0
};

ALIGNED(4) static const u8 sInvalidText[] = _("{COLOR RED_W}invalidity{RESET}");
ALIGNED(4) static const u8 sUndefineText[] = _("{COLOR RED_W}undefine{RESET}");
ALIGNED(4) static const u8 sSpeechBubbleText[] = _("{SPEECH_BUBBLE}");
ALIGNED(4) static const u8 sYellowSpeechBubbleText[] = _("{COLOR YELLOW_N}{SPEECH_BUBBLE}{RESET}");
ALIGNED(4) static const u8 sYellowStringText[] = _("{COLOR YELLOW_N}%s{RESET}");
// TODO: Convert to actual string
ALIGNED(4) static const u8 gUnknown_8116190[] = {0x25, 0x73, 0x23, 0x5b, 0x49, 0x5d, 0x23, 0x7e, 0x20, 0x81, 0x40, 0x23, 0x57, 0x0a, 0x23, 0x5b, 0x4f, 0x5d, 0x23, 0x7e, 0x20, 0x81, 0x40, 0x00};

void sub_809A560(void)
{
    sub_8014144();
    gUnknown_3001B64 = MemoryAlloc(sizeof(struct unkStruct_3001B64), 6);
    gUnknown_3001B64->unk0 = 0;
    gUnknown_3001B64->unk4 = -1;
    gUnknown_3001B64->unk8 = -1;
    gUnknown_20399DC = 0;
    gUnknown_20399DE = 0;
    sub_80095CC(0,0x14);
    xxx_call_save_unk_text_struct_800641C(0,1,1);
    sub_8009408(0,0x14);
    ResetTextbox_809B294();
    gUnknown_3001B64->unk414 = 0;
    gUnknown_3001B64->unk418 = NULL;
    gUnknown_3001B64->unk41C = 0;
    gUnknown_3001B64->unk420 = 0;
    gUnknown_3001B64->unk424 = 0;
    gUnknown_3001B64->unk428 = 0;
    gUnknown_3001B64->unk42C = NULL;
    gUnknown_3001B64->unk430 = -1;
    gUnknown_3001B64->unk434 = -1;
    sub_809A7EC();
    gUnknown_3001B64->unk5A4 = -1;
}

void sub_809A610(void)
{
    sub_809A62C();
    MemoryFree(gUnknown_3001B64);
    gUnknown_3001B64 = NULL;
}

void sub_809A62C(void)
{
    s32 index;

    gUnknown_3001B64->unk0 = 0;
    gUnknown_3001B64->unk4 = -1;
    gUnknown_3001B64->unk8 = -1;
    gUnknown_20399DC = 0;
    gUnknown_20399DE = 0;
    for(index = 0; index < 10; index++)
    {
        sub_809A83C(index);
    }
    gUnknown_3001B64->unk414 = 0;
    xxx_script_textboxes_809A680(0, 1);
}

u32 xxx_script_textboxes_809A680(u32 param_1, u32 param_2)
{
    switch(param_1) {
        case 0:
            ResetTextbox_809B294();
            xxx_call_save_unk_text_struct_800641C(0,1,1);
            break;
        case 1:
            ResetTextbox_809B294();
            break;
        case 2:
            ResetTextbox_809B294();
            break;
        case 3:
            ResetTextbox_809B294();
            break;
        case 4:
            ResetTextbox_809B294();
            break;
        default:
            ResetTextbox_809B294();
            xxx_call_save_unk_text_struct_800641C(0,1,1);
    }
    gUnknown_3001B64->unk0 = param_1;
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

u16 sub_809A70C(u16 r0)
{
    return gUnknown_20399DC;
}

void nullsub_209(void) {}

void sub_809A71C(s32 param_1)
{
    gUnknown_3001B64->unk4 = param_1;
    gUnknown_3001B64->unk8 = param_1;
    sub_801416C(param_1, param_1);
}

void sub_809A738(s32 param_1, s32 param_2)
{
    gUnknown_3001B64->unk4 = param_1;
    gUnknown_3001B64->unk8 = param_2;
    sub_801416C(param_1, param_2);
}

u8 IsTextboxOpen_809A750(void)
{
    return IsTextboxOpen_809B40C(&gUnknown_3001B64->unkC);
}

u32 sub_809A768(void)
{
    return 0;
}

u8 ScriptPrintNullTextbox(void)
{
    switch(gUnknown_3001B64->unk0)
    {
        case 3:
            return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC,4,-1,0);
        case 1:
        case 2:
            return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC,0x84,-1,0);
        default:
            xxx_script_textboxes_809A680(0, 1);
            return 0;
    }
}

u8 ScriptPrintEmptyTextbox(void)
{
    switch(gUnknown_3001B64->unk0)
    {
        case 3:
        case 1:
        case 2:
            return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC,4,-1,0);
        default:
            xxx_script_textboxes_809A680(0, 1);
            return 0;
    }
}

void sub_809A7EC(void)
{
    s32 counter;
    struct unkStruct_3001B64_sub *temp;

    temp = &gUnknown_3001B64->unk43C[0];

    for(counter = 0; counter < 10; counter++, temp++)
    {
        temp->unk0 |= -1;
        temp->speciesID = MONSTER_NONE;
        temp->unk4 = 0;
        temp->unk5 = 0;
        temp->unk6 |= -1;
        temp->unk7 = 0;
        temp->unk8.a0 = 0;
        temp->unk8.a4 = 0;
        temp->monPortrait.faceFile = NULL;
        temp->monPortrait.faceData = NULL;
        temp->monPortrait.spriteId = 0;
        temp->faceFile = NULL;
    }
}

void sub_809A83C(s16 param_1)
{
    s32 param1 = param_1;
    struct unkStruct_3001B64_sub *temp = &gUnknown_3001B64->unk43C[param1];

    temp->unk0 = -1;
    temp->speciesID = 0;
    temp->unk4 = 0;
    temp->unk5 = 0;
    temp->unk6 = -1;
    temp->unk7 = 0;
    temp->unk8.a0 = 0;
    temp->unk8.a4 = 0;
    temp->monPortrait.faceFile = NULL;
    temp->monPortrait.faceData = NULL;
    temp->monPortrait.spriteId = 0;
    strcpy(gFormatBuffer_Monsters[param_1], sInvalidText);
    strcpy(gFormatBuffer_Names[param_1], sInvalidText);
    if(temp->faceFile)
    {
        CloseFile(temp->faceFile);
        temp->faceFile = NULL;
    }
}

bool8 sub_809A8B8(s32 param_1, s32 param_2)
{
    bool8 ret;
    s16 local_26;
    s32 iVar5 = (s16) param_1;
    s16 local_28 = (s16) param_2;
    struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[iVar5];
    u8 uVar9 = 1;
    u8 byte1 = 0;

    if (unkPtr->faceFile != NULL) {
        CloseFile(unkPtr->faceFile);
        unkPtr->faceFile = NULL;
    }

    sub_80A7DDC(&local_28,&local_26);
    if (local_28 >= 10 && local_28 <= 29) {
        PokemonStruct1 *pPVar6 = sub_80A8D54(local_28);
        if (pPVar6 == NULL) {
            uVar9 = '\0';
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
            switch (local_26) {
                case 0x104:
                case 0x133:
                case 0x183:
                case 0x198:
                case 0x199:
                    break;
                default:
                    uVar9 = 0;
                    break;
            }
        }
        else {
            switch (local_26) {
                case 0x90:
                case 0x91:
                case 0x92:
                case 0x96:
                case 0x10C:
                case 0x10D:
                case 0x10E:
                case 0x112:
                case 0x113:
                case 0x19A:
                case 0x19B:
                case 0x19C:
                case 0x19D:
                case 0x19E:
                case 0x1A7:
                    break;
                default:
                    uVar9 = 0;
                    break;
            }
        }
    }

    switch(local_28) {
        case 1:
        case 2:
        case 6:
        case 7:
        case 0x21:
        case 0x22:
        if (sub_80A8CF0(local_26) != 0) {
            byte1 = 0x1;
        }
        else {
            uVar9 = 0;
        }
        break;
    }

    if (local_28 != -1) {
        s32 sVar3 = sub_80A7AE8(local_28);
        if (sVar3 >= 0) {
            unkPtr->unk0 = local_28;
            unkPtr->speciesID = sub_80A8BFC(sVar3);
            strcpy(gFormatBuffer_Monsters[iVar5], sUndefineText);
            strcpy(gFormatBuffer_Names[iVar5], sUndefineText);
            unkPtr->unk4 = uVar9;
            unkPtr->unk5 = byte1;
            unkPtr->unk6 = 0xff;
            unkPtr->unk7 = 0;
            unkPtr->unk8.a0 = 0;
            unkPtr->unk8.a4 = 0;
            unkPtr->monPortrait.faceFile = NULL;
            unkPtr->monPortrait.faceData = NULL;
            unkPtr->monPortrait.spriteId = 0;
            ret = TRUE;
        }
        else if (local_26 != 0) {
            unkPtr->unk0 = local_28;
            unkPtr->speciesID = local_26;
            strcpy(gFormatBuffer_Monsters[iVar5], sUndefineText);
            strcpy(gFormatBuffer_Names[iVar5], sUndefineText);
            unkPtr->unk4 = uVar9;
            unkPtr->unk5 = byte1;
            unkPtr->unk6 = 0xff;
            unkPtr->unk7 = 0;
            unkPtr->unk8.a0 = 0;
            unkPtr->unk8.a4 = 0;
            unkPtr->monPortrait.faceFile = NULL;
            unkPtr->monPortrait.faceData = NULL;
            unkPtr->monPortrait.spriteId = 0;
            ret = TRUE;
        }
        else {
            sub_809A83C(iVar5);
            ret = FALSE;
        }
    }
    else {
        sub_809A83C(iVar5);
        ret = FALSE;
    }

    return ret;
}

bool8 sub_809AB4C(s32 a0_, s32 a1_)
{
    s32 a0 = (s16) a0_;
    s32 a1 = (s16) a1_;
    struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[a0];

    if (sub_809A8B8(a0, a1)) {
        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[a0], unkPtr->speciesID);
        strcpy(gFormatBuffer_Names[a0], sSpeechBubbleText);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_809ABB4(s32 a0_, s32 a1_)
{
    s32 a0 = (s16) a0_;
    s32 a1 = (s16) a1_;
    struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[a0];

    if (sub_809A8B8(a0, a1)) {
        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[a0], unkPtr->speciesID);
        strcpy(gFormatBuffer_Names[a0], gFormatBuffer_Monsters[a0]);
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
    struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[a0];

    if (sub_809A8B8(a0, a1)) {
        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[a0], unkPtr->speciesID);
        sub_80A8EC0(gFormatBuffer_Names[a0], unkPtr->unk0);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_809AC7C(s32 a0_, s32 a1_, s32 a2_)
{
    s32 a0 = (s16) a0_;
    s32 r5 = (s8) a1_;
    u8 a2 = (u8) a2_;
    struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[a0];

    if (unkPtr->faceFile != NULL) {
        CloseFile(unkPtr->faceFile);
        unkPtr->faceFile = NULL;
    }

    if (unkPtr->speciesID >= 0 && r5 != -1 && unkPtr->speciesID != 0) {
        if (a2 != 0x15) {
            unkPtr->unk7 = a2;
            unkPtr->unk8.a0 = 0;
            unkPtr->unk8.a4 = 0;
        }
        unkPtr->monPortrait.pos.x = gUnknown_8116040[unkPtr->unk7].x + unkPtr->unk8.a0;
        unkPtr->monPortrait.pos.y = gUnknown_8116040[unkPtr->unk7].y + unkPtr->unk8.a4;
        unkPtr->monPortrait.flip = gUnknown_8116040[unkPtr->unk7].flip;
        unkPtr->monPortrait.unkE = 0;
        if (r5 == -2) {
            unkPtr->unk6 = r5;
            unkPtr->monPortrait.faceFile = NULL;
            unkPtr->monPortrait.faceData = NULL;
            unkPtr->monPortrait.spriteId = 0;
            return FALSE;
        }

        if (unkPtr->unk4) {
            unkPtr->faceFile = OpenPokemonDialogueSpriteFile(unkPtr->speciesID);
            if (unkPtr->faceFile != NULL) {
                unkPtr->unk6 = r5;
                unkPtr->monPortrait.faceFile = unkPtr->faceFile;
                GetFileDataPtr(unkPtr->faceFile, 0);
                switch (unkPtr->unk0) {
                    case 0x47:
                        if ((r5 & 0xF) < 6) {
                            r5 = (s8) (r5 + 6);
                            r5 = (s8) (r5 | 0x40);
                        }
                        break;
                    case 0x4D:
                        if (unkPtr->monPortrait.flip && (r5 & 0xF) < 4) {
                            unkPtr->monPortrait.flip = FALSE;
                            r5 = (s8) (r5 + 4);
                            r5 = (s8) (r5 | 0x40);
                        }
                        break;
                    case 0x53:
                        if (unkPtr->monPortrait.flip && (r5 & 0xF) < 1) {
                            unkPtr->monPortrait.flip = FALSE;
                            r5 = (s8) (r5 + 1);
                            r5 = (s8) (r5 | 0x40);
                        }
                        break;
                    case 0x73:
                        if (unkPtr->monPortrait.flip && (r5 & 0xF) < 2) {
                            unkPtr->monPortrait.flip = FALSE;
                            r5 = (s8) (r5 + 2);
                            r5 = (s8) (r5 | 0x40);
                        }
                        break;
                }

                unkPtr->monPortrait.faceData = (void *) unkPtr->faceFile->data;
                unkPtr->monPortrait.spriteId = r5 & 0xF;
            }
            else {
                unkPtr->monPortrait.faceFile = NULL;
                unkPtr->monPortrait.faceData = NULL;
                unkPtr->monPortrait.spriteId = 0;
            }
            return TRUE;
        }
    }

    unkPtr->unk6 = 0xFF;
    unkPtr->unk7 = 0;
    unkPtr->unk8.a0 = 0;
    unkPtr->unk8.a4 = 0;
    unkPtr->monPortrait.faceFile = NULL;
    unkPtr->monPortrait.faceData = NULL;
    unkPtr->monPortrait.spriteId = 0;
    return FALSE;
}

bool8 sub_809ADD8(s32 a0_, struct unkStruct_3001B64_sub_sub *a1)
{
    s32 a0 = (s16) a0_;
    struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[a0];

    if (unkPtr->speciesID < 0)
        return FALSE;
    if (unkPtr->speciesID == MONSTER_NONE)
        return FALSE;

    unkPtr->unk8 = *a1;
    unkPtr->monPortrait.pos.x = gUnknown_8116040[unkPtr->unk7].x + unkPtr->unk8.a0;
    unkPtr->monPortrait.pos.y = gUnknown_8116040[unkPtr->unk7].y + unkPtr->unk8.a4;
    return TRUE;
}

struct MonPortraitMsg *sub_809AE3C(s32 a0_)
{
    s32 a0 = (s16) a0_;

    if (a0 >= 0) {
        struct unkStruct_3001B64_sub *unkPtr = &gUnknown_3001B64->unk43C[a0];
        if (unkPtr->speciesID != MONSTER_NONE && unkPtr->unk6 == -1) {
            sub_809AC7C(a0, 0, 0);
        }
        if (unkPtr->monPortrait.faceFile != NULL) {
            return &unkPtr->monPortrait;
        }
    }

    return NULL;
}

bool8 ScriptPrintText(s32 a0, s32 a1_, const char *text)
{
    s32 a1 = (s16) a1_;

    if (text == NULL) {
        return ScriptPrintNullTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptPrintEmptyTextbox();
    }
    else {
        xxx_script_textboxes_809A680(gUnknown_8116134[a0], 0);
        return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC, gUnknown_8116148[a0], a1, text);
    }
}

bool8 sub_809AEEC(const char *text)
{
    if (text == NULL) {
        return ScriptPrintNullTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptPrintNullTextbox();
    }
    else {
        xxx_script_textboxes_809A680(2, 1);
        return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC, 0xC2, -1, text);
    }
}

bool8 sub_809AF2C(const char *text)
{
    if (text == NULL) {
        return ScriptPrintNullTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptPrintNullTextbox();
    }
    else {
        xxx_script_textboxes_809A680(2, 1);
        return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC, 0xC2, -1, text);
    }
}

bool8 sub_809AF6C(s32 unused, const char *text)
{
    if (text == NULL) {
        return ScriptPrintNullTextbox();
    }
    else if (text[0] == '\0') {
        return ScriptPrintNullTextbox();
    }
    else {
        xxx_script_textboxes_809A680(3, 1);
        return ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC, 0x65, -1, text);
    }
}

bool8 sub_809AFAC(void)
{
    return (gUnknown_3001B64->unk0 == 4);
}

struct unkStruct_8096AF8
{
    bool8 unk0;
    /* 0x2 */ s16 clientSpecies;
    /* 0x4 */ s16 targetSpecies;
};

void sub_809B028(const MenuItem *, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text);
bool8 sub_809B18C(s32 *sp);
extern void sub_8099A34(s32 a0);
extern void sub_8099A48(s32 a0);
extern void GroundScriptLock(s16 index, s32 r1);
extern void GroundScriptLockJumpZero(s16 index);
void sub_8096AF8(struct unkStruct_8096AF8 *, u8 slotIndex, u8 dungeon);
u8 sub_802DB28(u8, u8);
void sub_8096BD0();
void ScenarioCalc(s16 varId, s32 main, s32 sub);
void MakuhitaDojo_Delete();
s32 HandleMakuhitaDojoState();
s16 sub_802FED0();
u8 sub_801FB50();
void sub_80151C0();
void sub_80155F0();
s32 sub_80160D8();
void ResetTextbox_809B294();
u8 sub_801A5D8();
s32 sub_801A6E8(s32);
s32 sub_801A8AC();
void sub_801A928();
s32 sub_8016080();
void CleanConfirmNameMenu();
u32 CreateConfirmNameMenu(u32 mode, u8 *name);
bool8 DrawCredits(s32 creditsCategoryIndex, s32);
u32 sub_8035574();
void sub_803565C();
u8 sub_8094D14();
void sub_802465C();
s32 sub_80246F0();
s32 GetScriptVarValue(u8 *localVarBuf, s32 varId);
bool8 HasEvolutionCompleted();
void GroundMap_ExecuteEvent();
void SetScriptVarValue(u8 *localVarBuf, s32 varId, s32 val);
void CleanLuminousCave();
u8 sub_80023E4();
u8 CreateFriendListMenu();
void PlayMenuSoundEffect();
bool8 sub_8015080(u8 *buffer, const MenuItem *menuItems);
s32 sub_801516C();
void sub_80151A4();
s32 sub_8015198();
u8 sub_80211AC();
void sub_80213A0();
u8 sub_802132C();
u8 MakuhitaDojo_New();
u8 sub_803B050();
void sub_803B100();
s32 sub_809CCDC();
u8 sub_801B60C();
u8 CreateKecleonBros();
s16 sub_80A2654(s16);
u8 sub_802F73C();
u8 sub_802F848();
s32 sub_802F8A0();
void sub_802F974();
s16 sub_802F90C();
s16 sub_80A26B8();
u8 sub_80302E8();
s32 sub_80303AC();
void sub_8030480();
s16 sub_8030418();
void PrepareSavePakWrite();
u8 WriteSavePak();
void FinishWriteSavePak();
u8 CreateKangaskhanStorage();
void sub_8011C28();
u8 CreateHelperPelipperMenu();
u8 CreateWigglytuffShop();
u8 sub_8099328();
void GetScriptVarScenario(s32 varId,u32 *outMain,u32 *outSub);
u32 sub_802E90C();
void sub_802E918();
u32 sub_80282DC(u8 *r0);
void sub_809927C(u8);
void sub_80282FC(void);
void sub_8001064(void);

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

u8 *sub_809B428(u8 *a0, s32 a1, u8 *a2);

void sub_809B028(const MenuItem * menuItems, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text)
{
    s32 a1 = (u8) a1_;
    s32 a4 = (s16) a4_;

    xxx_script_textboxes_809A680(gUnknown_8116134[a3], 0);
    gUnknown_3001B64->unk414 = 1;
    gUnknown_3001B64->unk418 = NULL;
    gUnknown_3001B64->unk41C = menuItems;
    gUnknown_3001B64->unk420 = 2;
    gUnknown_3001B64->unk424 = (a1 != 0) ? 2 : 0;
    gUnknown_3001B64->unk428 = 0;
    gUnknown_3001B64->unk430 = a2;
    if (gUnknown_8116148[a3] & 0x100) {
        if (a4 < 0) {
            strcpy(gSpeakerNameBuffer, sYellowSpeechBubbleText);
        }
        else {
            sprintfStatic(gSpeakerNameBuffer, sYellowStringText, gFormatBuffer_Names[a4]);
        }
    }

    CreateMenuDialogueBoxAndPortrait(text, sub_809B428, a2, menuItems, 0, 4, 0, sub_809AE3C(a4),
         ((gUnknown_8116148[a3] & 0x100) ? 0xC : 0) | ((gUnknown_8116148[a3] & 0x200) ? 0x4 : 0) | ((gUnknown_8116148[a3] & 0x20) ? 0x21 : 1)); // What an ugly way to get flags lol
    if (gUnknown_3001B64->unk424 & 2) {
        sub_809A6E4(1);
    }
}

bool8 sub_809B18C(s32 *sp)
{
    if (sp != NULL) {
        *sp = gUnknown_3001B64->unk430;
    }

    return (gUnknown_3001B64->unk420 == 3);
}

bool8 sub_809B1D4(s32 a0, u32 kind, s32 a2, u8 *a3);

bool8 sub_809B1C0(s32 a0, u32 kind, u8 *a2)
{
    return sub_809B1D4(a0, kind, 0, a2);
}

bool8 sub_809B1D4(s32 a0, u32 kind, s32 a2, u8 *a3)
{
    switch (a0) {
        case 0xB:
            if (sub_8021700(kind)) {
                return FALSE;
            }
            break;
        case 0xC:
            sub_8001D88();
            if (sub_802FCF0()) {
                return FALSE;
            }
            break;
    }

    xxx_script_textboxes_809A680(4, 0);
    gUnknown_3001B64->unk414 = a0;
    gUnknown_3001B64->unk418 = NULL;
    gUnknown_3001B64->unk41C = NULL;
    gUnknown_3001B64->unk420 = 1;
    gUnknown_3001B64->unk424 = kind;
    gUnknown_3001B64->unk428 = a2;
    gUnknown_3001B64->unk42C = a3;
    gUnknown_3001B64->unk430 = -1;
    return TRUE;
}

// The same as sub_809B18C
bool8 sub_809B260(s32 *a0)
{
    if (a0 != NULL) {
        *a0 = gUnknown_3001B64->unk430;
    }

    return (gUnknown_3001B64->unk420 == 3);
}

void ResetTextbox_809B294(void)
{
    SetCharacterMask(3);
    ScriptPrintText_809B2B8(&gUnknown_3001B64->unkC, 0, -1, NULL);
}

u8 ScriptPrintText_809B2B8(struct unkStruct_3001B64_unkC *ptr, s32 a1_, s32 a2_, const char *text)
{
    u16 a1 = (u16) a1_;
    s32 a2 = (s16) a2_;

    ptr->unk0 = a1;
    if (text == NULL) {
        if (a1 == 0) {
            ptr->unk4 = 0;
            return FALSE;
        }

        if (a1 & 4) {
            sub_8014490();
            xxx_script_textboxes_809A680(0, 1);
        }
        return TRUE;
    }

    ptr->unk4 = 1;
    if (a1 & 0x100) {
        if (a2 < 0) {
            strcpy(gSpeakerNameBuffer, sYellowSpeechBubbleText);
        }
        else {
            sprintfStatic(gSpeakerNameBuffer, sYellowStringText, gFormatBuffer_Names[a2]);
        }
    }

    if (gUnknown_3001B64->unk0 == 3) {
        sprintfStatic(ptr->buffer, gUnknown_8116190, text);
        text = ptr->buffer;
    }

    CreateMenuDialogueBoxAndPortrait(text, sub_809B428, -1, NULL, 0, 3, 0, sub_809AE3C(a2),
         ((a1 & 0x100) ? 0xC : 0)
         | ((a1 & 0x200) ? 0x4 : 0)
         | ((gUnknown_3001B64->unk0 == 3) ? 0x10 : 0)
         | ((gUnknown_3001B64->unk0 == 2) ? 0x10 : 0)
         | ((a1 & 0x20) ? 0x20 : 0)
         | ((a1 & 0x40) ? 0x1 : 0)
         | ((a1 & 0x80) ? 0x100 : 0)
         | ((a1 & 0x4) ? 0x200 : 0)
         | ((gUnknown_3001B64->unk4 != -1) ? 0x2 : 0)
                                     );

    return TRUE;
}

bool8 IsTextboxOpen_809B40C(struct unkStruct_3001B64_unkC *a0)
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
u8 *sub_809B428(u8 *a0, s32 a1, u8 *a2)
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

bool8 sub_809B648(void);
void sub_809B57C(void);

void sub_809B474(void)
{
    const struct unkStruct_3001B64_unk418 *unkStructPtr;

    switch (gUnknown_3001B64->unk0) {
        case 0:
        case 1:
        case 2:
        case 3:
        default:
            break;
        case 4:
            switch (gUnknown_3001B64->unk420) {
                case 1:
                    if (!sub_809B648()) {
                        gUnknown_3001B64->unk420 = 3;
                        xxx_script_textboxes_809A680(0, 1);
                        break;
                    }

                    unkStructPtr = gUnknown_3001B64->unk418;
                    if (unkStructPtr != NULL) {
                        if (unkStructPtr->unk4 != NULL) {
                            ResetTextbox_809B294();
                            if (!unkStructPtr->unk4()) {
                                gUnknown_3001B64->unk430 = -1;
                                gUnknown_3001B64->unk420 = 3;
                                xxx_script_textboxes_809A680(0, 1);
                                break;
                            }
                        }
                        sub_809A6E4(unkStructPtr->unk0);
                    }
                    gUnknown_3001B64->unk420 = 2;
                    // Fallthrough
                case 2:
                    unkStructPtr = gUnknown_3001B64->unk418;
                    if (unkStructPtr != NULL) {
                        s32 retVal = unkStructPtr->unkC();
                        if (retVal == 0 || retVal == 1)
                            break;
                        gUnknown_3001B64->unk430 = (retVal == 2) ? -1 : 0;
                        if (unkStructPtr->unk8 != NULL) {
                            unkStructPtr->unk8();
                        }
                        sub_809A6F8(unkStructPtr->unk0);
                    }
                    else if (sub_809B648()) {
                        break;
                    }
                    gUnknown_3001B64->unk420 = 3;
                    xxx_script_textboxes_809A680(0, 1);
                    break;
            }
            break;
    }
    sub_809B57C();
}

void sub_809B57C(void)
{
    DrawDialogueBoxString();
    switch (gUnknown_3001B64->unk0) {
        case 1:
        case 2:
        case 3:
            switch (gUnknown_3001B64->unk420) {
                default: {
                    s32 sp;
                    if (sub_80144A4(&sp) == 0) {
                        GroundScriptLock(1, sp);
                        gUnknown_3001B64->unk420 = 3;
                        gUnknown_3001B64->unk430 = sp;
                    }
                    break;
                }
                case 0:
                case 3: {
                    s32 sp;
                    if (sub_80144A4(&sp) == 0) {
                        GroundScriptLockJumpZero(0);
                        gUnknown_3001B64->unk0 = 0;
                    }
                    break;
                }
            }
            break;
    }

    if (gUnknown_3001B64->unk434 < 0) {
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

void nullsub_210(void)
{

}

void sub_809C39C(void);
void sub_809C3D8(void);
void sub_809C504(void);

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

extern const struct unkStruct_3001B64_unk418 gUnknown_81162F8;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116298;
extern const struct unkStruct_3001B64_unk418 gUnknown_81162A8;
extern const struct unkStruct_3001B64_unk418 gUnknown_81162B8;
extern const struct unkStruct_3001B64_unk418 gUnknown_81162C8;
extern const struct unkStruct_3001B64_unk418 gUnknown_81162D8;
extern const struct unkStruct_3001B64_unk418 gUnknown_81162E8;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116308;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116318;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116238;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116248;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116258;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116268;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116278;
extern const struct unkStruct_3001B64_unk418 gUnknown_8116288;

bool8 sub_809B648(void)
{
    switch (gUnknown_3001B64->unk414) {
        case 2:
            if (gUnknown_3001B64->unk420 != 1) {
                u32 pressed = gRealInputs.pressed;
                if ((pressed & AB_BUTTONS) != 0) {
                    gUnknown_3001B64->unk430 = 1;
                    return 0;
                }

                if (sub_8094D14()) {
                    gUnknown_3001B64->unk430 = 2;
                    return 0;
                }
                else {
                    return 1;
                }
            }
            ResetTextbox_809B294();
            return 1;
        case 3:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
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
             if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (gUnknown_3001B64->unk424 == 0) {
                    CreateConfirmNameMenu(0, gUnknown_3001B64->unk42C);
                }
                else {
                    CreateConfirmNameMenu(2, gUnknown_3001B64->unk42C);
                }
                return 1;
             }
             else {
                s32 var = sub_8016080();
                if (var == 3) {
                    CleanConfirmNameMenu();
                    gUnknown_3001B64->unk430 = 1;
                }
                else if (var == 2)  {
                    if (gUnknown_3001B64->unk424 == 0) {
                        return 1;
                    }
                    CleanConfirmNameMenu();
                    gUnknown_3001B64->unk430 = 0;
                    return 0;
                }
                else {
                    return 1;
                }
             }
             break;
          case 5:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                CreateConfirmNameMenu(1, gUnknown_3001B64->unk42C);
            }
            else {
                s32 var = sub_8016080();
                if (var == 3) {
                    CleanConfirmNameMenu();
                    gUnknown_3001B64->unk430 = 1;
                    return 0;
                }
                else if (var == 2) {
                    if (gUnknown_3001B64->unk424 == 0) {
                        return 1;
                    }
                    CleanConfirmNameMenu();
                    gUnknown_3001B64->unk430 = 0;
                    return 0;
                }
            }
            return 1;
        case 6:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                sub_80151C0(4,gUnknown_3001B64->unk42C);
            }
            else {
                s32 var = sub_80154F0();
                if (var == 3)
                {
                    sub_80155F0();
                    gUnknown_3001B64->unk430 = 1;
                    return 0;
                }
                else if (var == 2)
                {
                    if (gUnknown_3001B64->unk424 == 0) {
                        return 1;
                    }
                    sub_80155F0();
                    gUnknown_3001B64->unk430 = 0;
                    return 0;
                }
            }
            return 1;
          case 7:
            sub_801D014((void *) gUnknown_3001B64->unk42C);
            gUnknown_3001B64->unk418 = &gUnknown_81161A8;
            PlayMenuSoundEffect(4);
            return 1;
          case 8:
            sub_801D014((void *) gUnknown_3001B64->unk42C);
            gUnknown_3001B64->unk418 = &gUnknown_81161B8;
            PlayMenuSoundEffect(4);
            return 1;
          case 9:
            ResetTextbox_809B294();
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (!sub_8015080(gUnknown_3001B64->unk42C, gUnknown_811610C)) {
                    gUnknown_3001B64->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch( sub_801516C())
                {
                    case 3:
                        gUnknown_3001B64->unk430 = sub_8015198();
                        sub_80151A4();
                        return 0;
                    case 2:
                        gUnknown_3001B64->unk430 = -1;
                        sub_80151A4();
                        return 0;
                }
            }
            return 1;
          case 10:
            ResetTextbox_809B294();
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (!sub_8015080(gUnknown_3001B64->unk42C, gUnknown_811612C)) {
                    gUnknown_3001B64->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch( sub_801516C()) {
                    case 3:
                        gUnknown_3001B64->unk430 = sub_8015198();
                        sub_80151A4();
                        return 0;
                    case 2:
                        gUnknown_3001B64->unk430 = -1;
                        sub_80151A4();
                        return 0;
                }
            }
            return 1;
          case 11:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (!sub_80211AC(gUnknown_3001B64->unk424,3)) {
                    gUnknown_3001B64->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch(sub_8021274(1)) {
                    case 3:
                        gUnknown_3001B64->unk430 =  sub_802132C();
                        sub_80213A0();
                        return 0;
                    case 2:
                        gUnknown_3001B64->unk430 = -1;
                        sub_80213A0();
                        return 0;
                }
            }
            return 1;
        case 0xc:
            if (gUnknown_3001B64->unk420 == 1) {
                s32 var = sub_80A2654(GetScriptVarValue(0,0x12));
                ResetTextbox_809B294();
                if (!sub_802F73C(3,0,10,1)) {
                    gUnknown_3001B64->unk430 = -1;
                    return 0;
                }
                if ((var != -1) && (!sub_802F848(var))) {
                    SetScriptVarValue(0,0x12,-1);
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch (sub_802F8A0(1)) {
                    case 3: {
                        s32 var = sub_802F90C();
                        SetScriptVarValue(0, 0x12, sub_80A26B8(var));
                        gUnknown_3001B64->unk430 = var;
                        sub_802F974();
                        return 0;
                    }
                    case 2:
                        gUnknown_3001B64->unk430 = -1;
                        sub_802F974();
                        return 0;
                }
            }
            return 1;
          case 0xd:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (!sub_80302E8(3,0,10)) {
                    gUnknown_3001B64->unk430 = -1;
                    return 0;
                }
                PlayMenuSoundEffect(4);
            }
            else {
                switch(sub_80303AC(1)) {
                    case 3:
                        gUnknown_3001B64->unk430 = sub_8030418();
                        sub_8030480();
                        return 0;
                    case 2:
                        gUnknown_3001B64->unk430 = -1;
                        sub_8030480();
                        return 0;
                }
            }
            return 1;
          case 0xe:
          case 0xf:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (gUnknown_3001B64->unk414 == 0xe) {
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
            ResetTextbox_809B294();
            if (CreateKangaskhanStorage(unkBool)) {
                gUnknown_3001B64->unk418 = &gUnknown_81161C8;
                return 1;
            }
            gUnknown_3001B64->unk430 = -1;
            return 0;
          }
          case 0x11:
            gUnknown_3001B64->unk418 = &gUnknown_81161D8;
            return 1;
          case 0x13: {
            bool8 unkBool = (sub_80023E4(4) != 0);
            ResetTextbox_809B294();
            if (CreateFelicityBank(unkBool)) {
                gUnknown_3001B64->unk418 = &gUnknown_81161E8;
                return 1;
            }
            else {
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
          }
          case 0x17:
          case 0x18: {
            u8 var;
            bool8 unkBool = sub_80023E4(4);
            ResetTextbox_809B294();
            if (gUnknown_3001B64->unk414 == 0x17) {
                var = (unkBool == 0) ? 0 : 1;
            }
            else {
                var = 2;
                if (unkBool) {
                    var = 3;
                }
            }

            if (CreateKecleonBros(var)) {
                gUnknown_3001B64->unk418 = &gUnknown_81161F8;
                return 1;
            }
            else {
               gUnknown_3001B64->unk430 = -1;
                return 0;
            }
          }
          case 0x19: {
            bool8 unkBool = (sub_80023E4(4) != 0);
            ResetTextbox_809B294();
            if (sub_801FB50(unkBool)) {
                gUnknown_3001B64->unk418 = &gUnknown_8116208;
                return 1;
            }
            else {
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
          }
        case 0x1a:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
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
                    gUnknown_3001B64->unk430 = 1;
                    return 0;
                }
                else if (iVar10 == 2) {
                    CleanLuminousCave();
                    gUnknown_3001B64->unk430 = 0;
                    return 0;
                }
                else {
                    return 1;
                }
            }
           return 0;
        case 0x1b: {
            bool8 unk = (sub_80023E4(4) != 0);
            ResetTextbox_809B294();
            if (CreateWigglytuffShop(unk)) {
                gUnknown_3001B64->unk418 = &gUnknown_8116218;
                return 1;
            }
            gUnknown_3001B64->unk430 = -1;
            return 0;
        }
          case 0x1c:
            gUnknown_3001B64->unk418 = &gUnknown_8116228;
            return 1;
          case 0x1d:
            gUnknown_3001B64->unk418 = &gUnknown_8116238;
            return 1;
          case 0x1e:
            gUnknown_3001B64->unk418 = &gUnknown_8116248;
            return 1;
          case 0x1f:
            ResetTextbox_809B294();
            if (!CreateHelperPelipperMenu(0x130)) {
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
            gUnknown_3001B64->unk418 = &gUnknown_8116258;
            return 1;
          case 0x20:
            PlayMenuSoundEffect(4);
            gUnknown_3001B64->unk418 = &gUnknown_8116268;
            return 1;
          case 0x21:
            PlayMenuSoundEffect(4);
            gUnknown_3001B64->unk418 = &gUnknown_8116278;
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
                        gUnknown_3001B64->unk430 = (local_28.clientSpecies == 0 ? 0 : 1) + ((local_28.targetSpecies != 0) ? 2 : 0);
                        if (gUnknown_3001B64->unk430 != 0) {
                            return 0;
                        }
                        else {
                            gUnknown_3001B64->unk430 = 3;
                            return 0;
                        }
                    }
                    local_2c++;
                }
            }
            gUnknown_3001B64->unk430 = 0;
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
                gUnknown_3001B64->unk418 = &gUnknown_8116288;
                return 1;
            }
          }
          case 0x24:
            if (gUnknown_3001B64->unk420 == 1) {
              u32 uVar19 = sub_80023E4(4) == 0 ? 0 : 4;
              ResetTextbox_809B294();
              if (MakuhitaDojo_New(uVar19)) {
                   return 1;
              }
              else
              {
                  gUnknown_3001B64->unk430 = -1;
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
                        gUnknown_3001B64->unk430 = sub_802FED0();
                        MakuhitaDojo_Delete();
                        return 0;
                    case 2:
                        gUnknown_3001B64->unk430 = -1;
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
            ResetTextbox_809B294();
            if (MakuhitaDojo_New(var)) {
                gUnknown_3001B64->unk418 = &gUnknown_8116298;
                return 1;
            }
            else {
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
          }
          case 0x26: {
            s32 var = 2;
            if (sub_80023E4(4)) {
                var = 6;
            }
            ResetTextbox_809B294();
            if (MakuhitaDojo_New(var)) {
                gUnknown_3001B64->unk418 = &gUnknown_81162A8;
                return 1;
            }
            else {
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
          }
          case 0x27: {
            s32 var = 3;
            if (sub_80023E4(4)) {
                var = 7;
            }
            ResetTextbox_809B294();
            if (MakuhitaDojo_New(var)) {
                gUnknown_3001B64->unk418 = &gUnknown_81162B8;
                return 1;
            }
            else {
               gUnknown_3001B64->unk430 = -1;
                return 0;
            }
          }
        case 0x28:
            gUnknown_3001B64->unk418 = &gUnknown_81162C8;
            return 1;
        case 0x29:
            gUnknown_3001B64->unk418 = &gUnknown_81162D8;
            return 1;
        case 0x2a:
            ResetTextbox_809B294();
            if (sub_803B050()) {
                sub_803B100(gUnknown_3001B64->unk5A4);
                gUnknown_3001B64->unk418 = &gUnknown_81162E8;
                return 1;
            }
            gUnknown_3001B64->unk430 = -1;
            return 0;
        case 0x12:
            gUnknown_3001B64->unk430 = 1;
            break;
        case 0x14:
        case 0x15:
            ResetTextbox_809B294();
            return 0;
          case 0x16:
            if (CreateFriendListMenu(2)) {
                gUnknown_3001B64->unk418 = &gUnknown_81162F8;
                return 1;
            }
            gUnknown_3001B64->unk430 = -2;
            return 0;
        case 0x2b:
            gUnknown_3001B64->unk430 = sub_809CCDC(gUnknown_3001B64->unk424,gUnknown_3001B64->unk428);
            gUnknown_3001B64->unk418 = &gUnknown_8116308;
            return 1;
        case 0x2c: {
            s32 uVar13 = gUnknown_3001B64->unk428;
            u8 uVar1 = gUnknown_3001B64->unk424;
            ResetTextbox_809B294();
            if (sub_801B60C(uVar13,uVar1,1)) {
                gUnknown_3001B64->unk418 = &gUnknown_8116318;
                return 1;
            }
            else {
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
        }
        case 0x2d:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                xxx_call_save_unk_text_struct_800641C(NULL, 1, 1);
                if (sub_801A5D8(0,0,0,10)) {
                    return 1;
                }
                else {
                    gUnknown_3001B64->unk430 = -1;
                    return 0;
                }
            }
            else {
                switch(sub_801A6E8(1)) {
                    case 3: {
                        s32 itemArrayId = sub_801A8AC();
                        s32 itemId = gTeamInventoryRef->teamItems[itemArrayId].id;
                        if (IsEdibleItem(itemId)) {
                            BufferItemName(gFormatBuffer_Items[0],itemId,0);
                            ShiftItemsDownFrom(itemArrayId);
                            gUnknown_3001B64->unk430 = 1;
                        }
                        else {
                            gUnknown_3001B64->unk430 = -1;
                        }
                        sub_801A928();
                        return 0;
                    }
                    case 2:
                        gUnknown_3001B64->unk430 = -1;sub_801A928();return 0;
                        return 0;
                    default:
                        return 1;
                }
            }
            break;
        case 0x2E:
            if (gUnknown_3001B64->unk420 == 1) {
                ResetTextbox_809B294();
                if (DrawCredits(gUnknown_3001B64->unk424, gUnknown_3001B64->unk428)) {
                    return 1;
                }
                gUnknown_3001B64->unk430 = -1;
                return 0;
            }
            else {
                switch (sub_8035574()) {
                    case 2:
                    case 3:
                        gUnknown_3001B64->unk430 = -1;
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

void sub_809C39C(void)
{
    gUnknown_3001B64->unk430 = sub_801D178();
    if(gUnknown_3001B64->unk430 == 3)
        GroundMainGroundRequest(sub_8002694(sub_801D1D4()), 0, -1);
    sub_801D1E0();
}

void sub_809C3D8(void)
{
    gUnknown_3001B64->unk430 = sub_801D178();
    if(gUnknown_3001B64->unk430 == 3)
        GroundMainGroundRequest(sub_8002694(sub_801D1D4()), 0, -1);
    sub_801D1E0();
}

void sub_809C414(void)
{
    u8 val;

    val = sub_802540C();

    if(val != 0)
    {
        gUnknown_3001B64->unk430 = val;
        GroundMainGroundRequest(sub_8002694(val), 0, -1);
    }
    else
{
        gUnknown_3001B64->unk430 = -1;
    }
    CleanFriendListMenu();

}

void sub_809C464(void)
{
	DeleteTestTracker();
	sub_8001064();
	sub_809965C();
}

void sub_809C478(void)
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

// https://decomp.me/scratch/WyHAL  - (84.32% matching - Seth)
NAKED
void sub_809C4B0(void)
{
    asm_unified(
	"\tpush {r4,r5,lr}\n"
	"\tmovs r4, 0x1\n"
	"\tnegs r4, r4\n"
	"\tldr r5, _0809C4FC\n"
	"\tldr r0, [r5]\n"
	"\tmovs r2, 0x86\n"
	"\tlsls r2, 3\n"
	"\tadds r1, r0, r2\n"
	"\tldr r0, [r1]\n"
	"\tcmp r0, 0\n"
	"\tbne _0809C4DE\n"
	"\tbl sub_803B168\n"
	"\tlsls r0, 16\n"
	"\tldr r1, [r5]\n"
	"\tldr r3, _0809C500\n"
	"\tadds r2, r1, r3\n"
	"\tasrs r4, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r2]\n"
	"\tmovs r0, 0x86\n"
	"\tlsls r0, 3\n"
	"\tadds r1, r0\n"
"_0809C4DE:\n"
	"\tstr r4, [r1]\n"
	"\tbl sub_803B1BC\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tcmp r4, r0\n"
	"\tbeq _0809C4F4\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tbl GroundMap_ExecuteEvent\n"
"_0809C4F4:\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0809C4FC: .4byte gUnknown_3001B64\n"
"_0809C500: .4byte 0x000005a4");
}


void sub_809C504(void)
{
    u8 temp;

    if(sub_80282DC(&temp) == 1)
    {
        sub_809927C(temp);
        gUnknown_3001B64->unk430 = 1;
    }
    else
    {
        gUnknown_3001B64->unk430 = -1;
    }
    sub_80282FC();
}

void sub_809C550(void)
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
    gUnknown_3001B64->unk430 = val;
}
