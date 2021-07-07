#include "global.h"
#include "memory.h"
#include "text.h"
#include "item.h"
#include "gUnknown_203B460.h"

extern struct unkStruct_203B460 *gUnknown_203B460;

extern u16 GetItemMove(u8);
extern void sub_8092C84(u8 *, u16);
extern void sub_8099690(u32);
extern u32 sub_801B2F4(void);
extern void sub_801B064(s32);


extern void sub_801B200(void);
extern void sub_801B2AC(void);
extern void sub_801B2D8(void);
extern void nullsub_37();
extern void sub_801B080();

extern u32 gUnknown_80DB9BC;
extern u32 gUnknown_80DB9E4;
extern u32 gUnknown_80DBA0C;

extern u8 gUnknown_202E1C8[0x50];

extern bool8 sub_80915A0(u8);
extern void DisplayGulpinDialogueSprite(u32, u32, u32 *);
extern void sub_801B178(void);
extern void sub_8094060(u32 *, u32 *);
extern void PlaySound(u32);
extern void sub_80141B4(u32 *, u32, u32 ,u32);
extern void sub_8014248(u32 *, u32, u32, u32 *, u32, u32, u32, u32, u32);

struct subStruct_203B22C
{
    u8 fill0[0x2C];
    u32 unk2C;
};

struct unkStruct_203B22C
{
    // size: 0xa4
    s32 state;
    u32 unk4;
    u8 unk8; // item index
    u16 unkA; // item move??
    u32 unkC;
    u8 fill10[0x58 - 0x10];
    s16 unk58;
    u16 unk5A;
    struct subStruct_203B22C *unk5C;
    u32 unk60;
    u32 unk64;
};
extern struct unkStruct_203B22C *gUnknown_203B22C;

u32 sub_801AFA4(u32 r0)
{
    gUnknown_203B22C = MemoryAlloc(0xA4, 8);
    gUnknown_203B22C->unk4 = r0;
    gUnknown_203B22C->unk8 = gUnknown_203B460->fill0[r0].itemIndex;
    gUnknown_203B22C->unkA = GetItemMove(gUnknown_203B22C->unk8);
    sub_8092C84(gUnknown_202E1C8, gUnknown_203B22C->unkA);
    sub_8099690(0);
    if(sub_801B2F4() == 0)
    {
        sub_801B064(3);
    }
    else
    {
        gUnknown_203B22C->unk60 = 4;
        sub_801B064(0);
    }
    return 1;
}

u32 sub_801B00C(void)
{
    switch(gUnknown_203B22C->state)
    {
        case 4:
            return 3;
        case 0:
            sub_801B200();
            break;
        case 1:
            sub_801B2AC();
            break;
        default:
            sub_801B2D8();
            break;
    }
    return 0;
}

void sub_801B048(void)
{
    if(gUnknown_203B22C != NULL)
    {
        MemoryFree(gUnknown_203B22C);
        gUnknown_203B22C = NULL;
    }
}

void sub_801B064(s32 newState)
{
    gUnknown_203B22C->state = newState;
    nullsub_37();
    sub_801B080();
}

void nullsub_37(void)
{
}

void sub_801B080(void)
{
    switch(gUnknown_203B22C->state)
    {
        case 0:
            sub_801B178();
            // #+Who will learn the move
            // #+#C5$m7#R?
            sub_8014248(&gUnknown_80DB9BC, 0, gUnknown_203B22C->unk60, &gUnknown_203B22C->unk64, 0, 4, 0, 0, 0x20);
            break;
        case 1:
            DisplayGulpinDialogueSprite(2, gUnknown_203B22C->unk58, &gUnknown_203B22C->unkC);
            break;
        case 2:
            sub_8094060(&gUnknown_203B22C->unkC, &gUnknown_203B22C->unk5C->unk2C);
            if(!sub_80915A0(gUnknown_203B22C->unk8))
            {
                gUnknown_203B460->fill0[gUnknown_203B22C->unk4].numItems = gUnknown_203B22C->unk8 - 0x7D;
                gUnknown_203B460->fill0[gUnknown_203B22C->unk4].itemIndex = 0x7C;
            }
            PlaySound(0x9C << 1);
            // #+CM$m8#R learned
            // #+the move #C5$m7#R!
            sub_80141B4(&gUnknown_80DB9E4, 0, 0, 0x121);
            break;
        case 3:
            // #+No one in the current team
            // #+can learn this move.
            sub_80141B4(&gUnknown_80DBA0C, 0, 0, 0x121);
            break;
        default:
        case 4:
            break;
    }
}
