const RGB gFlag04Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag04.pmdpal") };

static const axmain sAxMainFlag04;
const SiroArchive gAxFlag04 = {"SIRO", &sAxMainFlag04};

static const ax_pose sFlag04Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag04Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag04Gfx1[] = INCBIN_U8("graphics/ornament/Flag04/sprite_1.4bpp");
static const ax_sprite sFlag04Sprites1[] = {
	{sFlag04Gfx1, ARRAY_COUNT(sFlag04Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx2[] = INCBIN_U8("graphics/ornament/Flag04/sprite_2.4bpp");
static const ax_sprite sFlag04Sprites2[] = {
	{sFlag04Gfx2, ARRAY_COUNT(sFlag04Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx3[] = INCBIN_U8("graphics/ornament/Flag04/sprite_3.4bpp");
static const ax_sprite sFlag04Sprites3[] = {
	{sFlag04Gfx3, ARRAY_COUNT(sFlag04Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx4[] = INCBIN_U8("graphics/ornament/Flag04/sprite_4.4bpp");
static const ax_sprite sFlag04Sprites4[] = {
	{sFlag04Gfx4, ARRAY_COUNT(sFlag04Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx5[] = INCBIN_U8("graphics/ornament/Flag04/sprite_5.4bpp");
static const ax_sprite sFlag04Sprites5[] = {
	{sFlag04Gfx5, ARRAY_COUNT(sFlag04Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx6[] = INCBIN_U8("graphics/ornament/Flag04/sprite_6.4bpp");
static const ax_sprite sFlag04Sprites6[] = {
	{sFlag04Gfx6, ARRAY_COUNT(sFlag04Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag04[] = {
	sFlag04Pose1,
	sFlag04Pose2,
	sFlag04Pose3,
	sFlag04Pose4,
	sFlag04Pose5,
	sFlag04Pose6,
};

static const ax_anim *const sFlag04AnimTable1[] = {
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag04[] = {
	sFlag04AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag04[] = {
	sFlag04Sprites1,
	sFlag04Sprites2,
	sFlag04Sprites3,
	sFlag04Sprites4,
	sFlag04Sprites5,
	sFlag04Sprites6,
};

static const axmain sAxMainFlag04 = {
	.poses = sAxPosesFlag04,
	.animations = sAxAnimationsFlag04,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag04),
	.spriteData = sAxSpritesFlag04,
	.positions = NULL,
};
