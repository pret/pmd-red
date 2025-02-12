#include "global.h"
#include "text.h"
#include "memory.h"
#include "pokemon.h"
#include "string_format.h"
#include "structs/str_3001B64.h"
#include "constants/dungeon.h"

IWRAM_INIT struct unkStruct_3001B64 *gUnknown_3001B64 = {NULL};

extern u16 gUnknown_20399DC;
extern u16 gUnknown_20399DE;
extern u8 gInvalidityText[];
extern u8 gUndefineText[];

extern u8 ScriptPrintText_809B2B8(u32 *, u32, u32, u32);
extern u32 IsTextboxOpen_809B40C(u32 *);
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
        temp->unk8 = 0;
        temp->unkC = 0;
        temp->unk10 = 0;
        temp->faceData = 0;
        temp->unk1C = 0;
        temp->faceFile = NULL;
    }
}

static inline struct unkStruct_3001B64_sub *sub_809A83C_inline(s16 p, struct unkStruct_3001B64 **thing) {
    return &thing[0]->unk43C[p];
}

void sub_809A83C(s16 param_1)
{
    struct unkStruct_3001B64_sub *temp;

    temp = sub_809A83C_inline(param_1, &gUnknown_3001B64);

    temp->unk0 = -1;
    temp->speciesID = 0;
    temp->unk4 = 0;
    temp->unk5 = 0;
    temp->unk6 = -1;
    temp->unk7 = 0;
    temp->unk8 = 0;
    temp->unkC = 0;
    temp->unk10 = 0;
    temp->faceData = NULL;
    temp->unk1C = 0;
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

bool8 sub_809A8B8(short param_1,u16 param_2)
{
    bool8 ret;
    s16 local_26;
    int iVar5 = param_1;
    s16 local_28 = param_2;
    struct unkStruct_3001B64_sub *puVar8 = &gUnknown_3001B64->unk43C[iVar5];
    u8 uVar9 = 1;
    u8 byte1 = 0;

    if (puVar8->faceFile != NULL) {
        CloseFile(puVar8->faceFile);
        puVar8->faceFile = NULL;
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
            puVar8->unk0 = local_28;
            puVar8->speciesID = sub_80A8BFC(sVar3);
            strcpy(gFormatBuffer_Monsters[iVar5], gUndefineText);
            strcpy(gFormatBuffer_Names[iVar5], gUndefineText);
            puVar8->unk4 = uVar9;
            puVar8->unk5 = byte1;
            puVar8->unk6 = 0xff;
            puVar8->unk7 = 0;
            puVar8->unk8 = 0;
            puVar8->unkC = 0;
            puVar8->unk10 = 0;
            puVar8->faceData = NULL;
            puVar8->unk1C = 0;
            ret = TRUE;
        }
        else if (local_26 != 0) {
            puVar8->unk0 = local_28;
            puVar8->speciesID = local_26;
            strcpy(gFormatBuffer_Monsters[iVar5], gUndefineText);
            strcpy(gFormatBuffer_Names[iVar5], gUndefineText);
            puVar8->unk4 = uVar9;
            puVar8->unk5 = byte1;
            puVar8->unk6 = 0xff;
            puVar8->unk7 = 0;
            puVar8->unk8 = 0;
            puVar8->unkC = 0;
            puVar8->unk10 = 0;
            puVar8->faceData = NULL;
            puVar8->unk1C = 0;
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
