#include "global.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "input.h"
#include "menu_input.h"
#include "pelipper_board.h"

extern void SetPelipperBoardState(u32);

const struct UnkTextStruct2 gUnknown_80E0330 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0348 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x03, 0x00, 0x03, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0360 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
    0x15, 0x00, 0x06, 0x00,
    0x07, 0x03,
    0x03, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80E0378 =
{
    0x00, 0x00, 0x00, 0x00,
    0x04,
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

extern void sub_802C10C(u32, u32, u32);
extern void sub_802C28C(u32);
extern void DrawPelipperBoardJobMenu(void);
extern void CreatePelipperAcceptedStatusBox(u32);
extern struct WonderMail *GetPelipperBoardSlotInfo(u32);
extern void sub_803B35C(struct WonderMail *, u32 *);
extern void sub_802DE84(u32 *);
extern void InitializeJobListMenu(u32);

u32 sub_802E864(void)
{
    gPelipperBoard = MemoryAlloc(sizeof(struct unkStruct_203B308), 8);
    gPelipperBoard->menuAction1 = 0;
    gPelipperBoard->menuAction2 = 0;
    gPelipperBoard->unk4 = 0;
    SetPelipperBoardState(INITIALIZE_PELIPPER_BOARD);
    return 1;
}

u32 sub_802E890(void)
{
    switch(gPelipperBoard->state)
    {
        case INITIALIZE_PELIPPER_BOARD:
            SetPelipperBoardState(MAIN_PELIPPER_BOARD_MENU);
            break;
        case MAIN_PELIPPER_BOARD_MENU:
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
        case PELIPPER_JOB_INFO:
            sub_802EEA0();
            break;
        case PELIPPER_JOB_LIST_MENU:
            sub_802EEBC();
            break;
        case PELIPPER_BOARD_EXIT:
        default:
            return 3;
    }
    return 0;
}

u32 sub_802E90C(void)
{
    return gPelipperBoard->unk4;
}

void sub_802E918(void)
{
    if(gPelipperBoard != NULL)
    {
        MemoryFree(gPelipperBoard);
        gPelipperBoard = NULL;
    }
}

void SetPelipperBoardState(u32 newState)
{
    gPelipperBoard->state = newState;
    sub_802E94C();
    sub_802EA58();
}

void sub_802E94C(void)
{
    s32 index;
    sub_8006518(gPelipperBoard->unk10C);
    switch(gPelipperBoard->state)
    {
        case MAIN_PELIPPER_BOARD_MENU:
            for(index = 0; index < 4; index++)
            {
                gPelipperBoard->unk10C[index] = gUnknown_80E0330;
            }
            CreatePelipperBoardMenu();
            gPelipperBoard->unk10C[2] = gUnknown_80E0348;
            sub_8012CAC(&gPelipperBoard->unk10C[2], gPelipperBoard->unkBC);
            break;
        case 6:
            sub_802EC10();
            gPelipperBoard->unk10C[2] = gUnknown_80E0360;
            sub_8012CAC(&gPelipperBoard->unk10C[2], gPelipperBoard->unkBC);
            gPelipperBoard->unk10C[2].unkC = 6;
            gPelipperBoard->unk10C[3] = gUnknown_80E0378;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gPelipperBoard->unk10C[index] = gUnknown_80E0330;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gPelipperBoard->unk10C, 1, 1);
}

void sub_802EA58(void)
{
    switch(gPelipperBoard->state)
    {
        case MAIN_PELIPPER_BOARD_MENU:
            sub_8012D60(&gPelipperBoard->unk6C, gPelipperBoard->unkBC, 0, gPelipperBoard->unkFC, gPelipperBoard->menuAction1, 2);
            break;
        case 4:
            sub_802C10C(0, 0, 4);
            break;
        case 5:
            sub_802C28C(1);
            break;
        case 6:
            DrawPelipperBoardJobMenu();
            CreatePelipperAcceptedStatusBox(3);
            sub_8012D60(&gPelipperBoard->unk6C, gPelipperBoard->unkBC, 0, 0, gPelipperBoard->menuAction2, 2);
            break;
        case PELIPPER_JOB_INFO:
            sub_803B35C(GetPelipperBoardSlotInfo(gPelipperBoard->jobIndex), &gPelipperBoard->unkC);
            gPelipperBoard->unkC = 3;
            gPelipperBoard->unk50 = 0;
            sub_802DE84(&gPelipperBoard->unkC);
            break;
        case PELIPPER_JOB_LIST_MENU:
            InitializeJobListMenu(0);
            break;
        case INITIALIZE_PELIPPER_BOARD:
        case 2:
        case PELIPPER_BOARD_EXIT:
            break;
    }
}
