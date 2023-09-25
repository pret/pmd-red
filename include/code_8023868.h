#ifndef GUARD_CODE_8023868_H
#define GUARD_CODE_8023868_H

struct unkStruct_3001B60
{
    u32 unk0;
    u32 sortMethod;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u8 fill14[0x18 - 0x14];
    s16 unk18;
    s16 unk1A[2];
    u8 fill1C[0x370 - 0x1E];
    s16 unk370;
    s16 unk372;
    s16 unk374;
    s16 unk376;
};

// code_8023868.s
extern void sub_8023868(u32, u32, u32, u32);
extern u32 sub_8023A94(bool8);
extern s16 sub_8023B44(void);
extern void sub_8023B7C(u32);
extern void sub_8023C60(void);
extern void sub_8023DA4(void);
extern bool8 sub_8024108(u32);

#endif // GUARD_CODE_8023868_H