#include "global.h"
#include "globaldata.h"
#include "rescue_team_info.h"
#include "data_serializer.h"
#include "text_util.h"
#include "event_flag.h"
#include "strings.h"

EWRAM_INIT struct RescueTeamData *gRescueTeamInfoRef = {NULL};
EWRAM_DATA struct RescueTeamData gRescueTeamInfo = {0};

static const s32 sRescueRankMaxPoints[MAX_TEAM_RANKS] = {
    [NORMAL_RANK] = 50,
    [BRONZE_RANK] = 500,
    [SILVER_RANK] = 1500,
    [GOLD_RANK] = 3000,
    [PLATINUM_RANK] = 7500,
    [DIAMOND_RANK] = 15000,
    [LUCARIO_RANK] = 100000000,
};

void LoadRescueTeamInfo(void)
{
    gRescueTeamInfoRef = &gRescueTeamInfo;
}

struct RescueTeamData *GetRescueTeamInfo(void)
{
    return &gRescueTeamInfo;
}

void InitializeRescueTeamInfo(void)
{
    BoundedCopyStringtoBuffer(gRescueTeamInfoRef->teamName, _("Pokémon"), TEAM_NAME_LENGTH);
    gRescueTeamInfoRef->teamRankPts = 0;
    gRescueTeamInfoRef->isTeamRenamed = FALSE;
}

void sub_80920B8(u8 *buffer)
{
    s32 counter;
    for (counter = 0; counter < TEAM_NAME_LENGTH; counter++) {
        *buffer++ = gRescueTeamInfoRef->teamName[counter];
    }
}

void sub_80920D8(u8 *buffer)
{
    StrncpyCustom(buffer, gRescueTeamInfoRef->teamName, TEAM_NAME_LENGTH);
}

void SetRescueTeamName(u8 *buffer)
{
    s32 counter;
    for (counter = 0; counter < TEAM_NAME_LENGTH; counter++) {
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
      return (sRescueRankMaxPoints[teamRank] - gRescueTeamInfoRef->teamRankPts);
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
    if (gRescueTeamInfoRef->teamRankPts < sRescueRankMaxPoints[rank]) {
      return rank;
    }
  }
  return LUCARIO_RANK;
}

const u8 *GetTeamRankString(u32 index)
{
    u8 index_u8 = (u8)index;
    return gRescueTeamRanks[index_u8];
}

// Unused
bool8 GetIsTeamRenamed(void)
{
    return gRescueTeamInfoRef->isTeamRenamed;
}

u32 SaveRescueTeamInfo(u8 *param_1, u32 size)
{
    DataSerializer auStack36;
    u8 neg1;
    u8 zero;
    u8 *puVar2;

    neg1 = -1;
    zero = 0;

    InitBitWriter(&auStack36, param_1, size);
    WriteBits(&auStack36, gRescueTeamInfoRef->teamName, 0x58);
    WriteBits(&auStack36, (u8 *)&gRescueTeamInfoRef->teamRankPts, 0x20);
    gRescueTeamInfoRef->isTeamRenamed = CheckQuest(QUEST_SET_TEAM_NAME);

    if (gRescueTeamInfoRef->isTeamRenamed)
    {
        puVar2 = &neg1;
    }
    else
    {
        puVar2 = &zero;
    }
    WriteBits(&auStack36,puVar2,1);
    FinishBitSerializer(&auStack36);
    return auStack36.count;
}

u32 ReadRescueTeamInfo(u8 *param_1, u32 size)
{
  DataSerializer auStack32;
  u8 byteArray[4];

  InitBitReader(&auStack32, param_1, size);
  ReadBits(&auStack32, gRescueTeamInfoRef->teamName, 0x58);
  ReadBits(&auStack32, &gRescueTeamInfoRef->teamRankPts, 0x20);
  ReadBits(&auStack32, byteArray, 1);
  gRescueTeamInfoRef->isTeamRenamed = byteArray[0] & 1;
  FinishBitSerializer(&auStack32);
  return auStack32.count;
}
