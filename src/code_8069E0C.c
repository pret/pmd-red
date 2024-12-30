#include "global.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "code_805D8C8.h"
#include "code_804267C.h"
#include "random.h"
#include "constants/ability.h"
#include "constants/move_id.h"
#include "constants/status.h"
#include "constants/type.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
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
#include "structs/str_806B7F8.h"
#include "structs/str_202ED28.h"
#include "dungeon_config.h"

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
extern void sub_8042B20(Entity *entity);
extern void sub_8042B0C(Entity *entity);
extern s32 sub_803D808(UnkDungeonGlobal_unk1CD98 *strPtr, s32 id);
extern void sub_8072AC8(u16 *param_1, s32 species, s32 param_3);
extern s16 sub_803D970(u32);
extern bool8 sub_8083660(const DungeonPos *param_1);
extern Entity *gLeaderPointer;
extern DungeonPos gUnknown_202EE0C;
extern void sub_803F4A0(Entity *a0);
extern bool8 sub_80860A8(u8 id);
extern u8 gUnknown_202F32C;
extern u8 sub_803D73C(s32 a0);
extern void DeletePokemonDungeonSprite(s32 id);
extern void sub_80429E8(Entity *r0);
extern s32 sub_803DA20(s32 param_1);
extern void sub_80694C0(Entity *, s32, s32, u32);
extern void AddPokemonDungeonSprite(s32 id, s16 species, DungeonPos *pos, u32);
extern s32 gUnknown_202EDCC;
extern void sub_800F958(s32 dungeonSpriteID, DungeonPos *pos, DungeonPos *statusOffsets, u32 a3);
extern void sub_8005700(DungeonPos *a0, struct axObject *a1);
u32 EntityGetStatusSprites(Entity *entity);
void UpdateDungeonPokemonSprite(int id, short species, int status, char visible);
extern void sub_8042EC8(Entity *a0, s32 a1);
void DoAxFrame_800558C(struct axObject *a0, s32 spriteX, s32 spriteY, u32 a3, u32 paletteNum, unkStruct_2039DB0 *spriteMasks);
extern Entity *sub_804550C(s16 a);
extern Entity *sub_80453AC(s16 id);
extern void sub_803F580(s32);
extern void sub_8040A84(void);
extern void sub_806B678(void);
extern void EntityUpdateStatusSprites(Entity *);
extern Entity *sub_80696A8(Entity *a0);
extern int sprintf(char *, const char *, ...);
extern const u8 gUnknown_8106EA8[]; // talkp%d
extern const u8 gUnknown_8106EB0[]; // talk%d
extern const struct FileArchive gDungeonFileArchive;

void sub_8069E0C(Entity *pokemon)
{
  s32 index;
  EntityInfo *entityInfo;

  entityInfo = GetEntInfo(pokemon);
  if (AbilityIsActive(pokemon, ABILITY_FORECAST)) {
    entityInfo->types[0] = gCastformByWeather[GetApparentWeather(pokemon)].type;
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
      if (EntityIsValid(entity)) {
        if (AbilityIsActive(entity, ABILITY_DRIZZLE)) {
            gDungeon->weather.naturalWeather[WEATHER_RAIN] = 1;
        }
        else if (AbilityIsActive(entity, ABILITY_SAND_STREAM)) {
            gDungeon->weather.naturalWeather[WEATHER_SANDSTORM] = 1;
        }
        else if (AbilityIsActive(entity, ABILITY_DROUGHT)) {
            gDungeon->weather.naturalWeather[WEATHER_SUNNY] = 1;
        }
        if ((AbilityIsActive(entity, ABILITY_AIR_LOCK)) || (AbilityIsActive(entity, ABILITY_CLOUD_NINE))) {
            gDungeon->weather.nullifyWeather = TRUE;
        }
      }
    }
  }
}

