#include "global.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_8045A00.h"
#include "code_80861A8.h"
#include "code_806CD90.h"
#include "code_80869E4.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "position_util.h"
#include "exclusive_pokemon.h"
#include "trap.h"
#include "math.h"
#include "dungeon_config.h"

extern u32 gDungeonBrightness;

extern const struct DungeonDialogueStruct GroudonPreFightDialogue_10;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_11;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_12;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_13;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_14;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_1;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_2;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_3;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_4;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_5;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_6;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_7;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_8;
extern const struct DungeonDialogueStruct GroudonPreFightDialogue_9;
extern const struct DungeonDialogueStruct HoOhReFightDialogue_1;
extern const struct DungeonDialogueStruct HoOhReFightDialogue_2;
extern const struct DungeonDialogueStruct HoOhReFightDialogue_3;
extern const struct DungeonDialogueStruct HoOhReFightDialogue_4;
extern const struct DungeonDialogueStruct HoOhReFightDialogue_5;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_10;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_11;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_12;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_13;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_14;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_15;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_1;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_2;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_3;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_4;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_5;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_6;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_7;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_8;
extern const struct DungeonDialogueStruct MagmaCavernMidDialogue_9;
extern const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gArticunoPostStoryPreFightDialogue_5;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_10;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_11;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_12;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_1;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_2;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_3;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_4;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_5;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_6;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_7;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_8;
extern const struct DungeonDialogueStruct gArticunoPreFightDialogue_9;
extern const struct DungeonDialogueStruct gArticunoReFightDialogue_1;
extern const struct DungeonDialogueStruct gArticunoReFightDialogue_2;
extern const struct DungeonDialogueStruct gArticunoReFightDialogue_3;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_10;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_1;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_2;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_3;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_4;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_5;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_6;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_7;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_8;
extern const struct DungeonDialogueStruct gCelebiJoinDialogue_9;
extern const struct DungeonDialogueStruct gDeoxysPreFightDialogue_1;
extern const struct DungeonDialogueStruct gDeoxysPreFightDialogue_2;
extern const struct DungeonDialogueStruct gDeoxysPreFightDialogue_3;
extern const struct DungeonDialogueStruct gDeoxysPreFightDialogue_4;
extern const struct DungeonDialogueStruct gDeoxysPreFightDialogue_5;
extern const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gEnteiPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gEnteiPreFightDialogue_1;
extern const struct DungeonDialogueStruct gEnteiPreFightDialogue_2;
extern const struct DungeonDialogueStruct gEnteiPreFightDialogue_3;
extern const struct DungeonDialogueStruct gEnteiReFightDialogue_1;
extern const struct DungeonDialogueStruct gEnteiReFightDialogue_2;
extern const struct DungeonDialogueStruct gEnteiReFightDialogue_3;
extern const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gGroudonPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gGroudonReFightDialogue_1;
extern const struct DungeonDialogueStruct gGroudonReFightDialogue_2;
extern const struct DungeonDialogueStruct gGroudonReFightDialogue_3;
extern const struct DungeonDialogueStruct gGroudonReFightDialogue_4;
extern const struct DungeonDialogueStruct gHoOhPreFightDialogue_1;
extern const struct DungeonDialogueStruct gHoOhPreFightDialogue_2;
extern const struct DungeonDialogueStruct gHoOhPreFightDialogue_3;
extern const struct DungeonDialogueStruct gHoOhPreFightDialogue_4;
extern const struct DungeonDialogueStruct gHoOhPreFightDialogue_5;
extern const struct DungeonDialogueStruct gHoOhPreFightDialogue_6;
extern const struct DungeonDialogueStruct gJirachiPreFightDialogue_1;
extern const struct DungeonDialogueStruct gJirachiPreFightDialogue_2;
extern const struct DungeonDialogueStruct gJirachiPreFightDialogue_3;
extern const struct DungeonDialogueStruct gJirachiPreFightDialogue_4;
extern const struct DungeonDialogueStruct gJirachiReFightDialogue_1;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_1;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_2;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_3;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_4;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_5;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_6;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_7;
extern const struct DungeonDialogueStruct gKyogrePreFightDialogue_8;
extern const struct DungeonDialogueStruct gLatiosPreFightDialogue_1;
extern const struct DungeonDialogueStruct gLatiosPreFightDialogue_2;
extern const struct DungeonDialogueStruct gLatiosPreFightDialogue_3;
extern const struct DungeonDialogueStruct gLatiosReFightDialogue_1;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_1;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_2;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_3;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_4;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_5;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_6;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_7;
extern const struct DungeonDialogueStruct gLugiaPreFightDialogue_8;
extern const struct DungeonDialogueStruct gMedichamRescueDialogue_1;
extern const struct DungeonDialogueStruct gMedichamRescueDialogue_2;
extern const struct DungeonDialogueStruct gMedichamRescueDialogue_3;
extern const struct DungeonDialogueStruct gMedichamRescueDialogue_4;
extern const struct DungeonDialogueStruct gMewtwoPreFightDialogue_1;
extern const struct DungeonDialogueStruct gMewtwoPreFightDialogue_2;
extern const struct DungeonDialogueStruct gMewtwoPreFightDialogue_3;
extern const struct DungeonDialogueStruct gMewtwoPreFightDialogue_4;
extern const struct DungeonDialogueStruct gMewtwoPreFightDialogue_5;
extern const struct DungeonDialogueStruct gMewtwoReFightDialogue_1;
extern const struct DungeonDialogueStruct gMewtwoReFightDialogue_2;
extern const struct DungeonDialogueStruct gMewtwoReFightDialogue_3;
extern const struct DungeonDialogueStruct gMewtwoReFightDialogue_4;
extern const struct DungeonDialogueStruct gMewtwoReFightDialogue_5;
extern const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gMoltresPostStoryPreFightDialogue_5;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_10;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_11;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_12;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_1;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_2;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_3;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_4;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_5;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_6;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_7;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_8;
extern const struct DungeonDialogueStruct gMoltresPreFightDialogue_9;
extern const struct DungeonDialogueStruct gMoltresReFightDialogue_1;
extern const struct DungeonDialogueStruct gMoltresReFightDialogue_2;
extern const struct DungeonDialogueStruct gMoltresReFightDialogue_3;
extern const struct DungeonDialogueStruct gMoltresReFightDialogue_4;
extern const struct DungeonDialogueStruct gMoltresReFightDialogue_5;
extern const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gRaikouPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gRaikouPreFightDialogue_1;
extern const struct DungeonDialogueStruct gRaikouPreFightDialogue_2;
extern const struct DungeonDialogueStruct gRaikouPreFightDialogue_3;
extern const struct DungeonDialogueStruct gRaikouPreFightDialogue_4;
extern const struct DungeonDialogueStruct gRaikouPreFightDialogue_5;
extern const struct DungeonDialogueStruct gRaikouPreFightDialogue_6;
extern const struct DungeonDialogueStruct gRaikouReFightDialogue_1;
extern const struct DungeonDialogueStruct gRaikouReFightDialogue_2;
extern const struct DungeonDialogueStruct gRaikouReFightDialogue_3;
extern const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_5;
extern const struct DungeonDialogueStruct gRayquazaPostStoryPreFightDialogue_6;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_10;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_11;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_1;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_2;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_3;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_4;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_5;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_6;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_7;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_7;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_8;
extern const struct DungeonDialogueStruct gRayquazaPreFightDialogue_9;
extern const struct DungeonDialogueStruct gRayquazaReFightDialogue_1;
extern const struct DungeonDialogueStruct gRayquazaReFightDialogue_2;
extern const struct DungeonDialogueStruct gRayquazaReFightDialogue_3;
extern const struct DungeonDialogueStruct gRayquazaReFightDialogue_4;
extern const struct DungeonDialogueStruct gRegicePostFightDialogue_1;
extern const struct DungeonDialogueStruct gRegicePostFightDialogue_2;
extern const struct DungeonDialogueStruct gRegicePreFightDialogue_1;
extern const struct DungeonDialogueStruct gRegirockPostFightDialogue_1;
extern const struct DungeonDialogueStruct gRegirockPostFightDialogue_2;
extern const struct DungeonDialogueStruct gRegirockPreFightDialogue_1;
extern const struct DungeonDialogueStruct gRegisteelPostFightDialogue_1;
extern const struct DungeonDialogueStruct gRegisteelPostFightDialogue_2;
extern const struct DungeonDialogueStruct gRegisteelPreFightDialogue_1;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_5;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_6;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_7;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_8;
extern const struct DungeonDialogueStruct gSkarmoryPreFightDialogue_9;
extern const struct DungeonDialogueStruct gSkarmoryReFightDialogue_1;
extern const struct DungeonDialogueStruct gSkarmoryReFightDialogue_2;
extern const struct DungeonDialogueStruct gSkarmoryReFightDialogue_3;
extern const struct DungeonDialogueStruct gSmeargleRescueDialogue_1;
extern const struct DungeonDialogueStruct gSmeargleRescueDialogue_2;
extern const struct DungeonDialogueStruct gSmeargleRescueDialogue_3;
extern const struct DungeonDialogueStruct gSmeargleRescueDialogue_4;
extern const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gSuicunePostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_1;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_2;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_3;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_4;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_5;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_6;
extern const struct DungeonDialogueStruct gSuicunePreFightDialogue_7;
extern const struct DungeonDialogueStruct gSuicuneReFightDialogue_1;
extern const struct DungeonDialogueStruct gSuicuneReFightDialogue_2;
extern const struct DungeonDialogueStruct gSuicuneReFightDialogue_3;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_1;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_2;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_3;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_4;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_5;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_6;
extern const struct DungeonDialogueStruct gTeamMeaniesPreFightDialogue_7;
extern const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_1;
extern const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_2;
extern const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_3;
extern const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_4;
extern const struct DungeonDialogueStruct gTeamMeaniesReFightDialogue_5;
extern const struct DungeonDialogueStruct gUnknown_8100D3C;
extern const struct DungeonDialogueStruct gUnknown_8100D3C;
extern const struct DungeonDialogueStruct gUnknown_8101440;
extern const struct DungeonDialogueStruct gUnknown_81014B0;
extern const struct DungeonDialogueStruct gUnknown_8101504;
extern const struct DungeonDialogueStruct gUnknown_81015A0;
extern const struct DungeonDialogueStruct gUnknown_81015D4;
extern const struct DungeonDialogueStruct gUnknown_81015E8;
extern const struct DungeonDialogueStruct gUnknown_8101624;
extern const struct DungeonDialogueStruct gUnknown_810165C;
extern const struct DungeonDialogueStruct gUnknown_8101750;
extern const struct DungeonDialogueStruct gUnknown_810178C;
extern const struct DungeonDialogueStruct gUnknown_81017B4;
extern const struct DungeonDialogueStruct gUnknown_8102A9C;
extern const struct DungeonDialogueStruct gUnknown_8102B10;
extern const struct DungeonDialogueStruct gUnknown_8103488;
extern const struct DungeonDialogueStruct gUnknown_8103BD8;
extern const struct DungeonDialogueStruct gUnknown_8103C00;
extern const struct DungeonDialogueStruct gUnknown_8103C3C;
extern const struct DungeonDialogueStruct gUnknown_8103C74;
extern const struct DungeonDialogueStruct gUnknown_8103CC4;
extern const struct DungeonDialogueStruct gUnknown_8103D0C;
extern const struct DungeonDialogueStruct gUnknown_8103D50;
extern const struct DungeonDialogueStruct gUnknown_8103D8C;
extern const struct DungeonDialogueStruct gUnknown_8103D98;
extern const struct DungeonDialogueStruct gUnknown_8103DD8;
extern const struct DungeonDialogueStruct gUnknown_8103E28;
extern const struct DungeonDialogueStruct gUnknown_8103E34;
extern const struct DungeonDialogueStruct gUnknown_8104FC8;
extern const struct DungeonDialogueStruct gUnknown_810554C;
extern const struct DungeonDialogueStruct gUnknown_8105558;
extern const struct DungeonDialogueStruct gUnknown_81055F4;
extern const struct DungeonDialogueStruct gUnknown_8105668;
extern const struct DungeonDialogueStruct gUnknown_8105674;
extern const struct DungeonDialogueStruct gUnknown_81056B8;
extern const struct DungeonDialogueStruct gUnknown_81056DC;
extern const struct DungeonDialogueStruct gUnknown_810581C;
extern const struct DungeonDialogueStruct gUnknown_81058A8;
extern const struct DungeonDialogueStruct gUnknown_81058C4;
extern const struct DungeonDialogueStruct gUnknown_81058E0;
extern const struct DungeonDialogueStruct gUnknown_810593C;
extern const struct DungeonDialogueStruct gUnknown_8105974;
extern const struct DungeonDialogueStruct gUnknown_8105A08;
extern const struct DungeonDialogueStruct gUnknown_8105AD4;
extern const struct DungeonDialogueStruct gUnknown_8105B20;
extern const struct DungeonDialogueStruct gUnknown_8105B68;
extern const struct DungeonDialogueStruct gUnknown_8105BA8;
extern const struct DungeonDialogueStruct gUnknown_8105BF4;
extern const struct DungeonDialogueStruct gUnknown_8105D2C;
extern const struct DungeonDialogueStruct gUnknown_8105D80;
extern const struct DungeonDialogueStruct gUnknown_8105D9C;
extern const struct DungeonDialogueStruct gUnknown_8106720;
extern const struct DungeonDialogueStruct gUnknown_810697C;
extern const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_1;
extern const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_2;
extern const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_3;
extern const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_4;
extern const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_5;
extern const struct DungeonDialogueStruct gZapdosPostStoryPreFightDialogue_6;
extern const struct DungeonDialogueStruct gZapdosReFightDialogue_1;
extern const struct DungeonDialogueStruct gZapdosReFightDialogue_2;
extern const struct DungeonDialogueStruct gZapdosReFightDialogue_3;
extern const struct DungeonDialogueStruct gZapdosReFightDialogue_4;
extern const struct MenuItem gPurityForestAllowCelebiToJoinPrompt[];
extern const struct MenuItem gPurityForestRefuseCelebiConfirmPrompt[];
extern const struct MenuItem gUnknown_810579C[];
extern const u64 gUnknown_8107544[];
extern const u8 *const gPtrPurityForestAllowCelebiToJoinText;
extern const u8 *const gPtrPurityForestRefuseCelebiConfirmText;
extern const u8 *const gUnknown_8105798;
extern const u8 gUnknown_810739C[];
extern const u8 gUnknown_81073D4[];
extern const u8 gUnknown_810740C[];
extern const u8 gUnknown_81074FC[];

