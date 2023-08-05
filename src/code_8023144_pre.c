#include "global.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "constants/iq_skill.h"
#include "memory.h"
#include "menu.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "team_inventory.h"
#include "text1.h"
#include "input.h"
#include "item.h"
#include "menu_input.h"
#include "code_8023144.h"
#include "text2.h"

struct unkStruct_203B294 *gUnknown_203B294;
extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_80DC5EC[];
extern u8 HasGummiItem(void);
extern void sub_8022924(s32);
extern void sub_8022E78(void);
extern void sub_8022EF4(void);
extern void sub_8023068(void);
extern void sub_80230E8(void);
extern void sub_8023120(void);
extern void sub_8023104(void);
extern void sub_802293C(void);
extern void sub_8022A10(void);
extern void sub_8022D2C(void);

extern struct UnkTextStruct2 gUnknown_80DC5A4;
extern struct UnkTextStruct2 gUnknown_80DC5D4;
extern struct UnkTextStruct2 gUnknown_80DC5BC;

bool8 sub_80227B8(struct PokemonStruct *pokeStruct)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
    gUnknown_203B294 = MemoryAlloc(sizeof(struct unkStruct_203B294), 8);
    gUnknown_203B294->menuAction = 0;
    gUnknown_203B294->pokeStruct = pokeStruct;
    if(pokeStruct != NULL)
    {
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames, pokeStruct, COLOR_WHITE_2);
        PrintColoredPokeNameToBuffer(gAvailablePokemonNames + 0x50, pokeStruct, COLOR_YELLOW);
        if(HasGummiItem())
        {
            sub_8022924(0x0);
        }
        else 
        {
            sub_8022924(0x11);
        }
    }
    else {
        strcpy(gAvailablePokemonNames, gUnknown_80DC5EC);
        strcpy(gAvailablePokemonNames + 0x50, gUnknown_80DC5EC);
        if(GetNumberOfFilledInventorySlots() == 0)
        {
            sub_8022924(0x12);

        }
        else {
            sub_8022924(0x0);
        }
    }
    return TRUE;
}

u32 sub_8022860(void)
{
    switch(gUnknown_203B294->state) {
        case 0:
        case 1:
            sub_8022E78();
            break;
        case 2:
            sub_8022EF4();
            break;
        case 3:
            sub_8023068();
            break;
        case 4:
            sub_80230E8();
            break;
        case 0x15:
            sub_8023104();
            break;
        case 0x16:
            return 3;
        default:
            sub_8023120();
            break;
    }
    return 0;
}

void sub_8022908(void)
{
    if(gUnknown_203B294)
    {
        MemoryFree(gUnknown_203B294);
        gUnknown_203B294 = NULL;
    }
}

void sub_8022924(s32 newState)
{
    gUnknown_203B294->state = newState;
    sub_802293C();
    sub_8022A10();
}

void sub_802293C(void) {
    s32 index;
    sub_8006518(gUnknown_203B294->unk148);
    switch(gUnknown_203B294->state)
    {
        case 2:
            sub_8022D2C();
            gUnknown_203B294->unk148[2] = gUnknown_80DC5BC;
            sub_8012CAC(&gUnknown_203B294->unk148[2], gUnknown_203B294->unkF8);
            gUnknown_203B294->unk148[2].unkC = 6;
            break;
        case 3:
            gUnknown_203B294->unk148[1] = gUnknown_80DC5D4;
            break;
        default:
            for(index = 0; index < 4; index++)
            {
                gUnknown_203B294->unk148[index] = gUnknown_80DC5A4;
            }
            break;
        case 0xA ... 0x10:
            break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B294->unk148, 1, 1);

}
