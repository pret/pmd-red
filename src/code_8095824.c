#include "global.h"
#include "pokemon.h"
#include "code_8094F88.h"

extern struct unkStruct_203B484 *gUnknown_203B484;
extern struct unkStruct_203B480 *gUnknown_203B480;
extern struct unkStruct_203B48C *gUnknown_203B48C;

extern void SaveDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void xxx_save_poke_sub_c_808F41C(struct unkStruct_8094924* a1, struct unkPokeSubStruct_C* unkC);
extern void xxx_restore_poke_sub_c_808F410(struct unkStruct_8094924*, struct unkPokeSubStruct_C*);
extern void SavePokemonMoves(struct unkStruct_8094924 *r0, struct PokemonMove *moveSet);
extern void RestorePokemonMoves(struct unkStruct_8094924 *r0, struct PokemonMove *moveSet);

void sub_8095824(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b);
void sub_8095774(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b);
extern u32 sub_8095324(u32);

u32 sub_80954B4(void)
{
    if(sub_8095324(3) != 0)
        return 1;
    else
        return 0;
}

u32 sub_80954CC(u8 *a, u32 b)
{
    struct unkStruct_8094924 backup;
    struct PokemonStruct *temp;
    s32 index;

    xxx_init_struct_8094924_restore_809485C(&backup, a, b);
    for(index = 0; index < 0x20; index++)
    {
        sub_8095774(&backup, &gUnknown_203B480[index]);
    }
    RestoreIntegerBits(&backup, &gUnknown_203B484->unk0, 0x20);
    temp  = &gUnknown_203B484->unk4;
    memset(temp, 0, sizeof(struct PokemonStruct));
    RestoreIntegerBits(&backup, &temp->unk0, 2);
    RestoreIntegerBits(&backup, &temp->isLeader, 1);
    RestoreIntegerBits(&backup, &temp->unkHasNextStage, 7);
    RestoreDungeonLocation(&backup, &temp->dungeonLocation);
    RestoreIntegerBits(&backup, &temp->speciesNum, 9);
    xxx_restore_poke_sub_c_808F410(&backup, &temp->unkC[0]);
    xxx_restore_poke_sub_c_808F410(&backup, &temp->unkC[1]);
    RestoreIntegerBits(&backup, &temp->IQ, 0xA);
    RestoreIntegerBits(&backup, &temp->pokeHP, 0xA);
    RestoreIntegerBits(&backup, &temp->offense.att[0], 8);
    RestoreIntegerBits(&backup, &temp->offense.att[1], 8);
    RestoreIntegerBits(&backup, &temp->offense.def[0], 8);
    RestoreIntegerBits(&backup, &temp->offense.def[1], 8);
    RestoreIntegerBits(&backup, &temp->unk1C, 0x18);
    RestoreIntegerBits(&backup, &temp->IQSkills, 0x18);
    RestoreIntegerBits(&backup, &temp->unk24, 4);
    RestoreHeldItem(&backup, &temp->heldItem);
    RestorePokemonMoves(&backup, temp->moves);
    RestoreIntegerBits(&backup, temp->name, 0x50);

    RestoreIntegerBits(&backup, &gUnknown_203B48C->unk0, 0x20);
    for(index = 0; index < 0x20; index++)
    {
        RestoreIntegerBits(&backup, &gUnknown_203B48C->unk4[index], 0x20);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

u32 sub_8095624(u8 *a, u32 b)
{
    struct unkStruct_8094924 backup;
    struct PokemonStruct *temp;
    s32 index;

    xxx_init_struct_8094924_save_809486C(&backup, a, b);
    for(index = 0; index < 0x20; index++)
    {
        sub_8095824(&backup, &gUnknown_203B480[index]);
    }
    SaveIntegerBits(&backup, &gUnknown_203B484->unk0, 0x20);
    temp  = &gUnknown_203B484->unk4;
    SaveIntegerBits(&backup, &temp->unk0, 2);
    SaveIntegerBits(&backup, &temp->isLeader, 1);
    SaveIntegerBits(&backup, &temp->unkHasNextStage, 7);
    SaveDungeonLocation(&backup, &temp->dungeonLocation);
    SaveIntegerBits(&backup, &temp->speciesNum, 9);
    xxx_save_poke_sub_c_808F41C(&backup, &temp->unkC[0]);
    xxx_save_poke_sub_c_808F41C(&backup, &temp->unkC[1]);
    SaveIntegerBits(&backup, &temp->IQ, 0xA);
    SaveIntegerBits(&backup, &temp->pokeHP, 0xA);
    SaveIntegerBits(&backup, &temp->offense.att[0], 8);
    SaveIntegerBits(&backup, &temp->offense.att[1], 8);
    SaveIntegerBits(&backup, &temp->offense.def[0], 8);
    SaveIntegerBits(&backup, &temp->offense.def[1], 8);
    SaveIntegerBits(&backup, &temp->unk1C, 0x18);
    SaveIntegerBits(&backup, &temp->IQSkills, 0x18);
    SaveIntegerBits(&backup, &temp->unk24, 4);
    SaveHeldItem(&backup, &temp->heldItem);
    SavePokemonMoves(&backup, temp->moves);
    SaveIntegerBits(&backup, temp->name, 0x50);

    SaveIntegerBits(&backup, &gUnknown_203B48C->unk0, 0x20);
    for(index = 0; index < 0x20; index++)
    {
        SaveIntegerBits(&backup, &gUnknown_203B48C->unk4[index], 0x20);
    }
    nullsub_102(&backup);
    return backup.unk8;
}

void sub_8095774(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b)
{
    u8 temp;

    RestoreIntegerBits(a, &b->mailType, 4);
    RestoreDungeonLocation(a, &b->unk4);
    RestoreIntegerBits(a, &b->unk8, 0x18);
    RestoreIntegerBits(a, &b->unkC, 0x9);
    RestoreIntegerBits(a, &b->unk10, 0x20);
    RestoreIntegerBits(a, &b->unk14, 0x50);
    RestoreIntegerBits(a, &b->unk20, 0x8);
    RestoreIntegerBits(a, &b->unk21, 0x8);
    RestoreIntegerBits(a, &b->unk22, 0x8);
    RestoreIntegerBits(a, &b->unk24, 0x20);
    RestoreIntegerBits(a, &b->unk28, 0x20);
    RestoreIntegerBits(a, &b->unk2C, 0x8);

    RestoreIntegerBits(a, &temp, 1);
    b->unk2D = temp & 1;
}

void sub_8095824(struct unkStruct_8094924 * a, struct unkStruct_203B480 *b)
{
    u8 neg1;
    u8 zero;
    u8 *puVar2;
    neg1 = -1;
    zero = 0;

    SaveIntegerBits(a, &b->mailType, 4);
    SaveDungeonLocation(a, &b->unk4);
    SaveIntegerBits(a, &b->unk8, 0x18);
    SaveIntegerBits(a, &b->unkC, 0x9);
    SaveIntegerBits(a, &b->unk10, 0x20);
    SaveIntegerBits(a, &b->unk14, 0x50);
    SaveIntegerBits(a, &b->unk20, 0x8);
    SaveIntegerBits(a, &b->unk21, 0x8);
    SaveIntegerBits(a, &b->unk22, 0x8);
    SaveIntegerBits(a, &b->unk24, 0x20);
    SaveIntegerBits(a, &b->unk28, 0x20);
    SaveIntegerBits(a, &b->unk2C, 0x8);

    if(b->unk2D != 0)
        puVar2 = &neg1;
    else
        puVar2 = &zero;
    SaveIntegerBits(a, puVar2, 1);
}

void sub_80958E4(u32 *a, u32 b)
{
    *a = b;
}
