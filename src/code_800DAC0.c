#include "global.h"
#include "structs/axdata.h"
#include "bg_control.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "music_util.h"
#include "code_803E724.h"
#include "def_filearchives.h"
#include "dungeon_map.h"
#include "file_system.h"
#include "main_loops.h"
#include "memory.h"
#include "sprite.h"
#include "bg_palette_buffer.h"
#include "cpu.h"

EWRAM_INIT struct unkStruct_203B0CC *gUnknown_203B0CC = NULL;

struct unkStruct_800F18C
{
    s32 effectID;
    u32 counter;
};

extern s32 sub_800E2C0(u32);
extern u32 sub_800E900(void);
extern void sub_8009BE4(void);
extern void sub_800F204(OpenedFile *file);
extern struct unkStruct_800F18C *sub_800F18C(s32);
extern void sub_800DCA8(struct unkStruct_203B0CC_sub *);

extern u8 gefob000_string[];
extern u8 gefob001_string[];

extern void sub_800F034(void);
extern void sub_800ED38(u32);
extern void sub_800F078();
extern void sub_800ED64();
extern void sub_800ED80();
extern void sub_800F094();

void sub_800DAC0(u32 fileSelection)
{
    s32 i;
    OpenedFile *filePtr;
    struct unkStruct_203B0CC_sub *ptr;

    if (gUnknown_203B0CC != NULL) {
        sub_800DB7C();
    }
    gUnknown_203B0CC = MemoryAlloc(sizeof(struct unkStruct_203B0CC), 0xb);
    MemoryClear8(gUnknown_203B0CC, sizeof(struct unkStruct_203B0CC));
    gUnknown_203B0CC->fileSelection = fileSelection;
    for (i = 0, ptr = &gUnknown_203B0CC->unk0[i]; i < 0x20; i++, ptr++) {
        ptr->unk4 = -1;
    }
    sub_800ED38(fileSelection);
    sub_800F034();

    switch (gUnknown_203B0CC->fileSelection) {
        case 1:
            filePtr = Call_OpenFileAndGetFileDataPtr(gefob001_string, &gEffectFileArchive);
            if (filePtr != NULL) {
                sub_8005610(filePtr,0x248,0x1f,0);
                CloseFile(filePtr);
            }
            break;
        case 0:
            filePtr = Call_OpenFileAndGetFileDataPtr(gefob000_string, &gEffectFileArchive);
            if (filePtr != NULL) {
                sub_8005610(filePtr,0x248,0x1f,0);
                CloseFile(filePtr);
            }
            break;
    }
}

void sub_800DB7C(void)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;

    for (i = 0, ptr = &gUnknown_203B0CC->unk0[i]; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        if (ptr->unk4 != -1)
            sub_800DC14(ptr->unk4);
    }

    sub_800F078();
    sub_800ED64();
    TRY_FREE_AND_SET_NULL(gUnknown_203B0CC);
}

void sub_800DBBC(void)
{
    s32 i1, i2;
    struct unkStruct_203B0CC_sub *ptr1, *ptr2;

    for (i1 = 0, ptr1 = &gUnknown_203B0CC->unk0[i1]; i1 < UNK_203B0CC_ARR_COUNT; i1++, ptr1++) {
        if (ptr1->unk4 != -1) {
            sub_800DC14(ptr1->unk4);
        }
    }

    for (i2 = 0, ptr2 = &gUnknown_203B0CC->unk0[i2]; i2 < UNK_203B0CC_ARR_COUNT; i2++, ptr2++) {
        ptr2->unk4 = -1;
    }

    sub_800ED80();
    sub_800F094();
}

bool8 sub_800DCC0(void)
{
    return gUnknown_203B0CC != NULL;
}

void sub_800DC14(s32 param_1)
{
    s32 index1 = sub_800E2C0(param_1);
    if (index1 != -1) {
        struct unkStruct_203B0CC_sub *ptr = &gUnknown_203B0CC->unk0[index1];
        if (ptr->unk34 == 4) {
            sub_8009BE4();
            if (sub_8000728() == 1) {
                LoadDungeonMapPalette();
                sub_803EAF0(0, NULL);
                sub_800CD64(0x8000,0);
            }
        }
        if (ptr->unk34 == 3) {
            s32 i;
            for (i = 0; i < 2; i = i + 1) {
                struct unkStruct_800F18C *piVar3 = sub_800F18C(i);
                if (piVar3->effectID == ptr->effectID) {
                    piVar3->counter--;
                    break;
                }
            }
        }
        else {
            struct unkStruct_800F18C *puVar4 = sub_800F18C(1);
            puVar4->counter  = 0;
            puVar4->effectID  = -1;
        }
        sub_800DCA8(ptr);
    }
}

