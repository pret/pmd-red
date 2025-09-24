#include "global.h"
#include "globaldata.h"
#include "effect_main.h"
#include "effect_sub_1.h"
#include "effect_sub_2.h"
#include "structs/axdata.h"
#include "bg_control.h"
#include "music_util.h"
#include "dungeon_vram.h"
#include "def_filearchives.h"
#include "dungeon_map.h"
#include "file_system.h"
#include "main_loops.h"
#include "memory.h"
#include "sprite.h"
#include "bg_palette_buffer.h"
#include "cpu.h"
#include "effect_data.h"
#include "graphics_memory.h"
#include "effect_anim_file.h"

struct unkStruct_203B0CC_x94
{
    struct EfbFileData sub;
    s32 unk14;
    s32 unk18;
    s32 fill1C;
    u8 unk20;
};

struct unkStruct_203B0CC_sub
{
    // size: 0xD0
    u32 unk0;
    s32 unk4;
    s32 unk8;
    unkStruct_80416E0 unkC;
    u32 unk34;
    u32 effectID;
    s32 paletteNum;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u32 unk4C;
    s32 unk50;
    u8 unk54;
    u8 unk55;
    axdata unk58;
    struct unkStruct_203B0CC_x94 unk94;
    OpenedFile *unkB8;
    DungeonPos unkBC;
    DungeonPos unkC0;
    s16 unkC4;
    DungeonPos unkC8;
    DungeonPos unkCC;
};

#define UNK_203B0CC_ARR_COUNT 32

struct unkStruct_203B0CC
{
    // size: 0x1A18
    struct unkStruct_203B0CC_sub unk0[UNK_203B0CC_ARR_COUNT];
    s32 unk1A00;
    /* 0x1A04 */ u32 fileSelection;
    s32 unk1A08;
    s32 unk1A0C;
    s32 unk1A10;
    u16 unk1A14;
};

static EWRAM_INIT struct unkStruct_203B0CC *gUnknown_203B0CC = NULL;

struct unkStruct_800F18C
{
    s32 effectID;
    u32 counter;
};

extern s16 gUnknown_2026E4E;


extern void sub_8009BE4(void);
extern void sub_809971C(u16 a0, const RGB *a1, int a2);

static s32 sub_800E900(s32 a0);
static s32 sub_800E2C0(s32);
static s32 sub_800E2B8(OpenedFile *a0);
static s32 sub_800E2F0(void);
static s32 sub_800E750(s32 a0, s32 a1);
static s32 sub_800EBBC(s32 param_1);
static s32 sub_800EC68(s32 param_1);
static void sub_800DCA8(struct unkStruct_203B0CC_sub *);

