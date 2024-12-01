#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_8023144.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_3.h"
#include "text.h"

static EWRAM_DATA_2 u32 gUnknown_203B298 = {0};
static EWRAM_DATA_2 u16 gUnknown_203B29C = {0};
static EWRAM_DATA_2 u16 gUnknown_203B29E = {0};

static IWRAM_DATA unkStruct_3001B5C *gUnknown_3001B5C = {0};

#include "data/code_8023144.h"

static void sub_8023420(void);
static void sub_80234BC(void);
static u32 sub_80236A4(void);
static bool8 sub_8023704(u8 unused);
static void sub_8023730(void);
static void sub_8023758(void);
static void sub_80237E0(void);

bool8 sub_8023144(s32 a0, s32 index, UnkTextStruct2_sub *sub, u32 a3)
{
    u8 param_1_u8 = a0;

    if (sub_8023704(param_1_u8))
        return FALSE;

    if (gUnknown_3001B5C == NULL)
        gUnknown_3001B5C = MemoryAlloc(sizeof(unkStruct_3001B5C), 8);

    gUnknown_3001B5C->unk0 = param_1_u8;
    gUnknown_3001B5C->unk4 = gUnknown_203B298;

    gUnknown_3001B5C->s35C.s0.unk34 = index;
    gUnknown_3001B5C->s35C.s0.unk38 = &gUnknown_3001B5C->s35C.s0.unk3C[index];
    RestoreUnkTextStruct_8006518(gUnknown_3001B5C->s35C.s0.unk3C);
    gUnknown_3001B5C->s35C.s0.unk3C[gUnknown_3001B5C->s35C.s0.unk34] = sUnknown_80DC91C;

    gUnknown_3001B5C->s35C.s0.unk38->unk14 = &gUnknown_3001B5C->s35C.unk9C;

    if (sub != NULL)
        gUnknown_3001B5C->s35C.s0.unk3C[gUnknown_3001B5C->s35C.s0.unk34].unk8 = *sub;

    sub_8012D08(gUnknown_3001B5C->s35C.s0.unk38, a3);
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_3001B5C->s35C.s0.unk3C, TRUE, TRUE);
    sub_8013818(&gUnknown_3001B5C->s35C.s0.input, sub_80236A4(), a3, index);
    gUnknown_3001B5C->s35C.s0.input.menuIndex = gUnknown_203B29C;
    gUnknown_3001B5C->s35C.s0.input.unk1E = gUnknown_203B29E;
    sub_8013984(&gUnknown_3001B5C->s35C.s0.input);
    sub_8023420();
    sub_80234BC();
    return TRUE;
}

u32 sub_8023278(bool8 a0)
{
    s32 iVar3;
    u32 temp;

    if (!a0) {
        sub_8013660(&gUnknown_3001B5C->s35C.s0.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_3001B5C->s35C.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        case INPUT_SELECT_BUTTON:
            PlayMenuSoundEffect(5);
            if (temp = gUnknown_3001B5C->unk4, iVar3 = 1, temp < 2)
                iVar3 = temp + 1;

            gUnknown_3001B5C->unk4 = iVar3;
            sub_80236A4();
            break;
        default:
            if (sub_80138B8(&gUnknown_3001B5C->s35C.s0.input, 1) == 0)
                return 0;
            break;
    }

    sub_8023420();
    sub_80234BC();
    return 1;
}

s16 sub_802331C(void)
{
    return gUnknown_3001B5C->unkC[(gUnknown_3001B5C->s35C.s0.input.unk1E * gUnknown_3001B5C->s35C.s0.input.unk1C) + gUnknown_3001B5C->s35C.s0.input.menuIndex];
}

void sub_8023354(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(gUnknown_3001B5C->s35C.s0.unk3C, FALSE, FALSE);
    sub_8013984(&gUnknown_3001B5C->s35C.s0.input);
    sub_8023420();
    sub_80234BC();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_3001B5C->s35C.s0.input);
}

void sub_80233A0(void)
{
    if (gUnknown_3001B5C != NULL) {
        gUnknown_203B298 = gUnknown_3001B5C->unk4;
        gUnknown_203B29C = gUnknown_3001B5C->s35C.s0.input.menuIndex;
        gUnknown_203B29E = gUnknown_3001B5C->s35C.s0.input.unk1E;
        gUnknown_3001B5C->s35C.s0.unk3C[gUnknown_3001B5C->s35C.s0.unk34] = sUnknown_80DC904;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(gUnknown_3001B5C->s35C.s0.unk3C, TRUE, TRUE);
        MemoryFree(gUnknown_3001B5C);
        gUnknown_3001B5C = NULL;
    }
}

