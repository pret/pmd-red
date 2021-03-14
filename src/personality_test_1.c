#include "global.h"
#include "constants/emotions.h"
#include "constants/species.h"
#include "personality_test.h"
#include "pokemon.h"

extern void sub_80073E0(u32);
extern void sub_80073B8(u32);
extern void sub_8008C54(u32);
extern void sub_800836C(u32, u8 *r0, u32);
extern void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray);

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

const struct unkData gUnknown_80F4278 = 
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const struct unkData gUnknown_80F4290 = 
{
    0x00, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x02, 0x00,
    0x09, 0x00, 0x0B, 0x00,
    0x0D, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const struct unkData gUnknown_80F42A8 = 
{
    0x00, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00,
    0x0E, 0x00, 0x04, 0x00,
    0x05, 0x00, 0x05, 0x00,
    0x05, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

extern u8 gUnknown_80F42D0[];
extern u8 gUnknown_80F42F0[];
extern u8 gUnknown_203B408;

// Definitely wrong but need to figure out better structure later
struct FaceData
{
    /* 0x0 */ u8 *unk0[5];
};

void PersonalityTest_DisplayPartnerSprite(void)
{
  s32 partnerID;
  struct OpenedFile *faceFile;
  int palleteIndex;
  u8 *r6;
  u32 faceIndex;

  partnerID = gUnknown_203B404->PartnerArray[gUnknown_203B404->currPartnerSelection];
  sub_8008C54(1);
  sub_80073B8(1);
  faceFile = GetDialogueSpriteDataPtr(partnerID);
  r6 = ((struct FaceData *)(faceFile->data))->unk0[1 + EMOTION_NORMAL];
  faceIndex = EMOTION_NORMAL;
  for(palleteIndex = 0; palleteIndex < 16; palleteIndex++){
    SetBGPaletteBufferColorArray(palleteIndex + 224,&((struct FaceData *)(faceFile->data))->unk0[faceIndex][palleteIndex << 2]);
  }
  sub_800836C(1,r6,0xe);
  CloseFile(faceFile);
  sub_80073E0(1);
  gUnknown_203B404->unk16 = 1;
}

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
