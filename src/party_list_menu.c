#include "global.h"
#include "constants/dungeon.h"
#include "item.h"
#include "input.h"
#include "menu.h"
#include "memory.h"
#include "pokemon.h"
#include "text.h"
#include "team_inventory.h"
#include "constants/move.h"
#include "code_800D090.h"
#include "menu_input.h"
#include "moves.h"

struct unkStruct_203B2B8
{
    // size: 0x280
    s32 state;
    s32 fallbackState;
    bool8 unk8;
    /* 0xA */ s16 pokeSpecies;
    u32 id;
    /* 0x10 */ struct BulkItem item1;
    /* 0x14 */ struct BulkItem item2;
    struct PokemonStruct *pokeStruct;
    bool8 isTeamLeader;
    u32 moveIndex;
    /* 0x24 */ u16 moveID;
    struct Move moves[8];
    u16 moveIDs[4];   // some list of move IDs
    u32 menuAction1;
    u32 menuAction2;
    u32 menuAction3; // unused
    struct MenuStruct unk7C;
    struct MenuStruct unkCC;
    struct MenuStruct unk11C; // unused
    struct MenuItem unk16C[10];
    struct MenuItem unk1BC[10];
    u16 unk20C[10];
    struct UnkTextStruct2 unk220[4];
};
EWRAM_DATA_2 struct unkStruct_203B2B8 *gUnknown_203B2B8 = {0};

const struct UnkTextStruct2 gUnknown_80DD310 = {
        0x00, 0x00, 0x00, 0x00,
        0x03,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00,
        0x00, 0x00,
        NULL
};

const struct UnkTextStruct2 gUnknown_80DD328 = {
        0x00, 0x00, 0x00, 0x00,
        0x03,
        0x13, 0x00, 0x03, 0x00,
        0x08, 0x03,
        0x03, 0x00,
        NULL
};

const struct UnkTextStruct2 gUnknown_80DD340 = {
        0x00, 0x00, 0x00, 0x00,
        0x03,
        0x14, 0x00, 0x04, 0x00,
        0x06, 0x03,
        0x03, 0x00,
        NULL
};

const struct UnkTextStruct2 gUnknown_80DD358 = {
        0x00, 0x00, 0x00, 0x00,
        0x03,
        0x02, 0x00, 0x11, 0x00,
        0x1A, 0x02,
        0x02, 0x00,
        NULL
};

const struct UnkTextStruct2 gUnknown_80DD370 = {
        0x00, 0x00, 0x00, 0x00,
        0x03,
        0x02, 0x00, 0x03, 0x00,
        0x0F, 0x02,
        0x02, 0x00,
        NULL
};

extern u8 gAvailablePokemonNames[0x58];
extern u8 gUnknown_202DEA8[0x58];
extern u8 gUnknown_202DE58[0x58];

extern u8 *gUnknown_80D4920[];
extern u8 *gUnknown_80D4928[];
extern u8 *gUnknown_80D4970[];
extern u8 *gUnknown_80D4970[];

ALIGNED(4) const u8 gUnknown_80DD388[] = _(
	"You have chosen to say farewell\n"
	"to this Pokémon.{EXTRA_MSG}"
	"The Pokémon will leave its Friend Area.\n"
	"It will no longer be available for\n"
	"adventures. Is that OK?");

ALIGNED(4) const u8 gUnknown_80DD420[] = _(
	"If you say farewell to this\n"
	"Pokémon{COMMA} it will be gone forever.{EXTRA_MSG}"
	"You will never be able to get another one\n"
	"like it to join your team.\n"
	"Will you release it anyway?");

ALIGNED(4) const u8 gUnknown_80DD4C4[] = _(
	"{CENTER_ALIGN}{ARG_POKEMON_1} joined the\n"
	"{CENTER_ALIGN}rescue team for adventures!");

