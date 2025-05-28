#include "global.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "game_options.h"
#include "code_800558C.h"
#include "code_80A26CC.h"
#include "def_filearchives.h"
#include "event_flag.h"
#include "file_system.h"
#include "text_1.h"
#include "text_2.h"

extern u8 gUnknown_20398B8;

extern const u8 gUnknown_811601C[];

extern void sub_8003600(void);
extern s32 sub_800388C(u16, const u8 *, u8);
extern void sub_8099690(u32);
extern void sub_80A4B38(void);
extern void sub_80A4B54(void);

bool8 sub_8099360(u8 *dungeonId) {
    s16 script_disc;
    DungeonInfo* dungeonInfo;

    script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 0x52) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        dungeonInfo = (DungeonInfo *)GetDungeonInfo_80A2608(script_disc);
            *dungeonId = dungeonInfo->dungeonIndex;
            return TRUE;
    }
    return FALSE;
}

bool8 sub_8099394(u8 *param) {
    s16 script_disc;

    script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER);
    if (script_disc == 0x50) {
        script_disc = GetScriptVarValue(NULL, DUNGEON_ENTER_INDEX);
        *param = script_disc;
        return TRUE;
    }
    return FALSE;
}

void sub_80993C0(bool8 param) {
    gUnknown_20398B8 = (param == FALSE);
}

void sub_80993D8(void) {
    sub_80A4B38();
}

void sub_80993E4(void) {
    sub_80A4B54();
}

/*
    TODO: this is a function that is never called
    and is very long. I didn't want to split up the
    file or spend time decomping so here it is in
    asm();
*/

