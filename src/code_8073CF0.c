#include "global.h"
#include "globaldata.h"
#include "dungeon_util.h"
#include "items.h"
#include "status.h"
#include "weather.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_moves.h"
#include "position_util.h"
#include "dungeon_music.h"
#include "dungeon_map_access.h"
#include "dungeon_vram.h"
#include "code_806CD90.h"
#include "game_options.h"
#include "dungeon_items.h"
#include "moves.h"
#include "dungeon_random.h"
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
#include "dungeon_logic.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_strings.h"
#include "dungeon_engine.h"
#include "dungeon_damage.h"
#include "dungeon_range.h"
#include "warp_target.h"

extern void sub_805229C(void);
extern void sub_80420B8(Entity *pokemon);
extern void sub_8041C4C(Entity *pokemon, u32 r1);
extern void sub_805E804(void);
extern bool8 TryUseChosenMove(struct Entity *, u32, u32, u32, u32, struct Move *);
extern void nullsub_97(Entity *entity);
extern void sub_805EE30(void);
extern void sub_8086AC0(void);
extern void sub_8085140(void);
extern void sub_8075708(Entity *entity);
extern void sub_8043ED0(u32);
extern void EnemyEvolution(Entity *);
extern void sub_8075900(Entity *pokemon, u8 r1);
extern void sub_806A5B8(Entity *);

bool8 DisplayActions(Entity *a0);

void sub_8074094(Entity *entity)
{
    s32 rand;
    EntityInfo *entityInfo;

    if (entity == NULL)
        return;
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    entityInfo = GetEntInfo(entity);
    entityInfo->unk146 = 0;
    sub_805229C();
    sub_807E8F0(entity);
    if (HasHeldItem(entity, ITEM_WARP_SCARF)) {
        if (++entityInfo->turnsSinceWarpScarfActivation >= WARP_SCARF_ACTIVATION_CHANCES_COUNT)
            entityInfo->turnsSinceWarpScarfActivation = WARP_SCARF_ACTIVATION_CHANCES_COUNT - 1;
        if (DungeonRandInt(100) < gWarpScarfActivationChances[entityInfo->turnsSinceWarpScarfActivation]) {
            entityInfo->turnsSinceWarpScarfActivation = 0;
            sub_80444F4(entity);
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
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
        s32 arrIndex = 10;
        if (HasHeldItem(entity, ITEM_TIGHT_BELT))
            arrIndex = 0;
        if (HasHeldItem(entity, ITEM_STAMINA_BAND))
            arrIndex--;
        if (IQSkillIsEnabled(entity, IQ_ENERGY_SAVER))
            arrIndex--;
        if (HasHeldItem(entity, ITEM_DIET_RIBBON))
            arrIndex++;
        if (HasHeldItem(entity, ITEM_HEAL_RIBBON))
            arrIndex++;
        if (HasHeldItem(entity, ITEM_MUNCH_BELT))
            arrIndex++;

        if (arrIndex < 0)
            arrIndex = 0;
        if (arrIndex >= BELLY_GO_DOWN_VALUES_COUNT)
            arrIndex = BELLY_GO_DOWN_VALUES_COUNT - 1;

        sp8.hi = 0;
        sp8.lo = 6554;
        F48_16_SMul(&sp10, &sp8, &gBellyGoDownValues[arrIndex]);
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
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
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

    if (!EntityIsValid(entity) || IsFloorOver())
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
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }

// Abilities check
    rand = DungeonRandInt(100);
    if (AbilityIsActive(entity, ABILITY_SHED_SKIN) && rand < gShedSkinActivateChance && HasNegativeStatus(entity)) {
        DisplayActions(NULL);
        if (!EntityIsValid(entity) || IsFloorOver())
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
        DisplayActions(NULL);
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
        sub_80420B8(entity);
    }

    if (entityInfo->burnClassStatus.status == STATUS_BURN) {
        if (entityInfo->burnClassStatus.damageCountdown == 0 || --entityInfo->burnClassStatus.damageCountdown == 0) {
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
                return;
            entityInfo->burnClassStatus.damageCountdown = gBurnDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gBurnDmgValue, 1, 0x208);
        }
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }

    if (entityInfo->burnClassStatus.status == STATUS_POISONED) {
        if (entityInfo->burnClassStatus.damageCountdown == 0 || --entityInfo->burnClassStatus.damageCountdown == 0) {
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
                return;
            entityInfo->burnClassStatus.damageCountdown = gPoisonDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gPoisonDmgValue, 3, 0x20A);
        }
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }
    else if (entityInfo->burnClassStatus.status == STATUS_BADLY_POISONED) {
        if (entityInfo->burnClassStatus.damageCountdown == 0 || --entityInfo->burnClassStatus.damageCountdown == 0) {
            s32 turns = entityInfo->burnClassStatus.badlyPoisonedDamageCount;
            if (entityInfo->burnClassStatus.badlyPoisonedDamageCount < BAD_POISON_DMG_TURN_VALUES_COUNT - 1)
                entityInfo->burnClassStatus.badlyPoisonedDamageCount++;
            entityInfo->burnClassStatus.damageCountdown = gBadPoisonDmgCountdown;
            if (turns >= BAD_POISON_DMG_TURN_VALUES_COUNT - 1)
                turns = BAD_POISON_DMG_TURN_VALUES_COUNT - 1;

            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
                return;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gBadPoisonDmgValuesByTurn[turns], 3, 0x20A);
        }
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }

    if (entityInfo->frozenClassStatus.status == STATUS_CONSTRICTION) {
        if (entityInfo->frozenClassStatus.damageCountdown == 0 || --entityInfo->frozenClassStatus.damageCountdown == 0) {
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
                return;
            entityInfo->frozenClassStatus.damageCountdown = gConstrictionDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            sub_8041C4C(entity, entityInfo->frozenClassStatus.unk4);
            DealDamageToEntity(entity, gConstrictionDmgValue, 2, 0x209);
        }
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }
    else if (entityInfo->frozenClassStatus.status == STATUS_WRAPPED) {
        if (entityInfo->frozenClassStatus.damageCountdown == 0 || --entityInfo->frozenClassStatus.damageCountdown == 0) {
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
                return;
            entityInfo->frozenClassStatus.damageCountdown = gWrapDmgCountdown;
            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, gWrapDmgValue, 5, 0x20B);
        }
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }
    else if (entityInfo->frozenClassStatus.status == STATUS_INGRAIN) {
        if (entityInfo->frozenClassStatus.damageCountdown == 0 || --entityInfo->frozenClassStatus.damageCountdown == 0) {
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
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
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
                return;

            TrySendImmobilizeSleepEndMsg(entity, entity);
            DealDamageToEntity(entity, dmg, 7, 0x20C);
        }
        if (!EntityIsValid(entity) || IsFloorOver())
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
                if (targetInfo->dungeonSpriteId != entityInfo->leechSeedClassStatus.unk4) {
                    entityInfo->leechSeedClassStatus.status = 0;
                }
                else {
                    bool8 dmgUser = AbilityIsActive(entity, ABILITY_LIQUID_OOZE);
                    sub_80444F4(entity);
                    DisplayActions(NULL);
                    if (!EntityIsValid(entity) || !EntityIsValid(target) || IsFloorOver())
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
        if (!EntityIsValid(entity) || IsFloorOver())
            return;
    }

    if (entityInfo->perishSongTurns != 0) {
        sub_80838EC(&entityInfo->perishSongTurns);
        if (entityInfo->perishSongTurns == 0) {
            DisplayActions(NULL);
            if (!EntityIsValid(entity) || IsFloorOver())
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
            if (!EntityIsValid(entity) || IsFloorOver())
                return;
        }
    }

    if (entityInfo->bideClassStatus.status == STATUS_BIDE) {
        sub_80838EC(&entityInfo->bideClassStatus.turns);
        if (entityInfo->bideClassStatus.turns == 0) {
            entityInfo->bideClassStatus.status = 0;
            if (!CheckVariousStatuses2(entity, FALSE) && !CannotAttack(entity, FALSE) && !CheckVariousStatuses(entity)) {
                Move bideMove;

                DisplayActions(NULL);
                InitPokemonMove(&bideMove, MOVE_BIDE_2);
                bideMove.moveFlags |= MOVE_FLAG_LAST_USED;
                TryUseChosenMove(entity, 0, 0, 0, 0, &bideMove);
                if (!EntityIsValid(entity) || IsFloorOver())
                    return;
                entityInfo->unkA0 = 0;
            }
        }
    }

    if (!EntityIsValid(entity) || IsFloorOver())
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

    if (!EntityIsValid(entity) || IsFloorOver())
        return;
}

