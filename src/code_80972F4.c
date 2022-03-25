#include "global.h"
#include "pokemon.h"
#include "wonder_mail.h"

extern void SaveDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void sub_80015C0(u32, u32);

struct unkStruct_8097270
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    struct DungeonLocation unk4;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
};

struct subStruct_203B490
{
    // size: 0xC
    struct DungeonLocation unk0;
    u32 unk4;
    u32 unk8;
};
 

struct unkStruct_203B490
{
    // size: 0x330?

    struct unkStruct_8097270 unk0[4];
    struct unkStruct_8097270 unk50[8];
    struct unkStruct_8097270 unkF0[8];
    u8 unk190[0x28];
    u8 unk1B8[0x78];
    struct subStruct_203B490 unk230[16];
    u8 unk2F0[0x38];
    u8 unk328;
};
extern struct unkStruct_203B490 *gUnknown_203B490;

void sub_8097270(struct unkStruct_8094924 *a, struct unkStruct_8097270 *b);
void sub_80971EC(struct unkStruct_8094924 *a, struct unkStruct_8097270 *b);
extern s32 sub_8096EB0(void);

bool8 sub_8096F50(struct WonderMail *r0)
{
    s32 index;
    s32 temp2;
    struct subStruct_203B490 *temp;

    temp2 = sub_8096EB0();


    for(index = 0; index < 0x10; index++)
    {
        temp  = &gUnknown_203B490->unk230[index];
        if(temp->unk0.dungeonIndex == r0->dungeon)
            if(temp->unk0.dungeonFloor == r0->floor)
                if(temp->unk4 == r0->unk8)
                    if(temp->unk8 == temp2)
                        return TRUE;
    }
    return FALSE;
}

u32 sub_8096FA0(u8 *r0, u32 size)
{
    s32 index;
    struct unkStruct_8094924 backup;
    u32 temp;

    xxx_init_struct_8094924_restore_809485C(&backup, r0, size);
    for(index = 0; index < 4; index++)
    {
        sub_80971EC(&backup, &gUnknown_203B490->unk0[index]);
    }
    for(index = 0; index < 8; index++)
    {
        sub_80971EC(&backup, &gUnknown_203B490->unk50[index]);
    }
    for(index = 0; index < 8; index++)
    {
        sub_80971EC(&backup, &gUnknown_203B490->unkF0[index]);
    }
    for(index = 0; index < 0x38; index++)
    {
        RestoreIntegerBits(&backup, &temp, 1);
        if(temp & 1)
            gUnknown_203B490->unk2F0[index] = 1;
        else
            gUnknown_203B490->unk2F0[index] = 0;
    }
    RestoreIntegerBits(&backup, &temp, 1);
    if(temp & 1)
        gUnknown_203B490->unk328 = 1;
    else
        gUnknown_203B490->unk328 = 0;
    
    RestoreIntegerBits(&backup, gUnknown_203B490->unk190, 0x140);
    RestoreIntegerBits(&backup, gUnknown_203B490->unk1B8, 0x3C0);
    for(index = 0; index < 0x10; index++)
    {
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk8, 0x20);
        RestoreIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk4, 0x18);
        RestoreDungeonLocation(&backup, &gUnknown_203B490->unk230[index].unk0);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

u32 sub_80970D8(u8 *r0, u32 size)
{
    s32 index;
    struct unkStruct_8094924 backup;
    u32 temp;

    xxx_init_struct_8094924_save_809486C(&backup, r0, size);
    for(index = 0; index < 4; index++)
    {
        sub_8097270(&backup, &gUnknown_203B490->unk0[index]);
    }
    for(index = 0; index < 8; index++)
    {
        sub_8097270(&backup, &gUnknown_203B490->unk50[index]);
    }
    for(index = 0; index < 8; index++)
    {
        sub_8097270(&backup, &gUnknown_203B490->unkF0[index]);
    }
    for(index = 0; index < 0x38; index++)
    {
        if(gUnknown_203B490->unk2F0[index] != 0)
            temp = -1;
        else
            temp = 0;
        SaveIntegerBits(&backup, &temp, 1);
    }
    if(gUnknown_203B490->unk328 != 0)
        temp = -1;
    else
        temp = 0;
    SaveIntegerBits(&backup, &temp, 1);
    SaveIntegerBits(&backup, gUnknown_203B490->unk190, 0x140);
    SaveIntegerBits(&backup, gUnknown_203B490->unk1B8, 0x3C0);
    for(index = 0; index < 0x10; index++)
    {
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk8, 0x20);
        SaveIntegerBits(&backup, &gUnknown_203B490->unk230[index].unk4, 0x18);
        SaveDungeonLocation(&backup, &gUnknown_203B490->unk230[index].unk0);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void sub_80971EC(struct unkStruct_8094924 *a, struct unkStruct_8097270 *b)
{
    RestoreIntegerBits(a, &b->unk0, 4);
    RestoreIntegerBits(a, &b->unk1, 3);
    RestoreIntegerBits(a, &b->unk2, 4);
    RestoreIntegerBits(a, &b->unkC, 9);
    RestoreIntegerBits(a, &b->unkE, 9);
    RestoreIntegerBits(a, &b->unk10, 8);
    RestoreIntegerBits(a, &b->unk11, 4);
    RestoreIntegerBits(a, &b->unk12, 8);
    RestoreIntegerBits(a, &b->unk13, 6);
    RestoreIntegerBits(a, &b->unk8, 0x18);
    RestoreDungeonLocation(a, &b->unk4);
}

void sub_8097270(struct unkStruct_8094924 *a, struct unkStruct_8097270 *b)
{
    SaveIntegerBits(a, &b->unk0, 4);
    SaveIntegerBits(a, &b->unk1, 3);
    SaveIntegerBits(a, &b->unk2, 4);
    SaveIntegerBits(a, &b->unkC, 9);
    SaveIntegerBits(a, &b->unkE, 9);
    SaveIntegerBits(a, &b->unk10, 8);
    SaveIntegerBits(a, &b->unk11, 4);
    SaveIntegerBits(a, &b->unk12, 8);
    SaveIntegerBits(a, &b->unk13, 6);
    SaveIntegerBits(a, &b->unk8, 0x18);
    SaveDungeonLocation(a, &b->unk4);
}

void sub_80972F4(void)
{
    sub_80015C0(0, 0x2B);
    sub_80015C0(0, 0x2C);
    sub_80015C0(0, 0x2D);
}

void nullsub_128(void)
{}
