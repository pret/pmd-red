#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "memory.h"
#include "text.h"
#include "input.h"
#include "menu.h"
#include "gulpin_shop.h"
#include "menu_input.h"

extern struct unkStruct_203B26C *gUnknown_203B26C;
extern void UpdateGulpinShopState(u32);
extern void RemoveLinkSequenceFromMoves8(struct Move *, u32);
extern void sub_801F214(void);
extern s32 sub_80144A4(s32 *);
extern u32 sub_801F890(void);
extern void sub_801F8D0(void);
extern u8 IsNextMoveLinked(u32, struct Move *);
extern void PlaySound(u32);
extern u32 sub_801EF38(u32);
extern u32 sub_801F194(void);

void sub_801ED28(void)
{
    s32 menuAction;

    menuAction = 0;
    sub_801EF38(0);
    if(sub_8012FD8(&gUnknown_203B26C->unk78) == 0)
        sub_8013114(&gUnknown_203B26C->unk78,&menuAction);
    switch(menuAction)
    {
        case 1:
        case 5:
            UpdateGulpinShopState(1);
            break;
        case 2:
            PlaySound(0x133);
            gUnknown_203B26C->isNextMoveLinked = IsNextMoveLinked(gUnknown_203B26C->unk20, gUnknown_203B26C->moves);
            UpdateGulpinShopState(4);
            break;
        case 3:
            UpdateGulpinShopState(3);
    }
}

void sub_801EDA4(void)
{
        switch(sub_801F890())
        {
            case 2:
            case 3:
                sub_801F8D0();
                UpdateGulpinShopState(1);
                break;
            case 0:
            case 1:
                break;
        }
}

void sub_801EDC0(void)
{
    s32 temp;
    if(sub_80144A4(&temp) == 0){
        switch(temp)
        {
            case 4:
                sub_801F214();
                RemoveLinkSequenceFromMoves8(gUnknown_203B26C->moves, gUnknown_203B26C->unk20);
                gUnknown_203B26C->state = 5;
                break;
            case 1:
            case 5:
                UpdateGulpinShopState(1);
                break;
        }
    }
}
