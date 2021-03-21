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

enum TeamRanks
{
    NORMAL_RANK,
    BRONZE_RANK,
    SILVER_RANK,
    GOLD_RANK,
    PLATINUM_RANK,
    DIAMOND_RANK,
    LUCARIO_RANK
};

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

struct RescueTeamData
{
    u8 teamName[0xA]; // some string of sorts
    s32 teamRankPts;
    u8 unk10;
};
extern struct RescueTeamData *gRescueTeamInfoRef;
extern struct RescueTeamData gRescueTeamInfo;

extern void sub_809485C(u32 *r0, u8 *r1, u32 r2);
extern void sub_809486C(u32 *r0, u8 *r1, u32 r2);
extern void sub_809488C(u32 *r0, u8 *r1, u32 r2);
extern void sub_8094924(u32 *r0, u8 *r1, u32);
extern void nullsub_102(u32 *r0);
extern u8 sub_80023E4(u32);

extern const char *gRescueTeamRanks[];
extern s32 gRescueRankMaxPoints[7];
extern u8 gTeamNamePlaceholder[0x8]; // Pokemon
extern u8 gUnknown_810A35B[0x10];

// Forward declaration
void sub_80922B4(u8 *buffer, u8 *string, s32 size);
void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size);
u8 GetRescueTeamRank(void);

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

void LoadRescueTeamInfo(void)
{
    gRescueTeamInfoRef = &gRescueTeamInfo;
}

struct RescueTeamData *GetRescueTeamInfo(void)
{
    return &gRescueTeamInfo;
}

void InitializeResuceTeamInfo(void)
{
    BoundedCopyStringtoBuffer(gRescueTeamInfoRef->teamName, gTeamNamePlaceholder, 0xA);
    gRescueTeamInfoRef->teamRankPts = 0;
    gRescueTeamInfoRef->unk10 = 0;
}

void sub_80920B8(u8 *buffer)
{
    s32 counter;
    for(counter = 0; counter < 0xA; counter++)
    {
        *buffer++ = gRescueTeamInfoRef->teamName[counter];
    }
}

void sub_80920D8(u8 *buffer)
{
    sub_80922B4(buffer, gRescueTeamInfoRef->teamName, 0xA);
}

void SetRescueTeamName(u8 *buffer)
{
    s32 counter;
    for(counter = 0; counter < 0xA; counter++)
    {
        gRescueTeamInfoRef->teamName[counter] = *buffer++;
    }
}

s32 GetTeamRankPts(void)
{
   return gRescueTeamInfoRef->teamRankPts;
}

s32 GetPtsToNextRank(void)
{
  u8 teamRank;

  teamRank = GetRescueTeamRank();
  if (teamRank == LUCARIO_RANK) {
      return 0;
  }
  else
  {
      return (gRescueRankMaxPoints[teamRank] - gRescueTeamInfoRef->teamRankPts);
  }
}

// Unused
void SetTeamRankPoints(s32 newPts)
{
    gRescueTeamInfoRef->teamRankPts = newPts;
}

void AddToTeamRankPts(s32 param_1)
{
  gRescueTeamInfoRef->teamRankPts += param_1;
  if (gRescueTeamInfoRef->teamRankPts > 99999999) {
   gRescueTeamInfoRef->teamRankPts = 99999999;
  }
}

u8 GetRescueTeamRank(void)
{
  s32 rank;

  for(rank = NORMAL_RANK; rank < LUCARIO_RANK + 1; rank++){
    if (gRescueTeamInfoRef->teamRankPts < gRescueRankMaxPoints[rank]) {
      return rank;
    }
  }
  return LUCARIO_RANK;
}

const char *GetTeamRankString(u8 index)
{
    return gRescueTeamRanks[index];
}

// Unused
u8 sub_80921B8(void)
{
    return gRescueTeamInfoRef->unk10;
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
    sub_809488C(auStack36, gRescueTeamInfoRef->teamName, 0x58);
    sub_809488C(auStack36, (u8 *)&gRescueTeamInfoRef->teamRankPts, 0x20);
    gRescueTeamInfoRef->unk10 = sub_80023E4(0);

    if (gRescueTeamInfoRef->unk10 != 0)
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
  sub_8094924(auStack32, gRescueTeamInfoRef->teamName, 0x58);
  sub_8094924(auStack32, (u8 *)&gRescueTeamInfoRef->teamRankPts, 0x20);
  sub_8094924(auStack32, byteArray, 1);
  gRescueTeamInfoRef->unk10 = byteArray[0] & 1;
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