ALIGNED(4) const u8 gUnknown_80DD4F4[] = _(
	"{CENTER_ALIGN}{ARG_POKEMON_1} left the team to remain\n"
	"{CENTER_ALIGN}on standby in the Friend Area.");

ALIGNED(4) const u8 gBecameLeader[] = _(
	"{CENTER_ALIGN}{ARG_POKEMON_1} became the leader\n"
	"{CENTER_ALIGN}of the rescue team.");

ALIGNED(4) const u8 gUnknown_80DD564[] = _(
	"{CENTER_ALIGN}{ARG_POKEMON_1} left\n"
	"{CENTER_ALIGN}the Friend Area.\n"
	"{CENTER_ALIGN}Bye-bye{COMMA} {ARG_POKEMON_1}!");

ALIGNED(4) const u8 gUnknown_80DD594[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}handed over. ");

ALIGNED(4) const u8 gUnknown_80DD5B8[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_1}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}handed over.{EXTRA_MSG}"
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) const u8 gUnknown_80DD60C[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}returned to the Toolbox.");

ALIGNED(4) const u8 gUnknown_80DD63C[] = _(
	"{CENTER_ALIGN}The {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} was\n"
	"{CENTER_ALIGN}sent to storage.");

ALIGNED(4) const u8 gPartyMenuStandBy[] = "Stand By";
ALIGNED(4) const u8 gPartyMenuMakeLeader[] = "Make Leader";
ALIGNED(4) const u8 gPartyMenuJoinTeam[] = "Join Team";
ALIGNED(4) const u8 gPartyMenuGiveGummi[] = "Give Gummi";
ALIGNED(4) const u8 gPartyMenuGive[] = "Give";
ALIGNED(4) const u8 gPartyMenuTake[] = "Take";
ALIGNED(4) const u8 gPartyMenuSayFarewell[] = "Say Farewell";
ALIGNED(4) const u8 gPartyMenuSummary[] = "Summary";
ALIGNED(4) const u8 gPartyMenuMoves[] = "Moves";
ALIGNED(4) const u8 gPartyMenuCheckIQ[] = "Check IQ";
ALIGNED(4) const u8 gPartyMenuItemPlaceholder[] = _("Item: {COLOR_1 GREEN}{ARG_MOVE_ITEM_0}{END_COLOR_TEXT_1} ");
ALIGNED(4) const u8 gUnknown_80DD6E0[] = "%s";
ALIGNED(4) static const u8 fill0[] = "pksdir0";

extern u32 sub_8026F04(struct PokemonStruct *);
extern void sub_8026074(s32);
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
extern void xxx_format_and_draw(s32, s32, const u8 *, ...);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
extern void nullsub_104(void);
extern void sub_801A928(void);
extern void sub_8099690(u32);
extern u32 sub_801A6E8(u32);
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
bool8 sub_8026E88(struct PokemonStruct *r0);
bool8 HasGummiItem();
bool8 sub_8026EB8(struct PokemonStruct *r0);
extern void sub_801BB20(void);
extern void sub_801A8D0(u32);
extern void sub_801A9E0(void);
extern void sub_801BC24(void);
extern void sub_801A5D8(u32, u32, u32, u32);
extern void sub_8024458(s16, u32);
void sub_8026E08(u32 r0);
void sub_8026DAC(u32 r0, struct BulkItem *item);
bool8 sub_801BEEC(s16 species);
void sub_8026FA4(void);
void sub_8026878(void);
extern void sub_801F808(u16*);
extern void sub_80227B8(struct PokemonStruct *);
extern void sub_801B3C0(struct Item *);
extern void sub_801EE10(u32, s16, struct Move *, u32, u32, u32);
extern void sub_801F1B0(u32, u32);
extern void sub_8014248(const char *r0, u32, u32, const struct MenuItem *r4, u32, u32, u32, void *r5, u32);
extern void sub_80141B4(const u8 *, u32, u32 *, u32);
extern void sub_808D31C(struct PokemonStruct *);