NAKED
UNUSED static void sub_80993F0(void)
{
    asm_unified("	.text\n"
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x28\n"
"	movs r0, 0\n"
"	mov r10, r0\n"
"	bl sub_801180C\n"
"	movs r0, 0x10\n"
"	bl FadeOutAllMusic\n"
"	ldr r1, _0809948C\n"
"	ldr r2, _08099490\n"
"	adds r0, r2, 0\n"
"	strh r0, [r1]\n"
"	movs r0, 0\n"
"	bl UpdateFadeInTile\n"
"	movs r0, 0\n"
"	movs r1, 0x14\n"
"	bl sub_80095CC\n"
"	movs r0, 0\n"
"	movs r1, 0x1\n"
"	movs r2, 0x1\n"
"	bl ShowWindows\n"
"	movs r0, 0\n"
"	movs r1, 0x14\n"
"	bl sub_8009408\n"
"	bl sub_8099648\n"
"	bl sub_809975C\n"
"	bl sub_809D0AC\n"
"	bl sub_8014144\n"
"	movs r0, 0\n"
"	movs r1, 0\n"
"	bl sub_8005838\n"
"	bl AllocGroundMapAction\n"
"	mov r7, sp\n"
"	add r0, sp, 0x8\n"
"	mov r8, r0\n"
"_08099454:\n"
"	bl sub_801D9E4\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	beq _0809949C\n"
"	mov r0, r10\n"
"	bl sub_801DA58\n"
"_08099464:\n"
"	movs r0, 0\n"
"	movs r1, 0\n"
"	bl sub_8005838\n"
"	movs r0, 0\n"
"	bl sub_8012A18\n"
"	bl sub_801DA78\n"
"	cmp r0, 0x2\n"
"	beq _08099494\n"
"	cmp r0, 0x3\n"
"	bne _08099464\n"
"	bl sub_801DAC0\n"
"	lsls r0, 16\n"
"	asrs r0, 16\n"
"	mov r10, r0\n"
"	b _080994A2\n"
"	.align 2, 0\n"
"_0809948C: .4byte gUnknown_2026E4E\n"
"_08099490: .4byte 0x00000808\n"
"_08099494:\n"
"	movs r1, 0x1\n"
"	negs r1, r1\n"
"	mov r10, r1\n"
"	b _080994A2\n"
"_0809949C:\n"
"	movs r2, 0x1\n"
"	negs r2, r2\n"
"	mov r10, r2\n"
"_080994A2:\n"
"	bl sub_801DB0C\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	cmp r10, r0\n"
"	bne _080994B0\n"
"	b _08099624\n"
"_080994B0:\n"
"	movs r0, 0\n"
"	movs r1, 0x1\n"
"	movs r2, 0x1\n"
"	bl ShowWindows\n"
"	bl GroundMap_Reset\n"
"	bl sub_809D0BC\n"
"	mov r0, r10\n"
"	bl GroundMap_Select\n"
"	mov r0, sp\n"
"	mov r1, r8\n"
"	bl sub_80A579C\n"
"	ldr r0, [r7, 0x4]\n"
"	movs r1, 0xC0\n"
"	lsls r1, 4\n"
"	adds r0, r1\n"
"	str r0, [r7, 0x4]\n"
"	mov r2, r8\n"
"	ldr r0, [r2, 0x4]\n"
"	adds r0, r1\n"
"	str r0, [r2, 0x4]\n"
"	ldr r0, [sp]\n"
"	ldr r1, _08099520\n"
"	adds r0, r1\n"
"	str r0, [sp]\n"
"	ldr r0, [r7, 0x4]\n"
"	adds r0, r1\n"
"	str r0, [r7, 0x4]\n"
"	ldr r0, [sp, 0x8]\n"
"	movs r2, 0x80\n"
"	lsls r2, 3\n"
"	adds r0, r2\n"
"	str r0, [sp, 0x8]\n"
"	mov r0, r8\n"
"	ldr r1, [r0, 0x4]\n"
"	adds r1, r2\n"
"	str r1, [r0, 0x4]\n"
"	ldr r2, [sp, 0x8]\n"
"	ldr r0, [sp]\n"
"	subs r0, r2, r0\n"
"	str r0, [sp, 0x20]\n"
"	ldr r0, [r7, 0x4]\n"
"	subs r0, r1, r0\n"
"	str r0, [sp, 0x24]\n"
"	movs r4, 0\n"
"	movs r5, 0\n"
"	movs r0, 0x4\n"
"	bl sub_80999E8\n"
"	mov r9, r5\n"
"	b _08099604\n"
"	.align 2, 0\n"
"_08099520: .4byte 0xfffffc00\n"
"_08099524:\n"
"	ldr r0, _0809953C\n"
"	ldrh r1, [r0, 0x2]\n"
"	ldrh r6, [r0]\n"
"	movs r0, 0x4\n"
"	ands r1, r0\n"
"	cmp r1, 0\n"
"	beq _08099540\n"
"	bl sub_80999FC\n"
"	movs r1, 0x1\n"
"	mov r9, r1\n"
"	b _080995AE\n"
"	.align 2, 0\n"
"_0809953C: .4byte gRealInputs\n"
"_08099540:\n"
"	adds r0, r6, 0\n"
"	bl sub_809CFE8\n"
"	lsls r0, 24\n"
"	asrs r1, r0, 24\n"
"	movs r2, 0x1\n"
"	negs r2, r2\n"
"	cmp r1, r2\n"
"	beq _0809959A\n"
"	add r0, sp, 0x10\n"
"	movs r2, 0x80\n"
"	lsls r2, 1\n"
"	bl SetVecFromDirectionSpeed\n"
"	ldr r2, [sp, 0x10]\n"
"	ldr r3, [sp, 0x14]\n"
"	movs r0, 0x2\n"
"	ands r6, r0\n"
"	cmp r6, 0\n"
"	beq _0809956A\n"
"	movs r0, 0x4\n"
"_0809956A:\n"
"	adds r1, r0, 0\n"
"	muls r1, r2\n"
"	adds r1, r4\n"
"	adds r4, r1, 0\n"
"	muls r0, r3\n"
"	adds r5, r0\n"
"	cmp r1, 0\n"
"	bge _0809957E\n"
"	movs r4, 0\n"
"	b _08099588\n"
"_0809957E:\n"
"	ldr r0, [sp, 0x20]\n"
"	cmp r4, r0\n"
"	blt _08099588\n"
"	adds r4, r0, 0\n"
"	subs r4, 0x1\n"
"_08099588:\n"
"	cmp r5, 0\n"
"	bge _08099590\n"
"	movs r5, 0\n"
"	b _0809959A\n"
"_08099590:\n"
"	ldr r1, [sp, 0x24]\n"
"	cmp r5, r1\n"
"	blt _0809959A\n"
"	adds r5, r1, 0\n"
"	subs r5, 0x1\n"
"_0809959A:\n"
"	ldr r0, [sp]\n"
"	adds r0, r4\n"
"	str r0, [sp, 0x18]\n"
"	ldr r0, [r7, 0x4]\n"
"	adds r0, r5\n"
"	add r1, sp, 0x18\n"
"	str r0, [r1, 0x4]\n"
"	movs r0, 0\n"
"	bl sub_809D158\n"
"_080995AE:\n"
"	bl sub_809D25C\n"
"	bl sub_80A59DC\n"
"	bl DrawDialogueBoxString\n"
"	movs r0, 0\n"
"	movs r1, 0\n"
"	bl sub_8005838\n"
"	bl sub_80060EC\n"
"	ldr r0, _08099620\n"
"	ldr r0, [r0]\n"
"	ldrb r0, [r0, 0xA]\n"
"	bl nullsub_8\n"
"	bl sub_8005180\n"
"	bl sub_8099BE4\n"
"	bl sub_8099744\n"
"	bl sub_8011860\n"
"	bl WaitForNextFrameAndAdvanceRNG\n"
"	bl LoadBufferedInputs\n"
"	bl nullsub_120\n"
"	bl sub_80A5E70\n"
"	bl xxx_call_update_bg_vram\n"
"	bl CopySpritesToOam\n"
"	bl sub_8005304\n"
"	bl sub_8099750\n"
"	bl sub_8009908\n"
"_08099604:\n"
"	bl xxx_call_update_bg_sound_input\n"
"	movs r0, 0\n"
"	bl ResetSprites\n"
"	mov r2, r9\n"
"	cmp r2, 0\n"
"	beq _08099524\n"
"	bl sub_8099B94\n"
"	lsls r0, 24\n"
"	cmp r0, 0\n"
"	bne _080995AE\n"
"	b _08099454\n"
"	.align 2, 0\n"
"_08099620: .4byte gGameOptionsRef\n"
"_08099624:\n"
"	movs r0, 0x10\n"
"	bl FadeOutAllMusic\n"
"	bl FreeGroundMapAction\n"
"	bl sub_8099768\n"
"	bl nullsub_103\n"
"	add sp, 0x28\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n");
}

