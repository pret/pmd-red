#include "global.h"
#include "globaldata.h"
#include "rescue_team_info.h"
#include "data_serializer.h"
#include "text_util.h"
#include "event_flag.h"
#include "strings.h"

EWRAM_INIT RescueTeamData *gRescueTeamInfoRef = { NULL };
EWRAM_DATA RescueTeamData gRescueTeamInfo = { 0 };

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

RescueTeamData *GetRescueTeamInfo(void)
{
    return &gRescueTeamInfo;
}

void InitializeRescueTeamInfo(void)
{
    BoundedCopyStringtoBuffer(gRescueTeamInfoRef->teamName, _("Pokémon"), TEAM_NAME_LENGTH);
    gRescueTeamInfoRef->teamRankPts = 0;
    gRescueTeamInfoRef->isTeamRenamed = FALSE;
}

void CopyTeamNameToBuffer(u8 *buffer)
{
    s32 i;

    for (i = 0; i < TEAM_NAME_LENGTH; i++) {
        *buffer++ = gRescueTeamInfoRef->teamName[i];
    }
}

void StrncpyTeamName(u8 *buffer)
{
    StrncpyCustom(buffer, gRescueTeamInfoRef->teamName, TEAM_NAME_LENGTH);
}

void SetRescueTeamName(u8 *buffer)
{
    s32 i;

    for (i = 0; i < TEAM_NAME_LENGTH; i++) {
        gRescueTeamInfoRef->teamName[i] = *buffer++;
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
    if (teamRank == LUCARIO_RANK)
        return 0;

    return (sRescueRankMaxPoints[teamRank] - gRescueTeamInfoRef->teamRankPts);
}

UNUSED static void SetTeamRankPoints(s32 newPts)
{
    gRescueTeamInfoRef->teamRankPts = newPts;
}

void AddToTeamRankPts(s32 newPts)
{
    gRescueTeamInfoRef->teamRankPts += newPts;

    if (gRescueTeamInfoRef->teamRankPts > 99999999)
        gRescueTeamInfoRef->teamRankPts = 99999999;
}

u8 GetRescueTeamRank(void)
{
    s32 rank;

    for (rank = NORMAL_RANK; rank < MAX_TEAM_RANKS; rank++){
        if (gRescueTeamInfoRef->teamRankPts < sRescueRankMaxPoints[rank])
            return rank;
    }

    return LUCARIO_RANK;
}

const u8 *GetTeamRankString(u32 index)
{
    u8 index_u8 = (u8)index;
    return gRescueTeamRanks[index_u8];
}

UNUSED static bool8 GetIsTeamRenamed(void)
{
    return gRescueTeamInfoRef->isTeamRenamed;
}

u32 SaveRescueTeamInfo(u8 *buffer, u32 bufLen)
{
    DataSerializer w;
    u8 neg1;
    u8 zero;
    u8 *ptr;

    neg1 = -1;
    zero = 0;

    InitBitWriter(&w, buffer, bufLen);

    WriteBits(&w, gRescueTeamInfoRef->teamName, (TEAM_NAME_LENGTH + 1) * 8);
    WriteBits(&w, &gRescueTeamInfoRef->teamRankPts, sizeof(s32) * 8);

    gRescueTeamInfoRef->isTeamRenamed = CheckQuest(QUEST_SET_TEAM_NAME);
    if (gRescueTeamInfoRef->isTeamRenamed)
        ptr = &neg1;
    else
        ptr = &zero;
    WriteBits(&w, ptr, 1);

    FinishBitSerializer(&w);
    return w.count;
}

u32 ReadRescueTeamInfo(u8 *buffer, u32 bufLen)
{
    DataSerializer r;
    u8 tempBuf[4];

    InitBitReader(&r, buffer, bufLen);

    ReadBits(&r, gRescueTeamInfoRef->teamName, (TEAM_NAME_LENGTH + 1) * 8);
    ReadBits(&r, &gRescueTeamInfoRef->teamRankPts, sizeof(s32) * 8);

    ReadBits(&r, tempBuf, 1);
    gRescueTeamInfoRef->isTeamRenamed = tempBuf[0] & 1;

    FinishBitSerializer(&r);
    return r.count;
}
