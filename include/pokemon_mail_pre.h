#ifndef POKEMON_MAIL_PRE_H
#define POKEMON_MAIL_PRE_H

struct PokemonPair
{
    s16 speciesA;
    s16 speciesB;
};

struct PokemonItem
{
    s16 species;
    u8 itemId;
};

extern const struct PokemonPair gUnknown_80E8168[6];
extern const struct PokemonItem gUnknown_80E8180[21];
extern const struct PokemonItem gUnknown_80E81D4[386];

extern const s16 gUnknown_80E80E0[35];
extern const s16 gUnknown_80E8126[33];
extern const u8 gMankeyMission[];
extern const u8 gSmeargleMission[];
extern const u8 gMedichamMission[];
extern const u8 gUnknown_80E8830[];
extern const u8 gUnknown_80E8848[];
extern const u8 gUnknown_80E885C[];
extern const u8 gUnknown_80E886C[];
extern const u8 gUnknown_80E8884[];
extern const u8 gUnknown_80E888C[];
extern const u8 gMankeyMissionDescription[];
extern const u8 gSmeargleMissionDescription[];
extern const u8 gMedichamMissionDescription[];
extern const u8 gUnknown_80E8968[];
extern const u8 gUnknown_80E89B0[];
extern const u8 gUnknown_80E89FC[];
extern const u8 gUnknown_80E8A40[];
extern const u8 gUnknown_80E8A7C[];
extern const u8 gUnknown_80E8AC8[];
extern const u8 gUnknown_80E8AD0[];
extern const u8 gUnknown_80E8AE0[];
extern const u8 gUnknown_80E8AEC[];
extern const u8 gUnknown_80E8AFC[];
extern const u8 gUnknown_80E8B10[];
extern const u8 gUnknown_80E8B20[];
extern const u8 gUnknown_80E8B2C[];
extern const u8 gUnknown_80E8B40[];
extern const u8 gSpecialMissionText[];
extern const u8 gPlaceText[];
extern const u8 gDifficultyText[];
extern const u8 gRewardText[];
extern const u8 gUnknown_80E8B7C[];

#endif // POKEMON_MAIL_PRE_H