static void sub_8023420(void)
{
    gUnknown_3001B5C->s35C.unk9C.f0 = 1;
    gUnknown_3001B5C->s35C.unk9C.f1 = 0;
    gUnknown_3001B5C->s35C.unk9C.f2 = 12;
    gUnknown_3001B5C->s35C.unk9C.f3 = 0;

    SUB_80095E4_CALL_2(gUnknown_3001B5C->s35C.s0);
}

static void sub_80234BC(void)
{
    u8 cVar2;
    u32 y;
    s32 uVar3;
    s32 iVar4;
    s32 species;
    u32 color;
    s32 i;
    u8 buffer2[256];
    u8 buffer1[100];
    unkStruct_8092638 auStack_2c;

    CallPrepareTextbox_8008C54(gUnknown_3001B5C->s35C.s0.unk34);
    sub_80073B8(gUnknown_3001B5C->s35C.s0.unk34);
    PrintStringOnWindow(10, 0, sPokemon, gUnknown_3001B5C->s35C.s0.unk34, 0);

    sub_8012BC4((gUnknown_3001B5C->s35C.unk9C.f2 * 8) + 4, 0, gUnknown_3001B5C->s35C.s0.input.unk1E + 1, 2, 7, gUnknown_3001B5C->s35C.s0.unk34);

    for (i = 0; i < gUnknown_3001B5C->s35C.s0.input.unk1A; i++) {
        y = sub_8013800(&gUnknown_3001B5C->s35C.s0.input, i);
        species = gUnknown_3001B5C->unkC[(gUnknown_3001B5C->s35C.s0.input.unk1E * gUnknown_3001B5C->s35C.s0.input.unk1C) + i];
        sub_8092638(GetFriendArea(species), &auStack_2c, FALSE, FALSE);
        color = COLOR_WHITE_2;
        if (auStack_2c.hasFriendArea)
            color = HasRecruitedMon(species) ? COLOR_CYAN : COLOR_GREEN;

        iVar4 = GetDexInternalNo(species, 0);
        cVar2 = (iVar4 % 10) + 48;
        sub_8012C60(20, y, cVar2, color, gUnknown_3001B5C->s35C.s0.unk34);

        if (9 < iVar4) {
            iVar4 /= 10;
            cVar2 = (iVar4 % 10) + 48;
            sub_8012C60(13, y, cVar2, color, gUnknown_3001B5C->s35C.s0.unk34);

            if (9 < iVar4) {
                uVar3 = iVar4 / 10;
                cVar2 = (uVar3 % 10) + 48;
                sub_8012C60(6, y, cVar2, color, gUnknown_3001B5C->s35C.s0.unk34);
            }
        }

        sub_808D930(buffer1,species);
        sprintfStatic(buffer2, sFmtColoredString, color, buffer1);
        PrintStringOnWindow(36, y, buffer2, gUnknown_3001B5C->s35C.s0.unk34, 0);
    }

    sub_80073E0(gUnknown_3001B5C->s35C.s0.unk34);
}

static u32 sub_80236A4(void)
{
    s32 index;

    gUnknown_3001B5C->unk8 = 0;

    for (index = 0; index < MONSTER_MAX; index++) {
        if (sub_8098134(index) && (s16)index == GetBaseSpeciesNoUnown(index))
            gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk8++] = index;
    }

    sub_8023730();
    return gUnknown_3001B5C->unk8;
}

static bool8 sub_8023704(u8 unused)
{
    s32 index;

    for (index = 0; index < MONSTER_MAX; index++) {
        if (sub_8098134(index))
            return FALSE;
    }

    return TRUE;
}

static void sub_8023730(void)
{
    switch (gUnknown_3001B5C->unk4) {
        case 1:
            sub_8023758();
            break;
        case 2:
            sub_80237E0();
            break;
    }
}

