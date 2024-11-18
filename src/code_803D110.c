#include "global.h"
#include "dungeon.h"
#include "pokemon.h"
#include "file_system.h"
#include "code_803E46C.h"
#include "code_8009804.h"
#include "cpu.h"
#include "dungeon_random.h"
#include "bg_palette_buffer.h"
#include "code_800D090.h"
#include "game_options.h"
#include "constants/dungeon.h"

extern void sub_80901D8(DungeonLocation *param_1,DungeonLocation *param_2);
extern s32 sub_80902C8(u8 dungeon);
extern s16 ExtractSpeciesIndex(UnkDungeonGlobal_unk1CD98 *r0);
extern u32 ExtractLevel(UnkDungeonGlobal_unk1CD98 *r0);
extern void sub_808E9C4(UnkDungeonGlobal_unk1CD98 *r0, s16 r1);
extern u8 GetBodySize(s16 index);
extern bool8 sub_80848EC(void);
extern u8 GetFloorType(void);
extern const u8 *GetDungeonName2(u8 dungeon);
extern void sub_8008DC8(s32 r0, s32 r1, u16 r2, u16 r3);

extern const char gUnknown_80F4D8C[]; // "mapparam"
extern const char gUnknown_80F60F8[]; // "banrpal"
extern const char gUnknown_80F6100[]; // "banfont"
extern const char gUnknown_80F6108[];
extern const char gUnknown_80F610C[];
extern const char gUnknown_80F6110[];
extern const char gUnknown_80F6118[];
extern const char gUnknown_80F61A8[];
extern const u32 gUnknown_80F6120[];

extern struct FileArchive gDungeonFileArchive;
extern OpenedFile *gDungeonNameBannerPalette;
extern OpenedFile *gDungeonNameBannerFontFile;
extern OpenedFile *gUnknown_202ECA0;
extern OpenedFile *gUnknown_202EC9C;
extern OpenedFile *gUnknown_202EC98;
extern OpenedFile *gUnknown_202EC94;
extern s32 gDungeonNameBannerFont;
extern u8 gUnknown_20274A5;
extern Palette32 gFontPalette[8];

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

// Very similar to unkChar struct
struct UnkStruct_sub_803DC6C
{
    u8 *unk0;
    u16 unk4;
    u8 unk6;
};

s32 sub_803DC14(const u8 *dungName, s32 strWidth, s32 a2);
s32 CalcStringWidth(const u8 *dungName);
s32 sub_803DC6C(u32 chr, s32 strWidth, s32 a2);
struct UnkStruct_sub_803DC6C *sub_803DEC8(s32 chr);
void sub_803DD30(u8 *a0, u32 *a1);

