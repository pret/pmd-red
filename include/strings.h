#ifndef GUARD_STRINGS_H
#define GUARD_STRINGS_H

#include "structs/str_status_text.h"
#include "rescue_team_info.h"
#include "constants/type.h"
#include "constants/ability.h"
#include "constants/dungeon.h"
#include "constants/dungeon_exit.h"
#include "constants/iq_skill.h"
#include "constants/tactic.h"
#include "constants/friend_area.h"

// size: 0x8
typedef struct DungeonName
{
    const u8 *name1;
    const u8 *name2;
} DungeonName;

struct unkStruct_8113080
{
    bool8 defeatedByPrefix;
    const u8 *text;
};

extern const char * const gUnformattedTypeStrings[NUM_TYPES];
extern const char * const gFormattedTypeStrings[NUM_TYPES];
extern const u8 *const gUnknown_810AF50[20];
extern const u8 *const gAdventureLogText[32];
extern const u8 *const gRescueTeamRanks[MAX_TEAM_RANKS];
extern const u8 *const gAbilityNames[NUM_ABILITIES];
extern const u8 *const gAbilityDescriptions[NUM_ABILITIES];
extern const u8 *const gRangeNames[49];
extern const u8 *const gUnknown_810CF00;
extern const u8 *const gTextType;
extern const u8 *const gTextPower;
extern const u8 *const gStatusNames[89];
extern const u8 *const gFormattedStatusNames[89];
extern const u8 *const gUnknown_810DD58;
extern const u8 *const gText_IqSkills;
extern const u8 *const gText_LevelUnkMacro;
extern const u8 *const gText_ExpPtsUnkMacro;
extern const u8 *const gText_ToNextLevel;
extern const u8 *const gUnknown_810DDD0;
extern const u8 *const gUnknown_810DDE4;
extern const u8 *const gUnknown_810DDFC;
extern const u8 *const gUnknown_810DE0C;
extern const u8 *const gUnknown_810DE20;
extern const u8 *const gUnknown_810DE24;
extern const u8 *const gUnknown_810DE28;
extern const u8 *const gUnknown_810DE38;
extern const u8 *const gUnknown_810DE4C;
extern const u8 *const gUnknown_810DE50;
extern const u8 *const gUnknown_810DE54;
extern const u8 *const gUnknown_810DE58;
extern const u8 *const gUnknown_810DE6C;
extern const u8 *const gUnknown_810DE80;
extern const u8 *const gUnknown_810DE98;
extern const u8 *const gUnknown_810DEB4;
extern const u8 *const gUnknown_810DEC8;
extern const u8 *const gUnknown_810DEDC;
extern const u8 *const gUnknown_810DEF4;
extern const u8 *const gUnknown_810DEF8;
extern const u8 *const gUnknown_810DF1C;
extern const u8 *const gUnknown_810DF34;
extern const u8 *const gUnknown_810DF50;
extern const u8 *const gUnknown_810DF78;
extern const u8 *const gUnknown_810DF84;
extern const u8 *const gUnknown_810DF98;
extern const u8 *const gUnknown_810DFB4;
extern const u8 *const gUnknown_810DFC8;
extern const u8 *const gEvolutionStrings[4];
extern const u8 *const gUnknown_810E02C[6];
extern const StatusText gStatusDescriptions[99];
extern const DungeonName gDungeonNames[NUM_DUNGEONS];
extern const u8 *const gIQSkillNames[NUM_IQ_SKILLS];
extern const u8 *const gIQSkillDescriptions[NUM_IQ_SKILLS];
extern const u8 *const gTacticsNames[NUM_TACTICS];
extern const u8 *const gTacticsDescriptions[NUM_TACTICS + 12];
extern const struct unkStruct_8113080 gDungeonExitReasonTexts[NUM_DUNGEON_EXIT_REASONS];
extern const u8 *const gText_DeathToMove;
extern const u8 *const gText_AlignPlaceX;
extern const u8 *const gText_Pokemon1WasDefeatedBy;
extern const u8 *const gText_Pokemon1;
extern const u8 *const gUnknown_8113898;
extern const u8 *const gUnknown_81138C0;
extern const u8 *const gUnknown_81138D0;
extern const u8 *const gUnknown_81138E4;
extern const u8 *const gUnknown_8113900;
extern const u8 *const gUnknown_8113918;
extern const u8 *const gUnknown_8113934;
extern const u8 *const gUnknown_8113950;
extern const u8 *const gUnknown_8113974;
extern const u8 *const gUnknown_8113990;
extern const u8 *const gUnknown_81139B4;
extern const u8 *const gUnknown_81139B8;
extern const u8 *const gText_ItemAlignedX;
extern const u8 *const gFriendAreaNames[FRIEND_AREA_COUNT];
extern const u8 *const gFriendAreaDescriptions[FRIEND_AREA_COUNT];
extern const u8 *const gUnknown_8115718[100];
extern const u8 *const gText_PP_Value0;
extern const u8 *const gText_TooManyMembersToEnterDungeon;
extern const u8 *const gText_OnlyOneMonMayEnterDungeon;
extern const u8 *const gText_OnlyXItemsMayBeBroughtIntoDungeon;
extern const u8 *const gText_AlsoOnlyXItemsMayBeBroughtIntoDungeon;
extern const u8 *const gText_ClientCouldNotJoinTooManyMembers;
extern const u8 *const gText_AlsoClientCouldNotJoinTooManyMembers;
extern const u8 *const gText_ClientCouldNotJoinNoSpace;
extern const u8 *const gText_AlsoClientCouldNotJoinNoSpace;
extern const u8 *const gText_MustHaveMonWithMove;
extern const u8 *const gText_AlsoMustHaveMonWithMove;
extern const u8 *const gText_MustHaveWaterTypeMon;
extern const u8 *const gText_AlsoMustHaveWaterTypeMon;
extern const u8 *const gText_IsOkToEnterWithFollowingRules;
extern const u8 *const gText_GameWilllBeSavedBeforeEntering;
extern const u8 *const gText_TeamWillEnterAtLv1;
extern const u8 *const gText_AllItemsLostOnEntering;
extern const u8 *const gText_AllMoneyLostOnEntering;

#endif