struct Zapdos1
{
    s16 unk0[12];
};

struct Zapdos2
{
    s16 unk0[16];
};

extern const struct Zapdos1 gUnknown_810744C;
extern struct Zapdos2 gUnknown_8107464;

extern void sub_8068FE0(Entity *, u32, u32);
extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F878(u32, s32);
extern void BgColorCallNullsub4(void);
extern void sub_8085EB0(void);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void ShowWholeRevealedDungeonMap(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_808BBA8(Entity * );
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern u8 sub_80860A8(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void sub_80464C8(Entity *, DungeonPos *, Item *);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern u32 sub_8085EC8(u32, u32, u32, DungeonPos *, u32);
extern void sub_807EAA0(u32, u32);
extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374(void);
extern void sub_8045C28(Item *, u8 , u8 *);
extern void sub_8046860(Entity *, DungeonPos *, Item *, u32);
extern u32 sub_803D73C(u32);
extern void sub_80460F8(DungeonPos *, Item *, u8);
extern u8 sub_8044B28(void);
extern bool8 sub_8085B80(struct_8085B80 *);

void sub_8085F44(s32);
void sub_808BBA8(Entity * );
void DeoxysScreenFlash(void);
void sub_8086A54(Entity *);
void ZapdosScreenFlash(s32 numFlashes);
void ZapdosDropInEffect(Entity *);
void SetupDeoxysFightHP(Entity *r0);
void sub_808C550(void);
void sub_808C590(Entity *r0);
void SetupDeoxysFacingDirection(Entity *r0);
void sub_808C9B0(Entity *);
void sub_808C8E0(Entity *param_1);
void sub_808C360(void);
void KyogreScreenFlash(void);
void sub_808C0CC(void);
void LugiaScreenFlash(void);
void LugiaScreenFlash2(void);
void nullsub_99(void);
void JirachiWish(void);
void JirachiSpinEffect(Entity *jirachiEntity);
void JirachiWishGrantDialogue(Entity *jirachiEntity);
void JirachiDropInEffect(Entity *jirachiEntity);
u8 JirachiFriendAreaSearch(void);
void sub_808B1CC(u8 itemID);
void CreateJirachiWishWarpTile(void);
void EnteiScreenFlash(void);
void RaikouScreenFlash(void);
void sub_808A528(Entity * param_1);
void SuicuneScreenFlash(void);
void HoOhDropInEffect(Entity * param_1);
void HoOhScreenFlash(void);
void LatiosScreenFlash(void);
void SetupRegiFacingDirection(Entity *entity);
void SetupRegirockFightHP(Entity *entity);
void SetupRegiceFightHP(Entity *entity);
void SetupRegisteelFightHP(Entity *entity);
void sub_808B50C(void);
void MewtwoDropInEffect(Entity *param_1);
void MewtwoScreenFlash(void);
void sub_80898F8(Entity *entity);
void sub_8089908(Entity *entity);
void RayquazaDropInEffect(Entity *param_1);
void RayquazaScreenFlash(void);
void sub_80891F0(void);
void sub_8089294(void);
void GroudonScreenFlash2(void);
void SceneGroudonMovement(Entity * param_1);
void GroudonScreenFlash(void);
void ArticunoScreenFlash(void);
void sub_8088484(Entity *param_1);
void sub_8088574(void);
void MoltresDropInEffect(Entity * param_1);
void MoltresScreenFlash1(s32 r0, s32 r1);
void MoltresScreenFlash2(s32 r0, s32 r1);
void MoltresScreenFlash3(void);
void MoltresScreenDarken(void);
void EnableJirachiWishWarpTile(void);
void sub_808BB3C(DungeonPos *pos);
void sub_8087144();
void SkarmoryEntry(Entity *);

void sub_8086A3C(Entity *pokemon)
{
    GetEntInfo(pokemon)->unk15C = 1;
    GetEntInfo(pokemon)->unk15E = 1;
}

void sub_8086A54(Entity *pokemon)
{
    GetEntInfo(pokemon)->unk15C = 1;
    GetEntInfo(pokemon)->unk15E = 0;
}

void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex)
{
  EntityInfo *entityInfo = GetEntInfo(pokemon);

  entityInfo->bossFlag = TRUE;

  // BUG: Source of the Reviver Seed Boss Glitch
  //
  // Video to demonstration:
  // https://www.youtube.com/watch?v=rHu7EehrZ68
  entityInfo->originalHP = entityInfo->maxHPStat;
  if (newHP != 0) {
    entityInfo->maxHPStat = newHP;
    entityInfo->HP = newHP;
  }

  gDungeon->unk644.bossSongIndex = songIndex;
  SetDefaultIQSkills(&entityInfo->IQSkillMenuFlags, entityInfo->bossFlag);
  LoadIQSkills(pokemon);
}

void sub_8086AC0(void)
{
    if(!sub_8044B28())
        if(gDungeon->unk2 == 0)
            sub_8097FF8();
}

u8 sub_8086AE4(s16 _index)
{
    s32 pokeIndex = _index;

    if(gDungeon->unk644.unk18 == 0)
        return 1;
    else
        return HasRecruitedMon(pokeIndex);
}

void sub_8086B14(void)
{
  Entity * leaderEntity;
  Entity * diglettEntity;
  Entity * skarmoryEntity;

  leaderEntity = xxx_call_GetLeader();
  diglettEntity = GetEntityFromMonsterBehavior(BEHAVIOR_DIGLETT);
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(skarmoryEntity);
  GetEntInfo(diglettEntity)->unk15C = 1;
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 2);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_DIGLETT);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_SKARMORY);
}

void sub_8086B94(void)
{
  Entity * leaderEntity;
  Entity * diglettEntity;
  Entity * skarmoryEntity;

  leaderEntity = xxx_call_GetLeader();
  diglettEntity = GetEntityFromMonsterBehavior(BEHAVIOR_DIGLETT);
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY);

  sub_8068FE0(skarmoryEntity,0x21c,0);
  sub_8068FE0(diglettEntity,0x21c,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
}

// TODO: fix this function as param_2 should be u8
void sub_8086BDC(u8 param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) - 0x1000000U) >> 0x18 < 2) && (param_1 == 3)) {
    sub_8097FA8(1);
    gDungeon->unk2 = 1;
  }
}

void SkarmoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity * diglettEntity;
  Entity * skarmoryEntity;

  PixelPos pos1;
  PixelPos pos2;

  leaderEntity = xxx_call_GetLeader(); // Player
  partnerEntity = GetPartnerEntity(); // Partner
  diglettEntity = GetEntityFromMonsterBehavior(BEHAVIOR_DIGLETT); // Diglett
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY); // Skarmory

  pos1.x = diglettEntity->pixelPos.x;
  pos1.y = diglettEntity->pixelPos.y + 0x3000;

  pos2.x = skarmoryEntity->pixelPos.x;
  pos2.y = skarmoryEntity->pixelPos.y + 0x2000;

  sub_8086448();
  sub_803E708(10,0x46);
  SpriteShockEffect(partnerEntity);
  sub_803E708(0x20,0x46);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_1);
  ShiftCameraToPosition(&pos1,0x40);
  sub_803E708(0x40,0x46);
  ShiftCameraToPosition(&pos2,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_2);
  sub_803E708(10,0x46);
  GetEntInfo(diglettEntity)->unk15D = 1;
  ShiftCameraToPosition(&pos1,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_3); // Diglett: ...I...\nI'm scared.
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&pos2,0x20);
  sub_803E708(0x20,0x46);
  SkarmoryEntry(skarmoryEntity);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_4); // Skarmory: You!\nWhat do you think you're doing here?!
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_806CDD4(skarmoryEntity,0xd,DIRECTION_SOUTH);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_8);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_9);
  sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SkarmoryReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * skarmoryEntity;
  PixelPos pos;

  leaderEntity = xxx_call_GetLeader();
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY);
  pos.x = skarmoryEntity->pixelPos.x;
  pos.y = skarmoryEntity->pixelPos.y + 0x2000;
  sub_8086448();
  sub_803E708(10,0x46);
  SkarmoryEntry(skarmoryEntity);
  ShiftCameraToPosition(&pos,0x10);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_806CDD4(skarmoryEntity,0xd,DIRECTION_SOUTH);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_3);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
}

