#include "global.h"
#include "constants/bg_music.h"
#include "constants/colors.h"
#include "input.h"
#include "item.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "random.h"
#include "text.h"
#include "text_util.h"
#include "team_inventory.h"
#include "menu_input.h"

struct unkStruct_203B2B0
{
    // size: 0x174
    bool8 evolutionComplete;
    u8 fill1[0x3];
    u8 evoItem1_itemIndex;
    u8 evoItem2_ItemIndex;
    u8 unk6;
    u16 evolutionConditionStatus;
    /* 0xA */ s16 targetSpecies; // species # of the evolved pokemon (what we are evolving to)
    struct PokemonStruct *pokeStruct;
    /* 0x10 */ bool8 pokeRenamed;
    /* 0x14 */ u32 evoItem1_InvIndex; // inventory index of item
    /* 0x18 */ u32 evoItem2_InvIndex; // inventory index of item
    struct Item chosenItem;
    u32 state;
    u32 fallbackState;
    u32 menuAction1;
    u32 menuAction2;
    u32 menuAction3;
    struct MenuItem unk34[8];
    u16 unk74[0x8];
    struct MenuStruct unk84;
    u8 fillD4[0x104 - 0xD4];
    struct OpenedFile *unk104;
    u8 *unk108;
    u16 unk10C;
    u16 unk10E;
    u8 unk110;
    u8 unk111;
    u8 unk112;
    struct UnkTextStruct2 unk114[4];
};

EWRAM_DATA_2 struct unkStruct_203B2B0 *gUnknown_203B2B0 = {0};
extern struct UnkTextStruct2 gUnknown_80DCA00;
extern struct UnkTextStruct2 gUnknown_80DC9E8;
extern u8 gPlayerName[];
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DFE8[];

extern u8 *gUnknown_80D4970[];
extern u8 *gUnknown_80D4934[];

extern u8 gUnknown_80DCA18[];
extern u8 gUnknown_80DCA24[];
extern u8 gUnknown_80DCA2C[];

ALIGNED(4) const u8 gLuminousCaveSeekAwakening[] = _(
	 "{CENTER_ALIGN}...{WAIT_PRESS}A voice emanates from somewhere...{EXTRA_MSG}"
	 "{CENTER_ALIGN}...Ye who seek awakening...{EXTRA_MSG}"
	 "{CENTER_ALIGN}This is Luminous Cave.{WAIT_PRESS}\n"
	 "{CENTER_ALIGN}Do ye seek a new evolution?");

ALIGNED(4) const u8 gLuminousCaveAskEvolution[] = _(
	 "{CENTER_ALIGN}Do ye seek evolution?");

ALIGNED(4) const u8 gLuminousCaveEvolutionInfo[] = _(
	 "{CENTER_ALIGN}There are those among Pokémon\n"
	 "{CENTER_ALIGN}that can evolve.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Such Pokémon can evolve at this very\n"
	 "{CENTER_ALIGN}spot if they satisfy certain conditions.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Evolution brings about changes\n"
	 "{CENTER_ALIGN}in appearance and abilities.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Not only that{COMMA} some Pokémon even change\n"
	 "{CENTER_ALIGN}type and learn different moves.{EXTRA_MSG}"
	 "{CENTER_ALIGN}However...{WAIT_PRESS} The requirements for\n"
	 "{CENTER_ALIGN}evolution differ among Pokémon.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Some become ready for evolution\n"
	 "{CENTER_ALIGN}merely by leveling up.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Still others may need special items\n"
	 "{CENTER_ALIGN}to attain evolution.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye must also be aware of this:{EXTRA_MSG}"
	 "{CENTER_ALIGN}Once it has evolved{COMMA} a Pokémon\n"
	 "{CENTER_ALIGN}can never regain its previous form.{EXTRA_MSG}"
	 "{CENTER_ALIGN}That is why ye must think carefully\n"
	 "{CENTER_ALIGN}before committing to evolution.");

ALIGNED(4) const u8 gLuminousCaveYeShallReturn[] = _(
	 "{CENTER_ALIGN}Ye shall return if evolution\n"
	 "{CENTER_ALIGN}is what ye seek...");

ALIGNED(4) const u8 gLuminousCaveGiveItem[] = _(
	 "{CENTER_ALIGN}Will ye give an item for evolution?");

