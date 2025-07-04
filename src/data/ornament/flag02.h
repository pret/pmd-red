const RGB gFlag02Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag02.pmdpal") };

static const axmain sAxMainFlag02;
const SiroArchive gAxFlag02 = {"SIRO", &sAxMainFlag02};

static const ax_pose sFlag02Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag02Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag02Gfx1[] = INCBIN_U8("graphics/ornament/Flag02/sprite_1.4bpp");
static const ax_sprite sFlag02Sprites1[] = {
	{sFlag02Gfx1, ARRAY_COUNT(sFlag02Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx2[] = INCBIN_U8("graphics/ornament/Flag02/sprite_2.4bpp");
static const ax_sprite sFlag02Sprites2[] = {
	{sFlag02Gfx2, ARRAY_COUNT(sFlag02Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx3[] = INCBIN_U8("graphics/ornament/Flag02/sprite_3.4bpp");
static const ax_sprite sFlag02Sprites3[] = {
	{sFlag02Gfx3, ARRAY_COUNT(sFlag02Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx4[] = INCBIN_U8("graphics/ornament/Flag02/sprite_4.4bpp");
static const ax_sprite sFlag02Sprites4[] = {
	{sFlag02Gfx4, ARRAY_COUNT(sFlag02Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx5[] = INCBIN_U8("graphics/ornament/Flag02/sprite_5.4bpp");
static const ax_sprite sFlag02Sprites5[] = {
	{sFlag02Gfx5, ARRAY_COUNT(sFlag02Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx6[] = INCBIN_U8("graphics/ornament/Flag02/sprite_6.4bpp");
static const ax_sprite sFlag02Sprites6[] = {
	{sFlag02Gfx6, ARRAY_COUNT(sFlag02Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag02[] = {
	sFlag02Pose1,
	sFlag02Pose2,
	sFlag02Pose3,
	sFlag02Pose4,
	sFlag02Pose5,
	sFlag02Pose6,
};

static const ax_anim *const sFlag02AnimTable1[] = {
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag02[] = {
	sFlag02AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag02[] = {
	sFlag02Sprites1,
	sFlag02Sprites2,
	sFlag02Sprites3,
	sFlag02Sprites4,
	sFlag02Sprites5,
	sFlag02Sprites6,
};

static const axmain sAxMainFlag02 = {
	.poses = sAxPosesFlag02,
	.animations = sAxAnimationsFlag02,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag02),
	.spriteData = sAxSpritesFlag02,
	.positions = NULL,
};