s32 GetMonsterApparentID(Entity *pokemon, s32 _id)
{
    s16 id = (s16)(_id);
    if (id == MONSTER_CASTFORM || IS_CASTFORM_FORM_MONSTER(id)) {
        if (AbilityIsActive(pokemon, ABILITY_FORECAST))
            return gCastformByWeather[GetApparentWeather(pokemon)].monsterId;
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

    if (!EntityIsValid(pokemon))
        return;
    if (!EntityIsValid(target))
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
        if (AbilityIsActive(target, ABILITY_COLOR_CHANGE)) {
            u8 type = GetMoveTypeForMonster(pokemon,move);
            if (move->id == MOVE_WEATHER_BALL) {
                u32 weather = GetApparentWeather(pokemon);
                type = gWeatherBallTypes[weather];
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

  if ((((EntityIsValid(pokemon)) && (EntityIsValid(target))) && (pokemon != target))
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
  if ((EntityIsValid(pokemon)) && (AbilityIsActive(pokemon, ABILITY_TRUANT))) {
    PausedStatusTarget(pokemon,pokemon,0,1,0);
  }
}

void sub_806A1E8(Entity *pokemon)
{
  bool8 bVar3;
  EntityInfo *entityInfo;

  bVar3 = FALSE;
  if (EntityIsValid(pokemon)) {
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
  if (EntityIsValid(pokemon)){
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
  if ((EntityIsValid(pokemon)) && (GetEntityType(pokemon) == ENTITY_MONSTER) && (gDungeon->unk181e8.cameraTarget != pokemon)) {
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
        if (EntityIsValid(entity) && (GetEntInfo(entity)->curseClassStatus.status == STATUS_SNATCH)) {
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

    if (!EntityIsValid(entity))
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
        if (EntityIsValid(entity)) {
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
        if (EntityIsValid(entity)) {
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
        if (EntityIsValid(entity)) {
            EntityInfo *info = GetEntInfo(entity);
            sub_806CE68(entity, info->action.direction);
        }
    }
}

void sub_806A9B4(Entity *entity, s32 moveIndex)
{
    if (EntityIsValid(entity)) {
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

void sub_806AA70(void)
{
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
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
        if (EntityIsValid(entity1)) {
            EntityInfo *info1 = GetEntInfo(entity1);
            for (j = 0; j < DUNGEON_MAX_POKEMON; j++) {
                Entity *entity2 = gDungeon->activePokemon[j];
                if (EntityIsValid(entity2) && entity1 != entity2 && info1->aiTarget.aiTargetSpawnGenID == entity2->spawnGenID) {
                    info1->aiTarget.aiTarget = entity2;
                }
            }
        }
    }
}

void EndAbilityImmuneStatus(Entity *attacker, Entity *target)
{
    EntityInfo *targetInfo = GetEntInfo(target);

    if (AbilityIsActive(target, ABILITY_LIMBER) && targetInfo->burnClassStatus.status == STATUS_PARALYSIS) {
        EndBurnClassStatus(attacker, target);
    }

    if (AbilityIsActive(target, ABILITY_OWN_TEMPO) && targetInfo->cringeClassStatus.status == STATUS_CONFUSED) {
        EndCringeClassStatus(attacker, target);
    }

    if (AbilityIsActive(target, ABILITY_WATER_VEIL) && targetInfo->burnClassStatus.status == STATUS_BURN) {
        EndBurnClassStatus(attacker, target);
    }

    if (AbilityIsActive(target, ABILITY_OBLIVIOUS) && targetInfo->cringeClassStatus.status == STATUS_INFATUATED) {
        EndCringeClassStatus(attacker, target);
    }

    if ((AbilityIsActive(target, ABILITY_INSOMNIA) || AbilityIsActive(target, ABILITY_VITAL_SPIRIT))
        && (IsSleeping(target) || targetInfo->sleepClassStatus.status == STATUS_YAWNING))
    {
        EndSleepClassStatus(attacker, target, FALSE, TRUE);
    }

    if (AbilityIsActive(target, ABILITY_MAGMA_ARMOR) && targetInfo->frozenClassStatus.status == STATUS_FROZEN) {
        EndFrozenClassStatus(attacker, target);
    }

    if (AbilityIsActive(target, ABILITY_IMMUNITY) && ENTITY_POISONED(targetInfo)) {
        EndBurnClassStatus(attacker, target);
    }

    if (AbilityIsActive(target, ABILITY_FORECAST)) {
        targetInfo->isColorChanged = FALSE;
        if (targetInfo->reflectClassStatus.status == STATUS_CONVERSION2) {
            EndReflectClassStatus(attacker, target);
        }
    }
}

void MarkLastUsedMonMove(Entity *entity, Move *move)
{
    s32 i;
    EntityInfo *entInfo = GetEntInfo(entity);

    for (i = 0; i < MAX_MON_MOVES; i++) {
        entInfo->moves.moves[i].moveFlags &= ~(MOVE_FLAG_LAST_USED);
    }
    entInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_LAST_USED);

    if (move->id == MOVE_STRUGGLE) {
        entInfo->moves.struggleMoveFlags |= MOVE_FLAG_LAST_USED;
    }
    else {
        move->moveFlags |= MOVE_FLAG_LAST_USED;
    }
}

s32 sub_806C444(s32 species, s32 level);
s32 sub_806C488(s32 species, s32 level, s32 categoryIndex);
s32 sub_806C4D4(s32 species, s32 level, s32 categoryIndex);
bool8 sub_806B8CC(s16 _species, s32 x, s32 y, PokemonStruct2 *monPtr, Entity **a4, bool32 _a5, u32 _a6);
void sub_806BC68(bool8 a0, Entity *entity, struct unkStruct_806B7F8 *structPtr, DungeonPos *pos);
void ResetMonEntityData(EntityInfo *, bool8 a1);
void sub_806C264(s32 teamIndex, EntityInfo *entInfo);

void sub_806AD3C(void)
{
    s32 r10;
    s32 i, j;
    UnkDungeonGlobal_unk1CD98 sp[64];
    unkDungeon2F3C *structPtr = gDungeon->unk2F3C;
    s32 var_24 = sub_803D808(sp, 0);

    for (i = 0; i < var_24; structPtr++, i++) {
        structPtr->species = ExtractSpeciesIndex(&sp[i]);
        structPtr->level = ExtractLevel(&sp[i]);
        sub_8072AC8(structPtr->moves, structPtr->species, structPtr->level);
        if (structPtr->moves[0] == MOVE_NOTHING) {
            structPtr->moves[0] = MOVE_BLOWBACK;
        }
        structPtr->unkC = sub_806C444(structPtr->species, structPtr->level);

        for (j = 0; j < 2; j++) {
            structPtr->unkE[j]  = sub_806C488(structPtr->species, structPtr->level, j);
            structPtr->unk10[j] = sub_806C4D4(structPtr->species, structPtr->level, j);
        }
    }

    for (; i < 64; structPtr++, i++) {
        structPtr->species = 0;
    }

    for (i = 0; i < MONSTER_MAX; i++) {
        gDungeon->expYieldRankings[i] = 0;
    }

    r10 = 1;
    for (i = 0; i < var_24; i++) {
        s32 j;
        s32 expSpecies = -1;
        s32 expGain = -1;

        for (j = 0; j < var_24; j++) {
            s32 species = ExtractSpeciesIndex(&sp[j]);
            if (gDungeon->expYieldRankings[species] == 0) {
                s32 level = ExtractLevel(&sp[j]);
                s32 exp = CalculateEXPGain(species, level);
                if (expGain < exp) {
                    expGain = exp;
                    expSpecies = species;
                }
            }
        }

        if (expSpecies < 0)
            break;

        gDungeon->expYieldRankings[expSpecies] = r10;
        r10 += 2;
    }

    for (i = 0; i < MONSTER_MAX; i++) {
        if (gDungeon->expYieldRankings[i] == 0) {
            gDungeon->expYieldRankings[i] = 1;
        }
    }
}

void sub_806AED8(Moves *moves, s16 *maxHPStat, u8 *atk, u8 *def, s16 _species, s32 level)
{
    s32 i;
    s32 moveCategory;
    s32 species = _species;
    unkDungeon2F3C *structPtr = gDungeon->unk2F3C;

    for (i = 0; i < 64; i++) {
        s16 loopSpecies;

        structPtr = &gDungeon->unk2F3C[i];
        loopSpecies = SpeciesId(structPtr->species);
        if (structPtr->species == 0)
            break;

        if (loopSpecies == species && structPtr->level == level) {
            s32 moveIndex;

            for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
                sub_8092AA8(&moves->moves[moveIndex], structPtr->moves[moveIndex]);
            }
            *maxHPStat = structPtr->unkC;
            for (moveCategory = 0; moveCategory < 2; moveCategory++) {
                atk[moveCategory] = structPtr->unkE[moveCategory];
                def[moveCategory] = structPtr->unk10[moveCategory];
            }

            moves->struggleMoveFlags = 0;
            return;
        }
    }

    if (i == 64) {
        s32 moveIndex;
        u16 spMoves[MAX_MON_MOVES];

        sub_8072AC8(spMoves, species, level);
        for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
            sub_8092AA8(&moves->moves[moveIndex], spMoves[moveIndex]);
        }
        *maxHPStat = sub_806C444(species, level);
        for (moveCategory = 0; moveCategory < 2; moveCategory++) {
            atk[moveCategory] = sub_806C488(species, level, moveCategory);
            def[moveCategory] = sub_806C4D4(species, level, moveCategory);
        }


    }
    else {
        s32 moveIndex;

        structPtr->species = species;
        structPtr->level = level;
        sub_8072AC8(structPtr->moves, species, level);
        structPtr->unkC = sub_806C444(structPtr->species, structPtr->level);
        for (moveCategory = 0; moveCategory < 2; moveCategory++) {
            structPtr->unkE[moveCategory]  = sub_806C488(structPtr->species, structPtr->level, moveCategory);
            structPtr->unk10[moveCategory] = sub_806C4D4(structPtr->species, structPtr->level, moveCategory);
        }
        for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
            sub_8092AA8(&moves->moves[moveIndex], structPtr->moves[moveIndex]);
        }

        *maxHPStat = structPtr->unkC;
        for (moveCategory = 0; moveCategory < 2; moveCategory++) {
            atk[moveCategory] = structPtr->unkE[moveCategory];
            def[moveCategory] = structPtr->unk10[moveCategory];
        }
    }

    moves->struggleMoveFlags = 0;
}

UNUSED static s32 sub_806B09C(UnkDungeonGlobal_unk1CD98 *unkPtr, bool8 a1)
{
    s32 i, j;
    s32 count = 0;
    s16 *unk2Field;
    UnkDungeonGlobal_unk1CD98 *loopPtr;

    for (i = 0, unk2Field = unkPtr->unk2, loopPtr = unkPtr; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *monStructPtr = &gRecruitedPokemonRef->pokemon2[i];

        if (PokemonFlag1Struct2(monStructPtr) && PokemonFlag2Struct2(monStructPtr))
        {
            for (j = 0; j < count; j++) {
                if (ExtractSpeciesIndex(&unkPtr[j]) == monStructPtr->speciesNum)
                    break;
            }

            if (j == count) {
                SetSpeciesLevelToExtract(loopPtr, 0, monStructPtr->speciesNum);
                unk2Field[0] = 0;
                unk2Field[1] = 0;
                unk2Field += sizeof(*unkPtr) / sizeof(unkPtr->unk2[0]); // Hacky solution, because loopPtr->unk2[0/1] = 0; doesn't match
                loopPtr++;
                count++;
            }
        }
    }

    count = sub_803D808(unkPtr, count);
    if (a1) {
        SetSpeciesLevelToExtract(&unkPtr[count], 1, MONSTER_DECOY);
        unkPtr[count].unk2[0] = 0;
        unkPtr[count].unk2[1] = 0;
        count++;
    }

    return count;
}

extern const DungeonPos gUnknown_80F4598[];

void sub_806B168(void)
{
    s32 count;
    PokemonStruct2 *monPtrs[MAX_TEAM_MEMBERS];
    PokemonStruct2 *monPtrs2[MAX_TEAM_MEMBERS]; // Leader and partner?
    u8 playerSpawnRoomId = GetTile(gDungeon->playerSpawn.x, gDungeon->playerSpawn.y)->room;
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *currMonPtr = &gRecruitedPokemonRef->pokemon2[i];
        currMonPtr->unkC = i;
    }

    // Populate monPtrs
    count = 0;
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *currMonPtr = &gRecruitedPokemonRef->pokemon2[i];
        if (PokemonFlag1Struct2(currMonPtr) && PokemonFlag2Struct2(currMonPtr)) {
            monPtrs[count++] = currMonPtr;
        }
    }
    for (; count < MAX_TEAM_MEMBERS; count++) {
        monPtrs[count] = NULL;
    }

    // Populate monPtrs2
    count = 0;
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *currMonPtr = monPtrs[i];
        if (currMonPtr != NULL && currMonPtr->isTeamLeader) {
            monPtrs[i] = NULL;
            monPtrs2[count++] = currMonPtr;
        }
    }

    if (gDungeon->unk644.unk18 == 0) {
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            PokemonStruct2 *currMonPtr = monPtrs[i];
            if (currMonPtr != NULL && currMonPtr->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER) {
                monPtrs[i] = NULL;
                monPtrs2[count++] = currMonPtr;
            }
        }
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *currMonPtr = monPtrs[i];
        if (monPtrs[i] != NULL) {
            monPtrs[i] = NULL;
            monPtrs2[count++] = currMonPtr;
        }
    }
    for (; count < MAX_TEAM_MEMBERS; count++) {
        monPtrs2[count] = NULL;
    }

    // Do something else
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *currMonPtr = monPtrs2[i];

        if (currMonPtr != NULL) {
            DungeonPos unkPosition;
            s32 j;
            const Tile *tile;
            bool8 skipSecondLoop;

            if (currMonPtr->speciesNum == MONSTER_CASTFORM_SNOWY || currMonPtr->speciesNum == MONSTER_CASTFORM_RAINY || currMonPtr->speciesNum == MONSTER_CASTFORM_SUNNY) {
                currMonPtr->speciesNum = MONSTER_CASTFORM;
            }

            skipSecondLoop = FALSE;
            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y);
                if (tile->room == playerSpawnRoomId && !sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y, currMonPtr, NULL, TRUE, 0);
                    skipSecondLoop = TRUE;
                    break;
                }
                j++;
            }

            if (skipSecondLoop)
                continue;

            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y);
                if (!sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + gDungeon->playerSpawn.x, unkPosition.y + gDungeon->playerSpawn.y, currMonPtr, NULL, TRUE, 0);
                    break;
                }
                j++;
            }
        }
    }

    sub_806B678();
}