ALIGNED(4) const u8 gLuminousCaveGiveAnotherItem[] = _(
	 "{CENTER_ALIGN}Will ye give yet another item?");

ALIGNED(4) const u8 gLuminousCaveLackWhatIsNeeded[] = _(
	 "{CENTER_ALIGN}Alas{COMMA} ye seem to lack what is needed\n"
	 "{CENTER_ALIGN}for evolution.");

ALIGNED(4) const u8 gLuminousCaveOnlyOneItem[] = _(
	 "{CENTER_ALIGN}Ye seem to have but one item.");

ALIGNED(4) const u8 gLuminousCaveLetUsBegin[] = _(
	 "{CENTER_ALIGN}...Ye who seek awakening...\n"
	 "{CENTER_ALIGN}Let us begin.");

ALIGNED(4) const u8 gLuminousCaveChangedAppearance[] = _(
	 "{CENTER_ALIGN}...{WAIT_PRESS}$n0 is undergoing changes...{EXTRA_MSG}"
	 "{CENTER_ALIGN}$n0{APOSTROPHE}s appearance changed...{EXTRA_MSG}");

ALIGNED(4) const u8 gLuminousCaveEvolved[] = _(
	 "{CENTER_ALIGN}It evolved from {COLOR_1 GREEN}{ARG_POKEMON_0}{END_COLOR_TEXT_1}\n"
	 "{CENTER_ALIGN}to {COLOR_1 YELLOW}{ARG_POKEMON_1}{END_COLOR_TEXT_1}!");

ALIGNED(4) const u8 gLuminousCaveComeAlone[] = _(
	 "{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}One cannot evolve if one\n"
	 "{CENTER_ALIGN}is in the company of others.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Come alone if ye wish to evolve.");

ALIGNED(4) const u8 gLuminousCaveLackLevel[] = _(
	 "{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye have not high enough a level.");

ALIGNED(4) const u8 gLuminousCaveCantEvolveAnymore[] = _(
	 "{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve anymore.");

ALIGNED(4) const u8 gLuminousCaveLackFriendArea[] = _(
	 "{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye need your Friend Area to evolve.");

ALIGNED(4) const u8 gLuminousCaveLackRoom[] = _(
	 "{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
	 "{CENTER_ALIGN}The Friend Area to which ye shall go\n"
	 "{CENTER_ALIGN}has no room for ye.");

ALIGNED(4) const u8 gLuminousCaveLackIQ[] = _(
	 "{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye seem to lack the IQ to evolve.");

ALIGNED(4) const u8 gLuminousCaveLackItem[] = _(
	 "{CENTER_ALIGN}{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve yet.{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye seem to lack an item to evolve.");

ALIGNED(4) const u8 gLuminousCaveCantEvolveYet[] = _(
	 "{CENTER_ALIGN}{CENTER_ALIGN}...{EXTRA_MSG}"
	 "{CENTER_ALIGN}Ye cannot evolve yet. ");

ALIGNED(4) const u8 gLuminousCaveGiveName[] = _(
	 "{CENTER_ALIGN}Ye must give a name to\n"
	 "{CENTER_ALIGN}the evolved Pokémon. ");

ALIGNED(4) static const u8 fill0[] = "pksdir0";
ALIGNED(4) static const u8 fill1[] = "pksdir0";

extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern void UpdateLuminousCaveState(u32);

extern void sub_8024E9C(void);
extern void sub_8024F00(void);
extern void sub_8024FD4(void);
extern void sub_80250EC(void);
extern void sub_80251CC(void);
extern void sub_8024F70(void);
extern void sub_8025058(void);
extern void sub_802515C(void);
extern void sub_80251E8(void);
extern void sub_8025204(void);
extern void LuminousCave_AdvancetoFallbackState(void);
extern void sub_8024804(void);
extern void UpdateLuminousCaveDialogue(void);

