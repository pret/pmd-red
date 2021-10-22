#include "global.h"
#include "dungeon_entity.h"
#include "constants/status.h"

extern u32 gUnknown_80F89F4;
extern u8 gAvailablePokemonNames[0x58];
extern u32 gUnknown_80FB580;
extern s16 gUnknown_80F4FB6;
extern s16 gUnknown_80F4FB8;
extern s16 gUnknown_80F4FBA;
extern s16 gUnknown_80F4FBC;
extern s16 gUnknown_80F4FBE;

extern void sub_807D148(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2, u32 r3);
extern void sub_8075FCC(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_8077AE4(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2);
extern void sub_8072008(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2, u8 r3, u32);
extern void sub_8076D10(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void LevelDownTarget(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2);

extern void SetMessageArgument(u8 *r0, struct DungeonEntity *r1, u32);
extern void sub_807A290(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_80522F4(struct DungeonEntity *r0, struct DungeonEntity *r1, u32);
extern void RestoreVisionTarget(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void sub_8077910(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32);
extern void sub_80791D8(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void BlindTarget(struct DungeonEntity *r0, struct DungeonEntity *r1);
extern void HealTargetHP(struct DungeonEntity *r0, struct DungeonEntity *r1, s16, s16, u32);
extern void sub_80792F8(struct DungeonEntity *r0, struct DungeonEntity *r1, u32);
extern void sub_8079F20(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u8);
extern void sub_806F370(struct DungeonEntity *r0, struct DungeonEntity *r1, u32, u32, u32, u32, u32, u32, u32, u32);

void sub_8048340(struct DungeonEntity *r0, struct DungeonEntity *r1, u32 r2)
{
    sub_806F370(r0, r1, r2, 1, 0, 0, 528, 0, 0, 0);
}

void sub_8048364(struct DungeonEntity *r0, struct DungeonEntity *r1, u8 r2)
{
    sub_8079F20(r0, r1, 1, r2);
}

void sub_8048374(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    HealTargetHP(r0, r1, gUnknown_80F4FB6, gUnknown_80F4FB8, 1);
}

void sub_804839C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    HealTargetHP(r0, r1, gUnknown_80F4FBA, gUnknown_80F4FBC, 1);
}

void sub_80483C4(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_80792F8(r0, r1, 999);
}

void sub_80483D4(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    HealTargetHP(r0, r1, 0, gUnknown_80F4FBE, 1);
}

void sub_80483F4(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    BlindTarget(r0, r1);
}

void sub_8048400(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_80791D8(r0, r1);
}

void sub_804840C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8077910(r0, r1, 0, 1);
}

void sub_804841C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    RestoreVisionTarget(r0, r1);
}

void sub_8048428(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    if(r1->entityData->nonVolatileStatus == NON_VOLATILE_STATUS_PARALYZED)
        sub_807A290(r0, r1);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_8048450(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    if((u8)(r1->entityData->nonVolatileStatus - 2) <= 1)
        sub_807A290(r0, r1);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_8048480(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_807D148(r0, r1, 0, 0);
}

void sub_8048490(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8075FCC(r0, r1);
}

void sub_804849C(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8077AE4(r0, r1, 1);
}

void sub_80484A8(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8072008(r0, r1, 1, 1, 1);
}

void sub_80484BC(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    sub_8076D10(r0, r1);
}

void sub_80484C8(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_80484DC(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    LevelDownTarget(r0, r1, 1);
}

void sub_80484E8(struct DungeonEntity *r0, struct DungeonEntity *r1)
{
    if(r1->entityData->nonVolatileStatus == NON_VOLATILE_STATUS_BURNED)
        sub_807A290(r0, r1);
    else
    {
        SetMessageArgument(gAvailablePokemonNames, r1, 0);
        // Pointer to "But nothing happened!"
        sub_80522F4(r0, r1, gUnknown_80FB580);
    }
}