void sub_802678C(void);
void sub_80264CC(void);
void sub_802608C(void);
void sub_80261D0(void);

void sub_80268CC(void);
void sub_8026A78(void);
void sub_8026A94(void);
void sub_8026AB0(void);
void sub_8026B10(void);
void sub_8026B48(void);
void sub_8026B64(void);
void sub_8026C14(void);
void sub_8026CF0(void);
void sub_8026D0C(void);
void sub_8026D6C(void);
void sub_8026D88(void);

u32 sub_8025EF4(struct PokemonStruct *pokeStruct)
{
    s32 index;
    gUnknown_203B2B8 = MemoryAlloc(sizeof(struct unkStruct_203B2B8), 0x8);
    gUnknown_203B2B8->pokeStruct = pokeStruct;

    for(index = 0; index < NUM_MONSTERS; index++)
    {
        if(gUnknown_203B2B8->pokeStruct == &gRecruitedPokemonRef->pokemon[(s16)index])
        {
            gUnknown_203B2B8->pokeSpecies = index;
            break;
        }
    }
    
    gUnknown_203B2B8->menuAction1 = 0;
    gUnknown_203B2B8->menuAction2 = 0;
    gUnknown_203B2B8->menuAction3 = 0;
    gUnknown_203B2B8->unk8 = FALSE;
    sub_8026074(0);
    return 1;
}

u32 sub_8025F68(void)
{
    switch(gUnknown_203B2B8->state)
    {
        case 0:
            sub_8026074(1);
            break;
        case 1:
        case 2:
            sub_80268CC();
            break;
        case 3:
            sub_8026A78();
            break;
        case 4:
            sub_8026A94();
            break;
        case 0xc:
            sub_8026AB0();
            break;
        case 0xd:
            sub_8026B10();
            break;
        case 0xe:
            sub_8026B48();
            break;
        case 0x12:
        case 0x13:
            sub_8026B64();
            break;
        case 0x14:
            sub_8026C14();
            break;
        case 0x15:
            sub_8026CF0();
            break;
        case 0x16:
        case 0x17:
            sub_8026D0C();
            break;
        case 0x18:
            sub_8026D6C();
            break;
        default:
            sub_8026D88();
            break;
        case 0x19:
            return 3;
    }
    return 0;
}

bool8 sub_802604C(void)
{
    return gUnknown_203B2B8->unk8;
}

void sub_8026058(void)
{
    if(gUnknown_203B2B8)
    {
        MemoryFree(gUnknown_203B2B8);
        gUnknown_203B2B8 = NULL;
    }
}

void sub_8026074(s32 newState)
{
    gUnknown_203B2B8->state = newState;
    sub_802608C();
    sub_80261D0();
}

void sub_802608C(void)
{
    s32 index;
    sub_8006518(gUnknown_203B2B8->unk220);
    switch(gUnknown_203B2B8->state)
    {
        case 1:
        case 2:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B2B8->unk220[index] = gUnknown_80DD310;
            }
            gUnknown_203B2B8->unk220[0] = gUnknown_80DD358;
            gUnknown_203B2B8->unk220[3] = gUnknown_80DD370;
            sub_80264CC();
            gUnknown_203B2B8->unk220[2] = gUnknown_80DD328;
            sub_8012CAC(&gUnknown_203B2B8->unk220[2], gUnknown_203B2B8->unk16C);
            gUnknown_203B2B8->unk220[2].unkC = 9;
            break;
        case 0x14:
            sub_802678C();
            gUnknown_203B2B8->unk220[2] = gUnknown_80DD340;
            sub_8012CAC(&gUnknown_203B2B8->unk220[2], gUnknown_203B2B8->unk16C);
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B2B8->unk220[index] = gUnknown_80DD310;
            }
            break; 
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2B8->unk220, 1, 1);
}

