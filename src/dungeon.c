#include "global.h"
#include "dungeon.h"
#include "code_800D090.h"
#include "pokemon.h"
#include "moves.h"
#include "random.h"
#include "code_8092334.h"
#include "pokemon_mid.h"
#include "string_format.h"
#include "constants/dungeon.h"
#include "constants/type.h"
#include "constants/monster.h"

extern const char gUnknown_8108F10[];
extern const char gUnknown_8108F18[];
extern const char gUnknown_8108F2C[];
extern u8 gInvalidDungeonIDs[];
extern u8 gDungeonFloorCount[];
extern const u8 *const gUnknown_8108084[];
extern DungeonLocation gUnknown_8107828[];
extern u8 gDungeonFloorCount[];
extern u8 gUnknown_81077E8[];
extern u8 gUnknown_8108F40[];
extern u8 *gUnknown_8115DD4[];
extern u8 *gUnknown_8115E54[];
extern u8 *gUnknown_8115A2C[];
extern u8 *gUnknown_81159DC[];
extern u8 *gUnknown_8115E00[];
extern u16 gUnknown_8108F42[];
extern u8 gUnknown_8108F4A[4];
extern u8 *gUnknown_8115ADC[];
extern u8 *gUnknown_8115A80[];
extern u8 *gUnknown_8115BA4[];
extern u8 *gUnknown_8115B3C[];
extern u8 *gUnknown_8115C4C[];
extern u8 *gUnknown_8115BF4[];
extern u8 *gUnknown_8115D14[];
extern u8 *gUnknown_8115CB8[];
extern u8 *gUnknown_8115D5C[];
extern u8 *gUnknown_8115D94[];
extern u8 *gUnknown_8115E28[];
extern u8 *gUnknown_8115E80[];
extern u8 gUnknown_8108F50[];

s32 sub_8091E94(s32 a1, s32 a2, s32 a3); // items.c
void sub_8090888(u8 *param_1, u8 *param_2);
bool8 sub_8090820(u16 moveID);
s32 GetItemPossessionCount(u8 id);

const u8 *GetDungeonName1(u8 dungeon)
{
    return gDungeonNames[dungeon].name1;
}

const u8 *GetDungeonName2(u8 dungeon)
{
    return gDungeonNames[dungeon].name2;
}

bool8 IsStairDirectionUp(u8 dungeon)
{
    return gDungeons[dungeon].stairDirectionUp;
}

s16 GetTurnLimit(u8 dungeon)
{
    return gDungeons[dungeon].turnLimit;
}

bool8 IsEnterWithoutGameSave(u8 dungeon)
{
    return gDungeons[dungeon].enterWithoutGameSave;
}

u8 HasCheckpoint(u8 dungeon)
{
    return gDungeons[dungeon].hasCheckpoint;
}

bool8 IsLevelResetTo1(u8 dungeon)
{
    return gDungeons[dungeon].levelResetTo1;
}

u32 GetMaxItemsAllowed(u8 dungeon)
{
    return gDungeons[dungeon].maxItemsAllowed;
}

bool8 IsKeepMoney(u8 dungeon)
{
    return gDungeons[dungeon].keepMoney;
}

s8 GetRescuesAllowed(u8 dungeon)
{
    return gDungeons[dungeon].rescuesAllowed;
}

bool8 IsRecruitingEnabled(u8 dungeon)
{
    return gDungeons[dungeon].recruitingEnabled;
}

bool8 CanLeaderSwitch(u8 dungeon)
{
    return gDungeons[dungeon].leaderCanSwitch;
}

s16 GetRandomMovementChance(u8 dungeon)
{
    return gDungeons[dungeon].randomMovementChance;
}

bool8 sub_809017C(DungeonLocation* a1)
{
    DungeonLocation location;
    int i;
    sub_80901D8(&location, a1);
    for (i = 0; i < 999 && gUnknown_8107828[i].id != 63; ++i) {
        if (location.id == gUnknown_8107828[i].id &&
            location.floor == gUnknown_8107828[i].floor) {
            return TRUE;
        }
    }
    return FALSE;
}

void sub_80901D8(DungeonLocation *param_1, DungeonLocation *param_2)
{
  if (DUNGEON_IS_MAZE(param_2->id)) {
    param_1->id = DUNGEON_NORMAL_MAZE;
    param_1->floor = (param_2->id - DUNGEON_NORMAL_MAZE_2) * 3 + param_2->floor;
  }
  else {
    *param_1 = *param_2;
  }
}

void PrintYellowDungeonNametoBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    sprintfStatic(buffer, gUnknown_8108F10, gDungeonNames[dungeonLocation->id].name1); // {color YELLOW_D}%s{reset} (normal floor print (no B)
}

void PrintDungeonLocationtoBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    if(gDungeons[dungeonLocation->id].stairDirectionUp){
        sprintfStatic(buffer, gUnknown_8108F18, gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); //_F
    }
    else
    {
        sprintfStatic(buffer, gUnknown_8108F2C, gDungeonNames[dungeonLocation->id].name1, dungeonLocation->floor); // B _F
    }
}

