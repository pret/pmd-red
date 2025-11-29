const RGB_Struct gFlag05Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag05.pmdpal") };

static const axmain sAxMainFlag05;
const SiroArchive gAxFlag05 = {"SIRO", &sAxMainFlag05};

static const ax_pose sFlag05Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag05Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag05Gfx1[] = INCBIN_U8("graphics/ornament/Flag05/sprite_1.4bpp");
static const ax_sprite sFlag05Sprites1[] = {
	{sFlag05Gfx1, ARRAY_COUNT(sFlag05Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx2[] = INCBIN_U8("graphics/ornament/Flag05/sprite_2.4bpp");
static const ax_sprite sFlag05Sprites2[] = {
	{sFlag05Gfx2, ARRAY_COUNT(sFlag05Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx3[] = INCBIN_U8("graphics/ornament/Flag05/sprite_3.4bpp");
static const ax_sprite sFlag05Sprites3[] = {
	{sFlag05Gfx3, ARRAY_COUNT(sFlag05Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx4[] = INCBIN_U8("graphics/ornament/Flag05/sprite_4.4bpp");
static const ax_sprite sFlag05Sprites4[] = {
	{sFlag05Gfx4, ARRAY_COUNT(sFlag05Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx5[] = INCBIN_U8("graphics/ornament/Flag05/sprite_5.4bpp");
static const ax_sprite sFlag05Sprites5[] = {
	{sFlag05Gfx5, ARRAY_COUNT(sFlag05Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx6[] = INCBIN_U8("graphics/ornament/Flag05/sprite_6.4bpp");
static const ax_sprite sFlag05Sprites6[] = {
	{sFlag05Gfx6, ARRAY_COUNT(sFlag05Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag05[] = {
	sFlag05Pose1,
	sFlag05Pose2,
	sFlag05Pose3,
	sFlag05Pose4,
	sFlag05Pose5,
	sFlag05Pose6,
};

static const ax_anim *const sFlag05AnimTable1[] = {
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag05[] = {
	sFlag05AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag05[] = {
	sFlag05Sprites1,
	sFlag05Sprites2,
	sFlag05Sprites3,
	sFlag05Sprites4,
	sFlag05Sprites5,
	sFlag05Sprites6,
};

static const axmain sAxMainFlag05 = {
	.poses = sAxPosesFlag05,
	.animations = sAxAnimationsFlag05,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag05),
	.spriteData = sAxSpritesFlag05,
	.positions = NULL,
};
