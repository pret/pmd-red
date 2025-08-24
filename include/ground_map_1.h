#ifndef GUARD_GROUND_MAP_1_H
#define GUARD_GROUND_MAP_1_H

// size: 0x24
#include "structs/str_position.h"

typedef struct unkStruct_3001B74
{
    s16 unk0;
    u8 unk2;
    s32 unk4;
    s32 unk8;
    PixelPos unkC;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
} unkStruct_3001B74;

void GroundWeather_Select(s16);
void nullsub_121(void);
void nullsub_122(void);
void nullsub_123(void);

void sub_80A5E70(void);
void sub_80A5E8C(u8);
void sub_80A5EBC(void);
void sub_80A5EDC(u8);
void sub_80A60D8(void);

#endif // GUARD_GROUND_MAP_1_H