void TickStatusAndHealthRegen(Entity *entity)
{
    s32 i;
    bool32 spdChange;
    EntityInfo *entityInfo;

    if (entity == NULL)
        return;
    if (!EntityIsValid(entity) || IsFloorOver())
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
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->burnClassStatus.status != 0) {
        sub_80838EC(&entityInfo->burnClassStatus.turns);
        if (entityInfo->burnClassStatus.turns == 0) {
            EndBurnClassStatus(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->frozenClassStatus.status != 0) {
        sub_80838EC(&entityInfo->frozenClassStatus.turns);
        if (entityInfo->frozenClassStatus.turns == 0) {
            EndFrozenClassStatus(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->cringeClassStatus.status != 0) {
        sub_80838EC(&entityInfo->cringeClassStatus.turns);
        if (entityInfo->cringeClassStatus.turns == 0) {
            EndCringeClassStatus(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->reflectClassStatus.status != 0) {
        sub_80838EC(&entityInfo->reflectClassStatus.turns);
        if (entityInfo->reflectClassStatus.turns == 0) {
            EndReflectClassStatus(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->curseClassStatus.status != 0) {
        sub_80838EC(&entityInfo->curseClassStatus.turns);
        if (entityInfo->curseClassStatus.turns == 0) {
            EndCurseClassStatus(entity, entity, 0);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->leechSeedClassStatus.status != 0) {
        sub_80838EC(&entityInfo->leechSeedClassStatus.turns);
        if (entityInfo->leechSeedClassStatus.turns == 0) {
            EndLeechSeedClassStatus(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->sureShotClassStatus.status != 0) {
        sub_80838EC(&entityInfo->sureShotClassStatus.turns);
        if (entityInfo->sureShotClassStatus.turns == 0) {
            SendMoveEndMessage(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->invisibleClassStatus.status != 0) {
        sub_80838EC(&entityInfo->invisibleClassStatus.turns);
        if (entityInfo->invisibleClassStatus.turns == 0) {
            SendTransformEndMessage(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->blinkerClassStatus.status != 0) {
        sub_80838EC(&entityInfo->blinkerClassStatus.turns);
        if (entityInfo->blinkerClassStatus.turns == 0) {
            SendEyesightEndMessage(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
        return;

    if (entityInfo->muzzled.muzzled != 0) {
        sub_80838EC(&entityInfo->muzzled.turns);
        if (entityInfo->muzzled.turns == 0) {
            SendMuzzledEndMessage(entity, entity);
        }
    }
    if (!EntityIsValid(entity) || IsFloorOver())
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

