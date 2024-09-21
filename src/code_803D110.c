#include "global.h"
#include "dungeon.h"
#include "pokemon.h"
#include "file_system.h"
#include "dungeon_random.h"

extern void sub_80901D8(DungeonLocation *param_1,DungeonLocation *param_2);
extern s32 sub_80902C8(u8 dungeon);
extern u16 ExtractSpeciesIndex(UnkDungeonGlobal_unk1CD98 *r0);
extern void sub_808E9C4(UnkDungeonGlobal_unk1CD98 *r0, s16 r1);

extern const char gUnknown_80F4D8C[]; // "mapparam"
extern struct FileArchive gDungeonFileArchive;

struct UnkDungeonFileData
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6[5];
};

struct UnkDataFileStruct
{
    struct UnkDungeonFileData **unk0;
    UnkDungeonGlobal_unk1C574 *unk4;
    u16 **unk8;
    UnkDungeonGlobal_unk1CD98 **unkC;
    u16 **unk10;
};

// TODO https://decomp.me/scratch/nXUH3
/*
void sub_803D4D0(void)
{
    u16 spArray[252];
    s32 i, j, k;
    OpenedFile *file;
    struct UnkDungeonFileData *strPtr;

    sub_80901D8(&gDungeon->dungeonLocation2, &gDungeon->dungeonLocation);
    if (gDungeon->unk1C570.id == gDungeon->dungeonLocation2.id && gDungeon->unk1C570.floor == gDungeon->dungeonLocation2.floor)
        return;

    gDungeon->unk1C570 = gDungeon->dungeonLocation2;
    file = OpenFileAndGetFileDataPtr(gUnknown_80F4D8C, &gDungeonFileArchive);

    strPtr = &file->data.dungData->unk0[gDungeon->unk1C570.id][gDungeon->unk1C570.floor];

    gDungeon->unk1CEC8 = GetDungeonFloorCount(gDungeon->dungeonLocation.id);
    gDungeon->unk14 = sub_80902C8(gDungeon->dungeonLocation.id);

    gDungeon->unk1C574 = file->data.dungData->unk4[strPtr->unk0];

    for (i = 0; i < 20; i++) {
        gDungeon->unk1CD70[i] = file->data.dungData->unk10[strPtr->unk4][i];
    }
    for (i = 0; i < 31; i++) {
        gDungeon->unk1CD98[i] = file->data.dungData->unkC[strPtr->unk2][i];
        if (ExtractSpeciesIndex(&gDungeon->unk1CD98[i]) == 0)
            break;
    }
    while (i <= 31) {
        sub_808E9C4(&gDungeon->unk1CD98[i], 0);
        i++;
    }

    for (i = 0; i < 4; i++)
    {
        u16 *src = file->data.dungData->unk8[strPtr->unk6[i]];

        for (j = 0; j < 252; src++) {
            if (*src > 29999) {
                for (k = *src - 30000; k != 0; k--) {
                    spArray[j++] = 0;
                }
            }
            else {
                spArray[j++] = *src;
            }
        }

        for (j = 0; j < 12; j++) {
            gDungeon->unk1C590[i].unk0[j] = spArray[j];
        }

        for (j = 0; j < 240; j++) {
            gDungeon->unk1C590[i].unk18[j] = spArray[12 + j];
        }
    }

    CloseFile(file);
}

*/
//

