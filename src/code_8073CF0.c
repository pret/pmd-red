#include "global.h"
#include "dungeon_util.h"
#include "items.h"
#include "dungeon_ai_targeting.h"
#include "code_8045A00.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "dungeon_music.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "number_util.h"
#include "dungeon_pokemon_attributes.h"

extern bool8 sub_8044B28(void);
extern void sub_806F324(Entity *, s32, u32, u32);
extern void sub_8067110(Entity *);
extern void sub_80671A0(Entity *);
extern void sub_8073D14(Entity *);
extern void sub_8045BF8(u8 *, Item *);
extern void sub_805239C(Entity *, const u8 *);
extern bool8 sub_80461C8(Position *, u32);
extern void sub_805229C(void);
extern void sub_807E8F0(Entity *);
extern void sub_80444F4(Entity *pokemon);
extern u8 UseAttack(u32);
extern void sub_807D148(Entity *pokemon, Entity *r1, u32 r2, Position *r3);
extern void sub_800A34C(struct unkStruct_80943A8 *, s32 *, const u8 *);
extern void sub_80420B8(Entity *pokemon, u32 r1);

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[];

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

extern const u8 *gUnknown_80F8F88;
extern const u8 *gUnknown_80F9054;
extern const u8 *gUnknown_80F9018;
extern const u8 *gUnknown_80F9050;
extern const u8 *gUnknown_80F8F54;
extern const u8 *gUnknown_80F8FAC;
extern const u8 *gUnknown_80FD594;
extern const u8 *gUnknown_80FD5B8;
extern const u8 *gUnknown_80FD5DC;
extern const u8 *gUnknown_80FD608;
extern const u8 *gUnknown_80FD628;

void sub_8073D14(Entity *entity)
{
    Item *groundItem;
    EntityInfo *_entityInfo;
    EntityInfo *entityInfo = entity->info;
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

    _entityInfo = entity->info; // Reloaded as a new variable for some reason.
    groundItem = GetItemData(tileObject);
    if (groundItem->flags & ITEM_FLAG_IN_SHOP)
        return;

    if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        sub_8045BF8(gUnknown_202DE58, groundItem);
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        sub_805239C(entity, gUnknown_80F8F88);
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
        sub_8045BF8(gUnknown_202DE58, groundItem);
        sub_80461C8(&entity->pos, 1);
        sub_805239C(entity, gUnknown_80F9054);
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

                sub_8045BF8(gUnknown_202DE58, groundItem);
                sub_80461C8(&entity->pos, 1);
                PlaySoundEffect(0x14A);
                if (inventoryIds[newInventoryId] <= -1)
                    sub_805239C(entity, gUnknown_80F9018);
                else
                    sub_805239C(entity, gUnknown_80F9050);

                return;
            }
        }

        for (i = 0; i < nItems; i++) {
            if (!(carriedItems[i]->flags & ITEM_FLAG_EXISTS))
                break;
        }

        if (i == nItems) {
            sub_8045BF8(gUnknown_202DE58, groundItem);
            sub_805239C(entity, gUnknown_80F8F54);
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
                sub_8045BF8(gUnknown_202DE58, groundItem);
                sub_80461C8(&entity->pos, 1);
                sub_805239C(entity, gUnknown_80F9018);
            }
            else if (AddItemToInventory(groundItem)) {
                SetMessageArgument(gAvailablePokemonNames, entity, 0);
                sub_805239C(entity, gUnknown_80F8FAC);
            }
            else {
                sub_8045BF8(gUnknown_202DE58, groundItem);
                sub_80461C8(&entity->pos, 1);
                sub_805239C(entity, gUnknown_80F9050);
            }
        }
    }
}

extern const s16 gWarpScarfActivationChances[];
extern const s16 gUnknown_80F4F8E;
extern const s16 gUnknown_80F4E0C;
extern const s16 gUnknown_80F4F30;
extern const u8 gUnknown_80F54F4[][8];
extern const s32 gUnknown_80F60DC[];

