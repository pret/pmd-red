#include "global.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "input.h"

// Guessing based off of 203B304
struct unkStruct_203B308
{
    // size: 0xB6 << 1
    u32 state;
    u32 unk4;
    u8 jobIndex;
    u8 fill9[0xC - 9];
    u32 unkC;
    u8 fill10[0x50 - 0x10];
    u8 unk50;
    u8 fill51[0x64 - 0x51];
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u8 fill70[0xBC - 0x70];
    struct MenuItem unkBC[8];
    u16 unkFC[8];
    struct UnkTextStruct2 unk10C[4];
};
extern struct unkStruct_203B308 *gUnknown_203B308;
extern void SetPelipperBoardState(u32);

const struct UnkTextStruct2 gUnknown_80E0330 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0348 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x03, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0360 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00,
    0x15, 0x00, 0x06, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0378 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00,
    0x15, 0x00, 0x0f, 0x00,
    0x06, 0x03,
    0x03, 0x00,
    NULL
};

const u8 gPelipperBoard_BulletinBoard[] = "Bulletin Board";
const u8 gPelipperBoard_JobList[] = "Job List";
const u8 gPelipperBoard_Accepted[] = "Accepted";
const u8 gPelipperStatusSlash[] = "/";
static const u8 gPelipperfill[] = "pksdir0";

extern void sub_8012CAC(struct UnkTextStruct2 *, struct MenuItem *);
extern void sub_802ECB4(void);
extern void nullsub_134(void);
extern void sub_802ED4C(void);
extern void sub_802EDBC(void);
extern void sub_802EEA0(void);
extern void sub_802EEBC(void);
extern void sub_802E94C(void);
extern void sub_802EA58(void);
extern void CreatePelipperBoardMenu(void);
extern void sub_802EC10(void);

extern void sub_8012D60(u32 *, struct MenuItem *, u32, u16 *, u32, u32);
extern void sub_802C10C(u32, u32, u32);
extern void sub_802C28C(u32);
extern void sub_802C39C(void);
extern void CreatePelipperAcceptedStatusBox(u32);
extern struct WonderMail *GetPelliperBoardSlotInfo(u32);
extern void sub_803B35C(struct WonderMail *, u32 *);
extern void sub_802DE84(u32 *);
extern void sub_802C860(u32);

u32 sub_802E864(void)
{
    gUnknown_203B308 = MemoryAlloc(sizeof(struct unkStruct_203B308), 8);
    gUnknown_203B308->unk64 = 0;
    gUnknown_203B308->unk68 = 0;
    gUnknown_203B308->unk4 = 0;
    SetPelipperBoardState(0);
    return 1;
}

u32 sub_802E890(void)
{
    switch(gUnknown_203B308->state)
    {
        case 0:
            SetPelipperBoardState(1);
            break;
        case 1:
            sub_802ECB4();
            break;
        case 2:
            nullsub_134();
            break;
        case 4:
        case 5:
            sub_802ED4C();
            break;
        case 6:
            sub_802EDBC();
            break;
        case 7:
            sub_802EEA0();
            break;
        case 8:
            sub_802EEBC();
            break;
        case 3:
        default:
            return 3;
    }
    return 0;
}

u32 sub_802E90C(void)
{
    return gUnknown_203B308->unk4;
}

void sub_802E918(void)
{
    if(gUnknown_203B308 != NULL)
    {
        MemoryFree(gUnknown_203B308);
        gUnknown_203B308 = NULL;
    }
}

void SetPelipperBoardState(u32 newState)
{
    gUnknown_203B308->state = newState;
    sub_802E94C();
    sub_802EA58();
}

void sub_802E94C(void)
{
    s32 iVar1;
    sub_8006518(gUnknown_203B308->unk10C);
    switch(gUnknown_203B308->state)
    {
        case 1:
            for(iVar1 = 0; iVar1 < 4; iVar1++)
            {
                gUnknown_203B308->unk10C[iVar1] = gUnknown_80E0330;
            }
            CreatePelipperBoardMenu();
            gUnknown_203B308->unk10C[2] = gUnknown_80E0348;
            sub_8012CAC(&gUnknown_203B308->unk10C[2], gUnknown_203B308->unkBC);
            break;
        case 6:
            sub_802EC10();
            gUnknown_203B308->unk10C[2] = gUnknown_80E0360;
            sub_8012CAC(&gUnknown_203B308->unk10C[2], gUnknown_203B308->unkBC);
            gUnknown_203B308->unk10C[2].unk0c = 6;
            gUnknown_203B308->unk10C[3] = gUnknown_80E0378;
            break;
        default:
            for(iVar1 = 0; iVar1 < 4; iVar1++)
            {
                gUnknown_203B308->unk10C[iVar1] = gUnknown_80E0330;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B308->unk10C, 1, 1);
}

void sub_802EA58(void)
{
    switch(gUnknown_203B308->state)
    {
        case 1:
            sub_8012D60(&gUnknown_203B308->unk6C, gUnknown_203B308->unkBC, 0, gUnknown_203B308->unkFC, gUnknown_203B308->unk64, 2);
            break;
        case 4:
            sub_802C10C(0, 0, 4);
            break;
        case 5:
            sub_802C28C(1);
            break;
        case 6:
            sub_802C39C();
            CreatePelipperAcceptedStatusBox(3);
            sub_8012D60(&gUnknown_203B308->unk6C, gUnknown_203B308->unkBC, 0, 0, gUnknown_203B308->unk68, 2);
            break;
        case 7:
            sub_803B35C(GetPelliperBoardSlotInfo(gUnknown_203B308->jobIndex), &gUnknown_203B308->unkC);
            gUnknown_203B308->unkC = 3;
            gUnknown_203B308->unk50 = 0;
            sub_802DE84(&gUnknown_203B308->unkC);
            break;
        case 8:
            sub_802C860(0);
            break;
        case 0:
        case 2:
        case 3:
            break;
    }
}