void sub_806B404(void)
{
    Entity *leader;
    s32 i;
    PokemonStruct2 *monPtrs[MAX_TEAM_MEMBERS];
    u8 roomId;
    DungeonPos pos;
    s32 count = 0;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *currMonPtr = &gRecruitedPokemonRef->pokemon2[i];
        if (PokemonFlag1Struct2(currMonPtr) && PokemonFlag2Struct2(currMonPtr) && currMonPtr->unkA == 0x55AA) {
            monPtrs[count++] = currMonPtr;
            break;
        }
    }
    for (; count < MAX_TEAM_MEMBERS; count++) {
        monPtrs[count] = NULL;
    }

    gLeaderPointer = NULL;
    leader = GetLeader();
    if (EntityIsValid(leader)) {
        pos.x = leader->pos.x;
        pos.y = leader->pos.y;
    }
    else {
        pos.x = gDungeon->playerSpawn.x;
        pos.y = gDungeon->playerSpawn.y;
    }

    roomId = GetTile(pos.x, pos.y)->room;
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        DungeonPos unkPosition;
        bool8 skipNextLoop;
        const Tile *tile;
        s32 j;
        PokemonStruct2 *currMonPtr = monPtrs[i];

        if (currMonPtr != NULL && PokemonFlag1Struct2(currMonPtr) && PokemonFlag2Struct2(currMonPtr) && currMonPtr->unkA == 0x55AA) {
            currMonPtr->unkA = 0x5AA5;
            skipNextLoop = FALSE;
            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + pos.x, unkPosition.y + pos.y);
                if (tile->room == roomId && !sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + pos.x, unkPosition.y + pos.y, currMonPtr, NULL, TRUE, 0);
                    skipNextLoop = TRUE;
                    break;
                }
                j++;
            }

            if (skipNextLoop)
                continue;

            skipNextLoop = FALSE;
            j = 0;
            while (1) {
                unkPosition = gUnknown_80F4598[j];
                if (unkPosition.x == 99)
                    break;

                tile = GetTile(unkPosition.x + pos.x, unkPosition.y + pos.y);
                if (!sub_807034C(currMonPtr->speciesNum, tile)) {
                    sub_806B8CC(currMonPtr->speciesNum, unkPosition.x + pos.x, unkPosition.y + pos.y, currMonPtr, NULL, TRUE, 0);
                    skipNextLoop = TRUE;
                    break;
                }
                j++;
            }

            if (skipNextLoop)
                continue;

            for (j = 0; j <= 99; j++) {
                if (sub_8083660(&unkPosition)) {
                    const Tile *tile = GetTile(unkPosition.x, unkPosition.y);
                    if (!sub_807034C(currMonPtr->speciesNum, tile)) {
                        sub_806B8CC(currMonPtr->speciesNum, unkPosition.x, unkPosition.y, currMonPtr, NULL, TRUE, 0);
                        break;
                    }
                }
            }
        }
    }
}

void sub_806B678(void)
{
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *mon = gDungeon->teamPokemon[i];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            if (monInfo->isTeamLeader) {
                sub_803F4A0(mon);
                gUnknown_202EE0C = mon->pos;
                break;
            }
        }
    }
}
/*    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    DungeonPos pos;
    u8 unk10;*/