void sub_8074094(Entity *entity)
{
    s32 rand;
    EntityInfo *entityInfo;

    if (entity == NULL)
        return;
    if (!EntityExists(entity) || sub_8044B28())
        return;

    entityInfo = entity->info;
    entityInfo->unk146 = 0;
    sub_805229C();
    sub_807E8F0(entity);
    if (HasHeldItem(entity, ITEM_WARP_SCARF)) {
        if (++entityInfo->turnsSinceWarpScarfActivation >= 20)
            entityInfo->turnsSinceWarpScarfActivation = 20;
        if (DungeonRandInt(100) > gWarpScarfActivationChances[entityInfo->turnsSinceWarpScarfActivation]) {
            entityInfo->turnsSinceWarpScarfActivation = 0;
            sub_80444F4(entity);
            UseAttack(0);
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
        s32 var_48;
        struct unkStruct_80943A8 var_40;
        FixedPoint var_38;
        FixedPoint bellyBefore;
        bool32 sound;

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
        if (HasHeldItem(entity, ITEM_TWIST_BAND))
            r4++;
        if (HasHeldItem(entity, ITEM_MUNCH_BELT))
            r4++;

        if (r4 < 0)
            r4 = 0;
        if (r4 > 19)
            r4 = 19;

        var_48 = r9;
        var_40.s4 = 6554;
        sub_800A34C(&var_40, &var_48, gUnknown_80F54F4[r4]);
        if (entityInfo->unk153 > 1)
            var_40.s4 += (gUnknown_80F60DC[entityInfo->unk153] << 0x10);
        entityInfo->unk153 = r9;

        bellyBefore = entityInfo->belly;
        var_38 = FixedPoint_SetFromUnk(&var_40);
        entityInfo->belly = FixedPoint_Substract(bellyBefore, var_38);
        sound = TRUE;
        if (FixedPointToInt(bellyBefore) > 19 && FixedPointToInt(entityInfo->belly) < 19)
            str = gUnknown_80FD594;
        if (FixedPointToInt(bellyBefore) > 9 && FixedPointToInt(entityInfo->belly) < 9)
            str = gUnknown_80FD5B8;
        // Why not just do <=
        if (FixedPointToInt(entityInfo->belly) == 0)
            entityInfo->belly = IntToFixedPoint(0);
        if (FixedPointToInt(entityInfo->belly) < 0)
            entityInfo->belly = IntToFixedPoint(0);

        if (FixedPointToInt(entityInfo->belly) == 0) {
            sub_805E804();
            sub_80444F4(entity);
            UseAttack(0);
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

            sub_807A96C(entity, entity);
            sub_806F324(entity, 1, 0xE, 0x211);
            entityInfo->unk146 = 1;
            if (FixedPointToInt(entityInfo->belly) != 0)
                goto AFTER_LEADER_BELLY;
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
AFTER_LEADER_BELLY:
    if (!EntityExists(entity) || sub_8044B28())
        return;
    if (gDungeon->weather.weatherDamageCounter == 0) {
        if (GetApparentWeather(entity) == WEATHER_HAIL) {
            if (!MonsterIsType(entity, TYPE_ICE)) {
                sub_806F324(entity, gUnknown_80F4F8E, 0x12, 0x220);
            }
        }
        else if (GetApparentWeather(entity) == WEATHER_SANDSTORM) {
            if (!MonsterIsType(entity, TYPE_GROUND) && !MonsterIsType(entity, TYPE_ROCK) && !MonsterIsType(entity, TYPE_STEEL)) {
                sub_806F324(entity, gUnknown_80F4F8E, 0x12, 0x220);
            }
        }
        if (!EntityExists(entity) || sub_8044B28())
            return;
    }

    rand = DungeonRandInt(100);
    if (HasAbility(entity, ABILITY_SHED_SKIN) && rand > gUnknown_80F4E0C && HasNegativeStatus(entity)) {
        UseAttack(0);
        if (!EntityExists(entity) || sub_8044B28())
            return;
        sub_8079F20(entity, entity, 1, 0);
    }
    if (HasAbility(entity, ABILITY_SPEED_BOOST)) {
        if (++entityInfo->unk113 > gUnknown_80F4F30) {
            entityInfo->unk113 = 0;
            RaiseMovementSpeedTarget(entity, entity, 0x7F, FALSE);
        }
    }
    if (entityInfo->sleep.sleep == STATUS_YAWNING) {
        UseAttack(0);
        if (!EntityExists(entity) || sub_8044B28())
            return;
        sub_80420B8(entity);
    }
    //
}

