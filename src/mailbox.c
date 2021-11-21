#include "global.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "input.h"
#include "mailbox.h"


extern void HandleMailboxMenu(void);
extern void nullsub_133(void);
extern void sub_802E578(void);
extern void HandleMailActionMenu(void);
extern void sub_802E73C(void);
extern void sub_802E758(void);
extern void sub_802E774(void);
extern void sub_802E7D0(void);


extern void sub_802E0A0(void);
extern void sub_802E1AC(void);

extern struct UnkTextStruct2 gUnknown_80E0284;
extern struct UnkTextStruct2 gUnknown_80E029C;
extern struct UnkTextStruct2 gUnknown_80E02B4;
extern struct UnkTextStruct2 gUnknown_80E02CC;


extern struct unkStruct_203B304 *gUnknown_203B304;
extern void sub_802E088(u32);
extern void sub_8012CAC(struct UnkTextStruct2 *, struct MenuItem *);
extern void CreateMailboxMenu(void);
extern void CreateMailActionMenu(void);

extern void sub_8012D60(u32 *, struct MenuItem *, u32, u16 *, u32, u32);
extern void sub_802BD14(u32, u32, u32);
extern void sub_802BE94(u32);
extern void CreateMailMenu(void);
extern void CreateMailAcceptedStatusBox(u32);
extern u32 sub_8095FE8(u32);
extern void sub_803B35C(u32, u32 *);
extern void sub_802DE84(u32 *);
extern void sub_802C860(u32);
extern void sub_802B640(u32, u32, u32);
extern void sub_802B7D0(u32);
extern void sub_802B9FC(u8);

u32 sub_802DFB0(void)
{
    gUnknown_203B304 = MemoryAlloc(sizeof(struct unkStruct_203B304), 8);
    gUnknown_203B304->unk64 = 0;
    gUnknown_203B304->unk68 = 0;
    SetMailboxState(0);
    return 1;
}

u32 sub_802DFD8(void)
{
    switch(gUnknown_203B304->state)
    {
        case 0:
            SetMailboxState(1);
            break;
        case 1:
            HandleMailboxMenu();
            break;
        case 2:
            nullsub_133();
            break;
        case 4:
        case 5:
            sub_802E578();
            break;
        case 6:
            HandleMailActionMenu();
            break;
        case 7:
            sub_802E73C();
            break;
        case 8:
            sub_802E758();
            break;
        case 9:
        case 0xA:
            sub_802E774();
            break;
        case 0xB:
            sub_802E7D0();
            break;
        case 3:
        default:
            return 3;
    }
    return 0;
}

void sub_802E06C(void)
{
    if(gUnknown_203B304 != NULL)
    {
        MemoryFree(gUnknown_203B304);
        gUnknown_203B304 = NULL;
    }
}

void SetMailboxState(u32 newState)
{
    gUnknown_203B304->state = newState;
    sub_802E0A0();
    sub_802E1AC();
}

void sub_802E0A0(void)
{
    s32 iVar1;
    sub_8006518(gUnknown_203B304->unk10C);
    switch(gUnknown_203B304->state)
    {
        case 1:
            for(iVar1 = 0; iVar1 < 4; iVar1++)
            {
                gUnknown_203B304->unk10C[iVar1] = gUnknown_80E0284;
            }
            CreateMailboxMenu();
            gUnknown_203B304->unk10C[2] = gUnknown_80E029C;
            sub_8012CAC(&gUnknown_203B304->unk10C[2], gUnknown_203B304->unkBC);
            break;
        case 6:
            CreateMailActionMenu();
            gUnknown_203B304->unk10C[2] = gUnknown_80E02B4;
            sub_8012CAC(&gUnknown_203B304->unk10C[2], gUnknown_203B304->unkBC);
            gUnknown_203B304->unk10C[2].unk0c = 6;
            gUnknown_203B304->unk10C[3] = gUnknown_80E02CC;
            break;
        default:
            for(iVar1 = 0; iVar1 < 4; iVar1++)
            {
                gUnknown_203B304->unk10C[iVar1] = gUnknown_80E0284;
            }
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B304->unk10C, 1, 1);
}

void sub_802E1AC(void)
{
    switch(gUnknown_203B304->state)
    {
        case 1:
            sub_8012D60(&gUnknown_203B304->unk6C, gUnknown_203B304->unkBC, 0, gUnknown_203B304->unkFC, gUnknown_203B304->unk64, 2);
            break;
        case 4:
            sub_802BD14(0, 0, 4);
            break;
        case 5:
            sub_802BE94(1);
            break;
        case 6:
            CreateMailMenu();
            CreateMailAcceptedStatusBox(3);
            sub_8012D60(&gUnknown_203B304->unk6C, gUnknown_203B304->unkBC, 0, 0, gUnknown_203B304->unk68, 2);
            break;
        case 7:
            sub_803B35C(sub_8095FE8(gUnknown_203B304->unk8), &gUnknown_203B304->unkC);
            gUnknown_203B304->unkC = 3;
            gUnknown_203B304->unk50 = 0;
            sub_802DE84(&gUnknown_203B304->unkC);
            break;
        case 8:
            sub_802C860(0);
            break;
        case 9:
            sub_802B640(0, 0, 8);
            break;
        case 0xA:
            sub_802B7D0(1);
            break;
        case 0xB:
            sub_802B9FC(gUnknown_203B304->mailIndex);
            break;
        case 0:
        case 2:
        case 3:
            break;
    }
}