void sub_806B6C4(void)
{
    struct unkStruct_806B7F8 spStruct;
    s32 i, j;
    s32 x, y;
    bool8 r8 = (gDungeon->unk644.unk44 != 0);

    if (sub_80860A8(ITEM_MUSIC_BOX) && !HasRecruitedMon(MONSTER_MEW)) {
        gDungeon->unk37FF = FALSE;
    }
    else {
        gDungeon->unk37FF = TRUE;
    }

    x = DungeonRandInt(DUNGEON_MAX_SIZE_X);
    y = DungeonRandInt(DUNGEON_MAX_SIZE_Y);

    for (j = 0; j < DUNGEON_MAX_SIZE_Y; j++) {
        y++;
        if (y == DUNGEON_MAX_SIZE_Y) {y = 0;}

        for (i = 0; i < DUNGEON_MAX_SIZE_X; i++) {
            x++;
            if (x == DUNGEON_MAX_SIZE_X) {x = 0;}

            if (GetTile(x, y)->spawnOrVisibilityFlags & 8) {
                bool8 r6 = FALSE;

                if (r8) {
                    spStruct.species = gDungeon->unk644.unk44;
                    spStruct.level = 1;
                    spStruct.unk2 = 1;
                    r6 = TRUE;
                }
                else {
                    spStruct.species = sub_803D970(0);
                    spStruct.level = 0;
                    spStruct.unk2 = 0;
                }

                spStruct.unk4 = 0;
                spStruct.unk10 = 0;
                spStruct.pos.x = x;
                spStruct.pos.y = y;
                if (r6 || sub_806AA0C(spStruct.species, TRUE)) {
                    if (sub_806B7F8(&spStruct, FALSE)) {
                        r8 = FALSE;
                    }
                }
            }
        }
    }

    if (r8) {
        gDungeon->unkA = 1;
    }
}

Entity* sub_806B7F8(struct unkStruct_806B7F8 *structPtr, bool8 a1)
{
    Entity *entity;
    EntityInfo *entityInfo;
    const Tile *tile = GetTile(structPtr->pos.x, structPtr->pos.y);

    if (sub_807034C(structPtr->species, tile))
        return FALSE;

    entity = sub_804550C(structPtr->species);
    if (entity == NULL)
        return FALSE;

    sub_806BC68(FALSE, entity, structPtr, &gUnknown_202EE0C);
    entityInfo = GetEntInfo(entity);
    entityInfo->isNotTeamMember = TRUE;
    sub_806AED8(&entityInfo->moves, &entityInfo->maxHPStat, entityInfo->atk, entityInfo->def, entityInfo->id, entityInfo->level);
    entityInfo->HP = entityInfo->maxHPStat;
    entityInfo->moveRandomly = structPtr->unk4;
    if (!structPtr->unk2 && !a1 && !structPtr->unk10) {
        s32 rand = DungeonRandInt(100);
        if (GetChanceAsleep(structPtr->species) > rand) {
            sub_8075BF4(entity, 0x7F);
            sub_806CE68(entity, NUM_DIRECTIONS);
        }
    }

    return entity;
}

bool8 sub_806B8CC(s16 _species, s32 x, s32 y, PokemonStruct2 *monPtr, Entity **a4, bool32 _a5, u32 _a6)
{
    s32 i;
    DungeonPos unkPosition;
    struct unkStruct_806B7F8 spStruct;
    // s16 memes
    s32 species = SpeciesId(_species);
    bool8 a5 = _a5;
    u8 a6 = _a6;

    Entity *entity;
    EntityInfo *entityInfo;
    bool8 isTeamLeader = (monPtr->isTeamLeader != FALSE);

    if (a4 != NULL) {
        *a4 = NULL;
    }

    if (GetBaseSpecies(species) == MONSTER_DEOXYS_NORMAL) {
        if (a5) {
            species = gDungeon->deoxysForm;
        }
        else {
            species = MONSTER_DEOXYS_NORMAL;
        }
    }

    if (sub_807034C(species, GetTile(x, y)))
        return FALSE;

    entity = sub_80453AC(species);
    if (entity == NULL)
        return FALSE;

    spStruct.pos.x = x;
    spStruct.pos.y = y;
    spStruct.species = species;
    spStruct.level = monPtr->level;
    spStruct.unk2 = 0;
    spStruct.unk4 = 0;
    spStruct.unk10 = 0;

    unkPosition.x = gAdjacentTileOffsets[gUnknown_202F32C].x + x;
    unkPosition.y = gAdjacentTileOffsets[gUnknown_202F32C].y + y;
    sub_806BC68(TRUE, entity, &spStruct, (isTeamLeader ? &unkPosition : &gUnknown_202EE0C));

    entityInfo = GetEntInfo(entity);
    entityInfo->isNotTeamMember = FALSE;
    entityInfo->shopkeeper = 0;
    entityInfo->isTeamLeader = isTeamLeader;
    entityInfo->unkF9 = a6;

    gLeaderPointer = NULL;
    if (isTeamLeader) {
        gUnknown_202EE0C.x = x;
        gUnknown_202EE0C.y = y;
    }

    entityInfo->HP = monPtr->unk10;
    entityInfo->maxHPStat = monPtr->unk12;
    entityInfo->exp = monPtr->currExp;

    for (i = 0; i < 2; i++) {
        entityInfo->atk[i] = monPtr->offense.att[i];
        entityInfo->def[i] = monPtr->offense.def[i];
    }

    entityInfo->moves = monPtr->moves;
    for (i = 0; i < MAX_MON_MOVES; i++) {
        Move *move = &entityInfo->moves.moves[i];
        if (MoveFlagExists(move)) {
            move->moveFlags &= ~(MOVE_FLAG_LAST_USED);
            move->moveFlags &= ~(MOVE_FLAG_REPLACE);
        }
    }
    entityInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_LAST_USED);
    entityInfo->moves.struggleMoveFlags &= ~(MOVE_FLAG_REPLACE);

    entityInfo->level = monPtr->level;
    entityInfo->IQ = monPtr->IQ;
    entityInfo->tactic = monPtr->tacticIndex;
    entityInfo->IQSkillMenuFlags = monPtr->IQSkills;
    entityInfo->hiddenPower = monPtr->hiddenPower;
    entityInfo->joinedAt = monPtr->dungeonLocation;
    entityInfo->belly = monPtr->belly;
    entityInfo->maxBelly = monPtr->maxBelly;
    entityInfo->teamIndex = monPtr->unkC;
    entityInfo->heldItem = monPtr->itemSlot;
    entityInfo->unkF3 = 0;
    entityInfo->unk64 = 0;

    // Pickup Check
    if (gDungeon->unk644.dungeonLocation.id != DUNGEON_TINY_WOODS
        && !IsBossFight()
        && (entityInfo->abilities[0] == ABILITY_PICKUP || entityInfo->abilities[1] == ABILITY_PICKUP)
        && !ItemExists(&entityInfo->heldItem))
    {
        u32 pickUpItem = sub_803D73C(0);
        if (pickUpItem != ITEM_POKE) {
            xxx_init_itemslot_8090A8C(&entityInfo->heldItem, pickUpItem, 0);
            entityInfo->unkF3 = TRUE;
        }
    }

    sub_806A6E8(entity);
    LoadIQSkills(entity);
    if (a4) {
        *a4 = entity;
    }

    return TRUE;
}

