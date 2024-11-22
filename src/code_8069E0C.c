#include "global.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_message.h"
#include "dungeon_util.h"
#include "game_options.h"
#include "move_effects_target.h"
#include "moves.h"
#include "pokemon.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "text_util.h"
#include "weather.h"
#include "file_system.h"
#include "tile_types.h"
#include "position_util.h"
#include "exclusive_pokemon.h"
#include "number_util.h"
#include "pokemon_3.h"
#include "code_8077274_1.h"
#include "code_806CD90.h"
#include "dungeon_capabilities.h"
#include "status_checks_1.h"
#include "dungeon_ai_movement.h"
#include "constants/iq_skill.h"

struct unkStruct_80F520C
{
    u8 unk0; // types0
    u8 unk1; // Most likely just padding and should be removed
    s16 unk2; // monsterID
};

// Castform Forecast ability data
extern struct unkStruct_80F520C gUnknown_80F520C[WEATHER_RANDOM];

extern u8 gUnknown_80F51E4[];
extern u8 *gUnknown_80FCC7C[];
extern u8 *gUnknown_80FCCAC[];
extern u8 *gUnknown_80FDCC8[];

extern void sub_8042900(Entity *r0);
extern void sub_8042968(Entity *r0);
extern void EndAbilityImmuneStatus(Entity *, Entity *);
void sub_8041BBC(Entity *r0);
extern bool8 sub_8045888(Entity *);
extern void sub_806A2BC(Entity *, u8);
extern void sub_804178C(u32);
extern void sub_803F508(Entity *);

void sub_8069E0C(Entity *pokemon)
{
  s32 index;
  EntityInfo *entityInfo;

  entityInfo = GetEntInfo(pokemon);
  if (HasAbility(pokemon, ABILITY_FORECAST)) {
    entityInfo->types[0] = gUnknown_80F520C[GetApparentWeather(pokemon)].unk0;
    entityInfo->types[1] = TYPE_NONE;
  }
  else {
    for(index = 0; index < 2; index++)
      entityInfo->types[index] = GetPokemonType(entityInfo->id, index);
  }
  for(index = 0; index < 2; index++)
    entityInfo->abilities[index] = GetPokemonAbility(entityInfo->id, index);
  gDungeon->unkC = 1;
}

void TriggerWeatherAbilities(void)
{
  Entity *entity;
  s32 index;

  if (gDungeon->unkC != 0) {
    gDungeon->unkC = 0;
    gDungeon->weather.nullifyWeather = FALSE;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->activePokemon[index];
      if (EntityExists(entity)) {
        if (HasAbility(entity, ABILITY_DRIZZLE)) {
            gDungeon->weather.naturalWeather[WEATHER_RAIN] = 1;
        }
        else if (HasAbility(entity, ABILITY_SAND_STREAM)) {
            gDungeon->weather.naturalWeather[WEATHER_SANDSTORM] = 1;
        }
        else if (HasAbility(entity, ABILITY_DROUGHT)) {
            gDungeon->weather.naturalWeather[WEATHER_SUNNY] = 1;
        }
        if ((HasAbility(entity, ABILITY_AIR_LOCK)) || (HasAbility(entity, ABILITY_CLOUD_NINE))) {
            gDungeon->weather.nullifyWeather = TRUE;
        }
      }
    }
  }
}

s32 GetMonsterApparentID(Entity *pokemon, s16 id)
{
    if (id == MONSTER_CASTFORM || id == MONSTER_CASTFORM_SNOWY || id == MONSTER_CASTFORM_SUNNY || id == MONSTER_CASTFORM_RAINY) {
        if (HasAbility(pokemon, ABILITY_FORECAST))
            return gUnknown_80F520C[GetApparentWeather(pokemon)].unk2;
        return MONSTER_CASTFORM;
    }

    return id;
}