void CopyDungeonName1toBuffer(u8 *buffer, DungeonLocation *dungeonLocation)
{
    strncpy(buffer, gDungeonNames[dungeonLocation->id].name1, 0x50);
}

s32 GetDungeonFloorCount(u8 dungeon)
{
    if (DUNGEON_IS_MAZE(dungeon))
        return 4;
    else if(dungeon > DUNGEON_PURITY_FOREST)
        return 1;
    else
        return gDungeonFloorCount[dungeon];
}

s32 sub_80902C8(u8 dungeon)
{
    if (DUNGEON_IS_MAZE(dungeon))
        return 0;
    else if(dungeon > DUNGEON_PURITY_FOREST)
        return 0;
    else
        return gUnknown_81077E8[dungeon];
}

void WriteDungeonLocationBits(DataSerializer* r0, DungeonLocation* src)
{
    WriteBits(r0, &src->id, 7);
    WriteBits(r0, &src->floor, 7);
}

void ReadDungeonLocationBits(DataSerializer* r0, DungeonLocation* dst)
{
    dst->id = 0;
    dst->floor = 0;
    ReadBits(r0, &dst->id, 7);
    ReadBits(r0, &dst->floor, 7);
}

bool8 DoEnemiesEvolveWhenKOed(u8 dungeon)
{
    return gDungeons[dungeon].enemiesEvolveWhenKOed;
}

// Needed to match.
static inline void AddNewLine(const u8 *str, u8 *buffer, u8 *newLine)
{
    FormatString(str, buffer, newLine, 0);
}

u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_)
{
    s32 maxPartyMembers, i;

    s32 speciesId = (s16) speciesId_;
    bool32 param_4 = (bool8) (param_4_);
    bool32 param_5 = (bool8) (param_5_);

    s32 numInvSlots = GetNumberOfFilledInventorySlots();
    s32 counter = 0;
    s32 sp_0xf0;
    bool8 sp_0xf4 = FALSE;
    bool8 r8 = FALSE;
    u8 text[200];
    u8 newLine[2];

    newLine[0] = '\n';
    newLine[1] = 0;

    strcpy(buffer,gUnknown_8108F40);
    sp_0xf0 = 0;

    for (i = 0; i < NUM_MONSTERS; i++) {
        struct PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonFlag1(mon) && PokemonFlag2(mon)) {
            if (mon->heldItem.id != 0) {
                sp_0xf0++;
            }
            if (++counter == 4) break;
        }
    }

    maxPartyMembers = gDungeons[dungeonIndex].maxPartyMembers;
    if (!param_4 && maxPartyMembers > 3) {
        maxPartyMembers = 3;
    }
    if (counter > maxPartyMembers) {
        if (maxPartyMembers == 1) {
            AddNewLine(*gUnknown_8115A2C,text,newLine);
        }
        else {
            gFormatArgs[0] = counter - maxPartyMembers;
            AddNewLine(*gUnknown_81159DC,text,newLine);
        }
        sub_8090888(buffer,text);
        r8 = TRUE;
    }

    if (gDungeons[dungeonIndex].maxItemsAllowed != 0 && gDungeons[dungeonIndex].maxItemsAllowed < numInvSlots) {
        gFormatArgs[0] = gDungeons[dungeonIndex].maxItemsAllowed;
        gFormatArgs[1] = numInvSlots - gDungeons[dungeonIndex].maxItemsAllowed;
        AddNewLine((!r8) ? *gUnknown_8115A80 : *gUnknown_8115ADC, text, newLine);
        sub_8090888(buffer,text);
        r8 = TRUE;
    }

    if (speciesId != MONSTER_NONE) {
        s32 i, bodySize;

        CopyCyanMonsterNametoBuffer(gFormatBuffer_Monsters[0],speciesId);
        if (counter > 3) {
            AddNewLine((!r8) ? *gUnknown_8115B3C : *gUnknown_8115BA4, text,newLine);
            sub_8090888(buffer,text);
            r8 = TRUE;
        }
        bodySize = GetBodySize(speciesId);
        for (i = 0; i < NUM_MONSTERS; i++) {
            struct PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[i];

            if (PokemonFlag1(mon) && PokemonFlag2(mon)){
                bodySize += GetBodySize(mon->speciesNum);
            }
        }
        if (bodySize > 6) {
            AddNewLine((!r8) ? *gUnknown_8115BF4 : *gUnknown_8115C4C, text,newLine);
            sub_8090888(buffer,text);
            r8 = TRUE;
        }
    }
    if (param_4) {
        s32 i;
        //u16 local_4c[4] = {0x99, 0x9C, 0x9b, 0xdb};
        //u8 local_44[4] = {0xe1, 0xe7, 0xe6, 0xe2};
        u16 local_4c[4];
        u8 local_44[4];
        memcpy(local_4c,gUnknown_8108F42,8);
        memcpy(local_44,gUnknown_8108F4A,4);

        for (i = 0; i < 4; i++) {
            if ((((gDungeons[dungeonIndex].HMMask >> (i) & 1) != 0) && !sub_8090820(local_4c[i])) && GetItemPossessionCount(local_44[i]) == 0) {
                break;
            }
        }

        if (i < 4) {
            struct Move move;

            InitPokemonMove(&move,local_4c[i]);
            BufferMoveName(gFormatBuffer_Items[0],&move,0);
            AddNewLine((!r8) ? *gUnknown_8115CB8 : *gUnknown_8115D14, text,newLine);
            sub_8090888(buffer,text);
            r8 = TRUE;
        }
    }

    if (gDungeons[dungeonIndex].HMMask & 0x10) {
        s32 otherSpeciesId = NUM_MONSTERS;

        if (speciesId != MONSTER_NONE && (GetPokemonType(speciesId,0) == TYPE_WATER || (GetPokemonType(speciesId,1) == TYPE_WATER))) {
            otherSpeciesId = 0;
        }

        if (otherSpeciesId == NUM_MONSTERS) {
            for (otherSpeciesId = 0; otherSpeciesId < NUM_MONSTERS; otherSpeciesId++) {
                struct PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[otherSpeciesId];

                if (PokemonFlag1(mon) && PokemonFlag2(mon)
                    && (GetPokemonType(mon->speciesNum,0) == TYPE_WATER || GetPokemonType(mon->speciesNum,1) == TYPE_WATER))
                {
                    break;
                }
            }
            if (otherSpeciesId == NUM_MONSTERS) {
                AddNewLine((!r8) ? *gUnknown_8115D5C : *gUnknown_8115D94, text,newLine);
                sub_8090888(buffer,text);
                r8 = TRUE;
            }
        }
    }

    if (r8) {
        return 1;
    }

    if ((!gDungeons[dungeonIndex].enterWithoutGameSave) || (param_5)) {
        if (!sp_0xf4) {
            strcpy(buffer,*gUnknown_8115DD4);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer,*gUnknown_8115E00);
        strcat(buffer,newLine);
    }
    if (gDungeons[dungeonIndex].levelResetTo1) {
        if (!sp_0xf4) {
            strcpy(buffer,*gUnknown_8115DD4);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer,*gUnknown_8115E28);
        strcat(buffer,newLine);
    }
    if ((gDungeons[dungeonIndex].maxItemsAllowed == 0) && (numInvSlots + sp_0xf0 != 0)) {
        if (!sp_0xf4) {
            strcpy(buffer,*gUnknown_8115DD4);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer,*gUnknown_8115E54);
        strcat(buffer,newLine);
    }
    if ((!gDungeons[dungeonIndex].keepMoney) && (gTeamInventoryRef->teamMoney != 0)) {
        if (!sp_0xf4) {
            strcpy(buffer,*gUnknown_8115DD4);
            strcat(buffer,newLine);
            sp_0xf4 = TRUE;
        }
        strcat(buffer, *gUnknown_8115E80);
        strcat(buffer,newLine);
    }

    if (sp_0xf4) {
        return 2;
    }
    else {
        sprintfStatic(buffer,gUnknown_8108F50);
        return 0;
    }
}

