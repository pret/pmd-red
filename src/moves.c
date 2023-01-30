#include "global.h"
#include "moves.h"

#include "file_system.h"
#include "moves.h"
#include "code_800D090.h"

struct MoveDataFile
{
    struct MoveDataEntry *moveData;
    u8 *unk4; // unsure of this struct's structure yet
};

struct unkStruct_80928C0
{
    u32 unk0;
    u32 unk4;
    u8 unk8;
    u8 unk9;
};

extern struct unkStruct_80928C0 gUnknown_81098C4;
extern struct FileArchive gSystemFileArchive;
extern struct OpenedFile *gWazaParametersFile;
extern struct MoveDataEntry *gMovesData;
extern u8 *gMoveLearnsets;

extern u8 gUnknown_81098D0[];
extern u8 gUnknown_81098DC[];
extern u8 gUnknown_810990C[];
extern u8 gUnknown_8109908[];
extern u8 gUnknown_8109928[];
extern u8 gUnknown_8109910[];
extern u8 gUnknown_81098E0[];
extern u8 gUnknown_81098EC[];
extern u8 *gRangeNames[];
extern u8 gUnknown_810992C[];

extern void sub_8093F10(struct Move *, struct Move *);
extern void sub_80928C0(u8 *, struct Move *, struct unkStruct_80928C0 *);

void LoadWazaParameters(void)
{
    gWazaParametersFile = OpenFileAndGetFileDataPtr(gUnknown_81098D0, &gSystemFileArchive);

    gMovesData = ((struct MoveDataFile *)(gWazaParametersFile->data))->moveData;
    gMoveLearnsets = ((struct MoveDataFile *)(gWazaParametersFile->data))->unk4;
}

u8 sub_809287C(struct Move *move)
{
    if((move->moveFlags & MOVE_FLAG_DISABLED) != 0)
        return 0x32;
    else if((move->moveFlags2 & MOVE_FLAG_SEALED) == 0)
        return 0x34;
    else
        return 0x32;
}

void sub_80928A0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *r2)
{
    struct Move stack;
    sub_8093F10(&stack, move);
    sub_80928C0(buffer, &stack, r2);
}

void sub_80928C0(u8 *buffer, struct Move *move, struct unkStruct_80928C0 *param_3)
{
  u32 uVar2;
  u32 basePP;
  u8 localBuffer[12];

  uVar2 = sub_809287C(move);
  if (param_3 == NULL) {
    param_3 = &gUnknown_81098C4;
  }

  if (move->ginseng != 0)
      sprintfStatic(localBuffer,gUnknown_81098DC,move->ginseng); // %+d
  else
      localBuffer[0] = '\0';

  if (param_3->unk8 != 0) {
        uVar2 = 2;
  }
  if (param_3->unk9 != 0 && DoesMoveCharge(move->id)) {
        uVar2 = 2;
  }
  switch(param_3->unk0) {
        case 0:
            sprintfStatic
                    (buffer,gUnknown_81098E0,uVar2,
                    gMovesData[move->id].name,localBuffer);
            break;

        case 1:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_81098EC,uVar2,move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;

        case 2:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_8109910,uVar2,move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;

        case 3:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_81098EC,uVar2,move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? gUnknown_8109928 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;

        case 4:
            basePP = GetMoveBasePP(move);
            sprintfStatic
                    (buffer,gUnknown_8109910,uVar2, move->moveFlags & MOVE_FLAG_ENABLED_FOR_AI ? gUnknown_8109928 : gUnknown_810990C,
                    gMovesData[move->id].name,localBuffer,param_3->unk4,
                    move->PP,basePP);
            break;
        }
}

void InitPokemonMove(struct Move *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
    move->moveFlags2 = 0;
    move->id = moveID;
    move->PP = GetMoveBasePP(move);
    move->ginseng = 0;
}

void sub_8092AA8(struct Move *move, u16 moveID)
{
    if(moveID == 0)
        move->moveFlags = 0;
    else
    {
        move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
        move->moveFlags2 = 0;
        move->id = moveID;
        move->PP = GetMoveBasePP(move);
        move->ginseng = 0;
    }
}

void InitZeroedPPPokemonMove(struct Move *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED_FOR_AI | MOVE_FLAG_EXISTS;
    move->id = moveID;
    move->PP = 0;
}

s16 GetMoveTargetAndRange(struct Move *move, bool32 isAI)
{
    return gMovesData[move->id].targetingFlags[isAI];
}

u8 GetMoveType(struct Move *move)
{
    return gMovesData[move->id].type;
}