void sub_809965C(void);

void sub_8099648(void)
{
    sub_8003600();
    sub_809965C();
}

void nullsub_103(void)
{
}

void sub_809965C(void)
{
    OpenedFile *temp;
    sub_8099690(0);

    // gUnknown_811601C -> "fontsppa" string
    temp = OpenFileAndGetFileDataPtr(gUnknown_811601C, &gSystemFileArchive);

    sub_800388C(0x1f0, temp->data, 0x10);
    CloseFile(temp);
}

extern const u8 gUnknown_8116028[];

void sub_8099690(u32 param_1)
{
    OpenedFile *temp;
    RGB *pal;
    RGB *var2;
    u8 gender;

    s32 index;

    temp = OpenFileAndGetFileDataPtr(gUnknown_8116028, &gSystemFileArchive);

    switch(param_1)
    {
        default:
            gender = gGameOptionsRef->playerGender;
             pal = &gFontPalette[0x10];
            if(gender != 0)
                pal += 0x40;
            break;
        case 1:
            pal = &gFontPalette[0x60];
            break;
        case 2:
            pal = &gFontPalette[0x70];
            break;
    }

    sub_800388C(0xF0, (u8 *)pal, 0x10);
    var2 = pal;
    for(index = 0; index < 0x10; index++)
    {
        nullsub_5(index + 0xF0, var2++);
    }
    CloseFile(temp);
}

// TODO: figure out if a new file starts here...

typedef struct unkStruct_3000400
{
    // size: 0x4
    u8 unk0[0x4];
} unkStruct_3000400;

extern void sub_8003810(u16 idx, unkStruct_3000400 param_2);
extern void sub_80039B8(void);
extern void TransferBGPaletteBuffer(void);
extern void sub_80037C8(u16, u32, unkStruct_3000400);
extern void sub_8003664(u16 param_1, u16 param_2);
extern void sub_80036AC(u16, u32, unkStruct_3000400);
extern void sub_80036F4(u16, u32, unkStruct_3000400);
extern void sub_8003780(u16, u32, unkStruct_3000400);

void sub_809977C(void);

UNUSED static void sub_8099708(u16 a0, unkStruct_3000400 a1)
{
    sub_8003810(a0, a1);
}

void sub_809971C(u16 idx, unkStruct_3000400 *strPtrs, s32 n)
{
    s32 i;

    for (i = 0; i < n; i++) {
        sub_8003810(idx++, *strPtrs++);
    }
}

void sub_8099744(void)
{
    sub_80039B8();
}

void sub_8099750(void)
{
    TransferBGPaletteBuffer();
}

void sub_809975C(void)
{
    sub_809977C();
}