// s16 species memes ughh https://decomp.me/scratch/jcfzb
#ifdef NONMATCHING
void sub_806BB6C(Entity *entity, s16 _species)
{
    s32 species = _species;
    s16 speciesMatch;
    struct unkStruct_806B7F8 spStruct;
    EntityInfo *entInfo = GetEntInfo(entity);

    DeletePokemonDungeonSprite(entInfo->unk98);
    speciesMatch = species;
    spStruct.species = speciesMatch;
    spStruct.level = 0;
    spStruct.unk2 = 0;
    spStruct.pos = entity->pos;
    spStruct.unk4 = 0;
{
    s16 apparentSpeciesMatch;
    s32 apparentSpecies = (GetMonsterApparentID(NULL, _species));

    entity->unk22 = 0;
    apparentSpeciesMatch = apparentSpecies;
    GetEntInfo(entity)->apparentID = (apparentSpecies);
    GetEntInfo(entity)->id = speciesMatch;
    entity->axObj.spriteFile = GetSpriteData(apparentSpeciesMatch);
}

    entity->axObj.unk42_animId1 = 7;
    entity->axObj.unk44_direction1 = 0;
    entity->axObj.unk43_animId2 = 0xFF;
    entity->axObj.unk45_orientation = 1;
    entity->axObj.unk47 = 1;
    entity->unk1C = 0;

    if (entInfo->frozenClassStatus.status == STATUS_WRAP || entInfo->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(entInfo->unk9C);
    }

    sub_806BC68((entInfo->isNotTeamMember == FALSE), entity, &spStruct, NULL);
    sub_806AED8(&entInfo->moves, &entInfo->maxHPStat, entInfo->atk, entInfo->def, entInfo->id, entInfo->level);
    entInfo->HP = entInfo->maxHPStat;
    entInfo->shopkeeper = 0;
    sub_80429E8(entity);
    EntityUpdateStatusSprites(entity);
}
#else
NAKED void sub_806BB6C(Entity *entity, s16 _species)
{
    asm_unified("\n"
"	push {r4-r7,lr}\n"
"	mov r7, r10\n"
"	mov r6, r9\n"
"	mov r5, r8\n"
"	push {r5-r7}\n"
"	sub sp, 0x1C\n"
"	adds r7, r0, 0\n"
"	lsls r4, r1, 16\n"
"	asrs r4, 16\n"
"	ldr r0, [r7, 0x70]\n"
"	mov r9, r0\n"
"	mov r8, r9\n"
"	adds r0, 0x98\n"
"	ldr r0, [r0]\n"
"	bl DeletePokemonDungeonSprite\n"
"	add r0, sp, 0x8\n"
"	movs r1, 0\n"
"	mov r10, r1\n"
"	movs r6, 0\n"
"	lsls r5, r4, 16\n"
"	lsrs r5, 16\n"
"	strh r5, [r0]\n"
"	strh r6, [r0, 0x8]\n"
"	mov r2, r10\n"
"	strb r2, [r0, 0x2]\n"
"	ldr r0, [r7, 0x4]\n"
"	str r0, [sp, 0x14]\n"
"	str r6, [sp, 0xC]\n"
"	movs r0, 0\n"
"	adds r1, r4, 0\n"
"	bl GetMonsterApparentID\n"
"	lsls r0, 16\n"
"	adds r1, r7, 0\n"
"	adds r1, 0x22\n"
"	mov r2, r10\n"
"	strb r2, [r1]\n"
"	ldr r1, [r7, 0x70]\n"
"	asrs r2, r0, 16\n"
"	lsrs r0, 16\n"
"	strh r0, [r1, 0x4]\n"
"	ldr r0, [r7, 0x70]\n"
"	strh r5, [r0, 0x2]\n"
"	adds r0, r2, 0\n"
"	bl GetSpriteData\n"
"	str r0, [r7, 0x64]\n"
"	adds r1, r7, 0\n"
"	adds r1, 0x6A\n"
"	movs r0, 0x7\n"
"	strb r0, [r1]\n"
"	adds r0, r7, 0\n"
"	adds r0, 0x6C\n"
"	mov r5, r10\n"
"	strb r5, [r0]\n"
"	adds r1, 0x1\n"
"	movs r0, 0xFF\n"
"	strb r0, [r1]\n"
"	adds r1, 0x2\n"
"	movs r0, 0x1\n"
"	strb r0, [r1]\n"
"	adds r1, 0x2\n"
"	strb r0, [r1]\n"
"	str r6, [r7, 0x1C]\n"
"	mov r0, r9\n"
"	adds r0, 0xB0\n"
"	ldrb r0, [r0]\n"
"	subs r0, 0x3\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	cmp r0, 0x1\n"
"	bhi _0806BC08\n"
"	mov r0, r9\n"
"	adds r0, 0x9C\n"
"	ldr r0, [r0]\n"
"	bl sub_8076CB4\n"
"_0806BC08:\n"
"	movs r1, 0\n"
"	mov r6, r9\n"
"	ldrb r0, [r6, 0x6]\n"
"	cmp r0, 0\n"
"	bne _0806BC14\n"
"	movs r1, 0x1\n"
"_0806BC14:\n"
"	adds r0, r1, 0\n"
"	adds r1, r7, 0\n"
"	add r2, sp, 0x8\n"
"	movs r3, 0\n"
"	bl sub_806BC68\n"
"	movs r0, 0x8C\n"
"	lsls r0, 1\n"
"	add r0, r8\n"
"	mov r1, r8\n"
"	adds r1, 0x10\n"
"	mov r2, r8\n"
"	adds r2, 0x14\n"
"	mov r3, r8\n"
"	adds r3, 0x16\n"
"	mov r5, r8\n"
"	movs r6, 0x2\n"
"	ldrsh r4, [r5, r6]\n"
"	str r4, [sp]\n"
"	ldrb r4, [r5, 0x9]\n"
"	str r4, [sp, 0x4]\n"
"	bl sub_806AED8\n"
"	ldrh r0, [r5, 0x10]\n"
"	strh r0, [r5, 0xE]\n"
"	mov r0, r10\n"
"	strb r0, [r5, 0x8]\n"
"	adds r0, r7, 0\n"
"	bl sub_80429E8\n"
"	adds r0, r7, 0\n"
"	bl EntityUpdateStatusSprites\n"
"	add sp, 0x1C\n"
"	pop {r3-r5}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	mov r10, r5\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0");
}
#endif // NONMATCHING