void sub_8086E40(void)
{
  SpriteLookAroundEffect(xxx_call_GetLeader());
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_8100D3C);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void SkarmoryEntry(Entity * skarmoryEntity)
{
  sub_806CDD4(skarmoryEntity,0xf,DIRECTION_SOUTH);
  sub_8086A54(skarmoryEntity);
  PlaySoundEffect(0x1f8);
  sub_803E708(0x44,0x46);
}

void sub_8086E9C(void)
{
  Entity * leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_METAPOD);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GENGAR);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[4], MONSTER_CATERPIE);
}

void sub_8086F00(void)
{
  Entity * leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_METAPOD);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GENGAR);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[4], MONSTER_CATERPIE);
}

void sub_8086F54(u8 param_1, u8 param_2)
{
    s32 index;

    if (param_2 == 4 || param_2 == 5)  {
        bool8 found = FALSE;
        for (index = 0; index < 0x10; index++) {
            struct Entity *entity = gDungeon->wildPokemon[index];
            if ((EntityIsValid(entity))) {
                struct EntityInfo *entInfo = GetEntInfo(entity);
                if (entInfo->monsterBehavior != param_1) {
                    found = TRUE;
                    return;
                }
            }
        }

        if (!found) {
            sub_8097FA8(3);
            gDungeon->unk2 = 1;
        }
    }
}

void TeamMeaniesPreFightDialogue(void)
{
    Entity *leaderEntity;

    leaderEntity = xxx_call_GetLeader();
    sub_8086448();
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_1);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_2);
    sub_803E708(10, 0x46);
    sub_8087144();
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_3);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_4);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_5);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_6);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_7);
    sub_803E708(10, 0x46);
    ShiftCameraToPosition(&leaderEntity->pixelPos, 0x10);
}

void TeamMeaniesReFightDialogue(void)
{
    Entity *leaderEntity;
    Entity *partnerEntity;

    leaderEntity = xxx_call_GetLeader();
    partnerEntity = GetPartnerEntity();
    sub_8086448();
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_1);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_2);
    sub_803E708(10, 0x46);
    sub_8087144();
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_2);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_3);
    sub_803E708(10, 0x46);
    sub_806CDD4(leaderEntity, 6, DIRECTION_NORTH);
    sub_806CDD4(partnerEntity, 6, DIRECTION_NORTH);
    sub_803E708(10, 0x46);
    sub_806CDD4(leaderEntity, 7, DIRECTION_NORTH);
    sub_806CDD4(partnerEntity, 7, DIRECTION_NORTH);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_4);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_5);
    sub_803E708(10, 0x46);
    ShiftCameraToPosition(&leaderEntity->pixelPos, 0x10);
}

void sub_8087130(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8101440);
}

void sub_8087144(void)
{
    Entity *iVar2;
    Entity *iVar3;
    Entity *iVar4;
    s16 auStack_10c[28];
    s16 puStack_60[28];
    s16 puStack_5c[28];
    s16 *puStack_64[3];
    Entity *pEStack_58[3];
    struct_8085B80 auStack_4c[3];

    iVar2 = GetEntityFromMonsterBehavior(BEHAVIOR_5);
    iVar3 = GetEntityFromMonsterBehavior(BEHAVIOR_6);
    iVar4 = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    memcpy(auStack_10c,gUnknown_810739C, 0x38);
    memcpy(puStack_60, gUnknown_81073D4, 0x38);
    memcpy(puStack_5c, gUnknown_810740C, 0x38);
    puStack_64[0] = auStack_10c;
    puStack_64[1] = puStack_60;
    puStack_64[2] = puStack_5c;
    pEStack_58[0] = iVar2;
    pEStack_58[1] = iVar3;
    pEStack_58[2] = iVar4;
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    sub_8086A54(iVar2);
    sub_8086A54(iVar3);
    sub_8086A54(iVar4);
    sub_8085B4C(auStack_4c,puStack_64,pEStack_58,3);
    GetEntInfo(iVar2)->unk15F = 1;
    GetEntInfo(iVar3)->unk15F = 1;
    GetEntInfo(iVar4)->unk15F = 1;
    while( TRUE ) {
        if (!sub_8085B80(auStack_4c)) break;
        sub_803E46C(0x46);
    }
    GetEntInfo(iVar2)->unk15F = 0;
    GetEntInfo(iVar3)->unk15F = 0;
    GetEntInfo(iVar4)->unk15F = 0;
}

void sub_8087230(void)
{
    Entity *leaderEntity;
    Entity *zapdosEntity;

    leaderEntity = xxx_call_GetLeader();
    zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_8085374();
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(zapdosEntity, DIRECTION_SOUTH);
    sub_8086A3C(zapdosEntity);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SHIFTRY);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ZAPDOS);
}

void sub_808729C(void)
{
  Entity *leaderEntity;
  Entity *zapdosEntity;

  leaderEntity = xxx_call_GetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(0x91) != 0) {
    sub_8068FE0(zapdosEntity,0x21c,0);
  }
  else {
    sub_8072008(zapdosEntity,zapdosEntity,gZapdosConfigLevel,0,0);
    SetFacingDirection(zapdosEntity,DIRECTION_SOUTH);
    sub_8086A3C(zapdosEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SHIFTRY);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ZAPDOS);
}

void sub_8087334(u8 param_1, u8 param_2)
{
  if ((param_2 == 7 || param_2 == 8 || param_2 == 9) && (param_1 == 8)) {
    sub_8097FA8(5);
    gDungeon->unk2 = 1;
  }
}

void ZapdosPreFightDialogue(void)
{
    Entity *leaderEntity;
    Entity *partnerEntity;
    struct Zapdos1 puStack_38; // sp 0x0
    struct_8085B80 auStack_78;
    struct Zapdos2 puStack_30;
    s16 *puStack_34[1]; // sp 0x58
    struct Entity *pEStack_34[1]; // sp 0x5c
    s16 *puStack_4c[1]; // sp 0x60
    Entity *pEStack_2c[1]; // sp 0x64
    Entity *zapdosEntity; // sp 0x68
    struct_8085B80 auStack_48;  // r8

    leaderEntity = xxx_call_GetLeader();
    partnerEntity = GetPartnerEntity();
    zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
    sub_8086448();
    sub_803E708(10,0x46);
    SpriteLookAroundEffect(partnerEntity);
    sub_803E708(10,0x46);
    sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
    sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
    DisplayDungeonDialogue(&gUnknown_81014B0);
    sub_803E708(10,0x46);
    sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
    sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
    DisplayDungeonDialogue(&gUnknown_8101504);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(3);
    DungeonStopBGM();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gUnknown_81015A0);
    ZapdosDropInEffect(zapdosEntity);
    DungeonStartNewBGM(MUS_RISING_FEAR);
    sub_806CDD4(partnerEntity,6,DIRECTION_NORTH);
    DisplayDungeonDialogue(&gUnknown_81015D4); //  Waah!
    sub_803E708(10,0x46);
    sub_80869E4(partnerEntity,2,1,DIRECTION_SOUTHEAST);

    puStack_38 = gUnknown_810744C;
    puStack_34[0] = puStack_38.unk0;
    pEStack_34[0] = partnerEntity;
    sub_8085B4C(&auStack_78,puStack_34,pEStack_34,1);
    GetEntInfo(partnerEntity)->unk15F = 1;
    while(sub_8085B80(&auStack_78)) {
        sub_803E46C(0x46);
    }

    GetEntInfo(partnerEntity)->unk15F = 0;
    GetEntInfo(partnerEntity)->unk15D = 1;
    sub_80869E4(partnerEntity,2,2,DIRECTION_NORTH);
    DisplayDungeonDialogue(&gUnknown_81015E8); // I warned you! I have no mercy for meddlers
    sub_803E708(0x3c,0x46);
    DisplayDungeonDialogue(&gUnknown_8101624);
    sub_803E708(10,0x46);
    GetEntInfo(partnerEntity)->unk15D = 0;
    sub_80869E4(partnerEntity,2,2,DIRECTION_NORTHWEST);

    puStack_30 = gUnknown_8107464;
    puStack_4c[0] = puStack_30.unk0;
    pEStack_2c[0] = partnerEntity;
    sub_8085B4C(&auStack_48,puStack_4c,pEStack_2c,1);
    while (sub_8085B80(&auStack_48)) {
        sub_803E46C(0x46);
    }

    sub_80869E4(partnerEntity,2,1,DIRECTION_NORTHEAST);
    DisplayDungeonDialogue(&gUnknown_810165C);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(3);
    DisplayDungeonDialogue(&gUnknown_8101750);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue(&gUnknown_810178C);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gUnknown_81017B4);
    sub_803E708(10,0x46);
    SetupBossFightHP(zapdosEntity,300, MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ZapdosReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *zapdosEntity;

  leaderEntity = xxx_call_GetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_8086448();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_1);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gUnknown_81015A0);
  sub_803E708(10,0x46);
  ZapdosDropInEffect(zapdosEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_2);
  ZapdosScreenFlash(1);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_3);
  ZapdosScreenFlash(2);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_4);
  SetupBossFightHP(zapdosEntity,300,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ZapdosPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * zapdosEntity;

  leaderEntity = xxx_call_GetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ZAPDOS)) {
    sub_80866C4(&gZapdosPostStoryPreFightDialogue_6);
  }
  else {
    ZapdosScreenFlash(1);
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_1);
    ZapdosDropInEffect(zapdosEntity);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_2);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_3);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_4);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(zapdosEntity,300,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}


void ZapdosDropInEffect(Entity *zapdosEntity)
{
  int iVar1;

  GetEntInfo(zapdosEntity)->unk15C = 1;
  GetEntInfo(zapdosEntity)->unk15E = 0;
  GetEntInfo(zapdosEntity)->unk174.raw = 200; // incorrect value? Overwritten immediately anyway
  PlaySoundEffect(0x1ea);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(zapdosEntity)->unk174 = IntToF248_2(iVar1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
}

void ZapdosScreenFlash(s32 numFlashes)
{
  s32 index;

  PlaySoundEffect(0x1f6);
  if (2 < numFlashes) {
    for(index = 250; index > 199; index -= 10)
    {
      SetDungeonBGColorRGB(index,index,index / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  if (1 < numFlashes) {
    for(index = 250; index > 199; index -= 10)
    {
      SetDungeonBGColorRGB(index,index,index / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  for(index = 250; index >= 0; index -= 10)
  {
    SetDungeonBGColorRGB(index,index,index / 4,1,1);
    sub_803E46C(0x46);
  }
  sub_8085EB0();
}

void sub_80877E8(void)
{
  Entity * leaderEntity;
  Entity * moltresEntity;

  leaderEntity = xxx_call_GetLeader();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(moltresEntity, DIRECTION_SOUTH);
  sub_8086A3C(moltresEntity);
  sub_8085860(leaderEntity->pos.x + -3,leaderEntity->pos.y + -2);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MOLTRES);
}

void sub_8087848(void)
{
  Entity *leaderEntity;
  Entity *moltresEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = xxx_call_GetLeader();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8068FE0(moltresEntity,0x21c,0);
  }
  else {
    sub_8072008(moltresEntity,moltresEntity,gMoltresConfigLevel,0,0);
    SetFacingDirection(moltresEntity, DIRECTION_SOUTH);
    sub_8086A3C(moltresEntity);
  }
  sub_8085860(leaderEntity->pos.x - 5, leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos, YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MOLTRES);
}

void sub_80878F4(u8 param_1, u8 param_2)
{
  if ((param_2 == 0xA || param_2 == 0xB || param_2 == 0xC) && (param_1 == 0x9)) {
    sub_8097FA8(0x7);
    gDungeon->unk2 = 1;
  }
}

void MoltresPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *moltresEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  MoltresScreenFlash1(0xc,5);
  sub_8086500();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SpriteLookAroundEffect(partnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_2);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_4);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,2,DIRECTION_WEST);
  sub_8086690();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  PlaySoundEffect(0x2f2);
  DungeonStopBGM();
  MoltresScreenDarken();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1cf);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_8);
  sub_803E708(10,0x46);
  MoltresScreenFlash3();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_9);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(9,5);
  MoltresScreenFlash2(0xb,5);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_10);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  MoltresDropInEffect(moltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_11);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_12);
  sub_803E708(10,0x46);
  SetupBossFightHP(moltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}


void MoltresReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *moltresEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  MoltresScreenFlash1(10,5);
  sub_8086500();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(partnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,2,DIRECTION_WEST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  sub_8086690();
  MoltresScreenDarken();
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  MoltresDropInEffect(moltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(&gMoltresReFightDialogue_3);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(moltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void MoltresPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * moltresEntity;

  leaderEntity = xxx_call_GetLeader();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  MoltresScreenFlash1(0xc,5);
  sub_808654C();
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    sub_803E708(4,0x46);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gUnknown_8100D3C);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_1);
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    MoltresDropInEffect(moltresEntity);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_2);
    MoltresScreenFlash1(0xc,5);
    MoltresScreenFlash2(9,5);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_3);
    MoltresScreenFlash3();
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_4);
    MoltresScreenFlash2(0xb,6);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(moltresEntity,400,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void MoltresDropInEffect(Entity * moltresEntity)
{
  s32 iVar1;

  GetEntInfo(moltresEntity)->unk15C = 1;
  GetEntInfo(moltresEntity)->unk15E = 0;
  GetEntInfo(moltresEntity)->unk174 = IntToF248_2(200);
  PlaySoundEffect(0x1f8);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(moltresEntity)->unk174 = IntToF248_2(iVar1);
    sub_803E46C(0x46);
  }
}

void MoltresScreenFlash1(s32 xArg, s32 yArg)
{
    s32 x, y;
    DungeonPos newPos;

    x = X_POS_TO_PIXELPOS(xArg);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(yArg);
    newPos.y = y / 256;

    sub_8085EC8(370,16,0,&newPos,0);
}

void MoltresScreenFlash2(s32 xArg, s32 yArg)
{
    s32 r6;
    s32 i, x, y;
    DungeonPos newPos;

    x = X_POS_TO_PIXELPOS(xArg);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(yArg);
    newPos.y = y / 256;

    r6 = sub_8085EC8(370,22,0,&newPos,0);
    PlaySoundEffect(0x1EC);

    for (i = 250; i >= 20; i -= 10) {
        SetDungeonBGColorRGB(i, 0, 0, 1, 1);
        sub_803E46C(0x46);
    }
    sub_803E708(0xA, 0x46);

    for (i = 250; i >= 0; i -= 10) {
        SetDungeonBGColorRGB(i, 0, 0, 1, 1);
        sub_803E46C(0x46);
    }
    sub_803E708(0xA, 0x46);

    sub_8085EB0();
    sub_8085F44(r6);
}

void MoltresScreenFlash3(void)
{
  int iVar1;

  PlaySoundEffect(0x1ed);
  iVar1 = 0xfa;
  for(iVar1 = 250; iVar1 > 9; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  sub_8085EB0();
}

void MoltresScreenDarken(void)
{
  s32 iVar1;

  for(iVar1 = 0; iVar1 >= -80; iVar1 -= 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}


void sub_8087F54(void)
{
  Entity  *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
  sub_8086A3C(articunoEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void sub_8087FB4(void)
{
  Entity  *articunoEntity;

  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
  sub_806CDD4(articunoEntity, 0xF, DIRECTION_SOUTH);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void sub_8087FF8(void)
{
  Entity  *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_8068FE0(articunoEntity,0x21c,0);
  }
  else {
    sub_8072008(articunoEntity,articunoEntity,gArticunoConfigLevel,0,0);
    SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
    sub_8086A3C(articunoEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void sub_8088088(u8 param_1, u8 param_2)
{
  if ((param_2 == 0xD || param_2 == 0xE || param_2 == 0xF) && (param_1 == 0xD)) {
    sub_8097FA8(0x9);
    gDungeon->unk2 = 1;
  }
}

void ArticunoPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8086448();
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_8086598();
  DungeonStopBGM();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_3);
  sub_803E708(10,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_SOUTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
  sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(leaderEntity);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0); // snow flurry
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  PlaySoundEffect(0x1ee); // flash effect?
  sub_8088574();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_8);
  sub_803E708(10,0x46);
  ArticunoScreenFlash();
  sub_8086738();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_9);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1ea);
  sub_8088484(articunoEntity);
  sub_80865E8();
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_10);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_11);
  sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_12);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x10,0x46);
  SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ArticunoReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoReFightDialogue_1);
  sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoReFightDialogue_2);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoReFightDialogue_3);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x28,0x46);
  SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ArticunoPostStoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_80866C4(&gUnknown_8102A9C);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_SNOW;
    sub_807EAA0(0,1);
    ArticunoScreenFlash();
    sub_8086738();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    sub_8088484(articunoEntity);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_2);
    sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_3);
    sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_4);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_5);
    sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
    sub_803E708(0x28,0x46);
    SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void sub_8088484(Entity *param_1)
{
  int iVar1;

  GetEntInfo(param_1)->unk15C = 1;
  GetEntInfo(param_1)->unk15E = 0;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(param_1)->unk174 = IntToF248_2(iVar1);
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,0);
    sub_803E46C(0x46);
  }
}

void ArticunoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x2ad);
  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  sub_8085EB0();
}

void sub_8088574(void)
{
  int iVar1;

  for(iVar1 = 0; iVar1 <= 80; iVar1 += 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}

void sub_80885A0(void)
{
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
}

void sub_80885C4(void)
{
  Entity * leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  DungeonFadeOutBGM(0x3c);
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
}

void sub_8088608(void)
{
    gDungeon->unk2 = 1;
}

void sub_8088618(void)
{
    sub_8086448();
    // The mountain's summit...
    // But there is no one here
    // It's time to go back
    sub_80866C4(&gUnknown_8102B10);
}

void sub_808862C(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(alakazamEntity, DIRECTION_NORTH);
  sub_80861D4(alakazamEntity,0xd,DIRECTION_NORTH);
  SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(groudonEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_80886C4(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = xxx_call_GetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  PlaySoundEffect(0x3e5);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8068FE0(alakazamEntity,0x21c,0);
  SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(groudonEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_808875C(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_80867F4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(alakazamEntity,0x21c,0);
  if (sub_8086AE4(MONSTER_GROUDON)) {
    sub_8068FE0(groudonEntity,0x21c,0);
  }
  else {
    sub_8072008(groudonEntity,groudonEntity,gGroudonConfigLevel,0,0);
    SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
    sub_80861D4(groudonEntity,0xf,DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088818(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x12 || param_2 == 0x13 || param_2 == 0x14) && (param_1 == 0xE)) {
    sub_8097FA8(0xC);
    gDungeon->unk2 = 1;
  }
}

void sub_8088848(void)
{
    sub_8086854();
}

void GroudonPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * partnerEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086448();
  DisplayDungeonDialogue(&GroudonPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_808682C();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_4);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  DisplayDungeonDialogue(&GroudonPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_6);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_80861B8(alakazamEntity,6,DIRECTION_NORTH);
  PlaySoundEffect(0x205);
  sub_8086738();
  sub_8068FE0(alakazamEntity,0x21c,0);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_8);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_9);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  sub_803E708(0x28,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_10);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_11);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  GroudonScreenFlash2();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_12);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_13);
  sub_803E708(10,0x46);
  sub_803E708(0x1e,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_14);
  sub_803E708(10,0x46);
  sub_8086A54(groudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void GroudonReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_1);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_2);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_3);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  DisplayDungeonDialogue(&gGroudonReFightDialogue_4);
  sub_803E708(10,0x46);
  sub_8086A54(groudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void GroudonPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086448();
  if (sub_8086AE4(MONSTER_GROUDON)) {
      sub_80866C4(&gUnknown_8103488);
  }
  else{
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    SceneGroudonMovement(groudonEntity);
    SceneGroudonMovement(groudonEntity);
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_2);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_3);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_4);
    sub_803E708(10,0x46);
    SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

// Moves Groudon down in a walking fashion
void SceneGroudonMovement(Entity * groudonEntity)
{
  int iVar1;

  sub_8086848(0x18,0x10);
  sub_806CDD4(groudonEntity,0,DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 0x2C; iVar1++)
  {
    if ((iVar1 == 10) || (iVar1 == 0x20)) {
      PlaySoundEffect(0x1f9);
      sub_8086838(0,1,0);
      sub_808680C();
    }
    if ((iVar1 - 10U < 0xc) || (iVar1 > 0x1f)) {
      IncreaseEntityPixelPos(groudonEntity,0,0x100);
    }
    sub_803E46C(0x46);
  }
  sub_80856C8(groudonEntity,groudonEntity->pos.x,groudonEntity->pos.y + 1);
  sub_80861D4(groudonEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(0x22,0x46);
}

void GroudonScreenFlash(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void GroudonScreenFlash2(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}


void sub_8088DC0(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(groudonEntity);
  sub_806CDD4(groudonEntity,0xe,DIRECTION_SOUTH);
  sub_8086A3C(alakazamEntity);
  sub_806CDD4(alakazamEntity,0xe,DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088E5C(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;

  leaderEntity = xxx_call_GetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(groudonEntity,0x21c,0);
  sub_8068FE0(alakazamEntity,0x21c,0);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088EE8(void)
{
    sub_8086854();
}


void MagmaCavernMidDialogue(void)
{
  Entity * leaderEntity;
  Entity * partnerEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;
  s16 IDStack [2];
  PixelPos pos;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_8052D44(IDStack,leaderEntity,partnerEntity);
  sub_8086448();
  SpriteLookAroundEffect(partnerEntity);
  // Let's see..
  // I wonder where we are?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  // I know we've come pretty
  // far...
  //
  // I'm certain we've come quite
  // far already..
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_2);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0x28,0x46);
  // Waaah!
  // Qu-quake!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_3);
  sub_803E708(0x78,0x46);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_803E708(0x14,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(10,0x46);
  // Whew!
  // It settled down.
  //
  // Whew
  // It's over.
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_4);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  PlaySoundEffect(0x1c7);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  // Hey! {POKEMON_0}!
  // Over there!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_5);
  GetEntInfo(groudonEntity)->unk15E = 0;
  GetEntInfo(alakazamEntity)->unk15E =0;
  pos.x = (groudonEntity->pixelPos.x + alakazamEntity->pixelPos.x) / 2;
  pos.y = (groudonEntity->pixelPos.y + alakazamEntity->pixelPos.y) / 2 + 0x800;
  ShiftCameraToPosition(&pos,0x20);
  sub_803E708(0x3c,0x46);
  sub_80891F0();
  // Hey!
  // Are you OK?!
  //
  // Hey!
  // Snap out of it!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_6);
  sub_803E708(10,0x46);
  // Urrrrgh...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_7);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,2,DIRECTION_NORTHWEST);
  // What happened to you?
  //
  // What happened here?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_8);
  sub_803E708(10,0x46);
  // We challenged..
  // {POKEMON_2}...
  // And wiped out..
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_9);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_10);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTHEAST);
  sub_80869E4(partnerEntity,4,1,DIRECTION_NORTHEAST);
  // Grrgh..
  // We... It crushed us
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_11);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  // That's right...
  // What happened to {POKEMON_3}?
  // Where is {POKEMON_3}?
  //
  // Wait...
  // What about {POKEMON_3}?
  // Where did {POKEMON_3} go?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_12);
  sub_803E708(0x1e,0x46);
  // {POKEMON_3} is...
  // Still battling {POKEMON_2}...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_13);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);

  // {POKEMON_0}!
  // We've got to hurry!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_14);
  sub_8089294();
  // Be careful!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_15);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void sub_8089168(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(leaderEntity);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808919C(Entity *r0)
{
    IncreaseEntityPixelPos(r0, 0, 0xfffffe00);
}

