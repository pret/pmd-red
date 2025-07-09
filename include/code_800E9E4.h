#ifndef GUARD_CODE_800E9E4_H
#define GUARD_CODE_800E9E4_H

#include "structs/code_800E9E4.h"

typedef struct unkStruct_80B9CC4
{
    // size: 0x24
    u32 animType;
    s32 effectId;
    s32 unk8;
    s32 animId;
    s32 unk10;
    s32 unk14;
    u8 unk18;
    // padding: 3 bytes
    s32 unk1c;
    s8 unk20;
    s8 loop;
    // padding: 2 bytes
} unkStruct_80B9CC4;

typedef struct unkStruct_80BDBC4
{
    // size: 0x24
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C; // Amount of gUnknown_80C183C entries to scan
    s32 unk20; // Index into gUnknown_80C183C
} unkStruct_80BDBC4;

const unkStruct_80B9CC4 *sub_800ECA4(s32 param_1);
const unkStruct_80BDBC4 *sub_800ECB8(u16 param_1);
const unkStruct_80C183C *sub_800ECD0(s32 param_1);
s16 sub_800ECE4(u8 param_1);
s16 sub_800ECF8(u8 param_1);
s16 sub_800ED0C(u8 param_1);
s32 sub_800ED20(u16 param_1);

#endif
