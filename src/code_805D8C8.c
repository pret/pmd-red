#include "global.h"
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
#include "dungeon_message.h"
#include "constants/dungeon.h"

// monster_sbin.s
// data_8106A4C.s
extern const u8 gUnknown_8106EA0[]; // ax%03d
extern const u8 gUnknown_8106E98[]; // palet
// ???
extern s32 sprintf(char *, const char *, ...);

extern u32 gDungeonFramesCounter;

static void EnsureCastformLoaded(void);
static void EnsureDeoxysLoaded(void);

extern s32 gUnknown_202F310;

void sub_8068310(s32 size, u16 **param_2)
{
    s32 counter;
    s32 index;
    counter = 0;

    for(index = 0; index < size; index++) {
        if ((*param_2[index] & 0x8000) != 0) {
            counter++;
        }
    }
    gUnknown_202F310 = counter;
}

void sub_8068344(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 16);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (window->y  * 8) + 0x8);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}

// The same as sub_80623B0
void sub_80684C4(void)
{
    if ((gDungeonFramesCounter & 8) != 0) {
        Window *window = &gWindows[0];
        SpriteOAM sprite = {0};

        SpriteSetAffine1(&sprite, 0);
        SpriteSetAffine2(&sprite, 0);
        SpriteSetObjMode(&sprite, 0);
        SpriteSetMosaic(&sprite, 0);
        SpriteSetBpp(&sprite, 0);
        SpriteSetShape(&sprite, 1);
        SpriteSetMatrixNum(&sprite, 0);
        SpriteSetSize(&sprite, 0);
        SpriteSetTileNum(&sprite, 0x3F0);
        SpriteSetPriority(&sprite, 0);
        SpriteSetPalNum(&sprite, 15);
        SpriteSetY(&sprite, (window->y  * 8) + 0x70);
        SpriteSetX(&sprite, (window->x  * 8) + 0x40);
        AddSprite(&sprite,0x100,NULL,NULL);
    }
}

// FILE SPLIT HERE

void OpenDungeonPaletteFile(void)
{
    gDungeon->paletFile = OpenFileAndGetFileDataPtr(gUnknown_8106E98, &gMonsterFileArchive);
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

static void EnsureSpriteLoaded(s32 _id) // TODO: Should this param be s16? If so, the castform part of LoadPokemonSprite is preventing us
{
    u8 name[12];
    s32 id = SpeciesId(_id);

    if (gDungeon->sprites[id] == NULL) {
        sprintf(name, gUnknown_8106EA0, id);
        gDungeon->sprites[id] = OpenFileAndGetFileDataPtr(name, &gMonsterFileArchive);
    }
}

void LoadPokemonSprite(s16 id, bool32 a1)
{
    s32 id_s32 = SpeciesId(id);
    bool8 param_2 = a1;

    if (!param_2 && (id_s32 == MONSTER_DEOXYS_NORMAL || id_s32 == MONSTER_DEOXYS_ATTACK || id_s32 == MONSTER_DEOXYS_DEFENSE || id_s32 == MONSTER_DEOXYS_SPEED)) {
        EnsureDeoxysLoaded();
    }
    else {
        EnsureSpriteLoaded(id_s32);

        if ((u16)(id_s32 - MONSTER_CASTFORM) < 4)
            EnsureCastformLoaded();
    }
}
/*void LoadPokemonSprite(s16 id, bool8 a1)
{
    s32 id_s32 = SpeciesId(id);

    if (!a1 && (id_s32 == MONSTER_DEOXYS_NORMAL || id_s32 == MONSTER_DEOXYS_ATTACK || id_s32 == MONSTER_DEOXYS_DEFENSE || id_s32 == MONSTER_DEOXYS_SPEED)) {
        EnsureDeoxysLoaded();
    }
    else {
        EnsureSpriteLoaded(id);

        // TODO: >= MONSTER_CASTFORM && <= MONSTER_CASTFORM_RAINY
        if (id_s32 == MONSTER_CASTFORM || id_s32 == MONSTER_CASTFORM_SNOWY || id_s32 == MONSTER_CASTFORM_SUNNY || id_s32 == MONSTER_CASTFORM_RAINY)
        //if ((u16)(id_s32 - MONSTER_CASTFORM) < 4)
            EnsureCastformLoaded();
    }
}*/

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

extern bool8 IsLevelResetTo1(u8 dungeon);
extern void xxx_pokemonstruct_index_to_pokemon2_808DE30(void* r0, u32 r1);

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

extern u8 *gUnknown_80FE168[];
extern u8 *gUnknown_80FE134[];
extern u8 *gUnknown_80FE0F4[];
extern u8 *gUnknown_80FE0F8[];
extern u8 *gUnknown_80FE0AC[];

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

//