// TODO https://decomp.me/scratch/nXUH3
/*
void sub_803D4D0(void)
{
    u16 spArray[252];
    s32 i, j, k;
    OpenedFile *file;
    struct UnkDungeonFileData *strPtr;

    sub_80901D8(&gDungeon->unk644.dungeonLocation2, &gDungeon->unk644.dungeonLocation);
    if (gDungeon->unk1C570.id == gDungeon->unk644.dungeonLocation2.id && gDungeon->unk1C570.floor == gDungeon->unk644.dungeonLocation2.floor)
        return;

    gDungeon->unk1C570 = gDungeon->unk644.dungeonLocation2;
    file = OpenFileAndGetFileDataPtr(gUnknown_80F4D8C, &gDungeonFileArchive);

    strPtr = &file->data.dungData->unk0[gDungeon->unk1C570.id][gDungeon->unk1C570.floor];

    gDungeon->unk1CEC8 = GetDungeonFloorCount(gDungeon->unk644.dungeonLocation.id);
    gDungeon->unk14 = sub_80902C8(gDungeon->unk644.dungeonLocation.id);

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

s32 sub_803D808(UnkDungeonGlobal_unk1CD98 *strPtr, s32 id)
{
    s32 i;

    for (i = 0; i < 32; i++) {
        if (ExtractSpeciesIndex(&gDungeon->unk1CD98[i]) == 0)
            break;
        strPtr[id] = gDungeon->unk1CD98[i];
        id++;
    }

    return id;
}

s32 sub_803D870(UnkDungeonGlobal_unk1CD98 *strPtr, s32 id)
{
    s32 i;

    for (i = 0; i < 32; i++) {
        s16 species = ExtractSpeciesIndex(&gDungeon->unk1CD98[i]);
        if (species == 0)
            break;
        if (GetBodySize(species) < 2 && gDungeon->unk1CD98[i].unk2[0] != 0) {
            strPtr[id] = gDungeon->unk1CD98[i];
            id++;
        }
    }

    return id;
}

void sub_803D8F0(void)
{
    if (gDungeon->unk37EC == 0) {
        gDungeon->unk37EC = 1;
        gDungeon->unk37E4 = sub_803D808(gDungeon->unk343C, 0);
    }
}

bool8 sub_803D930(s16 speciesToFind)
{
    s32 i;
    s32 id = SpeciesId(speciesToFind);

    for (i = 0; i < 32; i++) {
        s16 species = ExtractSpeciesIndex(&gDungeon->unk1CD98[i]);
        if (species == 0)
            break;
        if (species == id)
            return TRUE;
    }
    return FALSE;
}

s16 sub_803D970(s32 arrId)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);

    for (i = 0; i < gDungeon->unk37E4; i++) {
        if (gDungeon->unk343C[i].unk2[arrId] != 0 && gDungeon->unk343C[i].unk2[arrId] >= rand) {
            return ExtractSpeciesIndex(&gDungeon->unk343C[i]);
        }
    }
    for (i = 0; i < gDungeon->unk37E4; i++) {
        if (gDungeon->unk343C[i].unk2[arrId] != 0) {
            return ExtractSpeciesIndex(&gDungeon->unk343C[i]);
        }
    }

    return MONSTER_KECLEON;
}

s32 sub_803DA20(s32 species)
{
    s32 i;
    s32 speciesId = SpeciesId(species);

    for (i = 0; i < gDungeon->unk37E4; i++) {
        if (ExtractSpeciesIndex(&gDungeon->unk343C[i]) == speciesId)
            return ExtractLevel(&gDungeon->unk343C[i]);
    }
    return 1;
}

struct DungeonNameFontFileData
{
    /* 0x0 */ u8 unk0;
    /* 0x4 */ s32 font;
};

struct DungeonNamePaletteFileData
{
    RGB pal[16];
};

void ShowDungeonNameBanner(void)
{
    u8 text[100];
    s32 var;
    s32 i, r7;
    const u8 *r6;

    gDungeonNameBannerPalette = OpenFileAndGetFileDataPtr(gUnknown_80F60F8, &gDungeonFileArchive);
    gDungeonNameBannerFontFile = OpenFileAndGetFileDataPtr(gUnknown_80F6100, &gDungeonFileArchive);
    gDungeonNameBannerFont =  ((struct DungeonNameFontFileData *)(gDungeonNameBannerFontFile->data))->font;
    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColorArray(i + 224, &((struct DungeonNamePaletteFileData *)(gDungeonNameBannerPalette->data))->pal[i]);
    }
    CpuClear((void *)(VRAM + 0x140), 0x1C00);
    if (sub_80848EC()) {
        s32 r8 = gDungeon->unk644.dungeonLocation.floor + gDungeon->unk14;
        const u8 *dungName = GetDungeonName2(gDungeon->unk644.dungeonLocation.id);
        s32 r5 = 10;

        for (r7 = 0; r7 < 8; r7++) {
            for (i = 0; i < 28; r5++) {
                u16 a2;

                i++;
                a2 = r5 | 0xE000;
                sub_8008DC8(i, r7 + 4, r5 | a2, 0);
            }
        }

        var = sub_803DC14(dungName, (224 - CalcStringWidth(dungName)) / 2, 0);
        if (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id))
            r6 = gUnknown_80F6108;
        else
            r6 = gUnknown_80F610C;

        if (r8 > 9) {
            sprintfStatic(text, gUnknown_80F6110, r6, 48 + (r8 / 10), 48 + (r8 % 10));
        }
        else {
            sprintfStatic(text, gUnknown_80F6118, r6, 48 + r8);
        }

        sub_803DC14(text, (224 - CalcStringWidth(text)) / 2, var + 32);
        gUnknown_20274A5 = 1;
    }

    CloseFile(gDungeonNameBannerFontFile);
    sub_803E46C(2);
}

