#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "item.h"
#include "pokemon.h"
#include "team_inventory.h"
#include "friend_area_action_menu.h"
#include "menu_input.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;

extern void sub_80141B4(const char *r0, u32, u32 *r1, u32);
extern void sub_8014248(const char *r0, u32, u32, struct MenuItem *r4, u32, u32, u32, u32 *r5, u32);
extern void sub_8027D40(u32, struct BulkItem *);
extern void sub_8023868(u32, u32, u32, u32);
extern void sub_8023B7C(u32);
extern void sub_8023DA4();
extern void sub_8024458(s16, u32);
extern void sub_801BEEC(s16);
extern void GetLinkedSequence(u32, struct Move *, u16*);
extern void sub_801F808(u16*);
extern void sub_8027794();
extern void sub_801A5D8(u32, u32, u32, u32);
extern void sub_801A8D0(u32);
extern void sub_801A9E0();
extern void sub_801F1B0(u32, u32);
extern void sub_801B3C0(struct Item *);
extern void unk_CopyMoves4To8(struct Move *, struct Move *);
extern void sub_801EE10(u32, s16, struct Move *, u32, u32, u32);

extern void SetFriendAreaActionMenuState(u32);
extern void ResetSprites(u8 );
extern void sub_802719C();
extern void sub_8027274();
extern void sub_80277FC();
extern void sub_80278B4();
extern void sub_8027A40();
extern void sub_8027A5C();
extern void FriendAreaActionMenu_GotoFallbackState();
extern void sub_8027A78();
extern void sub_8027AE4();
extern void sub_8027B28();
extern void sub_8027BD8();
extern void sub_8027C84();
extern void sub_8027CA0();
extern void sub_8027D00();
extern void CreateFriendActionMenu();
extern void sub_80276A8();

const struct UnkTextStruct2 gUnknown_80DD6EC =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};


const struct UnkTextStruct2 gUnknown_80DD704 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x13, 0x04,
    0x09, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DD71C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x14, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DD734 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x16, 0x04,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80DD74C =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x02, 0x11,
    0x1A, 0x02,
    0x02, 0x00,
    NULL
};


ALIGNED(4) const u8 gFriendAreaActionSayFarewellPrompt[] = _(
         "You have chosen to say farewell\n"
         "to this Pokémon.{EXTRA_MSG}"
         "The Pokémon will leave its Friend Area.\n"
         "It will no longer be available for\n"
         "adventures. Is that OK?");

ALIGNED(4) const u8 gFriendAreaActionSayFarewellConfirm[] = _(
         "If you say farewell to this\n"
         "Pokémon{COMMA} it will be gone forever.{EXTRA_MSG}"
         "You will never be able to get another one\n"
         "like it to join your team.\n"
         "Will you release it anyway?");

ALIGNED(4) const u8 gUnknown_80DD8A0[] = _(
         "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
         "{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) const u8 gUnknown_80DD8D0[] = _(
         "{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n{CENTER_ALIGN}sent to storage.");


u32 sub_8027074(void)
{
    ResetSprites(0);
    gUnknown_203B2BC = MemoryAlloc(sizeof(struct unkStruct_203B2BC), 8);
    gUnknown_203B2BC->menuAction1 = 0;
    gUnknown_203B2BC->menuAction2 = 0;
    gUnknown_203B2BC->menuAction3 = 0;
    SetFriendAreaActionMenuState(FRIEND_AREA_ACTION_MENU_INIT);
    return 1;
}

u32 sub_80270A4(void)
{
  switch(gUnknown_203B2BC->state) {
      case FRIEND_AREA_ACTION_MENU_INIT:
        SetFriendAreaActionMenuState(1);
        break;
      case 1:
      case 2:
        sub_80277FC();
        break;
      case 3:
        sub_80278B4();
        break;
      case 4:
        sub_8027A40();
        break;
      case 5:
        sub_8027A5C();
        break;
      case 8:
        sub_8027A78();
        break;
      case 9:
        sub_8027AE4();
        break;
      case 10:
      case 0xb:
        sub_8027B28();
        break;
      case 0xc:
        sub_8027BD8();
        break;
      case 0xd:
        sub_8027C84();
        break;
      case 0xe:
      case 0xf:
        sub_8027CA0();
        break;
      case 0x10:
        sub_8027D00();
        break;
      default:
        FriendAreaActionMenu_GotoFallbackState();
        break;
      case FRIEND_AREA_ACTION_MENU_EXIT:
        return 3;
  }
  return 0;
}

