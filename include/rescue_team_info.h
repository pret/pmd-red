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

struct RescueTeamData
{
    u8 teamName[TEAM_NAME_LENGTH];
    s32 teamRankPts;
    bool8 isTeamRenamed;
};

extern struct RescueTeamData *gRescueTeamInfoRef;

void LoadRescueTeamInfo(void);
struct RescueTeamData *GetRescueTeamInfo(void);
void InitializeRescueTeamInfo(void);
void sub_80920B8(u8 *buffer);
void sub_80920D8(u8 *buffer);
void SetRescueTeamName(u8 *buffer);
s32 GetTeamRankPts(void);
s32 GetPtsToNextRank(void);
void SetTeamRankPoints(s32 newPts);
void AddToTeamRankPts(s32 newPts);
u8 GetRescueTeamRank(void);
const u8 *GetTeamRankString(u32 index);
u8 GetIsTeamRenamed(void);
u32 SaveRescueTeamInfo(u8 *param_1,u32 param_2);
u32 ReadRescueTeamInfo(u8 *param_1, u32 param_2);

#endif // GUARD_RESCUE_TEAM_INFO_H