void sub_806BC68(bool8 a0, Entity *entity, struct unkStruct_806B7F8 *structPtr, DungeonPos *pos)
{
    DungeonPos entityPos;
    EntityInfo *entInfo;

    gDungeon->unkC = 1;
    entInfo = GetEntInfo(entity);
    ResetMonEntityData(entInfo, TRUE);
    entInfo->monsterBehavior = structPtr->unk2;
    entity->isVisible = TRUE;
    entity->unk22 = 0;
    entity->prevPos.x = -1;
    entity->prevPos.y = -1;
    entity->pos.x = -2;
    entity->pos.y = -2;

    sub_80694C0(entity, structPtr->pos.x, structPtr->pos.y, 1);
    sub_804535C(entity, NULL);

    if (!a0) {
        if (structPtr->species == MONSTER_KECLEON
            && !gDungeon->unk644.unk2A
            && gDungeon->unk3A0A
            && !structPtr->unk2)
        {
            entInfo->shopkeeper = 1;
        }
        else {
            entInfo->shopkeeper = 0;
        }

        if (GetBaseSpecies(entInfo->id) == MONSTER_DEOXYS_NORMAL) {
            gDungeon->unk37FD = TRUE;
        }
        if (GetBaseSpecies(entInfo->id) == MONSTER_MEW) {
            gDungeon->unk37FF = TRUE;
        }
    }

    entInfo->unk98 = gDungeon->unk37F0;
    gDungeon->unk37F0++;
    entInfo->unk9C = 0;
    if (structPtr->level == 0) {
        entInfo->level = sub_803DA20(structPtr->species);
    }
    else {
        entInfo->level = structPtr->level;
    }

    entInfo->moveRandomly = structPtr->unk4;
    entInfo->IQ = 1;
    SetDefaultIQSkills(&entInfo->IQSkillMenuFlags, FALSE);
    GenerateHiddenPower(&entInfo->hiddenPower);
    entInfo->maxHPStat = 1;
    entInfo->HP = 1;
    entInfo->belly = IntToFixedPoint(100);
    entInfo->maxBelly = IntToFixedPoint(100);

    if (pos != NULL) {
        entInfo->targetPos = *pos;
    }
    else {
        entInfo->targetPos.x = 0;
        entInfo->targetPos.y = 0;
    }

    entInfo->flags = 0;
    entInfo->aiAllySkip = FALSE;
    entInfo->recalculateFollow = FALSE;
    entInfo->numMoveTiles = 0;
    entInfo->notMoving = 0;
    entInfo->aiTarget.aiObjective = 0;
    entInfo->aiTarget.aiTargetPos = entity->pos;
    entInfo->aiTarget.aiTarget = NULL;
    entInfo->aiTarget.unkC = 0;
    entInfo->aiTarget.aiTargetSpawnGenID = 0;
    entInfo->unkFF = 0;
    entInfo->unk174.raw = 0;
    entInfo->decoyAITracker = 0;
    ResetMonEntityData(entInfo, TRUE);
    ZeroOutItem(&entInfo->heldItem);
    entInfo->unk64 = 0;
    entInfo->statusIcons = 0;
    entInfo->unk164 = 0xFF;
    entInfo->unk165 = 0xFF;
    entInfo->expGainedInTurn = 0;
    entInfo->waiting = 0;
    entInfo->unk146 = 0;
    entInfo->unk166 = 0;
    entInfo->unk1F8 = 0;
    entInfo->mobileTurnTimer = 0;
    entInfo->attacking = FALSE;
    entInfo->unk149 = FALSE;
    entInfo->abilityEffectFlags = FALSE;
    entInfo->terrifiedTurns = 0;
    entInfo->useHeldItem = 0;
    entInfo->unk14B = 0;
    entInfo->unk14C = 1;
    entInfo->visualFlags = 0;
    entInfo->previousVisualFlags = 0;
    entInfo->unk152 = 0;
    entInfo->unk153 = 0;
    entInfo->unk154 = 0;
    entInfo->unk155 = 0;
    entInfo->turnsSinceWarpScarfActivation = 0;
    entInfo->perishSongTurns = 0;
    entInfo->unkFE = 99;
    entInfo->unk158 = 0;
    entInfo->unk159 = 0;
    entInfo->unk15A = 0;
    CalcSpeedStage(entity);
    entInfo->unk156 = 1;
    entInfo->unk15C = 0;
    entInfo->unk15E = 0;
    entInfo->unk15D = 0;
    entInfo->unk15F = 0;
    entInfo->unk160 = 0;
    if (entInfo->apparentID == MONSTER_DIGLETT || entInfo->apparentID == MONSTER_DUGTRIO) {
        entInfo->unk156 = 0;
    }

    entityPos.x = entity->pos.x;
    entityPos.y = entity->pos.y;
    AddPokemonDungeonSprite(entInfo->unk98, entInfo->apparentID, &entityPos, gDungeon->unk181e8.unk18208);
    LoadIQSkills(entity);
    sub_806A898(entity, FALSE, FALSE);
}

void ResetMonEntityData(EntityInfo *entInfo, bool8 setStatsToOne)
{
    s32 i;
    bool8 hasForecast;

    entInfo->sleepClassStatus.status = 0;
    entInfo->sleepClassStatus.turns = 0;
    entInfo->burnClassStatus.status = 0;
    entInfo->burnClassStatus.turns = 0;
    entInfo->burnClassStatus.damageCountdown = 0;
    entInfo->burnClassStatus.unk4 = 0;
    entInfo->frozenClassStatus.status = 0;
    entInfo->frozenClassStatus.turns = 0;
    entInfo->frozenClassStatus.damageCountdown = 0;
    entInfo->frozenClassStatus.unk4 = 34;
    entInfo->cringeClassStatus.status = 0;
    entInfo->cringeClassStatus.turns = 0;
    entInfo->bideClassStatus.status = 0;
    entInfo->reflectClassStatus.status = 0;
    entInfo->reflectClassStatus.turns = 0;
    entInfo->curseClassStatus.status = 0;
    entInfo->curseClassStatus.turns = 0;
    entInfo->curseClassStatus.damageCountdown = 0;
    entInfo->leechSeedClassStatus.status = 0;
    entInfo->leechSeedClassStatus.turns = 0;
    entInfo->leechSeedClassStatus.damageCountdown = 0;
    entInfo->sureShotClassStatus.status = 0;
    entInfo->sureShotClassStatus.turns = 0;
    entInfo->longTossClassStatus.status = 0;
    entInfo->invisibleClassStatus.status = 0;
    entInfo->invisibleClassStatus.turns = 0;
    entInfo->blinkerClassStatus.status = 0;
    entInfo->blinkerClassStatus.turns = 0;
    entInfo->muzzled.muzzled = FALSE;
    entInfo->muzzled.turns = 0;
    entInfo->powerEars = FALSE;
    entInfo->scanning = FALSE;
    entInfo->stairSpotter = FALSE;
    entInfo->stairSpotter = FALSE;
    entInfo->unk164 = 0xFF;
    entInfo->unk165 = 0xFF;

    for (i = 0; i < NUM_SPEED_COUNTERS; i++) {
        entInfo->speedUpCounters[i] = 0;
        entInfo->speedDownCounters[i] = 0;
    }

    hasForecast = FALSE;
    for (i = 0; i < 2; i++) {
        entInfo->abilities[i] = GetPokemonAbility(entInfo->id, i);
        if (entInfo->abilities[i] == ABILITY_FORECAST) {
            hasForecast = TRUE;
        }
        if (setStatsToOne) {
            entInfo->atk[i] = 1;
            entInfo->def[i] = 1;
        }

        entInfo->offensiveStages[i] = 10;
        entInfo->defensiveStages[i] = 10;
        entInfo->hitChanceStages[i] = 10;
        entInfo->offensiveMultipliers[i].raw = IntToF248_2(1).raw;
        entInfo->defensiveMultipliers[i].raw = IntToF248_2(1).raw;
    }

    if (hasForecast) {
        entInfo->types[0] = gCastformByWeather[GetApparentWeather(NULL)].type;
        entInfo->types[1] = TYPE_NONE;
    }
    else {
        for (i = 0; i < 2; i++) {
            entInfo->types[i] = GetPokemonType(entInfo->id, i);
        }
    }

    gDungeon->unkC = 1;
    entInfo->flashFireBoost = 0;
    entInfo->stockpileStage = 0;
    entInfo->perishSongTurns = 0;
    entInfo->speedBoostFrames = 0;
    entInfo->grudge = 0;
    entInfo->expMultiplier = EXP_HALVED;
    entInfo->exposed = FALSE;
    entInfo->isColorChanged = 0;
    entInfo->bossFlag = 0;
    entInfo->unkFF = 0;
}

void sub_806C1D8(void)
{
    s32 i, j;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            EntityInfo *entInfo = GetEntInfo(entity);
            s32 teamIndex = entInfo->teamIndex;
            if (teamIndex >= 0) {
                for (j = 0; j < MAX_MON_MOVES; j++) {
                    if (MoveFlagExists(&entInfo->moves.moves[j])) {
                        entInfo->moves.moves[j].moveFlags2 &= ~(1);
                    }
                }
                sub_806C264(teamIndex, entInfo);
            }
        }
    }
}