s32 sub_803DC14(const u8 *dungName, s32 strWidth, s32 a2)
{
    while (*dungName != '\0') {
        u32 currChar = *(dungName++);
        if (currChar == '/') {
            strWidth = 0;
            a2 += 24;
        }
        else if (currChar == '#') {
            strWidth += 8;
        }
        else if (currChar == ' ') {
            strWidth += 12;
        }
        else {
            if (currChar & 0x80 && *dungName != '\0') {
                currChar = (currChar << 8) | *dungName;
                dungName++;
            }
            strWidth += sub_803DC6C(currChar, strWidth, a2);
        }
    }
    return a2;
}

s32 sub_803DC6C(u32 chr, s32 strWidth, s32 a2)
{
    u32 *spPtr;
    s32 i, j, a2DivMul;
    u32 *vramPtr;
    const u32 *constData;
    u32 sp[72];
    s32 r9;
    struct UnkStruct_sub_803DC6C *strPtr = sub_803DEC8(chr);

    sub_803DD30(strPtr->unk0, sp);
    r9 = strPtr->unk6;
    spPtr = sp;

    a2DivMul = ((a2 / 8) * 8);
    vramPtr = (void *)(VRAM + 0x140 + (((a2DivMul - a2 / 8) * 4) + (strWidth / 8)) * 32); // Pixels?
    vramPtr += a2 - a2DivMul;
    constData = &gUnknown_80F6120[(strWidth - ((strWidth / 8) * 8)) * 4];
    for (i = 0; i < 24; i++) {
        u32 *vramPtrLoop = vramPtr;
        for (j = 0; j < 3; j++) {
            // Sadly cannot match it without asm :/
            #ifdef NONMATCHING
            u32 spVal = *spPtr;
            #else
            register u32 spVal asm("r2") = *spPtr;
            #endif // NONMATCHING

            if (spVal != 0) {
                *vramPtrLoop |= ((constData[0] & spVal) << constData[2]);

                vramPtrLoop += 8;
                spVal &= constData[1];
                spVal >>= constData[3];
                *vramPtrLoop |= spVal;
                vramPtrLoop -= 8;
            }
            spPtr++;
            vramPtrLoop += 8;
        }

        vramPtr++;
        a2++;

        if (!(a2 & 7)) {
            vramPtr += 216;
        }
    }

    return r9;
}

void sub_803DD30(u8 *a0, u32 *a1)
{
    u8 sp[576];
    u8 sp575[576];
    s32 spId = 0;
    s32 i, j = 0, k;
    u32 currSp;
    s32 r6;

    for (i = 0; i < 576; i += 2) {
        sp[i] = (*a0 >> 4) & 0xF;
        sp[i+1] = *a0 & 0xF;
        a0++;
    }

    while (j < 576) {
        currSp = sp[spId++];
        r6 = currSp & 7;
        if (currSp & 8) {
            currSp = sp[spId++];
            for (k = 0; k < r6; k++) {
                sp575[j] = currSp;
                if (++j >= 576)
                    break;
            }
        }
        else {
            for (k = 0; k < r6; k++) {
                currSp = sp[spId++];
                sp575[j] = currSp;
                if (++j >= 576)
                    break;
            }
        }
        if (j >= 576)
            break;
    }

    for (i = 0; i < 576; i += 8) {
        u32 val = sp575[i + 7] << 0x1C;
        val |= (sp575[i + 6] << 0x18) & 0xF000000;
        val |= (sp575[i + 5] << 0x14) & 0xF00000;
        val |= (sp575[i + 4] << 0x10) & 0xF0000;
        val |= (sp575[i + 3] << 0xC) & 0xF000;
        val |= (sp575[i + 2] << 0x8) & 0xF00;
        val |= (sp575[i + 1] << 0x4) & 0xF0;
        val |= (sp575[i]) & 0xF;
        *(a1++) = val;
    }
}

