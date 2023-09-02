#ifndef GUARD_GROUND_MAP_H
#define GUARD_GROUND_MAP_H

// size: 0x55C
typedef struct unkStruct_3001B70
{
    u8 fill0[0x55C - 0x0];
} unkStruct_3001B70;

extern unkStruct_3001B70 *gUnknown_3001B70;

void GroundMap_Reset(void);

void sub_80A4A7C(void);
void sub_80A4AC4(void);
void sub_80A4B38(void);
void sub_80A4B54(void);

#endif // GUARD_GROUND_MAP_H