static const axmain sAxMainNpc03;
const SiroArchive gAxNpc03 = {"SIRO", &sAxMainNpc03};

static const ax_pose sNpc03Pose1[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc03Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc03Gfx1[] = INCBIN_U8("graphics/ornament/Npc03/sprite_1.4bpp");
static const ax_sprite sNpc03Sprites1[] = {
	{NULL, 32},
	{sNpc03Gfx1, ARRAY_COUNT(sNpc03Gfx1)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc03[] = {
	sNpc03Pose1,
};

static const ax_anim *const sNpc03AnimTable1[] = {
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc03[] = {
	sNpc03AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc03[] = {
	sNpc03Sprites1,
};

static const axmain sAxMainNpc03 = {
	.poses = sAxPosesNpc03,
	.animations = sAxAnimationsNpc03,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc03),
	.spriteData = sAxSpritesNpc03,
	.positions = NULL,
};
