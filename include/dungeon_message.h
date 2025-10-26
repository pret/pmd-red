#ifndef GUARD_DUNGEON_MESSAGE_H
#define GUARD_DUNGEON_MESSAGE_H

#include "structs/dungeon_entity.h"
#include "string_format.h"
#include "structs/str_dungeon.h"

struct MonDialogueSpriteInfo
{
    s16 species;
    u8 spriteId;
};

// Depending on partner's pokemon species, the dialogue may be slightly different.
#define DIALOGUE_ALLOW_ALL 0
#define DIALOGUE_ALLOW_MOST 1 // Bulbasaur, Cyndaquil, Mudkip, Pikachu, Charmander, Treecko
#define DIALOGUE_ONLY_SQUIRTLE_TOTODILE 7
#define DIALOGUE_ONLY_TORCHIC_CHICORITA 280

struct DungeonDialogueStruct
{
    u16 type;
    u8 spriteId;
    u8 spritePlacementId; // Information on mon's portrait x/y and flip
    s16 speciesId;
    s16 allowType;
    const u8 *str;
};

extern bool8 gUnknown_203B434;

void sub_80521D0(void);
void sub_8052210(bool8 a0);
void sub_805229C(void);

// These functions display the string if certain conditions are met. The conditions differ depending on the function. The string is then saved to the message log.
void LogMessageByIdWithPopupCheckUser(Entity *pokemon, const u8 *str);
void TryDisplayDungeonLoggableMessage2(Entity *pokemon, const u8 *str);
void TryDisplayDungeonLoggableMessage3(Entity *attacker, Entity *target, const u8 *str);
void TryDisplayDungeonLoggableMessage4(Entity *attacker, Entity *target, const u8 *str);
void LogMessageByIdWithPopupCheckUserUnknown(Entity *pokemon, DungeonPos *pos, const u8 *str);

// As opposed to the above - these always display the string and save it in the message log. False/True stand for an unknown argument. Not sure what the practical difference is between these.
void DisplayDungeonLoggableMessage(Entity *pokemon, const u8 *str);
void DisplayDungeonLoggableMessageFalse(Entity *pokemon, const u8 *str);
void DisplayDungeonLoggableMessageTrue(Entity *pokemon, const u8 *str);

void xxx_draw_string_80524F0(void);
void sub_80526D0(s32 r0);
void sub_8052740(s32 a0);
void DisplayDungeonMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, bool8 a2);
void DisplayDungeonDialogue(const struct DungeonDialogueStruct *dialogueInfo);
bool32 DisplayDungeonYesNoMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, bool32 defaultYes);
s32 DisplayDungeonMenuMessage(struct MonDialogueSpriteInfo *monSpriteInfo, const u8 *str, const MenuItem *menuItems, u16 unkArg);
void sub_8052D44(s16 *ids, Entity *leader, Entity *partner);
void TryDisplayGeneralTutorialMessage(void);
void DisplayItemTip(u8 itemId);
void DisplayYouReachedDestFloorStr(void);
void sub_8052FB8(const u8 *str);
const u8 *GetCurrentDungeonName(void);

// Actual function in Sky.
static inline void SetUnk1C05E(bool8 val)
{
    gDungeon->unk1BDD4.unk1C05E = val;
}

#endif // GUARD_DUNGEON_MESSAGE_H
