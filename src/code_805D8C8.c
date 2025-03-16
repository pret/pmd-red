#include "global.h"
#include "globaldata.h"
#include "code_805D8C8.h"
#include "structs/str_dungeon.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "file_system.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text.h"
#include "moves.h"
#include "string_format.h"
#include "friend_area.h"
#include "code_80450F8.h"
#include "code_8045A00.h"
#include "code_803E668.h"
#include "dungeon_engine.h"
#include "move_effects_target.h"
#include "dungeon_map_access.h"
#include "dungeon_map.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "constants/dungeon.h"
#include "constants/friend_area.h"
#include "constants/status.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_movement.h"
#include "dungeon_util.h"
#include "status_checks_1.h"
#include "code_8069D4C.h"


static void EnsureCastformLoaded(void);
static void EnsureDeoxysLoaded(void);

extern s32 sprintf(char *, const char *, ...);
extern bool8 IsLevelResetTo1(u8 dungeon);
extern void xxx_pokemonstruct_index_to_pokemon2_808DE30(void* r0, u32 r1);
extern void DeletePokemonDungeonSprite(s32 id);
extern void sub_803E178(void);
extern void sub_806C264(s32 teamIndex, EntityInfo *entInfo);
extern void sub_8083AB0(s16 param_0, Entity * target, Entity * entity);
extern bool8 sub_806A58C(s16 r0);
extern void sub_8084E00(Entity *entity, u8 param_2, u8 param_3);
extern void sub_8078084(Entity * pokemon);
extern void xxx_pokemon2_to_pokemonstruct_index_808DF2C(s32 a1, PokemonStruct2* a2);
extern bool8 sub_806A564(s32 r0);
extern void sub_808DFDC(s32 a1, PokemonStruct2* a2);
extern void xxx_pokemon2_to_pokemonstruct_808DF44(PokemonStruct1*, PokemonStruct2*);
extern void sub_8067A80(u8 a0, s32 a1, s32 a2, PokemonStruct1 **a3);
extern bool8 sub_806A5A4(s32 r0);
extern u8 sub_806A538(s32);
extern bool8 sub_8070F80(Entity * pokemon, s32 direction);
extern s32 sub_806A4DC(EntityInfo *info);

extern u8 *gUnknown_80FE168[];
extern u8 *gUnknown_80FE134[];
extern u8 *gUnknown_80FE0F4[];
extern u8 *gUnknown_80FE0F8[];
extern u8 *gUnknown_80FE0AC[];
extern u8 *gUnknown_80FE2D0[];
extern u8 *gUnknown_80FE268[];
extern u8 *gUnknown_80FE28C[];
extern u8 *gUnknown_80FA580[];
extern const u8 *const gUnknown_80FE1A4;
extern const u8 *const gUnknown_80FE20C;
extern const s16 gUnknown_810AC60; // 0xC
extern const s16 gUnknown_810AC62; // 0xC
extern const s16 gUnknown_810AC68; // 0x8
extern const s16 gUnknown_810AC64; // 0x8
extern const s16 gUnknown_810AC66; // 0x8

extern Entity *gLeaderPointer;
extern u8 gUnknown_202EE70[MAX_TEAM_BODY_SIZE];
extern u8 gUnknown_202EE76[DUNGEON_MAX_WILD_POKEMON_BODY_SIZE];
extern DungeonPos gPlayerDotMapPosition;
extern DungeonPos gUnknown_202EE0C;

void OpenDungeonPaletteFile(void)
{
    gDungeon->paletFile = OpenFileAndGetFileDataPtr("palet", &gMonsterFileArchive);
}

void CloseDungeonPaletteFile(void)
{
    CloseFile(gDungeon->paletFile);
}

void LoadDungeonPokemonSprites(void)
{
    s32 index;

    for(index = 0; index < 0x1A8; index++)
    {
        gDungeon->sprites[index] = NULL;
    }
    LoadPokemonSprite(MONSTER_DECOY, TRUE);
    for(index = 0; index < gDungeon->unk37E4; index++)
    {
        LoadPokemonSprite(ExtractSpeciesIndex(&gDungeon->unk343C[index]), TRUE);
    }
    if(gDungeon->unk644.unk44)
    {
        LoadPokemonSprite(gDungeon->unk644.unk44, TRUE);
    }
    for(index = 0; index < 4; index++)
    {
        PokemonStruct2 *ptr = &gRecruitedPokemonRef->pokemon2[index];
        if(PokemonFlag1Struct2(ptr))
            if(PokemonFlag2Struct2(ptr))
                LoadPokemonSprite(ptr->speciesNum, FALSE);
    }
    if(gDungeon->fixedRoomNumber == 0x31)
    {
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
        {
            PokemonStruct1 *ptr = &gRecruitedPokemonRef->team[index];
            if(PokemonFlag1(ptr))
                LoadPokemonSprite(ptr->speciesNum, TRUE);
        }
    }
}