// Could be a misnomer?
s32 CalcStringWidth(const u8 *dungName)
{
    s32 w = 0;

    while (*dungName != '\0') {
        u32 currChar = *(dungName++);
        if (currChar == '#') {
            w += 8;
        }
        else if (currChar == ' ') {
            w += 12;
        }
        else {
            struct UnkStruct_sub_803DC6C *strPtr;

            if (currChar & 0x80 && *dungName != '\0') {
                currChar = (currChar << 8) | *dungName;
                dungName++;
            }
            strPtr = sub_803DEC8(currChar);
            if (strPtr != NULL) {
                w += strPtr->unk6;
            }
        }
    }

    return w;
}

struct UnkStruct_sub_803DC6C *sub_803DEC8(s32 chr)
{
    s32 r2, r4;
    struct UnkStruct_sub_803DC6C *ret;
    struct UnkStruct_sub_803DC6C *strPtr = *((struct UnkStruct_sub_803DC6C **) gDungeonNameBannerFontFile->data);
    // Fakematch? Or just magic numbers which will make more sense once this file is documented?
    if (chr > 63487 && chr < 65535)
    {
        s32 r2 = chr & 0xFF;
        s32 r1 = (chr & 0xFF00) >> 8;
        r2 -= 32;
        r1 -= 248;
        ret = &strPtr[r1 * 224 + r2];
    }
    else
    {
        r4 = 0;
        r2 = gDungeonNameBannerFont - 1;
        while (r4 < r2) {
            s32 r1 = (r4 + r2) / 2;
            if (strPtr[r1].unk4 == chr) {
                r4 = r1;
                break;
            }
            else if (strPtr[r1].unk4 < chr) {
                r4 = r1 + 1;
            }
            else {
                r2 = r1;
            }
        }

        ret = &strPtr[r4];
        if (ret->unk4 != chr)
            ret = &strPtr[1];


    }
    return ret;
};

/*
I'm leaving this as it is, because I'm not sure how to generate the ldmia asm instruction. Maybe once the file's data format is better understood.
struct FileSub_803DF60Struct
{
    s32 count;
    void *unkPtr;
};

struct OpenedFile_sub_803DF60
{
    File *file;
    struct FileSub_803DF60Struct **strPtr;
};

void sub_803DF60(void)
{
    s32 i;
    struct OpenedFile_sub_803DF60 *file = (void*) OpenFileAndGetFileDataPtr(gUnknown_80F61A8, &gDungeonFileArchive);
    struct FileSub_803DF60Struct r5 = **file->strPtr;

    for (i = 0; i < r5.count; i++) {
        CpuCopy((void *)VRAM + 0x13400 + i * 0x20, r5.unkPtr + i * 0x20, 0x20);
    }

    CloseFile(file);
}

*/

