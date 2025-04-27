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
