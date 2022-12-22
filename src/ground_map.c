#include "global.h"
#include "memory.h"
#include "debug.h"
#include "ground_script.h"

extern struct GroundScript_ExecutePP_1 *gUnknown_3001B6C;

extern struct DebugLocation gUnknown_8117538[];

extern u8 gUnknown_811736C[];
extern u8 *gUnknown_3001B70;

extern void sub_809D600(void *, u8 *, u32, u32, u32);
extern void GroundMap_Reset(void);
extern void sub_80A5E8C(u32);
extern void sub_809D648(void *);
extern void sub_80A5EBC(void);

extern void sub_80A2D00(void *);
extern void sub_80015C0(u32, u32);
extern void sub_80A5EDC(u32);
extern void sub_809D754(void *, struct DebugLocation *);
extern void sub_80A2D68(void *);
extern void nullsub_121(void);
extern void sub_80A2D88(void *);
extern void nullsub_122(void);

void sub_80A4A7C(void)
{
    gUnknown_3001B6C = MemoryAlloc(0x110, 6);
    gUnknown_3001B6C->unkE4 = -1;
    sub_809D600(gUnknown_3001B6C, gUnknown_811736C, 0, -1, -1);
    sub_80A5E8C(0);
    GroundMap_Reset();
}

void sub_80A4AC4(void)
{
    GroundMap_Reset();
    sub_80A5EBC();
    sub_809D648(gUnknown_3001B6C);
    MemoryFree(gUnknown_3001B6C);
    gUnknown_3001B6C = NULL;
}

void GroundMap_Reset(void)
{
    sub_80015C0(0, 0x37);
    sub_80015C0(0, 0x38);
    sub_809D754(gUnknown_3001B6C, gUnknown_8117538);
    if(gUnknown_3001B70 != NULL)
    {
        sub_80A2D00(gUnknown_3001B70);
        MemoryFree(gUnknown_3001B70);
        gUnknown_3001B70 = NULL;
    }
    sub_80A5EDC(0);
}

void sub_80A4B38(void)
{
    nullsub_121();
    if(gUnknown_3001B70 != NULL)
        sub_80A2D68(gUnknown_3001B70);
}

void sub_80A4B54(void)
{
    if(gUnknown_3001B70 != NULL)
        sub_80A2D88(gUnknown_3001B70);
    nullsub_122();
}