// 41.34%. Similar to SortbyAlphabetNo: https://decomp.me/scratch/Wmgj6
NAKED static void sub_8023758(void)
{
    asm_unified(
    "\tpush {r4-r7,lr}\n"
    "\tmov r7, r9\n"
    "\tmov r6, r8\n"
    "\tpush {r6,r7}\n"
    "\tsub sp, 0x4\n"
    "\tldr r3, _080237DC\n"
    "\tldr r2, [r3]\n"
    "\tldr r1, [r2, 0x8]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, 0xA\n"
    "\tadds r2, r0\n"
    "\tmov r9, r2\n"
    "\tmovs r2, 0\n"
    "\tsubs r1, 0x1\n"
    "\tcmp r2, r1\n"
    "\tbge _080237CC\n"
"_08023778:\n"
    "\tmov r5, r9\n"
    "\tldr r0, [r3]\n"
    "\tldr r0, [r0, 0x8]\n"
    "\tsubs r7, r0, 0x1\n"
    "\tadds r0, r2, 0x1\n"
    "\tmov r8, r0\n"
    "\tcmp r7, r2\n"
    "\tble _080237BE\n"
"_08023788:\n"
    "\tsubs r6, r5, 0x2\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r6, r1]\n"
    "\tmovs r1, 0x1\n"
    "\tstr r2, [sp]\n"
    "\tbl GetAlphabetParentNo\n"
    "\tadds r4, r0, 0\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tmovs r1, 0x1\n"
    "\tbl GetAlphabetParentNo\n"
    "\tlsls r4, 16\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [sp]\n"
    "\tcmp r4, r0\n"
    "\tble _080237B6\n"
    "\tmovs r0, 0\n"
    "\tldrsh r1, [r5, r0]\n"
    "\tldrh r0, [r6]\n"
    "\tstrh r0, [r5]\n"
    "\tstrh r1, [r6]\n"
"_080237B6:\n"
    "\tadds r5, r6, 0\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, r2\n"
    "\tbgt _08023788\n"
"_080237BE:\n"
    "\tmov r2, r8\n"
    "\tldr r3, _080237DC\n"
    "\tldr r0, [r3]\n"
    "\tldr r0, [r0, 0x8]\n"
    "\tsubs r0, 0x1\n"
    "\tcmp r2, r0\n"
    "\tblt _08023778\n"
"_080237CC:\n"
    "\tadd sp, 0x4\n"
    "\tpop {r3,r4}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_080237DC: .4byte gUnknown_3001B5C");
}

 // SIMILAR TO ABOVE: https://decomp.me/scratch/BG2JR
NAKED static void sub_80237E0(void)
{
    asm_unified(
    "\tpush {r4-r7,lr}\n"
    "\tmov r7, r9\n"
    "\tmov r6, r8\n"
    "\tpush {r6,r7}\n"
    "\tsub sp, 0x4\n"
    "\tldr r3, _08023864\n"
    "\tldr r2, [r3]\n"
    "\tldr r1, [r2, 0x8]\n"
    "\tlsls r0, r1, 1\n"
    "\tadds r0, 0xA\n"
    "\tadds r2, r0\n"
    "\tmov r9, r2\n"
    "\tmovs r2, 0\n"
    "\tsubs r1, 0x1\n"
    "\tcmp r2, r1\n"
    "\tbge _08023854\n"
"_08023800:\n"
    "\tmov r5, r9\n"
    "\tldr r0, [r3]\n"
    "\tldr r0, [r0, 0x8]\n"
    "\tsubs r7, r0, 0x1\n"
    "\tadds r0, r2, 0x1\n"
    "\tmov r8, r0\n"
    "\tcmp r7, r2\n"
    "\tble _08023846\n"
"_08023810:\n"
    "\tsubs r6, r5, 0x2\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r6, r1]\n"
    "\tmovs r1, 0\n"
    "\tstr r2, [sp]\n"
    "\tbl GetAlphabetParentNo\n"
    "\tadds r4, r0, 0\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tmovs r1, 0\n"
    "\tbl GetAlphabetParentNo\n"
    "\tlsls r4, 16\n"
    "\tlsls r0, 16\n"
    "\tldr r2, [sp]\n"
    "\tcmp r4, r0\n"
    "\tble _0802383E\n"
    "\tmovs r0, 0\n"
    "\tldrsh r1, [r5, r0]\n"
    "\tldrh r0, [r6]\n"
    "\tstrh r0, [r5]\n"
    "\tstrh r1, [r6]\n"
"_0802383E:\n"
    "\tadds r5, r6, 0\n"
    "\tsubs r7, 0x1\n"
    "\tcmp r7, r2\n"
    "\tbgt _08023810\n"
"_08023846:\n"
    "\tmov r2, r8\n"
    "\tldr r3, _08023864\n"
    "\tldr r0, [r3]\n"
    "\tldr r0, [r0, 0x8]\n"
    "\tsubs r0, 0x1\n"
    "\tcmp r2, r0\n"
    "\tblt _08023800\n"
"_08023854:\n"
    "\tadd sp, 0x4\n"
    "\tpop {r3,r4}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_08023864: .4byte gUnknown_3001B5C");
}
