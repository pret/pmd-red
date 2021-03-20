#include "global.h"

#define NUM_POKEMON_TYPES 18

extern const char gNoneText[];
extern const char gNormalText[];
extern const char gFireText[];
extern const char gWaterText[];
extern const char gGrassText[];
extern const char gElectricText[];
extern const char gIceText[];
extern const char gFightingText[];
extern const char gPoisonText[];
extern const char gGroundText[];
extern const char gFlyingText[];
extern const char gPsychicText[];
extern const char gBugText[];
extern const char gRockText[];
extern const char gGhostText[];
extern const char gDragonText[];
extern const char gDarkText[];
extern const char gSteelText[];

const char * const gUnformattedTypeStrings[NUM_POKEMON_TYPES] =
{
    gNoneText,
    gNormalText,
    gFireText,
    gWaterText,
    gGrassText,
    gElectricText,
    gIceText,
    gFightingText,
    gPoisonText,
    gGroundText,
    gFlyingText,
    gPsychicText,
    gBugText,
    gRockText,
    gGhostText,
    gDragonText,
    gDarkText,
    gSteelText,
};

#include "data/unformatted_type_names.h"

extern const char * gFormattedTypeStrings[NUM_POKEMON_TYPES]; // formatted type names

extern u8 gUnknown_810AC7C[];
extern u8 gUnknown_810AC6A[];

extern u8 *gAbilityNames[];
extern u8 *AbilityDescriptions[];

extern u32 gUnknown_810983C[26]; // TODO: verify size later

struct unkStruct_203B464
{
    u8 unk0[0xA]; // some string of sorts
    s32 unkC;
    u8 unk10;
};
extern struct unkStruct_203B464 *gUnknown_203B464;
extern struct unkStruct_203B464 gUnknown_2038C10;

extern void sub_809485C(u32 *r0, u8 *r1, u32 r2);
extern void sub_809486C(u32 *r0, u8 *r1, u32 r2);
extern void sub_809488C(u32 *r0, u8 *r1, u32 r2);
extern void sub_8094924(u32 *r0, u8 *r1, u32);
extern void nullsub_102(u32 *r0);
extern u8 sub_80023E4(u32);

extern const char *gRescueTeamRanks[];
extern s32 gUnknown_8109810[7];
extern u8 gUnknown_810982C[0x8]; // Pokemon
extern u8 gUnknown_810A35B[0x10];

// Forward declaration
void sub_80922B4(u8 *buffer, u8 *string, s32 size);
void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size);

bool32 sub_8092040(u8 param_1)
{
  s32 index;

  if (param_1 >= 0xF0)
      return TRUE;
  else {
    index = 0;
    while (gUnknown_810A35B[index] != 0xF0){
      if (gUnknown_810A35B[index] == param_1)
        return TRUE;
      index++;
    };
    return FALSE;
  }
}

void sub_809207C(void)
{
    gUnknown_203B464 = &gUnknown_2038C10;
}

struct unkStruct_203B464 *sub_809208C(void)
{
    return &gUnknown_2038C10;
}

void sub_8092094(void)
{
    BoundedCopyStringtoBuffer(gUnknown_203B464->unk0, gUnknown_810982C, 0xA);
    gUnknown_203B464->unkC = 0;
    gUnknown_203B464->unk10 = 0;
}

void sub_80920B8(u8 *buffer)
{
    s32 counter;
    for(counter = 0; counter < 0xA; counter++)
    {
        *buffer++ = gUnknown_203B464->unk0[counter];
    }
}

void sub_80920D8(u8 *buffer)
{
    sub_80922B4(buffer, gUnknown_203B464->unk0, 0xA);
}

void sub_80920EC(u8 *r0)
{
    s32 counter;
    for(counter = 0; counter < 0xA; counter++)
    {
        gUnknown_203B464->unk0[counter] = *r0++;
    }
}

s32 sub_8092110(void)
{
   return gUnknown_203B464->unkC;
}


#ifdef NONMATCHING
s32 sub_809211C(void)
{
  u8 uVar1;
  s32 iVar2;

  uVar1 = sub_8092178();
  if (uVar1 != 6) {
    // Goes to R2 instead of R1 but matches aside from that
    iVar2 =  gUnknown_8109810[uVar1] - gUnknown_203B464->unkC;
  }
  else
  {
    iVar2 = 0;
  }
  return iVar2;
}
#else
NAKED 
s32 sub_809211C(void)
{
    asm_unified(
	"\tpush {lr}\n"
	"\tbl sub_8092178\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tcmp r0, 0x6\n"
	"\tbeq _08092144\n"
	"\tldr r1, _0809213C\n"
	"\tlsls r0, 2\n"
	"\tadds r0, r1\n"
	"\tldr r1, _08092140\n"
	"\tldr r1, [r1]\n"
	"\tldr r0, [r0]\n"
	"\tldr r1, [r1, 0xC]\n"
	"\tsubs r0, r1\n"
	"\tb _08092146\n"
	"\t.align 2, 0\n"
"_0809213C: .4byte gUnknown_8109810\n"
"_08092140: .4byte gUnknown_203B464\n"
"_08092144:\n"
	"\tmovs r0, 0\n"
"_08092146:\n"
	"\tpop {r1}\n"
	"\tbx r1");
}
#endif