NAKED void sub_803D4D0(void)
{
    asm_unified("	.text\n"
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x1FC\n"
"	ldr r6, _0803D654\n"
"	ldr r1, [r6]\n"
"	movs r4, 0xC9\n"
"	lsls r4, 3\n"
"	adds r0, r1, r4\n"
"	ldr r2, _0803D658\n"
"	adds r1, r2\n"
"	bl sub_80901D8\n"
"	ldr r0, [r6]\n"
"	ldr r3, _0803D65C\n"
"	adds r2, r0, r3\n"
"	adds r1, r0, r4\n"
"	ldrh r0, [r2]\n"
"	ldrh r4, [r1]\n"
"	cmp r0, r4\n"
"	bne _0803D500\n"
"	b _0803D6E0\n"
"_0803D500:\n"
"	ldr r0, [r1]\n"
"	str r0, [r2]\n"
"	ldr r0, _0803D660\n"
"	ldr r1, _0803D664\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	mov r9, r0\n"
"	ldr r3, [r0, 0x4]\n"
"	ldr r2, [r6]\n"
"	ldr r7, _0803D65C\n"
"	adds r0, r2, r7\n"
"	ldrb r1, [r0]\n"
"	ldr r0, [r3]\n"
"	lsls r1, 2\n"
"	adds r1, r0\n"
"	ldr r3, _0803D668\n"
"	adds r0, r2, r3\n"
"	ldrb r0, [r0]\n"
"	lsls r0, 4\n"
"	ldr r1, [r1]\n"
"	adds r1, r0\n"
"	mov r8, r1\n"
"	ldr r4, _0803D658\n"
"	adds r2, r4\n"
"	ldrb r0, [r2]\n"
"	bl GetDungeonFloorCount\n"
"	ldr r1, [r6]\n"
"	ldr r7, _0803D66C\n"
"	adds r1, r7\n"
"	strb r0, [r1]\n"
"	ldr r0, [r6]\n"
"	adds r0, r4\n"
"	ldrb r0, [r0]\n"
"	bl sub_80902C8\n"
"	ldr r1, [r6]\n"
"	strh r0, [r1, 0x14]\n"
"	mov r2, r9\n"
"	ldr r0, [r2, 0x4]\n"
"	mov r3, r8\n"
"	movs r4, 0\n"
"	ldrsh r2, [r3, r4]\n"
"	ldr r3, [r0, 0x4]\n"
"	lsls r0, r2, 3\n"
"	subs r0, r2\n"
"	lsls r0, 2\n"
"	ldr r7, _0803D670\n"
"	adds r1, r7\n"
"	adds r0, r3\n"
"	ldm r0!, {r2-r4}\n"
"	stm r1!, {r2-r4}\n"
"	ldm r0!, {r2,r3,r7}\n"
"	stm r1!, {r2,r3,r7}\n"
"	ldr r0, [r0]\n"
"	str r0, [r1]\n"
"	movs r5, 0\n"
"	mov r10, r6\n"
"	ldr r4, _0803D674\n"
"_0803D576:\n"
"	mov r6, r10\n"
"	ldr r2, [r6]\n"
"	lsls r3, r5, 1\n"
"	adds r2, r4\n"
"	adds r2, r3\n"
"	mov r7, r9\n"
"	ldr r1, [r7, 0x4]\n"
"	mov r6, r8\n"
"	movs r7, 0x4\n"
"	ldrsh r0, [r6, r7]\n"
"	ldr r1, [r1, 0x10]\n"
"	lsls r0, 2\n"
"	adds r0, r1\n"
"	ldr r0, [r0]\n"
"	adds r3, r0\n"
"	ldrh r0, [r3]\n"
"	strh r0, [r2]\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x13\n"
"	ble _0803D576\n"
"	movs r5, 0\n"
"	adds r6, 0x6\n"
"	str r6, [sp, 0x1F8]\n"
"	ldr r6, _0803D678\n"
"	mov r10, r6\n"
"_0803D5A8:\n"
"	ldr r1, _0803D654\n"
"	ldr r0, [r1]\n"
"	lsls r3, r5, 3\n"
"	mov r2, r10\n"
"	adds r4, r0, r2\n"
"	adds r4, r3\n"
"	mov r12, r4\n"
"	mov r4, r9\n"
"	ldr r2, [r4, 0x4]\n"
"	mov r7, r8\n"
"	movs r4, 0x2\n"
"	ldrsh r1, [r7, r4]\n"
"	ldr r2, [r2, 0xC]\n"
"	lsls r1, 2\n"
"	adds r1, r2\n"
"	ldr r1, [r1]\n"
"	adds r3, r1\n"
"	ldr r1, [r3]\n"
"	ldr r2, [r3, 0x4]\n"
"	mov r7, r12\n"
"	str r1, [r7]\n"
"	str r2, [r7, 0x4]\n"
"	adds r0, r6\n"
"	bl ExtractSpeciesIndex\n"
"	lsls r0, 16\n"
"	cmp r0, 0\n"
"	beq _0803D5E8\n"
"	adds r6, 0x8\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x1E\n"
"	ble _0803D5A8\n"
"_0803D5E8:\n"
"	cmp r5, 0x1F\n"
"	bgt _0803D606\n"
"	ldr r6, _0803D654\n"
"	lsls r0, r5, 3\n"
"	ldr r1, _0803D678\n"
"	adds r4, r0, r1\n"
"_0803D5F4:\n"
"	ldr r0, [r6]\n"
"	adds r0, r4\n"
"	movs r1, 0\n"
"	bl sub_808E9C4\n"
"	adds r4, 0x8\n"
"	adds r5, 0x1\n"
"	cmp r5, 0x1F\n"
"	ble _0803D5F4\n"
"_0803D606:\n"
"	movs r5, 0\n"
"	ldr r2, _0803D67C\n"
"	mov r10, r2\n"
"_0803D60C:\n"
"	mov r3, r9\n"
"	ldr r1, [r3, 0x4]\n"
"	lsls r0, r5, 1\n"
"	ldr r4, [sp, 0x1F8]\n"
"	adds r0, r4, r0\n"
"	movs r6, 0\n"
"	ldrsh r0, [r0, r6]\n"
"	ldr r1, [r1, 0x8]\n"
"	lsls r0, 2\n"
"	adds r0, r1\n"
"	movs r4, 0\n"
"	adds r7, r5, 0x1\n"
"	mov r8, r7\n"
"	lsls r1, r5, 6\n"
"	mov r12, r1\n"
"	ldr r3, [r0]\n"
"	mov r2, sp\n"
"_0803D62E:\n"
"	ldrh r0, [r3]\n"
"	cmp r0, r10\n"
"	bls _0803D684\n"
"	ldrh r0, [r3]\n"
"	ldr r6, _0803D680\n"
"	adds r1, r0, r6\n"
"	cmp r1, 0\n"
"	beq _0803D68A\n"
"	movs r6, 0\n"
"	lsls r0, r4, 1\n"
"	add r0, sp\n"
"_0803D644:\n"
"	strh r6, [r0]\n"
"	adds r0, 0x2\n"
"	adds r2, 0x2\n"
"	adds r4, 0x1\n"
"	subs r1, 0x1\n"
"	cmp r1, 0\n"
"	bne _0803D644\n"
"	b _0803D68A\n"
"	.align 2, 0\n"
"_0803D654: .4byte gDungeon\n"
"_0803D658: .4byte 0x00000644\n"
"_0803D65C: .4byte 0x0001c570\n"
"_0803D660: .4byte gUnknown_80F4D8C\n"
"_0803D664: .4byte gDungeonFileArchive\n"
"_0803D668: .4byte 0x0001c571\n"
"_0803D66C: .4byte 0x0001cec8\n"
"_0803D670: .4byte 0x0001c574\n"
"_0803D674: .4byte 0x0001cd70\n"
"_0803D678: .4byte 0x0001cd98\n"
"_0803D67C: .4byte 0x0000752f\n"
"_0803D680: .4byte 0xffff8ad0\n"
"_0803D684:\n"
"	strh r0, [r2]\n"
"	adds r2, 0x2\n"
"	adds r4, 0x1\n"
"_0803D68A:\n"
"	adds r3, 0x2\n"
"	cmp r4, 0xFB\n"
"	ble _0803D62E\n"
"	ldr r7, _0803D6F0\n"
"	mov r1, r12\n"
"	subs r0, r1, r5\n"
"	movs r4, 0xB\n"
"	mov r3, sp\n"
"	lsls r2, r0, 3\n"
"	ldr r6, _0803D6F4\n"
"_0803D69E:\n"
"	ldr r0, [r7]\n"
"	adds r0, r6\n"
"	adds r0, r2\n"
"	ldrh r1, [r3]\n"
"	strh r1, [r0]\n"
"	adds r3, 0x2\n"
"	adds r2, 0x2\n"
"	subs r4, 0x1\n"
"	cmp r4, 0\n"
"	bge _0803D69E\n"
"	ldr r6, _0803D6F0\n"
"	mov r2, r12\n"
"	subs r0, r2, r5\n"
"	lsls r3, r0, 3\n"
"	add r2, sp, 0x18\n"
"	ldr r5, _0803D6F8\n"
"	movs r4, 0xEF\n"
"_0803D6C0:\n"
"	ldr r0, [r6]\n"
"	adds r0, r5\n"
"	adds r0, r3\n"
"	ldrh r1, [r2]\n"
"	strh r1, [r0]\n"
"	adds r2, 0x2\n"
"	adds r3, 0x2\n"
"	subs r4, 0x1\n"
"	cmp r4, 0\n"
"	bge _0803D6C0\n"
"	mov r5, r8\n"
"	cmp r5, 0x3\n"
"	ble _0803D60C\n"
"	mov r0, r9\n"
"	bl CloseFile\n"
"_0803D6E0:\n"
"	add sp, 0x1FC\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0803D6F0: .4byte gDungeon\n"
"_0803D6F4: .4byte 0x0001c590\n"
"_0803D6F8: .4byte 0x0001c5a8\n");
}

u8 sub_803D6FC(void)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);
    for (i = 0; i < 20; i++) {
        if (gDungeon->unk1CD70[i] != 0 && gDungeon->unk1CD70[i] >= rand)
            return i;
    }

    return 16;
}

u8 sub_803D73C(s32 a0)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);
    u8 category = NUM_ITEM_CATEGORIES;
    for (i = 0; i < NUM_ITEM_CATEGORIES; i++) {
        if (gDungeon->unk1C590[a0].unk0[i] != 0 && gDungeon->unk1C590[a0].unk0[i] >= rand) {
            category = i;
            break;
        }
    }
    if (category == NUM_ITEM_CATEGORIES)
        return 105;

    rand = DungeonRandInt(10000);
    for (i = 0; i < NUMBER_OF_ITEM_IDS; i++) {
        if (gDungeon->unk1C590[a0].unk18[i] != 0 && GetItemCategory(i) == category && gDungeon->unk1C590[a0].unk18[i] >= rand) {
            return i;
        }
    }

    return 105;
}

