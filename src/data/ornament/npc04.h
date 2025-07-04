static const axmain sAxMainNpc04;
const SiroArchive gAxNpc04 = {"SIRO", &sAxMainNpc04};

static const ax_pose sNpc04Pose1[] = {
	AX_POSE(0, OAM1(233, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc04Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc04Gfx1[] = INCBIN_U8("graphics/ornament/Npc04/sprite_1.4bpp");
static const ax_sprite sNpc04Sprites1[] = {
	{sNpc04Gfx1, ARRAY_COUNT(sNpc04Gfx1)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc04[] = {
	sNpc04Pose1,
};

static const ax_anim *const sNpc04AnimTable1[] = {
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc04[] = {
	sNpc04AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc04[] = {
	sNpc04Sprites1,
};

static const axmain sAxMainNpc04 = {
	.poses = sAxPosesNpc04,
	.animations = sAxAnimationsNpc04,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc04),
	.spriteData = sAxSpritesNpc04,
	.positions = NULL,
};
