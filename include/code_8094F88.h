#ifndef GUARD_CODE_8094F88_H
#define GUARD_CODE_8094F88_H

#include "code_8092334.h"
#include "structs/str_dungeon.h"
#include "items.h"
#include "pokemon.h"
#include "structs/str_wonder_mail.h"

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
unkStruct_203B480 * GetMailatIndex(u8 index);
void DeleteMailAtIndex(u8 index);
void sub_8095274(u32);
bool8 sub_8095298(s32);
void sub_80952C4(void);
bool8 HasMail(u8 mailType, u32);
s32 CountMailType(u8 mailType);
u32 CountAllMail(void);
s32 sub_8095374(void);
s32 GetMailIndex(u8 mailType, u32);
s32 GetFirstIndexofMailType(u8 mailType);
void sub_8095824(DataSerializer *a, unkStruct_203B480 *b);
void sub_8095774(DataSerializer *a, unkStruct_203B480 *b);
void sub_809542C(WonderMailSub *param_1);

#endif // GUARD_CODE_8094F88_H