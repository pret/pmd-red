#include "global.h"
#include "memory.h"
#include "text.h"
#include "menu.h"
#include "input.h"
#include "mailbox.h"

extern u8 gMailAccepted[];
extern u8 gUnknown_80E0324[];
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u32 sub_802BA8C(void);
extern void sub_802BACC(void);
extern u8 GetPokemonNewsIndex(void);
extern void sub_802B81C(void);
extern u32 sub_802B720(u32);
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);
extern u32 sub_802DEE0(void);
extern void sub_802DF24(void);

extern struct unkStruct_203B304 *gUnknown_203B304;


void sub_802E73C(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            SetMailboxState(5);
        case 0:
        case 1:
            break;
    }
}

void sub_802E758(void)
{
    switch(sub_802C898())
    {
        case 2:
        case 3:
            sub_802C8F4();
            SetMailboxState(1);
        case 0:
        case 1:
            break;
    }
}

void sub_802E774(void)
{
    switch(sub_802B720(1))
    {
        case 0:
        case 1:
            break;
        case 3:
        case 4:
            gUnknown_203B304->mailIndex = GetPokemonNewsIndex();
            gUnknown_203B304->unk4 = 0xA;
            SetMailboxState(0xB);
            break;
        case 2:
            sub_802B81C();
            SetMailboxState(0x1);
            break;
    }
}

void sub_802E7D0(void)
{
    switch(sub_802BA8C())
    {
        case 2:
        case 3:
            sub_802BACC();
            SetMailboxState(gUnknown_203B304->unk4);
        case 0:
        case 1:
            break;
    }
}

void nullsub_133(void)
{
}

void CreateMailAcceptedStatusBox(u32 r0)
{
    sub_8008C54(r0);
    sub_80073B8(r0);
    xxx_call_draw_string(3, 0, gMailAccepted, r0, 0);
    sub_8012BC4(0x12, 0xD, GetNumAcceptedJobs(), 2, 7, r0);
    xxx_call_draw_string(0x16, 0xD, gUnknown_80E0324, r0, 0); // "/"
    sub_8012BC4(0x23, 0xD, MAX_ACCEPTED_JOBS, 2, 7, r0);
    sub_80073E0(r0);
}