void sub_80261D0(void)
{
    struct Item item;

    switch(gUnknown_203B2B8->state) {
        case 1:
            sub_8026E08(3);
            sub_8026DAC(0,&gUnknown_203B2B8->item2);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames,gUnknown_203B2B8->pokeStruct,7);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 0x50,gUnknown_203B2B8->pokeStruct,6);
            sub_8012D60(&gUnknown_203B2B8->unk7C,gUnknown_203B2B8->unk16C,0,gUnknown_203B2B8->unk20C,gUnknown_203B2B8->menuAction1,2);
            break;
        case 2:
            sub_8026E08(3);
            sub_8026DAC(0,&gUnknown_203B2B8->item2);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames,gUnknown_203B2B8->pokeStruct,7);
            PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 0x50,gUnknown_203B2B8->pokeStruct,6);
            sub_8012EA4(&gUnknown_203B2B8->unk7C,1);
            break;
        case 3:
            sub_8024458(gUnknown_203B2B8->pokeSpecies,2);
            break;
        case 4:
            sub_801BEEC(gUnknown_203B2B8->pokeSpecies);
            break;
        case 0xe:
            sub_80227B8(gUnknown_203B2B8->pokeStruct);
            break;
        case 0x12:
            sub_801A5D8(1,0,0,10);
            break;
        case 0x13:
            sub_801A8D0(1);
            break;
        case 0x14:
            sub_801A9E0();
            sub_8012D60(&gUnknown_203B2B8->unkCC,gUnknown_203B2B8->unk16C,0,gUnknown_203B2B8->unk20C,gUnknown_203B2B8->menuAction2,2);
            break;
        case 0x15:
            HeldItemToSlot(&item,&gUnknown_203B2B8->item1);
            sub_801B3C0(&item);
            break;
        case 0x16:
            unk_CopyMoves4To8(gUnknown_203B2B8->moves,gUnknown_203B2B8->pokeStruct->moves);
            sub_801EE10(3,gUnknown_203B2B8->pokeSpecies,gUnknown_203B2B8->moves,0,0,0);
            break;
        case 0x17:
            sub_801F1B0(1,0);
            break;
        case 0xc:
            sub_8026878();
            sub_8014248(gUnknown_80DD388,0,3,gUnknown_203B2B8->unk1BC,0,4,0,0,0x101);
            break;
        case 0xd:
            sub_8026878();
            sub_8014248(gUnknown_80DD420,0,3,gUnknown_203B2B8->unk1BC,0,4,0,0,0x101);
            break;
        case 0x18:
            GetLinkedSequence(gUnknown_203B2B8->moveIndex, gUnknown_203B2B8->moves,gUnknown_203B2B8->moveIDs);
            sub_801F808(gUnknown_203B2B8->moveIDs);
            break;
        case 5:
            gUnknown_203B2B8->fallbackState = 0x19;
            PlaySound(0xcf);
            sub_80141B4(gUnknown_80DD4C4,0,0,0x101);
            break;
        case 6:
            gUnknown_203B2B8->fallbackState = 0x19;
            PlaySound(0xcf);
            sub_80141B4(gUnknown_80DD4F4,0,0,0x101);
            break;
        case 7:
            gUnknown_203B2B8->fallbackState = 0x19;
            PlaySound(0xcc);
            sub_80141B4(gBecameLeader,0,0,0x101);
            break;
        case 8:
            gUnknown_203B2B8->fallbackState = 9;
            PlaySound(0xca);
            sub_80141B4(gUnknown_80DD564,0,0,0x101);
            break;
        case 9:
            sub_8026FA4();
            sub_808D31C(gUnknown_203B2B8->pokeStruct);
            gUnknown_203B2B8->unk8 = TRUE;
            break;
        case 0xf:
            gUnknown_203B2B8->fallbackState = 2;
            sub_80141B4(gUnknown_80DD594,0,0,0x101);
            break;
        case 0x10:
            gUnknown_203B2B8->fallbackState = 2;
            sub_80141B4(gUnknown_80DD5B8,0,0,0x101);
            break;
        case 0x11:
            gUnknown_203B2B8->fallbackState = 2;
            sub_80141B4(gUnknown_80DD60C,0,0,0x101);
            break;
        case 10:
            gUnknown_203B2B8->fallbackState = 0x19;
            sub_80141B4(gUnknown_80DD60C,0,0,0x101);
            break;
        case 0xb:
            gUnknown_203B2B8->fallbackState = 0x19;
            sub_80141B4(gUnknown_80DD63C,0,0,0x101);
            break;
        case 0:
        case 0x19:
            break;
    }
}

