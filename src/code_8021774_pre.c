#include "global.h"
#include "constants/friend_area.h"
#include "constants/input.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "text1.h"
#include "text2.h"
#include "item.h"
#include "team_inventory.h"
#include "menu_input.h"

struct unkStruct_203B280
{
    u8 unk0[NUM_FRIEND_AREAS];
    u32 unk3C;
    struct MenuInputStruct unk40;
    s32 unk74;
    struct UnkTextStruct2 *unk78;
    struct UnkTextStruct2 unk7C[4];
    u8 unkDC[4];
};
extern struct unkStruct_203B280 *gUnknown_203B280;
extern u32 gUnknown_203B284;
extern u16 gUnknown_203B288;
extern u16 gUnknown_203B28A;

extern struct UnkTextStruct2 gUnknown_80DC47C;
extern struct UnkTextStruct2 gUnknown_80DC464;

u8 sub_8021700(u32 mode);
s32 sub_8021664(void);
extern u8 sub_802132C(void);
extern void sub_8021410(void);
extern void sub_8021494(void);
extern void PlayMenuSoundEffect(u32);

bool8 sub_80211AC(u32 param_1, u32 param_2)
{
    if(sub_8021700(param_1))
    {
        return FALSE;
    }
    else {
        gUnknown_203B280 = MemoryAlloc(sizeof(struct unkStruct_203B280), 8);
        gUnknown_203B280->unk3C = param_1;
        gUnknown_203B280->unk74 = param_2;
        gUnknown_203B280->unk78 = &gUnknown_203B280->unk7C[gUnknown_203B280->unk74];
        sub_8006518(gUnknown_203B280->unk7C);
        gUnknown_203B280->unk7C[gUnknown_203B280->unk74] = gUnknown_80DC47C;
        gUnknown_203B280->unk78->unk14 = gUnknown_203B280->unkDC;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B280->unk7C, 1, 1);
        sub_8013818(&gUnknown_203B280->unk40, sub_8021664(), 10, param_2);
        if(gUnknown_203B284 == gUnknown_203B280->unk3C)
        {
            gUnknown_203B280->unk40.menuIndex = gUnknown_203B288;
            gUnknown_203B280->unk40.unk1E = gUnknown_203B28A;
            sub_8013984(&gUnknown_203B280->unk40);
        }
        sub_8021410();
        sub_8021494();
        return TRUE;
    }
}

u32 sub_8021274(u8 param_1)
{
    if (param_1 == 0) {
        sub_8013660(&gUnknown_203B280->unk40);
        return 0;
    }
    switch(GetKeyPress(&gUnknown_203B280->unk40))
    {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            if ((gUnknown_203B280->unk3C == 2)  && (GetFriendAreaPrice(sub_802132C()) > gTeamInventoryRef->teamMoney)) 
            {
                PlayMenuSoundEffect(2);
            }
            else
            {
                PlayMenuSoundEffect(0);
            }
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if (sub_80138B8(&gUnknown_203B280->unk40, 1) != 0) {
                sub_8021410();
                sub_8021494();
                return 1;
            }
            else {
                return 0;
            }
    }
}

u8 sub_802132C(void)
{
    return gUnknown_203B280->unk0[gUnknown_203B280->unk40.unk1E * gUnknown_203B280->unk40.unk1C + gUnknown_203B280->unk40.menuIndex];
}

void sub_8021354(u8 param_1)
{
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B280->unk7C,0,0);
    gUnknown_203B280->unk40.unk22 = sub_8021664();
    sub_8013984(&gUnknown_203B280->unk40);
    sub_8021410();
    sub_8021494();
    if (param_1) {
        AddMenuCursorSprite(&gUnknown_203B280->unk40);
    }
}

void sub_80213A0(void)
{
    if(gUnknown_203B280)
    {
        gUnknown_203B284 = gUnknown_203B280->unk3C;
        gUnknown_203B288 = gUnknown_203B280->unk40.menuIndex;
        gUnknown_203B28A = gUnknown_203B280->unk40.unk1E;
        gUnknown_203B280->unk7C[gUnknown_203B280->unk74] = gUnknown_80DC464;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B280->unk7C, 1, 1);
        MemoryFree(gUnknown_203B280);
        gUnknown_203B280 = NULL;
    }
}
