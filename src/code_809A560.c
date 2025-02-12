#include "global.h"
#include "text.h"
#include "memory.h"
#include "pokemon.h"
#include "code_800D090.h"
#include "pokemon_mid.h"
#include "string_format.h"
#include "structs/str_3001B64.h"
#include "constants/dungeon.h"
#include "wigglytuff_shop1.h"
#include "event_flag.h"

IWRAM_INIT struct unkStruct_3001B64 *gUnknown_3001B64 = {NULL};

extern u16 gUnknown_20399DC;
extern u16 gUnknown_20399DE;
extern u8 gInvalidityText[];
extern u8 gUndefineText[];
extern const u8 gSpeechBubbleChar[];

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
    gUnknown_3001B64->unk418 = 0;
    gUnknown_3001B64->unk41C = 0;
    gUnknown_3001B64->unk420 = 0;
    gUnknown_3001B64->unk424 = 0;
    gUnknown_3001B64->unk428 = 0;
    gUnknown_3001B64->unk42C = 0;
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
    strcpy(gFormatBuffer_Monsters[param_1], gInvalidityText);
    strcpy(gFormatBuffer_Names[param_1], gInvalidityText);
    if(temp->faceFile)
    {
        CloseFile(temp->faceFile);
        temp->faceFile = NULL;
    }
}

PokemonStruct1 *sub_808D3BC(void);
PokemonStruct1 *sub_808D3F8(void);
PokemonStruct1 *sub_80A8D54(s16);
void sub_80A7DDC(s16 *, s16*);
u8 sub_80A8CF0(s16);
s16 sub_80A7AE8(s16);
s16 sub_80A8BFC(s32);

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
            strcpy(gFormatBuffer_Monsters[iVar5], gUndefineText);
            strcpy(gFormatBuffer_Names[iVar5], gUndefineText);
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
            strcpy(gFormatBuffer_Monsters[iVar5], gUndefineText);
            strcpy(gFormatBuffer_Names[iVar5], gUndefineText);
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
        strcpy(gFormatBuffer_Names[a0], gSpeechBubbleChar);
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

extern void sub_80A8EC0(u8 *, u32);

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

struct Unk8116040Struct
{
    u16 x;
    u16 y;
    bool8 flip;
};

extern const struct Unk8116040Struct gUnknown_8116040[];

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

extern const u32 gUnknown_8116134[];
extern const u16 gUnknown_8116148[];

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

extern const MenuItem gUnknown_81160E8[];
void sub_809B028(const MenuItem *, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text);
bool8 sub_809B18C(s32 *sp);

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

extern const char gUnknown_8116188[];
extern const char gUnknown_8116190[];
extern const char gFormattedSpeechBubble[];

bool8 sub_809B428(u8 *a0, s32 a1, u8 *a2);

void sub_809B028(const MenuItem * menuItems, s32 a1_, s32 a2, s32 a3, s32 a4_, const char *text)
{
    s32 a1 = (u8) a1_;
    s32 a4 = (s16) a4_;

    xxx_script_textboxes_809A680(gUnknown_8116134[a3], 0);
    gUnknown_3001B64->unk414 = 1;
    gUnknown_3001B64->unk418 = 0;
    gUnknown_3001B64->unk41C = menuItems;
    gUnknown_3001B64->unk420 = 2;
    gUnknown_3001B64->unk424 = (a1 != 0) ? 2 : 0;
    gUnknown_3001B64->unk428 = 0;
    gUnknown_3001B64->unk430 = a2;
    if (gUnknown_8116148[a3] & 0x100) {
        if (a4 < 0) {
            strcpy(gSpeakerNameBuffer, gFormattedSpeechBubble);
        }
        else {
            sprintfStatic(gSpeakerNameBuffer, gUnknown_8116188, gFormatBuffer_Names[a4]);
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

bool8 sub_809B1D4(s32 a0, u32 kind, s32 a2, s32 r3);

bool8 sub_809B1C0(s32 a0, u32 kind, s32 a2)
{
    return sub_809B1D4(a0, kind, 0, a2);
}

bool8 sub_809B1D4(s32 a0, u32 kind, s32 a2, s32 a3)
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
    gUnknown_3001B64->unk418 = 0;
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
            strcpy(gSpeakerNameBuffer, gFormattedSpeechBubble);
        }
        else {
            sprintfStatic(gSpeakerNameBuffer, gUnknown_8116188, gFormatBuffer_Names[a2]);
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