void sub_8069F9C(Entity *pokemon, Entity *target, Move *move)
{
    s32 abilityIndex;
    EntityInfo *targetInfo;
    EntityInfo *pokemonInfo;
    u8 abilities[4];

    if (!EntityExists(pokemon))
        return;
    if (!EntityExists(target))
        return;
    if (pokemon == target)
        return;

    pokemonInfo = GetEntInfo(pokemon);
    targetInfo = GetEntInfo(target);
    abilityIndex = -1;
    if (targetInfo->abilities[0] == ABILITY_TRACE) {
        abilityIndex = 0;
    }
    if (targetInfo->abilities[1] == ABILITY_TRACE) {
        abilityIndex = 1;
    }

    if (abilityIndex > -1) {
        s32 randomIndex;
        s32 abilityCounter = 0;
        if (pokemonInfo->abilities[0] != ABILITY_UNKNOWN) {
            abilities[0] = pokemonInfo->abilities[0];
            abilityCounter = 1;
        }
        if (pokemonInfo->abilities[1] != ABILITY_UNKNOWN) {
            abilities[abilityCounter] = pokemonInfo->abilities[1];
            abilityCounter++;
        }

        if (abilityCounter != 0) {
            if (abilityCounter == 1) {
                randomIndex = 0;
            }
            else {
                randomIndex = DungeonRandInt(abilityCounter);
            }

            if (randomIndex >= 0) {
                targetInfo->abilities[abilityIndex] = abilities[randomIndex];
                gDungeon->unkC = 1;
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
                TryDisplayDungeonLoggableMessage3(pokemon, target, *gUnknown_80FCC7C);
                sub_8042900(target);
                EndAbilityImmuneStatus(pokemon, target);
            }
        }
    }

    if (targetInfo->unk15A != 0) {
        targetInfo->unk15A = 0;
        if (HasAbility(target, ABILITY_COLOR_CHANGE)) {
            u8 type = GetMoveTypeForMonster(pokemon,move);
            if (move->id == MOVE_WEATHER_BALL) {
                u32 weather = GetApparentWeather(pokemon);
                type = gUnknown_80F51E4[weather];
            }
            if (type != TYPE_NONE && !MonsterIsType(target,type)) {
                const u8 *str;

                targetInfo->types[0] = type;
                targetInfo->types[1] = TYPE_NONE;
                targetInfo->isColorChanged = TRUE;
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
                str = GetUnformattedTypeString(targetInfo->types[0]);
                strcpy(gFormatBuffer_Items[0], str);
                TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FCCAC);
                sub_8042968(target);
            }
        }
    }
}

void sub_806A120(Entity * pokemon, Entity * target, Move* move)
{
  u32 uVar2_u32;
  u8 moveType;
  const char *typeString;
  EntityInfo *entityInfo;

  if ((((EntityExists(pokemon)) && (EntityExists(target))) && (pokemon != target))
     && (entityInfo = GetEntInfo(target), entityInfo->reflectClassStatus.status == STATUS_CONVERSION2)) {
    moveType = GetMoveTypeForMonster(pokemon, move);
    uVar2_u32 = sub_8092364(moveType);
    if (uVar2_u32 != TYPE_NONE) {
      entityInfo->types[0] = uVar2_u32;
      entityInfo->types[1] = 0;
      sub_8041BBC(target);
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
      typeString = GetUnformattedTypeString(uVar2_u32);
      strcpy(gFormatBuffer_Items[0],typeString);
      TryDisplayDungeonLoggableMessage3(pokemon,target,*gUnknown_80FDCC8);
    }
  }
}

void sub_806A1B0(Entity *pokemon)
{
  if ((EntityExists(pokemon)) && (HasAbility(pokemon, ABILITY_TRUANT))) {
    PausedStatusTarget(pokemon,pokemon,0,1,0);
  }
}