u32 sub_800DC9C(void)
{
    return sub_800E900();
}

void sub_800DCA8(struct unkStruct_203B0CC_sub *param_1)
{
    param_1->unk4 = -1;
    param_1->unk54 = 0;
    if (param_1->unkB8 != NULL) {
        sub_800F204(param_1->unkB8);
        param_1->unkB8 = NULL;
    }
}

void sub_800DCD0(struct unkStruct_203B0CC_sub *param_1)
{
    if (param_1->unk4C != -1 && param_1->unk50 == 0) {
        if (sub_8000728() != 2) {
            PlaySound(param_1->unk4C);
        }
        param_1->unk4C = -1;
        param_1->unk50 = -1;
    }
    if (param_1->unk50 > 0) {
        param_1->unk50--;
    }
}

#ifdef NONMATCHING
bool8 sub_800DD0C(struct unkStruct_203B0CC_sub *param_1, DungeonPos *posArg)
{
    struct axObject *axObj = &param_1->unk58;

    if (!AxFlag8000_Not2000(&axObj->axdata)) {
        sub_800DCA8(param_1);
        if (param_1->unk34 == 3) {
            s32 i;
            for (i = 0; i < 2; i++) {
                struct unkStruct_800F18C *puVar4 = sub_800F18C(i);
                if (puVar4->effectID == param_1->effectID) {
                    puVar4->counter--;
                    break;
                }
            }
        }
        return FALSE;
    }
    else {
        DungeonPos pos;
        s32 unkYAdd;

        RunAxAnimationFrame(&axObj->axdata);
        unkYAdd = 0;
        if ((param_1->unk8 % 8) == 0) {
            switch (param_1->unk14) {
                case 3:
                case 4:
                case 5:
                    unkYAdd -= 3;
                    break;
                default:
                    unkYAdd += 3;
                    break;
            }
        }
        else {
            unkYAdd += 3;
        }
        pos = (DungeonPos) {0, 0};
        if (param_1->unk20 != -1) {
            pos.x = param_1->unk1c.x;
            pos.y = param_1->unk1c.y;
        }

        if (pos.x != 99 && pos.y != 99) {
            s32 x, y;
            s32 unkY = param_1->unk24;
            if (unkY == 0xffff) {
                unkY = (param_1->unk18.y - posArg->y) / 2 + unkYAdd;
            }
            x = param_1->unk18.x - posArg->x + pos.x;
            y = param_1->unk18.y - posArg->y + pos.y;
            param_1->unk18.x += param_1->unkCC[0];
            param_1->unk18.y += param_1->unkCC[1];
            if (x > -64 && x < 304 && y > -64 && y < 224) {
                DoAxFrame_800558C(&axObj->axdata,x,y,unkY,param_1->paletteNum,&param_1->spriteMasks);
            }
        }
        return TRUE;
    }
}
#else
NAKED bool8 sub_800DD0C(struct unkStruct_203B0CC_sub *param_1, DungeonPos *posArg)
{
    asm_unified("   push {r4-r7,lr}\n"
"	mov r7, r8\n"
"	push {r7}\n"
"	sub sp, 0x8\n"
"	adds r5, r0, 0\n"
"	adds r6, r1, 0\n"
"	movs r0, 0x58\n"
"	adds r0, r5\n"
"	mov r8, r0\n"
"	ldrh r1, [r0]\n"
"	movs r0, 0x80\n"
"	lsls r0, 6\n"
"	ands r0, r1\n"
"	cmp r0, 0\n"
"	beq _0800DD2E\n"
"	movs r0, 0\n"
"	b _0800DD30\n"
"_0800DD2E:\n"
"	lsrs r0, r1, 15\n"
"_0800DD30:\n"
"	cmp r0, 0\n"
"	bne _0800DD64\n"
"	adds r0, r5, 0\n"
"	bl sub_800DCA8\n"
"	ldr r0, [r5, 0x34]\n"
"	cmp r0, 0x3\n"
"	bne _0800DD60\n"
"	movs r4, 0\n"
"	b _0800DD46\n"
"_0800DD44:\n"
"	adds r4, 0x1\n"
"_0800DD46:\n"
"	cmp r4, 0x1\n"
"	bgt _0800DD60\n"
"	adds r0, r4, 0\n"
"	bl sub_800F18C\n"
"	adds r2, r0, 0\n"
"	ldr r1, [r2]\n"
"	ldr r0, [r5, 0x38]\n"
"	cmp r1, r0\n"
"	bne _0800DD44\n"
"	ldr r0, [r2, 0x4]\n"
"	subs r0, 0x1\n"
"	str r0, [r2, 0x4]\n"
"_0800DD60:\n"
"	movs r0, 0\n"
"	b _0800DE28\n"
"_0800DD64:\n"
"	mov r0, r8\n"
"	bl RunAxAnimationFrame\n"
"	movs r4, 0\n"
"	ldr r0, [r5, 0x8]\n"
"	movs r1, 0x7\n"
"	ands r0, r1\n"
"	cmp r0, 0\n"
"	bne _0800DD88\n"
"	ldr r0, [r5, 0x14]\n"
"	cmp r0, 0x5\n"
"	bgt _0800DD84\n"
"	cmp r0, 0x3\n"
"	blt _0800DD84\n"
"	subs r4, 0x3\n"
"	b _0800DD8A\n"
"_0800DD84:\n"
"	adds r4, 0x3\n"
"	b _0800DD8A\n"
"_0800DD88:\n"
"	movs r4, 0x3\n"
"_0800DD8A:\n"
"	movs r2, 0\n"
"	ldr r1, [r5, 0x20]\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	cmp r1, r0\n"
"	beq _0800DD9E\n"
"	ldrh r0, [r5, 0x1E]\n"
"	lsls r0, 16\n"
"	ldrh r2, [r5, 0x1C]\n"
"	orrs r2, r0\n"
"_0800DD9E:\n"
"	lsls r0, r2, 16\n"
"	asrs r1, r0, 16\n"
"	adds r7, r0, 0\n"
"	cmp r1, 0x63\n"
"	beq _0800DE26\n"
"	asrs r0, r2, 16\n"
"	adds r2, r0, 0\n"
"	cmp r2, 0x63\n"
"	beq _0800DE26\n"
"	ldr r3, [r5, 0x24]\n"
"	ldr r0, _0800DE34\n"
"	cmp r3, r0\n"
"	bne _0800DDCA\n"
"	movs r1, 0x1A\n"
"	ldrsh r0, [r5, r1]\n"
"	movs r3, 0x2\n"
"	ldrsh r1, [r6, r3]\n"
"	subs r0, r1\n"
"	lsrs r1, r0, 31\n"
"	adds r0, r1\n"
"	asrs r0, 1\n"
"	adds r3, r0, r4\n"
"_0800DDCA:\n"
"	movs r4, 0x18\n"
"	ldrsh r0, [r5, r4]\n"
"	movs r4, 0\n"
"	ldrsh r1, [r6, r4]\n"
"	subs r0, r1\n"
"	asrs r1, r7, 16\n"
"	adds r4, r0, r1\n"
"	movs r7, 0x1A\n"
"	ldrsh r0, [r5, r7]\n"
"	movs r7, 0x2\n"
"	ldrsh r1, [r6, r7]\n"
"	subs r0, r1\n"
"	adds r2, r0, r2\n"
"	adds r0, r5, 0\n"
"	adds r0, 0xCC\n"
"	ldrh r0, [r0]\n"
"	ldrh r1, [r5, 0x18]\n"
"	adds r0, r1\n"
"	strh r0, [r5, 0x18]\n"
"	adds r0, r5, 0\n"
"	adds r0, 0xCE\n"
"	ldrh r0, [r0]\n"
"	ldrh r7, [r5, 0x1A]\n"
"	adds r0, r7\n"
"	strh r0, [r5, 0x1A]\n"
"	adds r1, r4, 0\n"
"	adds r1, 0x3F\n"
"	movs r0, 0xB7\n"
"	lsls r0, 1\n"
"	cmp r1, r0\n"
"	bhi _0800DE26\n"
"	movs r0, 0x40\n"
"	negs r0, r0\n"
"	cmp r2, r0\n"
"	ble _0800DE26\n"
"	cmp r2, 0xDF\n"
"	bgt _0800DE26\n"
"	ldr r0, [r5, 0x3C]\n"
"	str r0, [sp]\n"
"	adds r0, r5, 0\n"
"	adds r0, 0x28\n"
"	str r0, [sp, 0x4]\n"
"	mov r0, r8\n"
"	adds r1, r4, 0\n"
"	bl DoAxFrame_800558C\n"
"_0800DE26:\n"
"	movs r0, 0x1\n"
"_0800DE28:\n"
"	add sp, 0x8\n"
"	pop {r3}\n"
"	mov r8, r3\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1\n"
"	.align 2, 0\n"
"_0800DE34: .4byte 0x0000ffff");
}
#endif // NONMATCHING

