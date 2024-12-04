#include "global.h"
#include "dungeon_util.h"
#include "items.h"
#include "status.h"
#include "weather.h"
#include "dungeon_ai_targeting.h"
#include "code_8045A00.h"
#include "dungeon_capabilities.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_moves.h"
#include "position_util.h"
#include "dungeon_music.h"
#include "dungeon_map_access.h"
#include "code_803E46C.h"
#include "code_806CD90.h"
#include "dungeon_movement.h"
#include "game_options.h"
#include "dungeon_items.h"
#include "moves.h"
#include "dungeon_random.h"
#include "status_checks_1.h"
#include "code_803E668.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/move_id.h"
#include "constants/weather.h"
#include "number_util.h"
#include "dungeon_message.h"
#include "code_8077274_1.h"
#include "dungeon_pokemon_attributes.h"
#include "math.h"
#include "dungeon_battle_data.h"

extern bool8 sub_8044B28(void);
extern void sub_8075708(Entity *entity);
extern void DealDamageToEntity(Entity *, s32, u32, u32);
extern void sub_8067110(Entity *);
extern void sub_80671A0(Entity *);
extern void sub_8073D14(Entity *);
extern void sub_8045BF8(u8 *, Item *);
extern bool8 sub_80461C8(DungeonPos *, u32);
extern void sub_805229C(void);
extern void sub_807E8F0(Entity *);
extern void sub_80444F4(Entity *pokemon);
extern void WarpTarget(Entity *pokemon, Entity *r1, u32 r2, DungeonPos *r3);
extern void sub_80420B8(Entity *pokemon);
extern void sub_8041C4C(Entity *pokemon, u32 r1);
extern void sub_805E804(void);
extern void sub_80838EC(u8 *a);
extern bool8 TryUseChosenMove(struct Entity *, u32, u32, u32, u32, struct Move *);
extern bool8 sub_8045888(Entity *);
extern void nullsub_97(Entity *entity);
extern void sub_805EE30(void);
extern void sub_8086AC0(void);
extern void sub_8085140(void);
extern void sub_8075708(Entity *entity);
extern void sub_8043ED0(u32);
extern void sub_8071DA4(Entity *);
extern void sub_8075900(Entity *pokemon, u8 r1);
extern void sub_806A5B8(Entity *);
extern void sub_807EC28(bool8);

extern s32 gUnknown_202F378;
extern u8 gUnknown_202F32D;

extern const u8 *gMonTerrifiedCouldntPickUpItem;
extern const u8 *gMonPickedUpItem;
extern const u8 *gMonPickedUpItem2;
extern const u8 *gMonPickedUpItemToolbox;
extern const u8 *gMonSteppedOnItem;
extern const u8 *gMonCouldntPickUpItem;
extern const u8 *gUnknown_80FD594;
extern const u8 *gUnknown_80FD5B8;
extern const u8 *gUnknown_80FD5DC;
extern const u8 *gUnknown_80FD608;
extern const u8 *gUnknown_80FD628;
extern const u8 *gUnknown_80FEB30;
extern const u8 *gUnknown_80FABD8;
extern const u8 *gPtrProtectSavedItMessage;
extern const u8 *gPtrStenchWavedOffMessage;
extern const u8 *gUnknown_80FA124[];

extern const s16 gWarpScarfActivationChances[];
extern const s16 gUnknown_80F4E0C;
extern s48_16 gUnknown_80F54F4[8];
extern const s32 gUnknown_80F60DC[];

extern const DungeonPos gUnknown_80F4D44[];

bool8 UseAttack(Entity *a0);
void sub_8075050(EntityInfo *info, Unk_Entity_x184 *strPtr);

void HandleEatAIAction(Entity *pokemon)
{
    sub_8067110(pokemon);
}

void HandleThrowItemAIAction(Entity *pokemon)
{
    sub_80671A0(pokemon);
}

void HandlePickUpAIAction(Entity *pokemon)
{
    sub_8073D14(pokemon);
}

