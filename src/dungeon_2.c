#include "global.h"
#include "dungeon.h"
#include "code_800D090.h"
#include "pokemon.h"
#include "code_8092334.h"
#include "constants/dungeon.h"

extern const char gUnknown_8108F10[];
extern const char gUnknown_8108F18[];
extern const char gUnknown_8108F2C[];
extern u8 gUnknown_81077A8[];
extern u8 gUnknown_81077E8[];

void sub_80901D8(struct unkPokeSubStruct_4 *param_1,struct unkPokeSubStruct_4 *param_2)
{ 
  if ((u8)(param_2->dungeonIndex - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE) {
    param_1->dungeonIndex = DUNGEON_NORMAL_MAZE;
    param_1->dungeonFloor = (param_2->dungeonIndex - DUNGEON_NORMAL_MAZE_2) * 3 + param_2->dungeonFloor;
  }
  else {
    *param_1 = *param_2;
  }
}

void PrintYellowDungeonNametoBuffer(u8 *buffer, struct unkPokeSubStruct_4 *dungeonLocation)
{
    sprintf_2(buffer, gUnknown_8108F10, gDungeonNames[dungeonLocation->dungeonIndex].name1); // {COLOR_2 YELLOW_4}%s{END_COLOR_TEXT_2} (normal floor print (no B)
}

void PrintDungeonLocationtoBuffer(u8 *buffer, struct unkPokeSubStruct_4 *dungeonLocation)
{
    if(gDungeons[dungeonLocation->dungeonIndex].stairDirection != 0){
        sprintf_2(buffer, gUnknown_8108F18, gDungeonNames[dungeonLocation->dungeonIndex].name1, dungeonLocation->dungeonFloor); //_F
    }
    else
    {
        sprintf_2(buffer, gUnknown_8108F2C, gDungeonNames[dungeonLocation->dungeonIndex].name1, dungeonLocation->dungeonFloor); // B _F
    }
}

void CopyDungeonName1toBuffer(u8 *buffer, struct unkPokeSubStruct_4 *dungeonLocation)
{
    strncpy(buffer, gDungeonNames[dungeonLocation->dungeonIndex].name1, 0x50);
}

u8 sub_8090298(u8 dungeon)
{
    if ((u8)(dungeon - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE)
        return 4;
    else if(dungeon > DUNGEON_PURITY_FOREST)
        return 1;
    else
        return gUnknown_81077A8[dungeon];
}

u8 sub_80902C8(u8 dungeon)
{
    if ((u8)(dungeon - DUNGEON_NORMAL_MAZE_2) < NUM_DUNGEON_MAZE)
        return 0;
    else if(dungeon > DUNGEON_PURITY_FOREST)
        return 0;
    else
        return gUnknown_81077E8[dungeon];
}

void xxx_save_poke_sub_4_80902F4(struct unkStruct_8094924* r0, struct unkPokeSubStruct_4* r1)
{
    SaveIntegerBits(r0, &r1->dungeonIndex, 0x7);
    SaveIntegerBits(r0, &r1->dungeonFloor, 0x7);
}

void xxx_restore_poke_sub_4_8090314(struct unkStruct_8094924* r0, struct unkPokeSubStruct_4* r1)
{
    r1->dungeonIndex = 0;
    r1->dungeonFloor = 0;
    RestoreIntegerBits(r0, &r1->dungeonIndex, 0x7);
    RestoreIntegerBits(r0, &r1->dungeonFloor, 0x7);
}

u8 GetDungeonUnk1(u8 dungeon)
{
    return gDungeons[dungeon].unk1;
}
