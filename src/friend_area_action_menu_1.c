#include "global.h"
#include "constants/dungeon.h"
#include "memory.h"
#include "text2.h"
#include "item.h"
#include "team_inventory.h"
#include "pokemon.h"
#include "friend_area_action_menu.h"
#include "menu_input.h"
#include "kecleon_bros.h"
#include "code_80130A8.h"
#include "code_801EE10_1.h"
#include "code_801B3C0.h"
#include "code_80118A4.h"
#include "event_flag.h"

extern struct unkStruct_203B2BC *gUnknown_203B2BC;
extern struct TeamInventory *gTeamInventoryRef;

extern u32 sub_801EF38(u8 r0);
extern void sub_801F214();

extern void SetFriendAreaActionMenuState(u32);
extern void nullsub_104();
extern void sub_8099690(u32);

extern void sub_8027EB8();
extern void sub_808D31C(struct PokemonStruct *);
extern struct PokemonStruct *sub_808D3F8(void);
extern struct PokemonStruct *sub_808D3BC(void);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u8 gUnknown_202DE58[];
extern u32 sub_801F194(void);

u32 sub_8027E18(struct PokemonStruct *);
u8 sub_8027E4C(struct PokemonStruct *r0);

extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern u32 sub_80244E4(void);
extern void sub_802453C(void);

extern bool8 sub_808D750(s16 index_);
extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void sub_808ED00();

ALIGNED(4) const u8 gFriendActionStandby[] = "Stand By";
ALIGNED(4) const u8 gFriendActionMakeLeader[] = "Make Leader";
ALIGNED(4) const u8 gFriendActionJoinTeam[] = "Join Team";
ALIGNED(4) const u8 gFriendActionSayFarewell[] = "Say Farewell";
ALIGNED(4) const u8 gFriendActionGive[] = "Give";
ALIGNED(4) const u8 gFriendActionTake[] = "Take";
ALIGNED(4) const u8 gFriendActionSummary[] = "Summary";
ALIGNED(4) const u8 gFriendActionMoves[] = "Moves";
ALIGNED(4) const u8 gFriendActionCheckIQ[] = "Check IQ";

ALIGNED(4) const u8 gUnknown_80DD958[] = _("Item: {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} ");
static const u8 filler[] = "pksdir0";