extern void sub_80141B4(const char *r0, u32, struct OpenedFile **r1, u32);
extern void sub_8014248(const char *r0, u32, u32, struct MenuItem *r4, u16 *, u32, u32, struct OpenedFile **r5, u32);
void xxx_call_fade_out_bgm(u16 speed);
void xxx_call_stop_fanfare_se(u16 songIndex);
void xxx_call_fade_in_new_bgm(u16 songIndex, u16 speed);
void sub_80977D0(void);
void PlaySound(u32);
void sub_8024CFC(void);
void sub_8025254(void);
void sub_8024D48(void);
extern void sub_801A5D8(u32, u32, u32, u32);
extern void sub_801A8D0(u32);
extern void sub_801A9E0();
extern void sub_801B3C0(struct Item *);
extern void nullsub_104();
void sub_8024DBC(void);
void sub_8024E30(void);
void sub_801AEE4(u32, u32);
void sub_808F734(struct PokemonStruct *, s16);
u32 sub_801602C(u32 r0, u8 *name);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801A6E8(bool8);
extern s32 sub_801A8AC(void);
extern void sub_8099690(u32);
extern void sub_801A928(void);
extern void PlayMenuSoundEffect(u32);
extern u32 sub_801B410(void);
extern void sub_801B450(void);
extern u32 sub_8016080(void);
extern void sub_80160D8(void);
extern void sub_808F468(struct PokemonStruct *, u8 *, u32);

bool8 LuminousCave_HasOnly1Member(void);

enum
{
    LUMINOUS_CAVE_ENTRY,
    LUMINOUS_CAVE_ASK_EVOLVE,
    LUMINOUS_CAVE_EVOLVE_INFO,
    LUMINOUS_CAVE_SHALL_RETURN,
    LUMINOUS_CAVE_GIVE_ITEM_1 = 5,
    LUMINOUS_CAVE_GIVE_ITEM_2 = 10,
    LUMINOUS_CAVE_LACK_WHAT_NEEDED = 0xF,
    LUMINOUS_CAVE_ONLY_ONE_ITEM = 0x10,
    LUMINOUS_CAVE_LET_US_BEGIN = 0x11,
    LUMINOUS_CAVE_CHANGED_APPEARANCE = 0x12,
    LUMINOUS_CAVE_EVOLVED = 0x13,
    LUMINOUS_CAVE_PROMPT_NAME = 0x14,
    LUMINOUS_CAVE_FINISH_NAME = 0x15,
    LUMINOUS_CAVE_COME_ALONE = 0x16,
    LUMINOUS_CAVE_LACK_LEVEL = 0x17,
    LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE = 0x18,
    LUMINOUS_CAVE_LACK_FRIEND_AREA = 0x19,
    LUMINOUS_CAVE_LACK_ROOM = 0x1A,
    LUMINOUS_CAVE_LACK_IQ = 0x1B,
    LUMINOUS_CAVE_LACK_ITEM = 0x1C,
    LUMINOUS_CAVE_CANT_EVOLVE_YET = 0x1D,
};

enum evolutionStatus
{
    EVOLUTION_GOOD = 1,
    EVOLUTION_LACK_LEVEL = 1 << 1,
    EVOLUTION_NO_MORE = 1 << 2,
    EVOLUTION_LACK_ITEM = 1 << 3,
    EVOLUTION_LACK_IQ = 1 << 4,
    EVOLUTION_LACK_FRIEND_AREA = 1 << 5,
    EVOLUTION_LACK_ROOM = 1 << 6,
};

u32 sub_802465C(void)
{
  struct OpenedFile *faceFile;

  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  gUnknown_203B2B0 = MemoryAlloc(sizeof(struct unkStruct_203B2B0),8);
  gUnknown_203B2B0->menuAction1 = 0;
  gUnknown_203B2B0->menuAction2 = 0;
  gUnknown_203B2B0->menuAction3 = 0;
  gUnknown_203B2B0->pokeStruct = GetPlayerPokemonStruct();
  gUnknown_203B2B0->pokeRenamed = IsPokemonRenamed(gUnknown_203B2B0->pokeStruct);
  gUnknown_203B2B0->evolutionComplete = FALSE;
  faceFile = GetDialogueSpriteDataPtr(MONSTER_GULPIN);
  gUnknown_203B2B0->unk104 = faceFile;
  gUnknown_203B2B0->unk108 = faceFile->data;
  gUnknown_203B2B0->unk110 = 0;
  gUnknown_203B2B0->unk111 = 0;
  gUnknown_203B2B0->unk112 = 0;
  gUnknown_203B2B0->unk10C = 2;
  gUnknown_203B2B0->unk10E = 8;
  UpdateLuminousCaveState(LUMINOUS_CAVE_ENTRY);
  return 1;
}

