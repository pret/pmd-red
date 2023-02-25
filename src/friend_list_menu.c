#include "global.h"
#include "constants/dungeon.h"
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
    u32 fallbackState;
    u8 unk8;
    /* 0xA */ s16 pokeSpecies;
    u32 id;
    /* 0x10 */ struct BulkItem item1;
    /* 0x14 */ struct BulkItem item2;
    struct PokemonStruct *unk18;
    bool8 isTeamLeader;
    u32 moveIndex;
    /* 0x24 */ u16 moveID;
    struct Move moves[8];
    u16 moveIDs[4];   // some list of move IDs
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
bool8 CanTakePokemonHeldItem(struct PokemonStruct *r0);
extern bool8 sub_80023E4(u8);
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
extern bool8 sub_808D750(s16 index_);
extern void sub_808ED00(void);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);

void sub_80268CC(void)
{
  struct PokemonStruct *playerPokemon;
  struct PokemonStruct *pokeStruct;
  struct PokemonStruct *iVar4;
  s32 choice;
  
  choice = 0;
  if ((sub_8012FD8(&gUnknown_203B2B8->unk7C) == 0) && (sub_8013114(&gUnknown_203B2B8->unk7C,&choice), choice != 1)) {
    gUnknown_203B2B8->unk70 = choice;
  }
  switch(choice) {
    case 6:
        if (sub_808D750(gUnknown_203B2B8->pokeSpecies)) {

#ifdef NONMATCHING
            pokeStruct = &gUnknown_203B2B8->pokeSpecies[gRecruitedPokemonRef->pokemon];
#else
            register size_t offset asm("r1") = offsetof(struct unkStruct_203B45C, pokemon[gUnknown_203B2B8->pokeSpecies]);
            struct PokemonStruct* p = gRecruitedPokemonRef->pokemon;
            size_t addr = offset + (size_t)p;
            pokeStruct = (struct PokemonStruct*)addr;
#endif

            pokeStruct->unk0 |= 2;
            nullsub_104();
        }
        sub_808ED00();
        sub_8026074(5);
        break;
    case 7:
        gUnknown_203B2B8->unk18->unk0 &= 0xfffd;
        nullsub_104();
        sub_808ED00();
        sub_8026074(6);
        break;
    case 8:
        iVar4 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B8->pokeSpecies];
        playerPokemon = GetPlayerPokemonStruct();

        if (!iVar4->isTeamLeader) {
            playerPokemon->isTeamLeader = FALSE;
            iVar4->isTeamLeader = TRUE;
            nullsub_104();
        }
        sub_808ED00();
        sub_8026074(7);
        break;
    case 9:
        sub_8026074(0xc);
        break;
    case 0xd:
        sub_8026074(0x16);
        break;
    case 10:
        sub_8026074(0xe);
        break;
    case 0xb:
        sub_8026074(0x12);
        break;
    case 0xc:
        PlaySound(0x14d);
        if (gUnknown_203B2B8->item2.id != ITEM_NOTHING) {
            AddHeldItemToInventory(&gUnknown_203B2B8->item2);
        }
        FillInventoryGaps();
        gUnknown_203B2B8->item2.id = ITEM_NOTHING;
        gUnknown_203B2B8->item2.quantity = 0;
        GivePokemonItem(gUnknown_203B2B8->pokeSpecies,&gUnknown_203B2B8->item2);
        nullsub_104();
        sub_8026074(0x11);
        break;
    case 4:
        sub_8026074(3);
        break;
    case 5:
        sub_8026074(4);
        break;
    case 1:
        sub_8026074(0x19);
        break;

  }
}

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
    if (gUnknown_203B2B8->unk18->dungeonLocation.id == 0x44 || gUnknown_203B2B8->unk18->dungeonLocation.id == 0x45)
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
            gUnknown_203B2B8->id = sub_801A8AC();
            gUnknown_203B2B8->item1.id = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->id].id;
            gUnknown_203B2B8->item1.quantity = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->id].quantity;
            sub_8026074(0x14);
            break;
        case 4:
            gUnknown_203B2B8->id = sub_801A8AC();
            gUnknown_203B2B8->item1.id = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->id].id;
            gUnknown_203B2B8->item1.quantity = gTeamInventory_203B460->teamItems[gUnknown_203B2B8->id].quantity;
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
  struct Item slot;

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
        ShiftItemsDownFrom(gUnknown_203B2B8->id);
        FillInventoryGaps();
        if (gUnknown_203B2B8->item2.id != ITEM_NOTHING) {
          AddHeldItemToInventory(&gUnknown_203B2B8->item2);
          nextState = 0x10;
        }
        HeldItemToSlot(&slot,&gUnknown_203B2B8->item1);
        temp.unk0 = 0;
        temp.unk4 = 0;
        temp.unk8 = 1;
        slot.flags = ITEM_FLAG_EXISTS;
        sub_8090E14(gUnknown_202DEA8,&slot,&temp);
        GivePokemonItem(gUnknown_203B2B8->pokeSpecies,&gUnknown_203B2B8->item1);
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
            gUnknown_203B2B8->moveIndex = sub_801F194();
            gUnknown_203B2B8->moveID = gUnknown_203B2B8->moves[gUnknown_203B2B8->moveIndex].id;
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
        sub_8026074(gUnknown_203B2B8->fallbackState);
    }
}