void sub_806A1E8(Entity *pokemon)
{
  bool8 bVar3;
  EntityInfo *entityInfo;

  bVar3 = FALSE;
  if (EntityExists(pokemon)) {
    if (GetEntityType(pokemon) == ENTITY_MONSTER) {
      entityInfo = GetEntInfo(pokemon);
      bVar3 = (!entityInfo->isNotTeamMember);
    }
    if (gGameOptionsRef->FarOffPals == '\0') {
      bVar3 = FALSE;
    }
    if (bVar3 && (!sub_8045888(pokemon))) {
      sub_806A2BC(pokemon,1);
    }
  }
}

void sub_806A240(Entity *pokemon, Entity *target)
{
  bool8 isNotTeamMember;
  EntityInfo *entityInfo;

  isNotTeamMember = FALSE;
  if (EntityExists(pokemon)){
    if (GetEntityType(pokemon) == ENTITY_MONSTER) {
        entityInfo = GetEntInfo(pokemon);
        isNotTeamMember = (!entityInfo->isNotTeamMember);
    }
    if (isNotTeamMember && (!sub_8045888(pokemon))) {
        sub_806A2BC(pokemon,1);
        return;
    }
    else if (GetEntityType(target) == ENTITY_MONSTER) {
        entityInfo = GetEntInfo(target);
        isNotTeamMember = (!entityInfo->isNotTeamMember);
    }
    if (isNotTeamMember && (!sub_8045888(target))) {
        sub_806A2BC(target,1);
    }
  }
}

void sub_806A2BC(Entity *pokemon, u8 param_2)
{
  if ((EntityExists(pokemon)) && (GetEntityType(pokemon) == ENTITY_MONSTER) && (gDungeon->unk181e8.cameraTarget != pokemon)) {
    if (param_2 != '\0') {
      sub_804178C(1);
      while (gDungeon->unk12 < 0x3c) {
        sub_803E46C(0x34);
      }
    }
    sub_803E708(4,0x44);
    sub_803F508(pokemon);
    sub_804AC20(&pokemon->pos);
    gDungeon->unk12 = 0;
  }
}

void nullsub_95(void)
{}

void sub_806A338(void)
{
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *entity = gDungeon->activePokemon[i];
        if (EntityExists(entity) && (GetEntInfo(entity)->curseClassStatus.status == STATUS_SNATCH)) {
            gDungeon->snatchPokemon = entity;
            gDungeon->unk17B3C = GetEntInfo(entity)->unk98;
            return;
        }
    }
}

void sub_806A390(Entity *pokemon)
{
    s32 i;

    EntityInfo *info = GetEntInfo(pokemon);
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &info->moves.moves[i];
        if (MoveFlagExists(move)) {
            move->moveFlags2 &= 0xF7;
            move->moveFlags2 &= 0xEF;
            move->moveFlags2 |= MOVE_FLAG2_UNK4;
            move->PP = GetMoveBasePP(move);
        }
    }
}

extern void EntityUpdateStatusSprites(Entity *);
extern s32 sub_808F700(PokemonStruct1 *pokemon);
extern Entity *sub_80696A8(Entity *a0);
extern int sprintf(char *, const char *, ...);
extern const u8 gUnknown_8106EA8[]; // talkp%d
extern const u8 gUnknown_8106EB0[]; // talk%d
extern const struct FileArchive gDungeonFileArchive;

struct UnkTalkFileStruct
{
    const u8 *strings[10][4];
};