u32 sub_80246F0(void)
{
  switch(gUnknown_203B2B0->state) {
    case LUMINOUS_CAVE_ENTRY:
    case LUMINOUS_CAVE_ASK_EVOLVE:
        sub_8024E9C();
        break;
    case LUMINOUS_CAVE_GIVE_ITEM_1:
        sub_8024F00();
        break;
    case 6:
    case 7:
        sub_8024FD4();
        break;
    case 8:
        sub_80250EC();
        break;
    case 9:
        sub_80251CC();
        break;
    case LUMINOUS_CAVE_GIVE_ITEM_2:
        sub_8024F70();
        break;
    case 0xb:
    case 0xc:
        sub_8025058();
        break;
    case 0xd:
        sub_802515C();
        break;
    case 0xe:
        sub_80251E8();
        break;
    case LUMINOUS_CAVE_FINISH_NAME:
        sub_8025204();
        break;
    case 4:
        return 3;
    default:
        LuminousCave_AdvancetoFallbackState();
        break;
  }
  return 0;
}

bool8 HasEvolutionCompleted(void)
{
    return gUnknown_203B2B0->evolutionComplete;
}

void CleanLuminousCave(void)
{
    if(gUnknown_203B2B0 != NULL)
    {
        CloseFile(gUnknown_203B2B0->unk104);
        MemoryFree(gUnknown_203B2B0);
        gUnknown_203B2B0 = NULL;
    }
}

void UpdateLuminousCaveState(u32 newState)
{
    gUnknown_203B2B0->state = newState;
    sub_8024804();
    UpdateLuminousCaveDialogue();
}

void sub_8024804(void)
{
  s32 index;

  sub_8006518(gUnknown_203B2B0->unk114);
  switch(gUnknown_203B2B0->state) {
    case 8:
    case 0xD:
        gUnknown_203B2B0->unk114[2] = gUnknown_80DCA00;
        break;
    case LUMINOUS_CAVE_LET_US_BEGIN:
    case LUMINOUS_CAVE_CHANGED_APPEARANCE:
    case LUMINOUS_CAVE_EVOLVED:
    case LUMINOUS_CAVE_COME_ALONE:
    case LUMINOUS_CAVE_LACK_LEVEL:
    case LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE:
    case LUMINOUS_CAVE_LACK_FRIEND_AREA:
    case LUMINOUS_CAVE_LACK_ROOM:
    case LUMINOUS_CAVE_LACK_IQ:
    case LUMINOUS_CAVE_LACK_ITEM:
        break;
    default:
        for(index = 0; index < 4; index++)
        {
            gUnknown_203B2B0->unk114[index] = gUnknown_80DC9E8;
        }
        break;
  }
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B2B0->unk114, 1, 1);
}

