#ifndef GUARD_DUNGEON_SERIALIZER_H
#define GUARD_DUNGEON_SERIALIZER_H

#include "data_serializer.h"

void ReadDungeonState(u8 *buffer, u32 bufLen);
void SaveDungeonState(u8 *buffer, u32 bufLen);

void sub_8082B40(void);

#endif // GUARD_DUNGEON_SERIALIZER_H