void LoadDungeonActivePokemonSprites(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (entity != NULL && EntityIsValid(entity))
            LoadPokemonSprite(GetEntInfo(entity)->apparentID, FALSE);
    }
}

void sub_80687AC(void)
{
    gDungeon->unk37F0 = 0x400;
    gDungeon->unk37F4 = 10;
}

OpenedFile *GetSpriteData(s32 _species)
{
    s32 species = (s16)(_species);
    return gDungeon->sprites[species];
}

static void EnsureSpriteLoaded(s32 _id)
{
    u8 name[12];
    s32 id = (s16) _id;

    if (gDungeon->sprites[id] == NULL) {
        sprintf(name, "ax%03d", id);
        gDungeon->sprites[id] = OpenFileAndGetFileDataPtr(name, &gMonsterFileArchive);
    }
}

void LoadPokemonSprite(s32 _id, bool32 _ignoreDeoxys)
{
    s32 id = (s16) _id;
    bool8 ignoreDeoxys = _ignoreDeoxys;

    if (!ignoreDeoxys && (id == MONSTER_DEOXYS_NORMAL || id == MONSTER_DEOXYS_ATTACK || id == MONSTER_DEOXYS_DEFENSE || id == MONSTER_DEOXYS_SPEED)) {
        EnsureDeoxysLoaded();
    }
    else {
        s16 idS16;

        EnsureSpriteLoaded(id);
        idS16 = id;
        if (idS16 == MONSTER_CASTFORM || IS_CASTFORM_FORM_MONSTER(idS16))
            EnsureCastformLoaded();
    }
}

static void EnsureCastformLoaded(void)
{
    EnsureSpriteLoaded(MONSTER_CASTFORM);
    EnsureSpriteLoaded(MONSTER_CASTFORM_SNOWY);
    EnsureSpriteLoaded(MONSTER_CASTFORM_SUNNY);
    EnsureSpriteLoaded(MONSTER_CASTFORM_RAINY);
}

static void EnsureDeoxysLoaded(void)
{
    EnsureSpriteLoaded(gDungeon->deoxysForm);
}

void CloseAllSpriteFiles(void)
{
    s32 i;

    for (i = 0; i < MONSTER_MAX; i++) {
        if (gDungeon->sprites[i] != NULL) {
            CloseFile(gDungeon->sprites[i]);
            gDungeon->sprites[i] = NULL;
        }
    }
}

void sub_806890C(void)
{
    int index;
    int speciesId;

    index = 0;
    for (speciesId = 0; speciesId < NUM_MONSTERS; speciesId++) {
        PokemonStruct1 stack;
        PokemonStruct1 *pokeStruct = &gRecruitedPokemonRef->pokemon[speciesId];
        if (PokemonFlag1(pokeStruct) && PokemonFlag2(pokeStruct)) {
            xxx_pokemonstruct_index_to_pokemon2_808DE30(&gRecruitedPokemonRef->pokemon2[index],speciesId);
            if (IsLevelResetTo1(gDungeon->unk644.dungeonLocation.id)) {
                struct DungeonLocation dungeonLoc = {.id = DUNGEON_TINY_WOODS, .floor = 1};
                sub_808CFD0(&stack,pokeStruct->speciesNum,0,0,&dungeonLoc,0);
                gRecruitedPokemonRef->pokemon2[index].level = stack.level;
                gRecruitedPokemonRef->pokemon2[index].IQ = stack.IQ;
                gRecruitedPokemonRef->pokemon2[index].unk10 = stack.pokeHP;
                gRecruitedPokemonRef->pokemon2[index].unk12 = stack.pokeHP;
                gRecruitedPokemonRef->pokemon2[index].offense.att[0] = stack.offense.att[0];
                gRecruitedPokemonRef->pokemon2[index].offense.att[1] = stack.offense.att[1];
                gRecruitedPokemonRef->pokemon2[index].offense.def[0] = stack.offense.def[0];
                gRecruitedPokemonRef->pokemon2[index].offense.def[1] = stack.offense.def[1];
                gRecruitedPokemonRef->pokemon2[index].currExp = stack.currExp;
                gRecruitedPokemonRef->pokemon2[index].IQSkills = stack.IQSkills;
                gRecruitedPokemonRef->pokemon2[index].tacticIndex = stack.tacticIndex;
                CopyAndResetMoves(&gRecruitedPokemonRef->pokemon2[index].moves, stack.moves);
            }
            gRecruitedPokemonRef->pokemon2[index].unkC = index;
            index++;
            if (index == 4)
                break;
        }
    }
    for (; index < 4; index++) {
        gRecruitedPokemonRef->pokemon2[index].unk0 = 0;
    }
}