void UpdateLuminousCaveDialogue(void)
{
  char *monName;

  switch(gUnknown_203B2B0->state) {
    case LUMINOUS_CAVE_ENTRY:
        if (LuminousCave_HasOnly1Member()) {
            gUnknown_203B2B0->menuAction1 = 3;
        }
        else {
            gUnknown_203B2B0->menuAction1 = 1;
        }
        sub_8024CFC();
        sub_8014248(gLuminousCaveSeekAwakening,0,gUnknown_203B2B0->menuAction1,gUnknown_203B2B0->unk34,gUnknown_203B2B0->unk74,4,0,0,5);
        break;
    case LUMINOUS_CAVE_ASK_EVOLVE:
        sub_8024CFC();
        sub_8014248(gLuminousCaveAskEvolution,0,gUnknown_203B2B0->menuAction1,gUnknown_203B2B0->unk34,gUnknown_203B2B0->unk74,4,0,0,5);
        break;
    case LUMINOUS_CAVE_EVOLVE_INFO:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_ASK_EVOLVE;
        sub_80141B4(gLuminousCaveEvolutionInfo,0,0,0x105);
        break;
    case LUMINOUS_CAVE_SHALL_RETURN:
        gUnknown_203B2B0->fallbackState = 4;
        xxx_call_fade_in_new_bgm(MUS_FILE_SELECT,0x3c);
        sub_80141B4(gLuminousCaveYeShallReturn,0,0,0x305);
        break;

    case LUMINOUS_CAVE_GIVE_ITEM_1:
        sub_8024D48();
        sub_8014248(gLuminousCaveGiveItem,0,gUnknown_203B2B0->menuAction2,gUnknown_203B2B0->unk34,gUnknown_203B2B0->unk74,4,0,0,5);
        break;
    case 6:
        sub_801A5D8(2,3,0,10);
        break;
    case 7:
        sub_801A8D0(1);
        break;
    case LUMINOUS_CAVE_GIVE_ITEM_2:
        sub_8024DBC();
        sub_8014248(gLuminousCaveGiveAnotherItem,0,gUnknown_203B2B0->menuAction2,gUnknown_203B2B0->unk34,gUnknown_203B2B0->unk74,4,0,0,5);
        break;
    case 0xb:
        sub_801A5D8(2,3,0,10);
        sub_801AEE4(gUnknown_203B2B0->evoItem1_InvIndex,1);
        sub_801A9E0();
        break;
    case 0xc:
        sub_801A8D0(1);
        sub_801AEE4(gUnknown_203B2B0->evoItem1_InvIndex,1);
        sub_801A9E0();
        break;
    case 8:
    case 0xd:
        sub_801A9E0();
        sub_8024E30();
        sub_8012D60(&gUnknown_203B2B0->unk84,gUnknown_203B2B0->unk34,0,gUnknown_203B2B0->unk74,
                    gUnknown_203B2B0->menuAction3,2);
        break;
    case 9:
    case 0xe:
        sub_801B3C0(&gUnknown_203B2B0->chosenItem);
        break;
    case LUMINOUS_CAVE_LACK_WHAT_NEEDED:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_GIVE_ITEM_1;
        sub_80141B4(gLuminousCaveLackWhatIsNeeded,0,0,0x105);
        break;
    case LUMINOUS_CAVE_ONLY_ONE_ITEM:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_GIVE_ITEM_2;
        sub_80141B4(gLuminousCaveOnlyOneItem,0,0,0x105);
        break;
    case LUMINOUS_CAVE_LET_US_BEGIN:
        sub_8025254();

        if((gUnknown_203B2B0->evolutionConditionStatus & EVOLUTION_GOOD))
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_CHANGED_APPEARANCE;
        else if(gUnknown_203B2B0->evolutionConditionStatus == EVOLUTION_NO_MORE)
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE;
        else if(gUnknown_203B2B0->evolutionConditionStatus == EVOLUTION_LACK_LEVEL)
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_LACK_LEVEL;
        else if(gUnknown_203B2B0->evolutionConditionStatus == EVOLUTION_LACK_IQ)
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_LACK_IQ;
        else if(gUnknown_203B2B0->evolutionConditionStatus == EVOLUTION_LACK_FRIEND_AREA)
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_LACK_FRIEND_AREA;
        else if(gUnknown_203B2B0->evolutionConditionStatus == EVOLUTION_LACK_ROOM)
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_LACK_ROOM;
        else if(gUnknown_203B2B0->evolutionConditionStatus == EVOLUTION_LACK_ITEM)
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_LACK_ITEM;
        else
            gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_CANT_EVOLVE_YET;
        xxx_call_fade_out_bgm(0x3c);
        sub_80141B4(gLuminousCaveLetUsBegin,0,0,0x105);
        break;
    case LUMINOUS_CAVE_CHANGED_APPEARANCE:
        PrintColoredPokeNameToBuffer(gPlayerName,gUnknown_203B2B0->pokeStruct, COLOR_CYAN);
        PlaySound(0x1ff);
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_EVOLVED;
        sub_80141B4(gLuminousCaveChangedAppearance,0,0,0x105);
        break;
    case LUMINOUS_CAVE_EVOLVED:
        monName = GetMonSpecies(gUnknown_203B2B0->pokeStruct->speciesNum);
        strcpy(gAvailablePokemonNames,monName);
        monName = GetMonSpecies(gUnknown_203B2B0->targetSpecies);
        strcpy(gAvailablePokemonNames + 0x50,monName);
        gUnknown_203B2B0->evolutionComplete = TRUE;
        sub_80977D0();
        sub_808F734(gUnknown_203B2B0->pokeStruct,gUnknown_203B2B0->targetSpecies);
        nullsub_104();
        gUnknown_203B2B0->pokeStruct = GetPlayerPokemonStruct();
        if (gUnknown_203B2B0->evoItem1_InvIndex != INVENTORY_SIZE) {
            ClearItemSlotAt(gUnknown_203B2B0->evoItem1_InvIndex);
        }
        if (gUnknown_203B2B0->evoItem2_InvIndex != INVENTORY_SIZE) {
            ClearItemSlotAt(gUnknown_203B2B0->evoItem2_InvIndex);
        }
        FillInventoryGaps();
        xxx_call_stop_fanfare_se(0x1ff);
        PlaySound(0xd2);
        if (gUnknown_203B2B0->pokeRenamed) {
                BoundedCopyStringtoBuffer(gUnknown_203B2B0->pokeStruct->name,GetMonSpecies(gUnknown_203B2B0->pokeStruct->speciesNum),POKEMON_NAME_LENGTH);
        }
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveEvolved,0,0,0x105);
        break;
    case LUMINOUS_CAVE_COME_ALONE:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveComeAlone,0,0,0x105);
        break;
    case LUMINOUS_CAVE_LACK_LEVEL:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveLackLevel,0,0,0x105);
        break;
    case LUMINOUS_CAVE_CANT_EVOLVE_ANYMORE:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveCantEvolveAnymore,0,0,0x105);
        break;
    case LUMINOUS_CAVE_LACK_FRIEND_AREA:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveLackFriendArea,0,0,0x105);
        break;
    case LUMINOUS_CAVE_LACK_ROOM:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveLackRoom,0,0,0x105);
        break;
    case LUMINOUS_CAVE_LACK_IQ:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveLackIQ,0,0,0x105);
        break;
    case LUMINOUS_CAVE_LACK_ITEM:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveLackItem,0,0,0x105);
        break;
    case LUMINOUS_CAVE_CANT_EVOLVE_YET:
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_SHALL_RETURN;
        sub_80141B4(gLuminousCaveCantEvolveYet,0,0,0x105);
        break;
    case LUMINOUS_CAVE_PROMPT_NAME:
        xxx_call_fade_in_new_bgm(8,0x3c);
        gUnknown_203B2B0->fallbackState = LUMINOUS_CAVE_FINISH_NAME;
        sub_80141B4(gLuminousCaveGiveName,0,0,0x105);
        break;
    case LUMINOUS_CAVE_FINISH_NAME:
        if (gUnknown_203B2B0->pokeRenamed) {
                BoundedCopyStringtoBuffer(gUnknown_203B2B0->pokeStruct->name,GetMonSpecies(gUnknown_203B2B0->pokeStruct->speciesNum),POKEMON_NAME_LENGTH);
        }
        sub_801602C(0,gUnknown_203B2B0->pokeStruct->name);
        break;
    default:
        break;
  }
}

