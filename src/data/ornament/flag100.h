const RGB gFlag100Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag100.pmdpal") };

static const axmain sAxMainFlag100;
const SiroArchive gAxFlag100 = {"SIRO", &sAxMainFlag100};

static const ax_pose sFlag100Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag100Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag100Gfx1[] = INCBIN_U8("graphics/ornament/Flag100/sprite_1.4bpp");
static const ax_sprite sFlag100Sprites1[] = {
	{sFlag100Gfx1, ARRAY_COUNT(sFlag100Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx2[] = INCBIN_U8("graphics/ornament/Flag100/sprite_2.4bpp");
static const ax_sprite sFlag100Sprites2[] = {
	{sFlag100Gfx2, ARRAY_COUNT(sFlag100Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx3[] = INCBIN_U8("graphics/ornament/Flag100/sprite_3.4bpp");
static const ax_sprite sFlag100Sprites3[] = {
	{sFlag100Gfx3, ARRAY_COUNT(sFlag100Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx4[] = INCBIN_U8("graphics/ornament/Flag100/sprite_4.4bpp");
static const ax_sprite sFlag100Sprites4[] = {
	{sFlag100Gfx4, ARRAY_COUNT(sFlag100Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx5[] = INCBIN_U8("graphics/ornament/Flag100/sprite_5.4bpp");
static const ax_sprite sFlag100Sprites5[] = {
	{sFlag100Gfx5, ARRAY_COUNT(sFlag100Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx6[] = INCBIN_U8("graphics/ornament/Flag100/sprite_6.4bpp");
static const ax_sprite sFlag100Sprites6[] = {
	{sFlag100Gfx6, ARRAY_COUNT(sFlag100Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag100[] = {
	sFlag100Pose1,
	sFlag100Pose2,
	sFlag100Pose3,
	sFlag100Pose4,
	sFlag100Pose5,
	sFlag100Pose6,
};

static const ax_anim *const sFlag100AnimTable1[] = {
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag100[] = {
	sFlag100AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag100[] = {
	sFlag100Sprites1,
	sFlag100Sprites2,
	sFlag100Sprites3,
	sFlag100Sprites4,
	sFlag100Sprites5,
	sFlag100Sprites6,
};

static const axmain sAxMainFlag100 = {
	.poses = sAxPosesFlag100,
	.animations = sAxAnimationsFlag100,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag100),
	.spriteData = sAxSpritesFlag100,
	.positions = NULL,
};
