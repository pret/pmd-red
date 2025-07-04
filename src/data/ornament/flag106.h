const RGB gFlag106Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag106.pmdpal") };

static const axmain sAxMainFlag106;
const SiroArchive gAxFlag106 = {"SIRO", &sAxMainFlag106};

static const ax_pose sFlag106Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag106Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag106Gfx1[] = INCBIN_U8("graphics/ornament/Flag106/sprite_1.4bpp");
static const ax_sprite sFlag106Sprites1[] = {
	{sFlag106Gfx1, ARRAY_COUNT(sFlag106Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx2[] = INCBIN_U8("graphics/ornament/Flag106/sprite_2.4bpp");
static const ax_sprite sFlag106Sprites2[] = {
	{sFlag106Gfx2, ARRAY_COUNT(sFlag106Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx3[] = INCBIN_U8("graphics/ornament/Flag106/sprite_3.4bpp");
static const ax_sprite sFlag106Sprites3[] = {
	{sFlag106Gfx3, ARRAY_COUNT(sFlag106Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx4[] = INCBIN_U8("graphics/ornament/Flag106/sprite_4.4bpp");
static const ax_sprite sFlag106Sprites4[] = {
	{sFlag106Gfx4, ARRAY_COUNT(sFlag106Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx5[] = INCBIN_U8("graphics/ornament/Flag106/sprite_5.4bpp");
static const ax_sprite sFlag106Sprites5[] = {
	{sFlag106Gfx5, ARRAY_COUNT(sFlag106Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx6[] = INCBIN_U8("graphics/ornament/Flag106/sprite_6.4bpp");
static const ax_sprite sFlag106Sprites6[] = {
	{sFlag106Gfx6, ARRAY_COUNT(sFlag106Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag106[] = {
	sFlag106Pose1,
	sFlag106Pose2,
	sFlag106Pose3,
	sFlag106Pose4,
	sFlag106Pose5,
	sFlag106Pose6,
};

static const ax_anim *const sFlag106AnimTable1[] = {
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag106[] = {
	sFlag106AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag106[] = {
	sFlag106Sprites1,
	sFlag106Sprites2,
	sFlag106Sprites3,
	sFlag106Sprites4,
	sFlag106Sprites5,
	sFlag106Sprites6,
};

static const axmain sAxMainFlag106 = {
	.poses = sAxPosesFlag106,
	.animations = sAxAnimationsFlag106,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag106),
	.spriteData = sAxSpritesFlag106,
	.positions = NULL,
};
