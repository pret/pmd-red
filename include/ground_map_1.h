#ifndef GUARD_GROUND_MAP_1_H
#define GUARD_GROUND_MAP_1_H

typedef struct unkStruct_811BAF4
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 *text;
} unkStruct_811BAF4;

void GroundMap_ExecuteEnter(s16);
void GroundMap_ExecuteEvent(s16, u32);
void GroundMap_ExecuteStation(s16, s16, s8, u32);

bool8 sub_80A4D2C(s16);
bool8 sub_80A4D48(s16);

#endif // GUARD_GROUND_MAP_1_H