void sub_80891B0(Entity *r0)
{
    sub_806CDD4(r0, 0, DIRECTION_NORTH);
    GetEntInfo(r0)->unk15F = 1;
}


void sub_80891D0(Entity *r0)
{
    sub_806CDD4(r0, 7, DIRECTION_NORTH);
    GetEntInfo(r0)->unk15F = 0;
}

void sub_80891F0(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 < 0x30; iVar1++)
  {
    sub_80855E4(sub_808919C);
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_8089224(Entity * entity)
{
  s32 xPixelPos;

  if (entity->pixelPos.y < 0x9001) {
    return;
  }
  xPixelPos = entity->pixelPos.x;

  if(xPixelPos < 0xE400)
  {
      if(xPixelPos <= 0xB400)
      {
          // 0 - 0xB400
          IncreaseEntityPixelPos(entity, 0, 0xfffffe00);
      }
      else
      {
          // 0xB401 - 0xE3FF
           IncreaseEntityPixelPos(entity, 0xfffffe00, 0);
      }
  }
  else
  {
      if(xPixelPos < 0xFC00)
      {
            IncreaseEntityPixelPos(entity, 0, 0xfffffe00);
      }
      else
      {
          if(xPixelPos <= 0x11400)
          {
              IncreaseEntityPixelPos(entity, 0x200, 0);
          }
          else
          {
              IncreaseEntityPixelPos(entity, 0, 0xfffffe00);
          }
      }
  }
}

void sub_8089294(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 <= 0x77; iVar1++)
  {
    sub_80855E4(sub_8089224);
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_80892C8(void)
{
  Entity * leaderEntity;
  Entity * RayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  RayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(RayquazaEntity, DIRECTION_SOUTH);
  sub_8086A3C(RayquazaEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_RAYQUAZA);
}

void sub_8089328(void)
{
  Entity * leaderEntity;
  Entity * rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_8068FE0(rayquazaEntity,0x21c,0);
  }
  else {
    sub_8072008(rayquazaEntity,rayquazaEntity,gRayquazaConfigLevel,0,0);
    sub_8086A3C(rayquazaEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_RAYQUAZA);
}

void sub_80893B4(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x17 || param_2 == 0x18 || param_2 == 0x19) && (param_1 == 0xF)) {
    sub_8097FA8(0xF);
    gDungeon->unk2 = 1;
  }
}

void RayquazaPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_2);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  SpriteLookAroundEffect(partnerEntity);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_3);
  sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_6);
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_7);
  RayquazaDropInEffect(rayquazaEntity);
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_8);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_9);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_10);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_11);
  SetupBossFightHP(rayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RayquazaReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue(&gRayquazaPreFightDialogue_7);
  sub_803E708(10,0x46);
  RayquazaDropInEffect(rayquazaEntity);
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_2);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_3);
  RayquazaScreenFlash();
  DisplayDungeonDialogue(&gRayquazaReFightDialogue_4);
  SetupBossFightHP(rayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RayquazaPostStoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *rayquazaEntity;

  leaderEntity = xxx_call_GetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_80866C4(&gRayquazaPostStoryPreFightDialogue_6);
  }
  else {
    PlaySoundEffect(0x1da); // Rayquaza Cry
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_1);
    RayquazaDropInEffect(rayquazaEntity);
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_2);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_3);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_4);
    RayquazaScreenFlash();
    DisplayDungeonDialogue(&gRayquazaPostStoryPreFightDialogue_5);
    SetupBossFightHP(rayquazaEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void RayquazaDropInEffect(Entity *rayquazaEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(rayquazaEntity)->unk15E = 0;
  iVar2 = IntToF248_2(200);
  iVar1 = IntToF248_2(6);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw = iVar2.raw - iVar1.raw; // must be .raw
    iVar1 = F248_Sub(iVar1, FloatToF248_2(3./32.));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(rayquazaEntity)->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  GetEntInfo(rayquazaEntity)->unk174 = IntToF248_2(0);
}

void RayquazaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}


void sub_808970C(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_TINY_WOODS);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
}

void sub_808974C(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
}

void sub_8089788(Entity *entity, u8 param_2, u8 param_3)
{
  Entity *monEntity;
  s32 index;
  u32 unk1;

  unk1 = 0;

  if (param_3 == 0x1A || param_3 == 0x1B) {
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
      monEntity = gDungeon->wildPokemon[index];
      if ((EntityIsValid(monEntity)) && (monEntity != entity) && (GetEntInfo(monEntity)->monsterBehavior == param_2)) {
        return;
      }
    }
    // WTF is this??
    if(!unk1){
        sub_8097FA8(0x11);
        gDungeon->unk2 = 1;
    }
  }
}

void sub_80897F0(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103BD8);
  // We don't like to brag or
  // nothing, but
  DisplayDungeonDialogue(&gUnknown_8103C00);
  // We get furious real easy
  // You know that?!
  DisplayDungeonDialogue(&gUnknown_8103C3C);
  // What really irritates us is
  // when we see some dim witted face
  DisplayDungeonDialogue(&gUnknown_8103C74);
  // .........
  // Wrooooooar!
  // That vacant expression
  DisplayDungeonDialogue(&gUnknown_8103CC4);
  // Gwoooh
  // It's ticking me off!
  // I'm seeing red!
  DisplayDungeonDialogue(&gUnknown_8103D0C);
  // Mukkkeeeeeh
  // Get 'em! It's frenzy time!
  DisplayDungeonDialogue(&gUnknown_8103D50);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}



void sub_8089878(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103D8C);
  DisplayDungeonDialogue(&gUnknown_8103D98);
  DisplayDungeonDialogue(&gUnknown_8103DD8);
  DisplayDungeonDialogue(&gUnknown_8103E28);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8103E34);
}

void sub_80898F8(Entity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void sub_8089908(Entity *r0)
{
    SetFacingDirection(r0, DIRECTION_NORTH);
}

void sub_8089914(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
  sub_8086A3C(MewtwoEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MEWTWO);
}

void sub_8089978(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if(HasRecruitedMon(MONSTER_MEWTWO)){
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8068FE0(MewtwoEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
    sub_8086A3C(MewtwoEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MEWTWO);
}

void sub_8089A00(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x1d || param_2 == 0x1e || param_2 == 0x1f) && (param_1 == 0x11)) {
    sub_8097FA8(0x13);
    gDungeon->unk2 = 1;
  }
}

void MewtwoPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  sub_8086448();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_1);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  sub_8086794();
  sub_803E708(0x1e,0x46);
  MewtwoDropInEffect(MewtwoEntity);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_2);
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_3);
  sub_803E708(10,0x46);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_4);
  MewtwoScreenFlash();
  DisplayDungeonDialogue(&gMewtwoPreFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void MewtwoReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = xxx_call_GetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  sub_8086448();
  if(HasRecruitedMon(MONSTER_MEWTWO)) {
    sub_80866C4(&gMewtwoReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_1);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8086794();
    MewtwoDropInEffect(MewtwoEntity);
    sub_803E708(0x3c,0x46);
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_2);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_3);
    MewtwoScreenFlash();
    DisplayDungeonDialogue(&gMewtwoReFightDialogue_4);
    SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void MewtwoDropInEffect(Entity *mewtwoEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(mewtwoEntity)->unk15E = 0;
  iVar2 = IntToF248_2(200);
  iVar1 = IntToF248_2(4);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248_2(0.045));
    if (F248LessThanFloat(iVar1, 0.12)) {
      iVar1 = FloatToF248_2(0.12);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(mewtwoEntity)->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  GetEntInfo(mewtwoEntity)->unk174 = IntToF248_2(0);
}

void MewtwoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_8089C44(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ENTEI);
}


void sub_8089C90(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
      sub_8068FE0(EnteiEntity,0x21c,0);
  }
  else {
      SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ENTEI);
}

void sub_8089CFC(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x20 || param_2 == 0x21 || param_2 == 0x22) && (param_1 == 0x12)) {
    sub_8097FA8(0x15);
    gDungeon->unk2 = 1;
  }
}

void EnteiPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void EnteiReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void EnteiPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
    sub_80866C4(&gEnteiPostStoryPreFightDialogue_4);
  }
  else {
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_1);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_2);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void EnteiScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, 0, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_8089EFC(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}


void sub_8089F44(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}


void sub_8089F8C(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
      sub_8068FE0(RaikouEntity,0x21c,0);
  }
  else {
      SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}

void sub_8089FF0(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x23 || param_2 == 0x24 || param_2 == 0x25) && (param_1 == 0x13)) {
    sub_8097FA8(0x17);
    gDungeon->unk2 = 1;
  }
}

void RaikouPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_2);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_3);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_4);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_5);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_2);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
    sub_80866C4(&gRaikouPostStoryPreFightDialogue_4);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_RAIN;
    sub_807EAA0(0,1);
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_1);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_2);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A264(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8086A3C(SuicuneEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A2C0(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A308(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
     sub_8068FE0(SuicuneEntity,0x21c,0);
  }
  else {
     SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A36C(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x26 || param_2 == 0x27 || param_2 == 0x28) && (param_1 == 0x14)) {
    sub_8097FA8(0x19);
    gDungeon->unk2 = 1;
  }
}

void SuicunePreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  sub_8086448();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_2);
  sub_803E708(10,70);
  sub_80426C8(1,2);
  sub_803E708(0x3c,70);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_3);
  sub_803E708(10,70);
  sub_808A528(SuicuneEntity);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_4);
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_5);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_6);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicunePreFightDialogue_7);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SuicuneReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_1);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_2);
  SuicuneScreenFlash();
  DisplayDungeonDialogue(&gSuicuneReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SuicunePostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = xxx_call_GetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
    sub_80866C4(&gSuicunePostStoryPreFightDialogue_4);
  }
  else {
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_1);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_2);
    SuicuneScreenFlash();
    DisplayDungeonDialogue(&gSuicunePostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void sub_808A528(Entity * param_1)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(param_1)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(12);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248(0.375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248_2(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(param_1)->unk174 = iVar2;
    sub_803E46C(70);
  }
  GetEntInfo(param_1)->unk174 = IntToF248_2(0);
}

void SuicuneScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A608(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
  sub_8086A3C(HoOhEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -6);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_HO_OH);
}

