const RGB_Struct gFlag103Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag103.pmdpal") };

static const axmain sAxMainFlag103;
const SiroArchive gAxFlag103 = {"SIRO", &sAxMainFlag103};

static const ax_pose sFlag103Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag103Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag103Gfx1[] = INCBIN_U8("graphics/ornament/Flag103/sprite_1.4bpp");
static const ax_sprite sFlag103Sprites1[] = {
	{sFlag103Gfx1, ARRAY_COUNT(sFlag103Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx2[] = INCBIN_U8("graphics/ornament/Flag103/sprite_2.4bpp");
static const ax_sprite sFlag103Sprites2[] = {
	{sFlag103Gfx2, ARRAY_COUNT(sFlag103Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx3[] = INCBIN_U8("graphics/ornament/Flag103/sprite_3.4bpp");
static const ax_sprite sFlag103Sprites3[] = {
	{sFlag103Gfx3, ARRAY_COUNT(sFlag103Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx4[] = INCBIN_U8("graphics/ornament/Flag103/sprite_4.4bpp");
static const ax_sprite sFlag103Sprites4[] = {
	{sFlag103Gfx4, ARRAY_COUNT(sFlag103Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx5[] = INCBIN_U8("graphics/ornament/Flag103/sprite_5.4bpp");
static const ax_sprite sFlag103Sprites5[] = {
	{sFlag103Gfx5, ARRAY_COUNT(sFlag103Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx6[] = INCBIN_U8("graphics/ornament/Flag103/sprite_6.4bpp");
static const ax_sprite sFlag103Sprites6[] = {
	{sFlag103Gfx6, ARRAY_COUNT(sFlag103Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag103[] = {
	sFlag103Pose1,
	sFlag103Pose2,
	sFlag103Pose3,
	sFlag103Pose4,
	sFlag103Pose5,
	sFlag103Pose6,
};

static const ax_anim *const sFlag103AnimTable1[] = {
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag103[] = {
	sFlag103AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag103[] = {
	sFlag103Sprites1,
	sFlag103Sprites2,
	sFlag103Sprites3,
	sFlag103Sprites4,
	sFlag103Sprites5,
	sFlag103Sprites6,
};

static const axmain sAxMainFlag103 = {
	.poses = sAxPosesFlag103,
	.animations = sAxAnimationsFlag103,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag103),
	.spriteData = sAxSpritesFlag103,
	.positions = NULL,
};