NAKED void sub_803DF60(void)
{
    asm_unified("	push {r4-r7,lr}\n"
"	ldr r0, _0803DFF8\n"
"	ldr r1, _0803DFFC\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	adds r7, r0, 0\n"
"	ldr r0, [r7, 0x4]\n"
"	ldr r5, [r0]\n"
"	ldm r5!, {r4}\n"
"	ldr r6, _0803E000\n"
"	cmp r4, 0\n"
"	beq _0803DF8C\n"
"_0803DF78:\n"
"	adds r0, r6, 0\n"
"	adds r1, r5, 0\n"
"	movs r2, 0x20\n"
"	bl CpuCopy\n"
"	adds r6, 0x20\n"
"	adds r5, 0x20\n"
"	subs r4, 0x1\n"
"	cmp r4, 0\n"
"	bne _0803DF78\n"
"_0803DF8C:\n"
"	adds r0, r7, 0\n"
"	bl CloseFile\n"
"	ldr r0, _0803E004\n"
"	ldr r1, _0803DFFC\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	adds r7, r0, 0\n"
"	ldr r5, [r7, 0x4]\n"
"	ldm r5!, {r4}\n"
"	ldr r6, _0803E008\n"
"	cmp r4, 0\n"
"	beq _0803DFBA\n"
"_0803DFA6:\n"
"	adds r0, r6, 0\n"
"	adds r1, r5, 0\n"
"	movs r2, 0x20\n"
"	bl CpuCopy\n"
"	adds r6, 0x20\n"
"	adds r5, 0x20\n"
"	subs r4, 0x1\n"
"	cmp r4, 0\n"
"	bne _0803DFA6\n"
"_0803DFBA:\n"
"	adds r0, r7, 0\n"
"	bl CloseFile\n"
"	ldr r0, _0803E00C\n"
"	ldr r4, _0803DFFC\n"
"	adds r1, r4, 0\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	ldr r1, _0803E010\n"
"	str r0, [r1]\n"
"	ldr r0, _0803E014\n"
"	adds r1, r4, 0\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	ldr r1, _0803E018\n"
"	str r0, [r1]\n"
"	ldr r0, _0803E01C\n"
"	adds r1, r4, 0\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	ldr r1, _0803E020\n"
"	str r0, [r1]\n"
"	ldr r0, _0803E024\n"
"	adds r1, r4, 0\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	ldr r1, _0803E028\n"
"	str r0, [r1]\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0803DFF8: .4byte gUnknown_80F61A8\n"
"_0803DFFC: .4byte gDungeonFileArchive\n"
"_0803E000: .4byte 0x06013400\n"
"_0803E004: .4byte gUnknown_80F61B0\n"
"_0803E008: .4byte 0x06014000\n"
"_0803E00C: .4byte gUnknown_80F61B8\n"
"_0803E010: .4byte gUnknown_202EC94\n"
"_0803E014: .4byte gUnknown_80F61C4\n"
"_0803E018: .4byte gUnknown_202EC98\n"
"_0803E01C: .4byte gUnknown_80F61CC\n"
"_0803E020: .4byte gUnknown_202EC9C\n"
"_0803E024: .4byte gUnknown_80F61D4\n"
"_0803E028: .4byte gUnknown_202ECA0\n");
}