void sub_8068A84(PokemonStruct1 *pokemon)
{
    s32 i, totalBodySize;

    totalBodySize = 0;
    for (i = 0; i < 4; i++) {
        PokemonStruct2 *ptr = &gRecruitedPokemonRef->pokemon2[i];
        if (PokemonFlag1Struct2(ptr)) {
            totalBodySize += GetBodySize(ptr->speciesNum);
        }
    }

    totalBodySize += GetBodySize(pokemon->speciesNum);
    if (totalBodySize >= 7) {
        PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],pokemon,0);
        if (pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON) {
            DisplayDungeonMessage(0,*gUnknown_80FE0F4,1);
        }
        else if (pokemon->dungeonLocation.id == DUNGEON_RESCUE_TEAM_BASE) {
            DisplayDungeonMessage(0,*gUnknown_80FE0F8,1);
        }
        else {
            DisplayDungeonMessage(0,*gUnknown_80FE0AC,1);
        }
    }
    else {
        for (i = 0; i < 4; i++) {
            PokemonStruct2 *monPtr = &gRecruitedPokemonRef->pokemon2[i];
            if (!PokemonFlag1Struct2(monPtr)) {
                xxx_pokemonstruct_to_pokemon2_808DE50(monPtr,pokemon,0x55aa);
                monPtr->unk0 |= 1;
                if (monPtr->IQ < 0x1a) {
                    monPtr->IQ = 0x1a;
                }
                monPtr->unk0 |= 2;
                monPtr->unkC = i;
                ZeroOutItem(&monPtr->itemSlot);
                PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],pokemon,6);
                if (pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON) {
                    DisplayDungeonMessage(0,*gUnknown_80FE168,1);
                }
                else if (pokemon->dungeonLocation.id == DUNGEON_RESCUE_TEAM_BASE) {
                    ;
                }
                else {
                    DisplayDungeonMessage(0,*gUnknown_80FE134,1);
                }
                return;
            }
        }
        PrintColoredPokeNameToBuffer(gFormatBuffer_Monsters[0],pokemon,6);
        if (pokemon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON) {
            DisplayDungeonMessage(0,*gUnknown_80FE0F4,1);
        }
        else if (pokemon->dungeonLocation.id == DUNGEON_RESCUE_TEAM_BASE) {
            DisplayDungeonMessage(0,*gUnknown_80FE0F8,1);
        }
        else {
            DisplayDungeonMessage(0,*gUnknown_80FE0AC,1);
        }
    }
}

static inline bool8 IsUnkDungeon(u8 joinedDungeon)
{
    if (joinedDungeon == DUNGEON_POKEMON_SQUARE || joinedDungeon == DUNGEON_HOWLING_FOREST_2)
        return TRUE;
    else
        return FALSE;
}

