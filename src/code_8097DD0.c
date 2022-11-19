#include "global.h"
#include "code_8092334.h"
#include "pokemon.h"
#include "exclusive_pokemon.h"

struct unkStruct_203B494
{
    // size: 0xC8?
    u32 unk0; // 32 bit bitfield, I think
    s32 numAdventures;
    s32 unk8;
    s32 unkC;
    struct DungeonLocation dungeonLocation;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    u32 unk1C[0xE];
    u32 unk54[0xE];
    u32 unk8C[0xD];
    s32 unkC0;
};

extern struct unkStruct_203B494 *gUnknown_203B494;

extern void SaveDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
extern void RestoreDungeonLocation(struct unkStruct_8094924*, struct DungeonLocation*);
void ReadGameOptions(struct unkStruct_8094924 *param_1);
void ReadPlayTime(struct unkStruct_8094924 *r0);
void WriteGameOptions(struct unkStruct_8094924 *param_1);
void WritePlayTime(struct unkStruct_8094924 *r0);

extern void sub_8097944(void);

void sub_8097C18(struct unkStruct_8094924 *r0)
{
    sub_8097944();
    SaveIntegerBits(r0, &gUnknown_203B494->numAdventures, 0x11);
    SaveIntegerBits(r0, &gUnknown_203B494->unk8, 0x11);
    SaveIntegerBits(r0, &gUnknown_203B494->unkC, 0x11);
    SaveIntegerBits(r0, &gUnknown_203B494->unk0, 0x20);
    SaveIntegerBits(r0, &gUnknown_203B494->unk14, 0xE);
    SaveIntegerBits(r0, &gUnknown_203B494->unk16, 0xE);
    SaveIntegerBits(r0, &gUnknown_203B494->unk18, 0x9);
    SaveIntegerBits(r0, &gUnknown_203B494->unkC0, 0x11);
    SaveIntegerBits(r0, gUnknown_203B494->unk1C, 0xE0 << 1);
    SaveIntegerBits(r0, gUnknown_203B494->unk54, 0xE0 << 1);
    SaveIntegerBits(r0, gUnknown_203B494->unk8C, 0xD0 << 1);
    SaveDungeonLocation(r0, &gUnknown_203B494->dungeonLocation);
}

void sub_8097CC0(struct unkStruct_8094924 *r0)
{
    RestoreIntegerBits(r0, &gUnknown_203B494->numAdventures, 0x11);
    RestoreIntegerBits(r0, &gUnknown_203B494->unk8, 0x11);
    RestoreIntegerBits(r0, &gUnknown_203B494->unkC, 0x11);
    RestoreIntegerBits(r0, &gUnknown_203B494->unk0, 0x20);
    RestoreIntegerBits(r0, &gUnknown_203B494->unk14, 0xE);
    RestoreIntegerBits(r0, &gUnknown_203B494->unk16, 0xE);
    RestoreIntegerBits(r0, &gUnknown_203B494->unk18, 0x9);
    RestoreIntegerBits(r0, &gUnknown_203B494->unkC0, 0x11);
    RestoreIntegerBits(r0, gUnknown_203B494->unk1C, 0xE0 << 1);
    RestoreIntegerBits(r0, gUnknown_203B494->unk54, 0xE0 << 1);
    RestoreIntegerBits(r0, gUnknown_203B494->unk8C, 0xD0 << 1);
    RestoreDungeonLocation(r0, &gUnknown_203B494->dungeonLocation);
}

u32 sub_8097D60(u8 *r0, u32 size)
{
    struct unkStruct_8094924 backup;
    xxx_init_struct_8094924_save_809486C(&backup, r0, size);
    WriteGameOptions(&backup);
    WritePlayTime(&backup);
    sub_8097C18(&backup);
    WriteExclusivePokemon(&backup);
    nullsub_102(&backup);
    return backup.unk8;
}

u32 sub_8097D98(u8 *r0, u32 size)
{
    struct unkStruct_8094924 backup;
    xxx_init_struct_8094924_restore_809485C(&backup, r0, size);
    ReadGameOptions(&backup);
    ReadPlayTime(&backup);
    sub_8097CC0(&backup);
    ReadExclusivePokemon(&backup);
    nullsub_102(&backup);
    return backup.unk8;
}

bool8 sub_8097DD0(s32 *param_1, s32 *param_2)
{
  if ((param_1[0] == param_2[0]) && (param_1[1] == param_2[1])) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}
