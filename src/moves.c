#include "global.h"
#include "moves.h"

#include "file_system.h"
#include "constants/move_id.h"

struct MoveDataFile
{
    struct MoveData *moveData;
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
extern struct MoveData *gMovesData;
extern u8 *gMovesRelated_2038C6C;

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

extern void sub_8093F10(struct PokemonMove *, struct PokemonMove *);
extern void sub_80928C0(u8 *, struct PokemonMove *, struct unkStruct_80928C0 *);
bool8 DoesMoveCharge(u16 move);
extern void ExpandPlaceholdersBuffer(u8 *, u8 *, ...);

void LoadWazaParameters(void)
{
    gWazaParametersFile = OpenFileAndGetFileDataPtr(gUnknown_81098D0, &gSystemFileArchive);

    gMovesData = ((struct MoveDataFile *)(gWazaParametersFile->data))->moveData;
    gMovesRelated_2038C6C = ((struct MoveDataFile *)(gWazaParametersFile->data))->unk4;
}

u8 sub_809287C(struct PokemonMove *move)
{
    if((move->moveFlags & MOVE_FLAG_DISABLED) != 0)
        return 0x32;
    else if((move->sealed & 1) == 0)
        return 0x34;
    else
        return 0x32;
}

void sub_80928A0(u8 *buffer, struct PokemonMove *move, struct unkStruct_80928C0 *r2)
{
    struct PokemonMove stack;
    sub_8093F10(&stack, move);
    sub_80928C0(buffer, &stack, r2);
}

void sub_80928C0(u8 *buffer, struct PokemonMove *move, struct unkStruct_80928C0 *param_3)
{
  u32 uVar2;
  u32 maxPP;
  u8 localBuffer[12];

  uVar2 = sub_809287C(move);
  if (param_3 == NULL) {
    param_3 = &gUnknown_81098C4;
  }

  if (move->powerBoost != 0)
      ExpandPlaceholdersBuffer(localBuffer,gUnknown_81098DC,move->powerBoost); // %+d
  else
      localBuffer[0] = '\0';

  if (param_3->unk8 != 0) {
        uVar2 = 2;
  }
  if (param_3->unk9 != 0 && DoesMoveCharge(move->moveID)) {
        uVar2 = 2;
  }
  switch(param_3->unk0) {
        case 0:
            ExpandPlaceholdersBuffer
                    (buffer,gUnknown_81098E0,uVar2,
                    gMovesData[move->moveID].namePointer,localBuffer);
            break;

        case 1:
            maxPP = GetMoveMaxPP(move);
            ExpandPlaceholdersBuffer
                    (buffer,gUnknown_81098EC,uVar2,move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                    gMovesData[move->moveID].namePointer,localBuffer,param_3->unk4,
                    move->pp,maxPP);
            break;

        case 2:
            maxPP = GetMoveMaxPP(move);
            ExpandPlaceholdersBuffer
                    (buffer,gUnknown_8109910,uVar2,move->moveFlags & MOVE_FLAG_SET ? gUnknown_8109908 : gUnknown_810990C,
                    gMovesData[move->moveID].namePointer,localBuffer,param_3->unk4,
                    move->pp,maxPP);
            break;

        case 3:
            maxPP = GetMoveMaxPP(move);
            ExpandPlaceholdersBuffer
                    (buffer,gUnknown_81098EC,uVar2,move->moveFlags & MOVE_FLAG_ENABLED ? gUnknown_8109928 : gUnknown_810990C,
                    gMovesData[move->moveID].namePointer,localBuffer,param_3->unk4,
                    move->pp,maxPP);
            break;

        case 4:
            maxPP = GetMoveMaxPP(move);
            ExpandPlaceholdersBuffer
                    (buffer,gUnknown_8109910,uVar2, move->moveFlags & MOVE_FLAG_ENABLED ? gUnknown_8109928 : gUnknown_810990C,
                    gMovesData[move->moveID].namePointer,localBuffer,param_3->unk4,
                    move->pp,maxPP);
            break;
        }
}

void InitPokemonMove(struct PokemonMove *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED | MOVE_FLAG_EXISTS;
    move->sealed = FALSE;
    move->moveID = moveID;
    move->pp = GetMoveMaxPP(move);
    move->powerBoost = 0;
}

void sub_8092AA8(struct PokemonMove *move, u16 moveID)
{
    if(moveID == 0)
        move->moveFlags = 0;
    else
    {
        move->moveFlags = MOVE_FLAG_ENABLED | MOVE_FLAG_EXISTS;
        move->sealed = FALSE;
        move->moveID = moveID;
        move->pp = GetMoveMaxPP(move);
        move->powerBoost = 0;
    }
}

void InitZeroedPPPokemonMove(struct PokemonMove *move, u16 moveID)
{
    move->moveFlags = MOVE_FLAG_ENABLED | MOVE_FLAG_EXISTS;
    move->moveID = moveID;
    move->pp = 0;
}

s16 GetMoveTargetingFlags(struct PokemonMove *move, u32 r1)
{
    return gMovesData[move->moveID].targetingFlags[r1];
}

u8 GetMoveType(struct PokemonMove *move)
{
    return gMovesData[move->moveID].type;
}

NAKED
void sub_8092B18(s16 species)
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
"_08092B44: .4byte gMovesRelated_2038C6C\n"
"_08092B48:\n"
	"\tldr r0, _08092B50\n"
"_08092B4A:\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_08092B50: .4byte gUnknown_810992B");
}