NAKED
void GetLevelUpMoves(s16 species)
{
	asm_unified("\tpush {lr}\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tadds r2, r1, 0\n"
	"\tldr r0, _08092B40\n"
	"\tcmp r1, r0\n"
	"\tbeq _08092B48\n"
	"\tcmp r1, 0\n"
	"\tbeq _08092B48\n"
	"\tmovs r0, 0xD2\n"
	"\tlsls r0, 1\n"
	"\tcmp r2, r0\n"
	"\tbeq _08092B48\n"
	"\tldr r0, _08092B44\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 3\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tb _08092B4A\n"
	"\t.align 2, 0\n"
"_08092B40: .4byte 0x000001a5\n"
"_08092B44: .4byte gMoveLearnsets\n"
"_08092B48:\n"
	"\tldr r0, _08092B50\n"
"_08092B4A:\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_08092B50: .4byte gUnknown_810992B");
}

NAKED
void GetHMTMMoves(s16 species)
{
	asm_unified("\tpush {lr}\n"
	"\tlsls r0, 16\n"
	"\tasrs r1, r0, 16\n"
	"\tadds r2, r1, 0\n"
	"\tldr r0, _08092B7C\n"
	"\tcmp r1, r0\n"
	"\tbeq _08092B84\n"
	"\tcmp r1, 0\n"
	"\tbeq _08092B84\n"
	"\tmovs r0, 0xD2\n"
	"\tlsls r0, 1\n"
	"\tcmp r2, r0\n"
	"\tbeq _08092B84\n"
	"\tldr r0, _08092B80\n"
	"\tldr r1, [r0]\n"
	"\tlsls r0, r2, 3\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0, 0x4]\n"
	"\tb _08092B86\n"
	"\t.align 2, 0\n"
"_08092B7C: .4byte 0x000001a5\n"
"_08092B80: .4byte gMoveLearnsets\n"
"_08092B84:\n"
	"\tldr r0, _08092B8C\n"
"_08092B86:\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_08092B8C: .4byte gUnknown_810992B");
}

u8 GetMoveAIWeight(struct Move *move)
{
    return gMovesData[move->id].aiWeight;
}

u32 GetMoveNumberOfChainedHits(struct Move *move)
{
    return gMovesData[move->id].numberOfChainedHits;
}

s32 GetMoveBasePower(struct Move *move)
{
    return gMovesData[move->id].basePower;
}

s32 GetMoveAccuracyOrAIChance(struct Move *move, u32 accuracyType)
{
    return gMovesData[move->id].accuracy[accuracyType];
}

u32 GetMoveBasePP(struct Move *move)
{
    return gMovesData[move->id].basePP;
}

u32 GetMoveMaxUpgradeLevel(struct Move *move)
{
    return gMovesData[move->id].maxUpgradeLevel;
}

u8 GetMoveCritChance(struct Move *move)
{
    return gMovesData[move->id].critChance;
}

bool8 MoveCannotHitFrozen(struct Move *move)
{
    return gMovesData[move->id].cannotHitFrozen;
}

bool8 MovesIgnoresTaunted(struct Move *move)
{
    return gMovesData[move->id].ignoresTaunted;
}

u32 GetMoveRangeID(struct Move *move)
{
    return gMovesData[move->id].rangeID;
}

void sub_8092C84(u8 *buffer, u16 moveID)
{
    struct Move stack;
    InitPokemonMove(&stack, moveID);
    sub_80928C0(buffer, &stack, NULL);
}

u8 *GetMoveUseText(u16 moveID)
{
    return gMovesData[moveID].useText;
}

bool8 IsReflectedByMagicCoat(u16 moveID)
{
    return gMovesData[moveID].affectedByMagicCoat;
}

bool8 CanBeSnatched(u16 moveID)
{
    return gMovesData[moveID].isSnatchable;
}

bool8 FailsWhileMuzzled(u16 moveID)
{
    return gMovesData[moveID].usesMouth;
}

bool8 IsSoundMove(struct Move *move)
{
    if(move->id == MOVE_GROWL)  return TRUE;
    if(move->id == MOVE_ROAR)  return TRUE;
    if(move->id == MOVE_METAL_SOUND)  return TRUE;
    if(move->id == MOVE_SING)  return TRUE;
    if(move->id == MOVE_GRASSWHISTLE)  return TRUE;
    if(move->id == MOVE_SUPERSONIC)  return TRUE;
    if(move->id == MOVE_PERISH_SONG)  return TRUE;
    if(move->id == MOVE_SCREECH)  return TRUE;
    if(move->id == MOVE_HYPER_VOICE)  return TRUE;
    if(move->id == MOVE_SNORE)  return TRUE;
    if(move->id == MOVE_HEAL_BELL)  return TRUE;

    return FALSE;
}

void sub_8092D54(u8 *buffer, struct Move *move)
{
    sprintfStatic(buffer, gUnknown_810992C, gRangeNames[GetMoveRangeID(move)]);
}