void sub_806C264(s32 teamIndex, EntityInfo *entInfo)
{
    s32 i;
    PokemonStruct2 *monPtr = &gRecruitedPokemonRef->pokemon2[teamIndex];

    monPtr->unk10 = entInfo->HP;
    monPtr->unk12 = entInfo->maxHPStat;
    monPtr->currExp = entInfo->exp;
    for (i = 0; i < 2; i++) {
        monPtr->offense.att[i] = entInfo->atk[i];
        monPtr->offense.def[i] = entInfo->def[i];
    }

    if (IS_CASTFORM_FORM_MONSTER(entInfo->apparentID)) {
        monPtr->speciesNum = MONSTER_CASTFORM;
    }

    monPtr->moves = entInfo->moves;
    monPtr->level = entInfo->level;
    monPtr->IQ = entInfo->IQ;
    monPtr->IQSkills = entInfo->IQSkillMenuFlags;
    monPtr->tacticIndex = entInfo->tactic;
    monPtr->hiddenPower = entInfo->hiddenPower;
    monPtr->belly = entInfo->belly;
    monPtr->maxBelly = entInfo->maxBelly;
    monPtr->itemSlot = entInfo->heldItem;
    if (monPtr->unkA == 0x55AA) {
        monPtr->unkA = 0x5AA5;
    }
}

// s16 species memes again
void sub_806C330(s32 _x, s32 _y, s16 _species, u32 _a3)
{
    s32 i;
    s32 x = _x;
    s32 y = _y;
    s32 species = (_species);
    u8 a3 = _a3;
    unkDungeon57C *strPtr = &gDungeon->unk57C;

    for (i = 0; i < strPtr->unk40; i++) {
        if (strPtr->unkArray[i].unk3 && strPtr->unkArray[i].unk4 == x && strPtr->unkArray[i].unk5 == y) {
            s16 speciesMatchMe = SpeciesId(_species);
            strPtr->unkArray[i].unk0 = speciesMatchMe;
            strPtr->unkArray[i].unk2 = a3;
            return;
        }
    }

    if (strPtr->unk40 < UNK_DUNGEON57C_ARRAY_COUNT) {
        strPtr->unkArray[strPtr->unk40].unk3 = TRUE;
        strPtr->unkArray[strPtr->unk40].unk4 = x;
        strPtr->unkArray[strPtr->unk40].unk5 = y;
        strPtr->unkArray[strPtr->unk40].unk0 = species;
        strPtr->unkArray[strPtr->unk40].unk2 = a3;

        strPtr->unk40++;
    }
}

void sub_806C3C0(void)
{
    s32 i;
    struct unkStruct_806B7F8 spStruct;
    unkDungeon57C *strPtr = &gDungeon->unk57C;

    for (i = 0; i < strPtr->unk40; i++) {
        if (strPtr->unkArray[i].unk3) {
            spStruct.species = strPtr->unkArray[i].unk0;
            spStruct.level = 0;
            spStruct.pos.x = strPtr->unkArray[i].unk4;
            spStruct.pos.y = strPtr->unkArray[i].unk5;
            spStruct.unk2 = strPtr->unkArray[i].unk2;
            spStruct.unk4 = 0;
            spStruct.unk10 = 0;
            sub_806B7F8(&spStruct, TRUE);
        }
    }
}

void sub_806C42C(void)
{
    unkDungeon57C *strPtr = &gDungeon->unk57C;
    strPtr->unk40 = 0;
}

s32 sub_806C444(s32 _species, s32 level)
{
    LevelData levelData;
    s32 i;
    s32 species = SpeciesId(_species);
    s32 hpCount = GetBaseHP(species);

    for (i = 2; i <= level; i++) {
        GetPokemonLevelData(&levelData, species, i);
        hpCount += levelData.gainHP;
    }

    return hpCount;
}

s32 sub_806C488(s32 _species, s32 level, s32 categoryIndex)
{
    LevelData levelData;
    s32 i;
    s32 species = SpeciesId(_species);
    s32 offensiveCount = GetBaseOffensiveStat(species, categoryIndex);

    for (i = 2; i <= level; i++) {
        GetPokemonLevelData(&levelData, species, i);
        offensiveCount += levelData.gainAtt[categoryIndex];
    }

    return offensiveCount;
}

s32 sub_806C4D4(s32 _species, s32 level, s32 categoryIndex)
{
    LevelData levelData;
    s32 i;
    s32 species = SpeciesId(_species);
    s32 defensiveCount = GetBaseDefensiveStat(species, categoryIndex);

    for (i = 2; i <= level; i++) {
        GetPokemonLevelData(&levelData, species, i);
        defensiveCount += levelData.gainDef[categoryIndex];
    }

    return defensiveCount;
}

extern const u8 gUnknown_8106EC8[][13];

static inline u16 GetUnkFlag(Entity *entity)
{
    if ((entity->axObj.axdata.flags & 0x2000))
        return 0;
    else
        return entity->axObj.axdata.flags >> 15;
}

