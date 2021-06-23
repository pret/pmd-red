#include "global.h"
#include "dungeon.h"

extern const char gUnknown_8108F10[];
extern const char gUnknown_8108F18[];
extern const char gUnknown_8108F2C[];

void ExpandPlaceholdersBuffer(u8 *buffer, const char *text, ...);


struct unkDungeonStruct
{
    u8 index;
    u8 floor;
};

void sub_8090208(u8 *buffer, struct unkDungeonStruct *dungeonLocation)
{
    ExpandPlaceholdersBuffer(buffer, gUnknown_8108F10, gDungeonNames[dungeonLocation->index].name1); // #cD%s#r (normal floor print (no B)
}

void PrintDungeonLocationtoBuffer(u8 *buffer, struct unkDungeonStruct *dungeonLocation)
{
    if(gDungeons[dungeonLocation->index].stairDirection != 0){
        ExpandPlaceholdersBuffer(buffer, gUnknown_8108F18, gDungeonNames[dungeonLocation->index].name1, dungeonLocation->floor); //_F
    }
    else
    {
        ExpandPlaceholdersBuffer(buffer, gUnknown_8108F2C, gDungeonNames[dungeonLocation->index].name1, dungeonLocation->floor); // B _F
    }
}

void CopyDungeonName1toBuffer(u8 *buffer, struct unkDungeonStruct *dungeonLocation)
{
    strncpy(buffer, gDungeonNames[dungeonLocation->index].name1, 0x50);
}
