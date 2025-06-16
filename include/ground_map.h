#ifndef GUARD_GROUND_MAP_H
#define GUARD_GROUND_MAP_H

void GroundMap_Reset(void);
void AllocGroundMapAction(void);
void FreeGroundMapAction(void);
void sub_80A4B38(void);
void sub_80A4B54(void);
s16 GetAdjustedGroundMap(s32 mapId);

#endif // GUARD_GROUND_MAP_H