// https://decomp.me/scratch/beUzw s16 memes again
#ifdef NONMATCHING
void sub_806A3D4(u8 *dst, s16 a1, s32 id, bool8 a3)
{
    u8 fileName[12];
    OpenedFile *file;
    s32 strId;

    if (a3) {
        sprintf(fileName, gUnknown_8106EA8, a1 / 10);
    }
    else {
        sprintf(fileName, gUnknown_8106EB0, a1 / 10);
    }

    file = OpenFileAndGetFileDataPtr(fileName, &gDungeonFileArchive);

    strId = a1 % 10;
    strcpy(dst, ((struct UnkTalkFileStruct *)(file->data))->strings[strId][id]);
    CloseFile(file);
}
#else
NAKED void sub_806A3D4(u8 *dst, s16 a1, s32 id, bool8 a3)
{
    asm_unified("push {r4-r7,lr}\n"
"	sub sp, 0xC\n"
"	adds r7, r0, 0\n"
"	adds r6, r2, 0\n"
"	lsls r1, 16\n"
"	asrs r5, r1, 16\n"
"	lsls r3, 24\n"
"	cmp r3, 0\n"
"	beq _0806A404\n"
"	ldr r4, _0806A400\n"
"	adds r0, r5, 0\n"
"	movs r1, 0xA\n"
"	bl __divsi3\n"
"	adds r2, r0, 0\n"
"	lsls r2, 16\n"
"	asrs r2, 16\n"
"	mov r0, sp\n"
"	adds r1, r4, 0\n"
"	bl sprintf\n"
"	b _0806A41C\n"
"	.align 2, 0\n"
"_0806A400: .4byte gUnknown_8106EA8\n"
"_0806A404:\n"
"	ldr r4, _0806A450\n"
"	adds r0, r5, 0\n"
"	movs r1, 0xA\n"
"	bl __divsi3\n"
"	adds r2, r0, 0\n"
"	lsls r2, 16\n"
"	asrs r2, 16\n"
"	mov r0, sp\n"
"	adds r1, r4, 0\n"
"	bl sprintf\n"
"_0806A41C:\n"
"	ldr r1, _0806A454\n"
"	mov r0, sp\n"
"	bl OpenFileAndGetFileDataPtr\n"
"	adds r4, r0, 0\n"
"	adds r0, r5, 0\n"
"	movs r1, 0xA\n"
"	bl __modsi3\n"
"	lsls r0, 16\n"
"	ldr r1, [r4, 0x4]\n"
"	asrs r0, 12\n"
"	adds r0, r1\n"
"	lsls r1, r6, 2\n"
"	adds r0, r1\n"
"	ldr r1, [r0]\n"
"	adds r0, r7, 0\n"
"	bl strcpy\n"
"	adds r0, r4, 0\n"
"	bl CloseFile\n"
"	add sp, 0xC\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
"	.align 2, 0\n"
"_0806A450: .4byte gUnknown_8106EB0\n"
"_0806A454: .4byte gDungeonFileArchive");
}
#endif // NONMATCHING

bool8 sub_806A458(Entity *pokemon)
{
    s32 x, y;
    s32 count = 0;
    EntityInfo *info = GetEntInfo(pokemon);
    bool8 isNotTeamMember = info->isNotTeamMember;

    if (!sub_80696A8(pokemon))
        return FALSE;

    for (y = -1; y < 2; y++) {
        for (x = -1; x < 2; x++) {
            Tile *tile = GetTileMut(pokemon->pos.x + x, pokemon->pos.y + y);
            if (tile->monster && GetEntityType(tile->monster) == ENTITY_MONSTER) {
                if (GetEntInfo(tile->monster)->isNotTeamMember != isNotTeamMember)
                    count++;
            }
        }
    }
    return (count > 1);
}

s32 sub_806A4DC(EntityInfo *info)
{
    PokemonStruct1 pokemon;
    DungeonLocation loc;

    loc.id = 0;
    loc.floor = 1;

    sub_808CFD0(&pokemon, info->id, NULL, 0, &loc, 0);

    pokemon.speciesNum = info->id;
    pokemon.level = info->level;
    pokemon.IQ = info->IQ;
    pokemon.offense.att[0] = info->atk[0];
    pokemon.offense.def[0] = info->def[0];

    return sub_808F700(&pokemon);
}

bool8 sub_806A538(s16 r0)
{
    s32 r0_1 = Self_s16(r0);
    if (r0 == 0x55AA)
        return TRUE;
    if (r0 == 0x5AA5)
        return TRUE;

    if (r0_1 >= 0)
        return FALSE;

    return TRUE;
}

bool8 sub_806A564(s16 r0)
{
    if (r0 == 0x55AA)
        return TRUE;
    if (r0 == 0x5AA5)
        return TRUE;

    return FALSE;
}