void sub_806C51C(Entity *entity)
{
    s32 x, y, y2;
    bool8 var_3C;
    bool8 decoySprite;
    s32 var_34;
    DungeonPos pos1;
    DungeonPos posArray[4];
    u32 statusSprites;
    bool8 r4;
    u8 r7;
    unkStruct_2039DB0 spriteMasks;
    s32 xSprite, ySprite;

    EntityInfo *entInfo = GetEntInfo(entity);
    if (gDungeon->unk181e8.cameraTarget == entity) {
        decoySprite = FALSE;
    }
    else {
        decoySprite = gDungeon->unk181e8.hallucinating;
    }

    if (entInfo->curseClassStatus.status == STATUS_DECOY) {
        decoySprite = TRUE;
    }

    if (entity->axObj.unk43_animId2 == entity->axObj.unk42_animId1 && entity->axObj.unk45_orientation == entity->axObj.unk44_direction1 && entity->axObj.unk47 == 0) {
        bool8 r2 = FALSE;

        if (!GetUnkFlag(entity))
            r2 = TRUE;

        if (r2) {
            s32 r0;
            s32 r3 = sub_806CEBC(entity);
            entity->unk21 = 1;
            if (entInfo->unkFE == 99) {
                if (entity->axObj.unk43_animId2 <= 12) {
                    s32 r2;
                    if (entInfo->bideClassStatus.status == STATUS_BIDE) {
                        r2 = 2;
                    }
                    else if (entity->unk23 < 3) {
                        r2 = 0;
                    }
                    else {
                        r2 = 1;
                    }

                    r0 = gUnknown_8106EC8[r2][entity->axObj.unk43_animId2];
                    if (r0 == 7) {
                        r0 = r3;
                    }
                }
                else {
                    r0 = 99;
                }
            }
            else {
                r0 = entInfo->unkFE;
            }

            if (r0 != 99) {
                entity->axObj.unk42_animId1 = r0;
                entity->axObj.unk44_direction1 = entity->axObj.unk45_orientation & DIRECTION_MASK;
                entity->axObj.unk47 = 1;
                if (entity->axObj.unk42_animId1 == 6 && ++entity->axObj.unk46 == 16) {
                    entity->axObj.unk42_animId1 = r3;
                }
            }
        }
    }

    if (entity->axObj.unk43_animId2 != entity->axObj.unk42_animId1 || entity->axObj.unk45_orientation != entity->axObj.unk44_direction1 || entity->axObj.unk47 != 0) {
        s32 r7;

        entity->axObj.unk43_animId2 = entity->axObj.unk42_animId1;
        entity->axObj.unk45_orientation = entity->axObj.unk44_direction1;
        entity->axObj.unk47 = 0;
        r7 = entity->axObj.unk40_maybeAnimTimer;
        if (sub_808DA44(entInfo->apparentID, entity->axObj.unk42_animId1)) {
            r7 = 0;
        }

        if (!decoySprite) {
            s32 rnd = Rand32Bit() & 3;
            AxResInitFile(&entity->axObj.axdata, entity->axObj.spriteFile, entity->axObj.unk42_animId1, entity->axObj.unk44_direction1, r7, rnd, FALSE);
        }
        else {
            OpenedFile *spriteData = GetSpriteData(MONSTER_DECOY);
            s32 rnd = Rand32Bit() & 3;
            AxResInitFile(&entity->axObj.axdata, spriteData, entity->axObj.unk42_animId1, entity->axObj.unk44_direction1, r7, rnd, FALSE);
        }

        if (entity->axObj.unk42_animId1 != 6) {
            entity->axObj.unk46 = 0;
        }
    }

    if (gDungeon->unk1356C) {
        if (entity->axObj.unk43_animId2 != 7 || GetMovementType(entInfo->apparentID) == 2) {
            if (entInfo->unk15C != 0) {
                if (entInfo->unk160 == 0) {
                    if (entInfo->unk15F != 0) {
                        RunAxAnimationFrame(&entity->axObj);
                        RunAxAnimationFrame(&entity->axObj);
                        RunAxAnimationFrame(&entity->axObj);
                    }
                    else {
                        RunAxAnimationFrame(&entity->axObj);
                    }
                }
            }
            else {
                RunAxAnimationFrame(&entity->axObj);
            }
        }
    }
    else {
        if (entInfo->frozenClassStatus.status != STATUS_FROZEN && entInfo->frozenClassStatus.status != STATUS_PETRIFIED) {
            if (gDungeon->unk644.unk28 != 0 && gDungeon->unk1BDD4.unk1C05F == 0) {
                RunAxAnimationFrame(&entity->axObj);
                RunAxAnimationFrame(&entity->axObj);
            }
            else if ((entity->axObj.unk43_animId2 == 0 || entity->axObj.unk43_animId2 == 7) && GetEntInfo(entity)->speedStage > 1) {
                RunAxAnimationFrame(&entity->axObj);
            }
            RunAxAnimationFrame(&entity->axObj);
        }
    }

    if (entity->pixelPos.x == entity->prevPixelPos.x && entity->pixelPos.y == entity->prevPixelPos.y) {
        if (entity->unk23 < 10) {
            entity->unk23++;
        }
    }
    else {
        entity->unk23 = 0;
    }

    entity->prevPixelPos.x = entity->pixelPos.x;
    entity->prevPixelPos.y = entity->pixelPos.y;

    x = (entity->pixelPos.x / 256) - gDungeon->unk181e8.cameraPixelPos.x;
    y = (((entity->pixelPos.y - entity->unk1C.raw) - entInfo->unk174.raw) / 256) - gDungeon->unk181e8.cameraPixelPos.y;
    y2 = (entity->pixelPos.y / 256) - gDungeon->unk181e8.cameraPixelPos.y;
    y2 /= 2;
    if (entInfo->unk156 == 0) {
        y2--;
    }

    if (entInfo->unk15C == 0) {
        var_3C = sub_8042768(entity);
    }
    else {
        if (entInfo->unk15D != 0) {
            if (gUnknown_202EDCC & 4) {
                x++;
            }
            else {
                x--;
            }
        }
        var_3C = (entInfo->unk15E == 0);
    }

    pos1.x = entity->pixelPos.x / 256;
    pos1.y = ((entity->pixelPos.y - entity->unk1C.raw) - entInfo->unk174.raw) / 256;

    sub_8005700(posArray, &entity->axObj);
    sub_800F958(entInfo->unk98, &pos1, posArray, gDungeon->unk181e8.unk18208);

    statusSprites = EntityGetStatusSprites(entity);
    UpdateDungeonPokemonSprite(entInfo->unk98, entInfo->apparentID, statusSprites, (var_3C && entInfo->unk14C));

    sub_8042EC8(entity, y2);
    if (entInfo->unk15C == 0) {
        if (entInfo->unkFF == 1) {
            if (entInfo->unk174.raw <= IntToF248_2(199.999).raw) {
                entInfo->unk174.raw += IntToF248_2(8).raw;
                if (entInfo->unk174.raw > IntToF248_2(200).raw) {
                    entInfo->unk174.raw = IntToF248_2(200).raw;
                }
            }
        }
        else {
            entInfo->unk174.raw -= IntToF248_2(12).raw;
            if (entInfo->unk174.raw < IntToF248_2(0).raw) {
                entInfo->unk174.raw = IntToF248_2(0).raw;
            }
        }
    }

    if (!var_3C)
        return;

    r4 = FALSE;
    r7 = sub_806CF54(entity);

    spriteMasks.unk0 = 0xF3FF;
    spriteMasks.unk2 = 0xFFFF;
    spriteMasks.unk4 = 0xF3FF;
    spriteMasks.unk6 = 0;
    spriteMasks.unk8 = 0;
    spriteMasks.unkA = gDungeon->unk181e8.unk18208 << 10;

    if (entInfo->isNotTeamMember && (entInfo->apparentID == MONSTER_DEOXYS_ATTACK || entInfo->apparentID == MONSTER_DEOXYS_DEFENSE || entInfo->apparentID == MONSTER_DEOXYS_SPEED)) {
        r4 = TRUE;
    }
    if (entInfo->invisibleClassStatus.status == STATUS_INVISIBLE && !gDungeon->unk181e8.unk1820F) {
        r4 = TRUE;
    }
    if (r4) {
        spriteMasks.unk6 |= 0x400;
    }

    var_34 = 0;
    if (!entInfo->isNotTeamMember || entInfo->curseClassStatus.status == STATUS_DECOY) {
        var_34 = 1;
    }
    if (IsExperienceLocked(entInfo->joinedAt.id) || entInfo->monsterBehavior == 1) {
        var_34 = 1;
    }

    if (entInfo->unkFF != 2) {
        s32 overworldPal;

        if (entInfo->frozenClassStatus.status == STATUS_PETRIFIED || entInfo->burnClassStatus.status == STATUS_PARALYSIS || entInfo->frozenClassStatus.status == STATUS_SHADOW_HOLD) {
            x += gUnknown_202EDCC & 2;
        }

        if (decoySprite) {
            overworldPal = GetPokemonOverworldPalette(MONSTER_DECOY, 0);
        }
        else {
            overworldPal = GetPokemonOverworldPalette(entInfo->apparentID, 0);
        }

        if (entity->unk22 == 0) {
            DoAxFrame_800558C(&entity->axObj, x, y, y2, overworldPal, &spriteMasks);
        }
        else if (entity->unk22 == 1 && (gUnknown_202EDCC & 1)) {
            DoAxFrame_800558C(&entity->axObj, x, y, y2, overworldPal, &spriteMasks);
        }
    }

    entInfo->pixelPos.x = (entity->pixelPos.x / 256) + entity->axObj.axdata.sub1.shadow.x;
    entInfo->pixelPos.y = (entity->pixelPos.y / 256) + entity->axObj.axdata.sub1.shadow.y;

    xSprite = entInfo->pixelPos.x - gDungeon->unk181e8.cameraPixelPos.x;
    ySprite = entInfo->pixelPos.y - gDungeon->unk181e8.cameraPixelPos.y;
    if (xSprite >= -32 && ySprite >= -32 && xSprite <= 271 && ySprite <= 191 && r7 != 6 && entity->unk22 == 0) {
        struct unkStruct_202ED28 *spriteStructPtr = &gUnknown_202ED28[var_34][r7];
        if (entInfo->unk156 != 0) {
            SpriteSetX(&spriteStructPtr->sprite, xSprite + spriteStructPtr->x);
            SpriteSetY(&spriteStructPtr->sprite, ySprite + spriteStructPtr->y);

            AddSprite(&spriteStructPtr->sprite, 0, NULL, NULL);
        }
    }
}
