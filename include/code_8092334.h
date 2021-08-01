#ifndef GUARD_CODE_8092334_H
#define GUARD_CODE_8092334_H


struct unkStruct_8094924
{
    // size: 0x10?
    u8 *unk0; // head?
    u8 *unk4; // tail?
    u32 unk8;
    u32 unkC;
};

void xxx_init_struct_8094924_save_809486C(struct unkStruct_8094924 *r0, u8 *r1, s32 size);
void nullsub_102(struct unkStruct_8094924 *r0);
void SaveIntegerBits(struct unkStruct_8094924 *r0, void *r1, s32 size);
void xxx_init_struct_8094924_restore_809485C(struct unkStruct_8094924 *r0, u8 *r1, s32 size);
void sub_80948E4(struct unkStruct_8094924 *r0, u8 *r1, s32 size);
void RestoreIntegerBits(struct unkStruct_8094924 *r0, void *r1, s32 size);

#endif