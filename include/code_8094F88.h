#ifndef GUARD_CODE_8094F88_H
#define GUARD_CODE_8094F88_H

#include "code_8092334.h"
#include "dungeon_global_data.h"
#include "items.h"
#include "pokemon.h"

// size: 0x8
typedef struct WonderMailSub
{
    /* 0x0 */ DungeonLocation dungeon;
    /* 0x4 */ u32 seed;
} WonderMailSub;

// size: 0x30
typedef struct unkStruct_203B480
{
    /* 0x0 */ u8 mailType;
    /* 0x1 */ u8 missionType;
    WonderMailSub unk4;
    /* 0xC */ s16 clientSpecies;
    /* 0xE */ s16 targetSpecies;
    union unk10_temp
    {
        u32 unk10;
        u16 unk10_u16;
    } unk10;
    /* 0x14 */ u8 playerName[0x20 - 0x14];
    Item item;
    u32 unk24;
    u32 unk28;
    /* 0x2C */ s8 rescuesAllowed;
    u8 unk2D;
} unkStruct_203B480;

// size: 0x5C
typedef struct unkStruct_203B484
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ PokemonStruct1 unk4;
} unkStruct_203B484;

// size: 0x84
typedef struct unkStruct_203B48C
{
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4[0x20];
} unkStruct_203B48C;

extern unkStruct_203B480 *gUnknown_203B480;
extern unkStruct_203B484 *gUnknown_203B484;
extern u32 *gUnknown_203B488;
extern unkStruct_203B48C *gUnknown_203B48C;

void sub_80950BC(void);
unkStruct_203B480 *sub_80950F8(void);
unkStruct_203B484 *sub_8095100(void);
u32 *sub_8095108(void);
unkStruct_203B48C *sub_8095110(void);
void sub_8095118(void);
s32 FindOpenMailSlot(void);
bool8 sub_80951BC(unkStruct_203B480 *mail);
bool8 sub_80951FC(unkStruct_203B480 *);
unkStruct_203B480 * GetMailatIndex(u8);
void DeleteMailAtIndex(u8);
void sub_8095274(u32);
bool8 sub_8095298(s32);
void sub_80952C4(void);
bool8 HasMail(u8, u32);
s32 CountMailType(u8);
u32 CountAllMail(void);
s32 sub_8095374(void);
s32 GetMailIndex(u8, u32);
s32 GetFirstIndexofMailType(u8);
void sub_8095824(struct unkStruct_8094924 *, unkStruct_203B480 *);
void sub_8095774(struct unkStruct_8094924 *, unkStruct_203B480 *);

#endif // GUARD_CODE_8094F88_H