bool8 sub_806A58C(s16 r0)
{
    if (r0 >= 0 && r0 <= 0x19C)
        return TRUE;
    else
        return FALSE;
}

bool8 sub_806A5A4(s16 r0)
{
    if (r0 < 0)
        return TRUE;
    else
        return FALSE;
}

extern const u8 *const gUnknown_80FD594;
extern const u8 *const gUnknown_80FD5B8;
extern const u8 *const gUnknown_80FEAC4;
extern const u8 *const gPtrLinkMoveTwoUsesWarningMessage;
extern const u8 *const gPtrLinkMoveOneUseWarningMessage;
extern const u8 *const gPtrLinkedMovesComeApartMessage;

void sub_806A5B8(Entity *entity)
{
    s32 terrainType;

    if (!EntityExists(entity))
        return;

    terrainType = GetTerrainType(GetTileAtEntitySafe(entity));
    if (terrainType == TERRAIN_TYPE_SECONDARY) {
        EntityInfo *info = GetEntInfo(entity);
        // If lava - defrost and burn
        if (gDungeonWaterType[gDungeon->tileset] == DUNGEON_WATER_TYPE_LAVA) {
            if (info->frozenClassStatus.status == STATUS_FROZEN) {
                EndFrozenClassStatus(entity, entity);
            }
            if (GetMovementType(info->id) != 4 &&
                info->id != MONSTER_HO_OH
                && info->id != MONSTER_MOLTRES
                && info->burnClassStatus.status != STATUS_BURN)
            {
                BurnedStatusTarget(entity, entity, 1, FALSE);
            }
        }
        // It's water - heal burn
        else {
            if (info->burnClassStatus.status == STATUS_BURN) {
                EndBurnClassStatus(entity, entity);
            }
        }
    }
    // If wall - decrement belly by 5
    else if (terrainType == TERRAIN_TYPE_WALL) {
        const u8 *str;
        EntityInfo *info = GetEntInfo(entity);

        if (info->isTeamLeader) {
            FixedPoint bellyBefore = info->belly;
            info->belly = FixedPoint_Subtract(bellyBefore, IntToFixedPointMacro(5));
            str = NULL;
            if (FixedPointToInt(bellyBefore) > 19 && FixedPointToInt(info->belly) <= 19) {
                str = gUnknown_80FD594; // Getting hungry...
            }
            if (FixedPointToInt(bellyBefore) > 9 && FixedPointToInt(info->belly) <= 9) {
                str = gUnknown_80FD5B8; // Getting dizzy from hunger...
            }

            if (str != NULL) {
                LogMessageByIdWithPopupCheckUser(entity, str);
            }
        }
    }
}

extern void sub_803F580(s32);
extern void sub_8040A84(void);

void sub_806A6E8(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);

    if (info->unk64 != info->heldItem.id) {
        if (!info->isTeamLeader) {
            if (info->heldItem.id == ITEM_HEAL_RIBBON || info->heldItem.id == ITEM_MUNCH_BELT) {
                info->belly = FixedPoint_Subtract(info->belly, IntToFixedPoint(10));
            }
            else if (info->heldItem.id == ITEM_DIET_RIBBON) {
                info->belly = IntToFixedPoint(0);
            }

            if (gDungeon->unk644.itemHoldersIdentified) {
                EntityUpdateStatusSprites(entity);
            }
        }
        else {
            if (info->heldItem.id == ITEM_X_RAY_SPECS || info->unk64 == ITEM_X_RAY_SPECS) {
                sub_803F580(1);
                sub_8040A84();
            }
        }
        sub_807AA30();
    }

    if (ItemExists(&info->heldItem)) {
        info->unk64 = info->heldItem.id;
    }
    else {
        info->unk64 = ITEM_NOTHING;
    }
}

void DisplayMsgIfNewIqSkillLearned(EntityInfo *info, s32 pokeIq);

