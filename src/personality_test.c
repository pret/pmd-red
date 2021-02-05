#include "global.h"
#include "constants/species.h"
#include "pokemon.h"

#define NUM_PARTNERS 10

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

const s16 gPartners[NUM_PARTNERS] = 
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

struct unkStruct_203B404
{
    // Size: 0xB8
    /* 0x0 */ s16 StarterID;
    /* 0x2 */ s16 PartnerArray[NUM_PARTNERS];
};

extern struct unkStruct_203B404 *gUnknown_203B404;

s32 GetValidPartners(void)
{
  u8 PlayerType[2];
  u8 currentPartnerTypes[2];
  s32 counter;
  s32 ValidPartnerCounter;
  s32 CurrentPartnerID;
  
  ValidPartnerCounter = 0;
  PlayerType[0] = GetPokemonType(gUnknown_203B404->StarterID,0);
  PlayerType[1] = GetPokemonType(gUnknown_203B404->StarterID,1);
  for(counter = 0; counter < NUM_PARTNERS; counter++){
    CurrentPartnerID = gPartners[counter];
    currentPartnerTypes[0] = GetPokemonType(CurrentPartnerID,0);
    currentPartnerTypes[1] = GetPokemonType(CurrentPartnerID,1);
    if (((currentPartnerTypes[0] == '\0') || ((currentPartnerTypes[0] != PlayerType[0] && (currentPartnerTypes[0] != PlayerType[1]))))
       && ((currentPartnerTypes[1] == '\0' || ((currentPartnerTypes[1] != PlayerType[0] && (currentPartnerTypes[1] != PlayerType[1])))
           ))) {
      gUnknown_203B404->PartnerArray[ValidPartnerCounter] = CurrentPartnerID;
      ValidPartnerCounter++;
    }
  }
  return ValidPartnerCounter;
}

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


