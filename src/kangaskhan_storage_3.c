#include "global.h"
#include "kangaskhan_storage.h"
#include "team_inventory.h"

extern struct unkStruct_203B20C *gUnknown_203B20C;

extern u32 sub_801B410();
extern void sub_801B450();
extern void sub_8017F10(u32);

extern u8 sub_801CF14(u32);

struct HeldItem_Alt {
  union tempHeld
  {
      struct HeldItem norm;
      u32 full_bits;
  } temp;
};

extern u8 sub_8012FD8(u32 *r0);
extern void sub_8013114(u32 *, s32 *);
extern void sub_801CBB8(void);
extern void sub_8017F10(u32);
extern void sub_8012EA4(u32 *, u32);

bool8 IsNotMoneyOrUsedTMItem(u8 id);
extern u8 sub_801ADA0(s32);
extern void sub_801A928(void);
extern void sub_8099690(u32);
extern u32 sub_801A6E8(u32);

extern u32 sub_8013BBC(u32 *);
extern u32 sub_801CA08(u32);
extern void sub_8018280(void);

extern void sub_801CF94(void);
extern u8 sub_801CB24();
extern u32 sub_801CFB8(void);
extern void sub_801AD34(u32);
extern u32 sub_801CFE0(u8);

extern u32 sub_801A8AC(void);
extern u32 sub_801AEA8(void);
extern u32 sub_801AED0(u32);
extern void sub_801AE84(void);
extern u8 sub_801CF50(u32);


void sub_8018588(void)
{
    s32 temp;
    temp = 0;

    if(sub_8012FD8(&gUnknown_203B20C->unk70) == 0)
    {
        sub_8013114(&gUnknown_203B20C->unk70, &temp);
        if(temp != 1) gUnknown_203B20C->unk14 = temp;
    }

    switch(temp)
    {
        case 2:
            if((GetNumberOfFilledInventorySlots() != 0) && sub_801CF50(0) == 0)
                sub_8017F10(4);
            else
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);;
            break;
        case 3:
            if(sub_801CF14(1) != 0)
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            else
                sub_8017F10(0xA);
            break;
        case 1:
            sub_8017F10(3);
            break;
    }
}

void sub_8018620(void)
{
    s32 iVar6;
    switch(sub_801A6E8(1))
    {
        case 3:
            if(sub_801AEA8() != 0)
            {
                for(iVar6 = 0; iVar6 < INVENTORY_SIZE; iVar6++)
                {
                    if(sub_801AED0(iVar6) != 0)
                    {
                        MoveToStorage(&gTeamInventory_203B460->teamItems[iVar6]);
                        gTeamInventory_203B460->teamItems[iVar6].itemIndex = 0;
                        gTeamInventory_203B460->teamItems[iVar6].itemFlags = 0;
                    }
                }
                FillInventoryGaps();
                sub_801AE84();
                if(GetNumberOfFilledInventorySlots() == 0)
                {
                    sub_801A928();
                    sub_8017F10(1);
                }
                else
                {
                    sub_8017F10(5);
                }
            }
            else
            {
                gUnknown_203B20C->unkC = sub_801A8AC();
                gUnknown_203B20C->unk8 = gTeamInventory_203B460->teamItems[gUnknown_203B20C->unkC];
                sub_8017F10(6);
            }
            break;
        case 4:
            gUnknown_203B20C->unkC = sub_801A8AC();
            gUnknown_203B20C->unk8 = gTeamInventory_203B460->teamItems[gUnknown_203B20C->unkC];
            sub_8017F10(7);
            break;
        case 2:
            sub_801A928();
            sub_8017F10(1);
            break;
    }
}

void sub_80186F8(void)
{
    struct HeldItem_Alt item;
    u16 cast;
    s32 iVar6;
    u8 iVar6_32;

    switch(sub_801CA08(1))
    {
        case 3:
            if(sub_801CFB8() != 0)
            {
                for(iVar6 = 0; iVar6 < NUMBER_OF_ITEM_IDS; iVar6++)
                {
                    iVar6_32 = iVar6; // dumb cast needed to match
                    if(sub_801CFE0(iVar6) != 0)
                    {
                        item.temp.full_bits = (item.temp.full_bits & 0xffffff00) | iVar6_32;
                        if(IsThrowableItem(item.temp.norm.itemIndex))
                            if(gTeamInventory_203B460->teamStorage[item.temp.norm.itemIndex] > 0x63)
                            {
                                item.temp.full_bits = (item.temp.full_bits & 0xffff00ff) | (0xC6 << 7);
                            }
                            else
                            {
                                cast = gTeamInventory_203B460->teamStorage[item.temp.norm.itemIndex] << 8;
                                item.temp.full_bits = (item.temp.full_bits & 0xffff00ff) | cast;
                            }
                        else
                        {
                            item.temp.full_bits = (item.temp.full_bits & 0xffff00ff) | (0x80 << 1);
                        }
                        gTeamInventory_203B460->teamStorage[item.temp.norm.itemIndex] -= item.temp.norm.numItems;
                        sub_8091274((struct HeldItem *)&item);
                    }
                }
                FillInventoryGaps();
                sub_801CF94();
                if((sub_801CF14(1) == 0) && (GetNumberOfFilledInventorySlots() < INVENTORY_SIZE))
                    sub_8017F10(0xB);
                else
                {
                    sub_801CBB8();
                    sub_8017F10(1);
                }
            }
            else
            {
                gUnknown_203B20C->itemIndex = sub_801CB24();
                xxx_init_itemslot_8090A8C(&gUnknown_203B20C->unk8, gUnknown_203B20C->itemIndex, 0);
                gUnknown_203B20C->unk8.numItems = 1;
                sub_8017F10(0xD);
            }
            break;
        case 4:
            gUnknown_203B20C->itemIndex = sub_801CB24();
            xxx_init_itemslot_8090A8C(&gUnknown_203B20C->unk8, gUnknown_203B20C->itemIndex, 0);
            gUnknown_203B20C->unk8.numItems = 1;
            sub_8017F10(0xE);
            break;
        case 2:
            sub_801CBB8();
            sub_8017F10(1);
            break;
        case 1:
            sub_801AD34(0);
            break;
    }
}

