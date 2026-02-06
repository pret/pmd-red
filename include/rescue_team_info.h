#ifndef GUARD_RESCUE_TEAM_INFO_H
#define GUARD_RESCUE_TEAM_INFO_H

enum TeamRanks
{
    NORMAL_RANK,
    BRONZE_RANK,
    SILVER_RANK,
    GOLD_RANK,
    PLATINUM_RANK,
    DIAMOND_RANK,
    LUCARIO_RANK,
    MAX_TEAM_RANKS
};

typedef struct RescueTeamData
{
    u8 teamName[TEAM_NAME_LENGTH];
    s32 teamRankPts;
    bool8 isTeamRenamed;
} RescueTeamData;

extern RescueTeamData *gRescueTeamInfoRef;

void LoadRescueTeamInfo(void);
RescueTeamData *GetRescueTeamInfo(void);
void InitializeRescueTeamInfo(void);
void CopyTeamNameToBuffer(u8 *buffer);
void StrncpyTeamName(u8 *buffer);
void SetRescueTeamName(u8 *buffer);
s32 GetTeamRankPts(void);
s32 GetPtsToNextRank(void);
void AddToTeamRankPts(s32 newPts);
u8 GetRescueTeamRank(void);
const u8 *GetTeamRankString(u32 index);
u32 SaveRescueTeamInfo(u8 *buffer, u32 bufLen);
u32 ReadRescueTeamInfo(u8 *buffer, u32 bufLen);

#endif // GUARD_RESCUE_TEAM_INFO_H
