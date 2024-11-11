#include "global.h"
#include "called_move_data.h"
#include "constants/move_id.h"

extern bool8 IronTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 YawnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 NightmareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CharmMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EncoreMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SuperFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PainSplitMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TormentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SwaggerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RockSlideMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WhirlpoolMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FakeTearsMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SpiteMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmokescreenMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FlatterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8057FF4(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ReturnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FlameWheelMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GustMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DisableMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CrunchMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BiteMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThunderMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EndeavorMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FacadeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058580(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BrickBreakMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RockTombMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GigaDrainMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ReversalMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmellingSaltMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MetalSoundMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TickleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 OutrageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LowKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AncientPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RapidSpinMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ScaryFaceMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8058E5C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FissureMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059190(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AbsorbMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SkillSwapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HeadbuttMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DoubleEdgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059528(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SmogMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SacredFireMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_80595EC(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MuddyWaterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TwisterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TwineedleMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_8059A2C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SupersonicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TauntMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HornDrillMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThundershockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ThunderWaveMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BlockMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonGasMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 ToxicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonFangMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonStingMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TriAttackMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TrickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 TripleKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MudSlapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A2A0(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RolePlayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LeerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PayDayMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CurseMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A568(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SuperpowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805A688(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 KnockOffMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 SecretPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AC90(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD04(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805AD34(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BeatUpMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BlastBurnMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 CrushClawMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 BlazeKickMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PresentMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 EruptionMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 GlareMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 PoisonTailMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 RoarMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 sub_805B17C(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 WrapMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MagnitudeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MistBallMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DestinyBondMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FalseSwipeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HiddenPowerMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 AttractMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 MimicMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FrustrationMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LeechSeedMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DreamEaterMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 LusterPurgeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 DragonRageMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 FakeOutMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 HandleRegularDamagingMove(Entity *pokemon, Entity *target, Move *move, s32 param_4);
extern bool8 StunSporeMoveAction(Entity *pokemon, Entity *target, Move *move, s32 param_4);

// Todo: move this data to some better place once the file structure is better understood

// These are random
const struct CalledMove gMetronomeCalledMoves[METRONOME_AVAILABLE_CALLED_MOVES] =
{
    {MOVE_IRON_TAIL, IronTailMoveAction},
    {MOVE_YAWN, YawnMoveAction},
    {MOVE_NIGHTMARE, NightmareMoveAction},
    {MOVE_CHARM, CharmMoveAction},
    {MOVE_ENCORE, EncoreMoveAction},
    {MOVE_SUPER_FANG, SuperFangMoveAction},
    {MOVE_PAIN_SPLIT, PainSplitMoveAction},
    {MOVE_TORMENT, TormentMoveAction},
    {MOVE_SWAGGER, SwaggerMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_WHIRLPOOL, WhirlpoolMoveAction},
    {MOVE_FAKE_TEARS, FakeTearsMoveAction},
    {MOVE_SPITE, SpiteMoveAction},
    {MOVE_SMOKESCREEN, SmokescreenMoveAction},
    {MOVE_FLATTER, FlatterMoveAction},
    {MOVE_WILL_O_WISP, sub_8057FF4},
    {MOVE_RETURN, ReturnMoveAction},
    {MOVE_FLAME_WHEEL, FlameWheelMoveAction},
    {MOVE_GUST, GustMoveAction},
    {MOVE_DISABLE, DisableMoveAction},
    {MOVE_CRUNCH, CrunchMoveAction},
    {MOVE_BITE, BiteMoveAction},
    {MOVE_THUNDER, ThunderMoveAction},
    {MOVE_ENDEAVOR, EndeavorMoveAction},
    {MOVE_FACADE, FacadeMoveAction},
    {MOVE_CONSTRICT, sub_8058580},
    {MOVE_BRICK_BREAK, BrickBreakMoveAction},
    {MOVE_ROCK_TOMB, RockTombMoveAction},
    {MOVE_GIGA_DRAIN, GigaDrainMoveAction},
    {MOVE_REVERSAL, ReversalMoveAction},
    {MOVE_SMELLINGSALT, SmellingSaltMoveAction},
    {MOVE_METAL_SOUND, MetalSoundMoveAction},
    {MOVE_TICKLE, TickleMoveAction},
    {MOVE_OUTRAGE, OutrageMoveAction},
    {MOVE_LOW_KICK, LowKickMoveAction},
    {MOVE_ANCIENTPOWER, AncientPowerMoveAction},
    {MOVE_RAPID_SPIN, RapidSpinMoveAction},
    {MOVE_SCARY_FACE, ScaryFaceMoveAction},
    {MOVE_SUBMISSION, sub_8058E5C},
    {MOVE_LICK, LickMoveAction},
    {MOVE_FISSURE, FissureMoveAction},
    {MOVE_EXTRASENSORY, sub_8059190},
    {MOVE_ABSORB, AbsorbMoveAction},
    {MOVE_SKILL_SWAP, SkillSwapMoveAction},
    {MOVE_HEADBUTT, HeadbuttMoveAction},
    {MOVE_DOUBLE_EDGE, DoubleEdgeMoveAction},
    {MOVE_SAND_ATTACK, sub_8059528},
    {MOVE_SMOG, SmogMoveAction},
    {MOVE_SACRED_FIRE, SacredFireMoveAction},
    {MOVE_SHEER_COLD, sub_80595EC},
    {MOVE_MUDDY_WATER, MuddyWaterMoveAction},
    {MOVE_TWISTER, TwisterMoveAction},
    {MOVE_TWINEEDLE, TwineedleMoveAction},
    {MOVE_SEISMIC_TOSS, sub_8059A2C},
    {MOVE_SUPERSONIC, SupersonicMoveAction},
    {MOVE_TAUNT, TauntMoveAction},
    {MOVE_HORN_DRILL, HornDrillMoveAction},
    {MOVE_THUNDERSHOCK, ThundershockMoveAction},
    {MOVE_THUNDER_WAVE, ThunderWaveMoveAction},
    {MOVE_BLOCK, BlockMoveAction},
    {MOVE_POISON_GAS, PoisonGasMoveAction},
    {MOVE_TOXIC, ToxicMoveAction},
    {MOVE_POISON_FANG, PoisonFangMoveAction},
    {MOVE_POISON_STING, PoisonStingMoveAction},
    {MOVE_TRI_ATTACK, TriAttackMoveAction},
    {MOVE_TRICK, TrickMoveAction},
    {MOVE_TRIPLE_KICK, TripleKickMoveAction},
    {MOVE_MUD_SLAP, MudSlapMoveAction},
    {MOVE_THIEF, sub_805A2A0},
    {MOVE_ROLE_PLAY, RolePlayMoveAction},
    {MOVE_LEER, LeerMoveAction},
    {MOVE_PAY_DAY, PayDayMoveAction},
    {MOVE_CURSE, CurseMoveAction},
    {MOVE_FRENZY_PLANT, sub_805A568},
    {MOVE_SUPERPOWER, SuperpowerMoveAction},
    {MOVE_DYNAMICPUNCH, sub_805A688},
    {MOVE_KNOCK_OFF, KnockOffMoveAction},
    {MOVE_SECRET_POWER, SecretPowerMoveAction},
    {MOVE_DIZZY_PUNCH, sub_805AC90},
    {MOVE_IMPRISON, sub_805AD04},
    {MOVE_FEATHERDANCE, sub_805AD34},
    {MOVE_BEAT_UP, BeatUpMoveAction},
    {MOVE_BLAST_BURN, BlastBurnMoveAction},
    {MOVE_CRUSH_CLAW, CrushClawMoveAction},
    {MOVE_BLAZE_KICK, BlazeKickMoveAction},
    {MOVE_PRESENT, PresentMoveAction},
    {MOVE_ERUPTION, EruptionMoveAction},
    {MOVE_GLARE, GlareMoveAction},
    {MOVE_POISON_TAIL, PoisonTailMoveAction},
    {MOVE_ROAR, RoarMoveAction},
    {MOVE_FIRE_SPIN, sub_805B17C},
    {MOVE_WRAP, WrapMoveAction},
    {MOVE_MAGNITUDE, MagnitudeMoveAction},
    {MOVE_MIST_BALL, MistBallMoveAction},
    {MOVE_DESTINY_BOND, DestinyBondMoveAction},
    {MOVE_FALSE_SWIPE, FalseSwipeMoveAction},
    {MOVE_HIDDEN_POWER, HiddenPowerMoveAction},
    {MOVE_ATTRACT, AttractMoveAction},
    {MOVE_MIMIC, MimicMoveAction},
    {MOVE_FRUSTRATION, FrustrationMoveAction},
    {MOVE_LEECH_SEED, LeechSeedMoveAction},
    {MOVE_DREAM_EATER, DreamEaterMoveAction},
    {MOVE_LUSTER_PURGE, LusterPurgeMoveAction},
    {MOVE_DRAGON_RAGE, DragonRageMoveAction},
    {MOVE_FAKE_OUT, FakeOutMoveAction},
};

// These correspond to dungeon's tileset id
const struct CalledMove gNaturePowerCalledMoves[] =
{
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_EARTHQUAKE, HandleRegularDamagingMove},
    {MOVE_BUBBLEBEAM, sub_8058580},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_SHADOW_BALL, CrunchMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_STUN_SPORE, StunSporeMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_RAZOR_LEAF, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, RockSlideMoveAction},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SWIFT, HandleRegularDamagingMove},
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_SURF, HandleRegularDamagingMove},
    {MOVE_ROCK_SLIDE, HandleRegularDamagingMove},
};

//
