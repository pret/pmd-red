#include "global.h"
#include "item.h"
#include "pokemon.h"
#include "text.h"
#include "team_inventory.h"
#include "constants/move.h"
#include "code_800D090.h"

struct unkStruct_203B2B8
{
    // size: 0x280
    u32 state;
    u32 unk4;
    u8 unk8;
    s16 pokeSpecies;
    u32 unkC;
    struct HeldItem unk10;
    struct HeldItem unk14;
    struct PokemonStruct *unk18;
    u8 fill1C[0x4];
    u32 unk20;
    u16 unk24;
    struct PokemonMove unk28[4];
    u8 fill48[0x70 - 0x48];
    u32 unk70;
    u32 unk74;
    u32 unk78;
    u32 unk7C;
    u8 fill80[0xCC - 0x80];
    u32 unkCC;
};
extern struct unkStruct_203B2B8 *gUnknown_203B2B8;
extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_202DEA8[0x58];
extern u8 gUnknown_202DE58[0x58];
extern u8 gUnknown_80DD6E0[];
extern u8 gPartyMenuItemPlaceholder[];
extern struct UnkTextStruct2 gUnknown_80DD370;

extern u32 sub_8026F04(struct PokemonStruct *);
extern void sub_8026074(u32);
extern void PlaySound(u32);
bool8 sub_8026F38(struct PokemonStruct *r0);
extern u8 sub_80023E4(u8);
extern struct PokemonStruct *sub_808D3F8(void);
extern struct PokemonStruct *sub_808D3BC(void);
extern void sub_801F214(void);
extern u32 sub_801F194(void);
extern u32 sub_801EF38(u32);


extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern void sub_80922B4(u8 *, const u8 *, u32);
extern void sub_808D930(u8 *, s16);
extern s32 sub_8008ED0(u8 *);
extern void xxx_call_draw_string(s32 x, s32 y, u8 *, u32, u32);
extern void xxx_format_and_draw(s32, s32, u8 *, ...);
extern s32 sub_80144A4(s32 *);

extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u32 sub_801B410(void);
extern void sub_801B450(void);

extern void nullsub_104(void);
extern void sub_801A928(void);
extern void sub_8099690(u32);
extern u32 sub_801A6E8(u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);

extern u32 sub_801A8AC(void);
extern u32 sub_8022860(void);
extern void sub_8022908(void);

extern void sub_801BF98(void);
extern u32 sub_801BF48(void);
extern void sub_802453C(void);
extern u32 sub_80244E4(void);


void sub_8026A78(void)
{
    switch(sub_80244E4())
    {
        case 2:
        case 3:
            sub_802453C();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8026A94(void)
{
    switch(sub_801BF48())
    {
        case 2:
        case 3:
            sub_801BF98();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}


static inline bool8 sub_8026AB0_sub(void) {
    if (gUnknown_203B2B8->unk18->unk4.dungeonIndex == 0x44 || gUnknown_203B2B8->unk18->unk4.dungeonIndex == 0x45)
        return TRUE;
    else
        return FALSE;
}

void sub_8026AB0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                sub_8026074(2);
                break;
            case 2:
                if (sub_8026AB0_sub())
                    sub_8026074(0xD);
                else
                    sub_8026074(8);
                break;
        }
    }
}

void sub_8026B10(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        switch(temp)
        {
            case 1:
            case 3:
                sub_8026074(2);
                break;
            case 2:
                sub_8026074(8);
                break;
        }
    }
}


void sub_8026B48(void)
{
    switch(sub_8022860())
    {
        case 2:
        case 3:
            sub_8022908();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}


void sub_8026B64(void)
{
    switch(sub_801A6E8(1))
    {
        case 3:
            gUnknown_203B2B8->unkC = sub_801A8AC();
            gUnknown_203B2B8->unk10.itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->unkC].itemIndex;
            gUnknown_203B2B8->unk10.numItems = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->unkC].numItems;
            sub_8026074(0x14);
            break;
        case 4:
            gUnknown_203B2B8->unkC = sub_801A8AC();
            gUnknown_203B2B8->unk10.itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->unkC].itemIndex;
            gUnknown_203B2B8->unk10.numItems = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->unkC].numItems;
            sub_8099690(0);
            sub_8026074(0x15);
            break;
        case 2:
            sub_801A928();
            sub_8026074(2);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8026C14(void)
{
  u32 nextState;
  struct unkStruct_8090F58 temp;
  int menuAction;
  struct ItemSlot slot;

  menuAction = 0;
  sub_801A6E8(0);
  if ((sub_8012FD8(&gUnknown_203B2B8->unkCC) == '\0') && (sub_8013114(&gUnknown_203B2B8->unkCC,&menuAction), menuAction != 1)) {
    gUnknown_203B2B8->unk74 = menuAction;
  }
  switch(menuAction)
  {
      case 0xb:
        nextState = 0xF;
        PlaySound(0x14d);
        ShiftItemsDownFrom(gUnknown_203B2B8->unkC);
        FillInventoryGaps();
        if (gUnknown_203B2B8->unk14.itemIndex != '\0') {
          AddHeldItemToInventory(&gUnknown_203B2B8->unk14);
          nextState = 0x10;
        }
        HeldItemToSlot(&slot,&gUnknown_203B2B8->unk10);
        temp.unk0 = 0;
        temp.unk4 = 0;
        temp.unk8 = 1;
        slot.itemFlags = ITEM_FLAG_EXISTS;
        sub_8090E14(gUnknown_202DEA8,&slot,&temp);
        GivePokemonItem(gUnknown_203B2B8->pokeSpecies,&gUnknown_203B2B8->unk10);
        sub_801A928();
        nullsub_104();
        sub_8026074(nextState);
        break;
      case 4:
        sub_8099690(0);
        sub_8026074(0x15);
        break;
      case 1:
        sub_8026074(0x13);
        break;
  }
}