void sub_8099768(void)
{
    sub_809977C();
    sub_8099744();
    sub_8099750();
}

struct UnkStruct_2039958
{
    s32 unk0;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
};

struct UnkStruct_2039978
{
    u32 unk0;
    unkStruct_3000400 unk4;
    struct UnkStruct_2039958 unk8;
};

static EWRAM_DATA struct UnkStruct_2039958 gUnknown_2039958 = {0};
static EWRAM_DATA struct UnkStruct_2039958 gUnknown_2039968 = {0};
static EWRAM_DATA struct UnkStruct_2039978 gUnknown_2039978 = {0};
static EWRAM_DATA u8 gUnknown_2039990 = FALSE;
static EWRAM_DATA s16 gUnknown_2039992 = 0;
UNUSED static EWRAM_DATA s32 sUnused = 0;
#define ARR_COUNT_2039998 33
static EWRAM_DATA u16 gUnknown_2039998[ARR_COUNT_2039998] = {0};

void sub_8099838(struct UnkStruct_2039958 *a0);
void sub_8099848(struct UnkStruct_2039958 *a0);
void sub_8099DD0(u16 a0);
void sub_8099E58(u16 a0);
void sub_8099E80(u16 a0, unkStruct_3000400 a1);

void sub_809977C(void)
{
    s32 i;

    gUnknown_2039990 = FALSE;
    gUnknown_2039992 = 0;
    sub_8099838(&gUnknown_2039958);
    sub_8099838(&gUnknown_2039968);
    sub_8099838(&gUnknown_2039978.unk8);
    gUnknown_2039978.unk0 = 0;
    gUnknown_2039978.unk8.unkC = 0x100;
    gUnknown_2039958.unkC = 0;
    sub_8099DD0(0);
    gUnknown_2039968.unkC = 0x100;
    sub_8099E58(0x100);
    for (i = 0; i < ARR_COUNT_2039998; i++) {
        gUnknown_2039998[i] = 0;
    }
}

void sub_80997F4(u16 a0, u32 a1)
{
    gUnknown_2039998[a0] = a1;
    sub_8099848(&gUnknown_2039958);
    sub_8099848(&gUnknown_2039968);
    sub_8099848(&gUnknown_2039978.unk8);
}

UNUSED static u32 sub_8099828(u16 a0)
{
    return gUnknown_2039998[a0];
}

void sub_8099838(struct UnkStruct_2039958 *a0)
{
    a0->unk0 = 1;
    a0->unkC = 0;
    a0->unk4 = 0;
    a0->unk6 = 0;
}

void sub_8099848(struct UnkStruct_2039958 *a0)
{
    if (a0->unk0 == 0) {
        a0->unk0 = 1;
    }
}

