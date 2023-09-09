#ifndef GUARD_CODE_8092334_H
#define GUARD_CODE_8092334_H

// size: 0x10?
typedef struct unkStruct_8094924
{
    u8 *unk0; // head?
    u8 *unk4; // tail?
    u32 unk8;
    u32 unkC;
} unkStruct_8094924;

void nullsub_102(unkStruct_8094924 *);
void RestoreIntegerBits(unkStruct_8094924 *, void *, s32 size);
void SaveIntegerBits(unkStruct_8094924 *, void *, s32 size);
void xxx_init_struct_8094924_restore_809485C(unkStruct_8094924 *, u8 *, s32 size);
void xxx_init_struct_8094924_save_809486C(unkStruct_8094924 *, u8 *, s32 size);

void sub_80948E4(unkStruct_8094924 *, u8 *, s32 size);

#endif // GUARD_CODE_8092334_H