void sub_8026DAC(u32 r0, struct BulkItem *item)
{
    struct Item slot;
    struct unkStruct_8090F58 temp;

    sub_8008C54(r0);
    sub_80073B8(r0);
    HeldItemToSlot(&slot, item);
    temp.unk0 = 0;
    temp.unk4 = 0;
    temp.unk8 = 1;
    slot.flags = ITEM_FLAG_EXISTS;
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
    sprintfStatic(buffer1, gUnknown_80DD6E0, gAvailablePokemonNames);
    x = sub_8008ED0(buffer1);
    xxx_call_draw_string(((gUnknown_80DD370.unkC << 3) - x) / 2, 3, buffer1, r0, 0);
    sub_80073E0(r0);
}

u32 sub_8026E88(struct PokemonStruct *r0)
{
    bool8 flag;
    if(!r0->isTeamLeader)
    {
        flag = (r0->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER);
        if(flag)
            if(!sub_80023E4(0x8))
                return FALSE;
    }
    else
        return FALSE;
    return TRUE;
}

bool8 sub_8026EB8(struct PokemonStruct *r0)
{
    bool8 flag;
    if(sub_808D3BC() != r0)
        if(sub_808D3F8() != r0)
            if(!r0->isTeamLeader)
            {
                flag = (r0->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER);
                if(flag)
                {
                    if(sub_80023E4(0x8))
                        goto check;
                }
                else
                    check:
                    if(sub_8026F04(r0) != 3)
                        return TRUE;
            }
    return FALSE;
}


u32 sub_8026F04(struct PokemonStruct *r0)
{
    if(r0->heldItem.id == 0)
        return 0;
    else if(GetNumberOfFilledInventorySlots() < INVENTORY_SIZE)
        return 1;
    else if(CanTakePokemonHeldItem(r0))
        return 2;
    else
        return 3;
}

bool8 CanTakePokemonHeldItem(struct PokemonStruct *r0)
{
    if(IsNotMoneyOrUsedTMItem(r0->heldItem.id))
    {
        if(IsThrowableItem(r0->heldItem.id))
        {
            if((gTeamInventory_203B460->teamStorage[r0->heldItem.id] + r0->heldItem.quantity) > 999)
                return FALSE;
        }
        else
        {
            if(gTeamInventory_203B460->teamStorage[r0->heldItem.id] > 998)
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
            AddHeldItemToInventory(&gUnknown_203B2B8->item2);
            FillInventoryGaps();
            gUnknown_203B2B8->item2.id = 0;
            gUnknown_203B2B8->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2B8->pokeSpecies, &gUnknown_203B2B8->item2);
            sub_8026074(0xA);
            break;
        case 2:
            PlaySound(0x14d);
            if(IsThrowableItem(gUnknown_203B2B8->item2.id))
            {
                gTeamInventory_203B460->teamStorage[gUnknown_203B2B8->item2.id] += gUnknown_203B2B8->item2.quantity;
            }
            else
            {
                gTeamInventory_203B460->teamStorage[gUnknown_203B2B8->item2.id] += 1;
            }

            gUnknown_203B2B8->item2.id = 0;
            gUnknown_203B2B8->item2.quantity = 0;
            GivePokemonItem(gUnknown_203B2B8->pokeSpecies, &gUnknown_203B2B8->item2);
            sub_8026074(0xB);
            break;
        case 0:
        default:
            sub_8026074(0x19);
            break;
    }
}
