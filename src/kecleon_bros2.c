#include "global.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "constants/input.h"
#include "items.h"
#include "kecleon_bros2.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 unkStruct_203B214 *gUnknown_203B214 = {0};
static EWRAM_DATA_2 u16 gUnknown_203B218 = {0};

#include "data/kecleon_bros2.h"

static void sub_801A064(void);

bool8 sub_8019E40(u32 r0)
{
    if (CountKecleonShopItems() == 0)
        return FALSE;

    gUnknown_203B214 = MemoryAlloc(sizeof(unkStruct_203B214), 8);
    gUnknown_203B214->unk34 = r0;
    gUnknown_203B214->unk38 = &gUnknown_203B214->unk3C[gUnknown_203B214->unk34];
    sub_8006518(gUnknown_203B214->unk3C);
    gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = sUnknown_80DB8CC;
    gUnknown_203B214->unk38->unk14 = gUnknown_203B214->unk9C;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, TRUE, TRUE);
    sub_8013818(&gUnknown_203B214->input, CountKecleonShopItems(), 10, r0);
    gUnknown_203B214->input.menuIndex = gUnknown_203B218;
    sub_8013984(&gUnknown_203B214->input);
    sub_801A064();
    sub_801A0D8();
    return TRUE;
}

u32 sub_8019EDC(u8 r0)
{
    Item slot;
    BulkItem *item;

    if (r0 == 0) {
        sub_8013660(&gUnknown_203B214->input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B214->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            item = GetKecleonShopItem(sub_8019FB0());
            slot.id = item->id;
            slot.quantity = item->quantity;

            if (GetStackBuyPrice(&slot) > gTeamInventoryRef->teamMoney)
                PlayMenuSoundEffect(2);
            else
                PlayMenuSoundEffect(0);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B214->input, 1) != FALSE) {
                sub_801A064();
                sub_801A0D8();
                return 1;
            }
            return 0;
    }
}

u8 sub_8019FB0(void)
{
    return (gUnknown_203B214->input.unk1E * gUnknown_203B214->input.unk1C) + (u8)gUnknown_203B214->input.menuIndex;
}

void sub_8019FCC(bool8 r0)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, FALSE, FALSE);
    gUnknown_203B214->input.unk22 = CountKecleonShopItems();
    sub_8013984(&gUnknown_203B214->input);
    sub_801A064();
    sub_801A0D8();
    if (r0)
        AddMenuCursorSprite(&gUnknown_203B214->input);
}

void sub_801A010(void)
{
    if (gUnknown_203B214 != NULL) {
        gUnknown_203B218 = gUnknown_203B214->input.menuIndex;
        gUnknown_203B214->unk3C[gUnknown_203B214->unk34] = sUnknown_80DB8B4;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B214->unk3C, TRUE, TRUE);
        MemoryFree(gUnknown_203B214);
        gUnknown_203B214 = NULL;
    }
}

