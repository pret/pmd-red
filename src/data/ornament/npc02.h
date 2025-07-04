static const axmain sAxMainNpc02;
const SiroArchive gAxNpc02 = {"SIRO", &sAxMainNpc02};

static const ax_pose sNpc02Pose1[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc02Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc02Gfx1[] = INCBIN_U8("graphics/ornament/Npc02/sprite_1.4bpp");
static const ax_sprite sNpc02Sprites1[] = {
	{sNpc02Gfx1, ARRAY_COUNT(sNpc02Gfx1)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc02[] = {
	sNpc02Pose1,
};

static const ax_anim *const sNpc02AnimTable1[] = {
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc02[] = {
	sNpc02AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc02[] = {
	sNpc02Sprites1,
};

static const axmain sAxMainNpc02 = {
	.poses = sAxPosesNpc02,
	.animations = sAxAnimationsNpc02,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc02),
	.spriteData = sAxSpritesNpc02,
	.positions = NULL,
};
