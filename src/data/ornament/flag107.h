const RGB gFlag107Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag107.pmdpal") };

static const axmain sAxMainFlag107;
const SiroArchive gAxFlag107 = {"SIRO", &sAxMainFlag107};

static const ax_pose sFlag107Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag107Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag107Gfx1[] = INCBIN_U8("graphics/ornament/Flag107/sprite_1.4bpp");
static const ax_sprite sFlag107Sprites1[] = {
	{sFlag107Gfx1, ARRAY_COUNT(sFlag107Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx2[] = INCBIN_U8("graphics/ornament/Flag107/sprite_2.4bpp");
static const ax_sprite sFlag107Sprites2[] = {
	{sFlag107Gfx2, ARRAY_COUNT(sFlag107Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx3[] = INCBIN_U8("graphics/ornament/Flag107/sprite_3.4bpp");
static const ax_sprite sFlag107Sprites3[] = {
	{sFlag107Gfx3, ARRAY_COUNT(sFlag107Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx4[] = INCBIN_U8("graphics/ornament/Flag107/sprite_4.4bpp");
static const ax_sprite sFlag107Sprites4[] = {
	{sFlag107Gfx4, ARRAY_COUNT(sFlag107Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx5[] = INCBIN_U8("graphics/ornament/Flag107/sprite_5.4bpp");
static const ax_sprite sFlag107Sprites5[] = {
	{sFlag107Gfx5, ARRAY_COUNT(sFlag107Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx6[] = INCBIN_U8("graphics/ornament/Flag107/sprite_6.4bpp");
static const ax_sprite sFlag107Sprites6[] = {
	{sFlag107Gfx6, ARRAY_COUNT(sFlag107Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag107[] = {
	sFlag107Pose1,
	sFlag107Pose2,
	sFlag107Pose3,
	sFlag107Pose4,
	sFlag107Pose5,
	sFlag107Pose6,
};

static const ax_anim *const sFlag107AnimTable1[] = {
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag107[] = {
	sFlag107AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag107[] = {
	sFlag107Sprites1,
	sFlag107Sprites2,
	sFlag107Sprites3,
	sFlag107Sprites4,
	sFlag107Sprites5,
	sFlag107Sprites6,
};

static const axmain sAxMainFlag107 = {
	.poses = sAxPosesFlag107,
	.animations = sAxAnimationsFlag107,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag107),
	.spriteData = sAxSpritesFlag107,
	.positions = NULL,
};
