#include "global.h"
#include "called_move_data.h"
#include "constants/move_id.h"

extern bool8 sub_8057634(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 YawnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 NightmareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805783C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057974(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PainSplitMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057BC4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057C88(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WhirlpoolMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057D7C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057D9C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057FCC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057FF4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805805C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805816C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058270(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80582C4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80583D8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058430(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058478(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80584C0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058548(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058638(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80586DC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058770(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80587E8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058838(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058858(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80588B8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80588F4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058930(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058A18(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058BF0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058FBC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80590D4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059190(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80591E4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059424(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805946C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059540(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80595A0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80595EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80598CC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059928(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059988(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059A2C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AA8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AB8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059AF8(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D00(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D48(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059D98(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059DA4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059DB4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059DC4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059E0C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TriAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A120(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A210(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A258(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A2A0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A3DC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A464(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CurseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A568(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A688(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 KnockOffMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SecretPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AC90(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD04(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD34(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD54(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AE3C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AE74(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AECC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PresentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AFA4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B028(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B074(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B0BC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B17C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WrapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B264(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B324(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DestinyBondMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B388(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B3E0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B454(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MimicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B53C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LeechSeedMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B668(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B910(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B808(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A408(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8055620(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059050(Entity *pokemon, Entity *target, Move *move, s32 param_4);

// Todo: move this data to some better place once the file structure is better understood

// These are random
const struct CalledMove gMetronomeCalledMoves[METRONOME_AVAILABLE_CALLED_MOVES] =
{
    {MOVE_IRON_TAIL, sub_8057634},
    {MOVE_YAWN, YawnMoveAction},
    {MOVE_NIGHTMARE, NightmareMoveAction},
    {MOVE_CHARM, sub_805783C},
    {MOVE_ENCORE, EncoreMoveAction},
    {MOVE_SUPER_FANG, sub_8057974},
    {MOVE_PAIN_SPLIT, PainSplitMoveAction},
    {MOVE_TORMENT, TormentMoveAction},
    {MOVE_SWAGGER, sub_8057BC4},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_WHIRLPOOL, WhirlpoolMoveAction},
    {MOVE_FAKE_TEARS, sub_8057D7C},
    {MOVE_SPITE, sub_8057D9C},
    {MOVE_SMOKESCREEN, SmokescreenMoveAction},
    {MOVE_FLATTER, sub_8057FCC},
    {MOVE_WILL_O_WISP, sub_8057FF4},
    {MOVE_RETURN, sub_805805C},
    {MOVE_FLAME_WHEEL, sub_805816C},
    {MOVE_GUST, sub_8058270},
    {MOVE_DISABLE, sub_80582C4},
    {MOVE_CRUNCH, sub_80583D8},
    {MOVE_BITE, sub_8058430},
    {MOVE_THUNDER, sub_8058478},
    {MOVE_ENDEAVOR, sub_80584C0},
    {MOVE_FACADE, sub_8058548},
    {MOVE_CONSTRICT, sub_8058580},
    {MOVE_BRICK_BREAK, BrickBreakMoveAction},
    {MOVE_ROCK_TOMB, sub_8058638},
    {MOVE_GIGA_DRAIN, sub_80586DC},
    {MOVE_REVERSAL, sub_8058770},
    {MOVE_SMELLINGSALT, sub_80587E8},
    {MOVE_METAL_SOUND, sub_8058838},
    {MOVE_TICKLE, sub_8058858},
    {MOVE_OUTRAGE, sub_80588B8},
    {MOVE_LOW_KICK, sub_80588F4},
    {MOVE_ANCIENTPOWER, sub_8058930},
    {MOVE_RAPID_SPIN, sub_8058A18},
    {MOVE_SCARY_FACE, sub_8058BF0},
    {MOVE_SUBMISSION, sub_8058E5C},
    {MOVE_LICK, sub_8058FBC},
    {MOVE_FISSURE, sub_80590D4},
    {MOVE_EXTRASENSORY, sub_8059190},
    {MOVE_ABSORB, sub_80591E4},
    {MOVE_SKILL_SWAP, SkillSwapMoveAction},
    {MOVE_HEADBUTT, sub_8059424},
    {MOVE_DOUBLE_EDGE, sub_805946C},
    {MOVE_SAND_ATTACK, sub_8059528},
    {MOVE_SMOG, sub_8059540},
    {MOVE_SACRED_FIRE, sub_80595A0},
    {MOVE_SHEER_COLD, sub_80595EC},
    {MOVE_MUDDY_WATER, sub_80598CC},
    {MOVE_TWISTER, sub_8059928},
    {MOVE_TWINEEDLE, sub_8059988},
    {MOVE_SEISMIC_TOSS, sub_8059A2C},
    {MOVE_SUPERSONIC, sub_8059AA8},
    {MOVE_TAUNT, sub_8059AB8},
    {MOVE_HORN_DRILL, sub_8059AF8},
    {MOVE_THUNDERSHOCK, sub_8059D00},
    {MOVE_THUNDER_WAVE, sub_8059D48},
    {MOVE_BLOCK, sub_8059D98},
    {MOVE_POISON_GAS, sub_8059DA4},
    {MOVE_TOXIC, sub_8059DB4},
    {MOVE_POISON_FANG, sub_8059DC4},
    {MOVE_POISON_STING, sub_8059E0C},
    {MOVE_TRI_ATTACK, TriAttackMoveAction},
    {MOVE_TRICK, sub_805A120},
    {MOVE_TRIPLE_KICK, sub_805A210},
    {MOVE_MUD_SLAP, sub_805A258},
    {MOVE_THIEF, sub_805A2A0},
    {MOVE_ROLE_PLAY, RolePlayMoveAction},
    {MOVE_LEER, sub_805A3DC},
    {MOVE_PAY_DAY, sub_805A464},
    {MOVE_CURSE, CurseMoveAction},
    {MOVE_FRENZY_PLANT, sub_805A568},
    {MOVE_SUPERPOWER, TickleMoveAction},
    {MOVE_DYNAMICPUNCH, sub_805A688},
    {MOVE_KNOCK_OFF, KnockOffMoveAction},
    {MOVE_SECRET_POWER, SecretPowerMoveAction},
    {MOVE_DIZZY_PUNCH, sub_805AC90},
    {MOVE_IMPRISON, sub_805AD04},
    {MOVE_FEATHERDANCE, sub_805AD34},
    {MOVE_BEAT_UP, sub_805AD54},
    {MOVE_BLAST_BURN, sub_805AE3C},
    {MOVE_CRUSH_CLAW, sub_805AE74},
    {MOVE_BLAZE_KICK, sub_805AECC},
    {MOVE_PRESENT, PresentMoveAction},
    {MOVE_ERUPTION, sub_805AFA4},
    {MOVE_GLARE, sub_805B028},
    {MOVE_POISON_TAIL, sub_805B074},
    {MOVE_ROAR, sub_805B0BC},
    {MOVE_FIRE_SPIN, sub_805B17C},
    {MOVE_WRAP, WrapMoveAction},
    {MOVE_MAGNITUDE, sub_805B264},
    {MOVE_MIST_BALL, sub_805B324},
    {MOVE_DESTINY_BOND, DestinyBondMoveAction},
    {MOVE_FALSE_SWIPE, sub_805B388},
    {MOVE_HIDDEN_POWER, sub_805B3E0},
    {MOVE_ATTRACT, sub_805B454},
    {MOVE_MIMIC, MimicMoveAction},
    {MOVE_FRUSTRATION, sub_805B53C},
    {MOVE_LEECH_SEED, LeechSeedMoveAction},
    {MOVE_DREAM_EATER, sub_805B668},
    {MOVE_LUSTER_PURGE, sub_805B910},
    {MOVE_DRAGON_RAGE, sub_805B808},
    {MOVE_FAKE_OUT, sub_805A408},
};

// These correspond to dungeon's tileset id
const struct CalledMove gNaturePowerCalledMoves[] =
{
    {MOVE_SURF, sub_8055620},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_EARTHQUAKE, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_EARTHQUAKE, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_RAZOR_LEAF, sub_8055620},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_RAZOR_LEAF, sub_8055620},
    {MOVE_RAZOR_LEAF, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_EARTHQUAKE, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SURF, sub_8055620},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_EARTHQUAKE, sub_8055620},
    {MOVE_BUBBLEBEAM, sub_8058580},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_SHADOW_BALL, sub_80583D8},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_STUN_SPORE, sub_8059050},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_RAZOR_LEAF, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8057C88},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SWIFT, sub_8055620},
    {MOVE_SURF, sub_8055620},
    {MOVE_SURF, sub_8055620},
    {MOVE_ROCK_SLIDE, sub_8055620},
};

//
