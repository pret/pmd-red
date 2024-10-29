#ifndef GUARD_DUNGEON_MESSAGE_H
#define GUARD_DUNGEON_MESSAGE_H

#include "structs/dungeon_entity.h"
#include "string_format.h"

struct MonDialogueSpriteInfo
{
    s16 species;
    u8 spriteId;
};

struct DungeonDialogueStruct
{
    u16 unk0;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    s16 unk6;
    const u8 *str;
};

void sub_80521D0(void);
void sub_8052210(bool8 a0);

// These functions display the string if certain conditions are met. The conditions differ depending on the function. The string is then saved to the message log.
void TryDisplayDungeonLoggableMessage(Entity *pokemon, const u8 *str);
void TryDisplayDungeonLoggableMessage2(Entity *pokemon, const u8 *str);
void TryDisplayDungeonLoggableMessage3(Entity *attacker, Entity *target, const u8 *str);
void TryDisplayDungeonLoggableMessage4(Entity *attacker, Entity *target, const u8 *str);
void TryDisplayDungeonLoggableMessage5(Entity *pokemon, Position *pos, const u8 *str);

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
void TryDisplayItemPickupTutorialMessage(u8 itemId);
void DisplayYouReachedDestFloorStr(void);
void sub_8052FB8(const u8 *str);
const u8 *GetCurrentDungeonName(void);
void ResetMessageLog(void);
bool32 DisplayMessageLog(void);

#endif // GUARD_DUNGEON_MESSAGE_H