static const unkStruct_2039DB0 sDefaultSpriteMasks = DEFAULT_UNK_2039DB0_MASKS;

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
    for (i = 0, ptr = &gUnknown_203B0CC->unk0[i]; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        ptr->unk4 = -1;
    }
    sub_800ED38(fileSelection);
    sub_800F034();

    switch (gUnknown_203B0CC->fileSelection) {
        case 1:
            filePtr = Call_OpenFileAndGetFileDataPtr("efob001", &gEffectFileArchive);
            if (filePtr != NULL) {
                sub_8005610(filePtr,0x248,0x1f,0);
                CloseFile(filePtr);
            }
            break;
        case 0:
            filePtr = Call_OpenFileAndGetFileDataPtr("efob000", &gEffectFileArchive);
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

UNUSED static bool8 sub_800DC00(void)
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

s32 sub_800DC9C(s32 a0)
{
    return sub_800E900(a0);
}

static void sub_800DCA8(struct unkStruct_203B0CC_sub *param_1)
{
    param_1->unk4 = -1;
    param_1->unk54 = 0;
    if (param_1->unkB8 != NULL) {
        CloseEffectFile(param_1->unkB8);
        param_1->unkB8 = NULL;
    }
}

static void sub_800DCD0(struct unkStruct_203B0CC_sub *param_1)
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
// https://decomp.me/scratch/OBo48
static bool8 sub_800DD0C(struct unkStruct_203B0CC_sub *param_1, DungeonPos *posArg)
{
    struct axdata *axData = &param_1->unk58;

    if (!AxFlag8000_Not2000(axData)) {
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

        RunAxAnimationFrame(axData);
        unkYAdd = 0;
        if ((param_1->unk8 % 8) == 0) {
            switch (param_1->unkC.dir) {
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
        if (param_1->unkC.unk14 != -1) {
            pos.x = param_1->unkC.pos2.x;
            pos.y = param_1->unkC.pos2.y;
        }

        if (pos.x != 99 && pos.y != 99) {
            s32 x, y;
            s32 unkY = param_1->unkC.unk18;
            if (unkY == 0xffff) {
                unkY = (param_1->unkC.pos1.y - posArg->y) / 2 + unkYAdd;
            }
            x = param_1->unkC.pos1.x - posArg->x + pos.x;
            y = param_1->unkC.pos1.y - posArg->y + pos.y;
            param_1->unkC.pos1.x += param_1->unkCC.x;
            param_1->unkC.pos1.y += param_1->unkCC.y;
            if (x > -64 && x < 304 && y > -64 && y < 224) {
                DoAxFrame_800558C(axData,x,y,unkY,param_1->paletteNum,&param_1->unkC.spriteMasks);
            }
        }
        return TRUE;
    }
}
#else
NAKED static bool8 sub_800DD0C(struct unkStruct_203B0CC_sub *param_1, DungeonPos *posArg)
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

static bool8 sub_800DE38(struct unkStruct_203B0CC_sub *a1)
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

static inline const EfoFileData *GetFileEfo(struct unkStruct_203B0CC_sub *a0)
{
    return a0->unkB8->data;
}

static bool8 sub_800DE8C(struct unkStruct_203B0CC_sub *a0, DungeonPos *unused)
{
    s16 sp[4];
    struct unkStruct_203B0CC_x94 *r8 = &a0->unk94;

    if (r8->unk18 == 0) {
        if (sub_8009A7C(&r8->sub, r8->unk14, 0, 0, TRUE, &r8->unk18, sp)) {
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

static void sub_800E0B4(struct unkStruct_203B0CC_sub *r5)
{
    s32 r2;
    const unkStruct_80B9CC4 *r6 = sub_800ECA4(r5->unkC.unk0);
    r5->unk34 = r6->animType;
    r5->effectID = r6->effectId;
    r5->unk4C = r6->unk10;
    r5->unk50 = r5->unkC.unk4 + r6->unk14;
    r5->unk55 = r6->loop;
    r5->unk54 = r6->unk20;
    r2 = sub_800E2B8(r5->unkB8);
    r5->unk8 = r2;
    r5->unk40 = r6->animId;
    if (r5->unkC.dir != -1 && (r2 % 8) == 0) {
        r5->unk40 += r5->unkC.dir;
    }

    switch (r5->unk34) {
        case 3:
            r5->unk48 = 0x370;
            r5->paletteNum = r6->unk8;
            r5->unk44 = -1;
            break;
        case 4:
            r5->unk48 = -1;
            r5->paletteNum = r6->unk8;
            r5->unk44 = 3840;
            gUnknown_203B0CC->unk1A08 = 0;
            gUnknown_203B0CC->unk1A0C = 0;
            gUnknown_203B0CC->unk1A10 = sub_800CDC8();
            gUnknown_203B0CC->unk1A14 = gUnknown_2026E4E;
            if (r6->unk18 != 0) {
                sub_800CDA8(5);
            }
            break;
        case 1:
        case 2:
            r5->unk48 = 0x248;
            r5->paletteNum = r6->unk8;
            r5->unk44 = -1;
            break;
    }

    switch (r5->unk34) {
        case 1:
        case 2:
            AxResInitUnorientedFile(&r5->unk58, r5->unkB8, r5->unk40, 0x248, 0, r5->unk55);
            break;
        case 3:
            AxResInitUnorientedFile(&r5->unk58, r5->unkB8, r5->unk40, 0x370, 0, r5->unk55);
            break;
        case 4:
            r5->unk94.sub = (*(struct EfbFileData*)(r5->unkB8->data));
            r5->unk94.unk20 = 0;
            break;
    }
}

static s32 sub_800E208(s32 a0, unkStruct_80416E0 *a1)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr = gUnknown_203B0CC->unk0;

    if (a1->unk0 == 0)
        return -1;

    for (i = 0; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        if (ptr->unk4 == -1) {
            const unkStruct_80B9CC4 *strPtr;

            MemoryClear8(ptr, sizeof(*ptr));
            strPtr = sub_800ECA4(a1->unk0);
            if (strPtr->animType == 2 && gUnknown_203B0CC->fileSelection != 1)
                return -1;
            if (strPtr->animType == 1 && gUnknown_203B0CC->fileSelection != 0)
                return -1;
            ptr->unkB8 = OpenEffectFile(strPtr->animType, strPtr->effectId);
            if (ptr->unkB8 == NULL)
                return -1;
            ptr->unk0 = a0;
            ptr->unk4 = sub_800E2F0();
            ptr->unkC = *a1;
            sub_800E0B4(ptr);
            return ptr->unk4;
        }
    }

    return -1;
}

static s32 sub_800E2B8(OpenedFile *a0)
{
    const EfoFileData *efo = a0->data;
    return efo->animCount;
}

static s32 sub_800E2C0(s32 a0)
{
    if (a0 != -1) {
        s32 i;
        struct unkStruct_203B0CC_sub *ptr = gUnknown_203B0CC->unk0;

        for (i = 0; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
            if (ptr->unk4 == a0)
                return i;
        }
    }
    return -1;
}

static s32 sub_800E2F0(void)
{
    s32 prev = gUnknown_203B0CC->unk1A00;
    gUnknown_203B0CC->unk1A00++;
    return prev;
}

s32 sub_800E308(struct UnkStruct_8040094 *a0, DungeonPos *a1)
{
    s32 id;
    unkStruct_80416E0 sp = {
        .unk0 = sub_800ECB8(a0->unk0)->unk6,
        .unk4 = a0->unk10,
        .dir = a0->unkC,
        .pos1 = a0->unk4,
        .pos2 = a0->unk8,
        .unk14 = sub_800E750(a0->unk2, a0->unk0),
        .unk18 = 0xFFFF,
        .spriteMasks = sDefaultSpriteMasks,
    };
    s32 retVal = sub_800E208(2, &sp);

    if (retVal == -1)
        return -1;

    id = sub_800E2C0(retVal);
    if (id != -1) {
        struct unkStruct_203B0CC_sub *ptr = &gUnknown_203B0CC->unk0[id];
        ptr->unkBC = a0->unk4;
        ptr->unkC0 = *a1;
        ptr->unkC4 = a0->unk2;
        ptr->unkC8 = ptr->unkC.pos2;
        return retVal;
    }

    return -1;
}

void sub_800E3AC(s32 a0, DungeonPos *pos, s32 a2)
{
    s32 val, valMinus1;
    struct unkStruct_203B0CC_sub *ptr;
    s32 id = sub_800E2C0(a0);

    if (id == -1)
        return;

    ptr = &gUnknown_203B0CC->unk0[id];
    ptr->unkC.pos1 = *pos;

    val = max(abs(ptr->unkC0.x - ptr->unkBC.x), abs(ptr->unkC0.y - ptr->unkBC.y)) / 4;
    valMinus1 = val - 1;

    ptr->unkC.pos2.y += 9;
    ptr->unkC.pos2.x *= valMinus1;
    ptr->unkC.pos2.y *= valMinus1;
    ptr->unkC.pos2.x /= val;
    ptr->unkC.pos2.y /= val;
    ptr->unkC.pos2.y -= 9;

    ptr->unkC.unk18 = a2;
}

s32 sub_800E448(u8 a0, DungeonPos *pos)
{
    unkStruct_80416E0 sp = {
        .unk0 = sub_800ECE4(a0),
        .unk4 = 0,
        .dir = -1,
        .pos1 = *pos,
        .pos2 = {0, 0},
        .unk14 = -1,
        .unk18 = 0xFFFF,
        .spriteMasks = sDefaultSpriteMasks,
    };
    return sub_800E208(3, &sp);
}

s32 sub_800E49C(u8 a0, DungeonPos *pos, DungeonPos posArray[4], bool8 a3, s32 a4)
{
    s32 r4 = a3 ? sub_800ECF8(a0) : sub_800ED0C(a0);
    s32 r5 = sub_800E700(r4);
    unkStruct_80416E0 sp = {
        .unk0 = r4,
        .unk4 = 0,
        .dir = -1,
        .pos1 = *pos,
        .pos2 = {0, 0},
        .unk14 = -1,
        .unk18 = 0,
        .spriteMasks = sDefaultSpriteMasks,
    };

    sp.unk18 = a4;
    if (a3) {
        if (r5 != -1) {
            sp.unk14 = r5;
            sp.pos2 = posArray[r5];
        }
    }
    else {
        sp.unk14 = 3;
        sp.pos2 = posArray[3];
    }

    return sub_800E208(4, &sp);
}

s32 sub_800E52C(struct UnkStruct_8040094 *a0)
{
    s32 i;

    if (a0->unk0 == 0x52) {
        DungeonPos positions[8] = {
            { -64,   10 },
            { -72,  -28 },
            { -60,   50 },
            { -65,  -60 },
            { -80,   24 },
            { -80,   70 },
            { -100,  32 },
            { -120, -48 },
        };
        unkStruct_80416E0 sp[8];
        s32 ret = 0;
        for (i = 0; i < 8; i++) {
            s32 possibleRet;
            s32 id;
            unkStruct_80416E0 *curr = &sp[i];

            curr->unk0 = sub_800ECB8(a0->unk0)->unk2;
            curr->unk4 = a0->unk10;
            curr->dir = a0->unkC;
            curr->pos1 = a0->unk4;
            curr->pos1.y += 64;
            curr->pos2 = a0->unk8;
            curr->pos2.x += positions[i].x;
            curr->pos2.y += positions[i].y - 64;
            curr->unk14 = sub_800E750(a0->unk2, a0->unk0);
            curr->unk18 = 0xFFFF;
            curr->spriteMasks = sDefaultSpriteMasks;
            possibleRet = sub_800E208(1, curr);
            id = sub_800E2C0(possibleRet);
            if (id != -1) {
                struct unkStruct_203B0CC_sub *ptr = &gUnknown_203B0CC->unk0[id];
                ptr->unkCC.x = 6;
            }
            if (i == 0) {
                ret = possibleRet;
            }
        }

        for (i = 0; i < 7; i++) {
            const unkStruct_80B9CC4 *ptr2 = sub_800ECA4(sub_800ECB8(a0->unk0)->unk2);
            sub_800F15C(ptr2->effectId);
        }
        return ret;
    }
    else {
        unkStruct_80416E0 sp = {
            .unk0 = sub_800ECB8(a0->unk0)->unk2,
            .unk4 = a0->unk10,
            .dir = a0->unkC,
            .pos1 = a0->unk4,
            .pos2 = a0->unk8,
            .unk14 = sub_800E750(a0->unk2, a0->unk0),
            .unk18 = 0xFFFF,
            .spriteMasks = sDefaultSpriteMasks,
        };
        return sub_800E208(1, &sp);
    }
}

UNUSED static void sub_800E698(s32 a0, DungeonPos *pos1, DungeonPos *pos2)
{
    s32 id = sub_800E2C0(a0);
    if (id != -1) {
        struct unkStruct_203B0CC_sub *ptr = &gUnknown_203B0CC->unk0[id];
        ptr->unkC.pos1 = *pos1;
        if (ptr->unkC.unk14 != -1) {
            ptr->unkC.pos2 = *pos2;
        }
        else {
            ptr->unkC.pos2.x = 0;
            ptr->unkC.pos2.y = 0;
        }
    }
}

s32 sub_800E6D8(s32 a0)
{
    s32 id = sub_800E2C0(a0);
    if (id != -1) {
        struct unkStruct_203B0CC_sub *ptr = &gUnknown_203B0CC->unk0[id];
        return ptr->unkC.unk14;
    }
    else {
        return -1;
    }
}

s32 sub_800E700(s32 a0)
{
    return sub_800E900((s16) a0);
}

s32 sub_800E710(s32 species_, s32 moveId)
{
    s32 i;
    s32 species = (s16) (species_);
    const unkStruct_80BDBC4 *unkPtr1 = sub_800ECB8(moveId);
    const unkStruct_80C183C *unkPtr2 = sub_800ECD0(unkPtr1->unk20);

    for (i = 0; i < unkPtr1->unk1C; i++, unkPtr2++) {
        if (unkPtr2->species == species) {
            return unkPtr2->unk4;
        }
    }
    return unkPtr1->unk14;
}

// Literally the same as the func above.
static s32 sub_800E750(s32 species_, s32 moveId)
{
    s32 i;
    s32 species = (s16) (species_);
    const unkStruct_80BDBC4 *unkPtr1 = sub_800ECB8(moveId);
    const unkStruct_80C183C *unkPtr2 = sub_800ECD0(unkPtr1->unk20);

    for (i = 0; i < unkPtr1->unk1C; i++, unkPtr2++) {
        if (unkPtr2->species == species) {
            return unkPtr2->unk4;
        }
    }
    return unkPtr1->unk14;
}

// Almost the same as the two funcs above, but returns different fields.
s32 sub_800E790(s32 species_, s32 moveId)
{
    s32 i;
    s32 species = (s16) (species_);
    const unkStruct_80BDBC4 *unkPtr1 = sub_800ECB8(moveId);
    const unkStruct_80C183C *unkPtr2 = sub_800ECD0(unkPtr1->unk20);

    for (i = 0; i < unkPtr1->unk1C; i++, unkPtr2++) {
        if (unkPtr2->species == species) {
            return unkPtr2->soundEffectId;
        }
    }
    return unkPtr1->soundEffectId;
}

bool8 sub_800E7D0(u16 *param_1)
{
    s32 local_1c[4];
    s32 index;
    bool8 flag = FALSE;

    local_1c[0] = sub_800ECB8(*param_1)->unk0;
    local_1c[1] = sub_800ECB8(*param_1)->unk2;
    local_1c[2] = sub_800ECB8(*param_1)->unk4;
    local_1c[3] = sub_800ECB8(*param_1)->unk6;
    for (index = 0; index < 4; index++) {
        flag = (sub_800ECA4(local_1c[index])->animType == 4);
        if (flag)
            break;
    }
    return flag;
}

bool8 sub_800E838(u16 *param_1, s32 param_2)
{
    s32 local_1c[4];

    local_1c[0] = sub_800ECB8(*param_1)->unk0;
    local_1c[1] = sub_800ECB8(*param_1)->unk2;
    local_1c[2] = sub_800ECB8(*param_1)->unk4;
    local_1c[3] = sub_800ECB8(*param_1)->unk6;
    return sub_800ECA4(local_1c[param_2])->animType == 4;
}

s32 sub_800E890(unkStruct_80416E0 *param_1)
{
    param_1->unk14 = sub_800E900(param_1->unk0);
    return sub_800E208(7, param_1);
}

void sub_800E8AC(s32 a0, DungeonPos *a1, DungeonPos *a2, s32 a3, unkStruct_2039DB0 *a4)
{
    s32 index = sub_800E2C0(a0);
    if (index != -1) {
        struct unkStruct_203B0CC_sub *ptr = &gUnknown_203B0CC->unk0[index];

        if (a1 != NULL) ptr->unkC.pos1 = *a1;
        if (a2 != NULL) ptr->unkC.pos2 = *a2;
        if (a3 != 0xFFFF) ptr->unkC.unk18 = a3;
        if (a4 != NULL) ptr->unkC.spriteMasks = *a4;
    }
}

static s32 sub_800E900(s32 r0)
{
    return sub_800ECA4(r0)->unk1c;
}

bool8 sub_800E90C(DungeonPos *param_1)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;
    bool8 flag = FALSE;

    for (i = 0, ptr = &gUnknown_203B0CC->unk0[i]; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        if (ptr->unk4 != -1) {
            if (ptr->unkC.unk4 <= 0) {
                if (ptr->unk34 == 4) {
                    sub_800DE8C(ptr, param_1);
                }
                else {
                    sub_800DD0C(ptr, param_1);
                }
            }
            if (ptr->unkC.unk4 > 0)
                ptr->unkC.unk4--;
            sub_800DCD0(ptr);
            if (ptr->unk54 == 0)
                flag = TRUE;
        }
    }

    return flag;
}

void sub_800E970(void)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;

    for (i = 0, ptr = &gUnknown_203B0CC->unk0[i]; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        if (ptr->unk4 != -1 && ptr->unkC.unk4 <= 0 && ptr->unk34 != 4) {
            sub_800DE38(ptr);
        }
    }
}

bool8 sub_800E9A8(s32 a0)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;

    if (a0 == -1)
        return FALSE;

    ptr = gUnknown_203B0CC->unk0;
    for (i = 0; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        if (ptr->unk4 == a0) {
            if (ptr->unk54 != 0)
                return FALSE;
            return TRUE;
        }
    }

    return FALSE;
}

bool8 sub_800E9E4(u32 param_1)
{
    if (sub_800E2C0(param_1) != -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_800E9FC(u8 a0)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr = gUnknown_203B0CC->unk0;
    for (i = 0; i < UNK_203B0CC_ARR_COUNT; i++, ptr++) {
        if (ptr->unk4 != -1) {
            if (a0 != 0)
                return TRUE;
            if (ptr->unk54 == 0)
                return TRUE;
        }
    }

    if (sub_800EC74())
        return TRUE;
    return FALSE;
}

u8 sub_800EA44(unkStruct_800EA44 param_1, s32 param_2)
{
    s32 i;
    s32 a = param_1.unk0;
    const unkStruct_80BDBC4 *ret = sub_800ECB8(param_2);
    const unkStruct_80C183C *unkStruct2 = sub_800ECD0(ret->unk20);

    for (i = 0; i < ret->unk1C; i++, unkStruct2++) {
        if (unkStruct2->species == a) {
            return unkStruct2->unk2;
        }
    }

    return ret->unk10;
}

s32 sub_800EA84(struct UnkStruct_8040094 *a0)
{
    unkStruct_80416E0 sp = {
        .unk0 = sub_800ECB8(a0->unk0)->unk0,
        .unk4 = a0->unk10,
        .dir = a0->unkC,
        .pos1 = a0->unk4,
        .pos2 = a0->unk8,
        .unk14 = sub_800EBBC(sub_800ECB8(a0->unk0)->unk0),
        .unk18 = 0xFFFF,
        .spriteMasks = sDefaultSpriteMasks,
    };
    return sub_800E208(5, &sp);
}

UNUSED static void sub_800EAE4(s32 param_1, DungeonPos *param_2, DungeonPos *param_3)
{
    s32 idx = sub_800E2C0(param_1);
    if (idx != -1) {
        struct unkStruct_203B0CC_sub *a = &gUnknown_203B0CC->unk0[idx];
        a->unkC.pos1 = *param_2;
        if (a->unkC.unk14 != -1) {
            a->unkC.pos2 = *param_3;
        }
        else {
            a->unkC.pos2.x = 0;
            a->unkC.pos2.y = 0;
        }
    }
}

void sub_800EB24(s32 param_1, DungeonPos *param_2, DungeonPos *param_3, s32 r5, s32 r4)
{
    s32 idx = sub_800E2C0(param_1);
    if (idx != -1) {
        struct unkStruct_203B0CC_sub *curStruct = &gUnknown_203B0CC->unk0[idx];
        if (curStruct->unkCC.x == 0 && curStruct->unkCC.y == 0) {
            curStruct->unkC.pos1 = *param_2;
        }

        if (curStruct->unk0 == 6) {
            curStruct->unkC.unk18 = r5 + 1;
        }
        else if ((curStruct->unk8 % 8) == 0) {
            s32 values[8] = {1, 1, 1, -1, -1, -1, 1, 1};
            curStruct->unkC.unk18 = r5 + values[r4 & 7];
        }
        else {
            curStruct->unkC.unk18 = r5 + 1;
        }

        if (curStruct->unkC.unk14 != -1) {
            curStruct->unkC.pos2 = *param_3;
        }
        else {
            curStruct->unkC.pos2.x = 0;
            curStruct->unkC.pos2.y = 0;
        }
    }
}

static s32 sub_800EBBC(s32 param_1)
{
    const unkStruct_80B9CC4 *ret = sub_800ECA4(param_1);
    return ret->unk1c;
}

s32 sub_800EBC8(struct UnkStruct_8040094 *a0)
{
    unkStruct_80416E0 sp = {
        .unk0 = sub_800ECB8(a0->unk0)->unk4,
        .unk4 = a0->unk10,
        .dir = a0->unkC,
        .pos1 = a0->unk4,
        .pos2 = a0->unk8,
        .unk14 = sub_800EC68(sub_800ECB8(a0->unk0)->unk4),
        .unk18 = 0xFFFF,
        .spriteMasks = sDefaultSpriteMasks,
    };
    return sub_800E208(6, &sp);
}

UNUSED static void sub_800EC28(u32 param_1, DungeonPos *param_2, DungeonPos *param_3)
{
    s32 idx = sub_800E2C0(param_1);
    if (idx != -1) {
        struct unkStruct_203B0CC_sub *struct203B0CC = &gUnknown_203B0CC->unk0[idx];

        struct203B0CC->unkC.pos1 = *param_2;
        if (struct203B0CC->unkC.unk14 != -1) {
            struct203B0CC->unkC.pos2 = *param_3;
        }
        else {
            struct203B0CC->unkC.pos2.x = 0;
            struct203B0CC->unkC.pos2.y = 0;
        }
    }
}

static s32 sub_800EC68(s32 param_1)
{
    const unkStruct_80B9CC4 *ret = sub_800ECA4(param_1);
    return ret->unk1c;
}

u8 sub_800EC74(void)
{
    return sub_800F19C(1);
}

bool8 sub_800EC84(s32 moveId)
{
    return sub_800ECB8(moveId)->useSineWobble;
}

u8 sub_800EC94(s32 param_1)
{
    const unkStruct_80BDBC4 *ret = sub_800ECB8(param_1);
    return ret->unk9;
}