void sub_80264CC(void) {
    struct PokemonStruct *pokeStruct;
    s32 index;
    s32 one;
    u16 temp;
    s32 loopMax = 0;
    pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B8->pokeSpecies];
    MemoryFill16(gUnknown_203B2B8->unk20C, 0, sizeof(gUnknown_203B2B8->unk20C));
    gUnknown_203B2B8->isTeamLeader = gUnknown_203B2B8->pokeStruct->isTeamLeader;

    PeekPokemonItem(gUnknown_203B2B8->pokeSpecies, &gUnknown_203B2B8->item2);

    if(temp = pokeStruct->unk0 >> 1, one = 1, temp & one)
    {
        gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuStandBy;
        gUnknown_203B2B8->unk16C[loopMax].menuAction = 7;
        if(!sub_8026E88(pokeStruct))
        {
            gUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;

        if(sub_80023E4(8) && !pokeStruct->isTeamLeader)
        {
            gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuMakeLeader;
            gUnknown_203B2B8->unk16C[loopMax].menuAction = 8;
            loopMax += 1;
        }
    }
    else
    {
        gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuJoinTeam;
        gUnknown_203B2B8->unk16C[loopMax].menuAction = 6;
        if(!sub_808D750(gUnknown_203B2B8->pokeSpecies))
        {
            gUnknown_203B2B8->unk20C[loopMax] = 1;
        }
        loopMax += 1;
    }
    
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuGiveGummi;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 10;
    if(!HasGummiItem())
    {
        gUnknown_203B2B8->unk20C[loopMax] = 1;
    }
    loopMax += 1;
    
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuGive;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 0xB;
    if(GetNumberOfFilledInventorySlots() == 0)
    {
        gUnknown_203B2B8->unk20C[loopMax] = 1; 
    }
    loopMax += 1;
    
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuTake;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 0xC;
    if(GetNumberOfFilledInventorySlots() >= INVENTORY_SIZE || gUnknown_203B2B8->item2.id == ITEM_NOTHING)
    {
        gUnknown_203B2B8->unk20C[loopMax] = 1; 
    }
    loopMax += 1;

    if((temp = pokeStruct->unk0 >> 1, one = 1, temp & one) == 0)
    {
        gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuSayFarewell;
        gUnknown_203B2B8->unk16C[loopMax].menuAction = 9;
        if(!sub_8026EB8(pokeStruct))
        {
            gUnknown_203B2B8->unk20C[loopMax] = 1; 
        }
        loopMax += 1;
    }
    
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuSummary;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuMoves;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 0xD;
    loopMax += 1;
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuCheckIQ;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2B8->unk16C[loopMax].text = NULL;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B8->unk20C[index] == 0)
        {
            if(gUnknown_203B2B8->unk16C[index].menuAction == gUnknown_203B2B8->menuAction1)
                return;
        }
    }
    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B8->unk20C[index] == 0)
        {
            gUnknown_203B2B8->menuAction1 = gUnknown_203B2B8->unk16C[index].menuAction;
            break;
        }
    }
}