UNUSED static void DisplayMsgIfTeamMonsLearnedNewIqSkill(void)
{
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityExists(entity)) {
            EntityInfo *info = GetEntInfo(entity);
            if (info->IQ > 1) {
                DisplayMsgIfNewIqSkillLearned(info, info->IQ - 1);
            }
        }
    }
}

void DisplayMsgIfNewIqSkillLearned(EntityInfo *info, s32 iqBefore)
{
    s32 i, j;
    u8 iqSkillsArrayBefore[NUM_IQ_SKILLS];
    u8 iqSkillsArrayNow[NUM_IQ_SKILLS];
    s32 numIqSkillsBefore = GetNumAvailableIQSkills(iqSkillsArrayBefore, iqBefore);
    s32 numIqSkillsNow = GetNumAvailableIQSkills(iqSkillsArrayNow, info->IQ);

    SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
    for (i = 1; i < NUM_IQ_SKILLS; i++) {
        bool8 hadIqSkillBefore = FALSE;
        bool8 hasIqSkillNow = FALSE;

        for (j = 0; j < numIqSkillsBefore; j++) {
            if (iqSkillsArrayBefore[j] == i) {
                hadIqSkillBefore = TRUE;
                break;
            }
        }

         for (j = 0; j < numIqSkillsNow; j++) {
            if (iqSkillsArrayNow[j] == i) {
                hasIqSkillNow = TRUE;
                break;
            }
        }

        if (hadIqSkillBefore != hasIqSkillNow) {
            strcpy(gFormatBuffer_Items[0], GetIQSkillName(i));
            DisplayDungeonLoggableMessageTrue(NULL, gUnknown_80FEAC4); // IQ rose! \n It learned the IQ skill 'i0'
        }
    }
}

void sub_806A898(Entity *entity, bool8 r7, bool8 showRunAwayEffect)
{
    EntityInfo *info = GetEntInfo(entity);
    if (info->isTeamLeader) {
        info->targetPos.x = entity->pos.x;
        info->targetPos.y = entity->pos.y + 1;
    }
    else {
        AIMovement(entity, showRunAwayEffect);
    }

    if (info->targetPos.x != 0 || info->targetPos.y != 0) {
        if (!CheckVariousStatuses2(entity, TRUE) || !CheckVariousStatuses(entity)) {
            s32 newDirection = GetDirectionTowardsPosition(&entity->pos, &info->targetPos);
            info->action.direction = newDirection & DIRECTION_MASK;
            if (r7) {
                sub_806CE68(entity, newDirection);
            }
        }
    }
}

void sub_806A914(bool8 a0, bool8 a1, bool8 showRunAwayEffect)
{
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *entity = gDungeon->activePokemon[i];
        if (EntityExists(entity)) {
            EntityInfo *info = GetEntInfo(entity);
            if (!a1 || info->monsterBehavior == 1) {
                sub_806A898(entity, a0, showRunAwayEffect);
            }
        }
    }
}

void sub_806A974(void)
{
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *entity = gDungeon->activePokemon[i];
        if (EntityExists(entity)) {
            EntityInfo *info = GetEntInfo(entity);
            sub_806CE68(entity, info->action.direction);
        }
    }
}

void sub_806A9B4(Entity *entity, s32 moveIndex)
{
    if (EntityExists(entity)) {
        EntityInfo *info = GetEntInfo(entity);
        s32 ret = sub_80935B8(info->moves.moves, moveIndex);

        if (ret == 0) {
            LogMessageByIdWithPopupCheckUser(entity, gPtrLinkedMovesComeApartMessage);
        }
        else if (ret == 1) {
            LogMessageByIdWithPopupCheckUser(entity, gPtrLinkMoveOneUseWarningMessage);
        }
        else if (ret == 2) {
            LogMessageByIdWithPopupCheckUser(entity, gPtrLinkMoveTwoUsesWarningMessage);
        }
    }
}