void sub_8026CF0(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            sub_8026074(0x13);
            break;
        case 0:
        case 1:
            break;
    }
}


void sub_8026D0C(void)
{
    switch(sub_801EF38(1))
    {
        case 0:
        case 1:
            break;
        case 3:
        case 4:
            gUnknown_203B2B8->unk20 = sub_801F194();
            gUnknown_203B2B8->unk24 = gUnknown_203B2B8->unk28[gUnknown_203B2B8->unk20].moveID;
            sub_8026074(0x18);
            break;
        case 2:
            sub_801F214();
            sub_8026074(2);
            break;
    }
}

void sub_8026D6C(void)
{
    switch(sub_801F890())
    {
        case 2:
        case 3:
            sub_801F8D0();
            sub_8026074(0x17);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8026D88(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        sub_8026074(gUnknown_203B2B8->unk4);
    }
}

void sub_8026DAC(u32 r0, struct HeldItem *r1)
{
    struct ItemSlot slot;
    struct unkStruct_8090F58 temp;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&slot, r1);
    temp.unk0 = 0;
    temp.unk4 = 0;
    temp.unk8 = 1;
    slot.itemFlags = ITEM_FLAG_EXISTS;
    sub_8090E14(gUnknown_202DE58, &slot, &temp);
    xxx_format_and_draw(4, 3, gPartyMenuItemPlaceholder, r0, 0);
    sub_80073E0(r0);
}

void sub_8026E08(u32 r0)
{
    u8 buffer1[40];
    u8 buffer[20];
    s32 x;

    sub_8008C54(r0);
    sub_80073B8(r0);
    sub_80922B4(gAvailablePokemonNames, gUnknown_203B2B8->unk18->name, POKEMON_NAME_LENGTH);
    sub_808D930(buffer, gUnknown_203B2B8->unk18->speciesNum);
    sprintf_2(buffer1, gUnknown_80DD6E0, gAvailablePokemonNames);
    x = sub_8008ED0(buffer1);
    xxx_call_draw_string(((gUnknown_80DD370.unk0c << 3) - x) / 2, 3, buffer1, r0, 0);
    sub_80073E0(r0);
}

u32 sub_8026E88(struct PokemonStruct *r0)
{
    u8 iVar3;
    if(r0->isLeader == 0)
    {
        iVar3 = (r0->unk4.dungeonIndex == 0x41);
        if(iVar3 != 0)
            if(sub_80023E4(0x8) == 0)
                return 0;
    }
    else
        return 0;
    return 1;
}

u32 sub_8026EB8(struct PokemonStruct *r0)
{
    u8 iVar3;
    if(sub_808D3BC() != r0)
        if(sub_808D3F8() != r0)
            if(r0->isLeader == 0)
            {
                iVar3 = (r0->unk4.dungeonIndex == 0x41);
                if(iVar3 != 0)
                {
                    if(sub_80023E4(0x8) != 0)
                        goto check;
                }
                else
                    check:
                    if(sub_8026F04(r0) != 3)
                        return 1;
            }
    return 0;
}


u32 sub_8026F04(struct PokemonStruct *r0)
{
    if(r0->heldItem.itemIndex == 0)
        return 0;
    else if(GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
        return 1;
    else if(sub_8026F38(r0))
        return 2;
    else
        return 3;
}

bool8 sub_8026F38(struct PokemonStruct *r0)
{
    if(IsNotMoneyOrUsedTMItem(r0->heldItem.itemIndex))
    {
        if(IsThrowableItem(r0->heldItem.itemIndex))
        {
            if((gTeamInventory_203B460->teamStorage[r0->heldItem.itemIndex] + r0->heldItem.numItems) > 999)
                return FALSE;
        }
        else
        {
            if(gTeamInventory_203B460->teamStorage[r0->heldItem.itemIndex] > 998)
                return FALSE;
        }
    }
    else
        return FALSE;
    return TRUE;
}

void sub_8026FA4(void)
{
    switch(sub_8026F04(gUnknown_203B2B8->unk18))
    {
        case 1:
            PlaySound(0x14d);
            AddHeldItemToInventory(&gUnknown_203B2B8->unk14);
            FillInventoryGaps();
            gUnknown_203B2B8->unk14.itemIndex = 0;
            gUnknown_203B2B8->unk14.numItems = 0;
            GivePokemonItem(gUnknown_203B2B8->pokeSpecies, &gUnknown_203B2B8->unk14);
            sub_8026074(0xA);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(gUnknown_203B2B8->unk14.itemIndex))
            {
                gTeamInventory_203B460->teamStorage[gUnknown_203B2B8->unk14.itemIndex] += gUnknown_203B2B8->unk14.numItems;
            }
            else
            {
                gTeamInventory_203B460->teamStorage[gUnknown_203B2B8->unk14.itemIndex] += 1;
            }

            gUnknown_203B2B8->unk14.itemIndex = 0;
            gUnknown_203B2B8->unk14.numItems = 0;
            GivePokemonItem(gUnknown_203B2B8->pokeSpecies, &gUnknown_203B2B8->unk14);
            sub_8026074(0xB);
            break;
        case 0:
        default:
            sub_8026074(0x19);
            break;
    }
}
