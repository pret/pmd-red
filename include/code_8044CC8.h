#ifndef GUARD_CODE_8044CC8_H
#define GUARD_CODE_8044CC8_H

// size: 0x4
typedef struct unkStruct_202EE44
{
    u16 actionId;
    u8 unk2;
    bool8 canBeChosen;
} unkStruct_202EE44;

extern unkStruct_202EE44 gDungeonSubMenu[10];

void AddActionToDungeonSubMenu(u16 actionId, u8 param_2);
void SetActionUnusableInDungeonSubMenu(u16 actionId);

#endif // GUARD_CODE_8044CC8_H