#if NONMATCHING // sub_80095E4 memes https://decomp.me/scratch/VjeuO
static void sub_801A064(void)
{
    s16 val;

    gUnknown_203B214->unk9C[0] = gUnknown_203B214->input.unk20;
    gUnknown_203B214->unk9C[1] = gUnknown_203B214->input.unk1E;
    gUnknown_203B214->unk9C[2] = 10;
    gUnknown_203B214->unk9C[3] = 0;

    val = sub_80095E4(gUnknown_203B214->input.unk1A, 12) + 2;
    gUnknown_203B214->unk3C[gUnknown_203B214->unk34].unkE = val;
    gUnknown_203B214->unk3C[gUnknown_203B214->unk34].unk10 = val + 2;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B214->unk3C, TRUE, TRUE);
}
#else
NAKED
static void sub_801A064(void)
{
    asm_unified(
            "\tpush {r4,lr}\n"
            "\tldr r4, _0801A0D4\n"
            "\tldr r0, [r4]\n"
            "\tldrh r1, [r0, 0x20]\n"
            "\tadds r0, 0x9C\n"
            "\tmovs r2, 0\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tldrh r1, [r0, 0x1E]\n"
            "\tadds r0, 0x9D\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x9E\n"
            "\tmovs r1, 0xA\n"
            "\tstrb r1, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x9F\n"
            "\tstrb r2, [r0]\n"
            "\tldr r0, [r4]\n"
            "\tmovs r1, 0x1A\n"
            "\tldrsh r0, [r0, r1]\n"
            "\tmovs r1, 0xC\n"
            "\tbl sub_80095E4\n"
            "\tadds r0, 0x2\n"
            "\tlsls r0, 16\n"
            "\tldr r2, [r4]\n"
            "\tldr r3, [r2, 0x34]\n"
            "\tlsls r1, r3, 1\n"
            "\tadds r1, r3\n"
            "\tlsls r1, 3\n"
            "\tadds r1, r2, r1\n"
            "\tadds r1, 0x4A\n"
            "\tasrs r3, r0, 16\n"
            "\tlsrs r0, 16\n"
            "\tstrh r0, [r1]\n"
            "\tldr r1, [r2, 0x34]\n"
            "\tlsls r0, r1, 1\n"
            "\tadds r0, r1\n"
            "\tlsls r0, 3\n"
            "\tadds r2, r0\n"
            "\tadds r3, 0x2\n"
            "\tadds r2, 0x4C\n"
            "\tstrh r3, [r2]\n"
            "\tbl ResetUnusedInputStruct\n"
            "\tldr r0, [r4]\n"
            "\tadds r0, 0x3C\n"
            "\tmovs r1, 0x1\n"
            "\tmovs r2, 0x1\n"
            "\tbl sub_800641C\n"
            "\tpop {r4}\n"
            "\tpop {r0}\n"
            "\tbx r0\n"
            "\t.align 2, 0\n"
    "_0801A0D4: .4byte gUnknown_203B214");
}
#endif // NONMATCHING

void sub_801A0D8(void)
{
    BulkItem *heldItem;
    s32 buyPrice;
    s32 y;
    s32 index;
    u8 auStack204[80];
    struct unkStruct_8090F58 local_7c;
    u8 auStack112[80];
    Item item;
    u8 temp_calc;

    sub_8008C54(gUnknown_203B214->unk34);
    sub_80073B8(gUnknown_203B214->unk34);
    xxx_call_draw_string((gUnknown_203B214->input.unk1E * 8) + 10, 0, sGoods, gUnknown_203B214->unk34, 0);

    for (index = 0; index < gUnknown_203B214->input.unk1A; index++) {
        temp_calc = (gUnknown_203B214->input.unk1E * gUnknown_203B214->input.unk1C) + index;
        heldItem = GetKecleonShopItem(temp_calc);
        item.id = heldItem->id;
        item.quantity = heldItem->quantity;
        item.flags = (ITEM_FLAG_EXISTS | ITEM_FLAG_IN_SHOP);
        local_7c.unk0 = 1;
        local_7c.unk4 = 0;
        local_7c.unk6 = 88;
        local_7c.unk8 = 1;
        sub_8090E14(auStack204, &item, &local_7c);
        buyPrice = GetStackBuyPrice(&item);

        if (buyPrice <= gTeamInventoryRef->teamMoney) {
            y = sub_8013800(&gUnknown_203B214->input, index);
            xxx_call_draw_string(8, y, auStack204, gUnknown_203B214->unk34, 0);
        }
        else {
            sprintfStatic(auStack112, sFmtRed, auStack204);
            y = sub_8013800(&gUnknown_203B214->input, index);
            xxx_call_draw_string(8, y, auStack112, gUnknown_203B214->unk34, 0);
        }
    }

    sub_80073E0(gUnknown_203B214->unk34);
}