#ifndef RESCUE_TEAM_INFO_H
#define RESCUE_TEAM_INFO_H

#define TEAM_NAME_LENGTH 10

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
    u8 unk10;
};

void LoadRescueTeamInfo(void);
struct RescueTeamData *GetRescueTeamInfo(void);
void InitializeResuceTeamInfo(void);
void sub_80920B8(u8 *buffer);
void sub_80920D8(u8 *buffer);
void SetRescueTeamName(u8 *buffer);
s32 GetTeamRankPts(void);
s32 GetPtsToNextRank(void);
void SetTeamRankPoints(s32 newPts);
void AddToTeamRankPts(s32 newPts);
u8 GetRescueTeamRank(void);
const char *GetTeamRankString(u8 index);
u8 sub_80921B8(void);
u32 SaveRescueTeamInfo(u8 *param_1,u32 param_2);
u32 ReadRescueTeamInfo(u8 *param_1, u32 param_2);

#endif // RESCUE_TEAM_INFO_H