void sub_802678C(void)
{
    s32 index;
    s32 loopMax = 0;
    MemoryFill16(gUnknown_203B2B8->unk20C, 0, sizeof(gUnknown_203B2B8->unk20C));
    gUnknown_203B2B8->unk16C[loopMax].text = gPartyMenuGive;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 0xB;
    if(GetNumberOfFilledInventorySlots() == 0)
    {
        gUnknown_203B2B8->unk20C[0] = 1;
    }
    loopMax += 1;
    gUnknown_203B2B8->unk16C[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2B8->unk16C[loopMax].text = NULL;
    gUnknown_203B2B8->unk16C[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B8->unk20C[index] == 0)
        {
            if(gUnknown_203B2B8->unk16C[index].menuAction == gUnknown_203B2B8->menuAction2)
                return;
        }
    }
    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B8->unk20C[index] == 0)
        {
            gUnknown_203B2B8->menuAction2 = gUnknown_203B2B8->unk16C[index].menuAction;
            break;
        }
    }
}

void sub_8026878(void) {
    s32 loopMax = 0;
    gUnknown_203B2B8->unk1BC[loopMax].text = *gUnknown_80D4920;
    gUnknown_203B2B8->unk1BC[loopMax].menuAction = 2;
    loopMax += 1;
    gUnknown_203B2B8->unk1BC[loopMax].text = *gUnknown_80D4928;
    gUnknown_203B2B8->unk1BC[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B2B8->unk1BC[loopMax].text = NULL;
    gUnknown_203B2B8->unk1BC[loopMax].menuAction = 1;
}

void sub_80268CC(void)
{
  struct PokemonStruct *playerPokemon;
  struct PokemonStruct *pokeStruct;
  struct PokemonStruct *pokeStruct2;
  s32 choice;
  
  choice = 0;
  if ((sub_8012FD8(&gUnknown_203B2B8->unk7C) == 0) && (sub_8013114(&gUnknown_203B2B8->unk7C,&choice), choice != 1)) {
    gUnknown_203B2B8->menuAction1 = choice;
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
        gUnknown_203B2B8->pokeStruct->unk0 &= 0xfffd;
        nullsub_104();
        sub_808ED00();
        sub_8026074(6);
        break;
    case 8:
        pokeStruct2 = &gRecruitedPokemonRef->pokemon[gUnknown_203B2B8->pokeSpecies];
        playerPokemon = GetPlayerPokemonStruct();

        if (!pokeStruct2->isTeamLeader) {
            playerPokemon->isTeamLeader = FALSE;
            pokeStruct2->isTeamLeader = TRUE;
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
    if (gUnknown_203B2B8->pokeStruct->dungeonLocation.id == DUNGEON_HOWLING_FOREST_2 || gUnknown_203B2B8->pokeStruct->dungeonLocation.id == DUNGEON_POKEMON_SQUARE)
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
    gUnknown_203B2B8->menuAction2 = menuAction;
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
    sub_80922B4(gAvailablePokemonNames, gUnknown_203B2B8->pokeStruct->name, POKEMON_NAME_LENGTH);
    sub_808D930(buffer, gUnknown_203B2B8->pokeStruct->speciesNum);
    sprintfStatic(buffer1, gUnknown_80DD6E0, gAvailablePokemonNames);
    x = sub_8008ED0(buffer1);
    xxx_call_draw_string(((gUnknown_80DD370.unkC << 3) - x) / 2, 3, buffer1, r0, 0);
    sub_80073E0(r0);
}

bool8 sub_8026E88(struct PokemonStruct *r0)
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
    if(r0->heldItem.id == ITEM_NOTHING)
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
    switch(sub_8026F04(gUnknown_203B2B8->pokeStruct))
    {
        case 1:
            PlaySound(0x14d);
            AddHeldItemToInventory(&gUnknown_203B2B8->item2);
            FillInventoryGaps();
            gUnknown_203B2B8->item2.id = ITEM_NOTHING;
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

            gUnknown_203B2B8->item2.id = ITEM_NOTHING;
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
