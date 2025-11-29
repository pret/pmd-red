const RGB_Struct gFlag12Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag12.pmdpal") };

static const axmain sAxMainFlag12;
const SiroArchive gAxFlag12 = {"SIRO", &sAxMainFlag12};

static const ax_pose sFlag12Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag12Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag12Gfx1[] = INCBIN_U8("graphics/ornament/Flag12/sprite_1.4bpp");
static const ax_sprite sFlag12Sprites1[] = {
	{sFlag12Gfx1, ARRAY_COUNT(sFlag12Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx2[] = INCBIN_U8("graphics/ornament/Flag12/sprite_2.4bpp");
static const ax_sprite sFlag12Sprites2[] = {
	{sFlag12Gfx2, ARRAY_COUNT(sFlag12Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx3[] = INCBIN_U8("graphics/ornament/Flag12/sprite_3.4bpp");
static const ax_sprite sFlag12Sprites3[] = {
	{sFlag12Gfx3, ARRAY_COUNT(sFlag12Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx4[] = INCBIN_U8("graphics/ornament/Flag12/sprite_4.4bpp");
static const ax_sprite sFlag12Sprites4[] = {
	{sFlag12Gfx4, ARRAY_COUNT(sFlag12Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx5[] = INCBIN_U8("graphics/ornament/Flag12/sprite_5.4bpp");
static const ax_sprite sFlag12Sprites5[] = {
	{sFlag12Gfx5, ARRAY_COUNT(sFlag12Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx6[] = INCBIN_U8("graphics/ornament/Flag12/sprite_6.4bpp");
static const ax_sprite sFlag12Sprites6[] = {
	{sFlag12Gfx6, ARRAY_COUNT(sFlag12Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag12[] = {
	sFlag12Pose1,
	sFlag12Pose2,
	sFlag12Pose3,
	sFlag12Pose4,
	sFlag12Pose5,
	sFlag12Pose6,
};

static const ax_anim *const sFlag12AnimTable1[] = {
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag12[] = {
	sFlag12AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag12[] = {
	sFlag12Sprites1,
	sFlag12Sprites2,
	sFlag12Sprites3,
	sFlag12Sprites4,
	sFlag12Sprites5,
	sFlag12Sprites6,
};

static const axmain sAxMainFlag12 = {
	.poses = sAxPosesFlag12,
	.animations = sAxAnimationsFlag12,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag12),
	.spriteData = sAxSpritesFlag12,
	.positions = NULL,
};
