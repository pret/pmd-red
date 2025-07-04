const RGB gFlag16Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag16.pmdpal") };

static const axmain sAxMainFlag16;
const SiroArchive gAxFlag16 = {"SIRO", &sAxMainFlag16};

static const ax_pose sFlag16Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag16Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag16Gfx1[] = INCBIN_U8("graphics/ornament/Flag16/sprite_1.4bpp");
static const ax_sprite sFlag16Sprites1[] = {
	{sFlag16Gfx1, ARRAY_COUNT(sFlag16Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx2[] = INCBIN_U8("graphics/ornament/Flag16/sprite_2.4bpp");
static const ax_sprite sFlag16Sprites2[] = {
	{sFlag16Gfx2, ARRAY_COUNT(sFlag16Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx3[] = INCBIN_U8("graphics/ornament/Flag16/sprite_3.4bpp");
static const ax_sprite sFlag16Sprites3[] = {
	{sFlag16Gfx3, ARRAY_COUNT(sFlag16Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx4[] = INCBIN_U8("graphics/ornament/Flag16/sprite_4.4bpp");
static const ax_sprite sFlag16Sprites4[] = {
	{sFlag16Gfx4, ARRAY_COUNT(sFlag16Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx5[] = INCBIN_U8("graphics/ornament/Flag16/sprite_5.4bpp");
static const ax_sprite sFlag16Sprites5[] = {
	{sFlag16Gfx5, ARRAY_COUNT(sFlag16Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx6[] = INCBIN_U8("graphics/ornament/Flag16/sprite_6.4bpp");
static const ax_sprite sFlag16Sprites6[] = {
	{sFlag16Gfx6, ARRAY_COUNT(sFlag16Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag16[] = {
	sFlag16Pose1,
	sFlag16Pose2,
	sFlag16Pose3,
	sFlag16Pose4,
	sFlag16Pose5,
	sFlag16Pose6,
};

static const ax_anim *const sFlag16AnimTable1[] = {
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag16[] = {
	sFlag16AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag16[] = {
	sFlag16Sprites1,
	sFlag16Sprites2,
	sFlag16Sprites3,
	sFlag16Sprites4,
	sFlag16Sprites5,
	sFlag16Sprites6,
};

static const axmain sAxMainFlag16 = {
	.poses = sAxPosesFlag16,
	.animations = sAxAnimationsFlag16,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag16),
	.spriteData = sAxSpritesFlag16,
	.positions = NULL,
};
