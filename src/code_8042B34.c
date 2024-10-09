#include "global.h"
#include "dungeon_util_1.h"
#include "memory.h"
#include "code_803E46C.h"
#include "code_800E9E4.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "random.h"
#include "dungeon.h"

extern void sub_800EE5C(s32);
extern void sub_800EF64(void);
extern void sub_800F15C(s32);

struct Sub_UnkStruct_203B414 // Maybe Position?
{
    s16 a0;
    s16 a2;
};

struct UnkStruct_203B414
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[16];
    s32 unk4C[16];
    struct Sub_UnkStruct_203B414 unk8C[16];
};

static EWRAM_DATA_2 struct UnkStruct_203B414 *sUnknown_203B414 = NULL;

struct UnkStruct_80F6624
{
    s16 unk0;
    s32 unk4;
};

extern const struct UnkStruct_80F6624 gUnknown_80F6624[][3];

extern const unkStruct_2039DB0 gUnknown_80F683C;

void sub_8042B34(s32 a0, s32 a1, s32 a2)
{
    unkStruct_80416E0 spStruct;
    s32 i;
    s32 r8 = 0;
    Entity *leader = xxx_call_GetLeader();
    sUnknown_203B414 = MemoryAlloc(sizeof(*sUnknown_203B414), 7);

    sUnknown_203B414->unk0 = a0;
    sUnknown_203B414->unk8 = (a1 + 1) * 4;
    sub_800EE5C(gUnknown_80F6624[a0][0].unk0);
    sub_800EF64();
    sub_803E46C(0x46);
    sUnknown_203B414->unk4 = a2;
    for (i = 0; i < sUnknown_203B414->unk8; i++) {
        s32 rnd;

        spStruct.unk0 = gUnknown_80F6624[sUnknown_203B414->unk0][r8].unk0;
        spStruct.unk4 = i;
        spStruct.unk8 = 0;
        spStruct.x = leader->pixelPos.x / 256;
        spStruct.y = leader->pixelPos.y / 256;

        rnd = RandInt(2);
        sUnknown_203B414->unk4C[i] = (gUnknown_80F6624[sUnknown_203B414->unk0][r8].unk4 * 2) + rnd;
        sUnknown_203B414->unk8C[i].a0 = RandInt(240) + 152;
        sUnknown_203B414->unk8C[i].a2 = RandInt(8 + (i * 2)) - (((i - (i / 4 * 4)) * 40) - 24);

        spStruct.unk10 = sUnknown_203B414->unk8C[i].a0;
        spStruct.unk12 = sUnknown_203B414->unk8C[i].a2;
        spStruct.unk14 = 4;
        spStruct.unk18 = 0xFFFF;
        spStruct.unk1C = gUnknown_80F683C;
        sUnknown_203B414->unkC[i] = sub_800E890(&spStruct);

        r8++;
        if (r8 >= 3 || gUnknown_80F6624[sUnknown_203B414->unk0][r8].unk0 == 0) {
            r8 = 0;
        }

        sub_800F15C(sub_800ECA4(spStruct.unk0)->unk4);
    }
}

bool8 sub_8042CC0(void)
{
    s32 i;
    bool8 ret = FALSE;

    if (sUnknown_203B414->unk4 != 0) {
        ret = TRUE;
        sUnknown_203B414->unk4--;
    }

    for (i = 0; i < sUnknown_203B414->unk8; i++) {
       sUnknown_203B414->unk8C[i].a0 -= sUnknown_203B414->unk4C[i];
       if (sUnknown_203B414->unk8C[i].a0 <= -152) {
            if (sUnknown_203B414->unk4 > 0) {
                sUnknown_203B414->unk8C[i].a0 = 152;
            }
            else {
                sUnknown_203B414->unk8C[i].a0 = -152;
            }
       }
       else {
            ret = TRUE;
       }
       sub_800E8AC(sUnknown_203B414->unkC[i], NULL, &sUnknown_203B414->unk8C[i], 0, NULL);
    }

    sub_800E90C(&gDungeon->unk181e8.cameraPixelPos);
    return ret;
}

void sub_8042D7C(void)
{
    s32 i;

    if (sUnknown_203B414 == NULL)
        return;

    for (i = 0; i < sUnknown_203B414->unk8; i++) {
        if (sub_800E9A8(sUnknown_203B414->unkC[i])) {
            sub_800DC14(sUnknown_203B414->unkC[i]);
        }
    }
    sub_800DBBC();
    MemoryFree(sUnknown_203B414);
    sUnknown_203B414 = NULL;
}

extern s32 sub_800E6D8(s32);

// TODO: Figure out if a new file should start here
void sub_8042DD4(s32 a0, Entity *a1, s32 a2)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 == -1) {
            strPtr->unk0 = a0;
            strPtr->unkC = a1;
            strPtr->unk4 = a2;
            strPtr->unk8 = sub_800E6D8(a0);
            return;
        }
    }
}

UNUSED bool32 sub_8042E1C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 != -1 && sub_800E9A8(strPtr->unk0)) {
            return TRUE;
        }
    }

    return FALSE;
}

void sub_8042E5C(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 >= 0 && !sub_800E9A8(strPtr->unk0)) {
            strPtr->unk0 = -1;
            strPtr->unkC = NULL;
        }
    }
}

void sub_8042E98(void)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        strPtr->unk0 = -1;
        strPtr->unk4 = 0;
        strPtr->unkC = NULL;
    }
}

extern void sub_800569C(Position *, EntitySpriteInfo *, u8);
extern void sub_800EB24(s32 param_1, Position *param_2, Position *param_3, s32 param_4, s32 param_5);

void sub_8042EC8(Entity *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < 3; i++) {
        struct unkStruct_Dungeon5C4_sub *strPtr = &gDungeon->unk5C4[i];
        if (strPtr->unk0 >= 0 && strPtr->unkC == a0) {
            Position sp8 = {a0->pixelPos.x / 256, a0->pixelPos.y / 256};
            Position sp4 = {0};
            EntityInfo *entInfo = GetEntInfo(a0);

            if (strPtr->unk8 != -1) {
                sub_800569C(&sp4, &a0->spriteInfo, strPtr->unk8);
            }

            sub_800EB24(strPtr->unk0, &sp8, &sp4,a1, entInfo->action.direction);
        }
    }
}