void sub_8068BDC(bool8 a0)
{
    bool8 spArr[NUM_FRIEND_AREAS];
    PokemonStruct1 *monPointers[21];
    PokemonStruct1 mon1Structs[MAX_TEAM_MEMBERS];
    u16 arr2[18];
    FriendAreaCapacity areaCapacity;
    s32 i, j, id;

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        spArr[i] = FALSE;
    }

    for (id = 0; id < MAX_TEAM_MEMBERS; id++) {
        PokemonStruct2 *monPtr = &gRecruitedPokemonRef->pokemon2[id];
        if (PokemonFlag1Struct2(monPtr) && !sub_806A564(monPtr->unkA)) {
            Item *monItem = &monPtr->itemSlot;
            if (ItemExists(monItem) && monItem->id == ITEM_POKE) {
                AddToTeamMoney(GetMoneyValue(monItem));
                ZeroOutItem(monItem);
            }
        }
    }

    for (id = 0; id < MAX_TEAM_MEMBERS; id++) {
        PokemonStruct2 *monPtr = &gRecruitedPokemonRef->pokemon2[id];
        if (PokemonFlag1Struct2(monPtr) && !sub_806A564(monPtr->unkA)) {
            if (IS_CASTFORM_FORM_MONSTER(monPtr->speciesNum)) {
                monPtr->speciesNum = MONSTER_CASTFORM;
            }

            if (sub_806A58C(monPtr->unkA)) {
                if (IsLevelResetTo1(gDungeon->unk644.dungeonLocation.id)) {
                    sub_808DFDC(monPtr->unkA, monPtr);
                }
                else {
                    xxx_pokemon2_to_pokemonstruct_index_808DF2C(monPtr->unkA, monPtr);
                }
            }
            else {
                if (a0) {
                    spArr[GetFriendArea(monPtr->speciesNum)] = TRUE;
                }
            }
        }
    }

    for (i = 0; i < NUM_FRIEND_AREAS; i++) {
        u8 friendAreaId = i;
        if (!spArr[friendAreaId])
            continue;

        sub_8092404(friendAreaId, arr2, TRUE, TRUE);
        GetFriendAreaCapacity2(friendAreaId, &areaCapacity, FALSE, FALSE);
        for (j = 0; j < 21 && arr2[j] != 0xFFFF; j++) {
            monPointers[j] = &gRecruitedPokemonRef->pokemon[arr2[j]];
        }

        for (id = 0; id < MAX_TEAM_MEMBERS; id++) {
            PokemonStruct2 *monPtr = &gRecruitedPokemonRef->pokemon2[id];
            if (PokemonFlag1Struct2(monPtr) && sub_806A5A4(monPtr->unkA) && GetFriendArea(monPtr->speciesNum) == friendAreaId && a0) {
                monPointers[j] = &mon1Structs[id];
                xxx_pokemon2_to_pokemonstruct_808DF44(monPointers[j], monPtr);
                monPointers[j]->unk0 |= 0x4000;
                monPointers[j]->unkC[0].level = 0;
                monPointers[j]->unkC[1].level = 0;
                j++;
            }
        }

        if (j <= areaCapacity.maxPokemon) {
            s32 k;
            for (k = 0; k < j; k++) {
                if (monPointers[k]->unk0 & 0x4000) {
                    sub_808D1DC(monPointers[k]);
                }
            }
        }
        else {
            WriteFriendAreaName(gFormatBuffer_Items[0], friendAreaId, FALSE);
            DisplayDungeonMessage(NULL, gUnknown_80FE1A4, TRUE); // The Friend Area is full, a friend must be released.
            while (1) {
                sub_8067A80(friendAreaId, j - areaCapacity.maxPokemon, j, monPointers);
                for (id = 0; id < j; id++) {
                    PokemonStruct1 *monPtr = monPointers[id];
                    if (PokemonFlag1(monPtr) && (monPtr->unk0 & 0x8000)) {
                        if (IsUnkDungeon(monPtr->dungeonLocation.id)) {
                            break;
                        }
                    }
                }

                if (id == j)
                    break;
                if (DisplayDungeonYesNoMessage(NULL, gUnknown_80FE20C, TRUE) == TRUE) // If you dismiss this mon, it may never join you again. Bid farewell to it?
                    break;
            }

            for (id = 0; id < j; id++) {
                if (PokemonFlag1(monPointers[id]) && (monPointers[id]->unk0 & 0x8000)) {
                    monPointers[id]->unk0 = 0;
                }
            }
            for (id = 0; id < j; id++) {
                if (PokemonFlag1(monPointers[id]) && (monPointers[id]->unk0 & 0x4000)) {
                    sub_808D1DC(monPointers[id]);
                    monPointers[id]->unk0 = 0;
                }
            }
        }
    }
}

void sub_8068F28(void)
{
    s32 i;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        PokemonStruct2 *monStruct2Ptr = &gRecruitedPokemonRef->pokemon2[i];
        if (PokemonFlag1Struct2(monStruct2Ptr)) {
            if (sub_806A564(monStruct2Ptr->unkA)) {
                monStruct2Ptr->unk0 = 0;
            }
            else if (sub_806A538(monStruct2Ptr->unkA)) {
                monStruct2Ptr->unk0 = 0;
            }
        }
    }
}

void sub_8068F80(void)
{
    Entity *leader = GetLeader();
    Dungeon *dungeon = gDungeon;

    dungeon->unk644.unk28 = 0;
    dungeon->unk644.unk29 = 0;
    dungeon->unk644.unk2F = 0;
    dungeon->unkC0 = 0;
    if (leader != NULL) {
        bool8 isShop = (GetTileAtEntitySafe(leader)->terrainType & TERRAIN_TYPE_SHOP) != 0;
        dungeon->unk644.unk54 = isShop;
        dungeon->unk644.unk55 = isShop;
        sub_804AC20(&leader->pos);
    }
}

static inline void ClearOnTeamFlag(PokemonStruct1 *mon)
{
    mon->unk0 &= ~(FLAG_ON_TEAM);
}

static inline void ClearMonItemId(PokemonStruct1 *mon)
{
    mon->heldItem.id = ITEM_NOTHING;
}