void sub_8027168(void)
{
    if(gUnknown_203B2BC != NULL)
    {
        MemoryFree(gUnknown_203B2BC);
        gUnknown_203B2BC = NULL;
    }
}

void SetFriendAreaActionMenuState(u32 newState)
{
    gUnknown_203B2BC->state = newState;
    sub_802719C();
    sub_8027274();
}

void sub_802719C(void)
{
    s32 index;

    sub_8006518(gUnknown_203B2BC->unk180);
    switch(gUnknown_203B2BC->state)
    {
        case 3:
            gUnknown_203B2BC->unk180[3] = gUnknown_80DD74C;
            CreateFriendActionMenu();
            gUnknown_203B2BC->unk180[2] = gUnknown_80DD704;
            sub_8012CAC(&gUnknown_203B2BC->unk180[2], gUnknown_203B2BC->menuItems);
            break;
        case 0xC:
            sub_80276A8();
            gUnknown_203B2BC->unk180[2] = gUnknown_80DD71C;
            sub_8012CAC(&gUnknown_203B2BC->unk180[2], gUnknown_203B2BC->menuItems);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B2BC->unk180[index] = gUnknown_80DD6EC;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2BC->unk180, 1, 1);
}

void sub_8027274(void)
{
  struct Item slot;

  switch(gUnknown_203B2BC->state) {
    case FRIEND_AREA_ACTION_MENU_INIT:
    case FRIEND_AREA_ACTION_MENU_EXIT:
        break;
    case 1:
        sub_8023868(1,0,0,7);
        break;
    case 2:
        sub_8023B7C(1);
        break;
    case 3:
        sub_8027D40(3,&gUnknown_203B2BC->item2);
        sub_8023DA4();
        sub_8012D60(&gUnknown_203B2BC->unk7C,gUnknown_203B2BC->menuItems,0,gUnknown_203B2BC->unk16C,gUnknown_203B2BC->menuAction1,2);
        break;
    case 4:
        sub_8024458(gUnknown_203B2BC->targetPoke,2);
        break;
    case 5:
        sub_801BEEC(gUnknown_203B2BC->targetPoke);
        break;
    case 10:
        sub_801A5D8(1,0,0,10);
        break;
    case 0xb:
        sub_801A8D0(1);
        break;
    case 0xc:
        sub_801A9E0();
        sub_8012D60(&gUnknown_203B2BC->unk7C,gUnknown_203B2BC->menuItems,0,gUnknown_203B2BC->unk16C,gUnknown_203B2BC->menuAction2,2);
        break;
    case 0xd:
        HeldItemToSlot(&slot, &gUnknown_203B2BC->itemToGive);
        sub_801B3C0(&slot);
        break;
    case 0xe:
        unk_CopyMoves4To8(gUnknown_203B2BC->moves,gUnknown_203B2BC->pokeStruct->moves);
        sub_801EE10(3,gUnknown_203B2BC->targetPoke,gUnknown_203B2BC->moves,0,0,0);
        break;
    case 0xf:
        sub_801F1B0(1,0);
        break;
    case 8:
        sub_8027794();
        sub_8014248(gFriendAreaActionSayFarewellPrompt,0,3,gUnknown_203B2BC->menuItems,0,4,0,0,0x101);
        break;
    case 9:
        sub_8027794();
        sub_8014248(gFriendAreaActionSayFarewellConfirm,0,3,gUnknown_203B2BC->menuItems,0,4,0,0,0x101);
        break;
    case 0x10:
        GetLinkedSequence(gUnknown_203B2BC->moveIndex,gUnknown_203B2BC->moves,gUnknown_203B2BC->moveIDs);
        sub_801F808(gUnknown_203B2BC->moveIDs);
        break;
    case 6:
        gUnknown_203B2BC->fallbackState = 2;
        // The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was
        // returned to the Toolbox
        sub_80141B4(gUnknown_80DD8A0,0,0,0x101);
        break;
    case 7:
        gUnknown_203B2BC->fallbackState = 2;
        // The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was
        // returned to storage
        sub_80141B4(gUnknown_80DD8D0,0,0,0x101);
        break;
  }
}
