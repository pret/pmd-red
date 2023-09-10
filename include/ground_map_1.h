#ifndef GUARD_GROUND_MAP_1_H
#define GUARD_GROUND_MAP_1_H

void GroundMap_ExecuteEnter(s16);
void GroundMap_ExecuteEvent(s16 scriptIndex, u32);
void GroundMap_ExecuteStation(s16, s16, s8, u32);

bool8 sub_80A4D2C(s16);
bool8 sub_80A4D48(s16 index);

#endif // GUARD_GROUND_MAP_1_H