void sub_8068FE0(Entity *entity, s32 param_2, Entity *param_3)
{
    u16 joinId;
    Entity EStack_a4;
    s32 i;
    s32 unkArg = (s16) param_2;
    EntityInfo *entInfo = GetEntInfo(entity);
    Tile *tile = GetTileAtEntitySafe(entity);
    if (param_3 == NULL) {
        sub_80457DC(&EStack_a4);
        param_3 = &EStack_a4;
    }
    if (tile->monster == entity) {
        tile->monster = NULL;
    }

    ShowDungeonMapAtPos(entity->pos.x,entity->pos.y);

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (mon != NULL && EntityIsValid(mon)) {
            EntityInfo *info = GetEntInfo(mon);
            if (info->aiTarget.aiTarget == entity) {
                info->aiTarget.aiTarget = NULL;
            }
        }
    }
    if (entInfo->curseClassStatus.status == STATUS_DECOY) {
        gDungeon->decoyIsActive = FALSE;
    }
    if (entInfo->frozenClassStatus.status == STATUS_WRAP || entInfo->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(entInfo->unk9C);
    }

    sub_8078084(entity);
    entity->unk22 = 0;
    entity->isVisible = FALSE;
    gLeaderPointer = NULL;
    joinId = entInfo->joinedAt.id;
    if (joinId == DUNGEON_JOIN_LOCATION_PARTNER && gDungeon->unk644.unk18 == 0) {
        gDungeon->unk10 = 1;
        entInfo->HP = 0;
        SubstitutePlaceholderStringTags(gDungeon->faintStringBuffer,entity,0);
        return;
    }

    #ifndef NONMATCHING
    // Yeah, this is just agbcc at its finest...
    joinId = entity->isVisible; joinId = entity->unk22;joinId = entity->isVisible; joinId = entity->unk22;joinId = entity->isVisible; joinId = entity->unk22;
    #endif
    if (entInfo->isTeamLeader) {
        sub_803E708(0x3c,0x49);
        DisplayMessageLog();
        if (gDungeon->unk6 == 0) {
            if (gDungeon->unk644.unk2A == 0
                && unkArg != 0x21c
                && unkArg != 0x222
                && unkArg != 0x21e
                && gDungeon->unk3A0D == 0
                && gDungeon->unk644.unk37 >= 0
                && gDungeon->unk644.unk34 != TRUE)
            {
                if (gDungeon->unk644.unk37 > 0) {
                    if (DisplayDungeonYesNoMessage(NULL,*gUnknown_80FE268,1) == 1) {
                        DisplayDungeonMessage(NULL,*gUnknown_80FE28C,1);
                        gDungeon->unk4 = 1;
                        gDungeon->unk6 = 1;
                        gDungeon->unk644.unk10 = 1;
                        gDungeon->unk644.unk37 -= 1;
                        return;
                    }
                }
                else {
                    DisplayDungeonMessage(NULL,*gUnknown_80FE2D0,1);
                }
            }
        }
        else {
            gDungeon->unk4 = 1;
            gDungeon->unk6 = 1;
            gDungeon->unk644.unk10 = 1;
            return;
        }

        sub_8083AB0(unkArg,param_3,entity);
        if (unkArg == 0x21f) {
            EntityInfo *partnerInfo = NULL;
            for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
                Entity *teamMon = gDungeon->teamPokemon[i];
                if (EntityIsValid(teamMon)) {
                    partnerInfo = GetEntInfo(teamMon);
                    if (partnerInfo->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
                        break;
                }
            }
            if (partnerInfo != NULL) {
                PokemonStruct2 *partnerStruct = &gRecruitedPokemonRef->pokemon2[partnerInfo->teamIndex];
                sub_806C264(partnerInfo->teamIndex,partnerInfo);
                if (sub_806A58C(partnerStruct->unkA) != 0) {
                    if (IsLevelResetTo1(gDungeon->unk644.dungeonLocation.id) == 0) {
                        xxx_pokemon2_to_pokemonstruct_index_808DF2C(partnerStruct->unkA, partnerStruct);
                    }
                    if (!IsMakuhitaTrainingMaze()) {
                        ClearMonItemId(&gRecruitedPokemonRef->pokemon[partnerStruct->unkA]);
                    }
                }
                partnerStruct->unk0 = 0;
            }
        }
    }

    if (entInfo->isNotTeamMember) {
        for (i = 0; i < entInfo->unk168; i++) {
            gUnknown_202EE76[entInfo->unk167 + i] = 0;
        }
    }
    else {
        for (i = 0; i < entInfo->unk168; i++) {
            gUnknown_202EE70[entInfo->unk167 + i] = 0;
        }
    }

    if (entInfo->joinedAt.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON) {
        gDungeon->unk10 = 2;
        SubstitutePlaceholderStringTags(gDungeon->faintStringBuffer,entity,0);
    }
    else if (entInfo->joinedAt.id == DUNGEON_RESCUE_TEAM_BASE) {
        gDungeon->unk10 = 3;
        SubstitutePlaceholderStringTags(gDungeon->faintStringBuffer,entity,0);
    }

    if (GetLeader() != NULL && unkArg != 0x21c && !entInfo->isTeamLeader && !gDungeon->unk10) {
        sub_8084E00(entity,entInfo->monsterBehavior, unkArg == 500);
        if (IS_DEOXYS_FORM_MONSTER(entInfo->apparentID) && !IsBossFight() && entInfo->isNotTeamMember) {
            gDungeon->deoxysDefeat = 1;
            DisplayDungeonLoggableMessageTrue(entity,*gUnknown_80FA580);
            sub_803E178();
            sub_8049ED4();
        }
    }

    if (!entInfo->isNotTeamMember) {
        PokemonStruct2 *mon2Ptr = &gRecruitedPokemonRef->pokemon2[entInfo->teamIndex];
        sub_806C264(entInfo->teamIndex,entInfo);
        if (sub_806A58C(mon2Ptr->unkA) != 0) {
            bool8 uVar10;

            if (IsLevelResetTo1(gDungeon->unk644.dungeonLocation.id) == 0) {
                xxx_pokemon2_to_pokemonstruct_index_808DF2C(mon2Ptr->unkA, mon2Ptr);
            }
            if (!IsMakuhitaTrainingMaze()) {
                ClearMonItemId(&gRecruitedPokemonRef->pokemon[mon2Ptr->unkA]);
            }

            uVar10 = FALSE;
            if (entInfo->isTeamLeader) {
                uVar10 = TRUE;
            }
            if (gDungeon->unk644.unk18 == 0 && entInfo->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER) {
                uVar10 = TRUE;
            }

            if (!uVar10) {
                ClearOnTeamFlag(&gRecruitedPokemonRef->pokemon[mon2Ptr->unkA]);
            }
        }
        mon2Ptr->unk0 = 0;
    }

    DeletePokemonDungeonSprite(entInfo->unk98);
    gLeaderPointer = 0;
    gDungeon->unkC = 1;
    entity->type = ENTITY_NOTHING;
    sub_8045ACC();
}

