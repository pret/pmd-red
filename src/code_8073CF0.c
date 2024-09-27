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
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "dungeon_pokemon_attributes.h"

extern bool8 sub_8044B28(void);
extern void sub_8075708(Entity *entity);
extern void sub_80526D0(u8 r0);
extern void DealDamageToEntity(Entity *, s32, u32, u32);
extern void sub_8067110(Entity *);
extern void sub_80671A0(Entity *);
extern void sub_8073D14(Entity *);
extern void sub_8045BF8(u8 *, Item *);
extern void sub_805239C(Entity *, const u8 *);
extern bool8 sub_80461C8(Position *, u32);
extern void sub_805229C(void);
extern void sub_807E8F0(Entity *);
extern void sub_80444F4(Entity *pokemon);
extern void sub_807D148(Entity *pokemon, Entity *r1, u32 r2, Position *r3);
extern void sub_800A34C(struct unkStruct_80943A8 *, struct unkStruct_80943A8 *, const u8 *);
extern void sub_80420B8(Entity *pokemon);
extern void sub_8041C4C(Entity *pokemon, u32 r1);
extern void sub_805E804(void);
extern void sub_80838EC(u8 *a);
extern bool8 sub_8055FA0(struct Entity *, u32, u32, u32, u32, struct Move *);
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
extern u8 gFormatItems[];
extern u8 gUnknown_202DFE8[];
extern u8 gAvailablePokemonNames[];

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
extern const s16 gUnknown_80F4FC8[];
extern const s16 gUnknown_80F4F8E;
extern const s16 gUnknown_80F4E0C;
extern const s16 gUnknown_80F4F32;
extern const s16 gUnknown_80F4F34;
extern const s16 gUnknown_80F4F70;
extern const s16 gUnknown_80F4F72;
extern const s16 gUnknown_80F4F30;
extern const s16 gUnknown_80F4F38;
extern const s16 gUnknown_80F4FC4;
extern const s16 gUnknown_80F4FC0;
extern const s16 gUnknown_80F4F3A;
extern const s16 gUnknown_80F4F3C;
extern const s16 gUnknown_80F4FB2;
extern const s16 gUnknown_80F4F3E;
extern const s16 gUnknown_80F4FB4;
extern const s16 gUnknown_80F4F40;
extern const s16 gUnknown_80F4F74;
extern const s16 gUnknown_80F4FC2;
extern const s16 gUnknown_80F4F76;
extern const s16 gUnknown_80F4F36;
extern const u8 gUnknown_80F54F4[][8];
extern const s32 gUnknown_80F60DC[];