void sub_8024CFC(void)
{
    s32 loopMax = 0;

    MemoryFill16(gUnknown_203B2B0->unk74, 0, sizeof(gUnknown_203B2B0->unk74));
    gUnknown_203B2B0->unk34[loopMax].text = gUnknown_80DCA18;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 3;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 2;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = *gUnknown_80D4934;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = NULL;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;
}

void sub_8024D48(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B2B0->unk74, 0, sizeof(gUnknown_203B2B0->unk74));
    gUnknown_203B2B0->unk34[loopMax].text = gUnknown_80DCA24;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = gUnknown_80DCA2C;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = *gUnknown_80D4934;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = NULL;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B0->unk74[index] == 0)
        {
            if(gUnknown_203B2B0->unk34[index].menuAction == gUnknown_203B2B0->menuAction2)
                return;
        }
    }

    gUnknown_203B2B0->menuAction2 = 4;
}

void sub_8024DBC(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B2B0->unk74, 0, sizeof(gUnknown_203B2B0->unk74));
    gUnknown_203B2B0->unk34[loopMax].text = gUnknown_80DCA24;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 4;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = gUnknown_80DCA2C;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = *gUnknown_80D4934;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = NULL;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B0->unk74[index] == 0)
        {
            if(gUnknown_203B2B0->unk34[index].menuAction == gUnknown_203B2B0->menuAction2)
                return;
        }
    }

    gUnknown_203B2B0->menuAction2 = 4;
}