void sub_8018854(void)
{
    struct HeldItem_Alt item;
    u32 itemsCast;
    u32 indexCast;

    sub_801CA08(0);
    sub_8012FD8(&gUnknown_203B20C->unk70);

    switch(sub_8013BBC(&gUnknown_203B20C->unkC0))
    {
        case 3:
            gUnknown_203B20C->unk8.numItems = gUnknown_203B20C->unkC0;

            gTeamInventory_203B460->teamStorage[gUnknown_203B20C->unk8.itemIndex] -= gUnknown_203B20C->unk8.numItems;

            indexCast = gUnknown_203B20C->unk8.itemIndex;
            item.temp.full_bits = (item.temp.full_bits & 0xffffff00) | indexCast;

            itemsCast = (gUnknown_203B20C->unk8.numItems << 8);
            item.temp.full_bits = (item.temp.full_bits & 0xffff00ff) | itemsCast;

            sub_8091274((struct HeldItem *)&item);
            if(sub_801CF14(1) == 0)
                if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                {
                    error:
                        sub_801CBB8();
                        sub_8017F10(0x1);
                }
                else
                    sub_8017F10(0xB);
            else
                goto error;
            break;
        case 2:
            sub_8017F10(0xB);
            break;
        case 1:
            sub_8018280();
            break;
        case 0:
            break;
    }
}

void sub_8018904(void)
{
    s32 temp;

    temp = 0;

    sub_801A6E8(0);
    if(sub_8012FD8(&gUnknown_203B20C->unk70) == 0)
    {
        sub_8013114(&gUnknown_203B20C->unk70, &temp);
        if(temp != 1) gUnknown_203B20C->unk18 = temp;
    }
    switch(temp)
    {
        case 2:
            if(IsNotMoneyOrUsedTMItem(gUnknown_203B20C->unk8.itemIndex))
                if(sub_801ADA0(gUnknown_203B20C->unkC) == 0)
            error:
                    sub_8012EA4(&gUnknown_203B20C->unk70, 1);
                else
                {
                    MoveToStorage(&gUnknown_203B20C->unk8);
                    ShiftItemsDownFrom(gUnknown_203B20C->unkC);
                    FillInventoryGaps();
                    if(GetNumberOfFilledInventorySlots() == 0)
                    {
                        sub_801A928();
                        sub_8017F10(1);
                    }
                    else
                        sub_8017F10(5);
                }
            else
                goto error;
            break;
        case 4:
            sub_8099690(0);
            sub_8017F10(7);
            break;
        case 1:
            sub_8017F10(5);
            break;
    }
}

void sub_80189C8(void)
{
    struct HeldItem_Alt item;
    s32 temp;
    u32 itemsCast;
    u32 indexCast;

    temp = 0;

    sub_801CA08(0);
    if(sub_8012FD8(&gUnknown_203B20C->unk70) == 0)
    {
        sub_8013114(&gUnknown_203B20C->unk70, &temp);
        if(temp != 1) gUnknown_203B20C->unk1C = temp;
    }
    switch(temp)
    {
        case 3:
            if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                sub_8012EA4(&gUnknown_203B20C->unk70, 1);
            else if(IsThrowableItem(gUnknown_203B20C->unk8.itemIndex))
                sub_8017F10(0xC);
            else
            {
                gTeamInventory_203B460->teamStorage[gUnknown_203B20C->unk8.itemIndex] -= gUnknown_203B20C->unk8.numItems;

                indexCast = gUnknown_203B20C->unk8.itemIndex;
                item.temp.full_bits = (item.temp.full_bits & 0xffffff00) | indexCast;

                itemsCast = (gUnknown_203B20C->unk8.numItems << 8);
                item.temp.full_bits = (item.temp.full_bits & 0xffff00ff) | itemsCast;

                sub_8091274((struct HeldItem *)&item);
                if(sub_801CF14(1) == 0)
                    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE)
                    {
                        error:
                            sub_801CBB8();
                            sub_8017F10(1);
                    }
                    else
                    {
                        sub_8017F10(0xB);
                    }
                else
                    goto error;
            }
            break;
        case 4:
            sub_8017F10(0xE);
            break;
        case 1:
            sub_8017F10(0xB);
            break;
    }
}

void sub_8018AC8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(0x5);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}

void sub_8018AE4(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8017F10(0xB);
            break;
        case 0:
        case 1:
        default:
            break;
    }
}
