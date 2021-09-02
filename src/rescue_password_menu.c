#include "global.h"
#include "memory.h"
#include "input.h"
#include "item.h"
#include "sub_8095228.h"
#include "text.h"
#include "main_menu.h"
#include "rescue_password_menu.h"

extern u8 gUnknown_202EC50[];
extern u32 gUnknown_202EC4C;

EWRAM_DATA u8 gUnknown_203B368;
EWRAM_DATA u32 gUnknown_203B36C;
EWRAM_DATA struct RescuePasswordMenu *gRescuePasswordMenu;

extern struct UnkTextStruct2 gUnknown_80E71E4;
extern s32 sub_8035D74(void);
extern void sub_80151C0(u32, u8 *);
extern void sub_8031D70(u32, u32);
extern u32 ConvertMenutoRescuePasswordState(u32);
extern void sub_8039174(void);
extern void sub_80155F0(void);
extern void sub_8031E10(void);

void CreateRescuePasswordMenu(u32 currMenu)
{
    struct unkStruct_8095228 *temp;
    s32 counter;

    if(gRescuePasswordMenu == NULL)
    {
        gRescuePasswordMenu = MemoryAlloc(sizeof(struct RescuePasswordMenu), 8);
        MemoryFill8((u8 *)gRescuePasswordMenu, 0, sizeof(struct RescuePasswordMenu));
    }

    for(counter = 0; counter < 4; counter++)
        gRescuePasswordMenu->unk148[counter] = gUnknown_80E71E4;

    ResetUnusedInputStruct();
    sub_800641C(gRescuePasswordMenu->unk148, 1, 1);

    if ((gUnknown_203B368 != 0) || (gUnknown_203B36C != currMenu)) {
        for(counter = 0; counter < 0x36; counter++)
        {
            gUnknown_202EC50[counter] = 0;
        }
        gUnknown_203B368 = 0;
    }

    gRescuePasswordMenu->currMenu = currMenu;
    gUnknown_203B36C = currMenu;

    switch(currMenu)
    {
        case 0x1B:
        case 0x1D:
        case 0x1F:
            sub_8031D70(sub_8035D74(), 0);
            break;
        case 0x1C:
        case 0x1E:
        case 0x20:
            sub_80151C0(4, gUnknown_202EC50);
            break;
        case MENU_DISPLAY_RESCUE_PASSWORD:
            temp = sub_8095228(0x1F);
            MemoryFill8((u8 *)temp, 0, sizeof(struct unkStruct_8095228));
            temp->unk0 = 2;
            temp->unk20.itemIndex = ITEM_ID_NOTHING;
            sub_8031D70(0x1F, 0);
            break;
        case MENU_RESCUE_PASSWORD_ENTRY:
            sub_80151C0(4, gUnknown_202EC50);
            break;
    }

    gRescuePasswordMenu->state = ConvertMenutoRescuePasswordState(currMenu);
    sub_8039174();
}

void CleanRescuePasswordMenu(void)
{

  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gRescuePasswordMenu != NULL) {
    sub_80155F0();
    sub_8031E10();
    MemoryFree(gRescuePasswordMenu);
    gRescuePasswordMenu = NULL;
  }
}