bool8 sub_8090820(u16 moveID)
{
    s32 speciesId, moveIndex;

    for (speciesId = 0; speciesId < NUM_MONSTERS; speciesId++) {
        PokemonStruct1 *pokeStruct = &gRecruitedPokemonRef->pokemon[speciesId];
        if (PokemonFlag1(pokeStruct) && PokemonFlag2(pokeStruct)) {
            for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++) {
                Move *move = &pokeStruct->moves[moveIndex];
                if (MoveFlagExists(move) && move->id == moveID) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void sub_8090888(u8 *param_1, u8 *param_2)
{
    s32 iVar3 = 0;

    while (*param_1 != '\0') {
        switch (*param_1) {
            case '\n':
                iVar3++;
                break;
        }
        param_1++;
    }

    while (iVar3 % 3) {
        *param_1++ = '\n';
        iVar3++;
    }

    while (*param_2 != '\0') {
        *param_1++ = *param_2;
        param_2++;
    }

    *param_1 = '\0';
}

u32 sub_80908D8(DungeonLocation *dungeon)
{
    if (dungeon->id < DUNGEON_OUT_ON_RESCUE && dungeon->floor < gDungeonFloorCount[dungeon->id]) {
        return gUnknown_8108084[dungeon->id][dungeon->floor];
    }
    else {
        return 1;
    }
}

u8 sub_8090910(DungeonLocation *dungeon, u32 param_2)
{
    s32 rand1 = RandInt(9999);
    s32 rand2 = RandInt(9999);
    if (dungeon->id < DUNGEON_OUT_ON_RESCUE && dungeon->floor < gDungeonFloorCount[dungeon->id]) {
        return sub_8091E94(param_2, rand1, rand2);
    }
    else {
        return 0x46;
    }
}

bool8 IsNotValidDungeon(u8 dungeon)
{
    if (dungeon >= DUNGEON_OUT_ON_RESCUE) {
        return TRUE;
    }
    else {
        s32 i;
        for (i = 0; gInvalidDungeonIDs[i] != DUNGEON_OUT_ON_RESCUE; i++) {
            if (gInvalidDungeonIDs[i] == dungeon)
                return TRUE;
        }
        return FALSE;
    }
}