NAKED
void sub_8092B54(s16 species)
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
"_08092B80: .4byte gMovesRelated_2038C6C\n"
"_08092B84:\n"
	"\tldr r0, _08092B8C\n"
"_08092B86:\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_08092B8C: .4byte gUnknown_810992B");
}

u8 GetMoveWeight(struct PokemonMove *move)
{
    return gMovesData[move->moveID].weight;
}

u8 GetMoveHitCount(struct PokemonMove *move)
{
    return gMovesData[move->moveID].hitCount;
}

s32 GetMovePower(struct PokemonMove *move)
{
    return gMovesData[move->moveID].power;
}

u8 GetMoveAccuracy(struct PokemonMove *move, u32 r1)
{
    return gMovesData[move->moveID].accuracy[r1];
}

u32 GetMoveMaxPP(struct PokemonMove *move)
{
    return gMovesData[move->moveID].maxPP;
}

u8 GetMoveUnk12(struct PokemonMove *move)
{
    return gMovesData[move->moveID].unk12;
}

u8 GetMoveCriticalHitChance(struct PokemonMove *move)
{
    return gMovesData[move->moveID].criticalHitChance;
}

u8 GetMoveCannotHitFrozen(struct PokemonMove *move)
{
    return gMovesData[move->moveID].cannotHitFrozen;
}

u8 GetMoveDealsDirectDamage(struct PokemonMove *move)
{
    return gMovesData[move->moveID].dealsDirectDamage;
}

u32 GetMoveRangeType(struct PokemonMove *move)
{
    return gMovesData[move->moveID].rangeType;
}

void sub_8092C84(u8 *buffer, u16 moveID)
{
    struct PokemonMove stack;
    InitPokemonMove(&stack, moveID);
    sub_80928C0(buffer, &stack, NULL);
}

u8 *GetMoveUseText(u16 moveID)
{
    return gMovesData[moveID].useText;
}

u8 GetMoveAffectedByMagicCoat(u16 moveID)
{
    return gMovesData[moveID].affectedByMagicCoat;
}

u8 GetMoveTargetsUser(u16 moveID)
{
    return gMovesData[moveID].targetsUser;
}

u8 GetMoveAffectedByMuzzled(u16 moveID)
{
    return gMovesData[moveID].affectedByMuzzled;
}

bool8 IsBlockedBySoundproof(struct PokemonMove *move)
{
    if(move->moveID == MOVE_GROWL)  return TRUE;
    if(move->moveID == MOVE_ROAR)  return TRUE;
    if(move->moveID == MOVE_METAL_SOUND)  return TRUE;
    if(move->moveID == MOVE_SING)  return TRUE;
    if(move->moveID == MOVE_GRASSWHISTLE)  return TRUE;
    if(move->moveID == MOVE_SUPERSONIC)  return TRUE;
    if(move->moveID == MOVE_PERISH_SONG)  return TRUE;
    if(move->moveID == MOVE_SCREECH)  return TRUE;
    if(move->moveID == MOVE_HYPER_VOICE)  return TRUE;
    if(move->moveID == MOVE_SNORE)  return TRUE;
    if(move->moveID == MOVE_HEAL_BELL)  return TRUE;

    return FALSE;
}

void sub_8092D54(u8 *buffer, struct PokemonMove *move)
{
    ExpandPlaceholdersBuffer(buffer, gUnknown_810992C, gRangeNames[GetMoveRangeType(move)]);
}