// Unused
void sub_809214C(s32 param_1)
{
    gUnknown_203B464->unkC = param_1;
}

void sub_8092158(s32 param_1)
{
  gUnknown_203B464->unkC += param_1;
  if (gUnknown_203B464->unkC > 99999999) {
   gUnknown_203B464->unkC = 99999999;
  }
}

u8 sub_8092178(void)
{
  s32 index;

  for(index = 0; index < 7; index++){
    if (gUnknown_203B464->unkC < gUnknown_8109810[index]) {
      return index;
    }
  }
  return 6;
}

const char *GetTeamRankString(u8 index)
{
    return gRescueTeamRanks[index];
}

// Unused
u8 sub_80921B8(void)
{
    return gUnknown_203B464->unk10;
}

u32 sub_80921C4(u8 *param_1,u32 param_2)

{
    u32 auStack36[4];
    u8 neg1;
    u8 zero;
    u8 *puVar2;

    neg1 = -1;
    zero = 0;

    sub_809486C(auStack36, param_1, param_2);
    sub_809488C(auStack36, gUnknown_203B464->unk0, 0x58);
    sub_809488C(auStack36, (u8 *)&gUnknown_203B464->unkC, 0x20);
    gUnknown_203B464->unk10 = sub_80023E4(0);

    if (gUnknown_203B464->unk10 != 0)
    {
        puVar2 = &neg1;
    }
    else
    {
        puVar2 = &zero;
    }
    sub_809488C(auStack36,puVar2,1);
    nullsub_102(auStack36);
    return auStack36[2];
}

u32 sub_809222C(u8 *param_1, u32 param_2)
{
  u32 auStack32 [4];
  u8 byteArray[4];

  sub_809485C(auStack32, param_1, param_2);
  sub_8094924(auStack32, gUnknown_203B464->unk0, 0x58);
  sub_8094924(auStack32, (u8 *)&gUnknown_203B464->unkC, 0x20);
  sub_8094924(auStack32, byteArray, 1);
  gUnknown_203B464->unk10 = byteArray[0] & 1;
  nullsub_102(auStack32);
  return auStack32[2];
}

u32 ReturnIntFromChar(u8 r0)
{
    return r0;
}

u32 ReturnIntFromChar2(u8 r0)
{
    return r0;
}

// Unused
void sub_8092290(u8 *buffer, u8 *string)
{
  while( *string != '\0' ) {
    *buffer++ = ReturnIntFromChar2(*string++);
  }
  *buffer = 0; // append a 0
}

void sub_80922B4(u8 *buffer, u8 *string, s32 size)
{
    while(1)
    {
        if(size-- < 1 || *string == '\0')
        {
            break;
        }
        *buffer++ = ReturnIntFromChar2(*string++);
    }
    *buffer = 0; // append a 0
}

u32 sub_80922E4(u32 r0)
{
    return gUnknown_810983C[r0];
}

void CopyStringtoBuffer(u8 *buffer, u8 *string)
{
  while( *string != '\0' ) {
    *buffer++ = *string++;
  }
  *buffer = 0; // append a 0
}

void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size)
{ 
  while( 1 ) {
    if (size-- < 1) {
        break;
    }
    if (*string == '\0') {
        *buffer = 0; // append a 0 and break
        break;
    }
    // NOTE: *buffer++ = *string++ cases register flip
    *buffer = *string;
    buffer++;
    string++;
  }
}

const char *GetUnformattedTypeString(u8 type)
{
    return gUnformattedTypeStrings[type];
}

const char * GetFormattedTypeString(u8 type)
{
    return gFormattedTypeStrings[type];
}

u8 sub_8092354(u8 index)
{
    return gUnknown_810AC7C[index];
}

u8 sub_8092364(u8 index)
{
    return gUnknown_810AC6A[index];
}

void sub_8092374(char *buffer, u8 index)
{
    strncpy(buffer, gAbilityNames[index], 0x50);
}

u8 *GetAbilityDescription(u8 index)
{
    return AbilityDescriptions[index];
}