void sub_8024E30(void)
{
    s32 index;
    s32 loopMax;

    loopMax = 0;
    MemoryFill16(gUnknown_203B2B0->unk74, 0, sizeof(gUnknown_203B2B0->unk74));
    gUnknown_203B2B0->unk34[loopMax].text = gUnknown_80DCA2C;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 5;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = *gUnknown_80D4970;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 2;
    loopMax += 1;
    gUnknown_203B2B0->unk34[loopMax].text = NULL;
    gUnknown_203B2B0->unk34[loopMax].menuAction = 1;

    for(index = 0; index < loopMax; index++)
    {
        if(gUnknown_203B2B0->unk74[index] == 0)
        {
            if(gUnknown_203B2B0->unk34[index].menuAction == gUnknown_203B2B0->menuAction3)
                return;
        }
    }

    gUnknown_203B2B0->menuAction3 = 5;
}

void sub_8024E9C(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        if(menuAction != 1) gUnknown_203B2B0->menuAction1 = menuAction;
        switch(menuAction)
        {
            case 3:
                if(LuminousCave_HasOnly1Member())
                    UpdateLuminousCaveState(LUMINOUS_CAVE_GIVE_ITEM_1);
                else
                    UpdateLuminousCaveState(LUMINOUS_CAVE_COME_ALONE);
                break;
            case 2:
                UpdateLuminousCaveState(LUMINOUS_CAVE_EVOLVE_INFO);
                break;
            case 1:
                UpdateLuminousCaveState(LUMINOUS_CAVE_SHALL_RETURN);
                break;
        }
    }
}

void sub_8024F00(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        if(menuAction != 1) gUnknown_203B2B0->menuAction2 = menuAction;
        switch(menuAction)
        {
            case 4:
                gUnknown_203B2B0->evoItem1_InvIndex = INVENTORY_SIZE;
                gUnknown_203B2B0->evoItem2_InvIndex = INVENTORY_SIZE;
                UpdateLuminousCaveState(LUMINOUS_CAVE_LET_US_BEGIN);
                break;
            case 5:
                if(GetNumberOfFilledInventorySlots() == 0)
                    UpdateLuminousCaveState(LUMINOUS_CAVE_LACK_WHAT_NEEDED);
                else
                    UpdateLuminousCaveState(0x6);
                break;
            case 1:
                UpdateLuminousCaveState(LUMINOUS_CAVE_ASK_EVOLVE);
                break;
        }
    }
}

void sub_8024F70(void)
{
    s32 menuAction;
    if(sub_80144A4(&menuAction) == 0)
    {
        if(menuAction != 1) gUnknown_203B2B0->menuAction2 = menuAction;
        switch(menuAction)
        {
            case 4:
                UpdateLuminousCaveState(LUMINOUS_CAVE_LET_US_BEGIN);
                break;
            case 5:
                if(GetNumberOfFilledInventorySlots() < 2)
                    UpdateLuminousCaveState(LUMINOUS_CAVE_ONLY_ONE_ITEM);
                else
                    UpdateLuminousCaveState(0xB);
                break;
            case 1:
                UpdateLuminousCaveState(LUMINOUS_CAVE_ASK_EVOLVE);
                break;
        }
    }
}

void sub_8024FD4(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            gUnknown_203B2B0->evoItem1_InvIndex = sub_801A8AC();
            gUnknown_203B2B0->evoItem2_InvIndex = INVENTORY_SIZE;
            gUnknown_203B2B0->chosenItem = gTeamInventory_203B460->teamItems[gUnknown_203B2B0->evoItem1_InvIndex];
            UpdateLuminousCaveState(8);
            break;
        case 4:
            gUnknown_203B2B0->chosenItem = gTeamInventory_203B460->teamItems[sub_801A8AC()];
            sub_8099690(0);
            UpdateLuminousCaveState(9);
            break;
        case 2:
            sub_801A928();
            UpdateLuminousCaveState(LUMINOUS_CAVE_GIVE_ITEM_1);
            break;
    }
}