void sub_809985C(struct UnkStruct_2039958 *a0, s32 a1)
{
    if (a1 >= 0) {
        if (a1 == 0) {
            a0->unkC = 0x100;
            a0->unk0 = 1;
        }
        else {
            a0->unk0 = 2;
        }
    }
    else {
        a1 = 30;
        a0->unk0 = 2;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
}

void sub_8099880(struct UnkStruct_2039958 *a0, s32 a1)
{
    if (a1 >= 0) {
        if (a1 == 0) {
            a0->unkC = a1;
            a0->unk0 = 1;
        }
        else {
            a0->unk0 = 3;
        }
    }
    else {
        a1 = 30;
        a0->unk0 = 3;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
}

void sub_80998A0(struct UnkStruct_2039958 *a0, s32 a1, u16 a2, u16 a3)
{
    if (a1 < 0) a1 = 30;

    if (a2 > a3) {
        a0->unk0 = 5;
        a0->unkA = a2 - a3;
    }
    else if (a2 < a3) {
        a0->unk0 = 4;
        a0->unkA = a3 - a2;
    }
    else {
        a0->unk0 = 1;
        a0->unkA = 0;
    }

    a0->unk4 = a1;
    a0->unk6 = a1;
    a0->unkC = a2;
    a0->unk8 = a3;
}

bool8 sub_80998E0(struct UnkStruct_2039958 *a0)
{
    switch (a0->unk0) {
        case 0:
            break;
        case 1:
            a0->unk0 = 0;
            return TRUE;
        case 2:
            if (--a0->unk4 > 0) {
                u16 var = 0x100 - ((a0->unk4 << 8) / a0->unk6);
                if (a0->unkC < var) {
                    a0->unkC = var;
                }
            }
            else {
                a0->unkC = 0x100;
                a0->unk0 = 0;
            }
            return TRUE;
        case 3:
            if (--a0->unk4 > 0) {
                u16 var = (a0->unk4 << 8) / a0->unk6;
                if (a0->unkC > var) {
                    a0->unkC = var;
                }
            }
            else {
                a0->unkC = 0;
                a0->unk0 = 0;
            }
            return TRUE;
        case 4:
            if (--a0->unk4 > 0) {
                a0->unkC = a0->unk8 - ((a0->unk4 * a0->unkA) / a0->unk6);
            }
            else {
                a0->unkC = a0->unk8;
                a0->unk0 = 0;
            }
            return TRUE;
        case 5:
            if (--a0->unk4 > 0) {
                a0->unkC = a0->unk8 + ((a0->unk4 * a0->unkA) / a0->unk6);
            }
            else {
                a0->unkC = a0->unk8;
                a0->unk0 = 0;
            }
            return TRUE;
    }

    return FALSE;
}

void sub_80999D4(s32 a0)
{
    gUnknown_2039990 = TRUE;
    gUnknown_2039992 = a0;
}

void sub_80999E8(s32 a0)
{
    sub_809985C(&gUnknown_2039958, a0);
}

void sub_80999FC(s32 a0)
{
    sub_8099880(&gUnknown_2039958, a0);
}

void sub_8099A10(s32 a1, u16 a2, u16 a3)
{
    sub_80998A0(&gUnknown_2039958, a1, a2, a3);
}

void sub_8099A34(s32 a0)
{
    sub_809985C(&gUnknown_2039968, a0);
}

void sub_8099A48(s32 a0)
{
    sub_8099880(&gUnknown_2039968, a0);
}

void sub_8099A5C(s32 a0, s32 a1, unkStruct_3000400 a2)
{
    gUnknown_2039978.unk0 = a0;
    gUnknown_2039978.unk4 = a2;
    gUnknown_2039978.unk8.unkC = 0;
    sub_809985C(&gUnknown_2039978.unk8, a1);

    switch (a0) {
        case 1:
        case 3:
            gUnknown_2039968.unkC = 0x100;
            gUnknown_2039958.unkC = 0x100;
            break;
        case 9:
        case 11:
            gUnknown_2039968.unkC = 0x100;
            break;
        case 5:
        case 7:
        case 13:
        case 14:
            gUnknown_2039958.unkC = 0x100;
            break;
    }
}

void sub_8099AFC(s32 a0, s32 a1, unkStruct_3000400 a2)
{
    gUnknown_2039978.unk0 = a0;
    gUnknown_2039978.unk4 = a2;
    gUnknown_2039978.unk8.unkC = 0x100;
    sub_8099880(&gUnknown_2039978.unk8, a1);

    switch (a0) {
        case 2:
        case 4:
            gUnknown_2039968.unkC = 0;
            gUnknown_2039958.unkC = 0;
            break;
        case 10:
        case 12:
            gUnknown_2039968.unkC = 0;
            break;
        case 6:
        case 8:
        case 13:
        case 14:
            gUnknown_2039958.unkC = 0;
            break;
    }
}

bool8 sub_8099B94(void)
{
    if (gUnknown_2039990)
        return TRUE;
    if (gUnknown_2039978.unk0 != 0) {
        return (gUnknown_2039978.unk8.unk0 != 0);
    }
    return (gUnknown_2039958.unk0 != 0 || gUnknown_2039968.unk0 != 0);
}

void sub_8099BE4(void)
{
    if (gUnknown_2039978.unk0 != 0 || gUnknown_2039978.unk8.unk0 != 0) {
        if (sub_80998E0(&gUnknown_2039978.unk8)) {
            sub_8099E80(gUnknown_2039978.unk8.unkC, gUnknown_2039978.unk4);
        }
        else if (gUnknown_2039978.unk8.unk0 == 0) {
            switch (gUnknown_2039978.unk0) {
                case 0:
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 9:
                case 11:
                    if (gUnknown_2039978.unk8.unkC >= 256) {
                        gUnknown_2039978.unk0 = 0;
                    }
                    else if (gUnknown_2039990) {
                        s32 var = 0;
                        switch (gUnknown_2039978.unk0) {
                            case 1: var = 2; break;
                            case 3: var = 4; break;
                            case 5: var = 6; break;
                            case 7: var = 8; break;
                        }

                        if (var != 0) {
                            sub_8099AFC(var, gUnknown_2039992, gUnknown_2039978.unk4);
                        }
                        else {
                            gUnknown_2039978.unk0 = 0;
                        }
                    }
                    break;
                case 2:
                case 4:
                case 6:
                case 8:
                case 10:
                case 12:
                case 13:
                case 14:
                    if (gUnknown_2039978.unk8.unkC == 0) {
                        gUnknown_2039978.unk0 = 0;
                    }
                    else if (gUnknown_2039990) {
                        sub_8099AFC(gUnknown_2039978.unk0, gUnknown_2039992, gUnknown_2039978.unk4);
                    }
                    break;
            }
        }
    }
    else if (gUnknown_2039990) {
        bool8 r5 = TRUE;
        if (gUnknown_2039958.unkC != 0 || gUnknown_2039958.unk0 != 0) {
            r5 = FALSE;
            if (gUnknown_2039958.unk0 != 3) {
                sub_8099880(&gUnknown_2039958, gUnknown_2039992);
            }
            if (sub_80998E0(&gUnknown_2039958)) {
                sub_8099DD0(gUnknown_2039958.unkC);
            }
        }
        if (gUnknown_2039968.unkC != 0 || gUnknown_2039968.unk0 != 0) {
            r5 = FALSE;
            if (gUnknown_2039968.unk0 != 3) {
                sub_8099880(&gUnknown_2039968, gUnknown_2039992);
            }
            if (sub_80998E0(&gUnknown_2039968)) {
                sub_8099E58(gUnknown_2039968.unkC);
            }
        }

        if (r5) {
            gUnknown_2039990 = FALSE;
        }
    }
    else {
        if (sub_80998E0(&gUnknown_2039958)) {
            sub_8099DD0(gUnknown_2039958.unkC);
        }
        if (sub_80998E0(&gUnknown_2039968)) {
            sub_8099E58(gUnknown_2039968.unkC);
        }
    }
}

void sub_8099DD0(u16 a0)
{
    s32 i;

    for (i = 0; i < 14; i++) {
        if (gUnknown_2039998[i] & 1) {
            sub_8003664(i, 0x100);
        }
        else {
            sub_8003664(i, a0);
        }
    }

    for (i = 16; i < 31; i++) {
        if (gUnknown_2039998[i] & 1) {
            sub_8003664(i, 0x100);
        }
        else {
            sub_8003664(i, a0);
        }
    }

    sub_8003664(32, a0);
}

void sub_8099E58(u16 a0)
{
    sub_8003664(15, a0);
    sub_8003664(14, a0);
    sub_8003664(31, a0);
}

void sub_8099E80(u16 param_1,unkStruct_3000400 param_2)
{
    s32 i;

    switch (gUnknown_2039978.unk0) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }
            break;
        case 9:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }
            break;
         case 5:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036AC(i,param_1,param_2);
                }
            }
            break;
        case 2:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }
            break;
        case 10:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }
            break;
        case 6:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_80036F4(i,param_1,param_2);
                }
            }
            break;
        case 3:
            for (i = 0; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }
            break;
        case 11:
            for (i = 14; i < 16; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }
            break;
        case 7:
            for (i = 0; i < 14; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i++) {
                if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,0x100);
                }
                else {
                    sub_8003780(i,param_1,param_2);
                }
            }
            break;
         case 4:
            for (i = 0; i < 16; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }

            for (i = 16; i < 32; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }
            break;
        case 12:
            for (i = 14; i < 16; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }

            for (i = 31; i < 32; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }
            break;
        case 13:
        case 14:
            switch (gUnknown_2039978.unk0) {
                case 13:
                    param_2.unk0[0] = 0x90;
                    param_2.unk0[1] = 0x90;
                    param_2.unk0[2] = 0xFF;
                    param_2.unk0[3] = 0xFF;
                    break;
                case 14:
                    param_2.unk0[0] = 0xFF;
                    param_2.unk0[1] = 0xC0;
                    param_2.unk0[2] = 0x80;
                    param_2.unk0[3] = 0xFF;
                    break;
            }
        // NOTE: fallthrough needed here
        case 8:
            for (i = 0; i < 14; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }

            for (i = 16; i < 31; i ++) {
                if (gUnknown_2039998[i] & 1) {
                    sub_8003664(i,0x100);
                }
                else if (gUnknown_2039998[i] & 2) {
                    sub_8003664(i,param_1);
                }
                else {
                    sub_80037C8(i,param_1,param_2);
                }
            }
            break;
    }
}