void sub_808A668(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_8068FE0(HoOhEntity,0x21c,0);
  }
  else {
    SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
    sub_8086A3C(HoOhEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 6);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_HO_OH);
}

void sub_808A6E8(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x29 || param_2 == 0x2A) && (param_1 == 0x15)) {
    sub_8097FA8(0x1A);
    gDungeon->unk2 = 1;
  }
}

void sub_808A718(void)
{
    sub_8086854();
}

void HoOhPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;
  PixelPos local_14;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  local_14.x = leaderEntity->pixelPos.x;
  local_14.y = leaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_1);
  sub_803E708(10,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_2);
  sub_803E708(10,70);
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0xfa,70);
  HoOhDropInEffect(HoOhEntity);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_3);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_4);
  sub_803E708(0x1e,70);
  sub_803E708(0x1e,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_5);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void HoOhReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;
  PixelPos local_14;

  leaderEntity = xxx_call_GetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);

  local_14.x = leaderEntity->pixelPos.x;
  local_14.y = leaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_80866C4(&HoOhReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&HoOhReFightDialogue_1);
    HoOhScreenFlash();
    sub_80855E4(sub_80868F4);
    sub_808680C();
    sub_803E708(10,70);
    HoOhDropInEffect(HoOhEntity);
    sub_808682C();
    sub_80855E4(sub_8086910);
    sub_8085930(DIRECTION_NORTH);
    DisplayDungeonDialogue(&HoOhReFightDialogue_2);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_3);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_4);
    sub_803E708(10,70);
    SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void HoOhDropInEffect(Entity * param_1)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(param_1)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(12);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248(0.375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248_2(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(param_1)->unk174 = iVar2;
    sub_803E46C(70);
  }
  GetEntInfo(param_1)->unk174 = IntToF248_2(0);
}

void HoOhScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A9E4(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 4);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AA3C(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AA94(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(LatiosEntity,0x21c,0);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AAF0(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x2B || param_2 == 0x2C || param_2 == 0x2D) && (param_1 == 0x16)) {
    sub_8097FA8(0x1C);
    gDungeon->unk2 = 1;
  }
}

void LatiosPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;
  PixelPos local_18;
  DungeonPos local_19;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);

  local_18.x = LatiosEntity->pixelPos.x;
  local_18.y = LatiosEntity->pixelPos.y + (0x80 << 6);
  local_19.y = 0x70;
  local_19.x = 0xFC;
  sub_8085EC8(0x1bd,0,0,&local_19,1);

  sub_803E708(0x1e,70);
  sub_8086448();
  ShiftCameraToPosition(&local_18,0x18);
  sub_803E708(2,70);
  SpriteShockEffect(LatiosEntity);
  sub_803E708(0x20,70);
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void LatiosReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = xxx_call_GetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  sub_8086448();
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosReFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808AC3C(void)
{
    sub_8086448();
    // There appears to be no one here
    sub_80866C4(&gUnknown_8104FC8);
}

void LatiosScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  gDungeonBrightness = 0x1f;
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808ACC0(void)
{
  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGIROCK)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGIROCK);
    sub_8068FE0(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ROCK_PART);
  }
  else if (sub_80860A8(ITEM_ROCK_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGIROCK);
  }
}

void sub_808AD48(void)
{
  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGICE)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGICE);
    sub_8068FE0(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ICE_PART);
  }
  else if (sub_80860A8(ITEM_ICE_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGICE);
  }
}

void sub_808ADCC(void)
{

  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGISTEEL)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGISTEEL);
    sub_8068FE0(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_STEEL_PART);
  }
  else if (sub_80860A8(ITEM_STEEL_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGISTEEL);
  }
}

void sub_808AE54(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      xxx_init_itemslot_8090A8C(&item,ITEM_ROCK_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      DisplayDungeonDialogue(&gRegirockPostFightDialogue_1);
    }
  }
}


void sub_808AEC8(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      xxx_init_itemslot_8090A8C(&item,ITEM_ICE_PART,0);
      sub_80464C8(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      DisplayDungeonDialogue(&gRegicePostFightDialogue_1);
    }
  }
}

void sub_808AF3C(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      xxx_init_itemslot_8090A8C(&item,ITEM_STEEL_PART,0);
      sub_80464C8(GetLeader(),param_3, &item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      DisplayDungeonDialogue(&gRegisteelPostFightDialogue_1);
    }
  }
}

void sub_808AFB0(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x2E) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_ROCK_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    // {POKEMON_0} obtained the Rock Part that Regirock was guarding
    DisplayDungeonDialogue(&gRegirockPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B030(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x2F) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_ICE_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    // {POKEMON_0} obtained the Ice Part that Regice was guarding
    DisplayDungeonDialogue(&gRegicePostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B0B0(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = xxx_call_GetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x30) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_STEEL_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
    // {POKEMON_0} obtained the Steel Part that Registeel was guarding
    DisplayDungeonDialogue(&gRegisteelPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void RegirockPreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegirockPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegirockFightHP);
  }
}

void RegicePreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegicePreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegiceFightHP);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegisteelPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegisteelFightHP);
  }
}

void sub_808B1CC(u8 itemID)
{
    Entity *entity;
    Tile *tile;
    DungeonPos pos;
    Item item;

    pos.x = gDungeon->unk644.unk40;
    pos.y = gDungeon->unk644.unk42;
    if ((pos.x < 0) || (pos.y  < 0)) {
        entity = GetLeader();
        if (entity == NULL) {
            gDungeon->unk2 = 1;
            return;
        }
        pos.x = entity->pos.x;
        pos.y = entity->pos.y;
    }
    sub_807FE04(&pos, 0);
    tile = GetTileMut(pos.x, pos.y);
    tile->terrainType = tile->terrainType | TERRAIN_TYPE_STAIRS;
    if (((itemID != ITEM_NOTHING) && (sub_80860A8(itemID) == 0)) &&
        (sub_80860A8(ITEM_MUSIC_BOX) == 0)) {
        xxx_init_itemslot_8090A8C(&item,itemID,0);
        pos.y--;
        sub_80460F8(&pos,&item,1);
    }
    sub_8049ED4();
    ShowWholeRevealedDungeonMap();
}

void SetupRegiFacingDirection(Entity *regiEntity)
{
    GetEntInfo(regiEntity)->action.direction = DIRECTION_NORTH;
    sub_806CE68(regiEntity, DIRECTION_NORTH);
}


void SetupRegirockFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}


void SetupRegiceFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}


void SetupRegisteelFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}

void sub_808B2F4(void)
{
  Entity * leaderEntity;
  Entity * jirachiEntity;

  leaderEntity = xxx_call_GetLeader();
  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  CreateJirachiWishWarpTile();
  sub_8049ED4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(jirachiEntity, DIRECTION_SOUTH);
  sub_8086A3C(jirachiEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
}

void sub_808B35C(void)
{
  Entity * leaderEntity;
  Entity * jirachiEntity;

  leaderEntity = xxx_call_GetLeader();
  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_JIRACHI)) {
    sub_8068FE0(jirachiEntity,0x21c,0);
  }
  else {
    SetFacingDirection(jirachiEntity, DIRECTION_SOUTH);
    sub_8086A3C(jirachiEntity);
    CreateJirachiWishWarpTile();
    sub_8049ED4();

  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
}

void sub_808B3E4(u8 param_1, u8 param_2, u8 param_3)
{
  u8 uVar1;
  if ((param_2 == 0x31 || param_2 == 0x32) && (param_1 == 0x1A)) {
    sub_8097FA8(0x1E);
    if(param_3 != 0)
    {
        gDungeon->unk2 = 1;
    }
    else {
        uVar1 = gDungeon->unk1356C;
        if(sub_80860A8(0x36) != 0)
        {
            JirachiWish();
        }
        else
        {
            sub_808B50C();
        }
        gDungeon->unk1356C = uVar1;
        ShowWholeRevealedDungeonMap();
    }
  }
}

void JirachiPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * jirachiEntity;

  leaderEntity = xxx_call_GetLeader();
  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  sub_8086448();
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_1);
  sub_803E708(10,70);
  SpriteLookAroundEffect(leaderEntity);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_2);
  sub_80861F8(0x37,jirachiEntity,1);
  sub_80855E4(SpriteShockEffect);
  sub_803E708(0x3c,70);
  JirachiDropInEffect(jirachiEntity);
  sub_803E708(0x5a,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_3);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_4);
  sub_803E708(10,70);
  SetupBossFightHP(jirachiEntity,0x15e,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808B50C(void)
{
  Entity * jirachiEntity;

  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(jirachiEntity);
  sub_8041888(0);
  GetEntInfo(jirachiEntity)->unk15C = 1;
  GetEntInfo(jirachiEntity)->unk15E = 0;
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,70);
  // Fwaaaahhhh
  DisplayDungeonDialogue(&gUnknown_810554C);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  // I think I had a dream, and I was fighting in it
  // Did I imagine it?
  // I'm sleepy so I'm going back to sleep.
  DisplayDungeonDialogue(&gUnknown_8105558);
  sub_803E708(10,70);
  JirachiSpinEffect(jirachiEntity);
  DisplayDungeonDialogue(&gUnknown_81055F4);
  sub_803E708(10,70);
  gDungeon->unk2 = 1;
}