NAKED void sub_803E02C(void)
{
    asm_unified(	"push {r4-r7,lr}\n"
"	mov r7, r9\n"
"	mov r6, r8\n"
"	push {r6,r7}\n"
"	sub sp, 0xC\n"
"	bl sub_803E13C\n"
"	mov r1, sp\n"
"	ldr r0, _0803E118\n"
"	ldm r0!, {r2,r3}\n"
"	stm r1!, {r2,r3}\n"
"	ldr r1, _0803E11C\n"
"	mov r0, sp\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	adds r7, r0, 0\n"
"	ldr r0, [r7, 0x4]\n"
"	ldr r5, [r0]\n"
"	ldm r5!, {r4}\n"
"	ldr r6, _0803E120\n"
"	cmp r4, 0\n"
"	beq _0803E06C\n"
"_0803E058:\n"
"	adds r0, r6, 0\n"
"	adds r1, r5, 0\n"
"	movs r2, 0x20\n"
"	bl CpuCopy\n"
"	adds r6, 0x20\n"
"	adds r5, 0x20\n"
"	subs r4, 0x1\n"
"	cmp r4, 0\n"
"	bne _0803E058\n"
"_0803E06C:\n"
"	ldr r0, _0803E124\n"
"	ldr r1, [r7, 0x4]\n"
"	ldr r1, [r1, 0x4]\n"
"	movs r2, 0x80\n"
"	bl CpuCopy\n"
"	adds r0, r7, 0\n"
"	bl CloseFile\n"
"	movs r6, 0x80\n"
"	lsls r6, 2\n"
"	movs r4, 0\n"
"	ldr r0, _0803E128\n"
"	mov r9, r0\n"
"	ldr r1, _0803E12C\n"
"	mov r12, r1\n"
"	movs r7, 0\n"
"	ldr r2, _0803E130\n"
"	mov r8, r2\n"
"_0803E092:\n"
"	mov r3, r12\n"
"	ldrh r0, [r3]\n"
"	lsls r5, r0, 12\n"
"	adds r2, r7, 0\n"
"	movs r3, 0x8\n"
"_0803E09C:\n"
"	mov r0, r9\n"
"	ldr r1, [r0]\n"
"	add r1, r8\n"
"	adds r1, r2\n"
"	adds r0, r5, 0\n"
"	orrs r0, r6\n"
"	strh r0, [r1]\n"
"	adds r6, 0x1\n"
"	adds r2, 0x2\n"
"	subs r3, 0x1\n"
"	cmp r3, 0\n"
"	bge _0803E09C\n"
"	movs r1, 0x2\n"
"	add r12, r1\n"
"	adds r7, 0x12\n"
"	adds r4, 0x1\n"
"	cmp r4, 0x1C\n"
"	ble _0803E092\n"
"	movs r4, 0\n"
"	ldr r5, _0803E128\n"
"	ldr r3, _0803E134\n"
"	movs r2, 0xC0\n"
"	lsls r2, 8\n"
"_0803E0CA:\n"
"	ldr r0, [r5]\n"
"	lsls r1, r4, 1\n"
"	adds r0, r3\n"
"	adds r0, r1\n"
"	strh r2, [r0]\n"
"	adds r4, 0x1\n"
"	cmp r4, 0x8\n"
"	ble _0803E0CA\n"
"	movs r4, 0\n"
"	ldr r2, _0803E128\n"
"	movs r6, 0xBE\n"
"	lsls r6, 1\n"
"	ldr r5, _0803E138\n"
"	movs r3, 0xBF\n"
"	lsls r3, 1\n"
"_0803E0E8:\n"
"	ldr r0, [r2]\n"
"	lsls r1, r4, 2\n"
"	adds r0, r1\n"
"	adds r0, r6\n"
"	strb r4, [r0]\n"
"	ldr r0, [r2]\n"
"	adds r0, r1\n"
"	adds r0, r5\n"
"	strb r4, [r0]\n"
"	ldr r0, [r2]\n"
"	adds r0, r1\n"
"	adds r0, r3\n"
"	strb r4, [r0]\n"
"	adds r4, 0x1\n"
"	cmp r4, 0xFF\n"
"	ble _0803E0E8\n"
"	add sp, 0xC\n"
"	pop {r3,r4}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0803E118: .4byte gUnknown_80F61DC\n"
"_0803E11C: .4byte gDungeonFileArchive\n"
"_0803E120: .4byte 0x0600c000\n"
"_0803E124: .4byte gUnknown_202ECA4\n"
"_0803E128: .4byte gDungeon\n"
"_0803E12C: .4byte gUnknown_80F5F70\n"
"_0803E130: .4byte 0x00012a18\n"
"_0803E134: .4byte 0x00013554\n"
"_0803E138: .4byte 0x0000017d\n");
}

void sub_803E13C(void)
{
    s32 i;
    RGB *pal;

    SetWindowBGColor();
    if (gGameOptionsRef->playerGender != 0)
        pal = gFontPalette[4].pal;
    else
        pal = gFontPalette[0].pal;

    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColorArray(240 + i, pal);
        pal++;
    }
}

void sub_803E178(void)
{
    s32 val = GetFloorType();

    if (val == 0) {
        if (gDungeon->unk644.dungeonLocation.id == DUNGEON_METEOR_CAVE && !gDungeon->deoxysDefeat) {
            gDungeon->unk3A12 = 28;
        }
        else {
            gDungeon->unk3A12 = (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id) != FALSE) ? 23 : 22;
        }
    }
    else if (val == 1) {
        gDungeon->unk3A12 = 6;
    }
    else {
        gDungeon->unk3A12 = 24;
    }
}

void sub_803E214(void)
{
    CloseFile(gUnknown_202EC94);
    CloseFile(gUnknown_202EC98);
    CloseFile(gUnknown_202EC9C);
    CloseFile(gUnknown_202ECA0);
}

void nullsub_56(void) {}

// sub_803E250 left, but it seems to be sprite related, and I'd rather not deal with it now lol