void sub_8073D14(Entity *entity)
{
    Item *groundItem;
    EntityInfo *_entityInfo;
    EntityInfo *entityInfo = GetEntInfo(entity);
    Entity *tileObject = GetTileAtEntitySafe(entity)->object;
    if (tileObject == NULL)
        return;
    if (sub_8044B28())
        return;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    if (entityInfo->isTeamLeader)
        return;
    if (entityInfo->shopkeeper == 1)
        return;
    if (IsExperienceLocked(entityInfo->joinedAt.id))
        return;
    if (entityInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET)
        return;

    _entityInfo = GetEntInfo(entity); // Reloaded as a new variable for some reason.
    groundItem = GetItemData(tileObject);
    if (groundItem->flags & ITEM_FLAG_IN_SHOP)
        return;

    if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        sub_8045BF8(gFormatBuffer_Items[0], groundItem);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
        DisplayDungeonLoggableMessageTrue(entity, gMonTerrifiedCouldntPickUpItem);
    }
    else if (!_entityInfo->isNotTeamMember && GetItemCategory(groundItem->id) == CATEGORY_POKE) {
        // Why check the same thing again?
        if (_entityInfo->isNotTeamMember) {
            PlaySoundEffect(0x14B);
        }
        else {
            PlaySoundEffect(0x14C);
        }
        AddToTeamMoney(GetMoneyValue(groundItem));
        sub_8045BF8(gFormatBuffer_Items[0], groundItem);
        sub_80461C8(&entity->pos, 1);
        DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItem);
    }
    else {
        s32 i, nItems, newInventoryId;
        s32 inventoryIds[INVENTORY_SIZE + 1]; // plus held
        Item *carriedItems[INVENTORY_SIZE + 1]; // plus held
        s32 newQuantity;

        if (gDungeon->unk644.unk17 && !_entityInfo->isNotTeamMember) {
            for (i = 0; i < INVENTORY_SIZE; i++) {
                carriedItems[i] = &gTeamInventoryRef->teamItems[i];
                inventoryIds[i] = i;
            }
            carriedItems[INVENTORY_SIZE] = &_entityInfo->heldItem;
            inventoryIds[INVENTORY_SIZE] = -1;
            nItems = INVENTORY_SIZE + 1;
        }
        else {
            carriedItems[0] = &_entityInfo->heldItem;
            inventoryIds[0] = -1;
            nItems = 1;
        }

        if ((groundItem->id < 9) && !(groundItem->flags & ITEM_FLAG_IN_SHOP)) {
            newInventoryId = -1;
            newQuantity = -1;
            for (i = 0; i < nItems; i++) {
                if (carriedItems[i]->flags & ITEM_FLAG_EXISTS
                    && !(carriedItems[i]->flags & ITEM_FLAG_IN_SHOP)
                    && ((groundItem->id == carriedItems[i]->id) && (groundItem->flags & ITEM_FLAG_STICKY) == (carriedItems[i]->flags & ITEM_FLAG_STICKY))
                    && carriedItems[i]->quantity != 99 && newQuantity < carriedItems[i]->quantity)
                {
                    newQuantity = carriedItems[i]->quantity;
                    newInventoryId = i;
                }
            }

            if (newInventoryId == -1) {
                newQuantity = -1;
                for (i = 0; i < nItems; i++) {
                    if (carriedItems[i]->flags & ITEM_FLAG_EXISTS
                        && !(carriedItems[i]->flags & ITEM_FLAG_IN_SHOP)
                        && groundItem->id == carriedItems[i]->id
                        && carriedItems[i]->quantity != 99
                        && newQuantity < carriedItems[i]->quantity)
                    {
                        newQuantity = carriedItems[i]->quantity;
                        newInventoryId = i;
                    }
                }
            }

            if (newInventoryId != -1) {
                s32 quantity = carriedItems[newInventoryId]->quantity + groundItem->quantity;
                if (quantity >= 99)
                    quantity = 99;
                carriedItems[newInventoryId]->quantity = quantity;
                if (groundItem->flags & ITEM_FLAG_STICKY)
                    carriedItems[newInventoryId]->flags |= ITEM_FLAG_STICKY;

                sub_8045BF8(gFormatBuffer_Items[0], groundItem);
                sub_80461C8(&entity->pos, 1);
                PlaySoundEffect(0x14A);
                if (inventoryIds[newInventoryId] <= -1)
                    DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItem2);
                else
                    DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItemToolbox);

                return;
            }
        }

        for (i = 0; i < nItems; i++) {
            if (!(carriedItems[i]->flags & ITEM_FLAG_EXISTS))
                break;
        }

        if (i == nItems) {
            sub_8045BF8(gFormatBuffer_Items[0], groundItem);
            DisplayDungeonLoggableMessageTrue(entity, gMonSteppedOnItem);
        }
        else {
            if (_entityInfo->isNotTeamMember) {
                PlaySoundEffect(0x14B);
            }
            else {
                PlaySoundEffect(0x14A);
            }

            if (inventoryIds[i] <= -1) {
                _entityInfo->heldItem = *groundItem;
                sub_8045BF8(gFormatBuffer_Items[0], groundItem);
                sub_80461C8(&entity->pos, 1);
                DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItem2);
            }
            else if (AddItemToInventory(groundItem)) {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
                DisplayDungeonLoggableMessageTrue(entity, gMonCouldntPickUpItem);
            }
            else {
                sub_8045BF8(gFormatBuffer_Items[0], groundItem);
                sub_80461C8(&entity->pos, 1);
                DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItemToolbox);
            }
        }
    }
}

