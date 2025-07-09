#ifndef GUARD_CODE_800E9E4_H
#define GUARD_CODE_800E9E4_H

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
    u8 fillA[0x0c - 0x0a];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} unkStruct_80BDBC4;

u8 sub_800EC74(void);
unkStruct_80B9CC4 *sub_800ECA4(s32);
unkStruct_80BDBC4 *sub_800ECB8(u16);
s16 sub_800ECE4(u8);
s16 sub_800ECF8(u8);
s16 sub_800ED0C(u8);

#endif