void sub_8025058(void)
{
    switch(sub_801A6E8(TRUE))
    {
        case 3:
            if(gUnknown_203B2B0->evoItem1_InvIndex != sub_801A8AC())
            {
                gUnknown_203B2B0->evoItem2_InvIndex = sub_801A8AC();
                gUnknown_203B2B0->chosenItem = gTeamInventory_203B460->teamItems[gUnknown_203B2B0->evoItem2_InvIndex];
                UpdateLuminousCaveState(0xD);
            }
            else
                PlayMenuSoundEffect(2);
            break;
        case 4:
            gUnknown_203B2B0->chosenItem = gTeamInventory_203B460->teamItems[sub_801A8AC()];
            sub_8099690(0);
            UpdateLuminousCaveState(0xE);
            break;
        case 2:
            sub_801A928();
            UpdateLuminousCaveState(0xA);
            break;
    }
}

void sub_80250EC(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801A6E8(FALSE);

    if(!sub_8012FD8(&gUnknown_203B2B0->unk84))
    {
        sub_8013114(&gUnknown_203B2B0->unk84, &menuAction);
        if(menuAction != 1) gUnknown_203B2B0->menuAction3 = menuAction;
    }
    switch(menuAction)
    {
        case 5:
            sub_801A928();
            UpdateLuminousCaveState(0xA);
            break;
        case 2:
            sub_8099690(0);
            UpdateLuminousCaveState(0x9);
            break;
        case 1:
            UpdateLuminousCaveState(0x7);
            break;
    }
}

void sub_802515C(void)
{
    s32 menuAction;
    menuAction = 0;
    sub_801A6E8(FALSE);

    if(!sub_8012FD8(&gUnknown_203B2B0->unk84))
    {
        sub_8013114(&gUnknown_203B2B0->unk84, &menuAction);
        if(menuAction != 1) gUnknown_203B2B0->menuAction3 = menuAction;
    }
    switch(menuAction)
    {
        case 5:
            sub_801A928();
            UpdateLuminousCaveState(LUMINOUS_CAVE_LET_US_BEGIN);
            break;
        case 2:
            sub_8099690(0);
            UpdateLuminousCaveState(0xE);
            break;
        case 1:
            UpdateLuminousCaveState(0xC);
            break;
    }
}

void sub_80251CC(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            UpdateLuminousCaveState(0x7);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_80251E8(void)
{
    switch(sub_801B410())
    {
        case 2:
        case 3:
            sub_801B450();
            UpdateLuminousCaveState(0xC);
            break;
        case 0:
        case 1:
            break;
    }
}

void sub_8025204(void)
{
    switch(sub_8016080())
    {
        case 3:
            sub_80160D8();
            gUnknown_203B2B0->pokeRenamed = IsPokemonRenamed(gUnknown_203B2B0->pokeStruct);
            UpdateLuminousCaveState(LUMINOUS_CAVE_SHALL_RETURN);
            break;
        default:
            break;
    }
}

void LuminousCave_AdvancetoFallbackState(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0)
    {
        UpdateLuminousCaveState(gUnknown_203B2B0->fallbackState);
    }
}

void sub_8025254(void)
{
    if(gUnknown_203B2B0->evoItem1_InvIndex == INVENTORY_SIZE)
        gUnknown_203B2B0->evoItem1_itemIndex = 0;
    else
    {
        gUnknown_203B2B0->evoItem1_itemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2B0->evoItem1_InvIndex].id;
    }
    if(gUnknown_203B2B0->evoItem2_InvIndex == INVENTORY_SIZE)
        gUnknown_203B2B0->evoItem2_ItemIndex = 0;
    else
    {
        gUnknown_203B2B0->evoItem2_ItemIndex = gTeamInventory_203B460->teamItems[gUnknown_203B2B0->evoItem2_InvIndex].id;
    }

    gUnknown_203B2B0->unk6 = RandInt(0xFF);
    sub_808F468(gUnknown_203B2B0->pokeStruct, &gUnknown_203B2B0->evoItem1_itemIndex, 1);
}

bool8 LuminousCave_HasOnly1Member(void)
{
    s32 memberCount;
    s32 index;
    struct PokemonStruct *preload;

    preload = &gRecruitedPokemonRef->pokemon[0];
    memberCount = 0;
    for(index = 0; index < NUM_MONSTERS; index++, preload++)
    {
        if((preload->unk0 >> 1) & 1)
            memberCount++;
    }

    if(memberCount == 1)
        return TRUE;
    else
        return FALSE;
}