void sub_80694C0(Entity *target,s32 x,int y,char param_4)
{
    Tile *tile;
    Tile *tile2;
    EntityInfo *info;

    tile = GetTileMut(x,y);
    info = GetEntInfo(target);

    if (info->frozenClassStatus.status == STATUS_WRAP || info->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(info->unk9C);
    }
    if (info->frozenClassStatus.status == STATUS_CONSTRICTION || info->frozenClassStatus.status == STATUS_INGRAIN || info->frozenClassStatus.status == STATUS_SHADOW_HOLD) {
        EndFrozenClassStatus(target,target);
    }
    if ((x != (target->pos).x) || (y != (target->pos).y)) {
        if ((0 <= (target->pos).x) && (0 <= (target->pos).y)) {
            tile2 = GetTileMut((target->pos).x,(target->pos).y);
            if (tile2->monster == target) {
                tile2->monster = NULL;
            }
            ShowDungeonMapAtPos((target->pos).x,(target->pos).y);
        }
        (target->prevPos).x = (target->pos).x;
        (target->prevPos).y = (target->pos).y;
        (target->pos).x = x;
        (target->pos).y = y;
        if (info->isTeamLeader) {
            gPlayerDotMapPosition.x = x;
            gPlayerDotMapPosition.y = y;
        }
        tile->monster = target;
        if (info->isTeamLeader) {
            gUnknown_202EE0C.x = x;
            gUnknown_202EE0C.y = y;
            gDungeon->unk1 = 0;
        }
        ShowDungeonMapAtPos(x,y);

        switch(param_4)
        {
            case 0:
                info->prevPos[3] = info->prevPos[2];
                info->prevPos[2] = info->prevPos[1];
                info->prevPos[1] = info->prevPos[0];
                if (info->invisibleClassStatus.status != 1) {
                    info->prevPos[0] = target->prevPos;
                }
                break;
            case 1:
                info->prevPos[0] = target->pos;
                info->prevPos[1] = info->prevPos[0];
                info->prevPos[2] = info->prevPos[0];
                info->prevPos[3] = info->prevPos[0];
                break;
        }
        target->room = tile->room;
        sub_806CF98(target);
    }
    return;
}

void sub_80695EC(Entity *param_1,int x,int y)
{
    EntityInfo *info;

    info = GetEntInfo(param_1);
    if (info->frozenClassStatus.status == STATUS_WRAP || info->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(info->unk9C);
    }
    if ((x != (param_1->pos).x) || (y != (param_1->pos).y)) {
        param_1->prevPos.x = param_1->pos.x;
        param_1->prevPos.y = param_1->pos.y;
        param_1->pos.x = x;
        param_1->pos.y = y;
        info->prevPos[3] = info->prevPos[2];
        info->prevPos[2] = info->prevPos[1];
        info->prevPos[1] = info->prevPos[0];
        if (info->invisibleClassStatus.status != 1) {
            info->prevPos[0] = param_1->prevPos;
        }
        param_1->room = GetTile(x,y)->room;
    }
}