void sub_8074094(Entity *entity)
{
    s32 rand;
    EntityInfo *entityInfo;

    if (entity == NULL)
        return;
    if (!EntityExists(entity) || sub_8044B28())
        return;

    entityInfo = GetEntInfo(entity);
    entityInfo->unk146 = 0;
    sub_805229C();
    sub_807E8F0(entity);
    if (HasHeldItem(entity, ITEM_WARP_SCARF)) {
        if (++entityInfo->turnsSinceWarpScarfActivation > 19)
            entityInfo->turnsSinceWarpScarfActivation = 19;
        if (DungeonRandInt(100) < gWarpScarfActivationChances[entityInfo->turnsSinceWarpScarfActivation]) {
            entityInfo->turnsSinceWarpScarfActivation = 0;
            sub_80444F4(entity);
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            WarpTarget(entity, entity, 0, NULL);
            if (entityInfo->isTeamLeader) {
                gDungeon->unk1 = 0;
                gDungeon->unk5C0 = -1;
            }
        }
    }

    if (entityInfo->isTeamLeader) {
        s48_16 sp8, sp10;
        FixedPoint var_38;
        FixedPoint bellyBefore;
        bool8 sound;

        const u8 *str = NULL;
        s32 r4 = 10;
        if (HasHeldItem(entity, ITEM_TIGHT_BELT))
            r4 = 0;
        if (HasHeldItem(entity, ITEM_STAMINA_BAND))
            r4--;
        if (IQSkillIsEnabled(entity, IQ_ENERGY_SAVER))
            r4--;
        if (HasHeldItem(entity, ITEM_DIET_RIBBON))
            r4++;
        if (HasHeldItem(entity, ITEM_HEAL_RIBBON))
            r4++;
        if (HasHeldItem(entity, ITEM_MUNCH_BELT))
            r4++;

        if (r4 < 0)
            r4 = 0;
        if (r4 > 19)
            r4 = 19;

        sp8.hi = 0;
        sp8.lo = 6554;
        F48_16_SMul(&sp10, &sp8, &gUnknown_80F54F4[r4]);
        if (entityInfo->unk153 > 1)
            sp10.lo += (gUnknown_80F60DC[entityInfo->unk153] << 0x10);
        entityInfo->unk153 = 0;

        bellyBefore = entityInfo->belly;
        var_38 = FixedPoint_SetFromUnk(&sp10);
        entityInfo->belly = FixedPoint_Subtract(bellyBefore, var_38);
        sound = TRUE;
        if (FixedPointToInt(bellyBefore) > 19 && FixedPointToInt(entityInfo->belly) <= 19)
            str = gUnknown_80FD594;
        if (FixedPointToInt(bellyBefore) > 9 && FixedPointToInt(entityInfo->belly) <= 9)
            str = gUnknown_80FD5B8;
        // Why not just do <=
        if (FixedPointToInt(entityInfo->belly) == 0)
            entityInfo->belly = IntToFixedPoint(0);
        if (FixedPointToInt(entityInfo->belly) < 0)
            entityInfo->belly = IntToFixedPoint(0);

        if (FixedPointToInt(entityInfo->belly) == 0) {
            sub_805E804();
            sub_80444F4(entity);
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            if (gDungeon->unk644.unk35 < 10)
                gDungeon->unk644.unk35++;
            if (gDungeon->unk644.unk35 == 1)
                str = gUnknown_80FD5DC;
            if (gDungeon->unk644.unk35 == 2)
                str = gUnknown_80FD608, sound = FALSE;
            if (gDungeon->unk644.unk35 == 3)
                str = gUnknown_80FD628, sound = FALSE;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, 1, 0xE, 0x211);
            entityInfo->unk146 = 1;
            if (FixedPointToInt(entityInfo->belly) != 0)
                str = NULL;
        }
        else {
            gDungeon->unk644.unk35 = 0;
        }

        if (str != NULL) {
            if (sound)
                PlaySoundEffect(0x153);
            LogMessageByIdWithPopupCheckUser(entity, str);
            sub_803E708(0x1E, 0x32);
        }
    }

    if (!EntityExists(entity) || sub_8044B28())
        return;
    if (gDungeon->weather.weatherDamageCounter == 0) {
        if (GetApparentWeather(entity) == WEATHER_HAIL) {
            if (!MonsterIsType(entity, TYPE_ICE)) {
                DealDamageToEntity(entity, gHailSandstormDmgValue, 0x12, 0x220);
            }
        }
        else if (GetApparentWeather(entity) == WEATHER_SANDSTORM) {
            if (!MonsterIsType(entity, TYPE_GROUND) && !MonsterIsType(entity, TYPE_ROCK) && !MonsterIsType(entity, TYPE_STEEL)) {
                DealDamageToEntity(entity, gHailSandstormDmgValue, 0x12, 0x220);
            }
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

// Abilities check
    rand = DungeonRandInt(100);
    if (AbilityIsActive(entity, ABILITY_SHED_SKIN) && rand < gUnknown_80F4E0C && HasNegativeStatus(entity)) {
        UseAttack(NULL);
        if (!EntityExists(entity) || sub_8044B28())
            return;
        sub_8079F20(entity, entity, 1, 0);
    }
    if (AbilityIsActive(entity, ABILITY_SPEED_BOOST)) {
        entityInfo->speedBoostFrames++;
        if (entityInfo->speedBoostFrames >= gSpeedBoostActivationFrame) {
            entityInfo->speedBoostFrames = 0;
            RaiseMovementSpeedTarget(entity, entity, 0x7F, FALSE);
        }
    }

// Statuses
    if (entityInfo->sleepClassStatus.status == STATUS_YAWNING) {
        UseAttack(NULL);
        if (!EntityExists(entity) || sub_8044B28())
            return;
        sub_80420B8(entity);
    }

    if (entityInfo->burnClassStatus.status == STATUS_BURN) {
        if (entityInfo->burnClassStatus.damageCountdown == 0 || --entityInfo->burnClassStatus.damageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->burnClassStatus.damageCountdown = gBurnDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gBurnDmgValue, 1, 0x208);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->burnClassStatus.status == STATUS_POISONED) {
        if (entityInfo->burnClassStatus.damageCountdown == 0 || --entityInfo->burnClassStatus.damageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->burnClassStatus.damageCountdown = gPoisonDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gPoisonDmgValue, 3, 0x20A);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }
    else if (entityInfo->burnClassStatus.status == STATUS_BADLY_POISONED) {
        if (entityInfo->burnClassStatus.damageCountdown == 0 || --entityInfo->burnClassStatus.damageCountdown == 0) {
            s32 turns = entityInfo->burnClassStatus.unk4;
            if (entityInfo->burnClassStatus.unk4 < BAD_POISON_DMG_TURN_VALUES_COUNT - 1)
                entityInfo->burnClassStatus.unk4++;
            entityInfo->burnClassStatus.damageCountdown = gBadPoisonDmgCountdown;
            if (turns >= BAD_POISON_DMG_TURN_VALUES_COUNT - 1)
                turns = BAD_POISON_DMG_TURN_VALUES_COUNT - 1;

            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gBadPoisonDmgValuesByTurn[turns], 3, 0x20A);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->frozenClassStatus.status == STATUS_CONSTRICTION) {
        if (entityInfo->frozenClassStatus.damageCountdown == 0 || --entityInfo->frozenClassStatus.damageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->frozenClassStatus.damageCountdown = gConstrictionDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            sub_8041C4C(entity, entityInfo->frozenClassStatus.unk4);
            DealDamageToEntity(entity, gConstrictionDmgValue, 2, 0x209);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }
    else if (entityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
        if (entityInfo->frozenClassStatus.damageCountdown == 0 || --entityInfo->frozenClassStatus.damageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->frozenClassStatus.damageCountdown = gWrapDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gWrapDmgValue, 5, 0x20B);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }
    else if (entityInfo->frozenClassStatus.status == STATUS_INGRAIN) {
        if (entityInfo->frozenClassStatus.damageCountdown == 0 || --entityInfo->frozenClassStatus.damageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->frozenClassStatus.damageCountdown = gIngrainHealCountdown;
            HealTargetHP(entity, entity, gIngrainHealValue, 0, TRUE);
        }
    }

    if (entityInfo->curseClassStatus.status == STATUS_CURSED) {
        if (entityInfo->curseClassStatus.damageCountdown == 0 || --entityInfo->curseClassStatus.damageCountdown == 0) {
            s32 dmg = entityInfo->maxHPStat / 4;
            if (dmg == 0)
                dmg = 1;
            entityInfo->curseClassStatus.damageCountdown = gCurseDmgCountdown;
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, dmg, 7, 0x20C);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->leechSeedClassStatus.status == STATUS_LEECH_SEED) {
        if (entityInfo->leechSeedClassStatus.damageCountdown == 0 || --entityInfo->leechSeedClassStatus.damageCountdown == 0) {
            s32 hp = gLeechSeedHealValue;
            Entity *target = gDungeon->activePokemon[entityInfo->leechSeedClassStatus.unk8];

            entityInfo->leechSeedClassStatus.damageCountdown = gLeechSeedDmgCountdown;
            if (target == NULL) {
                entityInfo->leechSeedClassStatus.status = 0;
            }
            else {
                EntityInfo *targetInfo = GetEntInfo(target);
                if (targetInfo->unk98 != entityInfo->leechSeedClassStatus.unk4) {
                    entityInfo->leechSeedClassStatus.status = 0;
                }
                else {
                    bool8 dmgUser = AbilityIsActive(entity, ABILITY_LIQUID_OOZE);
                    sub_80444F4(entity);
                    UseAttack(NULL);
                    if (!EntityExists(entity) || !EntityExists(target) || sub_8044B28())
                        return;

                    if (entityInfo->frozenClassStatus.status != STATUS_FROZEN) {
                        TrySendImmobilizeSleepEndMsg(entity, entity);
                        DealDamageToEntity(entity, hp, 9, 0x20D);
                        if (dmgUser) {
                            TrySendImmobilizeSleepEndMsg(target, target);
                            DealDamageToEntity(target, hp, 0xD, 0x1FA);
                        }
                        else {
                            HealTargetHP(target, target, hp, 0, TRUE);
                        }
                    }
                }
            }
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->perishSongTurns != 0) {
        sub_80838EC(&entityInfo->perishSongTurns);
        if (entityInfo->perishSongTurns == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1], entity, 0);
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FEB30);
            TrySendImmobilizeSleepEndMsg(entity, entity);
            if (entityInfo->reflectClassStatus.status == STATUS_PROTECT) {
                LogMessageByIdWithPopupCheckUser(entity, gPtrProtectSavedItMessage);
            }
            else {
                DealDamageToEntity(entity, 0x270F, 0xB, 0x20E);
            }
            if (!EntityExists(entity) || sub_8044B28())
                return;
        }
    }

    if (entityInfo->bideClassStatus.status == STATUS_BIDE) {
        sub_80838EC(&entityInfo->bideClassStatus.turns);
        if (entityInfo->bideClassStatus.turns == 0) {
            entityInfo->bideClassStatus.status = 0;
            if (!CheckVariousStatuses2(entity, FALSE) && !CannotAttack(entity, FALSE) && !CheckVariousStatuses(entity)) {
                Move bideMove;

                UseAttack(NULL);
                InitPokemonMove(&bideMove, MOVE_BIDE_2);
                bideMove.moveFlags |= MOVE_FLAG_LAST_USED;
                TryUseChosenMove(entity, 0, 0, 0, 0, &bideMove);
                if (!EntityExists(entity) || sub_8044B28())
                    return;
                entityInfo->unkA0 = 0;
            }
        }
    }

    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->bideClassStatus.status == STATUS_ENRAGED) {
        sub_80838EC(&entityInfo->bideClassStatus.turns);
        if (entityInfo->bideClassStatus.turns == 0) {
            entityInfo->bideClassStatus.status = 0;
            entityInfo->unk14A = 0;
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FABD8);
        }
    }

    if (!EntityExists(entity) || sub_8044B28())
        return;
}

