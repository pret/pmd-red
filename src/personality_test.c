#include "global.h"
#include "constants/species.h"

// TODO convert this... maybe a script?
const u8 gUnknown_80F4244[32] = 
{
    0, 0, 0, 0,
    5, 0, 0, 0,
    0xC, 0, 6, 0,
    5, 0, 5, 0,
    5, 0, 0, 0,
    0, 0, 0, 0,

    'p', 'k', 's', 'd', 'i', 'r', '0', 0
};

const u16 gPartners[10] = 
{
    SPECIES_CHARMANDER,
    SPECIES_BULBASAUR,
    SPECIES_SQUIRTLE,
    SPECIES_PIKACHU,
    SPECIES_CHIKORITA,
    SPECIES_TOTODILE,
    SPECIES_CYNDAQUIL,
    SPECIES_TORCHIC,
    SPECIES_TREECKO,
    SPECIES_MUDKIP
};

extern u8 gUnknown_80F42D0[];
extern u8 gUnknown_80F42F0[];
extern u8 gUnknown_203B408;

u8 sub_803D0D8()
{
    return gUnknown_203B408;
}

void sub_803D0E4(u8 r0)
{
    gUnknown_203B408 = r0;
}

u8 sub_803D0F0(u8 r0)
{
    return gUnknown_80F42F0[r0];
}

u8 sub_803D100(u8 r0)
{
    return gUnknown_80F42D0[r0];
}