extern const Position gUnknown_80F4D44[];

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
    EntityInfo *entityInfo = entity->axObj.info;
    Entity *tileObject = GetTileAtEntitySafe(entity)->object;
    if (tileObject == NULL)
        return;
    if (sub_8044B28())
        return;
    SetMessageArgument(gAvailablePokemonNames, entity, 0);
    if (entityInfo->isTeamLeader)
        return;
    if (entityInfo->shopkeeper == 1)
        return;
    if (IsClientOrTeamBase(entityInfo->joinedAt.joinedAt))
        return;
    if (entityInfo->clientType == 1)
        return;

    _entityInfo = entity->axObj.info; // Reloaded as a new variable for some reason.
    groundItem = GetItemData(tileObject);
    if (groundItem->flags & ITEM_FLAG_IN_SHOP)
        return;

    if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        sub_8045BF8(gFormatItems, groundItem);
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        sub_805239C(entity, gMonTerrifiedCouldntPickUpItem);
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
        sub_8045BF8(gFormatItems, groundItem);
        sub_80461C8(&entity->pos, 1);
        sub_805239C(entity, gMonPickedUpItem);
    }
    else {
        s32 i, nItems, newInventoryId;
        s32 inventoryIds[INVENTORY_SIZE + 1]; // plus held
        Item *carriedItems[INVENTORY_SIZE + 1]; // plus held
        s32 newQuantity;

        if (gDungeon->unk65B && !_entityInfo->isNotTeamMember) {
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

                sub_8045BF8(gFormatItems, groundItem);
                sub_80461C8(&entity->pos, 1);
                PlaySoundEffect(0x14A);
                if (inventoryIds[newInventoryId] <= -1)
                    sub_805239C(entity, gMonPickedUpItem2);
                else
                    sub_805239C(entity, gMonPickedUpItemToolbox);

                return;
            }
        }

        for (i = 0; i < nItems; i++) {
            if (!(carriedItems[i]->flags & ITEM_FLAG_EXISTS))
                break;
        }

        if (i == nItems) {
            sub_8045BF8(gFormatItems, groundItem);
            sub_805239C(entity, gMonSteppedOnItem);
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
                sub_8045BF8(gFormatItems, groundItem);
                sub_80461C8(&entity->pos, 1);
                sub_805239C(entity, gMonPickedUpItem2);
            }
            else if (AddItemToInventory(groundItem)) {
                SetMessageArgument(gAvailablePokemonNames, entity, 0);
                sub_805239C(entity, gMonCouldntPickUpItem);
            }
            else {
                sub_8045BF8(gFormatItems, groundItem);
                sub_80461C8(&entity->pos, 1);
                sub_805239C(entity, gMonPickedUpItemToolbox);
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

    entityInfo = entity->axObj.info;
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
            sub_807D148(entity, entity, 0, NULL);
            if (entityInfo->isTeamLeader) {
                gDungeon->unk1 = 0;
                gDungeon->unk5C0 = -1;
            }
        }
    }

    if (entityInfo->isTeamLeader) {
        struct unkStruct_80943A8 sp8, sp10;
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

        sp8.s0 = 0;
        sp8.s4 = 6554;
        sub_800A34C(&sp10, &sp8, gUnknown_80F54F4[r4]);
        if (entityInfo->unk153 > 1)
            sp10.s4 += (gUnknown_80F60DC[entityInfo->unk153] << 0x10);
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
            if (gDungeon->unk679 < 10)
                gDungeon->unk679++;
            if (gDungeon->unk679 == 1)
                str = gUnknown_80FD5DC;
            if (gDungeon->unk679 == 2)
                str = gUnknown_80FD608, sound = FALSE;
            if (gDungeon->unk679 == 3)
                str = gUnknown_80FD628, sound = FALSE;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, 1, 0xE, 0x211);
            entityInfo->unk146 = 1;
            if (FixedPointToInt(entityInfo->belly) != 0)
                str = NULL;
        }
        else {
            gDungeon->unk679 = 0;
        }

        if (str != NULL) {
            if (sound)
                PlaySoundEffect(0x153);
            SendMessage(entity, str);
            sub_803E708(0x1E, 0x32);
        }
    }

    if (!EntityExists(entity) || sub_8044B28())
        return;
    if (gDungeon->weather.weatherDamageCounter == 0) {
        if (GetApparentWeather(entity) == WEATHER_HAIL) {
            if (!MonsterIsType(entity, TYPE_ICE)) {
                DealDamageToEntity(entity, gUnknown_80F4F8E, 0x12, 0x220);
            }
        }
        else if (GetApparentWeather(entity) == WEATHER_SANDSTORM) {
            if (!MonsterIsType(entity, TYPE_GROUND) && !MonsterIsType(entity, TYPE_ROCK) && !MonsterIsType(entity, TYPE_STEEL)) {
                DealDamageToEntity(entity, gUnknown_80F4F8E, 0x12, 0x220);
            }
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

// Abilities check
    rand = DungeonRandInt(100);
    if (HasAbility(entity, ABILITY_SHED_SKIN) && rand < gUnknown_80F4E0C && HasNegativeStatus(entity)) {
        UseAttack(NULL);
        if (!EntityExists(entity) || sub_8044B28())
            return;
        sub_8079F20(entity, entity, 1, 0);
    }
    if (HasAbility(entity, ABILITY_SPEED_BOOST)) {
        entityInfo->unk113++;
        if (entityInfo->unk113 >= gUnknown_80F4F30) {
            entityInfo->unk113 = 0;
            RaiseMovementSpeedTarget(entity, entity, 0x7F, FALSE);
        }
    }

// Statuses
    if (entityInfo->sleep.sleep == STATUS_YAWNING) {
        UseAttack(NULL);
        if (!EntityExists(entity) || sub_8044B28())
            return;
        sub_80420B8(entity);
    }

    if (entityInfo->nonVolatile.nonVolatileStatus == STATUS_BURN) {
        if (entityInfo->nonVolatile.nonVolatileStatusDamageCountdown == 0 || --entityInfo->nonVolatile.nonVolatileStatusDamageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = gUnknown_80F4F32;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gUnknown_80F4F70, 1, 0x208);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->nonVolatile.nonVolatileStatus == STATUS_POISONED) {
        if (entityInfo->nonVolatile.nonVolatileStatusDamageCountdown == 0 || --entityInfo->nonVolatile.nonVolatileStatusDamageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = gUnknown_80F4F34;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gUnknown_80F4F72, 3, 0x20A);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }
    else if (entityInfo->nonVolatile.nonVolatileStatus == STATUS_BADLY_POISONED) {
        if (entityInfo->nonVolatile.nonVolatileStatusDamageCountdown == 0 || --entityInfo->nonVolatile.nonVolatileStatusDamageCountdown == 0) {
            s32 turns = entityInfo->nonVolatile.unk4;
            if (entityInfo->nonVolatile.unk4 < 29)
                entityInfo->nonVolatile.unk4++;
            entityInfo->nonVolatile.nonVolatileStatusDamageCountdown = gUnknown_80F4F36;
            if (turns >= 29)
                turns = 29;

            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gUnknown_80F4FC8[turns], 3, 0x20A);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->immobilize.immobilizeStatus == STATUS_CONSTRICTION) {
        if (entityInfo->immobilize.immobilizeStatusDamageCountdown == 0 || --entityInfo->immobilize.immobilizeStatusDamageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->immobilize.immobilizeStatusDamageCountdown = gUnknown_80F4F38;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            sub_8041C4C(entity, entityInfo->immobilize.unk4);
            DealDamageToEntity(entity, gUnknown_80F4F74, 2, 0x209);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }
    else if (entityInfo->immobilize.immobilizeStatus == STATUS_WRAPPED) {
        if (entityInfo->immobilize.immobilizeStatusDamageCountdown == 0 || --entityInfo->immobilize.immobilizeStatusDamageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->immobilize.immobilizeStatusDamageCountdown = gUnknown_80F4F3A;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gUnknown_80F4F76, 5, 0x20B);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }
    else if (entityInfo->immobilize.immobilizeStatus == STATUS_INGRAIN) {
        if (entityInfo->immobilize.immobilizeStatusDamageCountdown == 0 || --entityInfo->immobilize.immobilizeStatusDamageCountdown == 0) {
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;
            entityInfo->immobilize.immobilizeStatusDamageCountdown = gUnknown_80F4F3C;
            HealTargetHP(entity, entity, gUnknown_80F4FB2, 0, TRUE);
        }
    }

    if (entityInfo->waitingStruct.waitingStatus == STATUS_CURSED) {
        if (entityInfo->waitingStruct.curseDamageCountdown == 0 || --entityInfo->waitingStruct.curseDamageCountdown == 0) {
            s32 dmg = entityInfo->maxHPStat / 4;
            if (dmg == 0)
                dmg = 1;
            entityInfo->waitingStruct.curseDamageCountdown = gUnknown_80F4F3E;
            UseAttack(NULL);
            if (!EntityExists(entity) || sub_8044B28())
                return;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, dmg, 7, 0x20C);
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    if (entityInfo->linked.linkedStatus == STATUS_LEECH_SEED) {
        if (entityInfo->linked.linkedStatusDamageCountdown == 0 || --entityInfo->linked.linkedStatusDamageCountdown == 0) {
            s32 hp = gUnknown_80F4FB4;
            Entity *target = gDungeon->allPokemon[entityInfo->linked.unkD8];

            entityInfo->linked.linkedStatusDamageCountdown = gUnknown_80F4F40;
            if (target == NULL) {
                entityInfo->linked.linkedStatus = 0;
            }
            else {
                EntityInfo *targetInfo = target->axObj.info;
                if (targetInfo->unk98 != entityInfo->linked.unkD4) {
                    entityInfo->linked.linkedStatus = 0;
                }
                else {
                    bool8 dmgUser = HasAbility(entity, ABILITY_LIQUID_OOZE);
                    sub_80444F4(entity);
                    UseAttack(NULL);
                    if (!EntityExists(entity) || !EntityExists(target) || sub_8044B28())
                        return;

                    if (entityInfo->immobilize.immobilizeStatus != STATUS_FROZEN) {
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
            SetMessageArgument(gUnknown_202DFE8, entity, 0);
            SendMessage(entity, gUnknown_80FEB30);
            TrySendImmobilizeSleepEndMsg(entity, entity);
            if (entityInfo->protection.protectionStatus == STATUS_PROTECT) {
                SendMessage(entity, gPtrProtectSavedItMessage);
            }
            else {
                DealDamageToEntity(entity, 0x270F, 0xB, 0x20E);
            }
            if (!EntityExists(entity) || sub_8044B28())
                return;
        }
    }

    if (entityInfo->charging.chargingStatus == STATUS_BIDE) {
        sub_80838EC(&entityInfo->charging.chargingStatusTurns);
        if (entityInfo->charging.chargingStatusTurns == 0) {
            entityInfo->charging.chargingStatus = 0;
            if (!CheckVariousStatuses2(entity, FALSE) && !CannotAttack(entity, FALSE) && !CheckVariousStatuses(entity)) {
                Move bideMove;

                UseAttack(NULL);
                InitPokemonMove(&bideMove, MOVE_BIDE_2);
                bideMove.moveFlags |= MOVE_FLAG_LAST_USED;
                sub_8055FA0(entity, 0, 0, 0, 0, &bideMove);
                if (!EntityExists(entity) || sub_8044B28())
                    return;
                entityInfo->unkA0 = 0;
            }
        }
    }

    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->charging.chargingStatus == STATUS_ENRAGED) {
        sub_80838EC(&entityInfo->charging.chargingStatusTurns);
        if (entityInfo->charging.chargingStatusTurns == 0) {
            entityInfo->charging.chargingStatus = 0;
            entityInfo->unk14A = 0;
            SetMessageArgument(gAvailablePokemonNames, entity, 0);
            SendMessage(entity, gUnknown_80FABD8);
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
    entityInfo = entity->axObj.info;

    // HP heal
    if (entityInfo->unk146 == 0 && entityInfo->nonVolatile.nonVolatileStatus != STATUS_POISONED && entityInfo->nonVolatile.nonVolatileStatus != STATUS_BADLY_POISONED) {
        s32 r4 = 0;

        if (!entityInfo->isNotTeamMember)
            r4 = GetRegenSpeed(entityInfo->id);

        if (r4 != 0) {
            if (HasHeldItem(entity, ITEM_HEAL_RIBBON))
                r4 += gUnknown_80F4FC4;
            if (entityInfo->protection.protectionStatus == STATUS_WISH)
                r4 += gUnknown_80F4FC0;
            if (HasAbility(entity, ABILITY_RAIN_DISH) && GetApparentWeather(entity) == WEATHER_RAIN)
                r4 += gUnknown_80F4FC2;

            if (r4 > 500)
                r4 = 500;
            if (r4 < 30)
                r4 = 30;

            entityInfo->unk1F8 += entityInfo->maxHPStat;
            while (entityInfo->unk1F8 >= r4) {
                entityInfo->HP++;
                entityInfo->unk1F8 -= r4;
            }

            if (entityInfo->HP >= entityInfo->maxHPStat)
                entityInfo->HP = entityInfo->maxHPStat;
        }
    }

    if (entityInfo->sleep.sleep != 0) {
        sub_80838EC(&entityInfo->sleep.sleepTurns);
        if (entityInfo->sleep.sleepTurns == 0) {
            SendSleepEndMessage(entity, entity, TRUE, TRUE);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->nonVolatile.nonVolatileStatus != 0) {
        sub_80838EC(&entityInfo->nonVolatile.nonVolatileStatusTurns);
        if (entityInfo->nonVolatile.nonVolatileStatusTurns == 0) {
            SendNonVolatileEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->immobilize.immobilizeStatus != 0) {
        sub_80838EC(&entityInfo->immobilize.immobilizeStatusTurns);
        if (entityInfo->immobilize.immobilizeStatusTurns == 0) {
            SendImmobilizeEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->volatileStatus.volatileStatus != 0) {
        sub_80838EC(&entityInfo->volatileStatus.volatileStatusTurns);
        if (entityInfo->volatileStatus.volatileStatusTurns == 0) {
            SendVolatileEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->protection.protectionStatus != 0) {
        sub_80838EC(&entityInfo->protection.protectionStatusTurns);
        if (entityInfo->protection.protectionStatusTurns == 0) {
            SendProtectionEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->waitingStruct.waitingStatus != 0) {
        sub_80838EC(&entityInfo->waitingStruct.waitingStatusTurns);
        if (entityInfo->waitingStruct.waitingStatusTurns == 0) {
            SendWaitingEndMessage(entity, entity, 0);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->linked.linkedStatus != 0) {
        sub_80838EC(&entityInfo->linked.linkedStatusTurns);
        if (entityInfo->linked.linkedStatusTurns == 0) {
            SendLinkedEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->moveStatus.moveStatus != 0) {
        sub_80838EC(&entityInfo->moveStatus.moveStatusTurns);
        if (entityInfo->moveStatus.moveStatusTurns == 0) {
            SendMoveEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->transformStatus.transformStatus != 0) {
        sub_80838EC(&entityInfo->transformStatus.transformStatusTurns);
        if (entityInfo->transformStatus.transformStatusTurns == 0) {
            SendTransformEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->eyesightStatus.eyesightStatus != 0) {
        sub_80838EC(&entityInfo->eyesightStatus.eyesightStatusTurns);
        if (entityInfo->eyesightStatus.eyesightStatusTurns == 0) {
            SendEyesightEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->muzzled.muzzled != 0) {
        sub_80838EC(&entityInfo->muzzled.muzzledTurns);
        if (entityInfo->muzzled.muzzledTurns == 0) {
            SendMuzzledEndMessage(entity, entity);
        }
    }
    if (!EntityExists(entity) || sub_8044B28())
        return;

    if (entityInfo->terrifiedTurns != 0) {
        sub_80838EC(&entityInfo->terrifiedTurns);
        if (entityInfo->terrifiedTurns == 0) {
            SetMessageArgument(gAvailablePokemonNames, entity, 0);
            SendMessage(entity, gPtrStenchWavedOffMessage);
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
        s32 oldSpdStage = entity->axObj.info->speedStage;
        s32 newSpdStage = CalcSpeedStage(entity);

        if (oldSpdStage != newSpdStage) {
            SetMessageArgument(gAvailablePokemonNames, entity, 0);
            SendMessage(entity, gUnknown_80FA124[newSpdStage]);
        }
    }
}

void sub_8074FB0(Entity *entity, s32 a1, Position *pos)
{
    Unk_Entity_x184 *strPtr;
    EntityInfo *entityInfo = entity->axObj.info;

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
        Entity *mon = gDungeon->allPokemon[i];
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
                Position32 pos;

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
    if (gDungeon->unk66C == 0 && r9) {
        sub_80526D0(0x35);
        for (loop = 0; loop < 24 / gUnknown_202F378; loop++) {
            sub_803E46C(7);
            for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
                Entity *mon = gDungeon->allPokemon[i];
                if (EntityExists(mon)) {
                    EntityInfo *monInfo = GetEntInfo(mon);
                    Unk_Entity_x184 *strPtr = &monInfo->unk184[monInfo->notMoving];

                    #ifndef NONMATCHING
                    // Dummy needed to match, feel free to remove if you do not care about matching.
                    i++;i--;
                    #endif // NONMATCHING
                    if (monInfo->numMoveTiles != 0) {
                        IncreaseEntityPixelPos(mon, strPtr->lastMoveIncrement.x, strPtr->lastMoveIncrement.y);
                        if (--strPtr->walkAnimFramesLeft == 0) {
                            if (++monInfo->notMoving == monInfo->numMoveTiles) {
                                monInfo->numMoveTiles = 0;
                            }
                            else {
                                Position32 pos;

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
        Entity *mon = gDungeon->allPokemon[i];
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
            Position monPosBefore;
            EntityInfo *monInfo;
            Entity *mon = gDungeon->allPokemon[loop];

            if (!EntityExists(mon))
                continue;
            if (sub_8044B28())
                break;

            monInfo = GetEntInfo(mon);
            if ((j == 0 && !monInfo->isTeamLeader) || (j != 0 && monInfo->isTeamLeader))
                continue;

            monPosBefore = mon->pos;

            // Statement with no effect needed to match.
            mon->axObj.info->isTeamLeader = mon->axObj.info->isTeamLeader;

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
                sub_8075900(mon, gDungeon->unk3A08);
            }
            if (!EntityExists(mon))
                continue;
            if (sub_8044B28())
                break;

            if (monPosBefore.x != mon->pos.x || monPosBefore.y != mon->pos.y)
                gUnknown_202F32D = 1;

            sub_806A5B8(mon);
            if (sub_80706A4(mon, &mon->pos)) {
                sub_807D148(mon, mon, 0, NULL);
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