void JirachiWish(void)
{
  Entity *jirachiEntity;
  DungeonPos *LeaderPos;
  Entity *leaderEntity;
  s32 wishChoice;

  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(jirachiEntity);
  sub_8041888(0);
  GetEntInfo(jirachiEntity)->unk15C = 1;
  GetEntInfo(jirachiEntity)->unk15E = 0;
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  sub_80855E4(sub_80861A8);
  gDungeon->unk1356C = 1;
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&gUnknown_8105668);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1a7);
  sub_803E708(0x96,0x46);
  SpriteShockEffect(jirachiEntity);
  DisplayDungeonDialogue(&gUnknown_8105674);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_803E708(10,0x46);
  sub_80856E0(jirachiEntity, DIRECTION_SOUTH);
  PlaySoundEffect(0x16a);
  DisplayDungeonDialogue(&gUnknown_81056B8);
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(jirachiEntity);
  DisplayDungeonDialogue(&gUnknown_81056DC);
  sub_803E708(10,0x46);
  while( 1 ) {
    while (1) {
        wishChoice = DisplayDungeonMenuMessage(NULL,gUnknown_8105798,gUnknown_810579C,0x705);
        if (wishChoice >= 1) break;
    }
    sub_803E708(10,0x46);
    if (wishChoice == 1) {
      s32 counter, index;
      DungeonPos pos;
      Item moneyItems [9];
      // Lots of Money
      DisplayDungeonDialogue(&gUnknown_810581C);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(jirachiEntity);

      for(counter = 0; counter < 6; counter++)
      {
        for(index = 0; index < 9; index++)
        {
          sub_8045C28(&moneyItems[index], ITEM_POKE, 0);
        }
        pos.x = (jirachiEntity->pos.x + DungeonRandInt(3) - 1);
        pos.y = (jirachiEntity->pos.y + DungeonRandInt(3) + -1);
        if ((GetTileMut(pos.x, pos.y)->terrainType & 3) != 0) {
          PlaySoundEffect(0x14c);
          sub_808BB3C(&pos);
          sub_8046860(jirachiEntity,&pos,moneyItems,9);
        }
      }
      GetEntInfo(jirachiEntity)->unk15D  = 0;
    }
    if (wishChoice == 2) {
      s32 counter, index;
      DungeonPos pos;
      Item items [9];
      // Lots of Items
      DisplayDungeonDialogue(&gUnknown_8105974);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(jirachiEntity);

      for(counter = 0; counter < 6; counter++)
      {
        for(index = 0; index < 9; index++)
        {
          sub_8045C28(&items[index], sub_803D73C(0),0);
        }
        pos.x = (jirachiEntity->pos.x + DungeonRandInt(3) - 1);
        pos.y = (jirachiEntity->pos.y + DungeonRandInt(3) + -1);

        if ((GetTileMut(pos.x, pos.y)->terrainType & 3) != 0) {
          PlaySoundEffect(400);
          sub_808BB3C(&pos);
          sub_8046860(jirachiEntity,&pos,items,9);
        }
      }
      GetEntInfo(jirachiEntity)->unk15D = 0;
    }

    if (wishChoice == 3)
    {
        // A Friend Area
        s32 friendArea = JirachiFriendAreaSearch();
        if (friendArea == NUM_FRIEND_AREAS)
        {
            // You want a friend area? But you already have many friend areas...
            DisplayDungeonDialogue(&gUnknown_8105A08);
            sub_803E708(10,0x46);
            continue;
        }
        else
        {
        // You want a friend area? As you wish..
          DisplayDungeonDialogue(&gUnknown_8105AD4);
          sub_803E708(10,0x46);
          JirachiWishGrantDialogue(jirachiEntity);
          GetEntInfo(jirachiEntity)->unk15D  = 0;
          DisplayDungeonDialogue(&gUnknown_8105B20);
          UnlockFriendArea(friendArea);
          PlaySoundEffect(0xd4);
          leaderEntity = GetLeader();
          SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leaderEntity,0);
          WriteFriendAreaName(gFormatBuffer_Items[0],friendArea,FALSE);
          // Obtained the friend area!
          DisplayDungeonDialogue(&gUnknown_8105B68);
        }
    }
    if (wishChoice == 4) {
        s32 counter, index;
        DungeonPos pos;
        Item strengthItems [9];
        // More Strength..
        DisplayDungeonDialogue(&gUnknown_8105BA8);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(jirachiEntity);

        for(counter = 0; counter < 5; counter++)
        {

          for(index = 0; index < 4; index++)
          {
            sub_8045C28(&strengthItems[index],gUnknown_81074FC[DungeonRandInt(8)],0);
          }

          pos.x = (jirachiEntity->pos.x + DungeonRandInt(3) - 1);
          pos.y = (jirachiEntity->pos.y + DungeonRandInt(3) + -1);

          if ((GetTileMut(pos.x, pos.y)->terrainType & 3) != 0) {
            PlaySoundEffect(400);
            sub_808BB3C(&pos);
            sub_8046860(jirachiEntity,&pos,strengthItems,4);
          }
        }
        GetEntInfo(jirachiEntity)->unk15D  = 0;
        DisplayDungeonDialogue(&gUnknown_8105BF4);
        sub_803E708(10,0x46);
    }
    if (wishChoice == 5) {
        s32 direction;
        // Something Good...
        DisplayDungeonDialogue(&gUnknown_8105D2C);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(jirachiEntity);
        GetEntInfo(jirachiEntity)->unk15D  = 0;
        DisplayDungeonDialogue(&gUnknown_8105D80);
        sub_803E708(10,0x46);
        LeaderPos = &GetLeader()->pos;
        direction = GetDirectionTowardsPosition(&jirachiEntity->pos,LeaderPos);
        SetFacingDirection(jirachiEntity,direction);
        sub_803E708(10,0x46);
        DisplayDungeonDialogue(&gUnknown_8105D9C);
        sub_803E708(10,0x46);
        gDungeon->unk644.unk30 = 1;
    }
    break;
  }

  DisplayDungeonDialogue(&gUnknown_81058E0);
  JirachiSpinEffect(jirachiEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_810593C);
  sub_803E708(10,0x46);
  EnableJirachiWishWarpTile();
}

void JirachiReFightDialogue(void)
{
    if(HasRecruitedMon(MONSTER_JIRACHI))
    {
        sub_8086448();
        sub_80866C4(&gJirachiReFightDialogue_1);
    }
    else
    {
        JirachiPreFightDialogue();
    }
}

void JirachiWishGrantFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  gDungeonBrightness = 0x1f;

  for(iVar1 = 0xFA; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 > 0xC7; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808BB3C(DungeonPos *pos1)
{
    s32 x, y;
    DungeonPos newPos;

    x = X_POS_TO_PIXELPOS(pos1->x);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(pos1->y);
    newPos.y = y / 256;

    sub_8085EC8(100,0,0,&newPos,0);
}

void sub_808BBA8(Entity *jirachiEntity)
{
  ResetMonEntityData(GetEntInfo(jirachiEntity),0);
}

void JirachiDropInEffect(Entity *jirachiEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  sub_80861F8(0x1b,jirachiEntity,0);
  sub_8086A54(jirachiEntity);
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  iVar1 = IntToF248(160);
  iVar2 = IntToF248(2);
  PlaySoundEffect(0x1f8);
  while (1) {
    iVar1.raw = iVar1.raw - iVar2.raw; // FRAGILE! Subtraction and assignment below must use .raw
    if (F248LessThanInt(iVar1, 24)) {
      iVar2.raw = IntToF248_2(1).raw;
    }
    if (F248LessThanInt(iVar1, 0)) break;
    GetEntInfo(jirachiEntity)->unk174 = iVar1;
    sub_803E46C(0x46);
  }
  GetEntInfo(jirachiEntity)->unk174 = IntToF248_2(0);
}

void JirachiSpinEffect(Entity * jirachiEntity)
{
  s32 uVar1;

  PlaySoundEffect(0x298);
  for(uVar1 = 0; uVar1 < 25; uVar1++){
    SetFacingDirection(jirachiEntity, uVar1 & DIRECTION_MASK);
    sub_803E708(3,0x46);
  }
  GetEntInfo(jirachiEntity)->unk15E = 1;
  PlaySoundEffect(0x27f);
  sub_80861F8(99,jirachiEntity,1);
}

void JirachiWishGrantDialogue(Entity *jirachiEntity)
{
  u32 uVar2;

  GetEntInfo(jirachiEntity)->unk15D = 1;
  // Nnnnnnnnnn!
  DisplayDungeonDialogue(&gUnknown_81058A8);
  PlaySoundEffect(0x375);
  sub_80861F8(0x67,jirachiEntity,1);
  PlaySoundEffect(0x2a8);
  uVar2 = sub_80861F8(0x68,jirachiEntity,0);
  // Taaaaaaaah!
  DisplayDungeonDialogue(&gUnknown_81058C4);
  if (sub_800E9A8(uVar2)) {
    sub_800DC14(uVar2);
  }
  sub_803E708(10,0x46);
  JirachiWishGrantFlash();
}

// Warp Tile is created but not enabled until the Wish is done with EnableJirachiWishWarpTile
void CreateJirachiWishWarpTile(void)
{
  Tile *tile;

  tile = GetTileMut(gDungeon->unkE220[7].x, gDungeon->unkE220[7].y);
  tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
  tile->terrainType &= ~TERRAIN_TYPE_STAIRS;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  ShowWholeRevealedDungeonMap();
}

void EnableJirachiWishWarpTile(void)
{
  Tile *tile;

  tile = GetTileMut(gDungeon->unkE220[7].x, gDungeon->unkE220[7].y);
  tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  tile->terrainType |= TERRAIN_TYPE_NORMAL;
  tile->terrainType &= ~TERRAIN_TYPE_IMPASSABLE_WALL;
  tile->terrainType |= TERRAIN_TYPE_STAIRS;
  tile->unk8 = 1;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  ShowWholeRevealedDungeonMap();
}

u8 JirachiFriendAreaSearch(void)
{
  u8 unlockCondition;
  s32 friendAreaCounter;
  s32 numUnlockableAreas;
  u8 friendAreas[NUM_FRIEND_AREAS];
  u32 friendAreaIndex;

  // Build a copy of friend area list and keep track of
  // how many are only Story Unlockable
  numUnlockableAreas = 0;
  for(friendAreaCounter = 1; friendAreaCounter < NUM_FRIEND_AREAS; friendAreaCounter++){
    unlockCondition = GetFriendAreaUnlockCondition(friendAreaCounter);
    if (!(unlockCondition == UNLOCK_LEGENDARY_REQUEST)){
        if (!(unlockCondition == UNLOCK_WONDER_MAIL)){
            if(!gFriendAreas[friendAreaCounter]) {
                friendAreas[numUnlockableAreas] = friendAreaCounter;
                numUnlockableAreas++;
            }
        }
    }
  }

  if (numUnlockableAreas == 0) {
    return NUM_FRIEND_AREAS;
  }
  else {
      // Randomly pick 1
    friendAreaIndex = DungeonRandInt(numUnlockableAreas);
    return friendAreas[friendAreaIndex];
  }
}

void sub_808BDEC(void)
{
  Entity * leaderEntity;
  Entity * lugiaEntity;

  leaderEntity = xxx_call_GetLeader();
  lugiaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LUGIA);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8068FE0(lugiaEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(lugiaEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LUGIA);
}

void sub_808BE70(u8 param_1,u8 param_2,u8 param_3)
{
  if ((param_2 == 0x33) && (param_1 == 0x1B)) {
    gDungeon->unk2 = 1;
  }
}


void LugiaPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * lugiaEntity;

  leaderEntity = xxx_call_GetLeader();
  lugiaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LUGIA);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    sub_8086448();
    sub_80866C4(&gLugiaPreFightDialogue_8);
  }
  else {
    DungeonStopBGM();
    sub_8086448();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C0CC();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_2);
    LugiaScreenFlash();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_3);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_4);
    PlaySoundEffect(0x1f8);
    sub_80861D4(lugiaEntity,0xd,DIRECTION_SOUTH);
    sub_803E708(0x2b,0x46);
    sub_80861B8(lugiaEntity,0,DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_5);
    LugiaScreenFlash();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_6);
    LugiaScreenFlash2();
    SetDungeonBGColorRGB(0xffffff06,0xffffff06,0xffffff06,1,0);
    DungeonStopBGM();
    sub_80861D4(lugiaEntity,7,DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_7);
    LugiaScreenFlash();
    SetupBossFightHP(lugiaEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void LugiaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void LugiaScreenFlash2(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(4,0x46);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    sub_803E46C(0x46);
  }

  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C0CC(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  BgColorCallNullsub4();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  LugiaScreenFlash();
}

void sub_808C10C(void)
{
  Entity * leaderEntity;
  Entity * kyogreEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = xxx_call_GetLeader();
  kyogreEntity = GetEntityFromMonsterBehavior(BEHAVIOR_KYOGRE);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    sub_8068FE0(kyogreEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(kyogreEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_KYOGRE);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GROUDON);
}

void sub_808C1A4(u8 param_1,u8 param_2,u8 param_3)
{
  if ((param_2 == 0x34) && (param_1 == 0x1C)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  }
}

void KyogrePreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *KyogreEntity;

  leaderEntity = xxx_call_GetLeader();
  KyogreEntity = GetEntityFromMonsterBehavior(BEHAVIOR_KYOGRE);
  DungeonStopBGM();
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    SpriteLookAroundEffect(leaderEntity);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_8);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_1);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_2);
    sub_803E708(10,0x46);
    nullsub_99();
    sub_803E708(10,0x46);
    // Gwwwwwooooooooh
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_3);
    sub_803E708(10,0x46);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C360();
    // My duels against {POKEMON_3} (Groudon) left us both exhausted
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_4);
    KyogreScreenFlash();
    // I am {POKEMON_2} (Kyogre)!
    // The lord of the sea!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_5);
    KyogreScreenFlash();
    // Witness the destructive force of my waves!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_6);
    KyogreScreenFlash();
    // Marvel at my awesome
    // power!
    DisplayDungeonDialogue(&gKyogrePreFightDialogue_7);
    sub_803E708(10,0x46);
    SetupBossFightHP(KyogreEntity,600,MUS_BOSS_BATTLE);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void nullsub_99(void)
{
}

void KyogreScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f8);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C360(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  BgColorCallNullsub4();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  KyogreScreenFlash();
}

void sub_808C3A0(void)
{
  Entity * leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    sub_808563C(sub_808C590);
  }
  else {
    gDungeon->unk7 = 1;
    sub_808563C(SetupDeoxysFacingDirection);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_DEOXYS_NORMAL);
}

void sub_808C414(u8 param_1,u8 param_2,u8 param_3)
{
  if ((param_2 == 0x35) && (param_1 == 0x1D)) {
    gDungeon->unk2 = 1;
    DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  }
}

void DeoxysPreFightDialogue(void)
{
  Entity * leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gDeoxysPreFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_RAYQUAZAS_DOMAIN, 0x3c);
    sub_808C550();
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_2);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_3);
    DeoxysScreenFlash();
    DisplayDungeonDialogue(&gDeoxysPreFightDialogue_4);
    sub_803E708(10,0x46);
    sub_808563C(SetupDeoxysFightHP);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

void DeoxysScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_808C550(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  BgColorCallNullsub4();
  sub_803E46C(0x46);
  gDungeon->unk7 = 0;
  DeoxysScreenFlash();
}

void sub_808C590(Entity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void SetupDeoxysFacingDirection(Entity *deoxysEntity)
{
    SetFacingDirection(deoxysEntity, DIRECTION_SOUTH);
}

void SetupDeoxysFightHP(Entity *deoxysEntity)
{
    SetupBossFightHP(deoxysEntity, 950, MUS_BATTLE_WITH_RAYQUAZA);
}

void sub_808C5C0(void)
{
  Entity * leaderEntity;
  Entity * celebiEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = xxx_call_GetLeader();
  celebiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_CELEBI);
  DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(celebiEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos - 0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_CELEBI);
}

void nullsub_100(u8 r0, u8 r1, u8 r3)
{
}

void CelebiJoinDialogue(void)
{
    Entity *leaderEntity;
    s32 state;
    s32 menuChoice;
    Entity *celebiEntity;

    leaderEntity = xxx_call_GetLeader();
    celebiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_CELEBI);
    if ((HasRecruitedMon(MONSTER_CELEBI)) || (!sub_806FD18(celebiEntity)))
    {
        sub_8068FE0(celebiEntity,0x21c,0);
        SpriteLookAroundEffect(leaderEntity);
        sub_803E708(10,0x46);
        // .........
        DisplayDungeonDialogue(&gCelebiJoinDialogue_10);
    }
    else
    {
        SpriteLookAroundEffect(leaderEntity);
        sub_803E708(10,0x46);
        SpriteShockEffect(leaderEntity);
        sub_803E708(10,0x46);
        // Oh? There's someone there.
        DisplayDungeonDialogue(&gCelebiJoinDialogue_1);
        sub_803E708(10,0x46);
        sub_8086598();
        sub_8086598();
        sub_8086598();
        sub_8086598();
        // The Time-Traveling Pokemon {POKEMON_2} (Celebi)!
        DisplayDungeonDialogue(&gCelebiJoinDialogue_2);
        PlaySoundEffect(0x1c7);
        sub_806CDD4(celebiEntity,10,DIRECTION_SOUTH);
        sub_803E708(0x14,0x46);
        sub_806CE68(celebiEntity, DIRECTION_SOUTH);
        sub_803E708(4,0x46);
        PlaySoundEffect(0x1c7);
        sub_806CDD4(celebiEntity,10,DIRECTION_SOUTH);
        DisplayDungeonDialogue(&gCelebiJoinDialogue_3);
        sub_803E708(10,0x46);
        state = 0;

        do
        {
            switch(state)
            {
            case 0:
                do
                {
                    menuChoice = DisplayDungeonMenuMessage(0,gPtrPurityForestAllowCelebiToJoinText, gPurityForestAllowCelebiToJoinPrompt,0x701);
                } while (menuChoice < 1);

                sub_803E708(10,0x46);

                if (menuChoice == 1)
                {
                    DungeonStopBGM();
                    PlaySoundEffect(0xcc);
                    while (IsFanfareSEPlaying_2(0xcc) != 0) {
                        sub_803E46C(0x46);
                    }
                    DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                    PlaySoundEffect(0x1c7);
                    sub_80861D4(celebiEntity,0xd,DIRECTION_SOUTH);
                    sub_803E708(0x37,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1a,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1c,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_4);
                    sub_803E708(10,0x46);
                    sub_806FDF4(leaderEntity,celebiEntity,&celebiEntity);
                    DungeonStartNewBGM(MUS_FRIEND_AREA_HEALING_FOREST);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_5);
                    sub_803E708(10,0x46);
                    PlaySoundEffect(0x1c7);
                    sub_80861D4(celebiEntity,0xd,DIRECTION_SOUTH);
                    sub_803E708(0x37,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1a,0x46);
                    PlaySoundEffect(0x1d5);
                    sub_803E708(0x1b,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_6);
                    sub_803E708(10,0x46);
                    state = 2;
                }
                else
                {
                    state = 1;
                }
                break;
            case 1:
                do
                {
                    menuChoice = DisplayDungeonMenuMessage(0,gPtrPurityForestRefuseCelebiConfirmText, gPurityForestRefuseCelebiConfirmPrompt,0x701);
                } while (menuChoice < 1);
                if (menuChoice == 1)
                {
                    state = 0;
                }
                else
                {
                    sub_803E708(10,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_7);
                    sub_80861F8(0x3e,celebiEntity,1);
                    sub_803E708(0x18,0x46);
                    sub_80861F8(0x3e,celebiEntity,1);
                    sub_803E708(0xe,0x46);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_8);
                    sub_803E708(10,0x46);
                    sub_808C8E0(celebiEntity);
                    DisplayDungeonDialogue(&gCelebiJoinDialogue_9);
                    sub_803E708(10,0x46);
                    state = 2;
                }
                break;
            }
        } while (state != 2);
    }
    DungeonFadeOutBGM(0x1e);
    sub_803E708(0x1e,0x46);
    gDungeon->unk2 = 1;
}

void sub_808C8E0(Entity *entity)
{
  s32 iVar1;

  PlaySoundEffect(0x1a5);
  sub_806CDD4(entity, 0, DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 16; iVar1++){
    GetEntInfo(entity)->unk174 = IntToF248_2(iVar1);
    sub_803E46C(0x46);
  }
  for(iVar1 = 16; iVar1 < 200; iVar1 += 4){
    GetEntInfo(entity)->unk174 = IntToF248_2(iVar1);
    sub_803E46C(0x46);
  }
  sub_8086A3C(entity);
}

void sub_808C938(void)
{
    sub_80855E4(sub_808C9B0);
}

void sub_808C948(Entity *entity, u8 param_2)
{
  bool8 flag;
  s32 index;
  Entity *pokeEntity;

  if (param_2 == 0x37) {
    flag = FALSE;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++){
      pokeEntity = gDungeon->wildPokemon[index];
      if ((pokeEntity != entity) && (EntityIsValid(pokeEntity))) {
        flag = TRUE;
        break;
      }
    }
    if (!flag) {
      gDungeon->unk2 = 1;
    }
  }
}

void sub_808C998(void)
{
    // Defeat the opposing team to win
    // Be careful, your opponents are tough
    DisplayDungeonDialogue(&gUnknown_8106720);
    sub_803E708(0xA, 0x46);
}

void sub_808C9B0(Entity *param_1)
{
    GetEntInfo(param_1)->action.direction = DIRECTION_NORTH;
    sub_806CE68(param_1, DIRECTION_NORTH);
}

void sub_808C9C4(void)
{
    Entity *leaderEntity;
    Entity *medichamEntity;

    leaderEntity = xxx_call_GetLeader();
    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(medichamEntity, DIRECTION_SOUTH);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MEDICHAM);
}

void MedichamRescueDialogue(void)
{
    Entity *medichamEntity;
    s32 counter;

    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    SpriteLookAroundEffect(medichamEntity);
    sub_803E708(0xA, 0x46);
    // Oh my I can't seem to find a way out...
    DisplayDungeonDialogue(&gMedichamRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(medichamEntity, 4, 2, DIRECTION_NORTH);
    sub_803E708(0xA, 0x46);
    // What am I to do...?
    DisplayDungeonDialogue(&gMedichamRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(medichamEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(medichamEntity, 4, 2, DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gMedichamRescueDialogue_3);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(medichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(medichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(medichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Yes Yes
    // I am so lucky
    //
    // There appears to be no one here
    DisplayDungeonDialogue(&gMedichamRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(medichamEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        IncreaseEntityPixelPos(medichamEntity, 0, 0x100);
        sub_803E46C(0x46);
    }
    sub_806CE68(medichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(medichamEntity);
    sub_8068FE0(medichamEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;
}

void sub_808CB5C(void)
{
    Entity *leaderEntity;
    Entity *medichamEntity;

    leaderEntity = xxx_call_GetLeader();
    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_8068FE0(medichamEntity, 0x21C, 0);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MEDICHAM);
}

void DummyFightDialogue(void)
{
}

void sub_808CBB0(void)
{
    Entity *leaderEntity;
    Entity *smeargleEntity;

    leaderEntity = xxx_call_GetLeader();
    smeargleEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SMEARGLE);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(smeargleEntity, DIRECTION_SOUTH);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SMEARGLE);
}

void SmeargleRescueDialogue(void)
{
    Entity *smeargleEntity;
    s32 counter;

    smeargleEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SMEARGLE);
    SpriteLookAroundEffect(smeargleEntity);
    sub_803E708(0xA, 0x46);
    // Ohhh...
    // I've lost my bearings
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(smeargleEntity, 4, 2, DIRECTION_NORTH);
    sub_803E708(0xA, 0x46);
    // I can't get out...
    // I'm hungry...
    // I'm in trouble
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(smeargleEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(smeargleEntity, 4, 2, DIRECTION_SOUTH);
    // Oh! You are?
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_3);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(smeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(smeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(smeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Did you maybe come to rescue me?
    // Am I glad to see you
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(smeargleEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        IncreaseEntityPixelPos(smeargleEntity, 0, 0x100);
        sub_803E46C(0x46);
    }
    sub_806CE68(smeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(smeargleEntity);
    sub_8068FE0(smeargleEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;

}

void sub_808CD44(void)
{
    Entity *leaderEntity;
    Entity *smeargleEntity;

    leaderEntity = xxx_call_GetLeader();
    smeargleEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SMEARGLE);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    sub_8068FE0(smeargleEntity, 540, 0);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SMEARGLE);
}

void sub_808CD9C(void)
{
    sub_8086448();
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gUnknown_810697C);
}

const u64 *sub_808CDB0(u8 r0)
{
    return &gUnknown_8107544[r0];
}