// s16 again...
bool8 sub_806AA0C(s16 _species, bool32 _a1)
{
    s32 species = _species;
    bool8 a1 = _a1;
    if (!IsExclusivePokemonUnlocked(_species))
        return FALSE;

    if (gDungeon->unk37FD && GetBaseSpecies(species) == MONSTER_DEOXYS_NORMAL)
        return FALSE;

    if (species == MONSTER_MEW) {
        if (gDungeon->unk37FF || !a1)
            return FALSE;
    }

    return TRUE;
}

extern void sub_8042B20(Entity *entity);
extern void sub_8042B0C(Entity *entity);

void sub_806AA70(void)
{
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityExists(entity)) {
            EntityInfo *info = GetEntInfo(entity);
            s32 teamIndex = info->teamIndex;

            if (info->isTeamLeader) {
                if (gDungeon->unk11 == 1) {
                    sub_8042B20(entity);
                }
                else {
                    sub_8042B0C(entity);
                }
                entity->isVisible = FALSE;
            }
            else {
                if (teamIndex >= 0) {
                    bool8 unkBool = FALSE;
                    PokemonStruct2 *monStruct2Ptr = &gRecruitedPokemonRef->pokemon2[teamIndex];

                    if (gDungeon->unk11)
                        unkBool = TRUE;
                    else if (sub_806A564(monStruct2Ptr->unkA))
                        unkBool = TRUE;
                    else if (sub_806A58C(monStruct2Ptr->unkA))
                        unkBool = TRUE;

                    if (unkBool) {
                        sub_8042B0C(entity);
                        entity->isVisible = FALSE;
                    }
                }
            }
        }
    }
}

void sub_806AB2C(void)
{
    s32 i, j;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *entity1 = gDungeon->activePokemon[i];
        if (EntityExists(entity1)) {
            EntityInfo *info1 = GetEntInfo(entity1);
            for (j = 0; j < DUNGEON_MAX_POKEMON; j++) {
                Entity *entity2 = gDungeon->activePokemon[j];
                if (EntityExists(entity2) && entity1 != entity2 && info1->aiTarget.aiTargetSpawnGenID == entity2->spawnGenID) {
                    info1->aiTarget.aiTarget = entity2;
                }
            }
        }
    }
}

void EndAbilityImmuneStatus(Entity *attacker, Entity *target)
{
    EntityInfo *targetInfo = GetEntInfo(target);

    if (HasAbility(target, ABILITY_LIMBER) && targetInfo->burnClassStatus.status == STATUS_PARALYSIS) {
        EndBurnClassStatus(attacker, target);
    }

    if (HasAbility(target, ABILITY_OWN_TEMPO) && targetInfo->cringeClassStatus.status == STATUS_CONFUSED) {
        EndCringeClassStatus(attacker, target);
    }

    if (HasAbility(target, ABILITY_WATER_VEIL) && targetInfo->burnClassStatus.status == STATUS_BURN) {
        EndBurnClassStatus(attacker, target);
    }

    if (HasAbility(target, ABILITY_OBLIVIOUS) && targetInfo->cringeClassStatus.status == STATUS_INFATUATED) {
        EndCringeClassStatus(attacker, target);
    }

    if ((HasAbility(target, ABILITY_INSOMNIA) || HasAbility(target, ABILITY_VITAL_SPIRIT))
        && (IsSleeping(target) || targetInfo->sleepClassStatus.status == STATUS_YAWNING))
    {
        EndSleepClassStatus(attacker, target, FALSE, TRUE);
    }

    if (HasAbility(target, ABILITY_MAGMA_ARMOR) && targetInfo->frozenClassStatus.status == STATUS_FROZEN) {
        EndFrozenClassStatus(attacker, target);
    }

    if (HasAbility(target, ABILITY_IMMUNITY) && ENTITY_POISIONED(targetInfo)) {
        EndBurnClassStatus(attacker, target);
    }

    if (HasAbility(target, ABILITY_FORECAST)) {
        targetInfo->isColorChanged = FALSE;
        if (targetInfo->reflectClassStatus.status == STATUS_CONVERSION2) {
            EndReflectClassStatus(attacker, target);
        }
    }
}