bool8 sub_800DE38(struct unkStruct_203B0CC_sub *a1)
{
    s32 i;

    if (!AxFlag8000_Not2000(&a1->unk58)) {
        sub_800DCA8(a1);
        if (a1->unk34 == 3) {
            for (i = 0; i < 2; i++) {
                struct unkStruct_800F18C *strPtr = sub_800F18C(i);
                if (strPtr->effectID == a1->effectID) {
                    strPtr->counter--;
                    break;
                }
            }
        }
        return FALSE;
    }

    return TRUE;
}

extern s16 gUnknown_2026E4E;
extern bool8 sub_8009A7C(void *a0, s32 a1, s32 a2, s32 a3, bool8 a4, s32 *a5, s16 *a6);
extern void sub_809971C(u16 a0, const RGB *a1, int a2);

static inline const EfoFileData *GetFileEfo(struct unkStruct_203B0CC_sub *a0)
{
    return a0->unkB8->data;
}

bool8 sub_800DE8C(struct unkStruct_203B0CC_sub *a0, DungeonPos *unused)
{
    s16 sp[4];
    struct unkStruct_203B0CC_x94 *r8 = &a0->unk94;

    if (r8->unk18 == 0) {
        if (sub_8009A7C(r8, r8->unk14, 0, 0, TRUE, &r8->unk18, sp)) {
            if (sp[0] != 0) {
                r8->unk20 = 1;
                gUnknown_203B0CC->unk1A08 = 0;
                gUnknown_203B0CC->unk1A0C = 0;
            }
            if (sp[1] != 0) {
                if (sp[1] == 99) {
                    gUnknown_203B0CC->unk1A08 = 3100;
                    gUnknown_203B0CC->unk1A0C = 0;
                }
                else if (sp[1] > 0) {
                    gUnknown_203B0CC->unk1A08 = gUnknown_203B0CC->unk1A0C = 3100 / sp[1];
                }
                else {
                    gUnknown_203B0CC->unk1A08 = 3100;
                    gUnknown_203B0CC->unk1A0C = 3100 / sp[1];
                }
            }

            if (r8->unk20 != 0) {
                switch (gUnknown_203B0CC->fileSelection) {
                    case 1:
                        sub_809971C(224, &GetFileEfo(a0)->unk10->pal[224],16);
                        break;
                    case 0: {
                        s32 i;
                        s32 brightness = gUnknown_203B0CC->unk1A08 / 100;

                        for (i = 0; i < 16; i++) {
                            SetBGPaletteBufferColorRGB(i + 224, &GetFileEfo(a0)->unk10->pal[i + 224], brightness, NULL);
                        }
                        break;
                    }
                }

                gUnknown_2026E4E = 2570;
                gUnknown_203B0CC->unk1A08 += gUnknown_203B0CC->unk1A0C;
                if (gUnknown_203B0CC->unk1A08 < 0) {
                    gUnknown_203B0CC->unk1A08 = 0;
                }
                else if (gUnknown_203B0CC->unk1A08 > 3100) {
                    gUnknown_203B0CC->unk1A08 = 3100;
                }
            }
        }
        else {
            struct unkStruct_800F18C *strPtr;

            sub_8009BE4();
            sub_800DCA8(a0);
            if (sub_8000728() == 1) {
                LoadDungeonMapPalette();
                sub_803EAF0(0, 0);
                sub_800CD64(0x8000, FALSE);
            }
            sub_800CDA8(gUnknown_203B0CC->unk1A10);
            gUnknown_2026E4E = gUnknown_203B0CC->unk1A14;
            strPtr = sub_800F18C(1);
            strPtr->counter = 0;
            strPtr->effectID = -1;
            return FALSE;
        }

        r8->unk14++;
    }

    r8->unk18--;
    return TRUE;
}

//