Entity * sub_8069660(Entity *target)
{
    const Tile *tile;

    EntityInfo *info;

    info = GetEntInfo(target);

    if(sub_8070F80(target, info->action.direction))
    {
        tile = GetTile((target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x,(target->pos).y + (gAdjacentTileOffsets)[info->action.direction].y);
        return tile->monster;
    }
    return NULL;
}

Entity * sub_80696A8(Entity *target)
{
    const Tile *tile;
    Entity *entity;

    EntityInfo *info;

    info = GetEntInfo(target);

    if(CanAttackInDirection(target, info->action.direction))
    {
        tile = GetTile((target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x,(target->pos).y + (gAdjacentTileOffsets)[info->action.direction].y);
        if (((entity = tile->monster, entity != NULL)) && (entity->type == ENTITY_MONSTER)) {
            return entity;
        }
    }
    return NULL;
}

Entity * sub_80696FC(Entity *target)
{
    const Tile *tile;
    Entity *entity;

    DungeonPos pos;
    EntityInfo *info;

    info = GetEntInfo(target);

    pos.x = (target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x;
    pos.y =  (target->pos).y + (gAdjacentTileOffsets)[info->action.direction].y;
    tile = GetTile(pos.x,pos.y);
    if (((!sub_80705F0(target,&pos)) && (entity = tile->monster, entity != NULL)) && (entity->type == ENTITY_MONSTER)) {
        return entity;
    }
    return NULL;
}

Entity * sub_806977C(Entity *target)
{
    const Tile *tile;
    Entity *entity;

    DungeonPos pos;
    EntityInfo *info;

    info = GetEntInfo(target);

    pos.x = (target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x;
    pos.y =  (target->pos).y + ((gAdjacentTileOffsets)[info->action.direction].y);
    GetTile(pos.x,(int)pos.y);
    if (!sub_80705F0(target,&pos)) {
        pos.x = (gAdjacentTileOffsets)[info->action.direction].x * 2 + (target->pos).x;
        pos.y = (gAdjacentTileOffsets)[info->action.direction].y * 2 + (target->pos).y;
        tile = GetTile(pos.x,pos.y);
        if (((!sub_80705F0(target,&pos)) && (entity = tile->monster, entity != NULL)) && (entity->type == ENTITY_MONSTER)) {
            return entity;
        }
    }
    return NULL;
}

void sub_8069844(struct unkStruct_808FF20 *param_1, Entity *target)
{
    int index;
    u8 *atkPtr;
    u8 *spAtkPtr;
    u8 *defPtr;
    s32 uVar15;
    u8 *spDefBoost;

    EntityInfo *info = GetEntInfo(target);

    SetMessageArgument_2(param_1->nameBuffer, info, 0);
    param_1->species = info->id;
    param_1->HP1 = info->HP;
    param_1->HP2 = info->maxHPStat;
    param_1->level = info->level;
    param_1->exp = info->exp;
    for(index = 0; index < 2; index++)
    {
        (param_1->offense).att[index] = info->atk[index];
        (param_1->offense).def[index] = info->def[index];
        param_1->types[index] = info->types[index];
        param_1->abilities[index] = info->abilities[index];
    }
    param_1->isTeamLeader = info->isTeamLeader;
    atkPtr = &param_1->atkBoost;
    *atkPtr = 0;
    spAtkPtr = &param_1->spAtkBoost;
    *spAtkPtr = 0;
    defPtr = &param_1->defBoost;
    *defPtr = 0;
    spDefBoost = &param_1->spDefBoost;
    *spDefBoost = 0;
    if ((info->heldItem.flags & ITEM_FLAG_EXISTS) && ((info->heldItem.flags & ITEM_FLAG_STICKY) == 0)) {
        if (info->heldItem.id == ITEM_POWER_BAND) {
            *atkPtr += gUnknown_810AC60;
        }
        if (info->heldItem.id == ITEM_MUNCH_BELT) {
            *atkPtr += gUnknown_810AC68;
        }
        if (info->heldItem.id == ITEM_SPECIAL_BAND) {
            *spAtkPtr += gUnknown_810AC62;
        }
        if (info->heldItem.id == ITEM_MUNCH_BELT) {
            *spAtkPtr += gUnknown_810AC68;
        }
        if (info->heldItem.id == ITEM_DEF_SCARF) {
            *defPtr += gUnknown_810AC64;
        }
        if (info->heldItem.id == ITEM_ZINC_BAND) {
            *spDefBoost += gUnknown_810AC66;
        }
    }
    param_1->tactic = info->tactic;
    param_1->item = info->heldItem;
    param_1->IQ = info->IQ;
    (param_1->dungeonLocation) = info->joinedAt;
    param_1->unk44[0].level = 0;
    param_1->unk44[1].level = 0;
    param_1->IQSkills = info->IQSkillMenuFlags;
    if (gDungeon->unk644.unk16 != 0) {
        param_1->unk4C = sub_806A4DC(info);
    }
    else {
        param_1->unk4C = 3;
    }

    uVar15 = 0;
    if (info->HP <= info->maxHPStat / 4) {
        param_1->unk58[0] = 6;
        uVar15 = 1;
    }

    if (gDungeon->unk644.itemHoldersIdentified) {
        param_1->unk58[uVar15] = 11;
        uVar15++;
    }
    if (FixedPointToInt(info->belly) == 0) {
        if (info->isTeamLeader) {
            param_1->unk58[uVar15] = 19;
        }
        else {
            param_1->unk58[uVar15] = 59;
        }

        uVar15++;
    }
    if (GetEntInfo(target)->speedStage > 1) {
        param_1->unk58[uVar15] = 27;
        uVar15++;
    }
    if (GetEntInfo(target)->speedStage < 1) {
        param_1->unk58[uVar15] = 40;
        uVar15++;
    }
    if ((((((info->offensiveMultipliers[0].raw < 0x100) || (info->offensiveMultipliers[1].raw < 0x100)
    ) || (info->defensiveMultipliers[0].raw < 0x100)) ||
        ((info->defensiveMultipliers[1].raw < 0x100 || (info->offensiveStages[0] < 10)))) ||
        ((info->offensiveStages[1] < 10 ||
        ((info->defensiveStages[0] < 10 || (info->defensiveStages[1] < 10)))))) ||
        ((info->hitChanceStages[0] < 10 || (info->hitChanceStages[1] < 10)))) {
        param_1->unk58[uVar15] = 55;
        uVar15++;
    }
    if (((info->sleepClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->sleepClassStatus).status;
        uVar15++;
    }
    if (((info->burnClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->burnClassStatus).status + 6;
        uVar15++;
    }
    if (((info->frozenClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->frozenClassStatus).status + 11;
        uVar15++;
    }
    if (((info->cringeClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->cringeClassStatus).status + 19;
        uVar15++;
    }
    if (((info->bideClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->bideClassStatus).status + 27;
        uVar15++;
    }
    if (((info->reflectClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->reflectClassStatus).status + 40;
        uVar15++;
    }
    if (((info->curseClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->curseClassStatus).status + 55;
        uVar15++;
    }
    if (((info->leechSeedClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->leechSeedClassStatus).status + 59;
        uVar15++;
    }
    if (((info->sureShotClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->sureShotClassStatus.status + 62;
        uVar15++;
    }
    if (((info->longTossClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->longTossClassStatus.status + 67;
        uVar15++;
    }
    if ((info->invisibleClassStatus.status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->invisibleClassStatus.status + 70;
        uVar15++;
    }
    if ((info->blinkerClassStatus.status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->blinkerClassStatus.status + 74;
        uVar15++;
    }
    if ((info->muzzled.muzzled) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->muzzled.muzzled + 78;
        uVar15++;
    }
    if ((info->stockpileStage != 0) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 80;
        uVar15++;
    }
    if ((info->powerEars) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 81;
        uVar15++;
    }
    if ((info->scanning) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 82;
        uVar15++;
    }
    if ((info->grudge) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 83;
        uVar15++;
    }
    if ((info->exposed) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 84;
        uVar15++;
    }
    if ((ShouldMonsterRunAway(target)) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 85;
        uVar15++;
    }
    if ((info->perishSongTurns != 0) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 86;
        uVar15++;
    }
    if ((1 < sub_8070828(target,FALSE)) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 87;
        uVar15++;
    }
    if (info->stairSpotter) {
        if (0xb < uVar15) {
            return;
        }
        param_1->unk58[uVar15] = 88;
        uVar15++;
    }

    for(; uVar15 < 0xC; uVar15++)
    {
        param_1->unk58[uVar15] = 0;
    }
    return;
}

u32 sub_8069D18(DungeonPos *pos,Entity *entity)
{
    EntityInfo *info;

    info = GetEntInfo(entity);

    pos->x = (entity->pos).x + gAdjacentTileOffsets[(info->action).direction].x;
    pos->y = (entity->pos).y + gAdjacentTileOffsets[(info->action).direction].y;
    return info->action.direction & 1;
}

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target)
{
    EntityInfo *info;
    LevelData leveldata;

    info = GetEntInfo(target);

    r0->id = info->id;
    r0->pos = target->pos;

    if(info->bossFlag)
        r0->HP = info->originalHP;
    else
        r0->HP = info->maxHPStat;

    r0->level = info->level;

    GetPokemonLevelData(&leveldata, info->id, info->level);
    r0->exp = leveldata.expRequired;
    r0->offense.att[0] = info->atk[0];
    r0->offense.att[1] = info->atk[1];
    r0->offense.def[0] = info->def[0];
    r0->offense.def[1] = info->def[1];
    r0->heldItem = info->heldItem;
    memcpy(r0->moves.moves, info->moves.moves, sizeof(r0->moves));
    r0->belly = info->belly;
    r0->maxBelly = info->maxBelly;
    r0->hiddenPower = info->hiddenPower;
}
