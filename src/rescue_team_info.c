#include "global.h"
#include "rescue_team_info.h"
#include "code_8092334.h"

extern struct RescueTeamData *gRescueTeamInfoRef;
EWRAM_DATA struct RescueTeamData gRescueTeamInfo;

extern u8 sub_80023E4(u32);
extern void sub_80922B4(u8 *buffer, u8 *string, s32 size);
extern void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size);

extern const char *gRescueTeamRanks[];
extern s32 gRescueRankMaxPoints[7];
extern u8 gTeamNamePlaceholder[0x8]; // Pokemon
extern u8 gUnknown_810A35B[0x10];

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
    BoundedCopyStringtoBuffer(gRescueTeamInfoRef->teamName, gTeamNamePlaceholder, TEAM_NAME_LENGTH);
    gRescueTeamInfoRef->teamRankPts = 0;
    gRescueTeamInfoRef->unk10 = 0;
}

void sub_80920B8(u8 *buffer)
{
    s32 counter;
    for(counter = 0; counter < TEAM_NAME_LENGTH; counter++)
    {
        *buffer++ = gRescueTeamInfoRef->teamName[counter];
    }
}

void sub_80920D8(u8 *buffer)
{
    sub_80922B4(buffer, gRescueTeamInfoRef->teamName, TEAM_NAME_LENGTH);
}

void SetRescueTeamName(u8 *buffer)
{
    s32 counter;
    for(counter = 0; counter < TEAM_NAME_LENGTH; counter++)
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

void AddToTeamRankPts(s32 newPts)
{
  gRescueTeamInfoRef->teamRankPts += newPts;
  if (gRescueTeamInfoRef->teamRankPts > 99999999) {
   gRescueTeamInfoRef->teamRankPts = 99999999;
  }
}

u8 GetRescueTeamRank(void)
{
  s32 rank;

  for(rank = NORMAL_RANK; rank < MAX_TEAM_RANKS; rank++){
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

u32 SaveRescueTeamInfo(u8 *param_1, u32 size)

{
    struct unkStruct_8094924 auStack36;
    u8 neg1;
    u8 zero;
    u8 *puVar2;

    neg1 = -1;
    zero = 0;

    sub_809486C(&auStack36, param_1, size);
    sub_809488C(&auStack36, gRescueTeamInfoRef->teamName, 0x58);
    sub_809488C(&auStack36, (u8 *)&gRescueTeamInfoRef->teamRankPts, 0x20);
    gRescueTeamInfoRef->unk10 = sub_80023E4(0);

    if (gRescueTeamInfoRef->unk10 != 0)
    {
        puVar2 = &neg1;
    }
    else
    {
        puVar2 = &zero;
    }
    sub_809488C(&auStack36,puVar2,1);
    nullsub_102(&auStack36);
    return auStack36.unk8;
}

u32 ReadRescueTeamInfo(u8 *param_1, u32 size)
{
  struct unkStruct_8094924 auStack32;
  u8 byteArray[4];

  sub_809485C(&auStack32, param_1, size);
  sub_8094924(&auStack32, gRescueTeamInfoRef->teamName, 0x58);
  sub_8094924(&auStack32, (u8 *)&gRescueTeamInfoRef->teamRankPts, 0x20);
  sub_8094924(&auStack32, byteArray, 1);
  gRescueTeamInfoRef->unk10 = byteArray[0] & 1;
  nullsub_102(&auStack32);
  return auStack32.unk8;
}