void TickStatusHeal(Entity *entity)
{
    s32 i;
    bool32 spdChange;
    EntityInfo *entityInfo;

    if (entity == NULL)
        return;
    if (!EntityExists(entity) || sub_8044B28())
        return;

    sub_805229C();
    entityInfo = GetEntInfo(entity);

    // HP heal
    if (entityInfo->unk146 == 0 && entityInfo->burnClassStatus.status != STATUS_POISONED && entityInfo->burnClassStatus.status != STATUS_BADLY_POISONED) {
        s32 regenSpeed = 0;

        if (!entityInfo->isNotTeamMember)
            regenSpeed = GetRegenSpeed(entityInfo->id);

        if (regenSpeed != 0) {
            if (HasHeldItem(entity, ITEM_HEAL_RIBBON))
                regenSpeed += gHealRibbonRegenValue;
            if (entityInfo->reflectClassStatus.status == STATUS_WISH)
                regenSpeed += gWishRegenValue;
            if (AbilityIsActive(entity, ABILITY_RAIN_DISH) && GetApparentWeather(entity) == WEATHER_RAIN)
                regenSpeed += gRainDishRegenValue;

            if (regenSpeed > 500)
                regenSpeed = 500;
            if (regenSpeed < 30)
                regenSpeed = 30;

            entityInfo->unk1F8 += entityInfo->maxHPStat;
            while (entityInfo->unk1F8 >= regenSpeed) {
                entityInfo->HP++;
                entityInfo->unk1F8 -= regenSpeed;
            }

            if (entityInfo->HP >= entityInfo->maxHPStat)
                entityInfo->HP = entityInfo->maxHPStat;
        }
    }

    if (entityInfo->sleepClassStatus.status != 0) {
        sub_80838EC(&entityInfo->sleepClassStatus.turns);
        if (entityInfo->sleepClassStatus.turns == 0) {
            EndSleepClassStatus(entity, entity, TRUE, TRUE);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->burnClassStatus.status != 0) {
        sub_80838EC(&entityInfo->burnClassStatus.turns);
        if (entityInfo->burnClassStatus.turns == 0) {
            EndBurnClassStatus(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->frozenClassStatus.status != 0) {
        sub_80838EC(&entityInfo->frozenClassStatus.turns);
        if (entityInfo->frozenClassStatus.turns == 0) {
            EndFrozenClassStatus(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->cringeClassStatus.status != 0) {
        sub_80838EC(&entityInfo->cringeClassStatus.turns);
        if (entityInfo->cringeClassStatus.turns == 0) {
            EndCringeClassStatus(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->reflectClassStatus.status != 0) {
        sub_80838EC(&entityInfo->reflectClassStatus.turns);
        if (entityInfo->reflectClassStatus.turns == 0) {
            EndReflectClassStatus(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->curseClassStatus.status != 0) {
        sub_80838EC(&entityInfo->curseClassStatus.turns);
        if (entityInfo->curseClassStatus.turns == 0) {
            EndCurseClassStatus(entity, entity, 0);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->leechSeedClassStatus.status != 0) {
        sub_80838EC(&entityInfo->leechSeedClassStatus.turns);
        if (entityInfo->leechSeedClassStatus.turns == 0) {
            EndLeechSeedClassStatus(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->sureShotClassStatus.status != 0) {
        sub_80838EC(&entityInfo->sureShotClassStatus.turns);
        if (entityInfo->sureShotClassStatus.turns == 0) {
            SendMoveEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->invisibleClassStatus.status != 0) {
        sub_80838EC(&entityInfo->invisibleClassStatus.turns);
        if (entityInfo->invisibleClassStatus.turns == 0) {
            SendTransformEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->blinkerClassStatus.status != 0) {
        sub_80838EC(&entityInfo->blinkerClassStatus.turns);
        if (entityInfo->blinkerClassStatus.turns == 0) {
            SendEyesightEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->muzzled.muzzled != 0) {
        sub_80838EC(&entityInfo->muzzled.turns);
        if (entityInfo->muzzled.turns == 0) {
            SendMuzzledEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->terrifiedTurns != 0) {
        sub_80838EC(&entityInfo->terrifiedTurns);
        if (entityInfo->terrifiedTurns == 0) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
            LogMessageByIdWithPopupCheckUser(entity, gPtrStenchWavedOffMessage);
        }
    }

    spdChange = FALSE;
    for (i = 0; i < NUM_SPEED_COUNTERS; i++) {
        if (entityInfo->speedDownCounters[i] != 0) {
            sub_80838EC(&entityInfo->speedDownCounters[i]);
            if (entityInfo->speedDownCounters[i] == 0)
                spdChange = TRUE;
        }

        if (entityInfo->speedUpCounters[i] != 0) {
            sub_80838EC(&entityInfo->speedUpCounters[i]);
            if (entityInfo->speedUpCounters[i] == 0)
                spdChange = TRUE;
        }
    }
    if (spdChange) {
        s32 oldSpdStage = GetEntInfo(entity)->speedStage;
        s32 newSpdStage = CalcSpeedStage(entity);

        if (oldSpdStage != newSpdStage) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
            LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FA124[newSpdStage]);
        }
    }
}

void sub_8074FB0(Entity *entity, s32 a1, DungeonPos *pos)
{
    Unk_Entity_x184 *strPtr;
    EntityInfo *entityInfo = GetEntInfo(entity);

    if (entityInfo->numMoveTiles > 3) {
        entityInfo->action.action = 0;
        return;
    }

    if (gGameOptionsRef->dungeonSpeed != 0)
        gUnknown_202F378 = 2;
    else
        gUnknown_202F378 = 1;

    strPtr = &entityInfo->unk184[entityInfo->numMoveTiles];
    strPtr->unk1A = 0;
    strPtr->lastMoveDirection = a1;
    strPtr->previousTargetMovePosition1.x = entity->pos.x;
    strPtr->previousTargetMovePosition1.y = entity->pos.y;
    strPtr->previousTargetMovePosition2.x = pos->x;
    strPtr->previousTargetMovePosition2.y = pos->y;
    strPtr->lastMoveIncrement.x = gUnknown_80F4D44[a1].x * gUnknown_202F378;
    strPtr->lastMoveIncrement.y = gUnknown_80F4D44[a1].y * gUnknown_202F378;
    sub_8075050(entityInfo, strPtr);
}

void sub_8075050(EntityInfo *info, Unk_Entity_x184 *strPtr)
{
    s32 savedX, savedY;

    if (gGameOptionsRef->dungeonSpeed != 0)
        gUnknown_202F378 = 2;
    else
        gUnknown_202F378 = 1;

    info->numMoveTiles++;
    if (info->numMoveTiles == 2) {
        info->unk184[0].walkAnimFramesLeft = 24 / (gUnknown_202F378 * 2);
        info->unk184[0].lastMoveIncrement.x *= 2;
        info->unk184[0].lastMoveIncrement.y *= 2;
        strPtr->walkAnimFramesLeft = 24 / (gUnknown_202F378 * 2);
        strPtr->lastMoveIncrement.x *= 2;
        strPtr->lastMoveIncrement.y *= 2;
    }
    else if (info->numMoveTiles == 3) {
        s32 i;

        savedX = strPtr->lastMoveIncrement.x;
        savedY = strPtr->lastMoveIncrement.y;
        for (i = 0; i < 2; i++) {
            info->unk184[i].walkAnimFramesLeft = 24 / (gUnknown_202F378 * 3);
            info->unk184[i].lastMoveIncrement.x *= 3;
            info->unk184[i].lastMoveIncrement.y *= 3;
            info->unk184[i].lastMoveIncrement.x /= 2;
            info->unk184[i].lastMoveIncrement.y /= 2;
        }
        strPtr->walkAnimFramesLeft = 24 / (gUnknown_202F378 * 3);
        strPtr->lastMoveIncrement.x = savedX * 3;
        strPtr->lastMoveIncrement.y = savedY * 3;
    }
    else if (info->numMoveTiles == 4) {
        s32 i;

        savedX = strPtr->lastMoveIncrement.x;
        savedY = strPtr->lastMoveIncrement.y;
        for (i = 0; i < 3; i++) {
            info->unk184[i].walkAnimFramesLeft = 24 / (gUnknown_202F378 * 4);
            info->unk184[i].lastMoveIncrement.x *= 4;
            info->unk184[i].lastMoveIncrement.y *= 4;
            info->unk184[i].lastMoveIncrement.x /= 3;
            info->unk184[i].lastMoveIncrement.y /= 3;
        }
        strPtr->walkAnimFramesLeft = 24 / (gUnknown_202F378 * 4);
        strPtr->lastMoveIncrement.x = savedX * 4;
        strPtr->lastMoveIncrement.y = savedY * 4;
    }
    else {
        strPtr->walkAnimFramesLeft = 24 / gUnknown_202F378;
    }
}

bool8 UseAttack(Entity *a0)
{
    s32 i, j, loop;
    Entity *savedEntityPtr;
    bool32 r7 = FALSE;
    bool32 r9 = FALSE;

    gUnknown_202F32D = 0;
    if (gGameOptionsRef->dungeonSpeed != 0)
        gUnknown_202F378 = 2;
    else
        gUnknown_202F378 = 1;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (EntityExists(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            if (monInfo->numMoveTiles == 0) {
                if (monInfo->waiting) {
                    monInfo->waiting = FALSE;
                    if ((monInfo->targetPos.x != 0 || monInfo->targetPos.y != 0)
                        && (monInfo->targetPos.x != mon->pos.x || monInfo->targetPos.y != mon->pos.y)
                        && (!CheckVariousStatuses2(mon, TRUE) || !CheckVariousStatuses(mon)))
                    {
                        s32 direction = GetDirectionTowardsPosition(&mon->pos, &monInfo->targetPos);
                        if (direction != monInfo->action.direction)
                            sub_806CE68(mon, direction);
                    }
                }
            }
            else {
                PixelPos pos;

                monInfo->flags |= 0x2000;
                pos.x = (monInfo->unk184[0].previousTargetMovePosition2.x * 0x1800) + 0xC00;
                pos.y = (monInfo->unk184[0].previousTargetMovePosition2.y * 0x1800) + 0x1000;
                sub_804535C(mon, &pos);
                sub_806CDFC(mon, 0, monInfo->unk184[0].lastMoveDirection);
                monInfo->notMoving = 0;
                r7 = TRUE;
                if (sub_8045888(mon))
                    r9 = TRUE;
            }
        }
    }

    if (!r7)
        return FALSE;

    savedEntityPtr = gDungeon->unkB8;
    gDungeon->unkB8 = a0;
    if (gDungeon->unk644.unk28 == 0 && r9) {
        sub_80526D0(0x35);
        for (loop = 0; loop < 24 / gUnknown_202F378; loop++) {
            sub_803E46C(7);
            for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
                Entity *mon = gDungeon->activePokemon[i];
                if (EntityExists(mon)) {
                    EntityInfo *monInfo = GetEntInfo(mon);
                    Unk_Entity_x184 *strPtr = &monInfo->unk184[monInfo->notMoving];

                    ASM_MATCH_TRICK(i);
                    if (monInfo->numMoveTiles != 0) {
                        IncreaseEntityPixelPos(mon, strPtr->lastMoveIncrement.x, strPtr->lastMoveIncrement.y);
                        if (--strPtr->walkAnimFramesLeft == 0) {
                            if (++monInfo->notMoving == monInfo->numMoveTiles) {
                                monInfo->numMoveTiles = 0;
                            }
                            else {
                                PixelPos pos;

                                pos.x = (monInfo->unk184[monInfo->notMoving].previousTargetMovePosition2.x * 0x1800) + 0xC00;
                                pos.y = (monInfo->unk184[monInfo->notMoving].previousTargetMovePosition2.y * 0x1800) + 0x1000;
                                sub_804535C(mon, &pos);
                                sub_806CDFC(mon, 0, monInfo->unk184[monInfo->notMoving].lastMoveDirection);
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (EntityExists(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            monInfo->numMoveTiles = 0;
            nullsub_97(mon);
            if (monInfo->flags & 0x2000) {
                sub_804535C(mon, NULL);
            }
        }
    }

    sub_807AA30();
    for (j = 0; j < 2; j++) {
        for (loop = 0; loop < DUNGEON_MAX_POKEMON; loop++) {
            DungeonPos monPosBefore;
            EntityInfo *monInfo;
            Entity *mon = gDungeon->activePokemon[loop];

            if (!EntityExists(mon))
                continue;
            if (sub_8044B28())
                break;

            monInfo = GetEntInfo(mon);
            if ((j == 0 && !monInfo->isTeamLeader) || (j != 0 && monInfo->isTeamLeader))
                continue;

            monPosBefore = mon->pos;

            // Statement with no effect needed to match.
            GetEntInfo(mon)->isTeamLeader = GetEntInfo(mon)->isTeamLeader;

            if (monInfo->flags & 0x2000) {
                monInfo->flags &= ~(0x2000);
                if (monInfo->isTeamLeader) {
                    sub_804AC20(&mon->pos);
                    sub_807EC28(FALSE);
                    sub_805EE30();
                }
                else {
                    sub_8075708(mon);
                }
                if (!EntityExists(mon))
                    continue;
                if (sub_8044B28())
                    break;

                sub_8043ED0(0);
                sub_8074094(mon);
                if (!EntityExists(mon))
                    continue;
                if (sub_8044B28())
                    break;

                sub_8071DA4(mon);
                sub_8046D20();
                sub_8075900(mon, gDungeon->forceMonsterHouse);
            }
            if (!EntityExists(mon))
                continue;
            if (sub_8044B28())
                break;

            if (monPosBefore.x != mon->pos.x || monPosBefore.y != mon->pos.y)
                gUnknown_202F32D = 1;

            sub_806A5B8(mon);
            if (sub_80706A4(mon, &mon->pos)) {
                WarpTarget(mon, mon, 0, NULL);
            }
        }
    }

    sub_8086AC0();
    if (!sub_8044B28()) {
        sub_8085140();
        gDungeon->unkB8 = savedEntityPtr;
    }
    else {
        gDungeon->unkB8 = savedEntityPtr;
    }

    return TRUE;
}

